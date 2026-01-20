#pragma once

#include <cstdint>
#include <expected>
#include <functional>
#include <memory>

#include "Object/Event.h"
#include "Object/Object.h"

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
        std::move_only_function<void()> &&functor)
    {
        windowShouldClose_.Subscribe(
            std::move(functor));
    }

    OWindow(OWindow &&) = default;

    OWindow &operator=(OWindow &&) = delete;
    OWindow(const OWindow &) = delete;
    OWindow &operator=(const OWindow &) = delete;

    virtual ~OWindow() override;

  private:
    OEvent<void> windowShouldClose_{};

    OWindow(int /*x*/, int /*y*/, int /*width*/,
            int /*height*/)
    {
    }
};
} // namespace ObjectWorld