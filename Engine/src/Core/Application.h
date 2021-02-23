#pragma once

#include "Window/Window.h"
#include "Core/pch.h"
#include "Core/Base.h"

namespace eng
{
    class ENG_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::vector<Window> m_Windows;
    };

    Application *CreateApplication();
}