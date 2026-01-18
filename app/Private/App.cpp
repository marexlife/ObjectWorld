#include "app/App.h"
#include "object/Object.h"
#include <memory>

void App::run() {
    for (std::unique_ptr<Events> &event : events_) {
        event->emerge();
    }

    while (true) {
        for (std::unique_ptr<Events> &event : events_) {
            event->tick();
        }
    }
}