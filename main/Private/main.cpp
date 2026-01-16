#include "player/Player.h"
#include "world/World.h"
#include <print>

int main() {
    OWorld world = OWorld();

    world.addObject<OPlayer>().addObject<OPlayer>();

    std::println("{}", world.getObjectName());

    world.emerge();
}