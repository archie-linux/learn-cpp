#pragma once
#include <memory>
#include <string>
#include "storage.h"
#include "index.h"
#include "transaction.h"
#include "user_manager.h"

class Database { 
    public: Database();
    bool insert(const std::string& key, const std::string& value, const std::string& user);
    std::string get(const std::string& key, const std::string& user);
    bool remove(const std::string& key, const std::string& user);
    bool start_transaction(const std::string& user);
    bool commit_transaction(const std::string& user);
    bool rollback_transaction(const std::string& user);
    bool add_user(const std::string& username, const std::string& role);
    private: std::unique_ptr<Storage> storage_;
    std::unique_ptr<Index> index_;
    std::unique_ptr<TransactionManager> transaction_manager_;
    std::unique_ptr<UserManager> user_manager_;
};
