#include <iostream>

// Problematic approach - manual memory management
class ResourceLeaker 
{
public:
    void doSomething() 
    {
        int* ptr = new int(42);  // Allocate memory
        
        // If an exception occurs here, memory leaks!
        if (someCondition()) 
        {
            throw std::runtime_error("Something went wrong");
        }
        
        delete ptr;  // This might never execute!
    }
    
private:
    bool someCondition() { return true; }  // Simulate condition
};
