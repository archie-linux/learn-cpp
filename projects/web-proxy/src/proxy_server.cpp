#include "proxy_server.h"
#include "http_parser.h"
#include "logger.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <iostream>

ProxyServer::ProxyServer(int port) : port_(port), sockfd_(-1) {}

void ProxyServer::start() {
    struct sockaddr_in addr;
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ < 0) return;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port_);

    bind(sockfd_, (struct sockaddr*)&addr, sizeof(addr));
    listen(sockfd_, 5);
    std::cout << "Proxy listening on :" << port_ << std::endl;

    while (true) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int clientfd = accept(sockfd_, (struct sockaddr*)&client_addr, &client_len);
        if (clientfd < 0) continue;

        handleClient(clientfd);
        close(clientfd);
    }
}

void ProxyServer::stop() {
    if (sockfd_ >= 0) close(sockfd_);
}

void ProxyServer::handleClient(int clientfd) {
    char buffer[4096];
    int bytes = recv(clientfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0) return;

    buffer[bytes] = '\0';
    std::string raw_req(buffer);

    HttpRequest req = parseRequest(raw_req);
    HttpResponse res = forwardRequest(req);

    // Send response back to client
    std::ostringstream oss;
    oss << res.version << " " << res.status << " " << res.reason << "\r\n";
    for (const auto& h : res.headers) {
        oss << h.first << ": " << h.second << "\r\n";
    }
    oss << "Content-Length: " << res.body.size() << "\r\n\r\n" << res.body;
    std::string raw_res = oss.str();
    send(clientfd, raw_res.c_str(), raw_res.size(), 0);

    logTraffic(req, res);
}

HttpRequest ProxyServer::parseRequest(const std::string& raw) {
    HttpRequest req;
    // Basic parsing: first line
    std::istringstream iss(raw);
    std::string line;
    std::getline(iss, line);
    std::istringstream first(line);
    first >> req.method >> req.url >> req.version;

    // Headers
    while (std::getline(iss, line) && line != "\r") {
        size_t pos = line.find(": ");
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string val = line.substr(pos + 2);
            req.headers[key] = val;
        }
    }

    // Body (simple, assume after empty line)
    std::string body;
    // For minimal, skip body parsing if no Content-Length
    req.body = body;
    return req;
}

HttpResponse ProxyServer::forwardRequest(const HttpRequest& req) {
    HttpResponse res;
    res.version = "HTTP/1.1";
    res.status = 200;
    res.reason = "OK";

    // Parse host from headers
    std::string host;
    try {
        host = req.headers.at("Host");
    } catch (const std::out_of_range&) {
        res.status = 400;
        res.reason = "Bad Request";
        res.body = "Missing Host header";
        return res;
    }

    // Parse URL
    std::string target_url = req.url;
    if (target_url.find("http://") == 0) target_url.erase(0, 7);
    size_t slash_pos = target_url.find('/');
    std::string hostname = (slash_pos != std::string::npos) ? target_url.substr(0, slash_pos) : target_url;

    // Connect to target
    int targetfd = socket(AF_INET, SOCK_STREAM, 0);
    if (targetfd < 0) {
        res.status = 500;
        res.reason = "Internal Server Error";
        res.body = "Failed to create socket";
        return res;
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, hostname.c_str(), &target_addr.sin_addr) <= 0) {
        res.status = 500;
        res.reason = "Internal Server Error";
        res.body = "Invalid target address";
        close(targetfd);
        return res;
    }

    if (connect(targetfd, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
        res.status = 500;
        res.reason = "Internal Server Error";
        res.body = "Failed to connect to target server";
        close(targetfd);
        return res;
    }

    // Forward request
    std::string fwd_req = req.method + " " + req.url + " " + req.version + "\r\n";
    for (const auto& h : req.headers) {
        fwd_req += h.first + ": " + h.second + "\r\n";
    }
    fwd_req += "\r\n" + req.body;
    send(targetfd, fwd_req.c_str(), fwd_req.size(), 0);

    // Receive response
    char resp_buf[4096];
    int resp_bytes = recv(targetfd, resp_buf, sizeof(resp_buf) - 1, 0);
    if (resp_bytes > 0) {
        resp_buf[resp_bytes] = '\0';
        std::string raw_res(resp_buf);

        // Parse response
        std::istringstream res_iss(raw_res);
        std::string line;
        std::getline(res_iss, line);
        std::istringstream res_first(line);
        res_first >> res.version >> res.status;
        std::getline(res_first, res.reason);  // Get reason phrase

        // Parse headers
        while (std::getline(res_iss, line) && line != "\r") {
            size_t pos = line.find(": ");
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string val = line.substr(pos + 2);
                if (val.back() == '\r') val.pop_back(); // Remove trailing \r
                res.headers[key] = val;
            }
        }
        res.body = raw_res.substr(raw_res.find("\r\n\r\n") + 4);
    }

    close(targetfd);
    return res;
}

void ProxyServer::logTraffic(const HttpRequest& req, const HttpResponse& res) {
    Logger::getInstance().addEntry(req, res);
}
