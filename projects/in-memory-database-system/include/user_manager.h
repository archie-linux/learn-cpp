#pragma once
#include <string>
#include <unordered_map>

class UserManager {
public:
    bool add_user(const std::string& username, const std::string& role);
    bool has_permission(const std::string& username, const std::string& operation);
private:
    struct User {
        std::string role;
        // Permissions: read, write, delete
        bool can_read;
        bool can_write;
        bool can_delete;
    };
    std::unordered_map<std::string, User> users_;
};
