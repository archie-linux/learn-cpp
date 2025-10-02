#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

class Resource 
{
private:
    std::string name;
    static int instanceCount;
    
public:
    Resource(const std::string& n) : name(n) 
    {
        ++instanceCount;
        std::cout << "Created resource: " << name << " (total: " << instanceCount << ")\n";
        
        // Simulate potential failure during construction
        if (name == "fail") 
        {
            throw std::runtime_error("Resource construction failed");
        }
    }
    
    ~Resource() 
    {
        --instanceCount;
        std::cout << "Destroyed resource: " << name << " (remaining: " << instanceCount << ")\n";
    }
    
    Resource(const Resource& other) : name(other.name + "_copy") 
    {
        ++instanceCount;
        std::cout << "Copied resource: " << name << "\n";
    }
    
    Resource& operator=(const Resource& other) 
    {
        if (this != &other) 
        {
            name = other.name + "_assigned";
            std::cout << "Assigned resource: " << name << "\n";
        }
        return *this;
    }
    
    const std::string& getName() const { return name; }
    static int getInstanceCount() { return instanceCount; }
};

int Resource::instanceCount = 0;

// ❌ No exception safety - can leak resources
class UnsafeContainer 
{
private:
    Resource* resource1;
    Resource* resource2;
    
public:
    UnsafeContainer(const std::string& name1, const std::string& name2)
        : resource1(nullptr), resource2(nullptr) 
    {
        resource1 = new Resource(name1);  // If this throws, no leak
        resource2 = new Resource(name2);  // If this throws, resource1 leaks!
    }
    
    ~UnsafeContainer() 
    {
        delete resource1;
        delete resource2;
    }
};

// ✅ Basic exception safety - no leaks, but object may be in invalid state
class BasicSafeContainer 
{
private:
    std::unique_ptr<Resource> resource1;
    std::unique_ptr<Resource> resource2;
    
public:
    BasicSafeContainer(const std::string& name1, const std::string& name2) 
    {
        resource1 = std::make_unique<Resource>(name1);
        resource2 = std::make_unique<Resource>(name2);
        // If second construction fails, first resource is automatically cleaned up
    }
    
    void replaceResources(const std::string& name1, const std::string& name2) 
    {
        auto temp1 = std::make_unique<Resource>(name1);  // May throw
        auto temp2 = std::make_unique<Resource>(name2);  // May throw
        
        // Only modify state after all operations that can throw have succeeded
        resource1 = std::move(temp1);
        resource2 = std::move(temp2);
    }
};

// ✅ Strong exception safety - operation succeeds completely or leaves object unchanged
class StrongSafeContainer 
{
private:
    std::vector<std::unique_ptr<Resource>> resources;
    
public:
    StrongSafeContainer() = default;
    
    void addResource(const std::string& name) 
    {
        // Create resource first (may throw)
        auto newResource = std::make_unique<Resource>(name);
        
        // Only modify container after successful construction
        resources.push_back(std::move(newResource));
        // Vector::push_back provides strong exception safety guarantee
    }
    
    void replaceAllResources(const std::vector<std::string>& names) 
    {
        // Create all new resources first
        std::vector<std::unique_ptr<Resource>> newResources;
        newResources.reserve(names.size());
        
        for (const auto& name : names) 
        {
            newResources.push_back(std::make_unique<Resource>(name));
        }
        
        // Only replace after all constructions succeed
        resources = std::move(newResources);
    }
    
    size_t size() const { return resources.size(); }
    
    const Resource& getResource(size_t index) const 
    {
        if (index >= resources.size()) 
        {
            throw std::out_of_range("Resource index out of range");
        }
        return *resources[index];
    }
};

// ✅ No-throw guarantee - operation cannot fail
class NoThrowContainer 
{
private:
    std::vector<std::string> resourceNames;
    
public:
    // No-throw operations
    size_t size() const noexcept { return resourceNames.size(); }
    bool empty() const noexcept { return resourceNames.empty(); }
    
    void clear() noexcept 
    {
        resourceNames.clear();  // vector::clear() is noexcept
    }
    
    void swap(NoThrowContainer& other) noexcept 
    {
        resourceNames.swap(other.resourceNames);  // vector::swap() is noexcept
    }
    
    // Operations that can throw are clearly marked
    void addResourceName(const std::string& name) 
    {
        resourceNames.push_back(name);  // May throw std::bad_alloc
    }
};

void demonstrateExceptionSafety() 
{
    std::cout << "\n=== Exception Safety Demo ===\n";
    
    // Test basic safety
    std::cout << "\n--- Basic Safety Test ---\n";
    try 
    {
        BasicSafeContainer container("resource1", "resource2");
        std::cout << "Container created successfully\n";
        
        // This will fail on second resource, but won't leak
        container.replaceResources("resource3", "fail");
    }
    catch (const std::exception& e) 
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
    
    // Test strong safety
    std::cout << "\n--- Strong Safety Test ---\n";
    try 
    {
        StrongSafeContainer container;
        container.addResource("resource1");
        container.addResource("resource2");
        std::cout << "Container has " << container.size() << " resources\n";
        
        // This will fail, but container remains in original state
        std::vector<std::string> badNames = {"resource3", "fail", "resource4"};
        container.replaceAllResources(badNames);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Caught exception: " << e.what() << "\n";
        // Container still has original 2 resources
    }
    
    std::cout << "Final resource count: " << Resource::getInstanceCount() << "\n";
}
