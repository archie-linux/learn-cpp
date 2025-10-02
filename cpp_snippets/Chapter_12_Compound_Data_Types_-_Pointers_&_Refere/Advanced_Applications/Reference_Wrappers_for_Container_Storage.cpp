#include <iostream>
#include <vector>
#include <functional>

int main() 
{
    int a = 1, b = 2, c = 3;
    
    // Can't do: std::vector<int&> refs;  // ❌ Error!
    
    // Solution: use reference_wrapper
    std::vector<std::reference_wrapper<int>> refs = {a, b, c};
    
    // Modify through references
    for (auto& ref : refs) 
    {
        ref.get() *= 2;  // Double each value
    }
    
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << '\n';
    // Prints: a = 2, b = 4, c = 6
    
    return 0;
}
