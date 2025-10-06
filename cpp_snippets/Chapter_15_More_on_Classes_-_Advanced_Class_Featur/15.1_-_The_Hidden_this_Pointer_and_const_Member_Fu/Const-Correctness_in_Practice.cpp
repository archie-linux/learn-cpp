#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string m_name;
    std::vector<int> m_grades;
    mutable int m_accessCount;  // mutable allows modification in const functions

public:
    Student(const std::string& name) : m_name{name}, m_accessCount{0} {}
    
    // const member functions - promise not to modify object state
    const std::string& getName() const {
        ++m_accessCount;  // ✅ mutable member can be modified
        return m_name;
    }
    
    double getAverageGrade() const {
        if (m_grades.empty()) return 0.0;
        
        int sum = 0;
        for (int grade : m_grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / m_grades.size();
    }
    
    size_t getGradeCount() const { return m_grades.size(); }
    
    int getAccessCount() const { return m_accessCount; }
    
    // non-const member functions - can modify object state
    void addGrade(int grade) {
        if (grade >= 0 && grade <= 100) {
            m_grades.push_back(grade);
        }
    }
    
    void setName(const std::string& name) {
        m_name = name;
    }
    
    // const and non-const overloads
    const std::vector<int>& getGrades() const {
        std::cout << "const version called\n";
        return m_grades;
    }
    
    std::vector<int>& getGrades() {
        std::cout << "non-const version called\n";
        return m_grades;
    }
};

void processStudent(const Student& student) {  // const reference parameter
    std::cout << "Processing student: " << student.getName() << '\n';
    std::cout << "Average grade: " << student.getAverageGrade() << '\n';
    // student.addGrade(95);  // ❌ Error: const object, non-const function
}

int main() {
    Student alice{"Alice"};
    alice.addGrade(85);
    alice.addGrade(92);
    alice.addGrade(78);
    
    processStudent(alice);  // Calls const member functions
    
    // Demonstrate const vs non-const overloads
    const Student& constRef = alice;
    constRef.getGrades();   // Calls const version
    alice.getGrades();      // Calls non-const version
    
    std::cout << "Access count: " << alice.getAccessCount() << '\n';
    
    return 0;
}
