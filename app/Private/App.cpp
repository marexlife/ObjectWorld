#include "app/App.h"
#include "player/Player.h"

void App::run() {
    world_.addObject<Player>();

    world_.emerge();

    while (true) {
        world_.tick();
    }
}