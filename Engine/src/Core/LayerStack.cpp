#include "Core/Layer.h"
#include "Core/Application.h"

namespace eng
{
	void Application::PushLayer(Layer *layer)
	{
		m_Layers.emplace_back(layer);
	}

	void Application::PopLayer(Layer *layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}

	void Application::BringLayerToFront(Layer *layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_Layers.emplace_back(layer);
		}
	}

	void Application::SendLayerToBack(Layer *layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_Layers.emplace(m_Layers.begin(), layer);
		}
	}

	/*********************************************************************/

	void Application::BringLayerForward(Layer *layer, unsigned int count)
	{
		if (count == 0)
			return;

		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			auto distance = it - m_Layers.begin();

			unsigned int targetPosition = distance + count;

			if (targetPosition < m_Layers.size())
			{
				m_Layers.erase(it);
				m_Layers.insert(m_Layers.begin() + targetPosition, layer);
			}
			else
			{
				m_Layers.erase(it);
				m_Layers.insert(m_Layers.end(), layer);
			}
		}
	}

	void Application::SendLayerBackward(Layer *layer, unsigned int count)
	{
		if (count == 0)
			return;

		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			auto distance = it - m_Layers.begin();
			int targetPosition = distance - count;

			if (targetPosition >= 0)
			{
				m_Layers.erase(it);
				m_Layers.insert(m_Layers.begin() + targetPosition, layer);
			}
			else
			{
				m_Layers.erase(it);
				m_Layers.insert(m_Layers.begin(), layer);
			}
		}
	}
}