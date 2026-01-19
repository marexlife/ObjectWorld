#pragma once

#include <expected>
#include <string_view>
#include <type_traits>

namespace ObjectWorld
{
template <typename NumType>
    requires std::is_arithmetic_v<NumType>
struct TVector final
{
    explicit TVector()
    {
    }

    [[nodiscard]] TVector operator+(
        const TVector &other)
    {
        return TVector(x + other.x, y + other.y,
                       z + other.z);
    }

    [[nodiscard]] TVector operator-(
        const TVector &other)
    {
        return TVector(x - other.x, y - other.y,
                       z - other.z);
    }

    [[nodiscard]] TVector operator*(
        const TVector &other)
    {
        return TVector(x * other.x, y * other.y,
                       z * other.z);
    }

    [[nodiscard]] std::expected<void,
                                std::string_view>
    operator/(const TVector &other)
    {
        if (other.x == 0 || other.y == 0 ||
            other.z == 0) [[unlikely]]
        {
            return std::unexpected(
                "division by zero");
        }

        return TVector(x / other.x, y / other.y,
                       z / other.z);
    }

    explicit TVector(const TVector &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    void operator=(const TVector &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    void operator+=(const TVector &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void operator-=(const TVector &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    void operator*=(const TVector &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }

    [[nodiscard]] std::expected<void,
                                std::string_view>
    operator/=(const TVector &other)
    {
        if (other.x == 0 || other.y == 0 ||
            other.z == 0) [[unlikely]]
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

using SVector = TVector<float>;

template <typename NumType>
    requires std::is_arithmetic_v<NumType>
struct TRotator final
{
    void operator+=(const TRotator &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void operator-=(const TRotator &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    void operator*=(const TRotator &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }

    [[nodiscard]] std::expected<void,
                                std::string_view>
    operator/=(const TRotator &other)
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

using SRotator = TRotator<float>;
} // namespace ObjectWorld