#include "Crawler.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <atomic>

Crawler::Crawler(const std::string& start_url, int max_threads, int max_urls)
    : queue_(), http_client_(), robots_(), parser_(), visualizer_(),
      max_threads_(max_threads), max_urls_(max_urls), running_(false), active_threads_(0) {
    queue_.add_url(start_url);
    std::cout << "Initialized crawler with start URL: " << start_url << "\n";
}

void Crawler::start() {
    std::filesystem::create_directory("data");
    running_ = true;
    std::cout << "Starting crawler with " << max_threads_ << " threads\n";
    for (int i = 0; i < max_threads_; ++i) {
        threads_.emplace_back(&Crawler::worker_thread, this);
        std::cout << "Started thread " << i << "\n";
    }
    for (auto& thread : threads_) {
        thread.join();
    }
    std::cout << "All threads completed\n";
    visualizer_.save_sitemap();
}

void Crawler::stop() {
    running_ = false;
    std::cout << "Stopping crawler\n";
}

void Crawler::worker_thread() {
    active_threads_++;
    while (running_) {
        std::string url = queue_.get_next_url();
        if (url.empty()) {
            if (active_threads_ == 1 && queue_.size() == 0) {
                // Last active thread with empty queue: stop crawler
                running_ = false;
                break;
            }
            std::cout << "Thread " << std::this_thread::get_id() << ": Queue empty, sleeping\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        if (queue_.size_visited() >= max_urls_) {
            running_ = false;
            break;
        }
        std::cout << "Thread " << std::this_thread::get_id() << ": Processing URL: " << url << "\n";
        
        if (!is_allowed(url)) {
            std::cout << "Thread " << std::this_thread::get_id() << ": URL disallowed: " << url << "\n";
            active_threads_--;
            return;
        }
        
        std::string content = http_client_.fetch(url);
        if (!content.empty()) {
            std::cout << "Thread " << std::this_thread::get_id() << ": Fetched content from " << url << "\n";
            std::vector<std::string> links = parser_.extract_links(content, url);
            queue_.add_urls(links);
            visualizer_.add_node(url, links);
            
            std::ofstream out("data/crawled_urls.txt", std::ios::app);
            out << url << "\n";
            std::cout << "Thread " << std::this_thread::get_id() << ": Saved URL: " << url << "\n";
        } else {
            std::cout << "Thread " << std::this_thread::get_id() << ": Failed to fetch " << url << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Rate limiting
    }
    active_threads_--;
    std::cout << "Thread " << std::this_thread::get_id() << ": Exiting\n";
}

bool Crawler::is_allowed(const std::string& url) {
    return robots_.is_allowed(url);
}
