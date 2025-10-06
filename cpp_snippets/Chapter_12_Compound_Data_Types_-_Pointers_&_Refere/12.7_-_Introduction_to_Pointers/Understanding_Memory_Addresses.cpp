#include <iostream>

int main() 
{
    int x = 5;           // Assume assigned to address 1000
    char c = 'A';        // Assume assigned to address 1004
    double d = 3.14;     // Assume assigned to address 1008
    
    std::cout << "x value: " << x << ", address: " << &x << '\n';
    std::cout << "c value: " << c << ", address: " << (void*)&c << '\n';  
    std::cout << "d value: " << d << ", address: " << &d << '\n';
    
    return 0;
}
