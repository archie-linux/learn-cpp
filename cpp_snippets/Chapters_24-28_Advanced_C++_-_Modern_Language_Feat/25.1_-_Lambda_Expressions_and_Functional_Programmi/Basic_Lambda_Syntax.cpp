#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void basicLambdas() {
    // Basic lambda syntax: [capture](parameters) -> return_type { body }
    
    // Simple lambda
    auto greet = []() {
        std::cout << "Hello, World!\n";
    };
    greet();
    
    // Lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << "3 + 4 = " << add(3, 4) << "\n";
    
    // Lambda with explicit return type
    auto divide = [](double a, double b) -> double {
        if (b != 0.0) {
            return a / b;
        }
        throw std::invalid_argument("Division by zero");
    };
    
    // Generic lambda (C++14)
    auto generic_add = [](auto a, auto b) {
        return a + b;
    };
    
    std::cout << generic_add(1, 2) << "\n";      // int + int
    std::cout << generic_add(1.5, 2.5) << "\n"; // double + double
    std::cout << generic_add(std::string("Hello"), std::string(" World")) << "\n"; // string + string
}
