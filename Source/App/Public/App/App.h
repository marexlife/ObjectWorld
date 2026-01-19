#pragma once

#include "Object/Object.h"
#include <memory>

namespace ObjectWorld
{
class OApp final : public OObject
{
  public:
    constexpr static int Width = 1800;
    constexpr static int Height = 1000;
    constexpr static int X = Width / 5;
    constexpr static int Y = Height / 5;

    [[nodiscard]] static OApp Create()
    {
        return OApp();
    }

    void Run();

    void EntityEvents(
        std::array<std::unique_ptr<OObject>, 2>
            &&events);

    virtual ~OApp() override = default;

  private:
    bool shouldRun_ = true;

    OApp()
    {
    }
};
} // namespace ObjectWorld