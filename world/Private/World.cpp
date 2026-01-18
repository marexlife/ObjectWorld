#include "world/World.h"
#include "object/Object.h"

#include <memory>

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
