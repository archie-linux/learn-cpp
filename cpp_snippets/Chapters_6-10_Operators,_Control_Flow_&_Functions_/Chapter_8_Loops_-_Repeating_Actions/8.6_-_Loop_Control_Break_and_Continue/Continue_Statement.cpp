#include <iostream>

int main() 
{
    // Print only odd numbers
    std::cout << "Odd numbers from 1 to 10: ";
    for (int i = 1; i <= 10; ++i) 
    {
        if (i % 2 == 0) 
        {
            continue;  // Skip rest of loop body for even numbers
        }
        
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // Skip negative numbers in calculation
    int sum = 0;
    int numbers[] = {5, -2, 8, -1, 3, -4, 7};
    
    for (int num : numbers) 
    {
        if (num < 0) 
        {
            std::cout << "Skipping negative number: " << num << '\n';
            continue;
        }
        
        sum += num;
        std::cout << "Adding " << num << ", sum now: " << sum << '\n';
    }
    
    std::cout << "Final sum of positive numbers: " << sum << '\n';
    
    return 0;
}
