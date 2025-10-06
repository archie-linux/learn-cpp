class Circle {
public:
    double area() const { return 3.14159 * m_radius * m_radius; }  // ✅ const-correct
};
