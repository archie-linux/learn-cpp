#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() 
{
    // Basic lambda syntax: [capture](parameters) { body }
    auto simpleLambda = []() 
    {
        std::cout << "Hello from lambda!\n";
    };
    simpleLambda();
    
    // Lambda with parameters
    auto addLambda = [](int a, int b) 
    {
        return a + b;
    };
    std::cout << "Lambda addition: " << addLambda(10, 5) << '\n';
    
    // Lambda with capture
    int multiplier = 3;
    auto multiplyBy = [multiplier](int value) 
    {
        return value * multiplier;
    };
    std::cout << "Multiply by " << multiplier << ": " << multiplyBy(7) << '\n';
    
    // Using lambdas with STL algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Count even numbers
    int evenCount = std::count_if(numbers.begin(), numbers.end(), 
                                  [](int n) { return n % 2 == 0; });
    std::cout << "Even numbers count: " << evenCount << '\n';
    
    // Transform all numbers (multiply by 2)
    std::vector<int> doubled(numbers.size());
    std::transform(numbers.begin(), numbers.end(), doubled.begin(),
                   [](int n) { return n * 2; });
    
    std::cout << "Original: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << '\n';
    
    std::cout << "Doubled: ";
    for (int n : doubled) std::cout << n << " ";
    std::cout << '\n';
    
    return 0;
}
