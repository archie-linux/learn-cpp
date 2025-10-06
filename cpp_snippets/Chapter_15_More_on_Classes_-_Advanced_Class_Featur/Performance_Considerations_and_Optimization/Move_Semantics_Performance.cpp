#include <chrono>
#include <iostream>
#include <vector>

class PerformanceTest 
{
public:
    static void compareCopyVsMove() 
    {
        std::cout << "\n=== Copy vs Move Performance ===\n";
        
        const size_t iterations = 1000000;
        std::vector<std::string> source;
        source.reserve(iterations);
        
        // Prepare source data
        for (size_t i = 0; i < iterations; ++i) 
        {
            source.emplace_back("This is a test string " + std::to_string(i));
        }
        
        // Test copy performance
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<std::string> copy_dest;
        copy_dest.reserve(iterations);
        
        for (const auto& str : source) 
        {
            copy_dest.push_back(str);  // Copy
        }
        
        auto copy_time = std::chrono::high_resolution_clock::now() - start;
        
        // Test move performance
        start = std::chrono::high_resolution_clock::now();
        std::vector<std::string> move_dest;
        move_dest.reserve(iterations);
        
        for (auto& str : source) 
        {
            move_dest.push_back(std::move(str));  // Move
        }
        
        auto move_time = std::chrono::high_resolution_clock::now() - start;
        
        std::cout << "Copy time: " << std::chrono::duration_cast<std::chrono::milliseconds>(copy_time).count() << "ms\n";
        std::cout << "Move time: " << std::chrono::duration_cast<std::chrono::milliseconds>(move_time).count() << "ms\n";
        
        auto speedup = static_cast<double>(copy_time.count()) / move_time.count();
        std::cout << "Speedup: " << speedup << "x faster\n";
    }
    
    static void testRVO() 
    {
        std::cout << "\n=== Return Value Optimization ===\n";
        
        auto createLargeString = [](size_t size) 
        {
            std::string result;
            result.reserve(size);
            for (size_t i = 0; i < size; ++i) 
            {
                result += 'A' + (i % 26);
            }
            return result;  // RVO applies here
        };
        
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < 10000; ++i) 
        {
            auto str = createLargeString(1000);  // No copy/move thanks to RVO
            // Use str to prevent optimization away
            volatile auto len = str.length();
            (void)len;
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        std::cout << "RVO test completed in: " << duration.count() << "ms\n";
    }
};
