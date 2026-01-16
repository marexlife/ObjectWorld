#include "object/Macros.h"
#include "player/Player.h"
#include "world/World.h"

class PPlayerCar : public PPlayer {
    OOBJECT(PPlayerCar, PPlayer)

  public:
    void emerge() override { super().emerge(); }
    void tick() override { super().tick(); }

    virtual ~PPlayerCar() = default;
};

int main() {
    OWorld().addObject<PPlayerCar>().addObject<PPlayer>().emerge();
}