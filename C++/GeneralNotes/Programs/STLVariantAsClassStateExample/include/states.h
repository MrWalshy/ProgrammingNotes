#ifndef STATES_H
#define STATES_H
struct AtGate
{
    int gate;
};

struct Taxi
{
    int lane;
    int numOfPassengers;
};

struct Flying
{
    float speed;
};
#endif