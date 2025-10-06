#include <iostream>
#include <memory>

// Storage policies
template <typename T>
class HeapStorage 
{
private:
    std::unique_ptr<T> data;
    
public:
    HeapStorage() : data(std::make_unique<T>()) {}
    explicit HeapStorage(const T& value) : data(std::make_unique<T>(value)) {}
    
    T& get() { return *data; }
    const T& get() const { return *data; }
    
    static constexpr const char* name() { return "HeapStorage"; }
};

template <typename T>
class StackStorage 
{
private:
    T data{};
    
public:
    StackStorage() = default;
    explicit StackStorage(const T& value) : data(value) {}
    
    T& get() { return data; }
    const T& get() const { return data; }
    
    static constexpr const char* name() { return "StackStorage"; }
};

// Threading policies
class SingleThreaded 
{
public:
    void lock() const {}
    void unlock() const {}
    static constexpr const char* name() { return "SingleThreaded"; }
};

class MultiThreaded 
{
private:
    mutable std::mutex mtx;
    
public:
    void lock() const { mtx.lock(); }
    void unlock() const { mtx.unlock(); }
    static constexpr const char* name() { return "MultiThreaded"; }
};

// Policy-based smart holder
template <typename T, 
          template<typename> class StoragePolicy = HeapStorage,
          class ThreadingPolicy = SingleThreaded>
class SmartHolder : private StoragePolicy<T>, private ThreadingPolicy 
{
public:
    SmartHolder() = default;
    explicit SmartHolder(const T& value) : StoragePolicy<T>(value) {}
    
    T& operator*() 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return this->StoragePolicy<T>::get();
    }
    
    const T& operator*() const 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return this->StoragePolicy<T>::get();
    }
    
    T* operator->() 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return &this->StoragePolicy<T>::get();
    }
    
    const T* operator->() const 
    {
        std::lock_guard<ThreadingPolicy> lock(*this);
        return &this->StoragePolicy<T>::get();
    }
    
    void info() const 
    {
        std::cout << "SmartHolder using " << StoragePolicy<T>::name() 
                  << " and " << ThreadingPolicy::name() << '\n';
    }
    
private:
    // RAII lock guard
    template <typename Policy>
    struct lock_guard 
    {
        const Policy& policy;
        lock_guard(const Policy& p) : policy(p) { policy.lock(); }
        ~lock_guard() { policy.unlock(); }
    };
};

void demonstratePolicyDesign() 
{
    std::cout << "\n=== Policy-Based Design Demo ===\n";
    
    // Different combinations of policies
    SmartHolder<std::string, HeapStorage> heapHolder("Heap stored");
    SmartHolder<std::string, StackStorage> stackHolder("Stack stored");
    SmartHolder<std::string, HeapStorage, MultiThreaded> threadSafeHolder("Thread safe");
    
    heapHolder.info();
    stackHolder.info();
    threadSafeHolder.info();
    
    std::cout << "Heap holder: " << *heapHolder << '\n';
    std::cout << "Stack holder: " << *stackHolder << '\n';
    std::cout << "Thread-safe holder: " << *threadSafeHolder << '\n';
}
