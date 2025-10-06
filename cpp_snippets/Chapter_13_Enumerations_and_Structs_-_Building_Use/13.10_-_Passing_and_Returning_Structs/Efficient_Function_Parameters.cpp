#include <iostream>
#include <string>

struct Student 
{
    std::string name;
    int id{};
    double gpa{};
    std::string major;
};

// ❌ Inefficient: copies the entire struct
void displayStudentCopy(Student s) 
{
    std::cout << s.name << " (ID: " << s.id << ", GPA: " << s.gpa << ")\n";
}

// ✅ Efficient: passes by const reference
void displayStudent(const Student& s) 
{
    std::cout << s.name << " (ID: " << s.id << ", GPA: " << s.gpa << ")\n";
}

// ✅ Modify struct through non-const reference
void updateGPA(Student& s, double newGPA) 
{
    s.gpa = newGPA;
}

// ✅ Return struct by value (modern compilers optimize this)
Student createStudent(const std::string& name, int id, double gpa, const std::string& major) 
{
    return Student{name, id, gpa, major};
}

int main() 
{
    Student alice = createStudent("Alice Johnson", 12345, 3.85, "Computer Science");
    
    displayStudent(alice);        // Efficient const reference
    
    updateGPA(alice, 3.92);       // Modify through reference
    displayStudent(alice);        // Show updated GPA
    
    return 0;
}
