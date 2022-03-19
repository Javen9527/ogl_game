#include "engine/app/Application.h"
#include "engine/events/AppEvent.h"
#include "engine/log/Log.h"

namespace ge
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		GE_TRACE(e);

		while (true)
		{
		}
	}

} // namespace ge