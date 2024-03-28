#include "lox_string.h"

LoxString::LoxString(const std::string value): backingValue(value) {}

std::string LoxString::toString()
{
    return backingValue;
}