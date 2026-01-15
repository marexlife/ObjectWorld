#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"

namespace player {
class Player final : public object::Object {
   public:
    void Tick() override {}
};
}  // namespace player
#endif