#include <iostream>
#include <optional>  // C++17
#include <string>

// Function that might fail - returns optional
std::optional<double> safeDivide(double numerator, double denominator) 
{
    if (denominator == 0.0) 
    {
        return std::nullopt;  // Indicate failure
    }
    return numerator / denominator;
}

// Error handling with return codes
enum class MathError 
{
    None,
    DivisionByZero,
    NegativeSquareRoot,
    InvalidInput
};

MathError safeSquareRoot(double input, double& result) 
{
    if (input < 0) 
    {
        return MathError::NegativeSquareRoot;
    }
    
    result = std::sqrt(input);
    return MathError::None;
}

// Utility function for error messages
std::string errorToString(MathError error) 
{
    switch (error) 
    {
        case MathError::None: return "No error";
        case MathError::DivisionByZero: return "Division by zero";
        case MathError::NegativeSquareRoot: return "Negative square root";
        case MathError::InvalidInput: return "Invalid input";
        default: return "Unknown error";
    }
}

int main() 
{
    // Using optional return values
    auto result1 = safeDivide(10.0, 2.0);
    if (result1.has_value()) 
    {
        std::cout << "Division result: " << result1.value() << '\n';
    } 
    else 
    {
        std::cout << "Division failed!\n";
    }
    
    auto result2 = safeDivide(10.0, 0.0);
    if (!result2.has_value()) 
    {
        std::cout << "Cannot divide by zero!\n";
    }
    
    // Using error codes
    double sqrtResult;
    MathError error = safeSquareRoot(16.0, sqrtResult);
    
    if (error == MathError::None) 
    {
        std::cout << "Square root: " << sqrtResult << '\n';
    } 
    else 
    {
        std::cout << "Error: " << errorToString(error) << '\n';
    }
    
    // Test with negative number
    error = safeSquareRoot(-4.0, sqrtResult);
    if (error != MathError::None) 
    {
        std::cout << "Error: " << errorToString(error) << '\n';
    }
    
    return 0;
}
