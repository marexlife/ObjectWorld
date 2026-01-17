#pragma once

#include "object/Object.h"
#include <print>
#include <string_view>

class Player final : public Events {
  public:
    ~Player() override {}

  private:
    /// runs once at emerging of the object
    void emerge() override { std::println("player emerges!"); }

    /// runs once per frame
    void tick() override {}
};
