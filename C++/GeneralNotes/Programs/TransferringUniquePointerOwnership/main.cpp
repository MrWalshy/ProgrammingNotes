#include <memory>
#include <utility>
#include <string>
#include <iostream>

struct Player
{
    std::string name;

    Player(std::string name = "player1"): name{name} 
    {
        std::cout << "Created player with name " << name << std::endl;
    }

    ~Player()
    {
        std::cout << "Destroyed player with name " << name << std::endl;
    }
};

void takePlayerOwnership(std::unique_ptr<Player> player)
{
    std::cout << "takePlayerOwnership() invoked on player " << player->name << std::endl;
}

int main()
{
    std::cout << "main() invoked by system" << std::endl;
    auto player1 { std::make_unique<Player>("Bob") };
    auto player2 { std::make_unique<Player>("Fred") };
    std::cout << "player1 " << player1->name << " and player2 " << player2->name << " owned by main() currently" << std::endl;

    takePlayerOwnership(std::move(player1));
    takePlayerOwnership(std::move(player2));

    std::cout << "main() no longer owns player1 and player2, cannot access objects" << std::endl;
}