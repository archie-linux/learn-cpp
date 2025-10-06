#include <iostream>

int main() 
{
    int temperature = 75;
    
    // Simple if statement
    if (temperature > 70) 
    {
        std::cout << "It's warm today!\n";
    }
    
    // If-else statement
    int score = 85;
    if (score >= 90) 
    {
        std::cout << "Grade: A\n";
    } 
    else 
    {
        std::cout << "Grade: Not an A\n";
    }
    
    // If-else chain
    if (score >= 90) 
    {
        std::cout << "Excellent!\n";
    } 
    else if (score >= 80) 
    {
        std::cout << "Good job!\n";
    } 
    else if (score >= 70) 
    {
        std::cout << "Passing grade.\n";
    } 
    else 
    {
        std::cout << "Need improvement.\n";
    }
    
    return 0;
}
