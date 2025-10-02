#include <iostream>
#include <type_traits>

// Compile-time factorial
template <int N>
struct Factorial 
{
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> 
{
    static constexpr int value = 1;
};

// SFINAE-based type traits
template <typename T, typename = void>
struct has_size_method : std::false_type {};

template <typename T>
struct has_size_method<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

// Template specialization based on type traits
template <typename Container>
auto getSize(const Container& c) -> std::enable_if_t<has_size_method<Container>::value, size_t> 
{
    return c.size();
}

template <typename Container>
auto getSize(const Container& c) -> std::enable_if_t<!has_size_method<Container>::value, size_t> 
{
    return std::distance(std::begin(c), std::end(c));
}

// Concepts (C++20)
template <typename T>
concept Printable = requires(T t) 
{
    std::cout << t;
};

template <Printable T>
void safePrint(const T& value) 
{
    std::cout << "Printing: " << value << '\n';
}
