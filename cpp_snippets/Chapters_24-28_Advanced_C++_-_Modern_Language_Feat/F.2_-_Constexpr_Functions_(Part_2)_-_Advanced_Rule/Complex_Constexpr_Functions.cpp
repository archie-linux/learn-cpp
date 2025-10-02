constexpr int factorial(int n)
{
    if (n <= 1) return 1;
    
    int result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    constexpr int fact5 { factorial(5) }; // ✅ Computed at compile-time: 120
    return 0;
}
