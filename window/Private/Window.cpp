#include "window/Window.h"
#include "SDL2/SDL.h"
#include <SDL_render.h>
#include <SDL_video.h>

Window::Window(int width, int height, std::uint32_t windowFlags)
    : window_(nullptr), renderer_(nullptr), width_(0), height_(0)
{
}

void Window::Emerge()
{
    int intiErr = SDL_Init(SDL_INIT_VIDEO);

    if (intiErr != 0)
    {
    }

    SDL_CreateWindowAndRenderer(width_, height_, windowFlags,
                                &window_, &renderer_);

    SDL_ShowWindow(window_);
}

void Window::Tick()
{
}

Window::~Window()
{
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
