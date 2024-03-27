#include "characters.h"
#include <iostream>

void characters::Hero::cast(const actions::Spell& spell)
{
    std::cout << "Casting spell " << spell.getName() << std::endl;
}