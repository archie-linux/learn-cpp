#include <iostream>

int main() 
{
    int x = 5, y = 10;
    
    // References
    int& ref = x;        // Must initialize, becomes permanent alias
    ref = 20;            // Changes x to 20
    ref = y;             // ❌ This assigns y's VALUE to x, doesn't rebind!
    
    // Pointers  
    int* ptr = &x;       // Initialize with address
    *ptr = 30;           // Changes x to 30
    ptr = &y;            // ✅ Now points to y instead
    *ptr = 40;           // Changes y to 40
    
    std::cout << "x = " << x << ", y = " << y << '\n';  // x = 30, y = 40
    
    return 0;
}
