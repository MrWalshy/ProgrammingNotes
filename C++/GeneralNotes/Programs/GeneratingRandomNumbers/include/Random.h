#include <random>

namespace Random
{
    int integer(int min, int max);
    bool boolean(float probability);
    void printSeed();
    void reseed(unsigned int seed);
}