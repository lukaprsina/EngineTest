#pragma once

#include "Core/pch.h"
#include "Core/Base.h"

namespace eng
{
    class ENG_API Window
    {
    public:
        Window();
        virtual ~Window();
        Window *Create();
    };
}