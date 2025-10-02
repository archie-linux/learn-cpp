#include <iostream>
#include <cstring>

// General template
template <typename T>
bool isEqual(const T& a, const T& b) 
{
    return a == b;
}

// Explicit specialization for C-style strings
template <>
bool isEqual<const char*>(const char* const& a, const char* const& b) 
{
    return std::strcmp(a, b) == 0;  // Use strcmp for C-strings
}

int main() 
{
    // Uses general template
    std::cout << "5 == 5: " << isEqual(5, 5) << '\n';
    std::cout << "'hello' == 'hello': " << isEqual(std::string("hello"), std::string("hello")) << '\n';
    
    // Uses specialized version
    const char* str1 = "hello";
    const char* str2 = "hello";
    std::cout << "C-strings equal: " << isEqual(str1, str2) << '\n';
    
    return 0;
}
