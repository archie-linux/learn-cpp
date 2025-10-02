template <typename T>
T max(T x, T y) 
{
    return (x < y) ? y : x;
}

int main() 
{
    std::cout << max<int>(5, 3) << '\n';      // Generates max<int>
    std::cout << max<double>(2.7, 4.1) << '\n'; // Generates max<double>
    std::cout << max<char>('a', 'z') << '\n';    // Generates max<char>
    return 0;
}
