#pragma once

namespace ObjectWorld
{
class Events;

class App final
{
  public:
    [[nodiscard]] static App Create()
    {
        return App();
    }

    void Run();

  private:
    App()
    {
    }
};
} // namespace ObjectWorld