consteval int mandatoryCompileTime(int x)
{
    return x * x + 10;
}

int main()
{
    constexpr int result1 { mandatoryCompileTime(5) }; // ✅ Compile-time
    
    int runtime_val = 5;
    // int result2 { mandatoryCompileTime(runtime_val) }; // ❌ COMPILE ERROR!
    
    return 0;
}
