#include <iostream>
#include <string>

// Function template - works with any type
template<typename T>
T getMax(T a, T b) 
{
    return (a > b) ? a : b;
}

// Function template with multiple type parameters
template<typename T, typename U>
void printPair(T first, U second) 
{
    std::cout << "(" << first << ", " << second << ")\n";
}

// Template specialization for strings
template<>
std::string getMax<std::string>(std::string a, std::string b) 
{
    std::cout << "Using specialized string version\n";
    return (a.length() > b.length()) ? a : b;
}

int main() 
{
    // Template automatically deduces types
    std::cout << "Max of 10 and 20: " << getMax(10, 20) << '\n';           // int
    std::cout << "Max of 3.14 and 2.71: " << getMax(3.14, 2.71) << '\n';   // double
    std::cout << "Max of 'a' and 'z': " << getMax('a', 'z') << '\n';       // char
    
    // Using specialized template
    std::cout << "Max string: " << getMax(std::string("hello"), std::string("world")) << '\n';
    
    // Multiple template parameters
    printPair(10, "hello");        // int, string
    printPair(3.14, true);         // double, bool
    printPair("name", 42);         // string, int
    
    return 0;
}
