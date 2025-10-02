#include <iostream>
#include <stdexcept>
#include <cmath>

// ✅ Exception-based error handling
class MathException : public std::runtime_error 
{
public:
    MathException(const std::string& message) 
        : std::runtime_error("Math Error: " + message) {}
};

class DivideByZeroException : public MathException 
{
public:
    DivideByZeroException() 
        : MathException("Division by zero attempted") {}
};

class NegativeInputException : public MathException 
{
public:
    NegativeInputException(const std::string& operation) 
        : MathException("Negative input not allowed for " + operation) {}
};

double divide(double a, double b) 
{
    if (b == 0.0) 
    {
        throw DivideByZeroException();
    }
    
    return a / b;
}

double sqrt_positive(double x) 
{
    if (x < 0) 
    {
        throw NegativeInputException("square root");
    }
    
    return std::sqrt(x);
}

int main() 
{
    try 
    {
        // Clean, readable code without error checking clutter
        double result1 = divide(10.0, 2.0);
        double result2 = sqrt_positive(result1);
        double final_result = divide(result2, 3.0);
        
        std::cout << "Final result: " << final_result << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cout << "Counter error: " << e.what() << "\n";
        std::cout << "Final count: " << counter.getValue() << "\n";
    }
}

int main() 
{
    demonstrateRAII();
    return 0;
}
