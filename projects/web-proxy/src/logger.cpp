#include "logger.h"
#include <map>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::addEntry(const HttpRequest& req, const HttpResponse& res) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::map<std::string, std::string> entry;
    entry["method"] = req.method;
    entry["url"] = req.url;
    entry["status"] = std::to_string(res.status);
    entry["size"] = std::to_string(res.body.size());
    entry["time"] = "now";  // Add timestamp lib if needed
    entries_.push_back(entry);
}

std::vector<std::map<std::string, std::string>> Logger::getEntries() {
    std::lock_guard<std::mutex> lock(mutex_);
    return entries_;
}

void Logger::clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    entries_.clear();
}
