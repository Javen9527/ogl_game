
#include "ge.h"

// example for layer
class ExampleLayer : public ge::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer")
	{
	}

	void OnUpdate() override
	{
		APP_INFO("ExampleLayer::update");
	}

	void OnEvent(ge::Event& event) override
	{
		APP_INFO("ExampleLayer event: {0}", event);
	}
};



// (alternal) you can inherit from applicaiton and do your own process
class Sandbox : public ge::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushOverLayer(new ge::ImguiLayer());
	}

	~Sandbox()
	{
	}
};


// (must) you need to implement this
ge::Application* ge::CreateApplication()
{
	return new Sandbox();
}
