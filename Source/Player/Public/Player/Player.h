#pragma once

#include "Object/Object.h"

namespace ObjectWorld
{
class Player final : public Object
{
  private:
    void Emerge() override;
    void Tick() override;
};
} // namespace ObjectWorld