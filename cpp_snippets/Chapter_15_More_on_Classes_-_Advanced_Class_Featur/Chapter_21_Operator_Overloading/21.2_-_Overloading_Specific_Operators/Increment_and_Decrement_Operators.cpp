#include <iostream>

class Counter 
{
private:
    int value;
    
public:
    explicit Counter(int v = 0) : value(v) {}
    
    // Prefix increment: ++counter
    Counter& operator++() 
    {
        ++value;
        return *this;
    }
    
    // Postfix increment: counter++
    Counter operator++(int) 
    {
        Counter temp(*this);  // Save current state
        ++value;              // Increment
        return temp;          // Return old state
    }
    
    // Prefix decrement: --counter
    Counter& operator--() 
    {
        --value;
        return *this;
    }
    
    // Postfix decrement: counter--
    Counter operator--(int) 
    {
        Counter temp(*this);
        --value;
        return temp;
    }
    
    int getValue() const { return value; }
    
    friend std::ostream& operator<<(std::ostream& out, const Counter& counter) 
    {
        out << counter.value;
        return out;
    }
};

int main() 
{
    Counter c(5);
    
    std::cout << "Initial value: " << c << '\n';
    
    // Prefix operations
    std::cout << "++c: " << ++c << '\n';        // c becomes 6, prints 6
    std::cout << "c after ++: " << c << '\n';   // prints 6
    
    std::cout << "c++: " << c++ << '\n';        // prints 6, c becomes 7
    std::cout << "c after ++: " << c << '\n';   // prints 7
    
    // Prefix operations
    std::cout << "--c: " << --c << '\n';        // c becomes 6, prints 6
    std::cout << "c after --: " << c << '\n';   // prints 6
    
    std::cout << "c--: " << c-- << '\n';        // prints 6, c becomes 5
    std::cout << "c after --: " << c << '\n';   // prints 5
    
    return 0;
}
