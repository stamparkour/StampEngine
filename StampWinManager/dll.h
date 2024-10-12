#pragma once
#ifdef STAMPWINMANAGER_EXPORTS
#define SE_API __declspec(dllexport)
#else
#define SE_API __declspec(dllimport)
#endif