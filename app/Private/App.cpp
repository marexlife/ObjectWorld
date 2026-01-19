#include "app/App.h"
#include "object/Events.h"
#include "spdlog/spdlog.h"
#include "window/Window.h"
#include "world/World.h"
#include <array>
#include <expected>
#include <memory>
#include <string_view>
#include <utility>

namespace ObjectWorld
{
void App::Run()
{
    if (std::expected<std::unique_ptr<Window>,
                      std::string_view>
            windowResult = Window::TryCreate(
                "Window", X, Y, Width, Height))
    {
        (*windowResult)
            ->SubscribeWindowShouldClose(
                [&] { shouldRun_ = false; });

        std::array<std::unique_ptr<Events>, 2>
            events{
                std::make_unique<World>(),
                std::move(*windowResult),
            };

        EntityEvents(std::move(events));
    }
    else
    {
        spdlog::error(std::format(
            "{}", windowResult.error()));
    }
}

void App::EntityEvents(
    std::array<std::unique_ptr<Events>, 2>
        &&events)
{
    for (std::unique_ptr<Events> &event : events)
    {
        event->Emerge();
    }

    while (shouldRun_)
    {
        for (std::unique_ptr<Events> &event :
             events)
        {
            event->Tick();
        }
    }
}
} // namespace ObjectWorld