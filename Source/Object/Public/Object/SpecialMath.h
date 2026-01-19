#pragma once

#include <type_traits>
namespace ObjectWorld
{
template <typename NumType>
    requires std::is_arithmetic_v<NumType>
struct TVec3 final
{
    NumType x;
    NumType y;
    NumType z;
};
} // namespace ObjectWorld