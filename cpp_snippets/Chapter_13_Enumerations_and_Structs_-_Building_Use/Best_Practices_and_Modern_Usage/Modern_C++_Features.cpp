// C++17: Structured bindings
struct Point { double x, y; };
Point p{3.0, 4.0};
auto [x, y] = p;  // ✅ Decompose struct

// C++20: Designated initializers
Car tesla{.brand = "Tesla", .year = 2023};  // ✅ Clear intent

// C++20: using enum
using enum Color;
if (paint == red) { /* ... */ }  // ✅ Less verbose
