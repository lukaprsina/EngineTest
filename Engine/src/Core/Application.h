#pragma once

#include "Core/Window.h"
#include "Core/pch.h"
#include "Core/Base.h"

namespace eng
{
    enum WindowLibraries
    {
        WLGLFW = 0,
        WLWin32,
        WLSDL
    };

    enum GraphicsLibraries
    {
        GLOpenGL = 0,
        GLVulkan,
        GLDX11,
        GLDX12
    };

    struct ApplicationProps
    {
        WindowLibraries WindowLibrary;
        GraphicsLibraries GraphicsLibrary;
    };

    class ENG_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run(ApplicationProps &AppProps);

    private:
        std::vector<Window> m_Windows;
    };

    extern Application *CreateApplication(ApplicationProps &AppProps);
}