#pragma once

#include "object/Events.h"

class Player final : public Events
{
  private:
    void Emerge() override;
    void Tick() override;
};
