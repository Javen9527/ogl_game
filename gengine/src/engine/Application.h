#pragma once

#include "Core.h"

namespace ge
{

// need to be inherit by client
class GE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};

// need to be implement by client
Application* CreateApplication();

} // namespace ge


