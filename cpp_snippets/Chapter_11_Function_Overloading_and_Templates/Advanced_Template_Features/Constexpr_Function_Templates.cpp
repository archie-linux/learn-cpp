template <typename T>
constexpr T factorial(T n) 
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() 
{
    constexpr int fact5 = factorial(5);        // Computed at compile-time
    constexpr long fact10 = factorial(10L);    // Different type, still compile-time
    
    std::cout << "5! = " << fact5 << '\n';
    std::cout << "10! = " << fact10 << '\n';
    return 0;
}
