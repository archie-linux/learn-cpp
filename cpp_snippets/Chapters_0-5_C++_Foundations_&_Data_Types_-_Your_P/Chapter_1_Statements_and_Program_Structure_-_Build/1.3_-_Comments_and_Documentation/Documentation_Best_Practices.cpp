#include <iostream>

int main() 
{
    // ✅ Good comments explain WHY, not just WHAT
    const double TAX_RATE = 0.08;  // State sales tax rate (8%)
    
    double price = 29.99;
    
    // Calculate final price including tax for customer receipt
    double finalPrice = price + (price * TAX_RATE);
    
    std::cout << "Item price: $" << price << '\n';
    std::cout << "Tax: $" << (price * TAX_RATE) << '\n';
    std::cout << "Total: $" << finalPrice << '\n';
    
    return 0;
}
