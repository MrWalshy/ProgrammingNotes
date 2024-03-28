#ifndef LOX_STRING_H
#define LOX_STRING_H
#include <string>
#include "object.h"

class LoxString: public Object
{
    public:
        LoxString(const std::string value);
        virtual std::string toString() override;

    private:
        const std::string backingValue;
};
#endif