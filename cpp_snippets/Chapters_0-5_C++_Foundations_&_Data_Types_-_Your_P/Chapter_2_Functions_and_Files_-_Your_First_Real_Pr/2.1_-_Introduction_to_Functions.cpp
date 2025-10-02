#include <iostream>

// Function to display welcome message
void showWelcome() 
{
    std::cout << "================================\n";
    std::cout << "     Welcome to My Program!     \n";
    std::cout << "================================\n";
}

// Function to display goodbye message
void showGoodbye() 
{
    std::cout << "================================\n";
    std::cout << "    Thanks for using my app!    \n";
    std::cout << "================================\n";
}

// Function to display menu options
void showMenu() 
{
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Start calculator\n";
    std::cout << "2. View help\n";
    std::cout << "3. Exit program\n";
    std::cout << "Choose an option: ";
}

int main() 
{
    showWelcome();    // Call welcome function
    showMenu();       // Call menu function
    
    // Simulate user interaction
    std::cout << "2\n";  // User chooses help
    
    std::cout << "\nHelp: This program demonstrates basic C++ structure.\n";
    
    showGoodbye();    // Call goodbye function
    
    return 0;
}
