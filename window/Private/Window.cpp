#include "window/Window.h"
#include "SDL2/SDL.h"
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <expected>
#include <memory>
#include <print>

namespace oworld
{
std::expected<std::unique_ptr<Window>,
              std::string_view>
Window::TryCreate(int width, int height,
                  std::uint32_t windowFlags)
{
    SDL_Init(0);

    SDL_Window *window = SDL_CreateWindow(
        "Window", 0, 0, 1000, 500, 0);

    SDL_ShowWindow(window);

    return std::expected<std::unique_ptr<Window>,
                         std::string_view>(
        std::unique_ptr<Window>(new Window(
            window, width, height, windowFlags)));
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