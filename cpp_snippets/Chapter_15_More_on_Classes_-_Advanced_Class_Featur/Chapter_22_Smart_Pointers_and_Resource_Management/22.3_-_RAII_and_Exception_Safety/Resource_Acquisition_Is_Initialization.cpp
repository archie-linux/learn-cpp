#include <iostream>
#include <memory>
#include <fstream>
#include <mutex>
#include <thread>
#include <vector>

// RAII wrapper for mutex locking
class LockGuard 
{
private:
    std::mutex& mtx;
    
public:
    explicit LockGuard(std::mutex& m) : mtx(m) 
    {
        mtx.lock();
        std::cout << "Mutex locked\n";
    }
    
    ~LockGuard() 
    {
        mtx.unlock();
        std::cout << "Mutex unlocked\n";
    }
    
    // Non-copyable
    LockGuard(const LockGuard&) = delete;
    LockGuard& operator=(const LockGuard&) = delete;
};

// Exception-safe resource management
class DatabaseConnection 
{
private:
    bool connected;
    std::string connectionString;
    
public:
    explicit DatabaseConnection(const std::string& connStr) 
        : connected(false), connectionString(connStr) 
    {
        // Simulate connection
        std::cout << "Connecting to database: " << connectionString << '\n';
        connected = true;
    }
    
    ~DatabaseConnection() 
    {
        if (connected) 
        {
            std::cout << "Disconnecting from database\n";
            connected = false;
        }
    }
    
    void query(const std::string& sql) 
    {
        if (!connected) throw std::runtime_error("Not connected");
        std::cout << "Executing query: " << sql << '\n';
    }
    
    // Non-copyable
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
    
    // Movable
    DatabaseConnection(DatabaseConnection&& other) noexcept 
        : connected(other.connected), connectionString(std::move(other.connectionString)) 
    {
        other.connected = false;
    }
};

class ExceptionSafeOperations 
{
private:
    std::mutex dataMutex;
    std::vector<int> data;
    
public:
    void riskyOperation() 
    {
        std::cout << "\n=== Exception Safety Demo ===\n";
        
        try 
        {
            // RAII ensures cleanup even if 
          exceptions occur
            auto dbConn = std::make_unique<DatabaseConnection>("postgresql://localhost:5432/mydb");
            LockGuard lock(dataMutex);  // Automatic unlocking
            
            dbConn->query("SELECT * FROM users");
            
            // Simulate exception
            if (true) 
            {
                throw std::runtime_error("Database error occurred");
            }
            
            dbConn->query("UPDATE users SET active = true");
            
        }
        catch (const std::exception& e) 
        {
            std::cout << "Exception caught: " << e.what() << '\n';
            std::cout << "Resources automatically cleaned up!\n";
        }
        // mutex automatically unlocked, database connection closed
    }
    
    void strongExceptionSafety() 
    {
        std::cout << "\n=== Strong Exception Safety ===\n";
        
        std::vector<int> backup = data;  // Save current state
        
        try 
        {
            // Perform operations that might throw
            data.push_back(1);
            data.push_back(2);
            
            // Simulate failure
            throw std::runtime_error("Operation failed");
            
            data.push_back(3);  // This won't execute
        }
        catch (const std::exception& e) 
        {
            // Restore to previous state (strong exception safety)
            data = backup;
            std::cout << "Exception: " << e.what() << '\n';
            std::cout << "Data restored to previous state\n";
        }
    }
};
