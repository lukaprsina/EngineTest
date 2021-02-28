#pragma once

#include "Core/pch.h"
#include "Core/Base.h"

namespace eng
{
    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    class ENG_API Event
    {
    public:
        virtual std::string ToString() const = 0;
        bool Handled = false;
    };

} // namespace eng