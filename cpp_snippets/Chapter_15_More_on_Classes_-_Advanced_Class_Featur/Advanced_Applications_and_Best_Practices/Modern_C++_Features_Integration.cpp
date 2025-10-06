// C++17: Structured bindings with custom types
struct Point3D 
{
    double x, y, z;
    
    // Enable structured bindings
    template <size_t I>
    auto get() const 
    {
        if constexpr (I == 0) return x;
        else if constexpr (I == 1) return y;
        else if constexpr (I == 2) return z;
    }
};

// Specialize std::tuple_size and std::tuple_element
namespace std 
{
    template <>
    struct tuple_size<Point3D> : std::integral_constant<size_t, 3> {};
    
    template <size_t I>
    struct tuple_element<I, Point3D> 
    {
        using type = double;
    };
}

// C++20: Abbreviated function templates
void processAny(auto&& value) 
{
    std::cout << "Processing: " << value << '\n';
}

// C++20: Requires clauses
template <typename T>
requires std::integral<T> || std::floating_point<T>
T multiply(T a, T b) 
{
    return a * b;
}
