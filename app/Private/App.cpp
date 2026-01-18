#include "app/App.h"
#include <memory>

void App::Run()
{
    for (std::unique_ptr<Events> &event : events_)
    {
        event->Emerge();
    }

    while (true)
    {
        for (std::unique_ptr<Events> &event : events_)
        {
            event->Tick();
        }
    }
}