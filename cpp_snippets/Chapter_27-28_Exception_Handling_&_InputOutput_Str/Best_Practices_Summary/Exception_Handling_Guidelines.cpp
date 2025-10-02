// ✅ DO: Use specific exception types
throw std::invalid_argument("Parameter cannot be negative");

// ❌ DON'T: Throw primitive types
throw "Error message";  // Hard to catch specifically

// ✅ DO: Catch by const reference
catch (const std::exception& e) { /* ... */ }

// ❌ DON'T: Catch by value (expensive copy)
catch (std::exception e) { /* ... */ }

// ✅ DO: Order catch blocks from specific to general
try { /* ... */ }
catch (const std::invalid_argument& e) { /* specific */ }
catch (const std::logic_error& e) { /* more general */ }
catch (const std::exception& e) { /* most general */ }

// ✅ DO: Use RAII for resource management
{
    std::unique_ptr<Resource> resource = std::make_unique<Resource>();
    // Automatic cleanup even if exception occurs
}

// ✅ DO: Prefer noexcept for functions that won't throw
void utilityFunction() noexcept { /* ... */ }
