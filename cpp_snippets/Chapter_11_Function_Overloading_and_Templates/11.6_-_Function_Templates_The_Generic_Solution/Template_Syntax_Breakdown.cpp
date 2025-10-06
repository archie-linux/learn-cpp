template <typename T>  // Template parameter declaration
T max(T x, T y)       // Function template definition
{
    return (x < y) ? y : x;
}
