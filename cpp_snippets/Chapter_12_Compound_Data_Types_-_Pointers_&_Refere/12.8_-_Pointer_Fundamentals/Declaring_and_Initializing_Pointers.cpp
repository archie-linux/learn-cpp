#include <iostream>

int main() 
{
    int x = 5, y = 10;
    
    // Pointer declarations and initialization
    int* ptr1;           // ❌ Uninitialized (wild pointer)
    int* ptr2{};         // ✅ Null pointer
    int* ptr3 = &x;      // ✅ Points to x
    int* ptr4{&y};       // ✅ Points to y (preferred syntax)
    
    std::cout << "x = " << x << ", *ptr3 = " << *ptr3 << '\n';  // Both print 5
    std::cout << "y = " << y << ", *ptr4 = " << *ptr4 << '\n';  // Both print 10
    
    return 0;
}
