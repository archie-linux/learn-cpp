#include <iostream>
#include <string>

class Fraction {
private:
    int m_numerator;
    int m_denominator;
    
    // Helper function to simplify fractions
    void simplify() {
        int gcd = calculateGCD(std::abs(m_numerator), std::abs(m_denominator));
        m_numerator /= gcd;
        m_denominator /= gcd;
        
        // Keep denominator positive
        if (m_denominator < 0) {
            m_numerator = -m_numerator;
            m_denominator = -m_denominator;
        }
    }
    
    static int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int numerator = 0, int denominator = 1) 
        : m_numerator{numerator}, m_denominator{denominator} {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }
    
    // Member function operators (for assignment-style operations)
    Fraction& operator+=(const Fraction& other) {
        m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
        m_denominator = m_denominator * other.m_denominator;
        simplify();
        return *this;
    }
    
    Fraction& operator-=(const Fraction& other) {
        m_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
        m_denominator = m_denominator * other.m_denominator;
        simplify();
        return *this;
    }
    
    // Friend functions for binary operators (need access to private members)
    friend Fraction operator+(const Fraction& left, const Fraction& right);
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, const Fraction& right);
    
    // Friend functions for comparison operators
    friend bool operator==(const Fraction& left, const Fraction& right);
    friend bool operator!=(const Fraction& left, const Fraction& right);
    friend bool operator<(const Fraction& left, const Fraction& right);
    friend bool operator>(const Fraction& left, const Fraction& right);
    
    // Friend function for stream insertion
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    
    // Accessor methods
    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }
    
    double toDouble() const {
        return static_cast<double>(m_numerator) / m_denominator;
    }
};

// Friend function implementations (have access to private members)
Fraction operator+(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_denominator + right.m_numerator * left.m_denominator,
        left.m_denominator * right.m_denominator
    };
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_denominator - right.m_numerator * left.m_denominator,
        left.m_denominator * right.m_denominator
    };
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_numerator,
        left.m_denominator * right.m_denominator
    };
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    return Fraction{
        left.m_numerator * right.m_denominator,
        left.m_denominator * right.m_numerator
    };
}

bool operator==(const Fraction& left, const Fraction& right) {
    return left.m_numerator == right.m_numerator && 
           left.m_denominator == right.m_denominator;
}

bool operator!=(const Fraction& left, const Fraction& right) {
    return !(left == right);
}

bool operator<(const Fraction& left, const Fraction& right) {
    return left.m_numerator * right.m_denominator < 
           right.m_numerator * left.m_denominator;
}

