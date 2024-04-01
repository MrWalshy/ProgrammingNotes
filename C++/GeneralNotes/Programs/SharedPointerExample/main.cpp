#include <iostream>
#include <string>
#include <memory>

class Player
{
    private:
        std::string name;

    public:
        Player(std::string name, int id): name(name), id(id) 
        {
            std::cout << "Constructing player " << name << std::endl;
        }

        ~Player()
        {
            std::cout << "Destroying player " << name << std::endl;
        }

        std::string getName() const
        {
            return name;
        }

        const int id;
};

void printPlayerName(std::shared_ptr<Player> player)
{
    std::cout << player->getName() << std::endl;
    std::cout << "Number of owners of player: " << player.use_count() << std::endl;
}

int main()
{
    auto player1 { std::make_shared<Player>("Bob", 1) };
    printPlayerName(player1);
    std::cout << "Back in main()" << std::endl;
    
    std::cout << "Owners: " << player1.use_count() << std::endl;

    std::shared_ptr<const int> playerId(player1, &player1->id);
    std::cout << "Player ID: " << *playerId << std::endl;
    std::cout << "Owners: " << player1.use_count() << std::endl;
}