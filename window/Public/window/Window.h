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
    [[nodiscard]] static std::expected<std::unique_ptr<Window>,
                                       std::string_view>
    TryCreate(int width, int height, std::uint32_t windowFlags = 0);

    void Emerge() override;
    void Tick() override;

    void SubscribeWindowShouldClose(
        std::move_only_function<void()> &&f)
    {
        windowShouldClose_.Subscribe(std::move(f));
    }

    Window(Window &&) = default;
    Window &operator=(Window &&) = delete;
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    ~Window() override;

  private:
    std::uint32_t windowFlags_{};
    Event<void> windowShouldClose_{};

    int width_{};
    int height_{};

    SDL_Window *window_{};
    SDL_Renderer *renderer_{};

    Window(SDL_Window *window, SDL_Renderer *renderer, int width,
           int height, std::uint32_t windowFlags)
        : window_(window), renderer_(renderer), width_(0), height_(0),
          windowFlags_(windowFlags)
    {
    }
};
} // namespace oworld