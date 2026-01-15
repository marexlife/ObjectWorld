#ifndef WORLD_H
#define WORLD_H
#include <cstdint>
#include <initializer_list>
#include <queue>
#include <valarray>
#include <vector>

namespace world {
class World final {
   public:
    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;
    ~World() {}

    void Emerge();
    void Tick();

   private:
};
}  // namespace world
#endif