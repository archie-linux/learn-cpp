#include <iostream>

int main() 
{
    // Expression statements (end with semicolon)
    std::cout << "Hello World";           // Output statement
    int age = 25;                         // Declaration + initialization
    age = age + 1;                        // Assignment statement
    
    // Compound statement (block)
    {
        int localVariable = 10;           // Only exists in this block
        std::cout << localVariable << '\n';
    }
    
    // Return statement
    return 0;
}
