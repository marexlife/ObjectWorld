#include "main.h"
#include <SDL.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_video.h>

int main()
{
    SDL_Init(0);

    SDL_Window *window = SDL_CreateWindow(
        "Window", 0, 0, 1000, 500, 0);

    SDL_ShowWindow(window);

    while (true)
    {
        SDL_UpdateWindowSurface(window);

        if (SDL_Event event;
            SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}