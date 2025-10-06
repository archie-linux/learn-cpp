#include <iostream>
#include <vector>
#include <concepts>
#include <type_traits>

// Template specialization
template<typename T>
class Container {
public

# Advanced Functions: Constexpr and Consteval (Chapter F)

## F.1 - Constexpr Functions

### Introduction to Constexpr Functions

A constexpr function is a function that is allowed to be called in a constant expression. This is a powerful feature that bridges the gap between compile-time and runtime programming.

### The Problem: Functions in Constant Expressions

Consider this scenario where we want to calculate a circle's circumference at compile-time:

```cpp
#include <iostream>

// This works fine
int main()
{
    constexpr double radius { 3.0 };
    constexpr double pi { 3.14159265359 };
    constexpr double circumference { 2.0 * radius * pi };
    std::cout << "Our circle has circumference " << circumference << "\n";
    return 0;
}
