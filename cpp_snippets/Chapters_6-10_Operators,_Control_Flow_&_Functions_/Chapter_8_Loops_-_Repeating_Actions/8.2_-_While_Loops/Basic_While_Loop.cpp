#include <iostream>

int main() 
{
    // Countdown example
    int countdown = 10;
    
    while (countdown > 0) 
    {
        std::cout << countdown << "... ";
        countdown--;
    }
    std::cout << "Liftoff!\n";
    
    // Input validation example
    int number;
    std::cout << "\nEnter a positive number: ";
    std::cin >> number;
    
    while (number <= 0) 
    {
        std::cout << "Invalid! Please enter a positive number: ";
        std::cin >> number;
    }
    
    std::cout << "You entered: " << number << '\n';
    
    return 0;
}
