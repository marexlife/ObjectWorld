#pragma once

#include "Object/Object.h"

namespace ObjectWorld
{
class Player final : public Object
{
  public:
    virtual ~Player() override = default;

  private:
    virtual void Emerge() override;
    virtual void Tick() override;
};
} // namespace ObjectWorld