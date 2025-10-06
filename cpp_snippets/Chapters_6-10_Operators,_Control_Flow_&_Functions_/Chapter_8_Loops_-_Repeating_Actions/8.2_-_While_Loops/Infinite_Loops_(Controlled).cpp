#include <iostream>

int main() 
{
    int userChoice = 0;
    
    while (true)  // Infinite loop
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Play game\n";
        std::cout << "2. View high scores\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        
        std::cin >> userChoice;
        
        if (userChoice == 1) 
        {
            std::cout << "Playing game...\n";
        } 
        else if (userChoice == 2) 
        {
            std::cout << "Showing high scores...\n";
        } 
        else if (userChoice == 3) 
        {
            std::cout << "Goodbye!\n";
            break;  // Exit the infinite loop
        } 
        else 
        {
            std::cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}
