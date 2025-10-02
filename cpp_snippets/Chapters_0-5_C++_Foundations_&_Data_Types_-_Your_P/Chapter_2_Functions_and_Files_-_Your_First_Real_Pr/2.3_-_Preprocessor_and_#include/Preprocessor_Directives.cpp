#include <iostream>

// Define constants using #define (older C-style)
#define PI 3.14159
#define PROGRAM_VERSION "1.0"

// Conditional compilation
#define DEBUG_MODE 1

int main() 
{
    std::cout << "Program Version: " << PROGRAM_VERSION << '\n';
    std::cout << "Value of PI: " << PI << '\n';
    
    #if DEBUG_MODE
        std::cout << "Debug: Program is running in debug mode\n";
    #endif
    
    // Modern C++ prefers const variables over #define
    const double BETTER_PI = 3.14159265359;
    std::cout << "Better PI: " << BETTER_PI << '\n';
    
    return 0;
}
