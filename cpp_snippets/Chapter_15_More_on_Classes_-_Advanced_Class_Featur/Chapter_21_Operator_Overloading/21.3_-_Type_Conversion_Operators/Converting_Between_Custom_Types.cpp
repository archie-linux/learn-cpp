#include <iostream>
#include <string>

class Temperature 
{
private:
    double celsius;
    
public:
    explicit Temperature(double c = 0.0) : celsius(c) {}
    
    // Conversion to double (returns Celsius)
    operator double() const 
    {
        return celsius;
    }
    
    // Conversion to int (returns rounded Celsius)
    operator int() const 
    {
        return static_cast<int>(celsius + 0.5);
    }
    
    // Explicit conversion to Fahrenheit
    double toFahrenheit() const 
    {
        return celsius * 9.0 / 5.0 + 32.0;
    }
    
    double getCelsius() const { return celsius; }
    
    friend std::ostream& operator<<(std::ostream& out, const Temperature& temp) 
    {
        out << temp.celsius << "°C";
        return out;
    }
};

class Distance 
{
private:
    double meters;
    
public:
    explicit Distance(double m = 0.0) : meters(m) {}
    
    // Constructor for conversion from feet
    Distance(double feet, bool fromFeet) : meters(fromFeet ? feet * 0.3048 : feet) {}
    
    // Implicit conversion to double (returns meters)
    operator double() const 
    {
        return meters;
    }
    
    // Explicit conversion to feet
    explicit operator double() const 
    {
        return meters / 0.3048;
    }
    
    double toFeet() const 
    {
        return meters / 0.3048;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Distance& dist) 
    {
        out << dist.meters << "m";
        return out;
    }
};

int main() 
{
    Temperature temp(25.7);
    std::cout << "Temperature: " << temp << '\n';
    std::cout << "As double: " << static_cast<double>(temp) << '\n';
    std::cout << "As int: " << static_cast<int>(temp) << '\n';
    std::cout << "In Fahrenheit: " << temp.toFahrenheit() << "°F\n";
    
    Distance dist(100.0);  // 100 meters
    std::cout << "Distance: " << dist << '\n';
    std::cout << "In feet: " << dist.toFeet() << " ft\n";
    
    // Implicit conversion in arithmetic
    double totalMeters = dist + 50.5;  // dist converts to double
    std::cout << "Total meters: " << totalMeters << '\n';
    
    return 0;
}
