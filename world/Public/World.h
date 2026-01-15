#pragma once

#include <memory>
#include <vector>

namespace game {
namespace player {
class Player;
}
} // namespace game

namespace game {
namespace world {
using game::player::Player;

class World final {
  public:
    World() {}

    World(const World &) = delete;
    World &operator=(const World &) = delete;
    World(World &&) = delete;
    World &operator=(World &&) = delete;
    ~World() = default;

    World &
    addPlayer(std::shared_ptr<Player> &&player);

    void emerge();

  private:
    void tick();

    std::vector<std::shared_ptr<Player>> players_;
};
} // namespace world
} // namespace game