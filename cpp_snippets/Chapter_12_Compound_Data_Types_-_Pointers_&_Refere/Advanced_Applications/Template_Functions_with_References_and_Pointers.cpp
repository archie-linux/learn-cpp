#include <iostream>
#include <string>

// Template function using const reference (efficient for large objects)
template <typename T>
void printTwice(const T& value) 
{
    std::cout << value << '\n';
    std::cout << value << '\n';
}

// Template function using pointers (can handle optional parameters)
template <typename T>
void printIfNotNull(const T* ptr) 
{
    if (ptr != nullptr) 
    {
        std::cout << *ptr << '\n';
    } 
    else 
    {
        std::cout << "null pointer!\n";
    }
}

int main() 
{
    std::string bigString = "This is a potentially large string object";
    int number = 42;
    
    // Efficient - no copying of large string
    printTwice(bigString);
    printTwice(number);
    
    // Safe pointer handling
    int* validPtr = &number;
    int* nullPtr = nullptr;
    
    printIfNotNull(validPtr);    // Prints: 42
    printIfNotNull(nullPtr);     // Prints: null pointer!
    
    return 0;
}
