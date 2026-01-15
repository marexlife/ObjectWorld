#pragma once

namespace game {
namespace object {
class Object {
  public:
    virtual void emerge() = 0;
    virtual void tick() = 0;

    virtual ~Object() = default;
};
} // namespace object
} // namespace game