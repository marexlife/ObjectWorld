#include "world/World.h"
#include "object/Events.h"

#include <memory>

namespace ObjectWorld
{
void World::Emerge()
{
    for (std::shared_ptr<Object> &object :
         events_)
    {
        object->Emerge();
    }
}

void World::Tick()
{
    for (std::shared_ptr<Object> &object :
         events_)
    {
        object->Tick();
    }
}
} // namespace ObjectWorld
