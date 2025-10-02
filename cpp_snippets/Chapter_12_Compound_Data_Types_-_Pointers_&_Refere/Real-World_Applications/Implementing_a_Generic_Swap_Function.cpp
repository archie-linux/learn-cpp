template <typename T>
void swap(T& a, T& b) 
{
    T temp = a;  // Copy a
    a = b;       // Copy b to a
    b = temp;    // Copy temp to b
}

// More efficient for large objects (uses pointers internally)
template <typename T>
void swapPtr(T* a, T* b) 
{
    if (a && b) {  // Safety check
        T temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() 
{
    int x = 10, y = 20;
    std::cout << "Before: x=" << x << ", y=" << y << '\n';
    
    swap(x, y);
    std::cout << "After: x=" << x << ", y=" << y << '\n';
    
    return 0;
}
