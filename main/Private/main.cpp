#include "main.h"
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
    std::unique_ptr<oworld::World> world =
        std::make_unique<oworld::World>();

    world->AddObject<oworld::Player>();

    if (std::expected<std::unique_ptr<oworld::Window>,
                      std::string_view>
            windowResult = oworld::Window::TryCreate(1000, 1000))
    {
        oworld::App::Create().Run();
    }
    else
    {
        std::println("{}", windowResult.error());
    }
}