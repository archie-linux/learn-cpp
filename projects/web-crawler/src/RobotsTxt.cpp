#include "RobotsTxt.h"
#include "HttpClient.h"
#include <sstream>

bool RobotsTxt::is_allowed(const std::string& url) {
    std::string domain = url.substr(0, url.find("/", 8));
    if (disallowed_.find(domain) == disallowed_.end()) {
        fetch_robots_txt(domain);
    }
    
    for (const auto& path : disallowed_[domain]) {
        if (url.find(path) != std::string::npos) return false;
    }
    return true;
}

void RobotsTxt::fetch_robots_txt(const std::string& domain) {
    HttpClient client;
    std::string content = client.fetch(domain + "/robots.txt");
    std::vector<std::string> paths;
    
    std::istringstream iss(content);
    std::string line;
    while (std::getline(iss, line)) {
        if (line.find("Disallow:") != std::string::npos) {
            std::string path = line.substr(line.find(":") + 1);
            paths.push_back(path);
        }
    }
    disallowed_[domain] = paths;
}
