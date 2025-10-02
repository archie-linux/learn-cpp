#include "Rectangle.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        Rectangle rect1{5.0, 3.0};
        Rectangle rect2;  // Default constructor
        
        rect1.display();
        rect2.display();
        
        rect1.scale(1.5);
        rect1.display();
        
        rect2.setWidth(4.0);
        rect2.setHeight(4.0);
        
        std::cout << "rect2 is square: " << (rect2.isSquare() ? "Yes" : "No") << '\n';
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
