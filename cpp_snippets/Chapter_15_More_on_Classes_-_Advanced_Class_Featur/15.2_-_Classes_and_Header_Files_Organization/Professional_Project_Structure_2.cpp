#include "Math/Vector2D.h"
#include <iostream>

int main() {
    using namespace Math;
    
    Vector2D a{3.0, 4.0};
    Vector2D b{1.0, 2.0};
    
    std::cout << "Vector a: " << a << '\n';
    std::cout << "Vector b: " << b << '\n';
    std::cout << "Magnitude of a: " << a.magnitude() << '\n';
    
    // Using operators
    Vector2D c = a + b;
    std::cout << "a + b = " << c << '\n';
    
    Vector2D d = a * 2.0;
    std::cout << "a * 2 = " << d << '\n';
    
    // Using member functions
    Vector2D e = a;
    e.normalize();
    std::cout << "Normalized a: " << e << '\n';
    
    // Static functions
    std::cout << "Distance between a and b: " << Vector2D::distance(a, b) << '\n';
    
    return 0;
}
