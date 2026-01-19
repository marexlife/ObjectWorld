#include "app/App.h"
#include "window/Window.h"
#include "world/World.h"
#include <expected>
#include <memory>
#include <string_view>

namespace ObjectWorld
{
void App::Run()
{
    if (std::expected<std::unique_ptr<Window>,
                      std::string_view>
            windowResult = Window::TryCreate(
                "Window", X, Y, Width, Height))
    {
        std::unique_ptr<Window> &window =
            *windowResult;
        std::unique_ptr<World> world =
            std::make_unique<World>();

        window->Emerge();
        world->Emerge();

        window->SubscribeWindowShouldClose(
            [&] { self.shouldRun = false; });

        while (shouldRun)
        {
            window->Tick();
            world->Tick();
        }
    }
}

} // namespace ObjectWorld