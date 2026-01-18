#include "app/App.h"
#include "object/Events.h"
#include <memory>

namespace oworld
{
void App::Run()
{
    for (std::unique_ptr<Events> &event : events_)
    {
        event->Emerge();
    }

    while (shouldRun_)
    {
        for (std::unique_ptr<Events> &event : events_)
        {
            event->Tick();
        }
    }
}

void App::RequestClose()
{
    shouldRun_ = false;
}
} // namespace oworld