#include <iostream>

int globalVariable = 100;  // Global scope

void demonstrateScope() 
{
    int localVar = 50;     // Local to this function
    
    std::cout << "Inside function:\n";
    std::cout << "  Local variable: " << localVar << '\n';
    std::cout << "  Global variable: " << globalVariable << '\n';
    
    // Block scope
    {
        int blockVar = 25;  // Only exists in this block
        localVar = 75;      // Can modify outer local variable
        
        std::cout << "  Inside block:\n";
        std::cout << "    Block variable: " << blockVar << '\n';
        std::cout << "    Modified local: " << localVar << '\n';
    }
    // blockVar no longer exists here
    
    std::cout << "  After block, local: " << localVar << '\n';
}

void anotherFunction() 
{
    // int x = localVar;  // Error! localVar not in scope
    int x = globalVariable;  // OK, global variables accessible everywhere
    
    std::cout << "Another function can access global: " << x << '\n';
}

int main() 
{
    std::cout << "In main, global variable: " << globalVariable << '\n';
    
    demonstrateScope();
    anotherFunction();
    
    return 0;
}
