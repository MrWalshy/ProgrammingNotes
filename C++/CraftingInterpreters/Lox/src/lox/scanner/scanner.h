#ifndef SCANNER_H
#define SCANNER_H
#include <string>
#include <vector>
#include "token.h"
#include <map>

class Scanner
{
    public:
        Scanner(const std::string& src);

        std::vector<Token> scanTokens();

    private:
        bool isAtEnd() const;
        char peek() const;
        char peekNext() const;
        bool isDigit(char c) const;
        bool isAlpha(char c) const;
        bool isAlphaNumeric(char c) const;

        void scanToken();
        char advance();
        bool match(char expected);
        void string();
        void number();
        void identifier();
        void addToken(TokenType type);
        void addToken(TokenType type, std::unique_ptr<Object> literal);

        std::string source;
        std::vector<Token> tokens;
        int start;
        int current;
        int line;

        static std::map<std::string, TokenType> keywords;
};
#endif