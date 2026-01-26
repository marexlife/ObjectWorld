#pragma once

#include "Object/Object.h"
#include <memory>

namespace ObjectWorld
{
class App final : public Object
{
  public:
    constexpr static int Width = 1800;
    constexpr static int Height = 1000;
    constexpr static int X = Width / 5;
    constexpr static int Y = Height / 5;

    [[nodiscard]] static App Create()
    {
        return App();
    }

    void Run();

    void EntityEvents(
        std::array<std::unique_ptr<Object>, 2>
            &&events);

    virtual ~App() override = default;

  private:
    bool shouldRun_ = true;

    App()
    {
    }
};
} // namespace ObjectWorld