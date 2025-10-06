class Temperature {
public:
    explicit Temperature(double celsius) : m_celsius{celsius} {}  // ✅ Prevents implicit conversion
};
