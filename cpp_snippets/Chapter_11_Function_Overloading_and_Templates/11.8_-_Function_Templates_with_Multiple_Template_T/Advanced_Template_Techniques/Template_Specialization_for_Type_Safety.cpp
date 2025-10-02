#include <iostream>
#include <string>

template <typename T>
T addOne(T x) 
{
    return x + 1;
}

// Specialized version for strings - delete to prevent compilation
template <>
std::string addOne<std::string>(std::string x) = delete;

int main() 
{
    std::cout << addOne(5) << '\n';       // ✅ Works: returns 6
    std::cout << addOne(3.14) << '\n';    // ✅ Works: returns 4.14
    // addOne(std::string("Hello"));      // ❌ Compile error: function deleted
    return 0;
}
