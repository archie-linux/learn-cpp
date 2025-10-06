#include <iostream>

// Demonstrate memory-efficient vs memory-wasteful approaches
int main() 
{
    std::cout << "Memory Efficiency Examples\n";
    std::cout << "==========================\n";
    
    // Example 1: Choosing appropriate data types
    
    // ❌ Memory wasteful for small values
    long long studentAge = 20;        // 8 bytes for a value that fits in 1 byte
    double simpleCounter = 5;         // 8 bytes for integer data
    
    // ✅ Memory efficient
    unsigned char betterAge = 20;     // 1 byte (can hold 0-255)
    int betterCounter = 5;            // 4 bytes, appropriate for integers
    
    std::cout << "Wasteful approach: " << sizeof(studentAge) + sizeof(simpleCounter) << " bytes\n";
    std::cout << "Efficient approach: " << sizeof(betterAge) + sizeof(betterCounter) << " bytes\n";
    
    // Example 2: Understanding the impact with large datasets
    const int ARRAY_SIZE = 1000;
    
    double largeArray[ARRAY_SIZE];         // 8000 bytes (8 * 1000)
    float smallerArray[ARRAY_SIZE];        // 4000 bytes (4 * 1000)
    
    std::cout << "\nFor " << ARRAY_SIZE << " elements:\n";
    std::cout << "double array: " << sizeof(largeArray) << " bytes\n";
    std::cout << "float array: " << sizeof(smallerArray) << " bytes\n";
    std::cout << "Memory saved: " << sizeof(largeArray) - sizeof(smallerArray) << " bytes\n";
    
    return 0;
}
