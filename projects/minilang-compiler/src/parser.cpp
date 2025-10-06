#include "parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& t) : tokens(t), pos(0) {}

Token Parser::currentToken() {
    return pos < tokens.size() ? tokens[pos] : Token{TOK_EOF, "", -1};
}

void Parser::advance() {
    pos++;
}

void Parser::expect(TokenType type) {
    if (currentToken().type != type) {
        throw std::runtime_error("Expected token " + std::to_string(type) + " at line " + std::to_string(currentToken().line));
    }
}

std::unique_ptr<Program> Parser::parse() {
    auto prog = std::make_unique<Program>();
    prog->body = std::make_unique<BlockStmt>();
    while (currentToken().type != TOK_EOF) {
        prog->body->stmts.push_back(parseStmt());
    }
    return prog;
}

std::unique_ptr<Stmt> Parser::parseStmt() {
    auto tok = currentToken();
    if (tok.type == TOK_INT) return parseVarDecl();
    if (tok.type == TOK_IDENT) {
        advance();
        if (currentToken().type == TOK_ASSIGN) {
            advance();
            auto expr = parseExpr();
            expect(TOK_SEMI);
            advance();
            return std::make_unique<AssignStmt>(tok.value, std::move(expr));
        }
        throw std::runtime_error("Unexpected after ident at line " + std::to_string(tok.line));
    }
    if (tok.type == TOK_IF) return parseIf();
    if (tok.type == TOK_WHILE) return parseWhile();
    if (tok.type == TOK_PRINT) return parsePrint();
    if (tok.type == TOK_LBRACE) return parseBlock();
    throw std::runtime_error("Invalid statement at line " + std::to_string(tok.line));
}

std::unique_ptr<Stmt> Parser::parseVarDecl() {
    advance(); // int
    expect(TOK_IDENT);
    std::string name = currentToken().value;
    advance();
    std::unique_ptr<Expr> init = nullptr;
    if (currentToken().type == TOK_ASSIGN) {
        advance();
        init = parseExpr();
    }
    expect(TOK_SEMI);
    advance();
    return std::make_unique<VarDeclStmt>("int", name, std::move(init));
}

std::unique_ptr<Stmt> Parser::parseIf() {
    advance(); // if
    expect(TOK_LPAREN);
    advance();
    auto cond = parseExpr();
    expect(TOK_RPAREN);
    advance();
    auto then = parseStmt();
    std::unique_ptr<Stmt> els = nullptr;
    if (currentToken().type == TOK_ELSE) {
        advance();
        els = parseStmt();
    }
    return std::make_unique<IfStmt>(std::move(cond), std::move(then), std::move(els));
}

std::unique_ptr<Stmt> Parser::parseWhile() {
    advance(); // while
    expect(TOK_LPAREN);
    advance();
    auto cond = parseExpr();
    expect(TOK_RPAREN);
    advance();
    auto body = parseStmt();
    return std::make_unique<WhileStmt>(std::move(cond), std::move(body));
}

std::unique_ptr<Stmt> Parser::parsePrint() {
    advance(); // print
    auto expr = parseExpr();
    expect(TOK_SEMI);
    advance();
    return std::make_unique<PrintStmt>(std::move(expr));
}

std::unique_ptr<Stmt> Parser::parseBlock() {
    advance(); // {
    auto block = std::make_unique<BlockStmt>();
    while (currentToken().type != TOK_RBRACE && currentToken().type != TOK_EOF) {
        block->stmts.push_back(parseStmt());
    }
    expect(TOK_RBRACE);
    advance();
    return block;
}

std::unique_ptr<Expr> Parser::parseExpr() {
    auto left = parseTerm();
    while (currentToken().type == TOK_PLUS || currentToken().type == TOK_MINUS ||
           currentToken().type == TOK_GT || currentToken().type == TOK_LT) {
        std::string op = currentToken().value;
        advance();
        auto right = parseTerm();
        left = std::make_unique<BinaryExpr>(op, std::move(left), std::move(right));
    }
    return left;
}

std::unique_ptr<Expr> Parser::parseTerm() {
    auto left = parseFactor();
    while (currentToken().type == TOK_MUL || currentToken().type == TOK_DIV) {
        std::string op = currentToken().value;
        advance();
        auto right = parseFactor();
        left = std::make_unique<BinaryExpr>(op, std::move(left), std::move(right));
    }
    return left;
}

std::unique_ptr<Expr> Parser::parseFactor() {
    auto tok = currentToken();
    if (tok.type == TOK_NUMBER) {
        advance();
        return std::make_unique<NumberExpr>(std::stoi(tok.value));
    } else if (tok.type == TOK_IDENT) {
        advance();
        return std::make_unique<IdentExpr>(tok.value);
    } else if (tok.type == TOK_LPAREN) {
        advance();
        auto expr = parseExpr();
        expect(TOK_RPAREN);
        advance();
        return expr;
    }
    throw std::runtime_error("Invalid expression at line " + std::to_string(tok.line));
}
