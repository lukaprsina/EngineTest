#include "Core/pch.h"
#include "Core/Application.h"

#include "Core/Window.h"
#include "Backends/GLFW/GLFW.h"

#include "Core/Renderer.h"
#include "Renderers/OpenGL/OpenGL.h"

#include <iostream>

namespace eng
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run(eng::ApplicationProps &AppProps)
    {
        std::cout << AppProps.GraphicsLibrary << '\n';
        std::cout << AppProps.WindowLibrary << '\n';

        OpenGL myOpenGL;
        Renderer *myRenderer = &myOpenGL;

        myRenderer->SayHello();
    }
}