#pragma once

// micro define

#ifdef GE_PLATFORM_WINDOWS

	#ifdef GE_BUILD_DLL
		#define GE_API __declspec(dllexport)
	#else
		#define GE_API __declspec(dllimport)
	#endif

#else

	#error GE only support windows!

#endif

#define BIT(x) (1 << x)