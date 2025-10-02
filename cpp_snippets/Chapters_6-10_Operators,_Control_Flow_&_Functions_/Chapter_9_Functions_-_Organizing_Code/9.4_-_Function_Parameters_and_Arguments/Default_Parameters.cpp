#include <iostream>

// Functions with default parameters
void printMessage(const std::string& message, int times = 1) 
{
    for (int i = 0; i < times; ++i) 
    {
        std::cout << message << '\n';
    }
}

double calculatePower(double base, double exponent = 2.0) 
{
    return std::pow(base, exponent);
}

void displayStudentInfo(const std::string& name, 
                       const std::string& major = "Undeclared", 
                       int year = 1) 
{
    std::cout << "Student: " << name << '\n';
    std::cout << "Major: " << major << '\n';
    std::cout << "Year: " << year << '\n';
    std::cout << "---\n";
}

int main() 
{
    // Using default parameters
    printMessage("Hello World");          // times = 1 (default)
    printMessage("Repeat this", 3);       // times = 3
    
    std::cout << "2^2 = " << calculatePower(2) << '\n';      // exponent = 2.0 (default)
    std::cout << "2^3 = " << calculatePower(2, 3) << '\n';   // exponent = 3
    
    displayStudentInfo("Alice");                                    // All defaults
    displayStudentInfo("Bob", "Computer Science");                  // year = 1 (default)
    displayStudentInfo("Charlie", "Mathematics", 3);               // No defaults
    
    return 0;
}
