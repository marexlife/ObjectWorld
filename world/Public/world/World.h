#pragma once

#include "object/Object.h"
#include <concepts>
#include <memory>
#include <vector>

namespace player {
class Player;
}

namespace world {
using object::Object;
using player::Player;

class World final : public Object {
  public:
    World() {}

    World(const World &) = delete;
    World &operator=(const World &) = delete;
    World(World &&) = delete;
    World &operator=(World &&) = delete;
    ~World() = default;

    template <std::derived_from<Object> Type>
    [[nodiscard]] World &
    addObject(Type &&object) {
        objects_.emplace_back(
            std::make_shared<Type>(object));

        return *this;
    }

    void emerge();

  private:
    void tick();

    std::vector<std::shared_ptr<Object>>
        objects_;
};
} // namespace world