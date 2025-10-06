#ifndef AST_H
#define AST_H

#include <memory>
#include <vector>
#include <string>

struct Expr {
    virtual ~Expr() = default;
};

struct NumberExpr : public Expr {
    int value;
    NumberExpr(int val) : value(val) {}
};

struct IdentExpr : public Expr {
    std::string name;
    IdentExpr(const std::string& n) : name(n) {}
};

struct BinaryExpr : public Expr {
    std::string op;
    std::unique_ptr<Expr> left, right;
    BinaryExpr(std::string o, std::unique_ptr<Expr> l, std::unique_ptr<Expr> r)
        : op(o), left(std::move(l)), right(std::move(r)) {}
};

struct Stmt {
    virtual ~Stmt() = default;
};

struct VarDeclStmt : public Stmt {
    std::string type;
    std::string name;
    std::unique_ptr<Expr> init;
    VarDeclStmt(std::string t, std::string n, std::unique_ptr<Expr> i)
        : type(t), name(n), init(std::move(i)) {}
};

struct AssignStmt : public Stmt {
    std::string name;
    std::unique_ptr<Expr> value;
    AssignStmt(std::string n, std::unique_ptr<Expr> v)
        : name(n), value(std::move(v)) {}
};

struct IfStmt : public Stmt {
    std::unique_ptr<Expr> cond;
    std::unique_ptr<Stmt> thenBranch, elseBranch;
    IfStmt(std::unique_ptr<Expr> c, std::unique_ptr<Stmt> t, std::unique_ptr<Stmt> e)
        : cond(std::move(c)), thenBranch(std::move(t)), elseBranch(std::move(e)) {}
};

struct WhileStmt : public Stmt {
    std::unique_ptr<Expr> cond;
    std::unique_ptr<Stmt> body;
    WhileStmt(std::unique_ptr<Expr> c, std::unique_ptr<Stmt> b)
        : cond(std::move(c)), body(std::move(b)) {}
};

struct PrintStmt : public Stmt {
    std::unique_ptr<Expr> expr;
    PrintStmt(std::unique_ptr<Expr> e) : expr(std::move(e)) {}
};

struct BlockStmt : public Stmt {
    std::vector<std::unique_ptr<Stmt>> stmts;
};

struct Program {
    std::unique_ptr<BlockStmt> body;
};

#endif
