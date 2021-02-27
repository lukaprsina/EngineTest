#pragma once

#ifdef ENG_PLATFORM_WINDOWS
#define ENG_DEBUGBREAK() __debugbreak()
#ifdef ENG_BUILD_DLL
#define ENG_API __declspec(dllexport)
#else
#define ENG_API __declspec(dllimport)
#endif
#elif ENG_PLATFORM_UNIX
#define ENG_DEBUGBREAK() raise(SIGTRAP)
#ifdef ENG_BUILD_DLL
#define ENG_API __attribute__((visibility("default")))
#else
#define ENG_API
#endif
#else
#error "Platform doesn't support debugbreak yet!"
#define ENG_API
#endif

#define BIT(x) (1 << x)
#define ENG_EXPAND_MACRO(x) x
#define ENG_STRINGIFY_MACRO(x) #x