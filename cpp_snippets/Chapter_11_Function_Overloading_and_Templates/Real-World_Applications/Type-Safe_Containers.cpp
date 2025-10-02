template <typename T>
class SimpleVector 
{
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    explicit SimpleVector(size_t initialCapacity = 10) 
        : data(new T[initialCapacity]), size(0), capacity(initialCapacity) {}
    
    ~SimpleVector() { delete[] data; }
    
    void push_back(const T& item) 
    {
        if (size >= capacity) resize();
        data[size++] = item;
    }
    
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    
    size_t getSize() const { return size; }

private:
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
};

int main() 
{
    SimpleVector<int> intVec;
    SimpleVector<std::string> stringVec;
    
    intVec.push_back(1);
    intVec.push_back(2);
    
    stringVec.push_back("Hello");
    stringVec.push_back("World");
    
    return 0;
}
