#include <iostream>
#include <string>

struct Point3D 
{
    double x{};
    double y{};
    double z{};
};

struct RGB 
{
    int red{};
    int green{};  
    int blue{};
};

int main() 
{
    // Aggregate initialization
    Point3D origin{};              // All members = 0.0
    Point3D position{1.5, 2.7, 3.2}; // x=1.5, y=2.7, z=3.2
    
    RGB white{255, 255, 255};      // red=255, green=255, blue=255
    RGB red{255, 0, 0};            // red=255, green=0, blue=0
    RGB partialColor{100};         // red=100, green=0, blue=0
    
    std::cout << "Position: (" << position.x << ", " << position.y << ", " << position.z << ")\n";
    std::cout << "Red color: RGB(" << red.red << ", " << red.green << ", " << red.blue << ")\n";
    
    return 0;
}
