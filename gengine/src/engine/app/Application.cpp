#include "engine/app/Application.h"
#include "engine/log/Log.h"

#include <functional>

namespace ge
{
	Application* Application::m_instance = nullptr;

	Application::Application()
	{
		GE_ASSERT(!m_instance, "Application is already existed!");
		m_instance = this;

		m_window = std::unique_ptr<Window>(Window::Create());
		m_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_running)
		{
			m_window->OnUpdate();

			for (auto layer : m_layerStack)
			{
				layer->OnUpdate();
			}
		}
	}

	void Application::OnEvent(Event& e)
	{
		// log event
		GE_TRACE("{0}", e);

		// use event dispatcher
		EventDispatcher dispatcher(e);
		/*
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& event)->bool {
			m_running = false;
			return true;
		});*/
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		// event for layer
		for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.GetHandled())
				break;
		}

	}

	void Application::PushLayer(Layer* layer)
	{
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverLayer(Layer* layer)
	{
		m_layerStack.PushOverLayer(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}

} // namespace ge