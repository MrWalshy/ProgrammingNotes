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
        ~Scanner();

        std::vector<Token> scanTokens();

    private:
        bool isAtEnd();
        void scanToken();
        char advance();
        bool match(char expected);
        char peek();
        char peekNext();
        bool isDigit(char c);
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);
        void string();
        void number();
        void identifier();
        void addToken(TokenType type);
        void addToken(TokenType type, Object* literal);

        const std::string& source;
        std::vector<Token> tokens;
        int start;
        int current;
        int line;

        static std::map<std::string, TokenType> keywords;
};
#endif