#pragma once

#include "object/Object.h"
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

    [[nodiscard]] World &addObject(
        std::shared_ptr<Object> &&object);

    void emerge();

  private:
    void tick();

    std::vector<std::shared_ptr<Object>>
        objects_;
};
} // namespace world