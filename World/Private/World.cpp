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
    for (std::shared_ptr<object::Object>& object :
         objects_) {
        object->Tick();
    }
}
}  // namespace world