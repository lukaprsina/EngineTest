#include "Core/Application.h"

namespace eng
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (true)
        {
            std::cout << "Hello from app!\n";
        }
    }
}