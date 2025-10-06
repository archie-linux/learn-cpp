#include <iostream>
#include <string>

int main() 
{
    std::cout << "Welcome to Input/Output Basics!\n";
    std::cout << "===============================\n";
    
    // Basic output with cout
    std::cout << "This is a line of text.\n";
    std::cout << "Numbers: " << 42 << " and " << 3.14159 << '\n';
    
    // Chaining output
    std::string name = "Alice";
    int age = 25;
    std::cout << "Name: " << name << ", Age: " << age << " years old\n";
    
    // Basic input with cin
    std::string userName;
    int userAge;
    
    std::cout << "\nLet's get to know you!\n";
    std::cout << "What's your name? ";
    std::cin >> userName;
    
    std::cout << "How old are you? ";
    std::cin >> userAge;
    
    // Display what we learned
    std::cout << "\nNice to meet you, " << userName << "!\n";
    std::cout << "You are " << userAge << " years old.\n";
    
    return 0;
}
