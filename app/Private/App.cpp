#include "app/App.h"
#include "player/Player.h"
#include "window/Window.h"

void App::run() {
    world_.addObject<Player>();
    world_.addObject<Window>();

    world_.emerge();

    while (true) {
        world_.tick();
    }
}