#include "Airplane.h"
#include <iostream>

Airplane::Airplane(int gate): state(AtGate{gate}) {}

void Airplane::startTaxi(int lane, int passengers)
{
    if (std::holds_alternative<AtGate>(state))
    {
        state = Taxi{lane, passengers};
        std::cout << "Plane on taxi to lane " << lane << "with " << passengers << " passengers." << std::endl;
    }
    else
    {
        std::cout << "Plane is not at gate, cannot taxi." << std::endl;
    }
}

void Airplane::takeOff(float speed)
{
    if (!std::holds_alternative<Taxi>(state))
    {
        std::cout << "Plane is not in taxi, cannot take off" << std::endl;
        return;
    }
    state = Flying{speed};
    std::cout << "Plane is taking off with flight speed of " << speed << std::endl;
}

void Airplane::currentStatus()
{
    // visitor class with operator() overloads for the different states would be preferable
    if (std::holds_alternative<AtGate>(state))
    {
        std::cout << "Plane is at gate " << std::get<AtGate>(state).gate << std::endl;
    }
    else if (std::holds_alternative<Taxi>(state))
    {
        std::cout << "Plane is currently in taxi process to lane " << std::get<Taxi>(state).lane << std::endl;
    }
    else if (std::holds_alternative<Flying>(state))
    {
        std::cout << "Plane is flying with air speed of " << std::get<Flying>(state).speed << std::endl;
    }
    else
    {
        std::cout << "Plane has unknown state" << std::endl;
    }
}