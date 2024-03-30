#include <iostream>
#include "Random.h"

namespace Random
{
    // anon namespace to hide internal variables
    namespace
    {
        std::random_device seeder;
        unsigned int seed { seeder() };
        std::mt19937 engine { seed };
    }

    int integer(int min, int max)
    {
        std::uniform_int_distribution get { min, max };
        return get(engine);
    }

    bool boolean(float probability)
    {
        std::uniform_real_distribution get { 0.0, 1.0 };
        return probability > get(engine);
    }

    void printSeed()
    {
        std::cout << seed;
    }

    void reseed(unsigned int newSeed)
    {
        seed = newSeed;
        engine.seed(newSeed);
    }
}