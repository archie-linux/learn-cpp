#include <iostream>
#include <string>

int main() 
{
    // Using sizeof with types
    std::cout << "Type sizes:\n";
    std::cout << "sizeof(int): " << sizeof(int) << " bytes\n";
    std::cout << "sizeof(double): " << sizeof(double) << " bytes\n";
    
    // Using sizeof with variables
    int number = 42;
    double decimal = 3.14159;
    std::string text = "Hello World";
    
    std::cout << "\nVariable sizes:\n";
    std::cout << "sizeof(number): " << sizeof(number) << " bytes\n";
    std::cout << "sizeof(decimal): " << sizeof(decimal) << " bytes\n";
    std::cout << "sizeof(text): " << sizeof(text) << " bytes\n";
    
    // Arrays and sizeof
    int numbers[10];
    std::cout << "\nArray sizes:\n";
    std::cout << "sizeof(numbers): " << sizeof(numbers) << " bytes\n";
    std::cout << "sizeof(numbers[0]): " << sizeof(numbers[0]) << " bytes\n";
    std::cout << "Array length: " << sizeof(numbers) / sizeof(numbers[0]) << " elements\n";
    
    return 0;
}
