#include <iostream>

int main() 
{
    int x = 100;
    
    std::cout << "Direct access: " << x << '\n';           // 100
    std::cout << "Address: " << &x << '\n';                // e.g., 0x7fff5fbff6ac
    std::cout << "Indirect access: " << *(&x) << '\n';     // 100
    
    // Address-of and dereference are opposites
    // &x gets the address, *(&x) gets the value back
    
    return 0;
}
