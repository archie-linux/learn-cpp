#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <unordered_map>
#include <string>
#include <vector>

class SymbolTable {
public:
    void enterScope();
    void exitScope();
    void declare(const std::string& name, const std::string& type);
    std::string lookup(const std::string& name);

private:
    std::vector<std::unordered_map<std::string, std::string>> scopes;
};

#endif
