#pragma once

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
        std::string Title = "Untitled Project";
        unsigned int Width = 1280;
        unsigned int Height = 920;
        WindowLibraries WindowLibrary = WindowLibraries::GLFW;
        GraphicsLibraries GraphicsLibrary = GraphicsLibraries::OpenGL;
    };

    class Window
    {
    public:
        virtual void Init(ApplicationSettings Settings) = 0;
        virtual void Shutdown() = 0;
        virtual void OnUpdate() = 0;

    protected:
        struct WindowSettings
        {
            std::string Title = "Untitled Project";
            unsigned int Width = 1280;
            unsigned int Height = 920;
        };

        WindowSettings m_WindowSettings;
    };
}