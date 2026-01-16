#pragma once

#include "object/Object.h"
#include <concepts>
#include <memory>
#include <utility>
#include <vector>

class OPlayer;

class OWorld final : public OObject {
    OOBJECT(OWorld)

  public:
    OWorld() {}

    OWorld(const OWorld &) = delete;
    OWorld &
    operator=(const OWorld &) = delete;
    OWorld(OWorld &&) = delete;
    OWorld &operator=(OWorld &&) = delete;
    ~OWorld() = default;

    /// A chainable method for creating a new
    /// object and adding it to the world
    /// @arg arguments you can give to to
    /// create your object, e.g. a player
    /// @return gives you back a reference to
    /// the world object to further chain
    /// methods on or store it.
    template <typename Tp, typename... Args>
        requires std::derived_from<
                     Tp, OObject> &&
                 std::constructible_from<
                     Tp, Args...>
    [[nodiscard]] OWorld &
    addObject(Args... args) {
        objects_.emplace_back(
            std::make_shared<Tp>(
                std::forward<Args>(
                    args)...));

        return *this;
    }

    /// the game world emerges out of
    /// all the pieces you gave to it
    void emerge();

  private:
    void tick();

    std::vector<std::shared_ptr<OObject>>
        objects_;
};