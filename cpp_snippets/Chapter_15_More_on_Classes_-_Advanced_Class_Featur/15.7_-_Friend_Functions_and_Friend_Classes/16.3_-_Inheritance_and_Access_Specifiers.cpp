#include <iostream>
#include <string>

class BaseClass {
public:
    int m_publicMember = 1;

protected:
    int m_protectedMember = 2;

private:
    int m_privateMember = 3;

public:
    void publicFunction() {
        std::cout << "Base public function\n";
        // Can access all members within the class
        std::cout << "Public: " << m_publicMember << '\n';
        std::cout << "Protected: " << m_protectedMember << '\n';
        std::cout << "Private: " << m_privateMember << '\n';
    }

protected:
    void protectedFunction() {
        std::cout << "Base protected function\n";
    }

private:
    void privateFunction() {
        std::cout << "Base private function\n";
    }
};

// Public inheritance: maintains access levels
class PublicDerived : public BaseClass {
public:
    void testAccess() {
        std::cout << "=== Public Inheritance Access ===\n";
        
        // ✅ Can access public members
        m_publicMember = 10;
        publicFunction();
        
        // ✅ Can access protected members
        m_protectedMember = 20;
        protectedFunction();
        
        // ❌ Cannot access private members
        // m_privateMember = 30;     // Error
        // privateFunction();        // Error
        
        std::cout << "Public: " << m_publicMember << '\n';
        std::cout << "Protected: " << m_protectedMember << '\n';
    }
};

// Protected inheritance: public becomes protected
class ProtectedDerived : protected BaseClass {
public:
    void testAccess() {
        std::cout << "=== Protected Inheritance Access ===\n";
        
        // ✅ Can access public members (now protected in derived)
        m_publicMember = 100;
        publicFunction();
        
        // ✅ Can access protected members
        m_protectedMember = 200;
        protectedFunction();
        
        std::cout << "Public (now protected): " << m_publicMember << '\n';
        std::cout << "Protected: " << m_protectedMember << '\n';
    }
};

// Private inheritance: public and protected become private
class PrivateDerived : private BaseClass {
public:
    void testAccess() {
        std::cout << "=== Private Inheritance Access ===\n";
        
        // ✅ Can access public members (now private in derived)
        m_publicMember = 1000;
        publicFunction();
        
        // ✅ Can access protected members (now private in derived)
        m_protectedMember = 2000;
        protectedFunction();
        
        std::cout << "Public (now private): " << m_publicMember << '\n';
        std::cout << "Protected (now private): " << m_protectedMember << '\n';
    }
    
    // Expose base functionality through wrapper
    void callBasePublicFunction() {
        publicFunction();  // Can access internally
    }
};

int main() {
    PublicDerived pubDerived;
    pubDerived.testAccess();
    pubDerived.publicFunction();  // ✅ Still public
    // pubDerived.protectedFunction();  // ❌ Error: protected
    
    std::cout << '\n';
    
    ProtectedDerived protDerived;
    protDerived.testAccess();
    // protDerived.publicFunction();  // ❌ Error: now protected
    
    std::cout << '\n';
    
    PrivateDerived privDerived;
    privDerived.testAccess();
    // privDerived.publicFunction();  // ❌ Error: now private
    privDerived.callBasePublicFunction();  // ✅ Wrapped access
    
    return 0;
}
