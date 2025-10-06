#include <iostream>

int main() 
{
    std::cout << "Understanding Memory and Data Sizes\n";
    std::cout << "===================================\n";
    
    // Different data types take different amounts of memory
    std::cout << "Memory sizes on this system:\n";
    std::cout << "bool:        " << sizeof(bool) << " byte(s)\n";
    std::cout << "char:        " << sizeof(char) << " byte(s)\n";
    std::cout << "int:         " << sizeof(int) << " byte(s)\n";
    std::cout << "float:       " << sizeof(float) << " byte(s)\n";
    std::cout << "double:      " << sizeof(double) << " byte(s)\n";
    std::cout << "long:        " << sizeof(long) << " byte(s)\n";
    std::cout << "long long:   " << sizeof(long long) << " byte(s)\n";
    
    std::cout << "\nWhy does this matter?\n";
    std::cout << "- Larger types can hold bigger values\n";
    std::cout << "- But they also use more memory\n";
    std::cout << "- Choose the right type for your needs\n";
    
    return 0;
}
