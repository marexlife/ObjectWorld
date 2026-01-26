#pragma once

#include <string_view>

namespace ObjectWorld
{
class Name
{
  public:
    [[nodiscard]] virtual std::string_view
    GetObjectName() const = 0;

    virtual ~Name() = default;
};
} // namespace ObjectWorld