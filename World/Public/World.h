#ifndef WORLD_H
#define WORLD_H
#include <memory>
#include <vector>

namespace world {
class World final {
   public:
    World() {}

    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;
    ~World() = default;

    void Emerge();

   private:
    void Tick();
};
}  // namespace world
#endif