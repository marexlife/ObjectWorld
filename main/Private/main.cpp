#include "Player.h"
#include "World.h"

int main() {
    World().addObject<Player>().emerge();
}