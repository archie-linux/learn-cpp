#include <iostream>
#include <string>

// Overloaded functions - same name, different parameters
int add(int a, int b) 
{
    std::cout << "Adding integers: ";
    return a + b;
}

double add(double a, double b) 
{
    std::cout << "Adding doubles: ";
    return a + b;
}

std::string add(const std::string& a, const std::string& b) 
{
    std::cout << "Concatenating strings: ";
    return a + b;
}

// Overloaded print functions
void print(int value) 
{
    std::cout << "Integer: " << value << '\n';
}

void print(double value) 
{
    std::cout << "Double: " << value << '\n';
}

void print(const std::string& value) 
{
    std::cout << "String: " << value << '\n';
}

void print(bool value) 
{
    std::cout << "Boolean: " << (value ? "true" : "false") << '\n';
}

int main() 
{
    // Compiler chooses correct overload based on arguments
    std::cout << add(5, 10) << '\n';           // Calls int version
    std::cout << add(3.14, 2.86) << '\n';     // Calls double version
    std::cout << add(std::string("Hello "), std::string("World")) << '\n'; // Calls string version
    
    std::cout << '\n';
    
    // Compiler determines type and calls appropriate print function
    print(42);                    // int version
    print(3.14159);              // double version
    print("Hello World");        // string version
    print(true);                 // bool version
    
    return 0;
}
