int main() 
{
    int x = 5, y = 10;
    
    // ✅ Valid reference declarations
    int& ref1 = x;           // Must initialize when declared
    int& ref2 = y;           // Each reference needs separate declaration
    
    // ❌ Invalid reference operations
    // int& ref3;            // Error: references must be initialized
    // ref1 = ref2;          // This assigns y's value to x (doesn't rebind ref1!)
    // int& ref4 = 42;       // Error: can't bind to rvalue
    
    return 0;
}
