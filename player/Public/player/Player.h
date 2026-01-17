#pragma once

#include "object/Object.h"
#include <print>
#include <string_view>

class Player final : public Name, public Events {
  public:
    ~Player() override {}

  private:
    /// runs once at emerging of the object
    void emerge() override {
        std::println("{}: emerge!", getObjectName());
    }

    /// runs once per frame
    void tick() override {}

    std::string_view getObjectName() const override {
        return "Player";
    }
};