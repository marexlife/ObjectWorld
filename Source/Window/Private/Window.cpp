#include "Window/Window.h"
#include <exception>
#include <expected>
#include <memory>
#include <print>
#include <string>

namespace ObjectWorld
{
std::expected<std::unique_ptr<CWindow>,
              std::string>
CWindow::TryCreate(std::string /*windowName*/,
                   int /*x*/, int /*y*/,
                   int /*width*/, int /*height*/,
                   std::uint32_t /*sdlFlags*/,
                   std::uint32_t /*windowFlags*/)
{
    std::println("unimplemented!");
    std::terminate();
}

void CWindow::Tick()
{
}

CWindow::~CWindow()
{
}
} // namespace ObjectWorld