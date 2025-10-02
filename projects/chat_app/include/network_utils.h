// network_utils.h (Common network functions for send/receive)
#ifndef NETWORK_UTILS_H
#define NETWORK_UTILS_H

#include <string>
#include <cstdint>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include "utils.h"

bool send_data(int sock, const std::string& data) {
    uint32_t size = htonl(static_cast<uint32_t>(data.size()));
    if (::send(sock, &size, sizeof(size), 0) != sizeof(size)) {
        return false;
    }
    if (::send(sock, data.c_str(), data.size(), 0) != static_cast<ssize_t>(data.size())) {
        return false;
    }
    return true;
}

std::string receive_data(int sock) {
    uint32_t size = 0;
    ssize_t bytes_read = recv(sock, &size, sizeof(size), 0);
    if (bytes_read != sizeof(size)) {
        return "";
    }
    size = ntohl(size);
    std::string data(size, '\0');
    bytes_read = recv(sock, &data[0], size, 0);
    if (bytes_read != static_cast<ssize_t>(size)) {
        return "";
    }
    return data;
}

#endif // NETWORK_UTILS_H
