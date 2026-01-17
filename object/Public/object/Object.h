#pragma once

#include <memory>
#include <string_view>
#include <vector>

class Name {
  public:
    [[nodiscard]] virtual std::string_view getObjectName() const = 0;

    virtual ~Name() = default;
};

class Events {
  public:
    /// runs once at emerging of the object
    virtual void emerge() = 0;

    /// runs once per frame
    virtual void tick() = 0;

    virtual ~Events() = default;
};
