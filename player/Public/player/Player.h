#pragma once

#include "object/Object.h"

namespace player {
using object::Object;

class Player final : public Object {
  public:
    void emerge() override {}
    void tick() override {}
};
} // namespace player