auto ptr = std::make_unique<MyClass>(args);     // ✅ Exception safe
auto ptr = std::unique_ptr<MyClass>(new MyClass(args)); // ❌ Not exception safe
