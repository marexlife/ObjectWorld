#pragma once

#include "object/Object.h"
#include <concepts>
#include <memory>
#include <utility>
#include <vector>

class Player;

class World final : public Events {
  public:
    World() : objects_{} {}
    World(World &&) = default;

    World(const World &) = delete;
    World &operator=(const World &) = delete;
    World &operator=(World &&) = delete;
    ~World() = default;

    void emerge() override;
    void tick() override;

  private:
    std::vector<std::shared_ptr<Events>> objects_{};
};