#pragma once

#include "define.h"
#include "engine/events/Event.h"
#include "engine/windows/Window.h"

#include <memory>

namespace ge
{

// need to be inherit by client
class GE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

private:
	std::unique_ptr<Window> m_window;
	bool m_running = true;
};

// need to be implement by client
Application* CreateApplication();

} // namespace ge


