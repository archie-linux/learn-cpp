#include <iostream>

class Counter {
private:
    int m_value;

public:
    Counter(int value = 0) : m_value{value} {}
    
    // These two functions are equivalent:
    void increment1() {
        m_value++;        // Implicit: this->m_value++
    }
    
    void increment2() {
        this->m_value++;  // Explicit use of this pointer
    }
    
    // const member function - this becomes const Counter* const this
    int getValue() const {
        return m_value;   // Can't modify m_value through const this
        // m_value++;     // ❌ Error: cannot modify in const function
    }
    
    // Method chaining using this
    Counter& add(int amount) {
        m_value += amount;
        return *this;     // Return reference to current object
    }
    
    // Self-comparison
    bool equals(const Counter& other) const {
        return this->m_value == other.m_value;
    }
    
    void displayAddress() const {
        std::cout << "Object at address: " << this << ", value: " << m_value << '\n';
    }
};

int main() {
    Counter a{10};
    Counter b{20};
    
    a.displayAddress();  // Different addresses
    b.displayAddress();
    
    // Method chaining
    a.add(5).add(3);     // Chained calls: 10 + 5 + 3 = 18
    std::cout << "a after chaining: " << a.getValue() << '\n';
    
    // const object can only call const member functions
    const Counter c{100};
    std::cout << "const counter: " << c.getValue() << '\n';  // ✅ const function
    // c.increment1();   // ❌ Error: non-const function on const object
    
    return 0;
}
