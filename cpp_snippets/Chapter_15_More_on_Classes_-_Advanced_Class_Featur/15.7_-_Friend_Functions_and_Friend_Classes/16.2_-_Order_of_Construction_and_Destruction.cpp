#include <iostream>
#include <string>

class Component {
private:
    std::string m_name;

public:
    Component(const std::string& name) : m_name{name} {
        std::cout << "  Component '" << m_name << "' constructed\n";
    }
    
    ~Component() {
        std::cout << "  Component '" << m_name << "' destroyed\n";
    }
    
    const std::string& getName() const { return m_name; }
};

class Vehicle {
protected:
    std::string m_model;
    Component m_engine;   // Member object constructed first

public:
    Vehicle(const std::string& model) : m_model{model}, m_engine{"Engine"} {
        std::cout << "Vehicle '" << m_model << "' constructed\n";
    }
    
    ~Vehicle() {
        std::cout << "Vehicle '" << m_model << "' destroyed\n";
    }
    
    void start() const {
        std::cout << m_model << " engine starting...\n";
    }
};

class Car : public Vehicle {
private:
    Component m_radio;    // Derived class members constructed after base
    int m_doors;

public:
    Car(const std::string& model, int doors) 
        : Vehicle{model}, m_radio{"Radio"}, m_doors{doors} {
        std::cout << "Car with " << m_doors << " doors constructed\n";
    }
    
    ~Car() {
        std::cout << "Car destroyed\n";
        // Destruction order: derived members, then base class
    }
    
    void playMusic() const {
        std::cout << "Playing music on " << m_radio.getName() << '\n';
    }
};

int main() {
    std::cout << "=== Construction Order ===\n";
    {
        Car sedan{"Toyota Camry", 4};
        std::cout << "\n=== Using the car ===\n";
        sedan.start();      // Inherited method
        sedan.playMusic();  // Derived method
        std::cout << "\n=== Destruction Order ===\n";
    } // Car destructor called here
    
    return 0;
}
