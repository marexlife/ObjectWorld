#include "World.h"

#include <memory>

#include "Object.h"

namespace world {
void World::Emerge() {
    while (true) {
        Tick();
    }
}

void World::Tick() {

}
}  // namespace world