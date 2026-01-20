#include "Window/Window.h"
#include <expected>
#include <memory>
#include <string>

namespace ObjectWorld
{
std::expected<std::unique_ptr<OWindow>,
              std::string>
OWindow::TryCreate(std::string windowName, int x,
                   int y, int width, int height,
                   std::uint32_t sdlFlags,
                   std::uint32_t windowFlags)
{
    return std::expected<std::unique_ptr<OWindow>,
                         std::string>();
}

void OWindow::Tick()
{
}

OWindow::~OWindow()
{
}
} // namespace ObjectWorld