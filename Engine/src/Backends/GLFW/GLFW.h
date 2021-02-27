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

    private:
        GLFWwindow *m_Window;
    };
}