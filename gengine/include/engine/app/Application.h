#pragma once

#include "define.h"
#include "engine/events/Event.h"
#include "engine/events/AppEvent.h"
#include "engine/windows/Window.h"
#include "engine/layer/LayerStack.h"
#include <memory>

namespace ge
{
	
/*
@ need to be implement by client
@ example:
```
class SandBox : public ge::Application{};
ge::Application* ge::CreateApplication()
{
	return new Sandbox();
}
```
*/ 
class Application;
Application* CreateApplication();

/*
Application you can think there are two main funcs:
1. Run()
2. OnEvent()

And the relationship between of window and layer:
diff:
1. main: window
2. back: layer
same:
1. both have onUpdate()
2. event handle system
*/
class GE_API Application
{
public:
	Application();
	virtual ~Application();

public:
	// main thread loop
	void Run();

	// this will excute as window's callback
	void OnEvent(Event& e);

	// for layer
	void PushLayer(Layer* layer);
	void PushOverLayer(Layer* layer);

	inline static Application& Get() { return *m_instance; }
	inline Window& GetWindow() { return *m_window; }

private:
	bool OnWindowClose(WindowCloseEvent& event);

private:
	bool m_running = true;
	static Application *m_instance;

	std::unique_ptr<Window> m_window;

	LayerStack m_layerStack;
};


} // namespace ge


