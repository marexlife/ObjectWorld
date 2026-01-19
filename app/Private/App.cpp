#include "app/App.h"
#include "window/Window.h"
#include "world/World.h"
#include <expected>
#include <memory>
#include <string_view>

namespace oworld
{
void App::Run()
{
    constexpr int WIDTH = 1800;
    constexpr int HEIGHT = 1000;
    constexpr int X = WIDTH / 5;
    constexpr int Y = HEIGHT / 5;

    bool shouldRun = true;

    if (std::expected<std::unique_ptr<Window>,
                      std::string_view>
            windowResult = Window::TryCreate(
                X, Y, WIDTH, HEIGHT))
    {
        std::unique_ptr<Window> &window =
            *windowResult;
        std::unique_ptr<World> world =
            std::make_unique<World>();

        window->Emerge();
        world->Emerge();

        window->SubscribeWindowShouldClose(
            [&shouldRun] { shouldRun = false; });

        while (shouldRun)
        {
            window->Tick();
            world->Tick();
        }
    }
}

} // namespace oworld