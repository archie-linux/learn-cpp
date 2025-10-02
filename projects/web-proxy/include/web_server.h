#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <string>

class WebServer {
public:
    WebServer(int port);
    void start();
    void stop();

private:
    int port_;
    int sockfd_;
    void handleRequest(int clientfd, const std::string& raw_req);
    std::string serveUI();
    std::string apiTraffic();  // JSON from logger
};

#endif
