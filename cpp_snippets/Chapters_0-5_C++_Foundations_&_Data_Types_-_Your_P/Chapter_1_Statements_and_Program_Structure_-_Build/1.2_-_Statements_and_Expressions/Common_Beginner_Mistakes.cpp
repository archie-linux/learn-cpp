#include <iostream>

int main() 
{
    // ❌ Missing semicolon
    // std::cout << "Hello"
    
    // ✅ Correct
    std::cout << "Hello";
    
    // ❌ Missing quotes for text
    // std::cout << Hello World;
    
    // ✅ Correct
    std::cout << "Hello World";
    
    // ❌ Wrong slash direction in comments
    // std::cout << "Test"; \\ This won't work
    
    // ✅ Correct comment
    std::cout << "Test"; // This works fine
    
    return 0;
}
