#include <iostream>
#include <stdexcept>

template <typename T>
class SimpleVector 
{
private:
    T* data;
    size_t size;
    size_t capacity;
    
    void resize() 
    {
        capacity *= 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) 
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    
public:
    explicit SimpleVector(size_t initialCapacity = 4) 
        : data(new T[initialCapacity]), size(0), capacity(initialCapacity) 
    {
    }
    
    ~SimpleVector() 
    {
        delete[] data;
    }
    
    // Copy constructor
    SimpleVector(const SimpleVector& other) 
        : data(new T[other.capacity]), size(other.size), capacity(other.capacity) 
    {
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }
    
    // Assignment operator
    SimpleVector& operator=(const SimpleVector& other) 
    {
        if (this != &other) 
        {
            delete[] data;
            data = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;
            for (size_t i = 0; i < size; ++i) 
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    void push_back(const T& value) 
    {
        if (size == capacity) 
        {
            resize();
        }
        data[size++] = value;
    }
    
    T& operator[](size_t index) 
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }
    
    const T& operator[](size_t index) const 
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }
    
    size_t getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};

int main() 
{
    // Vector of integers
    SimpleVector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    
    std::cout << "Integer vector: ";
    for (size_t i = 0; i < intVec.getSize(); ++i) 
    {
        std::cout << intVec[i] << " ";
    }
    std::cout << '\n';
    
    // Vector of strings
    SimpleVector<std::string> stringVec;
    stringVec.push_back("Hello");
    stringVec.push_back("Template");
    stringVec.push_back("World");
    
    std::cout << "String vector: ";
    for (size_t i = 0; i < stringVec.getSize(); ++i) 
    {
        std::cout << stringVec[i] << " ";
    }
    std::cout << '\n';
    
    return 0;
}
