int main() 
{
    int x = 5;           // Original variable
    int& ref = x;        // ref is now an alias for x
    
    std::cout << x << '\n';      // Prints: 5
    std::cout << ref << '\n';    // Prints: 5 (same object)
    
    ref = 10;                    // Changes x through ref
    std::cout << x << '\n';      // Prints: 10
    
    x = 20;                      // Changes ref through x  
    std::cout << ref << '\n';    // Prints: 20
    
    return 0;
}
