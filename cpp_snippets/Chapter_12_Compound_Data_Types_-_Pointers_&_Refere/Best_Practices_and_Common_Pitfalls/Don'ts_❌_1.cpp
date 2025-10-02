int* ptr = nullptr;
{
    int x = 5;
    ptr = &x;
}  // x destroyed here
std::cout << *ptr;  // ❌ Undefined behavior
