#pragma once

#include "Object/Object.h"
#include <concepts>
#include <memory>
#include <utility>
#include <vector>

namespace ObjectWorld
{
class Player;

class World final : public OObject
{
  public:
    World()
    {
    }

    World(World &&) = default;

    /// A chainable method for creating a new
    /// object and adding it to the world
    /// @arg arguments you can give to to
    /// create your object, e.g. a player
    /// @return gives you back a reference to
    /// the world object to further chain
    /// methods on or store it.
    template <typename Tp, typename... Args>
        requires std::destructible<Tp> &&
                 std::derived_from<Tp, OObject>
    World &AddObject(Args... args)
    {
        events_.emplace_back(std::make_shared<Tp>(
            std::forward<Args>(args)...));

        return *this;
    }

    virtual void Emerge() override;
    virtual void Tick() override;

    World(const World &) = delete;
    World &operator=(const World &) = delete;
    World &operator=(World &&) = delete;
    virtual ~World() override = default;

  private:
    std::vector<std::shared_ptr<OObject>>
        events_{};
};
} // namespace ObjectWorld