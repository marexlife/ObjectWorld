#pragma once

#include "SpecialMath.h"

namespace ObjectWorld
{
class OObject
{
  public:
    OObject()
    {
    }
    /// runs once at emerging of the object
    virtual void Emerge()
    {
    }

    [[nodiscard]] virtual const SVector &
    GetPosition() const
    {
        return pos_;
    }

    virtual void SetPosition(
        const SVector &newPos)
    {
        pos_ = newPos;
    }

    /// runs once per frame
    virtual void Tick()
    {
    }

    virtual ~OObject()
    {
    }

  private:
    SVector pos_;
    SRotator rot_;
    SVector sca_;
};
} // namespace ObjectWorld