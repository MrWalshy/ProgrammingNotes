#include "number.h"
#include <string>

LoxNumber::LoxNumber(const double value): backingValue(value) {}

std::string LoxNumber::toString()
{
    return std::to_string(backingValue);
}