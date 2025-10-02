// Procedural approach - data and functions are separate
struct BankAccount {
    double balance;
    std::string accountNumber;
};

// Functions operate on the data externally
double getBalance(const BankAccount& account) {
    return account.balance;
}

bool withdraw(BankAccount& account, double amount) {
    if (amount <= account.balance) {
        account.balance -= amount;
        return true;
    }
    return false;
}

void deposit(BankAccount& account, double amount) {
    account.balance += amount;
}
