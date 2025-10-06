#include <iostream>
#include <string>

// Template function - works with any type T
template <typename T>
T max(const T& a, const T& b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    // Compiler automatically deduces types
    std::cout << "Max of 5, 7: " << max(5, 7) << '\n';           // T = int
    std::cout << "Max of 3.14, 2.71: " << max(3.14, 2.71) << '\n'; // T = double
    std::cout << "Max of 'hello', 'world': " << max(std::string("hello"), std::string("world")) << '\n';
    
    return 0;
}
