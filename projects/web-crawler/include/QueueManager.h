#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include <string>
#include <queue>
#include <mutex>
#include <set>

class QueueManager {
public:
    void add_url(const std::string& url);
    void add_urls(const std::vector<std::string>& urls);
    std::string get_next_url();
    size_t size();
    size_t size_visited();
private:
    std::queue<std::string> url_queue_;
    std::set<std::string> visited_;
    std::mutex mutex_;
};

#endif
