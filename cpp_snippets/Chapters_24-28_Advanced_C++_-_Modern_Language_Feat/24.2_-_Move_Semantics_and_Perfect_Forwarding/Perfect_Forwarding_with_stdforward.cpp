#include <iostream>
#include <memory>
#include <utility>

class Widget {
public:
    Widget() { std::cout << "Widget default constructor\n"; }
    Widget(const Widget&) { std::cout << "Widget copy constructor\n"; }
    Widget(Widget&&) noexcept { std::cout << "Widget move constructor\n"; }
    
    explicit Widget(int value) { 
        std::cout << "Widget constructor with value: " << value << "\n"; 
    }
    
    Widget(const std::string& name, int value) {
        std::cout << "Widget constructor: " << name << ", " << value << "\n";
    }
};

// Factory function with perfect forwarding
template<typename T, typename... Args>
std::unique_ptr<T> make_unique_perfect(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

// Wrapper that forwards arguments perfectly
template<typename F, typename... Args>
decltype(auto) call_with_timing(F&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Perfect forwarding preserves value categories
    decltype(auto) result = std::forward<F>(func)(std::forward<Args>(args)...);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Function took " << duration.count() << " microseconds\n";
    
    return result;
}

void demonstratePerfectForwarding() {
    // Perfect forwarding in factory functions
    auto widget1 = make_unique_perfect<Widget>();                    // Default construction
    auto widget2 = make_unique_perfect<Widget>(42);                  // Value construction
    auto widget3 = make_unique_perfect<Widget>("Test", 100);         // Multi-argument
    
    // Perfect forwarding with function wrappers
    Widget w;
    auto result = call_with_timing([](const Widget& w) { return w; }, w);         // lvalue
    auto result2 = call_with_timing([](Widget w) { return w; }, std::move(w));    // rvalue
}
