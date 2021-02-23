#pragma once

#include "Window/Window.h"

namespace eng
{
    class GLFWWindow : public Window
    {
    public:
        GLFWWindow();
        ~GLFWWindow();
    };
}