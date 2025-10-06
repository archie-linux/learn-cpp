constexpr int square(int x)  // x is NOT constexpr
{
    // x is treated as a runtime variable within the function
    return x * x;
}

int main()
{
    constexpr int result { square(5) }; // ✅ Works: argument 5 is compile-time constant
    return 0;
}
