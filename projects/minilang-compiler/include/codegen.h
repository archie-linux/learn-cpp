#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

class CodeGenerator {
public:
    CodeGenerator(const std::string& outputFile);
    void generate(Program* program);

private:
    std::ofstream out;
    int labelCount = 0;
    std::unordered_map<std::string, int> varOffsets;
    int stackOffset = 0;

    std::string newLabel();
    void emit(const std::string& instr);

    void genStmt(Stmt* stmt);
    void genVarDecl(VarDeclStmt* stmt);
    void genAssign(AssignStmt* stmt);
    void genIf(IfStmt* stmt);
    void genWhile(WhileStmt* stmt);
    void genPrint(PrintStmt* stmt);
    void genBlock(BlockStmt* stmt);

    void genExpr(Expr* expr, const std::string& reg);
    void genNumber(NumberExpr* expr, const std::string& reg);
    void genIdent(IdentExpr* expr, const std::string& reg);
    void genBinary(BinaryExpr* expr, const std::string& reg);
};

#endif
