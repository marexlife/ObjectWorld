#pragma once

#include <cstdint>

#include "object/Object.h"

struct SDL_Window;
struct SDL_Renderer;

class Window final : public Events
{
  public:
    Window(int width, int height, std::uint32_t windowFlags = 0);

    void Emerge() override;
    void Tick() override;

    ~Window() override;

  private:
    SDL_Window *window_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    std::uint32_t windowFlags;

    int width_ = 0;
    int height_ = 0;
};