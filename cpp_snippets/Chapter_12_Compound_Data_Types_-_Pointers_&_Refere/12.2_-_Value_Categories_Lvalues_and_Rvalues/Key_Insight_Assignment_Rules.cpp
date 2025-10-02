int main() 
{
    int x = 5, y = 10;
    
    x = y;              // ✅ lvalue = rvalue (y converts to rvalue)
    x = 42;             // ✅ lvalue = rvalue
    x = x + 1;          // ✅ lvalue = rvalue
    
    // 42 = x;          // ❌ rvalue = lvalue (illegal!)
    // x + 1 = y;       // ❌ rvalue = rvalue (illegal!)
    
    return 0;
}
