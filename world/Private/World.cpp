#include "World.h"

#include <memory>

namespace game {
namespace world {
void World::emerge() {
    while (true) {
        tick();
    }
}

World &World::addObject(
    std::shared_ptr<Object> &&object) {
    objects_.emplace_back(std::move(object));

    return *this;
}

void World::tick() {
    for (std::shared_ptr<Object> &object :
         objects_) {
        object->tick();
    }
}
} // namespace world
} // namespace game