#pragma once

#include "wininput.h"
#include "winevent.h"

#ifdef UNICODE
typedef wchar_t WIN_CHAR;
#else
typedef char WIN_CHAR;
#endif

extern const WIN_CHAR* WIN_NAME;