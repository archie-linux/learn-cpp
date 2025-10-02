#include <iostream>
#include <string_view>

enum class Direction 
{
    north,
    south,
    east,
    west
};

std::string_view getDirectionName(Direction dir) 
{
    using enum Direction;  // C++20: Import all enumerators
    
    switch (dir) 
    {
        case north: return "North";  // No need for Direction::north
        case south: return "South";
        case east:  return "East";
        case west:  return "West";
        default:    return "Unknown";
    }
}

int main() 
{
    Direction playerDirection = Direction::north;
    std::cout << "Moving " << getDirectionName(playerDirection) << '\n';
    
    return 0;
}
