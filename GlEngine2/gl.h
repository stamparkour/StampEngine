#pragma once

#include <gl/gl.h>
#include <gl/glu.h>
#include "glext.h"
#include "wglext.h"

HGLRC exglCreateContext(HDC hdc);
BOOL wglSwapIntervalEXT(int interval);
int wglGetSwapIntervalEXT(void);