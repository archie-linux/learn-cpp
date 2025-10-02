#include <vector>
#include <memory>
#include <algorithm>

class MovableResource {
private:
    std::unique_ptr<int[]> data_;
    size_t size_;
    
public:
    // Constructor
    explicit MovableResource(size_t size) 
        : data_(std::make_unique<int[]>(size)), size_(size) {
        std::cout << "Constructor: allocated " << size_ << " elements\n";
        
        // Initialize with some values
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = static_cast<int>(i);
        }
    }
    
    // Copy constructor (expensive)
    MovableResource(const MovableResource& other) 
        : data_(std::make_unique<int[]>(other.size_)), size_(other.size_) {
        std::cout << "Copy constructor: copying " << size_ << " elements\n";
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
    
    // Move constructor (cheap)
    MovableResource(MovableResource&& other) noexcept 
        : data_(std::move(other.data_)), size_(other.size_) {
        std::cout << "Move constructor: transferred " << size_ << " elements\n";
        other.size_ = 0;  // Reset moved-from object
    }
    
    // Copy assignment operator
    MovableResource& operator=(const MovableResource& other) {
        if (this != &other) {
            std::cout << "Copy assignment: copying " << other.size_ << " elements\n";
            data_ = std::make_unique<int[]>(other.size_);
            size_ = other.size_;
            std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
        }
        return *this;
    }
    
    // Move assignment operator
    MovableResource& operator=(MovableResource&& other) noexcept {
        if (this != &other) {
            std::cout << "Move assignment: transferred " << other.size_ << " elements\n";
            data_ = std::move(other.data_);
            size_ = other.size_;
            other.size_ = 0;
        }
        return *this;
    }
    
    size_t size() const { return size_; }
    int& operator[](size_t index) { return data_[index]; }
    const int& operator[](size_t index) const { return data_[index]; }
};

void demonstrateMoveSemantics() {
    std::vector<MovableResource> resources;
    
    // Move construction
    resources.push_back(MovableResource(1000));  // Temporary object moved
    
    MovableResource large(2000);
    resources.push_back(std::move(large));       // Explicit move
    
    // Move in algorithms
    std::vector<MovableResource> moved_resources;
    moved_resources.reserve(resources.size());
    
    std::move(resources.begin(), resources.end(), 
              std::back_inserter(moved_resources));
}
