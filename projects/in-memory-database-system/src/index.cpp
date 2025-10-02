#include "index.h"

void Index::add(const std::string& key, size_t offset) {
    index_[key] = offset;
}

size_t Index::find(const std::string& key) {
    auto it = index_.find(key);
    if (it != index_.end()) return it->second;
    return 0;
}

void Index::remove(const std::string& key) {
    index_.erase(key);
}
