#pragma once

#include "Core/Base.h"
#include "Events/Event.h"

namespace eng
{
	class ENG_API Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event &event) {}
	};

}