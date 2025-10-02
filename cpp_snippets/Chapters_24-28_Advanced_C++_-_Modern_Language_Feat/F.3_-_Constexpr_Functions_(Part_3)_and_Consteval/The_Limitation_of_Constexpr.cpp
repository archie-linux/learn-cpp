constexpr int slowComputation(int n)
{
    // Imagine this is expensive
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += i * i;
    }
    return result;
}

int main()
{
    // We WANT this computed at compile-time, but it might not be!
    int value { slowComputation(1000) }; // Might be runtime evaluation
    return 0;
}
