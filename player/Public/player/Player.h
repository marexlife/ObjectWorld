#pragma once

#include "object/Events.h"

namespace oworld
{
class Player final : public Events
{
  private:
    void Emerge() override;
    void Tick() override;
};
} // namespace oworld