#ifndef PROXY_SERVER_H
#define PROXY_SERVER_H

#include <string>
#include <vector>
#include <map>

struct HttpRequest {
    std::string method;
    std::string url;
    std::string version;
    std::map<std::string, std::string> headers;
    std::string body;
};

struct HttpResponse {
    std::string version;
    int status;
    std::string reason;
    std::map<std::string, std::string> headers;
    std::string body;
};

class ProxyServer {
public:
    ProxyServer(int port);
    void start();
    void stop();

private:
    int port_;
    int sockfd_;
    void handleClient(int clientfd);
    HttpRequest parseRequest(const std::string& raw);
    HttpResponse forwardRequest(const HttpRequest& req);
    void logTraffic(const HttpRequest& req, const HttpResponse& res);
};

#endif
