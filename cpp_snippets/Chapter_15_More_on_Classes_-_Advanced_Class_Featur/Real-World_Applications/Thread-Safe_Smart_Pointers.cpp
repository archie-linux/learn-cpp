#include <atomic>
#include <memory>

template <typename T>
class AtomicSharedPtr 
{
private:
    mutable std::atomic<std::shared_ptr<T>*> ptr;
    
public:
    AtomicSharedPtr() : ptr(new std::shared_ptr<T>()) {}
    
    explicit AtomicSharedPtr(std::shared_ptr<T> p) 
        : ptr(new std::shared_ptr<T>(std::move(p))) {}
    
    ~AtomicSharedPtr() 
    {
        delete ptr.load();
    }
    
    std::shared_ptr<T> load() const 
    {
        return *ptr.load();
    }
    
    void store(std::shared_ptr<T> p) 
    {
        auto old_ptr = ptr.exchange(new std::shared_ptr<T>(std::move(p)));
        delete old_ptr;
    }
    
    std::shared_ptr<T> exchange(std::shared_ptr<T> p) 
    {
        auto new_ptr = new std::shared_ptr<T>(std::move(p));
        auto old_ptr = ptr.exchange(new_ptr);
        auto result = *old_ptr;
        delete old_ptr;
        return result;
    }
};
