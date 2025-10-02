#include <iostream>
#include <string>

int main() 
{
    std::cout << "Demonstrating Input Buffer Issues\n";
    std::cout << "=================================\n";
    
    int age;
    std::string name;
    
    // ❌ This pattern causes problems:
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    std::cout << "Enter your name: ";
    // std::getline(std::cin, name);  // This would be skipped!
    
    // ✅ Solution: Clear the buffer
    std::cin.ignore();  // Consume the leftover newline
    std::getline(std::cin, name);
    
    std::cout << "Age: " << age << ", Name: " << name << '\n';
    
    return 0;
}
