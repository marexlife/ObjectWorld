#pragma once

#include <exception>
#include <expected>
#include <print>
#include <stdexcept>
#include <string_view>
#include <type_traits>

namespace ObjectWorld
{
template <typename NumType>
    requires std::is_arithmetic_v<NumType>
struct Vector final
{
    explicit Vector()
    {
    }

    [[nodiscard]] Vector operator+(
        const Vector &other)
    {
        return Vector(x + other.x, y + other.y,
                      z + other.z);
    }

    [[nodiscard]] Vector operator-(
        const Vector &other)
    {
        return Vector(x - other.x, y - other.y,
                      z - other.z);
    }

    [[nodiscard]] Vector operator*(
        const Vector &other)
    {
        return Vector(x * other.x, y * other.y,
                      z * other.z);
    }

    Vector operator/(const Vector &other)
    {
        if (other.x == 0 || other.y == 0 ||
            other.z == 0) [[unlikely]]
        {
            std::println("division by zero");
            std::terminate();
        }

        return Vector(x / other.x, y / other.y,
                      z / other.z);
    }

    explicit Vector(const Vector &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    void operator=(const Vector &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    void operator+=(const Vector &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void operator-=(const Vector &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    void operator*=(const Vector &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }

    void operator/=(const Vector &other)
    {
        if (other.x == 0 || other.y == 0 ||
            other.z == 0) [[unlikely]]
        {
            throw std::runtime_error(
                "division by zero");
        }

        x /= other.x;
        y /= other.y;
        z /= other.z;
    }

    NumType x{};
    NumType y{};
    NumType z{};
};

using SVector = Vector<float>;

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