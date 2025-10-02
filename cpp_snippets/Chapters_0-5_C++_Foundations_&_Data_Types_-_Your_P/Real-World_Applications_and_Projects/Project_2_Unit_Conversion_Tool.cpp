#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << "Universal Unit Conversion Tool\n";
    std::cout << "==============================\n";
    
    bool continueConverting = true;
    
    while (continueConverting) 
    {
        std::cout << "\nConversion Categories:\n";
        std::cout << "1. Length (meters, feet, inches)\n";
        std::cout << "2. Weight (kg, pounds, ounces)\n";
        std::cout << "3. Temperature (Celsius, Fahrenheit, Kelvin)\n";
        std::cout << "4. Currency (simple USD/EUR example)\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose category: ";
        
        int category;
        std::cin >> category;
        
        if (category == 5) 
        {
            continueConverting = false;
            continue;
        }
        
        double value;
        std::cout << "Enter value to convert: ";
        std::cin >> value;
        
        std::cout << std::fixed << std::setprecision(2);
        
        switch (category) 
        {
            case 1: // Length
                std::cout << "\nLength Conversions for " << value << ":\n";
                std::cout << "Meters: " << value << " m\n";
                std::cout << "Feet: " << (value * 3.28084) << " ft\n";
                std::cout << "Inches: " << (value * 39.3701) << " in\n";
                std::cout << "Centimeters: " << (value * 100) << " cm\n";
                std::cout << "Kilometers: " << (value / 1000) << " km\n";
                break;
                
            case 2: // Weight
                std::cout << "\nWeight Conversions for " << value << " kg:\n";
                std::cout << "Kilograms: " << value << " kg\n";
                std::cout << "Pounds: " << (value * 2.20462) << " lbs\n";
                std::cout << "Ounces: " << (value * 35.274) << " oz\n";
                std::cout << "Grams: " << (value * 1000) << " g\n";
                break;
                
            case 3: // Temperature
                std::cout << "\nTemperature Conversions for " << value << "°C:\n";
                std::cout << "Celsius: " << value << "°C\n";
                std::cout << "Fahrenheit: " << ((value * 9.0/5.0) + 32) << "°F\n";
                std::cout << "Kelvin: " << (value + 273.15) << "K\n";
                break;
                
            case 4: // Currency (example rates)
                std::cout << "\nCurrency Conversions for $" << value << " USD:\n";
                std::cout << "USD: $" << value << '\n';
                std::cout << "EUR: €" << (value * 0.85) << " (example rate)\n";
                std::cout << "GBP: £" << (value * 0.73) << " (example rate)\n";
                std::cout << "JPY: ¥" << (value * 110) << " (example rate)\n";
                break;
                
            default:
                std::cout << "Invalid category!\n";
        }
        
        char again;
        std::cout << "\nConvert another value? (y/n): ";
        std::cin >> again;
        if (again != 'y' && again != 'Y') 
        {
            continueConverting = false;
        }
    }
    
    std::cout << "Thank you for using the Unit Conversion Tool!\n";
    return 0;
}
