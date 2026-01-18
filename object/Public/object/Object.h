#pragma once

#include <expected>
#include <string_view>

class Name
{
  public:
    [[nodiscard]] virtual std::string_view GetObjectName() const = 0;

    virtual ~Name() = default;
};

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
