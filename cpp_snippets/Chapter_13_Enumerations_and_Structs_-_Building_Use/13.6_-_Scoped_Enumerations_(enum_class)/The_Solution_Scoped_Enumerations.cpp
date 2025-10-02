#include <iostream>

enum class Color 
{
    red,      // Color::red
    green,    // Color::green
    blue      // Color::blue
};

enum class Fruit 
{
    apple,    // Fruit::apple
    banana,   // Fruit::banana  
    orange    // Fruit::orange
};

int main() 
{
    Color paint = Color::red;       // ✅ Must use scope resolution
    Fruit snack = Fruit::apple;     // ✅ Must use scope resolution
    
    // These no longer compile (good!):
    // if (paint == snack) {}       // ❌ Error: can't compare different enum types
    // int value = paint;           // ❌ Error: no implicit conversion to int
    
    // This works (same type comparison):
    if (paint == Color::red) 
    {
        std::cout << "Paint is red!\n";
    }
    
    return 0;
}
