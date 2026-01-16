#include "object/Macros.h"
#include "player/Player.h"
#include "world/World.h"

class PPlayerCar : public PPlayer {
    OOBJECT(PPlayerCar, PPlayer)

  public:
    void emerge() override { Super::emerge(); }

    void tick() override { Super::tick(); }

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