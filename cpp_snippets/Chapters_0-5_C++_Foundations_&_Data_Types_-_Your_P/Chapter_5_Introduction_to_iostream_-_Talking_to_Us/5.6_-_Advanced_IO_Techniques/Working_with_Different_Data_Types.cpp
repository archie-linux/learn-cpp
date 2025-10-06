#include <iostream>
#include <string>
#include <sstream>
#include <limits>

int main() 
{
    std::cout << "Advanced Input/Output Techniques\n";
    std::cout << "================================\n";
    
    // Safe input function for integers
    auto getInteger = [](const std::string& prompt) -> int 
    {
        int value;
        while (true) 
        {
            std::cout << prompt;
            if (std::cin >> value) 
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            } 
            else 
            {
                std::cout << "Invalid input! Please enter a whole number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    };
    
    // Safe input function for doubles
    auto getDouble = [](const std::string& prompt) -> double 
    {
        double value;
        while (true) 
        {
            std::cout << prompt;
            if (std::cin >> value) 
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            } 
            else 
            {
                std::cout << "Invalid input! Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    };
    
    // Using the safe input functions
    int age = getInteger("Enter your age: ");
    double salary = getDouble("Enter your salary: ");
    
    std::cout << "You are " << age << " years old with a salary of $" 
              << std::fixed << std::setprecision(2) << salary << '\n';
    
    // String stream for parsing
    std::string dateInput;
    std::cout << "Enter a date (MM/DD/YYYY): ";
    std::getline(std::cin, dateInput);
    
    // Replace slashes with spaces for easier parsing
    for (char& c : dateInput) 
    {
        if (c == '/') c = ' ';
    }
    
    std::stringstream ss(dateInput);
    int month, day, year;
    if (ss >> month >> day >> year) 
    {
        std::cout << "Parsed date: Month=" << month 
                  << ", Day=" << day << ", Year=" << year << '\n';
        
        // Validate date
        bool validDate = true;
        if (month < 1 || month > 12) validDate = false;
        if (day < 1 || day > 31) validDate = false;
        if (year < 1900 || year > 2100) validDate = false;
        
        std::cout << "Date is " << (validDate ? "valid" : "invalid") << '\n';
    } 
    else 
    {
        std::cout << "Could not parse the date!\n";
    }
    
    return 0;
}
