#include "QueueManager.h"

void QueueManager::add_url(const std::string& url) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (visited_.find(url) == visited_.end()) {
        url_queue_.push(url);
        visited_.insert(url);
    }
}

void QueueManager::add_urls(const std::vector<std::string>& urls) {
    for (const auto& url : urls) {
        add_url(url);
    }
}

std::string QueueManager::get_next_url() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (url_queue_.empty()) return "";
    std::string url = url_queue_.front();
    url_queue_.pop();
    return url;
}

size_t QueueManager::size() {
    std::lock_guard<std::mutex> lock(mutex_);
    return url_queue_.size();
}

size_t QueueManager::size_visited() {
    std::lock_guard<std::mutex> lock(mutex_);
    return visited_.size();
}
