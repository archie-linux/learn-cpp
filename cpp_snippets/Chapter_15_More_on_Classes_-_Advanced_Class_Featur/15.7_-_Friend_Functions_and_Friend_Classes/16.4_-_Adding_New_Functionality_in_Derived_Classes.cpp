#include <iostream>
#include <string>
#include <vector>

// Base class for all employees
class Employee {
protected:
    std::string m_name;
    int m_employeeId;
    double m_baseSalary;

public:
    Employee(const std::string& name, int id, double baseSalary)
        : m_name{name}, m_employeeId{id}, m_baseSalary{baseSalary} {}
    
    virtual ~Employee() = default;  // Virtual destructor for proper cleanup
    
    const std::string& getName() const { return m_name; }
    int getId() const { return m_employeeId; }
    double getBaseSalary() const { return m_baseSalary; }
    
    virtual double calculatePay() const {
        return m_baseSalary;
    }
    
    virtual void displayInfo() const {
        std::cout << "Employee: " << m_name << " (ID: " << m_employeeId 
                  << ", Base: $" << m_baseSalary << ")\n";
    }
};

// Developer with additional programming skills
class Developer : public Employee {
private:
    std::vector<std::string> m_programmingLanguages;
    int m_yearsExperience;
    double m_bonusRate;

public:
    Developer(const std::string& name, int id, double baseSalary, 
              int yearsExp, double bonusRate = 0.1)
        : Employee{name, id, baseSalary}, m_yearsExperience{yearsExp}, 
          m_bonusRate{bonusRate} {}
    
    // Add new functionality
    void addProgrammingLanguage(const std::string& language) {
        m_programmingLanguages.push_back(language);
    }
    
    const std::vector<std::string>& getProgrammingLanguages() const {
        return m_programmingLanguages;
    }
    
    int getYearsExperience() const { return m_yearsExperience; }
    
    // Override base class methods with enhanced functionality
    double calculatePay() const override {
        double experienceBonus = m_yearsExperience * 1000.0;
        double languageBonus = m_programmingLanguages.size() * 500.0;
        return m_baseSalary + experienceBonus + languageBonus;
    }
    
    void displayInfo() const override {
        std::cout << "Developer: " << m_name << " (ID: " << m_employeeId << ")\n";
        std::cout << "  Base Salary: $" << m_baseSalary << '\n';
        std::cout << "  Experience: " << m_yearsExperience << " years\n";
        std::cout << "  Languages: ";
        for (size_t i = 0; i < m_programmingLanguages.size(); ++i) {
            std::cout << m_programmingLanguages[i];
            if (i < m_programmingLanguages.size() - 1) std::cout << ", ";
        }
        std::cout << "\n  Total Pay: $" << calculatePay() << '\n';
    }
    
    // New methods specific to developers
    void codeReview() const {
        std::cout << m_name << " is conducting a code review\n";
    }
    
    void debugCode() const {
        std::cout << m_name << " is debugging code\n";
    }
};

// Manager with team management capabilities
class Manager : public Employee {
private:
    std::vector<Employee*> m_team;
    double m_teamBonusRate;

public:
    Manager(const std::string& name, int id, double baseSalary, double teamBonusRate = 0.05)
        : Employee{name, id, baseSalary}, m_teamBonusRate{teamBonusRate} {}
    
    // Team management functionality
    void addTeamMember(Employee* employee) {
        m_team.push_back(employee);
    }
    
    void removeTeamMember(int employeeId) {
        m_team.erase(
            std::remove_if(m_team.begin(), m_team.end(),
                [employeeId](Employee* emp) { return emp->getId() == employeeId; }),
            m_team.end()
        );
    }
    
    size_t getTeamSize() const { return m_team.size(); }
    
    const std::vector<Employee*>& getTeam() const { return m_team; }
    
    // Override with team-based bonus calculation
    double calculatePay() const override {
        double teamBonus = m_team.size() * 2000.0 * m_teamBonusRate;
        return m_baseSalary + teamBonus;
    }
    
    void displayInfo() const override {
        std::cout << "Manager: " << m_name << " (ID: " << m_employeeId << ")\n";
        std::cout << "  Base Salary: $" << m_baseSalary << '\n';
        std::cout << "  Team Size: " << m_team.size() << " members\n";
        std::cout << "  Total Pay: $" << calculatePay() << '\n';
    }
    
    // Manager-specific methods
    void conductMeeting() const {
        std::cout << m_name << " is conducting a team meeting with " 
                  << m_team.size() << " members\n";
    }
    
    void reviewPerformance(Employee* employee) const {
        std::cout << m_name << " is reviewing performance of " 
                  << employee->getName() << '\n';
    }
    
    void displayTeam() const {
        std::cout << "Team managed by " << m_name << ":\n";
        for (const Employee* emp : m_team) {
            std::cout << "  - " << emp->getName() << " (ID: " << emp->getId() << ")\n";
        }
    }
};

int main() {
    // Create different types of employees
    Developer alice{"Alice Johnson", 1001, 75000, 5, 0.15};
    alice.addProgrammingLanguage("C++");
    alice.addProgrammingLanguage("Python");
    alice.addProgrammingLanguage("JavaScript");
    
    Developer bob{"Bob Smith", 1002, 70000, 3};
    bob.addProgrammingLanguage("Java");
    bob.addProgrammingLanguage("C#");
    
    Manager charlie{"Charlie Brown", 2001, 90000, 0.08};
    
    // Build team relationship
    charlie.addTeamMember(&alice);
    charlie.addTeamMember(&bob);
    
    std::cout << "=== Employee Information ===\n";
    alice.displayInfo();
    std::cout << '\n';
    bob.displayInfo();
    std::cout << '\n';
    charlie.displayInfo();
    
    std::cout << "\n=== Demonstrating additional functionality ===\n";
    alice.codeReview();
    alice.debugCode();
    
    charlie.conductMeeting();
    charlie.reviewPerformance(&alice);
    charlie.displayTeam();
    
    return 0;
}
