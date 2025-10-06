#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

// SFINAE (Substitution Failure Is Not An Error) examples

// Enable function only for integral types
template<typename T>
std::enable_if_t<std::is_integral_v<T>, void>
process_integral(T value) {
    std::cout << "Processing integral value: " << value << "\n";
}

// Enable function only for floating point types
template<typename T>
std::enable_if_t<std::is_floating_point_v<T>, void>
process_floating_point(T value) {
    std::cout << "Processing floating point value: " << value << "\n";
}

// Detect if a type has a specific member function
template<typename T, typename = void>
struct has_size : std::false_type {};

template<typename T>
struct has_size<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

template<typename T>
constexpr bool has_size_v = has_size<T>::value;

// Function overloading based on type traits
template<typename Container>
std::enable_if_t<has_size_v<Container>, size_t>
get_size(const Container& container) {
    return container.size();
}

template<typename T>
std::enable_if_t<!has_size_v<T>, size_t>
get_size(const T&) {
    return 1;  // Assume single element for non-containers
}

// if constexpr (C++17) - compile-time conditional
template<typename T>
void process_value(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integral: " << value << " (squared: " << value * value << ")\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Float: " << value << " (sqrt: " << std::sqrt(value) << ")\n";
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::cout << "String: '" << value << "' (length: " << value.length() << ")\n";
    } else {
        std::cout << "Other type\n";
    }
}

void demonstrateSFINAE() {
    // Type-based function selection
    process_integral(42);
    process_floating_point(3.14);
    
    // Member detection
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::string str = "hello";
    int single_value = 42;
    
    std::cout << "Vector size: " << get_size(vec) << "\n";
    std::cout << "String size: " << get_size(str) << "\n";
    std::cout << "Int 'size': " << get_size(single_value) << "\n";
    
    // if constexpr usage
    process_value(42);
    process_value(3.14);
    process_value(std::string("Hello"));
}
