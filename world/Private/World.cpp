#include "World.h"

#include <memory>

void OWorld::emerge() {
    while (true) {
        tick();
    }
}

void OWorld::tick() {
    for (std::shared_ptr<OObject> &object :
         objects_) {
        object->tick();
    }
}