#pragma once

#include <string_view>

namespace ObjectWorld
{
class IName
{
  public:
    [[nodiscard]] virtual std::string_view
    GetObjectName() const = 0;

    virtual ~IName() = default;
};
} // namespace ObjectWorld