#include <iostream>
#include <vector>
#include <string>

class Database {
private:
    // Nested class for internal use
    class Connection {
    private:
        std::string m_connectionString;
        bool m_isOpen;
        
    public:
        Connection(const std::string& connStr) : m_connectionString{connStr}, m_isOpen{false} {}
        
        bool open() {
            std::cout << "Opening database connection: " << m_connectionString << '\n';
            m_isOpen = true;
            return true;
        }
        
        void close() {
            if (m_isOpen) {
                std::cout << "Closing database connection\n";
                m_isOpen = false;
            }
        }
        
        bool execute(const std::string& query) {
            if (!m_isOpen) return false;
            std::cout << "Executing: " << query << '\n';
            return true;
        }
        
        bool isOpen() const { return m_isOpen; }
    };
    
    Connection m_connection;
    std::string m_databaseName;

public:
    Database(const std::string& dbName, const std::string& connStr)
        : m_databaseName{dbName}, m_connection{connStr} {}
    
    ~Database() {
        m_connection.close();
    }
    
    bool connect() {
        return m_connection.open();
    }
    
    bool executeQuery(const std::string& query) {
        return m_connection.execute(query);
    }
    
    bool isConnected() const {
        return m_connection.isOpen();
    }
    
    const std::string& getName() const { return m_databaseName; }
};

int main() {
    Database userDB{"UserDatabase", "postgresql://localhost:5432/users"};
    
    if (userDB.connect()) {
        userDB.executeQuery("SELECT * FROM users");
        userDB.executeQuery("UPDATE users SET last_login = NOW() WHERE id = 1");
    }
    
    // Connection automatically closed by destructor
    
    return 0;
}
