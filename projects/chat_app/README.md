This is a modular C++ multiplayer chat application using sockets, multithreading, JSON serialization (via nlohmann/json), and basic authentication.

- Run Server: ./server <port>
- Run Client: ./client <host> <port> <username> <password>
- Dependencies: nlohmann/json (place in include/nlohmann/)
- Features: Client-server model, concurrent connections, group chat broadcasting, error handling.

### Prompt

Multiplayer Chat Application 

Developing a chat application with networking capabilities is a fantastic way to demonstrate practical systems programming skills. 
What it shows:
Networking: Implementing a client-server model from scratch using C++ sockets, handling requests and responses over a network.
Multithreading: Managing multiple client connections and simultaneous message transfers requires concurrent programming to avoid blocking.
Error Handling: Building robust handling for network failures, disconnections, and invalid client input. 
Advanced features to implement:
Authentication: Implement a login system to manage user identity and access.
Group Chat: Extend the basic functionality to allow for multiple users to participate in a single channel.
Data Serialization: Use a format like JSON to structure and transfer messages between the server and clients.

## AI Agent: Grok
