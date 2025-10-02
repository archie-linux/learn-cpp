#include <iostream>

int main() 
{
    // INITIALIZATION (happens when variable is created)
    int score = 100;              // Direct initialization
    int lives(3);                 // Parentheses initialization
    int level{1};                 // Brace initialization (C++11)
    
    std::cout << "Initial values:\n";
    std::cout << "Score: " << score << ", Lives: " << lives << ", Level: " << level << '\n';
    
    // ASSIGNMENT (happens after variable exists)
    score = 150;                  // Change score to 150
    lives = lives - 1;            // Lose a life
    level = level + 1;            // Level up
    
    std::cout << "\nAfter assignment:\n";
    std::cout << "Score: " << score << ", Lives: " << lives << ", Level: " << level << '\n';
    
    // Multiple variable declaration and initialization
    int x = 10, y = 20, z = 30;  // All in one line
    std::cout << "\nMultiple variables: x=" << x << ", y=" << y << ", z=" << z << '\n';
    
    // Uninitialized variables (dangerous!)
    int dangerous;                // Contains garbage value
    std::cout << "Uninitialized variable: " << dangerous << " (undefined behavior!)\n";
    
    return 0;
}
