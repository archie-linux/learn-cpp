#ifndef ROBOTS_TXT_H
#define ROBOTS_TXT_H

#include <string>
#include <vector>
#include <map>

class RobotsTxt {
public:
    bool is_allowed(const std::string& url);
private:
    std::map<std::string, std::vector<std::string>> disallowed_;
    void fetch_robots_txt(const std::string& domain);
};

#endif
