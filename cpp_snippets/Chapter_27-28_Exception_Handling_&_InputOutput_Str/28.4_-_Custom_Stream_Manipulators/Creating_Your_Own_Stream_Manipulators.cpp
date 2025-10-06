#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// ✅ Simple manipulator without parameters
std::ostream& bold(std::ostream& os) 
{
    return os << "\033[1m";  // ANSI bold escape sequence
}

std::ostream& reset(std::ostream& os) 
{
    return os << "\033[0m";  // ANSI reset escape sequence
}

std::ostream& red(std::ostream& os) 
{
    return os << "\033[31m";  // ANSI red color
}

std::ostream& green(std::ostream& os) 
{
    return os << "\033[32m";  // ANSI green color
}

std::ostream& blue(std::ostream& os) 
{
    return os << "\033[34m";  // ANSI blue color
}

// ✅ Manipulator with parameters using function objects
class Indent 
{
private:
    int spaces;
    
public:
    Indent(int n) : spaces(n) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Indent& indent) 
    {
        for (int i = 0; i < indent.spaces; ++i) 
        {
            os << ' ';
        }
        return os;
    }
};

// Factory function for easier use
Indent indent(int spaces) 
{
    return Indent(spaces);
}

// ✅ Advanced manipulator with internal state
class TableFormatter 
{
private:
    std::vector<int> columnWidths;
    char borderChar;
    
public:
    TableFormatter(const std::vector<int>& widths, char border = '|') 
        : columnWidths(widths), borderChar(border) {}
    
    std::ostream& printHeader(std::ostream& os, const std::vector<std::string>& headers) const 
    {
        printSeparator(os);
        
        os << borderChar;
        for (size_t i = 0; i < headers.size() && i < columnWidths.size(); ++i) 
        {
            os << " " << std::left << std::setw(columnWidths[i] - 1) << headers[i] << borderChar;
        }
        os << "\n";
        
        printSeparator(os);
        return os;
    }
    
    std::ostream& printRow(std::ostream& os, const std::vector<std::string>& row) const 
    {
        os << borderChar;
        for (size_t i = 0; i < row.size() && i < columnWidths.size(); ++i) 
        {
            os << " " << std::left << std::setw(columnWidths[i] - 1) << row[i] << borderChar;
        }
        os << "\n";
        return os;
    }
    
    std::ostream& printSeparator(std::ostream& os) const 
    {
        os << "+";
        for (int width : columnWidths) 
        {
            os << std::string(width, '-') << "+";
        }
        os << "\n";
        return os;
    }
    
    void finishTable(std::ostream& os) const 
    {
        printSeparator(os);
    }
};

// ✅ Progress bar manipulator
class ProgressBar 
{
private:
    double percentage;
    int width;
    char fillChar;
    char emptyChar;
    
public:
    ProgressBar(double percent, int w = 30, char fill = '=', char empty = '-')
        : percentage(percent), width(w), fillChar(fill), emptyChar(empty) 
    {
        if (percentage < 0.0) percentage = 0.0;
        if (percentage > 100.0) percentage = 100.0;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const ProgressBar& pb) 
    {
        int filledWidth = static_cast<int>((pb.percentage / 100.0) * pb.width);
        int emptyWidth = pb.width - filledWidth;
        
        os << "[";
        os << std::string(filledWidth, pb.fillChar);
        os << std::string(emptyWidth, pb.emptyChar);
        os << "] " << std::fixed << std::setprecision(1) << pb.percentage << "%";
        
        return os;
    }
};

// Factory function
ProgressBar progress(double percent, int width = 30) 
{
    return ProgressBar(percent, width);
}

// ✅ Binary formatter
class BinaryFormatter 
{
private:
    unsigned int value;
    int width;
    
public:
    BinaryFormatter(unsigned int val, int w = 8) : value(val), width(w) {}
    
    friend std::ostream& operator<<(std::ostream& os, const BinaryFormatter& bf) 
    {
        std::string binary;
        unsigned int temp = bf.value;
        
        if (temp == 0) 
        {
            binary = "0";
        } 
        else 
        {
            while (temp > 0) 
            {
                binary = (temp % 2 == 0 ? "0" : "1") + binary;
                temp /= 2;
            }
        }
        
        // Pad with leading zeros if necessary
        while (static_cast<int>(binary.length()) < bf.width) 
        {
            binary = "0" + binary;
        }
        
        return os << binary;
    }
};

BinaryFormatter binary(unsigned int value, int width = 8) 
{
    return BinaryFormatter(value, width);
}

void demonstrateCustomManipulators() 
{
    std::cout << "=== Custom Stream Manipulators ===\n";
    
    // Color manipulators
    std::cout << "\n--- Color Manipulators ---\n";
    std::cout << red << "This is red text" << reset << "\n";
    std::cout << green << bold << "This is bold green text" << reset << "\n";
    std::cout << blue << "This is blue text" << reset << "\n";
    
    // Indentation manipulator
    std::cout << "\n--- Indentation ---\n";
    std::cout << "No indentation\n";
    std::cout << indent(4) << "4 spaces indentation\n";
    std::cout << indent(8) << "8 spaces indentation\n";
    std::cout << indent(12) << "12 spaces indentation\n";
    
    // Progress bar manipulator
    std::cout << "\n--- Progress Bars ---\n";
    for (int i = 0; i <= 100; i += 20) 
    {
        std::cout << "Download: " << progress(i) << "\n";
    }
    
    std::cout << "Upload:   " << progress(73.5, 20) << "\n";
    
    // Binary formatter
    std::cout << "\n--- Binary Formatter ---\n";
    for (int i = 0; i < 16; ++i) 
    {
        std::cout << "Dec: " << std::setw(2) << i 
                  << " Bin: " << binary(i, 4) 
                  << " Hex: " << std::hex << i << std::dec << "\n";
    }
    
    // Table formatter
    std::cout << "\n--- Table Formatter ---\n";
    TableFormatter table({12, 8, 15, 10});
    
    table.printHeader(std::cout, {"Name", "Age", "Department", "Salary"});
    table.printRow(std::cout, {"Alice", "28", "Engineering", "$65000"});
    table.printRow(std::cout, {"Bob", "35", "Marketing", "$58000"});
    table.printRow(std::cout, {"Carol", "42", "Sales", "$72000"});
    table.finishTable(std::cout);
}
