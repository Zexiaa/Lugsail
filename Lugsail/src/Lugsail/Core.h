#pragma once

#ifdef LS_PLATFORM_WINDOWS
	#ifdef LS_BUILD_DLL
		#define LUGSAIL_API __declspec(dllexport)
	#else
		#define LUGSAIL_API __declspec(dllimport)
	#endif
#else
	#error Lugsail Engine only supports Windows!
#endif