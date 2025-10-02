constexpr double pow(double base, int exponent)
{
    if (exponent == 0) return 1.0;
    if (exponent < 0) return 1.0 / pow(base, -exponent);
    
    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

int main()
{
    constexpr double result { pow(2.0, 10) }; // 1024.0 computed at compile-time
    return 0;
}
