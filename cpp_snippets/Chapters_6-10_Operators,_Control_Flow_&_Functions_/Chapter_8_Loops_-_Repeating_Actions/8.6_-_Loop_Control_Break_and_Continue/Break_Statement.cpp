#include <iostream>

int main() 
{
    // Finding first even number
    std::cout << "Looking for first even number in sequence:\n";
    for (int i = 1; i <= 20; ++i) 
    {
        std::cout << "Checking " << i << "... ";
        
        if (i % 2 == 0) 
        {
            std::cout << "Found it! " << i << " is even.\n";
            break;  // Exit the loop
        }
        
        std::cout << "odd, continue searching.\n";
    }
    
    // Break in nested loops (only breaks inner loop)
    std::cout << "\nNested loop break example:\n";
    for (int i = 1; i <= 3; ++i) 
    {
        std::cout << "Outer loop i=" << i << '\n';
        
        for (int j = 1; j <= 5; ++j) 
        {
            if (j == 3) 
            {
                std::cout << "  Breaking inner loop at j=" << j << '\n';
                break;  // Only breaks inner loop
            }
            std::cout << "  Inner loop j=" << j << '\n';
        }
    }
    
    return 0;
}
