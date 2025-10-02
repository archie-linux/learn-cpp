#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
#include <string>
#include <iomanip>

class StreamPerformance 
{
public:
    // ✅ Benchmark different output methods
    static void benchmarkOutputMethods() 
    {
        std::cout << "\n=== Output Performance Benchmark ===\n";
        
        const int iterations = 100000;
        
        // Method 1: std::cout with sync_with_stdio
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < iterations; ++i) 
        {
            std::cout << "Line " << i << ": Hello, World!\n";
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        // Method 2: std::cout without sync_with_stdio
        std::ios_base::sync_with_stdio(false);  // Disable sync with C stdio
        std::cin.tie(nullptr);  // Untie cin from cout
        
        start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < iterations; ++i) 
        {
            std::cout << "Line " << i << ": Hello, World!\n";
        }
        
        end = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        // Method 3: Buffered output with ostringstream
        start = std::chrono::high_resolution_clock::now();
        
        std::ostringstream buffer;
        for (int i = 0; i < iterations; ++i) 
        {
            buffer << "Line " << i << ": Hello, World!\n";
        }
        std::cout << buffer.str();
        
        end = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        std::cout << "\nPerformance Results:\n";
        std::cout << "Synced stdout:    " << duration1.count() << " ms\n";
        std::cout << "Unsynced stdout:  " << duration2.count() << " ms\n";
        std::cout << "Buffered output:  " << duration3.count() << " ms\n";
        
