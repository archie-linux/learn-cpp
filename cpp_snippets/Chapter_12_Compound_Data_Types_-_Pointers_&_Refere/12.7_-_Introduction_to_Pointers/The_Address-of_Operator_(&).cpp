#include <iostream>

int main() 
{
    int x = 42;
    double arr[3] = {1.1, 2.2, 3.3};
    
    std::cout << "Address of x: " << &x << '\n';
    std::cout << "Address of arr[0]: " << &arr[0] << '\n';
    std::cout << "Address of arr[1]: " << &arr[1] << '\n';
    std::cout << "Address of arr[2]: " << &arr[2] << '\n';
    
    // Notice how array elements are contiguous in memory!
    return 0;
}
