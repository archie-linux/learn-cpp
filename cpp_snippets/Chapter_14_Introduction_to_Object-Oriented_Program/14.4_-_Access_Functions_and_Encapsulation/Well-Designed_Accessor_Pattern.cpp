#include <iostream>
#include <string>
#include <stdexcept>

class Temperature {
private:
    double m_celsius;
    
    // Private helper functions
    bool isValidCelsius(double temp) const {
        return temp >= -273.15;  // Absolute zero
    }

public:
    // Constructor with validation
    Temperature(double celsius = 0.0) {
        if (!isValidCelsius(celsius)) {
            throw std::invalid_argument("Temperature cannot be below absolute zero");
        }
        m_celsius = celsius;
    }
    
    // Read-only accessors (getters)
    double celsius() const { return m_celsius; }
    double fahrenheit() const { return (m_celsius * 9.0/5.0) + 32.0; }
    double kelvin() const { return m_celsius + 273.15; }
    
    // Mutator with validation (setter)
    void setCelsius(double temp) {
        if (!isValidCelsius(temp)) {
            throw std::invalid_argument("Invalid temperature");
        }
        m_celsius = temp;
    }
    
    void setFahrenheit(double temp) {
        double celsiusEquivalent = (temp - 32.0) * 5.0/9.0;
        setCelsius(celsiusEquivalent);  // Reuse validation
    }
    
    void setKelvin(double temp) {
        setCelsius(temp - 273.15);  // Reuse validation
    }
    
    // Utility functions
    bool isFreezing() const { return m_celsius <= 0.0; }
    bool isBoiling() const { return m_celsius >= 100.0; }
    
    std::string getState() const {
        if (m_celsius < 0.0) return "Solid (Ice)";
        if (m_celsius < 100.0) return "Liquid (Water)";
        return "Gas (Steam)";
    }
    
    void display() const {
        std::cout << "Temperature: " << m_celsius << "°C (" 
                  << fahrenheit() << "°F, " << kelvin() << "K)\n"
                  << "State: " << getState() << '\n';
    }
};

int main() {
    try {
        Temperature room{22.5};
        room.display();
        
        Temperature hot;
        hot.setFahrenheit(212.0);  // Boiling point
        hot.display();
        
        // Temperature invalid{-300.0};  // ❌ Throws exception
        
        room.setCelsius(0.0);
        std::cout << "Is freezing: " << (room.isFreezing() ? "Yes" : "No") << '\n';
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return 0;
}
