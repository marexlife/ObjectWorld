#pragma once

#include "world/World.h"

class App final {
  public:
    void run();

  private:
    World world_;
};