int (*oldStyle)(int, int);  // ❌ C-style
std::function<int(int, int)> modernStyle;  // ✅ C++ style
