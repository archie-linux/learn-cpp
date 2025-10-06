template <typename T>
void func(T&& param) 
{
    other_func(std::forward<T>(param));  // ✅ Universal reference
}

void func(MyClass&& obj) 
{
    other_func(std::move(obj));  // ✅ Rvalue reference
}
