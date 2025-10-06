#include <iostream>

// Function definition
void greetUser() 
{
    std::cout << "Welcome to our program!\n";
    std::cout << "We hope you enjoy using it.\n";
}

int main() 
{
    std::cout << "Program starting...\n";
    
    greetUser();  // Function call
    
    std::cout << "Program continuing...\n";
    
    greetUser();  // Can call multiple times
    
    return 0;
}
