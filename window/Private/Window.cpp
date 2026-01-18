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
std::expected<std::unique_ptr<Window>, std::string_view> Window::
    TryCreate(int width, int height, std::uint32_t windowFlags)
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int intiErr = SDL_Init(SDL_INIT_EVENTS);

    if (intiErr != 0)
    {
        return std::unexpected(SDL_GetError());
    }

    int creationErr = SDL_CreateWindowAndRenderer(
        width, height, windowFlags, &window, &renderer);

    if (creationErr != 0)
    {
        return std::unexpected(SDL_GetError());
    }

    SDL_ShowWindow(window);

    return std::expected<std::unique_ptr<Window>, std::string_view>(
        std::unique_ptr<Window>(new Window(window, renderer, width,
                                           height, windowFlags)));
}

void Window::Emerge()
{
}

void Window::Tick()
{
    SDL_Event *event = nullptr;

    std::println("Window tick");

    while (SDL_PollEvent(event))
    {
        if (event == nullptr)
        {
            std::println("event is NULL!");

            continue;
        }

        switch (event->type)
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