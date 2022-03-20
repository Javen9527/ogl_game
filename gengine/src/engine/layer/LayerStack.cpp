#include "engine/layer/LayerStack.h"

namespace ge
{
	LayerStack::LayerStack()
	{
		m_layerItr = m_layers.begin();
	}
	LayerStack::~LayerStack()
	{
		for (auto layer : m_layers)
		{
			delete layer;
		}
	}
	void LayerStack::PushLayer(Layer* layer)
	{
		m_layerItr = m_layers.emplace(m_layerItr, layer);
	}
	void LayerStack::PushOverLayer(Layer* overlayer)
	{
		m_layers.emplace_back(overlayer);
	}
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);
		if (it != m_layers.end())
		{
			m_layers.erase(it);
			m_layerItr--;
		}
	}
	void LayerStack::PopOverLayer(Layer* overlayer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), overlayer);
		if (it != m_layers.end())
		{
			m_layers.erase(it);
		}
	}
} // namespace ge
