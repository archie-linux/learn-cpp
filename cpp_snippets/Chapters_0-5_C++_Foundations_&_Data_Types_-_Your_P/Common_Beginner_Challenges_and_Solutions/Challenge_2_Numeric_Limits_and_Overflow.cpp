#include <iostream>
#include <limits>

int main() 
{
    std::cout << "Understanding Numeric Limits\n";
    std::cout << "============================\n";
    
    // Display limits for common types
    std::cout << "int range: " << std::numeric_limits<int>::min() 
              << " to " << std::numeric_limits<int>::max() << '\n';
    
    std::cout << "double range: " << std::numeric_limits<double>::min() 
              << " to " << std::numeric_limits<double>::max() << '\n';
    
    // Demonstrate overflow
    int maxInt = std::numeric_limits<int>::max();
    std::cout << "Maximum int: " << maxInt << '\n';
    std::cout << "Max int + 1: " << (maxInt + 1) << " (overflow!)\n";
    
    // Safe arithmetic
    if (maxInt > std::numeric_limits<int>::max() - 1) 
    {
        std::cout << "Cannot safely add 1 to maxInt\n";
    }
    
    return 0;
}
