#include <iostream>
#include <functional>

// Regular functions
int add(int a, int b) 
{
    return a + b;
}

int multiply(int a, int b) 
{
    return a * b;
}

// Function that accepts std::function
void executeOperation(int x, int y, std::function<int(int, int)> op) 
{
    std::cout << "Result: " << op(x, y) << '\n';
}

int main() 
{
    // std::function can hold any callable
    std::function<int(int, int)> operation;
    
    // Assign regular function
    operation = add;
    executeOperation(5, 3, operation);  // 8
    
    operation = multiply;
    executeOperation(5, 3, operation);  // 15
    
    // Assign lambda function (C++11)
    operation = [](int a, int b) { return a - b; };
    executeOperation(5, 3, operation);  // 2
    
    return 0;
}
