#include <iostream>
#include <cmath>

int main() 
{
    double a = 0.1 + 0.2;
    double b = 0.3;
    
    std::cout << std::fixed;
    std::cout << "a = " << a << '\n';                    // 0.300000
    std::cout << "b = " << b << '\n';                    // 0.300000
    std::cout << "a == b: " << (a == b) << '\n';        // false! (floating-point precision)
    
    // Correct way to compare floating-point numbers
    const double epsilon = 1e-9;
    bool areEqual = std::abs(a - b) < epsilon;
    std::cout << "Are they approximately equal? " << areEqual << '\n'; // true
    
    return 0;
}
