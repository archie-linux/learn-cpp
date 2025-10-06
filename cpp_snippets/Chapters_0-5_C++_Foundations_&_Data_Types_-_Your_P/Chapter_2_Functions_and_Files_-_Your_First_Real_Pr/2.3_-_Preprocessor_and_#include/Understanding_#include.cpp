// System includes (angle brackets)
#include <iostream>    // For input/output operations
#include <string>      // For string class
#include <cmath>       // For mathematical functions
#include <iomanip>     // For output formatting

// User-defined includes (quotes) - for your own header files
// #include "myheader.h"  // Would include your custom header

int main() 
{
    // Demonstrate different library features
    
    // From <iostream>
    std::cout << "Hello World!\n";
    
    // From <string>
    std::string name = "C++ Programmer";
    std::cout << "Name: " << name << '\n';
    
    // From <cmath>
    double result = std::sqrt(16.0);
    std::cout << "Square root of 16: " << result << '\n';
    
    // From <iomanip>
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Pi approximately: " << 3.14159 << '\n';  // Shows 3.14
    
    return 0;
}
