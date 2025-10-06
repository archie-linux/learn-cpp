#include <iostream>
#include <string>

// T& is an lvalue reference - preferred for lvalues
template <typename T>
constexpr bool is_lvalue(T&) { return true; }

// T&& is an rvalue reference - preferred for rvalues  
template <typename T>
constexpr bool is_lvalue(T&&) { return false; }

#define TEST_CATEGORY(expr) \
    std::cout << #expr << " is " << (is_lvalue(expr) ? "lvalue" : "rvalue") << '\n';

int getNumber() { return 42; }

int main() 
{
    int x = 5;
    
    TEST_CATEGORY(x);                    // lvalue
    TEST_CATEGORY(42);                   // rvalue
    TEST_CATEGORY(x + 1);                // rvalue  
    TEST_CATEGORY(++x);                  // lvalue
    TEST_CATEGORY(x++);                  // rvalue
    TEST_CATEGORY(getNumber());          // rvalue
    TEST_CATEGORY("Hello");              // lvalue (special case!)
    TEST_CATEGORY(std::string("Hello")); // rvalue
    
    return 0;
}
