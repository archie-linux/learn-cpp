#include <cmath>

constexpr double badExample(double x)
{
    return std::sqrt(x); // ❌ std::sqrt is not constexpr in many implementations
}

// Better approach
constexpr double goodExample(double x)
{
    // Implement your own compile-time safe version
    return x * x; // Simple example
}
