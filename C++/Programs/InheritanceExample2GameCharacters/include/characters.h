#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <string>
#include "actions.h"

namespace characters
{
    // lol, this being below the Character class causes a whole slew of type errors
    struct Position
    {
        std::string positionIdentifier;
    };

    class Character
    {
        public:
            void moveTo(const Position& position);
    };

    class Hero: public Character
    {
        public:
            void cast(const actions::Spell& spell);
    };
    
    class Enemy: public Character
    {
        public:
            void swingSword();
    };
}
#endif