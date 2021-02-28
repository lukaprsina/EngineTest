#pragma once

#include "Core/pch.h"
#include "Events/Event.h"

namespace eng
{

	class ENG_API MouseMovedEvent : public Event
	{
	};

	class ENG_API MouseScrolledEvent : public Event
	{
	};

	class ENG_API MouseButtonEvent : public Event
	{
	};

	class ENG_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	};

	class ENG_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	};

}