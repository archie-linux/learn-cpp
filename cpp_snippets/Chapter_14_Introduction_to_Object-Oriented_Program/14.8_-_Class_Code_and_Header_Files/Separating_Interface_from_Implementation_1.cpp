#include "Rectangle.h"
#include <stdexcept>

// Constructor definitions
Rectangle::Rectangle(double width, double height) : m_width{width}, m_height{height} {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Dimensions must be positive");
    }
}

Rectangle::Rectangle() : Rectangle(1.0, 1.0) {
    // Delegates to parameterized constructor
}

// Accessor definitions
double Rectangle::getWidth() const {
    return m_width;
}

double Rectangle::getHeight() const {
    return m_height;
}

double Rectangle::area() const {
    return m_width * m_height;
}

double Rectangle::perimeter() const {
    return 2.0 * (m_width + m_height);
}

// Mutator definitions
void Rectangle::setWidth(double width) {
    if (width <= 0) {
        throw std::invalid_argument("Width must be positive");
    }
    m_width = width;
}

void Rectangle::setHeight(double height) {
    if (height <= 0) {
        throw std::invalid_argument("Height must be positive");
    }
    m_height = height;
}

void Rectangle::scale(double factor) {
    if (factor <= 0) {
        throw std::invalid_argument("Scale factor must be positive");
    }
    m_width *= factor;
    m_height *= factor;
}

// Utility function definitions
void Rectangle::display() const {
    std::cout << "Rectangle: " << m_width << "x" << m_height 
              << " (area: " << area() << ", perimeter: " << perimeter() << ")\n";
}

bool Rectangle::isSquare() const {
    const double EPSILON = 0.0001;
    return std::abs(m_width - m_height) < EPSILON;
}
