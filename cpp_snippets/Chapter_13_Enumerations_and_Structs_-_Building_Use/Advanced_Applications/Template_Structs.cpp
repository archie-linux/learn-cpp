#include <iostream>
#include <string>

template <typename T>
struct Pair 
{
    T first;
    T second;
    
    // Member functions
    T sum() const { return first + second; }
    T max() const { return (first > second) ? first : second; }
    void swap() { std::swap(first, second); }
};

// Template specialization for string concatenation
template <>
std::string Pair<std::string>::sum() const 
{
    return first + " " + second;
}

int main() 
{
    Pair<int> numbers{10, 20};
    std::cout << "Sum: " << numbers.sum() << '\n';        // 30
    std::cout << "Max: " << numbers.max() << '\n';        // 20
    
    Pair<double> decimals{3.14, 2.71};
    std::cout << "Sum: " << decimals.sum() << '\n';       // 5.85
    
    Pair<std::string> words{"Hello", "World"};
    std::cout << "Combined: " << words.sum() << '\n';     // Hello World
    
    return 0;
}
