#include "app/App.h"

void App::run() {
    world_.emerge();

    while (true) {
        world_.tick();
    }
}