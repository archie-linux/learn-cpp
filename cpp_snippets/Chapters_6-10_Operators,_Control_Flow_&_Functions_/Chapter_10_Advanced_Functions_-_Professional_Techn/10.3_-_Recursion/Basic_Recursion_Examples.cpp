#include <iostream>

// Factorial calculation using recursion
int factorial(int n) 
{
    // Base case
    if (n <= 1) 
    {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}

// Fibonacci sequence using recursion
int fibonacci(int n) 
{
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Power calculation using recursion
double power(double base, int exponent) 
{
    // Base case
    if (exponent == 0) 
    {
        return 1.0;
    }
    
    // Handle negative exponents
    if (exponent < 0) 
    {
        return 1.0 / power(base, -exponent);
    }
    
    // Recursive case
    return base * power(base, exponent - 1);
}

int main() 
{
    // Test factorial
    std::cout << "Factorial examples:\n";
    for (int i = 1; i <= 6; ++i) 
    {
        std::cout << i << "! = " << factorial(i) << '\n';
    }
    
    // Test Fibonacci
    std::cout << "\nFibonacci sequence:\n";
    for (int i = 0; i <= 10; ++i) 
    {
        std::cout << "F(" << i << ") = " << fibonacci(i) << '\n';
    }
    
    // Test power function
    std::cout << "\nPower examples:\n";
    std::cout << "2^5 = " << power(2, 5) << '\n';
    std::cout << "3^4 = " << power(3, 4) << '\n';
    std::cout << "5^0 = " << power(5, 0) << '\n';
    std::cout << "2^(-3) = " << power(2, -3) << '\n';
    
    return 0;
}
