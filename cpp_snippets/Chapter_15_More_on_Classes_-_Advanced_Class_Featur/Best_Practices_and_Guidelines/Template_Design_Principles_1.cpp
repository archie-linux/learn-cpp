// C++20 concepts (preferred)
template <std::integral T>
void processInteger(T value) { /* ... */ }

// Pre-C++20 SFINAE
template <typename T>
std::enable_if_t<std::is_integral_v<T>, void>
processInteger(T value) { /* ... */ }
