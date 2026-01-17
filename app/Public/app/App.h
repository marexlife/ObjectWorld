#pragma once

#include "window/Window.h"
#include "world/World.h"

class App final {
  public:
    App() : world_{} {}

    void run();

  private:
    Window window_{};
    World world_{};
};