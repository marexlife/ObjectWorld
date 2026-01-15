#pragma once

#include "Object.h"
#include <memory>
#include <vector>

namespace game {
namespace object {
class Object;
}
namespace player {
class Player;
}
} // namespace game

namespace game {
namespace world {
using game::object::Object;
using game::player::Player;

class World final {
  public:
    World() {}

    World(const World &) = delete;
    World &operator=(const World &) = delete;
    World(World &&) = delete;
    World &operator=(World &&) = delete;
    ~World() = default;

    [[nodiscard]] World &
    addObject(std::shared_ptr<Object> &&object);

    void emerge();

  private:
    void tick();

    std::vector<std::shared_ptr<Object>> objects_;
};
} // namespace world
} // namespace game