#pragma once

#include <cstdio>

#include "Application.h"
#include "engine/log/Log.h"

#ifdef GE_PLATFORM_WINDOWS

// implement by client
extern ge::Application* ge::CreateApplication();

// entry point 
int main(int argc, char** argv)
{
	ge::Log::init();
	GE_WARN("Log Initialzied!");

	auto app = ge::CreateApplication();
	app->Run();

	delete app;
}

#endif
