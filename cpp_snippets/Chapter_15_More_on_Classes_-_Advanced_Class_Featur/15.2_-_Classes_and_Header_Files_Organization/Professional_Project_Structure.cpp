#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

namespace Math {

class Vector2D {
private:
    double m_x, m_y;

public:
    // Constructors
    Vector2D(double x = 0.0, double y = 0.0);
    Vector2D(const Vector2D& other);  // Copy constructor
    
    // Destructor
    ~Vector2D() = default;
    
    // Assignment operator
    Vector2D& operator=(const Vector2D& other);
    
    // Accessors
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double magnitude() const;
    double magnitudeSquared() const;
    
    // Mutators
    void setX(double x) { m_x = x; }
    void setY(double y) { m_y = y; }
    void set(double x, double y);
    void normalize();
    
    // Vector operations
    Vector2D& add(const Vector2D& other);
    Vector2D& subtract(const Vector2D& other);
    Vector2D& multiply(double scalar);
    double dotProduct(const Vector2D& other) const;
    
    // Utility functions
    void print() const;
    bool isZero() const;
    
    // Static utility functions
    static double distance(const Vector2D& a, const Vector2D& b);
    static Vector2D lerp(const Vector2D& a, const Vector2D& b, double t);
    
    // Friend functions (declared here, defined outside)
    friend Vector2D operator+(const Vector2D& left, const Vector2D& right);
    friend Vector2D operator-(const Vector2D& left, const Vector2D& right);
    friend Vector2D operator*(const Vector2D& vec, double scalar);
    friend Vector2D operator*(double scalar, const Vector2D& vec);
    friend std::ostream& operator<<(std::ostream& out, const Vector2D& vec);
};

// Free function declarations
Vector2D operator+(const Vector2D& left, const Vector2D& right);
Vector2D operator-(const Vector2D& left, const Vector2D& right);
Vector2D operator*(const Vector2D& vec, double scalar);
Vector2D operator*(double scalar, const Vector2D& vec);
std::ostream& operator<<(std::ostream& out, const Vector2D& vec);

} // namespace Math

#endif
