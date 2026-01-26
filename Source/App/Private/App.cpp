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
void CApp::Run()
{
    std::expected<std::unique_ptr<CWindow>,
                  std::string_view>
        windowResult = CWindow::TryCreate(
            "Window", X, Y, Width, Height);

    if (windowResult)
    {
        std::unique_ptr<CWorld> world =
            std::make_unique<CWorld>();

        (*windowResult)
            ->SubscribeWindowShouldClose(
                [&] { shouldRun_ = false; });

        world->AddObject<CPlayer>();

        std::array<std::unique_ptr<CObject>, 2>
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

void CApp::EntityEvents(
    std::array<std::unique_ptr<CObject>, 2>
        &&events)
{
    for (std::unique_ptr<CObject> &event : events)
    {
        event->Emerge();
    }

    while (shouldRun_)
    {
        for (std::unique_ptr<CObject> &event :
             events)
        {
            event->Tick();
        }
    }
}
} // namespace ObjectWorld