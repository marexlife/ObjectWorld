#pragma once

#include <expected>
#include <string_view>
#include <type_traits>

namespace ObjectWorld
{
template <typename NumType>
    requires std::is_arithmetic_v<NumType>
struct TVec3 final
{
    explicit TVec3()
    {
    }

    [[nodiscard]] TVec3 operator+(
        const TVec3 &other)
    {
        return TVec3(x + other.x, y + other.y,
                     z + other.z);
    }

    [[nodiscard]] TVec3 operator-(
        const TVec3 &other)
    {
        return TVec3(x - other.x, y - other.y,
                     z - other.z);
    }

    [[nodiscard]] TVec3 operator*(
        const TVec3 &other)
    {
        return TVec3(x * other.x, y * other.y,
                     z * other.z);
    }

    [[nodiscard]] TVec3 operator/(
        const TVec3 &other)
    {
        return TVec3(x / other.x, y / other.y,
                     z / other.z);
    }

    explicit TVec3(const TVec3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    TVec3 &operator=(const TVec3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    void operator+=(const TVec3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void operator-=(const TVec3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    void operator*=(const TVec3 &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }

    [[nodiscard]] std::expected<void,
                                std::string_view>
    operator/=(const TVec3 &other)
    {
        if (other.x == 0 || other.y == 0 ||
            other.z == 0)
        {
            return std::unexpected(
                "division by zero");
        }

        x /= other.x;
        y /= other.y;
        z /= other.z;

        return std::expected<void,
                             std::string_view>();
    }

    NumType x{};
    NumType y{};
    NumType z{};
};

using Vec3 = TVec3<float>;

template <typename NumType>
    requires std::is_arithmetic_v<NumType>
struct TRot3 final
{
    void operator+=(const TRot3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void operator-=(const TRot3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    void operator*=(const TRot3 &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }

    [[nodiscard]] std::expected<void,
                                std::string_view>
    operator/=(const TRot3 &other)
    {
        if (other.x == 0 || other.y == 0 ||
            other.z == 0)
        {
            return std::unexpected(
                "division by zero");
        }

        x *= other.x;
        y *= other.y;
        z *= other.z;

        return std::expected<void,
                             std::string_view>();
    }

    NumType x;
    NumType y;
    NumType z;
};

using Rot3 = TRot3<float>;
} // namespace ObjectWorld