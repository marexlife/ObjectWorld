#pragma once

#include "Object/Object.h"
#include <concepts>
#include <memory>
#include <utility>
#include <vector>

namespace ObjectWorld
{
class Player;

class CWorld final : public CObject
{
  public:
    CWorld()
    {
    }

    CWorld(CWorld &&) = default;

    /// A chainable method for creating a new
    /// object and adding it to the world
    /// @arg arguments you can give to to
    /// create your object, e.g. a player
    /// @return gives you back a reference to
    /// the world object to further chain
    /// methods on or store it.
    template <typename Tp, typename... Args>
        requires std::destructible<Tp> &&
                 std::derived_from<Tp, CObject>
    CWorld &AddObject(Args... args)
    {
        events_.emplace_back(std::make_shared<Tp>(
            std::forward<Args>(args)...));

        return *this;
    }

    virtual void Emerge() override;
    virtual void Tick() override;

    CWorld(const CWorld &) = delete;
    CWorld &operator=(const CWorld &) = delete;
    CWorld &operator=(CWorld &&) = delete;
    virtual ~CWorld() override = default;

  private:
    std::vector<std::shared_ptr<CObject>>
        events_{};
};
} // namespace ObjectWorld