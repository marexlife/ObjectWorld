#include "app/App.h"
#include "player/Player.h"
#include "window/Window.h"
#include "world/World.h"
#include <expected>
#include <memory>
#include <print>
#include <string_view>

int main()
{
    std::unique_ptr<World> world = std::make_unique<World>();

    world->AddObject<Player>();

    if (std::expected<std::unique_ptr<Window>, std::string_view>
            windowResult = Window::TryCreate(1000, 1000))
    {
        App::Create().AddObject<World>(std::move(world)).Run();
    }
    else
    {
        std::println("{}", windowResult.error());
    }
}