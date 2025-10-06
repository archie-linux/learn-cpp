#include <iostream>
#include <string>
#include <utility>

void demonstrateValueCategories() {
    std::string str = "Hello";
    
    // lvalues (have names, can appear on left of assignment)
    std::string& lref = str;        // lvalue reference
    const std::string& clref = str; // const lvalue reference
    
    // rvalues (temporary objects, literals)
    std::string&& rref = std::move(str);  // rvalue reference
    std::string&& rref2 = "World";        // rvalue reference to temporary
    
    // Functions can be overloaded based on value category
    auto result1 = processString(str);           // Calls lvalue version
    auto result2 = processString(std::move(str)); // Calls rvalue version
    auto result3 = processString("literal");      // Calls rvalue version
}

// Overloaded functions for different value categories
std::string processString(const std::string& s) {  // lvalue version
    std::cout << "Processing lvalue: " << s << "\n";
    return s;  // Copy
}

std::string processString(std::string&& s) {  // rvalue version
    std::cout << "Processing rvalue: " << s << "\n";
    return std::move(s);  // Move
}
