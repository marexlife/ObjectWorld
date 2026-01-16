#include "player/Player.h"
#include "world/World.h"

int main() {
    OWorld().addObject<OPlayer>().emerge();
}