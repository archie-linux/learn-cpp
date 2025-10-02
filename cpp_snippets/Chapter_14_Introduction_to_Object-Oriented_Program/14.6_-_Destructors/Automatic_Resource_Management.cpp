#include <iostream>
#include <string>

class FileHandler {
private:
    std::string m_filename;
    bool m_isOpen;

public:
    // Constructor
    FileHandler(const std::string& filename) : m_filename{filename}, m_isOpen{false} {
        std::cout << "FileHandler created for: " << m_filename << '\n';
        // In real implementation, would open file here
        m_isOpen = true;
        std::cout << "File opened: " << m_filename << '\n';
    }
    
    // Destructor - called automatically when object goes out of scope
    ~FileHandler() {
        std::cout << "FileHandler destructor called for: " << m_filename << '\n';
        if (m_isOpen) {
            // In real implementation, would close file here
            std::cout << "File closed: " << m_filename << '\n';
            m_isOpen = false;
        }
        std::cout << "FileHandler destroyed\n";
    }
    
    void writeData(const std::string& data) {
        if (m_isOpen) {
            std::cout << "Writing to " << m_filename << ": " << data << '\n';
        }
    }
    
    bool isOpen() const { return m_isOpen; }
};

void processFiles() {
    std::cout << "=== Entering processFiles() ===\n";
    
    FileHandler config{"config.txt"};      // Constructor called
    FileHandler log{"application.log"};    // Constructor called
    
    config.writeData("server_port=8080");
    log.writeData("Application started");
    
    std::cout << "=== Leaving processFiles() ===\n";
    // Destructors called automatically as objects go out of scope
    // Order: log destroyed first (LIFO), then config
}

int main() {
    std::cout << "=== Main function start ===\n";
    
    processFiles();  // Objects created and destroyed within this function
    
    std::cout << "=== Back in main ===\n";
    
    {
        std::cout << "--- Entering block scope ---\n";
        FileHandler temp{"temp.dat"};
        temp.writeData("temporary data");
        std::cout << "--- Leaving block scope ---\n";
        // temp destructor called here
    }
    
    std::cout << "=== Main function end ===\n";
    
    return 0;
}
