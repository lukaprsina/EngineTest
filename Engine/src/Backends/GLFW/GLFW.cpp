#include "Core/pch.h"

#include "Backends/GLFW/GLFW.h"
#include "Core/Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

#include <glad/glad.h>

namespace eng
{
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description)
    {
        ENG_CORE_ERROR("GLFW Error [{0}]: {1}", error, description);
    }

    void GLFW::Init(ApplicationSettings Settings)
    {
        ENG_CORE_TRACE("Initializing GLFW...");
        if (s_GLFWInitialized)
        {
            ENG_CORE_TRACE("GLFW already initialized.");
        }
        else
        {
            int success = glfwInit();
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_WindowSettings.Title = Settings.Title;
        m_WindowSettings.Width = Settings.Width;
        m_WindowSettings.Height = Settings.Height;

        m_Window = glfwCreateWindow((int)m_WindowSettings.Width, (int)m_WindowSettings.Height, m_WindowSettings.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);

        ENG_CORE_TRACE("Created a window.");

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            ENG_CORE_ERROR("Cannot initialize Glad.");
        }
        else
        {
            ENG_CORE_TRACE("Initialized Glad.");
        }

        glfwSetWindowUserPointer(m_Window, &m_WindowSettings);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow *window, int focused) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);
            WindowFocusedEvent event(focused);
            data.EventCallback(event);
        });

        glfwSetWindowPosCallback(m_Window, [](GLFWwindow *window, int XPositon, int YPosition) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);
            WindowMovedEvent event(XPositon, YPosition);
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);

            switch (action)
            {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.EventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, 1);
                data.EventCallback(event);
                break;
            }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);

            switch (action)
            {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(button);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(button);
                data.EventCallback(event);
                break;
            }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos) {
            WindowSettings &data = *(WindowSettings *)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });
    }

    void GLFW::Shutdown()
    {
        ENG_CORE_TRACE("Destroyed the GLFW window.");
        glfwDestroyWindow(m_Window);
    }
    void GLFW::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
}