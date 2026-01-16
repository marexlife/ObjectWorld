#include "object/Macros.h"
#include "player/Player.h"
#include "world/World.h"

class PPlayerCar : public PPlayer {
    OOBJECT(PPlayerCar, PPlayer)

  public:
    void emerge() override {}
    void tick() override {}

    virtual ~PPlayerCar() = default;
};

int main() {
    OWorld().addObject<PPlayerCar>().addObject<PPlayer>().emerge();
}