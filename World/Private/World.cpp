#include "World.h"

#include <initializer_list>
#include <vector>

namespace world {
void World::Emerge() {
    while (true) {
        Tick();
    }
}

void World::Tick() {}
}  // namespace world