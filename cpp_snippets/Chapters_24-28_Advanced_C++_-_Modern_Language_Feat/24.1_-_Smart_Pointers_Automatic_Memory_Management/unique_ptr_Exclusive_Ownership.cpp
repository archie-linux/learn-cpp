#include <memory>
#include <vector>
#include <algorithm>

class Database {
public:
    void connect() { std::cout << "Connected to database\n"; }
    void disconnect() { std::cout << "Disconnected from database\n"; }
    ~Database() { disconnect(); }
};

class DataManager {
private:
    std::unique_ptr<Database> db_;
    
public:
    DataManager() : db_(std::make_unique<Database>()) {
        db_->connect();
    }
    
    // Move-only semantics (no copying)
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;
    
    DataManager(DataManager&& other) noexcept : db_(std::move(other.db_)) {}
    DataManager& operator=(DataManager&& other) noexcept {
        if (this != &other) {
            db_ = std::move(other.db_);
        }
        return *this;
    }
    
    // Transfer ownership
    std::unique_ptr<Database> releaseDatabase() {
        return std::move(db_);
    }
};

// Factory function returning unique ownership
std::unique_ptr<Resource> createResource(int value) {
    return std::make_unique<Resource>(value);
}

void uniquePtrExamples() {
    // Array management
    std::unique_ptr<int[]> numbers = std::make_unique<int[]>(100);
    
    // Container of unique_ptrs
    std::vector<std::unique_ptr<Resource>> resources;
    resources.push_back(createResource(10));
    resources.push_back(createResource(20));
    
    // Move semantics in algorithms
    std::sort(resources.begin(), resources.end(),
        [](const std::unique_ptr<Resource>& a, const std::unique_ptr<Resource>& b) {
            return a.get() < b.get();  // Sort by pointer address
        });
}
