#include "AddX.h"

AddX::AddX(int v) : value(v) {}

int AddX::operator()(int other)
{
    return value + other;
}