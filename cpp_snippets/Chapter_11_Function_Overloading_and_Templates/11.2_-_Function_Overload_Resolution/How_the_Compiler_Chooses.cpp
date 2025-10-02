void func(int x) { std::cout << "int version\n"; }
void func(double x) { std::cout << "double version\n"; }
void func(const std::string& x) { std::cout << "string version\n"; }

int main() 
{
    func(42);        // Exact match: calls func(int)
    func(3.14);      // Exact match: calls func(double)
    func(42.0f);     // Promotion: float→double, calls func(double)
    func("Hello");   // Conversion: const char*→std::string, calls func(const std::string&)
    return 0;
}
