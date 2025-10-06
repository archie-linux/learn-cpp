#include <iostream>

class Fraction 
{
private:
    int numerator;
    int denominator;
    
    // Helper function to find GCD
    int gcd(int a, int b) const 
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
    
    // Helper function to reduce fraction
    void reduce() 
    {
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
        
        // Keep denominator positive
        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    
public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) 
    {
        if (denominator == 0) 
        {
            throw std::runtime_error("Denominator cannot be zero");
        }
        reduce();
    }
    
    // Arithmetic operators
    Fraction operator+(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                       denominator * other.denominator);
    }
    
    Fraction operator-(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                       denominator * other.denominator);
    }
    
    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    
    Fraction operator/(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    
    // Comparison operators
    bool operator==(const Fraction& other) const 
    {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }
    
    bool operator!=(const Fraction& other) const 
    {
        return !(*this == other);
    }
    
    bool operator<(const Fraction& other) const 
    {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }
    
    // Unary operators
    Fraction operator-() const 
    {
        return Fraction(-numerator, denominator);
    }
    
    // Compound assignment operators
    Fraction& operator+=(const Fraction& other) 
    {
        *this = *this + other;
        return *this;
    }
    
    // Stream operators (as friend functions)
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

// Stream output operator
std::ostream& operator<<(std::ostream& out, const Fraction& fraction) 
{
    if (fraction.denominator == 1) 
    {
        out << fraction.numerator;
    }
    else 
    {
        out << fraction.numerator << '/' << fraction.denominator;
    }
    return out;
}

// Stream input operator
std::istream& operator>>(std::istream& in, Fraction& fraction) 
{
    int num, den = 1;
    in >> num;
    
    if (in.peek() == '/') 
    {
        in.ignore();  // Skip the '/'
        in >> den;
    }
    
    fraction = Fraction(num, den);
    return in;
}

int main() 
{
    Fraction f1(1, 2);    // 1/2
    Fraction f2(3, 4);    // 3/4
    Fraction f3(2, 3);    // 2/3
    
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    
    // Arithmetic operations
    std::cout << "f1 + f2 = " << (f1 + f2) << '\n';    // 10/8 = 5/4
    std::cout << "f2 - f1 = " << (f2 - f1) << '\n';    // 2/8 = 1/4
    std::cout << "f1 * f3 = " << (f1 * f3) << '\n';    // 2/6 = 1/3
    std::cout << "f2 / f3 = " << (f2 / f3) << '\n';    // 9/8
    
    // Comparison operations
    std::cout << "f1 == f2: " << (f1 == f2) << '\n';
    std::cout << "f1 < f2: " << (f1 < f2) << '\n';
    
    // Compound assignment
    f1 += f2;
    std::cout << "f1 after += f2: " << f1 << '\n';
    
    return 0;
}
