#pragma once

#include "Core/pch.h"
#include "Core/Renderer.h"

namespace eng
{
    class OpenGL : public Renderer
    {
    public:
        virtual void SayHello() override;
    };
}