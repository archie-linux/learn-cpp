#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
private:
    double m_width;
    double m_height;

public:
    // Constructor declarations
    Rectangle(double width, double height);
    Rectangle();  // Default constructor
    
    // Accessor declarations
    double getWidth() const;
    double getHeight() const;
    double area() const;
    double perimeter() const;
    
    // Mutator declarations
    void setWidth(double width);
    void setHeight(double height);
    void scale(double factor);
    
    // Utility function declarations
    void display() const;
    bool isSquare() const;
};

#endif
