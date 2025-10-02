#include <iostream>
#include <string>

int main() 
{
    std::cout << "Variable Best Practices\n";
    std::cout << "=======================\n";
    
    // ✅ Good: Meaningful names
    int studentAge = 20;
    double accountBalance = 1500.75;
    std::string firstName = "Alice";
    bool isLoggedIn = false;
    
    // ❌ Bad: Cryptic names
    int x = 20;           // What does x represent?
    double d = 1500.75;   // What kind of data?
    std::string s = "Alice"; // String of what?
    
    // ✅ Good: Initialize when declaring
    int score = 0;        // Start with known value
    bool gameActive = true; // Clear initial state
    
    // ❌ Bad: Uninitialized variables
    int badScore;         // Contains garbage
    bool badState;        // Unpredictable
    
    // ✅ Good: Use const for values that shouldn't change
    const int MAX_LIVES = 3;
    const double PI = 3.14159;
    const std::string GAME_TITLE = "Super Adventure";
    
    std::cout << "Game: " << GAME_TITLE << '\n';
    std::cout << "Max Lives: " << MAX_LIVES << '\n';
    std::cout << "Player: " << firstName << " (Age: " << studentAge << ")\n";
    std::cout << "Account Balance: $" << accountBalance << '\n';
    std::cout << "Logged In: " << (isLoggedIn ? "Yes" : "No") << '\n';
    
    // Using const prevents accidental changes
    // MAX_LIVES = 5;  // Error: cannot modify const variable
    
    return 0;
}
