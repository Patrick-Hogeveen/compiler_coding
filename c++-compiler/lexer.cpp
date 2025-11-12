#include <string>
#include <vector>
#include <iostream>


enum TokenType {
    OpenBrace,
    CloseBrace,
    OpenParen,
    CloseParen,
    Semicolon,
    Int,
    Ret,
    Identifier,
    IntLit,
};

struct Token {
    std::string value;
    TokenType type;
};

std::vector<std::string> SplitString(std::string &srcCode) {
    std::vector<std::string> words;
    std::string word;


    for (char ch : srcCode) {
        if (ch != ' ') {
            word += ch;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

std::vector<Token> tokenize(std::string &sourceCode) {
    std::vector<Token> tokens;

    return tokens;
}

int main(int argc, char *argv[]) {

    std::string test = "The quick brown fox jumps over the lazy dog";
    std::vector<std::string> words = SplitString(test);

    for (auto i: words) {
        std::cout << i << std::endl;
    }
    return 0;
}