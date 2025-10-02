#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

void demonstrateBasicStreams() 
{
    std::cout << "=== Basic Stream Concepts ===\n";
    
    // Standard streams
    std::cout << "This goes to standard output (cout)\n";
    std::cerr << "This goes to standard error (cerr)\n";
    std::clog << "This goes to standard log (clog)\n";
    
    // String streams - treat strings like files
    std::ostringstream oss;  // Output string stream
    oss << "Hello, " << "World! " << 42 << " " << 3.14;
    std::string result = oss.str();
    std::cout << "String stream result: " << result << "\n";
    
    // Input string stream
    std::istringstream iss("100 200 300 hello world");
    int a, b, c;
    std::string word1, word2;
    
    iss >> a >> b >> c >> word1 >> word2;
    std::cout << "Parsed from string: " << a << ", " << b << ", " << c 
              << ", '" << word1 << "', '" << word2 << "'\n";
    
    // Check stream state
    if (iss.good()) 
    {
        std::cout << "String stream is in good state\n";
    }
}

void demonstrateStreamStates() 
{
    std::cout << "\n--- Stream States ---\n";
    
    std::istringstream iss("123 abc 456");
    int number;
    
    // Read first number - should succeed
    iss >> number;
    std::cout << "First read: " << number << " (good: " << iss.good() << ")\n";
    
    // Try to read string as number - should fail
    iss >> number;
    std::cout << "Second read failed (good: " << iss.good() 
              << ", fail: " << iss.fail() 
              << ", bad: " << iss.bad() 
              << ", eof: " << iss.eof() << ")\n";
    
    // Clear error state
    iss.clear();
    
    // Skip the invalid input
    std::string invalidInput;
    iss >> invalidInput;
    std::cout << "Skipped invalid input: '" << invalidInput << "'\n";
    
    // Now we can read the last number
    iss >> number;
    std::cout << "Third read: " << number << " (good: " << iss.good() << ")\n";
}

void demonstrateStreamFormatting() 
{
    std::cout << "\n--- Stream Formatting ---\n";
    
    double pi = 3.14159265359;
    int value = 255;
    
    // Precision control
    std::cout << "Default precision: " << pi << "\n";
    std::cout << std::setprecision(3) << "3 decimal places: " << pi << "\n";
    std::cout << std::setprecision(6) << std::fixed << "Fixed 6 places: " << pi << "\n";
    std::cout << std::scientific << "Scientific notation: " << pi << "\n";
    std::cout << std::defaultfloat;  // Reset to default
    
    // Width and alignment
    std::cout << "\n--- Width and Alignment ---\n";
    std::cout << "|" << std::setw(10) << "Hello" << "|\n";
    std::cout << "|" << std::setw(10) << std::left << "Hello" << "|\n";
    std::cout << "|" << std::setw(10) << std::right << "Hello" << "|\n";
    std::cout << "|" << std::setw(10) << std::setfill('*') << "Hello" << "|\n";
    std::cout << std::setfill(' ');  // Reset fill character
    
    // Number bases
    std::cout << "\n--- Number Bases ---\n";
    std::cout << "Decimal: " << value << "\n";
    std::cout << "Hex: " << std::hex << value << "\n";
    std::cout << "Hex with prefix: " << std::showbase << value << "\n";
    std::cout << "Octal: " << std::oct << value << "\n";
    std::cout << std::dec << std::noshowbase;  // Reset to decimal
    
    // Boolean formatting
    std::cout << "\n--- Boolean Formatting ---\n";
    bool flag = true;
    std::cout << "Default bool: " << flag << "\n";
    std::cout << std::boolalpha << "Alpha bool: " << flag << "\n";
    std::cout << std::noboolalpha;  // Reset
}

int main() 
{
    demonstrateBasicStreams();
    demonstrateStreamStates();
    demonstrateStreamFormatting();
    return 0;
}
