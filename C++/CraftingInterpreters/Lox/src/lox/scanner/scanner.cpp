#include "scanner.h"
#include <iostream>
#include "lox/types/lox_string.h"
#include "lox/types/number.h"

class Lox
{
    public:
    static void error(int line, const std::string& message);
};

Scanner::Scanner(const std::string& src): source(src), 
    tokens(std::vector<Token>()), start(0), current(0), line(1) {}

std::vector<Token> Scanner::scanTokens()
{
    while (!isAtEnd())
    {
        start = current;
        scanToken();
    }

    tokens.push_back(Token{TokenType::END, "", nullptr, line});
    // each Token contains a std::unique_ptr<Object> member
    // - std::unique_ptr isn't copyable but can be moved, due to 
    //   this std::move needs to be used to prevent the compiler from 
    //   trying to copy each element of the vector.
    // - std::move enables move semantics, transferring ownership of 
    //   the vector of tokens to the caller. This is done by transforming 
    //   from an lvalue to an xvalue - xvalue signals to the compiler that 
    //   it can transfer ownership of resources from one object to another 
    //   as the current one will be destroyed soon. Or is it an rvalue reference its 
    //   converted to, people on the web seem to give conflicting info???
    // - from what I can tell, the vector used here is discarded but the tokens 
    //   inside it are moved to the new vector in the caller
    return std::move(tokens);
}

bool Scanner::isAtEnd() const
{
    return current >= source.length();
}

bool Scanner::match(char expected)
{
    if (isAtEnd()) return false;
    if (source[current] != expected) return false;

    current++;
    return true;
}

void Scanner::scanToken()
{
    const char c = advance();

    switch (c)
    {
        case '(':
            addToken(TokenType::LEFT_PAREN);
            break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;
        case '!':
            addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
            break;
        case '=':
            addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '<':
            addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '>':
            addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;
        case '/':
            if (match('/'))
            {
                // double // matched, comment to end of line, skip it all
                while (peek() != '\n' && !isAtEnd()) advance();
            }
            else
            {
                addToken(TokenType::SLASH); // its a divide
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        case '"': string(); break;
        default:
            if (isDigit(c))
            {
                number();
            }
            else if (isAlpha(c))
            {
                // for maximal munch purposes, assumed that any lexeme starting with letter or underscore is an identifer
                identifier();
            }
            else
            {
                Lox::error(line, "Unexpected character");
            }
            break;
    }
}

char Scanner::peek() const
{
    if (isAtEnd()) return '\0';
    return source[current];
}

char Scanner::peekNext() const
{
    if (current + 1 >= source.size()) return '\0';
    return source[current + 1];
}

char Scanner::advance()
{
    return source[current++];
}

void Scanner::addToken(TokenType type)
{
    addToken(type, nullptr);
}

void Scanner::addToken(TokenType type, std::unique_ptr<Object> literal)
{
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token{type, text, std::move(literal), line});
}

bool Scanner::isDigit(char c) const
{
    return c >= '0' && c <= '9';
}

bool Scanner::isAlpha(char c) const
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

bool Scanner::isAlphaNumeric(char c) const
{
    return isDigit(c) || isAlpha(c);
}

void Scanner::identifier()
{
    while (isAlphaNumeric(peek())) advance();

    std::string text = source.substr(start, current - start);
    auto typePosition = Scanner::keywords.find(text);
    if (typePosition == Scanner::keywords.end())
    {
        addToken(TokenType::IDENTIFIER);
    }
    else
    {
        // its a keyword
        addToken(typePosition->second);
    }
}

void Scanner::string()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n') line++;
        advance();
    }

    if (isAtEnd())
    {
        Lox::error(line, "Unterminated string");
        return;
    }

    advance(); // consume closing "
    // trim quotes, seems to still be including the quotes??? STRING "Hello" is printed in console
    // - TODO: Do debug mode and inspect why
    //   maybe its just the console showing the quotes when printing?
    std::string value = source.substr(start + 1, current - start - 1);
    std::unique_ptr<Object> loxString = std::make_unique<LoxString>(value);
    addToken(TokenType::STRING, std::move(loxString)); // std::move - transfer ownership using move semantics
}

void Scanner::number()
{
    while (isDigit(peek())) advance();

    // fractional part
    if (peek() == '.' && isDigit(peekNext()))
    {
        advance(); // consume '.'

        while (isDigit(peek())) advance();
    }

    double num = std::stod(source.substr(start, current - start));
    std::unique_ptr<Object> loxNumber = std::make_unique<LoxNumber>(num);
    addToken(TokenType::NUMBER, std::move(loxNumber)); // std::move - transfer ownership using move semantics
}

// static map of keywords
std::map<std::string, TokenType> Scanner::keywords = {
    {"and", TokenType::AND},
    {"class", TokenType::CLASS},
    {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},
    {"for", TokenType::FOR},
    {"fun", TokenType::FUN},
    {"if", TokenType::IF},
    {"nil", TokenType::NIL},
    {"or", TokenType::OR},
    {"print", TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super", TokenType::SUPER},
    {"this", TokenType::THIS},
    {"true", TokenType::TRUE},
    {"var", TokenType::VAR},
    {"while", TokenType::WHILE}
};