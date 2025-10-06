#include "Visualizer.h"
#include <fstream>

void Visualizer::add_node(const std::string& url, const std::vector<std::string>& links) {
    graph_[url] = links;
}

void Visualizer::save_sitemap() {
    std::ofstream out("data/sitemap.dot");
    out << "digraph G {\n";
    for (const auto& node : graph_) {
        for (const auto& link : node.second) {
            out << "\"" << node.first << "\" -> \"" << link << "\";\n";
        }
    }
    out << "}\n";
}
