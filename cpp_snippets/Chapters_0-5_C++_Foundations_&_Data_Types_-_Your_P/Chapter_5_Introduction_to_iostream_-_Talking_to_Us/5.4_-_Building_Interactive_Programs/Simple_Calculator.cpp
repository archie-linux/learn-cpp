#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Simple Calculator\n";
    std::cout << "=================\n";
    
    double num1, num2;
    char operation;
    
    // Get input from user
    std::cout << "Enter first number: ";
    std::cin >> num1;
    
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;
    
    std::cout << "Enter second number: ";
    std::cin >> num2;
    
    // Perform calculation
    double result = 0;
    bool validOperation = true;
    
    switch (operation) 
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) 
            {
                result = num1 / num2;
            } 
            else 
            {
                std::cout << "Error: Cannot divide by zero!\n";
                validOperation = false;
            }
            break;
        default:
            std::cout << "Error: Unknown operation!\n";
            validOperation = false;
    }
    
    // Display result
    if (validOperation) 
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << num1 << " " << operation << " " << num2 << " = " << result << '\n';
    }
    
    return 0;
}
