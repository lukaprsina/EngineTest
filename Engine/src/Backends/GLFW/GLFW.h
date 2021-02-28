#pragma once

#include "Core/pch.h"
#include "Core/Window.h"
#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace eng
{
    class GLFW : public Window
    {
    public:
        virtual void Init(ApplicationSettings Settings) override;
        virtual void Shutdown() override;
        virtual void OnUpdate() override;

        inline void SetEventCallback(const std::function<void(Event &)> &callback) override { m_WindowSettings.EventCallback = callback; }

    private:
        GLFWwindow *m_Window;
        WindowSettings m_WindowSettings;
    };
}