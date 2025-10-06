#include <iostream>
#include <string>
#include <vector>

class NetworkConnection {
public:
    // Nested enumeration - scoped to the class
    enum class Protocol { TCP, UDP, HTTP, HTTPS };
    enum class Status { Disconnected, Connecting, Connected, Error };
    
    // Nested type alias
    using Port = unsigned short;
    using Address = std::string;
    
private:
    Address m_serverAddress;
    Port m_port;
    Protocol m_protocol;
    Status m_status;

public:
    NetworkConnection(const Address& address, Port port, Protocol protocol)
        : m_serverAddress{address}, m_port{port}, m_protocol{protocol}, m_status{Status::Disconnected} {}
    
    bool connect() {
        m_status = Status::Connecting;
        std::cout << "Connecting to " << m_serverAddress << ":" << m_port;
        std::cout << " using " << protocolToString(m_protocol) << '\n';
        
        // Simulate connection logic
        m_status = Status::Connected;
        return true;
    }
    
    void disconnect() {
        if (m_status == Status::Connected) {
            m_status = Status::Disconnected;
            std::cout << "Disconnected from server\n";
        }
    }
    
    Status getStatus() const { return m_status; }
    Protocol getProtocol() const { return m_protocol; }
    
private:
    std::string protocolToString(Protocol protocol) const {
        switch (protocol) {
            case Protocol::TCP:   return "TCP";
            case Protocol::UDP:   return "UDP";
            case Protocol::HTTP:  return "HTTP";
            case Protocol::HTTPS: return "HTTPS";
            default: return "Unknown";
        }
    }
};

int main() {
    // Use nested types with scope resolution
    NetworkConnection conn{"192.168.1.1", 8080, NetworkConnection::Protocol::HTTP};
    
    conn.connect();
    
    if (conn.getStatus() == NetworkConnection::Status::Connected) {
        std::cout << "Connection successful!\n";
    }
    
    conn.disconnect();
    
    return 0;
}
