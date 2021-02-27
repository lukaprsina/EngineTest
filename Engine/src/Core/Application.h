#pragma once

#include "Core/Window.h"
#include "Core/pch.h"
#include "Core/Base.h"

namespace eng
{
    class ENG_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run(ApplicationSettings &AppProps);

    private:
        std::vector<Window> m_Windows;
    };

    extern Application *CreateApplication(ApplicationSettings &Settings);
}