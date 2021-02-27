#include "Core/pch.h"

#include "Core/Application.h"
#include "Core/Log.h"

#include "Core/Window.h"
#include "Backends/GLFW/GLFW.h"

#include "Core/Renderer.h"
#include "Renderers/OpenGL/OpenGL.h"

namespace eng
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run(eng::ApplicationSettings &Settings)
    {
        Log::Init();
        ENG_CORE_TRACE("Created an Application class and initialized spdlog.");
        Window *myWindow;
        GLFW GLFWBackend;

        switch (Settings.WindowLibrary)
        {
        case WindowLibraries::GLFW:
            myWindow = &GLFWBackend;
            ENG_CORE_TRACE("GLFW is the window library.");
            break;
        case WindowLibraries::Win32:
        case WindowLibraries::SDL:
        default:
            ENG_CORE_CRITICAL("No usable window library");
            throw 1;
            break;
        }

        Renderer *myRenderer;
        OpenGL OpenGLRenderer;

        switch (Settings.GraphicsLibrary)
        {
        case GraphicsLibraries::OpenGL:
            myRenderer = &OpenGLRenderer;
            ENG_CORE_TRACE("OpenGL is the graphics library.");
            break;
        case GraphicsLibraries::Vulkan:
        case GraphicsLibraries::DX11:
        case GraphicsLibraries::DX12:
        default:
            ENG_CORE_CRITICAL("No usable graphics library");
            throw 1;
            break;
        }

        ENG_CORE_TRACE("Initializing the window library...");
        myWindow->Init(Settings);
        while (true)
        {
        }
    }
}