#pragma once

#include "object/Object.h"
#include <memory>
#include <vector>

class Events;

class App final {
  public:
    App() {}

    /// A chainable method for creating a new
    /// object and adding it to the world
    /// @arg arguments you can give to to
    /// create your object, e.g. a player
    /// @return gives you back a reference to
    /// the world object to further chain
    /// methods on or store it.
    template <typename Tp, typename... Args>
        requires std::destructible<Tp> &&
                 std::derived_from<Tp, Events>
    App &addObject(Args... args) {
        events_.emplace_back(
            std::make_unique<Tp>(std::forward<Args>(args)...));

        return *this;
    }

    /// A chainable method for creating a new
    /// object and adding it to the world
    /// @arg arguments you can give to to
    /// create your object, e.g. a player
    /// @return gives you back a reference to
    /// the world object to further chain
    /// methods on or store it.
    template <typename Tp> App &addObject(std::unique_ptr<Tp> &&tp) {
        events_.emplace_back(std::move(tp));

        return *this;
    }

    void run();

  private:
    std::vector<std::unique_ptr<Events>> events_{};
};