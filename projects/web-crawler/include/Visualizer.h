#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <string>
#include <vector>
#include <map>

class Visualizer {
public:
    void add_node(const std::string& url, const std::vector<std::string>& links);
    void save_sitemap();
private:
    std::map<std::string, std::vector<std::string>> graph_;
};

#endif
