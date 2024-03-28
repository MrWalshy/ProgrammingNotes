#include "token.h"

std::string Token::toString() const
{
    return tokenTypeToString(type) + " " + lexeme;
}