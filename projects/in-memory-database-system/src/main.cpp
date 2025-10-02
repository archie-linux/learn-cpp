#include "database.h"
#include <iostream>

int main() {
    Database db;
    db.add_user("admin", "admin");
    db.add_user("user1", "reader");
    
    db.insert("key1", "value1", "admin");
    std::cout << "Get key1: " << db.get("key1", "user1") << std::endl;
    
    db.start_transaction("admin");
    db.insert("key2", "value2", "admin");
    db.commit_transaction("admin");
    
    std::cout << "Get key2: " << db.get("key2", "user1") << std::endl;
    return 0;
}
