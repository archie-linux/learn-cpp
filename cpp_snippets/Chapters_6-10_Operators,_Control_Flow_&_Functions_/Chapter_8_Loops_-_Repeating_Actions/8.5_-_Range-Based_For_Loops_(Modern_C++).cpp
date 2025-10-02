#include <iostream>
#include <vector>
#include <string>

int main() 
{
    // With arrays
    int numbers[] = {1, 2, 3, 4, 5};
    
    std::cout << "Array elements: ";
    for (int num : numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << '\n';
    
    // With vectors
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Diana"};
    
    std::cout << "Names:\n";
    for (const auto& name : names)  // const auto& for efficiency
    {
        std::cout << "- " << name << '\n';
    }
    
    // Modifying elements (use reference)
    std::vector<int> scores = {80, 85, 90, 75, 88};
    
    std::cout << "Original scores: ";
    for (int score : scores) std::cout << score << " ";
    std::cout << '\n';
    
    // Add 5 points bonus to each score
    for (int& score : scores)  // Note the reference (&)
    {
        score += 5;
    }
    
    std::cout << "After bonus: ";
    for (int score : scores) std::cout << score << " ";
    std::cout << '\n';
    
    return 0;
}
