#include <iostream>

// Pass by value (makes a copy)
void modifyValue(int x) 
{
    x = x * 2;
    std::cout << "Inside function, x = " << x << '\n';
}

// Pass by reference (works with original variable)
void modifyReference(int& x) 
{
    x = x * 2;
    std::cout << "Inside function, x = " << x << '\n';
}

// Pass by const reference (efficient, safe)
void printValue(const int& x) 
{
    std::cout << "Value is: " << x << '\n';
    // x = 10;  // Error! Can't modify const reference
}

int main() 
{
    int number = 10;
    
    std::cout << "Original number: " << number << '\n';
    
    modifyValue(number);  // Pass by value
    std::cout << "After modifyValue: " << number << '\n';  // Unchanged
    
    modifyReference(number);  // Pass by reference
    std::cout << "After modifyReference: " << number << '\n';  // Changed!
    
    printValue(number);  // Efficient const reference
    
    return 0;
}
