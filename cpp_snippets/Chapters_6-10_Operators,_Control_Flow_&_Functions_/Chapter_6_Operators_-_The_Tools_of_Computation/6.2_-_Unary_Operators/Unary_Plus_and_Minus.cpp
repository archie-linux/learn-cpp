#include <iostream>

int main() 
{
    int positive = 42;
    int negative = -positive;    // Unary minus
    int unchanged = +positive;   // Unary plus (rarely used)
    
    std::cout << "Original: " << positive << '\n';    // 42
    std::cout << "Negated: " << negative << '\n';     // -42
    std::cout << "Unchanged: " << unchanged << '\n';   // 42
    
    // Useful for clarity
    int temperature = -15;       // Negative temperature
    int balance = +1000;         // Positive balance (explicit)
    
    return 0;
}
