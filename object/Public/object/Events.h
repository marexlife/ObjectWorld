#pragma once

#include <functional>
#include <vector>
namespace oworld
{
class Events
{
  public:
    /// runs once at emerging of the object
    virtual void Emerge() = 0;

    /// runs once per frame
    virtual void Tick() = 0;

    virtual ~Events()
    {
    }
};

template <typename Ret, typename... Args> class Event
{
  public:
    void Subscribe(std::move_only_function<Ret(Args...)> &&f)
    {
        funcs_.emplace_back(f);
    }

    void operator()()
    {
        for (std::move_only_function<void()> &f : funcs_)
        {
            f();
        }
    }

    virtual ~Event() = default;

  private:
    std::vector<std::move_only_function<Ret(Args...)>> funcs_{};
};
} // namespace oworld