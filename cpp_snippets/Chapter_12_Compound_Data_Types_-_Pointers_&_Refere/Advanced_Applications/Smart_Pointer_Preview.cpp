#include <iostream>
#include <memory>
#include <string>

int main() 
{
    // Raw pointer (dangerous)
    int* rawPtr = new int(42);
    std::cout << *rawPtr << '\n';
    delete rawPtr;  // Must remember to delete!
    
    // Smart pointer (safe) - C++14
    auto smartPtr = std::make_unique<int>(42);
    std::cout << *smartPtr << '\n';
    // Automatic cleanup - no delete needed!
    
    // Smart pointers work great with templates
    auto smartString = std::make_unique<std::string>("Hello, Smart Pointers!");
    std::cout << *smartString << '\n';
    
    return 0;
}
