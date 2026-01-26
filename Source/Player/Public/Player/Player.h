#pragma once

#include "Object/Object.h"

namespace ObjectWorld
{
class CPlayer final : public CObject
{
  public:
    virtual ~CPlayer() override = default;

  private:
    virtual void Emerge() override;
    virtual void Tick() override;
};
} // namespace ObjectWorld