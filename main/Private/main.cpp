#include "main.h"
#include "app/App.h"
#include <SDL.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_video.h>

int main()
{
    ObjectWorld::App::Create().Run();
}