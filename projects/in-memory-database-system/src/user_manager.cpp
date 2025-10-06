#include "user_manager.h"

bool UserManager::add_user(const std::string& username, const std::string& role) {
    User user;
    user.role = role;
    if (role == "admin") {
        user.can_read = user.can_write = user.can_delete = true;
    } else if (role == "reader") {
        user.can_read = true;
        user.can_write = user.can_delete = false;
    } else {
        return false;
    }
    return users_.emplace(username, user).second;
}

bool UserManager::has_permission(const std::string& username, const std::string& operation) {
    auto it = users_.find(username);
    if (it == users_.end()) return false;
    if (operation == "read") return it->second.can_read;
    if (operation == "write") return it->second.can_write;
    if (operation == "delete") return it->second.can_delete;
    return false;
}
