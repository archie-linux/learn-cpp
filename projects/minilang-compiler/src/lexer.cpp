#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& src) : source(src), pos(0), line(1) {
    keywords = {
        {"int", TOK_INT},
        {"if", TOK_IF},
        {"else", TOK_ELSE},
        {"while", TOK_WHILE},
        {"print", TOK_PRINT}
    };
}

char Lexer::currentChar() {
    return pos < source.size() ? source[pos] : '\0';
}

void Lexer::advance() {
    if (currentChar() == '\n') line++;
    pos++;
}

void Lexer::skipWhitespace() {
    while (std::isspace(currentChar())) advance();
}

Token Lexer::number() {
    std::string val;
    while (std::isdigit(currentChar())) {
        val += currentChar();
        advance();
    }
    return {TOK_NUMBER, val, line};
}

Token Lexer::identifier() {
    std::string val;
    while (std::isalnum(currentChar()) || currentChar() == '_') {
        val += currentChar();
        advance();
    }
    auto it = keywords.find(val);
    return (it != keywords.end()) ? Token{it->second, val, line} : Token{TOK_IDENT, val, line};
}

Token Lexer::nextToken() {
    skipWhitespace();
    char c = currentChar();
    if (c == '\0') return {TOK_EOF, "", line};

    if (std::isdigit(c)) return number();
    if (std::isalpha(c) || c == '_') return identifier();

    advance();
    switch (c) {
        case '+': return {TOK_PLUS, "+", line};
        case '-': return {TOK_MINUS, "-", line};
        case '*': return {TOK_MUL, "*", line};
        case '/': return {TOK_DIV, "/", line};
        case '=': return {TOK_ASSIGN, "=", line};
        case '>': return {TOK_GT, ">", line};
        case '<': return {TOK_LT, "<", line};
        case '(': return {TOK_LPAREN, "(", line};
        case ')': return {TOK_RPAREN, ")", line};
        case '{': return {TOK_LBRACE, "{", line};
        case '}': return {TOK_RBRACE, "}", line};
        case ';': return {TOK_SEMI, ";", line};
        default: return {TOK_INVALID, std::string(1, c), line};
    }
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    Token tok;
    do {
        tok = nextToken();
        if (tok.type == TOK_INVALID) throw std::runtime_error("Invalid token at line " + std::to_string(line));
        tokens.push_back(tok);
    } while (tok.type != TOK_EOF);
    return tokens;
}
