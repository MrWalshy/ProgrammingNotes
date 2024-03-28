#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "token_type.h"
#include "lox/types/object.h"
#include <memory>

struct Token
{
    TokenType type;
    std::string lexeme;
    std::unique_ptr<Object> literal;
    const int line;

    std::string toString() const;
};
#endif