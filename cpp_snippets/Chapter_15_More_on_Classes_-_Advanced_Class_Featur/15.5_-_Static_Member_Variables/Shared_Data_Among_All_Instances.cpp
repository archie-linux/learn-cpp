#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    static int s_nextEmployeeId;        // Shared by all instances
    static double s_minimumWage;        // Company-wide policy
    static std::string s_companyName;   // Company information
    
    int m_employeeId;                   // Instance-specific data
    std::string m_name;
    double m_salary;
    
public:
    Employee(const std::string& name, double salary)
        : m_employeeId{s_nextEmployeeId++}, m_name{name}, m_salary{salary} {
        if (salary < s_minimumWage) {
            m_salary = s_minimumWage;
            std::cout << "Salary adjusted to minimum wage for " << m_name << '\n';
        }
    }
    
    // Static member functions - can only access static members
    static void setCompanyName(const std::string& name) {
        s_companyName = name;
    }
    
    static const std::string& getCompanyName() {
        return s_companyName;
    }
    
    static void setMinimumWage(double wage) {
        if (wage > 0) {
            s_minimumWage = wage;
            std::cout << "Minimum wage updated to $" << wage << '\n';
        }
    }
    
    static double getMinimumWage() {
        return s_minimumWage;
    }
    
    static int getNextEmployeeId() {
        return s_nextEmployeeId;
    }
    
    static int getTotalEmployees() {
        return s_nextEmployeeId - 1;
    }
    
    // Instance member functions
    int getEmployeeId() const { return m_employeeId; }
    const std::string& getName() const { return m_name; }
    double getSalary() const { return m_salary; }
    
    void setSalary(double salary) {
        if (salary >= s_minimumWage) {
            m_salary = salary;
        } else {
            std::cout << "Cannot set salary below minimum wage\n";
        }
    }
    
    void displayInfo() const {
        std::cout << "Employee #" << m_employeeId << ": " << m_name 
                  << " at " << s_companyName << " earns $" << m_salary << '\n';
    }
};

// Static member variable definitions (required outside class)
int Employee::s_nextEmployeeId = 1000;         // Start employee IDs at 1000
double Employee::s_minimumWage = 15.0;         // $15/hour minimum
std::string Employee::s_companyName = "TechCorp";

int main() {
    std::cout << "Company: " << Employee::getCompanyName() << '\n';
    std::cout << "Current minimum wage: $" << Employee::getMinimumWage() << '\n';
    std::cout << "Total employees: " << Employee::getTotalEmployees() << '\n';
    
    // Create employees
    Employee alice{"Alice Johnson", 25.0};
    Employee bob{"Bob Smith", 10.0};    // Below minimum, will be adjusted
    Employee charlie{"Charlie Brown", 30.0};
    
    alice.displayInfo();
    bob.displayInfo();
    charlie.displayInfo();
    
    std::cout << "Total employees after creation: " << Employee::getTotalEmployees() << '\n';
    
    // Update company-wide policies
    Employee::setMinimumWage(18.0);
    Employee::setCompanyName("TechCorp Solutions");
    
    // Try to set salary below new minimum
    bob.setSalary(16.0);  // Will be rejected
    bob.setSalary(20.0);  // Will be accepted
    
    bob.displayInfo();
    
    return 0;
}
