#pragma once

#include "Object/Object.h"
#include <memory>

namespace ObjectWorld
{
class CApp final : public CObject
{
  public:
    constexpr static int Width = 1800;
    constexpr static int Height = 1000;
    constexpr static int X = Width / 5;
    constexpr static int Y = Height / 5;

    [[nodiscard]] static CApp Create()
    {
        return CApp();
    }

    void Run();

    void EntityEvents(
        std::array<std::unique_ptr<CObject>, 2>
            &&events);

    virtual ~CApp() override = default;

  private:
    bool shouldRun_ = true;

    CApp()
    {
    }
};
} // namespace ObjectWorld