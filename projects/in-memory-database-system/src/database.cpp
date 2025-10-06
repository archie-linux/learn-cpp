#include "database.h"

Database::Database() {
    storage_ = std::make_unique<Storage>();
    index_ = std::make_unique<Index>();
    transaction_manager_ = std::make_unique<TransactionManager>();
    user_manager_ = std::make_unique<UserManager>();
}

bool Database::insert(const std::string& key, const std::string& value, const std::string& user) {
    if (!user_manager_->has_permission(user, "write")) return false;
    if (transaction_manager_->start_transaction(user)) {
        transaction_manager_->log_operation(user, "insert", key, value);
        bool success = storage_->insert(key, value);
        if (success) {
            transaction_manager_->commit_transaction(user); // Commit on success
        } else {
            transaction_manager_->rollback_transaction(user); // Rollback on failure
        }
        return success;
    }
    return false;
}

std::string Database::get(const std::string& key, const std::string& user) {
    if (!user_manager_->has_permission(user, "read")) return "";
    return storage_->get(key);
}

bool Database::remove(const std::string& key, const std::string& user) {
    if (!user_manager_->has_permission(user, "delete")) return false;
    if (transaction_manager_->start_transaction(user)) {
        transaction_manager_->log_operation(user, "remove", key, "");
        bool success = storage_->remove(key);
        if (success) {
            transaction_manager_->commit_transaction(user); // Commit on success
        } else {
            transaction_manager_->rollback_transaction(user); // Rollback on failure
        }
        return success;
    }
    return false;
}

bool Database::start_transaction(const std::string& user) {
    return transaction_manager_->start_transaction(user);
}

bool Database::commit_transaction(const std::string& user) {
    return transaction_manager_->commit_transaction(user);
}

bool Database::rollback_transaction(const std::string& user) {
    return transaction_manager_->rollback_transaction(user);
}

bool Database::add_user(const std::string& username, const std::string& role) {
    return user_manager_->add_user(username, role);
}
