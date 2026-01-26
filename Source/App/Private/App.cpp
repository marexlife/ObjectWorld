#include "App/App.h"
#include "Object/Object.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include "World/World.h"
#include <array>
#include <expected>
#include <memory>
#include <print>
#include <string_view>
#include <utility>

namespace ObjectWorld
{
void App::Run()
{
    std::expected<std::unique_ptr<CWindow>,
                  std::string_view>
        windowResult = CWindow::TryCreate(
            "Window", X, Y, Width, Height);

    if (windowResult)
    {
        std::unique_ptr<World> world =
            std::make_unique<World>();

        (*windowResult)
            ->SubscribeWindowShouldClose(
                [&] { shouldRun_ = false; });

        world->AddObject<Player>();

        std::array<std::unique_ptr<Object>, 2>
            events{
                std::move(world),
                std::move(*windowResult),
            };

        EntityEvents(std::move(events));
    }
    else
    {
        std::println("{}", windowResult.error());
    }
}

void App::EntityEvents(
    std::array<std::unique_ptr<Object>, 2>
        &&events)
{
    for (std::unique_ptr<Object> &event : events)
    {
        event->Emerge();
    }

    while (shouldRun_)
    {
        for (std::unique_ptr<Object> &event :
             events)
        {
            event->Tick();
        }
    }
}
} // namespace ObjectWorld