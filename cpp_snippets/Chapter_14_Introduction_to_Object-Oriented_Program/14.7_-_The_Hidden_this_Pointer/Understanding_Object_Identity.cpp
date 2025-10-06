#include <iostream>
#include <string>

class Counter {
private:
    int m_value;
    std::string m_name;

public:
    Counter(const std::string& name, int initial = 0) 
        : m_name{name}, m_value{initial} {}
    
    // Method that doesn't use 'this' explicitly
    void increment() {
        ++m_value;  // Equivalent to: ++(this->m_value);
        std::cout << m_name << " incremented to " << m_value << '\n';
    }
    
    // Method that explicitly uses 'this'
    Counter& add(int amount) {
        this->m_value += amount;  // Explicit use of 'this'
        return *this;             // Return reference to current object
    }
    
    // Method chaining using 'this'
    Counter& multiply(int factor) {
        m_value *= factor;
        return *this;  // Enable chaining: counter.multiply(2).add(5)
    }
    
    // Compare with another Counter
    bool isGreaterThan(const Counter& other) const {
        return this->m_value > other.m_value;
        // Could also write: return m_value > other.m_value;
    }
    
    // Self-assignment check (useful in copy assignment operator)
    Counter& copyFrom(const Counter& other) {
        if (this == &other) {  // Check for self-assignment
            std::cout << "Self-assignment detected, no operation performed\n";
            return *this;
        }
        
        this->m_value = other.m_value;
        std::cout << m_name << " copied value from " << other.m_name << '\n';
        return *this;
    }
    
    int getValue() const { return m_value; }
    const std::string& getName() const { return m_name; }
    
    void display() const {
        std::cout << m_name << ": " << m_value << " (object at " << this << ")\n";
    }
};

int main() {
    Counter alpha{"Alpha", 10};
    Counter beta{"Beta", 5};
    
    std::cout << "Initial state:\n";
    alpha.display();  // Shows object address
    beta.display();   // Different object address
    
    // Method chaining using returned *this
    alpha.add(5).multiply(2).add(3);  // 10 + 5 = 15, 15 * 2 = 30, 30 + 3 = 33
    std::cout << "After chaining: " << alpha.getValue() << '\n';
    
    // Comparison using 'this'
    if (alpha.isGreaterThan(beta)) {
        std::cout << alpha.getName() << " is greater than " << beta.getName() << '\n';
    }
    
    // Self-assignment
    alpha.copyFrom(alpha);  // Detects self-assignment
    
    // Copy from other
    beta.copyFrom(alpha);
    
    alpha.display();
    beta.display();
    
    return 0;
}
