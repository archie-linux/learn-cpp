#include <iostream>

void printValue(const int& value)    // Can accept any int expression
{
    std::cout << "Value: " << value << '\n';
}

int getValue() { return 42; }

int main() 
{
    int x = 5;
    const int c = 10;
    
    // const references can bind to anything!
    printValue(x);           // ✅ Modifiable lvalue
    printValue(c);           // ✅ Non-modifiable lvalue  
    printValue(42);          // ✅ Rvalue literal
    printValue(x + 1);       // ✅ Rvalue expression
    printValue(getValue());  // ✅ Rvalue from function
    
    return 0;
}
