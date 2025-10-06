#include <iostream>
#include <cmath>

class Circle {
private:
    double m_radius;

public:
    Circle(double radius) : m_radius{radius} {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }
    
    // Accessor
    double radius() const { return m_radius; }
    
    // Mutator  
    void setRadius(double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
        m_radius = radius;
    }
    
    // Member functions - operate on this object's data
    double area() const { return 3.14159 * m_radius * m_radius; }
    double circumference() const { return 2 * 3.14159 * m_radius; }
    
    void scale(double factor) {
        if (factor <= 0) return;
        m_radius *= factor;
    }
    
    void display() const {
        std::cout << "Circle with radius " << m_radius 
                  << " (area: " << area() << ")\n";
    }
};

// Free functions - don't need access to private members
bool areEqual(const Circle& c1, const Circle& c2) {
    return std::abs(c1.radius() - c2.radius()) < 0.001;
}

Circle createUnitCircle() {
    return Circle{1.0};
}

double distanceBetweenCenters(const Circle& c1, const Circle& c2) {
    // This would need coordinate data if we had it
    return 0.0;  // Simplified example
}

int main() {
    Circle small{2.0};
    Circle large{5.0};
    
    small.display();
    large.display();
    
    small.scale(2.0);  // Member function modifies the object
    std::cout << "After scaling: ";
    small.display();
    
    std::cout << "Circles equal: " << (areEqual(small, large) ? "Yes" : "No") << '\n';
    
    Circle unit = createUnitCircle();  // Free function creates object
    unit.display();
    
    return 0;
}
