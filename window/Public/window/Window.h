#pragma once

#include <cstdint>
#include <expected>
#include <functional>
#include <memory>
#include <string_view>

#include "object/Events.h"

struct SDL_Window;
struct SDL_Renderer;

namespace oworld
{
class Window final : public Events
{
  public:
    [[nodiscard]] static std::expected<
        std::unique_ptr<Window>, std::string>
    TryCreate(std::string_view windowName, int x,
              int y, int width, int height,
              std::uint32_t sdlFlags = 0,
              std::uint32_t windowFlags = 0);

    void Emerge() override;
    void Tick() override;

    void SubscribeWindowShouldClose(
        std::move_only_function<void()> &&f)
    {
        windowShouldClose_.Subscribe(
            std::move(f));
    }

    Window(Window &&) = default;
    Window &operator=(Window &&) = delete;
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    ~Window() override;

  private:
    SDL_Window *window_{};

    int x_{};
    int y_{};
    int width_{};
    int height_{};

    Event<void> windowShouldClose_{};

    Window(SDL_Window *window, int x, int y,
           int width, int height)
        : x_(x), y_(y), window_(window),
          width_(width), height_(height)
    {
    }
};
} // namespace oworld