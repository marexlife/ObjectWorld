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
    int initErrorCode = SDL_Init(sdlFlags);

    if (initErrorCode != 0)
    {
        return std::unexpected(
            std::format("Failed to init SDL with "
                        "error code: {}",
                        initErrorCode));
    }

    SDL_Window *window = SDL_CreateWindow(
        windowName.data(), x, y, width, height,
        windowFlags);

    if (window == nullptr)
    {
        return std::unexpected(
            "Failed to create Window");
    }

    SDL_GLContext context =
        SDL_GL_CreateContext(window);

    if (context == nullptr)
    {
        return std::unexpected(
            "Failed to create OpenGL context for "
            "SDL2");
    }

    SDL_ShowWindow(window);

    return std::expected<std::unique_ptr<OWindow>,
                         std::string>(
        std::unique_ptr<OWindow>(new OWindow(
            window, x, y, width, height)));
}

void OWindow::Tick()
{
    SDL_UpdateWindowSurface(window_);
    SDL_Event sdlEvent{};

    if (SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {
        case SDL_QUIT:
            windowShouldClose_.Fire();
            break;
        default:
            break;
        }
    }
}

OWindow::~OWindow()
{
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
} // namespace ObjectWorld