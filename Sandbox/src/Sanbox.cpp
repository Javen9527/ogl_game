
#include "ge.h"

// (alternal) you can inherit from applicaiton and do your own process
class Sandbox : public ge::Application
{
public:
	Sandbox()
	{

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
