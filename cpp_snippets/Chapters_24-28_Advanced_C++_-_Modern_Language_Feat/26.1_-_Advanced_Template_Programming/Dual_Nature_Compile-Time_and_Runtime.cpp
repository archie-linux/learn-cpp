#include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    // Compile-time evaluation
    constexpr int result1 { greater(5, 3) }; // Evaluated at compile-time
    
    // Runtime evaluation  
    int x{ 5 }; // not constexpr
    int y{ 6 }; // not constexpr
    std::cout << greater(x, y) << " is greater!\n"; // ✅ Evaluated at runtime
    
    return 0;
}
