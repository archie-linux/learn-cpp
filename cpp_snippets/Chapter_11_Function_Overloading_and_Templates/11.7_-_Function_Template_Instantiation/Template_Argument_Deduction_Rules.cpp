template <typename T>
void print(T value) 
{
    std::cout << value << '\n';
}

int main() 
{
    print(42);        // T deduced as int
    print(3.14);      // T deduced as double
    print("Hello");   // T deduced as const char*
    print('A');       // T deduced as char
    return 0;
}
