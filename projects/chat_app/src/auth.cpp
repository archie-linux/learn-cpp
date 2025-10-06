// auth.cpp (Implementation of authentication)
#include "auth.h"

Auth::Auth() {
    // Dummy users for demonstration
    users["user1"] = "pass1";
    users["user2"] = "pass2";
    // Add more users as needed
}

bool Auth::authenticate(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}