        // Re-enable sync for safety
        std::ios_base::sync_with_stdio(true);
    }
    
    // ✅ Benchmark file I/O methods
    static void benchmarkFileIO() 
    {
        std::cout << "\n=== File I/O Performance Benchmark ===\n";
        
        const int dataSize = 10000;
        std::vector<int> testData;
        
        // Generate test data
        for (int i = 0; i < dataSize; ++i) 
        {
            testData.push_back(i * i);
        }
        
        // Method 1: Text file I/O
        auto start = std::chrono::high_resolution_clock::now();
        
        {
            std::ofstream textFile("test_text.txt");
            for (int value : testData) 
            {
                textFile << value << "\n";
            }
        }
        
        std::vector<int> readData1;
        {
            std::ifstream textFile("test_text.txt");
            int value;
            while (textFile >> value) 
            {
                readData1.push_back(value);
            }
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto textDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        // Method 2: Binary file I/O
        start = std::chrono::high_resolution_clock::now();
        
        {
            std::ofstream binaryFile("test_binary.bin", std::ios::binary);
            size_t size = testData.size();
            binaryFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
            binaryFile.write(reinterpret_cast<const char*>(testData.data()), 
                           testData.size() * sizeof(int));
        }
        
        std::vector<int> readData2;
        {
            std::ifstream binaryFile("test_binary.bin", std::ios::binary);
            size_t size;
            binaryFile.read(reinterpret_cast<char*>(&size), sizeof(size));
            readData2.resize(size);
            binaryFile.read(reinterpret_cast<char*>(readData2.data()), 
                          size * sizeof(int));
        }
        
        end = std::chrono::high_resolution_clock::now();
        auto binaryDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "File I/O Results (" << dataSize << " integers):\n";
        std::cout << "Text file:   " << textDuration.count() << " µs\n";
        std::cout << "Binary file: " << binaryDuration.count() << " µs\n";
        std::cout << "Binary is " << std::fixed << std::setprecision(1) 
                  << (static_cast<double>(textDuration.count()) / binaryDuration.count()) 
                  << "x faster\n";
        
        // Verify data integrity
        bool textCorrect = (testData == readData1);
        bool binaryCorrect = (testData == readData2);
        
        std::cout << "Text data integrity: " << (textCorrect ? "PASS" : "FAIL") << "\n";
        std::cout << "Binary data integrity: " << (binaryCorrect ? "PASS" : "FAIL") << "\n";
    }
    
    // ✅ String manipulation performance
    static void benchmarkStringOperations() 
    {
        std::cout << "\n=== String Operations Benchmark ===\n";
        
        const int iterations = 10000;
        
        // Method 1: String concatenation with +=
        auto start = std::chrono::high_resolution_clock::now();
        
        std::string result1;
        for (int i = 0; i < iterations; ++i) 
        {
            result1 += "Item " + std::to_string(i) + "\n";
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto concat_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        // Method 2: ostringstream
        start = std::chrono::high_resolution_clock::now();
        
        std::ostringstream oss;
        for (int i = 0; i < iterations; ++i) 
        {
            oss << "Item " << i << "\n";
        }
        std::string result2 = oss.str();
        
        end = std::chrono::high_resolution_clock::now();
        auto stream_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        // Method 3: Pre-allocated string with reserve
        start = std::chrono::high_resolution_clock::now();
        
        std::string result3;
        result3.reserve(iterations * 20);  // Estimate final size
        for (int i = 0; i < iterations; ++i) 
        {
            result3 += "Item " + std::to_string(i) + "\n";
        }
        
        end = std::chrono::high_resolution_clock::now();
        auto reserved_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "String Building Results (" << iterations << " items):\n";
        std::cout << "String concatenation: " << concat_duration.count() << " µs\n";
        std::cout << "ostringstream:        " << stream_duration.count() << " µs\n";
        std::cout << "Reserved string:      " << reserved_duration.count() << " µs\n";
        
        // Verify all methods produce same result
        bool results_match = (result1 == result2) && (result2 == result3);
        std::cout << "Results match: " << (results_match ? "YES" : "NO") << "\n";
    }
};

// ✅ Best practices class
class StreamBestPractices 
{
public:
    static void demonstrateBestPractices() 
    {
        std::cout << "\n=== Stream Best Practices ===\n";
        
        // ✅ Always check stream state
        std::cout << "\n--- Error Handling ---\n";
        {
            std::ifstream file("nonexistent.txt");
            if (!file.is_open()) 
            {
                std::cout << "✓ Properly checked if file opened\n";
            }
            
            if (file.fail()) 
            {
                std::cout << "✓ Detected file operation failure\n";
            }
        }
        
        // ✅ Use RAII for automatic cleanup
        std::cout << "\n--- RAII Usage ---\n";
        {
            std::ofstream file("temp.txt");
            if (file.is_open()) 
            {
                file << "Temporary data\n";
                std::cout << "✓ File automatically closed when going out of scope\n";
            }
            // File automatically closed here
        }
        
        // ✅ Efficient buffering
        std::cout << "\n--- Efficient Buffering ---\n";
        {
            std::ostringstream buffer;
            
            // Build output in memory first
            for (int i = 0; i < 5; ++i) 
            {
                buffer << "Line " << i << ": Some data\n";
            }
            
            // Single output operation
            std::cout << buffer.str();
            std::cout << "✓ Used buffering for efficient output\n";
        }
        
        // ✅ Proper stream synchronization control
        std::cout << "\n--- Stream Synchronization ---\n";
        {
            // For performance-critical code
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            
            std::cout << "✓ Disabled sync for better performance (when not mixing C and C++ I/O)\n";
            
            // Re-enable for safety
            std::ios_base::sync_with_stdio(true);
            std::cout << "✓ Re-enabled sync for safety\n";
        }
        
        // ✅ Exception safety with streams
        std::cout << "\n--- Exception Safety ---\n";
        try 
        {
            std::ofstream file("readonly_dir/file.txt");  // This might fail
            
            if (!file.is_open()) 
            {
                throw std::runtime_error("Cannot create file");
            }
            
            file << "Some data\n";
            
            if (file.fail()) 
            {
                throw std::runtime_error("Write operation failed");
            }
            
            std::cout << "✓ File operations completed successfully\n";
        }
        catch (const std::exception& e) 
        {
            std::cout << "✓ Properly caught and handled file error: " << e.what() << "\n";
        }
        
        // ✅ Binary vs text mode considerations
        std::cout << "\n--- Binary vs Text Mode ---\n";
        {
            // Text mode - platform-specific line endings
            std::ofstream textFile("text_data.txt");
            textFile << "Line 1\nLine 2\nLine 3\n";
            
            // Binary mode - exact byte control
            std::ofstream binaryFile("binary_data.bin", std::ios::binary);
            const char data[] = "Line 1\nLine 2\nLine 3\n";
            binaryFile.write(data, sizeof(data) - 1);
            
            std::cout << "✓ Used appropriate modes for text and binary data\n";
        }
    }
};

int main() 
{
    demonstrateStringStreams();
    demonstrateCustomManipulators();
    
    // Performance benchmarks (may take some time)
    StreamPerformance::benchmarkOutputMethods();
    StreamPerformance::benchmarkFileIO();
    StreamPerformance::benchmarkStringOperations();
    
    StreamBestPractices::demonstrateBestPractices();
    
    return 0;
}
