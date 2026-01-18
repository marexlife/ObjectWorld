#pragma once

class Events
{
  public:
    /// runs once at emerging of the object
    virtual void Emerge() = 0;

    /// runs once per frame
    virtual void Tick() = 0;

    virtual ~Events()
    {
    }
};
