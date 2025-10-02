#ifndef LOGGER_H
#define LOGGER_H

#include "proxy_server.h"
#include <vector>
#include <mutex>

class Logger {
public:
    static Logger& getInstance();
    void addEntry(const HttpRequest& req, const HttpResponse& res);
    std::vector<std::map<std::string, std::string>> getEntries();  // JSON-friendly
    void clear();

private:
    Logger() = default;
    std::vector<std::map<std::string, std::string>> entries_;
    std::mutex mutex_;
};

#endif
