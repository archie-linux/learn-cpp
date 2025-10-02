#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>

// Basic variadic template
template<typename... Args>
void print(Args&&... args) {
    ((std::cout << args << " "), ...);  // C++17 fold expression
    std::cout << "\n";
}

// Recursive variadic template (pre-C++17 style)
template<typename First>
void print_recursive(First&& first) {
    std::cout << first << "\n";
}

template<typename First, typename... Rest>
void print_recursive(First&& first, Rest&&... rest) {
    std::cout << first << " ";
    print_recursive(rest...);
}

// Perfect forwarding with variadic templates
template<typename T, typename... Args>
std::unique_ptr<T> make_unique_variadic(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class ComplexObject {
public:
    ComplexObject(const std::string& name, int value, double rate) 
        : name_(name), value_(value), rate_(rate) {
        std::cout << "ComplexObject created: " << name_ << "\n";
    }
    
private:
    std::string name_;
    int value_;
    double rate_;
};

// Variadic template for string formatting
template<typename... Args>
std::string format_string(const std::string& format, Args&&... args) {
    std::ostringstream oss;
    format_impl(oss, format, std::forward<Args>(args)...);
    return oss.str();
}

template<typename T>
void format_impl(std::ostringstream& oss, const std::string& format, T&& value) {
    size_t pos = format.find("{}");
    if (pos != std::string::npos) {
        oss << format.substr(0, pos) << value << format.substr(pos + 2);
    } else {
        oss << format;
    }
}

template<typename T, typename... Args>
void format_impl(std::ostringstream& oss, const std::string& format, T&& value, Args&&... args) {
    size_t pos = format.find("{}");
    if (pos != std::string::npos) {
        oss << format.substr(0, pos) << value;
        format_impl(oss, format.substr(pos + 2), std::forward<Args>(args)...);
    } else {
        oss << format;
    }
}

void demonstrateVariadicTemplates() {
    // Basic usage
    print("Hello", "World", 42, 3.14, true);
    print_recursive("Recursive:", 1, 2, 3);
    
    // Perfect forwarding
    auto obj = make_unique_variadic<ComplexObject>("Test", 100, 2.5);
    
    // String formatting
    std::string result = format_string("Value: {}, Rate: {}, Active: {}", 42, 3.14, true);
    std::cout << result << "\n";
}
