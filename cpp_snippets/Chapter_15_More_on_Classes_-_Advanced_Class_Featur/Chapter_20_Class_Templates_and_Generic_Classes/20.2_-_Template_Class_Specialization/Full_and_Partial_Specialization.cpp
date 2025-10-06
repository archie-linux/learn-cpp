#include <iostream>
#include <cstring>

// Primary template
template <typename T>
class Storage 
{
private:
    T value;
    
public:
    Storage(const T& v) : value(v) {}
    
    void print() const 
    {
        std::cout << "Generic storage: " << value << '\n';
    }
    
    T getValue() const { return value; }
};

// Explicit specialization for bool
template <>
class Storage<bool> 
{
private:
    bool value;
    
public:
    Storage(bool v) : value(v) {}
    
    void print() const 
    {
        std::cout << "Boolean storage: " << (value ? "true" : "false") << '\n';
    }
    
    bool getValue() const { return value; }
};

// Explicit specialization for C-string
template <>
class Storage<const char*> 
{
private:
    char* value;
    
public:
    Storage(const char* v) : value(new char[std::strlen(v) + 1]) 
    {
        std::strcpy(value, v);
    }
    
    ~Storage() 
    {
        delete[] value;
    }
    
    // Copy constructor
    Storage(const Storage& other) : value(new char[std::strlen(other.value) + 1]) 
    {
        std::strcpy(value, other.value);
    }
    
    void print() const 
    {
        std::cout << "C-string storage: " << value << '\n';
    }
    
    const char* getValue() const { return value; }
};

int main() 
{
    Storage<int> intStorage(42);
    Storage<bool> boolStorage(true);
    Storage<const char*> stringStorage("Hello Templates!");
    
    intStorage.print();     // Uses generic version
    boolStorage.print();    // Uses bool specialization
    stringStorage.print();  // Uses C-string specialization
    
    return 0;
}
