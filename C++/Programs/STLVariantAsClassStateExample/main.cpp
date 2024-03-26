#include "Airplane.h"

int main()
{
    Airplane airplane(1);
    airplane.currentStatus();
    airplane.startTaxi(2, 342);
    airplane.currentStatus();
    airplane.takeOff(330);
    airplane.currentStatus();
    airplane.startTaxi(3, 448);

    return 0;
}
// g++ -I include/ -o main main.cpp Airplane.cpp