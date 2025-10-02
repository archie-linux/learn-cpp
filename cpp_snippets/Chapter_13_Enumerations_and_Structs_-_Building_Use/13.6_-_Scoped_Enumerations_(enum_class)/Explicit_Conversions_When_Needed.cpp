#include <iostream>
#include <utility>  // for std::to_underlying (C++23)

enum class ErrorCode 
{
    none = 0,
    fileNotFound = 404,
    serverError = 500,
    timeout = 408
};

void logError(ErrorCode code) 
{
    // Method 1: static_cast (all C++ versions)
    std::cout << "Error code: " << static_cast<int>(code) << '\n';
    
    // Method 2: std::to_underlying (C++23 - preferred)
    // std::cout << "Error code: " << std::to_underlying(code) << '\n';
}

int main() 
{
    ErrorCode error = ErrorCode::fileNotFound;
    logError(error);  // prints: Error code: 404
    
    return 0;
}
