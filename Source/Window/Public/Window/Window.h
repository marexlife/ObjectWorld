#pragma once

#include <cstdint>
#include <expected>
#include <functional>
#include <memory>

#include "Object/Event.h"
#include "Object/Object.h"

namespace ObjectWorld
{
class CWindow final : public Object
{
  public:
    [[nodiscard]] static std::expected<
        std::unique_ptr<CWindow>, std::string>
    TryCreate(std::string windowName, int x,
              int y, int width, int height,
              std::uint32_t sdlFlags = 0,
              std::uint32_t windowFlags = 0);

    virtual void Tick() override;

    void SubscribeWindowShouldClose(
        std::move_only_function<void()> &&functor)
    {
        windowShouldClose_.Subscribe(
            std::move(functor));
    }

    CWindow(CWindow &&) = default;

    CWindow &operator=(CWindow &&) = delete;
    CWindow(const CWindow &) = delete;
    CWindow &operator=(const CWindow &) = delete;

    virtual ~CWindow() override;

  private:
    Event<void> windowShouldClose_{};

    CWindow(int /*x*/, int /*y*/, int /*width*/,
            int /*height*/)
    {
    }
};
} // namespace ObjectWorld