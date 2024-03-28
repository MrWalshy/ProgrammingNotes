#ifndef LOX_NUMBER_H
#define LOX_NUMBER_H
#include "object.h"

class LoxNumber: public Object
{
    public:
        LoxNumber(const double value);
        virtual std::string toString() override;

    private:
        const double backingValue;
};
#endif