#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <memory>
#include <vector>
#include <new>

void demonstrateStandardExceptions() 
{
    std::cout << "=== Standard Exception Classes ===\n";
    
    // Logic errors - programming mistakes
    try 
    {
        std::vector<int> vec(5);
        vec.at(10);  // Out of bounds access
    }
    catch (const std::out_of_range& e) 
    {
        std::cout << "std::out_of_range: " << e.what() << "\n";
    }
    
    try 
    {
        std::string str = "hello";
        str.substr(10, 5);  // Invalid substring
    }
    catch (const std::out_of_range& e) 
    {
        std::cout << "std::out_of_range (substring): " << e.what() << "\n";
    }
    
    try 
    {
        throw std::invalid_argument("This argument is not valid");
    }
    catch (const std::invalid_argument& e) 
    {
        std::cout << "std::invalid_argument: " << e.what() << "\n";
    }
    
    try 
    {
        throw std::domain_error("Input outside valid domain");
    }
    catch (const std::domain_error& e) 
    {
        std::cout << "std::domain_error: " << e.what() << "\n";
    }
    
    try 
    {
        throw std::length_error("Container size exceeded");
    }
    catch (const std::length_error& e) 
    {
        std::cout << "std::length_error: " << e.what() << "\n";
    }
    
    // Runtime errors - environmental issues
    try 
    {
        throw std::runtime_error("Something went wrong at runtime");
    }
    catch (const std::runtime_error& e) 
    {
        std::cout << "std::runtime_error: " << e.what() << "\n";
    }
    
    try 
    {
        throw std::range_error("Value out of range");
    }
    catch (const std::range_error& e) 
    {
        std::cout << "std::range_error: " << e.what() << "\n";
    }
    
    try 
    {
        throw std::overflow_error("Arithmetic overflow");
    }
    catch (const std::overflow_error& e) 
    {
        std::cout << "std::overflow_error: " << e.what() << "\n";
    }
    
    try 
    {
        throw std::underflow_error("Arithmetic underflow");
    }
    catch (const std::underflow_error& e) 
    {
        std::cout << "std::underflow_error: " << e.what() << "\n";
    }
    
    // System exceptions
    try 
    {
        throw std::bad_alloc();
    }
    catch (const std::bad_alloc& e) 
    {
        std::cout << "std::bad_alloc: " << e.what() << "\n";
    }
    
    try 
    {
        throw std::bad_cast();
    }
    catch (const std::bad_cast& e) 
    {
        std::cout << "std::bad_cast: " << e.what() << "\n";
    }
}
