#include "World.h"

#include <algorithm>
#include <memory>

namespace Game
{
namespace World
{
void World::Emerge()
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
} // namespace World
} // namespace Game