#pragma once
#include <cstdio>

#ifdef GE_PLATFORM_WINDOWS

// implement by client
extern ge::Application* ge::CreateApplication();

int main(int argc, char** argv)
{
	printf("ge start!\n");

	auto app = ge::CreateApplication();
	app->Run();

	delete app;
}


#endif
