#include <iostream>

int main() 
{
    std::cout << "Testing different return scenarios:\n";
    
    bool simulateError = false;  // Change to true to simulate error
    
    if (simulateError) 
    {
        std::cout << "Error occurred! Exiting with error code.\n";
        return 1;  // Non-zero return indicates error
    }
    
    std::cout << "Program completed successfully!\n";
    return 0;  // Zero indicates success
}
