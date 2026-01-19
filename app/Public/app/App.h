#pragma once

namespace ObjectWorld
{
class Events;

class App final
{
  public:
    constexpr static int Width = 1800;
    constexpr static int Height = 1000;
    constexpr static int X = Width / 5;
    constexpr static int Y = Height / 5;

    [[nodiscard]] static App Create()
    {
        return App();
    }

    void Run();

  private:
    bool shouldRun_ = true;

    App()
    {
    }
};
} // namespace ObjectWorld