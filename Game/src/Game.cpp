#include "Engine.h"

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

eng::Application *eng::CreateApplication(eng::ApplicationSettings &Settings)
{
    Settings.GraphicsLibrary = GraphicsLibraries::OpenGL;
    Settings.WindowLibrary = WindowLibraries::GLFW;

    return new Game();
}