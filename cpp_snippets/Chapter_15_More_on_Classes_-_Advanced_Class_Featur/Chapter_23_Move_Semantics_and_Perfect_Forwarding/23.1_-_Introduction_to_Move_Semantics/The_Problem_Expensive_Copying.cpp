#include <iostream>
#include <vector>
#include <string>
#include <utility>

class ExpensiveResource 
{
private:
    std::vector<int> data;
    std::string name;
    
public:
    // Constructor
    ExpensiveResource(const std::string& n, size_t size) : name(n), data(size) 
    {
        std::cout << "Creating " << name << " with " << size << " elements\n";
        
        // Fill with some data
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = static_cast<int>(i);
        }
    }
    
    // Copy constructor (expensive)
    ExpensiveResource(const ExpensiveResource& other) 
        : name(other.name + "_copy"), data(other.data) 
    {
        std::cout << "EXPENSIVE COPY: Copying " << other.name << " to " << name << '\n';
    }
    
    // Move constructor (cheap)
    ExpensiveResource(ExpensiveResource&& other) noexcept 
        : name(std::move(other.name)), data(std::move(other.data)) 
    {
        std::cout << "EFFICIENT MOVE: Moving " << name << '\n';
        other.name = "moved_from";
    }
    
    // Copy assignment operator
    ExpensiveResource& operator=(const ExpensiveResource& other) 
    {
        if (this != &other) 
        {
            name = other.name + "_assigned";
            data = other.data;
            std::cout << "EXPENSIVE COPY ASSIGNMENT\n";
        }
        return *this;
    }
    
    // Move assignment operator
    ExpensiveResource& operator=(ExpensiveResource&& other) noexcept 
    {
        if (this != &other) 
        {
            name = std::move(other.name);
            data = std::move(other.data);
            other.name = "moved_from";
            std::cout << "EFFICIENT MOVE ASSIGNMENT\n";
        }
        return *this;
    }
    
    // Destructor
    ~ExpensiveResource() 
    {
        std::cout << "Destroying " << name << '\n';
    }
    
    const std::string& getName() const { return name; }
    size_t size() const { return data.size(); }
};

// Function that returns by value
ExpensiveResource createResource(const std::string& name, size_t size) 
{
    return ExpensiveResource(name, size);  // Move semantics kicks in
}

void demonstrateMoveSemantics() 
{
    std::cout << "=== Move Semantics Demo ===\n";
    
    // Direct construction
    ExpensiveResource res1("Resource1", 1000);
    
    // Move construction (efficient)
    ExpensiveResource res2 = std::move(res1);
    std::cout << "res1 name after move: " << res1.getName() << '\n';
    std::cout << "res2 name: " << res2.getName() << '\n';
    
    // Function return value (automatic move)
    ExpensiveResource res3 = createResource("Resource3", 2000);
    
    // Move assignment
    res1 = std::move(res3);
    std::cout << "res1 name after move assignment: " << res1.getName() << '\n';
    
    // Copy vs Move in containers
    std::vector<ExpensiveResource> resources;
    resources.reserve(3);  // Avoid reallocations
    
    std::cout << "\n--- Adding to vector ---\n";
    resources.push_back(createResource("VecResource1", 500));  // Move
    resources.emplace_back("VecResource2", 750);               // Direct construction
    
    ExpensiveResource temp("Temp", 300);
    resources.push_back(temp);              // Copy (temp is lvalue)
    resources.push_back(std::move(temp));   // Move
}
