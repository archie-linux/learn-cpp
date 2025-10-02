#include <iostream>

int main() 
{
    // Multiple variables
    for (int i = 0, j = 10; i < j; ++i, --j) 
    {
        std::cout << "i=" << i << ", j=" << j << '\n';
    }
    
    // Nested loops (multiplication table)
    std::cout << "\nMultiplication Table:\n";
    for (int row = 1; row <= 5; ++row) 
    {
        for (int col = 1; col <= 5; ++col) 
        {
            std::cout << (row * col) << '\t';
        }
        std::cout << '\n';
    }
    
    return 0;
}
