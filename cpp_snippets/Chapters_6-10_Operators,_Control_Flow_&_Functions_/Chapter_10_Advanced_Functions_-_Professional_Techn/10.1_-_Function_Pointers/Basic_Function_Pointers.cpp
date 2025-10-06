#include <iostream>

// Functions to demonstrate function pointers
int add(int a, int b) 
{
    return a + b;
}

int multiply(int a, int b) 
{
    return a * b;
}

int subtract(int a, int b) 
{
    return a - b;
}

// Function that takes a function pointer as parameter
int calculate(int x, int y, int (*operation)(int, int)) 
{
    return operation(x, y);
}

int main() 
{
    // Declare function pointer
    int (*mathOperation)(int, int);
    
    // Assign function to pointer
    mathOperation = add;
    std::cout << "Addition: " << mathOperation(10, 5) << '\n';  // 15
    
    mathOperation = multiply;
    std::cout << "Multiplication: " << mathOperation(10, 5) << '\n';  // 50
    
    mathOperation = subtract;
    std::cout << "Subtraction: " << mathOperation(10, 5) << '\n';  // 5
    
    // Using function pointers with other functions
    std::cout << "Using calculate function:\n";
    std::cout << "Add: " << calculate(8, 3, add) << '\n';
    std::cout << "Multiply: " << calculate(8, 3, multiply) << '\n';
    std::cout << "Subtract: " << calculate(8, 3, subtract) << '\n';
    
    return 0;
}
