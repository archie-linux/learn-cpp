template <typename T>
T max(T x, T y)  // Both parameters must be the same type!
{
    return (x < y) ? y : x;
}

int main() 
{
    // max(5, 3.14); // ❌ ERROR: Can't deduce T (int vs double)
    return 0;
}
