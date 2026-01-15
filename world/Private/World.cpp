#include "World.h"

#include <generator>
#include <memory>

namespace game {
namespace world {
std::generator<std::monostate> World::emerge() {
    while (true) {
        tick();
    }
}

World &World::addPlayer(
    std::shared_ptr<Player> &&player) {
    players_.emplace_back(std::move(player));

    return *this;
}

void World::tick() {
    for (std::shared_ptr<Player> &player :
         players_) {
    }
}
} // namespace world
} // namespace game