#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser {
public:
    std::vector<std::string> extract_links(const std::string& html, const std::string& base_url);
};

#endif
