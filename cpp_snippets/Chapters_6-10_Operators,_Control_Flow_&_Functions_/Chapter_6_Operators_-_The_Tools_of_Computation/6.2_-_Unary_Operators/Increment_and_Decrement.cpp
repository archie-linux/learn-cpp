#include <iostream>

int main() 
{
    int x = 5;
    
    std::cout << "Initial x: " << x << '\n';          // 5
    
    // Post-increment: use current value, then increment
    std::cout << "x++: " << x++ << '\n';              // prints 5, x becomes 6
    std::cout << "After x++: " << x << '\n';          // 6
    
    // Pre-increment: increment first, then use new value
    std::cout << "++x: " << ++x << '\n';              // x becomes 7, prints 7
    std::cout << "After ++x: " << x << '\n';          // 7
    
    // Same logic for decrement
    std::cout << "x--: " << x-- << '\n';              // prints 7, x becomes 6
    std::cout << "--x: " << --x << '\n';              // x becomes 5, prints 5
    
    return 0;
}
