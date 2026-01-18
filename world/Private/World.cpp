#include "world/World.h"
#include "object/Events.h"

#include <memory>

namespace oworld
{
void World::Emerge()
{
    for (std::shared_ptr<Events> &object : events_)
    {
        object->Emerge();
    }
}

void World::Tick()
{
    for (std::shared_ptr<Events> &object : events_)
    {
        object->Tick();
    }
}
} // namespace oworld
