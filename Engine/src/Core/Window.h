#pragma once

#include "Core/Base.h"
#include "Events/Event.h"

namespace eng
{
    enum class WindowLibraries
    {
        GLFW = 0,
        Win32,
        SDL
    };

    enum class GraphicsLibraries
    {
        OpenGL = 0,
        Vulkan,
        DX11,
        DX12
    };

    struct ApplicationSettings
    {
        std::string Title = "Engine";
        unsigned int Width = 1280;
        unsigned int Height = 920;
        WindowLibraries WindowLibrary = WindowLibraries::GLFW;
        GraphicsLibraries GraphicsLibrary = GraphicsLibraries::OpenGL;
    };

    struct WindowSettings
    {
        std::string Title = "Engine";
        unsigned int Width = 1280;
        unsigned int Height = 920;

        std::function<void(Event &)> EventCallback;
    };

    class Window
    {
    public:
        virtual void Init(ApplicationSettings Settings) = 0;
        virtual void Shutdown() = 0;
        virtual void OnUpdate() = 0;

        virtual void SetEventCallback(const std::function<void(Event &)> &callback) = 0;
    };
}