// BankAccount.h
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>

struct Transaction {
    enum Type { Deposit, Withdrawal, Transfer };
    Type type;
    double amount;
    std::string description;
    std::string timestamp;
};

class BankAccount {
private:
    std::string m_accountNumber;
    std::string m_ownerName;
    double m_balance;
    std::vector<Transaction> m_transactions;
    static double s_interestRate;

public:
    BankAccount(const std::string& accountNumber, const std::string& ownerName, 
                double initialDeposit = 0.0);
    
    // Account operations
    bool deposit(double amount, const std::string& description = "Deposit");
    bool withdraw(double amount, const std::string& description = "Withdrawal");
    bool transferTo(BankAccount& recipient, double amount, 
                   const std::string& description = "Transfer");
    
    // Interest calculation
    void applyInterest();
    static void setInterestRate(double rate) { s_interestRate = rate; }
    static double getInterestRate() { return s_interestRate; }
    
    // Account information
    double getBalance() const { return m_balance; }
    const std::string& getAccountNumber() const { return m_accountNumber; }
    const std::string& getOwnerName() const { return m_ownerName; }
    
    // Transaction history
    void displayTransactionHistory() const;
    void displayAccountSummary() const;
    
private:
    void addTransaction(Transaction::Type type, double amount, const std::string& description);
    std::string getCurrentTimestamp() const;
};

#endif
