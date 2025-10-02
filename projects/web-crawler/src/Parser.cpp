#include "Parser.h"
#include <regex>
#include <iostream>

std::vector<std::string> Parser::extract_links(const std::string& html, const std::string& base_url) {
    std::vector<std::string> links;
    std::regex link_regex("<a\\s+[^>]*href\\s*=\\s*\"([^\"]+)\"");
    auto begin = std::sregex_iterator(html.begin(), html.end(), link_regex);
    auto end = std::sregex_iterator();
    
    for (auto i = begin; i != end; ++i) {
        std::string link = i->str(1);
        if (link.find("http") == 0) {
            links.push_back(link);
        } else if (link[0] == '/') {
            links.push_back(base_url + link);
        } else if (link[0] == '#') {
            // Skip anchor links
            continue;
        } else {
            links.push_back(base_url + "/" + link);
        }
    }
    std::cout << "Extracted " << links.size() << " links from " << base_url << "\n";
    return links;
}
