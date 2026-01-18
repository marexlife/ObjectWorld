#include "app/App.h"
#include "player/Player.h"
#include "window/Window.h"
#include "world/World.h"
#include <memory>

int main()
{
    std::unique_ptr<World> world = std::make_unique<World>();

    world->AddObject<Player>();

    App()
        .AddObject<World>(std::move(world))
        .AddObject<Window>(500, 100)
        .Run();
}