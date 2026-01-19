#pragma once

#include "Object/Object.h"

namespace ObjectWorld
{
class Player final : public Object
{
  private:
    virtual void Emerge() override;
    virtual void Tick() override;

    virtual ~Player() override = default;
};
} // namespace ObjectWorld