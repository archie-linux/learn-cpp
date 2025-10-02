#include <iostream>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return (b != 0) ? a / b : 0; }

int main() 
{
    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    const char* operatorNames[] = {"+", "-", "*", "/"};
    
    int a = 12, b = 3;
    
    std::cout << "Calculator using function pointer array:\n";
    for (int i = 0; i < 4; ++i) 
    {
        int result = operations[i](a, b);
        std::cout << a << " " << operatorNames[i] << " " << b << " = " << result << '\n';
    }
    
    // Interactive calculator
    std::cout << "\nInteractive Calculator:\n";
    std::cout << "0: Add, 1: Subtract, 2: Multiply, 3: Divide\n";
    
    int x, y, choice;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    std::cout << "Choose operation (0-3): ";
    std::cin >> choice;
    
    if (choice >= 0 && choice <= 3) 
    {
        int result = operations[choice](x, y);
        std::cout << "Result: " << x << " " << operatorNames[choice] << " " << y 
                  << " = " << result << '\n';
    } 
    else 
    {
        std::cout << "Invalid choice!\n";
    }
    
    return 0;
}
