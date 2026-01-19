#include "World/World.h"
#include "Object/Object.h"

#include <memory>

namespace ObjectWorld
{
void World::Emerge()
{
    for (std::shared_ptr<OObject> &object :
         events_)
    {
        object->Emerge();
    }
}

void World::Tick()
{
    for (std::shared_ptr<OObject> &object :
         events_)
    {
        object->Tick();
    }
}
} // namespace ObjectWorld
