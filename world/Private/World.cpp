#include "world/World.h"
#include "object/Object.h"

#include <memory>

void World::emerge() {
    for (std::shared_ptr<Events> &object : objects_) {
        object->emerge();
    }
}

void World::tick() {
    for (std::shared_ptr<Events> &object : objects_) {
        object->tick();
    }
}