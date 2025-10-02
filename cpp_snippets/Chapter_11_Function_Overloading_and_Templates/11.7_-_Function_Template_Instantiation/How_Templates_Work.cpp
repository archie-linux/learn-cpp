template <typename T>
T square(T x) 
{
    return x * x;
}

int main() 
{
    auto result1 = square<int>(5);    // Instantiates square<int>
    auto result2 = square<double>(3.14); // Instantiates square<double>
    return 0;
}
