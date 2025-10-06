#pragma once
#include <string>
#include <unordered_map>
#include <mutex>

class Storage {
public:
    bool insert(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    bool remove(const std::string& key);
private:
    std::unordered_map<std::string, std::string> data_;
    std::mutex mutex_;
};
