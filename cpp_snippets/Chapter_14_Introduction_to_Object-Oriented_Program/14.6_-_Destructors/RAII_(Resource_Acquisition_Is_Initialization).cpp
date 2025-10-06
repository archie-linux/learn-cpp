#include <iostream>
#include <memory>

class DatabaseConnection {
private:
    std::string m_connectionString;
    bool m_connected;

public:
    DatabaseConnection(const std::string& connStr) 
        : m_connectionString{connStr}, m_connected{false} {
        // Acquire resource in constructor
        std::cout << "Connecting to database: " << m_connectionString << '\n';
        m_connected = true;
        std::cout << "Database connection established\n";
    }
    
    ~DatabaseConnection() {
        // Release resource in destructor
        if (m_connected) {
            std::cout << "Closing database connection: " << m_connectionString << '\n';
            m_connected = false;
        }
    }
    
    // Delete copy constructor and copy assignment to prevent copying
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
    
    void executeQuery(const std::string& query) {
        if (m_connected) {
            std::cout << "Executing query: " << query << '\n';
        } else {
            std::cout << "Error: Not connected to database\n";
        }
    }
    
    bool isConnected() const { return m_connected; }
};

class DataProcessor {
private:
    DatabaseConnection m_dbConn;

public:
    DataProcessor(const std::string& dbConnStr) : m_dbConn{dbConnStr} {
        std::cout << "DataProcessor initialized\n";
    }
    
    ~DataProcessor() {
        std::cout << "DataProcessor shutting down\n";
        // m_dbConn destructor called automatically
    }
    
    void processUserData(int userId) {
        m_dbConn.executeQuery("SELECT * FROM users WHERE id = " + std::to_string(userId));
        // Process data...
        m_dbConn.executeQuery("UPDATE users SET last_access = NOW() WHERE id = " + std::to_string(userId));
    }
};

int main() {
    std::cout << "=== Application Start ===\n";
    
    try {
        DataProcessor processor{"postgresql://localhost:5432/mydb"};
        processor.processUserData(12345);
        
        std::cout << "=== Processing Complete ===\n";
        
        // When processor goes out of scope:
        // 1. DataProcessor destructor called
        // 2. DatabaseConnection destructor called automatically
        // 3. All resources properly cleaned up
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    std::cout << "=== Application End ===\n";
    
    return 0;
}
