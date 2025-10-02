#include <iostream>

int main() 
{
    char grade = 'B';
    
    std::cout << "Grade " << grade << ": ";
    
    switch (grade) 
    {
        case 'A':
            std::cout << "Excellent! ";
            [[fallthrough]];  // C++17: explicit fallthrough
        case 'B':
            std::cout << "Good work! ";
            [[fallthrough]];
        case 'C':
            std::cout << "Passing grade. ";
            break;
        case 'D':
            std::cout << "Below average. ";
            break;
        case 'F':
            std::cout << "Failing grade. ";
            break;
        default:
            std::cout << "Invalid grade. ";
            break;
    }
    
    std::cout << '\n';
    return 0;
}
