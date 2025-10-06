#include <iostream>
#include <vector>
#include <memory>

class Shape {
protected:
    std::string m_name;
    std::string m_color;

public:
    Shape(const std::string& name, const std::string& color)
        : m_name{name}, m_color{color} {}
    
    virtual ~Shape() = default;  // Virtual destructor
    
    // Non-virtual functions - early binding (compile-time)
    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
    
    void setColor(const std::string& color) { m_color = color; }
    
    // Virtual functions - late binding (runtime)
    virtual double getArea() const = 0;        // Pure virtual - abstract
    virtual double getPerimeter() const = 0;   // Pure virtual - abstract
    
    virtual void draw() const {
        std::cout << "Drawing a " << m_color << " " << m_name << '\n';
    }
    
    virtual void displayInfo() const {
        std::cout << m_name << " (" << m_color << ") - Area: " << getArea() 
                  << ", Perimeter: " << getPerimeter() << '\n';
    }
};

class Circle : public Shape {
private:
    double m_radius;

public:
    Circle(double radius, const std::string& color = "red")
        : Shape{"Circle", color}, m_radius{radius} {}
    
    double getRadius() const { return m_radius; }
    void setRadius(double radius) { m_radius = radius; }
    
    // Override virtual functions
    double getArea() const override {
        return 3.14159 * m_radius * m_radius;
    }
    
    double getPerimeter() const override {
        return 2 * 3.14159 * m_radius;
    }
    
    void draw() const override {
        std::cout << "Drawing a " << m_color << " circle with radius " << m_radius << '\n';
    }
};

class Rectangle : public Shape {
private:
    double m_width, m_height;

public:
    Rectangle(double width, double height, const std::string& color = "blue")
        : Shape{"Rectangle", color}, m_width{width}, m_height{height} {}
    
    double getWidth() const { return m_width; }
    double getHeight() const { return m_height; }
    
    double getArea() const override {
        return m_width * m_height;
    }
    
    double getPerimeter() const override {
        return 2 * (m_width + m_height);
    }
    
    void draw() const override {
        std::cout << "Drawing a " << m_color << " rectangle " 
                  << m_width << "x" << m_height << '\n';
    }
};

class Triangle : public Shape {
private:
    double m_base, m_height, m_side1, m_side2;

public:
    Triangle(double base, double height, double side1, double side2, 
             const std::string& color = "green")
        : Shape{"Triangle", color}, m_base{base}, m_height{height}, 
          m_side1{side1}, m_side2{side2} {}
    
    double getArea() const override {
        return 0.5 * m_base * m_height;
    }
    
    double getPerimeter() const override {
        return m_base + m_side1 + m_side2;
    }
    
    void draw() const override {
        std::cout << "Drawing a " << m_color << " triangle with base " 
                  << m_base << " and height " << m_height << '\n';
    }
};

// Function that works with any Shape through polymorphism
void processShape(const Shape& shape) {
    shape.displayInfo();  // Calls appropriate derived version
    shape.draw();         // Calls appropriate derived version
}

void processShapePointer(const Shape* shape) {
    if (shape) {
        shape->displayInfo();  // Polymorphic call
        shape->draw();         // Polymorphic call
    }
}

int main() {
    // Create different shapes
    Circle circle{5.0, "red"};
    Rectangle rect{4.0, 6.0, "blue"};
    Triangle triangle{3.0, 4.0, 5.0, 5.0, "green"};
    
    std::cout << "=== Direct object usage ===\n";
    circle.displayInfo();
    rect.displayInfo();
    triangle.displayInfo();
    
    std::cout << "\n=== Polymorphism with references ===\n";
    processShape(circle);    // Shape& refers to Circle
    processShape(rect);      // Shape& refers to Rectangle
    processShape(triangle);  // Shape& refers to Triangle
    
    std::cout << "\n=== Polymorphism with pointers ===\n";
    Shape* shapes[] = {&circle, &rect, &triangle};
    
    for (int i = 0; i < 3; ++i) {
        std::cout << "Shape " << (i + 1) << ": ";
        processShapePointer(shapes[i]);
        std::cout << '\n';
    }
    
    std::cout << "\n=== Dynamic polymorphism with smart pointers ===\n";
    std::vector<std::unique_ptr<Shape>> shapeCollection;
    shapeCollection.push_back(std::make_unique<Circle>(3.0, "yellow"));
    shapeCollection.push_back(std::make_unique<Rectangle>(2.0, 8.0, "purple"));
    shapeCollection.push_back(std::make_unique<Triangle>(6.0, 8.0, 10.0, 10.0, "orange"));
    
    double totalArea = 0.0;
    for (const auto& shape : shapeCollection) {
        shape->displayInfo();
        totalArea += shape->getArea();  // Polymorphic call to correct getArea()
    }
    
    std::cout << "Total area of all shapes: " << totalArea << '\n';
    
    return 0;
}
