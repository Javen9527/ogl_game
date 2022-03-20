#pragma once

#include "define.h"
#include "engine/layer/Layer.h"

namespace ge
{
	class GE_API ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& e);

	private:
		double m_time = 0.0f;
	};

}

