#include "player/Player.h"
#include "world/World.h"
#include <memory>

using player::Player;
using world::World;

int main() {
    auto p1 = std::make_shared<Player>();
    auto p2 = std::make_shared<Player>();

    World()
        .addObject(p1)
        .addObject(p2)
        .emerge();
}