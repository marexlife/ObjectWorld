#include "window/Window.h"
#include "SDL2/SDL.h"
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <expected>
#include <memory>
#include <string_view>

namespace oworld
{
std::expected<std::unique_ptr<Window>,
              std::string_view>
Window::TryCreate(std::string_view windowName,
                  int x, int y, int width,
                  int height,
                  std::uint32_t windowFlags)
{
    SDL_Init(0);

    SDL_Window *window = SDL_CreateWindow(
        windowName.data(), x, y, width, height,
        windowFlags);

    SDL_ShowWindow(window);

    return std::expected<std::unique_ptr<Window>,
                         std::string_view>(
        std::unique_ptr<Window>(
            new Window(window, x, y, width,
                       height, windowFlags)));
}

void Window::Emerge()
{
}

void Window::Tick()
{
    SDL_UpdateWindowSurface(window_);

    if (SDL_Event event; SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            windowShouldClose_.Fire();
            break;
        default:
            break;
        }
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
} // namespace oworld