#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

// Higher-order functions demonstration
class FunctionUtils 
{
public:
    // Apply function to all elements
    template<typename Container, typename Function>
    static void forEach(Container& container, Function func) 
    {
        for (auto& element : container) 
        {
            func(element);
        }
    }
    
    // Filter elements based on predicate
    template<typename Container, typename Predicate>
    static Container filter(const Container& container, Predicate pred) 
    {
        Container result;
        std::copy_if(container.begin(), container.end(), 
                    std::back_inserter(result), pred);
        return result;
    }
    
    // Transform elements
    template<typename InputContainer, typename OutputContainer, typename Transform>
    static OutputContainer map(const InputContainer& input, Transform transform) 
    {
        OutputContainer result;
        std::transform(input.begin(), input.end(), 
                      std::back_inserter(result), transform);
        return result;
    }
    
    // Reduce/fold operation
    template<typename Container, typename T, typename BinaryOp>
    static T reduce(const Container& container, T init, BinaryOp op) 
    {
        return std::accumulate(container.begin(), container.end(), init, op);
    }
};

int main() 
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Original numbers: ";
    FunctionUtils::forEach(numbers, [](int n) { std::cout << n << " "; });
    std::cout << '\n';
    
    // Filter even numbers
    auto evenNumbers = FunctionUtils::filter(numbers, 
        [](int n) { return n % 2 == 0; });
    
    std::cout << "Even numbers: ";
    FunctionUtils::forEach(evenNumbers, [](int n) { std::cout << n << " "; });
    std::cout << '\n';
    
    // Transform to squares
    std::vector<int> squares = FunctionUtils::map<std::vector<int>, std::vector<int>>(
        numbers, [](int n) { return n * n; });
    
    std::cout << "Squares: ";
    FunctionUtils::forEach(squares, [](int n) { std::cout << n << " "; });
    std::cout << '\n';
    
    // Reduce to sum
    int sum = FunctionUtils::reduce(numbers, 0, 
        [](int acc, int n) { return acc + n; });
    
    std::cout << "Sum: " << sum << '\n';
    
    // Reduce to product
    int product = FunctionUtils::reduce(numbers, 1, 
        [](int acc, int n) { return acc * n; });
    
    std::cout << "Product: " << product << '\n';
    
    return 0;
}
