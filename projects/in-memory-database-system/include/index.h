#pragma once
#include <string>
#include <map>

class Index {
public:
    void add(const std::string& key, size_t offset);
    size_t find(const std::string& key);
    void remove(const std::string& key);
private:
    std::map<std::string, size_t> index_; // Simplified B+ tree representation
};
