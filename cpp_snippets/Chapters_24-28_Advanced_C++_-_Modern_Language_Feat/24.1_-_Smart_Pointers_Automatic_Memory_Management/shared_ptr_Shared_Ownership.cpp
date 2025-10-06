#include <memory>
#include <vector>
#include <thread>

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
    }
    
    ~Logger() {
        std::cout << "Logger destroyed\n";
    }
};

class Service {
private:
    std::shared_ptr<Logger> logger_;
    std::string name_;
    
public:
    Service(const std::string& name, std::shared_ptr<Logger> logger) 
        : name_(name), logger_(std::move(logger)) {}
    
    void doWork() {
        logger_->log(name_ + " is working");
    }
};

void sharedPtrExamples() {
    // Shared logger across multiple services
    auto logger = std::make_shared<Logger>();
    
    std::vector<std::unique_ptr<Service>> services;
    services.push_back(std::make_unique<Service>("Service1", logger));
    services.push_back(std::make_unique<Service>("Service2", logger));
    services.push_back(std::make_unique<Service>("Service3", logger));
    
    // All services share the same logger
    for (auto& service : services) {
        service->doWork();
    }
    
    std::cout << "Logger use count: " << logger.use_count() << "\n";
    
    // Logger automatically destroyed when last shared_ptr is destroyed
}

// Thread-safe shared ownership
void threadSafeSharing() {
    auto resource = std::make_shared<Resource>(100);
    
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([resource]() {  // Capture by value (copies shared_ptr)
            resource->use();  // Thread-safe reference counting
        });
    }
    
    for (auto& t : threads) {
        t.join();
    }
}
