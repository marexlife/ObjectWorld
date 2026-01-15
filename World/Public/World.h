#pragma once

#include <generator>
#include <memory>
#include <variant>
#include <vector>

namespace game
{
namespace player
{
class Player;
}
} // namespace Game

namespace game
{
namespace world
{
using game::player::Player;

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

    std::generator<std::monostate> Emerge();

  private:
    void Tick();

    std::vector<std::shared_ptr<Player>> players_;
};
} // namespace World
} // namespace Game