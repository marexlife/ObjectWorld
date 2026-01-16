#include "object/Object.h"
#include "player/Player.h"
#include "world/World.h"

class PlayerCar final : public Events {
  public:
    void emerge() override {}

    void tick() override {}
};

int main() {
    World world = World().addObject<PlayerCar>().addObject<Player>();

    while (true) {
        world.tick();
    }

    world.emerge();
}