#pragma once

#include <cstdint>
#include <expected>
#include <functional>
#include <memory>

#include "Object/Event.h"
#include "Object/Object.h"

struct SDL_Window;
struct SDL_Renderer;

namespace ObjectWorld
{
class OWindow final : public OObject
{
  public:
    [[nodiscard]] static std::expected<
        std::unique_ptr<OWindow>, std::string>
    TryCreate(std::string windowName, int x,
              int y, int width, int height,
              std::uint32_t sdlFlags = 0,
              std::uint32_t windowFlags = 0);

    virtual void Tick() override;

    void SubscribeWindowShouldClose(
        std::move_only_function<void()> &&f)
    {
        windowShouldClose_.Subscribe(
            std::move(f));
    }

    OWindow(OWindow &&) = default;
    OWindow &operator=(OWindow &&) = delete;
    OWindow(const OWindow &) = delete;
    OWindow &operator=(const OWindow &) = delete;

    virtual ~OWindow() override;

  private:
    SDL_Window *window_{};

    int x_{};
    int y_{};
    int width_{};
    int height_{};

    OEvent<void> windowShouldClose_{};

    OWindow(SDL_Window *window, int x, int y,
            int width, int height)
        : x_(x), y_(y), window_(window),
          width_(width), height_(height)
    {
    }
};
} // namespace ObjectWorld