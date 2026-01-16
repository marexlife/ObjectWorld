#include "World.h"

#include <generator>
#include <memory>

namespace game {
namespace World {
std::generator<std::monostate>
OWorld::emerge() {
    while (true) {
        tick();
    }
}

OWorld &World::addPlayer(
    std::shared_ptr<OPlayer> &&player) {
    players_.emplace_back(std::move(player));

    return *this;
}

void World::tick() {
    for (std::shared_ptr<Player> &player :
         players_) {
    }
}
} // namespace World
} // namespace game