constexpr int doSomething(int x, int y)
{
    int temp = x + y;      // ✅ Non-constexpr local variable allowed
    temp *= 2;             // ✅ Can modify local variables
    return temp;
}
