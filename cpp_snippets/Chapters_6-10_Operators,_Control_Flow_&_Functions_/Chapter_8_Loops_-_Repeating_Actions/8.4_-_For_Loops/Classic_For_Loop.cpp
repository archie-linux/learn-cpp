#include <iostream>

int main() 
{
    // Basic counting
    std::cout << "Counting up: ";
    for (int i = 1; i <= 10; ++i) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // Counting down
    std::cout << "Counting down: ";
    for (int i = 10; i >= 1; --i) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // Different increment
    std::cout << "Even numbers: ";
    for (int i = 2; i <= 20; i += 2) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    return 0;
}
