// client.cpp (Client implementation)
#include <iostream>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "message.h"
#include "network_utils.h"
#include "utils.h"

int client_sock = -1;

void receive_loop() {
    while (true) {
        std::string data = receive_data(client_sock);
        if (data.empty()) {
            std::cout << "Disconnected from server" << std::endl;
            break;
        }

        Message msg = Message::deserialize(data);
        if (msg.type == "message") {
            std::cout << msg.username << ": " << msg.content << std::endl;
        } else if (msg.type == "info") {
            std::cout << "[INFO] " << msg.content << std::endl;
        } else if (msg.type == "error") {
            std::cout << "[ERROR] " << msg.content << std::endl;
            break;
        } else if (msg.type == "success") {
            std::cout << "[SUCCESS] " << msg.content << std::endl;
        }
    }
    close(client_sock);
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <host> <port> <username> <password>" << std::endl;
        return 1;
    }

    std::string host = argv[1];
    int port = std::stoi(argv[2]);
    std::string username = argv[3];
    std::string password = argv[4];

    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        log_error("Socket creation failed");
        return 1;
    }

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host.c_str(), &addr.sin_addr) <= 0) {
        log_error("Invalid address");
        close(client_sock);
        return 1;
    }

    if (connect(client_sock, (sockaddr*)&addr, sizeof(addr)) == -1) {
        log_error("Connection failed");
        close(client_sock);
        return 1;
    }

    // Send login
    Message login_msg{"login", username, password};
    if (!send_data(client_sock, login_msg.serialize())) {
        log_error("Send login failed");
        close(client_sock);
        return 1;
    }

    // Receive response
    std::string resp = receive_data(client_sock);
    if (resp.empty()) {
        log_error("No response from server");
        close(client_sock);
        return 1;
    }

    Message resp_msg = Message::deserialize(resp);
    if (resp_msg.type == "error") {
        std::cout << "Login failed: " << resp_msg.content << std::endl;
        close(client_sock);
        return 1;
    }

    std::cout << "Logged in successfully" << std::endl;

    // Start receive thread
    std::thread(receive_loop).detach();

    // Send messages from stdin
    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "/quit") {
            send_data(client_sock, Message{"logout", username, ""}.serialize());
            break;
        }
        send_data(client_sock, Message{"message", username, input}.serialize());
    }

    close(client_sock);
    return 0;
}
