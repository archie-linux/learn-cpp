#include <iostream>

// Define an enumeration for colors
enum Color 
{
    red,      // assigned value 0
    green,    // assigned value 1  
    blue,     // assigned value 2
    yellow    // assigned value 3
};

int main() 
{
    Color paint = red;        // paint now holds the value corresponding to red
    Color house = green;      // house now holds the value corresponding to green
    Color apple = red;        // apple now holds the value corresponding to red
    
    std::cout << "Paint color: " << paint << '\n';  // prints 0
    std::cout << "House color: " << house << '\n';  // prints 1
    
    return 0;
}
