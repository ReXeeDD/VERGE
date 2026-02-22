// In Verge/src/Test.h
#pragma once

#ifdef VERGE_BUILD_DLL
    // We are inside the Engine project, so EXPORT
#define VERGE_API __declspec(dllexport)
#else
    // We are inside the Sandbox project, so IMPORT
#define VERGE_API __declspec(dllimport)
#endif
