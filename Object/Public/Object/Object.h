#pragma once

#include <functional>
#include <vector>

namespace ObjectWorld
{
class Object
{
  public:
    /// runs once at emerging of the object
    virtual void Emerge()
    {
    }

    /// runs once per frame
    virtual void Tick()
    {
    }

    virtual ~Object()
    {
    }
};
} // namespace ObjectWorld