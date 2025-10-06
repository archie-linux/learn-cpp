#include <iostream>
#include <memory>
#include <utility>

class Widget 
{
private:
    std::string name;
    int value;
    
public:
    Widget(const std::string& n, int v) : name(n), value(v) 
    {
        std::cout << "Widget constructed: " << name << " = " << value << '\n';
    }
    
    Widget(std::string&& n, int v) : name(std::move(n)), value(v) 
    {
        std::cout << "Widget move-constructed: " << name << " = " << value << '\n';
    }
    
    const std::string& getName() const { return name; }
    int getValue() const { return value; }
};

// Perfect forwarding factory function
template <typename T, typename... Args>
std::unique_ptr<T> makeUnique(Args&&... args) 
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// Universal reference function
template <typename T>
void processValue(T&& value) 
{
    using ValueType = std::remove_reference_t<T>;
    
    if constexpr (std::is_lvalue_reference_v<T>) 
    {
        std::cout << "Received lvalue reference\n";
    }
    else 
    {
        std::cout << "Received rvalue reference\n";
    }
    
    // Forward the value maintaining its value category
    forwardToProcessor(std::forward<T>(value));
}

template <typename T>
void forwardToProcessor(T&& value) 
{
    std::cout << "Processing: " << value << '\n';
}

// Variadic template with perfect forwarding
template <typename Func, typename... Args>
auto measureTime(Func&& func, Args&&... args) -> decltype(func(std::forward<Args>(args)...)) 
{
    auto start = std::chrono::high_resolution_clock::now();
    
    // Perfect forwarding of all arguments
    auto result = func(std::forward<Args>(args)...);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Execution time: " << duration.count() << " microseconds\n";
    
    return result;
}

void demonstratePerfectForwarding() 
{
    std::cout << "\n=== Perfect Forwarding Demo ===\n";
    
    // Perfect forwarding with makeUnique
    std::string name = "Widget1";
    auto widget1 = makeUnique<Widget>(name, 42);           // Copy string
    auto widget2 = makeUnique<Widget>(std::string("Widget2"), 84);  // Move string
    auto widget3 = makeUnique<Widget>("Widget3", 126);     // Direct construction
    
    // Universal references
    int x = 10;
    processValue(x);              // Lvalue reference
    processValue(20);             // Rvalue reference
    processValue(std::move(x));   // Rvalue reference
    
    // Perfect forwarding with function measurement
    auto expensiveFunction = [](const std::string& s, int multiplier) 
    {
        std::string result;
        for (int i = 0; i < multiplier; ++i) 
        {
            result += s;
        }
        return result;
    };
    
    std::string text = "Hello ";
    auto result = measureTime(expensiveFunction, text, 1000);
    std::cout << "Result length: " << result.length() << '\n';
}
