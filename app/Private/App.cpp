#include "app/App.h"
#include "object/Events.h"
#include "window/Window.h"
#include <expected>
#include <memory>
#include <string_view>

namespace oworld
{
void App::Run()
{
    bool shouldRun = true;

    if (std::expected<std::unique_ptr<Window>, std::string_view>
            windowResult = Window::TryCreate(1000, 1000))
    {
        std::unique_ptr<Window> &window = *windowResult;

        window->Emerge();
        window->SubscribeWindowShouldClose(
            [&shouldRun] { shouldRun = false; });

        while (shouldRun)
        {
            window->Tick();
        }
    }
}

} // namespace oworld