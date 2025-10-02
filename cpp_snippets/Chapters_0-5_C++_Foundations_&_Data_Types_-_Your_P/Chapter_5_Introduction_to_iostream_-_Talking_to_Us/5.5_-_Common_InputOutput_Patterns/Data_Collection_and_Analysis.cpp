#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Student Grade Analyzer\n";
    std::cout << "======================\n";
    
    int numStudents;
    std::cout << "How many students? ";
    std::cin >> numStudents;
    
    if (numStudents <= 0) 
    {
        std::cout << "Invalid number of students!\n";
        return 1;
    }
    
    double totalGrades = 0;
    double highestGrade = 0;
    double lowestGrade = 100;
    int passingStudents = 0;
    
    // Collect grades
    for (int i = 1; i <= numStudents; i++) 
    {
        double grade;
        std::cout << "Enter grade for student " << i << ": ";
        std::cin >> grade;
        
        // Validate grade
        if (grade < 0 || grade > 100) 
        {
            std::cout << "Invalid grade! Please enter 0-100.\n";
            i--;  // Don't count this iteration
            continue;
        }
        
        // Update statistics
        totalGrades += grade;
        
        if (grade > highestGrade) 
        {
            highestGrade = grade;
        }
        
        if (grade < lowestGrade) 
        {
            lowestGrade = grade;
        }
        
        if (grade >= 60) 
        {
            passingStudents++;
        }
        
        // Show grade classification
        std::cout << "  Grade: " << grade;
        if (grade >= 90) std::cout << " (A)";
        else if (grade >= 80) std::cout << " (B)";
        else if (grade >= 70) std::cout << " (C)";
        else if (grade >= 60) std::cout << " (D)";
        else std::cout << " (F)";
        std::cout << '\n';
    }
    
    // Calculate and display statistics
    double average = totalGrades / numStudents;
    double passRate = (static_cast<double>(passingStudents) / numStudents) * 100;
    
    std::cout << "\n--- GRADE STATISTICS ---\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Number of students: " << numStudents << '\n';
    std::cout << "Average grade: " << average << '\n';
    std::cout << "Highest grade: " << highestGrade << '\n';
    std::cout << "Lowest grade: " << lowestGrade << '\n';
    std::cout << "Passing students: " << passingStudents << " out of " << numStudents << '\n';
    std::cout << "Pass rate: " << passRate << "%\n";
    
    // Overall class performance
    if (average >= 90) 
    {
        std::cout << "Outstanding class performance!\n";
    } 
    else if (average >= 80) 
    {
        std::cout << "Good class performance.\n";
    } 
    else if (average >= 70) 
    {
        std::cout << "Average class performance.\n";
    } 
    else 
    {
        std::cout << "Class needs improvement.\n";
    }
    
    return 0;
}
