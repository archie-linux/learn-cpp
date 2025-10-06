#include <iostream>
#include <string>

class Person {
private:
    std::string m_name;
    int m_age;

public:
    Person(const std::string& name, int age) : m_name{name}, m_age{age} {}
    
    // Case 1: Parameter name conflicts with member name
    void setName(const std::string& name) {
        this->m_name = name;  // 'this->' needed to distinguish from parameter
        // Without 'this->': name = name; would assign parameter to itself!
    }
    
    void setAge(int age) {
        this->m_age = age;    // 'this->' needed to distinguish from parameter
    }
    
    // Case 2: Method chaining
    Person& changeName(const std::string& name) {
        m_name = name;        // 'this->' not needed here (no naming conflict)
        return *this;         // 'this' needed to return current object
    }
    
    Person& changeAge(int age) {
        this->m_age = age;    // 'this->' used for consistency
        return *this;
    }
    
    // Case 3: Self-comparison or operations
    bool isSamePersonAs(const Person& other) const {
        return this == &other;  // Comparing object addresses
    }
    
    bool isOlderThan(const Person& other) const {
        return m_age > other.m_age;  // 'this->' not needed - no ambiguity
        // Could write: return this->m_age > other.m_age;
    }
    
    void display() const {
        std::cout << "Name: " << m_name << ", Age: " << m_age << '\n';
    }
};

int main() {
    Person john{"John", 25};
    Person jane{"Jane", 30};
    
    john.display();
    
    // Method chaining
    john.changeName("Johnny").changeAge(26);
    john.display();
    
    // Self-comparison
    std::cout << "john same as john: " << (john.isSamePersonAs(john) ? "Yes" : "No") << '\n';
    std::cout << "john same as jane: " << (john.isSamePersonAs(jane) ? "Yes" : "No") << '\n';
    
    return 0;
}
