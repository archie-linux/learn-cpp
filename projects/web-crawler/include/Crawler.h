#ifndef CRAWLER_H
#define CRAWLER_H

#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include "QueueManager.h"
#include "HttpClient.h"
#include "RobotsTxt.h"
#include "Parser.h"
#include "Visualizer.h"

class Crawler {
public:
    Crawler(const std::string& start_url, int max_threads, int max_urls);
    void start();
    void stop();
private:
    void worker_thread();
    bool is_allowed(const std::string& url);
    
    QueueManager queue_;
    HttpClient http_client_;
    RobotsTxt robots_;
    Parser parser_;
    Visualizer visualizer_;
    std::vector<std::thread> threads_;
    int max_threads_;
    int max_urls_;
    std::atomic<bool> running_;
    std::atomic<int> active_threads_;
};

#endif
