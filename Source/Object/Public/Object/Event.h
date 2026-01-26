#pragma once

#include <functional>

namespace ObjectWorld
{
template <typename Ret, typename... Args>
class Event
{
  public:
    virtual void Subscribe(
        std::move_only_function<Ret(Args...)> &&f)
    {
        functors_.emplace_back(std::move(f));
    }

    virtual void Fire()
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