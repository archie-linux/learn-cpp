// C++11: Auto keyword for type deduction
auto name = std::string("Alice");    // ✅ Compiler deduces type

// C++11: Uniform initialization
int score{100};                      // ✅ Brace initialization
std::string title{"C++ Programming"}; // ✅ Consistent syntax

// C++11: Range-based for loops (when applicable)
std::string text = "Hello";
for (char c : text) {               // ✅ Modern iteration
    std::cout << c << ' ';
}
