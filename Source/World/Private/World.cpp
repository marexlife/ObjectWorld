#include "World/World.h"
#include "Object/Object.h"

#include <memory>

namespace ObjectWorld
{
void CWorld::Emerge()
{
    for (std::shared_ptr<CObject> &object :
         events_)
    {
        object->Emerge();
    }
}

void CWorld::Tick()
{
    for (std::shared_ptr<CObject> &object :
         events_)
    {
        object->Tick();
    }
}
} // namespace ObjectWorld
