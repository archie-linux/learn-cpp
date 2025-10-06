#include <iostream>
#include <memory>
#include <cstdio>

// Custom deleter for FILE*
struct FileDeleter 
{
    void operator()(FILE* file) const 
    {
        if (file) 
        {
            std::cout << "Closing file\n";
            std::fclose(file);
        }
    }
};

// Custom deleter for arrays
template <typename T>
struct ArrayDeleter 
{
    void operator()(T* ptr) const 
    {
        std::cout << "Deleting array\n";
        delete[] ptr;
    }
};

class SmartResourceManager 
{
public:
    void demonstrateCustomDeleters() 
    {
        std::cout << "=== Custom Deleters Demo ===\n";
        
        // Smart pointer with custom deleter for FILE*
        std::unique_ptr<FILE, FileDeleter> file(std::fopen("temp.txt", "w"));
        
        if (file) 
        {
            std::fprintf(file.get(), "Hello from smart pointer!\n");
            // File automatically closed when unique_ptr is destroyed
        }
        
        // Smart pointer with lambda deleter
        auto arrayPtr = std::unique_ptr<int[], ArrayDeleter<int>>(new int[10]);
        
        // Initialize array
        for (int i = 0; i < 10; ++i) 
        {
            arrayPtr[i] = i * i;
        }
        
        std::cout << "Array values: ";
        for (int i = 0; i < 10; ++i) 
        {
            std::cout << arrayPtr[i] << " ";
        }
        std::cout << '\n';
        
        // Lambda deleter example
        auto customPtr = std::unique_ptr<Resource, std::function<void(Resource*)>>(
            new Resource(99),
            [](Resource* r) 
            {
                std::cout << "Custom lambda deleter called\n";
                delete r;
            }
        );
        
        customPtr->doWork();
    }
    
    void demonstrateSharedPtrWithCustomDeleter() 
    {
        std::cout << "\n=== shared_ptr with Custom Deleter ===\n";
        
        // shared_ptr with custom deleter
        std::shared_ptr<Resource> resource(new Resource(100), 
            [](Resource* r) 
            {
                std::cout << "Custom deleter for shared_ptr\n";
                delete r;
            });
        
        // Multiple shared_ptr instances can share the same custom deleter
        std::shared_ptr<Resource> resource2 = resource;
        
        std::cout << "Reference count: " << resource.use_count() << '\n';
        
        resource->doWork();
        resource2->doWork();
    }
};
