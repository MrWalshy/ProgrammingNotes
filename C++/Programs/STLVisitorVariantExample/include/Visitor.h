#ifndef VISITOR_H
#define VISITOR_H
#include <string>

struct Visitor
{
    void operator()(const std::string& value);
    void operator()(const int& value);
};
#endif