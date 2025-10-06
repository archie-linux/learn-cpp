#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

class FileHandler 
{
public:
    // ✅ Write data to file with error handling
    static void writeToFile(const std::string& filename, const std::vector<std::string>& data) 
    {
        std::ofstream outFile(filename);
        
        if (!outFile.is_open()) 
        {
            throw std::runtime_error("Cannot open file for writing: " + filename);
        }
        
        std::cout << "Writing to file: " << filename << "\n";
        
        for (const auto& line : data) 
        {
            outFile << line << "\n";
            
            // Check for write errors
            if (outFile.fail()) 
            {
                throw std::runtime_error("Write error occurred");
            }
        }
        
        std::cout << "Successfully wrote " << data.size() << " lines\n";
        // File automatically closed when outFile goes out of scope
    }
    
    // ✅ Read data from file with error handling
    static std::vector<std::string> readFromFile(const std::string& filename) 
    {
        std::ifstream inFile(filename);
        
        if (!inFile.is_open()) 
        {
            throw std::runtime_error("Cannot open file for reading: " + filename);
        }
        
        std::cout << "Reading from file: " << filename << "\n";
        
        std::vector<std::string> lines;
        std::string line;
        
        while (std::getline(inFile, line)) 
        {
            lines.push_back(line);
        }
        
        // Check if we stopped due to error or EOF
        if (inFile.bad()) 
        {
            throw std::runtime_error("Read error occurred");
        }
        
        std::cout << "Successfully read " << lines.size() << " lines\n";
        return lines;
    }
    
    // ✅ Append data to existing file
    static void appendToFile(const std::string& filename, const std::string& data) 
    {
        std::ofstream outFile(filename, std::ios::app);  // Append mode
        
        if (!outFile.is_open()) 
        {
            throw std::runtime_error("Cannot open file for appending: " + filename);
        }
        
        outFile << data << "\n";
        
        if (outFile.fail()) 
        {
            throw std::runtime_error("Append error occurred");
        }
        
        std::cout << "Successfully appended data to " << filename << "\n";
    }
    
    // ✅ Binary file operations
    static void writeBinaryData(const std::string& filename, const std::vector<int>& data) 
    {
        std::ofstream outFile(filename, std::ios::binary);
        
        if (!outFile.is_open()) 
        {
            throw std::runtime_error("Cannot open file for binary writing: " + filename);
        }
        
        // Write the size first
        size_t size = data.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        // Write the data
        outFile.write(reinterpret_cast<const char*>(data.data()), 
                     data.size() * sizeof(int));
        
        if (outFile.fail()) 
        {
            throw std::runtime_error("Binary write error occurred");
        }
        
        std::cout << "Successfully wrote " << data.size() << " integers to binary file\n";
    }
    
    static std::vector<int> readBinaryData(const std::string& filename) 
    {
        std::ifstream inFile(filename, std::ios::binary);
        
        if (!inFile.is_open()) 
        {
            throw std::runtime_error("Cannot open file for binary reading: " + filename);
        }
        
        // Read the size first
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        if (inFile.fail()) 
        {
            throw std::runtime_error("Failed to read data size");
        }
        
        // Read the data
        std::vector<int> data(size);
        inFile.read(reinterpret_cast<char*>(data.data()), size * sizeof(int));
        
        if (inFile.fail()) 
        {
            throw std::runtime_error("Failed to read binary data");
        }
        
        std::cout << "Successfully read " << data.size() << " integers from binary file\n";
        return data;
    }
};

void demonstrateTextFileOperations() 
{
    std::cout << "=== Text File Operations ===\n";
    
    try 
    {
        // Create sample data
        std::vector<std::string> sampleData = {
            "Line 1: Hello, World!",
            "Line 2: This is a test file",
            "Line 3: With multiple lines",
            "Line 4: For demonstration"
        };
        
        // Write to file
        FileHandler::writeToFile("sample.txt", sampleData);
        
        // Read from file
        auto readData = FileHandler::readFromFile("sample.txt");
        
        std::cout << "\n--- File Contents ---\n";
        for (size_t i = 0; i < readData.size(); ++i) 
        {
            std::cout << i + 1 << ": " << readData[i] << "\n";
        }
        
        // Append to file
        FileHandler::appendToFile("sample.txt", "Line 5: Appended line");
        
        // Read again to show appended content
        readData = FileHandler::readFromFile("sample.txt");
        
        std::cout << "\n--- After Appending ---\n";
        std::cout << "Last line: " << readData.back() << "\n";
        
    }
    catch (const std::exception& e) 
    {
        std::cout << "File operation error: " << e.what() << "\n";
    }
}

void demonstrateBinaryFileOperations() 
{
    std::cout << "\n=== Binary File Operations ===\n";
    
    try 
    {
        // Create sample binary data
        std::vector<int> numbers;
        for (int i = 1; i <= 10; ++i) 
        {
            numbers.push_back(i * i);  // Square numbers
        }
        
        std::cout << "Original data: ";
        for (int num : numbers) 
        {
            std::cout << num << " ";
        }
        std::cout << "\n";
        
        // Write binary data
        FileHandler::writeBinaryData("numbers.bin", numbers);
        
        // Read binary data
        auto readNumbers = FileHandler::readBinaryData("numbers.bin");
        
        std::cout << "Read data: ";
        for (int num : readNumbers) 
        {
            std::cout << num << " ";
        }
        std::cout << "\n";
        
        // Verify data integrity
        bool dataMatch = (numbers == readNumbers);
        std::cout << "Data integrity check: " << (dataMatch ? "PASSED" : "FAILED") << "\n";
        
    }
    catch (const std::exception& e) 
    {
        std::cout << "Binary file operation error: " << e.what() << "\n";
    }
}
