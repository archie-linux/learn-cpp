#include "transaction.h"

bool TransactionManager::start_transaction(const std::string& user) {
    auto& txn = transactions_[user];
    if (txn.active_) return false;
    txn.active_ = true;
    txn.operations_.clear();
    return true;
}

bool TransactionManager::commit_transaction(const std::string& user) {
    auto it = transactions_.find(user);
    if (it == transactions_.end() || !it->second.active_) return false;
    it->second.active_ = false;
    return true;
}

bool TransactionManager::rollback_transaction(const std::string& user) {
    auto it = transactions_.find(user);
    if (it == transactions_.end() || !it->second.active_) return false;
    it->second.active_ = false;
    it->second.operations_.clear();
    return true;
}

void TransactionManager::log_operation(const std::string& user, const std::string& operation, const std::string& key, const std::string& value) {
    auto it = transactions_.find(user);
    if (it != transactions_.end() && it->second.active_) {
        it->second.operations_.emplace_back(operation, key, value);
    }
}
