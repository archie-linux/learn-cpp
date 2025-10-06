#include <iostream>

constexpr double calcCircumference(double radius) // ✅ Now a constexpr function
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

int main()
{
    constexpr double circumference { calcCircumference(3.0) }; // ✅ Now compiles
    std::cout << "Our circle has circumference " << circumference << "\n";
    return 0;
}
