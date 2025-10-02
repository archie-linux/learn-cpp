#include <memory>
#include <iostream>

class Child;

class Parent {
public:
    std::shared_ptr<Child> child_;
    
    Parent() { std::cout << "Parent created\n"; }
    ~Parent() { std::cout << "Parent destroyed\n"; }
    
    void setChild(std::shared_ptr<Child> child) {
        child_ = child;
    }
};

class Child {
public:
    std::weak_ptr<Parent> parent_;  // ✅ weak_ptr breaks the cycle
    
    Child() { std::cout << "Child created\n"; }
    ~Child() { std::cout << "Child destroyed\n"; }
    
    void setParent(std::shared_ptr<Parent> parent) {
        parent_ = parent;
    }
    
    void doSomethingWithParent() {
        if (auto parent = parent_.lock()) {  // Safe access
            std::cout << "Child accessing parent\n";
        } else {
            std::cout << "Parent no longer exists\n";
        }
    }
};

void demonstrateWeakPtr() {
    auto parent = std::make_shared<Parent>();
    auto child = std::make_shared<Child>();
    
    parent->setChild(child);
    child->setParent(parent);  // No circular reference due to weak_ptr
    
    child->doSomethingWithParent();
    
    // Both objects properly destroyed when shared_ptrs go out of scope
}
