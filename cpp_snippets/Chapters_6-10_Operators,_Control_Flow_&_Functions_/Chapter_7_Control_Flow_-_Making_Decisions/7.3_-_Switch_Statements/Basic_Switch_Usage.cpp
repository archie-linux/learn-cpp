#include <iostream>

int main() 
{
    int dayOfWeek = 3;
    
    switch (dayOfWeek) 
    {
        case 1:
            std::cout << "Monday - Start of work week\n";
            break;
        case 2:
            std::cout << "Tuesday - Getting into the rhythm\n";
            break;
        case 3:
            std::cout << "Wednesday - Hump day!\n";
            break;
        case 4:
            std::cout << "Thursday - Almost there\n";
            break;
        case 5:
            std::cout << "Friday - TGIF!\n";
            break;
        case 6:
        case 7:
            std::cout << "Weekend - Relax time!\n";
            break;
        default:
            std::cout << "Invalid day number\n";
            break;
    }
    
    return 0;
}
