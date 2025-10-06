#include "storage.h"
#include <stdexcept>

bool Storage::insert(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    return data_.emplace(key, value).second;
}

std::string Storage::get(const std::string& key) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = data_.find(key);
    if (it != data_.end()) return it->second;
    return "";
}

bool Storage::remove(const std::string& key) {
    std::lock_guard<std::mutex> lock(mutex_);
    return data_.erase(key) > 0;
}
