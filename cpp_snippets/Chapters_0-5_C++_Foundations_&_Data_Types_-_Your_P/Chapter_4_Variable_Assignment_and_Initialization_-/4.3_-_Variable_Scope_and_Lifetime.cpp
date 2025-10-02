#include <iostream>

// Global variable (avoid when possible)
int globalCounter = 0;

int main() 
{
    std::cout << "Variable Scope Demonstration\n";
    std::cout << "============================\n";
    
    // Local variable in main function
    int mainVariable = 10;
    
    std::cout << "Main variable: " << mainVariable << '\n';
    std::cout << "Global counter: " << globalCounter << '\n';
    
    // Block scope
    {
        int blockVariable = 20;           // Only exists in this block
        mainVariable = 15;                // Can modify outer variable
        globalCounter++;                  // Can modify global variable
        
        std::cout << "\nInside block:\n";
        std::cout << "Block variable: " << blockVariable << '\n';
        std::cout << "Main variable: " << mainVariable << '\n';
        std::cout << "Global counter: " << globalCounter << '\n';
        
        // Another nested block
        {
            int deepVariable = 30;
            std::cout << "Deep variable: " << deepVariable << '\n';
        }
        // deepVariable no longer exists here!
    }
    // blockVariable no longer exists here!
    
    std::cout << "\nBack in main:\n";
    std::cout << "Main variable: " << mainVariable << '\n';
    std::cout << "Global counter: " << globalCounter << '\n';
    
    // This would cause an error:
    // std::cout << blockVariable;  // Error: not in scope
    
    return 0;
}
