#include <iostream>

// Function with parameters
void greetUser(const std::string& name) 
{
    std::cout << "Hello, " << name << "!\n";
    std::cout << "Welcome to our program.\n";
}

void printRectangle(int width, int height) 
{
    for (int row = 0; row < height; ++row) 
    {
        for (int col = 0; col < width; ++col) 
        {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

int main() 
{
    greetUser("Alice");
    greetUser("Bob");
    
    std::cout << "\nDrawing rectangles:\n";
    printRectangle(5, 3);
    
    std::cout << '\n';
    printRectangle(3, 4);
    
    return 0;
}
