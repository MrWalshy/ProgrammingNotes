#include "characters.h"
#include <iostream>

void characters::Character::moveTo(const characters::Position& position)
{
    std::cout << "Moved to position " << position.positionIdentifier << std::endl;
}