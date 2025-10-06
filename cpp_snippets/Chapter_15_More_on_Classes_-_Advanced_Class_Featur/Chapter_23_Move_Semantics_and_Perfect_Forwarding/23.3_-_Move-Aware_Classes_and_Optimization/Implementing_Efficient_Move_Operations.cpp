#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

template <typename T>
class MoveOptimizedVector 
{
private:
    std::unique_ptr<T[]> data;
    size_t size_;
    size_t capacity_;
    
    void reallocate(size_t newCapacity) 
    {
        auto newData = std::make_unique<T[]>(newCapacity);
        
        // Move elements if T has noexcept move constructor
        if constexpr (std::is_nothrow_move_constructible_v<T>) 
        {
            for (size_t i = 0; i < size_; ++i) 
            {
                new (&newData[i]) T(std::move(data[i]));
            }
        }
        else 
        {
            // Copy if move might throw
            for (size_t i = 0; i < size_; ++i) 
            {
                new (&newData[i]) T(data[i]);
            }
        }
        
        data = std::move(newData);
        capacity_ = newCapacity;
    }
    
public:
    MoveOptimizedVector() : data(nullptr), size_(0), capacity_(0) {}
    
    explicit MoveOptimizedVector(size_t initialCapacity) 
        : data(std::make_unique<T[]>(initialCapacity)), size_(0), capacity_(initialCapacity) {}
    
    // Copy constructor
    MoveOptimizedVector(const MoveOptimizedVector& other) 
        : data(std::make_unique<T[]>(other.capacity_)), size_(other.size_), capacity_(other.capacity_) 
    {
        for (size_t i = 0; i < size_; ++i) 
        {
            new (&data[i]) T(other.data[i]);
        }
        std::cout << "Vector copied\n";
    }
    
    // Move constructor
    MoveOptimizedVector(MoveOptimizedVector&& other) noexcept 
        : data(std::move(other.data)), size_(other.size_), capacity_(other.capacity_) 
    {
        other.size_ = 0;
        other.capacity_ = 0;
        std::cout << "Vector moved\n";
    }
    
    // Copy assignment
    MoveOptimizedVector& operator=(const MoveOptimizedVector& other) 
    {
        if (this != &other) 
        {
            data = std::make_unique<T[]>(other.capacity_);
            size_ = other.size_;
            capacity_ = other.capacity_;
            
            for (size_t i = 0; i < size_; ++i) 
            {
                new (&data[i]) T(other.data[i]);
            }
            std::cout << "Vector copy-assigned\n";
        }
        return *this;
    }
    
    // Move assignment
    MoveOptimizedVector& operator=(MoveOptimizedVector&& other) noexcept 
    {
        if (this != &other) 
        {
            data = std::move(other.data);
            size_ = other.size_;
            capacity_ = other.capacity_;
            
            other.size_ = 0;
            other.capacity_ = 0;
            std::cout << "Vector move-assigned\n";
        }
        return *this;
    }
    
    void push_back(const T& value) 
    {
        if (size_ == capacity_) 
        {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (&data[size_++]) T(value);
    }
    
    void push_back(T&& value) 
    {
        if (size_ == capacity_) 
        {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (&data[size_++]) T(std::move(value));
    }
    
    template <typename... Args>
    void emplace_back(Args&&... args) 
    {
        if (size_ == capacity_) 
        {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (&data[size_++]) T(std::forward<Args>(args)...);
    }
    
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
};

// Test class to demonstrate move optimizations
class MoveTestClass 
{
private:
    std::string data;
    
public:
    MoveTestClass(const std::string& s) : data(s) 
    {
        std::cout << "MoveTestClass constructed: " << data << '\n';
    }
    
    MoveTestClass(const MoveTestClass& other) : data(other.data) 
    {
        std::cout << "MoveTestClass copied: " << data << '\n';
    }
    
    MoveTestClass(MoveTestClass&& other) noexcept : data(std::move(other.data)) 
    {
        std::cout << "MoveTestClass moved: " << data << '\n';
    }
    
    ~MoveTestClass() 
    {
        std::cout << "MoveTestClass destroyed: " << data << '\n';
    }
    
    const std::string& getData() const { return data; }
};

void demonstrateMoveOptimizations() 
{
    std::cout << "\n=== Move Optimizations Demo ===\n";
    
    MoveOptimizedVector<MoveTestClass> vec;
    
    std::cout << "--- Adding elements ---\n";
    vec.emplace_back("Element1");                    // Direct construction
    
    MoveTestClass temp("Element2");
    vec.push_back(temp);                            // Copy
    vec.push_back(std::move(temp));                 // Move
    
    std::cout << "\n--- Moving entire vector ---\n";
    MoveOptimizedVector<MoveTestClass> vec2 = std::move(vec);  // Efficient move
    
    std::cout << "\n--- Vector operations complete ---\n";
}

int main() 
{
    demonstrateMoveSemantics();
    demonstratePerfectForwarding();
    demonstrateMoveOptimizations();
    
    return 0;
}
