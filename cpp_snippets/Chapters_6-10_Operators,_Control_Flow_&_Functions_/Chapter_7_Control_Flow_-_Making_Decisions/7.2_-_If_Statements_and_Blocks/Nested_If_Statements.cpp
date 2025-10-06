#include <iostream>

int main() 
{
    int age = 25;
    bool hasLicense = true;
    bool hasInsurance = true;
    
    // Nested conditions for car rental eligibility
    if (age >= 18) 
    {
        std::cout << "Age requirement met.\n";
        
        if (hasLicense) 
        {
            std::cout << "License requirement met.\n";
            
            if (hasInsurance) 
            {
                std::cout << "All requirements met! You can rent a car.\n";
            } 
            else 
            {
                std::cout << "Insurance required.\n";
            }
        } 
        else 
        {
            std::cout << "Valid license required.\n";
        }
    } 
    else 
    {
        std::cout << "Must be 18 or older.\n";
    }
    
    return 0;
}
