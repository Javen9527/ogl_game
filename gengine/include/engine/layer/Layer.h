#pragma once

#include <string>

#include "define.h"
#include "engine/events/Event.h"


namespace ge
{

	class GE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline std::string GetName() const { return m_debug; }

	protected:
		std::string m_debug;
	};

} // namespace ge

