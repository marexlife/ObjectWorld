#include "world/World.h"
#include "object/Object.h"

#include <memory>

void World::emerge() {
    for (std::shared_ptr<Events> &object : events_) {
        object->emerge();
    }
}

void World::tick() {
    for (std::shared_ptr<Events> &object : events_) {
        object->tick();
    }
}
