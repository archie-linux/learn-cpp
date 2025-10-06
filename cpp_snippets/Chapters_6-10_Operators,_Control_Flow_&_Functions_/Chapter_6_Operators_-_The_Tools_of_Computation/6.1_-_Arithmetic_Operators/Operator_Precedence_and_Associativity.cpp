#include <iostream>

int main() 
{
    // Understanding precedence
    int result1 = 2 + 3 * 4;        // 14, not 20 (multiplication first)
    int result2 = (2 + 3) * 4;      // 20 (parentheses override precedence)
    
    // Multiple operations of same precedence
    int result3 = 10 - 5 - 2;       // 3 (left-to-right associativity)
    int result4 = 2 * 3 * 4;        // 24 (left-to-right associativity)
    
    std::cout << "2 + 3 * 4 = " << result1 << '\n';
    std::cout << "(2 + 3) * 4 = " << result2 << '\n';
    std::cout << "10 - 5 - 2 = " << result3 << '\n';
    std::cout << "2 * 3 * 4 = " << result4 << '\n';
    
    return 0;
}
