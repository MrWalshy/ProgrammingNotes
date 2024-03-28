#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <variant>
#include "states.h"

class Airplane
{
    std::variant<AtGate, Taxi, Flying> state;

    public:
        Airplane(int gate);

        void startTaxi(int lane, int passengers);
        void takeOff(float speed);
        void currentStatus();
};
#endif