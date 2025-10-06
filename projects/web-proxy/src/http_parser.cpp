#include "http_parser.h"
#include <sstream>
#include <map>

HttpRequest parseHttpRequest(const std::string& raw) {
    // Implementation similar to ProxyServer::parseRequest; can factor out later
    HttpRequest req;
    std::istringstream iss(raw);
    std::string line;
    std::getline(iss, line);
    std::istringstream first(line);
    first >> req.method >> req.url >> req.version;

    while (std::getline(iss, line) && line != "\r") {
        size_t pos = line.find(": ");
        if (pos != std::string::npos) {
            req.headers[line.substr(0, pos)] = line.substr(pos + 2);
        }
    }
    // Body after
    size_t body_pos = raw.find("\r\n\r\n");
    if (body_pos != std::string::npos) {
        req.body = raw.substr(body_pos + 4);
    }
    return req;
}

HttpResponse parseHttpResponse(const std::string& raw) {
    HttpResponse res;
    std::istringstream iss(raw);
    std::string line;
    std::getline(iss, line);
    std::istringstream first(line);
    first >> res.version >> res.status;
    // Reason is rest of line
    std::getline(iss, line);  // Skip if needed
    res.reason = "OK";  // Minimal

    while (std::getline(iss, line) && line != "\r") {
        size_t pos = line.find(": ");
        if (pos != std::string::npos) {
            res.headers[line.substr(0, pos)] = line.substr(pos + 2);
        }
    }
    size_t body_pos = raw.find("\r\n\r\n");
    if (body_pos != std::string::npos) {
        res.body = raw.substr(body_pos + 4);
    }
    return res;
}
