#include <iostream>

int main() 
{
    int score = 100;
    int bonus = 25;
    
    std::cout << "Initial score: " << score << '\n';
    
    // Compound assignment operators
    score += bonus;    // Equivalent to: score = score + bonus
    std::cout << "After += " << bonus << ": " << score << '\n';  // 125
    
    score -= 10;       // Equivalent to: score = score - 10
    std::cout << "After -= 10: " << score << '\n';               // 115
    
    score *= 2;        // Equivalent to: score = score * 2
    std::cout << "After *= 2: " << score << '\n';                // 230
    
    score /= 5;        // Equivalent to: score = score / 5
    std::cout << "After /= 5: " << score << '\n';                // 46
    
    score %= 7;        // Equivalent to: score = score % 7
    std::cout << "After %= 7: " << score << '\n';                // 4
    
    return 0;
}
