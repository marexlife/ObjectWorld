#pragma once

#include "object/Object.h"

class Player final : public Events
{
  private:
    void Emerge() override;
    void Tick() override;
};
