#pragma once

#include "define.h"
#include "engine/events/Event.h"
#include "engine/events/AppEvent.h"
#include "engine/windows/Window.h"
#include "engine/layer/LayerStack.h"
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

	// this will excute as window's callback
	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverLayer(Layer* layer);

private:
	bool OnWindowClose(WindowCloseEvent& event);

private:
	std::unique_ptr<Window> m_window;
	LayerStack m_layerStack;
	bool m_running = true;
};

// need to be implement by client
Application* CreateApplication();

} // namespace ge


