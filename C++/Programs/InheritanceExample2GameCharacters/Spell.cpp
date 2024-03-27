#include "actions.h"

actions::Spell::Spell(std::string spellName): name(spellName) {}

std::string actions::Spell::getName() const
{
    return this->name;
}