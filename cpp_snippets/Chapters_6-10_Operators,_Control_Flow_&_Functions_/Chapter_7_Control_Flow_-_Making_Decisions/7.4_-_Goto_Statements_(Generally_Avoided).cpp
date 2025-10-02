#include <iostream>

// Example showing why goto is problematic (don't use in real code!)
int main() 
{
    int attempts = 0;
    
    retry:  // Label
    attempts++;
    
    std::cout << "Attempt " << attempts << '\n';
    
    if (attempts < 3) 
    {
        goto retry;  // Jump to label (creates spaghetti code!)
    }
    
    std::cout << "Done after " << attempts << " attempts\n";
    
    // Better approach would use a loop (covered in Chapter 8)
    
    return 0;
}
