#pragma once

#include "SpecialMath.h"

namespace ObjectWorld
{
class Object
{
  public:
    Object() {}
    /// runs once at emerging of the object
    virtual void Emerge()
    {
    }

    [[nodiscard]] virtual const Vec3 &
    GetPosition() const
    {
        return pos_;
    }

    virtual void SetPosition(const Vec3 &newPos)
    {
        pos_ = newPos;
    }

    /// runs once per frame
    virtual void Tick()
    {
    }

    virtual ~Object()
    {
    }

  private:
    Vec3 pos_;
    Rot3 rot_;
    Vec3 sca_;
};
} // namespace ObjectWorld