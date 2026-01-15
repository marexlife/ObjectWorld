#include "Player.h"
#include "World.h"
#include <memory>

int main() {
    auto p1 = std::make_shared<Player>();
    auto p2 = std::make_shared<Player>();

    World().addObject<Player>().emerge();
}