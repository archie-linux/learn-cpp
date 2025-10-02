#include <iostream>
#include <string>
#include <vector>

struct Address 
{
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;
};

struct Person 
{
    std::string firstName;
    std::string lastName;
    Address address;           // Nested struct
    std::vector<std::string> phoneNumbers;
    
    // Member function
    std::string fullName() const 
    {
        return firstName + " " + lastName;
    }
    
    void displayInfo() const 
    {
        std::cout << "Name: " << fullName() << '\n';
        std::cout << "Address: " << address.street << ", " 
                  << address.city << ", " << address.state << " " << address.zipCode << '\n';
        std::cout << "Phone numbers: ";
        for (const auto& phone : phoneNumbers) 
        {
            std::cout << phone << " ";
        }
        std::cout << '\n';
    }
};

int main() 
{
    Person john {
        .firstName = "John",
        .lastName = "Doe", 
        .address = {
            .street = "123 Main St",
            .city = "Springfield",
            .state = "IL",
            .zipCode = "62701"
        },
        .phoneNumbers = {"555-1234", "555-5678"}
    };
    
    john.displayInfo();
    
    return 0;
}
