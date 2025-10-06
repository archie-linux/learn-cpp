#include <iostream>

int value = 10;  // Global variable

void demonstrateShadowing() 
{
    int value = 20;  // Local variable shadows global
    
    std::cout << "Local value: " << value << '\n';          // 20
    std::cout << "Global value: " << ::value << '\n';       // 10 (scope resolution operator)
    
    {
        int value = 30;  // Block variable shadows both global and function-local
        std::cout << "Block value: " << value << '\n';      // 30
    }
    
    std::cout << "Back to local value: " << value << '\n';  // 20
}

int main() 
{
    std::cout << "Global value: " << value << '\n';         // 10
    demonstrateShadowing();
    std::cout << "Still global value: " << value << '\n';   // 10
    
    return 0;
}
