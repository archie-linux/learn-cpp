enum Color { red, blue };
enum Fruit { banana, apple };

int main() 
{
    Color color = red;      // red = 0
    Fruit fruit = banana;   // banana = 0
    
    if (color == fruit)     // ❌ This compiles but makes no sense!
    {
        std::cout << "Color and fruit are equal!\n"; // This prints!
    }
    
    // Even worse:
    Color paint = red;
    int number = paint + 5;  // ❌ Unwanted implicit conversion
    
    return 0;
}
