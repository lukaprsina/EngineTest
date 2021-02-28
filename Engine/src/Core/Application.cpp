#include "Core/pch.h"

#include "Core/Log.h"

#include "Core/Window.h"
#include "Backends/GLFW/GLFW.h"

#include "Events/ApplicationEvent.h"

#include "Core/Renderer.h"
#include "Renderers/OpenGL/OpenGL.h"

#include <glad/glad.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace eng
{
    Application::Application()
    {
        Log::Init();
        ENG_CORE_TRACE("Creating an Application class...");
    }

    Application::~Application()
    {
        ENG_CORE_TRACE("Destroying the Application class...");
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        for (auto it = m_Layers.end(); it != m_Layers.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::Run(eng::ApplicationSettings &Settings)
    {
        ENG_CORE_TRACE("Running the Application.");
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
        myWindow->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
        ENG_CORE_TRACE("Set the event callback.");

        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            myWindow->OnUpdate();
            for (Layer *layer : m_Layers)
                layer->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        ENG_CORE_TRACE("Closing the window...");
        m_Running = false;
        return true;
    }
}