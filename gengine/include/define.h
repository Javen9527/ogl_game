#pragma once

// dll
#ifdef GE_PLATFORM_WINDOWS

	#ifdef GE_BUILD_DLL
		#define GE_API __declspec(dllexport)
	#else
		#define GE_API __declspec(dllimport)
	#endif

#else

	#error GE only support windows!

#endif

// utility
#define BIT(x) (1 << x)

// log
#ifdef GE_ENABLE_ASSERTS
	#define GE_ASSERT(x, ...) {if(!(x)){GE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define APP_ASSERT(x, ...) {if(!(x)){APP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define GE_ASSERT(x, ...)
	#define APP_ASSERT(x, ...)
#endif