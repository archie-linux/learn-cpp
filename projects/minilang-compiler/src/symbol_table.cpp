#include "symbol_table.h"
#include <stdexcept>

void SymbolTable::enterScope() {
    scopes.emplace_back();
}

void SymbolTable::exitScope() {
    if (scopes.empty()) throw std::runtime_error("Scope mismatch");
    scopes.pop_back();
}

void SymbolTable::declare(const std::string& name, const std::string& type) {
    if (scopes.back().count(name)) throw std::runtime_error("Redeclaration: " + name);
    scopes.back()[name] = type;
}

std::string SymbolTable::lookup(const std::string& name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto found = it->find(name);
        if (found != it->end()) return found->second;
    }
    return "";
}
