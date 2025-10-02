#include "semantic.h"
#include <stdexcept>

void SemanticAnalyzer::analyze(Program* program) {
    symTable.enterScope();
    visit(program->body.get());
    symTable.exitScope();
}

void SemanticAnalyzer::visit(Stmt* stmt) {
    if (auto* vd = dynamic_cast<VarDeclStmt*>(stmt)) visit(vd);
    else if (auto* as = dynamic_cast<AssignStmt*>(stmt)) visit(as);
    else if (auto* ifs = dynamic_cast<IfStmt*>(stmt)) visit(ifs);
    else if (auto* wh = dynamic_cast<WhileStmt*>(stmt)) visit(wh);
    else if (auto* pr = dynamic_cast<PrintStmt*>(stmt)) visit(pr);
    else if (auto* bl = dynamic_cast<BlockStmt*>(stmt)) visit(bl);
}

void SemanticAnalyzer::visit(VarDeclStmt* stmt) {
    if (stmt->init) {
        auto initType = inferType(stmt->init.get());
        if (initType != "int") throw std::runtime_error("Type mismatch in declaration");
    }
    symTable.declare(stmt->name, stmt->type);
}

void SemanticAnalyzer::visit(AssignStmt* stmt) {
    auto varType = symTable.lookup(stmt->name);
    if (varType.empty()) throw std::runtime_error("Undeclared variable: " + stmt->name);
    auto valType = inferType(stmt->value.get());
    if (valType != varType) throw std::runtime_error("Type mismatch in assignment");
}

void SemanticAnalyzer::visit(IfStmt* stmt) {
    auto condType = inferType(stmt->cond.get());
    if (condType != "int") throw std::runtime_error("Condition must be int");
    visit(stmt->thenBranch.get());
    if (stmt->elseBranch) visit(stmt->elseBranch.get());
}

void SemanticAnalyzer::visit(WhileStmt* stmt) {
    auto condType = inferType(stmt->cond.get());
    if (condType != "int") throw std::runtime_error("Condition must be int");
    visit(stmt->body.get());
}

void SemanticAnalyzer::visit(PrintStmt* stmt) {
    auto exprType = inferType(stmt->expr.get());
    if (exprType != "int") throw std::runtime_error("Print argument must be int");
}

void SemanticAnalyzer::visit(BlockStmt* stmt) {
    symTable.enterScope();
    for (auto& s : stmt->stmts) visit(s.get());
    symTable.exitScope();
}

std::string SemanticAnalyzer::inferType(Expr* expr) {
    if (auto* num = dynamic_cast<NumberExpr*>(expr)) return visit(num);
    if (auto* id = dynamic_cast<IdentExpr*>(expr)) return visit(id);
    if (auto* bin = dynamic_cast<BinaryExpr*>(expr)) return visit(bin);
    throw std::runtime_error("Unknown expression type");
}

std::string SemanticAnalyzer::visit(NumberExpr* expr) {
    return "int";
}

std::string SemanticAnalyzer::visit(IdentExpr* expr) {
    auto type = symTable.lookup(expr->name);
    if (type.empty()) throw std::runtime_error("Undeclared variable: " + expr->name);
    return type;
}

std::string SemanticAnalyzer::visit(BinaryExpr* expr) {
    auto left = inferType(expr->left.get());
    auto right = inferType(expr->right.get());
    if (left != "int" || right != "int") throw std::runtime_error("Operands must be int");
    return "int";  // All ops return int
}
