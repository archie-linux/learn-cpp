#include <iostream>
#include <string>
#include <stdexcept>

// Function that can throw different types of exceptions
void demonstrateBasicExceptions(int choice) 
{
    switch (choice) 
    {
        case 1:
            throw 42;  // Throw an integer
            
        case 2:
            throw std::string("String exception");  // Throw a string
            
        case 3:
            throw std::runtime_error("Runtime error occurred");  // Standard exception
            
        case 4:
            throw;  // Re-throw current exception (only valid in catch block)
            
        default:
            std::cout << "No exception thrown\n";
    }
}

int main() 
{
    for (int i = 1; i <= 4; ++i) 
    {
        std::cout << "\n=== Test " << i << " ===\n";
        
        try 
        {
            demonstrateBasicExceptions(i);
            std::cout << "No exception was thrown\n";
        }
        catch (int value) 
        {
            std::cout << "Caught integer exception: " << value << "\n";
        }
        catch (const std::string& message) 
        {
            std::cout << "Caught string exception: " << message << "\n";
        }
        catch (const std::runtime_error& e) 
        {
            std::cout << "Caught runtime_error: " << e.what() << "\n";
        }
        catch (...) 
        {
            std::cout << "Caught unknown exception type\n";
        }
    }
    
    return 0;
}
