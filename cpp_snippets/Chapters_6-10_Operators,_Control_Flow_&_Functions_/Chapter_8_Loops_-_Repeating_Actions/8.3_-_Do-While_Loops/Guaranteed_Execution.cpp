#include <iostream>

int main() 
{
    char playAgain;
    
    do 
    {
        std::cout << "Playing the game...\n";
        std::cout << "Game over!\n";
        
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    std::cout << "Thanks for playing!\n";
    
    // Password verification example
    std::string password;
    const std::string correctPassword = "secret123";
    
    do 
    {
        std::cout << "Enter password: ";
        std::cin >> password;
        
        if (password != correctPassword) 
        {
            std::cout << "Incorrect password!\n";
        }
        
    } while (password != correctPassword);
    
    std::cout << "Access granted!\n";
    
    return 0;
}
