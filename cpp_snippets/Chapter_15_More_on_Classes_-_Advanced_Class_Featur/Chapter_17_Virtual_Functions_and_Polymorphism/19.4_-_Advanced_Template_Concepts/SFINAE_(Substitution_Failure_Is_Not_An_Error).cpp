#include <iostream>
#include <type_traits>
#include <vector>

// Only enabled for integral types
template <typename T>
typename std::enable_if_t<std::is_integral_v<T>, void>
processNumber(T value) 
{
    std::cout << "Processing integer: " << value << '\n';
}

// Only enabled for floating-point types
template <typename T>
typename std::enable_if_t<std::is_floating_point_v<T>, void>
processNumber(T value) 
{
    std::cout << "Processing float: " << value << " (rounded: " << static_cast<int>(value) << ")\n";
}

// Constexpr if (C++17) - cleaner alternative
template <typename T>
void processValue(T value) 
{
    if constexpr (std::is_integral_v<T>) 
    {
        std::cout << "Integer value: " << value << '\n';
    }
    else if constexpr (std::is_floating_point_v<T>) 
    {
        std::cout << "Floating-point value: " << value << '\n';
    }
    else 
    {
        std::cout << "Other type value: " << value << '\n';
    }
}

int main() 
{
    processNumber(42);      // Calls integral version
    processNumber(3.14);    // Calls floating-point version
    
    processValue(100);      // Integer branch
    processValue(2.71);     // Floating-point branch
    processValue("hello");  // Other type branch
    
    return 0;
}
