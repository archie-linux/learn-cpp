#include <iostream>
#include <string>

int main() 
{
    std::cout << "Input Techniques Demonstration\n";
    std::cout << "==============================\n";
    
    // Single word input
    std::string firstName;
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    
    // Numeric input
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    // Multiple inputs in one line
    int day, month, year;
    std::cout << "Enter your birth date (DD MM YYYY): ";
    std::cin >> day >> month >> year;
    
    // Display results
    std::cout << "\nWhat you entered:\n";
    std::cout << "Name: " << firstName << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Birth date: " << day << "/" << month << "/" << year << '\n';
    
    // Full line input (after clearing buffer)
    std::cin.ignore();  // Clear any leftover input
    std::string fullName;
    std::cout << "\nEnter your full name: ";
    std::getline(std::cin, fullName);
    
    std::cout << "Full name: " << fullName << '\n';
    
    return 0;
}
