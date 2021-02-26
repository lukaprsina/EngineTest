#include "Engine.h"
#include <iostream>

class Game : public eng::Application
{
public:
    Game()
    {
    }
    ~Game()
    {
    }
};

eng::Application *eng::CreateApplication(eng::ApplicationProps &AppProps)
{
    AppProps.GraphicsLibrary = GLDX11;
    AppProps.WindowLibrary = WLWin32;

    return new Game();
}