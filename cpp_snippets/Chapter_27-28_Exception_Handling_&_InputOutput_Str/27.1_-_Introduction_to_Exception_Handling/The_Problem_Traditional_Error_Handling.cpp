#include <iostream>
#include <cstdlib>

// ❌ Traditional error handling with return codes
enum ErrorCode { SUCCESS = 0, DIVIDE_BY_ZERO = 1, NEGATIVE_INPUT = 2 };

ErrorCode divide(double a, double b, double& result) 
{
    if (b == 0.0) 
    {
        return DIVIDE_BY_ZERO;
    }
    
    if (a < 0 || b < 0) 
    {
        return NEGATIVE_INPUT;
    }
    
    result = a / b;
    return SUCCESS;
}

ErrorCode sqrt_positive(double x, double& result) 
{
    if (x < 0) 
    {
        return NEGATIVE_INPUT;
    }
    
    result = std::sqrt(x);
    return SUCCESS;
}

int main() 
{
    double result1, result2, final_result;
    
    // Lots of error checking code!
    ErrorCode err = divide(10.0, 2.0, result1);
    if (err != SUCCESS) 
    {
        std::cout << "Division failed with error: " << err << "\n";
        return 1;
    }
    
    err = sqrt_positive(result1, result2);
    if (err != SUCCESS) 
    {
        std::cout << "Square root failed with error: " << err << "\n";
        return 1;
    }
    
    err = divide(result2, 3.0, final_result);
    if (err != SUCCESS) 
    {
        std::cout << "Final division failed with error: " << err << "\n";
        return 1;
    }
    
    std::cout << "Final result: " << final_result << "\n";
    return 0;
}
