#include <iostream>

int main()  // Return type 'int' indicates success/failure to operating system
{
    std::cout << "Program execution starts here!\n";
    
    // Your program logic goes here
    std::cout << "Doing some work...\n";
    std::cout << "More work...\n";
    std::cout << "Almost done...\n";
    
    std::cout << "Program execution ends here!\n";
    
    return 0;  // 0 typically means "success"
               // Non-zero values indicate errors
}
