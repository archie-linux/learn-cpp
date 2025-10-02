#include <iostream>
#include <cmath>

// Function returning a value
int add(int a, int b) 
{
    return a + b;
}

double calculateCircleArea(double radius) 
{
    return M_PI * radius * radius;
}

bool isEven(int number) 
{
    return (number % 2) == 0;
}

// Function with multiple return paths
std::string getGrade(int score) 
{
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}

int main() 
{
    // Using return values
    int sum = add(15, 25);
    std::cout << "Sum: " << sum << '\n';
    
    double area = calculateCircleArea(5.0);
    std::cout << "Circle area: " << area << '\n';
    
    int testNumber = 42;
    if (isEven(testNumber)) 
    {
        std::cout << testNumber << " is even\n";
    } 
    else 
    {
        std::cout << testNumber << " is odd\n";
    }
    
    int studentScore = 87;
    std::cout << "Grade for " << studentScore << ": " << getGrade(studentScore) << '\n';
    
    return 0;
}
