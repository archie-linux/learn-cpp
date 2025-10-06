#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <tuple>

class TransactionManager {
public:
    bool start_transaction(const std::string& user);
    bool commit_transaction(const std::string& user);
    bool rollback_transaction(const std::string& user);
    void log_operation(const std::string& user, const std::string& operation, const std::string& key, const std::string& value);
private:
    struct Transaction {
        std::vector<std::tuple<std::string, std::string, std::string>> operations_;
        bool active_;
    };
    std::unordered_map<std::string, Transaction> transactions_;
};



