#include <iostream>
#include <string>

int main()
{
    // c-string
    const char charString[4] = {'C', '+', '+', '\0'};

    // construct c-string from a literal string, compiler auto adds \0 to the end
    const char* literalString = "C++ Fundamentals";

    // can also construct c-string using function on std string, and convert literals to std strings
    std::string strString = literalString;
    const char* charString2 = strString.c_str();

    std::cout << charString << std::endl;
    std::cout << charString2 << std::endl;

    return EXIT_SUCCESS;
}