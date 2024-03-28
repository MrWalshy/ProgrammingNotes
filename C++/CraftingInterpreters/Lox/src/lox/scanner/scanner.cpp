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

    // tokens.push_back(new Token(TokenType::END, "", nullptr, line));
    tokens.push_back(Token(TokenType::END, "", nullptr, line));
    return tokens;
}

const bool Scanner::isAtEnd()
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
    // std::cout << "Scanning char: " << c << std::endl;

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

const char Scanner::peek()
{
    if (isAtEnd()) return '\0';
    return source[current];
}

const char Scanner::peekNext()
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

void Scanner::addToken(TokenType type, Object* literal)
{
    // std::cout << "start = " << start << ", current = " << current << std::endl;
    // std::cout << "Token lexeme: ";
    // std::cout << source.substr(start, current - start) << std::endl;
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type, text, literal, line));
}

const bool Scanner::isDigit(char c)
{
    return c >= '0' && c <= '9';
}

const bool Scanner::isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

const bool Scanner::isAlphaNumeric(char c)
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
    
    // addToken(TokenType::IDENTIFIER);
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
    LoxString* loxString = new LoxString(value);
    addToken(TokenType::STRING, loxString);
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
    LoxNumber* loxNumber = new LoxNumber(num);
    addToken(TokenType::NUMBER, loxNumber);
}

Scanner::~Scanner()
{
    // need to release dynamic memory taken by any lox object tokens
    // - I wonder what I'll do when it comes to the parser...
    //   should I keep this or defer deletion elsewhere? Maybe switch 
    //   to smart pointers, shared pointer maybe, so I don't have to manage it.
    //   This will do for the time being though, I'll tackle that bridge 
    //   when I get to it. With this, I probably only need the nullptr
    //   check wrapped around checks for types given only Lox types 
    //   will have a backing Object*
    for (Token token : tokens)
    {
        if (token.type == TokenType::STRING)
        {
            LoxString* loxStringPtr = dynamic_cast<LoxString*>(token.literal);
            if (loxStringPtr != nullptr)
            {
                // std::cout << "Destroying token: " << token.toString() << std::endl;
                delete loxStringPtr;
            }
        }
        else if (token.type == TokenType::NUMBER)
        {
            LoxNumber* loxNumberPtr = dynamic_cast<LoxNumber*>(token.literal);
            if (loxNumberPtr != nullptr)
            {
                delete loxNumberPtr;
            }
        }
    }
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