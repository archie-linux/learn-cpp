#include <iostream>
#include <functional>
#include <vector>
#include <memory>

// Recursive lambda (C++14 with auto)
void recursiveLambda() {
    std::function<int(int)> factorial = [&factorial](int n) -> int {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    };
    
    std::cout << "5! = " << factorial(5) << "\n";
    
    // Y combinator style recursive lambda
    auto make_recursive = [](auto f) {
        return [f](auto&&... args) {
            return f(f, std::forward<decltype(args)>(args)...);
        };
    };
    
    auto fib = make_recursive([](auto f, int n) -> int {
        return (n <= 1) ? n : f(f, n-1) + f(f, n-2);
    });
    
    std::cout << "fib(10) = " << fib(10) << "\n";
}

// Lambda as template parameter
template<typename Container, typename Predicate>
auto filter(const Container& container, Predicate pred) {
    Container result;
    std::copy_if(container.begin(), container.end(), std::back_inserter(result), pred);
    return result;
}

// Higher-order functions
template<typename F>
auto curry(F&& f) {
    return [f = std::forward<F>(f)](auto&& arg1) {
        return [f, arg1 = std::forward<decltype(arg1)>(arg1)](auto&& arg2) {
            return f(arg1, std::forward<decltype(arg2)>(arg2));
        };
    };
}

void advancedLambdaFeatures() {
    // Lambda templates (C++20)
    auto generic_lambda = []<typename T>(T&& value) {
        std::cout << "Processing: " << value << " of type " << typeid(T).name() << "\n";
        return std::forward<T>(value);
    };
    
    generic_lambda(42);
    generic_lambda("Hello");
    
    // Using lambdas with custom algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto evens = filter(numbers, [](int n) { return n % 2 == 0; });
    
    std::cout << "Even numbers: ";
    for (int n : evens) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    
    // Currying example
    auto add = [](int a, int b) { return a + b; };
    auto curried_add = curry(add);
    auto add_five = curried_add(5);
    
    std::cout << "5 + 3 = " << add_five(3) << "\n";
}

// Lambda in class context
class EventHandler {
private:
    std::vector<std::function<void()>> handlers_;
    
public:
    void addHandler(std::function<void()> handler) {
        handlers_.push_back(handler);
    }
    
    void processEvents() {
        for (auto& handler : handlers_) {
            handler();
        }
    }
};

void lambdaInClassContext() {
    EventHandler eventSystem;
    
    std::string message = "Event processed";
    int counter = 0;
    
    // Lambda capturing class context
    eventSystem.addHandler([&message, &counter]() {
        std::cout << message << " #" << ++counter << "\n";
    });
    
    eventSystem.addHandler([]() {
        std::cout << "Another event handler\n";
    });
    
    eventSystem.processEvents();
    eventSystem.processEvents();
}