bool operator>(const Fraction& left, const Fraction& right) {
    return right < left;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    if (fraction.m_denominator == 1) {
        out << fraction.m_numerator;
    } else {
        out << fraction.m_numerator << "/" << fraction.m_denominator;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    int numerator, denominator = 1;
    char slash;
    
    in >> numerator;
    if (in.peek() == '/') {
        in >> slash >> denominator;
    }
    
    fraction = Fraction{numerator, denominator};
    return in;
}

int main() {
    try {
        Fraction a{3, 4};
        Fraction b{1, 2};
        
        std::cout << "a = " << a << '\n';
        std::cout << "b = " << b << '\n';
        
        // Using friend operators
        Fraction sum = a + b;
        Fraction difference = a - b;
        Fraction product = a * b;
        Fraction quotient = a / b;
        
        std::cout << "a + b = " << sum << '\n';
        std::cout << "a - b = " << difference << '\n';
        std::cout << "a * b = " << product << '\n';
        std::cout << "a / b = " << quotient << '\n';
        
        // Comparisons
        std::cout << "a == b: " << (a == b ? "true" : "false") << '\n';
        std::cout << "a > b: " << (a > b ? "true" : "false") << '\n';
        
        // Assignment operators
        Fraction c{1, 3};
        c += a;
        std::cout << "After c += a: c = " << c << '\n';
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
    

# Chapters 16-18: Comprehensive Object-Oriented Programming Guide

## From Basic Classes to Advanced OOP: Inheritance, Virtual Functions, and Polymorphism

Building on the foundation from Chapters 14-15, we now explore the advanced pillars of Object-Oriented Programming: **Inheritance** (Chapter 16), **Virtual Functions** (Chapter 17), and **Polymorphism** (Chapter 18). These concepts enable code reuse, extensibility, and elegant design patterns essential for large-scale software development.

---

## Chapter 16: Inheritance - Building Class Hierarchies

### 16.1 - Introduction to Inheritance

Inheritance allows us to create new classes based on existing classes, promoting code reuse and establishing "is-a" relationships.

```cpp
#include <iostream>
#include <string>

// Base class (parent class)
class Animal {
protected:  // Accessible to derived classes, but not to external code
    std::string m_name;
    int m_age;

public:
    Animal(const std::string& name, int age) : m_name{name}, m_age{age} {
        std::cout << "Animal constructor: " << m_name << '\n';
    }
    
    ~Animal() {
        std::cout << "Animal destructor: " << m_name << '\n';
    }
    
    void eat() const {
        std::cout << m_name << " is eating\n";
    }
    
    void sleep() const {
        std::cout << m_name << " is sleeping\n";
    }
    
    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
    
    void displayInfo() const {
        std::cout << "Animal: " << m_name << ", Age: " << m_age << '\n';
    }
};

// Derived class (child class) - inherits from Animal
class Dog : public Animal {  // "public inheritance" - is-a relationship
private:
    std::string m_breed;

public:
    Dog(const std::string& name, int age, const std::string& breed)
        : Animal{name, age}, m_breed{breed} {  // Call base class constructor
        std::cout << "Dog constructor: " << m_name << '\n';
    }
    
    ~Dog() {
        std::cout << "Dog destructor: " << m_name << '\n';
    }
    
    // Additional methods specific to Dog
    void bark() const {
        std::cout << m_name << " barks: Woof! Woof!\n";
    }
    
    void wagTail() const {
        std::cout << m_name << " wags tail happily\n";
    }
    
    const std::string& getBreed() const { return m_breed; }
    
    // Override base class method with additional information
    void displayInfo() const {
        std::cout << "Dog: " << m_name << " (" << m_breed << "), Age: " << m_age << '\n';
    }
};

class Cat : public Animal {
private:
    bool m_isIndoor;

public:
    Cat(const std::string& name, int age, bool isIndoor = true)
        : Animal{name, age}, m_isIndoor{isIndoor} {
        std::cout << "Cat constructor: " << m_name << '\n';
    }
    
    ~Cat() {
        std::cout << "Cat destructor: " << m_name << '\n';
    }
    
    void meow() const {
        std::cout << m_name << " meows: Meow! Meow!\n";
    }
    
    void purr() const {
        std::cout << m_name << " purrs contentedly\n";
    }
    
    bool isIndoor() const { return m_isIndoor; }
    
    void displayInfo() const {
        std::cout << "Cat: " << m_name << ", Age: " << m_age 
                  << " (" << (m_isIndoor ? "Indoor" : "Outdoor") << ")\n";
    }
};

int main() {
    std::cout << "=== Creating Animals ===\n";
    
    Dog buddy{"Buddy", 3, "Golden Retriever"};
    Cat whiskers{"Whiskers", 2, true};
    
    std::cout << "\n=== Using inherited methods ===\n";
    buddy.eat();        // Inherited from Animal
    buddy.sleep();      // Inherited from Animal
    buddy.bark();       // Dog-specific method
    buddy.wagTail();    // Dog-specific method
    
    whiskers.eat();     // Inherited from Animal
    whiskers.sleep();   // Inherited from Animal
    whiskers.meow();    // Cat-specific method
    whiskers.purr();    // Cat-specific method
    
    std::cout << "\n=== Display information ===\n";
    buddy.displayInfo();    // Dog's version
    whiskers.displayInfo(); // Cat's version
    
    std::cout << "\n=== Destructors called automatically ===\n";
    return 0;
    // Destructors called in reverse order: derived, then base
}
