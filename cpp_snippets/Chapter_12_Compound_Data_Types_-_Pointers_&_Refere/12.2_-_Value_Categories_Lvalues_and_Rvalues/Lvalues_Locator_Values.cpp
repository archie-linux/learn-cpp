int main() 
{
    int x = 5;           // x is an lvalue (has identity, persists)
    int arr[5];          // arr is an lvalue
    const int c = 10;    // c is a non-modifiable lvalue
    
    // Lvalue expressions:
    x;                   // ✅ Variable
    arr[0];              // ✅ Array element
    ++x;                 // ✅ Pre-increment returns lvalue
    (x + y);             // ❌ This is actually an rvalue!
    
    return 0;
}
