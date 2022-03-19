#include "engine/app/Application.h"
#include "engine/events/AppEvent.h"
#include "engine/log/Log.h"

namespace ge
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		while (m_running)
		{
			m_window->OnUpdate();
		}
	}

} // namespace ge