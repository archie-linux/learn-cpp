#include <iostream>

int main() 
{
    std::cout << "Special Characters and Escape Sequences\n";
    std::cout << "=======================================\n";
    
    // Common escape sequences
    std::cout << "Tab character: Hello\tWorld\n";
    std::cout << "New line: Hello\nWorld\n";
    std::cout << "Carriage return: Hello\rWorld\n";
    std::cout << "Backslash: C:\\Program Files\\\n";
    std::cout << "Quote marks: He said \"Hello World\"\n";
    std::cout << "Single quote: It\\'s a beautiful day\n";
    
    // Creating formatted output
    std::cout << "\nCreating a simple box:\n";
    std::cout << "+----------+\n";
    std::cout << "|  Hello   |\n";
    std::cout << "|  World   |\n";
    std::cout << "+----------+\n";
    
    // ASCII art example
    std::cout << "\nSimple ASCII Art:\n";
    std::cout << "    /\\_/\\  \n";
    std::cout << "   ( o.o ) \n";
    std::cout << "    > ^ <  \n";
    
    return 0;
}
