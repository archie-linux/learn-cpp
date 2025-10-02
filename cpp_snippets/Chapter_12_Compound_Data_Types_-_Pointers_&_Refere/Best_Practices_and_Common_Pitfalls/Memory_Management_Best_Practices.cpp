#include <memory>

// ❌ Manual memory management (error-prone)
void badExample() 
{
    int* ptr = new int(42);
    // ... do work ...
    delete ptr;  // Easy to forget or miss on exception!
}

// ✅ RAII with smart pointers
void goodExample() 
{
    auto ptr = std::make_unique<int>(42);
    // ... do work ...
    // Automatic cleanup, exception-safe
}

// ✅ Stack allocation when possible
void bestExample() 
{
    int value = 42;  // No dynamic allocation needed
    // ... do work ...
    // Automatic cleanup
}
