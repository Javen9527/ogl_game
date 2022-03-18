#pragma once

#include <cstdio>

#include "Application.h"
#include "../log/Log.h"

#ifdef GE_PLATFORM_WINDOWS

// implement by client
extern ge::Application* ge::CreateApplication();

int main(int argc, char** argv)
{
	ge::Log::init();

	GE_WARN("GE Initialzied!");

	auto app = ge::CreateApplication();
	app->Run();

	delete app;
}


#endif
