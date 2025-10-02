#include <iostream>
#include <string>

class BankAccount {
private:
    double m_balance;
    std::string m_accountNumber;

public:
    // Constructor
    BankAccount(const std::string& accountNumber, double initialBalance = 0.0)
        : m_accountNumber{accountNumber}, m_balance{initialBalance} {}
    
    // Member functions (methods) that operate on the object's data
    double getBalance() const { return m_balance; }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= m_balance) {
            m_balance -= amount;
            return true;
        }
        return false;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            m_balance += amount;
        }
    }
    
    void displayInfo() const {
        std::cout << "Account: " << m_accountNumber 
                  << ", Balance: $" << m_balance << '\n';
    }
};

int main() {
    BankAccount savings{"SAV-001", 1000.0};
    
    savings.displayInfo();           // Account: SAV-001, Balance: $1000
    savings.deposit(250.0);          // Method call on the object
    savings.withdraw(100.0);         // Object manages its own state
    savings.displayInfo();           // Account: SAV-001, Balance: $1150
    
    // savings.m_balance = -500;     // ❌ Error: private member not accessible
    
    return 0;
}
