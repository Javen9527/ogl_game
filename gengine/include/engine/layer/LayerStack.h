#pragma once

#include "Layer.h"

#include <vector>

namespace ge
{

	class GE_API LayerStack
	{
	public:
		using layerItr = std::vector<Layer*>::iterator;

		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* overlayer);
		void PopLayer(Layer* layer);
		void PopOverLayer(Layer* overlayer);

		layerItr begin() { return m_layers.begin(); }
		layerItr end() { return m_layers.end(); }

	private:
		layerItr m_layerItr;
		std::vector<Layer*> m_layers;
	};

} // namespace ge 

