int getValue() { return 42; }

int main() 
{
    int x = 5;
    
    // Rvalue expressions:
    42;                  // ✅ Literal
    x + 1;               // ✅ Arithmetic result
    getValue();          // ✅ Function return value
    x++;                 // ✅ Post-increment returns rvalue
    static_cast<int>(3.14); // ✅ Cast result
    
    return 0;
}
