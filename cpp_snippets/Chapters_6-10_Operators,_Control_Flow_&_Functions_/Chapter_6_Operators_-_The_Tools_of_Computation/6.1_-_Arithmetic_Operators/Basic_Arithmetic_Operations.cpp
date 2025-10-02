#include <iostream>

int main() 
{
    int a = 15, b = 4;
    
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "Addition: " << a << " + " << b << " = " << (a + b) << '\n';      // 19
    std::cout << "Subtraction: " << a << " - " << b << " = " << (a - b) << '\n';   // 11
    std::cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << '\n'; // 60
    std::cout << "Division: " << a << " / " << b << " = " << (a / b) << '\n';       // 3 (integer division!)
    std::cout << "Modulus: " << a << " % " << b << " = " << (a % b) << '\n';        // 3
    
    // Floating-point division
    double x = 15.0, y = 4.0;
    std::cout << "Float division: " << x << " / " << y << " = " << (x / y) << '\n'; // 3.75
    
    return 0;
}
