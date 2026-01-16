#include "object/Macros.h"
#include "player/Player.h"
#include "world/World.h"

class PPlayerCar : public PPlayer {
    OOBJECT(PPlayerCar, PPlayer)

  public:
    void emerge() override {
        std::println("{}: emerge", getObjectName());
    }

    void tick() override {
        std::println("{}: tick", getObjectName());
    }

    virtual ~PPlayerCar() = default;
};

int main() {
    OWorld world =
        OWorld().addObject<PPlayerCar>().addObject<PPlayer>();

    while (true) {
        world.tick();
    }

    world.emerge();
}