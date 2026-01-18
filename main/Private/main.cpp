#include "app/App.h"
#include "player/Player.h"
#include "window/Window.h"
#include "world/World.h"
#include <memory>

int main() {
    std::unique_ptr<World> world = std::make_unique<World>();

    world->addObject<Player>();

    App{}
        .addObject<World>(std::move(world))
        .addObject<Window>()
        .run();
}