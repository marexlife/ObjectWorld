#include "World.h"

#include <generator>
#include <memory>

namespace game
{
namespace world
{
std::generator<std::monostate> World::Emerge()
{
    while (true)
    {
        Tick();
    }
}

World &World::AddPlayer(
    std::shared_ptr<Player> &&player)
{
    players_.emplace_back(std::move(player));

    return *this;
}

void World::Tick()
{
    for (std::shared_ptr<Player> &player :
         players_)
    {
    }
}
} // namespace world
} // namespace game