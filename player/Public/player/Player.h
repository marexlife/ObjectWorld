#pragma once

#include "object/Object.h"

class OPlayer final : public OObject {
  public:
    void emerge() override {}
    void tick() override {}

    ~OPlayer() override {}
};