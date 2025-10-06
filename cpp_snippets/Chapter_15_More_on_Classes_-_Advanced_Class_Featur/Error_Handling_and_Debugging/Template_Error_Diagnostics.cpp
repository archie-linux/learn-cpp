#include <type_traits>
#include <string>

// Better error messages with static_assert
template <typename T>
class NumericContainer 
{
    static_assert(std::is_arithmetic_v<T>, 
                  "NumericContainer requires arithmetic types (int, float, double, etc.)");
    
private:
    T value{};
    
public:
    explicit NumericContainer(T v) : value(v) {}
    
    T getValue() const { return value; }
    
    // Operations only available for numeric types
    NumericContainer operator+(const NumericContainer& other) const 
    {
        return NumericContainer(value + other.value);
    }
    
    NumericContainer operator*(const NumericContainer& other) const 
    {
        return NumericContainer(value * other.value);
    }
};

// Concept-based constraints (C++20)
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

template <Numeric T>
class BetterNumericContainer 
{
private:
    T value{};
    
public:
    explicit BetterNumericContainer(T v) : value(v) {}
    T getValue() const { return value; }
};

// SFINAE-friendly detection
template <typename T, typename = void>
struct has_begin : std::false_type {};

template <typename T>
struct has_begin<T, std::void_t<decltype(std::begin(std::declval<T>()))>> : std::true_type {};

template <typename Container>
auto safeIterate(Container&& container) 
    -> std::enable_if_t<has_begin<Container>::value, void> 
{
    std::cout << "Iterating over container:\n";
    for (const auto& item : container) 
    {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

template <typename T>
auto safeIterate(T&& item) 
    -> std::enable_if_t<!has_begin<T>::value, void> 
{
    std::cout << "Single item: " << item << '\n';
}

void demonstrateErrorHandling() 
{
    std::cout << "\n=== Template Error Handling ===\n";
    
    // These work fine
    NumericContainer<int> intContainer(42);
    NumericContainer<double> doubleContainer(3.14);
    
    std::cout << "Int container: " << intContainer.getValue() << '\n';
    std::cout << "Double container: " << doubleContainer.getValue() << '\n';
    
    auto sum = intContainer + NumericContainer<int>(8);
    std::cout << "Sum: " << sum.getValue() << '\n';
    
    // This would cause a compile-time error:
    // NumericContainer<std::string> stringContainer("hello"); // Error!
    
    // SFINAE-based safe iteration
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::string str = "hello";
    
    safeIterate(vec);   // Uses container version
    safeIterate(42);    // Uses single item version
}
