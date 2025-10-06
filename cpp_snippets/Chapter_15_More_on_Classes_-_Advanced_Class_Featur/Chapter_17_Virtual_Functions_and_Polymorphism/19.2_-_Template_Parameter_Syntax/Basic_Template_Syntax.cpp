// Single template parameter
template <typename T>
T add(const T& a, const T& b) 
{
    return a + b;
}

// Multiple template parameters
template <typename T, typename U>
auto multiply(const T& a, const U& b) -> decltype(a * b) 
{
    return a * b;
}

// Alternative syntax (equivalent to typename)
template <class T>
T square(const T& value) 
{
    return value * value;
}
