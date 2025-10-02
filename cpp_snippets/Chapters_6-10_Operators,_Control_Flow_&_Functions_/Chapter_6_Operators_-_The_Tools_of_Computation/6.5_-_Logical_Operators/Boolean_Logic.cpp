#include <iostream>

int main() 
{
    bool hasTicket = true;
    bool hasID = true;
    bool isBanned = false;
    int age = 20;
    
    // Logical AND (&&) - all conditions must be true
    bool canEnterClub = hasTicket && hasID && !isBanned && (age >= 18);
    
    // Logical OR (||) - at least one condition must be true
    bool canGetDiscount = (age < 18) || (age >= 65);
    
    // Logical NOT (!) - negates boolean value
    bool cannotEnter = !canEnterClub;
    
    std::cout << std::boolalpha;
    std::cout << "Can enter club: " << canEnterClub << '\n';       // true
    std::cout << "Can get discount: " << canGetDiscount << '\n';   // false
    std::cout << "Cannot enter: " << cannotEnter << '\n';          // false
    
    return 0;
}
