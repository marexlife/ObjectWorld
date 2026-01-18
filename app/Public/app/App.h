#pragma once

#include "object/Events.h"
#include <memory>
#include <vector>

namespace oworld
{
class Events;

class App final
{
  public:
    [[nodiscard]] static App Create()
    {
        return App();
    }

    /// A chainable method for creating a new
    /// object and adding it to the world
    /// @arg arguments you can give to to
    /// create your object, e.g. a player
    /// @return gives you back a reference to
    /// the world object to further chain
    /// methods on or store it.
    template <typename T> App &AddObject(std::unique_ptr<T> &&tp)
    {
        events_.emplace_back(std::move(tp));

        return *this;
    }

    void Run();

  private:
    std::vector<std::unique_ptr<Events>> events_{};
    bool shouldRun_{true};

    App() = default;
};
} // namespace oworld