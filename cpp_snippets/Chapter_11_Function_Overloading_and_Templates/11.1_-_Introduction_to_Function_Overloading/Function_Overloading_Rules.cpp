#include <iostream>

// Overloaded functions for different types
void print(int value) 
{
    std::cout << "Printing int: " << value << '\n';
}

void print(double value) 
{
    std::cout << "Printing double: " << value << '\n';
}

void print(const std::string& value) 
{
    std::cout << "Printing string: " << value << '\n';
}

int main() 
{
    print(42);           // Calls print(int)
    print(3.14);         // Calls print(double)
    print("Hello");      // Calls print(const std::string&)
    return 0;
}
