#include "codegen.h"
#include <stdexcept>
#include <sstream>

CodeGenerator::CodeGenerator(const std::string& outputFile) {
    out.open(outputFile);
    if (!out) throw std::runtime_error("Cannot open output file");

    // Preamble
    emit("section .data");
    emit("fmt: db \"%d\", 10, 0");  // For printf
    emit("section .text");
    emit("global _start");
    emit("extern printf");
    emit("_start:");
    emit("push rbp");
    emit("mov rbp, rsp");
}

void CodeGenerator::generate(Program* program) {
    genStmt(program->body.get());
    emit("mov rax, 60");  // sys_exit
    emit("xor rdi, rdi");
    emit("syscall");
    out.close();
}

std::string CodeGenerator::newLabel() {
    return "L" + std::to_string(labelCount++);
}

void CodeGenerator::emit(const std::string& instr) {
    out << instr << std::endl;
}

void CodeGenerator::genStmt(Stmt* stmt) {
    if (auto* vd = dynamic_cast<VarDeclStmt*>(stmt)) genVarDecl(vd);
    else if (auto* as = dynamic_cast<AssignStmt*>(stmt)) genAssign(as);
    else if (auto* ifs = dynamic_cast<IfStmt*>(stmt)) genIf(ifs);
    else if (auto* wh = dynamic_cast<WhileStmt*>(stmt)) genWhile(wh);
    else if (auto* pr = dynamic_cast<PrintStmt*>(stmt)) genPrint(pr);
    else if (auto* bl = dynamic_cast<BlockStmt*>(stmt)) genBlock(bl);
}

void CodeGenerator::genVarDecl(VarDeclStmt* stmt) {
    stackOffset -= 8;  // 64-bit int
    varOffsets[stmt->name] = stackOffset;
    if (stmt->init) {
        genExpr(stmt->init.get(), "rax");
        emit("mov [rbp + " + std::to_string(stackOffset) + "], rax");
    }
}

void CodeGenerator::genAssign(AssignStmt* stmt) {
    auto it = varOffsets.find(stmt->name);
    if (it == varOffsets.end()) throw std::runtime_error("Undeclared var: " + stmt->name);
    genExpr(stmt->value.get(), "rax");
    emit("mov [rbp + " + std::to_string(it->second) + "], rax");
}

void CodeGenerator::genIf(IfStmt* stmt) {
    std::string elseLabel = newLabel();
    std::string endLabel = newLabel();

    genExpr(stmt->cond.get(), "rax");
    emit("cmp rax, 0");
    emit("je " + elseLabel);

    genStmt(stmt->thenBranch.get());

    emit("jmp " + endLabel);
    emit(elseLabel + ":");
    if (stmt->elseBranch) genStmt(stmt->elseBranch.get());
    emit(endLabel + ":");
}

void CodeGenerator::genWhile(WhileStmt* stmt) {
    std::string startLabel = newLabel();
    std::string endLabel = newLabel();

    emit(startLabel + ":");
    genExpr(stmt->cond.get(), "rax");
    emit("cmp rax, 0");
    emit("je " + endLabel);

    genStmt(stmt->body.get());

    emit("jmp " + startLabel);
    emit(endLabel + ":");
}

void CodeGenerator::genPrint(PrintStmt* stmt) {
    genExpr(stmt->expr.get(), "rdi");  // First arg for printf
    emit("lea rsi, [fmt]");
    emit("xor rax, rax");
    emit("call printf");
}

void CodeGenerator::genBlock(BlockStmt* stmt) {
    for (auto& s : stmt->stmts) genStmt(s.get());
}

void CodeGenerator::genExpr(Expr* expr, const std::string& reg) {
    if (auto* num = dynamic_cast<NumberExpr*>(expr)) genNumber(num, reg);
    else if (auto* id = dynamic_cast<IdentExpr*>(expr)) genIdent(id, reg);
    else if (auto* bin = dynamic_cast<BinaryExpr*>(expr)) genBinary(bin, reg);
}

void CodeGenerator::genNumber(NumberExpr* expr, const std::string& reg) {
    emit("mov " + reg + ", " + std::to_string(expr->value));
}

void CodeGenerator::genIdent(IdentExpr* expr, const std::string& reg) {
    auto it = varOffsets.find(expr->name);
    if (it == varOffsets.end()) throw std::runtime_error("Undeclared var: " + expr->name);
    emit("mov " + reg + ", [rbp + " + std::to_string(it->second) + "]");
}

void CodeGenerator::genBinary(BinaryExpr* expr, const std::string& reg) {
    genExpr(expr->left.get(), "rax");
    genExpr(expr->right.get(), "rbx");
    if (expr->op == "+") emit("add rax, rbx");
    else if (expr->op == "-") emit("sub rax, rbx");
    else if (expr->op == "*") emit("imul rax, rbx");
    else if (expr->op == "/") {
        emit("cqo");  // Sign extend rax to rdx:rax
        emit("idiv rbx");
    } else if (expr->op == ">") {
        emit("cmp rax, rbx");
        emit("setg al");
        emit("movzx rax, al");
    } else if (expr->op == "<") {
        emit("cmp rax, rbx");
        emit("setl al");
        emit("movzx rax, al");
    }
    emit("mov " + reg + ", rax");
}
