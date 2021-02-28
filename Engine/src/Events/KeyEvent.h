#pragma once

#include "Core/pch.h"
#include "Events/Event.h"

namespace eng
{

	class ENG_API KeyEvent : public Event
	{
	};

	class ENG_API KeyPressedEvent : public KeyEvent
	{
	};

	class ENG_API KeyReleasedEvent : public KeyEvent
	{
	};
}