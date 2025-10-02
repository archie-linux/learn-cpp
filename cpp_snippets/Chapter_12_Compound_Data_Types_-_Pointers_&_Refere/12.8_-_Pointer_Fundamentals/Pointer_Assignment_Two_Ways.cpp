#include <iostream>

int main() 
{
    int x = 5, y = 10, z = 15;
    int* ptr = &x;
    
    std::cout << "Initially: *ptr = " << *ptr << '\n';  // 5
    
    // Method 1: Change what pointer points to
    ptr = &y;
    std::cout << "After ptr = &y: *ptr = " << *ptr << '\n';  // 10
    
    // Method 2: Change the value being pointed at
    *ptr = 99;
    std::cout << "After *ptr = 99: y = " << y << '\n';  // 99 (y changed!)
    
    return 0;
}
