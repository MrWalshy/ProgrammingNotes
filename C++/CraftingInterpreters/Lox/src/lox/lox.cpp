#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include "lox.h"
#include "lox/scanner/scanner.h"

void Lox::run(int argc, char* argv[])
{
    if (argc > 2)
    {
        // std::cout << "Usage: jlox [script]" << std::endl;
        std::cerr << "Usage: jlox [script]" << std::endl;
        std::exit(64);
        // exit codes defined: https://man.freebsd.org/cgi/man.cgi?query=sysexits&apropos=0&sektion=0&manpath=FreeBSD+4.3-RELEASE&format=html
        // - 64: Command used incorrectly
        // std::exit() indicates a normal end to a program, although can still indicate failure
    }
    else if (argc == 2)
    {
        std::string fileName(argv[1]);
        this->runFile(fileName);
    }
    else
    {
        this->runPrompt();
    }
}

void Lox::run(const std::string& data)
{
    // std::cout << data << std::endl;
    Scanner sc(data);
    std::vector<Token> tokens = sc.scanTokens();

    // can't use for (Token token : tokens) as it tries to make a copy
    // of each Token but can't as it contains std::unique_prt<Object>.
    // - using const Token& prevents attempting to copy the objects
    for (const Token& token : tokens)
    {
        std::cout << token.toString() << std::endl;
    }


}

void Lox::runFile(std::string fileName)
{
    std::string fileData = this->readFile(fileName);
    this->run(fileData);
    if (Lox::hadError) std::exit(65);
}

void Lox::runPrompt()
{
    for (;;)
    {
        std::cout << "> ";
        std::string line;
        // std::cin >> line;
        // std::cin only reads input until it encounters whitespace (spaces, tabs, newlines)
        // - causes hang on checking if empty for exit
        std::getline(std::cin, line); // this reads the whole line, including whitespace

        if (line.empty()) break;
        run(line);
        Lox::hadError = false;
    }
}

// I have no idea if this will work, need to mess about with it and test
std::string Lox::readFile(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::in | std::ios::binary); // open file in binary mode, prevents newline translation

    if (!file.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        std::exit(64);
    }

    // set file stream to UTF-8 encoding mode
    // - causes error on build???
    // file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<char>));

    std::string fileContents;
    std::string line;

    while (std::getline(file, line))
    {
        fileContents += line;
    }
    file.close();

    return fileContents;
}

void Lox::error(int line, const std::string& message)
{
    Lox::report(line, "", message);
}

void Lox::report(int line, const std::string& where, const std::string& message)
{
    std::cerr << "[Line " << line << "] Error " << where << ": " << message << std::endl;
    Lox::hadError = true;
}

bool Lox::hadError = false;