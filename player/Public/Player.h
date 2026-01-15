#pragma once

#include "Object.h"

namespace game {
namespace player {
using object::Object;

class Player final : public Object {
  public:
    void emerge() override {}
    void tick() override {
        std
    }
};
} // namespace player
} // namespace game