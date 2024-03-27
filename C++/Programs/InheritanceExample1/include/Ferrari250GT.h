#ifndef FERRARI_250GT_H
#define FERRARI_250GT_H
#include "Vehicle.h"
#include "CollectorItem.h"

class Ferrari250GT: protected Vehicle, public CollectorItem
{
    public:
        Ferrari250GT();
};
#endif