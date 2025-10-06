#include <iostream>
#include <iomanip>
#include <string>

int main() 
{
    std::cout << "Advanced Output Formatting\n";
    std::cout << "==========================\n";
    
    // Different ways to create new lines
    std::cout << "Method 1: Using \\n" << '\n';
    std::cout << "Method 2: Using std::endl" << std::endl;  // Flushes buffer too
    
    // Formatting numbers
    double price = 19.99;
    double tax = 1.6;
    double total = price + tax;
    
    std::cout << std::fixed << std::setprecision(2);  // 2 decimal places
    std::cout << "Item Price: $" << price << '\n';
    std::cout << "Tax:        $" << tax << '\n';
    std::cout << "Total:      $" << total << '\n';
    
    // Formatting with width and alignment
    std::cout << "\nFormatted Table:\n";
    std::cout << std::left << std::setw(12) << "Product" 
              << std::right << std::setw(8) << "Price" << '\n';
    std::cout << std::left << std::setw(12) << "Laptop" 
              << std::right << std::setw(8) << "$899.99" << '\n';
    std::cout << std::left << std::setw(12) << "Mouse" 
              << std::right << std::setw(8) << "$24.99" << '\n';
    
    // Boolean values
    bool inStock = true;
    bool onSale = false;
    
    std::cout << "\nBoolean Display:\n";
    std::cout << "In Stock: " << inStock << " (numeric)\n";  // Shows 1
    std::cout << std::boolalpha;  // Switch to text display
    std::cout << "In Stock: " << inStock << " (text)\n";     // Shows true
    std::cout << "On Sale: " << onSale << " (text)\n";       // Shows false
    
    return 0;
}
