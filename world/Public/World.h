#pragma once

#include "Object.h"
#include <concepts>
#include <memory>
#include <vector>

class Player;

class World final : public Object {
  public:
    World() {}

    World(const World &) = delete;
    World &operator=(const World &) = delete;
    World(World &&) = delete;
    World &operator=(World &&) = delete;
    ~World() = default;

    template <typename Tp, typename... Args>
        requires std::derived_from<Tp,
                                   Object> &&
                 std::constructible_from<
                     Tp, Args...>
    [[nodiscard]] World &addObject() {
        objects_.emplace_back(
            std::make_shared<Tp>());

        return *this;
    }

    void emerge();

  private:
    void tick();

    std::vector<std::shared_ptr<Object>>
        objects_;
};