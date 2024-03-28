#include "characters.h"
// #include "actions.h"

using namespace characters;
using namespace actions;

int main()
{
    Spell fireball{"fireball"};
    Position position{"Enemy castle"};
    Hero hero;
    Enemy enemy;

    hero.moveTo(position);
    enemy.moveTo(position);
    hero.cast(fireball);
    enemy.swingSword();

    return 0;
}
// g++ -I include/ -o main *.cpp