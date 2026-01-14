#include <string>
#include <unordered_map>
#include <vector>

#ifndef LEXER_H
#define LEXER_H

enum TokenType {
    OpenBrace,
    CloseBrace,
    OpenParen,
    CloseParen,
    OpenSquare,
    CloseSqaure,
    Semicolon,
    Identifier,
    Number,
    BinaryOp,
    //Keywords
    Int,
    Return,
};

struct Token {
    std::string value;
    TokenType type;

    Token(std::string v, TokenType t) : value(v), type(t) {}
};

typedef std::unordered_map<std::string, TokenType> KeywordMap;

std::vector<Token> tokenize(std::string &sourceCode);

#endif