#pragma once

#include "object/Object.h"

class Player final : public Events {
  private:
    void emerge() override;
    void tick() override;
};
