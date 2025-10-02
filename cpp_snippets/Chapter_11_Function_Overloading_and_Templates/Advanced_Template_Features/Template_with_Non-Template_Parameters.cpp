template <typename T>
void repeat(T value, int times = 1) 
{
    for (int i = 0; i < times; ++i) 
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() 
{
    repeat("Hello", 3);    // Template: T=const char*, Non-template: times=3
    repeat(42, 2);         // Template: T=int, Non-template: times=2
    repeat(3.14);          // Template: T=double, Non-template: times=1 (default)
    return 0;
}
