#include <iostream>
#include <string>

// Define the Employee struct type
struct Employee 
{
    int id{};           // Data member (value-initialized)
    std::string name;   // Data member
    std::string title;  // Data member
    int age{};         // Data member  
    double wage{};     // Data member
};

int main() 
{
    // Create Employee objects
    Employee joe{};     // All members value-initialized
    Employee sarah{};   // Separate Employee object
    
    // Access members using the dot operator
    joe.id = 101;
    joe.name = "Joe Smith";
    joe.title = "Developer";
    joe.age = 32;
    joe.wage = 75000.0;
    
    sarah.id = 102;
    sarah.name = "Sarah Johnson";
    sarah.title = "Manager";
    sarah.age = 28;
    sarah.wage = 85000.0;
    
    // Use the data
    std::cout << joe.name << " (ID: " << joe.id << ") earns $" << joe.wage << '\n';
    std::cout << sarah.name << " (ID: " << sarah.id << ") earns $" << sarah.wage << '\n';
    
    if (sarah.wage > joe.wage) 
    {
        std::cout << sarah.name << " earns more than " << joe.name << '\n';
    }
    
    return 0;
}
