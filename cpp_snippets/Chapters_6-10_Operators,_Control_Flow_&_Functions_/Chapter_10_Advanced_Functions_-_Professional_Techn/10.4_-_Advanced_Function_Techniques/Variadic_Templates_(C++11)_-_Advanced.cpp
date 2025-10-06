#include <iostream>

// Base case for recursion
void print() 
{
    std::cout << '\n';
}

// Variadic template function
template<typename T, typename... Args>
void print(T first, Args... args) 
{
    std::cout << first << " ";
    print(args...);  // Recursive call with remaining arguments
}

// Variadic template for sum calculation
template<typename T>
T sum(T value) 
{
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) 
{
    return first + sum(args...);
}

int main() 
{
    // Print function with variable arguments
    print("Hello", "World", 42, 3.14, true);
    print(1, 2, 3, 4, 5);
    print("Just one argument");
    
    // Sum function with variable arguments
    std::cout << "Sum of integers: " << sum(1, 2, 3, 4, 5) << '\n';
    std::cout << "Sum of doubles: " << sum(1.1, 2.2, 3.3) << '\n';
    
    return 0;
}
