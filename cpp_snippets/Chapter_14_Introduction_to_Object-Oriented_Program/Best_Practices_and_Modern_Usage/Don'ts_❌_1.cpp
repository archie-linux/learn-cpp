class Circle {
public:
    double area() { return 3.14159 * m_radius * m_radius; }  // ❌ Should be const
};
