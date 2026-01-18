#pragma once

#include "object/Events.h"
#include "window/Window.h"
#include <memory>
#include <vector>

namespace oworld
{
class Events;

class App final
{
  public:
    [[nodiscard]] static App Create()
    {
        return App();
    }

    void Run();

  private:
    App()
    {
    }
};
} // namespace oworld