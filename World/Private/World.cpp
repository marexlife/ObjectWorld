#include "World.h"

#include <memory>

namespace world {
void World::Emerge() {
    while (true) {
        Tick();
    }
}

void World::Tick() {}
}  // namespace world