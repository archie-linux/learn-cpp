#include <iostream>

int main() 
{
    int age = 25;
    int votingAge = 18;
    int retirementAge = 65;
    
    // Basic comparisons
    std::cout << std::boolalpha;  // Print true/false instead of 1/0
    
    std::cout << "age == votingAge: " << (age == votingAge) << '\n';      // false
    std::cout << "age != votingAge: " << (age != votingAge) << '\n';      // true
    std::cout << "age >= votingAge: " << (age >= votingAge) << '\n';      // true
    std::cout << "age > votingAge: " << (age > votingAge) << '\n';        // true
    std::cout << "age < retirementAge: " << (age < retirementAge) << '\n'; // true
    std::cout << "age <= retirementAge: " << (age <= retirementAge) << '\n'; // true
    
    return 0;
}
