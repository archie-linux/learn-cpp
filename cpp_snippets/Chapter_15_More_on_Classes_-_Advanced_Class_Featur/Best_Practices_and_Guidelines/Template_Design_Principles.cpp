// ✅ Good: Single template handles all types
template <typename T>
T max(const T& a, const T& b) { return (a > b) ? a : b; }

// ❌ Avoid: Multiple overloads for similar logic
int max(int a, int b);
double max(double a, double b);
// ... many more overloads
