#include <iostream>
#include <string>

struct Car 
{
    std::string brand;
    std::string model;
    int year{};
    double price{};
    bool isElectric{};
};

int main() 
{
    // C++20 designated initializers
    Car tesla {
        .brand = "Tesla",
        .model = "Model 3",
        .year = 2023,
        .price = 35000.0,
        .isElectric = true
    };
    
    Car honda {
        .brand = "Honda",
        .model = "Civic",
        .year = 2022,
        .price = 23000.0
        // isElectric defaults to false
    };
    
    std::cout << tesla.brand << " " << tesla.model << " (" << tesla.year << ")\n";
    std::cout << "Electric: " << (tesla.isElectric ? "Yes" : "No") << "\n";
    
    return 0;
}
