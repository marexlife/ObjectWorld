#pragma once

#include <memory>
#include <string_view>

class Name {
  public:
    [[nodiscard]] virtual std::string_view getObjectName() const = 0;

    virtual ~Name() = default;
};

class Events {
  public:
    /// runs once at emerging of the object
    virtual void emerge() = 0;

    /// runs once per frame
    virtual void tick() = 0;

    virtual ~Events() = default;
};

class EventScheduler {
  public:
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
    Derived &addObject(Args... args) {
        getEventObjects().emplace_back(
            std::make_shared<Tp>(std::forward<Args>(args)...));

        return *this;
    }

    virtual Events getEventObjects() = 0;

    virtual ~EventScheduler() = default;
};