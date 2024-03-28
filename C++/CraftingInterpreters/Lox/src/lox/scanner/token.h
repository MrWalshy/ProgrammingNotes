#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "token_type.h"
#include "lox/types/object.h"

class Token
{
    public:
        const TokenType type;
        const std::string lexeme;
        Object* literal;
        const int line;

        Token(TokenType type, std::string lexeme, Object* literal, int line);

        std::string toString();
};
#endif