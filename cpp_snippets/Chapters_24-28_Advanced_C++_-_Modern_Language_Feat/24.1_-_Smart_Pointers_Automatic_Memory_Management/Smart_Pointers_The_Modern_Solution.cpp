#include <memory>
#include <iostream>
#include <vector>

class Resource {
public:
    Resource(int value) : data_(value) {
        std::cout << "Resource " << data_ << " created\n";
    }
    
    ~Resource() {
        std::cout << "Resource " << data_ << " destroyed\n";
    }
    
    void use() const {
        std::cout << "Using resource " << data_ << "\n";
    }
    
private:
    int data_;
};

void demonstrateSmartPointers() {
    // unique_ptr: Exclusive ownership
    std::unique_ptr<Resource> unique = std::make_unique<Resource>(1);
    unique->use();
    // Automatically deleted when unique goes out of scope
    
    // shared_ptr: Shared ownership
    std::shared_ptr<Resource> shared1 = std::make_shared<Resource>(2);
    {
        std::shared_ptr<Resource> shared2 = shared1;  // Reference count: 2
        shared2->use();
    }  // shared2 destroyed, reference count: 1
    shared1->use();  // Resource still alive
    // Resource deleted when shared1 goes out of scope
}
