#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>

// ❌ Manual resource management - error-prone
void badFileHandling() 
{
    std::cout << "\n--- Bad File Handling ---\n";
    
    FILE* file = fopen("data.txt", "w");
    if (!file) 
    {
        std::cout << "Failed to open file\n";
        return;
    }
    
    try 
    {
        // Some operation that might throw
        if (true)  // Simulate error condition
        {
            throw std::runtime_error("Something went wrong");
        }
        
        fprintf(file, "Hello, World!\n");
        fclose(file);  // This never gets called!
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
        // File handle leaked!
    }
}

// ✅ RAII with automatic cleanup
class FileRAII 
{
private:
    FILE* file;
    std::string filename;
    
public:
    FileRAII(const std::string& filename, const std::string& mode)
        : file(nullptr), filename(filename) 
    {
        file = fopen(filename.c_str(), mode.c_str());
        if (!file) 
        {
            throw std::runtime_error("Failed to open file: " + filename);
        }
        std::cout << "Opened file: " << filename << "\n";
    }
    
    ~FileRAII() 
    {
        if (file) 
        {
            fclose(file);
            std::cout << "Closed file: " << filename << "\n";
        }
    }
    
    // Delete copy constructor and assignment to prevent double-close
    FileRAII(const FileRAII&) = delete;
    FileRAII& operator=(const FileRAII&) = delete;
    
    // Move semantics for transferring ownership
    FileRAII(FileRAII&& other) noexcept 
        : file(other.file), filename(std::move(other.filename)) 
    {
        other.file = nullptr;
    }
    
    FileRAII& operator=(FileRAII&& other) noexcept 
    {
        if (this != &other) 
        {
            if (file) 
            {
                fclose(file);
            }
            
            file = other.file;
            filename = std::move(other.filename);
            other.file = nullptr;
        }
        return *this;
    }
    
    void write(const std::string& data) 
    {
        if (!file) 
        {
            throw std::runtime_error("File not open");
        }
        
        if (fprintf(file, "%s", data.c_str()) < 0) 
        {
            throw std::runtime_error("Write failed");
        }
    }
    
    operator FILE*() const { return file; }  // Allow use as FILE*
};

void goodFileHandling() 
{
    std::cout << "\n--- Good File Handling (RAII) ---\n";
    
    try 
    {
        FileRAII file("data.txt", "w");  // File automatically closed on scope exit
        
        file.write("Hello, RAII World!\n");
        
        // Simulate exception
        throw std::runtime_error("Something went wrong");
        
        file.write("This won't be reached\n");
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << "\n";
        // File automatically closed by destructor
    }
}

// ✅ Modern C++ RAII with smart pointers
class DatabaseConnection 
{
private:
    std::string connectionString;
    bool connected;
    
public:
    DatabaseConnection(const std::string& connStr) 
        : connectionString(connStr), connected(false) 
    {
        // Simulate database connection
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        connected = true;
        std::cout << "Connected to database: " << connectionString << "\n";
    }
    
    ~DatabaseConnection() 
    {
        if (connected) 
        {
            std::cout << "Disconnecting from database: " << connectionString << "\n";
        }
    }
    
    void executeQuery(const std::string& query) 
    {
        if (!connected) 
        {
            throw std::runtime_error("Not connected to database");
        }
        
        std::cout << "Executing query: " << query << "\n";
        
        // Simulate query failure
        if (query == "bad query") 
        {
            throw std::runtime_error("Query execution failed");
        }
    }
    
    bool isConnected() const { return connected; }
};

void demonstrateSmartPointerRAII() 
{
    std::cout << "\n--- Smart Pointer RAII ---\n";
    
    try 
    {
        // Automatic cleanup with unique_ptr
        auto db = std::make_unique<DatabaseConnection>("localhost:5432/mydb");
        
        db->executeQuery("SELECT * FROM users");
        db->executeQuery("bad query");  // This will throw
        
        db->executeQuery("SELECT * FROM products");  // Won't execute
    }
    catch (const std::exception& e) 
    {
        std::cout << "Database error: " << e.what() << "\n";
        // DatabaseConnection automatically destroyed
    }
}

// ✅ Lock Guard Pattern
class ThreadSafeCounter 
{
private:
    mutable std::mutex mtx;
    int count = 0;
    
public:
    void increment() 
    {
        std::lock_guard<std::mutex> lock(mtx);  // RAII lock
        ++count;
        // Lock automatically released when lock goes out of scope
    }
    
    void decrement() 
    {
        std::lock_guard<std::mutex> lock(mtx);
        --count;
    }
    
    int getValue() const 
    {
        std::lock_guard<std::mutex> lock(mtx);
        return count;
    }
    
    void riskyOperation() 
    {
        std::lock_guard<std::mutex> lock(mtx);
        
        // Even if exception is thrown, lock is released
        if (count > 100) 
        {
            throw std::runtime_error("Count too high");
        }
        
        count += 10;
    }
};

void demonstrateRAII() 
{
    std::cout << "=== RAII Demonstration ===\n";
    
    badFileHandling();
    goodFileHandling();
    demonstrateSmartPointerRAII();
    
    // Thread-safe counter example
    std::cout << "\n--- Thread-Safe Counter ---\n";
    ThreadSafeCounter counter;
    
    try 
    {
        for (int i = 0; i < 105; ++i) 
        {
            counter.increment();
        }
        
        counter.riskyOperation();  // Will throw, but mutex released properly
    }
    catch
