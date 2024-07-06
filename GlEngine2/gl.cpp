#include <Windows.h>
#include <iostream>
#include "gl.h"

#define procDec(type) type _##type
#define procAss(type,name) if(!(_##type = (type)wglGetProcAddress(#name)))std::cout << #name " not available." << std::endl
#define procCall(type,...) if(_##type) _##type(##__VA_ARGS__); else throw 1
#define procCallR(type,...) if(_##type) return _##type(##__VA_ARGS__); else throw 1

bool WGLExtensionSupported(const char* extension_name)
{
    // this is pointer to function which returns pointer to string with list of all wgl extensions
    PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglGetExtensionsStringEXT = NULL;

    // determine pointer to wglGetExtensionsStringEXT function
    _wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT");

    if (strstr(_wglGetExtensionsStringEXT(), extension_name) == NULL)
    {
        // string was not found
        return false;
    }

    // extension is supported
    return true;
}

procDec(PFNWGLSWAPINTERVALEXTPROC);
procDec(PFNWGLGETSWAPINTERVALEXTPROC);
HGLRC exglCreateContext(HDC hdc) {
    HGLRC v = wglCreateContext(hdc);
    if (wglMakeCurrent(hdc, v) == FALSE) return NULL;
    procAss(PFNWGLSWAPINTERVALEXTPROC, wglSwapIntervalEXT);
    procAss(PFNWGLGETSWAPINTERVALEXTPROC, wglGetSwapIntervalEXT);
    return v;
}

BOOL wglSwapIntervalEXT(int interval) {
	procCallR(PFNWGLSWAPINTERVALEXTPROC, interval);
}

int wglGetSwapIntervalEXT(void) {
	procCallR(PFNWGLGETSWAPINTERVALEXTPROC);
}