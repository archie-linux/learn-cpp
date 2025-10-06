#include <iostream>
#include <array>

// Template with value parameter
template <typename T, size_t N>
void printArray(const std::array<T, N>& arr) 
{
    std::cout << "Array of " << N << " elements: ";
    for (const auto& element : arr) 
    {
        std::cout << element << " ";
    }
    std::cout << '\n';
}

int main() 
{
    std::array<int, 5> numbers{1, 2, 3, 4, 5};
    std::array<std::string, 3> words{"hello", "world", "template"};
    
    printArray(numbers);  // T=int, N=5
    printArray(words);    // T=std::string, N=3
    
    return 0;
}
