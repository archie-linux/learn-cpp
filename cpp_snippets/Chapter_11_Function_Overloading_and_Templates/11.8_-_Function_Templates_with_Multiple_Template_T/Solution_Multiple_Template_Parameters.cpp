template <typename T, typename U>
auto max(T x, U y) -> decltype(x < y ? y : x)  // C++11 trailing return type
{
    return (x < y) ? y : x;
}

// Or in C++14+, simply:
template <typename T, typename U>
auto max(T x, U y) 
{
    return (x < y) ? y : x;
}

int main() 
{
    std::cout << max(5, 3.14) << '\n';    // T=int, U=double, returns double
    std::cout << max(2.5, 1) << '\n';     // T=double, U=int, returns double
    return 0;
}
