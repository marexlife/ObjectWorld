#pragma once

#include <functional>
#include <vector>

namespace ObjectWorld
{
class Object
{
  public:
    /// runs once at emerging of the object
    virtual void Emerge() = 0;

    /// runs once per frame
    virtual void Tick() = 0;

    virtual ~Object()
    {
    }
};

template <typename Ret, typename... Args>
class Event
{
  public:
    void Subscribe(
        std::move_only_function<Ret(Args...)> &&f)
    {
        functors_.emplace_back(std::move(f));
    }

    void Fire()
    {
        for (std::move_only_function<void()>
                 &functor : functors_)
        {
            functor();
        }
    }

    virtual ~Event() = default;

  private:
    std::vector<
        std::move_only_function<Ret(Args...)>>
        functors_{};
};
} // namespace ObjectWorld