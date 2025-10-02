#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

// Base exception class for a banking application
class BankException : public std::runtime_error 
{
protected:
    std::string accountNumber;
    double amount;
    
public:
    BankException(const std::string& message, 
                  const std::string& account, 
                  double amt = 0.0)
        : std::runtime_error(message), accountNumber(account), amount(amt) {}
    
    const std::string& getAccountNumber() const { return accountNumber; }
    double getAmount() const { return amount; }
    
    virtual std::string getDetailedMessage() const 
    {
        std::ostringstream oss;
        oss << what() << " (Account: " << accountNumber;
        if (amount != 0.0) 
        {
            oss << ", Amount: $" << amount;
        }
        oss << ")";
        return oss.str();
    }
};

class InsufficientFundsException : public BankException 
{
private:
    double currentBalance;
    
public:
    InsufficientFundsException(const std::string& account, 
                              double requestedAmount, 
                              double balance)
        : BankException("Insufficient funds", account, requestedAmount)
        , currentBalance(balance) {}
    
    double getCurrentBalance() const { return currentBalance; }
    
    std::string getDetailedMessage() const override 
    {
        std::ostringstream oss;
        oss << "Insufficient funds in account " << accountNumber 
            << ": Requested $" << amount 
            << ", Available $" << currentBalance;
        return oss.str();
    }
};

class InvalidAccountException : public BankException 
{
public:
    InvalidAccountException(const std::string& account)
        : BankException("Invalid account number", account) {}
};

class NegativeAmountException : public BankException 
{
public:
    NegativeAmountException(const std::string& account, double amt)
        : BankException("Negative amount not allowed", account, amt) {}
};

// Simple bank account class
class BankAccount 
{
private:
    std::string accountNumber;
    double balance;
    
public:
    BankAccount(const std::string& account, double initialBalance)
        : accountNumber(account), balance(initialBalance) 
    {
        if (initialBalance < 0) 
        {
            throw NegativeAmountException(account, initialBalance);
        }
    }
    
    void withdraw(double amount) 
    {
        if (amount < 0) 
        {
            throw NegativeAmountException(accountNumber, amount);
        }
        
        if (amount > balance) 
        {
            throw InsufficientFundsException(accountNumber, amount, balance);
        }
        
        balance -= amount;
        std::cout << "Withdrew $" << amount << " from " << accountNumber 
                  << ". New balance: $" << balance << "\n";
    }
    
    void deposit(double amount) 
    {
        if (amount < 0) 
        {
            throw NegativeAmountException(accountNumber, amount);
        }
        
        balance += amount;
        std::cout << "Deposited $" << amount << " to " << accountNumber 
                  << ". New balance: $" << balance << "\n";
    }
    
    double getBalance() const { return balance; }
    const std::string& getAccountNumber() const { return accountNumber; }
};

void demonstrateCustomExceptions() 
{
    std::cout << "\n=== Custom Exceptions Demo ===\n";
    
    try 
    {
        BankAccount account("ACC-12345", 1000.0);
        
        account.deposit(500.0);   // Should work
        account.withdraw(200.0);  // Should work
        account.withdraw(2000.0); // Should throw InsufficientFundsException
    }
    catch (const InsufficientFundsException& e) 
    {
        std::cout << "Banking Error: " << e.getDetailedMessage() << "\n";
    }
    catch (const BankException& e) 
    {
        std::cout << "Banking Error: " << e.getDetailedMessage() << "\n";
    }
    
    try 
    {
        BankAccount badAccount("ACC-67890", -100.0);  // Should throw
    }
    catch (const NegativeAmountException& e) 
    {
        std::cout << "Account Creation Error: " << e.getDetailedMessage() << "\n";
    }
}

int main() 
{
    demonstrateStandardExceptions();
    demonstrateCustomExceptions();
    return 0;
}
