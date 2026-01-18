#include "app/App.h"
#include "window/Window.h"
#include "world/World.h"

int main() {
    App{}.addObject<World>().addObject<Window>(Args args...).run();
}