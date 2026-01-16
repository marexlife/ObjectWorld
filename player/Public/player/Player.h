#pragma once

#include "object/Object.h"
#include <string_view>

class Player final : public Name, public Events {
  private:
    /// runs once at emerging of the object
    void emerge() override {}

    /// runs once per frame
    void tick() override {}

    std::string_view getObjectName() const override {
        return "Player";
    }

    ~Player() override {}
};