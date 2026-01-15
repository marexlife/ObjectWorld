#pragma once

#include <memory>
#include <vector>

namespace Game
{
namespace Player
{
class Player;
}
} // namespace Game

namespace Game
{
namespace World
{
using Game::Player::Player;

class World final
{
  public:
    World()
    {
    }

    World(const World &) = delete;
    World &operator=(const World &) = delete;
    World(World &&) = delete;
    World &operator=(World &&) = delete;
    ~World() = default;

    World &AddPlayer(
        std::shared_ptr<Player> &&player);

    void Emerge();

  private:
    void Tick();

    std::vector<std::shared_ptr<Player>> players_;
};
} // namespace World
} // namespace Game