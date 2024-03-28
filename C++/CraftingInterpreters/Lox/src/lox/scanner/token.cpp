#include "token.h"

Token::Token(TokenType type, std::string lexeme, Object* literal, int line): type(type), lexeme(lexeme), literal(literal), line(line) {}

std::string Token::toString()
{
    return tokenTypeToString(type) + " " + lexeme;
}