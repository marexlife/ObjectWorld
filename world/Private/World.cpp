#include "world/World.h"

#include <memory>

void OWorld::emerge() {
    for (std::shared_ptr<OObject> &object : objects_) {
        object->emerge();
    }
}

void OWorld::tick() {
    for (std::shared_ptr<OObject> &object : objects_) {
        object->tick();
    }
}