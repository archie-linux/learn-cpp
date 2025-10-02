// C++11: auto keyword
auto result = calculateValue();  // ✅ Type deduction

// C++11: Lambda functions
auto isEven = [](int n) { return n % 2 == 0; };  // ✅ Inline functions

// C++14: Generic lambdas
auto printer = [](const auto& value) { std::cout << value; };  // ✅ Generic

// C++17: std::optional for error handling
std::optional<int> safeParse(const std::string& str);  // ✅ Safe returns

// C++20: Concepts for template constraints
template<typename T>
requires std::integral<T>
T add(T a, T b) { return a + b; }  // ✅ Constrained templates
