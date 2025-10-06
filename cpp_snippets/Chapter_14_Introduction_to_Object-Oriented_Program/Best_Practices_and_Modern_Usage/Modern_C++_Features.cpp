// C++11: Default and delete
class NonCopyable {
public:
    NonCopyable() = default;                           // ✅ Explicitly defaulted
    NonCopyable(const NonCopyable&) = delete;         // ✅ Explicitly deleted
    NonCopyable& operator=(const NonCopyable&) = delete;
};

// C++11: Delegating constructors
class Rectangle {
public:
    Rectangle(double w, double h) : m_width{w}, m_height{h} {}
    Rectangle() : Rectangle(1.0, 1.0) {}              // ✅ Delegates to main constructor
};

// C++14: Auto return type deduction
class Calculator {
public:
    auto add(double a, double b) const { return a + b; }  // ✅ Auto deduced as double
};
