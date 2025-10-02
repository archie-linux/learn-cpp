#include <iostream>
#include <memory>
#include <vector>

// Debug allocator for tracking allocations
template <typename T>
class DebuggingAllocator 
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    
    template <typename U>
    struct rebind { using other = DebuggingAllocator<U>; };
    
    DebuggingAllocator() = default;
    
    template <typename U>
    DebuggingAllocator(const DebuggingAllocator<U>&) {}
    
    pointer allocate(size_type n) 
    {
        std::cout << "Allocating " << n << " objects of size " << sizeof(T) << '\n';
        return static_cast<pointer>(::operator new(n * sizeof(T)));
    }
    
    void deallocate(pointer p, size_type n) 
    {
        std::cout << "Deallocating " << n << " objects of size " << sizeof(T) << '\n';
        ::operator delete(p);
    }
    
    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) 
    {
        std::cout << "Constructing object at " << p << '\n';
        new(p) U(std::forward<Args>(args)...);
    }
    
    template <typename U>
    void destroy(U* p) 
    {
        std::cout << "Destroying object at " << p << '\n';
        p->~U();
    }
};

template <typename T, typename U>
bool operator==(const DebuggingAllocator<T>&, const DebuggingAllocator<U>&) 
{
    return true;
}

template <typename T, typename U>
bool operator!=(const DebuggingAllocator<T>&, const DebuggingAllocator<U>&) 
{
    return false;
}

// Memory leak detector for smart pointers
class MemoryTracker 
{
private:
    static inline std::atomic<size_t> allocation_count{0};
    static inline std::atomic<size_t> deallocation_count{0};
    
public:
    static void track_allocation() 
    {
        allocation_count++;
        std::cout << "Allocation #" << allocation_count.load() << '\n';
    }
    
    static void track_deallocation() 
    {
        deallocation_count++;
        std::cout << "Deallocation #" << deallocation_count.load() << '\n';
    }
    
    static void report() 
    {
        std::cout << "=== Memory Report ===\n";
        std::cout << "Allocations: " << allocation_count.load() << '\n';
        std::cout << "Deallocations: " << deallocation_count.load() << '\n';
        std::cout << "Potential leaks: " << (allocation_count.load() - deallocation_count.load()) << '\n';
    }
};

template <typename T>
class TrackedResource 
{
private:
    T* data;
    
public:
    explicit TrackedResource(const T& value) : data(new T(value)) 
    {
        MemoryTracker::track_allocation();
    }
    
    ~TrackedResource() 
    {
        delete data;
        MemoryTracker::track_deallocation();
    }
    
    // Non-copyable, movable
    TrackedResource(const TrackedResource&) = delete;
    TrackedResource& operator=(const TrackedResource&) = delete;
    
    TrackedResource(TrackedResource&& other) noexcept : data(other.data) 
    {
        other.data = nullptr;
    }
    
    TrackedResource& operator=(TrackedResource&& other) noexcept 
    {
        if (this != &other) 
        {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
    
    T& get() { return *data; }
    const T& get() const { return *data; }
};

void demonstrateDebugging() 
{
    std::cout << "\n=== Memory Debugging Demo ===\n";
    
    // Debug allocator usage
    std::vector<int, DebuggingAllocator<int>> debugVec;
    debugVec.push_back(1);
    debugVec.push_back(2);
    debugVec.push_back(3);
    
    std::cout << "\n--- Memory tracking ---\n";
    {
        TrackedResource<std::string> resource1("Resource 1");
        TrackedResource<std::string> resource2("Resource 2");
        
        std::cout << "Resource 1: " << resource1.get() << '\n';
        std::cout << "Resource 2: " << resource2.get() << '\n';
        
        // Move resource2
        TrackedResource<std::string> resource3 = std::move(resource2);
        std::cout << "Resource 3 (moved): " << resource3.get() << '\n';
    }
    
    MemoryTracker::report();
}
