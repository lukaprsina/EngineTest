#pragma once

#include "Core/pch.h"
#include "Events/Event.h"

namespace eng
{

    class ENG_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}
        std::string ToString() const { return "Window Resize event"; };

    private:
        unsigned int m_Width, m_Height;
    };

    class ENG_API WindowCloseEvent : public Event
    {
    public:
    };
} // namespace eng