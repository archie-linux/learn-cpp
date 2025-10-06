#include <iostream>
#include <memory>
#include <vector>

class Resource 
{
private:
    int id;
    
public:
    explicit Resource(int identifier) : id(identifier) 
    {
        std::cout << "Resource " << id << " created\n";
    }
    
    ~Resource() 
    {
        std::cout << "Resource " << id << " destroyed\n";
    }
    
    void doWork() 
    {
        std::cout << "Resource " << id << " is working\n";
    }
    
    int getId() const { return id; }
};

// Modern approach with smart pointers
class ResourceManager 
{
public:
    void demonstrateUniquePtr() 
    {
        std::cout << "=== unique_ptr Demo ===\n";
        
        // Automatic memory management
        std::unique_ptr<Resource> ptr = std::make_unique<Resource>(1);
        ptr->doWork();
        
        // Transfer ownership
        std::unique_ptr<Resource> ptr2 = std::move(ptr);
        // ptr is now nullptr, ptr2 owns the resource
        
        if (ptr == nullptr) 
        {
            std::cout << "ptr is now null\n";
        }
        
        ptr2->doWork();
        
        // Resource automatically destroyed when ptr2 goes out of scope
    }
    
    void demonstrateSharedPtr() 
    {
        std::cout << "\n=== shared_ptr Demo ===\n";
        
        std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(2);
        std::cout << "Reference count: " << ptr1.use_count() << '\n';
        
        {
            std::shared_ptr<Resource> ptr2 = ptr1;  // Share ownership
            std::cout << "Reference count: " << ptr1.use_count() << '\n';
            
            std::shared_ptr<Resource> ptr3 = ptr1;  // Another shared owner
            std::cout << "Reference count: " << ptr1.use_count() << '\n';
            
            ptr2->doWork();
            ptr3->doWork();
            
        }  // ptr2 and ptr3 destroyed here
        
        std::cout << "Reference count: " << ptr1.use_count() << '\n';
        ptr1->doWork();
        
        // Resource destroyed when ptr1 goes out of scope
    }
    
    void demonstrateWeakPtr() 
    {
        std::cout << "\n=== weak_ptr Demo ===\n";
        
        std::shared_ptr<Resource> shared = std::make_shared<Resource>(3);
        std::weak_ptr<Resource> weak = shared;  // Doesn't increase ref count
        
        std::cout << "Shared ref count: " << shared.use_count() << '\n';
        std::cout << "Weak expired? " << weak.expired() << '\n';
        
        // Use weak_ptr safely
        if (auto locked = weak.lock()) 
        {
            locked->doWork();
            std::cout << "Successfully accessed resource through weak_ptr\n";
        }
        
        shared.reset();  // Release the shared_ptr
        
        std::cout << "After reset - Weak expired? " << weak.expired() << '\n';
        
        // Attempting to lock now returns nullptr
        if (auto locked = weak.lock()) 
        {
            locked->doWork();  // Won't execute
        }
        else 
        {
            std::cout << "weak_ptr is expired, cannot access resource\n";
        }
    }
};

int main() 
{
    ResourceManager manager;
    
    manager.demonstrateUniquePtr();
    manager.demonstrateSharedPtr();
    manager.demonstrateWeakPtr();
    
    return 0;
}
