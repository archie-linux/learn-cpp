#include <iostream>
#include <string>

class SecureVault {
private:
    std::string m_contents;
    std::string m_passcode;
    bool m_isLocked;
    int m_failedAttempts;
    static constexpr int MAX_ATTEMPTS = 3;

public:
    SecureVault(const std::string& passcode) 
        : m_passcode{passcode}, m_isLocked{true}, m_failedAttempts{0} {}
    
    bool unlock(const std::string& attempt) {
        if (m_failedAttempts >= MAX_ATTEMPTS) {
            std::cout << "Vault permanently locked due to too many failed attempts!\n";
            return false;
        }
        
        if (attempt == m_passcode) {
            m_isLocked = false;
            m_failedAttempts = 0;  // Reset on successful unlock
            std::cout << "Vault unlocked!\n";
            return true;
        } else {
            ++m_failedAttempts;
            std::cout << "Wrong passcode! Attempts remaining: " 
                      << (MAX_ATTEMPTS - m_failedAttempts) << '\n';
            return false;
        }
    }
    
    void lock() {
        m_isLocked = true;
        std::cout << "Vault locked\n";
    }
    
    bool storeItem(const std::string& item) {
        if (m_isLocked) {
            std::cout << "Cannot store item: vault is locked\n";
            return false;
        }
        m_contents = item;
        std::cout << "Item stored successfully\n";
        return true;
    }
    
    std::string retrieveContents() {
        if (m_isLocked) {
            std::cout << "Cannot retrieve: vault is locked\n";
            return "";
        }
        return m_contents;
    }
    
    bool isLocked() const { return m_isLocked; }
};

int main() {
    SecureVault myVault{"secret123"};
    
    // myVault.m_passcode = "hacked";  // ❌ Error: private member
    
    myVault.storeItem("Gold coins");     // Cannot store: vault is locked
    
    myVault.unlock("wrong");             // Wrong passcode! Attempts remaining: 2
    myVault.unlock("alsowrong");         // Wrong passcode! Attempts remaining: 1
    myVault.unlock("secret123");         // Vault unlocked!
    
    myVault.storeItem("Gold coins");     // Item stored successfully
    std::cout << "Retrieved: " << myVault.retrieveContents() << '\n';
    
    myVault.lock();
    
    return 0;
}
