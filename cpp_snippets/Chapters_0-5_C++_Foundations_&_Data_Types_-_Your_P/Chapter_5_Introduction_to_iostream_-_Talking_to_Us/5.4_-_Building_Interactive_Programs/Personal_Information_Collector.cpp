#include <iostream>
#include <string>
#include <iomanip>

int main() 
{
    std::cout << "Personal Information Collector\n";
    std::cout << "==============================\n";
    
    // Collect various types of information
    std::string firstName, lastName, city;
    int age, birthYear;
    double height, weight;
    char gender;
    bool hasJob;
    
    // Name information
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    
    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    
    // Numeric information
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    std::cout << "Enter your birth year: ";
    std::cin >> birthYear;
    
    std::cout << "Enter your height (in meters): ";
    std::cin >> height;
    
    std::cout << "Enter your weight (in kg): ";
    std::cin >> weight;
    
    // Character information
    std::cout << "Enter your gender (M/F): ";
    std::cin >> gender;
    
    // Boolean information (1 for true, 0 for false)
    std::cout << "Do you have a job? (1 for yes, 0 for no): ";
    std::cin >> hasJob;
    
    // Clear buffer for getline
    std::cin.ignore();
    
    // String with spaces
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    
    // Calculate BMI
    double bmi = weight / (height * height);
    
    // Display collected information
    std::cout << "\n" << std::string(40, '=') << '\n';
    std::cout << "PERSONAL INFORMATION SUMMARY\n";
    std::cout << std::string(40, '=') << '\n';
    
    std::cout << "Name: " << firstName << " " << lastName << '\n';
    std::cout << "Age: " << age << " (Born in " << birthYear << ")\n";
    std::cout << "City: " << city << '\n';
    std::cout << "Gender: " << gender << '\n';
    std::cout << "Employment: " << (hasJob ? "Employed" : "Unemployed") << '\n';
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Height: " << height << " m\n";
    std::cout << "Weight: " << weight << " kg\n";
    std::cout << "BMI: " << bmi;
    
    // BMI categories
    if (bmi < 18.5) 
    {
        std::cout << " (Underweight)";
    } 
    else if (bmi < 25) 
    {
        std::cout << " (Normal weight)";
    } 
    else if (bmi < 30) 
    {
        std::cout << " (Overweight)";
    } 
    else 
    {
        std::cout << " (Obese)";
    }
    std::cout << '\n';
    
    return 0;
}
