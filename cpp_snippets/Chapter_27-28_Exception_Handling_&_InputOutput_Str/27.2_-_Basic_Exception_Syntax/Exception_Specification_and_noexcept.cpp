#include <iostream>
#include <stdexcept>

// Functions with different exception specifications
void throwingFunction() 
{
    throw std::runtime_error("This function can throw");
}

void nonThrowingFunction() noexcept 
{
    // This function promises not to throw
    std::cout << "This function won't throw\n";
}

void conditionalNoexcept(bool shouldThrow) noexcept(!shouldThrow) 
{
    if (shouldThrow) 
    {
        // This would terminate the program if shouldThrow is true
        // because noexcept(false) when shouldThrow is true
    }
    
    std::cout << "Conditional noexcept function\n";
}

// Template with conditional noexcept
template<typename T>
void templateFunction(T&& value) noexcept(noexcept(std::forward<T>(value))) 
{
    auto result = std::forward<T>(value);
    std::cout << "Template function completed\n";
}

int main() 
{
    std::cout << "=== Exception Specifications ===\n";
    
    // Check if functions are noexcept at compile time
    std::cout << "throwingFunction is noexcept: " 
              << std::boolalpha << noexcept(throwingFunction()) << "\n";
    
    std::cout << "nonThrowingFunction is noexcept: " 
              << std::boolalpha << noexcept(nonThrowingFunction()) << "\n";
    
    std::cout << "conditionalNoexcept(false) is noexcept: " 
              << std::boolalpha << noexcept(conditionalNoexcept(false)) << "\n";
    
    std::cout << "conditionalNoexcept(true) is noexcept: " 
              << std::boolalpha << noexcept(conditionalNoexcept(true)) << "\n";
    
    nonThrowingFunction();
    conditionalNoexcept(false);
    
    try 
    {
        throwingFunction();
    }
    catch (const std::exception& e) 
    {
        std::cout << "Caught: " << e.what() << "\n";
    }
    
    return 0;
}
