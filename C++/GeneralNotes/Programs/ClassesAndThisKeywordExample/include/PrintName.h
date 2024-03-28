#ifndef PRINT_NAME_H
#define PRINT_NAME_H
#include <string>

class PrintName
{
    std::string name;

    public:
    void setName(const std::string &name);
    void printName();
};

#endif