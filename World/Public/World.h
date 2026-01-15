#ifndef WORLD_H
#define WORLD_H
#include <memory>
#include <vector>

namespace object {
class Object;
}

namespace world {
class World final {
   public:
    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;
    ~World() = default;

    void Emerge();
    void Tick();

   private:
    std::vector<std::shared_ptr<object::Object>>
        objects_;
};
}  // namespace world
#endif