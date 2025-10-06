#include <iostream>
#include <string>

int main() 
{
    // Without lifetime extension:
    // auto temp = std::string("Hello") + " World";
    // const std::string& ref = temp;  // Normal reference to existing object
    
    // With lifetime extension:
    const std::string& ref = std::string("Hello") + " World";  // Temporary extended!
    
    std::cout << ref << '\n';  // ✅ Safe to use - temporary still alive
    
    return 0;
}
