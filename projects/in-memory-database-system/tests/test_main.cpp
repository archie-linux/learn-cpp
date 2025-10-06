#include "database.h"
#include <cassert>
#include <iostream>

int main() {
    Database db;
    assert(db.add_user("admin", "admin"));
    assert(db.add_user("user1", "reader"));
    assert(db.insert("key1", "value1", "admin"));
    assert(db.get("key1", "user1") == "value1");
    assert(!db.insert("key2", "value2", "user1")); // No write permission
    assert(db.remove("key1", "admin"));
    assert(db.get("key1", "user1").empty());
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
