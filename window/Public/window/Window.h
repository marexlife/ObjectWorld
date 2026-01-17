#pragma once

#include "object/Object.h"

class Window final : public Events {
  public:
    void emerge() override;
    void tick() override;
};