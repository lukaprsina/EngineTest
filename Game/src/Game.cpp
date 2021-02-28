#include "Engine.h"

class TransparentLayer : public eng::Layer
{
public:
    TransparentLayer()
        : Layer()
    {
    }

    void OnEvent(eng::Event &event) override
    {
        ENG_TRACE("{0}", event.ToString());
    }
};

class BlockingLayer : public eng::Layer
{
public:
    BlockingLayer()
        : Layer()
    {
    }

    void OnEvent(eng::Event &event) override
    {
        event.Handled = true;
    }
};

class Game : public eng::Application
{
public:
    Game()
    {
        TransparentLayer *gameLayer = new TransparentLayer;
        PushLayer(gameLayer);

        BlockingLayer *inventory = new BlockingLayer;
        PushLayer(inventory);

        // change to int
        BringLayerForward(gameLayer, 2);
        SendLayerBackward(gameLayer, 2);
    }
    ~Game()
    {
    }
};

eng::Application *eng::CreateApplication(eng::ApplicationSettings &Settings)
{
    Settings.GraphicsLibrary = GraphicsLibraries::OpenGL;
    Settings.WindowLibrary = WindowLibraries::GLFW;
    Settings.Title = "Dev";

    return new Game();
}