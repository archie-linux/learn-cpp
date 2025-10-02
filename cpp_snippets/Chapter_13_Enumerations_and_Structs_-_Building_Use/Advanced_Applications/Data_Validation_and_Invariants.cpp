#include <iostream>
#include <string>
#include <stdexcept>

struct Temperature 
{
    enum class Scale { Celsius, Fahrenheit, Kelvin };
    
    double value{};
    Scale scale = Scale::Celsius;
    
    // Validation function
    bool isValid() const 
    {
        switch (scale) 
        {
            case Scale::Celsius:    return value >= -273.15;
            case Scale::Fahrenheit: return value >= -459.67;
            case Scale::Kelvin:     return value >= 0.0;
        }
        return false;
    }
    
    // Conversion functions
    Temperature toCelsius() const 
    {
        if (!isValid()) throw std::invalid_argument("Invalid temperature");
        
        switch (scale) 
        {
            case Scale::Celsius:    return *this;
            case Scale::Fahrenheit: return {(value - 32) * 5.0/9.0, Scale::Celsius};
            case Scale::Kelvin:     return {value - 273.15, Scale::Celsius};
        }
        return {};
    }
    
    void display() const 
    {
        char symbol = (scale == Scale::Celsius) ? 'C' : 
                     (scale == Scale::Fahrenheit) ? 'F' : 'K';
        std::cout << value << "°" << symbol;
    }
};

int main() 
{
    Temperature room{22.5, Temperature::Scale::Celsius};
    Temperature freezing{32.0, Temperature::Scale::Fahrenheit};
    
    std::cout << "Room temperature: ";
    room.display();
    std::cout << '\n';
    
    std::cout << "Freezing point in Fahrenheit: ";
    freezing.display();
    std::cout << " = ";
    freezing.toCelsius().display();
    std::cout << '\n';
    
    return 0;
}
