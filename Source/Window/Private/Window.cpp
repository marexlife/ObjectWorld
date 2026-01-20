#include "Window/Window.h"
#include <exception>
#include <expected>
#include <memory>
#include <print>
#include <string>

namespace ObjectWorld
{
std::expected<std::unique_ptr<OWindow>,
              std::string>
OWindow::TryCreate(std::string /*windowName*/,
                   int /*x*/, int /*y*/,
                   int /*width*/, int /*height*/,
                   std::uint32_t /*sdlFlags*/,
                   std::uint32_t /*windowFlags*/)
{
    std::println("unimplemented!");
    std::terminate();
}

void OWindow::Tick()
{
}

OWindow::~OWindow()
{
}
} // namespace ObjectWorld