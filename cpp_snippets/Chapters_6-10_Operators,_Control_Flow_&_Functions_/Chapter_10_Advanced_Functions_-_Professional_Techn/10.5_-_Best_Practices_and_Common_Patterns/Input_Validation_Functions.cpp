#include <iostream>
#include <limits>
#include <string>

// Robust input validation
int getValidInteger(const std::string& prompt, int min = INT_MIN, int max = INT_MAX) 
{
    int value;
    
    while (true) 
    {
        std::cout << prompt;
        std::cin >> value;
        
        // Check for input failure
        if (std::cin.fail()) 
        {
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        // Clear any remaining characters
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Check range
        if (value < min || value > max) 
        {
            std::cout << "Value must be between " << min << " and " << max << ".\n";
            continue;
        }
        
        return value;
    }
}

char getValidChoice(const std::string& prompt, const std::string& validChoices) 
{
    char choice;
    
    while (true) 
    {
        std::cout << prompt;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Convert to lowercase for comparison
        choice = std::tolower(choice);
        
        if (validChoices.find(choice) != std::string::npos) 
        {
            return choice;
        }
        
        std::cout << "Invalid choice! Valid options: " << validChoices << '\n';
    }
}

int main() 
{
    // Test input validation
    int age = getValidInteger("Enter your age (1-120): ", 1, 120);
    std::cout << "You entered: " << age << '\n';
    
    char choice = getValidChoice("Continue? (y/n): ", "yn");
    std::cout << "You chose: " << choice << '\n';
    
    if (choice == 'y') 
    {
        int score = getValidInteger("Enter test score (0-100): ", 0, 100);
        std::cout << "Your score: " << score << '\n';
    }
    
    return 0;
}
