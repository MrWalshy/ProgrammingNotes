#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "token_type.h"
#include "lox/types/object.h"

struct Token
{
    TokenType type;
    std::string lexeme;
    Object* literal;
    const int line;

    std::string toString() const;
};
#endif