#include "web_server.h"
#include "logger.h"
#include "http_parser.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>

WebServer::WebServer(int port) : port_(port), sockfd_(-1) {}

void WebServer::start() {
    struct sockaddr_in addr;
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ < 0) return;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port_);

    bind(sockfd_, (struct sockaddr*)&addr, sizeof(addr));
    listen(sockfd_, 5);
    std::cout << "Web UI listening on :" << port_ << std::endl;

    while (true) {
        int clientfd = accept(sockfd_, NULL, NULL);
        if (clientfd < 0) continue;

        char buffer[4096];
        int bytes = recv(clientfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes > 0) {
            buffer[bytes] = '\0';
            handleRequest(clientfd, std::string(buffer));
        }
        close(clientfd);
    }
}

void WebServer::stop() {
    if (sockfd_ >= 0) close(sockfd_);
}

void WebServer::handleRequest(int clientfd, const std::string& raw_req) {
    HttpRequest req = parseHttpRequest(raw_req);
    std::string response;

    if (req.url == "/" || req.url == "/index.html") {
        response = serveUI();
    } else if (req.url == "/api/traffic") {
        response = apiTraffic();
    } else {
        // 404
        response = "HTTP/1.1 404 Not Found\r\n\r\n";
    }

    send(clientfd, response.c_str(), response.size(), 0);
}

std::string WebServer::serveUI() {
    std::ifstream file("ui/index.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::string html = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n" + content;
    return html;
}

std::string WebServer::apiTraffic() {
    auto entries = Logger::getInstance().getEntries();
    std::ostringstream oss;
    oss << "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n[";
    for (size_t i = 0; i < entries.size(); ++i) {
        if (i > 0) oss << ",";
        oss << "{";
        bool first = true;
        for (const auto& e : entries[i]) {
            if (!first) oss << ",";
            oss << "\"" << e.first << "\":\"" << e.second << "\"";
            first = false;
        }
        oss << "}";
    }
    oss << "]";
    return oss.str();
}
