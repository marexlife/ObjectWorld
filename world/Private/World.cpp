#include "world/World.h"

#include <memory>

namespace world {
void World::emerge() {
    while (true) {
        tick();
    }
}


void World::tick() {
    for (std::shared_ptr<Object>
             &object : objects_) {
        object->tick();
    }
}
} // namespace world