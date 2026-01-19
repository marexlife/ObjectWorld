#include "Window/Window.h"
#include "SDL2/SDL.h"
#include "SDL_events.h"
#include <SDL_error.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <expected>
#include <format>
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
 
}

void OWindow::Tick()
{

}

OWindow::~OWindow()
{
}
} // namespace ObjectWorld