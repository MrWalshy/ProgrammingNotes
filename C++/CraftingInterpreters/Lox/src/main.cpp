#include <iostream>
#include "lox/lox.h"

// handle UTF-8 encoding for Windows and Linux
#ifdef _WIN32
#include <windows.h>
#elif defined(__LINUX__) || defined(__UNIX__) || defined(__APPLE__)
#include <cstdlib>
#endif

// argc is the arg count
// argv is the actual arguments using c-style strings
int main(int argc, char*argv[])
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #elif defined(__LINUX__) || defined(__UNIX__) || defined(__APPLE__)
    std::system("export LANG=en_US.UTF-8");
    #endif

    Lox lox;
    lox.run(argc, argv);

    return EXIT_SUCCESS;
}