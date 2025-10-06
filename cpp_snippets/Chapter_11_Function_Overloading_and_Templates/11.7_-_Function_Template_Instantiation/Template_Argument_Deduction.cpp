template <typename T>
T add(T x, T y) 
{
    return x + y;
}

int main() 
{
    // All equivalent calls:
    auto result1 = add<int>(5, 3);    // Explicit template argument
    auto result2 = add<>(5, 3);       // Empty angle brackets
    auto result3 = add(5, 3);         // Template argument deduction (preferred)
    
    return 0;
}
