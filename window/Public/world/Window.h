#pragma once

#include "object/Object.h"
#include <concepts>
#include <memory>
#include <utility>
#include <vector>

class Player;

class Window final : public Events {
  public:
    void emerge() override {}
    void tick() override {}
};