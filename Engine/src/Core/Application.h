#pragma once

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
    };

    Application *CreateApplication();
}