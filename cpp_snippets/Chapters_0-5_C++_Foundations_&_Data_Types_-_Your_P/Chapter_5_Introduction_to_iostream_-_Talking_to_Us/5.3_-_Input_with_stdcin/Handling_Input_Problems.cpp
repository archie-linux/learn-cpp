#include <iostream>
#include <string>
#include <limits>

int main() 
{
    std::cout << "Input Validation Example\n";
    std::cout << "========================\n";
    
    int number;
    bool validInput = false;
    
    while (!validInput) 
    {
        std::cout << "Please enter a whole number: ";
        std::cin >> number;
        
        if (std::cin.fail()) 
        {
            std::cout << "That's not a valid number! Try again.\n";
            
            // Clear the error flag
            std::cin.clear();
            
            // Remove the bad input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else 
        {
            validInput = true;
        }
    }
    
    std::cout << "Great! You entered: " << number << '\n';
    
    // Demonstrating the whitespace problem with getline
    std::cout << "\nDemonstrating input buffer issues:\n";
    
    int favoriteNumber;
    std::string favoriteColor;
    
    std::cout << "Enter your favorite number: ";
    std::cin >> favoriteNumber;
    
    // This is needed to consume the leftover newline
    std::cin.ignore();
    
    std::cout << "Enter your favorite color: ";
    std::getline(std::cin, favoriteColor);
    
    std::cout << "Number: " << favoriteNumber << ", Color: " << favoriteColor << '\n';
    
    return 0;
}
