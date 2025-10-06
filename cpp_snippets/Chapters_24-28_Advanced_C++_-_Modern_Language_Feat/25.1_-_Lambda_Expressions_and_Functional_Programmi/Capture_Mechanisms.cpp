#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

void demonstrateCaptures() {
    int x = 10;
    int y = 20;
    
    // Capture by value
    auto lambda1 = [x, y](int z) {
        return x + y + z;  // x and y are copied
    };
    
    // Capture by reference
    auto lambda2 = [&x, &y](int z) {
        x += z;  // Modifies original x
        return x + y;
    };
    
    // Capture all by value
    auto lambda3 = [=](int z) {
        return x + y + z;  // All variables copied
    };
    
    // Capture all by reference
    auto lambda4 = [&](int z) {
        x += z;  // All variables by reference
        return x + y;
    };
    
    // Mixed capture
    auto lambda5 = [=, &x](int z) {
        x += z;      // x by reference
        return x + y + z;  // y by value
    };
    
    // Init capture (C++14)
    auto lambda6 = [captured_value = x * 2](int z) {
        return captured_value + z;
    };
    
    // Move capture
    auto resource = std::make_unique<int>(42);
    auto lambda7 = [moved_resource = std::move(resource)](int multiplier) {
        return *moved_resource * multiplier;
    };
    
    std::cout << lambda1(5) << "\n";  // 35
    std::cout << lambda6(8) << "\n";  // 28 (x*2 + 8)
    std::cout << lambda7(3) << "\n";  // 126 (42 * 3)
}
