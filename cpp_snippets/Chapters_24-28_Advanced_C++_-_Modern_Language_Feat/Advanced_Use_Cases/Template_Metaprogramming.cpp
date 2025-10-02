template<int N>
constexpr int fibonacci()
{
    if constexpr (N <= 1)
        return N;
    else
        return fibonacci<N-1>() + fibonacci<N-2>();
}

int main()
{
    constexpr int fib10 { fibonacci<10>() }; // Computed at compile-time
    return 0;
}
