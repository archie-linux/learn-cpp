#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"
#include "symbol_table.h"

class SemanticAnalyzer {
public:
    void analyze(Program* program);

private:
    SymbolTable symTable;

    void visit(Stmt* stmt);
    void visit(VarDeclStmt* stmt);
    void visit(AssignStmt* stmt);
    void visit(IfStmt* stmt);
    void visit(WhileStmt* stmt);
    void visit(PrintStmt* stmt);
    void visit(BlockStmt* stmt);

    std::string inferType(Expr* expr);
    std::string visit(NumberExpr* expr);
    std::string visit(IdentExpr* expr);
    std::string visit(BinaryExpr* expr);
};

#endif
