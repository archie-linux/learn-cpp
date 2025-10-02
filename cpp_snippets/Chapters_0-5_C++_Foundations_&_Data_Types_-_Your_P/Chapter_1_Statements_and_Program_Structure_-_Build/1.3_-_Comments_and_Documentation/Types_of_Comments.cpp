#include <iostream>

/*
 * Multi-line comment for program description
 * Program: Grade Calculator
 * Author: Student Name
 * Date: Today's Date
 * Purpose: Calculate student average grade
 */

int main() 
{
    // Single-line comment for quick notes
    std::cout << "Welcome to Grade Calculator\n";
    
    int score1 = 85;  // First test score
    int score2 = 92;  // Second test score
    int score3 = 78;  // Third test score
    
    /* 
       Calculate the average of three scores
       Formula: (score1 + score2 + score3) / 3
    */
    double average = (score1 + score2 + score3) / 3.0;
    
    std::cout << "Your average grade is: " << average << '\n';
    
    return 0;  // Indicate successful program completion
}
