#include <Windows.h>
#include "gl.h"

HGLRC exglCreateContext(HDC hdc) {
	return wglCreateContext(hdc);
}