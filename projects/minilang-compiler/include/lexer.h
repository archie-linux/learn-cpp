#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <unordered_map>

enum TokenType {
    TOK_INT, TOK_IDENT, TOK_NUMBER,
    TOK_PLUS, TOK_MINUS, TOK_MUL, TOK_DIV,
    TOK_EQ, TOK_GT, TOK_LT,
    TOK_IF, TOK_ELSE, TOK_WHILE, TOK_PRINT,
    TOK_LPAREN, TOK_RPAREN, TOK_LBRACE, TOK_RBRACE,
    TOK_SEMI, TOK_ASSIGN,
    TOK_EOF, TOK_INVALID
};

struct Token {
    TokenType type;
    std::string value;
    int line;
};

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t pos;
    int line;
    std::unordered_map<std::string, TokenType> keywords;

    char currentChar();
    void advance();
    void skipWhitespace();
    Token number();
    Token identifier();
    Token nextToken();
};

#endif
