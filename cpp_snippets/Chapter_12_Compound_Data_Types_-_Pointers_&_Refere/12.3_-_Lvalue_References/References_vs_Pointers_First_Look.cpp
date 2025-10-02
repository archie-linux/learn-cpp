int main() 
{
    int x = 5, y = 10;
    
    // References
    int& ref = x;        // Must initialize, becomes alias
    ref = 20;            // Changes x to 20
    // ref = &y;         // ❌ Can't rebind reference
    
    // Pointers (preview)
    int* ptr = &x;       // Stores address of x
    *ptr = 30;           // Changes x to 30
    ptr = &y;            // ✅ Can point to different objects
    
    return 0;
}
