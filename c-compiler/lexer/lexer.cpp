#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cstring>
#include <filesystem>
#include "lexer.h"

namespace fs = std::filesystem;


KeywordMap keywords;

void INIT_KEYWORDS() {
    keywords["int"] = TokenType::Int;
    keywords["return"] = TokenType::Return;
}



bool isNumber(const std::string &str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }

    return true;
}

bool isWord(const std::string &str) {
    for (char ch : str) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}

std::string chrToStr(char chr) {
    
    return std::string(1, chr);
}


std::vector<Token> tokenize(std::string &sourceCode) {
    std::vector<Token> tokens;
    //std::vector<std::string> strTokens = SplitString(sourceCode);

    int N = sourceCode.size();
    int i = 0;

    while (i < N) {
        char chr = sourceCode[i];
        //std::string chr = std::string(1, sourceCode[i]);

        if (chr == ' '| chr == '\n') {
            i++;
            continue;
        }

        if (chr == '(') {
            tokens.push_back(Token(chrToStr(chr), TokenType::OpenParen));
        }
        else if (chr == ')') {
            tokens.push_back(Token(chrToStr(chr), TokenType::CloseParen));
        }
        else if (chr == '{') {
            tokens.push_back(Token(chrToStr(chr), TokenType::OpenBrace));
        }
        else if (chr == '}') {
            tokens.push_back(Token(chrToStr(chr), TokenType::CloseBrace));
        }
        else if (chr == '[') {
            tokens.push_back(Token(chrToStr(chr), TokenType::OpenSquare));
        }
        else if (chr == ']') {
            tokens.push_back(Token(chrToStr(chr), TokenType::CloseSqaure));
        }
        else if (chr == ';') {
            tokens.push_back(Token(chrToStr(chr), TokenType::Semicolon));
        }
        else {
            if (isdigit(chr)) {
                std::string word;

                while(i < N && isdigit(chr)) {
                    word += chr;
                    i++;
                    chr = sourceCode[i];
                }
                tokens.push_back(Token(word, TokenType::Number));
            }
            else if (isalpha(chr)) {
                std::string word;

                while(i<N && isalpha(chr)) {
                    word += chr;
                    i++;
                    chr = sourceCode[i];
                }

                auto it = keywords.find(word);
                if (it != keywords.end()) {
                    tokens.push_back(Token(word, it->second));
                }
                else {
                    tokens.push_back(Token(word, TokenType::Identifier));
                }
            }
            //Making sure the char after a multi-char token gets processed properly
            i--;
        }

        i++;
    }

    
    return tokens;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Incorrect arguments" << std::endl;
        return EXIT_FAILURE;
    }

    fs::path fpath = argv[1];
    if (fpath.extension() != ".c") {
        std::cerr << "Invalid code file" << std::endl;
        return EXIT_FAILURE;
    }

    

    INIT_KEYWORDS();

    std::string sourceCode;
    std::stringstream contents_stream;
    std::fstream input(argv[1], std::ios::in);
    contents_stream << input.rdbuf();
    sourceCode = contents_stream.str();


    std::vector<Token> tokens = tokenize(sourceCode);
    std::cout << sourceCode << std::endl;
    std::cout << tokens.size() << std::endl;
    for (int i = 0; i < tokens.size(); ++i)
    {
        std::cout << "Value: " << tokens[i].value << "   Type: " << tokens[i].type << std::endl;
    }
    return 0;
}