#include "Vector2D.h"
#include <cmath>
#include <iostream>

namespace Math {

// Constructor implementations
Vector2D::Vector2D(double x, double y) : m_x{x}, m_y{y} {}

Vector2D::Vector2D(const Vector2D& other) : m_x{other.m_x}, m_y{other.m_y} {}

// Assignment operator
Vector2D& Vector2D::operator=(const Vector2D& other) {
    if (this != &other) {  // Self-assignment check
        m_x = other.m_x;
        m_y = other.m_y;
    }
    return *this;
}

// Magnitude calculations
double Vector2D::magnitude() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

double Vector2D::magnitudeSquared() const {
    return m_x * m_x + m_y * m_y;  // Avoid expensive sqrt when possible
}

// Mutator implementations
void Vector2D::set(double x, double y) {
    m_x = x;
    m_y = y;
}

void Vector2D::normalize() {
    double mag = magnitude();
    if (mag > 0.0) {
        m_x /= mag;
        m_y /= mag;
    }
}

// Vector operation implementations
Vector2D& Vector2D::add(const Vector2D& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return *this;
}

Vector2D& Vector2D::multiply(double scalar) {
    m_x *= scalar;
    m_y *= scalar;
    return *this;
}

double Vector2D::dotProduct(const Vector2D& other) const {
    return m_x * other.m_x + m_y * other.m_y;
}

// Utility function implementations
void Vector2D::print() const {
    std::cout << "(" << m_x << ", " << m_y << ")";
}

bool Vector2D::isZero() const {
    const double EPSILON = 0.0001;
    return std::abs(m_x) < EPSILON && std::abs(m_y) < EPSILON;
}

// Static function implementations
double Vector2D::distance(const Vector2D& a, const Vector2D& b) {
    double dx = a.m_x - b.m_x;
    double dy = a.m_y - b.m_y;
    return std::sqrt(dx * dx + dy * dy);
}

Vector2D Vector2D::lerp(const Vector2D& a, const Vector2D& b, double t) {
    return Vector2D{
        a.m_x + t * (b.m_x - a.m_x),
        a.m_y + t * (b.m_y - a.m_y)
    };
}

// Friend function implementations
Vector2D operator+(const Vector2D& left, const Vector2D& right) {
    return Vector2D{left.m_x + right.m_x, left.m_y + right.m_y};
}

Vector2D operator-(const Vector2D& left, const Vector2D& right) {
    return Vector2D{left.m_x - right.m_x, left.m_y - right.m_y};
}

Vector2D operator*(const Vector2D& vec, double scalar) {
    return Vector2D{vec.m_x * scalar, vec.m_y * scalar};
}

Vector2D operator*(double scalar, const Vector2D& vec) {
    return vec * scalar;  // Reuse the above operator
}

std::ostream& operator<<(std::ostream& out, const Vector2D& vec) {
    out << "(" << vec.m_x << ", " << vec.m_y << ")";
    return out;
}

} // namespace Math
