#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>

namespace fs = std::filesystem;

class AdvancedFileOperations 
{
public:
    // ✅ Get file information
    static void displayFileInfo(const std::string& filename) 
    {
        std::cout << "\n=== File Information: " << filename << " ===\n";
        
        try 
        {
            if (!fs::exists(filename)) 
            {
                std::cout << "File does not exist\n";
                return;
            }
            
            auto fileSize = fs::file_size(filename);
            auto lastWrite = fs::last_write_time(filename);
            auto perms = fs::status(filename).permissions();
            
            std::cout << "Size: " << fileSize << " bytes\n";
            
            // Convert file time to system time for display
            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                lastWrite - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
            );
            auto time_t = std::chrono::system_clock::to_time_t(sctp);
            
            std::cout << "Last modified: " << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S") << "\n";
            
            // Check permissions
            std::cout << "Permissions: ";
            std::cout << ((perms & fs::perms::owner_read) != fs::perms::none ? "r" : "-");
            std::cout << ((perms & fs::perms::owner_write) != fs::perms::none ? "w" : "-");
            std::cout << ((perms & fs::perms::owner_exec) != fs::perms::none ? "x" : "-");
            std::cout << "\n";
            
        }
        catch (const fs::filesystem_error& e) 
        {
            std::cout << "Filesystem error: " << e.what() << "\n";
        }
    }
    
    // ✅ Random access file operations
    static void demonstrateRandomAccess(const std::string& filename) 
    {
        std::cout << "\n=== Random Access Demo ===\n";
        
        try 
        {
            // Create a file with known content
            {
                std::ofstream outFile(filename);
                for (int i = 0; i < 10; ++i) 
                {
                    outFile << "Line " << std::setfill('0') << std::setw(2) << i << ": Some content\n";
                }
            }
            
            // Random access reading
            std::ifstream inFile(filename);
            
            if (!inFile.is_open()) 
            {
                throw std::runtime_error("Cannot open file for random access");
            }
            
            // Seek to different positions
            std::cout << "File content at different positions:\n";
            
            // Read from beginning
            inFile.seekg(0, std::ios::beg);
            std::string line;
            std::getline(inFile, line);
            std::cout << "Beginning: " << line << "\n";
            
            // Read from middle
            inFile.seekg(100, std::ios::beg);  // Seek to position 100
            std::getline(inFile, line);
            std::cout << "Position 100: " << line << "\n";
            
            // Read from end
            inFile.seekg(-50, std::ios::end);  // Seek 50 characters from end
            std::getline(inFile, line);
            std::cout << "Near end: " << line << "\n";
            
            // Get current position
            auto currentPos = inFile.tellg();
            std::cout << "Current position: " << currentPos << "\n";
            
        }
        catch (const std::exception& e) 
        {
            std::cout << "Random access error: " << e.what() << "\n";
        }
    }
    
    // ✅ File copying with progress
    static void copyFileWithProgress(const std::string& source, const std::string& dest) 
    {
        std::cout << "\n=== File Copy with Progress ===\n";
        
        try 
        {
            std::ifstream src(source, std::ios::binary);
            std::ofstream dst(dest, std::ios::binary);
            
            if (!src.is_open()) 
            {
                throw std::runtime_error("Cannot open source file: " + source);
            }
            
            if (!dst.is_open()) 
            {
                throw std::runtime_error("Cannot open destination file: " + dest);
            }
            
            // Get file size for progress calculation
            src.seekg(0, std::ios::end);
            std::streamsize totalSize = src.tellg();
            src.seekg(0, std::ios::beg);
            
            std::cout << "Copying " << totalSize << " bytes from " << source << " to " << dest << "\n";
            
            const size_t bufferSize = 4096;
            char buffer[bufferSize];
            std::streamsize copiedBytes = 0;
            
            while (src.read(buffer, bufferSize) || src.gcount() > 0) 
            {
                std::streamsize bytesRead = src.gcount();
                dst.write(buffer, bytesRead);
                
                if (dst.fail()) 
                {
                    throw std::runtime_error("Write error during copy");
                }
                
                copiedBytes += bytesRead;
                
                // Show progress
                int progress = static_cast<int>((copiedBytes * 100) / totalSize);
                std::cout << "\rProgress: " << progress << "% (" << copiedBytes << "/" << totalSize << " bytes)";
                std::cout.flush();
            }
            
            std::cout << "\nCopy completed successfully!\n";
            
        }
        catch (const std::exception& e) 
        {
            std::cout << "\nCopy error: " << e.what() << "\n";
        }
    }
    
    // ✅ Directory operations
    static void listDirectory(const std::string& path) 
    {
        std::cout << "\n=== Directory Listing: " << path << " ===\n";
        
        try 
        {
            if (!fs::exists(path) || !fs::is_directory(path)) 
            {
                std::cout << "Path does not exist or is not a directory\n";
                return;
            }
            
            std::cout << std::left << std::setw(20) << "Name" 
                      << std::setw(10) << "Type" 
                      << std::setw(15) << "Size" << "\n";
            std::cout << std::string(45, '-') << "\n";
            
            for (const auto& entry : fs::directory_iterator(path)) 
            {
                std::string name = entry.path().filename().string();
                std::string type = entry.is_directory() ? "DIR" : "FILE";
                std::string size = entry.is_directory() ? "-" : std::to_string(entry.file_size());
                
                std::cout << std::left << std::setw(20) << name 
                          << std::setw(10) << type 
                          << std::setw(15) << size << "\n";
            }
            
        }
        catch (const fs::filesystem_error& e) 
        {
            std::cout << "Directory listing error: " << e.what() << "\n";
        }
    }
};

void demonstrateAdvancedFileOperations() 
{
    std::cout << "=== Advanced File Operations ===\n";
    
    // Create a test file first
    try 
    {
        {
            std::ofstream testFile("test_file.txt");
            testFile << "This is a test file for advanced operations.\n";
            testFile << "It contains multiple lines of text.\n";
            testFile << "We'll use it to demonstrate various file operations.\n";
        }
        
        AdvancedFileOperations::displayFileInfo("test_file.txt");
        AdvancedFileOperations::demonstrateRandomAccess("random_access_test.txt");
        AdvancedFileOperations::copyFileWithProgress("test_file.txt", "copied_file.txt");
        AdvancedFileOperations::listDirectory(".");
        
        // Display info for the copied file
        AdvancedFileOperations::displayFileInfo("copied_file.txt");
        
    }
    catch (const std::exception& e) 
    {
        std::cout << "Advanced operations error: " << e.what() << "\n";
    }
}

int main() 
{
    demonstrateTextFileOperations();
    demonstrateBinaryFileOperations();
    demonstrateAdvancedFileOperations();
    return 0;
}
