#pragma once

#include "world/World.h"

class App final {
  public:
    App() : world_{} {}

    void run();

  private:
    World world_{};
};