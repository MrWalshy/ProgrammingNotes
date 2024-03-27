#ifndef ACTIONS_H
#define ACTIONS_H
#include <string>

namespace actions
{
    class Spell
    {
        public:
            Spell(std::string name);

            std::string getName() const;

        private:
            std::string name;
    };
}
#endif