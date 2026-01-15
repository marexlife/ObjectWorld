#include "World.h"

#include <memory>

void World::emerge() {
    while (true) {
        tick();
    }
}

void World::tick() {
    for (std::shared_ptr<Object> &object :
         objects_) {
        object->tick();
    }
}