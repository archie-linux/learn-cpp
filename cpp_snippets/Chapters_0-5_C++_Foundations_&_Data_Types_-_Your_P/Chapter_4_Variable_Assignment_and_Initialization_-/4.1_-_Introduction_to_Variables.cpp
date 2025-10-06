#include <iostream>

int main() 
{
    std::cout << "Understanding Variables\n";
    std::cout << "======================\n";
    
    // Variable declaration and initialization
    int playerScore = 100;        // Declare and initialize
    std::string playerName;       // Declare only
    playerName = "Alex";          // Assign later
    
    bool gameRunning = true;      // Boolean variable
    double accountBalance = 1250.75; // Decimal number
    
    // Display variable values
    std::cout << "Player: " << playerName << '\n';
    std::cout << "Score: " << playerScore << '\n';
    std::cout << "Balance: $" << accountBalance << '\n';
    std::cout << "Game Running: " << (gameRunning ? "Yes" : "No") << '\n';
    
    // Variables can change (that's why they're called "variable"!)
    playerScore += 50;  // Add 50 points
    accountBalance -= 25.00; // Spend $25
    
    std::cout << "\nAfter some gameplay:\n";
    std::cout << "New Score: " << playerScore << '\n';
    std::cout << "New Balance: $" << accountBalance << '\n';
    
    return 0;
}
