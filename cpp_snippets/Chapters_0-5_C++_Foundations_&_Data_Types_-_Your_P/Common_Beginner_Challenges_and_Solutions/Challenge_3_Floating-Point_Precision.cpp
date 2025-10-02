#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Floating-Point Precision Issues\n";
    std::cout << "===============================\n";
    
    double a = 0.1;
    double b = 0.2;
    double sum = a + b;
    
    std::cout << std::setprecision(17);
    std::cout << "0.1 + 0.2 = " << sum << '\n';
    std::cout << "Expected: 0.3\n";
    std::cout << "Equal to 0.3? " << (sum == 0.3 ? "Yes" : "No") << '\n';
    
    // Safe comparison for floating-point
    const double EPSILON = 1e-9;
    bool approximately_equal = std::abs(sum - 0.3) < EPSILON;
    std::cout << "Approximately equal? " << (approximately_equal ? "Yes" : "No") << '\n';
    
    return 0;
}
