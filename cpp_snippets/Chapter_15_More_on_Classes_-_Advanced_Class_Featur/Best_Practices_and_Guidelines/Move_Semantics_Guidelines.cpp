class MyClass 
{
public:
    MyClass(MyClass&& other) noexcept { /* ... */ }
    MyClass& operator=(MyClass&& other) noexcept { /* ... */ }
};
