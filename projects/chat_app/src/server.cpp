// server.cpp (Server implementation)
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "auth.h"
#include "message.h"
#include "network_utils.h"
#include "utils.h"

std::vector<int> clients;
std::mutex clients_mutex;
Auth auth;

void broadcast(const std::string& serialized_msg) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (auto it = clients.begin(); it != clients.end(); ) {
        if (!send_data(*it, serialized_msg)) {
            close(*it);
            it = clients.erase(it);
        } else {
            ++it;
        }
    }
}

void handle_client(int client_sock) {
    std::string data = receive_data(client_sock);
    if (data.empty()) {
        close(client_sock);
        return;
    }

    Message msg = Message::deserialize(data);
    if (msg.type != "login") {
        send_data(client_sock, Message{"error", "", "Must login first"}.serialize());
        close(client_sock);
        return;
    }

    if (!auth.authenticate(msg.username, msg.content)) {
        send_data(client_sock, Message{"error", "", "Authentication failed"}.serialize());
        close(client_sock);
        return;
    }

    // Add to clients
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        clients.push_back(client_sock);
    }

    // Send welcome
    send_data(client_sock, Message{"success", "", "Logged in"}.serialize());

    // Broadcast join message
    broadcast(Message{"info", "", msg.username + " has joined the chat"}.serialize());

    while (true) {
        data = receive_data(client_sock);
        if (data.empty()) {
            break;
        }

        msg = Message::deserialize(data);
        if (msg.type == "logout") {
            break;
        } else if (msg.type == "message") {
            broadcast(Message{"message", msg.username, msg.content}.serialize());
        } else {
            send_data(client_sock, Message{"error", "", "Invalid message type"}.serialize());
        }
    }

    // Remove from clients
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        auto it = std::find(clients.begin(), clients.end(), client_sock);
        if (it != clients.end()) {
            clients.erase(it);
        }
    }

    // Broadcast leave message
    broadcast(Message{"info", "", msg.username + " has left the chat"}.serialize());

    close(client_sock);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    int port = std::stoi(argv[1]);

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        log_error("Socket creation failed");
        return 1;
    }

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_sock, (sockaddr*)&addr, sizeof(addr)) == -1) {
        log_error("Bind failed");
        close(server_sock);
        return 1;
    }

    if (listen(server_sock, SOMAXCONN) == -1) {
        log_error("Listen failed");
        close(server_sock);
        return 1;
    }

    std::cout << "Server listening on port " << port << std::endl;

    while (true) {
        sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (sockaddr*)&client_addr, &addr_len);
        if (client_sock == -1) {
            log_error("Accept failed");
            continue;
        }

        std::thread(handle_client, client_sock).detach();
    }

    close(server_sock);
    return 0;
}
