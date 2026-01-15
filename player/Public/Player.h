#pragma once

#include "Object.h"

class Player final : public Object {
  public:
    void emerge() override {}
    void tick() override {}

    ~Player() override {}
};