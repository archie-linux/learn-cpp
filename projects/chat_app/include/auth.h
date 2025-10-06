// auth.h (Authentication module)
#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <unordered_map>

class Auth {
public:
    Auth();
    bool authenticate(const std::string& username, const std::string& password);
private:
    std::unordered_map<std::string, std::string> users;
};

#endif // AUTH_H
