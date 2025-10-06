#include <iostream>
#include <string>

class Student {
private:
    // Data members (member variables)
    std::string m_name;
    int m_id;
    double m_gpa;
    static int s_totalStudents;  // Static member - shared by all instances

public:
    // Member functions (methods)
    Student(const std::string& name, int id, double gpa = 0.0);  // Constructor
    ~Student();  // Destructor
    
    // Accessor functions (getters)
    const std::string& getName() const { return m_name; }
    int getId() const { return m_id; }
    double getGpa() const { return m_gpa; }
    
    // Mutator functions (setters)
    void setName(const std::string& name) { m_name = name; }
    void setGpa(double gpa) { 
        if (gpa >= 0.0 && gpa <= 4.0) {
            m_gpa = gpa; 
        }
    }
    
    // Utility functions
    void displayInfo() const;
    bool isHonorStudent() const { return m_gpa >= 3.5; }
    
    // Static member function
    static int getTotalStudents() { return s_totalStudents; }
};

// Static member definition (outside class)
int Student::s_totalStudents = 0;

// Constructor implementation
Student::Student(const std::string& name, int id, double gpa)
    : m_name{name}, m_id{id}, m_gpa{gpa} {
    ++s_totalStudents;
    std::cout << "Student " << m_name << " created\n";
}

// Destructor implementation  
Student::~Student() {
    --s_totalStudents;
    std::cout << "Student " << m_name << " destroyed\n";
}

// Member function implementation
void Student::displayInfo() const {
    std::cout << "Name: " << m_name << ", ID: " << m_id 
              << ", GPA: " << m_gpa << '\n';
}

int main() {
    std::cout << "Total students: " << Student::getTotalStudents() << '\n';
    
    Student alice{"Alice Johnson", 12345, 3.85};
    Student bob{"Bob Smith", 54321, 2.95};
    
    std::cout << "Total students: " << Student::getTotalStudents() << '\n';
    
    alice.displayInfo();
    std::cout << alice.getName() << " is " 
              << (alice.isHonorStudent() ? "" : "not ") 
              << "an honor student\n";
    
    return 0;
}
