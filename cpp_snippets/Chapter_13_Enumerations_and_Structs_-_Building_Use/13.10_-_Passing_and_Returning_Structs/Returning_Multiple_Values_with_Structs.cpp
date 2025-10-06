#include <iostream>
#include <cmath>

struct Coordinates 
{
    double x;
    double y;
};

struct PolarCoordinates 
{
    double radius;
    double angle;  // in radians
};

// Convert Cartesian to Polar coordinates
PolarCoordinates toPolar(const Coordinates& cartesian) 
{
    double radius = std::sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y);
    double angle = std::atan2(cartesian.y, cartesian.x);
    
    return PolarCoordinates{radius, angle};
}

// Convert Polar to Cartesian coordinates
Coordinates toCartesian(const PolarCoordinates& polar) 
{
    double x = polar.radius * std::cos(polar.angle);
    double y = polar.radius * std::sin(polar.angle);
    
    return Coordinates{x, y};
}

int main() 
{
    Coordinates point{3.0, 4.0};
    std::cout << "Cartesian: (" << point.x << ", " << point.y << ")\n";
    
    PolarCoordinates polar = toPolar(point);
    std::cout << "Polar: radius=" << polar.radius << ", angle=" << polar.angle << " rad\n";
    
    Coordinates converted = toCartesian(polar);
    std::cout << "Back to Cartesian: (" << converted.x << ", " << converted.y << ")\n";
    
    return 0;
}
