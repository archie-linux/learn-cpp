#include <iostream>
#include <string>

class Rectangle {
private:
    double m_width;
    double m_height;

public:
    // Primary constructor
    Rectangle(double width, double height) : m_width{width}, m_height{height} {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Dimensions must be positive");
        }
        std::cout << "Rectangle created: " << m_width << "x" << m_height << '\n';
    }
    
    // Delegating constructors - call the primary constructor
    Rectangle() : Rectangle(1.0, 1.0) {  // Default to unit square
        std::cout << "Default rectangle created\n";
    }
    
    Rectangle(double side) : Rectangle(side, side) {  // Square constructor
        std::cout << "Square created\n";
    }
    
    double area() const { return m_width * m_height; }
    double perimeter() const { return 2 * (m_width + m_height); }
    
    void display() const {
        std::cout << "Rectangle: " << m_width << "x" << m_height 
                  << " (area: " << area() << ")\n";
    }
};

int main() {
    try {
        Rectangle unit;           // Default constructor -> delegates to Rectangle(1.0, 1.0)
        Rectangle square{5.0};    // Square constructor -> delegates to Rectangle(5.0, 5.0)
        Rectangle rect{3.0, 4.0}; // Direct constructor call
        
        unit.display();
        square.display();
        rect.display();
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
