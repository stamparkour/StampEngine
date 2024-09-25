#include "glm.h"
PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARBproc = 0;
HANDLE WINAPI wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType) {
	if (!wglCreateBufferRegionARBproc) return 0;
	return wglCreateBufferRegionARBproc(hDC, iLayerPlane, uType);
}
PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARBproc = 0;
VOID WINAPI wglDeleteBufferRegionARB(HANDLE hRegion) {
	if (!wglDeleteBufferRegionARBproc) return;
	wglDeleteBufferRegionARBproc(hRegion);
}
PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARBproc = 0;
BOOL WINAPI wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height) {
	if (!wglSaveBufferRegionARBproc) return 0;
	return wglSaveBufferRegionARBproc(hRegion, x, y, width, height);
}
PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARBproc = 0;
BOOL WINAPI wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc) {
	if (!wglRestoreBufferRegionARBproc) return 0;
	return wglRestoreBufferRegionARBproc(hRegion, x, y, width, height, xSrc, ySrc);
}
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARBproc = 0;
HGLRC WINAPI wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList) {
	if (!wglCreateContextAttribsARBproc) return 0;
	return wglCreateContextAttribsARBproc(hDC, hShareContext, attribList);
}
PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARBproc = 0;
const char* WINAPI wglGetExtensionsStringARB(HDC hdc) {
	if (!wglGetExtensionsStringARBproc) return 0;
	return wglGetExtensionsStringARBproc(hdc);
}
PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARBproc = 0;
BOOL WINAPI wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc) {
	if (!wglMakeContextCurrentARBproc) return 0;
	return wglMakeContextCurrentARBproc(hDrawDC, hReadDC, hglrc);
}
PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARBproc = 0;
HDC WINAPI wglGetCurrentReadDCARB(void) {
	if (!wglGetCurrentReadDCARBproc) return 0;
	return wglGetCurrentReadDCARBproc();
}
PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARBproc = 0;
HPBUFFERARB WINAPI wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) {
	if (!wglCreatePbufferARBproc) return 0;
	return wglCreatePbufferARBproc(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}
PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARBproc = 0;
HDC WINAPI wglGetPbufferDCARB(HPBUFFERARB hPbuffer) {
	if (!wglGetPbufferDCARBproc) return 0;
	return wglGetPbufferDCARBproc(hPbuffer);
}
PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARBproc = 0;
int WINAPI wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC) {
	if (!wglReleasePbufferDCARBproc) return 0;
	return wglReleasePbufferDCARBproc(hPbuffer, hDC);
}
PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARBproc = 0;
BOOL WINAPI wglDestroyPbufferARB(HPBUFFERARB hPbuffer) {
	if (!wglDestroyPbufferARBproc) return 0;
	return wglDestroyPbufferARBproc(hPbuffer);
}
PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARBproc = 0;
BOOL WINAPI wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int* piValue) {
	if (!wglQueryPbufferARBproc) return 0;
	return wglQueryPbufferARBproc(hPbuffer, iAttribute, piValue);
}
PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARBproc = 0;
BOOL WINAPI wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues) {
	if (!wglGetPixelFormatAttribivARBproc) return 0;
	return wglGetPixelFormatAttribivARBproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARBproc = 0;
BOOL WINAPI wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues) {
	if (!wglGetPixelFormatAttribfvARBproc) return 0;
	return wglGetPixelFormatAttribfvARBproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARBproc = 0;
BOOL WINAPI wglChoosePixelFormatARB(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats) {
	if (!wglChoosePixelFormatARBproc) return 0;
	return wglChoosePixelFormatARBproc(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}
PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARBproc = 0;
BOOL WINAPI wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer) {
	if (!wglBindTexImageARBproc) return 0;
	return wglBindTexImageARBproc(hPbuffer, iBuffer);
}
PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARBproc = 0;
BOOL WINAPI wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer) {
	if (!wglReleaseTexImageARBproc) return 0;
	return wglReleaseTexImageARBproc(hPbuffer, iBuffer);
}
PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARBproc = 0;
BOOL WINAPI wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int* piAttribList) {
	if (!wglSetPbufferAttribARBproc) return 0;
	return wglSetPbufferAttribARBproc(hPbuffer, piAttribList);
}
PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DLproc = 0;
BOOL WINAPI wglSetStereoEmitterState3DL(HDC hDC, UINT uState) {
	if (!wglSetStereoEmitterState3DLproc) return 0;
	return wglSetStereoEmitterState3DLproc(hDC, uState);
}
PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMDproc = 0;
UINT WINAPI wglGetGPUIDsAMD(UINT maxCount, UINT* ids) {
	if (!wglGetGPUIDsAMDproc) return 0;
	return wglGetGPUIDsAMDproc(maxCount, ids);
}
PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMDproc = 0;
INT WINAPI wglGetGPUInfoAMD(UINT id, INT property, GLenum dataType, UINT size, void* data) {
	if (!wglGetGPUInfoAMDproc) return 0;
	return wglGetGPUInfoAMDproc(id, property, dataType, size, data);
}
PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMDproc = 0;
UINT WINAPI wglGetContextGPUIDAMD(HGLRC hglrc) {
	if (!wglGetContextGPUIDAMDproc) return 0;
	return wglGetContextGPUIDAMDproc(hglrc);
}
PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMDproc = 0;
HGLRC WINAPI wglCreateAssociatedContextAMD(UINT id) {
	if (!wglCreateAssociatedContextAMDproc) return 0;
	return wglCreateAssociatedContextAMDproc(id);
}
PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMDproc = 0;
HGLRC WINAPI wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int* attribList) {
	if (!wglCreateAssociatedContextAttribsAMDproc) return 0;
	return wglCreateAssociatedContextAttribsAMDproc(id, hShareContext, attribList);
}
PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMDproc = 0;
BOOL WINAPI wglDeleteAssociatedContextAMD(HGLRC hglrc) {
	if (!wglDeleteAssociatedContextAMDproc) return 0;
	return wglDeleteAssociatedContextAMDproc(hglrc);
}
PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMDproc = 0;
BOOL WINAPI wglMakeAssociatedContextCurrentAMD(HGLRC hglrc) {
	if (!wglMakeAssociatedContextCurrentAMDproc) return 0;
	return wglMakeAssociatedContextCurrentAMDproc(hglrc);
}
PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMDproc = 0;
HGLRC WINAPI wglGetCurrentAssociatedContextAMD(void) {
	if (!wglGetCurrentAssociatedContextAMDproc) return 0;
	return wglGetCurrentAssociatedContextAMDproc();
}
PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMDproc = 0;
VOID WINAPI wglBlitContextFramebufferAMD(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	if (!wglBlitContextFramebufferAMDproc) return;
	wglBlitContextFramebufferAMDproc(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC wglCreateDisplayColorTableEXTproc = 0;
GLboolean WINAPI wglCreateDisplayColorTableEXT(GLushort id) {
	if (!wglCreateDisplayColorTableEXTproc) return 0;
	return wglCreateDisplayColorTableEXTproc(id);
}
PFNWGLLOADDISPLAYCOLORTABLEEXTPROC wglLoadDisplayColorTableEXTproc = 0;
GLboolean WINAPI wglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) {
	if (!wglLoadDisplayColorTableEXTproc) return 0;
	return wglLoadDisplayColorTableEXTproc(table, length);
}
PFNWGLBINDDISPLAYCOLORTABLEEXTPROC wglBindDisplayColorTableEXTproc = 0;
GLboolean WINAPI wglBindDisplayColorTableEXT(GLushort id) {
	if (!wglBindDisplayColorTableEXTproc) return 0;
	return wglBindDisplayColorTableEXTproc(id);
}
PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC wglDestroyDisplayColorTableEXTproc = 0;
VOID WINAPI wglDestroyDisplayColorTableEXT(GLushort id) {
	if (!wglDestroyDisplayColorTableEXTproc) return;
	wglDestroyDisplayColorTableEXTproc(id);
}
PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXTproc = 0;
const char* WINAPI wglGetExtensionsStringEXT(void) {
	if (!wglGetExtensionsStringEXTproc) return 0;
	return wglGetExtensionsStringEXTproc();
}
PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXTproc = 0;
BOOL WINAPI wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc) {
	if (!wglMakeContextCurrentEXTproc) return 0;
	return wglMakeContextCurrentEXTproc(hDrawDC, hReadDC, hglrc);
}
PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXTproc = 0;
HDC WINAPI wglGetCurrentReadDCEXT(void) {
	if (!wglGetCurrentReadDCEXTproc) return 0;
	return wglGetCurrentReadDCEXTproc();
}
PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXTproc = 0;
HPBUFFEREXT WINAPI wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) {
	if (!wglCreatePbufferEXTproc) return 0;
	return wglCreatePbufferEXTproc(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}
PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXTproc = 0;
HDC WINAPI wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer) {
	if (!wglGetPbufferDCEXTproc) return 0;
	return wglGetPbufferDCEXTproc(hPbuffer);
}
PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXTproc = 0;
int WINAPI wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC) {
	if (!wglReleasePbufferDCEXTproc) return 0;
	return wglReleasePbufferDCEXTproc(hPbuffer, hDC);
}
PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXTproc = 0;
BOOL WINAPI wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer) {
	if (!wglDestroyPbufferEXTproc) return 0;
	return wglDestroyPbufferEXTproc(hPbuffer);
}
PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXTproc = 0;
BOOL WINAPI wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue) {
	if (!wglQueryPbufferEXTproc) return 0;
	return wglQueryPbufferEXTproc(hPbuffer, iAttribute, piValue);
}
PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXTproc = 0;
BOOL WINAPI wglGetPixelFormatAttribivEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues) {
	if (!wglGetPixelFormatAttribivEXTproc) return 0;
	return wglGetPixelFormatAttribivEXTproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}
PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXTproc = 0;
BOOL WINAPI wglGetPixelFormatAttribfvEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues) {
	if (!wglGetPixelFormatAttribfvEXTproc) return 0;
	return wglGetPixelFormatAttribfvEXTproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}
PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXTproc = 0;
BOOL WINAPI wglChoosePixelFormatEXT(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats) {
	if (!wglChoosePixelFormatEXTproc) return 0;
	return wglChoosePixelFormatEXTproc(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXTproc = 0;
BOOL WINAPI wglSwapIntervalEXT(int interval) {
	if (!wglSwapIntervalEXTproc) return 0;
	return wglSwapIntervalEXTproc(interval);
}
PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXTproc = 0;
int WINAPI wglGetSwapIntervalEXT(void) {
	if (!wglGetSwapIntervalEXTproc) return 0;
	return wglGetSwapIntervalEXTproc();
}
PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3Dproc = 0;
BOOL WINAPI wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int* piValue) {
	if (!wglGetDigitalVideoParametersI3Dproc) return 0;
	return wglGetDigitalVideoParametersI3Dproc(hDC, iAttribute, piValue);
}
PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3Dproc = 0;
BOOL WINAPI wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int* piValue) {
	if (!wglSetDigitalVideoParametersI3Dproc) return 0;
	return wglSetDigitalVideoParametersI3Dproc(hDC, iAttribute, piValue);
}
PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3Dproc = 0;
BOOL WINAPI wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int* piValue) {
	if (!wglGetGammaTableParametersI3Dproc) return 0;
	return wglGetGammaTableParametersI3Dproc(hDC, iAttribute, piValue);
}
PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3Dproc = 0;
BOOL WINAPI wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int* piValue) {
	if (!wglSetGammaTableParametersI3Dproc) return 0;
	return wglSetGammaTableParametersI3Dproc(hDC, iAttribute, piValue);
}
PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3Dproc = 0;
BOOL WINAPI wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue) {
	if (!wglGetGammaTableI3Dproc) return 0;
	return wglGetGammaTableI3Dproc(hDC, iEntries, puRed, puGreen, puBlue);
}
PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3Dproc = 0;
BOOL WINAPI wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue) {
	if (!wglSetGammaTableI3Dproc) return 0;
	return wglSetGammaTableI3Dproc(hDC, iEntries, puRed, puGreen, puBlue);
}
PFNWGLENABLEGENLOCKI3DPROC wglEnableGenlockI3Dproc = 0;
BOOL WINAPI wglEnableGenlockI3D(HDC hDC) {
	if (!wglEnableGenlockI3Dproc) return 0;
	return wglEnableGenlockI3Dproc(hDC);
}
PFNWGLDISABLEGENLOCKI3DPROC wglDisableGenlockI3Dproc = 0;
BOOL WINAPI wglDisableGenlockI3D(HDC hDC) {
	if (!wglDisableGenlockI3Dproc) return 0;
	return wglDisableGenlockI3Dproc(hDC);
}
PFNWGLISENABLEDGENLOCKI3DPROC wglIsEnabledGenlockI3Dproc = 0;
BOOL WINAPI wglIsEnabledGenlockI3D(HDC hDC, BOOL* pFlag) {
	if (!wglIsEnabledGenlockI3Dproc) return 0;
	return wglIsEnabledGenlockI3Dproc(hDC, pFlag);
}
PFNWGLGENLOCKSOURCEI3DPROC wglGenlockSourceI3Dproc = 0;
BOOL WINAPI wglGenlockSourceI3D(HDC hDC, UINT uSource) {
	if (!wglGenlockSourceI3Dproc) return 0;
	return wglGenlockSourceI3Dproc(hDC, uSource);
}
PFNWGLGETGENLOCKSOURCEI3DPROC wglGetGenlockSourceI3Dproc = 0;
BOOL WINAPI wglGetGenlockSourceI3D(HDC hDC, UINT* uSource) {
	if (!wglGetGenlockSourceI3Dproc) return 0;
	return wglGetGenlockSourceI3Dproc(hDC, uSource);
}
PFNWGLGENLOCKSOURCEEDGEI3DPROC wglGenlockSourceEdgeI3Dproc = 0;
BOOL WINAPI wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge) {
	if (!wglGenlockSourceEdgeI3Dproc) return 0;
	return wglGenlockSourceEdgeI3Dproc(hDC, uEdge);
}
PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglGetGenlockSourceEdgeI3Dproc = 0;
BOOL WINAPI wglGetGenlockSourceEdgeI3D(HDC hDC, UINT* uEdge) {
	if (!wglGetGenlockSourceEdgeI3Dproc) return 0;
	return wglGetGenlockSourceEdgeI3Dproc(hDC, uEdge);
}
PFNWGLGENLOCKSAMPLERATEI3DPROC wglGenlockSampleRateI3Dproc = 0;
BOOL WINAPI wglGenlockSampleRateI3D(HDC hDC, UINT uRate) {
	if (!wglGenlockSampleRateI3Dproc) return 0;
	return wglGenlockSampleRateI3Dproc(hDC, uRate);
}
PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglGetGenlockSampleRateI3Dproc = 0;
BOOL WINAPI wglGetGenlockSampleRateI3D(HDC hDC, UINT* uRate) {
	if (!wglGetGenlockSampleRateI3Dproc) return 0;
	return wglGetGenlockSampleRateI3Dproc(hDC, uRate);
}
PFNWGLGENLOCKSOURCEDELAYI3DPROC wglGenlockSourceDelayI3Dproc = 0;
BOOL WINAPI wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay) {
	if (!wglGenlockSourceDelayI3Dproc) return 0;
	return wglGenlockSourceDelayI3Dproc(hDC, uDelay);
}
PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglGetGenlockSourceDelayI3Dproc = 0;
BOOL WINAPI wglGetGenlockSourceDelayI3D(HDC hDC, UINT* uDelay) {
	if (!wglGetGenlockSourceDelayI3Dproc) return 0;
	return wglGetGenlockSourceDelayI3Dproc(hDC, uDelay);
}
PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglQueryGenlockMaxSourceDelayI3Dproc = 0;
BOOL WINAPI wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay) {
	if (!wglQueryGenlockMaxSourceDelayI3Dproc) return 0;
	return wglQueryGenlockMaxSourceDelayI3Dproc(hDC, uMaxLineDelay, uMaxPixelDelay);
}
PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3Dproc = 0;
LPVOID WINAPI wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags) {
	if (!wglCreateImageBufferI3Dproc) return 0;
	return wglCreateImageBufferI3Dproc(hDC, dwSize, uFlags);
}
PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3Dproc = 0;
BOOL WINAPI wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress) {
	if (!wglDestroyImageBufferI3Dproc) return 0;
	return wglDestroyImageBufferI3Dproc(hDC, pAddress);
}
PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3Dproc = 0;
BOOL WINAPI wglAssociateImageBufferEventsI3D(HDC hDC, const HANDLE* pEvent, const LPVOID* pAddress, const DWORD* pSize, UINT count) {
	if (!wglAssociateImageBufferEventsI3Dproc) return 0;
	return wglAssociateImageBufferEventsI3Dproc(hDC, pEvent, pAddress, pSize, count);
}
PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3Dproc = 0;
BOOL WINAPI wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID* pAddress, UINT count) {
	if (!wglReleaseImageBufferEventsI3Dproc) return 0;
	return wglReleaseImageBufferEventsI3Dproc(hDC, pAddress, count);
}
PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3Dproc = 0;
BOOL WINAPI wglEnableFrameLockI3D(void) {
	if (!wglEnableFrameLockI3Dproc) return 0;
	return wglEnableFrameLockI3Dproc();
}
PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3Dproc = 0;
BOOL WINAPI wglDisableFrameLockI3D(void) {
	if (!wglDisableFrameLockI3Dproc) return 0;
	return wglDisableFrameLockI3Dproc();
}
PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3Dproc = 0;
BOOL WINAPI wglIsEnabledFrameLockI3D(BOOL* pFlag) {
	if (!wglIsEnabledFrameLockI3Dproc) return 0;
	return wglIsEnabledFrameLockI3Dproc(pFlag);
}
PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3Dproc = 0;
BOOL WINAPI wglQueryFrameLockMasterI3D(BOOL* pFlag) {
	if (!wglQueryFrameLockMasterI3Dproc) return 0;
	return wglQueryFrameLockMasterI3Dproc(pFlag);
}
PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3Dproc = 0;
BOOL WINAPI wglGetFrameUsageI3D(float* pUsage) {
	if (!wglGetFrameUsageI3Dproc) return 0;
	return wglGetFrameUsageI3Dproc(pUsage);
}
PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3Dproc = 0;
BOOL WINAPI wglBeginFrameTrackingI3D(void) {
	if (!wglBeginFrameTrackingI3Dproc) return 0;
	return wglBeginFrameTrackingI3Dproc();
}
PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3Dproc = 0;
BOOL WINAPI wglEndFrameTrackingI3D(void) {
	if (!wglEndFrameTrackingI3Dproc) return 0;
	return wglEndFrameTrackingI3Dproc();
}
PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3Dproc = 0;
BOOL WINAPI wglQueryFrameTrackingI3D(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage) {
	if (!wglQueryFrameTrackingI3Dproc) return 0;
	return wglQueryFrameTrackingI3Dproc(pFrameCount, pMissedFrames, pLastMissedUsage);
}
PFNWGLDXSETRESOURCESHAREHANDLENVPROC wglDXSetResourceShareHandleNVproc = 0;
BOOL WINAPI wglDXSetResourceShareHandleNV(void* dxObject, HANDLE shareHandle) {
	if (!wglDXSetResourceShareHandleNVproc) return 0;
	return wglDXSetResourceShareHandleNVproc(dxObject, shareHandle);
}
PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNVproc = 0;
HANDLE WINAPI wglDXOpenDeviceNV(void* dxDevice) {
	if (!wglDXOpenDeviceNVproc) return 0;
	return wglDXOpenDeviceNVproc(dxDevice);
}
PFNWGLDXCLOSEDEVICENVPROC wglDXCloseDeviceNVproc = 0;
BOOL WINAPI wglDXCloseDeviceNV(HANDLE hDevice) {
	if (!wglDXCloseDeviceNVproc) return 0;
	return wglDXCloseDeviceNVproc(hDevice);
}
PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNVproc = 0;
HANDLE WINAPI wglDXRegisterObjectNV(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access) {
	if (!wglDXRegisterObjectNVproc) return 0;
	return wglDXRegisterObjectNVproc(hDevice, dxObject, name, type, access);
}
PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNVproc = 0;
BOOL WINAPI wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject) {
	if (!wglDXUnregisterObjectNVproc) return 0;
	return wglDXUnregisterObjectNVproc(hDevice, hObject);
}
PFNWGLDXOBJECTACCESSNVPROC wglDXObjectAccessNVproc = 0;
BOOL WINAPI wglDXObjectAccessNV(HANDLE hObject, GLenum access) {
	if (!wglDXObjectAccessNVproc) return 0;
	return wglDXObjectAccessNVproc(hObject, access);
}
PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNVproc = 0;
BOOL WINAPI wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects) {
	if (!wglDXLockObjectsNVproc) return 0;
	return wglDXLockObjectsNVproc(hDevice, count, hObjects);
}
PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNVproc = 0;
BOOL WINAPI wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects) {
	if (!wglDXUnlockObjectsNVproc) return 0;
	return wglDXUnlockObjectsNVproc(hDevice, count, hObjects);
}
PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNVproc = 0;
BOOL WINAPI wglCopyImageSubDataNV(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
	if (!wglCopyImageSubDataNVproc) return 0;
	return wglCopyImageSubDataNVproc(hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}
PFNWGLDELAYBEFORESWAPNVPROC wglDelayBeforeSwapNVproc = 0;
BOOL WINAPI wglDelayBeforeSwapNV(HDC hDC, GLfloat seconds) {
	if (!wglDelayBeforeSwapNVproc) return 0;
	return wglDelayBeforeSwapNVproc(hDC, seconds);
}
PFNWGLENUMGPUSNVPROC wglEnumGpusNVproc = 0;
BOOL WINAPI wglEnumGpusNV(UINT iGpuIndex, HGPUNV* phGpu) {
	if (!wglEnumGpusNVproc) return 0;
	return wglEnumGpusNVproc(iGpuIndex, phGpu);
}
PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNVproc = 0;
BOOL WINAPI wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice) {
	if (!wglEnumGpuDevicesNVproc) return 0;
	return wglEnumGpuDevicesNVproc(hGpu, iDeviceIndex, lpGpuDevice);
}
PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNVproc = 0;
HDC WINAPI wglCreateAffinityDCNV(const HGPUNV* phGpuList) {
	if (!wglCreateAffinityDCNVproc) return 0;
	return wglCreateAffinityDCNVproc(phGpuList);
}
PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNVproc = 0;
BOOL WINAPI wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu) {
	if (!wglEnumGpusFromAffinityDCNVproc) return 0;
	return wglEnumGpusFromAffinityDCNVproc(hAffinityDC, iGpuIndex, hGpu);
}
PFNWGLDELETEDCNVPROC wglDeleteDCNVproc = 0;
BOOL WINAPI wglDeleteDCNV(HDC hdc) {
	if (!wglDeleteDCNVproc) return 0;
	return wglDeleteDCNVproc(hdc);
}
PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNVproc = 0;
int WINAPI wglEnumerateVideoDevicesNV(HDC hDc, HVIDEOOUTPUTDEVICENV* phDeviceList) {
	if (!wglEnumerateVideoDevicesNVproc) return 0;
	return wglEnumerateVideoDevicesNVproc(hDc, phDeviceList);
}
PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNVproc = 0;
BOOL WINAPI wglBindVideoDeviceNV(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList) {
	if (!wglBindVideoDeviceNVproc) return 0;
	return wglBindVideoDeviceNVproc(hDc, uVideoSlot, hVideoDevice, piAttribList);
}
PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNVproc = 0;
BOOL WINAPI wglQueryCurrentContextNV(int iAttribute, int* piValue) {
	if (!wglQueryCurrentContextNVproc) return 0;
	return wglQueryCurrentContextNVproc(iAttribute, piValue);
}
PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNVproc = 0;
BOOL WINAPI wglJoinSwapGroupNV(HDC hDC, GLuint group) {
	if (!wglJoinSwapGroupNVproc) return 0;
	return wglJoinSwapGroupNVproc(hDC, group);
}
PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNVproc = 0;
BOOL WINAPI wglBindSwapBarrierNV(GLuint group, GLuint barrier) {
	if (!wglBindSwapBarrierNVproc) return 0;
	return wglBindSwapBarrierNVproc(group, barrier);
}
PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNVproc = 0;
BOOL WINAPI wglQuerySwapGroupNV(HDC hDC, GLuint* group, GLuint* barrier) {
	if (!wglQuerySwapGroupNVproc) return 0;
	return wglQuerySwapGroupNVproc(hDC, group, barrier);
}
PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNVproc = 0;
BOOL WINAPI wglQueryMaxSwapGroupsNV(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers) {
	if (!wglQueryMaxSwapGroupsNVproc) return 0;
	return wglQueryMaxSwapGroupsNVproc(hDC, maxGroups, maxBarriers);
}
PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNVproc = 0;
BOOL WINAPI wglQueryFrameCountNV(HDC hDC, GLuint* count) {
	if (!wglQueryFrameCountNVproc) return 0;
	return wglQueryFrameCountNVproc(hDC, count);
}
PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNVproc = 0;
BOOL WINAPI wglResetFrameCountNV(HDC hDC) {
	if (!wglResetFrameCountNVproc) return 0;
	return wglResetFrameCountNVproc(hDC);
}
PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemoryNVproc = 0;
void* WINAPI wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority) {
	if (!wglAllocateMemoryNVproc) return 0;
	return wglAllocateMemoryNVproc(size, readfreq, writefreq, priority);
}
PFNWGLFREEMEMORYNVPROC wglFreeMemoryNVproc = 0;
void WINAPI wglFreeMemoryNV(void* pointer) {
	if (!wglFreeMemoryNVproc) return;
	wglFreeMemoryNVproc(pointer);
}
PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNVproc = 0;
BOOL WINAPI wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice) {
	if (!wglBindVideoCaptureDeviceNVproc) return 0;
	return wglBindVideoCaptureDeviceNVproc(uVideoSlot, hDevice);
}
PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNVproc = 0;
UINT WINAPI wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList) {
	if (!wglEnumerateVideoCaptureDevicesNVproc) return 0;
	return wglEnumerateVideoCaptureDevicesNVproc(hDc, phDeviceList);
}
PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNVproc = 0;
BOOL WINAPI wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice) {
	if (!wglLockVideoCaptureDeviceNVproc) return 0;
	return wglLockVideoCaptureDeviceNVproc(hDc, hDevice);
}
PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNVproc = 0;
BOOL WINAPI wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue) {
	if (!wglQueryVideoCaptureDeviceNVproc) return 0;
	return wglQueryVideoCaptureDeviceNVproc(hDc, hDevice, iAttribute, piValue);
}
PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNVproc = 0;
BOOL WINAPI wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice) {
	if (!wglReleaseVideoCaptureDeviceNVproc) return 0;
	return wglReleaseVideoCaptureDeviceNVproc(hDc, hDevice);
}
PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNVproc = 0;
BOOL WINAPI wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice) {
	if (!wglGetVideoDeviceNVproc) return 0;
	return wglGetVideoDeviceNVproc(hDC, numDevices, hVideoDevice);
}
PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNVproc = 0;
BOOL WINAPI wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice) {
	if (!wglReleaseVideoDeviceNVproc) return 0;
	return wglReleaseVideoDeviceNVproc(hVideoDevice);
}
PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNVproc = 0;
BOOL WINAPI wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer) {
	if (!wglBindVideoImageNVproc) return 0;
	return wglBindVideoImageNVproc(hVideoDevice, hPbuffer, iVideoBuffer);
}
PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNVproc = 0;
BOOL WINAPI wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer) {
	if (!wglReleaseVideoImageNVproc) return 0;
	return wglReleaseVideoImageNVproc(hPbuffer, iVideoBuffer);
}
PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNVproc = 0;
BOOL WINAPI wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock) {
	if (!wglSendPbufferToVideoNVproc) return 0;
	return wglSendPbufferToVideoNVproc(hPbuffer, iBufferType, pulCounterPbuffer, bBlock);
}
PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNVproc = 0;
BOOL WINAPI wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo) {
	if (!wglGetVideoInfoNVproc) return 0;
	return wglGetVideoInfoNVproc(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);
}
PFNWGLGETSYNCVALUESOMLPROC wglGetSyncValuesOMLproc = 0;
BOOL WINAPI wglGetSyncValuesOML(HDC hdc, INT64* ust, INT64* msc, INT64* sbc) {
	if (!wglGetSyncValuesOMLproc) return 0;
	return wglGetSyncValuesOMLproc(hdc, ust, msc, sbc);
}
PFNWGLGETMSCRATEOMLPROC wglGetMscRateOMLproc = 0;
BOOL WINAPI wglGetMscRateOML(HDC hdc, INT32* numerator, INT32* denominator) {
	if (!wglGetMscRateOMLproc) return 0;
	return wglGetMscRateOMLproc(hdc, numerator, denominator);
}
PFNWGLSWAPBUFFERSMSCOMLPROC wglSwapBuffersMscOMLproc = 0;
INT64 WINAPI wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder) {
	if (!wglSwapBuffersMscOMLproc) return 0;
	return wglSwapBuffersMscOMLproc(hdc, target_msc, divisor, remainder);
}
PFNWGLSWAPLAYERBUFFERSMSCOMLPROC wglSwapLayerBuffersMscOMLproc = 0;
INT64 WINAPI wglSwapLayerBuffersMscOML(HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder) {
	if (!wglSwapLayerBuffersMscOMLproc) return 0;
	return wglSwapLayerBuffersMscOMLproc(hdc, fuPlanes, target_msc, divisor, remainder);
}
PFNWGLWAITFORMSCOMLPROC wglWaitForMscOMLproc = 0;
BOOL WINAPI wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc) {
	if (!wglWaitForMscOMLproc) return 0;
	return wglWaitForMscOMLproc(hdc, target_msc, divisor, remainder, ust, msc, sbc);
}
PFNWGLWAITFORSBCOMLPROC wglWaitForSbcOMLproc = 0;
BOOL WINAPI wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc) {
	if (!wglWaitForSbcOMLproc) return 0;
	return wglWaitForSbcOMLproc(hdc, target_sbc, ust, msc, sbc);
}
void wglextInit() {
	wglCreateBufferRegionARBproc = (PFNWGLCREATEBUFFERREGIONARBPROC)wglGetProcAddress("wglCreateBufferRegionARB");
	wglDeleteBufferRegionARBproc = (PFNWGLDELETEBUFFERREGIONARBPROC)wglGetProcAddress("wglDeleteBufferRegionARB");
	wglSaveBufferRegionARBproc = (PFNWGLSAVEBUFFERREGIONARBPROC)wglGetProcAddress("wglSaveBufferRegionARB");
	wglRestoreBufferRegionARBproc = (PFNWGLRESTOREBUFFERREGIONARBPROC)wglGetProcAddress("wglRestoreBufferRegionARB");
	wglCreateContextAttribsARBproc = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	wglGetExtensionsStringARBproc = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");
	wglMakeContextCurrentARBproc = (PFNWGLMAKECONTEXTCURRENTARBPROC)wglGetProcAddress("wglMakeContextCurrentARB");
	wglGetCurrentReadDCARBproc = (PFNWGLGETCURRENTREADDCARBPROC)wglGetProcAddress("wglGetCurrentReadDCARB");
	wglCreatePbufferARBproc = (PFNWGLCREATEPBUFFERARBPROC)wglGetProcAddress("wglCreatePbufferARB");
	wglGetPbufferDCARBproc = (PFNWGLGETPBUFFERDCARBPROC)wglGetProcAddress("wglGetPbufferDCARB");
	wglReleasePbufferDCARBproc = (PFNWGLRELEASEPBUFFERDCARBPROC)wglGetProcAddress("wglReleasePbufferDCARB");
	wglDestroyPbufferARBproc = (PFNWGLDESTROYPBUFFERARBPROC)wglGetProcAddress("wglDestroyPbufferARB");
	wglQueryPbufferARBproc = (PFNWGLQUERYPBUFFERARBPROC)wglGetProcAddress("wglQueryPbufferARB");
	wglGetPixelFormatAttribivARBproc = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribivARB");
	wglGetPixelFormatAttribfvARBproc = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribfvARB");
	wglChoosePixelFormatARBproc = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
	wglBindTexImageARBproc = (PFNWGLBINDTEXIMAGEARBPROC)wglGetProcAddress("wglBindTexImageARB");
	wglReleaseTexImageARBproc = (PFNWGLRELEASETEXIMAGEARBPROC)wglGetProcAddress("wglReleaseTexImageARB");
	wglSetPbufferAttribARBproc = (PFNWGLSETPBUFFERATTRIBARBPROC)wglGetProcAddress("wglSetPbufferAttribARB");
	wglSetStereoEmitterState3DLproc = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC)wglGetProcAddress("wglSetStereoEmitterState3DL");
	wglGetGPUIDsAMDproc = (PFNWGLGETGPUIDSAMDPROC)wglGetProcAddress("wglGetGPUIDsAMD");
	wglGetGPUInfoAMDproc = (PFNWGLGETGPUINFOAMDPROC)wglGetProcAddress("wglGetGPUInfoAMD");
	wglGetContextGPUIDAMDproc = (PFNWGLGETCONTEXTGPUIDAMDPROC)wglGetProcAddress("wglGetContextGPUIDAMD");
	wglCreateAssociatedContextAMDproc = (PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglCreateAssociatedContextAMD");
	wglCreateAssociatedContextAttribsAMDproc = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)wglGetProcAddress("wglCreateAssociatedContextAttribsAMD");
	wglDeleteAssociatedContextAMDproc = (PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglDeleteAssociatedContextAMD");
	wglMakeAssociatedContextCurrentAMDproc = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)wglGetProcAddress("wglMakeAssociatedContextCurrentAMD");
	wglGetCurrentAssociatedContextAMDproc = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglGetCurrentAssociatedContextAMD");
	wglBlitContextFramebufferAMDproc = (PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)wglGetProcAddress("wglBlitContextFramebufferAMD");
	wglCreateDisplayColorTableEXTproc = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglCreateDisplayColorTableEXT");
	wglLoadDisplayColorTableEXTproc = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglLoadDisplayColorTableEXT");
	wglBindDisplayColorTableEXTproc = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglBindDisplayColorTableEXT");
	wglDestroyDisplayColorTableEXTproc = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglDestroyDisplayColorTableEXT");
	wglGetExtensionsStringEXTproc = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT");
	wglMakeContextCurrentEXTproc = (PFNWGLMAKECONTEXTCURRENTEXTPROC)wglGetProcAddress("wglMakeContextCurrentEXT");
	wglGetCurrentReadDCEXTproc = (PFNWGLGETCURRENTREADDCEXTPROC)wglGetProcAddress("wglGetCurrentReadDCEXT");
	wglCreatePbufferEXTproc = (PFNWGLCREATEPBUFFEREXTPROC)wglGetProcAddress("wglCreatePbufferEXT");
	wglGetPbufferDCEXTproc = (PFNWGLGETPBUFFERDCEXTPROC)wglGetProcAddress("wglGetPbufferDCEXT");
	wglReleasePbufferDCEXTproc = (PFNWGLRELEASEPBUFFERDCEXTPROC)wglGetProcAddress("wglReleasePbufferDCEXT");
	wglDestroyPbufferEXTproc = (PFNWGLDESTROYPBUFFEREXTPROC)wglGetProcAddress("wglDestroyPbufferEXT");
	wglQueryPbufferEXTproc = (PFNWGLQUERYPBUFFEREXTPROC)wglGetProcAddress("wglQueryPbufferEXT");
	wglGetPixelFormatAttribivEXTproc = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)wglGetProcAddress("wglGetPixelFormatAttribivEXT");
	wglGetPixelFormatAttribfvEXTproc = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)wglGetProcAddress("wglGetPixelFormatAttribfvEXT");
	wglChoosePixelFormatEXTproc = (PFNWGLCHOOSEPIXELFORMATEXTPROC)wglGetProcAddress("wglChoosePixelFormatEXT");
	wglSwapIntervalEXTproc = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
	wglGetSwapIntervalEXTproc = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
	wglGetDigitalVideoParametersI3Dproc = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)wglGetProcAddress("wglGetDigitalVideoParametersI3D");
	wglSetDigitalVideoParametersI3Dproc = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)wglGetProcAddress("wglSetDigitalVideoParametersI3D");
	wglGetGammaTableParametersI3Dproc = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)wglGetProcAddress("wglGetGammaTableParametersI3D");
	wglSetGammaTableParametersI3Dproc = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)wglGetProcAddress("wglSetGammaTableParametersI3D");
	wglGetGammaTableI3Dproc = (PFNWGLGETGAMMATABLEI3DPROC)wglGetProcAddress("wglGetGammaTableI3D");
	wglSetGammaTableI3Dproc = (PFNWGLSETGAMMATABLEI3DPROC)wglGetProcAddress("wglSetGammaTableI3D");
	wglEnableGenlockI3Dproc = (PFNWGLENABLEGENLOCKI3DPROC)wglGetProcAddress("wglEnableGenlockI3D");
	wglDisableGenlockI3Dproc = (PFNWGLDISABLEGENLOCKI3DPROC)wglGetProcAddress("wglDisableGenlockI3D");
	wglIsEnabledGenlockI3Dproc = (PFNWGLISENABLEDGENLOCKI3DPROC)wglGetProcAddress("wglIsEnabledGenlockI3D");
	wglGenlockSourceI3Dproc = (PFNWGLGENLOCKSOURCEI3DPROC)wglGetProcAddress("wglGenlockSourceI3D");
	wglGetGenlockSourceI3Dproc = (PFNWGLGETGENLOCKSOURCEI3DPROC)wglGetProcAddress("wglGetGenlockSourceI3D");
	wglGenlockSourceEdgeI3Dproc = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)wglGetProcAddress("wglGenlockSourceEdgeI3D");
	wglGetGenlockSourceEdgeI3Dproc = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)wglGetProcAddress("wglGetGenlockSourceEdgeI3D");
	wglGenlockSampleRateI3Dproc = (PFNWGLGENLOCKSAMPLERATEI3DPROC)wglGetProcAddress("wglGenlockSampleRateI3D");
	wglGetGenlockSampleRateI3Dproc = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)wglGetProcAddress("wglGetGenlockSampleRateI3D");
	wglGenlockSourceDelayI3Dproc = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)wglGetProcAddress("wglGenlockSourceDelayI3D");
	wglGetGenlockSourceDelayI3Dproc = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)wglGetProcAddress("wglGetGenlockSourceDelayI3D");
	wglQueryGenlockMaxSourceDelayI3Dproc = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)wglGetProcAddress("wglQueryGenlockMaxSourceDelayI3D");
	wglCreateImageBufferI3Dproc = (PFNWGLCREATEIMAGEBUFFERI3DPROC)wglGetProcAddress("wglCreateImageBufferI3D");
	wglDestroyImageBufferI3Dproc = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)wglGetProcAddress("wglDestroyImageBufferI3D");
	wglAssociateImageBufferEventsI3Dproc = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)wglGetProcAddress("wglAssociateImageBufferEventsI3D");
	wglReleaseImageBufferEventsI3Dproc = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)wglGetProcAddress("wglReleaseImageBufferEventsI3D");
	wglEnableFrameLockI3Dproc = (PFNWGLENABLEFRAMELOCKI3DPROC)wglGetProcAddress("wglEnableFrameLockI3D");
	wglDisableFrameLockI3Dproc = (PFNWGLDISABLEFRAMELOCKI3DPROC)wglGetProcAddress("wglDisableFrameLockI3D");
	wglIsEnabledFrameLockI3Dproc = (PFNWGLISENABLEDFRAMELOCKI3DPROC)wglGetProcAddress("wglIsEnabledFrameLockI3D");
	wglQueryFrameLockMasterI3Dproc = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)wglGetProcAddress("wglQueryFrameLockMasterI3D");
	wglGetFrameUsageI3Dproc = (PFNWGLGETFRAMEUSAGEI3DPROC)wglGetProcAddress("wglGetFrameUsageI3D");
	wglBeginFrameTrackingI3Dproc = (PFNWGLBEGINFRAMETRACKINGI3DPROC)wglGetProcAddress("wglBeginFrameTrackingI3D");
	wglEndFrameTrackingI3Dproc = (PFNWGLENDFRAMETRACKINGI3DPROC)wglGetProcAddress("wglEndFrameTrackingI3D");
	wglQueryFrameTrackingI3Dproc = (PFNWGLQUERYFRAMETRACKINGI3DPROC)wglGetProcAddress("wglQueryFrameTrackingI3D");
	wglDXSetResourceShareHandleNVproc = (PFNWGLDXSETRESOURCESHAREHANDLENVPROC)wglGetProcAddress("wglDXSetResourceShareHandleNV");
	wglDXOpenDeviceNVproc = (PFNWGLDXOPENDEVICENVPROC)wglGetProcAddress("wglDXOpenDeviceNV");
	wglDXCloseDeviceNVproc = (PFNWGLDXCLOSEDEVICENVPROC)wglGetProcAddress("wglDXCloseDeviceNV");
	wglDXRegisterObjectNVproc = (PFNWGLDXREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXRegisterObjectNV");
	wglDXUnregisterObjectNVproc = (PFNWGLDXUNREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXUnregisterObjectNV");
	wglDXObjectAccessNVproc = (PFNWGLDXOBJECTACCESSNVPROC)wglGetProcAddress("wglDXObjectAccessNV");
	wglDXLockObjectsNVproc = (PFNWGLDXLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXLockObjectsNV");
	wglDXUnlockObjectsNVproc = (PFNWGLDXUNLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXUnlockObjectsNV");
	wglCopyImageSubDataNVproc = (PFNWGLCOPYIMAGESUBDATANVPROC)wglGetProcAddress("wglCopyImageSubDataNV");
	wglDelayBeforeSwapNVproc = (PFNWGLDELAYBEFORESWAPNVPROC)wglGetProcAddress("wglDelayBeforeSwapNV");
	wglEnumGpusNVproc = (PFNWGLENUMGPUSNVPROC)wglGetProcAddress("wglEnumGpusNV");
	wglEnumGpuDevicesNVproc = (PFNWGLENUMGPUDEVICESNVPROC)wglGetProcAddress("wglEnumGpuDevicesNV");
	wglCreateAffinityDCNVproc = (PFNWGLCREATEAFFINITYDCNVPROC)wglGetProcAddress("wglCreateAffinityDCNV");
	wglEnumGpusFromAffinityDCNVproc = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)wglGetProcAddress("wglEnumGpusFromAffinityDCNV");
	wglDeleteDCNVproc = (PFNWGLDELETEDCNVPROC)wglGetProcAddress("wglDeleteDCNV");
	wglEnumerateVideoDevicesNVproc = (PFNWGLENUMERATEVIDEODEVICESNVPROC)wglGetProcAddress("wglEnumerateVideoDevicesNV");
	wglBindVideoDeviceNVproc = (PFNWGLBINDVIDEODEVICENVPROC)wglGetProcAddress("wglBindVideoDeviceNV");
	wglQueryCurrentContextNVproc = (PFNWGLQUERYCURRENTCONTEXTNVPROC)wglGetProcAddress("wglQueryCurrentContextNV");
	wglJoinSwapGroupNVproc = (PFNWGLJOINSWAPGROUPNVPROC)wglGetProcAddress("wglJoinSwapGroupNV");
	wglBindSwapBarrierNVproc = (PFNWGLBINDSWAPBARRIERNVPROC)wglGetProcAddress("wglBindSwapBarrierNV");
	wglQuerySwapGroupNVproc = (PFNWGLQUERYSWAPGROUPNVPROC)wglGetProcAddress("wglQuerySwapGroupNV");
	wglQueryMaxSwapGroupsNVproc = (PFNWGLQUERYMAXSWAPGROUPSNVPROC)wglGetProcAddress("wglQueryMaxSwapGroupsNV");
	wglQueryFrameCountNVproc = (PFNWGLQUERYFRAMECOUNTNVPROC)wglGetProcAddress("wglQueryFrameCountNV");
	wglResetFrameCountNVproc = (PFNWGLRESETFRAMECOUNTNVPROC)wglGetProcAddress("wglResetFrameCountNV");
	wglAllocateMemoryNVproc = (PFNWGLALLOCATEMEMORYNVPROC)wglGetProcAddress("wglAllocateMemoryNV");
	wglFreeMemoryNVproc = (PFNWGLFREEMEMORYNVPROC)wglGetProcAddress("wglFreeMemoryNV");
	wglBindVideoCaptureDeviceNVproc = (PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglBindVideoCaptureDeviceNV");
	wglEnumerateVideoCaptureDevicesNVproc = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)wglGetProcAddress("wglEnumerateVideoCaptureDevicesNV");
	wglLockVideoCaptureDeviceNVproc = (PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglLockVideoCaptureDeviceNV");
	wglQueryVideoCaptureDeviceNVproc = (PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglQueryVideoCaptureDeviceNV");
	wglReleaseVideoCaptureDeviceNVproc = (PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglReleaseVideoCaptureDeviceNV");
	wglGetVideoDeviceNVproc = (PFNWGLGETVIDEODEVICENVPROC)wglGetProcAddress("wglGetVideoDeviceNV");
	wglReleaseVideoDeviceNVproc = (PFNWGLRELEASEVIDEODEVICENVPROC)wglGetProcAddress("wglReleaseVideoDeviceNV");
	wglBindVideoImageNVproc = (PFNWGLBINDVIDEOIMAGENVPROC)wglGetProcAddress("wglBindVideoImageNV");
	wglReleaseVideoImageNVproc = (PFNWGLRELEASEVIDEOIMAGENVPROC)wglGetProcAddress("wglReleaseVideoImageNV");
	wglSendPbufferToVideoNVproc = (PFNWGLSENDPBUFFERTOVIDEONVPROC)wglGetProcAddress("wglSendPbufferToVideoNV");
	wglGetVideoInfoNVproc = (PFNWGLGETVIDEOINFONVPROC)wglGetProcAddress("wglGetVideoInfoNV");
	wglGetSyncValuesOMLproc = (PFNWGLGETSYNCVALUESOMLPROC)wglGetProcAddress("wglGetSyncValuesOML");
	wglGetMscRateOMLproc = (PFNWGLGETMSCRATEOMLPROC)wglGetProcAddress("wglGetMscRateOML");
	wglSwapBuffersMscOMLproc = (PFNWGLSWAPBUFFERSMSCOMLPROC)wglGetProcAddress("wglSwapBuffersMscOML");
	wglSwapLayerBuffersMscOMLproc = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)wglGetProcAddress("wglSwapLayerBuffersMscOML");
	wglWaitForMscOMLproc = (PFNWGLWAITFORMSCOMLPROC)wglGetProcAddress("wglWaitForMscOML");
	wglWaitForSbcOMLproc = (PFNWGLWAITFORSBCOMLPROC)wglGetProcAddress("wglWaitForSbcOML");
}
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElementsproc = 0;
void APIENTRY glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) {
	if (!glDrawRangeElementsproc) return;
	glDrawRangeElementsproc(mode, start, end, count, type, indices);
}
PFNGLTEXIMAGE3DPROC glTexImage3Dproc = 0;
void APIENTRY glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glTexImage3Dproc) return;
	glTexImage3Dproc(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3Dproc = 0;
void APIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) {
	if (!glTexSubImage3Dproc) return;
	glTexSubImage3Dproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3Dproc = 0;
void APIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyTexSubImage3Dproc) return;
	glCopyTexSubImage3Dproc(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLACTIVETEXTUREPROC glActiveTextureproc = 0;
void APIENTRY glActiveTexture(GLenum texture) {
	if (!glActiveTextureproc) return;
	glActiveTextureproc(texture);
}
PFNGLSAMPLECOVERAGEPROC glSampleCoverageproc = 0;
void APIENTRY glSampleCoverage(GLfloat value, GLboolean invert) {
	if (!glSampleCoverageproc) return;
	glSampleCoverageproc(value, invert);
}
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3Dproc = 0;
void APIENTRY glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) {
	if (!glCompressedTexImage3Dproc) return;
	glCompressedTexImage3Dproc(target, level, internalformat, width, height, depth, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2Dproc = 0;
void APIENTRY glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) {
	if (!glCompressedTexImage2Dproc) return;
	glCompressedTexImage2Dproc(target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1Dproc = 0;
void APIENTRY glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) {
	if (!glCompressedTexImage1Dproc) return;
	glCompressedTexImage1Dproc(target, level, internalformat, width, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3Dproc = 0;
void APIENTRY glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTexSubImage3Dproc) return;
	glCompressedTexSubImage3Dproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2Dproc = 0;
void APIENTRY glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTexSubImage2Dproc) return;
	glCompressedTexSubImage2Dproc(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1Dproc = 0;
void APIENTRY glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTexSubImage1Dproc) return;
	glCompressedTexSubImage1Dproc(target, level, xoffset, width, format, imageSize, data);
}
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImageproc = 0;
void APIENTRY glGetCompressedTexImage(GLenum target, GLint level, void* img) {
	if (!glGetCompressedTexImageproc) return;
	glGetCompressedTexImageproc(target, level, img);
}
PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTextureproc = 0;
void APIENTRY glClientActiveTexture(GLenum texture) {
	if (!glClientActiveTextureproc) return;
	glClientActiveTextureproc(texture);
}
PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1dproc = 0;
void APIENTRY glMultiTexCoord1d(GLenum target, GLdouble s) {
	if (!glMultiTexCoord1dproc) return;
	glMultiTexCoord1dproc(target, s);
}
PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dvproc = 0;
void APIENTRY glMultiTexCoord1dv(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord1dvproc) return;
	glMultiTexCoord1dvproc(target, v);
}
PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1fproc = 0;
void APIENTRY glMultiTexCoord1f(GLenum target, GLfloat s) {
	if (!glMultiTexCoord1fproc) return;
	glMultiTexCoord1fproc(target, s);
}
PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fvproc = 0;
void APIENTRY glMultiTexCoord1fv(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord1fvproc) return;
	glMultiTexCoord1fvproc(target, v);
}
PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1iproc = 0;
void APIENTRY glMultiTexCoord1i(GLenum target, GLint s) {
	if (!glMultiTexCoord1iproc) return;
	glMultiTexCoord1iproc(target, s);
}
PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1ivproc = 0;
void APIENTRY glMultiTexCoord1iv(GLenum target, const GLint* v) {
	if (!glMultiTexCoord1ivproc) return;
	glMultiTexCoord1ivproc(target, v);
}
PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1sproc = 0;
void APIENTRY glMultiTexCoord1s(GLenum target, GLshort s) {
	if (!glMultiTexCoord1sproc) return;
	glMultiTexCoord1sproc(target, s);
}
PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1svproc = 0;
void APIENTRY glMultiTexCoord1sv(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord1svproc) return;
	glMultiTexCoord1svproc(target, v);
}
PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2dproc = 0;
void APIENTRY glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
	if (!glMultiTexCoord2dproc) return;
	glMultiTexCoord2dproc(target, s, t);
}
PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dvproc = 0;
void APIENTRY glMultiTexCoord2dv(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord2dvproc) return;
	glMultiTexCoord2dvproc(target, v);
}
PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2fproc = 0;
void APIENTRY glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
	if (!glMultiTexCoord2fproc) return;
	glMultiTexCoord2fproc(target, s, t);
}
PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fvproc = 0;
void APIENTRY glMultiTexCoord2fv(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord2fvproc) return;
	glMultiTexCoord2fvproc(target, v);
}
PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2iproc = 0;
void APIENTRY glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
	if (!glMultiTexCoord2iproc) return;
	glMultiTexCoord2iproc(target, s, t);
}
PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2ivproc = 0;
void APIENTRY glMultiTexCoord2iv(GLenum target, const GLint* v) {
	if (!glMultiTexCoord2ivproc) return;
	glMultiTexCoord2ivproc(target, v);
}
PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2sproc = 0;
void APIENTRY glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
	if (!glMultiTexCoord2sproc) return;
	glMultiTexCoord2sproc(target, s, t);
}
PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2svproc = 0;
void APIENTRY glMultiTexCoord2sv(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord2svproc) return;
	glMultiTexCoord2svproc(target, v);
}
PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3dproc = 0;
void APIENTRY glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
	if (!glMultiTexCoord3dproc) return;
	glMultiTexCoord3dproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dvproc = 0;
void APIENTRY glMultiTexCoord3dv(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord3dvproc) return;
	glMultiTexCoord3dvproc(target, v);
}
PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3fproc = 0;
void APIENTRY glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
	if (!glMultiTexCoord3fproc) return;
	glMultiTexCoord3fproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fvproc = 0;
void APIENTRY glMultiTexCoord3fv(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord3fvproc) return;
	glMultiTexCoord3fvproc(target, v);
}
PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3iproc = 0;
void APIENTRY glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
	if (!glMultiTexCoord3iproc) return;
	glMultiTexCoord3iproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3ivproc = 0;
void APIENTRY glMultiTexCoord3iv(GLenum target, const GLint* v) {
	if (!glMultiTexCoord3ivproc) return;
	glMultiTexCoord3ivproc(target, v);
}
PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3sproc = 0;
void APIENTRY glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
	if (!glMultiTexCoord3sproc) return;
	glMultiTexCoord3sproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3svproc = 0;
void APIENTRY glMultiTexCoord3sv(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord3svproc) return;
	glMultiTexCoord3svproc(target, v);
}
PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4dproc = 0;
void APIENTRY glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
	if (!glMultiTexCoord4dproc) return;
	glMultiTexCoord4dproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dvproc = 0;
void APIENTRY glMultiTexCoord4dv(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord4dvproc) return;
	glMultiTexCoord4dvproc(target, v);
}
PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4fproc = 0;
void APIENTRY glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	if (!glMultiTexCoord4fproc) return;
	glMultiTexCoord4fproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fvproc = 0;
void APIENTRY glMultiTexCoord4fv(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord4fvproc) return;
	glMultiTexCoord4fvproc(target, v);
}
PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4iproc = 0;
void APIENTRY glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
	if (!glMultiTexCoord4iproc) return;
	glMultiTexCoord4iproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4ivproc = 0;
void APIENTRY glMultiTexCoord4iv(GLenum target, const GLint* v) {
	if (!glMultiTexCoord4ivproc) return;
	glMultiTexCoord4ivproc(target, v);
}
PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4sproc = 0;
void APIENTRY glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
	if (!glMultiTexCoord4sproc) return;
	glMultiTexCoord4sproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4svproc = 0;
void APIENTRY glMultiTexCoord4sv(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord4svproc) return;
	glMultiTexCoord4svproc(target, v);
}
PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixfproc = 0;
void APIENTRY glLoadTransposeMatrixf(const GLfloat* m) {
	if (!glLoadTransposeMatrixfproc) return;
	glLoadTransposeMatrixfproc(m);
}
PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixdproc = 0;
void APIENTRY glLoadTransposeMatrixd(const GLdouble* m) {
	if (!glLoadTransposeMatrixdproc) return;
	glLoadTransposeMatrixdproc(m);
}
PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixfproc = 0;
void APIENTRY glMultTransposeMatrixf(const GLfloat* m) {
	if (!glMultTransposeMatrixfproc) return;
	glMultTransposeMatrixfproc(m);
}
PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixdproc = 0;
void APIENTRY glMultTransposeMatrixd(const GLdouble* m) {
	if (!glMultTransposeMatrixdproc) return;
	glMultTransposeMatrixdproc(m);
}
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparateproc = 0;
void APIENTRY glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	if (!glBlendFuncSeparateproc) return;
	glBlendFuncSeparateproc(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArraysproc = 0;
void APIENTRY glMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount) {
	if (!glMultiDrawArraysproc) return;
	glMultiDrawArraysproc(mode, first, count, drawcount);
}
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElementsproc = 0;
void APIENTRY glMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount) {
	if (!glMultiDrawElementsproc) return;
	glMultiDrawElementsproc(mode, count, type, indices, drawcount);
}
PFNGLPOINTPARAMETERFPROC glPointParameterfproc = 0;
void APIENTRY glPointParameterf(GLenum pname, GLfloat param) {
	if (!glPointParameterfproc) return;
	glPointParameterfproc(pname, param);
}
PFNGLPOINTPARAMETERFVPROC glPointParameterfvproc = 0;
void APIENTRY glPointParameterfv(GLenum pname, const GLfloat* params) {
	if (!glPointParameterfvproc) return;
	glPointParameterfvproc(pname, params);
}
PFNGLPOINTPARAMETERIPROC glPointParameteriproc = 0;
void APIENTRY glPointParameteri(GLenum pname, GLint param) {
	if (!glPointParameteriproc) return;
	glPointParameteriproc(pname, param);
}
PFNGLPOINTPARAMETERIVPROC glPointParameterivproc = 0;
void APIENTRY glPointParameteriv(GLenum pname, const GLint* params) {
	if (!glPointParameterivproc) return;
	glPointParameterivproc(pname, params);
}
PFNGLFOGCOORDFPROC glFogCoordfproc = 0;
void APIENTRY glFogCoordf(GLfloat coord) {
	if (!glFogCoordfproc) return;
	glFogCoordfproc(coord);
}
PFNGLFOGCOORDFVPROC glFogCoordfvproc = 0;
void APIENTRY glFogCoordfv(const GLfloat* coord) {
	if (!glFogCoordfvproc) return;
	glFogCoordfvproc(coord);
}
PFNGLFOGCOORDDPROC glFogCoorddproc = 0;
void APIENTRY glFogCoordd(GLdouble coord) {
	if (!glFogCoorddproc) return;
	glFogCoorddproc(coord);
}
PFNGLFOGCOORDDVPROC glFogCoorddvproc = 0;
void APIENTRY glFogCoorddv(const GLdouble* coord) {
	if (!glFogCoorddvproc) return;
	glFogCoorddvproc(coord);
}
PFNGLFOGCOORDPOINTERPROC glFogCoordPointerproc = 0;
void APIENTRY glFogCoordPointer(GLenum type, GLsizei stride, const void* pointer) {
	if (!glFogCoordPointerproc) return;
	glFogCoordPointerproc(type, stride, pointer);
}
PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3bproc = 0;
void APIENTRY glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
	if (!glSecondaryColor3bproc) return;
	glSecondaryColor3bproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bvproc = 0;
void APIENTRY glSecondaryColor3bv(const GLbyte* v) {
	if (!glSecondaryColor3bvproc) return;
	glSecondaryColor3bvproc(v);
}
PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3dproc = 0;
void APIENTRY glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
	if (!glSecondaryColor3dproc) return;
	glSecondaryColor3dproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dvproc = 0;
void APIENTRY glSecondaryColor3dv(const GLdouble* v) {
	if (!glSecondaryColor3dvproc) return;
	glSecondaryColor3dvproc(v);
}
PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3fproc = 0;
void APIENTRY glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
	if (!glSecondaryColor3fproc) return;
	glSecondaryColor3fproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fvproc = 0;
void APIENTRY glSecondaryColor3fv(const GLfloat* v) {
	if (!glSecondaryColor3fvproc) return;
	glSecondaryColor3fvproc(v);
}
PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3iproc = 0;
void APIENTRY glSecondaryColor3i(GLint red, GLint green, GLint blue) {
	if (!glSecondaryColor3iproc) return;
	glSecondaryColor3iproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3ivproc = 0;
void APIENTRY glSecondaryColor3iv(const GLint* v) {
	if (!glSecondaryColor3ivproc) return;
	glSecondaryColor3ivproc(v);
}
PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3sproc = 0;
void APIENTRY glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
	if (!glSecondaryColor3sproc) return;
	glSecondaryColor3sproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3svproc = 0;
void APIENTRY glSecondaryColor3sv(const GLshort* v) {
	if (!glSecondaryColor3svproc) return;
	glSecondaryColor3svproc(v);
}
PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ubproc = 0;
void APIENTRY glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
	if (!glSecondaryColor3ubproc) return;
	glSecondaryColor3ubproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubvproc = 0;
void APIENTRY glSecondaryColor3ubv(const GLubyte* v) {
	if (!glSecondaryColor3ubvproc) return;
	glSecondaryColor3ubvproc(v);
}
PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3uiproc = 0;
void APIENTRY glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
	if (!glSecondaryColor3uiproc) return;
	glSecondaryColor3uiproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uivproc = 0;
void APIENTRY glSecondaryColor3uiv(const GLuint* v) {
	if (!glSecondaryColor3uivproc) return;
	glSecondaryColor3uivproc(v);
}
PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3usproc = 0;
void APIENTRY glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
	if (!glSecondaryColor3usproc) return;
	glSecondaryColor3usproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usvproc = 0;
void APIENTRY glSecondaryColor3usv(const GLushort* v) {
	if (!glSecondaryColor3usvproc) return;
	glSecondaryColor3usvproc(v);
}
PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointerproc = 0;
void APIENTRY glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glSecondaryColorPointerproc) return;
	glSecondaryColorPointerproc(size, type, stride, pointer);
}
PFNGLWINDOWPOS2DPROC glWindowPos2dproc = 0;
void APIENTRY glWindowPos2d(GLdouble x, GLdouble y) {
	if (!glWindowPos2dproc) return;
	glWindowPos2dproc(x, y);
}
PFNGLWINDOWPOS2DVPROC glWindowPos2dvproc = 0;
void APIENTRY glWindowPos2dv(const GLdouble* v) {
	if (!glWindowPos2dvproc) return;
	glWindowPos2dvproc(v);
}
PFNGLWINDOWPOS2FPROC glWindowPos2fproc = 0;
void APIENTRY glWindowPos2f(GLfloat x, GLfloat y) {
	if (!glWindowPos2fproc) return;
	glWindowPos2fproc(x, y);
}
PFNGLWINDOWPOS2FVPROC glWindowPos2fvproc = 0;
void APIENTRY glWindowPos2fv(const GLfloat* v) {
	if (!glWindowPos2fvproc) return;
	glWindowPos2fvproc(v);
}
PFNGLWINDOWPOS2IPROC glWindowPos2iproc = 0;
void APIENTRY glWindowPos2i(GLint x, GLint y) {
	if (!glWindowPos2iproc) return;
	glWindowPos2iproc(x, y);
}
PFNGLWINDOWPOS2IVPROC glWindowPos2ivproc = 0;
void APIENTRY glWindowPos2iv(const GLint* v) {
	if (!glWindowPos2ivproc) return;
	glWindowPos2ivproc(v);
}
PFNGLWINDOWPOS2SPROC glWindowPos2sproc = 0;
void APIENTRY glWindowPos2s(GLshort x, GLshort y) {
	if (!glWindowPos2sproc) return;
	glWindowPos2sproc(x, y);
}
PFNGLWINDOWPOS2SVPROC glWindowPos2svproc = 0;
void APIENTRY glWindowPos2sv(const GLshort* v) {
	if (!glWindowPos2svproc) return;
	glWindowPos2svproc(v);
}
PFNGLWINDOWPOS3DPROC glWindowPos3dproc = 0;
void APIENTRY glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
	if (!glWindowPos3dproc) return;
	glWindowPos3dproc(x, y, z);
}
PFNGLWINDOWPOS3DVPROC glWindowPos3dvproc = 0;
void APIENTRY glWindowPos3dv(const GLdouble* v) {
	if (!glWindowPos3dvproc) return;
	glWindowPos3dvproc(v);
}
PFNGLWINDOWPOS3FPROC glWindowPos3fproc = 0;
void APIENTRY glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
	if (!glWindowPos3fproc) return;
	glWindowPos3fproc(x, y, z);
}
PFNGLWINDOWPOS3FVPROC glWindowPos3fvproc = 0;
void APIENTRY glWindowPos3fv(const GLfloat* v) {
	if (!glWindowPos3fvproc) return;
	glWindowPos3fvproc(v);
}
PFNGLWINDOWPOS3IPROC glWindowPos3iproc = 0;
void APIENTRY glWindowPos3i(GLint x, GLint y, GLint z) {
	if (!glWindowPos3iproc) return;
	glWindowPos3iproc(x, y, z);
}
PFNGLWINDOWPOS3IVPROC glWindowPos3ivproc = 0;
void APIENTRY glWindowPos3iv(const GLint* v) {
	if (!glWindowPos3ivproc) return;
	glWindowPos3ivproc(v);
}
PFNGLWINDOWPOS3SPROC glWindowPos3sproc = 0;
void APIENTRY glWindowPos3s(GLshort x, GLshort y, GLshort z) {
	if (!glWindowPos3sproc) return;
	glWindowPos3sproc(x, y, z);
}
PFNGLWINDOWPOS3SVPROC glWindowPos3svproc = 0;
void APIENTRY glWindowPos3sv(const GLshort* v) {
	if (!glWindowPos3svproc) return;
	glWindowPos3svproc(v);
}
PFNGLBLENDCOLORPROC glBlendColorproc = 0;
void APIENTRY glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	if (!glBlendColorproc) return;
	glBlendColorproc(red, green, blue, alpha);
}
PFNGLBLENDEQUATIONPROC glBlendEquationproc = 0;
void APIENTRY glBlendEquation(GLenum mode) {
	if (!glBlendEquationproc) return;
	glBlendEquationproc(mode);
}
PFNGLGENQUERIESPROC glGenQueriesproc = 0;
void APIENTRY glGenQueries(GLsizei n, GLuint* ids) {
	if (!glGenQueriesproc) return;
	glGenQueriesproc(n, ids);
}
PFNGLDELETEQUERIESPROC glDeleteQueriesproc = 0;
void APIENTRY glDeleteQueries(GLsizei n, const GLuint* ids) {
	if (!glDeleteQueriesproc) return;
	glDeleteQueriesproc(n, ids);
}
PFNGLISQUERYPROC glIsQueryproc = 0;
GLboolean APIENTRY glIsQuery(GLuint id) {
	if (!glIsQueryproc) return 0;
	return glIsQueryproc(id);
}
PFNGLBEGINQUERYPROC glBeginQueryproc = 0;
void APIENTRY glBeginQuery(GLenum target, GLuint id) {
	if (!glBeginQueryproc) return;
	glBeginQueryproc(target, id);
}
PFNGLENDQUERYPROC glEndQueryproc = 0;
void APIENTRY glEndQuery(GLenum target) {
	if (!glEndQueryproc) return;
	glEndQueryproc(target);
}
PFNGLGETQUERYIVPROC glGetQueryivproc = 0;
void APIENTRY glGetQueryiv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetQueryivproc) return;
	glGetQueryivproc(target, pname, params);
}
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectivproc = 0;
void APIENTRY glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) {
	if (!glGetQueryObjectivproc) return;
	glGetQueryObjectivproc(id, pname, params);
}
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuivproc = 0;
void APIENTRY glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) {
	if (!glGetQueryObjectuivproc) return;
	glGetQueryObjectuivproc(id, pname, params);
}
PFNGLBINDBUFFERPROC glBindBufferproc = 0;
void APIENTRY glBindBuffer(GLenum target, GLuint buffer) {
	if (!glBindBufferproc) return;
	glBindBufferproc(target, buffer);
}
PFNGLDELETEBUFFERSPROC glDeleteBuffersproc = 0;
void APIENTRY glDeleteBuffers(GLsizei n, const GLuint* buffers) {
	if (!glDeleteBuffersproc) return;
	glDeleteBuffersproc(n, buffers);
}
PFNGLGENBUFFERSPROC glGenBuffersproc = 0;
void APIENTRY glGenBuffers(GLsizei n, GLuint* buffers) {
	if (!glGenBuffersproc) return;
	glGenBuffersproc(n, buffers);
}
PFNGLISBUFFERPROC glIsBufferproc = 0;
GLboolean APIENTRY glIsBuffer(GLuint buffer) {
	if (!glIsBufferproc) return 0;
	return glIsBufferproc(buffer);
}
PFNGLBUFFERDATAPROC glBufferDataproc = 0;
void APIENTRY glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) {
	if (!glBufferDataproc) return;
	glBufferDataproc(target, size, data, usage);
}
PFNGLBUFFERSUBDATAPROC glBufferSubDataproc = 0;
void APIENTRY glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) {
	if (!glBufferSubDataproc) return;
	glBufferSubDataproc(target, offset, size, data);
}
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubDataproc = 0;
void APIENTRY glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data) {
	if (!glGetBufferSubDataproc) return;
	glGetBufferSubDataproc(target, offset, size, data);
}
PFNGLMAPBUFFERPROC glMapBufferproc = 0;
void* APIENTRY glMapBuffer(GLenum target, GLenum access) {
	if (!glMapBufferproc) return 0;
	return glMapBufferproc(target, access);
}
PFNGLUNMAPBUFFERPROC glUnmapBufferproc = 0;
GLboolean APIENTRY glUnmapBuffer(GLenum target) {
	if (!glUnmapBufferproc) return 0;
	return glUnmapBufferproc(target);
}
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameterivproc = 0;
void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetBufferParameterivproc) return;
	glGetBufferParameterivproc(target, pname, params);
}
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointervproc = 0;
void APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, void** params) {
	if (!glGetBufferPointervproc) return;
	glGetBufferPointervproc(target, pname, params);
}
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparateproc = 0;
void APIENTRY glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
	if (!glBlendEquationSeparateproc) return;
	glBlendEquationSeparateproc(modeRGB, modeAlpha);
}
PFNGLDRAWBUFFERSPROC glDrawBuffersproc = 0;
void APIENTRY glDrawBuffers(GLsizei n, const GLenum* bufs) {
	if (!glDrawBuffersproc) return;
	glDrawBuffersproc(n, bufs);
}
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparateproc = 0;
void APIENTRY glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
	if (!glStencilOpSeparateproc) return;
	glStencilOpSeparateproc(face, sfail, dpfail, dppass);
}
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparateproc = 0;
void APIENTRY glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
	if (!glStencilFuncSeparateproc) return;
	glStencilFuncSeparateproc(face, func, ref, mask);
}
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparateproc = 0;
void APIENTRY glStencilMaskSeparate(GLenum face, GLuint mask) {
	if (!glStencilMaskSeparateproc) return;
	glStencilMaskSeparateproc(face, mask);
}
PFNGLATTACHSHADERPROC glAttachShaderproc = 0;
void APIENTRY glAttachShader(GLuint program, GLuint shader) {
	if (!glAttachShaderproc) return;
	glAttachShaderproc(program, shader);
}
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocationproc = 0;
void APIENTRY glBindAttribLocation(GLuint program, GLuint index, const GLchar* name) {
	if (!glBindAttribLocationproc) return;
	glBindAttribLocationproc(program, index, name);
}
PFNGLCOMPILESHADERPROC glCompileShaderproc = 0;
void APIENTRY glCompileShader(GLuint shader) {
	if (!glCompileShaderproc) return;
	glCompileShaderproc(shader);
}
PFNGLCREATEPROGRAMPROC glCreateProgramproc = 0;
GLuint APIENTRY glCreateProgram(void) {
	if (!glCreateProgramproc) return 0;
	return glCreateProgramproc();
}
PFNGLCREATESHADERPROC glCreateShaderproc = 0;
GLuint APIENTRY glCreateShader(GLenum type) {
	if (!glCreateShaderproc) return 0;
	return glCreateShaderproc(type);
}
PFNGLDELETEPROGRAMPROC glDeleteProgramproc = 0;
void APIENTRY glDeleteProgram(GLuint program) {
	if (!glDeleteProgramproc) return;
	glDeleteProgramproc(program);
}
PFNGLDELETESHADERPROC glDeleteShaderproc = 0;
void APIENTRY glDeleteShader(GLuint shader) {
	if (!glDeleteShaderproc) return;
	glDeleteShaderproc(shader);
}
PFNGLDETACHSHADERPROC glDetachShaderproc = 0;
void APIENTRY glDetachShader(GLuint program, GLuint shader) {
	if (!glDetachShaderproc) return;
	glDetachShaderproc(program, shader);
}
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArrayproc = 0;
void APIENTRY glDisableVertexAttribArray(GLuint index) {
	if (!glDisableVertexAttribArrayproc) return;
	glDisableVertexAttribArrayproc(index);
}
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArrayproc = 0;
void APIENTRY glEnableVertexAttribArray(GLuint index) {
	if (!glEnableVertexAttribArrayproc) return;
	glEnableVertexAttribArrayproc(index);
}
PFNGLGETACTIVEATTRIBPROC glGetActiveAttribproc = 0;
void APIENTRY glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) {
	if (!glGetActiveAttribproc) return;
	glGetActiveAttribproc(program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniformproc = 0;
void APIENTRY glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) {
	if (!glGetActiveUniformproc) return;
	glGetActiveUniformproc(program, index, bufSize, length, size, type, name);
}
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShadersproc = 0;
void APIENTRY glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders) {
	if (!glGetAttachedShadersproc) return;
	glGetAttachedShadersproc(program, maxCount, count, shaders);
}
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocationproc = 0;
GLint APIENTRY glGetAttribLocation(GLuint program, const GLchar* name) {
	if (!glGetAttribLocationproc) return 0;
	return glGetAttribLocationproc(program, name);
}
PFNGLGETPROGRAMIVPROC glGetProgramivproc = 0;
void APIENTRY glGetProgramiv(GLuint program, GLenum pname, GLint* params) {
	if (!glGetProgramivproc) return;
	glGetProgramivproc(program, pname, params);
}
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLogproc = 0;
void APIENTRY glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
	if (!glGetProgramInfoLogproc) return;
	glGetProgramInfoLogproc(program, bufSize, length, infoLog);
}
PFNGLGETSHADERIVPROC glGetShaderivproc = 0;
void APIENTRY glGetShaderiv(GLuint shader, GLenum pname, GLint* params) {
	if (!glGetShaderivproc) return;
	glGetShaderivproc(shader, pname, params);
}
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLogproc = 0;
void APIENTRY glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
	if (!glGetShaderInfoLogproc) return;
	glGetShaderInfoLogproc(shader, bufSize, length, infoLog);
}
PFNGLGETSHADERSOURCEPROC glGetShaderSourceproc = 0;
void APIENTRY glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) {
	if (!glGetShaderSourceproc) return;
	glGetShaderSourceproc(shader, bufSize, length, source);
}
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocationproc = 0;
GLint APIENTRY glGetUniformLocation(GLuint program, const GLchar* name) {
	if (!glGetUniformLocationproc) return 0;
	return glGetUniformLocationproc(program, name);
}
PFNGLGETUNIFORMFVPROC glGetUniformfvproc = 0;
void APIENTRY glGetUniformfv(GLuint program, GLint location, GLfloat* params) {
	if (!glGetUniformfvproc) return;
	glGetUniformfvproc(program, location, params);
}
PFNGLGETUNIFORMIVPROC glGetUniformivproc = 0;
void APIENTRY glGetUniformiv(GLuint program, GLint location, GLint* params) {
	if (!glGetUniformivproc) return;
	glGetUniformivproc(program, location, params);
}
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdvproc = 0;
void APIENTRY glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params) {
	if (!glGetVertexAttribdvproc) return;
	glGetVertexAttribdvproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfvproc = 0;
void APIENTRY glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params) {
	if (!glGetVertexAttribfvproc) return;
	glGetVertexAttribfvproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribivproc = 0;
void APIENTRY glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params) {
	if (!glGetVertexAttribivproc) return;
	glGetVertexAttribivproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointervproc = 0;
void APIENTRY glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer) {
	if (!glGetVertexAttribPointervproc) return;
	glGetVertexAttribPointervproc(index, pname, pointer);
}
PFNGLISPROGRAMPROC glIsProgramproc = 0;
GLboolean APIENTRY glIsProgram(GLuint program) {
	if (!glIsProgramproc) return 0;
	return glIsProgramproc(program);
}
PFNGLISSHADERPROC glIsShaderproc = 0;
GLboolean APIENTRY glIsShader(GLuint shader) {
	if (!glIsShaderproc) return 0;
	return glIsShaderproc(shader);
}
PFNGLLINKPROGRAMPROC glLinkProgramproc = 0;
void APIENTRY glLinkProgram(GLuint program) {
	if (!glLinkProgramproc) return;
	glLinkProgramproc(program);
}
PFNGLSHADERSOURCEPROC glShaderSourceproc = 0;
void APIENTRY glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length) {
	if (!glShaderSourceproc) return;
	glShaderSourceproc(shader, count, string, length);
}
PFNGLUSEPROGRAMPROC glUseProgramproc = 0;
void APIENTRY glUseProgram(GLuint program) {
	if (!glUseProgramproc) return;
	glUseProgramproc(program);
}
PFNGLUNIFORM1FPROC glUniform1fproc = 0;
void APIENTRY glUniform1f(GLint location, GLfloat v0) {
	if (!glUniform1fproc) return;
	glUniform1fproc(location, v0);
}
PFNGLUNIFORM2FPROC glUniform2fproc = 0;
void APIENTRY glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
	if (!glUniform2fproc) return;
	glUniform2fproc(location, v0, v1);
}
PFNGLUNIFORM3FPROC glUniform3fproc = 0;
void APIENTRY glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	if (!glUniform3fproc) return;
	glUniform3fproc(location, v0, v1, v2);
}
PFNGLUNIFORM4FPROC glUniform4fproc = 0;
void APIENTRY glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	if (!glUniform4fproc) return;
	glUniform4fproc(location, v0, v1, v2, v3);
}
PFNGLUNIFORM1IPROC glUniform1iproc = 0;
void APIENTRY glUniform1i(GLint location, GLint v0) {
	if (!glUniform1iproc) return;
	glUniform1iproc(location, v0);
}
PFNGLUNIFORM2IPROC glUniform2iproc = 0;
void APIENTRY glUniform2i(GLint location, GLint v0, GLint v1) {
	if (!glUniform2iproc) return;
	glUniform2iproc(location, v0, v1);
}
PFNGLUNIFORM3IPROC glUniform3iproc = 0;
void APIENTRY glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
	if (!glUniform3iproc) return;
	glUniform3iproc(location, v0, v1, v2);
}
PFNGLUNIFORM4IPROC glUniform4iproc = 0;
void APIENTRY glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	if (!glUniform4iproc) return;
	glUniform4iproc(location, v0, v1, v2, v3);
}
PFNGLUNIFORM1FVPROC glUniform1fvproc = 0;
void APIENTRY glUniform1fv(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform1fvproc) return;
	glUniform1fvproc(location, count, value);
}
PFNGLUNIFORM2FVPROC glUniform2fvproc = 0;
void APIENTRY glUniform2fv(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform2fvproc) return;
	glUniform2fvproc(location, count, value);
}
PFNGLUNIFORM3FVPROC glUniform3fvproc = 0;
void APIENTRY glUniform3fv(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform3fvproc) return;
	glUniform3fvproc(location, count, value);
}
PFNGLUNIFORM4FVPROC glUniform4fvproc = 0;
void APIENTRY glUniform4fv(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform4fvproc) return;
	glUniform4fvproc(location, count, value);
}
PFNGLUNIFORM1IVPROC glUniform1ivproc = 0;
void APIENTRY glUniform1iv(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform1ivproc) return;
	glUniform1ivproc(location, count, value);
}
PFNGLUNIFORM2IVPROC glUniform2ivproc = 0;
void APIENTRY glUniform2iv(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform2ivproc) return;
	glUniform2ivproc(location, count, value);
}
PFNGLUNIFORM3IVPROC glUniform3ivproc = 0;
void APIENTRY glUniform3iv(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform3ivproc) return;
	glUniform3ivproc(location, count, value);
}
PFNGLUNIFORM4IVPROC glUniform4ivproc = 0;
void APIENTRY glUniform4iv(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform4ivproc) return;
	glUniform4ivproc(location, count, value);
}
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fvproc = 0;
void APIENTRY glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix2fvproc) return;
	glUniformMatrix2fvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fvproc = 0;
void APIENTRY glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix3fvproc) return;
	glUniformMatrix3fvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fvproc = 0;
void APIENTRY glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix4fvproc) return;
	glUniformMatrix4fvproc(location, count, transpose, value);
}
PFNGLVALIDATEPROGRAMPROC glValidateProgramproc = 0;
void APIENTRY glValidateProgram(GLuint program) {
	if (!glValidateProgramproc) return;
	glValidateProgramproc(program);
}
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1dproc = 0;
void APIENTRY glVertexAttrib1d(GLuint index, GLdouble x) {
	if (!glVertexAttrib1dproc) return;
	glVertexAttrib1dproc(index, x);
}
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dvproc = 0;
void APIENTRY glVertexAttrib1dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib1dvproc) return;
	glVertexAttrib1dvproc(index, v);
}
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1fproc = 0;
void APIENTRY glVertexAttrib1f(GLuint index, GLfloat x) {
	if (!glVertexAttrib1fproc) return;
	glVertexAttrib1fproc(index, x);
}
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fvproc = 0;
void APIENTRY glVertexAttrib1fv(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib1fvproc) return;
	glVertexAttrib1fvproc(index, v);
}
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1sproc = 0;
void APIENTRY glVertexAttrib1s(GLuint index, GLshort x) {
	if (!glVertexAttrib1sproc) return;
	glVertexAttrib1sproc(index, x);
}
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1svproc = 0;
void APIENTRY glVertexAttrib1sv(GLuint index, const GLshort* v) {
	if (!glVertexAttrib1svproc) return;
	glVertexAttrib1svproc(index, v);
}
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2dproc = 0;
void APIENTRY glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
	if (!glVertexAttrib2dproc) return;
	glVertexAttrib2dproc(index, x, y);
}
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dvproc = 0;
void APIENTRY glVertexAttrib2dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib2dvproc) return;
	glVertexAttrib2dvproc(index, v);
}
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2fproc = 0;
void APIENTRY glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
	if (!glVertexAttrib2fproc) return;
	glVertexAttrib2fproc(index, x, y);
}
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fvproc = 0;
void APIENTRY glVertexAttrib2fv(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib2fvproc) return;
	glVertexAttrib2fvproc(index, v);
}
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2sproc = 0;
void APIENTRY glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
	if (!glVertexAttrib2sproc) return;
	glVertexAttrib2sproc(index, x, y);
}
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2svproc = 0;
void APIENTRY glVertexAttrib2sv(GLuint index, const GLshort* v) {
	if (!glVertexAttrib2svproc) return;
	glVertexAttrib2svproc(index, v);
}
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3dproc = 0;
void APIENTRY glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	if (!glVertexAttrib3dproc) return;
	glVertexAttrib3dproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dvproc = 0;
void APIENTRY glVertexAttrib3dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib3dvproc) return;
	glVertexAttrib3dvproc(index, v);
}
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3fproc = 0;
void APIENTRY glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
	if (!glVertexAttrib3fproc) return;
	glVertexAttrib3fproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fvproc = 0;
void APIENTRY glVertexAttrib3fv(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib3fvproc) return;
	glVertexAttrib3fvproc(index, v);
}
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3sproc = 0;
void APIENTRY glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
	if (!glVertexAttrib3sproc) return;
	glVertexAttrib3sproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3svproc = 0;
void APIENTRY glVertexAttrib3sv(GLuint index, const GLshort* v) {
	if (!glVertexAttrib3svproc) return;
	glVertexAttrib3svproc(index, v);
}
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbvproc = 0;
void APIENTRY glVertexAttrib4Nbv(GLuint index, const GLbyte* v) {
	if (!glVertexAttrib4Nbvproc) return;
	glVertexAttrib4Nbvproc(index, v);
}
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Nivproc = 0;
void APIENTRY glVertexAttrib4Niv(GLuint index, const GLint* v) {
	if (!glVertexAttrib4Nivproc) return;
	glVertexAttrib4Nivproc(index, v);
}
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsvproc = 0;
void APIENTRY glVertexAttrib4Nsv(GLuint index, const GLshort* v) {
	if (!glVertexAttrib4Nsvproc) return;
	glVertexAttrib4Nsvproc(index, v);
}
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nubproc = 0;
void APIENTRY glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
	if (!glVertexAttrib4Nubproc) return;
	glVertexAttrib4Nubproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubvproc = 0;
void APIENTRY glVertexAttrib4Nubv(GLuint index, const GLubyte* v) {
	if (!glVertexAttrib4Nubvproc) return;
	glVertexAttrib4Nubvproc(index, v);
}
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuivproc = 0;
void APIENTRY glVertexAttrib4Nuiv(GLuint index, const GLuint* v) {
	if (!glVertexAttrib4Nuivproc) return;
	glVertexAttrib4Nuivproc(index, v);
}
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusvproc = 0;
void APIENTRY glVertexAttrib4Nusv(GLuint index, const GLushort* v) {
	if (!glVertexAttrib4Nusvproc) return;
	glVertexAttrib4Nusvproc(index, v);
}
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bvproc = 0;
void APIENTRY glVertexAttrib4bv(GLuint index, const GLbyte* v) {
	if (!glVertexAttrib4bvproc) return;
	glVertexAttrib4bvproc(index, v);
}
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4dproc = 0;
void APIENTRY glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glVertexAttrib4dproc) return;
	glVertexAttrib4dproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dvproc = 0;
void APIENTRY glVertexAttrib4dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib4dvproc) return;
	glVertexAttrib4dvproc(index, v);
}
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4fproc = 0;
void APIENTRY glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glVertexAttrib4fproc) return;
	glVertexAttrib4fproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fvproc = 0;
void APIENTRY glVertexAttrib4fv(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib4fvproc) return;
	glVertexAttrib4fvproc(index, v);
}
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4ivproc = 0;
void APIENTRY glVertexAttrib4iv(GLuint index, const GLint* v) {
	if (!glVertexAttrib4ivproc) return;
	glVertexAttrib4ivproc(index, v);
}
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4sproc = 0;
void APIENTRY glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
	if (!glVertexAttrib4sproc) return;
	glVertexAttrib4sproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4svproc = 0;
void APIENTRY glVertexAttrib4sv(GLuint index, const GLshort* v) {
	if (!glVertexAttrib4svproc) return;
	glVertexAttrib4svproc(index, v);
}
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubvproc = 0;
void APIENTRY glVertexAttrib4ubv(GLuint index, const GLubyte* v) {
	if (!glVertexAttrib4ubvproc) return;
	glVertexAttrib4ubvproc(index, v);
}
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uivproc = 0;
void APIENTRY glVertexAttrib4uiv(GLuint index, const GLuint* v) {
	if (!glVertexAttrib4uivproc) return;
	glVertexAttrib4uivproc(index, v);
}
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usvproc = 0;
void APIENTRY glVertexAttrib4usv(GLuint index, const GLushort* v) {
	if (!glVertexAttrib4usvproc) return;
	glVertexAttrib4usvproc(index, v);
}
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointerproc = 0;
void APIENTRY glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) {
	if (!glVertexAttribPointerproc) return;
	glVertexAttribPointerproc(index, size, type, normalized, stride, pointer);
}
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fvproc = 0;
void APIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix2x3fvproc) return;
	glUniformMatrix2x3fvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fvproc = 0;
void APIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix3x2fvproc) return;
	glUniformMatrix3x2fvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fvproc = 0;
void APIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix2x4fvproc) return;
	glUniformMatrix2x4fvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fvproc = 0;
void APIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix4x2fvproc) return;
	glUniformMatrix4x2fvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fvproc = 0;
void APIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix3x4fvproc) return;
	glUniformMatrix3x4fvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fvproc = 0;
void APIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix4x3fvproc) return;
	glUniformMatrix4x3fvproc(location, count, transpose, value);
}
PFNGLCOLORMASKIPROC glColorMaskiproc = 0;
void APIENTRY glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	if (!glColorMaskiproc) return;
	glColorMaskiproc(index, r, g, b, a);
}
PFNGLGETBOOLEANI_VPROC glGetBooleani_vproc = 0;
void APIENTRY glGetBooleani_v(GLenum target, GLuint index, GLboolean* data) {
	if (!glGetBooleani_vproc) return;
	glGetBooleani_vproc(target, index, data);
}
PFNGLGETINTEGERI_VPROC glGetIntegeri_vproc = 0;
void APIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint* data) {
	if (!glGetIntegeri_vproc) return;
	glGetIntegeri_vproc(target, index, data);
}
PFNGLENABLEIPROC glEnableiproc = 0;
void APIENTRY glEnablei(GLenum target, GLuint index) {
	if (!glEnableiproc) return;
	glEnableiproc(target, index);
}
PFNGLDISABLEIPROC glDisableiproc = 0;
void APIENTRY glDisablei(GLenum target, GLuint index) {
	if (!glDisableiproc) return;
	glDisableiproc(target, index);
}
PFNGLISENABLEDIPROC glIsEnablediproc = 0;
GLboolean APIENTRY glIsEnabledi(GLenum target, GLuint index) {
	if (!glIsEnablediproc) return 0;
	return glIsEnablediproc(target, index);
}
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedbackproc = 0;
void APIENTRY glBeginTransformFeedback(GLenum primitiveMode) {
	if (!glBeginTransformFeedbackproc) return;
	glBeginTransformFeedbackproc(primitiveMode);
}
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedbackproc = 0;
void APIENTRY glEndTransformFeedback(void) {
	if (!glEndTransformFeedbackproc) return;
	glEndTransformFeedbackproc();
}
PFNGLBINDBUFFERRANGEPROC glBindBufferRangeproc = 0;
void APIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	if (!glBindBufferRangeproc) return;
	glBindBufferRangeproc(target, index, buffer, offset, size);
}
PFNGLBINDBUFFERBASEPROC glBindBufferBaseproc = 0;
void APIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
	if (!glBindBufferBaseproc) return;
	glBindBufferBaseproc(target, index, buffer);
}
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryingsproc = 0;
void APIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) {
	if (!glTransformFeedbackVaryingsproc) return;
	glTransformFeedbackVaryingsproc(program, count, varyings, bufferMode);
}
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVaryingproc = 0;
void APIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) {
	if (!glGetTransformFeedbackVaryingproc) return;
	glGetTransformFeedbackVaryingproc(program, index, bufSize, length, size, type, name);
}
PFNGLCLAMPCOLORPROC glClampColorproc = 0;
void APIENTRY glClampColor(GLenum target, GLenum clamp) {
	if (!glClampColorproc) return;
	glClampColorproc(target, clamp);
}
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRenderproc = 0;
void APIENTRY glBeginConditionalRender(GLuint id, GLenum mode) {
	if (!glBeginConditionalRenderproc) return;
	glBeginConditionalRenderproc(id, mode);
}
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRenderproc = 0;
void APIENTRY glEndConditionalRender(void) {
	if (!glEndConditionalRenderproc) return;
	glEndConditionalRenderproc();
}
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointerproc = 0;
void APIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glVertexAttribIPointerproc) return;
	glVertexAttribIPointerproc(index, size, type, stride, pointer);
}
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIivproc = 0;
void APIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params) {
	if (!glGetVertexAttribIivproc) return;
	glGetVertexAttribIivproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuivproc = 0;
void APIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params) {
	if (!glGetVertexAttribIuivproc) return;
	glGetVertexAttribIuivproc(index, pname, params);
}
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1iproc = 0;
void APIENTRY glVertexAttribI1i(GLuint index, GLint x) {
	if (!glVertexAttribI1iproc) return;
	glVertexAttribI1iproc(index, x);
}
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2iproc = 0;
void APIENTRY glVertexAttribI2i(GLuint index, GLint x, GLint y) {
	if (!glVertexAttribI2iproc) return;
	glVertexAttribI2iproc(index, x, y);
}
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3iproc = 0;
void APIENTRY glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
	if (!glVertexAttribI3iproc) return;
	glVertexAttribI3iproc(index, x, y, z);
}
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4iproc = 0;
void APIENTRY glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
	if (!glVertexAttribI4iproc) return;
	glVertexAttribI4iproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1uiproc = 0;
void APIENTRY glVertexAttribI1ui(GLuint index, GLuint x) {
	if (!glVertexAttribI1uiproc) return;
	glVertexAttribI1uiproc(index, x);
}
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2uiproc = 0;
void APIENTRY glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
	if (!glVertexAttribI2uiproc) return;
	glVertexAttribI2uiproc(index, x, y);
}
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3uiproc = 0;
void APIENTRY glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
	if (!glVertexAttribI3uiproc) return;
	glVertexAttribI3uiproc(index, x, y, z);
}
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4uiproc = 0;
void APIENTRY glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
	if (!glVertexAttribI4uiproc) return;
	glVertexAttribI4uiproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1ivproc = 0;
void APIENTRY glVertexAttribI1iv(GLuint index, const GLint* v) {
	if (!glVertexAttribI1ivproc) return;
	glVertexAttribI1ivproc(index, v);
}
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2ivproc = 0;
void APIENTRY glVertexAttribI2iv(GLuint index, const GLint* v) {
	if (!glVertexAttribI2ivproc) return;
	glVertexAttribI2ivproc(index, v);
}
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3ivproc = 0;
void APIENTRY glVertexAttribI3iv(GLuint index, const GLint* v) {
	if (!glVertexAttribI3ivproc) return;
	glVertexAttribI3ivproc(index, v);
}
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4ivproc = 0;
void APIENTRY glVertexAttribI4iv(GLuint index, const GLint* v) {
	if (!glVertexAttribI4ivproc) return;
	glVertexAttribI4ivproc(index, v);
}
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uivproc = 0;
void APIENTRY glVertexAttribI1uiv(GLuint index, const GLuint* v) {
	if (!glVertexAttribI1uivproc) return;
	glVertexAttribI1uivproc(index, v);
}
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uivproc = 0;
void APIENTRY glVertexAttribI2uiv(GLuint index, const GLuint* v) {
	if (!glVertexAttribI2uivproc) return;
	glVertexAttribI2uivproc(index, v);
}
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uivproc = 0;
void APIENTRY glVertexAttribI3uiv(GLuint index, const GLuint* v) {
	if (!glVertexAttribI3uivproc) return;
	glVertexAttribI3uivproc(index, v);
}
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uivproc = 0;
void APIENTRY glVertexAttribI4uiv(GLuint index, const GLuint* v) {
	if (!glVertexAttribI4uivproc) return;
	glVertexAttribI4uivproc(index, v);
}
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bvproc = 0;
void APIENTRY glVertexAttribI4bv(GLuint index, const GLbyte* v) {
	if (!glVertexAttribI4bvproc) return;
	glVertexAttribI4bvproc(index, v);
}
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4svproc = 0;
void APIENTRY glVertexAttribI4sv(GLuint index, const GLshort* v) {
	if (!glVertexAttribI4svproc) return;
	glVertexAttribI4svproc(index, v);
}
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubvproc = 0;
void APIENTRY glVertexAttribI4ubv(GLuint index, const GLubyte* v) {
	if (!glVertexAttribI4ubvproc) return;
	glVertexAttribI4ubvproc(index, v);
}
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usvproc = 0;
void APIENTRY glVertexAttribI4usv(GLuint index, const GLushort* v) {
	if (!glVertexAttribI4usvproc) return;
	glVertexAttribI4usvproc(index, v);
}
PFNGLGETUNIFORMUIVPROC glGetUniformuivproc = 0;
void APIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint* params) {
	if (!glGetUniformuivproc) return;
	glGetUniformuivproc(program, location, params);
}
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocationproc = 0;
void APIENTRY glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) {
	if (!glBindFragDataLocationproc) return;
	glBindFragDataLocationproc(program, color, name);
}
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocationproc = 0;
GLint APIENTRY glGetFragDataLocation(GLuint program, const GLchar* name) {
	if (!glGetFragDataLocationproc) return 0;
	return glGetFragDataLocationproc(program, name);
}
PFNGLUNIFORM1UIPROC glUniform1uiproc = 0;
void APIENTRY glUniform1ui(GLint location, GLuint v0) {
	if (!glUniform1uiproc) return;
	glUniform1uiproc(location, v0);
}
PFNGLUNIFORM2UIPROC glUniform2uiproc = 0;
void APIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1) {
	if (!glUniform2uiproc) return;
	glUniform2uiproc(location, v0, v1);
}
PFNGLUNIFORM3UIPROC glUniform3uiproc = 0;
void APIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
	if (!glUniform3uiproc) return;
	glUniform3uiproc(location, v0, v1, v2);
}
PFNGLUNIFORM4UIPROC glUniform4uiproc = 0;
void APIENTRY glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	if (!glUniform4uiproc) return;
	glUniform4uiproc(location, v0, v1, v2, v3);
}
PFNGLUNIFORM1UIVPROC glUniform1uivproc = 0;
void APIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform1uivproc) return;
	glUniform1uivproc(location, count, value);
}
PFNGLUNIFORM2UIVPROC glUniform2uivproc = 0;
void APIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform2uivproc) return;
	glUniform2uivproc(location, count, value);
}
PFNGLUNIFORM3UIVPROC glUniform3uivproc = 0;
void APIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform3uivproc) return;
	glUniform3uivproc(location, count, value);
}
PFNGLUNIFORM4UIVPROC glUniform4uivproc = 0;
void APIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform4uivproc) return;
	glUniform4uivproc(location, count, value);
}
PFNGLTEXPARAMETERIIVPROC glTexParameterIivproc = 0;
void APIENTRY glTexParameterIiv(GLenum target, GLenum pname, const GLint* params) {
	if (!glTexParameterIivproc) return;
	glTexParameterIivproc(target, pname, params);
}
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuivproc = 0;
void APIENTRY glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params) {
	if (!glTexParameterIuivproc) return;
	glTexParameterIuivproc(target, pname, params);
}
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIivproc = 0;
void APIENTRY glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetTexParameterIivproc) return;
	glGetTexParameterIivproc(target, pname, params);
}
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuivproc = 0;
void APIENTRY glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params) {
	if (!glGetTexParameterIuivproc) return;
	glGetTexParameterIuivproc(target, pname, params);
}
PFNGLCLEARBUFFERIVPROC glClearBufferivproc = 0;
void APIENTRY glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value) {
	if (!glClearBufferivproc) return;
	glClearBufferivproc(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERUIVPROC glClearBufferuivproc = 0;
void APIENTRY glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value) {
	if (!glClearBufferuivproc) return;
	glClearBufferuivproc(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERFVPROC glClearBufferfvproc = 0;
void APIENTRY glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) {
	if (!glClearBufferfvproc) return;
	glClearBufferfvproc(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERFIPROC glClearBufferfiproc = 0;
void APIENTRY glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
	if (!glClearBufferfiproc) return;
	glClearBufferfiproc(buffer, drawbuffer, depth, stencil);
}
PFNGLGETSTRINGIPROC glGetStringiproc = 0;
const GLubyte* APIENTRY glGetStringi(GLenum name, GLuint index) {
	if (!glGetStringiproc) return 0;
	return glGetStringiproc(name, index);
}
PFNGLISRENDERBUFFERPROC glIsRenderbufferproc = 0;
GLboolean APIENTRY glIsRenderbuffer(GLuint renderbuffer) {
	if (!glIsRenderbufferproc) return 0;
	return glIsRenderbufferproc(renderbuffer);
}
PFNGLBINDRENDERBUFFERPROC glBindRenderbufferproc = 0;
void APIENTRY glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
	if (!glBindRenderbufferproc) return;
	glBindRenderbufferproc(target, renderbuffer);
}
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffersproc = 0;
void APIENTRY glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) {
	if (!glDeleteRenderbuffersproc) return;
	glDeleteRenderbuffersproc(n, renderbuffers);
}
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffersproc = 0;
void APIENTRY glGenRenderbuffers(GLsizei n, GLuint* renderbuffers) {
	if (!glGenRenderbuffersproc) return;
	glGenRenderbuffersproc(n, renderbuffers);
}
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorageproc = 0;
void APIENTRY glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glRenderbufferStorageproc) return;
	glRenderbufferStorageproc(target, internalformat, width, height);
}
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameterivproc = 0;
void APIENTRY glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetRenderbufferParameterivproc) return;
	glGetRenderbufferParameterivproc(target, pname, params);
}
PFNGLISFRAMEBUFFERPROC glIsFramebufferproc = 0;
GLboolean APIENTRY glIsFramebuffer(GLuint framebuffer) {
	if (!glIsFramebufferproc) return 0;
	return glIsFramebufferproc(framebuffer);
}
PFNGLBINDFRAMEBUFFERPROC glBindFramebufferproc = 0;
void APIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer) {
	if (!glBindFramebufferproc) return;
	glBindFramebufferproc(target, framebuffer);
}
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffersproc = 0;
void APIENTRY glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) {
	if (!glDeleteFramebuffersproc) return;
	glDeleteFramebuffersproc(n, framebuffers);
}
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffersproc = 0;
void APIENTRY glGenFramebuffers(GLsizei n, GLuint* framebuffers) {
	if (!glGenFramebuffersproc) return;
	glGenFramebuffersproc(n, framebuffers);
}
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatusproc = 0;
GLenum APIENTRY glCheckFramebufferStatus(GLenum target) {
	if (!glCheckFramebufferStatusproc) return 0;
	return glCheckFramebufferStatusproc(target);
}
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1Dproc = 0;
void APIENTRY glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	if (!glFramebufferTexture1Dproc) return;
	glFramebufferTexture1Dproc(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2Dproc = 0;
void APIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	if (!glFramebufferTexture2Dproc) return;
	glFramebufferTexture2Dproc(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3Dproc = 0;
void APIENTRY glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	if (!glFramebufferTexture3Dproc) return;
	glFramebufferTexture3Dproc(target, attachment, textarget, texture, level, zoffset);
}
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbufferproc = 0;
void APIENTRY glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	if (!glFramebufferRenderbufferproc) return;
	glFramebufferRenderbufferproc(target, attachment, renderbuffertarget, renderbuffer);
}
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameterivproc = 0;
void APIENTRY glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params) {
	if (!glGetFramebufferAttachmentParameterivproc) return;
	glGetFramebufferAttachmentParameterivproc(target, attachment, pname, params);
}
PFNGLGENERATEMIPMAPPROC glGenerateMipmapproc = 0;
void APIENTRY glGenerateMipmap(GLenum target) {
	if (!glGenerateMipmapproc) return;
	glGenerateMipmapproc(target);
}
PFNGLBLITFRAMEBUFFERPROC glBlitFramebufferproc = 0;
void APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	if (!glBlitFramebufferproc) return;
	glBlitFramebufferproc(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisampleproc = 0;
void APIENTRY glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glRenderbufferStorageMultisampleproc) return;
	glRenderbufferStorageMultisampleproc(target, samples, internalformat, width, height);
}
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayerproc = 0;
void APIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	if (!glFramebufferTextureLayerproc) return;
	glFramebufferTextureLayerproc(target, attachment, texture, level, layer);
}
PFNGLMAPBUFFERRANGEPROC glMapBufferRangeproc = 0;
void* APIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	if (!glMapBufferRangeproc) return 0;
	return glMapBufferRangeproc(target, offset, length, access);
}
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRangeproc = 0;
void APIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
	if (!glFlushMappedBufferRangeproc) return;
	glFlushMappedBufferRangeproc(target, offset, length);
}
PFNGLBINDVERTEXARRAYPROC glBindVertexArrayproc = 0;
void APIENTRY glBindVertexArray(GLuint array) {
	if (!glBindVertexArrayproc) return;
	glBindVertexArrayproc(array);
}
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArraysproc = 0;
void APIENTRY glDeleteVertexArrays(GLsizei n, const GLuint* arrays) {
	if (!glDeleteVertexArraysproc) return;
	glDeleteVertexArraysproc(n, arrays);
}
PFNGLGENVERTEXARRAYSPROC glGenVertexArraysproc = 0;
void APIENTRY glGenVertexArrays(GLsizei n, GLuint* arrays) {
	if (!glGenVertexArraysproc) return;
	glGenVertexArraysproc(n, arrays);
}
PFNGLISVERTEXARRAYPROC glIsVertexArrayproc = 0;
GLboolean APIENTRY glIsVertexArray(GLuint array) {
	if (!glIsVertexArrayproc) return 0;
	return glIsVertexArrayproc(array);
}
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstancedproc = 0;
void APIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
	if (!glDrawArraysInstancedproc) return;
	glDrawArraysInstancedproc(mode, first, count, instancecount);
}
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstancedproc = 0;
void APIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) {
	if (!glDrawElementsInstancedproc) return;
	glDrawElementsInstancedproc(mode, count, type, indices, instancecount);
}
PFNGLTEXBUFFERPROC glTexBufferproc = 0;
void APIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
	if (!glTexBufferproc) return;
	glTexBufferproc(target, internalformat, buffer);
}
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndexproc = 0;
void APIENTRY glPrimitiveRestartIndex(GLuint index) {
	if (!glPrimitiveRestartIndexproc) return;
	glPrimitiveRestartIndexproc(index);
}
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubDataproc = 0;
void APIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
	if (!glCopyBufferSubDataproc) return;
	glCopyBufferSubDataproc(readTarget, writeTarget, readOffset, writeOffset, size);
}
PFNGLGETUNIFORMINDICESPROC glGetUniformIndicesproc = 0;
void APIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices) {
	if (!glGetUniformIndicesproc) return;
	glGetUniformIndicesproc(program, uniformCount, uniformNames, uniformIndices);
}
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsivproc = 0;
void APIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params) {
	if (!glGetActiveUniformsivproc) return;
	glGetActiveUniformsivproc(program, uniformCount, uniformIndices, pname, params);
}
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformNameproc = 0;
void APIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) {
	if (!glGetActiveUniformNameproc) return;
	glGetActiveUniformNameproc(program, uniformIndex, bufSize, length, uniformName);
}
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndexproc = 0;
GLuint APIENTRY glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) {
	if (!glGetUniformBlockIndexproc) return 0;
	return glGetUniformBlockIndexproc(program, uniformBlockName);
}
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockivproc = 0;
void APIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params) {
	if (!glGetActiveUniformBlockivproc) return;
	glGetActiveUniformBlockivproc(program, uniformBlockIndex, pname, params);
}
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockNameproc = 0;
void APIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) {
	if (!glGetActiveUniformBlockNameproc) return;
	glGetActiveUniformBlockNameproc(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBindingproc = 0;
void APIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
	if (!glUniformBlockBindingproc) return;
	glUniformBlockBindingproc(program, uniformBlockIndex, uniformBlockBinding);
}
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertexproc = 0;
void APIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) {
	if (!glDrawElementsBaseVertexproc) return;
	glDrawElementsBaseVertexproc(mode, count, type, indices, basevertex);
}
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertexproc = 0;
void APIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) {
	if (!glDrawRangeElementsBaseVertexproc) return;
	glDrawRangeElementsBaseVertexproc(mode, start, end, count, type, indices, basevertex);
}
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertexproc = 0;
void APIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex) {
	if (!glDrawElementsInstancedBaseVertexproc) return;
	glDrawElementsInstancedBaseVertexproc(mode, count, type, indices, instancecount, basevertex);
}
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertexproc = 0;
void APIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex) {
	if (!glMultiDrawElementsBaseVertexproc) return;
	glMultiDrawElementsBaseVertexproc(mode, count, type, indices, drawcount, basevertex);
}
PFNGLPROVOKINGVERTEXPROC glProvokingVertexproc = 0;
void APIENTRY glProvokingVertex(GLenum mode) {
	if (!glProvokingVertexproc) return;
	glProvokingVertexproc(mode);
}
PFNGLFENCESYNCPROC glFenceSyncproc = 0;
GLsync APIENTRY glFenceSync(GLenum condition, GLbitfield flags) {
	if (!glFenceSyncproc) return 0;
	return glFenceSyncproc(condition, flags);
}
PFNGLISSYNCPROC glIsSyncproc = 0;
GLboolean APIENTRY glIsSync(GLsync sync) {
	if (!glIsSyncproc) return 0;
	return glIsSyncproc(sync);
}
PFNGLDELETESYNCPROC glDeleteSyncproc = 0;
void APIENTRY glDeleteSync(GLsync sync) {
	if (!glDeleteSyncproc) return;
	glDeleteSyncproc(sync);
}
PFNGLCLIENTWAITSYNCPROC glClientWaitSyncproc = 0;
GLenum APIENTRY glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
	if (!glClientWaitSyncproc) return 0;
	return glClientWaitSyncproc(sync, flags, timeout);
}
PFNGLWAITSYNCPROC glWaitSyncproc = 0;
void APIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
	if (!glWaitSyncproc) return;
	glWaitSyncproc(sync, flags, timeout);
}
PFNGLGETINTEGER64VPROC glGetInteger64vproc = 0;
void APIENTRY glGetInteger64v(GLenum pname, GLint64* data) {
	if (!glGetInteger64vproc) return;
	glGetInteger64vproc(pname, data);
}
PFNGLGETSYNCIVPROC glGetSyncivproc = 0;
void APIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values) {
	if (!glGetSyncivproc) return;
	glGetSyncivproc(sync, pname, count, length, values);
}
PFNGLGETINTEGER64I_VPROC glGetInteger64i_vproc = 0;
void APIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64* data) {
	if (!glGetInteger64i_vproc) return;
	glGetInteger64i_vproc(target, index, data);
}
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64vproc = 0;
void APIENTRY glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params) {
	if (!glGetBufferParameteri64vproc) return;
	glGetBufferParameteri64vproc(target, pname, params);
}
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTextureproc = 0;
void APIENTRY glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	if (!glFramebufferTextureproc) return;
	glFramebufferTextureproc(target, attachment, texture, level);
}
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisampleproc = 0;
void APIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	if (!glTexImage2DMultisampleproc) return;
	glTexImage2DMultisampleproc(target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisampleproc = 0;
void APIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	if (!glTexImage3DMultisampleproc) return;
	glTexImage3DMultisampleproc(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefvproc = 0;
void APIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val) {
	if (!glGetMultisamplefvproc) return;
	glGetMultisamplefvproc(pname, index, val);
}
PFNGLSAMPLEMASKIPROC glSampleMaskiproc = 0;
void APIENTRY glSampleMaski(GLuint maskNumber, GLbitfield mask) {
	if (!glSampleMaskiproc) return;
	glSampleMaskiproc(maskNumber, mask);
}
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexedproc = 0;
void APIENTRY glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) {
	if (!glBindFragDataLocationIndexedproc) return;
	glBindFragDataLocationIndexedproc(program, colorNumber, index, name);
}
PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndexproc = 0;
GLint APIENTRY glGetFragDataIndex(GLuint program, const GLchar* name) {
	if (!glGetFragDataIndexproc) return 0;
	return glGetFragDataIndexproc(program, name);
}
PFNGLGENSAMPLERSPROC glGenSamplersproc = 0;
void APIENTRY glGenSamplers(GLsizei count, GLuint* samplers) {
	if (!glGenSamplersproc) return;
	glGenSamplersproc(count, samplers);
}
PFNGLDELETESAMPLERSPROC glDeleteSamplersproc = 0;
void APIENTRY glDeleteSamplers(GLsizei count, const GLuint* samplers) {
	if (!glDeleteSamplersproc) return;
	glDeleteSamplersproc(count, samplers);
}
PFNGLISSAMPLERPROC glIsSamplerproc = 0;
GLboolean APIENTRY glIsSampler(GLuint sampler) {
	if (!glIsSamplerproc) return 0;
	return glIsSamplerproc(sampler);
}
PFNGLBINDSAMPLERPROC glBindSamplerproc = 0;
void APIENTRY glBindSampler(GLuint unit, GLuint sampler) {
	if (!glBindSamplerproc) return;
	glBindSamplerproc(unit, sampler);
}
PFNGLSAMPLERPARAMETERIPROC glSamplerParameteriproc = 0;
void APIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
	if (!glSamplerParameteriproc) return;
	glSamplerParameteriproc(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIVPROC glSamplerParameterivproc = 0;
void APIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param) {
	if (!glSamplerParameterivproc) return;
	glSamplerParameterivproc(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFPROC glSamplerParameterfproc = 0;
void APIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
	if (!glSamplerParameterfproc) return;
	glSamplerParameterfproc(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfvproc = 0;
void APIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param) {
	if (!glSamplerParameterfvproc) return;
	glSamplerParameterfvproc(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIivproc = 0;
void APIENTRY glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param) {
	if (!glSamplerParameterIivproc) return;
	glSamplerParameterIivproc(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuivproc = 0;
void APIENTRY glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param) {
	if (!glSamplerParameterIuivproc) return;
	glSamplerParameterIuivproc(sampler, pname, param);
}
PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameterivproc = 0;
void APIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params) {
	if (!glGetSamplerParameterivproc) return;
	glGetSamplerParameterivproc(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIivproc = 0;
void APIENTRY glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params) {
	if (!glGetSamplerParameterIivproc) return;
	glGetSamplerParameterIivproc(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfvproc = 0;
void APIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params) {
	if (!glGetSamplerParameterfvproc) return;
	glGetSamplerParameterfvproc(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuivproc = 0;
void APIENTRY glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params) {
	if (!glGetSamplerParameterIuivproc) return;
	glGetSamplerParameterIuivproc(sampler, pname, params);
}
PFNGLQUERYCOUNTERPROC glQueryCounterproc = 0;
void APIENTRY glQueryCounter(GLuint id, GLenum target) {
	if (!glQueryCounterproc) return;
	glQueryCounterproc(id, target);
}
PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64vproc = 0;
void APIENTRY glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params) {
	if (!glGetQueryObjecti64vproc) return;
	glGetQueryObjecti64vproc(id, pname, params);
}
PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64vproc = 0;
void APIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params) {
	if (!glGetQueryObjectui64vproc) return;
	glGetQueryObjectui64vproc(id, pname, params);
}
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisorproc = 0;
void APIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor) {
	if (!glVertexAttribDivisorproc) return;
	glVertexAttribDivisorproc(index, divisor);
}
PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1uiproc = 0;
void APIENTRY glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	if (!glVertexAttribP1uiproc) return;
	glVertexAttribP1uiproc(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uivproc = 0;
void APIENTRY glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
	if (!glVertexAttribP1uivproc) return;
	glVertexAttribP1uivproc(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2uiproc = 0;
void APIENTRY glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	if (!glVertexAttribP2uiproc) return;
	glVertexAttribP2uiproc(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uivproc = 0;
void APIENTRY glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
	if (!glVertexAttribP2uivproc) return;
	glVertexAttribP2uivproc(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3uiproc = 0;
void APIENTRY glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	if (!glVertexAttribP3uiproc) return;
	glVertexAttribP3uiproc(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uivproc = 0;
void APIENTRY glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
	if (!glVertexAttribP3uivproc) return;
	glVertexAttribP3uivproc(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4uiproc = 0;
void APIENTRY glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
	if (!glVertexAttribP4uiproc) return;
	glVertexAttribP4uiproc(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uivproc = 0;
void APIENTRY glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) {
	if (!glVertexAttribP4uivproc) return;
	glVertexAttribP4uivproc(index, type, normalized, value);
}
PFNGLVERTEXP2UIPROC glVertexP2uiproc = 0;
void APIENTRY glVertexP2ui(GLenum type, GLuint value) {
	if (!glVertexP2uiproc) return;
	glVertexP2uiproc(type, value);
}
PFNGLVERTEXP2UIVPROC glVertexP2uivproc = 0;
void APIENTRY glVertexP2uiv(GLenum type, const GLuint* value) {
	if (!glVertexP2uivproc) return;
	glVertexP2uivproc(type, value);
}
PFNGLVERTEXP3UIPROC glVertexP3uiproc = 0;
void APIENTRY glVertexP3ui(GLenum type, GLuint value) {
	if (!glVertexP3uiproc) return;
	glVertexP3uiproc(type, value);
}
PFNGLVERTEXP3UIVPROC glVertexP3uivproc = 0;
void APIENTRY glVertexP3uiv(GLenum type, const GLuint* value) {
	if (!glVertexP3uivproc) return;
	glVertexP3uivproc(type, value);
}
PFNGLVERTEXP4UIPROC glVertexP4uiproc = 0;
void APIENTRY glVertexP4ui(GLenum type, GLuint value) {
	if (!glVertexP4uiproc) return;
	glVertexP4uiproc(type, value);
}
PFNGLVERTEXP4UIVPROC glVertexP4uivproc = 0;
void APIENTRY glVertexP4uiv(GLenum type, const GLuint* value) {
	if (!glVertexP4uivproc) return;
	glVertexP4uivproc(type, value);
}
PFNGLTEXCOORDP1UIPROC glTexCoordP1uiproc = 0;
void APIENTRY glTexCoordP1ui(GLenum type, GLuint coords) {
	if (!glTexCoordP1uiproc) return;
	glTexCoordP1uiproc(type, coords);
}
PFNGLTEXCOORDP1UIVPROC glTexCoordP1uivproc = 0;
void APIENTRY glTexCoordP1uiv(GLenum type, const GLuint* coords) {
	if (!glTexCoordP1uivproc) return;
	glTexCoordP1uivproc(type, coords);
}
PFNGLTEXCOORDP2UIPROC glTexCoordP2uiproc = 0;
void APIENTRY glTexCoordP2ui(GLenum type, GLuint coords) {
	if (!glTexCoordP2uiproc) return;
	glTexCoordP2uiproc(type, coords);
}
PFNGLTEXCOORDP2UIVPROC glTexCoordP2uivproc = 0;
void APIENTRY glTexCoordP2uiv(GLenum type, const GLuint* coords) {
	if (!glTexCoordP2uivproc) return;
	glTexCoordP2uivproc(type, coords);
}
PFNGLTEXCOORDP3UIPROC glTexCoordP3uiproc = 0;
void APIENTRY glTexCoordP3ui(GLenum type, GLuint coords) {
	if (!glTexCoordP3uiproc) return;
	glTexCoordP3uiproc(type, coords);
}
PFNGLTEXCOORDP3UIVPROC glTexCoordP3uivproc = 0;
void APIENTRY glTexCoordP3uiv(GLenum type, const GLuint* coords) {
	if (!glTexCoordP3uivproc) return;
	glTexCoordP3uivproc(type, coords);
}
PFNGLTEXCOORDP4UIPROC glTexCoordP4uiproc = 0;
void APIENTRY glTexCoordP4ui(GLenum type, GLuint coords) {
	if (!glTexCoordP4uiproc) return;
	glTexCoordP4uiproc(type, coords);
}
PFNGLTEXCOORDP4UIVPROC glTexCoordP4uivproc = 0;
void APIENTRY glTexCoordP4uiv(GLenum type, const GLuint* coords) {
	if (!glTexCoordP4uivproc) return;
	glTexCoordP4uivproc(type, coords);
}
PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1uiproc = 0;
void APIENTRY glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) {
	if (!glMultiTexCoordP1uiproc) return;
	glMultiTexCoordP1uiproc(texture, type, coords);
}
PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uivproc = 0;
void APIENTRY glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint* coords) {
	if (!glMultiTexCoordP1uivproc) return;
	glMultiTexCoordP1uivproc(texture, type, coords);
}
PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2uiproc = 0;
void APIENTRY glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) {
	if (!glMultiTexCoordP2uiproc) return;
	glMultiTexCoordP2uiproc(texture, type, coords);
}
PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uivproc = 0;
void APIENTRY glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint* coords) {
	if (!glMultiTexCoordP2uivproc) return;
	glMultiTexCoordP2uivproc(texture, type, coords);
}
PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3uiproc = 0;
void APIENTRY glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) {
	if (!glMultiTexCoordP3uiproc) return;
	glMultiTexCoordP3uiproc(texture, type, coords);
}
PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uivproc = 0;
void APIENTRY glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint* coords) {
	if (!glMultiTexCoordP3uivproc) return;
	glMultiTexCoordP3uivproc(texture, type, coords);
}
PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4uiproc = 0;
void APIENTRY glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) {
	if (!glMultiTexCoordP4uiproc) return;
	glMultiTexCoordP4uiproc(texture, type, coords);
}
PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uivproc = 0;
void APIENTRY glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint* coords) {
	if (!glMultiTexCoordP4uivproc) return;
	glMultiTexCoordP4uivproc(texture, type, coords);
}
PFNGLNORMALP3UIPROC glNormalP3uiproc = 0;
void APIENTRY glNormalP3ui(GLenum type, GLuint coords) {
	if (!glNormalP3uiproc) return;
	glNormalP3uiproc(type, coords);
}
PFNGLNORMALP3UIVPROC glNormalP3uivproc = 0;
void APIENTRY glNormalP3uiv(GLenum type, const GLuint* coords) {
	if (!glNormalP3uivproc) return;
	glNormalP3uivproc(type, coords);
}
PFNGLCOLORP3UIPROC glColorP3uiproc = 0;
void APIENTRY glColorP3ui(GLenum type, GLuint color) {
	if (!glColorP3uiproc) return;
	glColorP3uiproc(type, color);
}
PFNGLCOLORP3UIVPROC glColorP3uivproc = 0;
void APIENTRY glColorP3uiv(GLenum type, const GLuint* color) {
	if (!glColorP3uivproc) return;
	glColorP3uivproc(type, color);
}
PFNGLCOLORP4UIPROC glColorP4uiproc = 0;
void APIENTRY glColorP4ui(GLenum type, GLuint color) {
	if (!glColorP4uiproc) return;
	glColorP4uiproc(type, color);
}
PFNGLCOLORP4UIVPROC glColorP4uivproc = 0;
void APIENTRY glColorP4uiv(GLenum type, const GLuint* color) {
	if (!glColorP4uivproc) return;
	glColorP4uivproc(type, color);
}
PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3uiproc = 0;
void APIENTRY glSecondaryColorP3ui(GLenum type, GLuint color) {
	if (!glSecondaryColorP3uiproc) return;
	glSecondaryColorP3uiproc(type, color);
}
PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uivproc = 0;
void APIENTRY glSecondaryColorP3uiv(GLenum type, const GLuint* color) {
	if (!glSecondaryColorP3uivproc) return;
	glSecondaryColorP3uivproc(type, color);
}
PFNGLMINSAMPLESHADINGPROC glMinSampleShadingproc = 0;
void APIENTRY glMinSampleShading(GLfloat value) {
	if (!glMinSampleShadingproc) return;
	glMinSampleShadingproc(value);
}
PFNGLBLENDEQUATIONIPROC glBlendEquationiproc = 0;
void APIENTRY glBlendEquationi(GLuint buf, GLenum mode) {
	if (!glBlendEquationiproc) return;
	glBlendEquationiproc(buf, mode);
}
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparateiproc = 0;
void APIENTRY glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	if (!glBlendEquationSeparateiproc) return;
	glBlendEquationSeparateiproc(buf, modeRGB, modeAlpha);
}
PFNGLBLENDFUNCIPROC glBlendFunciproc = 0;
void APIENTRY glBlendFunci(GLuint buf, GLenum src, GLenum dst) {
	if (!glBlendFunciproc) return;
	glBlendFunciproc(buf, src, dst);
}
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparateiproc = 0;
void APIENTRY glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	if (!glBlendFuncSeparateiproc) return;
	glBlendFuncSeparateiproc(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirectproc = 0;
void APIENTRY glDrawArraysIndirect(GLenum mode, const void* indirect) {
	if (!glDrawArraysIndirectproc) return;
	glDrawArraysIndirectproc(mode, indirect);
}
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirectproc = 0;
void APIENTRY glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) {
	if (!glDrawElementsIndirectproc) return;
	glDrawElementsIndirectproc(mode, type, indirect);
}
PFNGLUNIFORM1DPROC glUniform1dproc = 0;
void APIENTRY glUniform1d(GLint location, GLdouble x) {
	if (!glUniform1dproc) return;
	glUniform1dproc(location, x);
}
PFNGLUNIFORM2DPROC glUniform2dproc = 0;
void APIENTRY glUniform2d(GLint location, GLdouble x, GLdouble y) {
	if (!glUniform2dproc) return;
	glUniform2dproc(location, x, y);
}
PFNGLUNIFORM3DPROC glUniform3dproc = 0;
void APIENTRY glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
	if (!glUniform3dproc) return;
	glUniform3dproc(location, x, y, z);
}
PFNGLUNIFORM4DPROC glUniform4dproc = 0;
void APIENTRY glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glUniform4dproc) return;
	glUniform4dproc(location, x, y, z, w);
}
PFNGLUNIFORM1DVPROC glUniform1dvproc = 0;
void APIENTRY glUniform1dv(GLint location, GLsizei count, const GLdouble* value) {
	if (!glUniform1dvproc) return;
	glUniform1dvproc(location, count, value);
}
PFNGLUNIFORM2DVPROC glUniform2dvproc = 0;
void APIENTRY glUniform2dv(GLint location, GLsizei count, const GLdouble* value) {
	if (!glUniform2dvproc) return;
	glUniform2dvproc(location, count, value);
}
PFNGLUNIFORM3DVPROC glUniform3dvproc = 0;
void APIENTRY glUniform3dv(GLint location, GLsizei count, const GLdouble* value) {
	if (!glUniform3dvproc) return;
	glUniform3dvproc(location, count, value);
}
PFNGLUNIFORM4DVPROC glUniform4dvproc = 0;
void APIENTRY glUniform4dv(GLint location, GLsizei count, const GLdouble* value) {
	if (!glUniform4dvproc) return;
	glUniform4dvproc(location, count, value);
}
PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dvproc = 0;
void APIENTRY glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix2dvproc) return;
	glUniformMatrix2dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dvproc = 0;
void APIENTRY glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix3dvproc) return;
	glUniformMatrix3dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dvproc = 0;
void APIENTRY glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix4dvproc) return;
	glUniformMatrix4dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dvproc = 0;
void APIENTRY glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix2x3dvproc) return;
	glUniformMatrix2x3dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dvproc = 0;
void APIENTRY glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix2x4dvproc) return;
	glUniformMatrix2x4dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dvproc = 0;
void APIENTRY glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix3x2dvproc) return;
	glUniformMatrix3x2dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dvproc = 0;
void APIENTRY glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix3x4dvproc) return;
	glUniformMatrix3x4dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dvproc = 0;
void APIENTRY glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix4x2dvproc) return;
	glUniformMatrix4x2dvproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dvproc = 0;
void APIENTRY glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glUniformMatrix4x3dvproc) return;
	glUniformMatrix4x3dvproc(location, count, transpose, value);
}
PFNGLGETUNIFORMDVPROC glGetUniformdvproc = 0;
void APIENTRY glGetUniformdv(GLuint program, GLint location, GLdouble* params) {
	if (!glGetUniformdvproc) return;
	glGetUniformdvproc(program, location, params);
}
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocationproc = 0;
GLint APIENTRY glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name) {
	if (!glGetSubroutineUniformLocationproc) return 0;
	return glGetSubroutineUniformLocationproc(program, shadertype, name);
}
PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndexproc = 0;
GLuint APIENTRY glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name) {
	if (!glGetSubroutineIndexproc) return 0;
	return glGetSubroutineIndexproc(program, shadertype, name);
}
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformivproc = 0;
void APIENTRY glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values) {
	if (!glGetActiveSubroutineUniformivproc) return;
	glGetActiveSubroutineUniformivproc(program, shadertype, index, pname, values);
}
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformNameproc = 0;
void APIENTRY glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) {
	if (!glGetActiveSubroutineUniformNameproc) return;
	glGetActiveSubroutineUniformNameproc(program, shadertype, index, bufSize, length, name);
}
PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineNameproc = 0;
void APIENTRY glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) {
	if (!glGetActiveSubroutineNameproc) return;
	glGetActiveSubroutineNameproc(program, shadertype, index, bufSize, length, name);
}
PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuivproc = 0;
void APIENTRY glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices) {
	if (!glUniformSubroutinesuivproc) return;
	glUniformSubroutinesuivproc(shadertype, count, indices);
}
PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuivproc = 0;
void APIENTRY glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params) {
	if (!glGetUniformSubroutineuivproc) return;
	glGetUniformSubroutineuivproc(shadertype, location, params);
}
PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageivproc = 0;
void APIENTRY glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values) {
	if (!glGetProgramStageivproc) return;
	glGetProgramStageivproc(program, shadertype, pname, values);
}
PFNGLPATCHPARAMETERIPROC glPatchParameteriproc = 0;
void APIENTRY glPatchParameteri(GLenum pname, GLint value) {
	if (!glPatchParameteriproc) return;
	glPatchParameteriproc(pname, value);
}
PFNGLPATCHPARAMETERFVPROC glPatchParameterfvproc = 0;
void APIENTRY glPatchParameterfv(GLenum pname, const GLfloat* values) {
	if (!glPatchParameterfvproc) return;
	glPatchParameterfvproc(pname, values);
}
PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedbackproc = 0;
void APIENTRY glBindTransformFeedback(GLenum target, GLuint id) {
	if (!glBindTransformFeedbackproc) return;
	glBindTransformFeedbackproc(target, id);
}
PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacksproc = 0;
void APIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) {
	if (!glDeleteTransformFeedbacksproc) return;
	glDeleteTransformFeedbacksproc(n, ids);
}
PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacksproc = 0;
void APIENTRY glGenTransformFeedbacks(GLsizei n, GLuint* ids) {
	if (!glGenTransformFeedbacksproc) return;
	glGenTransformFeedbacksproc(n, ids);
}
PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedbackproc = 0;
GLboolean APIENTRY glIsTransformFeedback(GLuint id) {
	if (!glIsTransformFeedbackproc) return 0;
	return glIsTransformFeedbackproc(id);
}
PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedbackproc = 0;
void APIENTRY glPauseTransformFeedback(void) {
	if (!glPauseTransformFeedbackproc) return;
	glPauseTransformFeedbackproc();
}
PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedbackproc = 0;
void APIENTRY glResumeTransformFeedback(void) {
	if (!glResumeTransformFeedbackproc) return;
	glResumeTransformFeedbackproc();
}
PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedbackproc = 0;
void APIENTRY glDrawTransformFeedback(GLenum mode, GLuint id) {
	if (!glDrawTransformFeedbackproc) return;
	glDrawTransformFeedbackproc(mode, id);
}
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStreamproc = 0;
void APIENTRY glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) {
	if (!glDrawTransformFeedbackStreamproc) return;
	glDrawTransformFeedbackStreamproc(mode, id, stream);
}
PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexedproc = 0;
void APIENTRY glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
	if (!glBeginQueryIndexedproc) return;
	glBeginQueryIndexedproc(target, index, id);
}
PFNGLENDQUERYINDEXEDPROC glEndQueryIndexedproc = 0;
void APIENTRY glEndQueryIndexed(GLenum target, GLuint index) {
	if (!glEndQueryIndexedproc) return;
	glEndQueryIndexedproc(target, index);
}
PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexedivproc = 0;
void APIENTRY glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params) {
	if (!glGetQueryIndexedivproc) return;
	glGetQueryIndexedivproc(target, index, pname, params);
}
PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompilerproc = 0;
void APIENTRY glReleaseShaderCompiler(void) {
	if (!glReleaseShaderCompilerproc) return;
	glReleaseShaderCompilerproc();
}
PFNGLSHADERBINARYPROC glShaderBinaryproc = 0;
void APIENTRY glShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length) {
	if (!glShaderBinaryproc) return;
	glShaderBinaryproc(count, shaders, binaryFormat, binary, length);
}
PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormatproc = 0;
void APIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) {
	if (!glGetShaderPrecisionFormatproc) return;
	glGetShaderPrecisionFormatproc(shadertype, precisiontype, range, precision);
}
PFNGLDEPTHRANGEFPROC glDepthRangefproc = 0;
void APIENTRY glDepthRangef(GLfloat n, GLfloat f) {
	if (!glDepthRangefproc) return;
	glDepthRangefproc(n, f);
}
PFNGLCLEARDEPTHFPROC glClearDepthfproc = 0;
void APIENTRY glClearDepthf(GLfloat d) {
	if (!glClearDepthfproc) return;
	glClearDepthfproc(d);
}
PFNGLGETPROGRAMBINARYPROC glGetProgramBinaryproc = 0;
void APIENTRY glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary) {
	if (!glGetProgramBinaryproc) return;
	glGetProgramBinaryproc(program, bufSize, length, binaryFormat, binary);
}
PFNGLPROGRAMBINARYPROC glProgramBinaryproc = 0;
void APIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length) {
	if (!glProgramBinaryproc) return;
	glProgramBinaryproc(program, binaryFormat, binary, length);
}
PFNGLPROGRAMPARAMETERIPROC glProgramParameteriproc = 0;
void APIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value) {
	if (!glProgramParameteriproc) return;
	glProgramParameteriproc(program, pname, value);
}
PFNGLUSEPROGRAMSTAGESPROC glUseProgramStagesproc = 0;
void APIENTRY glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {
	if (!glUseProgramStagesproc) return;
	glUseProgramStagesproc(pipeline, stages, program);
}
PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgramproc = 0;
void APIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program) {
	if (!glActiveShaderProgramproc) return;
	glActiveShaderProgramproc(pipeline, program);
}
PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramvproc = 0;
GLuint APIENTRY glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* const* strings) {
	if (!glCreateShaderProgramvproc) return 0;
	return glCreateShaderProgramvproc(type, count, strings);
}
PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipelineproc = 0;
void APIENTRY glBindProgramPipeline(GLuint pipeline) {
	if (!glBindProgramPipelineproc) return;
	glBindProgramPipelineproc(pipeline);
}
PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelinesproc = 0;
void APIENTRY glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines) {
	if (!glDeleteProgramPipelinesproc) return;
	glDeleteProgramPipelinesproc(n, pipelines);
}
PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelinesproc = 0;
void APIENTRY glGenProgramPipelines(GLsizei n, GLuint* pipelines) {
	if (!glGenProgramPipelinesproc) return;
	glGenProgramPipelinesproc(n, pipelines);
}
PFNGLISPROGRAMPIPELINEPROC glIsProgramPipelineproc = 0;
GLboolean APIENTRY glIsProgramPipeline(GLuint pipeline) {
	if (!glIsProgramPipelineproc) return 0;
	return glIsProgramPipelineproc(pipeline);
}
PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineivproc = 0;
void APIENTRY glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params) {
	if (!glGetProgramPipelineivproc) return;
	glGetProgramPipelineivproc(pipeline, pname, params);
}
PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1iproc = 0;
void APIENTRY glProgramUniform1i(GLuint program, GLint location, GLint v0) {
	if (!glProgramUniform1iproc) return;
	glProgramUniform1iproc(program, location, v0);
}
PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1ivproc = 0;
void APIENTRY glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform1ivproc) return;
	glProgramUniform1ivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1fproc = 0;
void APIENTRY glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
	if (!glProgramUniform1fproc) return;
	glProgramUniform1fproc(program, location, v0);
}
PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fvproc = 0;
void APIENTRY glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform1fvproc) return;
	glProgramUniform1fvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1dproc = 0;
void APIENTRY glProgramUniform1d(GLuint program, GLint location, GLdouble v0) {
	if (!glProgramUniform1dproc) return;
	glProgramUniform1dproc(program, location, v0);
}
PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dvproc = 0;
void APIENTRY glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform1dvproc) return;
	glProgramUniform1dvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1uiproc = 0;
void APIENTRY glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
	if (!glProgramUniform1uiproc) return;
	glProgramUniform1uiproc(program, location, v0);
}
PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uivproc = 0;
void APIENTRY glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform1uivproc) return;
	glProgramUniform1uivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2iproc = 0;
void APIENTRY glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
	if (!glProgramUniform2iproc) return;
	glProgramUniform2iproc(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2ivproc = 0;
void APIENTRY glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform2ivproc) return;
	glProgramUniform2ivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2fproc = 0;
void APIENTRY glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
	if (!glProgramUniform2fproc) return;
	glProgramUniform2fproc(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fvproc = 0;
void APIENTRY glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform2fvproc) return;
	glProgramUniform2fvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2dproc = 0;
void APIENTRY glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) {
	if (!glProgramUniform2dproc) return;
	glProgramUniform2dproc(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dvproc = 0;
void APIENTRY glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform2dvproc) return;
	glProgramUniform2dvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2uiproc = 0;
void APIENTRY glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {
	if (!glProgramUniform2uiproc) return;
	glProgramUniform2uiproc(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uivproc = 0;
void APIENTRY glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform2uivproc) return;
	glProgramUniform2uivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3iproc = 0;
void APIENTRY glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
	if (!glProgramUniform3iproc) return;
	glProgramUniform3iproc(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3ivproc = 0;
void APIENTRY glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform3ivproc) return;
	glProgramUniform3ivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3fproc = 0;
void APIENTRY glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	if (!glProgramUniform3fproc) return;
	glProgramUniform3fproc(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fvproc = 0;
void APIENTRY glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform3fvproc) return;
	glProgramUniform3fvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3dproc = 0;
void APIENTRY glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) {
	if (!glProgramUniform3dproc) return;
	glProgramUniform3dproc(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dvproc = 0;
void APIENTRY glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform3dvproc) return;
	glProgramUniform3dvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3uiproc = 0;
void APIENTRY glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
	if (!glProgramUniform3uiproc) return;
	glProgramUniform3uiproc(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uivproc = 0;
void APIENTRY glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform3uivproc) return;
	glProgramUniform3uivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4iproc = 0;
void APIENTRY glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	if (!glProgramUniform4iproc) return;
	glProgramUniform4iproc(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4ivproc = 0;
void APIENTRY glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform4ivproc) return;
	glProgramUniform4ivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4fproc = 0;
void APIENTRY glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	if (!glProgramUniform4fproc) return;
	glProgramUniform4fproc(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fvproc = 0;
void APIENTRY glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform4fvproc) return;
	glProgramUniform4fvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4dproc = 0;
void APIENTRY glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) {
	if (!glProgramUniform4dproc) return;
	glProgramUniform4dproc(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dvproc = 0;
void APIENTRY glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform4dvproc) return;
	glProgramUniform4dvproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4uiproc = 0;
void APIENTRY glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	if (!glProgramUniform4uiproc) return;
	glProgramUniform4uiproc(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uivproc = 0;
void APIENTRY glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform4uivproc) return;
	glProgramUniform4uivproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fvproc = 0;
void APIENTRY glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix2fvproc) return;
	glProgramUniformMatrix2fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fvproc = 0;
void APIENTRY glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix3fvproc) return;
	glProgramUniformMatrix3fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fvproc = 0;
void APIENTRY glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix4fvproc) return;
	glProgramUniformMatrix4fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dvproc = 0;
void APIENTRY glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix2dvproc) return;
	glProgramUniformMatrix2dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dvproc = 0;
void APIENTRY glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix3dvproc) return;
	glProgramUniformMatrix3dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dvproc = 0;
void APIENTRY glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix4dvproc) return;
	glProgramUniformMatrix4dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fvproc = 0;
void APIENTRY glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix2x3fvproc) return;
	glProgramUniformMatrix2x3fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fvproc = 0;
void APIENTRY glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix3x2fvproc) return;
	glProgramUniformMatrix3x2fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fvproc = 0;
void APIENTRY glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix2x4fvproc) return;
	glProgramUniformMatrix2x4fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fvproc = 0;
void APIENTRY glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix4x2fvproc) return;
	glProgramUniformMatrix4x2fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fvproc = 0;
void APIENTRY glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix3x4fvproc) return;
	glProgramUniformMatrix3x4fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fvproc = 0;
void APIENTRY glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix4x3fvproc) return;
	glProgramUniformMatrix4x3fvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dvproc = 0;
void APIENTRY glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix2x3dvproc) return;
	glProgramUniformMatrix2x3dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dvproc = 0;
void APIENTRY glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix3x2dvproc) return;
	glProgramUniformMatrix3x2dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dvproc = 0;
void APIENTRY glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix2x4dvproc) return;
	glProgramUniformMatrix2x4dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dvproc = 0;
void APIENTRY glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix4x2dvproc) return;
	glProgramUniformMatrix4x2dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dvproc = 0;
void APIENTRY glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix3x4dvproc) return;
	glProgramUniformMatrix3x4dvproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dvproc = 0;
void APIENTRY glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix4x3dvproc) return;
	glProgramUniformMatrix4x3dvproc(program, location, count, transpose, value);
}
PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipelineproc = 0;
void APIENTRY glValidateProgramPipeline(GLuint pipeline) {
	if (!glValidateProgramPipelineproc) return;
	glValidateProgramPipelineproc(pipeline);
}
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLogproc = 0;
void APIENTRY glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
	if (!glGetProgramPipelineInfoLogproc) return;
	glGetProgramPipelineInfoLogproc(pipeline, bufSize, length, infoLog);
}
PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1dproc = 0;
void APIENTRY glVertexAttribL1d(GLuint index, GLdouble x) {
	if (!glVertexAttribL1dproc) return;
	glVertexAttribL1dproc(index, x);
}
PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2dproc = 0;
void APIENTRY glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
	if (!glVertexAttribL2dproc) return;
	glVertexAttribL2dproc(index, x, y);
}
PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3dproc = 0;
void APIENTRY glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	if (!glVertexAttribL3dproc) return;
	glVertexAttribL3dproc(index, x, y, z);
}
PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4dproc = 0;
void APIENTRY glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glVertexAttribL4dproc) return;
	glVertexAttribL4dproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dvproc = 0;
void APIENTRY glVertexAttribL1dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL1dvproc) return;
	glVertexAttribL1dvproc(index, v);
}
PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dvproc = 0;
void APIENTRY glVertexAttribL2dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL2dvproc) return;
	glVertexAttribL2dvproc(index, v);
}
PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dvproc = 0;
void APIENTRY glVertexAttribL3dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL3dvproc) return;
	glVertexAttribL3dvproc(index, v);
}
PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dvproc = 0;
void APIENTRY glVertexAttribL4dv(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL4dvproc) return;
	glVertexAttribL4dvproc(index, v);
}
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointerproc = 0;
void APIENTRY glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glVertexAttribLPointerproc) return;
	glVertexAttribLPointerproc(index, size, type, stride, pointer);
}
PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdvproc = 0;
void APIENTRY glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params) {
	if (!glGetVertexAttribLdvproc) return;
	glGetVertexAttribLdvproc(index, pname, params);
}
PFNGLVIEWPORTARRAYVPROC glViewportArrayvproc = 0;
void APIENTRY glViewportArrayv(GLuint first, GLsizei count, const GLfloat* v) {
	if (!glViewportArrayvproc) return;
	glViewportArrayvproc(first, count, v);
}
PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedfproc = 0;
void APIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
	if (!glViewportIndexedfproc) return;
	glViewportIndexedfproc(index, x, y, w, h);
}
PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfvproc = 0;
void APIENTRY glViewportIndexedfv(GLuint index, const GLfloat* v) {
	if (!glViewportIndexedfvproc) return;
	glViewportIndexedfvproc(index, v);
}
PFNGLSCISSORARRAYVPROC glScissorArrayvproc = 0;
void APIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint* v) {
	if (!glScissorArrayvproc) return;
	glScissorArrayvproc(first, count, v);
}
PFNGLSCISSORINDEXEDPROC glScissorIndexedproc = 0;
void APIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
	if (!glScissorIndexedproc) return;
	glScissorIndexedproc(index, left, bottom, width, height);
}
PFNGLSCISSORINDEXEDVPROC glScissorIndexedvproc = 0;
void APIENTRY glScissorIndexedv(GLuint index, const GLint* v) {
	if (!glScissorIndexedvproc) return;
	glScissorIndexedvproc(index, v);
}
PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayvproc = 0;
void APIENTRY glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v) {
	if (!glDepthRangeArrayvproc) return;
	glDepthRangeArrayvproc(first, count, v);
}
PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexedproc = 0;
void APIENTRY glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) {
	if (!glDepthRangeIndexedproc) return;
	glDepthRangeIndexedproc(index, n, f);
}
PFNGLGETFLOATI_VPROC glGetFloati_vproc = 0;
void APIENTRY glGetFloati_v(GLenum target, GLuint index, GLfloat* data) {
	if (!glGetFloati_vproc) return;
	glGetFloati_vproc(target, index, data);
}
PFNGLGETDOUBLEI_VPROC glGetDoublei_vproc = 0;
void APIENTRY glGetDoublei_v(GLenum target, GLuint index, GLdouble* data) {
	if (!glGetDoublei_vproc) return;
	glGetDoublei_vproc(target, index, data);
}
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstanceproc = 0;
void APIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
	if (!glDrawArraysInstancedBaseInstanceproc) return;
	glDrawArraysInstancedBaseInstanceproc(mode, first, count, instancecount, baseinstance);
}
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstanceproc = 0;
void APIENTRY glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance) {
	if (!glDrawElementsInstancedBaseInstanceproc) return;
	glDrawElementsInstancedBaseInstanceproc(mode, count, type, indices, instancecount, baseinstance);
}
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstanceproc = 0;
void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
	if (!glDrawElementsInstancedBaseVertexBaseInstanceproc) return;
	glDrawElementsInstancedBaseVertexBaseInstanceproc(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
PFNGLGETINTERNALFORMATIVPROC glGetInternalformativproc = 0;
void APIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params) {
	if (!glGetInternalformativproc) return;
	glGetInternalformativproc(target, internalformat, pname, count, params);
}
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferivproc = 0;
void APIENTRY glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params) {
	if (!glGetActiveAtomicCounterBufferivproc) return;
	glGetActiveAtomicCounterBufferivproc(program, bufferIndex, pname, params);
}
PFNGLBINDIMAGETEXTUREPROC glBindImageTextureproc = 0;
void APIENTRY glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
	if (!glBindImageTextureproc) return;
	glBindImageTextureproc(unit, texture, level, layered, layer, access, format);
}
PFNGLMEMORYBARRIERPROC glMemoryBarrierproc = 0;
void APIENTRY glMemoryBarrier(GLbitfield barriers) {
	if (!glMemoryBarrierproc) return;
	glMemoryBarrierproc(barriers);
}
PFNGLTEXSTORAGE1DPROC glTexStorage1Dproc = 0;
void APIENTRY glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	if (!glTexStorage1Dproc) return;
	glTexStorage1Dproc(target, levels, internalformat, width);
}
PFNGLTEXSTORAGE2DPROC glTexStorage2Dproc = 0;
void APIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glTexStorage2Dproc) return;
	glTexStorage2Dproc(target, levels, internalformat, width, height);
}
PFNGLTEXSTORAGE3DPROC glTexStorage3Dproc = 0;
void APIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	if (!glTexStorage3Dproc) return;
	glTexStorage3Dproc(target, levels, internalformat, width, height, depth);
}
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstancedproc = 0;
void APIENTRY glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) {
	if (!glDrawTransformFeedbackInstancedproc) return;
	glDrawTransformFeedbackInstancedproc(mode, id, instancecount);
}
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstancedproc = 0;
void APIENTRY glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) {
	if (!glDrawTransformFeedbackStreamInstancedproc) return;
	glDrawTransformFeedbackStreamInstancedproc(mode, id, stream, instancecount);
}
PFNGLCLEARBUFFERDATAPROC glClearBufferDataproc = 0;
void APIENTRY glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data) {
	if (!glClearBufferDataproc) return;
	glClearBufferDataproc(target, internalformat, format, type, data);
}
PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubDataproc = 0;
void APIENTRY glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) {
	if (!glClearBufferSubDataproc) return;
	glClearBufferSubDataproc(target, internalformat, offset, size, format, type, data);
}
PFNGLDISPATCHCOMPUTEPROC glDispatchComputeproc = 0;
void APIENTRY glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
	if (!glDispatchComputeproc) return;
	glDispatchComputeproc(num_groups_x, num_groups_y, num_groups_z);
}
PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirectproc = 0;
void APIENTRY glDispatchComputeIndirect(GLintptr indirect) {
	if (!glDispatchComputeIndirectproc) return;
	glDispatchComputeIndirectproc(indirect);
}
PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubDataproc = 0;
void APIENTRY glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
	if (!glCopyImageSubDataproc) return;
	glCopyImageSubDataproc(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteriproc = 0;
void APIENTRY glFramebufferParameteri(GLenum target, GLenum pname, GLint param) {
	if (!glFramebufferParameteriproc) return;
	glFramebufferParameteriproc(target, pname, param);
}
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameterivproc = 0;
void APIENTRY glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetFramebufferParameterivproc) return;
	glGetFramebufferParameterivproc(target, pname, params);
}
PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64vproc = 0;
void APIENTRY glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params) {
	if (!glGetInternalformati64vproc) return;
	glGetInternalformati64vproc(target, internalformat, pname, count, params);
}
PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImageproc = 0;
void APIENTRY glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) {
	if (!glInvalidateTexSubImageproc) return;
	glInvalidateTexSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}
PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImageproc = 0;
void APIENTRY glInvalidateTexImage(GLuint texture, GLint level) {
	if (!glInvalidateTexImageproc) return;
	glInvalidateTexImageproc(texture, level);
}
PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubDataproc = 0;
void APIENTRY glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) {
	if (!glInvalidateBufferSubDataproc) return;
	glInvalidateBufferSubDataproc(buffer, offset, length);
}
PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferDataproc = 0;
void APIENTRY glInvalidateBufferData(GLuint buffer) {
	if (!glInvalidateBufferDataproc) return;
	glInvalidateBufferDataproc(buffer);
}
PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebufferproc = 0;
void APIENTRY glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments) {
	if (!glInvalidateFramebufferproc) return;
	glInvalidateFramebufferproc(target, numAttachments, attachments);
}
PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebufferproc = 0;
void APIENTRY glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glInvalidateSubFramebufferproc) return;
	glInvalidateSubFramebufferproc(target, numAttachments, attachments, x, y, width, height);
}
PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirectproc = 0;
void APIENTRY glMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride) {
	if (!glMultiDrawArraysIndirectproc) return;
	glMultiDrawArraysIndirectproc(mode, indirect, drawcount, stride);
}
PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirectproc = 0;
void APIENTRY glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride) {
	if (!glMultiDrawElementsIndirectproc) return;
	glMultiDrawElementsIndirectproc(mode, type, indirect, drawcount, stride);
}
PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceivproc = 0;
void APIENTRY glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params) {
	if (!glGetProgramInterfaceivproc) return;
	glGetProgramInterfaceivproc(program, programInterface, pname, params);
}
PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndexproc = 0;
GLuint APIENTRY glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name) {
	if (!glGetProgramResourceIndexproc) return 0;
	return glGetProgramResourceIndexproc(program, programInterface, name);
}
PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceNameproc = 0;
void APIENTRY glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) {
	if (!glGetProgramResourceNameproc) return;
	glGetProgramResourceNameproc(program, programInterface, index, bufSize, length, name);
}
PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceivproc = 0;
void APIENTRY glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params) {
	if (!glGetProgramResourceivproc) return;
	glGetProgramResourceivproc(program, programInterface, index, propCount, props, count, length, params);
}
PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocationproc = 0;
GLint APIENTRY glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name) {
	if (!glGetProgramResourceLocationproc) return 0;
	return glGetProgramResourceLocationproc(program, programInterface, name);
}
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndexproc = 0;
GLint APIENTRY glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name) {
	if (!glGetProgramResourceLocationIndexproc) return 0;
	return glGetProgramResourceLocationIndexproc(program, programInterface, name);
}
PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBindingproc = 0;
void APIENTRY glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) {
	if (!glShaderStorageBlockBindingproc) return;
	glShaderStorageBlockBindingproc(program, storageBlockIndex, storageBlockBinding);
}
PFNGLTEXBUFFERRANGEPROC glTexBufferRangeproc = 0;
void APIENTRY glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	if (!glTexBufferRangeproc) return;
	glTexBufferRangeproc(target, internalformat, buffer, offset, size);
}
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisampleproc = 0;
void APIENTRY glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	if (!glTexStorage2DMultisampleproc) return;
	glTexStorage2DMultisampleproc(target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisampleproc = 0;
void APIENTRY glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	if (!glTexStorage3DMultisampleproc) return;
	glTexStorage3DMultisampleproc(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXTUREVIEWPROC glTextureViewproc = 0;
void APIENTRY glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
	if (!glTextureViewproc) return;
	glTextureViewproc(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
PFNGLBINDVERTEXBUFFERPROC glBindVertexBufferproc = 0;
void APIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
	if (!glBindVertexBufferproc) return;
	glBindVertexBufferproc(bindingindex, buffer, offset, stride);
}
PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormatproc = 0;
void APIENTRY glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
	if (!glVertexAttribFormatproc) return;
	glVertexAttribFormatproc(attribindex, size, type, normalized, relativeoffset);
}
PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormatproc = 0;
void APIENTRY glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	if (!glVertexAttribIFormatproc) return;
	glVertexAttribIFormatproc(attribindex, size, type, relativeoffset);
}
PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormatproc = 0;
void APIENTRY glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	if (!glVertexAttribLFormatproc) return;
	glVertexAttribLFormatproc(attribindex, size, type, relativeoffset);
}
PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBindingproc = 0;
void APIENTRY glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) {
	if (!glVertexAttribBindingproc) return;
	glVertexAttribBindingproc(attribindex, bindingindex);
}
PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisorproc = 0;
void APIENTRY glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) {
	if (!glVertexBindingDivisorproc) return;
	glVertexBindingDivisorproc(bindingindex, divisor);
}
PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControlproc = 0;
void APIENTRY glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) {
	if (!glDebugMessageControlproc) return;
	glDebugMessageControlproc(source, type, severity, count, ids, enabled);
}
PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsertproc = 0;
void APIENTRY glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf) {
	if (!glDebugMessageInsertproc) return;
	glDebugMessageInsertproc(source, type, id, severity, length, buf);
}
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallbackproc = 0;
void APIENTRY glDebugMessageCallback(GLDEBUGPROC callback, const void* userParam) {
	if (!glDebugMessageCallbackproc) return;
	glDebugMessageCallbackproc(callback, userParam);
}
PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLogproc = 0;
GLuint APIENTRY glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog) {
	if (!glGetDebugMessageLogproc) return 0;
	return glGetDebugMessageLogproc(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
PFNGLPUSHDEBUGGROUPPROC glPushDebugGroupproc = 0;
void APIENTRY glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message) {
	if (!glPushDebugGroupproc) return;
	glPushDebugGroupproc(source, id, length, message);
}
PFNGLPOPDEBUGGROUPPROC glPopDebugGroupproc = 0;
void APIENTRY glPopDebugGroup(void) {
	if (!glPopDebugGroupproc) return;
	glPopDebugGroupproc();
}
PFNGLOBJECTLABELPROC glObjectLabelproc = 0;
void APIENTRY glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label) {
	if (!glObjectLabelproc) return;
	glObjectLabelproc(identifier, name, length, label);
}
PFNGLGETOBJECTLABELPROC glGetObjectLabelproc = 0;
void APIENTRY glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label) {
	if (!glGetObjectLabelproc) return;
	glGetObjectLabelproc(identifier, name, bufSize, length, label);
}
PFNGLOBJECTPTRLABELPROC glObjectPtrLabelproc = 0;
void APIENTRY glObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label) {
	if (!glObjectPtrLabelproc) return;
	glObjectPtrLabelproc(ptr, length, label);
}
PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabelproc = 0;
void APIENTRY glGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label) {
	if (!glGetObjectPtrLabelproc) return;
	glGetObjectPtrLabelproc(ptr, bufSize, length, label);
}
PFNGLBUFFERSTORAGEPROC glBufferStorageproc = 0;
void APIENTRY glBufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags) {
	if (!glBufferStorageproc) return;
	glBufferStorageproc(target, size, data, flags);
}
PFNGLCLEARTEXIMAGEPROC glClearTexImageproc = 0;
void APIENTRY glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data) {
	if (!glClearTexImageproc) return;
	glClearTexImageproc(texture, level, format, type, data);
}
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImageproc = 0;
void APIENTRY glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data) {
	if (!glClearTexSubImageproc) return;
	glClearTexSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}
PFNGLBINDBUFFERSBASEPROC glBindBuffersBaseproc = 0;
void APIENTRY glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers) {
	if (!glBindBuffersBaseproc) return;
	glBindBuffersBaseproc(target, first, count, buffers);
}
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRangeproc = 0;
void APIENTRY glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes) {
	if (!glBindBuffersRangeproc) return;
	glBindBuffersRangeproc(target, first, count, buffers, offsets, sizes);
}
PFNGLBINDTEXTURESPROC glBindTexturesproc = 0;
void APIENTRY glBindTextures(GLuint first, GLsizei count, const GLuint* textures) {
	if (!glBindTexturesproc) return;
	glBindTexturesproc(first, count, textures);
}
PFNGLBINDSAMPLERSPROC glBindSamplersproc = 0;
void APIENTRY glBindSamplers(GLuint first, GLsizei count, const GLuint* samplers) {
	if (!glBindSamplersproc) return;
	glBindSamplersproc(first, count, samplers);
}
PFNGLBINDIMAGETEXTURESPROC glBindImageTexturesproc = 0;
void APIENTRY glBindImageTextures(GLuint first, GLsizei count, const GLuint* textures) {
	if (!glBindImageTexturesproc) return;
	glBindImageTexturesproc(first, count, textures);
}
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffersproc = 0;
void APIENTRY glBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) {
	if (!glBindVertexBuffersproc) return;
	glBindVertexBuffersproc(first, count, buffers, offsets, strides);
}
PFNGLCLIPCONTROLPROC glClipControlproc = 0;
void APIENTRY glClipControl(GLenum origin, GLenum depth) {
	if (!glClipControlproc) return;
	glClipControlproc(origin, depth);
}
PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacksproc = 0;
void APIENTRY glCreateTransformFeedbacks(GLsizei n, GLuint* ids) {
	if (!glCreateTransformFeedbacksproc) return;
	glCreateTransformFeedbacksproc(n, ids);
}
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBaseproc = 0;
void APIENTRY glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) {
	if (!glTransformFeedbackBufferBaseproc) return;
	glTransformFeedbackBufferBaseproc(xfb, index, buffer);
}
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRangeproc = 0;
void APIENTRY glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	if (!glTransformFeedbackBufferRangeproc) return;
	glTransformFeedbackBufferRangeproc(xfb, index, buffer, offset, size);
}
PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackivproc = 0;
void APIENTRY glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param) {
	if (!glGetTransformFeedbackivproc) return;
	glGetTransformFeedbackivproc(xfb, pname, param);
}
PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_vproc = 0;
void APIENTRY glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param) {
	if (!glGetTransformFeedbacki_vproc) return;
	glGetTransformFeedbacki_vproc(xfb, pname, index, param);
}
PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_vproc = 0;
void APIENTRY glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param) {
	if (!glGetTransformFeedbacki64_vproc) return;
	glGetTransformFeedbacki64_vproc(xfb, pname, index, param);
}
PFNGLCREATEBUFFERSPROC glCreateBuffersproc = 0;
void APIENTRY glCreateBuffers(GLsizei n, GLuint* buffers) {
	if (!glCreateBuffersproc) return;
	glCreateBuffersproc(n, buffers);
}
PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorageproc = 0;
void APIENTRY glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags) {
	if (!glNamedBufferStorageproc) return;
	glNamedBufferStorageproc(buffer, size, data, flags);
}
PFNGLNAMEDBUFFERDATAPROC glNamedBufferDataproc = 0;
void APIENTRY glNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) {
	if (!glNamedBufferDataproc) return;
	glNamedBufferDataproc(buffer, size, data, usage);
}
PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubDataproc = 0;
void APIENTRY glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) {
	if (!glNamedBufferSubDataproc) return;
	glNamedBufferSubDataproc(buffer, offset, size, data);
}
PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubDataproc = 0;
void APIENTRY glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
	if (!glCopyNamedBufferSubDataproc) return;
	glCopyNamedBufferSubDataproc(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferDataproc = 0;
void APIENTRY glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data) {
	if (!glClearNamedBufferDataproc) return;
	glClearNamedBufferDataproc(buffer, internalformat, format, type, data);
}
PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubDataproc = 0;
void APIENTRY glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) {
	if (!glClearNamedBufferSubDataproc) return;
	glClearNamedBufferSubDataproc(buffer, internalformat, offset, size, format, type, data);
}
PFNGLMAPNAMEDBUFFERPROC glMapNamedBufferproc = 0;
void* APIENTRY glMapNamedBuffer(GLuint buffer, GLenum access) {
	if (!glMapNamedBufferproc) return 0;
	return glMapNamedBufferproc(buffer, access);
}
PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRangeproc = 0;
void* APIENTRY glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	if (!glMapNamedBufferRangeproc) return 0;
	return glMapNamedBufferRangeproc(buffer, offset, length, access);
}
PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBufferproc = 0;
GLboolean APIENTRY glUnmapNamedBuffer(GLuint buffer) {
	if (!glUnmapNamedBufferproc) return 0;
	return glUnmapNamedBufferproc(buffer);
}
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRangeproc = 0;
void APIENTRY glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) {
	if (!glFlushMappedNamedBufferRangeproc) return;
	glFlushMappedNamedBufferRangeproc(buffer, offset, length);
}
PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameterivproc = 0;
void APIENTRY glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params) {
	if (!glGetNamedBufferParameterivproc) return;
	glGetNamedBufferParameterivproc(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64vproc = 0;
void APIENTRY glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params) {
	if (!glGetNamedBufferParameteri64vproc) return;
	glGetNamedBufferParameteri64vproc(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointervproc = 0;
void APIENTRY glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params) {
	if (!glGetNamedBufferPointervproc) return;
	glGetNamedBufferPointervproc(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubDataproc = 0;
void APIENTRY glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) {
	if (!glGetNamedBufferSubDataproc) return;
	glGetNamedBufferSubDataproc(buffer, offset, size, data);
}
PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffersproc = 0;
void APIENTRY glCreateFramebuffers(GLsizei n, GLuint* framebuffers) {
	if (!glCreateFramebuffersproc) return;
	glCreateFramebuffersproc(n, framebuffers);
}
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbufferproc = 0;
void APIENTRY glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	if (!glNamedFramebufferRenderbufferproc) return;
	glNamedFramebufferRenderbufferproc(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteriproc = 0;
void APIENTRY glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) {
	if (!glNamedFramebufferParameteriproc) return;
	glNamedFramebufferParameteriproc(framebuffer, pname, param);
}
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTextureproc = 0;
void APIENTRY glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
	if (!glNamedFramebufferTextureproc) return;
	glNamedFramebufferTextureproc(framebuffer, attachment, texture, level);
}
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayerproc = 0;
void APIENTRY glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	if (!glNamedFramebufferTextureLayerproc) return;
	glNamedFramebufferTextureLayerproc(framebuffer, attachment, texture, level, layer);
}
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBufferproc = 0;
void APIENTRY glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) {
	if (!glNamedFramebufferDrawBufferproc) return;
	glNamedFramebufferDrawBufferproc(framebuffer, buf);
}
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffersproc = 0;
void APIENTRY glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs) {
	if (!glNamedFramebufferDrawBuffersproc) return;
	glNamedFramebufferDrawBuffersproc(framebuffer, n, bufs);
}
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBufferproc = 0;
void APIENTRY glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) {
	if (!glNamedFramebufferReadBufferproc) return;
	glNamedFramebufferReadBufferproc(framebuffer, src);
}
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferDataproc = 0;
void APIENTRY glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments) {
	if (!glInvalidateNamedFramebufferDataproc) return;
	glInvalidateNamedFramebufferDataproc(framebuffer, numAttachments, attachments);
}
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubDataproc = 0;
void APIENTRY glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glInvalidateNamedFramebufferSubDataproc) return;
	glInvalidateNamedFramebufferSubDataproc(framebuffer, numAttachments, attachments, x, y, width, height);
}
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferivproc = 0;
void APIENTRY glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value) {
	if (!glClearNamedFramebufferivproc) return;
	glClearNamedFramebufferivproc(framebuffer, buffer, drawbuffer, value);
}
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuivproc = 0;
void APIENTRY glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value) {
	if (!glClearNamedFramebufferuivproc) return;
	glClearNamedFramebufferuivproc(framebuffer, buffer, drawbuffer, value);
}
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfvproc = 0;
void APIENTRY glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value) {
	if (!glClearNamedFramebufferfvproc) return;
	glClearNamedFramebufferfvproc(framebuffer, buffer, drawbuffer, value);
}
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfiproc = 0;
void APIENTRY glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
	if (!glClearNamedFramebufferfiproc) return;
	glClearNamedFramebufferfiproc(framebuffer, buffer, drawbuffer, depth, stencil);
}
PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebufferproc = 0;
void APIENTRY glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	if (!glBlitNamedFramebufferproc) return;
	glBlitNamedFramebufferproc(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatusproc = 0;
GLenum APIENTRY glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) {
	if (!glCheckNamedFramebufferStatusproc) return 0;
	return glCheckNamedFramebufferStatusproc(framebuffer, target);
}
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameterivproc = 0;
void APIENTRY glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param) {
	if (!glGetNamedFramebufferParameterivproc) return;
	glGetNamedFramebufferParameterivproc(framebuffer, pname, param);
}
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameterivproc = 0;
void APIENTRY glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params) {
	if (!glGetNamedFramebufferAttachmentParameterivproc) return;
	glGetNamedFramebufferAttachmentParameterivproc(framebuffer, attachment, pname, params);
}
PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffersproc = 0;
void APIENTRY glCreateRenderbuffers(GLsizei n, GLuint* renderbuffers) {
	if (!glCreateRenderbuffersproc) return;
	glCreateRenderbuffersproc(n, renderbuffers);
}
PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorageproc = 0;
void APIENTRY glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glNamedRenderbufferStorageproc) return;
	glNamedRenderbufferStorageproc(renderbuffer, internalformat, width, height);
}
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisampleproc = 0;
void APIENTRY glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glNamedRenderbufferStorageMultisampleproc) return;
	glNamedRenderbufferStorageMultisampleproc(renderbuffer, samples, internalformat, width, height);
}
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameterivproc = 0;
void APIENTRY glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params) {
	if (!glGetNamedRenderbufferParameterivproc) return;
	glGetNamedRenderbufferParameterivproc(renderbuffer, pname, params);
}
PFNGLCREATETEXTURESPROC glCreateTexturesproc = 0;
void APIENTRY glCreateTextures(GLenum target, GLsizei n, GLuint* textures) {
	if (!glCreateTexturesproc) return;
	glCreateTexturesproc(target, n, textures);
}
PFNGLTEXTUREBUFFERPROC glTextureBufferproc = 0;
void APIENTRY glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) {
	if (!glTextureBufferproc) return;
	glTextureBufferproc(texture, internalformat, buffer);
}
PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRangeproc = 0;
void APIENTRY glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	if (!glTextureBufferRangeproc) return;
	glTextureBufferRangeproc(texture, internalformat, buffer, offset, size);
}
PFNGLTEXTURESTORAGE1DPROC glTextureStorage1Dproc = 0;
void APIENTRY glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) {
	if (!glTextureStorage1Dproc) return;
	glTextureStorage1Dproc(texture, levels, internalformat, width);
}
PFNGLTEXTURESTORAGE2DPROC glTextureStorage2Dproc = 0;
void APIENTRY glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glTextureStorage2Dproc) return;
	glTextureStorage2Dproc(texture, levels, internalformat, width, height);
}
PFNGLTEXTURESTORAGE3DPROC glTextureStorage3Dproc = 0;
void APIENTRY glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	if (!glTextureStorage3Dproc) return;
	glTextureStorage3Dproc(texture, levels, internalformat, width, height, depth);
}
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisampleproc = 0;
void APIENTRY glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	if (!glTextureStorage2DMultisampleproc) return;
	glTextureStorage2DMultisampleproc(texture, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisampleproc = 0;
void APIENTRY glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	if (!glTextureStorage3DMultisampleproc) return;
	glTextureStorage3DMultisampleproc(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1Dproc = 0;
void APIENTRY glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureSubImage1Dproc) return;
	glTextureSubImage1Dproc(texture, level, xoffset, width, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2Dproc = 0;
void APIENTRY glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureSubImage2Dproc) return;
	glTextureSubImage2Dproc(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3Dproc = 0;
void APIENTRY glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureSubImage3Dproc) return;
	glTextureSubImage3Dproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1Dproc = 0;
void APIENTRY glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTextureSubImage1Dproc) return;
	glCompressedTextureSubImage1Dproc(texture, level, xoffset, width, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2Dproc = 0;
void APIENTRY glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTextureSubImage2Dproc) return;
	glCompressedTextureSubImage2Dproc(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3Dproc = 0;
void APIENTRY glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTextureSubImage3Dproc) return;
	glCompressedTextureSubImage3Dproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1Dproc = 0;
void APIENTRY glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	if (!glCopyTextureSubImage1Dproc) return;
	glCopyTextureSubImage1Dproc(texture, level, xoffset, x, y, width);
}
PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2Dproc = 0;
void APIENTRY glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyTextureSubImage2Dproc) return;
	glCopyTextureSubImage2Dproc(texture, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3Dproc = 0;
void APIENTRY glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyTextureSubImage3Dproc) return;
	glCopyTextureSubImage3Dproc(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLTEXTUREPARAMETERFPROC glTextureParameterfproc = 0;
void APIENTRY glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) {
	if (!glTextureParameterfproc) return;
	glTextureParameterfproc(texture, pname, param);
}
PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfvproc = 0;
void APIENTRY glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param) {
	if (!glTextureParameterfvproc) return;
	glTextureParameterfvproc(texture, pname, param);
}
PFNGLTEXTUREPARAMETERIPROC glTextureParameteriproc = 0;
void APIENTRY glTextureParameteri(GLuint texture, GLenum pname, GLint param) {
	if (!glTextureParameteriproc) return;
	glTextureParameteriproc(texture, pname, param);
}
PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIivproc = 0;
void APIENTRY glTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params) {
	if (!glTextureParameterIivproc) return;
	glTextureParameterIivproc(texture, pname, params);
}
PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuivproc = 0;
void APIENTRY glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params) {
	if (!glTextureParameterIuivproc) return;
	glTextureParameterIuivproc(texture, pname, params);
}
PFNGLTEXTUREPARAMETERIVPROC glTextureParameterivproc = 0;
void APIENTRY glTextureParameteriv(GLuint texture, GLenum pname, const GLint* param) {
	if (!glTextureParameterivproc) return;
	glTextureParameterivproc(texture, pname, param);
}
PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmapproc = 0;
void APIENTRY glGenerateTextureMipmap(GLuint texture) {
	if (!glGenerateTextureMipmapproc) return;
	glGenerateTextureMipmapproc(texture);
}
PFNGLBINDTEXTUREUNITPROC glBindTextureUnitproc = 0;
void APIENTRY glBindTextureUnit(GLuint unit, GLuint texture) {
	if (!glBindTextureUnitproc) return;
	glBindTextureUnitproc(unit, texture);
}
PFNGLGETTEXTUREIMAGEPROC glGetTextureImageproc = 0;
void APIENTRY glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) {
	if (!glGetTextureImageproc) return;
	glGetTextureImageproc(texture, level, format, type, bufSize, pixels);
}
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImageproc = 0;
void APIENTRY glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels) {
	if (!glGetCompressedTextureImageproc) return;
	glGetCompressedTextureImageproc(texture, level, bufSize, pixels);
}
PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfvproc = 0;
void APIENTRY glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params) {
	if (!glGetTextureLevelParameterfvproc) return;
	glGetTextureLevelParameterfvproc(texture, level, pname, params);
}
PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameterivproc = 0;
void APIENTRY glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params) {
	if (!glGetTextureLevelParameterivproc) return;
	glGetTextureLevelParameterivproc(texture, level, pname, params);
}
PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfvproc = 0;
void APIENTRY glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params) {
	if (!glGetTextureParameterfvproc) return;
	glGetTextureParameterfvproc(texture, pname, params);
}
PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIivproc = 0;
void APIENTRY glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params) {
	if (!glGetTextureParameterIivproc) return;
	glGetTextureParameterIivproc(texture, pname, params);
}
PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuivproc = 0;
void APIENTRY glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params) {
	if (!glGetTextureParameterIuivproc) return;
	glGetTextureParameterIuivproc(texture, pname, params);
}
PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameterivproc = 0;
void APIENTRY glGetTextureParameteriv(GLuint texture, GLenum pname, GLint* params) {
	if (!glGetTextureParameterivproc) return;
	glGetTextureParameterivproc(texture, pname, params);
}
PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArraysproc = 0;
void APIENTRY glCreateVertexArrays(GLsizei n, GLuint* arrays) {
	if (!glCreateVertexArraysproc) return;
	glCreateVertexArraysproc(n, arrays);
}
PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttribproc = 0;
void APIENTRY glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) {
	if (!glDisableVertexArrayAttribproc) return;
	glDisableVertexArrayAttribproc(vaobj, index);
}
PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttribproc = 0;
void APIENTRY glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) {
	if (!glEnableVertexArrayAttribproc) return;
	glEnableVertexArrayAttribproc(vaobj, index);
}
PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBufferproc = 0;
void APIENTRY glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) {
	if (!glVertexArrayElementBufferproc) return;
	glVertexArrayElementBufferproc(vaobj, buffer);
}
PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBufferproc = 0;
void APIENTRY glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
	if (!glVertexArrayVertexBufferproc) return;
	glVertexArrayVertexBufferproc(vaobj, bindingindex, buffer, offset, stride);
}
PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffersproc = 0;
void APIENTRY glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) {
	if (!glVertexArrayVertexBuffersproc) return;
	glVertexArrayVertexBuffersproc(vaobj, first, count, buffers, offsets, strides);
}
PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBindingproc = 0;
void APIENTRY glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
	if (!glVertexArrayAttribBindingproc) return;
	glVertexArrayAttribBindingproc(vaobj, attribindex, bindingindex);
}
PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormatproc = 0;
void APIENTRY glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
	if (!glVertexArrayAttribFormatproc) return;
	glVertexArrayAttribFormatproc(vaobj, attribindex, size, type, normalized, relativeoffset);
}
PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormatproc = 0;
void APIENTRY glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	if (!glVertexArrayAttribIFormatproc) return;
	glVertexArrayAttribIFormatproc(vaobj, attribindex, size, type, relativeoffset);
}
PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormatproc = 0;
void APIENTRY glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	if (!glVertexArrayAttribLFormatproc) return;
	glVertexArrayAttribLFormatproc(vaobj, attribindex, size, type, relativeoffset);
}
PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisorproc = 0;
void APIENTRY glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
	if (!glVertexArrayBindingDivisorproc) return;
	glVertexArrayBindingDivisorproc(vaobj, bindingindex, divisor);
}
PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayivproc = 0;
void APIENTRY glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param) {
	if (!glGetVertexArrayivproc) return;
	glGetVertexArrayivproc(vaobj, pname, param);
}
PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexedivproc = 0;
void APIENTRY glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param) {
	if (!glGetVertexArrayIndexedivproc) return;
	glGetVertexArrayIndexedivproc(vaobj, index, pname, param);
}
PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64ivproc = 0;
void APIENTRY glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param) {
	if (!glGetVertexArrayIndexed64ivproc) return;
	glGetVertexArrayIndexed64ivproc(vaobj, index, pname, param);
}
PFNGLCREATESAMPLERSPROC glCreateSamplersproc = 0;
void APIENTRY glCreateSamplers(GLsizei n, GLuint* samplers) {
	if (!glCreateSamplersproc) return;
	glCreateSamplersproc(n, samplers);
}
PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelinesproc = 0;
void APIENTRY glCreateProgramPipelines(GLsizei n, GLuint* pipelines) {
	if (!glCreateProgramPipelinesproc) return;
	glCreateProgramPipelinesproc(n, pipelines);
}
PFNGLCREATEQUERIESPROC glCreateQueriesproc = 0;
void APIENTRY glCreateQueries(GLenum target, GLsizei n, GLuint* ids) {
	if (!glCreateQueriesproc) return;
	glCreateQueriesproc(target, n, ids);
}
PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64vproc = 0;
void APIENTRY glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	if (!glGetQueryBufferObjecti64vproc) return;
	glGetQueryBufferObjecti64vproc(id, buffer, pname, offset);
}
PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectivproc = 0;
void APIENTRY glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	if (!glGetQueryBufferObjectivproc) return;
	glGetQueryBufferObjectivproc(id, buffer, pname, offset);
}
PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64vproc = 0;
void APIENTRY glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	if (!glGetQueryBufferObjectui64vproc) return;
	glGetQueryBufferObjectui64vproc(id, buffer, pname, offset);
}
PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuivproc = 0;
void APIENTRY glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
	if (!glGetQueryBufferObjectuivproc) return;
	glGetQueryBufferObjectuivproc(id, buffer, pname, offset);
}
PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegionproc = 0;
void APIENTRY glMemoryBarrierByRegion(GLbitfield barriers) {
	if (!glMemoryBarrierByRegionproc) return;
	glMemoryBarrierByRegionproc(barriers);
}
PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImageproc = 0;
void APIENTRY glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels) {
	if (!glGetTextureSubImageproc) return;
	glGetTextureSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImageproc = 0;
void APIENTRY glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels) {
	if (!glGetCompressedTextureSubImageproc) return;
	glGetCompressedTextureSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}
PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatusproc = 0;
GLenum APIENTRY glGetGraphicsResetStatus(void) {
	if (!glGetGraphicsResetStatusproc) return 0;
	return glGetGraphicsResetStatusproc();
}
PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImageproc = 0;
void APIENTRY glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels) {
	if (!glGetnCompressedTexImageproc) return;
	glGetnCompressedTexImageproc(target, lod, bufSize, pixels);
}
PFNGLGETNTEXIMAGEPROC glGetnTexImageproc = 0;
void APIENTRY glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) {
	if (!glGetnTexImageproc) return;
	glGetnTexImageproc(target, level, format, type, bufSize, pixels);
}
PFNGLGETNUNIFORMDVPROC glGetnUniformdvproc = 0;
void APIENTRY glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) {
	if (!glGetnUniformdvproc) return;
	glGetnUniformdvproc(program, location, bufSize, params);
}
PFNGLGETNUNIFORMFVPROC glGetnUniformfvproc = 0;
void APIENTRY glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) {
	if (!glGetnUniformfvproc) return;
	glGetnUniformfvproc(program, location, bufSize, params);
}
PFNGLGETNUNIFORMIVPROC glGetnUniformivproc = 0;
void APIENTRY glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params) {
	if (!glGetnUniformivproc) return;
	glGetnUniformivproc(program, location, bufSize, params);
}
PFNGLGETNUNIFORMUIVPROC glGetnUniformuivproc = 0;
void APIENTRY glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params) {
	if (!glGetnUniformuivproc) return;
	glGetnUniformuivproc(program, location, bufSize, params);
}
PFNGLREADNPIXELSPROC glReadnPixelsproc = 0;
void APIENTRY glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) {
	if (!glReadnPixelsproc) return;
	glReadnPixelsproc(x, y, width, height, format, type, bufSize, data);
}
PFNGLGETNMAPDVPROC glGetnMapdvproc = 0;
void APIENTRY glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v) {
	if (!glGetnMapdvproc) return;
	glGetnMapdvproc(target, query, bufSize, v);
}
PFNGLGETNMAPFVPROC glGetnMapfvproc = 0;
void APIENTRY glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v) {
	if (!glGetnMapfvproc) return;
	glGetnMapfvproc(target, query, bufSize, v);
}
PFNGLGETNMAPIVPROC glGetnMapivproc = 0;
void APIENTRY glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint* v) {
	if (!glGetnMapivproc) return;
	glGetnMapivproc(target, query, bufSize, v);
}
PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfvproc = 0;
void APIENTRY glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat* values) {
	if (!glGetnPixelMapfvproc) return;
	glGetnPixelMapfvproc(map, bufSize, values);
}
PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuivproc = 0;
void APIENTRY glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint* values) {
	if (!glGetnPixelMapuivproc) return;
	glGetnPixelMapuivproc(map, bufSize, values);
}
PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusvproc = 0;
void APIENTRY glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort* values) {
	if (!glGetnPixelMapusvproc) return;
	glGetnPixelMapusvproc(map, bufSize, values);
}
PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStippleproc = 0;
void APIENTRY glGetnPolygonStipple(GLsizei bufSize, GLubyte* pattern) {
	if (!glGetnPolygonStippleproc) return;
	glGetnPolygonStippleproc(bufSize, pattern);
}
PFNGLGETNCOLORTABLEPROC glGetnColorTableproc = 0;
void APIENTRY glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table) {
	if (!glGetnColorTableproc) return;
	glGetnColorTableproc(target, format, type, bufSize, table);
}
PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilterproc = 0;
void APIENTRY glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image) {
	if (!glGetnConvolutionFilterproc) return;
	glGetnConvolutionFilterproc(target, format, type, bufSize, image);
}
PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilterproc = 0;
void APIENTRY glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, void* column, void* span) {
	if (!glGetnSeparableFilterproc) return;
	glGetnSeparableFilterproc(target, format, type, rowBufSize, row, columnBufSize, column, span);
}
PFNGLGETNHISTOGRAMPROC glGetnHistogramproc = 0;
void APIENTRY glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) {
	if (!glGetnHistogramproc) return;
	glGetnHistogramproc(target, reset, format, type, bufSize, values);
}
PFNGLGETNMINMAXPROC glGetnMinmaxproc = 0;
void APIENTRY glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) {
	if (!glGetnMinmaxproc) return;
	glGetnMinmaxproc(target, reset, format, type, bufSize, values);
}
PFNGLTEXTUREBARRIERPROC glTextureBarrierproc = 0;
void APIENTRY glTextureBarrier(void) {
	if (!glTextureBarrierproc) return;
	glTextureBarrierproc();
}
PFNGLSPECIALIZESHADERPROC glSpecializeShaderproc = 0;
void APIENTRY glSpecializeShader(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue) {
	if (!glSpecializeShaderproc) return;
	glSpecializeShaderproc(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCountproc = 0;
void APIENTRY glMultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
	if (!glMultiDrawArraysIndirectCountproc) return;
	glMultiDrawArraysIndirectCountproc(mode, indirect, drawcount, maxdrawcount, stride);
}
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCountproc = 0;
void APIENTRY glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
	if (!glMultiDrawElementsIndirectCountproc) return;
	glMultiDrawElementsIndirectCountproc(mode, type, indirect, drawcount, maxdrawcount, stride);
}
PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClampproc = 0;
void APIENTRY glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) {
	if (!glPolygonOffsetClampproc) return;
	glPolygonOffsetClampproc(factor, units, clamp);
}
PFNGLPRIMITIVEBOUNDINGBOXARBPROC glPrimitiveBoundingBoxARBproc = 0;
void APIENTRY glPrimitiveBoundingBoxARB(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
	if (!glPrimitiveBoundingBoxARBproc) return;
	glPrimitiveBoundingBoxARBproc(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
PFNGLGETTEXTUREHANDLEARBPROC glGetTextureHandleARBproc = 0;
GLuint64 APIENTRY glGetTextureHandleARB(GLuint texture) {
	if (!glGetTextureHandleARBproc) return 0;
	return glGetTextureHandleARBproc(texture);
}
PFNGLGETTEXTURESAMPLERHANDLEARBPROC glGetTextureSamplerHandleARBproc = 0;
GLuint64 APIENTRY glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler) {
	if (!glGetTextureSamplerHandleARBproc) return 0;
	return glGetTextureSamplerHandleARBproc(texture, sampler);
}
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC glMakeTextureHandleResidentARBproc = 0;
void APIENTRY glMakeTextureHandleResidentARB(GLuint64 handle) {
	if (!glMakeTextureHandleResidentARBproc) return;
	glMakeTextureHandleResidentARBproc(handle);
}
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC glMakeTextureHandleNonResidentARBproc = 0;
void APIENTRY glMakeTextureHandleNonResidentARB(GLuint64 handle) {
	if (!glMakeTextureHandleNonResidentARBproc) return;
	glMakeTextureHandleNonResidentARBproc(handle);
}
PFNGLGETIMAGEHANDLEARBPROC glGetImageHandleARBproc = 0;
GLuint64 APIENTRY glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) {
	if (!glGetImageHandleARBproc) return 0;
	return glGetImageHandleARBproc(texture, level, layered, layer, format);
}
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC glMakeImageHandleResidentARBproc = 0;
void APIENTRY glMakeImageHandleResidentARB(GLuint64 handle, GLenum access) {
	if (!glMakeImageHandleResidentARBproc) return;
	glMakeImageHandleResidentARBproc(handle, access);
}
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC glMakeImageHandleNonResidentARBproc = 0;
void APIENTRY glMakeImageHandleNonResidentARB(GLuint64 handle) {
	if (!glMakeImageHandleNonResidentARBproc) return;
	glMakeImageHandleNonResidentARBproc(handle);
}
PFNGLUNIFORMHANDLEUI64ARBPROC glUniformHandleui64ARBproc = 0;
void APIENTRY glUniformHandleui64ARB(GLint location, GLuint64 value) {
	if (!glUniformHandleui64ARBproc) return;
	glUniformHandleui64ARBproc(location, value);
}
PFNGLUNIFORMHANDLEUI64VARBPROC glUniformHandleui64vARBproc = 0;
void APIENTRY glUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value) {
	if (!glUniformHandleui64vARBproc) return;
	glUniformHandleui64vARBproc(location, count, value);
}
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC glProgramUniformHandleui64ARBproc = 0;
void APIENTRY glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value) {
	if (!glProgramUniformHandleui64ARBproc) return;
	glProgramUniformHandleui64ARBproc(program, location, value);
}
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC glProgramUniformHandleui64vARBproc = 0;
void APIENTRY glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* values) {
	if (!glProgramUniformHandleui64vARBproc) return;
	glProgramUniformHandleui64vARBproc(program, location, count, values);
}
PFNGLISTEXTUREHANDLERESIDENTARBPROC glIsTextureHandleResidentARBproc = 0;
GLboolean APIENTRY glIsTextureHandleResidentARB(GLuint64 handle) {
	if (!glIsTextureHandleResidentARBproc) return 0;
	return glIsTextureHandleResidentARBproc(handle);
}
PFNGLISIMAGEHANDLERESIDENTARBPROC glIsImageHandleResidentARBproc = 0;
GLboolean APIENTRY glIsImageHandleResidentARB(GLuint64 handle) {
	if (!glIsImageHandleResidentARBproc) return 0;
	return glIsImageHandleResidentARBproc(handle);
}
PFNGLVERTEXATTRIBL1UI64ARBPROC glVertexAttribL1ui64ARBproc = 0;
void APIENTRY glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x) {
	if (!glVertexAttribL1ui64ARBproc) return;
	glVertexAttribL1ui64ARBproc(index, x);
}
PFNGLVERTEXATTRIBL1UI64VARBPROC glVertexAttribL1ui64vARBproc = 0;
void APIENTRY glVertexAttribL1ui64vARB(GLuint index, const GLuint64EXT* v) {
	if (!glVertexAttribL1ui64vARBproc) return;
	glVertexAttribL1ui64vARBproc(index, v);
}
PFNGLGETVERTEXATTRIBLUI64VARBPROC glGetVertexAttribLui64vARBproc = 0;
void APIENTRY glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT* params) {
	if (!glGetVertexAttribLui64vARBproc) return;
	glGetVertexAttribLui64vARBproc(index, pname, params);
}
PFNGLCREATESYNCFROMCLEVENTARBPROC glCreateSyncFromCLeventARBproc = 0;
GLsync APIENTRY glCreateSyncFromCLeventARB(struct _cl_context* context, struct _cl_event* event, GLbitfield flags) {
	if (!glCreateSyncFromCLeventARBproc) return 0;
	return glCreateSyncFromCLeventARBproc(context, event, flags);
}
PFNGLCLAMPCOLORARBPROC glClampColorARBproc = 0;
void APIENTRY glClampColorARB(GLenum target, GLenum clamp) {
	if (!glClampColorARBproc) return;
	glClampColorARBproc(target, clamp);
}
PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC glDispatchComputeGroupSizeARBproc = 0;
void APIENTRY glDispatchComputeGroupSizeARB(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z) {
	if (!glDispatchComputeGroupSizeARBproc) return;
	glDispatchComputeGroupSizeARBproc(num_groups_x, num_groups_y, num_groups_z, group_size_x, group_size_y, group_size_z);
}
PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARBproc = 0;
void APIENTRY glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) {
	if (!glDebugMessageControlARBproc) return;
	glDebugMessageControlARBproc(source, type, severity, count, ids, enabled);
}
PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARBproc = 0;
void APIENTRY glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf) {
	if (!glDebugMessageInsertARBproc) return;
	glDebugMessageInsertARBproc(source, type, id, severity, length, buf);
}
PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARBproc = 0;
void APIENTRY glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void* userParam) {
	if (!glDebugMessageCallbackARBproc) return;
	glDebugMessageCallbackARBproc(callback, userParam);
}
PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARBproc = 0;
GLuint APIENTRY glGetDebugMessageLogARB(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog) {
	if (!glGetDebugMessageLogARBproc) return 0;
	return glGetDebugMessageLogARBproc(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
PFNGLDRAWBUFFERSARBPROC glDrawBuffersARBproc = 0;
void APIENTRY glDrawBuffersARB(GLsizei n, const GLenum* bufs) {
	if (!glDrawBuffersARBproc) return;
	glDrawBuffersARBproc(n, bufs);
}
PFNGLBLENDEQUATIONIARBPROC glBlendEquationiARBproc = 0;
void APIENTRY glBlendEquationiARB(GLuint buf, GLenum mode) {
	if (!glBlendEquationiARBproc) return;
	glBlendEquationiARBproc(buf, mode);
}
PFNGLBLENDEQUATIONSEPARATEIARBPROC glBlendEquationSeparateiARBproc = 0;
void APIENTRY glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	if (!glBlendEquationSeparateiARBproc) return;
	glBlendEquationSeparateiARBproc(buf, modeRGB, modeAlpha);
}
PFNGLBLENDFUNCIARBPROC glBlendFunciARBproc = 0;
void APIENTRY glBlendFunciARB(GLuint buf, GLenum src, GLenum dst) {
	if (!glBlendFunciARBproc) return;
	glBlendFunciARBproc(buf, src, dst);
}
PFNGLBLENDFUNCSEPARATEIARBPROC glBlendFuncSeparateiARBproc = 0;
void APIENTRY glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	if (!glBlendFuncSeparateiARBproc) return;
	glBlendFuncSeparateiARBproc(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
PFNGLDRAWARRAYSINSTANCEDARBPROC glDrawArraysInstancedARBproc = 0;
void APIENTRY glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
	if (!glDrawArraysInstancedARBproc) return;
	glDrawArraysInstancedARBproc(mode, first, count, primcount);
}
PFNGLDRAWELEMENTSINSTANCEDARBPROC glDrawElementsInstancedARBproc = 0;
void APIENTRY glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount) {
	if (!glDrawElementsInstancedARBproc) return;
	glDrawElementsInstancedARBproc(mode, count, type, indices, primcount);
}
PFNGLPROGRAMSTRINGARBPROC glProgramStringARBproc = 0;
void APIENTRY glProgramStringARB(GLenum target, GLenum format, GLsizei len, const void* string) {
	if (!glProgramStringARBproc) return;
	glProgramStringARBproc(target, format, len, string);
}
PFNGLBINDPROGRAMARBPROC glBindProgramARBproc = 0;
void APIENTRY glBindProgramARB(GLenum target, GLuint program) {
	if (!glBindProgramARBproc) return;
	glBindProgramARBproc(target, program);
}
PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARBproc = 0;
void APIENTRY glDeleteProgramsARB(GLsizei n, const GLuint* programs) {
	if (!glDeleteProgramsARBproc) return;
	glDeleteProgramsARBproc(n, programs);
}
PFNGLGENPROGRAMSARBPROC glGenProgramsARBproc = 0;
void APIENTRY glGenProgramsARB(GLsizei n, GLuint* programs) {
	if (!glGenProgramsARBproc) return;
	glGenProgramsARBproc(n, programs);
}
PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARBproc = 0;
void APIENTRY glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glProgramEnvParameter4dARBproc) return;
	glProgramEnvParameter4dARBproc(target, index, x, y, z, w);
}
PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARBproc = 0;
void APIENTRY glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble* params) {
	if (!glProgramEnvParameter4dvARBproc) return;
	glProgramEnvParameter4dvARBproc(target, index, params);
}
PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARBproc = 0;
void APIENTRY glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glProgramEnvParameter4fARBproc) return;
	glProgramEnvParameter4fARBproc(target, index, x, y, z, w);
}
PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARBproc = 0;
void APIENTRY glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat* params) {
	if (!glProgramEnvParameter4fvARBproc) return;
	glProgramEnvParameter4fvARBproc(target, index, params);
}
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARBproc = 0;
void APIENTRY glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glProgramLocalParameter4dARBproc) return;
	glProgramLocalParameter4dARBproc(target, index, x, y, z, w);
}
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARBproc = 0;
void APIENTRY glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble* params) {
	if (!glProgramLocalParameter4dvARBproc) return;
	glProgramLocalParameter4dvARBproc(target, index, params);
}
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARBproc = 0;
void APIENTRY glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glProgramLocalParameter4fARBproc) return;
	glProgramLocalParameter4fARBproc(target, index, x, y, z, w);
}
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARBproc = 0;
void APIENTRY glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat* params) {
	if (!glProgramLocalParameter4fvARBproc) return;
	glProgramLocalParameter4fvARBproc(target, index, params);
}
PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARBproc = 0;
void APIENTRY glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble* params) {
	if (!glGetProgramEnvParameterdvARBproc) return;
	glGetProgramEnvParameterdvARBproc(target, index, params);
}
PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARBproc = 0;
void APIENTRY glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat* params) {
	if (!glGetProgramEnvParameterfvARBproc) return;
	glGetProgramEnvParameterfvARBproc(target, index, params);
}
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARBproc = 0;
void APIENTRY glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble* params) {
	if (!glGetProgramLocalParameterdvARBproc) return;
	glGetProgramLocalParameterdvARBproc(target, index, params);
}
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARBproc = 0;
void APIENTRY glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat* params) {
	if (!glGetProgramLocalParameterfvARBproc) return;
	glGetProgramLocalParameterfvARBproc(target, index, params);
}
PFNGLGETPROGRAMIVARBPROC glGetProgramivARBproc = 0;
void APIENTRY glGetProgramivARB(GLenum target, GLenum pname, GLint* params) {
	if (!glGetProgramivARBproc) return;
	glGetProgramivARBproc(target, pname, params);
}
PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARBproc = 0;
void APIENTRY glGetProgramStringARB(GLenum target, GLenum pname, void* string) {
	if (!glGetProgramStringARBproc) return;
	glGetProgramStringARBproc(target, pname, string);
}
PFNGLISPROGRAMARBPROC glIsProgramARBproc = 0;
GLboolean APIENTRY glIsProgramARB(GLuint program) {
	if (!glIsProgramARBproc) return 0;
	return glIsProgramARBproc(program);
}
PFNGLPROGRAMPARAMETERIARBPROC glProgramParameteriARBproc = 0;
void APIENTRY glProgramParameteriARB(GLuint program, GLenum pname, GLint value) {
	if (!glProgramParameteriARBproc) return;
	glProgramParameteriARBproc(program, pname, value);
}
PFNGLFRAMEBUFFERTEXTUREARBPROC glFramebufferTextureARBproc = 0;
void APIENTRY glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	if (!glFramebufferTextureARBproc) return;
	glFramebufferTextureARBproc(target, attachment, texture, level);
}
PFNGLFRAMEBUFFERTEXTURELAYERARBPROC glFramebufferTextureLayerARBproc = 0;
void APIENTRY glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	if (!glFramebufferTextureLayerARBproc) return;
	glFramebufferTextureLayerARBproc(target, attachment, texture, level, layer);
}
PFNGLFRAMEBUFFERTEXTUREFACEARBPROC glFramebufferTextureFaceARBproc = 0;
void APIENTRY glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
	if (!glFramebufferTextureFaceARBproc) return;
	glFramebufferTextureFaceARBproc(target, attachment, texture, level, face);
}
PFNGLSPECIALIZESHADERARBPROC glSpecializeShaderARBproc = 0;
void APIENTRY glSpecializeShaderARB(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue) {
	if (!glSpecializeShaderARBproc) return;
	glSpecializeShaderARBproc(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}
PFNGLUNIFORM1I64ARBPROC glUniform1i64ARBproc = 0;
void APIENTRY glUniform1i64ARB(GLint location, GLint64 x) {
	if (!glUniform1i64ARBproc) return;
	glUniform1i64ARBproc(location, x);
}
PFNGLUNIFORM2I64ARBPROC glUniform2i64ARBproc = 0;
void APIENTRY glUniform2i64ARB(GLint location, GLint64 x, GLint64 y) {
	if (!glUniform2i64ARBproc) return;
	glUniform2i64ARBproc(location, x, y);
}
PFNGLUNIFORM3I64ARBPROC glUniform3i64ARBproc = 0;
void APIENTRY glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z) {
	if (!glUniform3i64ARBproc) return;
	glUniform3i64ARBproc(location, x, y, z);
}
PFNGLUNIFORM4I64ARBPROC glUniform4i64ARBproc = 0;
void APIENTRY glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) {
	if (!glUniform4i64ARBproc) return;
	glUniform4i64ARBproc(location, x, y, z, w);
}
PFNGLUNIFORM1I64VARBPROC glUniform1i64vARBproc = 0;
void APIENTRY glUniform1i64vARB(GLint location, GLsizei count, const GLint64* value) {
	if (!glUniform1i64vARBproc) return;
	glUniform1i64vARBproc(location, count, value);
}
PFNGLUNIFORM2I64VARBPROC glUniform2i64vARBproc = 0;
void APIENTRY glUniform2i64vARB(GLint location, GLsizei count, const GLint64* value) {
	if (!glUniform2i64vARBproc) return;
	glUniform2i64vARBproc(location, count, value);
}
PFNGLUNIFORM3I64VARBPROC glUniform3i64vARBproc = 0;
void APIENTRY glUniform3i64vARB(GLint location, GLsizei count, const GLint64* value) {
	if (!glUniform3i64vARBproc) return;
	glUniform3i64vARBproc(location, count, value);
}
PFNGLUNIFORM4I64VARBPROC glUniform4i64vARBproc = 0;
void APIENTRY glUniform4i64vARB(GLint location, GLsizei count, const GLint64* value) {
	if (!glUniform4i64vARBproc) return;
	glUniform4i64vARBproc(location, count, value);
}
PFNGLUNIFORM1UI64ARBPROC glUniform1ui64ARBproc = 0;
void APIENTRY glUniform1ui64ARB(GLint location, GLuint64 x) {
	if (!glUniform1ui64ARBproc) return;
	glUniform1ui64ARBproc(location, x);
}
PFNGLUNIFORM2UI64ARBPROC glUniform2ui64ARBproc = 0;
void APIENTRY glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y) {
	if (!glUniform2ui64ARBproc) return;
	glUniform2ui64ARBproc(location, x, y);
}
PFNGLUNIFORM3UI64ARBPROC glUniform3ui64ARBproc = 0;
void APIENTRY glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z) {
	if (!glUniform3ui64ARBproc) return;
	glUniform3ui64ARBproc(location, x, y, z);
}
PFNGLUNIFORM4UI64ARBPROC glUniform4ui64ARBproc = 0;
void APIENTRY glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) {
	if (!glUniform4ui64ARBproc) return;
	glUniform4ui64ARBproc(location, x, y, z, w);
}
PFNGLUNIFORM1UI64VARBPROC glUniform1ui64vARBproc = 0;
void APIENTRY glUniform1ui64vARB(GLint location, GLsizei count, const GLuint64* value) {
	if (!glUniform1ui64vARBproc) return;
	glUniform1ui64vARBproc(location, count, value);
}
PFNGLUNIFORM2UI64VARBPROC glUniform2ui64vARBproc = 0;
void APIENTRY glUniform2ui64vARB(GLint location, GLsizei count, const GLuint64* value) {
	if (!glUniform2ui64vARBproc) return;
	glUniform2ui64vARBproc(location, count, value);
}
PFNGLUNIFORM3UI64VARBPROC glUniform3ui64vARBproc = 0;
void APIENTRY glUniform3ui64vARB(GLint location, GLsizei count, const GLuint64* value) {
	if (!glUniform3ui64vARBproc) return;
	glUniform3ui64vARBproc(location, count, value);
}
PFNGLUNIFORM4UI64VARBPROC glUniform4ui64vARBproc = 0;
void APIENTRY glUniform4ui64vARB(GLint location, GLsizei count, const GLuint64* value) {
	if (!glUniform4ui64vARBproc) return;
	glUniform4ui64vARBproc(location, count, value);
}
PFNGLGETUNIFORMI64VARBPROC glGetUniformi64vARBproc = 0;
void APIENTRY glGetUniformi64vARB(GLuint program, GLint location, GLint64* params) {
	if (!glGetUniformi64vARBproc) return;
	glGetUniformi64vARBproc(program, location, params);
}
PFNGLGETUNIFORMUI64VARBPROC glGetUniformui64vARBproc = 0;
void APIENTRY glGetUniformui64vARB(GLuint program, GLint location, GLuint64* params) {
	if (!glGetUniformui64vARBproc) return;
	glGetUniformui64vARBproc(program, location, params);
}
PFNGLGETNUNIFORMI64VARBPROC glGetnUniformi64vARBproc = 0;
void APIENTRY glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64* params) {
	if (!glGetnUniformi64vARBproc) return;
	glGetnUniformi64vARBproc(program, location, bufSize, params);
}
PFNGLGETNUNIFORMUI64VARBPROC glGetnUniformui64vARBproc = 0;
void APIENTRY glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64* params) {
	if (!glGetnUniformui64vARBproc) return;
	glGetnUniformui64vARBproc(program, location, bufSize, params);
}
PFNGLPROGRAMUNIFORM1I64ARBPROC glProgramUniform1i64ARBproc = 0;
void APIENTRY glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x) {
	if (!glProgramUniform1i64ARBproc) return;
	glProgramUniform1i64ARBproc(program, location, x);
}
PFNGLPROGRAMUNIFORM2I64ARBPROC glProgramUniform2i64ARBproc = 0;
void APIENTRY glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y) {
	if (!glProgramUniform2i64ARBproc) return;
	glProgramUniform2i64ARBproc(program, location, x, y);
}
PFNGLPROGRAMUNIFORM3I64ARBPROC glProgramUniform3i64ARBproc = 0;
void APIENTRY glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z) {
	if (!glProgramUniform3i64ARBproc) return;
	glProgramUniform3i64ARBproc(program, location, x, y, z);
}
PFNGLPROGRAMUNIFORM4I64ARBPROC glProgramUniform4i64ARBproc = 0;
void APIENTRY glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) {
	if (!glProgramUniform4i64ARBproc) return;
	glProgramUniform4i64ARBproc(program, location, x, y, z, w);
}
PFNGLPROGRAMUNIFORM1I64VARBPROC glProgramUniform1i64vARBproc = 0;
void APIENTRY glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value) {
	if (!glProgramUniform1i64vARBproc) return;
	glProgramUniform1i64vARBproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2I64VARBPROC glProgramUniform2i64vARBproc = 0;
void APIENTRY glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value) {
	if (!glProgramUniform2i64vARBproc) return;
	glProgramUniform2i64vARBproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3I64VARBPROC glProgramUniform3i64vARBproc = 0;
void APIENTRY glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value) {
	if (!glProgramUniform3i64vARBproc) return;
	glProgramUniform3i64vARBproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4I64VARBPROC glProgramUniform4i64vARBproc = 0;
void APIENTRY glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value) {
	if (!glProgramUniform4i64vARBproc) return;
	glProgramUniform4i64vARBproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1UI64ARBPROC glProgramUniform1ui64ARBproc = 0;
void APIENTRY glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x) {
	if (!glProgramUniform1ui64ARBproc) return;
	glProgramUniform1ui64ARBproc(program, location, x);
}
PFNGLPROGRAMUNIFORM2UI64ARBPROC glProgramUniform2ui64ARBproc = 0;
void APIENTRY glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y) {
	if (!glProgramUniform2ui64ARBproc) return;
	glProgramUniform2ui64ARBproc(program, location, x, y);
}
PFNGLPROGRAMUNIFORM3UI64ARBPROC glProgramUniform3ui64ARBproc = 0;
void APIENTRY glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z) {
	if (!glProgramUniform3ui64ARBproc) return;
	glProgramUniform3ui64ARBproc(program, location, x, y, z);
}
PFNGLPROGRAMUNIFORM4UI64ARBPROC glProgramUniform4ui64ARBproc = 0;
void APIENTRY glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) {
	if (!glProgramUniform4ui64ARBproc) return;
	glProgramUniform4ui64ARBproc(program, location, x, y, z, w);
}
PFNGLPROGRAMUNIFORM1UI64VARBPROC glProgramUniform1ui64vARBproc = 0;
void APIENTRY glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value) {
	if (!glProgramUniform1ui64vARBproc) return;
	glProgramUniform1ui64vARBproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2UI64VARBPROC glProgramUniform2ui64vARBproc = 0;
void APIENTRY glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value) {
	if (!glProgramUniform2ui64vARBproc) return;
	glProgramUniform2ui64vARBproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3UI64VARBPROC glProgramUniform3ui64vARBproc = 0;
void APIENTRY glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value) {
	if (!glProgramUniform3ui64vARBproc) return;
	glProgramUniform3ui64vARBproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4UI64VARBPROC glProgramUniform4ui64vARBproc = 0;
void APIENTRY glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value) {
	if (!glProgramUniform4ui64vARBproc) return;
	glProgramUniform4ui64vARBproc(program, location, count, value);
}
PFNGLCOLORTABLEPROC glColorTableproc = 0;
void APIENTRY glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* table) {
	if (!glColorTableproc) return;
	glColorTableproc(target, internalformat, width, format, type, table);
}
PFNGLCOLORTABLEPARAMETERFVPROC glColorTableParameterfvproc = 0;
void APIENTRY glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat* params) {
	if (!glColorTableParameterfvproc) return;
	glColorTableParameterfvproc(target, pname, params);
}
PFNGLCOLORTABLEPARAMETERIVPROC glColorTableParameterivproc = 0;
void APIENTRY glColorTableParameteriv(GLenum target, GLenum pname, const GLint* params) {
	if (!glColorTableParameterivproc) return;
	glColorTableParameterivproc(target, pname, params);
}
PFNGLCOPYCOLORTABLEPROC glCopyColorTableproc = 0;
void APIENTRY glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
	if (!glCopyColorTableproc) return;
	glCopyColorTableproc(target, internalformat, x, y, width);
}
PFNGLGETCOLORTABLEPROC glGetColorTableproc = 0;
void APIENTRY glGetColorTable(GLenum target, GLenum format, GLenum type, void* table) {
	if (!glGetColorTableproc) return;
	glGetColorTableproc(target, format, type, table);
}
PFNGLGETCOLORTABLEPARAMETERFVPROC glGetColorTableParameterfvproc = 0;
void APIENTRY glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetColorTableParameterfvproc) return;
	glGetColorTableParameterfvproc(target, pname, params);
}
PFNGLGETCOLORTABLEPARAMETERIVPROC glGetColorTableParameterivproc = 0;
void APIENTRY glGetColorTableParameteriv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetColorTableParameterivproc) return;
	glGetColorTableParameterivproc(target, pname, params);
}
PFNGLCOLORSUBTABLEPROC glColorSubTableproc = 0;
void APIENTRY glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void* data) {
	if (!glColorSubTableproc) return;
	glColorSubTableproc(target, start, count, format, type, data);
}
PFNGLCOPYCOLORSUBTABLEPROC glCopyColorSubTableproc = 0;
void APIENTRY glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
	if (!glCopyColorSubTableproc) return;
	glCopyColorSubTableproc(target, start, x, y, width);
}
PFNGLCONVOLUTIONFILTER1DPROC glConvolutionFilter1Dproc = 0;
void APIENTRY glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* image) {
	if (!glConvolutionFilter1Dproc) return;
	glConvolutionFilter1Dproc(target, internalformat, width, format, type, image);
}
PFNGLCONVOLUTIONFILTER2DPROC glConvolutionFilter2Dproc = 0;
void APIENTRY glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* image) {
	if (!glConvolutionFilter2Dproc) return;
	glConvolutionFilter2Dproc(target, internalformat, width, height, format, type, image);
}
PFNGLCONVOLUTIONPARAMETERFPROC glConvolutionParameterfproc = 0;
void APIENTRY glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
	if (!glConvolutionParameterfproc) return;
	glConvolutionParameterfproc(target, pname, params);
}
PFNGLCONVOLUTIONPARAMETERFVPROC glConvolutionParameterfvproc = 0;
void APIENTRY glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat* params) {
	if (!glConvolutionParameterfvproc) return;
	glConvolutionParameterfvproc(target, pname, params);
}
PFNGLCONVOLUTIONPARAMETERIPROC glConvolutionParameteriproc = 0;
void APIENTRY glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
	if (!glConvolutionParameteriproc) return;
	glConvolutionParameteriproc(target, pname, params);
}
PFNGLCONVOLUTIONPARAMETERIVPROC glConvolutionParameterivproc = 0;
void APIENTRY glConvolutionParameteriv(GLenum target, GLenum pname, const GLint* params) {
	if (!glConvolutionParameterivproc) return;
	glConvolutionParameterivproc(target, pname, params);
}
PFNGLCOPYCONVOLUTIONFILTER1DPROC glCopyConvolutionFilter1Dproc = 0;
void APIENTRY glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
	if (!glCopyConvolutionFilter1Dproc) return;
	glCopyConvolutionFilter1Dproc(target, internalformat, x, y, width);
}
PFNGLCOPYCONVOLUTIONFILTER2DPROC glCopyConvolutionFilter2Dproc = 0;
void APIENTRY glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyConvolutionFilter2Dproc) return;
	glCopyConvolutionFilter2Dproc(target, internalformat, x, y, width, height);
}
PFNGLGETCONVOLUTIONFILTERPROC glGetConvolutionFilterproc = 0;
void APIENTRY glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, void* image) {
	if (!glGetConvolutionFilterproc) return;
	glGetConvolutionFilterproc(target, format, type, image);
}
PFNGLGETCONVOLUTIONPARAMETERFVPROC glGetConvolutionParameterfvproc = 0;
void APIENTRY glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetConvolutionParameterfvproc) return;
	glGetConvolutionParameterfvproc(target, pname, params);
}
PFNGLGETCONVOLUTIONPARAMETERIVPROC glGetConvolutionParameterivproc = 0;
void APIENTRY glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetConvolutionParameterivproc) return;
	glGetConvolutionParameterivproc(target, pname, params);
}
PFNGLGETSEPARABLEFILTERPROC glGetSeparableFilterproc = 0;
void APIENTRY glGetSeparableFilter(GLenum target, GLenum format, GLenum type, void* row, void* column, void* span) {
	if (!glGetSeparableFilterproc) return;
	glGetSeparableFilterproc(target, format, type, row, column, span);
}
PFNGLSEPARABLEFILTER2DPROC glSeparableFilter2Dproc = 0;
void APIENTRY glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* row, const void* column) {
	if (!glSeparableFilter2Dproc) return;
	glSeparableFilter2Dproc(target, internalformat, width, height, format, type, row, column);
}
PFNGLGETHISTOGRAMPROC glGetHistogramproc = 0;
void APIENTRY glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values) {
	if (!glGetHistogramproc) return;
	glGetHistogramproc(target, reset, format, type, values);
}
PFNGLGETHISTOGRAMPARAMETERFVPROC glGetHistogramParameterfvproc = 0;
void APIENTRY glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetHistogramParameterfvproc) return;
	glGetHistogramParameterfvproc(target, pname, params);
}
PFNGLGETHISTOGRAMPARAMETERIVPROC glGetHistogramParameterivproc = 0;
void APIENTRY glGetHistogramParameteriv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetHistogramParameterivproc) return;
	glGetHistogramParameterivproc(target, pname, params);
}
PFNGLGETMINMAXPROC glGetMinmaxproc = 0;
void APIENTRY glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values) {
	if (!glGetMinmaxproc) return;
	glGetMinmaxproc(target, reset, format, type, values);
}
PFNGLGETMINMAXPARAMETERFVPROC glGetMinmaxParameterfvproc = 0;
void APIENTRY glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetMinmaxParameterfvproc) return;
	glGetMinmaxParameterfvproc(target, pname, params);
}
PFNGLGETMINMAXPARAMETERIVPROC glGetMinmaxParameterivproc = 0;
void APIENTRY glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint* params) {
	if (!glGetMinmaxParameterivproc) return;
	glGetMinmaxParameterivproc(target, pname, params);
}
PFNGLHISTOGRAMPROC glHistogramproc = 0;
void APIENTRY glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
	if (!glHistogramproc) return;
	glHistogramproc(target, width, internalformat, sink);
}
PFNGLMINMAXPROC glMinmaxproc = 0;
void APIENTRY glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
	if (!glMinmaxproc) return;
	glMinmaxproc(target, internalformat, sink);
}
PFNGLRESETHISTOGRAMPROC glResetHistogramproc = 0;
void APIENTRY glResetHistogram(GLenum target) {
	if (!glResetHistogramproc) return;
	glResetHistogramproc(target);
}
PFNGLRESETMINMAXPROC glResetMinmaxproc = 0;
void APIENTRY glResetMinmax(GLenum target) {
	if (!glResetMinmaxproc) return;
	glResetMinmaxproc(target);
}
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC glMultiDrawArraysIndirectCountARBproc = 0;
void APIENTRY glMultiDrawArraysIndirectCountARB(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
	if (!glMultiDrawArraysIndirectCountARBproc) return;
	glMultiDrawArraysIndirectCountARBproc(mode, indirect, drawcount, maxdrawcount, stride);
}
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC glMultiDrawElementsIndirectCountARBproc = 0;
void APIENTRY glMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
	if (!glMultiDrawElementsIndirectCountARBproc) return;
	glMultiDrawElementsIndirectCountARBproc(mode, type, indirect, drawcount, maxdrawcount, stride);
}
PFNGLVERTEXATTRIBDIVISORARBPROC glVertexAttribDivisorARBproc = 0;
void APIENTRY glVertexAttribDivisorARB(GLuint index, GLuint divisor) {
	if (!glVertexAttribDivisorARBproc) return;
	glVertexAttribDivisorARBproc(index, divisor);
}
PFNGLCURRENTPALETTEMATRIXARBPROC glCurrentPaletteMatrixARBproc = 0;
void APIENTRY glCurrentPaletteMatrixARB(GLint index) {
	if (!glCurrentPaletteMatrixARBproc) return;
	glCurrentPaletteMatrixARBproc(index);
}
PFNGLMATRIXINDEXUBVARBPROC glMatrixIndexubvARBproc = 0;
void APIENTRY glMatrixIndexubvARB(GLint size, const GLubyte* indices) {
	if (!glMatrixIndexubvARBproc) return;
	glMatrixIndexubvARBproc(size, indices);
}
PFNGLMATRIXINDEXUSVARBPROC glMatrixIndexusvARBproc = 0;
void APIENTRY glMatrixIndexusvARB(GLint size, const GLushort* indices) {
	if (!glMatrixIndexusvARBproc) return;
	glMatrixIndexusvARBproc(size, indices);
}
PFNGLMATRIXINDEXUIVARBPROC glMatrixIndexuivARBproc = 0;
void APIENTRY glMatrixIndexuivARB(GLint size, const GLuint* indices) {
	if (!glMatrixIndexuivARBproc) return;
	glMatrixIndexuivARBproc(size, indices);
}
PFNGLMATRIXINDEXPOINTERARBPROC glMatrixIndexPointerARBproc = 0;
void APIENTRY glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glMatrixIndexPointerARBproc) return;
	glMatrixIndexPointerARBproc(size, type, stride, pointer);
}
PFNGLSAMPLECOVERAGEARBPROC glSampleCoverageARBproc = 0;
void APIENTRY glSampleCoverageARB(GLfloat value, GLboolean invert) {
	if (!glSampleCoverageARBproc) return;
	glSampleCoverageARBproc(value, invert);
}
PFNGLACTIVETEXTUREARBPROC glActiveTextureARBproc = 0;
void APIENTRY glActiveTextureARB(GLenum texture) {
	if (!glActiveTextureARBproc) return;
	glActiveTextureARBproc(texture);
}
PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARBproc = 0;
void APIENTRY glClientActiveTextureARB(GLenum texture) {
	if (!glClientActiveTextureARBproc) return;
	glClientActiveTextureARBproc(texture);
}
PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARBproc = 0;
void APIENTRY glMultiTexCoord1dARB(GLenum target, GLdouble s) {
	if (!glMultiTexCoord1dARBproc) return;
	glMultiTexCoord1dARBproc(target, s);
}
PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARBproc = 0;
void APIENTRY glMultiTexCoord1dvARB(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord1dvARBproc) return;
	glMultiTexCoord1dvARBproc(target, v);
}
PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARBproc = 0;
void APIENTRY glMultiTexCoord1fARB(GLenum target, GLfloat s) {
	if (!glMultiTexCoord1fARBproc) return;
	glMultiTexCoord1fARBproc(target, s);
}
PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARBproc = 0;
void APIENTRY glMultiTexCoord1fvARB(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord1fvARBproc) return;
	glMultiTexCoord1fvARBproc(target, v);
}
PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARBproc = 0;
void APIENTRY glMultiTexCoord1iARB(GLenum target, GLint s) {
	if (!glMultiTexCoord1iARBproc) return;
	glMultiTexCoord1iARBproc(target, s);
}
PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARBproc = 0;
void APIENTRY glMultiTexCoord1ivARB(GLenum target, const GLint* v) {
	if (!glMultiTexCoord1ivARBproc) return;
	glMultiTexCoord1ivARBproc(target, v);
}
PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARBproc = 0;
void APIENTRY glMultiTexCoord1sARB(GLenum target, GLshort s) {
	if (!glMultiTexCoord1sARBproc) return;
	glMultiTexCoord1sARBproc(target, s);
}
PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARBproc = 0;
void APIENTRY glMultiTexCoord1svARB(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord1svARBproc) return;
	glMultiTexCoord1svARBproc(target, v);
}
PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARBproc = 0;
void APIENTRY glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t) {
	if (!glMultiTexCoord2dARBproc) return;
	glMultiTexCoord2dARBproc(target, s, t);
}
PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARBproc = 0;
void APIENTRY glMultiTexCoord2dvARB(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord2dvARBproc) return;
	glMultiTexCoord2dvARBproc(target, v);
}
PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARBproc = 0;
void APIENTRY glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) {
	if (!glMultiTexCoord2fARBproc) return;
	glMultiTexCoord2fARBproc(target, s, t);
}
PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARBproc = 0;
void APIENTRY glMultiTexCoord2fvARB(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord2fvARBproc) return;
	glMultiTexCoord2fvARBproc(target, v);
}
PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARBproc = 0;
void APIENTRY glMultiTexCoord2iARB(GLenum target, GLint s, GLint t) {
	if (!glMultiTexCoord2iARBproc) return;
	glMultiTexCoord2iARBproc(target, s, t);
}
PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARBproc = 0;
void APIENTRY glMultiTexCoord2ivARB(GLenum target, const GLint* v) {
	if (!glMultiTexCoord2ivARBproc) return;
	glMultiTexCoord2ivARBproc(target, v);
}
PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARBproc = 0;
void APIENTRY glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t) {
	if (!glMultiTexCoord2sARBproc) return;
	glMultiTexCoord2sARBproc(target, s, t);
}
PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARBproc = 0;
void APIENTRY glMultiTexCoord2svARB(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord2svARBproc) return;
	glMultiTexCoord2svARBproc(target, v);
}
PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARBproc = 0;
void APIENTRY glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
	if (!glMultiTexCoord3dARBproc) return;
	glMultiTexCoord3dARBproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARBproc = 0;
void APIENTRY glMultiTexCoord3dvARB(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord3dvARBproc) return;
	glMultiTexCoord3dvARBproc(target, v);
}
PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARBproc = 0;
void APIENTRY glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
	if (!glMultiTexCoord3fARBproc) return;
	glMultiTexCoord3fARBproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARBproc = 0;
void APIENTRY glMultiTexCoord3fvARB(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord3fvARBproc) return;
	glMultiTexCoord3fvARBproc(target, v);
}
PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARBproc = 0;
void APIENTRY glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r) {
	if (!glMultiTexCoord3iARBproc) return;
	glMultiTexCoord3iARBproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARBproc = 0;
void APIENTRY glMultiTexCoord3ivARB(GLenum target, const GLint* v) {
	if (!glMultiTexCoord3ivARBproc) return;
	glMultiTexCoord3ivARBproc(target, v);
}
PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARBproc = 0;
void APIENTRY glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r) {
	if (!glMultiTexCoord3sARBproc) return;
	glMultiTexCoord3sARBproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARBproc = 0;
void APIENTRY glMultiTexCoord3svARB(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord3svARBproc) return;
	glMultiTexCoord3svARBproc(target, v);
}
PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARBproc = 0;
void APIENTRY glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
	if (!glMultiTexCoord4dARBproc) return;
	glMultiTexCoord4dARBproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARBproc = 0;
void APIENTRY glMultiTexCoord4dvARB(GLenum target, const GLdouble* v) {
	if (!glMultiTexCoord4dvARBproc) return;
	glMultiTexCoord4dvARBproc(target, v);
}
PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARBproc = 0;
void APIENTRY glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	if (!glMultiTexCoord4fARBproc) return;
	glMultiTexCoord4fARBproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARBproc = 0;
void APIENTRY glMultiTexCoord4fvARB(GLenum target, const GLfloat* v) {
	if (!glMultiTexCoord4fvARBproc) return;
	glMultiTexCoord4fvARBproc(target, v);
}
PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARBproc = 0;
void APIENTRY glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q) {
	if (!glMultiTexCoord4iARBproc) return;
	glMultiTexCoord4iARBproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARBproc = 0;
void APIENTRY glMultiTexCoord4ivARB(GLenum target, const GLint* v) {
	if (!glMultiTexCoord4ivARBproc) return;
	glMultiTexCoord4ivARBproc(target, v);
}
PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARBproc = 0;
void APIENTRY glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
	if (!glMultiTexCoord4sARBproc) return;
	glMultiTexCoord4sARBproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARBproc = 0;
void APIENTRY glMultiTexCoord4svARB(GLenum target, const GLshort* v) {
	if (!glMultiTexCoord4svARBproc) return;
	glMultiTexCoord4svARBproc(target, v);
}
PFNGLGENQUERIESARBPROC glGenQueriesARBproc = 0;
void APIENTRY glGenQueriesARB(GLsizei n, GLuint* ids) {
	if (!glGenQueriesARBproc) return;
	glGenQueriesARBproc(n, ids);
}
PFNGLDELETEQUERIESARBPROC glDeleteQueriesARBproc = 0;
void APIENTRY glDeleteQueriesARB(GLsizei n, const GLuint* ids) {
	if (!glDeleteQueriesARBproc) return;
	glDeleteQueriesARBproc(n, ids);
}
PFNGLISQUERYARBPROC glIsQueryARBproc = 0;
GLboolean APIENTRY glIsQueryARB(GLuint id) {
	if (!glIsQueryARBproc) return 0;
	return glIsQueryARBproc(id);
}
PFNGLBEGINQUERYARBPROC glBeginQueryARBproc = 0;
void APIENTRY glBeginQueryARB(GLenum target, GLuint id) {
	if (!glBeginQueryARBproc) return;
	glBeginQueryARBproc(target, id);
}
PFNGLENDQUERYARBPROC glEndQueryARBproc = 0;
void APIENTRY glEndQueryARB(GLenum target) {
	if (!glEndQueryARBproc) return;
	glEndQueryARBproc(target);
}
PFNGLGETQUERYIVARBPROC glGetQueryivARBproc = 0;
void APIENTRY glGetQueryivARB(GLenum target, GLenum pname, GLint* params) {
	if (!glGetQueryivARBproc) return;
	glGetQueryivARBproc(target, pname, params);
}
PFNGLGETQUERYOBJECTIVARBPROC glGetQueryObjectivARBproc = 0;
void APIENTRY glGetQueryObjectivARB(GLuint id, GLenum pname, GLint* params) {
	if (!glGetQueryObjectivARBproc) return;
	glGetQueryObjectivARBproc(id, pname, params);
}
PFNGLGETQUERYOBJECTUIVARBPROC glGetQueryObjectuivARBproc = 0;
void APIENTRY glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint* params) {
	if (!glGetQueryObjectuivARBproc) return;
	glGetQueryObjectuivARBproc(id, pname, params);
}
PFNGLMAXSHADERCOMPILERTHREADSARBPROC glMaxShaderCompilerThreadsARBproc = 0;
void APIENTRY glMaxShaderCompilerThreadsARB(GLuint count) {
	if (!glMaxShaderCompilerThreadsARBproc) return;
	glMaxShaderCompilerThreadsARBproc(count);
}
PFNGLPOINTPARAMETERFARBPROC glPointParameterfARBproc = 0;
void APIENTRY glPointParameterfARB(GLenum pname, GLfloat param) {
	if (!glPointParameterfARBproc) return;
	glPointParameterfARBproc(pname, param);
}
PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARBproc = 0;
void APIENTRY glPointParameterfvARB(GLenum pname, const GLfloat* params) {
	if (!glPointParameterfvARBproc) return;
	glPointParameterfvARBproc(pname, params);
}
PFNGLGETGRAPHICSRESETSTATUSARBPROC glGetGraphicsResetStatusARBproc = 0;
GLenum APIENTRY glGetGraphicsResetStatusARB(void) {
	if (!glGetGraphicsResetStatusARBproc) return 0;
	return glGetGraphicsResetStatusARBproc();
}
PFNGLGETNTEXIMAGEARBPROC glGetnTexImageARBproc = 0;
void APIENTRY glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img) {
	if (!glGetnTexImageARBproc) return;
	glGetnTexImageARBproc(target, level, format, type, bufSize, img);
}
PFNGLREADNPIXELSARBPROC glReadnPixelsARBproc = 0;
void APIENTRY glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) {
	if (!glReadnPixelsARBproc) return;
	glReadnPixelsARBproc(x, y, width, height, format, type, bufSize, data);
}
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC glGetnCompressedTexImageARBproc = 0;
void APIENTRY glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void* img) {
	if (!glGetnCompressedTexImageARBproc) return;
	glGetnCompressedTexImageARBproc(target, lod, bufSize, img);
}
PFNGLGETNUNIFORMFVARBPROC glGetnUniformfvARBproc = 0;
void APIENTRY glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) {
	if (!glGetnUniformfvARBproc) return;
	glGetnUniformfvARBproc(program, location, bufSize, params);
}
PFNGLGETNUNIFORMIVARBPROC glGetnUniformivARBproc = 0;
void APIENTRY glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params) {
	if (!glGetnUniformivARBproc) return;
	glGetnUniformivARBproc(program, location, bufSize, params);
}
PFNGLGETNUNIFORMUIVARBPROC glGetnUniformuivARBproc = 0;
void APIENTRY glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params) {
	if (!glGetnUniformuivARBproc) return;
	glGetnUniformuivARBproc(program, location, bufSize, params);
}
PFNGLGETNUNIFORMDVARBPROC glGetnUniformdvARBproc = 0;
void APIENTRY glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) {
	if (!glGetnUniformdvARBproc) return;
	glGetnUniformdvARBproc(program, location, bufSize, params);
}
PFNGLGETNMAPDVARBPROC glGetnMapdvARBproc = 0;
void APIENTRY glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v) {
	if (!glGetnMapdvARBproc) return;
	glGetnMapdvARBproc(target, query, bufSize, v);
}
PFNGLGETNMAPFVARBPROC glGetnMapfvARBproc = 0;
void APIENTRY glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v) {
	if (!glGetnMapfvARBproc) return;
	glGetnMapfvARBproc(target, query, bufSize, v);
}
PFNGLGETNMAPIVARBPROC glGetnMapivARBproc = 0;
void APIENTRY glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint* v) {
	if (!glGetnMapivARBproc) return;
	glGetnMapivARBproc(target, query, bufSize, v);
}
PFNGLGETNPIXELMAPFVARBPROC glGetnPixelMapfvARBproc = 0;
void APIENTRY glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat* values) {
	if (!glGetnPixelMapfvARBproc) return;
	glGetnPixelMapfvARBproc(map, bufSize, values);
}
PFNGLGETNPIXELMAPUIVARBPROC glGetnPixelMapuivARBproc = 0;
void APIENTRY glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint* values) {
	if (!glGetnPixelMapuivARBproc) return;
	glGetnPixelMapuivARBproc(map, bufSize, values);
}
PFNGLGETNPIXELMAPUSVARBPROC glGetnPixelMapusvARBproc = 0;
void APIENTRY glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort* values) {
	if (!glGetnPixelMapusvARBproc) return;
	glGetnPixelMapusvARBproc(map, bufSize, values);
}
PFNGLGETNPOLYGONSTIPPLEARBPROC glGetnPolygonStippleARBproc = 0;
void APIENTRY glGetnPolygonStippleARB(GLsizei bufSize, GLubyte* pattern) {
	if (!glGetnPolygonStippleARBproc) return;
	glGetnPolygonStippleARBproc(bufSize, pattern);
}
PFNGLGETNCOLORTABLEARBPROC glGetnColorTableARBproc = 0;
void APIENTRY glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table) {
	if (!glGetnColorTableARBproc) return;
	glGetnColorTableARBproc(target, format, type, bufSize, table);
}
PFNGLGETNCONVOLUTIONFILTERARBPROC glGetnConvolutionFilterARBproc = 0;
void APIENTRY glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image) {
	if (!glGetnConvolutionFilterARBproc) return;
	glGetnConvolutionFilterARBproc(target, format, type, bufSize, image);
}
PFNGLGETNSEPARABLEFILTERARBPROC glGetnSeparableFilterARBproc = 0;
void APIENTRY glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, void* column, void* span) {
	if (!glGetnSeparableFilterARBproc) return;
	glGetnSeparableFilterARBproc(target, format, type, rowBufSize, row, columnBufSize, column, span);
}
PFNGLGETNHISTOGRAMARBPROC glGetnHistogramARBproc = 0;
void APIENTRY glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) {
	if (!glGetnHistogramARBproc) return;
	glGetnHistogramARBproc(target, reset, format, type, bufSize, values);
}
PFNGLGETNMINMAXARBPROC glGetnMinmaxARBproc = 0;
void APIENTRY glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) {
	if (!glGetnMinmaxARBproc) return;
	glGetnMinmaxARBproc(target, reset, format, type, bufSize, values);
}
PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC glFramebufferSampleLocationsfvARBproc = 0;
void APIENTRY glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, const GLfloat* v) {
	if (!glFramebufferSampleLocationsfvARBproc) return;
	glFramebufferSampleLocationsfvARBproc(target, start, count, v);
}
PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC glNamedFramebufferSampleLocationsfvARBproc = 0;
void APIENTRY glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v) {
	if (!glNamedFramebufferSampleLocationsfvARBproc) return;
	glNamedFramebufferSampleLocationsfvARBproc(framebuffer, start, count, v);
}
PFNGLEVALUATEDEPTHVALUESARBPROC glEvaluateDepthValuesARBproc = 0;
void APIENTRY glEvaluateDepthValuesARB(void) {
	if (!glEvaluateDepthValuesARBproc) return;
	glEvaluateDepthValuesARBproc();
}
PFNGLMINSAMPLESHADINGARBPROC glMinSampleShadingARBproc = 0;
void APIENTRY glMinSampleShadingARB(GLfloat value) {
	if (!glMinSampleShadingARBproc) return;
	glMinSampleShadingARBproc(value);
}
PFNGLDELETEOBJECTARBPROC glDeleteObjectARBproc = 0;
void APIENTRY glDeleteObjectARB(GLhandleARB obj) {
	if (!glDeleteObjectARBproc) return;
	glDeleteObjectARBproc(obj);
}
PFNGLGETHANDLEARBPROC glGetHandleARBproc = 0;
GLhandleARB APIENTRY glGetHandleARB(GLenum pname) {
	if (!glGetHandleARBproc) return 0;
	return glGetHandleARBproc(pname);
}
PFNGLDETACHOBJECTARBPROC glDetachObjectARBproc = 0;
void APIENTRY glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj) {
	if (!glDetachObjectARBproc) return;
	glDetachObjectARBproc(containerObj, attachedObj);
}
PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARBproc = 0;
GLhandleARB APIENTRY glCreateShaderObjectARB(GLenum shaderType) {
	if (!glCreateShaderObjectARBproc) return 0;
	return glCreateShaderObjectARBproc(shaderType);
}
PFNGLSHADERSOURCEARBPROC glShaderSourceARBproc = 0;
void APIENTRY glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB** string, const GLint* length) {
	if (!glShaderSourceARBproc) return;
	glShaderSourceARBproc(shaderObj, count, string, length);
}
PFNGLCOMPILESHADERARBPROC glCompileShaderARBproc = 0;
void APIENTRY glCompileShaderARB(GLhandleARB shaderObj) {
	if (!glCompileShaderARBproc) return;
	glCompileShaderARBproc(shaderObj);
}
PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARBproc = 0;
GLhandleARB APIENTRY glCreateProgramObjectARB(void) {
	if (!glCreateProgramObjectARBproc) return 0;
	return glCreateProgramObjectARBproc();
}
PFNGLATTACHOBJECTARBPROC glAttachObjectARBproc = 0;
void APIENTRY glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj) {
	if (!glAttachObjectARBproc) return;
	glAttachObjectARBproc(containerObj, obj);
}
PFNGLLINKPROGRAMARBPROC glLinkProgramARBproc = 0;
void APIENTRY glLinkProgramARB(GLhandleARB programObj) {
	if (!glLinkProgramARBproc) return;
	glLinkProgramARBproc(programObj);
}
PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARBproc = 0;
void APIENTRY glUseProgramObjectARB(GLhandleARB programObj) {
	if (!glUseProgramObjectARBproc) return;
	glUseProgramObjectARBproc(programObj);
}
PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARBproc = 0;
void APIENTRY glValidateProgramARB(GLhandleARB programObj) {
	if (!glValidateProgramARBproc) return;
	glValidateProgramARBproc(programObj);
}
PFNGLUNIFORM1FARBPROC glUniform1fARBproc = 0;
void APIENTRY glUniform1fARB(GLint location, GLfloat v0) {
	if (!glUniform1fARBproc) return;
	glUniform1fARBproc(location, v0);
}
PFNGLUNIFORM2FARBPROC glUniform2fARBproc = 0;
void APIENTRY glUniform2fARB(GLint location, GLfloat v0, GLfloat v1) {
	if (!glUniform2fARBproc) return;
	glUniform2fARBproc(location, v0, v1);
}
PFNGLUNIFORM3FARBPROC glUniform3fARBproc = 0;
void APIENTRY glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	if (!glUniform3fARBproc) return;
	glUniform3fARBproc(location, v0, v1, v2);
}
PFNGLUNIFORM4FARBPROC glUniform4fARBproc = 0;
void APIENTRY glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	if (!glUniform4fARBproc) return;
	glUniform4fARBproc(location, v0, v1, v2, v3);
}
PFNGLUNIFORM1IARBPROC glUniform1iARBproc = 0;
void APIENTRY glUniform1iARB(GLint location, GLint v0) {
	if (!glUniform1iARBproc) return;
	glUniform1iARBproc(location, v0);
}
PFNGLUNIFORM2IARBPROC glUniform2iARBproc = 0;
void APIENTRY glUniform2iARB(GLint location, GLint v0, GLint v1) {
	if (!glUniform2iARBproc) return;
	glUniform2iARBproc(location, v0, v1);
}
PFNGLUNIFORM3IARBPROC glUniform3iARBproc = 0;
void APIENTRY glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) {
	if (!glUniform3iARBproc) return;
	glUniform3iARBproc(location, v0, v1, v2);
}
PFNGLUNIFORM4IARBPROC glUniform4iARBproc = 0;
void APIENTRY glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	if (!glUniform4iARBproc) return;
	glUniform4iARBproc(location, v0, v1, v2, v3);
}
PFNGLUNIFORM1FVARBPROC glUniform1fvARBproc = 0;
void APIENTRY glUniform1fvARB(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform1fvARBproc) return;
	glUniform1fvARBproc(location, count, value);
}
PFNGLUNIFORM2FVARBPROC glUniform2fvARBproc = 0;
void APIENTRY glUniform2fvARB(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform2fvARBproc) return;
	glUniform2fvARBproc(location, count, value);
}
PFNGLUNIFORM3FVARBPROC glUniform3fvARBproc = 0;
void APIENTRY glUniform3fvARB(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform3fvARBproc) return;
	glUniform3fvARBproc(location, count, value);
}
PFNGLUNIFORM4FVARBPROC glUniform4fvARBproc = 0;
void APIENTRY glUniform4fvARB(GLint location, GLsizei count, const GLfloat* value) {
	if (!glUniform4fvARBproc) return;
	glUniform4fvARBproc(location, count, value);
}
PFNGLUNIFORM1IVARBPROC glUniform1ivARBproc = 0;
void APIENTRY glUniform1ivARB(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform1ivARBproc) return;
	glUniform1ivARBproc(location, count, value);
}
PFNGLUNIFORM2IVARBPROC glUniform2ivARBproc = 0;
void APIENTRY glUniform2ivARB(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform2ivARBproc) return;
	glUniform2ivARBproc(location, count, value);
}
PFNGLUNIFORM3IVARBPROC glUniform3ivARBproc = 0;
void APIENTRY glUniform3ivARB(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform3ivARBproc) return;
	glUniform3ivARBproc(location, count, value);
}
PFNGLUNIFORM4IVARBPROC glUniform4ivARBproc = 0;
void APIENTRY glUniform4ivARB(GLint location, GLsizei count, const GLint* value) {
	if (!glUniform4ivARBproc) return;
	glUniform4ivARBproc(location, count, value);
}
PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fvARBproc = 0;
void APIENTRY glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix2fvARBproc) return;
	glUniformMatrix2fvARBproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fvARBproc = 0;
void APIENTRY glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix3fvARBproc) return;
	glUniformMatrix3fvARBproc(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARBproc = 0;
void APIENTRY glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glUniformMatrix4fvARBproc) return;
	glUniformMatrix4fvARBproc(location, count, transpose, value);
}
PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfvARBproc = 0;
void APIENTRY glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat* params) {
	if (!glGetObjectParameterfvARBproc) return;
	glGetObjectParameterfvARBproc(obj, pname, params);
}
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARBproc = 0;
void APIENTRY glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint* params) {
	if (!glGetObjectParameterivARBproc) return;
	glGetObjectParameterivARBproc(obj, pname, params);
}
PFNGLGETINFOLOGARBPROC glGetInfoLogARBproc = 0;
void APIENTRY glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog) {
	if (!glGetInfoLogARBproc) return;
	glGetInfoLogARBproc(obj, maxLength, length, infoLog);
}
PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObjectsARBproc = 0;
void APIENTRY glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei* count, GLhandleARB* obj) {
	if (!glGetAttachedObjectsARBproc) return;
	glGetAttachedObjectsARBproc(containerObj, maxCount, count, obj);
}
PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARBproc = 0;
GLint APIENTRY glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB* name) {
	if (!glGetUniformLocationARBproc) return 0;
	return glGetUniformLocationARBproc(programObj, name);
}
PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniformARBproc = 0;
void APIENTRY glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name) {
	if (!glGetActiveUniformARBproc) return;
	glGetActiveUniformARBproc(programObj, index, maxLength, length, size, type, name);
}
PFNGLGETUNIFORMFVARBPROC glGetUniformfvARBproc = 0;
void APIENTRY glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat* params) {
	if (!glGetUniformfvARBproc) return;
	glGetUniformfvARBproc(programObj, location, params);
}
PFNGLGETUNIFORMIVARBPROC glGetUniformivARBproc = 0;
void APIENTRY glGetUniformivARB(GLhandleARB programObj, GLint location, GLint* params) {
	if (!glGetUniformivARBproc) return;
	glGetUniformivARBproc(programObj, location, params);
}
PFNGLGETSHADERSOURCEARBPROC glGetShaderSourceARBproc = 0;
void APIENTRY glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* source) {
	if (!glGetShaderSourceARBproc) return;
	glGetShaderSourceARBproc(obj, maxLength, length, source);
}
PFNGLNAMEDSTRINGARBPROC glNamedStringARBproc = 0;
void APIENTRY glNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string) {
	if (!glNamedStringARBproc) return;
	glNamedStringARBproc(type, namelen, name, stringlen, string);
}
PFNGLDELETENAMEDSTRINGARBPROC glDeleteNamedStringARBproc = 0;
void APIENTRY glDeleteNamedStringARB(GLint namelen, const GLchar* name) {
	if (!glDeleteNamedStringARBproc) return;
	glDeleteNamedStringARBproc(namelen, name);
}
PFNGLCOMPILESHADERINCLUDEARBPROC glCompileShaderIncludeARBproc = 0;
void APIENTRY glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length) {
	if (!glCompileShaderIncludeARBproc) return;
	glCompileShaderIncludeARBproc(shader, count, path, length);
}
PFNGLISNAMEDSTRINGARBPROC glIsNamedStringARBproc = 0;
GLboolean APIENTRY glIsNamedStringARB(GLint namelen, const GLchar* name) {
	if (!glIsNamedStringARBproc) return 0;
	return glIsNamedStringARBproc(namelen, name);
}
PFNGLGETNAMEDSTRINGARBPROC glGetNamedStringARBproc = 0;
void APIENTRY glGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string) {
	if (!glGetNamedStringARBproc) return;
	glGetNamedStringARBproc(namelen, name, bufSize, stringlen, string);
}
PFNGLGETNAMEDSTRINGIVARBPROC glGetNamedStringivARBproc = 0;
void APIENTRY glGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum pname, GLint* params) {
	if (!glGetNamedStringivARBproc) return;
	glGetNamedStringivARBproc(namelen, name, pname, params);
}
PFNGLBUFFERPAGECOMMITMENTARBPROC glBufferPageCommitmentARBproc = 0;
void APIENTRY glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit) {
	if (!glBufferPageCommitmentARBproc) return;
	glBufferPageCommitmentARBproc(target, offset, size, commit);
}
PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC glNamedBufferPageCommitmentEXTproc = 0;
void APIENTRY glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) {
	if (!glNamedBufferPageCommitmentEXTproc) return;
	glNamedBufferPageCommitmentEXTproc(buffer, offset, size, commit);
}
PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC glNamedBufferPageCommitmentARBproc = 0;
void APIENTRY glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) {
	if (!glNamedBufferPageCommitmentARBproc) return;
	glNamedBufferPageCommitmentARBproc(buffer, offset, size, commit);
}
PFNGLTEXPAGECOMMITMENTARBPROC glTexPageCommitmentARBproc = 0;
void APIENTRY glTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
	if (!glTexPageCommitmentARBproc) return;
	glTexPageCommitmentARBproc(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
PFNGLTEXBUFFERARBPROC glTexBufferARBproc = 0;
void APIENTRY glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer) {
	if (!glTexBufferARBproc) return;
	glTexBufferARBproc(target, internalformat, buffer);
}
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARBproc = 0;
void APIENTRY glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) {
	if (!glCompressedTexImage3DARBproc) return;
	glCompressedTexImage3DARBproc(target, level, internalformat, width, height, depth, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARBproc = 0;
void APIENTRY glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) {
	if (!glCompressedTexImage2DARBproc) return;
	glCompressedTexImage2DARBproc(target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARBproc = 0;
void APIENTRY glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) {
	if (!glCompressedTexImage1DARBproc) return;
	glCompressedTexImage1DARBproc(target, level, internalformat, width, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARBproc = 0;
void APIENTRY glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTexSubImage3DARBproc) return;
	glCompressedTexSubImage3DARBproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARBproc = 0;
void APIENTRY glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTexSubImage2DARBproc) return;
	glCompressedTexSubImage2DARBproc(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARBproc = 0;
void APIENTRY glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) {
	if (!glCompressedTexSubImage1DARBproc) return;
	glCompressedTexSubImage1DARBproc(target, level, xoffset, width, format, imageSize, data);
}
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARBproc = 0;
void APIENTRY glGetCompressedTexImageARB(GLenum target, GLint level, void* img) {
	if (!glGetCompressedTexImageARBproc) return;
	glGetCompressedTexImageARBproc(target, level, img);
}
PFNGLLOADTRANSPOSEMATRIXFARBPROC glLoadTransposeMatrixfARBproc = 0;
void APIENTRY glLoadTransposeMatrixfARB(const GLfloat* m) {
	if (!glLoadTransposeMatrixfARBproc) return;
	glLoadTransposeMatrixfARBproc(m);
}
PFNGLLOADTRANSPOSEMATRIXDARBPROC glLoadTransposeMatrixdARBproc = 0;
void APIENTRY glLoadTransposeMatrixdARB(const GLdouble* m) {
	if (!glLoadTransposeMatrixdARBproc) return;
	glLoadTransposeMatrixdARBproc(m);
}
PFNGLMULTTRANSPOSEMATRIXFARBPROC glMultTransposeMatrixfARBproc = 0;
void APIENTRY glMultTransposeMatrixfARB(const GLfloat* m) {
	if (!glMultTransposeMatrixfARBproc) return;
	glMultTransposeMatrixfARBproc(m);
}
PFNGLMULTTRANSPOSEMATRIXDARBPROC glMultTransposeMatrixdARBproc = 0;
void APIENTRY glMultTransposeMatrixdARB(const GLdouble* m) {
	if (!glMultTransposeMatrixdARBproc) return;
	glMultTransposeMatrixdARBproc(m);
}
PFNGLWEIGHTBVARBPROC glWeightbvARBproc = 0;
void APIENTRY glWeightbvARB(GLint size, const GLbyte* weights) {
	if (!glWeightbvARBproc) return;
	glWeightbvARBproc(size, weights);
}
PFNGLWEIGHTSVARBPROC glWeightsvARBproc = 0;
void APIENTRY glWeightsvARB(GLint size, const GLshort* weights) {
	if (!glWeightsvARBproc) return;
	glWeightsvARBproc(size, weights);
}
PFNGLWEIGHTIVARBPROC glWeightivARBproc = 0;
void APIENTRY glWeightivARB(GLint size, const GLint* weights) {
	if (!glWeightivARBproc) return;
	glWeightivARBproc(size, weights);
}
PFNGLWEIGHTFVARBPROC glWeightfvARBproc = 0;
void APIENTRY glWeightfvARB(GLint size, const GLfloat* weights) {
	if (!glWeightfvARBproc) return;
	glWeightfvARBproc(size, weights);
}
PFNGLWEIGHTDVARBPROC glWeightdvARBproc = 0;
void APIENTRY glWeightdvARB(GLint size, const GLdouble* weights) {
	if (!glWeightdvARBproc) return;
	glWeightdvARBproc(size, weights);
}
PFNGLWEIGHTUBVARBPROC glWeightubvARBproc = 0;
void APIENTRY glWeightubvARB(GLint size, const GLubyte* weights) {
	if (!glWeightubvARBproc) return;
	glWeightubvARBproc(size, weights);
}
PFNGLWEIGHTUSVARBPROC glWeightusvARBproc = 0;
void APIENTRY glWeightusvARB(GLint size, const GLushort* weights) {
	if (!glWeightusvARBproc) return;
	glWeightusvARBproc(size, weights);
}
PFNGLWEIGHTUIVARBPROC glWeightuivARBproc = 0;
void APIENTRY glWeightuivARB(GLint size, const GLuint* weights) {
	if (!glWeightuivARBproc) return;
	glWeightuivARBproc(size, weights);
}
PFNGLWEIGHTPOINTERARBPROC glWeightPointerARBproc = 0;
void APIENTRY glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glWeightPointerARBproc) return;
	glWeightPointerARBproc(size, type, stride, pointer);
}
PFNGLVERTEXBLENDARBPROC glVertexBlendARBproc = 0;
void APIENTRY glVertexBlendARB(GLint count) {
	if (!glVertexBlendARBproc) return;
	glVertexBlendARBproc(count);
}
PFNGLBINDBUFFERARBPROC glBindBufferARBproc = 0;
void APIENTRY glBindBufferARB(GLenum target, GLuint buffer) {
	if (!glBindBufferARBproc) return;
	glBindBufferARBproc(target, buffer);
}
PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARBproc = 0;
void APIENTRY glDeleteBuffersARB(GLsizei n, const GLuint* buffers) {
	if (!glDeleteBuffersARBproc) return;
	glDeleteBuffersARBproc(n, buffers);
}
PFNGLGENBUFFERSARBPROC glGenBuffersARBproc = 0;
void APIENTRY glGenBuffersARB(GLsizei n, GLuint* buffers) {
	if (!glGenBuffersARBproc) return;
	glGenBuffersARBproc(n, buffers);
}
PFNGLISBUFFERARBPROC glIsBufferARBproc = 0;
GLboolean APIENTRY glIsBufferARB(GLuint buffer) {
	if (!glIsBufferARBproc) return 0;
	return glIsBufferARBproc(buffer);
}
PFNGLBUFFERDATAARBPROC glBufferDataARBproc = 0;
void APIENTRY glBufferDataARB(GLenum target, GLsizeiptrARB size, const void* data, GLenum usage) {
	if (!glBufferDataARBproc) return;
	glBufferDataARBproc(target, size, data, usage);
}
PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARBproc = 0;
void APIENTRY glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void* data) {
	if (!glBufferSubDataARBproc) return;
	glBufferSubDataARBproc(target, offset, size, data);
}
PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubDataARBproc = 0;
void APIENTRY glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void* data) {
	if (!glGetBufferSubDataARBproc) return;
	glGetBufferSubDataARBproc(target, offset, size, data);
}
PFNGLMAPBUFFERARBPROC glMapBufferARBproc = 0;
void* APIENTRY glMapBufferARB(GLenum target, GLenum access) {
	if (!glMapBufferARBproc) return 0;
	return glMapBufferARBproc(target, access);
}
PFNGLUNMAPBUFFERARBPROC glUnmapBufferARBproc = 0;
GLboolean APIENTRY glUnmapBufferARB(GLenum target) {
	if (!glUnmapBufferARBproc) return 0;
	return glUnmapBufferARBproc(target);
}
PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARBproc = 0;
void APIENTRY glGetBufferParameterivARB(GLenum target, GLenum pname, GLint* params) {
	if (!glGetBufferParameterivARBproc) return;
	glGetBufferParameterivARBproc(target, pname, params);
}
PFNGLGETBUFFERPOINTERVARBPROC glGetBufferPointervARBproc = 0;
void APIENTRY glGetBufferPointervARB(GLenum target, GLenum pname, void** params) {
	if (!glGetBufferPointervARBproc) return;
	glGetBufferPointervARBproc(target, pname, params);
}
PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARBproc = 0;
void APIENTRY glVertexAttrib1dARB(GLuint index, GLdouble x) {
	if (!glVertexAttrib1dARBproc) return;
	glVertexAttrib1dARBproc(index, x);
}
PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARBproc = 0;
void APIENTRY glVertexAttrib1dvARB(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib1dvARBproc) return;
	glVertexAttrib1dvARBproc(index, v);
}
PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARBproc = 0;
void APIENTRY glVertexAttrib1fARB(GLuint index, GLfloat x) {
	if (!glVertexAttrib1fARBproc) return;
	glVertexAttrib1fARBproc(index, x);
}
PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARBproc = 0;
void APIENTRY glVertexAttrib1fvARB(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib1fvARBproc) return;
	glVertexAttrib1fvARBproc(index, v);
}
PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARBproc = 0;
void APIENTRY glVertexAttrib1sARB(GLuint index, GLshort x) {
	if (!glVertexAttrib1sARBproc) return;
	glVertexAttrib1sARBproc(index, x);
}
PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARBproc = 0;
void APIENTRY glVertexAttrib1svARB(GLuint index, const GLshort* v) {
	if (!glVertexAttrib1svARBproc) return;
	glVertexAttrib1svARBproc(index, v);
}
PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARBproc = 0;
void APIENTRY glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y) {
	if (!glVertexAttrib2dARBproc) return;
	glVertexAttrib2dARBproc(index, x, y);
}
PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARBproc = 0;
void APIENTRY glVertexAttrib2dvARB(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib2dvARBproc) return;
	glVertexAttrib2dvARBproc(index, v);
}
PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARBproc = 0;
void APIENTRY glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y) {
	if (!glVertexAttrib2fARBproc) return;
	glVertexAttrib2fARBproc(index, x, y);
}
PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARBproc = 0;
void APIENTRY glVertexAttrib2fvARB(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib2fvARBproc) return;
	glVertexAttrib2fvARBproc(index, v);
}
PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARBproc = 0;
void APIENTRY glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y) {
	if (!glVertexAttrib2sARBproc) return;
	glVertexAttrib2sARBproc(index, x, y);
}
PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARBproc = 0;
void APIENTRY glVertexAttrib2svARB(GLuint index, const GLshort* v) {
	if (!glVertexAttrib2svARBproc) return;
	glVertexAttrib2svARBproc(index, v);
}
PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARBproc = 0;
void APIENTRY glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	if (!glVertexAttrib3dARBproc) return;
	glVertexAttrib3dARBproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARBproc = 0;
void APIENTRY glVertexAttrib3dvARB(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib3dvARBproc) return;
	glVertexAttrib3dvARBproc(index, v);
}
PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARBproc = 0;
void APIENTRY glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
	if (!glVertexAttrib3fARBproc) return;
	glVertexAttrib3fARBproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARBproc = 0;
void APIENTRY glVertexAttrib3fvARB(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib3fvARBproc) return;
	glVertexAttrib3fvARBproc(index, v);
}
PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARBproc = 0;
void APIENTRY glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z) {
	if (!glVertexAttrib3sARBproc) return;
	glVertexAttrib3sARBproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARBproc = 0;
void APIENTRY glVertexAttrib3svARB(GLuint index, const GLshort* v) {
	if (!glVertexAttrib3svARBproc) return;
	glVertexAttrib3svARBproc(index, v);
}
PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARBproc = 0;
void APIENTRY glVertexAttrib4NbvARB(GLuint index, const GLbyte* v) {
	if (!glVertexAttrib4NbvARBproc) return;
	glVertexAttrib4NbvARBproc(index, v);
}
PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARBproc = 0;
void APIENTRY glVertexAttrib4NivARB(GLuint index, const GLint* v) {
	if (!glVertexAttrib4NivARBproc) return;
	glVertexAttrib4NivARBproc(index, v);
}
PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARBproc = 0;
void APIENTRY glVertexAttrib4NsvARB(GLuint index, const GLshort* v) {
	if (!glVertexAttrib4NsvARBproc) return;
	glVertexAttrib4NsvARBproc(index, v);
}
PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARBproc = 0;
void APIENTRY glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
	if (!glVertexAttrib4NubARBproc) return;
	glVertexAttrib4NubARBproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARBproc = 0;
void APIENTRY glVertexAttrib4NubvARB(GLuint index, const GLubyte* v) {
	if (!glVertexAttrib4NubvARBproc) return;
	glVertexAttrib4NubvARBproc(index, v);
}
PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARBproc = 0;
void APIENTRY glVertexAttrib4NuivARB(GLuint index, const GLuint* v) {
	if (!glVertexAttrib4NuivARBproc) return;
	glVertexAttrib4NuivARBproc(index, v);
}
PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARBproc = 0;
void APIENTRY glVertexAttrib4NusvARB(GLuint index, const GLushort* v) {
	if (!glVertexAttrib4NusvARBproc) return;
	glVertexAttrib4NusvARBproc(index, v);
}
PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARBproc = 0;
void APIENTRY glVertexAttrib4bvARB(GLuint index, const GLbyte* v) {
	if (!glVertexAttrib4bvARBproc) return;
	glVertexAttrib4bvARBproc(index, v);
}
PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARBproc = 0;
void APIENTRY glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glVertexAttrib4dARBproc) return;
	glVertexAttrib4dARBproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARBproc = 0;
void APIENTRY glVertexAttrib4dvARB(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib4dvARBproc) return;
	glVertexAttrib4dvARBproc(index, v);
}
PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARBproc = 0;
void APIENTRY glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glVertexAttrib4fARBproc) return;
	glVertexAttrib4fARBproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARBproc = 0;
void APIENTRY glVertexAttrib4fvARB(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib4fvARBproc) return;
	glVertexAttrib4fvARBproc(index, v);
}
PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARBproc = 0;
void APIENTRY glVertexAttrib4ivARB(GLuint index, const GLint* v) {
	if (!glVertexAttrib4ivARBproc) return;
	glVertexAttrib4ivARBproc(index, v);
}
PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARBproc = 0;
void APIENTRY glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
	if (!glVertexAttrib4sARBproc) return;
	glVertexAttrib4sARBproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARBproc = 0;
void APIENTRY glVertexAttrib4svARB(GLuint index, const GLshort* v) {
	if (!glVertexAttrib4svARBproc) return;
	glVertexAttrib4svARBproc(index, v);
}
PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARBproc = 0;
void APIENTRY glVertexAttrib4ubvARB(GLuint index, const GLubyte* v) {
	if (!glVertexAttrib4ubvARBproc) return;
	glVertexAttrib4ubvARBproc(index, v);
}
PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARBproc = 0;
void APIENTRY glVertexAttrib4uivARB(GLuint index, const GLuint* v) {
	if (!glVertexAttrib4uivARBproc) return;
	glVertexAttrib4uivARBproc(index, v);
}
PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARBproc = 0;
void APIENTRY glVertexAttrib4usvARB(GLuint index, const GLushort* v) {
	if (!glVertexAttrib4usvARBproc) return;
	glVertexAttrib4usvARBproc(index, v);
}
PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARBproc = 0;
void APIENTRY glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) {
	if (!glVertexAttribPointerARBproc) return;
	glVertexAttribPointerARBproc(index, size, type, normalized, stride, pointer);
}
PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARBproc = 0;
void APIENTRY glEnableVertexAttribArrayARB(GLuint index) {
	if (!glEnableVertexAttribArrayARBproc) return;
	glEnableVertexAttribArrayARBproc(index);
}
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARBproc = 0;
void APIENTRY glDisableVertexAttribArrayARB(GLuint index) {
	if (!glDisableVertexAttribArrayARBproc) return;
	glDisableVertexAttribArrayARBproc(index);
}
PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARBproc = 0;
void APIENTRY glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble* params) {
	if (!glGetVertexAttribdvARBproc) return;
	glGetVertexAttribdvARBproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARBproc = 0;
void APIENTRY glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat* params) {
	if (!glGetVertexAttribfvARBproc) return;
	glGetVertexAttribfvARBproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARBproc = 0;
void APIENTRY glGetVertexAttribivARB(GLuint index, GLenum pname, GLint* params) {
	if (!glGetVertexAttribivARBproc) return;
	glGetVertexAttribivARBproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARBproc = 0;
void APIENTRY glGetVertexAttribPointervARB(GLuint index, GLenum pname, void** pointer) {
	if (!glGetVertexAttribPointervARBproc) return;
	glGetVertexAttribPointervARBproc(index, pname, pointer);
}
PFNGLBINDATTRIBLOCATIONARBPROC glBindAttribLocationARBproc = 0;
void APIENTRY glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB* name) {
	if (!glBindAttribLocationARBproc) return;
	glBindAttribLocationARBproc(programObj, index, name);
}
PFNGLGETACTIVEATTRIBARBPROC glGetActiveAttribARBproc = 0;
void APIENTRY glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name) {
	if (!glGetActiveAttribARBproc) return;
	glGetActiveAttribARBproc(programObj, index, maxLength, length, size, type, name);
}
PFNGLGETATTRIBLOCATIONARBPROC glGetAttribLocationARBproc = 0;
GLint APIENTRY glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB* name) {
	if (!glGetAttribLocationARBproc) return 0;
	return glGetAttribLocationARBproc(programObj, name);
}
PFNGLDEPTHRANGEARRAYDVNVPROC glDepthRangeArraydvNVproc = 0;
void APIENTRY glDepthRangeArraydvNV(GLuint first, GLsizei count, const GLdouble* v) {
	if (!glDepthRangeArraydvNVproc) return;
	glDepthRangeArraydvNVproc(first, count, v);
}
PFNGLDEPTHRANGEINDEXEDDNVPROC glDepthRangeIndexeddNVproc = 0;
void APIENTRY glDepthRangeIndexeddNV(GLuint index, GLdouble n, GLdouble f) {
	if (!glDepthRangeIndexeddNVproc) return;
	glDepthRangeIndexeddNVproc(index, n, f);
}
PFNGLWINDOWPOS2DARBPROC glWindowPos2dARBproc = 0;
void APIENTRY glWindowPos2dARB(GLdouble x, GLdouble y) {
	if (!glWindowPos2dARBproc) return;
	glWindowPos2dARBproc(x, y);
}
PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARBproc = 0;
void APIENTRY glWindowPos2dvARB(const GLdouble* v) {
	if (!glWindowPos2dvARBproc) return;
	glWindowPos2dvARBproc(v);
}
PFNGLWINDOWPOS2FARBPROC glWindowPos2fARBproc = 0;
void APIENTRY glWindowPos2fARB(GLfloat x, GLfloat y) {
	if (!glWindowPos2fARBproc) return;
	glWindowPos2fARBproc(x, y);
}
PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARBproc = 0;
void APIENTRY glWindowPos2fvARB(const GLfloat* v) {
	if (!glWindowPos2fvARBproc) return;
	glWindowPos2fvARBproc(v);
}
PFNGLWINDOWPOS2IARBPROC glWindowPos2iARBproc = 0;
void APIENTRY glWindowPos2iARB(GLint x, GLint y) {
	if (!glWindowPos2iARBproc) return;
	glWindowPos2iARBproc(x, y);
}
PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARBproc = 0;
void APIENTRY glWindowPos2ivARB(const GLint* v) {
	if (!glWindowPos2ivARBproc) return;
	glWindowPos2ivARBproc(v);
}
PFNGLWINDOWPOS2SARBPROC glWindowPos2sARBproc = 0;
void APIENTRY glWindowPos2sARB(GLshort x, GLshort y) {
	if (!glWindowPos2sARBproc) return;
	glWindowPos2sARBproc(x, y);
}
PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARBproc = 0;
void APIENTRY glWindowPos2svARB(const GLshort* v) {
	if (!glWindowPos2svARBproc) return;
	glWindowPos2svARBproc(v);
}
PFNGLWINDOWPOS3DARBPROC glWindowPos3dARBproc = 0;
void APIENTRY glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z) {
	if (!glWindowPos3dARBproc) return;
	glWindowPos3dARBproc(x, y, z);
}
PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARBproc = 0;
void APIENTRY glWindowPos3dvARB(const GLdouble* v) {
	if (!glWindowPos3dvARBproc) return;
	glWindowPos3dvARBproc(v);
}
PFNGLWINDOWPOS3FARBPROC glWindowPos3fARBproc = 0;
void APIENTRY glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z) {
	if (!glWindowPos3fARBproc) return;
	glWindowPos3fARBproc(x, y, z);
}
PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARBproc = 0;
void APIENTRY glWindowPos3fvARB(const GLfloat* v) {
	if (!glWindowPos3fvARBproc) return;
	glWindowPos3fvARBproc(v);
}
PFNGLWINDOWPOS3IARBPROC glWindowPos3iARBproc = 0;
void APIENTRY glWindowPos3iARB(GLint x, GLint y, GLint z) {
	if (!glWindowPos3iARBproc) return;
	glWindowPos3iARBproc(x, y, z);
}
PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARBproc = 0;
void APIENTRY glWindowPos3ivARB(const GLint* v) {
	if (!glWindowPos3ivARBproc) return;
	glWindowPos3ivARBproc(v);
}
PFNGLWINDOWPOS3SARBPROC glWindowPos3sARBproc = 0;
void APIENTRY glWindowPos3sARB(GLshort x, GLshort y, GLshort z) {
	if (!glWindowPos3sARBproc) return;
	glWindowPos3sARBproc(x, y, z);
}
PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARBproc = 0;
void APIENTRY glWindowPos3svARB(const GLshort* v) {
	if (!glWindowPos3svARBproc) return;
	glWindowPos3svARBproc(v);
}
PFNGLBLENDBARRIERKHRPROC glBlendBarrierKHRproc = 0;
void APIENTRY glBlendBarrierKHR(void) {
	if (!glBlendBarrierKHRproc) return;
	glBlendBarrierKHRproc();
}
PFNGLMAXSHADERCOMPILERTHREADSKHRPROC glMaxShaderCompilerThreadsKHRproc = 0;
void APIENTRY glMaxShaderCompilerThreadsKHR(GLuint count) {
	if (!glMaxShaderCompilerThreadsKHRproc) return;
	glMaxShaderCompilerThreadsKHRproc(count);
}
PFNGLMULTITEXCOORD1BOESPROC glMultiTexCoord1bOESproc = 0;
void APIENTRY glMultiTexCoord1bOES(GLenum texture, GLbyte s) {
	if (!glMultiTexCoord1bOESproc) return;
	glMultiTexCoord1bOESproc(texture, s);
}
PFNGLMULTITEXCOORD1BVOESPROC glMultiTexCoord1bvOESproc = 0;
void APIENTRY glMultiTexCoord1bvOES(GLenum texture, const GLbyte* coords) {
	if (!glMultiTexCoord1bvOESproc) return;
	glMultiTexCoord1bvOESproc(texture, coords);
}
PFNGLMULTITEXCOORD2BOESPROC glMultiTexCoord2bOESproc = 0;
void APIENTRY glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t) {
	if (!glMultiTexCoord2bOESproc) return;
	glMultiTexCoord2bOESproc(texture, s, t);
}
PFNGLMULTITEXCOORD2BVOESPROC glMultiTexCoord2bvOESproc = 0;
void APIENTRY glMultiTexCoord2bvOES(GLenum texture, const GLbyte* coords) {
	if (!glMultiTexCoord2bvOESproc) return;
	glMultiTexCoord2bvOESproc(texture, coords);
}
PFNGLMULTITEXCOORD3BOESPROC glMultiTexCoord3bOESproc = 0;
void APIENTRY glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r) {
	if (!glMultiTexCoord3bOESproc) return;
	glMultiTexCoord3bOESproc(texture, s, t, r);
}
PFNGLMULTITEXCOORD3BVOESPROC glMultiTexCoord3bvOESproc = 0;
void APIENTRY glMultiTexCoord3bvOES(GLenum texture, const GLbyte* coords) {
	if (!glMultiTexCoord3bvOESproc) return;
	glMultiTexCoord3bvOESproc(texture, coords);
}
PFNGLMULTITEXCOORD4BOESPROC glMultiTexCoord4bOESproc = 0;
void APIENTRY glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
	if (!glMultiTexCoord4bOESproc) return;
	glMultiTexCoord4bOESproc(texture, s, t, r, q);
}
PFNGLMULTITEXCOORD4BVOESPROC glMultiTexCoord4bvOESproc = 0;
void APIENTRY glMultiTexCoord4bvOES(GLenum texture, const GLbyte* coords) {
	if (!glMultiTexCoord4bvOESproc) return;
	glMultiTexCoord4bvOESproc(texture, coords);
}
PFNGLTEXCOORD1BOESPROC glTexCoord1bOESproc = 0;
void APIENTRY glTexCoord1bOES(GLbyte s) {
	if (!glTexCoord1bOESproc) return;
	glTexCoord1bOESproc(s);
}
PFNGLTEXCOORD1BVOESPROC glTexCoord1bvOESproc = 0;
void APIENTRY glTexCoord1bvOES(const GLbyte* coords) {
	if (!glTexCoord1bvOESproc) return;
	glTexCoord1bvOESproc(coords);
}
PFNGLTEXCOORD2BOESPROC glTexCoord2bOESproc = 0;
void APIENTRY glTexCoord2bOES(GLbyte s, GLbyte t) {
	if (!glTexCoord2bOESproc) return;
	glTexCoord2bOESproc(s, t);
}
PFNGLTEXCOORD2BVOESPROC glTexCoord2bvOESproc = 0;
void APIENTRY glTexCoord2bvOES(const GLbyte* coords) {
	if (!glTexCoord2bvOESproc) return;
	glTexCoord2bvOESproc(coords);
}
PFNGLTEXCOORD3BOESPROC glTexCoord3bOESproc = 0;
void APIENTRY glTexCoord3bOES(GLbyte s, GLbyte t, GLbyte r) {
	if (!glTexCoord3bOESproc) return;
	glTexCoord3bOESproc(s, t, r);
}
PFNGLTEXCOORD3BVOESPROC glTexCoord3bvOESproc = 0;
void APIENTRY glTexCoord3bvOES(const GLbyte* coords) {
	if (!glTexCoord3bvOESproc) return;
	glTexCoord3bvOESproc(coords);
}
PFNGLTEXCOORD4BOESPROC glTexCoord4bOESproc = 0;
void APIENTRY glTexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
	if (!glTexCoord4bOESproc) return;
	glTexCoord4bOESproc(s, t, r, q);
}
PFNGLTEXCOORD4BVOESPROC glTexCoord4bvOESproc = 0;
void APIENTRY glTexCoord4bvOES(const GLbyte* coords) {
	if (!glTexCoord4bvOESproc) return;
	glTexCoord4bvOESproc(coords);
}
PFNGLVERTEX2BOESPROC glVertex2bOESproc = 0;
void APIENTRY glVertex2bOES(GLbyte x, GLbyte y) {
	if (!glVertex2bOESproc) return;
	glVertex2bOESproc(x, y);
}
PFNGLVERTEX2BVOESPROC glVertex2bvOESproc = 0;
void APIENTRY glVertex2bvOES(const GLbyte* coords) {
	if (!glVertex2bvOESproc) return;
	glVertex2bvOESproc(coords);
}
PFNGLVERTEX3BOESPROC glVertex3bOESproc = 0;
void APIENTRY glVertex3bOES(GLbyte x, GLbyte y, GLbyte z) {
	if (!glVertex3bOESproc) return;
	glVertex3bOESproc(x, y, z);
}
PFNGLVERTEX3BVOESPROC glVertex3bvOESproc = 0;
void APIENTRY glVertex3bvOES(const GLbyte* coords) {
	if (!glVertex3bvOESproc) return;
	glVertex3bvOESproc(coords);
}
PFNGLVERTEX4BOESPROC glVertex4bOESproc = 0;
void APIENTRY glVertex4bOES(GLbyte x, GLbyte y, GLbyte z, GLbyte w) {
	if (!glVertex4bOESproc) return;
	glVertex4bOESproc(x, y, z, w);
}
PFNGLVERTEX4BVOESPROC glVertex4bvOESproc = 0;
void APIENTRY glVertex4bvOES(const GLbyte* coords) {
	if (!glVertex4bvOESproc) return;
	glVertex4bvOESproc(coords);
}
PFNGLALPHAFUNCXOESPROC glAlphaFuncxOESproc = 0;
void APIENTRY glAlphaFuncxOES(GLenum func, GLfixed ref) {
	if (!glAlphaFuncxOESproc) return;
	glAlphaFuncxOESproc(func, ref);
}
PFNGLCLEARCOLORXOESPROC glClearColorxOESproc = 0;
void APIENTRY glClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	if (!glClearColorxOESproc) return;
	glClearColorxOESproc(red, green, blue, alpha);
}
PFNGLCLEARDEPTHXOESPROC glClearDepthxOESproc = 0;
void APIENTRY glClearDepthxOES(GLfixed depth) {
	if (!glClearDepthxOESproc) return;
	glClearDepthxOESproc(depth);
}
PFNGLCLIPPLANEXOESPROC glClipPlanexOESproc = 0;
void APIENTRY glClipPlanexOES(GLenum plane, const GLfixed* equation) {
	if (!glClipPlanexOESproc) return;
	glClipPlanexOESproc(plane, equation);
}
PFNGLCOLOR4XOESPROC glColor4xOESproc = 0;
void APIENTRY glColor4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	if (!glColor4xOESproc) return;
	glColor4xOESproc(red, green, blue, alpha);
}
PFNGLDEPTHRANGEXOESPROC glDepthRangexOESproc = 0;
void APIENTRY glDepthRangexOES(GLfixed n, GLfixed f) {
	if (!glDepthRangexOESproc) return;
	glDepthRangexOESproc(n, f);
}
PFNGLFOGXOESPROC glFogxOESproc = 0;
void APIENTRY glFogxOES(GLenum pname, GLfixed param) {
	if (!glFogxOESproc) return;
	glFogxOESproc(pname, param);
}
PFNGLFOGXVOESPROC glFogxvOESproc = 0;
void APIENTRY glFogxvOES(GLenum pname, const GLfixed* param) {
	if (!glFogxvOESproc) return;
	glFogxvOESproc(pname, param);
}
PFNGLFRUSTUMXOESPROC glFrustumxOESproc = 0;
void APIENTRY glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	if (!glFrustumxOESproc) return;
	glFrustumxOESproc(l, r, b, t, n, f);
}
PFNGLGETCLIPPLANEXOESPROC glGetClipPlanexOESproc = 0;
void APIENTRY glGetClipPlanexOES(GLenum plane, GLfixed* equation) {
	if (!glGetClipPlanexOESproc) return;
	glGetClipPlanexOESproc(plane, equation);
}
PFNGLGETFIXEDVOESPROC glGetFixedvOESproc = 0;
void APIENTRY glGetFixedvOES(GLenum pname, GLfixed* params) {
	if (!glGetFixedvOESproc) return;
	glGetFixedvOESproc(pname, params);
}
PFNGLGETTEXENVXVOESPROC glGetTexEnvxvOESproc = 0;
void APIENTRY glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed* params) {
	if (!glGetTexEnvxvOESproc) return;
	glGetTexEnvxvOESproc(target, pname, params);
}
PFNGLGETTEXPARAMETERXVOESPROC glGetTexParameterxvOESproc = 0;
void APIENTRY glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed* params) {
	if (!glGetTexParameterxvOESproc) return;
	glGetTexParameterxvOESproc(target, pname, params);
}
PFNGLLIGHTMODELXOESPROC glLightModelxOESproc = 0;
void APIENTRY glLightModelxOES(GLenum pname, GLfixed param) {
	if (!glLightModelxOESproc) return;
	glLightModelxOESproc(pname, param);
}
PFNGLLIGHTMODELXVOESPROC glLightModelxvOESproc = 0;
void APIENTRY glLightModelxvOES(GLenum pname, const GLfixed* param) {
	if (!glLightModelxvOESproc) return;
	glLightModelxvOESproc(pname, param);
}
PFNGLLIGHTXOESPROC glLightxOESproc = 0;
void APIENTRY glLightxOES(GLenum light, GLenum pname, GLfixed param) {
	if (!glLightxOESproc) return;
	glLightxOESproc(light, pname, param);
}
PFNGLLIGHTXVOESPROC glLightxvOESproc = 0;
void APIENTRY glLightxvOES(GLenum light, GLenum pname, const GLfixed* params) {
	if (!glLightxvOESproc) return;
	glLightxvOESproc(light, pname, params);
}
PFNGLLINEWIDTHXOESPROC glLineWidthxOESproc = 0;
void APIENTRY glLineWidthxOES(GLfixed width) {
	if (!glLineWidthxOESproc) return;
	glLineWidthxOESproc(width);
}
PFNGLLOADMATRIXXOESPROC glLoadMatrixxOESproc = 0;
void APIENTRY glLoadMatrixxOES(const GLfixed* m) {
	if (!glLoadMatrixxOESproc) return;
	glLoadMatrixxOESproc(m);
}
PFNGLMATERIALXOESPROC glMaterialxOESproc = 0;
void APIENTRY glMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
	if (!glMaterialxOESproc) return;
	glMaterialxOESproc(face, pname, param);
}
PFNGLMATERIALXVOESPROC glMaterialxvOESproc = 0;
void APIENTRY glMaterialxvOES(GLenum face, GLenum pname, const GLfixed* param) {
	if (!glMaterialxvOESproc) return;
	glMaterialxvOESproc(face, pname, param);
}
PFNGLMULTMATRIXXOESPROC glMultMatrixxOESproc = 0;
void APIENTRY glMultMatrixxOES(const GLfixed* m) {
	if (!glMultMatrixxOESproc) return;
	glMultMatrixxOESproc(m);
}
PFNGLMULTITEXCOORD4XOESPROC glMultiTexCoord4xOESproc = 0;
void APIENTRY glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	if (!glMultiTexCoord4xOESproc) return;
	glMultiTexCoord4xOESproc(texture, s, t, r, q);
}
PFNGLNORMAL3XOESPROC glNormal3xOESproc = 0;
void APIENTRY glNormal3xOES(GLfixed nx, GLfixed ny, GLfixed nz) {
	if (!glNormal3xOESproc) return;
	glNormal3xOESproc(nx, ny, nz);
}
PFNGLORTHOXOESPROC glOrthoxOESproc = 0;
void APIENTRY glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
	if (!glOrthoxOESproc) return;
	glOrthoxOESproc(l, r, b, t, n, f);
}
PFNGLPOINTPARAMETERXVOESPROC glPointParameterxvOESproc = 0;
void APIENTRY glPointParameterxvOES(GLenum pname, const GLfixed* params) {
	if (!glPointParameterxvOESproc) return;
	glPointParameterxvOESproc(pname, params);
}
PFNGLPOINTSIZEXOESPROC glPointSizexOESproc = 0;
void APIENTRY glPointSizexOES(GLfixed size) {
	if (!glPointSizexOESproc) return;
	glPointSizexOESproc(size);
}
PFNGLPOLYGONOFFSETXOESPROC glPolygonOffsetxOESproc = 0;
void APIENTRY glPolygonOffsetxOES(GLfixed factor, GLfixed units) {
	if (!glPolygonOffsetxOESproc) return;
	glPolygonOffsetxOESproc(factor, units);
}
PFNGLROTATEXOESPROC glRotatexOESproc = 0;
void APIENTRY glRotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
	if (!glRotatexOESproc) return;
	glRotatexOESproc(angle, x, y, z);
}
PFNGLSCALEXOESPROC glScalexOESproc = 0;
void APIENTRY glScalexOES(GLfixed x, GLfixed y, GLfixed z) {
	if (!glScalexOESproc) return;
	glScalexOESproc(x, y, z);
}
PFNGLTEXENVXOESPROC glTexEnvxOESproc = 0;
void APIENTRY glTexEnvxOES(GLenum target, GLenum pname, GLfixed param) {
	if (!glTexEnvxOESproc) return;
	glTexEnvxOESproc(target, pname, param);
}
PFNGLTEXENVXVOESPROC glTexEnvxvOESproc = 0;
void APIENTRY glTexEnvxvOES(GLenum target, GLenum pname, const GLfixed* params) {
	if (!glTexEnvxvOESproc) return;
	glTexEnvxvOESproc(target, pname, params);
}
PFNGLTEXPARAMETERXOESPROC glTexParameterxOESproc = 0;
void APIENTRY glTexParameterxOES(GLenum target, GLenum pname, GLfixed param) {
	if (!glTexParameterxOESproc) return;
	glTexParameterxOESproc(target, pname, param);
}
PFNGLTEXPARAMETERXVOESPROC glTexParameterxvOESproc = 0;
void APIENTRY glTexParameterxvOES(GLenum target, GLenum pname, const GLfixed* params) {
	if (!glTexParameterxvOESproc) return;
	glTexParameterxvOESproc(target, pname, params);
}
PFNGLTRANSLATEXOESPROC glTranslatexOESproc = 0;
void APIENTRY glTranslatexOES(GLfixed x, GLfixed y, GLfixed z) {
	if (!glTranslatexOESproc) return;
	glTranslatexOESproc(x, y, z);
}
PFNGLACCUMXOESPROC glAccumxOESproc = 0;
void APIENTRY glAccumxOES(GLenum op, GLfixed value) {
	if (!glAccumxOESproc) return;
	glAccumxOESproc(op, value);
}
PFNGLBITMAPXOESPROC glBitmapxOESproc = 0;
void APIENTRY glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte* bitmap) {
	if (!glBitmapxOESproc) return;
	glBitmapxOESproc(width, height, xorig, yorig, xmove, ymove, bitmap);
}
PFNGLBLENDCOLORXOESPROC glBlendColorxOESproc = 0;
void APIENTRY glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	if (!glBlendColorxOESproc) return;
	glBlendColorxOESproc(red, green, blue, alpha);
}
PFNGLCLEARACCUMXOESPROC glClearAccumxOESproc = 0;
void APIENTRY glClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	if (!glClearAccumxOESproc) return;
	glClearAccumxOESproc(red, green, blue, alpha);
}
PFNGLCOLOR3XOESPROC glColor3xOESproc = 0;
void APIENTRY glColor3xOES(GLfixed red, GLfixed green, GLfixed blue) {
	if (!glColor3xOESproc) return;
	glColor3xOESproc(red, green, blue);
}
PFNGLCOLOR3XVOESPROC glColor3xvOESproc = 0;
void APIENTRY glColor3xvOES(const GLfixed* components) {
	if (!glColor3xvOESproc) return;
	glColor3xvOESproc(components);
}
PFNGLCOLOR4XVOESPROC glColor4xvOESproc = 0;
void APIENTRY glColor4xvOES(const GLfixed* components) {
	if (!glColor4xvOESproc) return;
	glColor4xvOESproc(components);
}
PFNGLCONVOLUTIONPARAMETERXOESPROC glConvolutionParameterxOESproc = 0;
void APIENTRY glConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param) {
	if (!glConvolutionParameterxOESproc) return;
	glConvolutionParameterxOESproc(target, pname, param);
}
PFNGLCONVOLUTIONPARAMETERXVOESPROC glConvolutionParameterxvOESproc = 0;
void APIENTRY glConvolutionParameterxvOES(GLenum target, GLenum pname, const GLfixed* params) {
	if (!glConvolutionParameterxvOESproc) return;
	glConvolutionParameterxvOESproc(target, pname, params);
}
PFNGLEVALCOORD1XOESPROC glEvalCoord1xOESproc = 0;
void APIENTRY glEvalCoord1xOES(GLfixed u) {
	if (!glEvalCoord1xOESproc) return;
	glEvalCoord1xOESproc(u);
}
PFNGLEVALCOORD1XVOESPROC glEvalCoord1xvOESproc = 0;
void APIENTRY glEvalCoord1xvOES(const GLfixed* coords) {
	if (!glEvalCoord1xvOESproc) return;
	glEvalCoord1xvOESproc(coords);
}
PFNGLEVALCOORD2XOESPROC glEvalCoord2xOESproc = 0;
void APIENTRY glEvalCoord2xOES(GLfixed u, GLfixed v) {
	if (!glEvalCoord2xOESproc) return;
	glEvalCoord2xOESproc(u, v);
}
PFNGLEVALCOORD2XVOESPROC glEvalCoord2xvOESproc = 0;
void APIENTRY glEvalCoord2xvOES(const GLfixed* coords) {
	if (!glEvalCoord2xvOESproc) return;
	glEvalCoord2xvOESproc(coords);
}
PFNGLFEEDBACKBUFFERXOESPROC glFeedbackBufferxOESproc = 0;
void APIENTRY glFeedbackBufferxOES(GLsizei n, GLenum type, const GLfixed* buffer) {
	if (!glFeedbackBufferxOESproc) return;
	glFeedbackBufferxOESproc(n, type, buffer);
}
PFNGLGETCONVOLUTIONPARAMETERXVOESPROC glGetConvolutionParameterxvOESproc = 0;
void APIENTRY glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed* params) {
	if (!glGetConvolutionParameterxvOESproc) return;
	glGetConvolutionParameterxvOESproc(target, pname, params);
}
PFNGLGETHISTOGRAMPARAMETERXVOESPROC glGetHistogramParameterxvOESproc = 0;
void APIENTRY glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed* params) {
	if (!glGetHistogramParameterxvOESproc) return;
	glGetHistogramParameterxvOESproc(target, pname, params);
}
PFNGLGETLIGHTXOESPROC glGetLightxOESproc = 0;
void APIENTRY glGetLightxOES(GLenum light, GLenum pname, GLfixed* params) {
	if (!glGetLightxOESproc) return;
	glGetLightxOESproc(light, pname, params);
}
PFNGLGETMAPXVOESPROC glGetMapxvOESproc = 0;
void APIENTRY glGetMapxvOES(GLenum target, GLenum query, GLfixed* v) {
	if (!glGetMapxvOESproc) return;
	glGetMapxvOESproc(target, query, v);
}
PFNGLGETMATERIALXOESPROC glGetMaterialxOESproc = 0;
void APIENTRY glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
	if (!glGetMaterialxOESproc) return;
	glGetMaterialxOESproc(face, pname, param);
}
PFNGLGETPIXELMAPXVPROC glGetPixelMapxvproc = 0;
void APIENTRY glGetPixelMapxv(GLenum map, GLint size, GLfixed* values) {
	if (!glGetPixelMapxvproc) return;
	glGetPixelMapxvproc(map, size, values);
}
PFNGLGETTEXGENXVOESPROC glGetTexGenxvOESproc = 0;
void APIENTRY glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed* params) {
	if (!glGetTexGenxvOESproc) return;
	glGetTexGenxvOESproc(coord, pname, params);
}
PFNGLGETTEXLEVELPARAMETERXVOESPROC glGetTexLevelParameterxvOESproc = 0;
void APIENTRY glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed* params) {
	if (!glGetTexLevelParameterxvOESproc) return;
	glGetTexLevelParameterxvOESproc(target, level, pname, params);
}
PFNGLINDEXXOESPROC glIndexxOESproc = 0;
void APIENTRY glIndexxOES(GLfixed component) {
	if (!glIndexxOESproc) return;
	glIndexxOESproc(component);
}
PFNGLINDEXXVOESPROC glIndexxvOESproc = 0;
void APIENTRY glIndexxvOES(const GLfixed* component) {
	if (!glIndexxvOESproc) return;
	glIndexxvOESproc(component);
}
PFNGLLOADTRANSPOSEMATRIXXOESPROC glLoadTransposeMatrixxOESproc = 0;
void APIENTRY glLoadTransposeMatrixxOES(const GLfixed* m) {
	if (!glLoadTransposeMatrixxOESproc) return;
	glLoadTransposeMatrixxOESproc(m);
}
PFNGLMAP1XOESPROC glMap1xOESproc = 0;
void APIENTRY glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points) {
	if (!glMap1xOESproc) return;
	glMap1xOESproc(target, u1, u2, stride, order, points);
}
PFNGLMAP2XOESPROC glMap2xOESproc = 0;
void APIENTRY glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points) {
	if (!glMap2xOESproc) return;
	glMap2xOESproc(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
PFNGLMAPGRID1XOESPROC glMapGrid1xOESproc = 0;
void APIENTRY glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2) {
	if (!glMapGrid1xOESproc) return;
	glMapGrid1xOESproc(n, u1, u2);
}
PFNGLMAPGRID2XOESPROC glMapGrid2xOESproc = 0;
void APIENTRY glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2) {
	if (!glMapGrid2xOESproc) return;
	glMapGrid2xOESproc(n, u1, u2, v1, v2);
}
PFNGLMULTTRANSPOSEMATRIXXOESPROC glMultTransposeMatrixxOESproc = 0;
void APIENTRY glMultTransposeMatrixxOES(const GLfixed* m) {
	if (!glMultTransposeMatrixxOESproc) return;
	glMultTransposeMatrixxOESproc(m);
}
PFNGLMULTITEXCOORD1XOESPROC glMultiTexCoord1xOESproc = 0;
void APIENTRY glMultiTexCoord1xOES(GLenum texture, GLfixed s) {
	if (!glMultiTexCoord1xOESproc) return;
	glMultiTexCoord1xOESproc(texture, s);
}
PFNGLMULTITEXCOORD1XVOESPROC glMultiTexCoord1xvOESproc = 0;
void APIENTRY glMultiTexCoord1xvOES(GLenum texture, const GLfixed* coords) {
	if (!glMultiTexCoord1xvOESproc) return;
	glMultiTexCoord1xvOESproc(texture, coords);
}
PFNGLMULTITEXCOORD2XOESPROC glMultiTexCoord2xOESproc = 0;
void APIENTRY glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t) {
	if (!glMultiTexCoord2xOESproc) return;
	glMultiTexCoord2xOESproc(texture, s, t);
}
PFNGLMULTITEXCOORD2XVOESPROC glMultiTexCoord2xvOESproc = 0;
void APIENTRY glMultiTexCoord2xvOES(GLenum texture, const GLfixed* coords) {
	if (!glMultiTexCoord2xvOESproc) return;
	glMultiTexCoord2xvOESproc(texture, coords);
}
PFNGLMULTITEXCOORD3XOESPROC glMultiTexCoord3xOESproc = 0;
void APIENTRY glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r) {
	if (!glMultiTexCoord3xOESproc) return;
	glMultiTexCoord3xOESproc(texture, s, t, r);
}
PFNGLMULTITEXCOORD3XVOESPROC glMultiTexCoord3xvOESproc = 0;
void APIENTRY glMultiTexCoord3xvOES(GLenum texture, const GLfixed* coords) {
	if (!glMultiTexCoord3xvOESproc) return;
	glMultiTexCoord3xvOESproc(texture, coords);
}
PFNGLMULTITEXCOORD4XVOESPROC glMultiTexCoord4xvOESproc = 0;
void APIENTRY glMultiTexCoord4xvOES(GLenum texture, const GLfixed* coords) {
	if (!glMultiTexCoord4xvOESproc) return;
	glMultiTexCoord4xvOESproc(texture, coords);
}
PFNGLNORMAL3XVOESPROC glNormal3xvOESproc = 0;
void APIENTRY glNormal3xvOES(const GLfixed* coords) {
	if (!glNormal3xvOESproc) return;
	glNormal3xvOESproc(coords);
}
PFNGLPASSTHROUGHXOESPROC glPassThroughxOESproc = 0;
void APIENTRY glPassThroughxOES(GLfixed token) {
	if (!glPassThroughxOESproc) return;
	glPassThroughxOESproc(token);
}
PFNGLPIXELMAPXPROC glPixelMapxproc = 0;
void APIENTRY glPixelMapx(GLenum map, GLint size, const GLfixed* values) {
	if (!glPixelMapxproc) return;
	glPixelMapxproc(map, size, values);
}
PFNGLPIXELSTOREXPROC glPixelStorexproc = 0;
void APIENTRY glPixelStorex(GLenum pname, GLfixed param) {
	if (!glPixelStorexproc) return;
	glPixelStorexproc(pname, param);
}
PFNGLPIXELTRANSFERXOESPROC glPixelTransferxOESproc = 0;
void APIENTRY glPixelTransferxOES(GLenum pname, GLfixed param) {
	if (!glPixelTransferxOESproc) return;
	glPixelTransferxOESproc(pname, param);
}
PFNGLPIXELZOOMXOESPROC glPixelZoomxOESproc = 0;
void APIENTRY glPixelZoomxOES(GLfixed xfactor, GLfixed yfactor) {
	if (!glPixelZoomxOESproc) return;
	glPixelZoomxOESproc(xfactor, yfactor);
}
PFNGLPRIORITIZETEXTURESXOESPROC glPrioritizeTexturesxOESproc = 0;
void APIENTRY glPrioritizeTexturesxOES(GLsizei n, const GLuint* textures, const GLfixed* priorities) {
	if (!glPrioritizeTexturesxOESproc) return;
	glPrioritizeTexturesxOESproc(n, textures, priorities);
}
PFNGLRASTERPOS2XOESPROC glRasterPos2xOESproc = 0;
void APIENTRY glRasterPos2xOES(GLfixed x, GLfixed y) {
	if (!glRasterPos2xOESproc) return;
	glRasterPos2xOESproc(x, y);
}
PFNGLRASTERPOS2XVOESPROC glRasterPos2xvOESproc = 0;
void APIENTRY glRasterPos2xvOES(const GLfixed* coords) {
	if (!glRasterPos2xvOESproc) return;
	glRasterPos2xvOESproc(coords);
}
PFNGLRASTERPOS3XOESPROC glRasterPos3xOESproc = 0;
void APIENTRY glRasterPos3xOES(GLfixed x, GLfixed y, GLfixed z) {
	if (!glRasterPos3xOESproc) return;
	glRasterPos3xOESproc(x, y, z);
}
PFNGLRASTERPOS3XVOESPROC glRasterPos3xvOESproc = 0;
void APIENTRY glRasterPos3xvOES(const GLfixed* coords) {
	if (!glRasterPos3xvOESproc) return;
	glRasterPos3xvOESproc(coords);
}
PFNGLRASTERPOS4XOESPROC glRasterPos4xOESproc = 0;
void APIENTRY glRasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w) {
	if (!glRasterPos4xOESproc) return;
	glRasterPos4xOESproc(x, y, z, w);
}
PFNGLRASTERPOS4XVOESPROC glRasterPos4xvOESproc = 0;
void APIENTRY glRasterPos4xvOES(const GLfixed* coords) {
	if (!glRasterPos4xvOESproc) return;
	glRasterPos4xvOESproc(coords);
}
PFNGLRECTXOESPROC glRectxOESproc = 0;
void APIENTRY glRectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2) {
	if (!glRectxOESproc) return;
	glRectxOESproc(x1, y1, x2, y2);
}
PFNGLRECTXVOESPROC glRectxvOESproc = 0;
void APIENTRY glRectxvOES(const GLfixed* v1, const GLfixed* v2) {
	if (!glRectxvOESproc) return;
	glRectxvOESproc(v1, v2);
}
PFNGLTEXCOORD1XOESPROC glTexCoord1xOESproc = 0;
void APIENTRY glTexCoord1xOES(GLfixed s) {
	if (!glTexCoord1xOESproc) return;
	glTexCoord1xOESproc(s);
}
PFNGLTEXCOORD1XVOESPROC glTexCoord1xvOESproc = 0;
void APIENTRY glTexCoord1xvOES(const GLfixed* coords) {
	if (!glTexCoord1xvOESproc) return;
	glTexCoord1xvOESproc(coords);
}
PFNGLTEXCOORD2XOESPROC glTexCoord2xOESproc = 0;
void APIENTRY glTexCoord2xOES(GLfixed s, GLfixed t) {
	if (!glTexCoord2xOESproc) return;
	glTexCoord2xOESproc(s, t);
}
PFNGLTEXCOORD2XVOESPROC glTexCoord2xvOESproc = 0;
void APIENTRY glTexCoord2xvOES(const GLfixed* coords) {
	if (!glTexCoord2xvOESproc) return;
	glTexCoord2xvOESproc(coords);
}
PFNGLTEXCOORD3XOESPROC glTexCoord3xOESproc = 0;
void APIENTRY glTexCoord3xOES(GLfixed s, GLfixed t, GLfixed r) {
	if (!glTexCoord3xOESproc) return;
	glTexCoord3xOESproc(s, t, r);
}
PFNGLTEXCOORD3XVOESPROC glTexCoord3xvOESproc = 0;
void APIENTRY glTexCoord3xvOES(const GLfixed* coords) {
	if (!glTexCoord3xvOESproc) return;
	glTexCoord3xvOESproc(coords);
}
PFNGLTEXCOORD4XOESPROC glTexCoord4xOESproc = 0;
void APIENTRY glTexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	if (!glTexCoord4xOESproc) return;
	glTexCoord4xOESproc(s, t, r, q);
}
PFNGLTEXCOORD4XVOESPROC glTexCoord4xvOESproc = 0;
void APIENTRY glTexCoord4xvOES(const GLfixed* coords) {
	if (!glTexCoord4xvOESproc) return;
	glTexCoord4xvOESproc(coords);
}
PFNGLTEXGENXOESPROC glTexGenxOESproc = 0;
void APIENTRY glTexGenxOES(GLenum coord, GLenum pname, GLfixed param) {
	if (!glTexGenxOESproc) return;
	glTexGenxOESproc(coord, pname, param);
}
PFNGLTEXGENXVOESPROC glTexGenxvOESproc = 0;
void APIENTRY glTexGenxvOES(GLenum coord, GLenum pname, const GLfixed* params) {
	if (!glTexGenxvOESproc) return;
	glTexGenxvOESproc(coord, pname, params);
}
PFNGLVERTEX2XOESPROC glVertex2xOESproc = 0;
void APIENTRY glVertex2xOES(GLfixed x) {
	if (!glVertex2xOESproc) return;
	glVertex2xOESproc(x);
}
PFNGLVERTEX2XVOESPROC glVertex2xvOESproc = 0;
void APIENTRY glVertex2xvOES(const GLfixed* coords) {
	if (!glVertex2xvOESproc) return;
	glVertex2xvOESproc(coords);
}
PFNGLVERTEX3XOESPROC glVertex3xOESproc = 0;
void APIENTRY glVertex3xOES(GLfixed x, GLfixed y) {
	if (!glVertex3xOESproc) return;
	glVertex3xOESproc(x, y);
}
PFNGLVERTEX3XVOESPROC glVertex3xvOESproc = 0;
void APIENTRY glVertex3xvOES(const GLfixed* coords) {
	if (!glVertex3xvOESproc) return;
	glVertex3xvOESproc(coords);
}
PFNGLVERTEX4XOESPROC glVertex4xOESproc = 0;
void APIENTRY glVertex4xOES(GLfixed x, GLfixed y, GLfixed z) {
	if (!glVertex4xOESproc) return;
	glVertex4xOESproc(x, y, z);
}
PFNGLVERTEX4XVOESPROC glVertex4xvOESproc = 0;
void APIENTRY glVertex4xvOES(const GLfixed* coords) {
	if (!glVertex4xvOESproc) return;
	glVertex4xvOESproc(coords);
}
PFNGLQUERYMATRIXXOESPROC glQueryMatrixxOESproc = 0;
GLbitfield APIENTRY glQueryMatrixxOES(GLfixed* mantissa, GLint* exponent) {
	if (!glQueryMatrixxOESproc) return 0;
	return glQueryMatrixxOESproc(mantissa, exponent);
}
PFNGLCLEARDEPTHFOESPROC glClearDepthfOESproc = 0;
void APIENTRY glClearDepthfOES(GLclampf depth) {
	if (!glClearDepthfOESproc) return;
	glClearDepthfOESproc(depth);
}
PFNGLCLIPPLANEFOESPROC glClipPlanefOESproc = 0;
void APIENTRY glClipPlanefOES(GLenum plane, const GLfloat* equation) {
	if (!glClipPlanefOESproc) return;
	glClipPlanefOESproc(plane, equation);
}
PFNGLDEPTHRANGEFOESPROC glDepthRangefOESproc = 0;
void APIENTRY glDepthRangefOES(GLclampf n, GLclampf f) {
	if (!glDepthRangefOESproc) return;
	glDepthRangefOESproc(n, f);
}
PFNGLFRUSTUMFOESPROC glFrustumfOESproc = 0;
void APIENTRY glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	if (!glFrustumfOESproc) return;
	glFrustumfOESproc(l, r, b, t, n, f);
}
PFNGLGETCLIPPLANEFOESPROC glGetClipPlanefOESproc = 0;
void APIENTRY glGetClipPlanefOES(GLenum plane, GLfloat* equation) {
	if (!glGetClipPlanefOESproc) return;
	glGetClipPlanefOESproc(plane, equation);
}
PFNGLORTHOFOESPROC glOrthofOESproc = 0;
void APIENTRY glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
	if (!glOrthofOESproc) return;
	glOrthofOESproc(l, r, b, t, n, f);
}
PFNGLTBUFFERMASK3DFXPROC glTbufferMask3DFXproc = 0;
void APIENTRY glTbufferMask3DFX(GLuint mask) {
	if (!glTbufferMask3DFXproc) return;
	glTbufferMask3DFXproc(mask);
}
PFNGLDEBUGMESSAGEENABLEAMDPROC glDebugMessageEnableAMDproc = 0;
void APIENTRY glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) {
	if (!glDebugMessageEnableAMDproc) return;
	glDebugMessageEnableAMDproc(category, severity, count, ids, enabled);
}
PFNGLDEBUGMESSAGEINSERTAMDPROC glDebugMessageInsertAMDproc = 0;
void APIENTRY glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar* buf) {
	if (!glDebugMessageInsertAMDproc) return;
	glDebugMessageInsertAMDproc(category, severity, id, length, buf);
}
PFNGLDEBUGMESSAGECALLBACKAMDPROC glDebugMessageCallbackAMDproc = 0;
void APIENTRY glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, void* userParam) {
	if (!glDebugMessageCallbackAMDproc) return;
	glDebugMessageCallbackAMDproc(callback, userParam);
}
PFNGLGETDEBUGMESSAGELOGAMDPROC glGetDebugMessageLogAMDproc = 0;
GLuint APIENTRY glGetDebugMessageLogAMD(GLuint count, GLsizei bufSize, GLenum* categories, GLenum* severities, GLuint* ids, GLsizei* lengths, GLchar* message) {
	if (!glGetDebugMessageLogAMDproc) return 0;
	return glGetDebugMessageLogAMDproc(count, bufSize, categories, severities, ids, lengths, message);
}
PFNGLBLENDFUNCINDEXEDAMDPROC glBlendFuncIndexedAMDproc = 0;
void APIENTRY glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst) {
	if (!glBlendFuncIndexedAMDproc) return;
	glBlendFuncIndexedAMDproc(buf, src, dst);
}
PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC glBlendFuncSeparateIndexedAMDproc = 0;
void APIENTRY glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	if (!glBlendFuncSeparateIndexedAMDproc) return;
	glBlendFuncSeparateIndexedAMDproc(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
PFNGLBLENDEQUATIONINDEXEDAMDPROC glBlendEquationIndexedAMDproc = 0;
void APIENTRY glBlendEquationIndexedAMD(GLuint buf, GLenum mode) {
	if (!glBlendEquationIndexedAMDproc) return;
	glBlendEquationIndexedAMDproc(buf, mode);
}
PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC glBlendEquationSeparateIndexedAMDproc = 0;
void APIENTRY glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	if (!glBlendEquationSeparateIndexedAMDproc) return;
	glBlendEquationSeparateIndexedAMDproc(buf, modeRGB, modeAlpha);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC glRenderbufferStorageMultisampleAdvancedAMDproc = 0;
void APIENTRY glRenderbufferStorageMultisampleAdvancedAMD(GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glRenderbufferStorageMultisampleAdvancedAMDproc) return;
	glRenderbufferStorageMultisampleAdvancedAMDproc(target, samples, storageSamples, internalformat, width, height);
}
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC glNamedRenderbufferStorageMultisampleAdvancedAMDproc = 0;
void APIENTRY glNamedRenderbufferStorageMultisampleAdvancedAMD(GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glNamedRenderbufferStorageMultisampleAdvancedAMDproc) return;
	glNamedRenderbufferStorageMultisampleAdvancedAMDproc(renderbuffer, samples, storageSamples, internalformat, width, height);
}
PFNGLFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC glFramebufferSamplePositionsfvAMDproc = 0;
void APIENTRY glFramebufferSamplePositionsfvAMD(GLenum target, GLuint numsamples, GLuint pixelindex, const GLfloat* values) {
	if (!glFramebufferSamplePositionsfvAMDproc) return;
	glFramebufferSamplePositionsfvAMDproc(target, numsamples, pixelindex, values);
}
PFNGLNAMEDFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC glNamedFramebufferSamplePositionsfvAMDproc = 0;
void APIENTRY glNamedFramebufferSamplePositionsfvAMD(GLuint framebuffer, GLuint numsamples, GLuint pixelindex, const GLfloat* values) {
	if (!glNamedFramebufferSamplePositionsfvAMDproc) return;
	glNamedFramebufferSamplePositionsfvAMDproc(framebuffer, numsamples, pixelindex, values);
}
PFNGLGETFRAMEBUFFERPARAMETERFVAMDPROC glGetFramebufferParameterfvAMDproc = 0;
void APIENTRY glGetFramebufferParameterfvAMD(GLenum target, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat* values) {
	if (!glGetFramebufferParameterfvAMDproc) return;
	glGetFramebufferParameterfvAMDproc(target, pname, numsamples, pixelindex, size, values);
}
PFNGLGETNAMEDFRAMEBUFFERPARAMETERFVAMDPROC glGetNamedFramebufferParameterfvAMDproc = 0;
void APIENTRY glGetNamedFramebufferParameterfvAMD(GLuint framebuffer, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat* values) {
	if (!glGetNamedFramebufferParameterfvAMDproc) return;
	glGetNamedFramebufferParameterfvAMDproc(framebuffer, pname, numsamples, pixelindex, size, values);
}
PFNGLUNIFORM1I64NVPROC glUniform1i64NVproc = 0;
void APIENTRY glUniform1i64NV(GLint location, GLint64EXT x) {
	if (!glUniform1i64NVproc) return;
	glUniform1i64NVproc(location, x);
}
PFNGLUNIFORM2I64NVPROC glUniform2i64NVproc = 0;
void APIENTRY glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y) {
	if (!glUniform2i64NVproc) return;
	glUniform2i64NVproc(location, x, y);
}
PFNGLUNIFORM3I64NVPROC glUniform3i64NVproc = 0;
void APIENTRY glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
	if (!glUniform3i64NVproc) return;
	glUniform3i64NVproc(location, x, y, z);
}
PFNGLUNIFORM4I64NVPROC glUniform4i64NVproc = 0;
void APIENTRY glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
	if (!glUniform4i64NVproc) return;
	glUniform4i64NVproc(location, x, y, z, w);
}
PFNGLUNIFORM1I64VNVPROC glUniform1i64vNVproc = 0;
void APIENTRY glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glUniform1i64vNVproc) return;
	glUniform1i64vNVproc(location, count, value);
}
PFNGLUNIFORM2I64VNVPROC glUniform2i64vNVproc = 0;
void APIENTRY glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glUniform2i64vNVproc) return;
	glUniform2i64vNVproc(location, count, value);
}
PFNGLUNIFORM3I64VNVPROC glUniform3i64vNVproc = 0;
void APIENTRY glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glUniform3i64vNVproc) return;
	glUniform3i64vNVproc(location, count, value);
}
PFNGLUNIFORM4I64VNVPROC glUniform4i64vNVproc = 0;
void APIENTRY glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glUniform4i64vNVproc) return;
	glUniform4i64vNVproc(location, count, value);
}
PFNGLUNIFORM1UI64NVPROC glUniform1ui64NVproc = 0;
void APIENTRY glUniform1ui64NV(GLint location, GLuint64EXT x) {
	if (!glUniform1ui64NVproc) return;
	glUniform1ui64NVproc(location, x);
}
PFNGLUNIFORM2UI64NVPROC glUniform2ui64NVproc = 0;
void APIENTRY glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y) {
	if (!glUniform2ui64NVproc) return;
	glUniform2ui64NVproc(location, x, y);
}
PFNGLUNIFORM3UI64NVPROC glUniform3ui64NVproc = 0;
void APIENTRY glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
	if (!glUniform3ui64NVproc) return;
	glUniform3ui64NVproc(location, x, y, z);
}
PFNGLUNIFORM4UI64NVPROC glUniform4ui64NVproc = 0;
void APIENTRY glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
	if (!glUniform4ui64NVproc) return;
	glUniform4ui64NVproc(location, x, y, z, w);
}
PFNGLUNIFORM1UI64VNVPROC glUniform1ui64vNVproc = 0;
void APIENTRY glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glUniform1ui64vNVproc) return;
	glUniform1ui64vNVproc(location, count, value);
}
PFNGLUNIFORM2UI64VNVPROC glUniform2ui64vNVproc = 0;
void APIENTRY glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glUniform2ui64vNVproc) return;
	glUniform2ui64vNVproc(location, count, value);
}
PFNGLUNIFORM3UI64VNVPROC glUniform3ui64vNVproc = 0;
void APIENTRY glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glUniform3ui64vNVproc) return;
	glUniform3ui64vNVproc(location, count, value);
}
PFNGLUNIFORM4UI64VNVPROC glUniform4ui64vNVproc = 0;
void APIENTRY glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glUniform4ui64vNVproc) return;
	glUniform4ui64vNVproc(location, count, value);
}
PFNGLGETUNIFORMI64VNVPROC glGetUniformi64vNVproc = 0;
void APIENTRY glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT* params) {
	if (!glGetUniformi64vNVproc) return;
	glGetUniformi64vNVproc(program, location, params);
}
PFNGLGETUNIFORMUI64VNVPROC glGetUniformui64vNVproc = 0;
void APIENTRY glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT* params) {
	if (!glGetUniformui64vNVproc) return;
	glGetUniformui64vNVproc(program, location, params);
}
PFNGLPROGRAMUNIFORM1I64NVPROC glProgramUniform1i64NVproc = 0;
void APIENTRY glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x) {
	if (!glProgramUniform1i64NVproc) return;
	glProgramUniform1i64NVproc(program, location, x);
}
PFNGLPROGRAMUNIFORM2I64NVPROC glProgramUniform2i64NVproc = 0;
void APIENTRY glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y) {
	if (!glProgramUniform2i64NVproc) return;
	glProgramUniform2i64NVproc(program, location, x, y);
}
PFNGLPROGRAMUNIFORM3I64NVPROC glProgramUniform3i64NVproc = 0;
void APIENTRY glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
	if (!glProgramUniform3i64NVproc) return;
	glProgramUniform3i64NVproc(program, location, x, y, z);
}
PFNGLPROGRAMUNIFORM4I64NVPROC glProgramUniform4i64NVproc = 0;
void APIENTRY glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
	if (!glProgramUniform4i64NVproc) return;
	glProgramUniform4i64NVproc(program, location, x, y, z, w);
}
PFNGLPROGRAMUNIFORM1I64VNVPROC glProgramUniform1i64vNVproc = 0;
void APIENTRY glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glProgramUniform1i64vNVproc) return;
	glProgramUniform1i64vNVproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2I64VNVPROC glProgramUniform2i64vNVproc = 0;
void APIENTRY glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glProgramUniform2i64vNVproc) return;
	glProgramUniform2i64vNVproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3I64VNVPROC glProgramUniform3i64vNVproc = 0;
void APIENTRY glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glProgramUniform3i64vNVproc) return;
	glProgramUniform3i64vNVproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4I64VNVPROC glProgramUniform4i64vNVproc = 0;
void APIENTRY glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value) {
	if (!glProgramUniform4i64vNVproc) return;
	glProgramUniform4i64vNVproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1UI64NVPROC glProgramUniform1ui64NVproc = 0;
void APIENTRY glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x) {
	if (!glProgramUniform1ui64NVproc) return;
	glProgramUniform1ui64NVproc(program, location, x);
}
PFNGLPROGRAMUNIFORM2UI64NVPROC glProgramUniform2ui64NVproc = 0;
void APIENTRY glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y) {
	if (!glProgramUniform2ui64NVproc) return;
	glProgramUniform2ui64NVproc(program, location, x, y);
}
PFNGLPROGRAMUNIFORM3UI64NVPROC glProgramUniform3ui64NVproc = 0;
void APIENTRY glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
	if (!glProgramUniform3ui64NVproc) return;
	glProgramUniform3ui64NVproc(program, location, x, y, z);
}
PFNGLPROGRAMUNIFORM4UI64NVPROC glProgramUniform4ui64NVproc = 0;
void APIENTRY glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
	if (!glProgramUniform4ui64NVproc) return;
	glProgramUniform4ui64NVproc(program, location, x, y, z, w);
}
PFNGLPROGRAMUNIFORM1UI64VNVPROC glProgramUniform1ui64vNVproc = 0;
void APIENTRY glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glProgramUniform1ui64vNVproc) return;
	glProgramUniform1ui64vNVproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2UI64VNVPROC glProgramUniform2ui64vNVproc = 0;
void APIENTRY glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glProgramUniform2ui64vNVproc) return;
	glProgramUniform2ui64vNVproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3UI64VNVPROC glProgramUniform3ui64vNVproc = 0;
void APIENTRY glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glProgramUniform3ui64vNVproc) return;
	glProgramUniform3ui64vNVproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4UI64VNVPROC glProgramUniform4ui64vNVproc = 0;
void APIENTRY glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glProgramUniform4ui64vNVproc) return;
	glProgramUniform4ui64vNVproc(program, location, count, value);
}
PFNGLVERTEXATTRIBPARAMETERIAMDPROC glVertexAttribParameteriAMDproc = 0;
void APIENTRY glVertexAttribParameteriAMD(GLuint index, GLenum pname, GLint param) {
	if (!glVertexAttribParameteriAMDproc) return;
	glVertexAttribParameteriAMDproc(index, pname, param);
}
PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC glMultiDrawArraysIndirectAMDproc = 0;
void APIENTRY glMultiDrawArraysIndirectAMD(GLenum mode, const void* indirect, GLsizei primcount, GLsizei stride) {
	if (!glMultiDrawArraysIndirectAMDproc) return;
	glMultiDrawArraysIndirectAMDproc(mode, indirect, primcount, stride);
}
PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC glMultiDrawElementsIndirectAMDproc = 0;
void APIENTRY glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, const void* indirect, GLsizei primcount, GLsizei stride) {
	if (!glMultiDrawElementsIndirectAMDproc) return;
	glMultiDrawElementsIndirectAMDproc(mode, type, indirect, primcount, stride);
}
PFNGLGENNAMESAMDPROC glGenNamesAMDproc = 0;
void APIENTRY glGenNamesAMD(GLenum identifier, GLuint num, GLuint* names) {
	if (!glGenNamesAMDproc) return;
	glGenNamesAMDproc(identifier, num, names);
}
PFNGLDELETENAMESAMDPROC glDeleteNamesAMDproc = 0;
void APIENTRY glDeleteNamesAMD(GLenum identifier, GLuint num, const GLuint* names) {
	if (!glDeleteNamesAMDproc) return;
	glDeleteNamesAMDproc(identifier, num, names);
}
PFNGLISNAMEAMDPROC glIsNameAMDproc = 0;
GLboolean APIENTRY glIsNameAMD(GLenum identifier, GLuint name) {
	if (!glIsNameAMDproc) return 0;
	return glIsNameAMDproc(identifier, name);
}
PFNGLQUERYOBJECTPARAMETERUIAMDPROC glQueryObjectParameteruiAMDproc = 0;
void APIENTRY glQueryObjectParameteruiAMD(GLenum target, GLuint id, GLenum pname, GLuint param) {
	if (!glQueryObjectParameteruiAMDproc) return;
	glQueryObjectParameteruiAMDproc(target, id, pname, param);
}
PFNGLGETPERFMONITORGROUPSAMDPROC glGetPerfMonitorGroupsAMDproc = 0;
void APIENTRY glGetPerfMonitorGroupsAMD(GLint* numGroups, GLsizei groupsSize, GLuint* groups) {
	if (!glGetPerfMonitorGroupsAMDproc) return;
	glGetPerfMonitorGroupsAMDproc(numGroups, groupsSize, groups);
}
PFNGLGETPERFMONITORCOUNTERSAMDPROC glGetPerfMonitorCountersAMDproc = 0;
void APIENTRY glGetPerfMonitorCountersAMD(GLuint group, GLint* numCounters, GLint* maxActiveCounters, GLsizei counterSize, GLuint* counters) {
	if (!glGetPerfMonitorCountersAMDproc) return;
	glGetPerfMonitorCountersAMDproc(group, numCounters, maxActiveCounters, counterSize, counters);
}
PFNGLGETPERFMONITORGROUPSTRINGAMDPROC glGetPerfMonitorGroupStringAMDproc = 0;
void APIENTRY glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei* length, GLchar* groupString) {
	if (!glGetPerfMonitorGroupStringAMDproc) return;
	glGetPerfMonitorGroupStringAMDproc(group, bufSize, length, groupString);
}
PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC glGetPerfMonitorCounterStringAMDproc = 0;
void APIENTRY glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei* length, GLchar* counterString) {
	if (!glGetPerfMonitorCounterStringAMDproc) return;
	glGetPerfMonitorCounterStringAMDproc(group, counter, bufSize, length, counterString);
}
PFNGLGETPERFMONITORCOUNTERINFOAMDPROC glGetPerfMonitorCounterInfoAMDproc = 0;
void APIENTRY glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, void* data) {
	if (!glGetPerfMonitorCounterInfoAMDproc) return;
	glGetPerfMonitorCounterInfoAMDproc(group, counter, pname, data);
}
PFNGLGENPERFMONITORSAMDPROC glGenPerfMonitorsAMDproc = 0;
void APIENTRY glGenPerfMonitorsAMD(GLsizei n, GLuint* monitors) {
	if (!glGenPerfMonitorsAMDproc) return;
	glGenPerfMonitorsAMDproc(n, monitors);
}
PFNGLDELETEPERFMONITORSAMDPROC glDeletePerfMonitorsAMDproc = 0;
void APIENTRY glDeletePerfMonitorsAMD(GLsizei n, GLuint* monitors) {
	if (!glDeletePerfMonitorsAMDproc) return;
	glDeletePerfMonitorsAMDproc(n, monitors);
}
PFNGLSELECTPERFMONITORCOUNTERSAMDPROC glSelectPerfMonitorCountersAMDproc = 0;
void APIENTRY glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint* counterList) {
	if (!glSelectPerfMonitorCountersAMDproc) return;
	glSelectPerfMonitorCountersAMDproc(monitor, enable, group, numCounters, counterList);
}
PFNGLBEGINPERFMONITORAMDPROC glBeginPerfMonitorAMDproc = 0;
void APIENTRY glBeginPerfMonitorAMD(GLuint monitor) {
	if (!glBeginPerfMonitorAMDproc) return;
	glBeginPerfMonitorAMDproc(monitor);
}
PFNGLENDPERFMONITORAMDPROC glEndPerfMonitorAMDproc = 0;
void APIENTRY glEndPerfMonitorAMD(GLuint monitor) {
	if (!glEndPerfMonitorAMDproc) return;
	glEndPerfMonitorAMDproc(monitor);
}
PFNGLGETPERFMONITORCOUNTERDATAAMDPROC glGetPerfMonitorCounterDataAMDproc = 0;
void APIENTRY glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint* data, GLint* bytesWritten) {
	if (!glGetPerfMonitorCounterDataAMDproc) return;
	glGetPerfMonitorCounterDataAMDproc(monitor, pname, dataSize, data, bytesWritten);
}
PFNGLSETMULTISAMPLEFVAMDPROC glSetMultisamplefvAMDproc = 0;
void APIENTRY glSetMultisamplefvAMD(GLenum pname, GLuint index, const GLfloat* val) {
	if (!glSetMultisamplefvAMDproc) return;
	glSetMultisamplefvAMDproc(pname, index, val);
}
PFNGLTEXSTORAGESPARSEAMDPROC glTexStorageSparseAMDproc = 0;
void APIENTRY glTexStorageSparseAMD(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
	if (!glTexStorageSparseAMDproc) return;
	glTexStorageSparseAMDproc(target, internalFormat, width, height, depth, layers, flags);
}
PFNGLTEXTURESTORAGESPARSEAMDPROC glTextureStorageSparseAMDproc = 0;
void APIENTRY glTextureStorageSparseAMD(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
	if (!glTextureStorageSparseAMDproc) return;
	glTextureStorageSparseAMDproc(texture, target, internalFormat, width, height, depth, layers, flags);
}
PFNGLSTENCILOPVALUEAMDPROC glStencilOpValueAMDproc = 0;
void APIENTRY glStencilOpValueAMD(GLenum face, GLuint value) {
	if (!glStencilOpValueAMDproc) return;
	glStencilOpValueAMDproc(face, value);
}
PFNGLTESSELLATIONFACTORAMDPROC glTessellationFactorAMDproc = 0;
void APIENTRY glTessellationFactorAMD(GLfloat factor) {
	if (!glTessellationFactorAMDproc) return;
	glTessellationFactorAMDproc(factor);
}
PFNGLTESSELLATIONMODEAMDPROC glTessellationModeAMDproc = 0;
void APIENTRY glTessellationModeAMD(GLenum mode) {
	if (!glTessellationModeAMDproc) return;
	glTessellationModeAMDproc(mode);
}
PFNGLELEMENTPOINTERAPPLEPROC glElementPointerAPPLEproc = 0;
void APIENTRY glElementPointerAPPLE(GLenum type, const void* pointer) {
	if (!glElementPointerAPPLEproc) return;
	glElementPointerAPPLEproc(type, pointer);
}
PFNGLDRAWELEMENTARRAYAPPLEPROC glDrawElementArrayAPPLEproc = 0;
void APIENTRY glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count) {
	if (!glDrawElementArrayAPPLEproc) return;
	glDrawElementArrayAPPLEproc(mode, first, count);
}
PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC glDrawRangeElementArrayAPPLEproc = 0;
void APIENTRY glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count) {
	if (!glDrawRangeElementArrayAPPLEproc) return;
	glDrawRangeElementArrayAPPLEproc(mode, start, end, first, count);
}
PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC glMultiDrawElementArrayAPPLEproc = 0;
void APIENTRY glMultiDrawElementArrayAPPLE(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount) {
	if (!glMultiDrawElementArrayAPPLEproc) return;
	glMultiDrawElementArrayAPPLEproc(mode, first, count, primcount);
}
PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC glMultiDrawRangeElementArrayAPPLEproc = 0;
void APIENTRY glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint* first, const GLsizei* count, GLsizei primcount) {
	if (!glMultiDrawRangeElementArrayAPPLEproc) return;
	glMultiDrawRangeElementArrayAPPLEproc(mode, start, end, first, count, primcount);
}
PFNGLGENFENCESAPPLEPROC glGenFencesAPPLEproc = 0;
void APIENTRY glGenFencesAPPLE(GLsizei n, GLuint* fences) {
	if (!glGenFencesAPPLEproc) return;
	glGenFencesAPPLEproc(n, fences);
}
PFNGLDELETEFENCESAPPLEPROC glDeleteFencesAPPLEproc = 0;
void APIENTRY glDeleteFencesAPPLE(GLsizei n, const GLuint* fences) {
	if (!glDeleteFencesAPPLEproc) return;
	glDeleteFencesAPPLEproc(n, fences);
}
PFNGLSETFENCEAPPLEPROC glSetFenceAPPLEproc = 0;
void APIENTRY glSetFenceAPPLE(GLuint fence) {
	if (!glSetFenceAPPLEproc) return;
	glSetFenceAPPLEproc(fence);
}
PFNGLISFENCEAPPLEPROC glIsFenceAPPLEproc = 0;
GLboolean APIENTRY glIsFenceAPPLE(GLuint fence) {
	if (!glIsFenceAPPLEproc) return 0;
	return glIsFenceAPPLEproc(fence);
}
PFNGLTESTFENCEAPPLEPROC glTestFenceAPPLEproc = 0;
GLboolean APIENTRY glTestFenceAPPLE(GLuint fence) {
	if (!glTestFenceAPPLEproc) return 0;
	return glTestFenceAPPLEproc(fence);
}
PFNGLFINISHFENCEAPPLEPROC glFinishFenceAPPLEproc = 0;
void APIENTRY glFinishFenceAPPLE(GLuint fence) {
	if (!glFinishFenceAPPLEproc) return;
	glFinishFenceAPPLEproc(fence);
}
PFNGLTESTOBJECTAPPLEPROC glTestObjectAPPLEproc = 0;
GLboolean APIENTRY glTestObjectAPPLE(GLenum object, GLuint name) {
	if (!glTestObjectAPPLEproc) return 0;
	return glTestObjectAPPLEproc(object, name);
}
PFNGLFINISHOBJECTAPPLEPROC glFinishObjectAPPLEproc = 0;
void APIENTRY glFinishObjectAPPLE(GLenum object, GLint name) {
	if (!glFinishObjectAPPLEproc) return;
	glFinishObjectAPPLEproc(object, name);
}
PFNGLBUFFERPARAMETERIAPPLEPROC glBufferParameteriAPPLEproc = 0;
void APIENTRY glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param) {
	if (!glBufferParameteriAPPLEproc) return;
	glBufferParameteriAPPLEproc(target, pname, param);
}
PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC glFlushMappedBufferRangeAPPLEproc = 0;
void APIENTRY glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size) {
	if (!glFlushMappedBufferRangeAPPLEproc) return;
	glFlushMappedBufferRangeAPPLEproc(target, offset, size);
}
PFNGLOBJECTPURGEABLEAPPLEPROC glObjectPurgeableAPPLEproc = 0;
GLenum APIENTRY glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option) {
	if (!glObjectPurgeableAPPLEproc) return 0;
	return glObjectPurgeableAPPLEproc(objectType, name, option);
}
PFNGLOBJECTUNPURGEABLEAPPLEPROC glObjectUnpurgeableAPPLEproc = 0;
GLenum APIENTRY glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option) {
	if (!glObjectUnpurgeableAPPLEproc) return 0;
	return glObjectUnpurgeableAPPLEproc(objectType, name, option);
}
PFNGLGETOBJECTPARAMETERIVAPPLEPROC glGetObjectParameterivAPPLEproc = 0;
void APIENTRY glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint* params) {
	if (!glGetObjectParameterivAPPLEproc) return;
	glGetObjectParameterivAPPLEproc(objectType, name, pname, params);
}
PFNGLTEXTURERANGEAPPLEPROC glTextureRangeAPPLEproc = 0;
void APIENTRY glTextureRangeAPPLE(GLenum target, GLsizei length, const void* pointer) {
	if (!glTextureRangeAPPLEproc) return;
	glTextureRangeAPPLEproc(target, length, pointer);
}
PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC glGetTexParameterPointervAPPLEproc = 0;
void APIENTRY glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, void** params) {
	if (!glGetTexParameterPointervAPPLEproc) return;
	glGetTexParameterPointervAPPLEproc(target, pname, params);
}
PFNGLBINDVERTEXARRAYAPPLEPROC glBindVertexArrayAPPLEproc = 0;
void APIENTRY glBindVertexArrayAPPLE(GLuint array) {
	if (!glBindVertexArrayAPPLEproc) return;
	glBindVertexArrayAPPLEproc(array);
}
PFNGLDELETEVERTEXARRAYSAPPLEPROC glDeleteVertexArraysAPPLEproc = 0;
void APIENTRY glDeleteVertexArraysAPPLE(GLsizei n, const GLuint* arrays) {
	if (!glDeleteVertexArraysAPPLEproc) return;
	glDeleteVertexArraysAPPLEproc(n, arrays);
}
PFNGLGENVERTEXARRAYSAPPLEPROC glGenVertexArraysAPPLEproc = 0;
void APIENTRY glGenVertexArraysAPPLE(GLsizei n, GLuint* arrays) {
	if (!glGenVertexArraysAPPLEproc) return;
	glGenVertexArraysAPPLEproc(n, arrays);
}
PFNGLISVERTEXARRAYAPPLEPROC glIsVertexArrayAPPLEproc = 0;
GLboolean APIENTRY glIsVertexArrayAPPLE(GLuint array) {
	if (!glIsVertexArrayAPPLEproc) return 0;
	return glIsVertexArrayAPPLEproc(array);
}
PFNGLVERTEXARRAYRANGEAPPLEPROC glVertexArrayRangeAPPLEproc = 0;
void APIENTRY glVertexArrayRangeAPPLE(GLsizei length, void* pointer) {
	if (!glVertexArrayRangeAPPLEproc) return;
	glVertexArrayRangeAPPLEproc(length, pointer);
}
PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC glFlushVertexArrayRangeAPPLEproc = 0;
void APIENTRY glFlushVertexArrayRangeAPPLE(GLsizei length, void* pointer) {
	if (!glFlushVertexArrayRangeAPPLEproc) return;
	glFlushVertexArrayRangeAPPLEproc(length, pointer);
}
PFNGLVERTEXARRAYPARAMETERIAPPLEPROC glVertexArrayParameteriAPPLEproc = 0;
void APIENTRY glVertexArrayParameteriAPPLE(GLenum pname, GLint param) {
	if (!glVertexArrayParameteriAPPLEproc) return;
	glVertexArrayParameteriAPPLEproc(pname, param);
}
PFNGLENABLEVERTEXATTRIBAPPLEPROC glEnableVertexAttribAPPLEproc = 0;
void APIENTRY glEnableVertexAttribAPPLE(GLuint index, GLenum pname) {
	if (!glEnableVertexAttribAPPLEproc) return;
	glEnableVertexAttribAPPLEproc(index, pname);
}
PFNGLDISABLEVERTEXATTRIBAPPLEPROC glDisableVertexAttribAPPLEproc = 0;
void APIENTRY glDisableVertexAttribAPPLE(GLuint index, GLenum pname) {
	if (!glDisableVertexAttribAPPLEproc) return;
	glDisableVertexAttribAPPLEproc(index, pname);
}
PFNGLISVERTEXATTRIBENABLEDAPPLEPROC glIsVertexAttribEnabledAPPLEproc = 0;
GLboolean APIENTRY glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname) {
	if (!glIsVertexAttribEnabledAPPLEproc) return 0;
	return glIsVertexAttribEnabledAPPLEproc(index, pname);
}
PFNGLMAPVERTEXATTRIB1DAPPLEPROC glMapVertexAttrib1dAPPLEproc = 0;
void APIENTRY glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points) {
	if (!glMapVertexAttrib1dAPPLEproc) return;
	glMapVertexAttrib1dAPPLEproc(index, size, u1, u2, stride, order, points);
}
PFNGLMAPVERTEXATTRIB1FAPPLEPROC glMapVertexAttrib1fAPPLEproc = 0;
void APIENTRY glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points) {
	if (!glMapVertexAttrib1fAPPLEproc) return;
	glMapVertexAttrib1fAPPLEproc(index, size, u1, u2, stride, order, points);
}
PFNGLMAPVERTEXATTRIB2DAPPLEPROC glMapVertexAttrib2dAPPLEproc = 0;
void APIENTRY glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points) {
	if (!glMapVertexAttrib2dAPPLEproc) return;
	glMapVertexAttrib2dAPPLEproc(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
PFNGLMAPVERTEXATTRIB2FAPPLEPROC glMapVertexAttrib2fAPPLEproc = 0;
void APIENTRY glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points) {
	if (!glMapVertexAttrib2fAPPLEproc) return;
	glMapVertexAttrib2fAPPLEproc(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
PFNGLDRAWBUFFERSATIPROC glDrawBuffersATIproc = 0;
void APIENTRY glDrawBuffersATI(GLsizei n, const GLenum* bufs) {
	if (!glDrawBuffersATIproc) return;
	glDrawBuffersATIproc(n, bufs);
}
PFNGLELEMENTPOINTERATIPROC glElementPointerATIproc = 0;
void APIENTRY glElementPointerATI(GLenum type, const void* pointer) {
	if (!glElementPointerATIproc) return;
	glElementPointerATIproc(type, pointer);
}
PFNGLDRAWELEMENTARRAYATIPROC glDrawElementArrayATIproc = 0;
void APIENTRY glDrawElementArrayATI(GLenum mode, GLsizei count) {
	if (!glDrawElementArrayATIproc) return;
	glDrawElementArrayATIproc(mode, count);
}
PFNGLDRAWRANGEELEMENTARRAYATIPROC glDrawRangeElementArrayATIproc = 0;
void APIENTRY glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count) {
	if (!glDrawRangeElementArrayATIproc) return;
	glDrawRangeElementArrayATIproc(mode, start, end, count);
}
PFNGLTEXBUMPPARAMETERIVATIPROC glTexBumpParameterivATIproc = 0;
void APIENTRY glTexBumpParameterivATI(GLenum pname, const GLint* param) {
	if (!glTexBumpParameterivATIproc) return;
	glTexBumpParameterivATIproc(pname, param);
}
PFNGLTEXBUMPPARAMETERFVATIPROC glTexBumpParameterfvATIproc = 0;
void APIENTRY glTexBumpParameterfvATI(GLenum pname, const GLfloat* param) {
	if (!glTexBumpParameterfvATIproc) return;
	glTexBumpParameterfvATIproc(pname, param);
}
PFNGLGETTEXBUMPPARAMETERIVATIPROC glGetTexBumpParameterivATIproc = 0;
void APIENTRY glGetTexBumpParameterivATI(GLenum pname, GLint* param) {
	if (!glGetTexBumpParameterivATIproc) return;
	glGetTexBumpParameterivATIproc(pname, param);
}
PFNGLGETTEXBUMPPARAMETERFVATIPROC glGetTexBumpParameterfvATIproc = 0;
void APIENTRY glGetTexBumpParameterfvATI(GLenum pname, GLfloat* param) {
	if (!glGetTexBumpParameterfvATIproc) return;
	glGetTexBumpParameterfvATIproc(pname, param);
}
PFNGLGENFRAGMENTSHADERSATIPROC glGenFragmentShadersATIproc = 0;
GLuint APIENTRY glGenFragmentShadersATI(GLuint range) {
	if (!glGenFragmentShadersATIproc) return 0;
	return glGenFragmentShadersATIproc(range);
}
PFNGLBINDFRAGMENTSHADERATIPROC glBindFragmentShaderATIproc = 0;
void APIENTRY glBindFragmentShaderATI(GLuint id) {
	if (!glBindFragmentShaderATIproc) return;
	glBindFragmentShaderATIproc(id);
}
PFNGLDELETEFRAGMENTSHADERATIPROC glDeleteFragmentShaderATIproc = 0;
void APIENTRY glDeleteFragmentShaderATI(GLuint id) {
	if (!glDeleteFragmentShaderATIproc) return;
	glDeleteFragmentShaderATIproc(id);
}
PFNGLBEGINFRAGMENTSHADERATIPROC glBeginFragmentShaderATIproc = 0;
void APIENTRY glBeginFragmentShaderATI(void) {
	if (!glBeginFragmentShaderATIproc) return;
	glBeginFragmentShaderATIproc();
}
PFNGLENDFRAGMENTSHADERATIPROC glEndFragmentShaderATIproc = 0;
void APIENTRY glEndFragmentShaderATI(void) {
	if (!glEndFragmentShaderATIproc) return;
	glEndFragmentShaderATIproc();
}
PFNGLPASSTEXCOORDATIPROC glPassTexCoordATIproc = 0;
void APIENTRY glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle) {
	if (!glPassTexCoordATIproc) return;
	glPassTexCoordATIproc(dst, coord, swizzle);
}
PFNGLSAMPLEMAPATIPROC glSampleMapATIproc = 0;
void APIENTRY glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle) {
	if (!glSampleMapATIproc) return;
	glSampleMapATIproc(dst, interp, swizzle);
}
PFNGLCOLORFRAGMENTOP1ATIPROC glColorFragmentOp1ATIproc = 0;
void APIENTRY glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
	if (!glColorFragmentOp1ATIproc) return;
	glColorFragmentOp1ATIproc(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod);
}
PFNGLCOLORFRAGMENTOP2ATIPROC glColorFragmentOp2ATIproc = 0;
void APIENTRY glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
	if (!glColorFragmentOp2ATIproc) return;
	glColorFragmentOp2ATIproc(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);
}
PFNGLCOLORFRAGMENTOP3ATIPROC glColorFragmentOp3ATIproc = 0;
void APIENTRY glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
	if (!glColorFragmentOp3ATIproc) return;
	glColorFragmentOp3ATIproc(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);
}
PFNGLALPHAFRAGMENTOP1ATIPROC glAlphaFragmentOp1ATIproc = 0;
void APIENTRY glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
	if (!glAlphaFragmentOp1ATIproc) return;
	glAlphaFragmentOp1ATIproc(op, dst, dstMod, arg1, arg1Rep, arg1Mod);
}
PFNGLALPHAFRAGMENTOP2ATIPROC glAlphaFragmentOp2ATIproc = 0;
void APIENTRY glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
	if (!glAlphaFragmentOp2ATIproc) return;
	glAlphaFragmentOp2ATIproc(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);
}
PFNGLALPHAFRAGMENTOP3ATIPROC glAlphaFragmentOp3ATIproc = 0;
void APIENTRY glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
	if (!glAlphaFragmentOp3ATIproc) return;
	glAlphaFragmentOp3ATIproc(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);
}
PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glSetFragmentShaderConstantATIproc = 0;
void APIENTRY glSetFragmentShaderConstantATI(GLuint dst, const GLfloat* value) {
	if (!glSetFragmentShaderConstantATIproc) return;
	glSetFragmentShaderConstantATIproc(dst, value);
}
PFNGLMAPOBJECTBUFFERATIPROC glMapObjectBufferATIproc = 0;
void* APIENTRY glMapObjectBufferATI(GLuint buffer) {
	if (!glMapObjectBufferATIproc) return 0;
	return glMapObjectBufferATIproc(buffer);
}
PFNGLUNMAPOBJECTBUFFERATIPROC glUnmapObjectBufferATIproc = 0;
void APIENTRY glUnmapObjectBufferATI(GLuint buffer) {
	if (!glUnmapObjectBufferATIproc) return;
	glUnmapObjectBufferATIproc(buffer);
}
PFNGLPNTRIANGLESIATIPROC glPNTrianglesiATIproc = 0;
void APIENTRY glPNTrianglesiATI(GLenum pname, GLint param) {
	if (!glPNTrianglesiATIproc) return;
	glPNTrianglesiATIproc(pname, param);
}
PFNGLPNTRIANGLESFATIPROC glPNTrianglesfATIproc = 0;
void APIENTRY glPNTrianglesfATI(GLenum pname, GLfloat param) {
	if (!glPNTrianglesfATIproc) return;
	glPNTrianglesfATIproc(pname, param);
}
PFNGLSTENCILOPSEPARATEATIPROC glStencilOpSeparateATIproc = 0;
void APIENTRY glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
	if (!glStencilOpSeparateATIproc) return;
	glStencilOpSeparateATIproc(face, sfail, dpfail, dppass);
}
PFNGLSTENCILFUNCSEPARATEATIPROC glStencilFuncSeparateATIproc = 0;
void APIENTRY glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask) {
	if (!glStencilFuncSeparateATIproc) return;
	glStencilFuncSeparateATIproc(frontfunc, backfunc, ref, mask);
}
PFNGLNEWOBJECTBUFFERATIPROC glNewObjectBufferATIproc = 0;
GLuint APIENTRY glNewObjectBufferATI(GLsizei size, const void* pointer, GLenum usage) {
	if (!glNewObjectBufferATIproc) return 0;
	return glNewObjectBufferATIproc(size, pointer, usage);
}
PFNGLISOBJECTBUFFERATIPROC glIsObjectBufferATIproc = 0;
GLboolean APIENTRY glIsObjectBufferATI(GLuint buffer) {
	if (!glIsObjectBufferATIproc) return 0;
	return glIsObjectBufferATIproc(buffer);
}
PFNGLUPDATEOBJECTBUFFERATIPROC glUpdateObjectBufferATIproc = 0;
void APIENTRY glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, const void* pointer, GLenum preserve) {
	if (!glUpdateObjectBufferATIproc) return;
	glUpdateObjectBufferATIproc(buffer, offset, size, pointer, preserve);
}
PFNGLGETOBJECTBUFFERFVATIPROC glGetObjectBufferfvATIproc = 0;
void APIENTRY glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat* params) {
	if (!glGetObjectBufferfvATIproc) return;
	glGetObjectBufferfvATIproc(buffer, pname, params);
}
PFNGLGETOBJECTBUFFERIVATIPROC glGetObjectBufferivATIproc = 0;
void APIENTRY glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint* params) {
	if (!glGetObjectBufferivATIproc) return;
	glGetObjectBufferivATIproc(buffer, pname, params);
}
PFNGLFREEOBJECTBUFFERATIPROC glFreeObjectBufferATIproc = 0;
void APIENTRY glFreeObjectBufferATI(GLuint buffer) {
	if (!glFreeObjectBufferATIproc) return;
	glFreeObjectBufferATIproc(buffer);
}
PFNGLARRAYOBJECTATIPROC glArrayObjectATIproc = 0;
void APIENTRY glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
	if (!glArrayObjectATIproc) return;
	glArrayObjectATIproc(array, size, type, stride, buffer, offset);
}
PFNGLGETARRAYOBJECTFVATIPROC glGetArrayObjectfvATIproc = 0;
void APIENTRY glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat* params) {
	if (!glGetArrayObjectfvATIproc) return;
	glGetArrayObjectfvATIproc(array, pname, params);
}
PFNGLGETARRAYOBJECTIVATIPROC glGetArrayObjectivATIproc = 0;
void APIENTRY glGetArrayObjectivATI(GLenum array, GLenum pname, GLint* params) {
	if (!glGetArrayObjectivATIproc) return;
	glGetArrayObjectivATIproc(array, pname, params);
}
PFNGLVARIANTARRAYOBJECTATIPROC glVariantArrayObjectATIproc = 0;
void APIENTRY glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
	if (!glVariantArrayObjectATIproc) return;
	glVariantArrayObjectATIproc(id, type, stride, buffer, offset);
}
PFNGLGETVARIANTARRAYOBJECTFVATIPROC glGetVariantArrayObjectfvATIproc = 0;
void APIENTRY glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat* params) {
	if (!glGetVariantArrayObjectfvATIproc) return;
	glGetVariantArrayObjectfvATIproc(id, pname, params);
}
PFNGLGETVARIANTARRAYOBJECTIVATIPROC glGetVariantArrayObjectivATIproc = 0;
void APIENTRY glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint* params) {
	if (!glGetVariantArrayObjectivATIproc) return;
	glGetVariantArrayObjectivATIproc(id, pname, params);
}
PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glVertexAttribArrayObjectATIproc = 0;
void APIENTRY glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset) {
	if (!glVertexAttribArrayObjectATIproc) return;
	glVertexAttribArrayObjectATIproc(index, size, type, normalized, stride, buffer, offset);
}
PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glGetVertexAttribArrayObjectfvATIproc = 0;
void APIENTRY glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat* params) {
	if (!glGetVertexAttribArrayObjectfvATIproc) return;
	glGetVertexAttribArrayObjectfvATIproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glGetVertexAttribArrayObjectivATIproc = 0;
void APIENTRY glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint* params) {
	if (!glGetVertexAttribArrayObjectivATIproc) return;
	glGetVertexAttribArrayObjectivATIproc(index, pname, params);
}
PFNGLVERTEXSTREAM1SATIPROC glVertexStream1sATIproc = 0;
void APIENTRY glVertexStream1sATI(GLenum stream, GLshort x) {
	if (!glVertexStream1sATIproc) return;
	glVertexStream1sATIproc(stream, x);
}
PFNGLVERTEXSTREAM1SVATIPROC glVertexStream1svATIproc = 0;
void APIENTRY glVertexStream1svATI(GLenum stream, const GLshort* coords) {
	if (!glVertexStream1svATIproc) return;
	glVertexStream1svATIproc(stream, coords);
}
PFNGLVERTEXSTREAM1IATIPROC glVertexStream1iATIproc = 0;
void APIENTRY glVertexStream1iATI(GLenum stream, GLint x) {
	if (!glVertexStream1iATIproc) return;
	glVertexStream1iATIproc(stream, x);
}
PFNGLVERTEXSTREAM1IVATIPROC glVertexStream1ivATIproc = 0;
void APIENTRY glVertexStream1ivATI(GLenum stream, const GLint* coords) {
	if (!glVertexStream1ivATIproc) return;
	glVertexStream1ivATIproc(stream, coords);
}
PFNGLVERTEXSTREAM1FATIPROC glVertexStream1fATIproc = 0;
void APIENTRY glVertexStream1fATI(GLenum stream, GLfloat x) {
	if (!glVertexStream1fATIproc) return;
	glVertexStream1fATIproc(stream, x);
}
PFNGLVERTEXSTREAM1FVATIPROC glVertexStream1fvATIproc = 0;
void APIENTRY glVertexStream1fvATI(GLenum stream, const GLfloat* coords) {
	if (!glVertexStream1fvATIproc) return;
	glVertexStream1fvATIproc(stream, coords);
}
PFNGLVERTEXSTREAM1DATIPROC glVertexStream1dATIproc = 0;
void APIENTRY glVertexStream1dATI(GLenum stream, GLdouble x) {
	if (!glVertexStream1dATIproc) return;
	glVertexStream1dATIproc(stream, x);
}
PFNGLVERTEXSTREAM1DVATIPROC glVertexStream1dvATIproc = 0;
void APIENTRY glVertexStream1dvATI(GLenum stream, const GLdouble* coords) {
	if (!glVertexStream1dvATIproc) return;
	glVertexStream1dvATIproc(stream, coords);
}
PFNGLVERTEXSTREAM2SATIPROC glVertexStream2sATIproc = 0;
void APIENTRY glVertexStream2sATI(GLenum stream, GLshort x, GLshort y) {
	if (!glVertexStream2sATIproc) return;
	glVertexStream2sATIproc(stream, x, y);
}
PFNGLVERTEXSTREAM2SVATIPROC glVertexStream2svATIproc = 0;
void APIENTRY glVertexStream2svATI(GLenum stream, const GLshort* coords) {
	if (!glVertexStream2svATIproc) return;
	glVertexStream2svATIproc(stream, coords);
}
PFNGLVERTEXSTREAM2IATIPROC glVertexStream2iATIproc = 0;
void APIENTRY glVertexStream2iATI(GLenum stream, GLint x, GLint y) {
	if (!glVertexStream2iATIproc) return;
	glVertexStream2iATIproc(stream, x, y);
}
PFNGLVERTEXSTREAM2IVATIPROC glVertexStream2ivATIproc = 0;
void APIENTRY glVertexStream2ivATI(GLenum stream, const GLint* coords) {
	if (!glVertexStream2ivATIproc) return;
	glVertexStream2ivATIproc(stream, coords);
}
PFNGLVERTEXSTREAM2FATIPROC glVertexStream2fATIproc = 0;
void APIENTRY glVertexStream2fATI(GLenum stream, GLfloat x, GLfloat y) {
	if (!glVertexStream2fATIproc) return;
	glVertexStream2fATIproc(stream, x, y);
}
PFNGLVERTEXSTREAM2FVATIPROC glVertexStream2fvATIproc = 0;
void APIENTRY glVertexStream2fvATI(GLenum stream, const GLfloat* coords) {
	if (!glVertexStream2fvATIproc) return;
	glVertexStream2fvATIproc(stream, coords);
}
PFNGLVERTEXSTREAM2DATIPROC glVertexStream2dATIproc = 0;
void APIENTRY glVertexStream2dATI(GLenum stream, GLdouble x, GLdouble y) {
	if (!glVertexStream2dATIproc) return;
	glVertexStream2dATIproc(stream, x, y);
}
PFNGLVERTEXSTREAM2DVATIPROC glVertexStream2dvATIproc = 0;
void APIENTRY glVertexStream2dvATI(GLenum stream, const GLdouble* coords) {
	if (!glVertexStream2dvATIproc) return;
	glVertexStream2dvATIproc(stream, coords);
}
PFNGLVERTEXSTREAM3SATIPROC glVertexStream3sATIproc = 0;
void APIENTRY glVertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z) {
	if (!glVertexStream3sATIproc) return;
	glVertexStream3sATIproc(stream, x, y, z);
}
PFNGLVERTEXSTREAM3SVATIPROC glVertexStream3svATIproc = 0;
void APIENTRY glVertexStream3svATI(GLenum stream, const GLshort* coords) {
	if (!glVertexStream3svATIproc) return;
	glVertexStream3svATIproc(stream, coords);
}
PFNGLVERTEXSTREAM3IATIPROC glVertexStream3iATIproc = 0;
void APIENTRY glVertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z) {
	if (!glVertexStream3iATIproc) return;
	glVertexStream3iATIproc(stream, x, y, z);
}
PFNGLVERTEXSTREAM3IVATIPROC glVertexStream3ivATIproc = 0;
void APIENTRY glVertexStream3ivATI(GLenum stream, const GLint* coords) {
	if (!glVertexStream3ivATIproc) return;
	glVertexStream3ivATIproc(stream, coords);
}
PFNGLVERTEXSTREAM3FATIPROC glVertexStream3fATIproc = 0;
void APIENTRY glVertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z) {
	if (!glVertexStream3fATIproc) return;
	glVertexStream3fATIproc(stream, x, y, z);
}
PFNGLVERTEXSTREAM3FVATIPROC glVertexStream3fvATIproc = 0;
void APIENTRY glVertexStream3fvATI(GLenum stream, const GLfloat* coords) {
	if (!glVertexStream3fvATIproc) return;
	glVertexStream3fvATIproc(stream, coords);
}
PFNGLVERTEXSTREAM3DATIPROC glVertexStream3dATIproc = 0;
void APIENTRY glVertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z) {
	if (!glVertexStream3dATIproc) return;
	glVertexStream3dATIproc(stream, x, y, z);
}
PFNGLVERTEXSTREAM3DVATIPROC glVertexStream3dvATIproc = 0;
void APIENTRY glVertexStream3dvATI(GLenum stream, const GLdouble* coords) {
	if (!glVertexStream3dvATIproc) return;
	glVertexStream3dvATIproc(stream, coords);
}
PFNGLVERTEXSTREAM4SATIPROC glVertexStream4sATIproc = 0;
void APIENTRY glVertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w) {
	if (!glVertexStream4sATIproc) return;
	glVertexStream4sATIproc(stream, x, y, z, w);
}
PFNGLVERTEXSTREAM4SVATIPROC glVertexStream4svATIproc = 0;
void APIENTRY glVertexStream4svATI(GLenum stream, const GLshort* coords) {
	if (!glVertexStream4svATIproc) return;
	glVertexStream4svATIproc(stream, coords);
}
PFNGLVERTEXSTREAM4IATIPROC glVertexStream4iATIproc = 0;
void APIENTRY glVertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w) {
	if (!glVertexStream4iATIproc) return;
	glVertexStream4iATIproc(stream, x, y, z, w);
}
PFNGLVERTEXSTREAM4IVATIPROC glVertexStream4ivATIproc = 0;
void APIENTRY glVertexStream4ivATI(GLenum stream, const GLint* coords) {
	if (!glVertexStream4ivATIproc) return;
	glVertexStream4ivATIproc(stream, coords);
}
PFNGLVERTEXSTREAM4FATIPROC glVertexStream4fATIproc = 0;
void APIENTRY glVertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glVertexStream4fATIproc) return;
	glVertexStream4fATIproc(stream, x, y, z, w);
}
PFNGLVERTEXSTREAM4FVATIPROC glVertexStream4fvATIproc = 0;
void APIENTRY glVertexStream4fvATI(GLenum stream, const GLfloat* coords) {
	if (!glVertexStream4fvATIproc) return;
	glVertexStream4fvATIproc(stream, coords);
}
PFNGLVERTEXSTREAM4DATIPROC glVertexStream4dATIproc = 0;
void APIENTRY glVertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glVertexStream4dATIproc) return;
	glVertexStream4dATIproc(stream, x, y, z, w);
}
PFNGLVERTEXSTREAM4DVATIPROC glVertexStream4dvATIproc = 0;
void APIENTRY glVertexStream4dvATI(GLenum stream, const GLdouble* coords) {
	if (!glVertexStream4dvATIproc) return;
	glVertexStream4dvATIproc(stream, coords);
}
PFNGLNORMALSTREAM3BATIPROC glNormalStream3bATIproc = 0;
void APIENTRY glNormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz) {
	if (!glNormalStream3bATIproc) return;
	glNormalStream3bATIproc(stream, nx, ny, nz);
}
PFNGLNORMALSTREAM3BVATIPROC glNormalStream3bvATIproc = 0;
void APIENTRY glNormalStream3bvATI(GLenum stream, const GLbyte* coords) {
	if (!glNormalStream3bvATIproc) return;
	glNormalStream3bvATIproc(stream, coords);
}
PFNGLNORMALSTREAM3SATIPROC glNormalStream3sATIproc = 0;
void APIENTRY glNormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz) {
	if (!glNormalStream3sATIproc) return;
	glNormalStream3sATIproc(stream, nx, ny, nz);
}
PFNGLNORMALSTREAM3SVATIPROC glNormalStream3svATIproc = 0;
void APIENTRY glNormalStream3svATI(GLenum stream, const GLshort* coords) {
	if (!glNormalStream3svATIproc) return;
	glNormalStream3svATIproc(stream, coords);
}
PFNGLNORMALSTREAM3IATIPROC glNormalStream3iATIproc = 0;
void APIENTRY glNormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz) {
	if (!glNormalStream3iATIproc) return;
	glNormalStream3iATIproc(stream, nx, ny, nz);
}
PFNGLNORMALSTREAM3IVATIPROC glNormalStream3ivATIproc = 0;
void APIENTRY glNormalStream3ivATI(GLenum stream, const GLint* coords) {
	if (!glNormalStream3ivATIproc) return;
	glNormalStream3ivATIproc(stream, coords);
}
PFNGLNORMALSTREAM3FATIPROC glNormalStream3fATIproc = 0;
void APIENTRY glNormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz) {
	if (!glNormalStream3fATIproc) return;
	glNormalStream3fATIproc(stream, nx, ny, nz);
}
PFNGLNORMALSTREAM3FVATIPROC glNormalStream3fvATIproc = 0;
void APIENTRY glNormalStream3fvATI(GLenum stream, const GLfloat* coords) {
	if (!glNormalStream3fvATIproc) return;
	glNormalStream3fvATIproc(stream, coords);
}
PFNGLNORMALSTREAM3DATIPROC glNormalStream3dATIproc = 0;
void APIENTRY glNormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz) {
	if (!glNormalStream3dATIproc) return;
	glNormalStream3dATIproc(stream, nx, ny, nz);
}
PFNGLNORMALSTREAM3DVATIPROC glNormalStream3dvATIproc = 0;
void APIENTRY glNormalStream3dvATI(GLenum stream, const GLdouble* coords) {
	if (!glNormalStream3dvATIproc) return;
	glNormalStream3dvATIproc(stream, coords);
}
PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glClientActiveVertexStreamATIproc = 0;
void APIENTRY glClientActiveVertexStreamATI(GLenum stream) {
	if (!glClientActiveVertexStreamATIproc) return;
	glClientActiveVertexStreamATIproc(stream);
}
PFNGLVERTEXBLENDENVIATIPROC glVertexBlendEnviATIproc = 0;
void APIENTRY glVertexBlendEnviATI(GLenum pname, GLint param) {
	if (!glVertexBlendEnviATIproc) return;
	glVertexBlendEnviATIproc(pname, param);
}
PFNGLVERTEXBLENDENVFATIPROC glVertexBlendEnvfATIproc = 0;
void APIENTRY glVertexBlendEnvfATI(GLenum pname, GLfloat param) {
	if (!glVertexBlendEnvfATIproc) return;
	glVertexBlendEnvfATIproc(pname, param);
}
PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC glEGLImageTargetTexStorageEXTproc = 0;
void APIENTRY glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, const GLint* attrib_list) {
	if (!glEGLImageTargetTexStorageEXTproc) return;
	glEGLImageTargetTexStorageEXTproc(target, image, attrib_list);
}
PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC glEGLImageTargetTextureStorageEXTproc = 0;
void APIENTRY glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, const GLint* attrib_list) {
	if (!glEGLImageTargetTextureStorageEXTproc) return;
	glEGLImageTargetTextureStorageEXTproc(texture, image, attrib_list);
}
PFNGLUNIFORMBUFFEREXTPROC glUniformBufferEXTproc = 0;
void APIENTRY glUniformBufferEXT(GLuint program, GLint location, GLuint buffer) {
	if (!glUniformBufferEXTproc) return;
	glUniformBufferEXTproc(program, location, buffer);
}
PFNGLGETUNIFORMBUFFERSIZEEXTPROC glGetUniformBufferSizeEXTproc = 0;
GLint APIENTRY glGetUniformBufferSizeEXT(GLuint program, GLint location) {
	if (!glGetUniformBufferSizeEXTproc) return 0;
	return glGetUniformBufferSizeEXTproc(program, location);
}
PFNGLGETUNIFORMOFFSETEXTPROC glGetUniformOffsetEXTproc = 0;
GLintptr APIENTRY glGetUniformOffsetEXT(GLuint program, GLint location) {
	if (!glGetUniformOffsetEXTproc) return 0;
	return glGetUniformOffsetEXTproc(program, location);
}
PFNGLBLENDCOLOREXTPROC glBlendColorEXTproc = 0;
void APIENTRY glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	if (!glBlendColorEXTproc) return;
	glBlendColorEXTproc(red, green, blue, alpha);
}
PFNGLBLENDEQUATIONSEPARATEEXTPROC glBlendEquationSeparateEXTproc = 0;
void APIENTRY glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha) {
	if (!glBlendEquationSeparateEXTproc) return;
	glBlendEquationSeparateEXTproc(modeRGB, modeAlpha);
}
PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXTproc = 0;
void APIENTRY glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	if (!glBlendFuncSeparateEXTproc) return;
	glBlendFuncSeparateEXTproc(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXTproc = 0;
void APIENTRY glBlendEquationEXT(GLenum mode) {
	if (!glBlendEquationEXTproc) return;
	glBlendEquationEXTproc(mode);
}
PFNGLCOLORSUBTABLEEXTPROC glColorSubTableEXTproc = 0;
void APIENTRY glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void* data) {
	if (!glColorSubTableEXTproc) return;
	glColorSubTableEXTproc(target, start, count, format, type, data);
}
PFNGLCOPYCOLORSUBTABLEEXTPROC glCopyColorSubTableEXTproc = 0;
void APIENTRY glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
	if (!glCopyColorSubTableEXTproc) return;
	glCopyColorSubTableEXTproc(target, start, x, y, width);
}
PFNGLLOCKARRAYSEXTPROC glLockArraysEXTproc = 0;
void APIENTRY glLockArraysEXT(GLint first, GLsizei count) {
	if (!glLockArraysEXTproc) return;
	glLockArraysEXTproc(first, count);
}
PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXTproc = 0;
void APIENTRY glUnlockArraysEXT(void) {
	if (!glUnlockArraysEXTproc) return;
	glUnlockArraysEXTproc();
}
PFNGLCONVOLUTIONFILTER1DEXTPROC glConvolutionFilter1DEXTproc = 0;
void APIENTRY glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* image) {
	if (!glConvolutionFilter1DEXTproc) return;
	glConvolutionFilter1DEXTproc(target, internalformat, width, format, type, image);
}
PFNGLCONVOLUTIONFILTER2DEXTPROC glConvolutionFilter2DEXTproc = 0;
void APIENTRY glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* image) {
	if (!glConvolutionFilter2DEXTproc) return;
	glConvolutionFilter2DEXTproc(target, internalformat, width, height, format, type, image);
}
PFNGLCONVOLUTIONPARAMETERFEXTPROC glConvolutionParameterfEXTproc = 0;
void APIENTRY glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params) {
	if (!glConvolutionParameterfEXTproc) return;
	glConvolutionParameterfEXTproc(target, pname, params);
}
PFNGLCONVOLUTIONPARAMETERFVEXTPROC glConvolutionParameterfvEXTproc = 0;
void APIENTRY glConvolutionParameterfvEXT(GLenum target, GLenum pname, const GLfloat* params) {
	if (!glConvolutionParameterfvEXTproc) return;
	glConvolutionParameterfvEXTproc(target, pname, params);
}
PFNGLCONVOLUTIONPARAMETERIEXTPROC glConvolutionParameteriEXTproc = 0;
void APIENTRY glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params) {
	if (!glConvolutionParameteriEXTproc) return;
	glConvolutionParameteriEXTproc(target, pname, params);
}
PFNGLCONVOLUTIONPARAMETERIVEXTPROC glConvolutionParameterivEXTproc = 0;
void APIENTRY glConvolutionParameterivEXT(GLenum target, GLenum pname, const GLint* params) {
	if (!glConvolutionParameterivEXTproc) return;
	glConvolutionParameterivEXTproc(target, pname, params);
}
PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC glCopyConvolutionFilter1DEXTproc = 0;
void APIENTRY glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
	if (!glCopyConvolutionFilter1DEXTproc) return;
	glCopyConvolutionFilter1DEXTproc(target, internalformat, x, y, width);
}
PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC glCopyConvolutionFilter2DEXTproc = 0;
void APIENTRY glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyConvolutionFilter2DEXTproc) return;
	glCopyConvolutionFilter2DEXTproc(target, internalformat, x, y, width, height);
}
PFNGLGETCONVOLUTIONFILTEREXTPROC glGetConvolutionFilterEXTproc = 0;
void APIENTRY glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, void* image) {
	if (!glGetConvolutionFilterEXTproc) return;
	glGetConvolutionFilterEXTproc(target, format, type, image);
}
PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC glGetConvolutionParameterfvEXTproc = 0;
void APIENTRY glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetConvolutionParameterfvEXTproc) return;
	glGetConvolutionParameterfvEXTproc(target, pname, params);
}
PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC glGetConvolutionParameterivEXTproc = 0;
void APIENTRY glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint* params) {
	if (!glGetConvolutionParameterivEXTproc) return;
	glGetConvolutionParameterivEXTproc(target, pname, params);
}
PFNGLGETSEPARABLEFILTEREXTPROC glGetSeparableFilterEXTproc = 0;
void APIENTRY glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, void* row, void* column, void* span) {
	if (!glGetSeparableFilterEXTproc) return;
	glGetSeparableFilterEXTproc(target, format, type, row, column, span);
}
PFNGLSEPARABLEFILTER2DEXTPROC glSeparableFilter2DEXTproc = 0;
void APIENTRY glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* row, const void* column) {
	if (!glSeparableFilter2DEXTproc) return;
	glSeparableFilter2DEXTproc(target, internalformat, width, height, format, type, row, column);
}
PFNGLTANGENT3BEXTPROC glTangent3bEXTproc = 0;
void APIENTRY glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz) {
	if (!glTangent3bEXTproc) return;
	glTangent3bEXTproc(tx, ty, tz);
}
PFNGLTANGENT3BVEXTPROC glTangent3bvEXTproc = 0;
void APIENTRY glTangent3bvEXT(const GLbyte* v) {
	if (!glTangent3bvEXTproc) return;
	glTangent3bvEXTproc(v);
}
PFNGLTANGENT3DEXTPROC glTangent3dEXTproc = 0;
void APIENTRY glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz) {
	if (!glTangent3dEXTproc) return;
	glTangent3dEXTproc(tx, ty, tz);
}
PFNGLTANGENT3DVEXTPROC glTangent3dvEXTproc = 0;
void APIENTRY glTangent3dvEXT(const GLdouble* v) {
	if (!glTangent3dvEXTproc) return;
	glTangent3dvEXTproc(v);
}
PFNGLTANGENT3FEXTPROC glTangent3fEXTproc = 0;
void APIENTRY glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz) {
	if (!glTangent3fEXTproc) return;
	glTangent3fEXTproc(tx, ty, tz);
}
PFNGLTANGENT3FVEXTPROC glTangent3fvEXTproc = 0;
void APIENTRY glTangent3fvEXT(const GLfloat* v) {
	if (!glTangent3fvEXTproc) return;
	glTangent3fvEXTproc(v);
}
PFNGLTANGENT3IEXTPROC glTangent3iEXTproc = 0;
void APIENTRY glTangent3iEXT(GLint tx, GLint ty, GLint tz) {
	if (!glTangent3iEXTproc) return;
	glTangent3iEXTproc(tx, ty, tz);
}
PFNGLTANGENT3IVEXTPROC glTangent3ivEXTproc = 0;
void APIENTRY glTangent3ivEXT(const GLint* v) {
	if (!glTangent3ivEXTproc) return;
	glTangent3ivEXTproc(v);
}
PFNGLTANGENT3SEXTPROC glTangent3sEXTproc = 0;
void APIENTRY glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz) {
	if (!glTangent3sEXTproc) return;
	glTangent3sEXTproc(tx, ty, tz);
}
PFNGLTANGENT3SVEXTPROC glTangent3svEXTproc = 0;
void APIENTRY glTangent3svEXT(const GLshort* v) {
	if (!glTangent3svEXTproc) return;
	glTangent3svEXTproc(v);
}
PFNGLBINORMAL3BEXTPROC glBinormal3bEXTproc = 0;
void APIENTRY glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz) {
	if (!glBinormal3bEXTproc) return;
	glBinormal3bEXTproc(bx, by, bz);
}
PFNGLBINORMAL3BVEXTPROC glBinormal3bvEXTproc = 0;
void APIENTRY glBinormal3bvEXT(const GLbyte* v) {
	if (!glBinormal3bvEXTproc) return;
	glBinormal3bvEXTproc(v);
}
PFNGLBINORMAL3DEXTPROC glBinormal3dEXTproc = 0;
void APIENTRY glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz) {
	if (!glBinormal3dEXTproc) return;
	glBinormal3dEXTproc(bx, by, bz);
}
PFNGLBINORMAL3DVEXTPROC glBinormal3dvEXTproc = 0;
void APIENTRY glBinormal3dvEXT(const GLdouble* v) {
	if (!glBinormal3dvEXTproc) return;
	glBinormal3dvEXTproc(v);
}
PFNGLBINORMAL3FEXTPROC glBinormal3fEXTproc = 0;
void APIENTRY glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz) {
	if (!glBinormal3fEXTproc) return;
	glBinormal3fEXTproc(bx, by, bz);
}
PFNGLBINORMAL3FVEXTPROC glBinormal3fvEXTproc = 0;
void APIENTRY glBinormal3fvEXT(const GLfloat* v) {
	if (!glBinormal3fvEXTproc) return;
	glBinormal3fvEXTproc(v);
}
PFNGLBINORMAL3IEXTPROC glBinormal3iEXTproc = 0;
void APIENTRY glBinormal3iEXT(GLint bx, GLint by, GLint bz) {
	if (!glBinormal3iEXTproc) return;
	glBinormal3iEXTproc(bx, by, bz);
}
PFNGLBINORMAL3IVEXTPROC glBinormal3ivEXTproc = 0;
void APIENTRY glBinormal3ivEXT(const GLint* v) {
	if (!glBinormal3ivEXTproc) return;
	glBinormal3ivEXTproc(v);
}
PFNGLBINORMAL3SEXTPROC glBinormal3sEXTproc = 0;
void APIENTRY glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz) {
	if (!glBinormal3sEXTproc) return;
	glBinormal3sEXTproc(bx, by, bz);
}
PFNGLBINORMAL3SVEXTPROC glBinormal3svEXTproc = 0;
void APIENTRY glBinormal3svEXT(const GLshort* v) {
	if (!glBinormal3svEXTproc) return;
	glBinormal3svEXTproc(v);
}
PFNGLTANGENTPOINTEREXTPROC glTangentPointerEXTproc = 0;
void APIENTRY glTangentPointerEXT(GLenum type, GLsizei stride, const void* pointer) {
	if (!glTangentPointerEXTproc) return;
	glTangentPointerEXTproc(type, stride, pointer);
}
PFNGLBINORMALPOINTEREXTPROC glBinormalPointerEXTproc = 0;
void APIENTRY glBinormalPointerEXT(GLenum type, GLsizei stride, const void* pointer) {
	if (!glBinormalPointerEXTproc) return;
	glBinormalPointerEXTproc(type, stride, pointer);
}
PFNGLCOPYTEXIMAGE1DEXTPROC glCopyTexImage1DEXTproc = 0;
void APIENTRY glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
	if (!glCopyTexImage1DEXTproc) return;
	glCopyTexImage1DEXTproc(target, level, internalformat, x, y, width, border);
}
PFNGLCOPYTEXIMAGE2DEXTPROC glCopyTexImage2DEXTproc = 0;
void APIENTRY glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	if (!glCopyTexImage2DEXTproc) return;
	glCopyTexImage2DEXTproc(target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYTEXSUBIMAGE1DEXTPROC glCopyTexSubImage1DEXTproc = 0;
void APIENTRY glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	if (!glCopyTexSubImage1DEXTproc) return;
	glCopyTexSubImage1DEXTproc(target, level, xoffset, x, y, width);
}
PFNGLCOPYTEXSUBIMAGE2DEXTPROC glCopyTexSubImage2DEXTproc = 0;
void APIENTRY glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyTexSubImage2DEXTproc) return;
	glCopyTexSubImage2DEXTproc(target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE3DEXTPROC glCopyTexSubImage3DEXTproc = 0;
void APIENTRY glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyTexSubImage3DEXTproc) return;
	glCopyTexSubImage3DEXTproc(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLCULLPARAMETERDVEXTPROC glCullParameterdvEXTproc = 0;
void APIENTRY glCullParameterdvEXT(GLenum pname, GLdouble* params) {
	if (!glCullParameterdvEXTproc) return;
	glCullParameterdvEXTproc(pname, params);
}
PFNGLCULLPARAMETERFVEXTPROC glCullParameterfvEXTproc = 0;
void APIENTRY glCullParameterfvEXT(GLenum pname, GLfloat* params) {
	if (!glCullParameterfvEXTproc) return;
	glCullParameterfvEXTproc(pname, params);
}
PFNGLLABELOBJECTEXTPROC glLabelObjectEXTproc = 0;
void APIENTRY glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label) {
	if (!glLabelObjectEXTproc) return;
	glLabelObjectEXTproc(type, object, length, label);
}
PFNGLGETOBJECTLABELEXTPROC glGetObjectLabelEXTproc = 0;
void APIENTRY glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label) {
	if (!glGetObjectLabelEXTproc) return;
	glGetObjectLabelEXTproc(type, object, bufSize, length, label);
}
PFNGLINSERTEVENTMARKEREXTPROC glInsertEventMarkerEXTproc = 0;
void APIENTRY glInsertEventMarkerEXT(GLsizei length, const GLchar* marker) {
	if (!glInsertEventMarkerEXTproc) return;
	glInsertEventMarkerEXTproc(length, marker);
}
PFNGLPUSHGROUPMARKEREXTPROC glPushGroupMarkerEXTproc = 0;
void APIENTRY glPushGroupMarkerEXT(GLsizei length, const GLchar* marker) {
	if (!glPushGroupMarkerEXTproc) return;
	glPushGroupMarkerEXTproc(length, marker);
}
PFNGLPOPGROUPMARKEREXTPROC glPopGroupMarkerEXTproc = 0;
void APIENTRY glPopGroupMarkerEXT(void) {
	if (!glPopGroupMarkerEXTproc) return;
	glPopGroupMarkerEXTproc();
}
PFNGLDEPTHBOUNDSEXTPROC glDepthBoundsEXTproc = 0;
void APIENTRY glDepthBoundsEXT(GLclampd zmin, GLclampd zmax) {
	if (!glDepthBoundsEXTproc) return;
	glDepthBoundsEXTproc(zmin, zmax);
}
PFNGLMATRIXLOADFEXTPROC glMatrixLoadfEXTproc = 0;
void APIENTRY glMatrixLoadfEXT(GLenum mode, const GLfloat* m) {
	if (!glMatrixLoadfEXTproc) return;
	glMatrixLoadfEXTproc(mode, m);
}
PFNGLMATRIXLOADDEXTPROC glMatrixLoaddEXTproc = 0;
void APIENTRY glMatrixLoaddEXT(GLenum mode, const GLdouble* m) {
	if (!glMatrixLoaddEXTproc) return;
	glMatrixLoaddEXTproc(mode, m);
}
PFNGLMATRIXMULTFEXTPROC glMatrixMultfEXTproc = 0;
void APIENTRY glMatrixMultfEXT(GLenum mode, const GLfloat* m) {
	if (!glMatrixMultfEXTproc) return;
	glMatrixMultfEXTproc(mode, m);
}
PFNGLMATRIXMULTDEXTPROC glMatrixMultdEXTproc = 0;
void APIENTRY glMatrixMultdEXT(GLenum mode, const GLdouble* m) {
	if (!glMatrixMultdEXTproc) return;
	glMatrixMultdEXTproc(mode, m);
}
PFNGLMATRIXLOADIDENTITYEXTPROC glMatrixLoadIdentityEXTproc = 0;
void APIENTRY glMatrixLoadIdentityEXT(GLenum mode) {
	if (!glMatrixLoadIdentityEXTproc) return;
	glMatrixLoadIdentityEXTproc(mode);
}
PFNGLMATRIXROTATEFEXTPROC glMatrixRotatefEXTproc = 0;
void APIENTRY glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	if (!glMatrixRotatefEXTproc) return;
	glMatrixRotatefEXTproc(mode, angle, x, y, z);
}
PFNGLMATRIXROTATEDEXTPROC glMatrixRotatedEXTproc = 0;
void APIENTRY glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
	if (!glMatrixRotatedEXTproc) return;
	glMatrixRotatedEXTproc(mode, angle, x, y, z);
}
PFNGLMATRIXSCALEFEXTPROC glMatrixScalefEXTproc = 0;
void APIENTRY glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
	if (!glMatrixScalefEXTproc) return;
	glMatrixScalefEXTproc(mode, x, y, z);
}
PFNGLMATRIXSCALEDEXTPROC glMatrixScaledEXTproc = 0;
void APIENTRY glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
	if (!glMatrixScaledEXTproc) return;
	glMatrixScaledEXTproc(mode, x, y, z);
}
PFNGLMATRIXTRANSLATEFEXTPROC glMatrixTranslatefEXTproc = 0;
void APIENTRY glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
	if (!glMatrixTranslatefEXTproc) return;
	glMatrixTranslatefEXTproc(mode, x, y, z);
}
PFNGLMATRIXTRANSLATEDEXTPROC glMatrixTranslatedEXTproc = 0;
void APIENTRY glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
	if (!glMatrixTranslatedEXTproc) return;
	glMatrixTranslatedEXTproc(mode, x, y, z);
}
PFNGLMATRIXFRUSTUMEXTPROC glMatrixFrustumEXTproc = 0;
void APIENTRY glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
	if (!glMatrixFrustumEXTproc) return;
	glMatrixFrustumEXTproc(mode, left, right, bottom, top, zNear, zFar);
}
PFNGLMATRIXORTHOEXTPROC glMatrixOrthoEXTproc = 0;
void APIENTRY glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
	if (!glMatrixOrthoEXTproc) return;
	glMatrixOrthoEXTproc(mode, left, right, bottom, top, zNear, zFar);
}
PFNGLMATRIXPOPEXTPROC glMatrixPopEXTproc = 0;
void APIENTRY glMatrixPopEXT(GLenum mode) {
	if (!glMatrixPopEXTproc) return;
	glMatrixPopEXTproc(mode);
}
PFNGLMATRIXPUSHEXTPROC glMatrixPushEXTproc = 0;
void APIENTRY glMatrixPushEXT(GLenum mode) {
	if (!glMatrixPushEXTproc) return;
	glMatrixPushEXTproc(mode);
}
PFNGLCLIENTATTRIBDEFAULTEXTPROC glClientAttribDefaultEXTproc = 0;
void APIENTRY glClientAttribDefaultEXT(GLbitfield mask) {
	if (!glClientAttribDefaultEXTproc) return;
	glClientAttribDefaultEXTproc(mask);
}
PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC glPushClientAttribDefaultEXTproc = 0;
void APIENTRY glPushClientAttribDefaultEXT(GLbitfield mask) {
	if (!glPushClientAttribDefaultEXTproc) return;
	glPushClientAttribDefaultEXTproc(mask);
}
PFNGLTEXTUREPARAMETERFEXTPROC glTextureParameterfEXTproc = 0;
void APIENTRY glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param) {
	if (!glTextureParameterfEXTproc) return;
	glTextureParameterfEXTproc(texture, target, pname, param);
}
PFNGLTEXTUREPARAMETERFVEXTPROC glTextureParameterfvEXTproc = 0;
void APIENTRY glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat* params) {
	if (!glTextureParameterfvEXTproc) return;
	glTextureParameterfvEXTproc(texture, target, pname, params);
}
PFNGLTEXTUREPARAMETERIEXTPROC glTextureParameteriEXTproc = 0;
void APIENTRY glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param) {
	if (!glTextureParameteriEXTproc) return;
	glTextureParameteriEXTproc(texture, target, pname, param);
}
PFNGLTEXTUREPARAMETERIVEXTPROC glTextureParameterivEXTproc = 0;
void APIENTRY glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params) {
	if (!glTextureParameterivEXTproc) return;
	glTextureParameterivEXTproc(texture, target, pname, params);
}
PFNGLTEXTUREIMAGE1DEXTPROC glTextureImage1DEXTproc = 0;
void APIENTRY glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureImage1DEXTproc) return;
	glTextureImage1DEXTproc(texture, target, level, internalformat, width, border, format, type, pixels);
}
PFNGLTEXTUREIMAGE2DEXTPROC glTextureImage2DEXTproc = 0;
void APIENTRY glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureImage2DEXTproc) return;
	glTextureImage2DEXTproc(texture, target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE1DEXTPROC glTextureSubImage1DEXTproc = 0;
void APIENTRY glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureSubImage1DEXTproc) return;
	glTextureSubImage1DEXTproc(texture, target, level, xoffset, width, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE2DEXTPROC glTextureSubImage2DEXTproc = 0;
void APIENTRY glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureSubImage2DEXTproc) return;
	glTextureSubImage2DEXTproc(texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLCOPYTEXTUREIMAGE1DEXTPROC glCopyTextureImage1DEXTproc = 0;
void APIENTRY glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
	if (!glCopyTextureImage1DEXTproc) return;
	glCopyTextureImage1DEXTproc(texture, target, level, internalformat, x, y, width, border);
}
PFNGLCOPYTEXTUREIMAGE2DEXTPROC glCopyTextureImage2DEXTproc = 0;
void APIENTRY glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	if (!glCopyTextureImage2DEXTproc) return;
	glCopyTextureImage2DEXTproc(texture, target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC glCopyTextureSubImage1DEXTproc = 0;
void APIENTRY glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	if (!glCopyTextureSubImage1DEXTproc) return;
	glCopyTextureSubImage1DEXTproc(texture, target, level, xoffset, x, y, width);
}
PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC glCopyTextureSubImage2DEXTproc = 0;
void APIENTRY glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyTextureSubImage2DEXTproc) return;
	glCopyTextureSubImage2DEXTproc(texture, target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLGETTEXTUREIMAGEEXTPROC glGetTextureImageEXTproc = 0;
void APIENTRY glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels) {
	if (!glGetTextureImageEXTproc) return;
	glGetTextureImageEXTproc(texture, target, level, format, type, pixels);
}
PFNGLGETTEXTUREPARAMETERFVEXTPROC glGetTextureParameterfvEXTproc = 0;
void APIENTRY glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetTextureParameterfvEXTproc) return;
	glGetTextureParameterfvEXTproc(texture, target, pname, params);
}
PFNGLGETTEXTUREPARAMETERIVEXTPROC glGetTextureParameterivEXTproc = 0;
void APIENTRY glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params) {
	if (!glGetTextureParameterivEXTproc) return;
	glGetTextureParameterivEXTproc(texture, target, pname, params);
}
PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC glGetTextureLevelParameterfvEXTproc = 0;
void APIENTRY glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params) {
	if (!glGetTextureLevelParameterfvEXTproc) return;
	glGetTextureLevelParameterfvEXTproc(texture, target, level, pname, params);
}
PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC glGetTextureLevelParameterivEXTproc = 0;
void APIENTRY glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params) {
	if (!glGetTextureLevelParameterivEXTproc) return;
	glGetTextureLevelParameterivEXTproc(texture, target, level, pname, params);
}
PFNGLTEXTUREIMAGE3DEXTPROC glTextureImage3DEXTproc = 0;
void APIENTRY glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureImage3DEXTproc) return;
	glTextureImage3DEXTproc(texture, target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLTEXTURESUBIMAGE3DEXTPROC glTextureSubImage3DEXTproc = 0;
void APIENTRY glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) {
	if (!glTextureSubImage3DEXTproc) return;
	glTextureSubImage3DEXTproc(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC glCopyTextureSubImage3DEXTproc = 0;
void APIENTRY glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyTextureSubImage3DEXTproc) return;
	glCopyTextureSubImage3DEXTproc(texture, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLBINDMULTITEXTUREEXTPROC glBindMultiTextureEXTproc = 0;
void APIENTRY glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) {
	if (!glBindMultiTextureEXTproc) return;
	glBindMultiTextureEXTproc(texunit, target, texture);
}
PFNGLMULTITEXCOORDPOINTEREXTPROC glMultiTexCoordPointerEXTproc = 0;
void APIENTRY glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glMultiTexCoordPointerEXTproc) return;
	glMultiTexCoordPointerEXTproc(texunit, size, type, stride, pointer);
}
PFNGLMULTITEXENVFEXTPROC glMultiTexEnvfEXTproc = 0;
void APIENTRY glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
	if (!glMultiTexEnvfEXTproc) return;
	glMultiTexEnvfEXTproc(texunit, target, pname, param);
}
PFNGLMULTITEXENVFVEXTPROC glMultiTexEnvfvEXTproc = 0;
void APIENTRY glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params) {
	if (!glMultiTexEnvfvEXTproc) return;
	glMultiTexEnvfvEXTproc(texunit, target, pname, params);
}
PFNGLMULTITEXENVIEXTPROC glMultiTexEnviEXTproc = 0;
void APIENTRY glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
	if (!glMultiTexEnviEXTproc) return;
	glMultiTexEnviEXTproc(texunit, target, pname, param);
}
PFNGLMULTITEXENVIVEXTPROC glMultiTexEnvivEXTproc = 0;
void APIENTRY glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params) {
	if (!glMultiTexEnvivEXTproc) return;
	glMultiTexEnvivEXTproc(texunit, target, pname, params);
}
PFNGLMULTITEXGENDEXTPROC glMultiTexGendEXTproc = 0;
void APIENTRY glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
	if (!glMultiTexGendEXTproc) return;
	glMultiTexGendEXTproc(texunit, coord, pname, param);
}
PFNGLMULTITEXGENDVEXTPROC glMultiTexGendvEXTproc = 0;
void APIENTRY glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params) {
	if (!glMultiTexGendvEXTproc) return;
	glMultiTexGendvEXTproc(texunit, coord, pname, params);
}
PFNGLMULTITEXGENFEXTPROC glMultiTexGenfEXTproc = 0;
void APIENTRY glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
	if (!glMultiTexGenfEXTproc) return;
	glMultiTexGenfEXTproc(texunit, coord, pname, param);
}
PFNGLMULTITEXGENFVEXTPROC glMultiTexGenfvEXTproc = 0;
void APIENTRY glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params) {
	if (!glMultiTexGenfvEXTproc) return;
	glMultiTexGenfvEXTproc(texunit, coord, pname, params);
}
PFNGLMULTITEXGENIEXTPROC glMultiTexGeniEXTproc = 0;
void APIENTRY glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param) {
	if (!glMultiTexGeniEXTproc) return;
	glMultiTexGeniEXTproc(texunit, coord, pname, param);
}
PFNGLMULTITEXGENIVEXTPROC glMultiTexGenivEXTproc = 0;
void APIENTRY glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint* params) {
	if (!glMultiTexGenivEXTproc) return;
	glMultiTexGenivEXTproc(texunit, coord, pname, params);
}
PFNGLGETMULTITEXENVFVEXTPROC glGetMultiTexEnvfvEXTproc = 0;
void APIENTRY glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetMultiTexEnvfvEXTproc) return;
	glGetMultiTexEnvfvEXTproc(texunit, target, pname, params);
}
PFNGLGETMULTITEXENVIVEXTPROC glGetMultiTexEnvivEXTproc = 0;
void APIENTRY glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params) {
	if (!glGetMultiTexEnvivEXTproc) return;
	glGetMultiTexEnvivEXTproc(texunit, target, pname, params);
}
PFNGLGETMULTITEXGENDVEXTPROC glGetMultiTexGendvEXTproc = 0;
void APIENTRY glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params) {
	if (!glGetMultiTexGendvEXTproc) return;
	glGetMultiTexGendvEXTproc(texunit, coord, pname, params);
}
PFNGLGETMULTITEXGENFVEXTPROC glGetMultiTexGenfvEXTproc = 0;
void APIENTRY glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params) {
	if (!glGetMultiTexGenfvEXTproc) return;
	glGetMultiTexGenfvEXTproc(texunit, coord, pname, params);
}
PFNGLGETMULTITEXGENIVEXTPROC glGetMultiTexGenivEXTproc = 0;
void APIENTRY glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint* params) {
	if (!glGetMultiTexGenivEXTproc) return;
	glGetMultiTexGenivEXTproc(texunit, coord, pname, params);
}
PFNGLMULTITEXPARAMETERIEXTPROC glMultiTexParameteriEXTproc = 0;
void APIENTRY glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
	if (!glMultiTexParameteriEXTproc) return;
	glMultiTexParameteriEXTproc(texunit, target, pname, param);
}
PFNGLMULTITEXPARAMETERIVEXTPROC glMultiTexParameterivEXTproc = 0;
void APIENTRY glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params) {
	if (!glMultiTexParameterivEXTproc) return;
	glMultiTexParameterivEXTproc(texunit, target, pname, params);
}
PFNGLMULTITEXPARAMETERFEXTPROC glMultiTexParameterfEXTproc = 0;
void APIENTRY glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
	if (!glMultiTexParameterfEXTproc) return;
	glMultiTexParameterfEXTproc(texunit, target, pname, param);
}
PFNGLMULTITEXPARAMETERFVEXTPROC glMultiTexParameterfvEXTproc = 0;
void APIENTRY glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params) {
	if (!glMultiTexParameterfvEXTproc) return;
	glMultiTexParameterfvEXTproc(texunit, target, pname, params);
}
PFNGLMULTITEXIMAGE1DEXTPROC glMultiTexImage1DEXTproc = 0;
void APIENTRY glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glMultiTexImage1DEXTproc) return;
	glMultiTexImage1DEXTproc(texunit, target, level, internalformat, width, border, format, type, pixels);
}
PFNGLMULTITEXIMAGE2DEXTPROC glMultiTexImage2DEXTproc = 0;
void APIENTRY glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glMultiTexImage2DEXTproc) return;
	glMultiTexImage2DEXTproc(texunit, target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLMULTITEXSUBIMAGE1DEXTPROC glMultiTexSubImage1DEXTproc = 0;
void APIENTRY glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) {
	if (!glMultiTexSubImage1DEXTproc) return;
	glMultiTexSubImage1DEXTproc(texunit, target, level, xoffset, width, format, type, pixels);
}
PFNGLMULTITEXSUBIMAGE2DEXTPROC glMultiTexSubImage2DEXTproc = 0;
void APIENTRY glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) {
	if (!glMultiTexSubImage2DEXTproc) return;
	glMultiTexSubImage2DEXTproc(texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLCOPYMULTITEXIMAGE1DEXTPROC glCopyMultiTexImage1DEXTproc = 0;
void APIENTRY glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
	if (!glCopyMultiTexImage1DEXTproc) return;
	glCopyMultiTexImage1DEXTproc(texunit, target, level, internalformat, x, y, width, border);
}
PFNGLCOPYMULTITEXIMAGE2DEXTPROC glCopyMultiTexImage2DEXTproc = 0;
void APIENTRY glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	if (!glCopyMultiTexImage2DEXTproc) return;
	glCopyMultiTexImage2DEXTproc(texunit, target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC glCopyMultiTexSubImage1DEXTproc = 0;
void APIENTRY glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
	if (!glCopyMultiTexSubImage1DEXTproc) return;
	glCopyMultiTexSubImage1DEXTproc(texunit, target, level, xoffset, x, y, width);
}
PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC glCopyMultiTexSubImage2DEXTproc = 0;
void APIENTRY glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyMultiTexSubImage2DEXTproc) return;
	glCopyMultiTexSubImage2DEXTproc(texunit, target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLGETMULTITEXIMAGEEXTPROC glGetMultiTexImageEXTproc = 0;
void APIENTRY glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels) {
	if (!glGetMultiTexImageEXTproc) return;
	glGetMultiTexImageEXTproc(texunit, target, level, format, type, pixels);
}
PFNGLGETMULTITEXPARAMETERFVEXTPROC glGetMultiTexParameterfvEXTproc = 0;
void APIENTRY glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetMultiTexParameterfvEXTproc) return;
	glGetMultiTexParameterfvEXTproc(texunit, target, pname, params);
}
PFNGLGETMULTITEXPARAMETERIVEXTPROC glGetMultiTexParameterivEXTproc = 0;
void APIENTRY glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params) {
	if (!glGetMultiTexParameterivEXTproc) return;
	glGetMultiTexParameterivEXTproc(texunit, target, pname, params);
}
PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC glGetMultiTexLevelParameterfvEXTproc = 0;
void APIENTRY glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params) {
	if (!glGetMultiTexLevelParameterfvEXTproc) return;
	glGetMultiTexLevelParameterfvEXTproc(texunit, target, level, pname, params);
}
PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC glGetMultiTexLevelParameterivEXTproc = 0;
void APIENTRY glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params) {
	if (!glGetMultiTexLevelParameterivEXTproc) return;
	glGetMultiTexLevelParameterivEXTproc(texunit, target, level, pname, params);
}
PFNGLMULTITEXIMAGE3DEXTPROC glMultiTexImage3DEXTproc = 0;
void APIENTRY glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glMultiTexImage3DEXTproc) return;
	glMultiTexImage3DEXTproc(texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLMULTITEXSUBIMAGE3DEXTPROC glMultiTexSubImage3DEXTproc = 0;
void APIENTRY glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) {
	if (!glMultiTexSubImage3DEXTproc) return;
	glMultiTexSubImage3DEXTproc(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC glCopyMultiTexSubImage3DEXTproc = 0;
void APIENTRY glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glCopyMultiTexSubImage3DEXTproc) return;
	glCopyMultiTexSubImage3DEXTproc(texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLENABLECLIENTSTATEINDEXEDEXTPROC glEnableClientStateIndexedEXTproc = 0;
void APIENTRY glEnableClientStateIndexedEXT(GLenum array, GLuint index) {
	if (!glEnableClientStateIndexedEXTproc) return;
	glEnableClientStateIndexedEXTproc(array, index);
}
PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC glDisableClientStateIndexedEXTproc = 0;
void APIENTRY glDisableClientStateIndexedEXT(GLenum array, GLuint index) {
	if (!glDisableClientStateIndexedEXTproc) return;
	glDisableClientStateIndexedEXTproc(array, index);
}
PFNGLGETFLOATINDEXEDVEXTPROC glGetFloatIndexedvEXTproc = 0;
void APIENTRY glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* data) {
	if (!glGetFloatIndexedvEXTproc) return;
	glGetFloatIndexedvEXTproc(target, index, data);
}
PFNGLGETDOUBLEINDEXEDVEXTPROC glGetDoubleIndexedvEXTproc = 0;
void APIENTRY glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* data) {
	if (!glGetDoubleIndexedvEXTproc) return;
	glGetDoubleIndexedvEXTproc(target, index, data);
}
PFNGLGETPOINTERINDEXEDVEXTPROC glGetPointerIndexedvEXTproc = 0;
void APIENTRY glGetPointerIndexedvEXT(GLenum target, GLuint index, void** data) {
	if (!glGetPointerIndexedvEXTproc) return;
	glGetPointerIndexedvEXTproc(target, index, data);
}
PFNGLENABLEINDEXEDEXTPROC glEnableIndexedEXTproc = 0;
void APIENTRY glEnableIndexedEXT(GLenum target, GLuint index) {
	if (!glEnableIndexedEXTproc) return;
	glEnableIndexedEXTproc(target, index);
}
PFNGLDISABLEINDEXEDEXTPROC glDisableIndexedEXTproc = 0;
void APIENTRY glDisableIndexedEXT(GLenum target, GLuint index) {
	if (!glDisableIndexedEXTproc) return;
	glDisableIndexedEXTproc(target, index);
}
PFNGLISENABLEDINDEXEDEXTPROC glIsEnabledIndexedEXTproc = 0;
GLboolean APIENTRY glIsEnabledIndexedEXT(GLenum target, GLuint index) {
	if (!glIsEnabledIndexedEXTproc) return 0;
	return glIsEnabledIndexedEXTproc(target, index);
}
PFNGLGETINTEGERINDEXEDVEXTPROC glGetIntegerIndexedvEXTproc = 0;
void APIENTRY glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint* data) {
	if (!glGetIntegerIndexedvEXTproc) return;
	glGetIntegerIndexedvEXTproc(target, index, data);
}
PFNGLGETBOOLEANINDEXEDVEXTPROC glGetBooleanIndexedvEXTproc = 0;
void APIENTRY glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean* data) {
	if (!glGetBooleanIndexedvEXTproc) return;
	glGetBooleanIndexedvEXTproc(target, index, data);
}
PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC glCompressedTextureImage3DEXTproc = 0;
void APIENTRY glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits) {
	if (!glCompressedTextureImage3DEXTproc) return;
	glCompressedTextureImage3DEXTproc(texture, target, level, internalformat, width, height, depth, border, imageSize, bits);
}
PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC glCompressedTextureImage2DEXTproc = 0;
void APIENTRY glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits) {
	if (!glCompressedTextureImage2DEXTproc) return;
	glCompressedTextureImage2DEXTproc(texture, target, level, internalformat, width, height, border, imageSize, bits);
}
PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC glCompressedTextureImage1DEXTproc = 0;
void APIENTRY glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits) {
	if (!glCompressedTextureImage1DEXTproc) return;
	glCompressedTextureImage1DEXTproc(texture, target, level, internalformat, width, border, imageSize, bits);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC glCompressedTextureSubImage3DEXTproc = 0;
void APIENTRY glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits) {
	if (!glCompressedTextureSubImage3DEXTproc) return;
	glCompressedTextureSubImage3DEXTproc(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC glCompressedTextureSubImage2DEXTproc = 0;
void APIENTRY glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits) {
	if (!glCompressedTextureSubImage2DEXTproc) return;
	glCompressedTextureSubImage2DEXTproc(texture, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC glCompressedTextureSubImage1DEXTproc = 0;
void APIENTRY glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits) {
	if (!glCompressedTextureSubImage1DEXTproc) return;
	glCompressedTextureSubImage1DEXTproc(texture, target, level, xoffset, width, format, imageSize, bits);
}
PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC glGetCompressedTextureImageEXTproc = 0;
void APIENTRY glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void* img) {
	if (!glGetCompressedTextureImageEXTproc) return;
	glGetCompressedTextureImageEXTproc(texture, target, lod, img);
}
PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC glCompressedMultiTexImage3DEXTproc = 0;
void APIENTRY glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits) {
	if (!glCompressedMultiTexImage3DEXTproc) return;
	glCompressedMultiTexImage3DEXTproc(texunit, target, level, internalformat, width, height, depth, border, imageSize, bits);
}
PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC glCompressedMultiTexImage2DEXTproc = 0;
void APIENTRY glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits) {
	if (!glCompressedMultiTexImage2DEXTproc) return;
	glCompressedMultiTexImage2DEXTproc(texunit, target, level, internalformat, width, height, border, imageSize, bits);
}
PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC glCompressedMultiTexImage1DEXTproc = 0;
void APIENTRY glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits) {
	if (!glCompressedMultiTexImage1DEXTproc) return;
	glCompressedMultiTexImage1DEXTproc(texunit, target, level, internalformat, width, border, imageSize, bits);
}
PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC glCompressedMultiTexSubImage3DEXTproc = 0;
void APIENTRY glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits) {
	if (!glCompressedMultiTexSubImage3DEXTproc) return;
	glCompressedMultiTexSubImage3DEXTproc(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}
PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC glCompressedMultiTexSubImage2DEXTproc = 0;
void APIENTRY glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits) {
	if (!glCompressedMultiTexSubImage2DEXTproc) return;
	glCompressedMultiTexSubImage2DEXTproc(texunit, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}
PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC glCompressedMultiTexSubImage1DEXTproc = 0;
void APIENTRY glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits) {
	if (!glCompressedMultiTexSubImage1DEXTproc) return;
	glCompressedMultiTexSubImage1DEXTproc(texunit, target, level, xoffset, width, format, imageSize, bits);
}
PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC glGetCompressedMultiTexImageEXTproc = 0;
void APIENTRY glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void* img) {
	if (!glGetCompressedMultiTexImageEXTproc) return;
	glGetCompressedMultiTexImageEXTproc(texunit, target, lod, img);
}
PFNGLMATRIXLOADTRANSPOSEFEXTPROC glMatrixLoadTransposefEXTproc = 0;
void APIENTRY glMatrixLoadTransposefEXT(GLenum mode, const GLfloat* m) {
	if (!glMatrixLoadTransposefEXTproc) return;
	glMatrixLoadTransposefEXTproc(mode, m);
}
PFNGLMATRIXLOADTRANSPOSEDEXTPROC glMatrixLoadTransposedEXTproc = 0;
void APIENTRY glMatrixLoadTransposedEXT(GLenum mode, const GLdouble* m) {
	if (!glMatrixLoadTransposedEXTproc) return;
	glMatrixLoadTransposedEXTproc(mode, m);
}
PFNGLMATRIXMULTTRANSPOSEFEXTPROC glMatrixMultTransposefEXTproc = 0;
void APIENTRY glMatrixMultTransposefEXT(GLenum mode, const GLfloat* m) {
	if (!glMatrixMultTransposefEXTproc) return;
	glMatrixMultTransposefEXTproc(mode, m);
}
PFNGLMATRIXMULTTRANSPOSEDEXTPROC glMatrixMultTransposedEXTproc = 0;
void APIENTRY glMatrixMultTransposedEXT(GLenum mode, const GLdouble* m) {
	if (!glMatrixMultTransposedEXTproc) return;
	glMatrixMultTransposedEXTproc(mode, m);
}
PFNGLNAMEDBUFFERDATAEXTPROC glNamedBufferDataEXTproc = 0;
void APIENTRY glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) {
	if (!glNamedBufferDataEXTproc) return;
	glNamedBufferDataEXTproc(buffer, size, data, usage);
}
PFNGLNAMEDBUFFERSUBDATAEXTPROC glNamedBufferSubDataEXTproc = 0;
void APIENTRY glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) {
	if (!glNamedBufferSubDataEXTproc) return;
	glNamedBufferSubDataEXTproc(buffer, offset, size, data);
}
PFNGLMAPNAMEDBUFFEREXTPROC glMapNamedBufferEXTproc = 0;
void* APIENTRY glMapNamedBufferEXT(GLuint buffer, GLenum access) {
	if (!glMapNamedBufferEXTproc) return 0;
	return glMapNamedBufferEXTproc(buffer, access);
}
PFNGLUNMAPNAMEDBUFFEREXTPROC glUnmapNamedBufferEXTproc = 0;
GLboolean APIENTRY glUnmapNamedBufferEXT(GLuint buffer) {
	if (!glUnmapNamedBufferEXTproc) return 0;
	return glUnmapNamedBufferEXTproc(buffer);
}
PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC glGetNamedBufferParameterivEXTproc = 0;
void APIENTRY glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint* params) {
	if (!glGetNamedBufferParameterivEXTproc) return;
	glGetNamedBufferParameterivEXTproc(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERPOINTERVEXTPROC glGetNamedBufferPointervEXTproc = 0;
void APIENTRY glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void** params) {
	if (!glGetNamedBufferPointervEXTproc) return;
	glGetNamedBufferPointervEXTproc(buffer, pname, params);
}
PFNGLGETNAMEDBUFFERSUBDATAEXTPROC glGetNamedBufferSubDataEXTproc = 0;
void APIENTRY glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) {
	if (!glGetNamedBufferSubDataEXTproc) return;
	glGetNamedBufferSubDataEXTproc(buffer, offset, size, data);
}
PFNGLPROGRAMUNIFORM1FEXTPROC glProgramUniform1fEXTproc = 0;
void APIENTRY glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) {
	if (!glProgramUniform1fEXTproc) return;
	glProgramUniform1fEXTproc(program, location, v0);
}
PFNGLPROGRAMUNIFORM2FEXTPROC glProgramUniform2fEXTproc = 0;
void APIENTRY glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
	if (!glProgramUniform2fEXTproc) return;
	glProgramUniform2fEXTproc(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM3FEXTPROC glProgramUniform3fEXTproc = 0;
void APIENTRY glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	if (!glProgramUniform3fEXTproc) return;
	glProgramUniform3fEXTproc(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM4FEXTPROC glProgramUniform4fEXTproc = 0;
void APIENTRY glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	if (!glProgramUniform4fEXTproc) return;
	glProgramUniform4fEXTproc(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM1IEXTPROC glProgramUniform1iEXTproc = 0;
void APIENTRY glProgramUniform1iEXT(GLuint program, GLint location, GLint v0) {
	if (!glProgramUniform1iEXTproc) return;
	glProgramUniform1iEXTproc(program, location, v0);
}
PFNGLPROGRAMUNIFORM2IEXTPROC glProgramUniform2iEXTproc = 0;
void APIENTRY glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) {
	if (!glProgramUniform2iEXTproc) return;
	glProgramUniform2iEXTproc(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM3IEXTPROC glProgramUniform3iEXTproc = 0;
void APIENTRY glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
	if (!glProgramUniform3iEXTproc) return;
	glProgramUniform3iEXTproc(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM4IEXTPROC glProgramUniform4iEXTproc = 0;
void APIENTRY glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	if (!glProgramUniform4iEXTproc) return;
	glProgramUniform4iEXTproc(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM1FVEXTPROC glProgramUniform1fvEXTproc = 0;
void APIENTRY glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform1fvEXTproc) return;
	glProgramUniform1fvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2FVEXTPROC glProgramUniform2fvEXTproc = 0;
void APIENTRY glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform2fvEXTproc) return;
	glProgramUniform2fvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3FVEXTPROC glProgramUniform3fvEXTproc = 0;
void APIENTRY glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform3fvEXTproc) return;
	glProgramUniform3fvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4FVEXTPROC glProgramUniform4fvEXTproc = 0;
void APIENTRY glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) {
	if (!glProgramUniform4fvEXTproc) return;
	glProgramUniform4fvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM1IVEXTPROC glProgramUniform1ivEXTproc = 0;
void APIENTRY glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform1ivEXTproc) return;
	glProgramUniform1ivEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2IVEXTPROC glProgramUniform2ivEXTproc = 0;
void APIENTRY glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform2ivEXTproc) return;
	glProgramUniform2ivEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3IVEXTPROC glProgramUniform3ivEXTproc = 0;
void APIENTRY glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform3ivEXTproc) return;
	glProgramUniform3ivEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4IVEXTPROC glProgramUniform4ivEXTproc = 0;
void APIENTRY glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) {
	if (!glProgramUniform4ivEXTproc) return;
	glProgramUniform4ivEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC glProgramUniformMatrix2fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix2fvEXTproc) return;
	glProgramUniformMatrix2fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC glProgramUniformMatrix3fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix3fvEXTproc) return;
	glProgramUniformMatrix3fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC glProgramUniformMatrix4fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix4fvEXTproc) return;
	glProgramUniformMatrix4fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC glProgramUniformMatrix2x3fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix2x3fvEXTproc) return;
	glProgramUniformMatrix2x3fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC glProgramUniformMatrix3x2fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix3x2fvEXTproc) return;
	glProgramUniformMatrix3x2fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC glProgramUniformMatrix2x4fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix2x4fvEXTproc) return;
	glProgramUniformMatrix2x4fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC glProgramUniformMatrix4x2fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix4x2fvEXTproc) return;
	glProgramUniformMatrix4x2fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC glProgramUniformMatrix3x4fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix3x4fvEXTproc) return;
	glProgramUniformMatrix3x4fvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC glProgramUniformMatrix4x3fvEXTproc = 0;
void APIENTRY glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	if (!glProgramUniformMatrix4x3fvEXTproc) return;
	glProgramUniformMatrix4x3fvEXTproc(program, location, count, transpose, value);
}
PFNGLTEXTUREBUFFEREXTPROC glTextureBufferEXTproc = 0;
void APIENTRY glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) {
	if (!glTextureBufferEXTproc) return;
	glTextureBufferEXTproc(texture, target, internalformat, buffer);
}
PFNGLMULTITEXBUFFEREXTPROC glMultiTexBufferEXTproc = 0;
void APIENTRY glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) {
	if (!glMultiTexBufferEXTproc) return;
	glMultiTexBufferEXTproc(texunit, target, internalformat, buffer);
}
PFNGLTEXTUREPARAMETERIIVEXTPROC glTextureParameterIivEXTproc = 0;
void APIENTRY glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params) {
	if (!glTextureParameterIivEXTproc) return;
	glTextureParameterIivEXTproc(texture, target, pname, params);
}
PFNGLTEXTUREPARAMETERIUIVEXTPROC glTextureParameterIuivEXTproc = 0;
void APIENTRY glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint* params) {
	if (!glTextureParameterIuivEXTproc) return;
	glTextureParameterIuivEXTproc(texture, target, pname, params);
}
PFNGLGETTEXTUREPARAMETERIIVEXTPROC glGetTextureParameterIivEXTproc = 0;
void APIENTRY glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params) {
	if (!glGetTextureParameterIivEXTproc) return;
	glGetTextureParameterIivEXTproc(texture, target, pname, params);
}
PFNGLGETTEXTUREPARAMETERIUIVEXTPROC glGetTextureParameterIuivEXTproc = 0;
void APIENTRY glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint* params) {
	if (!glGetTextureParameterIuivEXTproc) return;
	glGetTextureParameterIuivEXTproc(texture, target, pname, params);
}
PFNGLMULTITEXPARAMETERIIVEXTPROC glMultiTexParameterIivEXTproc = 0;
void APIENTRY glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params) {
	if (!glMultiTexParameterIivEXTproc) return;
	glMultiTexParameterIivEXTproc(texunit, target, pname, params);
}
PFNGLMULTITEXPARAMETERIUIVEXTPROC glMultiTexParameterIuivEXTproc = 0;
void APIENTRY glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint* params) {
	if (!glMultiTexParameterIuivEXTproc) return;
	glMultiTexParameterIuivEXTproc(texunit, target, pname, params);
}
PFNGLGETMULTITEXPARAMETERIIVEXTPROC glGetMultiTexParameterIivEXTproc = 0;
void APIENTRY glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params) {
	if (!glGetMultiTexParameterIivEXTproc) return;
	glGetMultiTexParameterIivEXTproc(texunit, target, pname, params);
}
PFNGLGETMULTITEXPARAMETERIUIVEXTPROC glGetMultiTexParameterIuivEXTproc = 0;
void APIENTRY glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint* params) {
	if (!glGetMultiTexParameterIuivEXTproc) return;
	glGetMultiTexParameterIuivEXTproc(texunit, target, pname, params);
}
PFNGLPROGRAMUNIFORM1UIEXTPROC glProgramUniform1uiEXTproc = 0;
void APIENTRY glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0) {
	if (!glProgramUniform1uiEXTproc) return;
	glProgramUniform1uiEXTproc(program, location, v0);
}
PFNGLPROGRAMUNIFORM2UIEXTPROC glProgramUniform2uiEXTproc = 0;
void APIENTRY glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1) {
	if (!glProgramUniform2uiEXTproc) return;
	glProgramUniform2uiEXTproc(program, location, v0, v1);
}
PFNGLPROGRAMUNIFORM3UIEXTPROC glProgramUniform3uiEXTproc = 0;
void APIENTRY glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
	if (!glProgramUniform3uiEXTproc) return;
	glProgramUniform3uiEXTproc(program, location, v0, v1, v2);
}
PFNGLPROGRAMUNIFORM4UIEXTPROC glProgramUniform4uiEXTproc = 0;
void APIENTRY glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	if (!glProgramUniform4uiEXTproc) return;
	glProgramUniform4uiEXTproc(program, location, v0, v1, v2, v3);
}
PFNGLPROGRAMUNIFORM1UIVEXTPROC glProgramUniform1uivEXTproc = 0;
void APIENTRY glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform1uivEXTproc) return;
	glProgramUniform1uivEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2UIVEXTPROC glProgramUniform2uivEXTproc = 0;
void APIENTRY glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform2uivEXTproc) return;
	glProgramUniform2uivEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3UIVEXTPROC glProgramUniform3uivEXTproc = 0;
void APIENTRY glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform3uivEXTproc) return;
	glProgramUniform3uivEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4UIVEXTPROC glProgramUniform4uivEXTproc = 0;
void APIENTRY glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) {
	if (!glProgramUniform4uivEXTproc) return;
	glProgramUniform4uivEXTproc(program, location, count, value);
}
PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC glNamedProgramLocalParameters4fvEXTproc = 0;
void APIENTRY glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params) {
	if (!glNamedProgramLocalParameters4fvEXTproc) return;
	glNamedProgramLocalParameters4fvEXTproc(program, target, index, count, params);
}
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC glNamedProgramLocalParameterI4iEXTproc = 0;
void APIENTRY glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
	if (!glNamedProgramLocalParameterI4iEXTproc) return;
	glNamedProgramLocalParameterI4iEXTproc(program, target, index, x, y, z, w);
}
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC glNamedProgramLocalParameterI4ivEXTproc = 0;
void APIENTRY glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint* params) {
	if (!glNamedProgramLocalParameterI4ivEXTproc) return;
	glNamedProgramLocalParameterI4ivEXTproc(program, target, index, params);
}
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC glNamedProgramLocalParametersI4ivEXTproc = 0;
void APIENTRY glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params) {
	if (!glNamedProgramLocalParametersI4ivEXTproc) return;
	glNamedProgramLocalParametersI4ivEXTproc(program, target, index, count, params);
}
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC glNamedProgramLocalParameterI4uiEXTproc = 0;
void APIENTRY glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
	if (!glNamedProgramLocalParameterI4uiEXTproc) return;
	glNamedProgramLocalParameterI4uiEXTproc(program, target, index, x, y, z, w);
}
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC glNamedProgramLocalParameterI4uivEXTproc = 0;
void APIENTRY glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint* params) {
	if (!glNamedProgramLocalParameterI4uivEXTproc) return;
	glNamedProgramLocalParameterI4uivEXTproc(program, target, index, params);
}
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC glNamedProgramLocalParametersI4uivEXTproc = 0;
void APIENTRY glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params) {
	if (!glNamedProgramLocalParametersI4uivEXTproc) return;
	glNamedProgramLocalParametersI4uivEXTproc(program, target, index, count, params);
}
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC glGetNamedProgramLocalParameterIivEXTproc = 0;
void APIENTRY glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params) {
	if (!glGetNamedProgramLocalParameterIivEXTproc) return;
	glGetNamedProgramLocalParameterIivEXTproc(program, target, index, params);
}
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC glGetNamedProgramLocalParameterIuivEXTproc = 0;
void APIENTRY glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params) {
	if (!glGetNamedProgramLocalParameterIuivEXTproc) return;
	glGetNamedProgramLocalParameterIuivEXTproc(program, target, index, params);
}
PFNGLENABLECLIENTSTATEIEXTPROC glEnableClientStateiEXTproc = 0;
void APIENTRY glEnableClientStateiEXT(GLenum array, GLuint index) {
	if (!glEnableClientStateiEXTproc) return;
	glEnableClientStateiEXTproc(array, index);
}
PFNGLDISABLECLIENTSTATEIEXTPROC glDisableClientStateiEXTproc = 0;
void APIENTRY glDisableClientStateiEXT(GLenum array, GLuint index) {
	if (!glDisableClientStateiEXTproc) return;
	glDisableClientStateiEXTproc(array, index);
}
PFNGLGETFLOATI_VEXTPROC glGetFloati_vEXTproc = 0;
void APIENTRY glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat* params) {
	if (!glGetFloati_vEXTproc) return;
	glGetFloati_vEXTproc(pname, index, params);
}
PFNGLGETDOUBLEI_VEXTPROC glGetDoublei_vEXTproc = 0;
void APIENTRY glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble* params) {
	if (!glGetDoublei_vEXTproc) return;
	glGetDoublei_vEXTproc(pname, index, params);
}
PFNGLGETPOINTERI_VEXTPROC glGetPointeri_vEXTproc = 0;
void APIENTRY glGetPointeri_vEXT(GLenum pname, GLuint index, void** params) {
	if (!glGetPointeri_vEXTproc) return;
	glGetPointeri_vEXTproc(pname, index, params);
}
PFNGLNAMEDPROGRAMSTRINGEXTPROC glNamedProgramStringEXTproc = 0;
void APIENTRY glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void* string) {
	if (!glNamedProgramStringEXTproc) return;
	glNamedProgramStringEXTproc(program, target, format, len, string);
}
PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC glNamedProgramLocalParameter4dEXTproc = 0;
void APIENTRY glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glNamedProgramLocalParameter4dEXTproc) return;
	glNamedProgramLocalParameter4dEXTproc(program, target, index, x, y, z, w);
}
PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC glNamedProgramLocalParameter4dvEXTproc = 0;
void APIENTRY glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble* params) {
	if (!glNamedProgramLocalParameter4dvEXTproc) return;
	glNamedProgramLocalParameter4dvEXTproc(program, target, index, params);
}
PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC glNamedProgramLocalParameter4fEXTproc = 0;
void APIENTRY glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glNamedProgramLocalParameter4fEXTproc) return;
	glNamedProgramLocalParameter4fEXTproc(program, target, index, x, y, z, w);
}
PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC glNamedProgramLocalParameter4fvEXTproc = 0;
void APIENTRY glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat* params) {
	if (!glNamedProgramLocalParameter4fvEXTproc) return;
	glNamedProgramLocalParameter4fvEXTproc(program, target, index, params);
}
PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC glGetNamedProgramLocalParameterdvEXTproc = 0;
void APIENTRY glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params) {
	if (!glGetNamedProgramLocalParameterdvEXTproc) return;
	glGetNamedProgramLocalParameterdvEXTproc(program, target, index, params);
}
PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC glGetNamedProgramLocalParameterfvEXTproc = 0;
void APIENTRY glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params) {
	if (!glGetNamedProgramLocalParameterfvEXTproc) return;
	glGetNamedProgramLocalParameterfvEXTproc(program, target, index, params);
}
PFNGLGETNAMEDPROGRAMIVEXTPROC glGetNamedProgramivEXTproc = 0;
void APIENTRY glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint* params) {
	if (!glGetNamedProgramivEXTproc) return;
	glGetNamedProgramivEXTproc(program, target, pname, params);
}
PFNGLGETNAMEDPROGRAMSTRINGEXTPROC glGetNamedProgramStringEXTproc = 0;
void APIENTRY glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void* string) {
	if (!glGetNamedProgramStringEXTproc) return;
	glGetNamedProgramStringEXTproc(program, target, pname, string);
}
PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC glNamedRenderbufferStorageEXTproc = 0;
void APIENTRY glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glNamedRenderbufferStorageEXTproc) return;
	glNamedRenderbufferStorageEXTproc(renderbuffer, internalformat, width, height);
}
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC glGetNamedRenderbufferParameterivEXTproc = 0;
void APIENTRY glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint* params) {
	if (!glGetNamedRenderbufferParameterivEXTproc) return;
	glGetNamedRenderbufferParameterivEXTproc(renderbuffer, pname, params);
}
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glNamedRenderbufferStorageMultisampleEXTproc = 0;
void APIENTRY glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glNamedRenderbufferStorageMultisampleEXTproc) return;
	glNamedRenderbufferStorageMultisampleEXTproc(renderbuffer, samples, internalformat, width, height);
}
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC glNamedRenderbufferStorageMultisampleCoverageEXTproc = 0;
void APIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glNamedRenderbufferStorageMultisampleCoverageEXTproc) return;
	glNamedRenderbufferStorageMultisampleCoverageEXTproc(renderbuffer, coverageSamples, colorSamples, internalformat, width, height);
}
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC glCheckNamedFramebufferStatusEXTproc = 0;
GLenum APIENTRY glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target) {
	if (!glCheckNamedFramebufferStatusEXTproc) return 0;
	return glCheckNamedFramebufferStatusEXTproc(framebuffer, target);
}
PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC glNamedFramebufferTexture1DEXTproc = 0;
void APIENTRY glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	if (!glNamedFramebufferTexture1DEXTproc) return;
	glNamedFramebufferTexture1DEXTproc(framebuffer, attachment, textarget, texture, level);
}
PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC glNamedFramebufferTexture2DEXTproc = 0;
void APIENTRY glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	if (!glNamedFramebufferTexture2DEXTproc) return;
	glNamedFramebufferTexture2DEXTproc(framebuffer, attachment, textarget, texture, level);
}
PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC glNamedFramebufferTexture3DEXTproc = 0;
void APIENTRY glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	if (!glNamedFramebufferTexture3DEXTproc) return;
	glNamedFramebufferTexture3DEXTproc(framebuffer, attachment, textarget, texture, level, zoffset);
}
PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC glNamedFramebufferRenderbufferEXTproc = 0;
void APIENTRY glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	if (!glNamedFramebufferRenderbufferEXTproc) return;
	glNamedFramebufferRenderbufferEXTproc(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetNamedFramebufferAttachmentParameterivEXTproc = 0;
void APIENTRY glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params) {
	if (!glGetNamedFramebufferAttachmentParameterivEXTproc) return;
	glGetNamedFramebufferAttachmentParameterivEXTproc(framebuffer, attachment, pname, params);
}
PFNGLGENERATETEXTUREMIPMAPEXTPROC glGenerateTextureMipmapEXTproc = 0;
void APIENTRY glGenerateTextureMipmapEXT(GLuint texture, GLenum target) {
	if (!glGenerateTextureMipmapEXTproc) return;
	glGenerateTextureMipmapEXTproc(texture, target);
}
PFNGLGENERATEMULTITEXMIPMAPEXTPROC glGenerateMultiTexMipmapEXTproc = 0;
void APIENTRY glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target) {
	if (!glGenerateMultiTexMipmapEXTproc) return;
	glGenerateMultiTexMipmapEXTproc(texunit, target);
}
PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC glFramebufferDrawBufferEXTproc = 0;
void APIENTRY glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode) {
	if (!glFramebufferDrawBufferEXTproc) return;
	glFramebufferDrawBufferEXTproc(framebuffer, mode);
}
PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC glFramebufferDrawBuffersEXTproc = 0;
void APIENTRY glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs) {
	if (!glFramebufferDrawBuffersEXTproc) return;
	glFramebufferDrawBuffersEXTproc(framebuffer, n, bufs);
}
PFNGLFRAMEBUFFERREADBUFFEREXTPROC glFramebufferReadBufferEXTproc = 0;
void APIENTRY glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode) {
	if (!glFramebufferReadBufferEXTproc) return;
	glFramebufferReadBufferEXTproc(framebuffer, mode);
}
PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC glGetFramebufferParameterivEXTproc = 0;
void APIENTRY glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params) {
	if (!glGetFramebufferParameterivEXTproc) return;
	glGetFramebufferParameterivEXTproc(framebuffer, pname, params);
}
PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC glNamedCopyBufferSubDataEXTproc = 0;
void APIENTRY glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
	if (!glNamedCopyBufferSubDataEXTproc) return;
	glNamedCopyBufferSubDataEXTproc(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC glNamedFramebufferTextureEXTproc = 0;
void APIENTRY glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
	if (!glNamedFramebufferTextureEXTproc) return;
	glNamedFramebufferTextureEXTproc(framebuffer, attachment, texture, level);
}
PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC glNamedFramebufferTextureLayerEXTproc = 0;
void APIENTRY glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	if (!glNamedFramebufferTextureLayerEXTproc) return;
	glNamedFramebufferTextureLayerEXTproc(framebuffer, attachment, texture, level, layer);
}
PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC glNamedFramebufferTextureFaceEXTproc = 0;
void APIENTRY glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) {
	if (!glNamedFramebufferTextureFaceEXTproc) return;
	glNamedFramebufferTextureFaceEXTproc(framebuffer, attachment, texture, level, face);
}
PFNGLTEXTURERENDERBUFFEREXTPROC glTextureRenderbufferEXTproc = 0;
void APIENTRY glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer) {
	if (!glTextureRenderbufferEXTproc) return;
	glTextureRenderbufferEXTproc(texture, target, renderbuffer);
}
PFNGLMULTITEXRENDERBUFFEREXTPROC glMultiTexRenderbufferEXTproc = 0;
void APIENTRY glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer) {
	if (!glMultiTexRenderbufferEXTproc) return;
	glMultiTexRenderbufferEXTproc(texunit, target, renderbuffer);
}
PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC glVertexArrayVertexOffsetEXTproc = 0;
void APIENTRY glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayVertexOffsetEXTproc) return;
	glVertexArrayVertexOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
PFNGLVERTEXARRAYCOLOROFFSETEXTPROC glVertexArrayColorOffsetEXTproc = 0;
void APIENTRY glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayColorOffsetEXTproc) return;
	glVertexArrayColorOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC glVertexArrayEdgeFlagOffsetEXTproc = 0;
void APIENTRY glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayEdgeFlagOffsetEXTproc) return;
	glVertexArrayEdgeFlagOffsetEXTproc(vaobj, buffer, stride, offset);
}
PFNGLVERTEXARRAYINDEXOFFSETEXTPROC glVertexArrayIndexOffsetEXTproc = 0;
void APIENTRY glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayIndexOffsetEXTproc) return;
	glVertexArrayIndexOffsetEXTproc(vaobj, buffer, type, stride, offset);
}
PFNGLVERTEXARRAYNORMALOFFSETEXTPROC glVertexArrayNormalOffsetEXTproc = 0;
void APIENTRY glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayNormalOffsetEXTproc) return;
	glVertexArrayNormalOffsetEXTproc(vaobj, buffer, type, stride, offset);
}
PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC glVertexArrayTexCoordOffsetEXTproc = 0;
void APIENTRY glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayTexCoordOffsetEXTproc) return;
	glVertexArrayTexCoordOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC glVertexArrayMultiTexCoordOffsetEXTproc = 0;
void APIENTRY glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayMultiTexCoordOffsetEXTproc) return;
	glVertexArrayMultiTexCoordOffsetEXTproc(vaobj, buffer, texunit, size, type, stride, offset);
}
PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC glVertexArrayFogCoordOffsetEXTproc = 0;
void APIENTRY glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayFogCoordOffsetEXTproc) return;
	glVertexArrayFogCoordOffsetEXTproc(vaobj, buffer, type, stride, offset);
}
PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC glVertexArraySecondaryColorOffsetEXTproc = 0;
void APIENTRY glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArraySecondaryColorOffsetEXTproc) return;
	glVertexArraySecondaryColorOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC glVertexArrayVertexAttribOffsetEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayVertexAttribOffsetEXTproc) return;
	glVertexArrayVertexAttribOffsetEXTproc(vaobj, buffer, index, size, type, normalized, stride, offset);
}
PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC glVertexArrayVertexAttribIOffsetEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayVertexAttribIOffsetEXTproc) return;
	glVertexArrayVertexAttribIOffsetEXTproc(vaobj, buffer, index, size, type, stride, offset);
}
PFNGLENABLEVERTEXARRAYEXTPROC glEnableVertexArrayEXTproc = 0;
void APIENTRY glEnableVertexArrayEXT(GLuint vaobj, GLenum array) {
	if (!glEnableVertexArrayEXTproc) return;
	glEnableVertexArrayEXTproc(vaobj, array);
}
PFNGLDISABLEVERTEXARRAYEXTPROC glDisableVertexArrayEXTproc = 0;
void APIENTRY glDisableVertexArrayEXT(GLuint vaobj, GLenum array) {
	if (!glDisableVertexArrayEXTproc) return;
	glDisableVertexArrayEXTproc(vaobj, array);
}
PFNGLENABLEVERTEXARRAYATTRIBEXTPROC glEnableVertexArrayAttribEXTproc = 0;
void APIENTRY glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
	if (!glEnableVertexArrayAttribEXTproc) return;
	glEnableVertexArrayAttribEXTproc(vaobj, index);
}
PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC glDisableVertexArrayAttribEXTproc = 0;
void APIENTRY glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
	if (!glDisableVertexArrayAttribEXTproc) return;
	glDisableVertexArrayAttribEXTproc(vaobj, index);
}
PFNGLGETVERTEXARRAYINTEGERVEXTPROC glGetVertexArrayIntegervEXTproc = 0;
void APIENTRY glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint* param) {
	if (!glGetVertexArrayIntegervEXTproc) return;
	glGetVertexArrayIntegervEXTproc(vaobj, pname, param);
}
PFNGLGETVERTEXARRAYPOINTERVEXTPROC glGetVertexArrayPointervEXTproc = 0;
void APIENTRY glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void** param) {
	if (!glGetVertexArrayPointervEXTproc) return;
	glGetVertexArrayPointervEXTproc(vaobj, pname, param);
}
PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC glGetVertexArrayIntegeri_vEXTproc = 0;
void APIENTRY glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint* param) {
	if (!glGetVertexArrayIntegeri_vEXTproc) return;
	glGetVertexArrayIntegeri_vEXTproc(vaobj, index, pname, param);
}
PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC glGetVertexArrayPointeri_vEXTproc = 0;
void APIENTRY glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void** param) {
	if (!glGetVertexArrayPointeri_vEXTproc) return;
	glGetVertexArrayPointeri_vEXTproc(vaobj, index, pname, param);
}
PFNGLMAPNAMEDBUFFERRANGEEXTPROC glMapNamedBufferRangeEXTproc = 0;
void* APIENTRY glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
	if (!glMapNamedBufferRangeEXTproc) return 0;
	return glMapNamedBufferRangeEXTproc(buffer, offset, length, access);
}
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC glFlushMappedNamedBufferRangeEXTproc = 0;
void APIENTRY glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length) {
	if (!glFlushMappedNamedBufferRangeEXTproc) return;
	glFlushMappedNamedBufferRangeEXTproc(buffer, offset, length);
}
PFNGLNAMEDBUFFERSTORAGEEXTPROC glNamedBufferStorageEXTproc = 0;
void APIENTRY glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags) {
	if (!glNamedBufferStorageEXTproc) return;
	glNamedBufferStorageEXTproc(buffer, size, data, flags);
}
PFNGLCLEARNAMEDBUFFERDATAEXTPROC glClearNamedBufferDataEXTproc = 0;
void APIENTRY glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data) {
	if (!glClearNamedBufferDataEXTproc) return;
	glClearNamedBufferDataEXTproc(buffer, internalformat, format, type, data);
}
PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC glClearNamedBufferSubDataEXTproc = 0;
void APIENTRY glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) {
	if (!glClearNamedBufferSubDataEXTproc) return;
	glClearNamedBufferSubDataEXTproc(buffer, internalformat, offset, size, format, type, data);
}
PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC glNamedFramebufferParameteriEXTproc = 0;
void APIENTRY glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param) {
	if (!glNamedFramebufferParameteriEXTproc) return;
	glNamedFramebufferParameteriEXTproc(framebuffer, pname, param);
}
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC glGetNamedFramebufferParameterivEXTproc = 0;
void APIENTRY glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params) {
	if (!glGetNamedFramebufferParameterivEXTproc) return;
	glGetNamedFramebufferParameterivEXTproc(framebuffer, pname, params);
}
PFNGLPROGRAMUNIFORM1DEXTPROC glProgramUniform1dEXTproc = 0;
void APIENTRY glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x) {
	if (!glProgramUniform1dEXTproc) return;
	glProgramUniform1dEXTproc(program, location, x);
}
PFNGLPROGRAMUNIFORM2DEXTPROC glProgramUniform2dEXTproc = 0;
void APIENTRY glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y) {
	if (!glProgramUniform2dEXTproc) return;
	glProgramUniform2dEXTproc(program, location, x, y);
}
PFNGLPROGRAMUNIFORM3DEXTPROC glProgramUniform3dEXTproc = 0;
void APIENTRY glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) {
	if (!glProgramUniform3dEXTproc) return;
	glProgramUniform3dEXTproc(program, location, x, y, z);
}
PFNGLPROGRAMUNIFORM4DEXTPROC glProgramUniform4dEXTproc = 0;
void APIENTRY glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glProgramUniform4dEXTproc) return;
	glProgramUniform4dEXTproc(program, location, x, y, z, w);
}
PFNGLPROGRAMUNIFORM1DVEXTPROC glProgramUniform1dvEXTproc = 0;
void APIENTRY glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform1dvEXTproc) return;
	glProgramUniform1dvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM2DVEXTPROC glProgramUniform2dvEXTproc = 0;
void APIENTRY glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform2dvEXTproc) return;
	glProgramUniform2dvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM3DVEXTPROC glProgramUniform3dvEXTproc = 0;
void APIENTRY glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform3dvEXTproc) return;
	glProgramUniform3dvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORM4DVEXTPROC glProgramUniform4dvEXTproc = 0;
void APIENTRY glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value) {
	if (!glProgramUniform4dvEXTproc) return;
	glProgramUniform4dvEXTproc(program, location, count, value);
}
PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC glProgramUniformMatrix2dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix2dvEXTproc) return;
	glProgramUniformMatrix2dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC glProgramUniformMatrix3dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix3dvEXTproc) return;
	glProgramUniformMatrix3dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC glProgramUniformMatrix4dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix4dvEXTproc) return;
	glProgramUniformMatrix4dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC glProgramUniformMatrix2x3dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix2x3dvEXTproc) return;
	glProgramUniformMatrix2x3dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC glProgramUniformMatrix2x4dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix2x4dvEXTproc) return;
	glProgramUniformMatrix2x4dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC glProgramUniformMatrix3x2dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix3x2dvEXTproc) return;
	glProgramUniformMatrix3x2dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC glProgramUniformMatrix3x4dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix3x4dvEXTproc) return;
	glProgramUniformMatrix3x4dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC glProgramUniformMatrix4x2dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix4x2dvEXTproc) return;
	glProgramUniformMatrix4x2dvEXTproc(program, location, count, transpose, value);
}
PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC glProgramUniformMatrix4x3dvEXTproc = 0;
void APIENTRY glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) {
	if (!glProgramUniformMatrix4x3dvEXTproc) return;
	glProgramUniformMatrix4x3dvEXTproc(program, location, count, transpose, value);
}
PFNGLTEXTUREBUFFERRANGEEXTPROC glTextureBufferRangeEXTproc = 0;
void APIENTRY glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	if (!glTextureBufferRangeEXTproc) return;
	glTextureBufferRangeEXTproc(texture, target, internalformat, buffer, offset, size);
}
PFNGLTEXTURESTORAGE1DEXTPROC glTextureStorage1DEXTproc = 0;
void APIENTRY glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	if (!glTextureStorage1DEXTproc) return;
	glTextureStorage1DEXTproc(texture, target, levels, internalformat, width);
}
PFNGLTEXTURESTORAGE2DEXTPROC glTextureStorage2DEXTproc = 0;
void APIENTRY glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glTextureStorage2DEXTproc) return;
	glTextureStorage2DEXTproc(texture, target, levels, internalformat, width, height);
}
PFNGLTEXTURESTORAGE3DEXTPROC glTextureStorage3DEXTproc = 0;
void APIENTRY glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	if (!glTextureStorage3DEXTproc) return;
	glTextureStorage3DEXTproc(texture, target, levels, internalformat, width, height, depth);
}
PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC glTextureStorage2DMultisampleEXTproc = 0;
void APIENTRY glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
	if (!glTextureStorage2DMultisampleEXTproc) return;
	glTextureStorage2DMultisampleEXTproc(texture, target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC glTextureStorage3DMultisampleEXTproc = 0;
void APIENTRY glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
	if (!glTextureStorage3DMultisampleEXTproc) return;
	glTextureStorage3DMultisampleEXTproc(texture, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC glVertexArrayBindVertexBufferEXTproc = 0;
void APIENTRY glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
	if (!glVertexArrayBindVertexBufferEXTproc) return;
	glVertexArrayBindVertexBufferEXTproc(vaobj, bindingindex, buffer, offset, stride);
}
PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC glVertexArrayVertexAttribFormatEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
	if (!glVertexArrayVertexAttribFormatEXTproc) return;
	glVertexArrayVertexAttribFormatEXTproc(vaobj, attribindex, size, type, normalized, relativeoffset);
}
PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC glVertexArrayVertexAttribIFormatEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	if (!glVertexArrayVertexAttribIFormatEXTproc) return;
	glVertexArrayVertexAttribIFormatEXTproc(vaobj, attribindex, size, type, relativeoffset);
}
PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC glVertexArrayVertexAttribLFormatEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
	if (!glVertexArrayVertexAttribLFormatEXTproc) return;
	glVertexArrayVertexAttribLFormatEXTproc(vaobj, attribindex, size, type, relativeoffset);
}
PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC glVertexArrayVertexAttribBindingEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
	if (!glVertexArrayVertexAttribBindingEXTproc) return;
	glVertexArrayVertexAttribBindingEXTproc(vaobj, attribindex, bindingindex);
}
PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC glVertexArrayVertexBindingDivisorEXTproc = 0;
void APIENTRY glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
	if (!glVertexArrayVertexBindingDivisorEXTproc) return;
	glVertexArrayVertexBindingDivisorEXTproc(vaobj, bindingindex, divisor);
}
PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC glVertexArrayVertexAttribLOffsetEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
	if (!glVertexArrayVertexAttribLOffsetEXTproc) return;
	glVertexArrayVertexAttribLOffsetEXTproc(vaobj, buffer, index, size, type, stride, offset);
}
PFNGLTEXTUREPAGECOMMITMENTEXTPROC glTexturePageCommitmentEXTproc = 0;
void APIENTRY glTexturePageCommitmentEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
	if (!glTexturePageCommitmentEXTproc) return;
	glTexturePageCommitmentEXTproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC glVertexArrayVertexAttribDivisorEXTproc = 0;
void APIENTRY glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor) {
	if (!glVertexArrayVertexAttribDivisorEXTproc) return;
	glVertexArrayVertexAttribDivisorEXTproc(vaobj, index, divisor);
}
PFNGLCOLORMASKINDEXEDEXTPROC glColorMaskIndexedEXTproc = 0;
void APIENTRY glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
	if (!glColorMaskIndexedEXTproc) return;
	glColorMaskIndexedEXTproc(index, r, g, b, a);
}
PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstancedEXTproc = 0;
void APIENTRY glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount) {
	if (!glDrawArraysInstancedEXTproc) return;
	glDrawArraysInstancedEXTproc(mode, start, count, primcount);
}
PFNGLDRAWELEMENTSINSTANCEDEXTPROC glDrawElementsInstancedEXTproc = 0;
void APIENTRY glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount) {
	if (!glDrawElementsInstancedEXTproc) return;
	glDrawElementsInstancedEXTproc(mode, count, type, indices, primcount);
}
PFNGLDRAWRANGEELEMENTSEXTPROC glDrawRangeElementsEXTproc = 0;
void APIENTRY glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) {
	if (!glDrawRangeElementsEXTproc) return;
	glDrawRangeElementsEXTproc(mode, start, end, count, type, indices);
}
PFNGLBUFFERSTORAGEEXTERNALEXTPROC glBufferStorageExternalEXTproc = 0;
void APIENTRY glBufferStorageExternalEXT(GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) {
	if (!glBufferStorageExternalEXTproc) return;
	glBufferStorageExternalEXTproc(target, offset, size, clientBuffer, flags);
}
PFNGLNAMEDBUFFERSTORAGEEXTERNALEXTPROC glNamedBufferStorageExternalEXTproc = 0;
void APIENTRY glNamedBufferStorageExternalEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) {
	if (!glNamedBufferStorageExternalEXTproc) return;
	glNamedBufferStorageExternalEXTproc(buffer, offset, size, clientBuffer, flags);
}
PFNGLFOGCOORDFEXTPROC glFogCoordfEXTproc = 0;
void APIENTRY glFogCoordfEXT(GLfloat coord) {
	if (!glFogCoordfEXTproc) return;
	glFogCoordfEXTproc(coord);
}
PFNGLFOGCOORDFVEXTPROC glFogCoordfvEXTproc = 0;
void APIENTRY glFogCoordfvEXT(const GLfloat* coord) {
	if (!glFogCoordfvEXTproc) return;
	glFogCoordfvEXTproc(coord);
}
PFNGLFOGCOORDDEXTPROC glFogCoorddEXTproc = 0;
void APIENTRY glFogCoorddEXT(GLdouble coord) {
	if (!glFogCoorddEXTproc) return;
	glFogCoorddEXTproc(coord);
}
PFNGLFOGCOORDDVEXTPROC glFogCoorddvEXTproc = 0;
void APIENTRY glFogCoorddvEXT(const GLdouble* coord) {
	if (!glFogCoorddvEXTproc) return;
	glFogCoorddvEXTproc(coord);
}
PFNGLFOGCOORDPOINTEREXTPROC glFogCoordPointerEXTproc = 0;
void APIENTRY glFogCoordPointerEXT(GLenum type, GLsizei stride, const void* pointer) {
	if (!glFogCoordPointerEXTproc) return;
	glFogCoordPointerEXTproc(type, stride, pointer);
}
PFNGLBLITFRAMEBUFFEREXTPROC glBlitFramebufferEXTproc = 0;
void APIENTRY glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	if (!glBlitFramebufferEXTproc) return;
	glBlitFramebufferEXTproc(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLBLITFRAMEBUFFERLAYERSEXTPROC glBlitFramebufferLayersEXTproc = 0;
void APIENTRY glBlitFramebufferLayersEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	if (!glBlitFramebufferLayersEXTproc) return;
	glBlitFramebufferLayersEXTproc(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLBLITFRAMEBUFFERLAYEREXTPROC glBlitFramebufferLayerEXTproc = 0;
void APIENTRY glBlitFramebufferLayerEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint srcLayer, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLint dstLayer, GLbitfield mask, GLenum filter) {
	if (!glBlitFramebufferLayerEXTproc) return;
	glBlitFramebufferLayerEXTproc(srcX0, srcY0, srcX1, srcY1, srcLayer, dstX0, dstY0, dstX1, dstY1, dstLayer, mask, filter);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glRenderbufferStorageMultisampleEXTproc = 0;
void APIENTRY glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glRenderbufferStorageMultisampleEXTproc) return;
	glRenderbufferStorageMultisampleEXTproc(target, samples, internalformat, width, height);
}
PFNGLISRENDERBUFFEREXTPROC glIsRenderbufferEXTproc = 0;
GLboolean APIENTRY glIsRenderbufferEXT(GLuint renderbuffer) {
	if (!glIsRenderbufferEXTproc) return 0;
	return glIsRenderbufferEXTproc(renderbuffer);
}
PFNGLBINDRENDERBUFFEREXTPROC glBindRenderbufferEXTproc = 0;
void APIENTRY glBindRenderbufferEXT(GLenum target, GLuint renderbuffer) {
	if (!glBindRenderbufferEXTproc) return;
	glBindRenderbufferEXTproc(target, renderbuffer);
}
PFNGLDELETERENDERBUFFERSEXTPROC glDeleteRenderbuffersEXTproc = 0;
void APIENTRY glDeleteRenderbuffersEXT(GLsizei n, const GLuint* renderbuffers) {
	if (!glDeleteRenderbuffersEXTproc) return;
	glDeleteRenderbuffersEXTproc(n, renderbuffers);
}
PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXTproc = 0;
void APIENTRY glGenRenderbuffersEXT(GLsizei n, GLuint* renderbuffers) {
	if (!glGenRenderbuffersEXTproc) return;
	glGenRenderbuffersEXTproc(n, renderbuffers);
}
PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXTproc = 0;
void APIENTRY glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glRenderbufferStorageEXTproc) return;
	glRenderbufferStorageEXTproc(target, internalformat, width, height);
}
PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC glGetRenderbufferParameterivEXTproc = 0;
void APIENTRY glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint* params) {
	if (!glGetRenderbufferParameterivEXTproc) return;
	glGetRenderbufferParameterivEXTproc(target, pname, params);
}
PFNGLISFRAMEBUFFEREXTPROC glIsFramebufferEXTproc = 0;
GLboolean APIENTRY glIsFramebufferEXT(GLuint framebuffer) {
	if (!glIsFramebufferEXTproc) return 0;
	return glIsFramebufferEXTproc(framebuffer);
}
PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXTproc = 0;
void APIENTRY glBindFramebufferEXT(GLenum target, GLuint framebuffer) {
	if (!glBindFramebufferEXTproc) return;
	glBindFramebufferEXTproc(target, framebuffer);
}
PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXTproc = 0;
void APIENTRY glDeleteFramebuffersEXT(GLsizei n, const GLuint* framebuffers) {
	if (!glDeleteFramebuffersEXTproc) return;
	glDeleteFramebuffersEXTproc(n, framebuffers);
}
PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXTproc = 0;
void APIENTRY glGenFramebuffersEXT(GLsizei n, GLuint* framebuffers) {
	if (!glGenFramebuffersEXTproc) return;
	glGenFramebuffersEXTproc(n, framebuffers);
}
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXTproc = 0;
GLenum APIENTRY glCheckFramebufferStatusEXT(GLenum target) {
	if (!glCheckFramebufferStatusEXTproc) return 0;
	return glCheckFramebufferStatusEXTproc(target);
}
PFNGLFRAMEBUFFERTEXTURE1DEXTPROC glFramebufferTexture1DEXTproc = 0;
void APIENTRY glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	if (!glFramebufferTexture1DEXTproc) return;
	glFramebufferTexture1DEXTproc(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXTproc = 0;
void APIENTRY glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	if (!glFramebufferTexture2DEXTproc) return;
	glFramebufferTexture2DEXTproc(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE3DEXTPROC glFramebufferTexture3DEXTproc = 0;
void APIENTRY glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
	if (!glFramebufferTexture3DEXTproc) return;
	glFramebufferTexture3DEXTproc(target, attachment, textarget, texture, level, zoffset);
}
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXTproc = 0;
void APIENTRY glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	if (!glFramebufferRenderbufferEXTproc) return;
	glFramebufferRenderbufferEXTproc(target, attachment, renderbuffertarget, renderbuffer);
}
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetFramebufferAttachmentParameterivEXTproc = 0;
void APIENTRY glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint* params) {
	if (!glGetFramebufferAttachmentParameterivEXTproc) return;
	glGetFramebufferAttachmentParameterivEXTproc(target, attachment, pname, params);
}
PFNGLGENERATEMIPMAPEXTPROC glGenerateMipmapEXTproc = 0;
void APIENTRY glGenerateMipmapEXT(GLenum target) {
	if (!glGenerateMipmapEXTproc) return;
	glGenerateMipmapEXTproc(target);
}
PFNGLPROGRAMPARAMETERIEXTPROC glProgramParameteriEXTproc = 0;
void APIENTRY glProgramParameteriEXT(GLuint program, GLenum pname, GLint value) {
	if (!glProgramParameteriEXTproc) return;
	glProgramParameteriEXTproc(program, pname, value);
}
PFNGLPROGRAMENVPARAMETERS4FVEXTPROC glProgramEnvParameters4fvEXTproc = 0;
void APIENTRY glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params) {
	if (!glProgramEnvParameters4fvEXTproc) return;
	glProgramEnvParameters4fvEXTproc(target, index, count, params);
}
PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC glProgramLocalParameters4fvEXTproc = 0;
void APIENTRY glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params) {
	if (!glProgramLocalParameters4fvEXTproc) return;
	glProgramLocalParameters4fvEXTproc(target, index, count, params);
}
PFNGLGETUNIFORMUIVEXTPROC glGetUniformuivEXTproc = 0;
void APIENTRY glGetUniformuivEXT(GLuint program, GLint location, GLuint* params) {
	if (!glGetUniformuivEXTproc) return;
	glGetUniformuivEXTproc(program, location, params);
}
PFNGLBINDFRAGDATALOCATIONEXTPROC glBindFragDataLocationEXTproc = 0;
void APIENTRY glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar* name) {
	if (!glBindFragDataLocationEXTproc) return;
	glBindFragDataLocationEXTproc(program, color, name);
}
PFNGLGETFRAGDATALOCATIONEXTPROC glGetFragDataLocationEXTproc = 0;
GLint APIENTRY glGetFragDataLocationEXT(GLuint program, const GLchar* name) {
	if (!glGetFragDataLocationEXTproc) return 0;
	return glGetFragDataLocationEXTproc(program, name);
}
PFNGLUNIFORM1UIEXTPROC glUniform1uiEXTproc = 0;
void APIENTRY glUniform1uiEXT(GLint location, GLuint v0) {
	if (!glUniform1uiEXTproc) return;
	glUniform1uiEXTproc(location, v0);
}
PFNGLUNIFORM2UIEXTPROC glUniform2uiEXTproc = 0;
void APIENTRY glUniform2uiEXT(GLint location, GLuint v0, GLuint v1) {
	if (!glUniform2uiEXTproc) return;
	glUniform2uiEXTproc(location, v0, v1);
}
PFNGLUNIFORM3UIEXTPROC glUniform3uiEXTproc = 0;
void APIENTRY glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2) {
	if (!glUniform3uiEXTproc) return;
	glUniform3uiEXTproc(location, v0, v1, v2);
}
PFNGLUNIFORM4UIEXTPROC glUniform4uiEXTproc = 0;
void APIENTRY glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
	if (!glUniform4uiEXTproc) return;
	glUniform4uiEXTproc(location, v0, v1, v2, v3);
}
PFNGLUNIFORM1UIVEXTPROC glUniform1uivEXTproc = 0;
void APIENTRY glUniform1uivEXT(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform1uivEXTproc) return;
	glUniform1uivEXTproc(location, count, value);
}
PFNGLUNIFORM2UIVEXTPROC glUniform2uivEXTproc = 0;
void APIENTRY glUniform2uivEXT(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform2uivEXTproc) return;
	glUniform2uivEXTproc(location, count, value);
}
PFNGLUNIFORM3UIVEXTPROC glUniform3uivEXTproc = 0;
void APIENTRY glUniform3uivEXT(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform3uivEXTproc) return;
	glUniform3uivEXTproc(location, count, value);
}
PFNGLUNIFORM4UIVEXTPROC glUniform4uivEXTproc = 0;
void APIENTRY glUniform4uivEXT(GLint location, GLsizei count, const GLuint* value) {
	if (!glUniform4uivEXTproc) return;
	glUniform4uivEXTproc(location, count, value);
}
PFNGLVERTEXATTRIBI1IEXTPROC glVertexAttribI1iEXTproc = 0;
void APIENTRY glVertexAttribI1iEXT(GLuint index, GLint x) {
	if (!glVertexAttribI1iEXTproc) return;
	glVertexAttribI1iEXTproc(index, x);
}
PFNGLVERTEXATTRIBI2IEXTPROC glVertexAttribI2iEXTproc = 0;
void APIENTRY glVertexAttribI2iEXT(GLuint index, GLint x, GLint y) {
	if (!glVertexAttribI2iEXTproc) return;
	glVertexAttribI2iEXTproc(index, x, y);
}
PFNGLVERTEXATTRIBI3IEXTPROC glVertexAttribI3iEXTproc = 0;
void APIENTRY glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z) {
	if (!glVertexAttribI3iEXTproc) return;
	glVertexAttribI3iEXTproc(index, x, y, z);
}
PFNGLVERTEXATTRIBI4IEXTPROC glVertexAttribI4iEXTproc = 0;
void APIENTRY glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w) {
	if (!glVertexAttribI4iEXTproc) return;
	glVertexAttribI4iEXTproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI1UIEXTPROC glVertexAttribI1uiEXTproc = 0;
void APIENTRY glVertexAttribI1uiEXT(GLuint index, GLuint x) {
	if (!glVertexAttribI1uiEXTproc) return;
	glVertexAttribI1uiEXTproc(index, x);
}
PFNGLVERTEXATTRIBI2UIEXTPROC glVertexAttribI2uiEXTproc = 0;
void APIENTRY glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y) {
	if (!glVertexAttribI2uiEXTproc) return;
	glVertexAttribI2uiEXTproc(index, x, y);
}
PFNGLVERTEXATTRIBI3UIEXTPROC glVertexAttribI3uiEXTproc = 0;
void APIENTRY glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z) {
	if (!glVertexAttribI3uiEXTproc) return;
	glVertexAttribI3uiEXTproc(index, x, y, z);
}
PFNGLVERTEXATTRIBI4UIEXTPROC glVertexAttribI4uiEXTproc = 0;
void APIENTRY glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
	if (!glVertexAttribI4uiEXTproc) return;
	glVertexAttribI4uiEXTproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI1IVEXTPROC glVertexAttribI1ivEXTproc = 0;
void APIENTRY glVertexAttribI1ivEXT(GLuint index, const GLint* v) {
	if (!glVertexAttribI1ivEXTproc) return;
	glVertexAttribI1ivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI2IVEXTPROC glVertexAttribI2ivEXTproc = 0;
void APIENTRY glVertexAttribI2ivEXT(GLuint index, const GLint* v) {
	if (!glVertexAttribI2ivEXTproc) return;
	glVertexAttribI2ivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI3IVEXTPROC glVertexAttribI3ivEXTproc = 0;
void APIENTRY glVertexAttribI3ivEXT(GLuint index, const GLint* v) {
	if (!glVertexAttribI3ivEXTproc) return;
	glVertexAttribI3ivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI4IVEXTPROC glVertexAttribI4ivEXTproc = 0;
void APIENTRY glVertexAttribI4ivEXT(GLuint index, const GLint* v) {
	if (!glVertexAttribI4ivEXTproc) return;
	glVertexAttribI4ivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI1UIVEXTPROC glVertexAttribI1uivEXTproc = 0;
void APIENTRY glVertexAttribI1uivEXT(GLuint index, const GLuint* v) {
	if (!glVertexAttribI1uivEXTproc) return;
	glVertexAttribI1uivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI2UIVEXTPROC glVertexAttribI2uivEXTproc = 0;
void APIENTRY glVertexAttribI2uivEXT(GLuint index, const GLuint* v) {
	if (!glVertexAttribI2uivEXTproc) return;
	glVertexAttribI2uivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI3UIVEXTPROC glVertexAttribI3uivEXTproc = 0;
void APIENTRY glVertexAttribI3uivEXT(GLuint index, const GLuint* v) {
	if (!glVertexAttribI3uivEXTproc) return;
	glVertexAttribI3uivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI4UIVEXTPROC glVertexAttribI4uivEXTproc = 0;
void APIENTRY glVertexAttribI4uivEXT(GLuint index, const GLuint* v) {
	if (!glVertexAttribI4uivEXTproc) return;
	glVertexAttribI4uivEXTproc(index, v);
}
PFNGLVERTEXATTRIBI4BVEXTPROC glVertexAttribI4bvEXTproc = 0;
void APIENTRY glVertexAttribI4bvEXT(GLuint index, const GLbyte* v) {
	if (!glVertexAttribI4bvEXTproc) return;
	glVertexAttribI4bvEXTproc(index, v);
}
PFNGLVERTEXATTRIBI4SVEXTPROC glVertexAttribI4svEXTproc = 0;
void APIENTRY glVertexAttribI4svEXT(GLuint index, const GLshort* v) {
	if (!glVertexAttribI4svEXTproc) return;
	glVertexAttribI4svEXTproc(index, v);
}
PFNGLVERTEXATTRIBI4UBVEXTPROC glVertexAttribI4ubvEXTproc = 0;
void APIENTRY glVertexAttribI4ubvEXT(GLuint index, const GLubyte* v) {
	if (!glVertexAttribI4ubvEXTproc) return;
	glVertexAttribI4ubvEXTproc(index, v);
}
PFNGLVERTEXATTRIBI4USVEXTPROC glVertexAttribI4usvEXTproc = 0;
void APIENTRY glVertexAttribI4usvEXT(GLuint index, const GLushort* v) {
	if (!glVertexAttribI4usvEXTproc) return;
	glVertexAttribI4usvEXTproc(index, v);
}
PFNGLVERTEXATTRIBIPOINTEREXTPROC glVertexAttribIPointerEXTproc = 0;
void APIENTRY glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glVertexAttribIPointerEXTproc) return;
	glVertexAttribIPointerEXTproc(index, size, type, stride, pointer);
}
PFNGLGETVERTEXATTRIBIIVEXTPROC glGetVertexAttribIivEXTproc = 0;
void APIENTRY glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint* params) {
	if (!glGetVertexAttribIivEXTproc) return;
	glGetVertexAttribIivEXTproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBIUIVEXTPROC glGetVertexAttribIuivEXTproc = 0;
void APIENTRY glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint* params) {
	if (!glGetVertexAttribIuivEXTproc) return;
	glGetVertexAttribIuivEXTproc(index, pname, params);
}
PFNGLGETHISTOGRAMEXTPROC glGetHistogramEXTproc = 0;
void APIENTRY glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values) {
	if (!glGetHistogramEXTproc) return;
	glGetHistogramEXTproc(target, reset, format, type, values);
}
PFNGLGETHISTOGRAMPARAMETERFVEXTPROC glGetHistogramParameterfvEXTproc = 0;
void APIENTRY glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetHistogramParameterfvEXTproc) return;
	glGetHistogramParameterfvEXTproc(target, pname, params);
}
PFNGLGETHISTOGRAMPARAMETERIVEXTPROC glGetHistogramParameterivEXTproc = 0;
void APIENTRY glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint* params) {
	if (!glGetHistogramParameterivEXTproc) return;
	glGetHistogramParameterivEXTproc(target, pname, params);
}
PFNGLGETMINMAXEXTPROC glGetMinmaxEXTproc = 0;
void APIENTRY glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values) {
	if (!glGetMinmaxEXTproc) return;
	glGetMinmaxEXTproc(target, reset, format, type, values);
}
PFNGLGETMINMAXPARAMETERFVEXTPROC glGetMinmaxParameterfvEXTproc = 0;
void APIENTRY glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetMinmaxParameterfvEXTproc) return;
	glGetMinmaxParameterfvEXTproc(target, pname, params);
}
PFNGLGETMINMAXPARAMETERIVEXTPROC glGetMinmaxParameterivEXTproc = 0;
void APIENTRY glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint* params) {
	if (!glGetMinmaxParameterivEXTproc) return;
	glGetMinmaxParameterivEXTproc(target, pname, params);
}
PFNGLHISTOGRAMEXTPROC glHistogramEXTproc = 0;
void APIENTRY glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
	if (!glHistogramEXTproc) return;
	glHistogramEXTproc(target, width, internalformat, sink);
}
PFNGLMINMAXEXTPROC glMinmaxEXTproc = 0;
void APIENTRY glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink) {
	if (!glMinmaxEXTproc) return;
	glMinmaxEXTproc(target, internalformat, sink);
}
PFNGLRESETHISTOGRAMEXTPROC glResetHistogramEXTproc = 0;
void APIENTRY glResetHistogramEXT(GLenum target) {
	if (!glResetHistogramEXTproc) return;
	glResetHistogramEXTproc(target);
}
PFNGLRESETMINMAXEXTPROC glResetMinmaxEXTproc = 0;
void APIENTRY glResetMinmaxEXT(GLenum target) {
	if (!glResetMinmaxEXTproc) return;
	glResetMinmaxEXTproc(target);
}
PFNGLINDEXFUNCEXTPROC glIndexFuncEXTproc = 0;
void APIENTRY glIndexFuncEXT(GLenum func, GLclampf ref) {
	if (!glIndexFuncEXTproc) return;
	glIndexFuncEXTproc(func, ref);
}
PFNGLINDEXMATERIALEXTPROC glIndexMaterialEXTproc = 0;
void APIENTRY glIndexMaterialEXT(GLenum face, GLenum mode) {
	if (!glIndexMaterialEXTproc) return;
	glIndexMaterialEXTproc(face, mode);
}
PFNGLAPPLYTEXTUREEXTPROC glApplyTextureEXTproc = 0;
void APIENTRY glApplyTextureEXT(GLenum mode) {
	if (!glApplyTextureEXTproc) return;
	glApplyTextureEXTproc(mode);
}
PFNGLTEXTURELIGHTEXTPROC glTextureLightEXTproc = 0;
void APIENTRY glTextureLightEXT(GLenum pname) {
	if (!glTextureLightEXTproc) return;
	glTextureLightEXTproc(pname);
}
PFNGLTEXTUREMATERIALEXTPROC glTextureMaterialEXTproc = 0;
void APIENTRY glTextureMaterialEXT(GLenum face, GLenum mode) {
	if (!glTextureMaterialEXTproc) return;
	glTextureMaterialEXTproc(face, mode);
}
PFNGLGETUNSIGNEDBYTEVEXTPROC glGetUnsignedBytevEXTproc = 0;
void APIENTRY glGetUnsignedBytevEXT(GLenum pname, GLubyte* data) {
	if (!glGetUnsignedBytevEXTproc) return;
	glGetUnsignedBytevEXTproc(pname, data);
}
PFNGLGETUNSIGNEDBYTEI_VEXTPROC glGetUnsignedBytei_vEXTproc = 0;
void APIENTRY glGetUnsignedBytei_vEXT(GLenum target, GLuint index, GLubyte* data) {
	if (!glGetUnsignedBytei_vEXTproc) return;
	glGetUnsignedBytei_vEXTproc(target, index, data);
}
PFNGLDELETEMEMORYOBJECTSEXTPROC glDeleteMemoryObjectsEXTproc = 0;
void APIENTRY glDeleteMemoryObjectsEXT(GLsizei n, const GLuint* memoryObjects) {
	if (!glDeleteMemoryObjectsEXTproc) return;
	glDeleteMemoryObjectsEXTproc(n, memoryObjects);
}
PFNGLISMEMORYOBJECTEXTPROC glIsMemoryObjectEXTproc = 0;
GLboolean APIENTRY glIsMemoryObjectEXT(GLuint memoryObject) {
	if (!glIsMemoryObjectEXTproc) return 0;
	return glIsMemoryObjectEXTproc(memoryObject);
}
PFNGLCREATEMEMORYOBJECTSEXTPROC glCreateMemoryObjectsEXTproc = 0;
void APIENTRY glCreateMemoryObjectsEXT(GLsizei n, GLuint* memoryObjects) {
	if (!glCreateMemoryObjectsEXTproc) return;
	glCreateMemoryObjectsEXTproc(n, memoryObjects);
}
PFNGLMEMORYOBJECTPARAMETERIVEXTPROC glMemoryObjectParameterivEXTproc = 0;
void APIENTRY glMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, const GLint* params) {
	if (!glMemoryObjectParameterivEXTproc) return;
	glMemoryObjectParameterivEXTproc(memoryObject, pname, params);
}
PFNGLGETMEMORYOBJECTPARAMETERIVEXTPROC glGetMemoryObjectParameterivEXTproc = 0;
void APIENTRY glGetMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint* params) {
	if (!glGetMemoryObjectParameterivEXTproc) return;
	glGetMemoryObjectParameterivEXTproc(memoryObject, pname, params);
}
PFNGLTEXSTORAGEMEM2DEXTPROC glTexStorageMem2DEXTproc = 0;
void APIENTRY glTexStorageMem2DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) {
	if (!glTexStorageMem2DEXTproc) return;
	glTexStorageMem2DEXTproc(target, levels, internalFormat, width, height, memory, offset);
}
PFNGLTEXSTORAGEMEM2DMULTISAMPLEEXTPROC glTexStorageMem2DMultisampleEXTproc = 0;
void APIENTRY glTexStorageMem2DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	if (!glTexStorageMem2DMultisampleEXTproc) return;
	glTexStorageMem2DMultisampleEXTproc(target, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
PFNGLTEXSTORAGEMEM3DEXTPROC glTexStorageMem3DEXTproc = 0;
void APIENTRY glTexStorageMem3DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) {
	if (!glTexStorageMem3DEXTproc) return;
	glTexStorageMem3DEXTproc(target, levels, internalFormat, width, height, depth, memory, offset);
}
PFNGLTEXSTORAGEMEM3DMULTISAMPLEEXTPROC glTexStorageMem3DMultisampleEXTproc = 0;
void APIENTRY glTexStorageMem3DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	if (!glTexStorageMem3DMultisampleEXTproc) return;
	glTexStorageMem3DMultisampleEXTproc(target, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
PFNGLBUFFERSTORAGEMEMEXTPROC glBufferStorageMemEXTproc = 0;
void APIENTRY glBufferStorageMemEXT(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset) {
	if (!glBufferStorageMemEXTproc) return;
	glBufferStorageMemEXTproc(target, size, memory, offset);
}
PFNGLTEXTURESTORAGEMEM2DEXTPROC glTextureStorageMem2DEXTproc = 0;
void APIENTRY glTextureStorageMem2DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) {
	if (!glTextureStorageMem2DEXTproc) return;
	glTextureStorageMem2DEXTproc(texture, levels, internalFormat, width, height, memory, offset);
}
PFNGLTEXTURESTORAGEMEM2DMULTISAMPLEEXTPROC glTextureStorageMem2DMultisampleEXTproc = 0;
void APIENTRY glTextureStorageMem2DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	if (!glTextureStorageMem2DMultisampleEXTproc) return;
	glTextureStorageMem2DMultisampleEXTproc(texture, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
PFNGLTEXTURESTORAGEMEM3DEXTPROC glTextureStorageMem3DEXTproc = 0;
void APIENTRY glTextureStorageMem3DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) {
	if (!glTextureStorageMem3DEXTproc) return;
	glTextureStorageMem3DEXTproc(texture, levels, internalFormat, width, height, depth, memory, offset);
}
PFNGLTEXTURESTORAGEMEM3DMULTISAMPLEEXTPROC glTextureStorageMem3DMultisampleEXTproc = 0;
void APIENTRY glTextureStorageMem3DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) {
	if (!glTextureStorageMem3DMultisampleEXTproc) return;
	glTextureStorageMem3DMultisampleEXTproc(texture, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
PFNGLNAMEDBUFFERSTORAGEMEMEXTPROC glNamedBufferStorageMemEXTproc = 0;
void APIENTRY glNamedBufferStorageMemEXT(GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset) {
	if (!glNamedBufferStorageMemEXTproc) return;
	glNamedBufferStorageMemEXTproc(buffer, size, memory, offset);
}
PFNGLTEXSTORAGEMEM1DEXTPROC glTexStorageMem1DEXTproc = 0;
void APIENTRY glTexStorageMem1DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) {
	if (!glTexStorageMem1DEXTproc) return;
	glTexStorageMem1DEXTproc(target, levels, internalFormat, width, memory, offset);
}
PFNGLTEXTURESTORAGEMEM1DEXTPROC glTextureStorageMem1DEXTproc = 0;
void APIENTRY glTextureStorageMem1DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) {
	if (!glTextureStorageMem1DEXTproc) return;
	glTextureStorageMem1DEXTproc(texture, levels, internalFormat, width, memory, offset);
}
PFNGLIMPORTMEMORYFDEXTPROC glImportMemoryFdEXTproc = 0;
void APIENTRY glImportMemoryFdEXT(GLuint memory, GLuint64 size, GLenum handleType, GLint fd) {
	if (!glImportMemoryFdEXTproc) return;
	glImportMemoryFdEXTproc(memory, size, handleType, fd);
}
PFNGLIMPORTMEMORYWIN32HANDLEEXTPROC glImportMemoryWin32HandleEXTproc = 0;
void APIENTRY glImportMemoryWin32HandleEXT(GLuint memory, GLuint64 size, GLenum handleType, void* handle) {
	if (!glImportMemoryWin32HandleEXTproc) return;
	glImportMemoryWin32HandleEXTproc(memory, size, handleType, handle);
}
PFNGLIMPORTMEMORYWIN32NAMEEXTPROC glImportMemoryWin32NameEXTproc = 0;
void APIENTRY glImportMemoryWin32NameEXT(GLuint memory, GLuint64 size, GLenum handleType, const void* name) {
	if (!glImportMemoryWin32NameEXTproc) return;
	glImportMemoryWin32NameEXTproc(memory, size, handleType, name);
}
PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXTproc = 0;
void APIENTRY glMultiDrawArraysEXT(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount) {
	if (!glMultiDrawArraysEXTproc) return;
	glMultiDrawArraysEXTproc(mode, first, count, primcount);
}
PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXTproc = 0;
void APIENTRY glMultiDrawElementsEXT(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei primcount) {
	if (!glMultiDrawElementsEXTproc) return;
	glMultiDrawElementsEXTproc(mode, count, type, indices, primcount);
}
PFNGLSAMPLEMASKEXTPROC glSampleMaskEXTproc = 0;
void APIENTRY glSampleMaskEXT(GLclampf value, GLboolean invert) {
	if (!glSampleMaskEXTproc) return;
	glSampleMaskEXTproc(value, invert);
}
PFNGLSAMPLEPATTERNEXTPROC glSamplePatternEXTproc = 0;
void APIENTRY glSamplePatternEXT(GLenum pattern) {
	if (!glSamplePatternEXTproc) return;
	glSamplePatternEXTproc(pattern);
}
PFNGLCOLORTABLEEXTPROC glColorTableEXTproc = 0;
void APIENTRY glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void* table) {
	if (!glColorTableEXTproc) return;
	glColorTableEXTproc(target, internalFormat, width, format, type, table);
}
PFNGLGETCOLORTABLEEXTPROC glGetColorTableEXTproc = 0;
void APIENTRY glGetColorTableEXT(GLenum target, GLenum format, GLenum type, void* data) {
	if (!glGetColorTableEXTproc) return;
	glGetColorTableEXTproc(target, format, type, data);
}
PFNGLGETCOLORTABLEPARAMETERIVEXTPROC glGetColorTableParameterivEXTproc = 0;
void APIENTRY glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint* params) {
	if (!glGetColorTableParameterivEXTproc) return;
	glGetColorTableParameterivEXTproc(target, pname, params);
}
PFNGLGETCOLORTABLEPARAMETERFVEXTPROC glGetColorTableParameterfvEXTproc = 0;
void APIENTRY glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetColorTableParameterfvEXTproc) return;
	glGetColorTableParameterfvEXTproc(target, pname, params);
}
PFNGLPIXELTRANSFORMPARAMETERIEXTPROC glPixelTransformParameteriEXTproc = 0;
void APIENTRY glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param) {
	if (!glPixelTransformParameteriEXTproc) return;
	glPixelTransformParameteriEXTproc(target, pname, param);
}
PFNGLPIXELTRANSFORMPARAMETERFEXTPROC glPixelTransformParameterfEXTproc = 0;
void APIENTRY glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param) {
	if (!glPixelTransformParameterfEXTproc) return;
	glPixelTransformParameterfEXTproc(target, pname, param);
}
PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC glPixelTransformParameterivEXTproc = 0;
void APIENTRY glPixelTransformParameterivEXT(GLenum target, GLenum pname, const GLint* params) {
	if (!glPixelTransformParameterivEXTproc) return;
	glPixelTransformParameterivEXTproc(target, pname, params);
}
PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC glPixelTransformParameterfvEXTproc = 0;
void APIENTRY glPixelTransformParameterfvEXT(GLenum target, GLenum pname, const GLfloat* params) {
	if (!glPixelTransformParameterfvEXTproc) return;
	glPixelTransformParameterfvEXTproc(target, pname, params);
}
PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC glGetPixelTransformParameterivEXTproc = 0;
void APIENTRY glGetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint* params) {
	if (!glGetPixelTransformParameterivEXTproc) return;
	glGetPixelTransformParameterivEXTproc(target, pname, params);
}
PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC glGetPixelTransformParameterfvEXTproc = 0;
void APIENTRY glGetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetPixelTransformParameterfvEXTproc) return;
	glGetPixelTransformParameterfvEXTproc(target, pname, params);
}
PFNGLPOINTPARAMETERFEXTPROC glPointParameterfEXTproc = 0;
void APIENTRY glPointParameterfEXT(GLenum pname, GLfloat param) {
	if (!glPointParameterfEXTproc) return;
	glPointParameterfEXTproc(pname, param);
}
PFNGLPOINTPARAMETERFVEXTPROC glPointParameterfvEXTproc = 0;
void APIENTRY glPointParameterfvEXT(GLenum pname, const GLfloat* params) {
	if (!glPointParameterfvEXTproc) return;
	glPointParameterfvEXTproc(pname, params);
}
PFNGLPOLYGONOFFSETEXTPROC glPolygonOffsetEXTproc = 0;
void APIENTRY glPolygonOffsetEXT(GLfloat factor, GLfloat bias) {
	if (!glPolygonOffsetEXTproc) return;
	glPolygonOffsetEXTproc(factor, bias);
}
PFNGLPOLYGONOFFSETCLAMPEXTPROC glPolygonOffsetClampEXTproc = 0;
void APIENTRY glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp) {
	if (!glPolygonOffsetClampEXTproc) return;
	glPolygonOffsetClampEXTproc(factor, units, clamp);
}
PFNGLPROVOKINGVERTEXEXTPROC glProvokingVertexEXTproc = 0;
void APIENTRY glProvokingVertexEXT(GLenum mode) {
	if (!glProvokingVertexEXTproc) return;
	glProvokingVertexEXTproc(mode);
}
PFNGLRASTERSAMPLESEXTPROC glRasterSamplesEXTproc = 0;
void APIENTRY glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations) {
	if (!glRasterSamplesEXTproc) return;
	glRasterSamplesEXTproc(samples, fixedsamplelocations);
}
PFNGLSECONDARYCOLOR3BEXTPROC glSecondaryColor3bEXTproc = 0;
void APIENTRY glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue) {
	if (!glSecondaryColor3bEXTproc) return;
	glSecondaryColor3bEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3BVEXTPROC glSecondaryColor3bvEXTproc = 0;
void APIENTRY glSecondaryColor3bvEXT(const GLbyte* v) {
	if (!glSecondaryColor3bvEXTproc) return;
	glSecondaryColor3bvEXTproc(v);
}
PFNGLSECONDARYCOLOR3DEXTPROC glSecondaryColor3dEXTproc = 0;
void APIENTRY glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue) {
	if (!glSecondaryColor3dEXTproc) return;
	glSecondaryColor3dEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3DVEXTPROC glSecondaryColor3dvEXTproc = 0;
void APIENTRY glSecondaryColor3dvEXT(const GLdouble* v) {
	if (!glSecondaryColor3dvEXTproc) return;
	glSecondaryColor3dvEXTproc(v);
}
PFNGLSECONDARYCOLOR3FEXTPROC glSecondaryColor3fEXTproc = 0;
void APIENTRY glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue) {
	if (!glSecondaryColor3fEXTproc) return;
	glSecondaryColor3fEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3FVEXTPROC glSecondaryColor3fvEXTproc = 0;
void APIENTRY glSecondaryColor3fvEXT(const GLfloat* v) {
	if (!glSecondaryColor3fvEXTproc) return;
	glSecondaryColor3fvEXTproc(v);
}
PFNGLSECONDARYCOLOR3IEXTPROC glSecondaryColor3iEXTproc = 0;
void APIENTRY glSecondaryColor3iEXT(GLint red, GLint green, GLint blue) {
	if (!glSecondaryColor3iEXTproc) return;
	glSecondaryColor3iEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3IVEXTPROC glSecondaryColor3ivEXTproc = 0;
void APIENTRY glSecondaryColor3ivEXT(const GLint* v) {
	if (!glSecondaryColor3ivEXTproc) return;
	glSecondaryColor3ivEXTproc(v);
}
PFNGLSECONDARYCOLOR3SEXTPROC glSecondaryColor3sEXTproc = 0;
void APIENTRY glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue) {
	if (!glSecondaryColor3sEXTproc) return;
	glSecondaryColor3sEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3SVEXTPROC glSecondaryColor3svEXTproc = 0;
void APIENTRY glSecondaryColor3svEXT(const GLshort* v) {
	if (!glSecondaryColor3svEXTproc) return;
	glSecondaryColor3svEXTproc(v);
}
PFNGLSECONDARYCOLOR3UBEXTPROC glSecondaryColor3ubEXTproc = 0;
void APIENTRY glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue) {
	if (!glSecondaryColor3ubEXTproc) return;
	glSecondaryColor3ubEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3UBVEXTPROC glSecondaryColor3ubvEXTproc = 0;
void APIENTRY glSecondaryColor3ubvEXT(const GLubyte* v) {
	if (!glSecondaryColor3ubvEXTproc) return;
	glSecondaryColor3ubvEXTproc(v);
}
PFNGLSECONDARYCOLOR3UIEXTPROC glSecondaryColor3uiEXTproc = 0;
void APIENTRY glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue) {
	if (!glSecondaryColor3uiEXTproc) return;
	glSecondaryColor3uiEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3UIVEXTPROC glSecondaryColor3uivEXTproc = 0;
void APIENTRY glSecondaryColor3uivEXT(const GLuint* v) {
	if (!glSecondaryColor3uivEXTproc) return;
	glSecondaryColor3uivEXTproc(v);
}
PFNGLSECONDARYCOLOR3USEXTPROC glSecondaryColor3usEXTproc = 0;
void APIENTRY glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue) {
	if (!glSecondaryColor3usEXTproc) return;
	glSecondaryColor3usEXTproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3USVEXTPROC glSecondaryColor3usvEXTproc = 0;
void APIENTRY glSecondaryColor3usvEXT(const GLushort* v) {
	if (!glSecondaryColor3usvEXTproc) return;
	glSecondaryColor3usvEXTproc(v);
}
PFNGLSECONDARYCOLORPOINTEREXTPROC glSecondaryColorPointerEXTproc = 0;
void APIENTRY glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glSecondaryColorPointerEXTproc) return;
	glSecondaryColorPointerEXTproc(size, type, stride, pointer);
}
PFNGLGENSEMAPHORESEXTPROC glGenSemaphoresEXTproc = 0;
void APIENTRY glGenSemaphoresEXT(GLsizei n, GLuint* semaphores) {
	if (!glGenSemaphoresEXTproc) return;
	glGenSemaphoresEXTproc(n, semaphores);
}
PFNGLDELETESEMAPHORESEXTPROC glDeleteSemaphoresEXTproc = 0;
void APIENTRY glDeleteSemaphoresEXT(GLsizei n, const GLuint* semaphores) {
	if (!glDeleteSemaphoresEXTproc) return;
	glDeleteSemaphoresEXTproc(n, semaphores);
}
PFNGLISSEMAPHOREEXTPROC glIsSemaphoreEXTproc = 0;
GLboolean APIENTRY glIsSemaphoreEXT(GLuint semaphore) {
	if (!glIsSemaphoreEXTproc) return 0;
	return glIsSemaphoreEXTproc(semaphore);
}
PFNGLSEMAPHOREPARAMETERUI64VEXTPROC glSemaphoreParameterui64vEXTproc = 0;
void APIENTRY glSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, const GLuint64* params) {
	if (!glSemaphoreParameterui64vEXTproc) return;
	glSemaphoreParameterui64vEXTproc(semaphore, pname, params);
}
PFNGLGETSEMAPHOREPARAMETERUI64VEXTPROC glGetSemaphoreParameterui64vEXTproc = 0;
void APIENTRY glGetSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64* params) {
	if (!glGetSemaphoreParameterui64vEXTproc) return;
	glGetSemaphoreParameterui64vEXTproc(semaphore, pname, params);
}
PFNGLWAITSEMAPHOREEXTPROC glWaitSemaphoreEXTproc = 0;
void APIENTRY glWaitSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* srcLayouts) {
	if (!glWaitSemaphoreEXTproc) return;
	glWaitSemaphoreEXTproc(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts);
}
PFNGLSIGNALSEMAPHOREEXTPROC glSignalSemaphoreEXTproc = 0;
void APIENTRY glSignalSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* dstLayouts) {
	if (!glSignalSemaphoreEXTproc) return;
	glSignalSemaphoreEXTproc(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts);
}
PFNGLIMPORTSEMAPHOREFDEXTPROC glImportSemaphoreFdEXTproc = 0;
void APIENTRY glImportSemaphoreFdEXT(GLuint semaphore, GLenum handleType, GLint fd) {
	if (!glImportSemaphoreFdEXTproc) return;
	glImportSemaphoreFdEXTproc(semaphore, handleType, fd);
}
PFNGLIMPORTSEMAPHOREWIN32HANDLEEXTPROC glImportSemaphoreWin32HandleEXTproc = 0;
void APIENTRY glImportSemaphoreWin32HandleEXT(GLuint semaphore, GLenum handleType, void* handle) {
	if (!glImportSemaphoreWin32HandleEXTproc) return;
	glImportSemaphoreWin32HandleEXTproc(semaphore, handleType, handle);
}
PFNGLIMPORTSEMAPHOREWIN32NAMEEXTPROC glImportSemaphoreWin32NameEXTproc = 0;
void APIENTRY glImportSemaphoreWin32NameEXT(GLuint semaphore, GLenum handleType, const void* name) {
	if (!glImportSemaphoreWin32NameEXTproc) return;
	glImportSemaphoreWin32NameEXTproc(semaphore, handleType, name);
}
PFNGLUSESHADERPROGRAMEXTPROC glUseShaderProgramEXTproc = 0;
void APIENTRY glUseShaderProgramEXT(GLenum type, GLuint program) {
	if (!glUseShaderProgramEXTproc) return;
	glUseShaderProgramEXTproc(type, program);
}
PFNGLACTIVEPROGRAMEXTPROC glActiveProgramEXTproc = 0;
void APIENTRY glActiveProgramEXT(GLuint program) {
	if (!glActiveProgramEXTproc) return;
	glActiveProgramEXTproc(program);
}
PFNGLCREATESHADERPROGRAMEXTPROC glCreateShaderProgramEXTproc = 0;
GLuint APIENTRY glCreateShaderProgramEXT(GLenum type, const GLchar* string) {
	if (!glCreateShaderProgramEXTproc) return 0;
	return glCreateShaderProgramEXTproc(type, string);
}
PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC glFramebufferFetchBarrierEXTproc = 0;
void APIENTRY glFramebufferFetchBarrierEXT(void) {
	if (!glFramebufferFetchBarrierEXTproc) return;
	glFramebufferFetchBarrierEXTproc();
}
PFNGLBINDIMAGETEXTUREEXTPROC glBindImageTextureEXTproc = 0;
void APIENTRY glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) {
	if (!glBindImageTextureEXTproc) return;
	glBindImageTextureEXTproc(index, texture, level, layered, layer, access, format);
}
PFNGLMEMORYBARRIEREXTPROC glMemoryBarrierEXTproc = 0;
void APIENTRY glMemoryBarrierEXT(GLbitfield barriers) {
	if (!glMemoryBarrierEXTproc) return;
	glMemoryBarrierEXTproc(barriers);
}
PFNGLSTENCILCLEARTAGEXTPROC glStencilClearTagEXTproc = 0;
void APIENTRY glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag) {
	if (!glStencilClearTagEXTproc) return;
	glStencilClearTagEXTproc(stencilTagBits, stencilClearTag);
}
PFNGLACTIVESTENCILFACEEXTPROC glActiveStencilFaceEXTproc = 0;
void APIENTRY glActiveStencilFaceEXT(GLenum face) {
	if (!glActiveStencilFaceEXTproc) return;
	glActiveStencilFaceEXTproc(face);
}
PFNGLTEXSUBIMAGE1DEXTPROC glTexSubImage1DEXTproc = 0;
void APIENTRY glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) {
	if (!glTexSubImage1DEXTproc) return;
	glTexSubImage1DEXTproc(target, level, xoffset, width, format, type, pixels);
}
PFNGLTEXSUBIMAGE2DEXTPROC glTexSubImage2DEXTproc = 0;
void APIENTRY glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) {
	if (!glTexSubImage2DEXTproc) return;
	glTexSubImage2DEXTproc(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXIMAGE3DEXTPROC glTexImage3DEXTproc = 0;
void APIENTRY glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glTexImage3DEXTproc) return;
	glTexImage3DEXTproc(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLTEXSUBIMAGE3DEXTPROC glTexSubImage3DEXTproc = 0;
void APIENTRY glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) {
	if (!glTexSubImage3DEXTproc) return;
	glTexSubImage3DEXTproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC glFramebufferTextureLayerEXTproc = 0;
void APIENTRY glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
	if (!glFramebufferTextureLayerEXTproc) return;
	glFramebufferTextureLayerEXTproc(target, attachment, texture, level, layer);
}
PFNGLTEXBUFFEREXTPROC glTexBufferEXTproc = 0;
void APIENTRY glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) {
	if (!glTexBufferEXTproc) return;
	glTexBufferEXTproc(target, internalformat, buffer);
}
PFNGLTEXPARAMETERIIVEXTPROC glTexParameterIivEXTproc = 0;
void APIENTRY glTexParameterIivEXT(GLenum target, GLenum pname, const GLint* params) {
	if (!glTexParameterIivEXTproc) return;
	glTexParameterIivEXTproc(target, pname, params);
}
PFNGLTEXPARAMETERIUIVEXTPROC glTexParameterIuivEXTproc = 0;
void APIENTRY glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint* params) {
	if (!glTexParameterIuivEXTproc) return;
	glTexParameterIuivEXTproc(target, pname, params);
}
PFNGLGETTEXPARAMETERIIVEXTPROC glGetTexParameterIivEXTproc = 0;
void APIENTRY glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint* params) {
	if (!glGetTexParameterIivEXTproc) return;
	glGetTexParameterIivEXTproc(target, pname, params);
}
PFNGLGETTEXPARAMETERIUIVEXTPROC glGetTexParameterIuivEXTproc = 0;
void APIENTRY glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint* params) {
	if (!glGetTexParameterIuivEXTproc) return;
	glGetTexParameterIuivEXTproc(target, pname, params);
}
PFNGLCLEARCOLORIIEXTPROC glClearColorIiEXTproc = 0;
void APIENTRY glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha) {
	if (!glClearColorIiEXTproc) return;
	glClearColorIiEXTproc(red, green, blue, alpha);
}
PFNGLCLEARCOLORIUIEXTPROC glClearColorIuiEXTproc = 0;
void APIENTRY glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
	if (!glClearColorIuiEXTproc) return;
	glClearColorIuiEXTproc(red, green, blue, alpha);
}
PFNGLARETEXTURESRESIDENTEXTPROC glAreTexturesResidentEXTproc = 0;
GLboolean APIENTRY glAreTexturesResidentEXT(GLsizei n, const GLuint* textures, GLboolean* residences) {
	if (!glAreTexturesResidentEXTproc) return 0;
	return glAreTexturesResidentEXTproc(n, textures, residences);
}
PFNGLBINDTEXTUREEXTPROC glBindTextureEXTproc = 0;
void APIENTRY glBindTextureEXT(GLenum target, GLuint texture) {
	if (!glBindTextureEXTproc) return;
	glBindTextureEXTproc(target, texture);
}
PFNGLDELETETEXTURESEXTPROC glDeleteTexturesEXTproc = 0;
void APIENTRY glDeleteTexturesEXT(GLsizei n, const GLuint* textures) {
	if (!glDeleteTexturesEXTproc) return;
	glDeleteTexturesEXTproc(n, textures);
}
PFNGLGENTEXTURESEXTPROC glGenTexturesEXTproc = 0;
void APIENTRY glGenTexturesEXT(GLsizei n, GLuint* textures) {
	if (!glGenTexturesEXTproc) return;
	glGenTexturesEXTproc(n, textures);
}
PFNGLISTEXTUREEXTPROC glIsTextureEXTproc = 0;
GLboolean APIENTRY glIsTextureEXT(GLuint texture) {
	if (!glIsTextureEXTproc) return 0;
	return glIsTextureEXTproc(texture);
}
PFNGLPRIORITIZETEXTURESEXTPROC glPrioritizeTexturesEXTproc = 0;
void APIENTRY glPrioritizeTexturesEXT(GLsizei n, const GLuint* textures, const GLclampf* priorities) {
	if (!glPrioritizeTexturesEXTproc) return;
	glPrioritizeTexturesEXTproc(n, textures, priorities);
}
PFNGLTEXTURENORMALEXTPROC glTextureNormalEXTproc = 0;
void APIENTRY glTextureNormalEXT(GLenum mode) {
	if (!glTextureNormalEXTproc) return;
	glTextureNormalEXTproc(mode);
}
PFNGLTEXSTORAGE1DEXTPROC glTexStorage1DEXTproc = 0;
void APIENTRY glTexStorage1DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
	if (!glTexStorage1DEXTproc) return;
	glTexStorage1DEXTproc(target, levels, internalformat, width);
}
PFNGLTEXSTORAGE2DEXTPROC glTexStorage2DEXTproc = 0;
void APIENTRY glTexStorage2DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glTexStorage2DEXTproc) return;
	glTexStorage2DEXTproc(target, levels, internalformat, width, height);
}
PFNGLTEXSTORAGE3DEXTPROC glTexStorage3DEXTproc = 0;
void APIENTRY glTexStorage3DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
	if (!glTexStorage3DEXTproc) return;
	glTexStorage3DEXTproc(target, levels, internalformat, width, height, depth);
}
PFNGLGETQUERYOBJECTI64VEXTPROC glGetQueryObjecti64vEXTproc = 0;
void APIENTRY glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64* params) {
	if (!glGetQueryObjecti64vEXTproc) return;
	glGetQueryObjecti64vEXTproc(id, pname, params);
}
PFNGLGETQUERYOBJECTUI64VEXTPROC glGetQueryObjectui64vEXTproc = 0;
void APIENTRY glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64* params) {
	if (!glGetQueryObjectui64vEXTproc) return;
	glGetQueryObjectui64vEXTproc(id, pname, params);
}
PFNGLBEGINTRANSFORMFEEDBACKEXTPROC glBeginTransformFeedbackEXTproc = 0;
void APIENTRY glBeginTransformFeedbackEXT(GLenum primitiveMode) {
	if (!glBeginTransformFeedbackEXTproc) return;
	glBeginTransformFeedbackEXTproc(primitiveMode);
}
PFNGLENDTRANSFORMFEEDBACKEXTPROC glEndTransformFeedbackEXTproc = 0;
void APIENTRY glEndTransformFeedbackEXT(void) {
	if (!glEndTransformFeedbackEXTproc) return;
	glEndTransformFeedbackEXTproc();
}
PFNGLBINDBUFFERRANGEEXTPROC glBindBufferRangeEXTproc = 0;
void APIENTRY glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	if (!glBindBufferRangeEXTproc) return;
	glBindBufferRangeEXTproc(target, index, buffer, offset, size);
}
PFNGLBINDBUFFEROFFSETEXTPROC glBindBufferOffsetEXTproc = 0;
void APIENTRY glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
	if (!glBindBufferOffsetEXTproc) return;
	glBindBufferOffsetEXTproc(target, index, buffer, offset);
}
PFNGLBINDBUFFERBASEEXTPROC glBindBufferBaseEXTproc = 0;
void APIENTRY glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer) {
	if (!glBindBufferBaseEXTproc) return;
	glBindBufferBaseEXTproc(target, index, buffer);
}
PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC glTransformFeedbackVaryingsEXTproc = 0;
void APIENTRY glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) {
	if (!glTransformFeedbackVaryingsEXTproc) return;
	glTransformFeedbackVaryingsEXTproc(program, count, varyings, bufferMode);
}
PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC glGetTransformFeedbackVaryingEXTproc = 0;
void APIENTRY glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) {
	if (!glGetTransformFeedbackVaryingEXTproc) return;
	glGetTransformFeedbackVaryingEXTproc(program, index, bufSize, length, size, type, name);
}
PFNGLARRAYELEMENTEXTPROC glArrayElementEXTproc = 0;
void APIENTRY glArrayElementEXT(GLint i) {
	if (!glArrayElementEXTproc) return;
	glArrayElementEXTproc(i);
}
PFNGLCOLORPOINTEREXTPROC glColorPointerEXTproc = 0;
void APIENTRY glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void* pointer) {
	if (!glColorPointerEXTproc) return;
	glColorPointerEXTproc(size, type, stride, count, pointer);
}
PFNGLDRAWARRAYSEXTPROC glDrawArraysEXTproc = 0;
void APIENTRY glDrawArraysEXT(GLenum mode, GLint first, GLsizei count) {
	if (!glDrawArraysEXTproc) return;
	glDrawArraysEXTproc(mode, first, count);
}
PFNGLEDGEFLAGPOINTEREXTPROC glEdgeFlagPointerEXTproc = 0;
void APIENTRY glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean* pointer) {
	if (!glEdgeFlagPointerEXTproc) return;
	glEdgeFlagPointerEXTproc(stride, count, pointer);
}
PFNGLGETPOINTERVEXTPROC glGetPointervEXTproc = 0;
void APIENTRY glGetPointervEXT(GLenum pname, void** params) {
	if (!glGetPointervEXTproc) return;
	glGetPointervEXTproc(pname, params);
}
PFNGLINDEXPOINTEREXTPROC glIndexPointerEXTproc = 0;
void APIENTRY glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void* pointer) {
	if (!glIndexPointerEXTproc) return;
	glIndexPointerEXTproc(type, stride, count, pointer);
}
PFNGLNORMALPOINTEREXTPROC glNormalPointerEXTproc = 0;
void APIENTRY glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void* pointer) {
	if (!glNormalPointerEXTproc) return;
	glNormalPointerEXTproc(type, stride, count, pointer);
}
PFNGLTEXCOORDPOINTEREXTPROC glTexCoordPointerEXTproc = 0;
void APIENTRY glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void* pointer) {
	if (!glTexCoordPointerEXTproc) return;
	glTexCoordPointerEXTproc(size, type, stride, count, pointer);
}
PFNGLVERTEXPOINTEREXTPROC glVertexPointerEXTproc = 0;
void APIENTRY glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void* pointer) {
	if (!glVertexPointerEXTproc) return;
	glVertexPointerEXTproc(size, type, stride, count, pointer);
}
PFNGLVERTEXATTRIBL1DEXTPROC glVertexAttribL1dEXTproc = 0;
void APIENTRY glVertexAttribL1dEXT(GLuint index, GLdouble x) {
	if (!glVertexAttribL1dEXTproc) return;
	glVertexAttribL1dEXTproc(index, x);
}
PFNGLVERTEXATTRIBL2DEXTPROC glVertexAttribL2dEXTproc = 0;
void APIENTRY glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y) {
	if (!glVertexAttribL2dEXTproc) return;
	glVertexAttribL2dEXTproc(index, x, y);
}
PFNGLVERTEXATTRIBL3DEXTPROC glVertexAttribL3dEXTproc = 0;
void APIENTRY glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	if (!glVertexAttribL3dEXTproc) return;
	glVertexAttribL3dEXTproc(index, x, y, z);
}
PFNGLVERTEXATTRIBL4DEXTPROC glVertexAttribL4dEXTproc = 0;
void APIENTRY glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glVertexAttribL4dEXTproc) return;
	glVertexAttribL4dEXTproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBL1DVEXTPROC glVertexAttribL1dvEXTproc = 0;
void APIENTRY glVertexAttribL1dvEXT(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL1dvEXTproc) return;
	glVertexAttribL1dvEXTproc(index, v);
}
PFNGLVERTEXATTRIBL2DVEXTPROC glVertexAttribL2dvEXTproc = 0;
void APIENTRY glVertexAttribL2dvEXT(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL2dvEXTproc) return;
	glVertexAttribL2dvEXTproc(index, v);
}
PFNGLVERTEXATTRIBL3DVEXTPROC glVertexAttribL3dvEXTproc = 0;
void APIENTRY glVertexAttribL3dvEXT(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL3dvEXTproc) return;
	glVertexAttribL3dvEXTproc(index, v);
}
PFNGLVERTEXATTRIBL4DVEXTPROC glVertexAttribL4dvEXTproc = 0;
void APIENTRY glVertexAttribL4dvEXT(GLuint index, const GLdouble* v) {
	if (!glVertexAttribL4dvEXTproc) return;
	glVertexAttribL4dvEXTproc(index, v);
}
PFNGLVERTEXATTRIBLPOINTEREXTPROC glVertexAttribLPointerEXTproc = 0;
void APIENTRY glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glVertexAttribLPointerEXTproc) return;
	glVertexAttribLPointerEXTproc(index, size, type, stride, pointer);
}
PFNGLGETVERTEXATTRIBLDVEXTPROC glGetVertexAttribLdvEXTproc = 0;
void APIENTRY glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble* params) {
	if (!glGetVertexAttribLdvEXTproc) return;
	glGetVertexAttribLdvEXTproc(index, pname, params);
}
PFNGLBEGINVERTEXSHADEREXTPROC glBeginVertexShaderEXTproc = 0;
void APIENTRY glBeginVertexShaderEXT(void) {
	if (!glBeginVertexShaderEXTproc) return;
	glBeginVertexShaderEXTproc();
}
PFNGLENDVERTEXSHADEREXTPROC glEndVertexShaderEXTproc = 0;
void APIENTRY glEndVertexShaderEXT(void) {
	if (!glEndVertexShaderEXTproc) return;
	glEndVertexShaderEXTproc();
}
PFNGLBINDVERTEXSHADEREXTPROC glBindVertexShaderEXTproc = 0;
void APIENTRY glBindVertexShaderEXT(GLuint id) {
	if (!glBindVertexShaderEXTproc) return;
	glBindVertexShaderEXTproc(id);
}
PFNGLGENVERTEXSHADERSEXTPROC glGenVertexShadersEXTproc = 0;
GLuint APIENTRY glGenVertexShadersEXT(GLuint range) {
	if (!glGenVertexShadersEXTproc) return 0;
	return glGenVertexShadersEXTproc(range);
}
PFNGLDELETEVERTEXSHADEREXTPROC glDeleteVertexShaderEXTproc = 0;
void APIENTRY glDeleteVertexShaderEXT(GLuint id) {
	if (!glDeleteVertexShaderEXTproc) return;
	glDeleteVertexShaderEXTproc(id);
}
PFNGLSHADEROP1EXTPROC glShaderOp1EXTproc = 0;
void APIENTRY glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1) {
	if (!glShaderOp1EXTproc) return;
	glShaderOp1EXTproc(op, res, arg1);
}
PFNGLSHADEROP2EXTPROC glShaderOp2EXTproc = 0;
void APIENTRY glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2) {
	if (!glShaderOp2EXTproc) return;
	glShaderOp2EXTproc(op, res, arg1, arg2);
}
PFNGLSHADEROP3EXTPROC glShaderOp3EXTproc = 0;
void APIENTRY glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) {
	if (!glShaderOp3EXTproc) return;
	glShaderOp3EXTproc(op, res, arg1, arg2, arg3);
}
PFNGLSWIZZLEEXTPROC glSwizzleEXTproc = 0;
void APIENTRY glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
	if (!glSwizzleEXTproc) return;
	glSwizzleEXTproc(res, in, outX, outY, outZ, outW);
}
PFNGLWRITEMASKEXTPROC glWriteMaskEXTproc = 0;
void APIENTRY glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
	if (!glWriteMaskEXTproc) return;
	glWriteMaskEXTproc(res, in, outX, outY, outZ, outW);
}
PFNGLINSERTCOMPONENTEXTPROC glInsertComponentEXTproc = 0;
void APIENTRY glInsertComponentEXT(GLuint res, GLuint src, GLuint num) {
	if (!glInsertComponentEXTproc) return;
	glInsertComponentEXTproc(res, src, num);
}
PFNGLEXTRACTCOMPONENTEXTPROC glExtractComponentEXTproc = 0;
void APIENTRY glExtractComponentEXT(GLuint res, GLuint src, GLuint num) {
	if (!glExtractComponentEXTproc) return;
	glExtractComponentEXTproc(res, src, num);
}
PFNGLGENSYMBOLSEXTPROC glGenSymbolsEXTproc = 0;
GLuint APIENTRY glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components) {
	if (!glGenSymbolsEXTproc) return 0;
	return glGenSymbolsEXTproc(datatype, storagetype, range, components);
}
PFNGLSETINVARIANTEXTPROC glSetInvariantEXTproc = 0;
void APIENTRY glSetInvariantEXT(GLuint id, GLenum type, const void* addr) {
	if (!glSetInvariantEXTproc) return;
	glSetInvariantEXTproc(id, type, addr);
}
PFNGLSETLOCALCONSTANTEXTPROC glSetLocalConstantEXTproc = 0;
void APIENTRY glSetLocalConstantEXT(GLuint id, GLenum type, const void* addr) {
	if (!glSetLocalConstantEXTproc) return;
	glSetLocalConstantEXTproc(id, type, addr);
}
PFNGLVARIANTBVEXTPROC glVariantbvEXTproc = 0;
void APIENTRY glVariantbvEXT(GLuint id, const GLbyte* addr) {
	if (!glVariantbvEXTproc) return;
	glVariantbvEXTproc(id, addr);
}
PFNGLVARIANTSVEXTPROC glVariantsvEXTproc = 0;
void APIENTRY glVariantsvEXT(GLuint id, const GLshort* addr) {
	if (!glVariantsvEXTproc) return;
	glVariantsvEXTproc(id, addr);
}
PFNGLVARIANTIVEXTPROC glVariantivEXTproc = 0;
void APIENTRY glVariantivEXT(GLuint id, const GLint* addr) {
	if (!glVariantivEXTproc) return;
	glVariantivEXTproc(id, addr);
}
PFNGLVARIANTFVEXTPROC glVariantfvEXTproc = 0;
void APIENTRY glVariantfvEXT(GLuint id, const GLfloat* addr) {
	if (!glVariantfvEXTproc) return;
	glVariantfvEXTproc(id, addr);
}
PFNGLVARIANTDVEXTPROC glVariantdvEXTproc = 0;
void APIENTRY glVariantdvEXT(GLuint id, const GLdouble* addr) {
	if (!glVariantdvEXTproc) return;
	glVariantdvEXTproc(id, addr);
}
PFNGLVARIANTUBVEXTPROC glVariantubvEXTproc = 0;
void APIENTRY glVariantubvEXT(GLuint id, const GLubyte* addr) {
	if (!glVariantubvEXTproc) return;
	glVariantubvEXTproc(id, addr);
}
PFNGLVARIANTUSVEXTPROC glVariantusvEXTproc = 0;
void APIENTRY glVariantusvEXT(GLuint id, const GLushort* addr) {
	if (!glVariantusvEXTproc) return;
	glVariantusvEXTproc(id, addr);
}
PFNGLVARIANTUIVEXTPROC glVariantuivEXTproc = 0;
void APIENTRY glVariantuivEXT(GLuint id, const GLuint* addr) {
	if (!glVariantuivEXTproc) return;
	glVariantuivEXTproc(id, addr);
}
PFNGLVARIANTPOINTEREXTPROC glVariantPointerEXTproc = 0;
void APIENTRY glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, const void* addr) {
	if (!glVariantPointerEXTproc) return;
	glVariantPointerEXTproc(id, type, stride, addr);
}
PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glEnableVariantClientStateEXTproc = 0;
void APIENTRY glEnableVariantClientStateEXT(GLuint id) {
	if (!glEnableVariantClientStateEXTproc) return;
	glEnableVariantClientStateEXTproc(id);
}
PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glDisableVariantClientStateEXTproc = 0;
void APIENTRY glDisableVariantClientStateEXT(GLuint id) {
	if (!glDisableVariantClientStateEXTproc) return;
	glDisableVariantClientStateEXTproc(id);
}
PFNGLBINDLIGHTPARAMETEREXTPROC glBindLightParameterEXTproc = 0;
GLuint APIENTRY glBindLightParameterEXT(GLenum light, GLenum value) {
	if (!glBindLightParameterEXTproc) return 0;
	return glBindLightParameterEXTproc(light, value);
}
PFNGLBINDMATERIALPARAMETEREXTPROC glBindMaterialParameterEXTproc = 0;
GLuint APIENTRY glBindMaterialParameterEXT(GLenum face, GLenum value) {
	if (!glBindMaterialParameterEXTproc) return 0;
	return glBindMaterialParameterEXTproc(face, value);
}
PFNGLBINDTEXGENPARAMETEREXTPROC glBindTexGenParameterEXTproc = 0;
GLuint APIENTRY glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value) {
	if (!glBindTexGenParameterEXTproc) return 0;
	return glBindTexGenParameterEXTproc(unit, coord, value);
}
PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glBindTextureUnitParameterEXTproc = 0;
GLuint APIENTRY glBindTextureUnitParameterEXT(GLenum unit, GLenum value) {
	if (!glBindTextureUnitParameterEXTproc) return 0;
	return glBindTextureUnitParameterEXTproc(unit, value);
}
PFNGLBINDPARAMETEREXTPROC glBindParameterEXTproc = 0;
GLuint APIENTRY glBindParameterEXT(GLenum value) {
	if (!glBindParameterEXTproc) return 0;
	return glBindParameterEXTproc(value);
}
PFNGLISVARIANTENABLEDEXTPROC glIsVariantEnabledEXTproc = 0;
GLboolean APIENTRY glIsVariantEnabledEXT(GLuint id, GLenum cap) {
	if (!glIsVariantEnabledEXTproc) return 0;
	return glIsVariantEnabledEXTproc(id, cap);
}
PFNGLGETVARIANTBOOLEANVEXTPROC glGetVariantBooleanvEXTproc = 0;
void APIENTRY glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) {
	if (!glGetVariantBooleanvEXTproc) return;
	glGetVariantBooleanvEXTproc(id, value, data);
}
PFNGLGETVARIANTINTEGERVEXTPROC glGetVariantIntegervEXTproc = 0;
void APIENTRY glGetVariantIntegervEXT(GLuint id, GLenum value, GLint* data) {
	if (!glGetVariantIntegervEXTproc) return;
	glGetVariantIntegervEXTproc(id, value, data);
}
PFNGLGETVARIANTFLOATVEXTPROC glGetVariantFloatvEXTproc = 0;
void APIENTRY glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat* data) {
	if (!glGetVariantFloatvEXTproc) return;
	glGetVariantFloatvEXTproc(id, value, data);
}
PFNGLGETVARIANTPOINTERVEXTPROC glGetVariantPointervEXTproc = 0;
void APIENTRY glGetVariantPointervEXT(GLuint id, GLenum value, void** data) {
	if (!glGetVariantPointervEXTproc) return;
	glGetVariantPointervEXTproc(id, value, data);
}
PFNGLGETINVARIANTBOOLEANVEXTPROC glGetInvariantBooleanvEXTproc = 0;
void APIENTRY glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) {
	if (!glGetInvariantBooleanvEXTproc) return;
	glGetInvariantBooleanvEXTproc(id, value, data);
}
PFNGLGETINVARIANTINTEGERVEXTPROC glGetInvariantIntegervEXTproc = 0;
void APIENTRY glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint* data) {
	if (!glGetInvariantIntegervEXTproc) return;
	glGetInvariantIntegervEXTproc(id, value, data);
}
PFNGLGETINVARIANTFLOATVEXTPROC glGetInvariantFloatvEXTproc = 0;
void APIENTRY glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat* data) {
	if (!glGetInvariantFloatvEXTproc) return;
	glGetInvariantFloatvEXTproc(id, value, data);
}
PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glGetLocalConstantBooleanvEXTproc = 0;
void APIENTRY glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) {
	if (!glGetLocalConstantBooleanvEXTproc) return;
	glGetLocalConstantBooleanvEXTproc(id, value, data);
}
PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glGetLocalConstantIntegervEXTproc = 0;
void APIENTRY glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint* data) {
	if (!glGetLocalConstantIntegervEXTproc) return;
	glGetLocalConstantIntegervEXTproc(id, value, data);
}
PFNGLGETLOCALCONSTANTFLOATVEXTPROC glGetLocalConstantFloatvEXTproc = 0;
void APIENTRY glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat* data) {
	if (!glGetLocalConstantFloatvEXTproc) return;
	glGetLocalConstantFloatvEXTproc(id, value, data);
}
PFNGLVERTEXWEIGHTFEXTPROC glVertexWeightfEXTproc = 0;
void APIENTRY glVertexWeightfEXT(GLfloat weight) {
	if (!glVertexWeightfEXTproc) return;
	glVertexWeightfEXTproc(weight);
}
PFNGLVERTEXWEIGHTFVEXTPROC glVertexWeightfvEXTproc = 0;
void APIENTRY glVertexWeightfvEXT(const GLfloat* weight) {
	if (!glVertexWeightfvEXTproc) return;
	glVertexWeightfvEXTproc(weight);
}
PFNGLVERTEXWEIGHTPOINTEREXTPROC glVertexWeightPointerEXTproc = 0;
void APIENTRY glVertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	if (!glVertexWeightPointerEXTproc) return;
	glVertexWeightPointerEXTproc(size, type, stride, pointer);
}
PFNGLACQUIREKEYEDMUTEXWIN32EXTPROC glAcquireKeyedMutexWin32EXTproc = 0;
GLboolean APIENTRY glAcquireKeyedMutexWin32EXT(GLuint memory, GLuint64 key, GLuint timeout) {
	if (!glAcquireKeyedMutexWin32EXTproc) return 0;
	return glAcquireKeyedMutexWin32EXTproc(memory, key, timeout);
}
PFNGLRELEASEKEYEDMUTEXWIN32EXTPROC glReleaseKeyedMutexWin32EXTproc = 0;
GLboolean APIENTRY glReleaseKeyedMutexWin32EXT(GLuint memory, GLuint64 key) {
	if (!glReleaseKeyedMutexWin32EXTproc) return 0;
	return glReleaseKeyedMutexWin32EXTproc(memory, key);
}
PFNGLWINDOWRECTANGLESEXTPROC glWindowRectanglesEXTproc = 0;
void APIENTRY glWindowRectanglesEXT(GLenum mode, GLsizei count, const GLint* box) {
	if (!glWindowRectanglesEXTproc) return;
	glWindowRectanglesEXTproc(mode, count, box);
}
PFNGLIMPORTSYNCEXTPROC glImportSyncEXTproc = 0;
GLsync APIENTRY glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags) {
	if (!glImportSyncEXTproc) return 0;
	return glImportSyncEXTproc(external_sync_type, external_sync, flags);
}
PFNGLFRAMETERMINATORGREMEDYPROC glFrameTerminatorGREMEDYproc = 0;
void APIENTRY glFrameTerminatorGREMEDY(void) {
	if (!glFrameTerminatorGREMEDYproc) return;
	glFrameTerminatorGREMEDYproc();
}
PFNGLSTRINGMARKERGREMEDYPROC glStringMarkerGREMEDYproc = 0;
void APIENTRY glStringMarkerGREMEDY(GLsizei len, const void* string) {
	if (!glStringMarkerGREMEDYproc) return;
	glStringMarkerGREMEDYproc(len, string);
}
PFNGLIMAGETRANSFORMPARAMETERIHPPROC glImageTransformParameteriHPproc = 0;
void APIENTRY glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param) {
	if (!glImageTransformParameteriHPproc) return;
	glImageTransformParameteriHPproc(target, pname, param);
}
PFNGLIMAGETRANSFORMPARAMETERFHPPROC glImageTransformParameterfHPproc = 0;
void APIENTRY glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param) {
	if (!glImageTransformParameterfHPproc) return;
	glImageTransformParameterfHPproc(target, pname, param);
}
PFNGLIMAGETRANSFORMPARAMETERIVHPPROC glImageTransformParameterivHPproc = 0;
void APIENTRY glImageTransformParameterivHP(GLenum target, GLenum pname, const GLint* params) {
	if (!glImageTransformParameterivHPproc) return;
	glImageTransformParameterivHPproc(target, pname, params);
}
PFNGLIMAGETRANSFORMPARAMETERFVHPPROC glImageTransformParameterfvHPproc = 0;
void APIENTRY glImageTransformParameterfvHP(GLenum target, GLenum pname, const GLfloat* params) {
	if (!glImageTransformParameterfvHPproc) return;
	glImageTransformParameterfvHPproc(target, pname, params);
}
PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC glGetImageTransformParameterivHPproc = 0;
void APIENTRY glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint* params) {
	if (!glGetImageTransformParameterivHPproc) return;
	glGetImageTransformParameterivHPproc(target, pname, params);
}
PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC glGetImageTransformParameterfvHPproc = 0;
void APIENTRY glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetImageTransformParameterfvHPproc) return;
	glGetImageTransformParameterfvHPproc(target, pname, params);
}
PFNGLMULTIMODEDRAWARRAYSIBMPROC glMultiModeDrawArraysIBMproc = 0;
void APIENTRY glMultiModeDrawArraysIBM(const GLenum* mode, const GLint* first, const GLsizei* count, GLsizei primcount, GLint modestride) {
	if (!glMultiModeDrawArraysIBMproc) return;
	glMultiModeDrawArraysIBMproc(mode, first, count, primcount, modestride);
}
PFNGLMULTIMODEDRAWELEMENTSIBMPROC glMultiModeDrawElementsIBMproc = 0;
void APIENTRY glMultiModeDrawElementsIBM(const GLenum* mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei primcount, GLint modestride) {
	if (!glMultiModeDrawElementsIBMproc) return;
	glMultiModeDrawElementsIBMproc(mode, count, type, indices, primcount, modestride);
}
PFNGLFLUSHSTATICDATAIBMPROC glFlushStaticDataIBMproc = 0;
void APIENTRY glFlushStaticDataIBM(GLenum target) {
	if (!glFlushStaticDataIBMproc) return;
	glFlushStaticDataIBMproc(target);
}
PFNGLCOLORPOINTERLISTIBMPROC glColorPointerListIBMproc = 0;
void APIENTRY glColorPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride) {
	if (!glColorPointerListIBMproc) return;
	glColorPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
PFNGLSECONDARYCOLORPOINTERLISTIBMPROC glSecondaryColorPointerListIBMproc = 0;
void APIENTRY glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride) {
	if (!glSecondaryColorPointerListIBMproc) return;
	glSecondaryColorPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
PFNGLEDGEFLAGPOINTERLISTIBMPROC glEdgeFlagPointerListIBMproc = 0;
void APIENTRY glEdgeFlagPointerListIBM(GLint stride, const GLboolean** pointer, GLint ptrstride) {
	if (!glEdgeFlagPointerListIBMproc) return;
	glEdgeFlagPointerListIBMproc(stride, pointer, ptrstride);
}
PFNGLFOGCOORDPOINTERLISTIBMPROC glFogCoordPointerListIBMproc = 0;
void APIENTRY glFogCoordPointerListIBM(GLenum type, GLint stride, const void** pointer, GLint ptrstride) {
	if (!glFogCoordPointerListIBMproc) return;
	glFogCoordPointerListIBMproc(type, stride, pointer, ptrstride);
}
PFNGLINDEXPOINTERLISTIBMPROC glIndexPointerListIBMproc = 0;
void APIENTRY glIndexPointerListIBM(GLenum type, GLint stride, const void** pointer, GLint ptrstride) {
	if (!glIndexPointerListIBMproc) return;
	glIndexPointerListIBMproc(type, stride, pointer, ptrstride);
}
PFNGLNORMALPOINTERLISTIBMPROC glNormalPointerListIBMproc = 0;
void APIENTRY glNormalPointerListIBM(GLenum type, GLint stride, const void** pointer, GLint ptrstride) {
	if (!glNormalPointerListIBMproc) return;
	glNormalPointerListIBMproc(type, stride, pointer, ptrstride);
}
PFNGLTEXCOORDPOINTERLISTIBMPROC glTexCoordPointerListIBMproc = 0;
void APIENTRY glTexCoordPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride) {
	if (!glTexCoordPointerListIBMproc) return;
	glTexCoordPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
PFNGLVERTEXPOINTERLISTIBMPROC glVertexPointerListIBMproc = 0;
void APIENTRY glVertexPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride) {
	if (!glVertexPointerListIBMproc) return;
	glVertexPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
PFNGLBLENDFUNCSEPARATEINGRPROC glBlendFuncSeparateINGRproc = 0;
void APIENTRY glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	if (!glBlendFuncSeparateINGRproc) return;
	glBlendFuncSeparateINGRproc(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC glApplyFramebufferAttachmentCMAAINTELproc = 0;
void APIENTRY glApplyFramebufferAttachmentCMAAINTEL(void) {
	if (!glApplyFramebufferAttachmentCMAAINTELproc) return;
	glApplyFramebufferAttachmentCMAAINTELproc();
}
PFNGLSYNCTEXTUREINTELPROC glSyncTextureINTELproc = 0;
void APIENTRY glSyncTextureINTEL(GLuint texture) {
	if (!glSyncTextureINTELproc) return;
	glSyncTextureINTELproc(texture);
}
PFNGLUNMAPTEXTURE2DINTELPROC glUnmapTexture2DINTELproc = 0;
void APIENTRY glUnmapTexture2DINTEL(GLuint texture, GLint level) {
	if (!glUnmapTexture2DINTELproc) return;
	glUnmapTexture2DINTELproc(texture, level);
}
PFNGLMAPTEXTURE2DINTELPROC glMapTexture2DINTELproc = 0;
void* APIENTRY glMapTexture2DINTEL(GLuint texture, GLint level, GLbitfield access, GLint* stride, GLenum* layout) {
	if (!glMapTexture2DINTELproc) return 0;
	return glMapTexture2DINTELproc(texture, level, access, stride, layout);
}
PFNGLVERTEXPOINTERVINTELPROC glVertexPointervINTELproc = 0;
void APIENTRY glVertexPointervINTEL(GLint size, GLenum type, const void** pointer) {
	if (!glVertexPointervINTELproc) return;
	glVertexPointervINTELproc(size, type, pointer);
}
PFNGLNORMALPOINTERVINTELPROC glNormalPointervINTELproc = 0;
void APIENTRY glNormalPointervINTEL(GLenum type, const void** pointer) {
	if (!glNormalPointervINTELproc) return;
	glNormalPointervINTELproc(type, pointer);
}
PFNGLCOLORPOINTERVINTELPROC glColorPointervINTELproc = 0;
void APIENTRY glColorPointervINTEL(GLint size, GLenum type, const void** pointer) {
	if (!glColorPointervINTELproc) return;
	glColorPointervINTELproc(size, type, pointer);
}
PFNGLTEXCOORDPOINTERVINTELPROC glTexCoordPointervINTELproc = 0;
void APIENTRY glTexCoordPointervINTEL(GLint size, GLenum type, const void** pointer) {
	if (!glTexCoordPointervINTELproc) return;
	glTexCoordPointervINTELproc(size, type, pointer);
}
PFNGLBEGINPERFQUERYINTELPROC glBeginPerfQueryINTELproc = 0;
void APIENTRY glBeginPerfQueryINTEL(GLuint queryHandle) {
	if (!glBeginPerfQueryINTELproc) return;
	glBeginPerfQueryINTELproc(queryHandle);
}
PFNGLCREATEPERFQUERYINTELPROC glCreatePerfQueryINTELproc = 0;
void APIENTRY glCreatePerfQueryINTEL(GLuint queryId, GLuint* queryHandle) {
	if (!glCreatePerfQueryINTELproc) return;
	glCreatePerfQueryINTELproc(queryId, queryHandle);
}
PFNGLDELETEPERFQUERYINTELPROC glDeletePerfQueryINTELproc = 0;
void APIENTRY glDeletePerfQueryINTEL(GLuint queryHandle) {
	if (!glDeletePerfQueryINTELproc) return;
	glDeletePerfQueryINTELproc(queryHandle);
}
PFNGLENDPERFQUERYINTELPROC glEndPerfQueryINTELproc = 0;
void APIENTRY glEndPerfQueryINTEL(GLuint queryHandle) {
	if (!glEndPerfQueryINTELproc) return;
	glEndPerfQueryINTELproc(queryHandle);
}
PFNGLGETFIRSTPERFQUERYIDINTELPROC glGetFirstPerfQueryIdINTELproc = 0;
void APIENTRY glGetFirstPerfQueryIdINTEL(GLuint* queryId) {
	if (!glGetFirstPerfQueryIdINTELproc) return;
	glGetFirstPerfQueryIdINTELproc(queryId);
}
PFNGLGETNEXTPERFQUERYIDINTELPROC glGetNextPerfQueryIdINTELproc = 0;
void APIENTRY glGetNextPerfQueryIdINTEL(GLuint queryId, GLuint* nextQueryId) {
	if (!glGetNextPerfQueryIdINTELproc) return;
	glGetNextPerfQueryIdINTELproc(queryId, nextQueryId);
}
PFNGLGETPERFCOUNTERINFOINTELPROC glGetPerfCounterInfoINTELproc = 0;
void APIENTRY glGetPerfCounterInfoINTEL(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar* counterName, GLuint counterDescLength, GLchar* counterDesc, GLuint* counterOffset, GLuint* counterDataSize, GLuint* counterTypeEnum, GLuint* counterDataTypeEnum, GLuint64* rawCounterMaxValue) {
	if (!glGetPerfCounterInfoINTELproc) return;
	glGetPerfCounterInfoINTELproc(queryId, counterId, counterNameLength, counterName, counterDescLength, counterDesc, counterOffset, counterDataSize, counterTypeEnum, counterDataTypeEnum, rawCounterMaxValue);
}
PFNGLGETPERFQUERYDATAINTELPROC glGetPerfQueryDataINTELproc = 0;
void APIENTRY glGetPerfQueryDataINTEL(GLuint queryHandle, GLuint flags, GLsizei dataSize, void* data, GLuint* bytesWritten) {
	if (!glGetPerfQueryDataINTELproc) return;
	glGetPerfQueryDataINTELproc(queryHandle, flags, dataSize, data, bytesWritten);
}
PFNGLGETPERFQUERYIDBYNAMEINTELPROC glGetPerfQueryIdByNameINTELproc = 0;
void APIENTRY glGetPerfQueryIdByNameINTEL(GLchar* queryName, GLuint* queryId) {
	if (!glGetPerfQueryIdByNameINTELproc) return;
	glGetPerfQueryIdByNameINTELproc(queryName, queryId);
}
PFNGLGETPERFQUERYINFOINTELPROC glGetPerfQueryInfoINTELproc = 0;
void APIENTRY glGetPerfQueryInfoINTEL(GLuint queryId, GLuint queryNameLength, GLchar* queryName, GLuint* dataSize, GLuint* noCounters, GLuint* noInstances, GLuint* capsMask) {
	if (!glGetPerfQueryInfoINTELproc) return;
	glGetPerfQueryInfoINTELproc(queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask);
}
PFNGLFRAMEBUFFERPARAMETERIMESAPROC glFramebufferParameteriMESAproc = 0;
void APIENTRY glFramebufferParameteriMESA(GLenum target, GLenum pname, GLint param) {
	if (!glFramebufferParameteriMESAproc) return;
	glFramebufferParameteriMESAproc(target, pname, param);
}
PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC glGetFramebufferParameterivMESAproc = 0;
void APIENTRY glGetFramebufferParameterivMESA(GLenum target, GLenum pname, GLint* params) {
	if (!glGetFramebufferParameterivMESAproc) return;
	glGetFramebufferParameterivMESAproc(target, pname, params);
}
PFNGLRESIZEBUFFERSMESAPROC glResizeBuffersMESAproc = 0;
void APIENTRY glResizeBuffersMESA(void) {
	if (!glResizeBuffersMESAproc) return;
	glResizeBuffersMESAproc();
}
PFNGLWINDOWPOS2DMESAPROC glWindowPos2dMESAproc = 0;
void APIENTRY glWindowPos2dMESA(GLdouble x, GLdouble y) {
	if (!glWindowPos2dMESAproc) return;
	glWindowPos2dMESAproc(x, y);
}
PFNGLWINDOWPOS2DVMESAPROC glWindowPos2dvMESAproc = 0;
void APIENTRY glWindowPos2dvMESA(const GLdouble* v) {
	if (!glWindowPos2dvMESAproc) return;
	glWindowPos2dvMESAproc(v);
}
PFNGLWINDOWPOS2FMESAPROC glWindowPos2fMESAproc = 0;
void APIENTRY glWindowPos2fMESA(GLfloat x, GLfloat y) {
	if (!glWindowPos2fMESAproc) return;
	glWindowPos2fMESAproc(x, y);
}
PFNGLWINDOWPOS2FVMESAPROC glWindowPos2fvMESAproc = 0;
void APIENTRY glWindowPos2fvMESA(const GLfloat* v) {
	if (!glWindowPos2fvMESAproc) return;
	glWindowPos2fvMESAproc(v);
}
PFNGLWINDOWPOS2IMESAPROC glWindowPos2iMESAproc = 0;
void APIENTRY glWindowPos2iMESA(GLint x, GLint y) {
	if (!glWindowPos2iMESAproc) return;
	glWindowPos2iMESAproc(x, y);
}
PFNGLWINDOWPOS2IVMESAPROC glWindowPos2ivMESAproc = 0;
void APIENTRY glWindowPos2ivMESA(const GLint* v) {
	if (!glWindowPos2ivMESAproc) return;
	glWindowPos2ivMESAproc(v);
}
PFNGLWINDOWPOS2SMESAPROC glWindowPos2sMESAproc = 0;
void APIENTRY glWindowPos2sMESA(GLshort x, GLshort y) {
	if (!glWindowPos2sMESAproc) return;
	glWindowPos2sMESAproc(x, y);
}
PFNGLWINDOWPOS2SVMESAPROC glWindowPos2svMESAproc = 0;
void APIENTRY glWindowPos2svMESA(const GLshort* v) {
	if (!glWindowPos2svMESAproc) return;
	glWindowPos2svMESAproc(v);
}
PFNGLWINDOWPOS3DMESAPROC glWindowPos3dMESAproc = 0;
void APIENTRY glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z) {
	if (!glWindowPos3dMESAproc) return;
	glWindowPos3dMESAproc(x, y, z);
}
PFNGLWINDOWPOS3DVMESAPROC glWindowPos3dvMESAproc = 0;
void APIENTRY glWindowPos3dvMESA(const GLdouble* v) {
	if (!glWindowPos3dvMESAproc) return;
	glWindowPos3dvMESAproc(v);
}
PFNGLWINDOWPOS3FMESAPROC glWindowPos3fMESAproc = 0;
void APIENTRY glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z) {
	if (!glWindowPos3fMESAproc) return;
	glWindowPos3fMESAproc(x, y, z);
}
PFNGLWINDOWPOS3FVMESAPROC glWindowPos3fvMESAproc = 0;
void APIENTRY glWindowPos3fvMESA(const GLfloat* v) {
	if (!glWindowPos3fvMESAproc) return;
	glWindowPos3fvMESAproc(v);
}
PFNGLWINDOWPOS3IMESAPROC glWindowPos3iMESAproc = 0;
void APIENTRY glWindowPos3iMESA(GLint x, GLint y, GLint z) {
	if (!glWindowPos3iMESAproc) return;
	glWindowPos3iMESAproc(x, y, z);
}
PFNGLWINDOWPOS3IVMESAPROC glWindowPos3ivMESAproc = 0;
void APIENTRY glWindowPos3ivMESA(const GLint* v) {
	if (!glWindowPos3ivMESAproc) return;
	glWindowPos3ivMESAproc(v);
}
PFNGLWINDOWPOS3SMESAPROC glWindowPos3sMESAproc = 0;
void APIENTRY glWindowPos3sMESA(GLshort x, GLshort y, GLshort z) {
	if (!glWindowPos3sMESAproc) return;
	glWindowPos3sMESAproc(x, y, z);
}
PFNGLWINDOWPOS3SVMESAPROC glWindowPos3svMESAproc = 0;
void APIENTRY glWindowPos3svMESA(const GLshort* v) {
	if (!glWindowPos3svMESAproc) return;
	glWindowPos3svMESAproc(v);
}
PFNGLWINDOWPOS4DMESAPROC glWindowPos4dMESAproc = 0;
void APIENTRY glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glWindowPos4dMESAproc) return;
	glWindowPos4dMESAproc(x, y, z, w);
}
PFNGLWINDOWPOS4DVMESAPROC glWindowPos4dvMESAproc = 0;
void APIENTRY glWindowPos4dvMESA(const GLdouble* v) {
	if (!glWindowPos4dvMESAproc) return;
	glWindowPos4dvMESAproc(v);
}
PFNGLWINDOWPOS4FMESAPROC glWindowPos4fMESAproc = 0;
void APIENTRY glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glWindowPos4fMESAproc) return;
	glWindowPos4fMESAproc(x, y, z, w);
}
PFNGLWINDOWPOS4FVMESAPROC glWindowPos4fvMESAproc = 0;
void APIENTRY glWindowPos4fvMESA(const GLfloat* v) {
	if (!glWindowPos4fvMESAproc) return;
	glWindowPos4fvMESAproc(v);
}
PFNGLWINDOWPOS4IMESAPROC glWindowPos4iMESAproc = 0;
void APIENTRY glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w) {
	if (!glWindowPos4iMESAproc) return;
	glWindowPos4iMESAproc(x, y, z, w);
}
PFNGLWINDOWPOS4IVMESAPROC glWindowPos4ivMESAproc = 0;
void APIENTRY glWindowPos4ivMESA(const GLint* v) {
	if (!glWindowPos4ivMESAproc) return;
	glWindowPos4ivMESAproc(v);
}
PFNGLWINDOWPOS4SMESAPROC glWindowPos4sMESAproc = 0;
void APIENTRY glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w) {
	if (!glWindowPos4sMESAproc) return;
	glWindowPos4sMESAproc(x, y, z, w);
}
PFNGLWINDOWPOS4SVMESAPROC glWindowPos4svMESAproc = 0;
void APIENTRY glWindowPos4svMESA(const GLshort* v) {
	if (!glWindowPos4svMESAproc) return;
	glWindowPos4svMESAproc(v);
}
PFNGLBEGINCONDITIONALRENDERNVXPROC glBeginConditionalRenderNVXproc = 0;
void APIENTRY glBeginConditionalRenderNVX(GLuint id) {
	if (!glBeginConditionalRenderNVXproc) return;
	glBeginConditionalRenderNVXproc(id);
}
PFNGLENDCONDITIONALRENDERNVXPROC glEndConditionalRenderNVXproc = 0;
void APIENTRY glEndConditionalRenderNVX(void) {
	if (!glEndConditionalRenderNVXproc) return;
	glEndConditionalRenderNVXproc();
}
PFNGLUPLOADGPUMASKNVXPROC glUploadGpuMaskNVXproc = 0;
void APIENTRY glUploadGpuMaskNVX(GLbitfield mask) {
	if (!glUploadGpuMaskNVXproc) return;
	glUploadGpuMaskNVXproc(mask);
}
PFNGLMULTICASTVIEWPORTARRAYVNVXPROC glMulticastViewportArrayvNVXproc = 0;
void APIENTRY glMulticastViewportArrayvNVX(GLuint gpu, GLuint first, GLsizei count, const GLfloat* v) {
	if (!glMulticastViewportArrayvNVXproc) return;
	glMulticastViewportArrayvNVXproc(gpu, first, count, v);
}
PFNGLMULTICASTVIEWPORTPOSITIONWSCALENVXPROC glMulticastViewportPositionWScaleNVXproc = 0;
void APIENTRY glMulticastViewportPositionWScaleNVX(GLuint gpu, GLuint index, GLfloat xcoeff, GLfloat ycoeff) {
	if (!glMulticastViewportPositionWScaleNVXproc) return;
	glMulticastViewportPositionWScaleNVXproc(gpu, index, xcoeff, ycoeff);
}
PFNGLMULTICASTSCISSORARRAYVNVXPROC glMulticastScissorArrayvNVXproc = 0;
void APIENTRY glMulticastScissorArrayvNVX(GLuint gpu, GLuint first, GLsizei count, const GLint* v) {
	if (!glMulticastScissorArrayvNVXproc) return;
	glMulticastScissorArrayvNVXproc(gpu, first, count, v);
}
PFNGLASYNCCOPYBUFFERSUBDATANVXPROC glAsyncCopyBufferSubDataNVXproc = 0;
GLuint APIENTRY glAsyncCopyBufferSubDataNVX(GLsizei waitSemaphoreCount, const GLuint* waitSemaphoreArray, const GLuint64* fenceValueArray, GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsizei signalSemaphoreCount, const GLuint* signalSemaphoreArray, const GLuint64* signalValueArray) {
	if (!glAsyncCopyBufferSubDataNVXproc) return 0;
	return glAsyncCopyBufferSubDataNVXproc(waitSemaphoreCount, waitSemaphoreArray, fenceValueArray, readGpu, writeGpuMask, readBuffer, writeBuffer, readOffset, writeOffset, size, signalSemaphoreCount, signalSemaphoreArray, signalValueArray);
}
PFNGLASYNCCOPYIMAGESUBDATANVXPROC glAsyncCopyImageSubDataNVXproc = 0;
GLuint APIENTRY glAsyncCopyImageSubDataNVX(GLsizei waitSemaphoreCount, const GLuint* waitSemaphoreArray, const GLuint64* waitValueArray, GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, GLsizei signalSemaphoreCount, const GLuint* signalSemaphoreArray, const GLuint64* signalValueArray) {
	if (!glAsyncCopyImageSubDataNVXproc) return 0;
	return glAsyncCopyImageSubDataNVXproc(waitSemaphoreCount, waitSemaphoreArray, waitValueArray, srcGpu, dstGpuMask, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth, signalSemaphoreCount, signalSemaphoreArray, signalValueArray);
}
PFNGLLGPUNAMEDBUFFERSUBDATANVXPROC glLGPUNamedBufferSubDataNVXproc = 0;
void APIENTRY glLGPUNamedBufferSubDataNVX(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) {
	if (!glLGPUNamedBufferSubDataNVXproc) return;
	glLGPUNamedBufferSubDataNVXproc(gpuMask, buffer, offset, size, data);
}
PFNGLLGPUCOPYIMAGESUBDATANVXPROC glLGPUCopyImageSubDataNVXproc = 0;
void APIENTRY glLGPUCopyImageSubDataNVX(GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srxY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
	if (!glLGPUCopyImageSubDataNVXproc) return;
	glLGPUCopyImageSubDataNVXproc(sourceGpu, destinationGpuMask, srcName, srcTarget, srcLevel, srcX, srxY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}
PFNGLLGPUINTERLOCKNVXPROC glLGPUInterlockNVXproc = 0;
void APIENTRY glLGPUInterlockNVX(void) {
	if (!glLGPUInterlockNVXproc) return;
	glLGPUInterlockNVXproc();
}
PFNGLCREATEPROGRESSFENCENVXPROC glCreateProgressFenceNVXproc = 0;
GLuint APIENTRY glCreateProgressFenceNVX(void) {
	if (!glCreateProgressFenceNVXproc) return 0;
	return glCreateProgressFenceNVXproc();
}
PFNGLSIGNALSEMAPHOREUI64NVXPROC glSignalSemaphoreui64NVXproc = 0;
void APIENTRY glSignalSemaphoreui64NVX(GLuint signalGpu, GLsizei fenceObjectCount, const GLuint* semaphoreArray, const GLuint64* fenceValueArray) {
	if (!glSignalSemaphoreui64NVXproc) return;
	glSignalSemaphoreui64NVXproc(signalGpu, fenceObjectCount, semaphoreArray, fenceValueArray);
}
PFNGLWAITSEMAPHOREUI64NVXPROC glWaitSemaphoreui64NVXproc = 0;
void APIENTRY glWaitSemaphoreui64NVX(GLuint waitGpu, GLsizei fenceObjectCount, const GLuint* semaphoreArray, const GLuint64* fenceValueArray) {
	if (!glWaitSemaphoreui64NVXproc) return;
	glWaitSemaphoreui64NVXproc(waitGpu, fenceObjectCount, semaphoreArray, fenceValueArray);
}
PFNGLCLIENTWAITSEMAPHOREUI64NVXPROC glClientWaitSemaphoreui64NVXproc = 0;
void APIENTRY glClientWaitSemaphoreui64NVX(GLsizei fenceObjectCount, const GLuint* semaphoreArray, const GLuint64* fenceValueArray) {
	if (!glClientWaitSemaphoreui64NVXproc) return;
	glClientWaitSemaphoreui64NVXproc(fenceObjectCount, semaphoreArray, fenceValueArray);
}
PFNGLALPHATOCOVERAGEDITHERCONTROLNVPROC glAlphaToCoverageDitherControlNVproc = 0;
void APIENTRY glAlphaToCoverageDitherControlNV(GLenum mode) {
	if (!glAlphaToCoverageDitherControlNVproc) return;
	glAlphaToCoverageDitherControlNVproc(mode);
}
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC glMultiDrawArraysIndirectBindlessNVproc = 0;
void APIENTRY glMultiDrawArraysIndirectBindlessNV(GLenum mode, const void* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) {
	if (!glMultiDrawArraysIndirectBindlessNVproc) return;
	glMultiDrawArraysIndirectBindlessNVproc(mode, indirect, drawCount, stride, vertexBufferCount);
}
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC glMultiDrawElementsIndirectBindlessNVproc = 0;
void APIENTRY glMultiDrawElementsIndirectBindlessNV(GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) {
	if (!glMultiDrawElementsIndirectBindlessNVproc) return;
	glMultiDrawElementsIndirectBindlessNVproc(mode, type, indirect, drawCount, stride, vertexBufferCount);
}
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawArraysIndirectBindlessCountNVproc = 0;
void APIENTRY glMultiDrawArraysIndirectBindlessCountNV(GLenum mode, const void* indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) {
	if (!glMultiDrawArraysIndirectBindlessCountNVproc) return;
	glMultiDrawArraysIndirectBindlessCountNVproc(mode, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawElementsIndirectBindlessCountNVproc = 0;
void APIENTRY glMultiDrawElementsIndirectBindlessCountNV(GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) {
	if (!glMultiDrawElementsIndirectBindlessCountNVproc) return;
	glMultiDrawElementsIndirectBindlessCountNVproc(mode, type, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}
PFNGLGETTEXTUREHANDLENVPROC glGetTextureHandleNVproc = 0;
GLuint64 APIENTRY glGetTextureHandleNV(GLuint texture) {
	if (!glGetTextureHandleNVproc) return 0;
	return glGetTextureHandleNVproc(texture);
}
PFNGLGETTEXTURESAMPLERHANDLENVPROC glGetTextureSamplerHandleNVproc = 0;
GLuint64 APIENTRY glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler) {
	if (!glGetTextureSamplerHandleNVproc) return 0;
	return glGetTextureSamplerHandleNVproc(texture, sampler);
}
PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glMakeTextureHandleResidentNVproc = 0;
void APIENTRY glMakeTextureHandleResidentNV(GLuint64 handle) {
	if (!glMakeTextureHandleResidentNVproc) return;
	glMakeTextureHandleResidentNVproc(handle);
}
PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glMakeTextureHandleNonResidentNVproc = 0;
void APIENTRY glMakeTextureHandleNonResidentNV(GLuint64 handle) {
	if (!glMakeTextureHandleNonResidentNVproc) return;
	glMakeTextureHandleNonResidentNVproc(handle);
}
PFNGLGETIMAGEHANDLENVPROC glGetImageHandleNVproc = 0;
GLuint64 APIENTRY glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) {
	if (!glGetImageHandleNVproc) return 0;
	return glGetImageHandleNVproc(texture, level, layered, layer, format);
}
PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glMakeImageHandleResidentNVproc = 0;
void APIENTRY glMakeImageHandleResidentNV(GLuint64 handle, GLenum access) {
	if (!glMakeImageHandleResidentNVproc) return;
	glMakeImageHandleResidentNVproc(handle, access);
}
PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glMakeImageHandleNonResidentNVproc = 0;
void APIENTRY glMakeImageHandleNonResidentNV(GLuint64 handle) {
	if (!glMakeImageHandleNonResidentNVproc) return;
	glMakeImageHandleNonResidentNVproc(handle);
}
PFNGLUNIFORMHANDLEUI64NVPROC glUniformHandleui64NVproc = 0;
void APIENTRY glUniformHandleui64NV(GLint location, GLuint64 value) {
	if (!glUniformHandleui64NVproc) return;
	glUniformHandleui64NVproc(location, value);
}
PFNGLUNIFORMHANDLEUI64VNVPROC glUniformHandleui64vNVproc = 0;
void APIENTRY glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64* value) {
	if (!glUniformHandleui64vNVproc) return;
	glUniformHandleui64vNVproc(location, count, value);
}
PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glProgramUniformHandleui64NVproc = 0;
void APIENTRY glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value) {
	if (!glProgramUniformHandleui64NVproc) return;
	glProgramUniformHandleui64NVproc(program, location, value);
}
PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glProgramUniformHandleui64vNVproc = 0;
void APIENTRY glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64* values) {
	if (!glProgramUniformHandleui64vNVproc) return;
	glProgramUniformHandleui64vNVproc(program, location, count, values);
}
PFNGLISTEXTUREHANDLERESIDENTNVPROC glIsTextureHandleResidentNVproc = 0;
GLboolean APIENTRY glIsTextureHandleResidentNV(GLuint64 handle) {
	if (!glIsTextureHandleResidentNVproc) return 0;
	return glIsTextureHandleResidentNVproc(handle);
}
PFNGLISIMAGEHANDLERESIDENTNVPROC glIsImageHandleResidentNVproc = 0;
GLboolean APIENTRY glIsImageHandleResidentNV(GLuint64 handle) {
	if (!glIsImageHandleResidentNVproc) return 0;
	return glIsImageHandleResidentNVproc(handle);
}
PFNGLBLENDPARAMETERINVPROC glBlendParameteriNVproc = 0;
void APIENTRY glBlendParameteriNV(GLenum pname, GLint value) {
	if (!glBlendParameteriNVproc) return;
	glBlendParameteriNVproc(pname, value);
}
PFNGLBLENDBARRIERNVPROC glBlendBarrierNVproc = 0;
void APIENTRY glBlendBarrierNV(void) {
	if (!glBlendBarrierNVproc) return;
	glBlendBarrierNVproc();
}
PFNGLVIEWPORTPOSITIONWSCALENVPROC glViewportPositionWScaleNVproc = 0;
void APIENTRY glViewportPositionWScaleNV(GLuint index, GLfloat xcoeff, GLfloat ycoeff) {
	if (!glViewportPositionWScaleNVproc) return;
	glViewportPositionWScaleNVproc(index, xcoeff, ycoeff);
}
PFNGLCREATESTATESNVPROC glCreateStatesNVproc = 0;
void APIENTRY glCreateStatesNV(GLsizei n, GLuint* states) {
	if (!glCreateStatesNVproc) return;
	glCreateStatesNVproc(n, states);
}
PFNGLDELETESTATESNVPROC glDeleteStatesNVproc = 0;
void APIENTRY glDeleteStatesNV(GLsizei n, const GLuint* states) {
	if (!glDeleteStatesNVproc) return;
	glDeleteStatesNVproc(n, states);
}
PFNGLISSTATENVPROC glIsStateNVproc = 0;
GLboolean APIENTRY glIsStateNV(GLuint state) {
	if (!glIsStateNVproc) return 0;
	return glIsStateNVproc(state);
}
PFNGLSTATECAPTURENVPROC glStateCaptureNVproc = 0;
void APIENTRY glStateCaptureNV(GLuint state, GLenum mode) {
	if (!glStateCaptureNVproc) return;
	glStateCaptureNVproc(state, mode);
}
PFNGLGETCOMMANDHEADERNVPROC glGetCommandHeaderNVproc = 0;
GLuint APIENTRY glGetCommandHeaderNV(GLenum tokenID, GLuint size) {
	if (!glGetCommandHeaderNVproc) return 0;
	return glGetCommandHeaderNVproc(tokenID, size);
}
PFNGLGETSTAGEINDEXNVPROC glGetStageIndexNVproc = 0;
GLushort APIENTRY glGetStageIndexNV(GLenum shadertype) {
	if (!glGetStageIndexNVproc) return 0;
	return glGetStageIndexNVproc(shadertype);
}
PFNGLDRAWCOMMANDSNVPROC glDrawCommandsNVproc = 0;
void APIENTRY glDrawCommandsNV(GLenum primitiveMode, GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, GLuint count) {
	if (!glDrawCommandsNVproc) return;
	glDrawCommandsNVproc(primitiveMode, buffer, indirects, sizes, count);
}
PFNGLDRAWCOMMANDSADDRESSNVPROC glDrawCommandsAddressNVproc = 0;
void APIENTRY glDrawCommandsAddressNV(GLenum primitiveMode, const GLuint64* indirects, const GLsizei* sizes, GLuint count) {
	if (!glDrawCommandsAddressNVproc) return;
	glDrawCommandsAddressNVproc(primitiveMode, indirects, sizes, count);
}
PFNGLDRAWCOMMANDSSTATESNVPROC glDrawCommandsStatesNVproc = 0;
void APIENTRY glDrawCommandsStatesNV(GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count) {
	if (!glDrawCommandsStatesNVproc) return;
	glDrawCommandsStatesNVproc(buffer, indirects, sizes, states, fbos, count);
}
PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC glDrawCommandsStatesAddressNVproc = 0;
void APIENTRY glDrawCommandsStatesAddressNV(const GLuint64* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count) {
	if (!glDrawCommandsStatesAddressNVproc) return;
	glDrawCommandsStatesAddressNVproc(indirects, sizes, states, fbos, count);
}
PFNGLCREATECOMMANDLISTSNVPROC glCreateCommandListsNVproc = 0;
void APIENTRY glCreateCommandListsNV(GLsizei n, GLuint* lists) {
	if (!glCreateCommandListsNVproc) return;
	glCreateCommandListsNVproc(n, lists);
}
PFNGLDELETECOMMANDLISTSNVPROC glDeleteCommandListsNVproc = 0;
void APIENTRY glDeleteCommandListsNV(GLsizei n, const GLuint* lists) {
	if (!glDeleteCommandListsNVproc) return;
	glDeleteCommandListsNVproc(n, lists);
}
PFNGLISCOMMANDLISTNVPROC glIsCommandListNVproc = 0;
GLboolean APIENTRY glIsCommandListNV(GLuint list) {
	if (!glIsCommandListNVproc) return 0;
	return glIsCommandListNVproc(list);
}
PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC glListDrawCommandsStatesClientNVproc = 0;
void APIENTRY glListDrawCommandsStatesClientNV(GLuint list, GLuint segment, const void** indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count) {
	if (!glListDrawCommandsStatesClientNVproc) return;
	glListDrawCommandsStatesClientNVproc(list, segment, indirects, sizes, states, fbos, count);
}
PFNGLCOMMANDLISTSEGMENTSNVPROC glCommandListSegmentsNVproc = 0;
void APIENTRY glCommandListSegmentsNV(GLuint list, GLuint segments) {
	if (!glCommandListSegmentsNVproc) return;
	glCommandListSegmentsNVproc(list, segments);
}
PFNGLCOMPILECOMMANDLISTNVPROC glCompileCommandListNVproc = 0;
void APIENTRY glCompileCommandListNV(GLuint list) {
	if (!glCompileCommandListNVproc) return;
	glCompileCommandListNVproc(list);
}
PFNGLCALLCOMMANDLISTNVPROC glCallCommandListNVproc = 0;
void APIENTRY glCallCommandListNV(GLuint list) {
	if (!glCallCommandListNVproc) return;
	glCallCommandListNVproc(list);
}
PFNGLBEGINCONDITIONALRENDERNVPROC glBeginConditionalRenderNVproc = 0;
void APIENTRY glBeginConditionalRenderNV(GLuint id, GLenum mode) {
	if (!glBeginConditionalRenderNVproc) return;
	glBeginConditionalRenderNVproc(id, mode);
}
PFNGLENDCONDITIONALRENDERNVPROC glEndConditionalRenderNVproc = 0;
void APIENTRY glEndConditionalRenderNV(void) {
	if (!glEndConditionalRenderNVproc) return;
	glEndConditionalRenderNVproc();
}
PFNGLSUBPIXELPRECISIONBIASNVPROC glSubpixelPrecisionBiasNVproc = 0;
void APIENTRY glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits) {
	if (!glSubpixelPrecisionBiasNVproc) return;
	glSubpixelPrecisionBiasNVproc(xbits, ybits);
}
PFNGLCONSERVATIVERASTERPARAMETERFNVPROC glConservativeRasterParameterfNVproc = 0;
void APIENTRY glConservativeRasterParameterfNV(GLenum pname, GLfloat value) {
	if (!glConservativeRasterParameterfNVproc) return;
	glConservativeRasterParameterfNVproc(pname, value);
}
PFNGLCONSERVATIVERASTERPARAMETERINVPROC glConservativeRasterParameteriNVproc = 0;
void APIENTRY glConservativeRasterParameteriNV(GLenum pname, GLint param) {
	if (!glConservativeRasterParameteriNVproc) return;
	glConservativeRasterParameteriNVproc(pname, param);
}
PFNGLCOPYIMAGESUBDATANVPROC glCopyImageSubDataNVproc = 0;
void APIENTRY glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
	if (!glCopyImageSubDataNVproc) return;
	glCopyImageSubDataNVproc(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}
PFNGLDEPTHRANGEDNVPROC glDepthRangedNVproc = 0;
void APIENTRY glDepthRangedNV(GLdouble zNear, GLdouble zFar) {
	if (!glDepthRangedNVproc) return;
	glDepthRangedNVproc(zNear, zFar);
}
PFNGLCLEARDEPTHDNVPROC glClearDepthdNVproc = 0;
void APIENTRY glClearDepthdNV(GLdouble depth) {
	if (!glClearDepthdNVproc) return;
	glClearDepthdNVproc(depth);
}
PFNGLDEPTHBOUNDSDNVPROC glDepthBoundsdNVproc = 0;
void APIENTRY glDepthBoundsdNV(GLdouble zmin, GLdouble zmax) {
	if (!glDepthBoundsdNVproc) return;
	glDepthBoundsdNVproc(zmin, zmax);
}
PFNGLDRAWTEXTURENVPROC glDrawTextureNVproc = 0;
void APIENTRY glDrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) {
	if (!glDrawTextureNVproc) return;
	glDrawTextureNVproc(texture, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}
PFNGLDRAWVKIMAGENVPROC glDrawVkImageNVproc = 0;
void APIENTRY glDrawVkImageNV(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) {
	if (!glDrawVkImageNVproc) return;
	glDrawVkImageNVproc(vkImage, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}
PFNGLGETVKPROCADDRNVPROC glGetVkProcAddrNVproc = 0;
GLVULKANPROCNV APIENTRY glGetVkProcAddrNV(const GLchar* name) {
	if (!glGetVkProcAddrNVproc) return 0;
	return glGetVkProcAddrNVproc(name);
}
PFNGLWAITVKSEMAPHORENVPROC glWaitVkSemaphoreNVproc = 0;
void APIENTRY glWaitVkSemaphoreNV(GLuint64 vkSemaphore) {
	if (!glWaitVkSemaphoreNVproc) return;
	glWaitVkSemaphoreNVproc(vkSemaphore);
}
PFNGLSIGNALVKSEMAPHORENVPROC glSignalVkSemaphoreNVproc = 0;
void APIENTRY glSignalVkSemaphoreNV(GLuint64 vkSemaphore) {
	if (!glSignalVkSemaphoreNVproc) return;
	glSignalVkSemaphoreNVproc(vkSemaphore);
}
PFNGLSIGNALVKFENCENVPROC glSignalVkFenceNVproc = 0;
void APIENTRY glSignalVkFenceNV(GLuint64 vkFence) {
	if (!glSignalVkFenceNVproc) return;
	glSignalVkFenceNVproc(vkFence);
}
PFNGLMAPCONTROLPOINTSNVPROC glMapControlPointsNVproc = 0;
void APIENTRY glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void* points) {
	if (!glMapControlPointsNVproc) return;
	glMapControlPointsNVproc(target, index, type, ustride, vstride, uorder, vorder, packed, points);
}
PFNGLMAPPARAMETERIVNVPROC glMapParameterivNVproc = 0;
void APIENTRY glMapParameterivNV(GLenum target, GLenum pname, const GLint* params) {
	if (!glMapParameterivNVproc) return;
	glMapParameterivNVproc(target, pname, params);
}
PFNGLMAPPARAMETERFVNVPROC glMapParameterfvNVproc = 0;
void APIENTRY glMapParameterfvNV(GLenum target, GLenum pname, const GLfloat* params) {
	if (!glMapParameterfvNVproc) return;
	glMapParameterfvNVproc(target, pname, params);
}
PFNGLGETMAPCONTROLPOINTSNVPROC glGetMapControlPointsNVproc = 0;
void APIENTRY glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void* points) {
	if (!glGetMapControlPointsNVproc) return;
	glGetMapControlPointsNVproc(target, index, type, ustride, vstride, packed, points);
}
PFNGLGETMAPPARAMETERIVNVPROC glGetMapParameterivNVproc = 0;
void APIENTRY glGetMapParameterivNV(GLenum target, GLenum pname, GLint* params) {
	if (!glGetMapParameterivNVproc) return;
	glGetMapParameterivNVproc(target, pname, params);
}
PFNGLGETMAPPARAMETERFVNVPROC glGetMapParameterfvNVproc = 0;
void APIENTRY glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetMapParameterfvNVproc) return;
	glGetMapParameterfvNVproc(target, pname, params);
}
PFNGLGETMAPATTRIBPARAMETERIVNVPROC glGetMapAttribParameterivNVproc = 0;
void APIENTRY glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint* params) {
	if (!glGetMapAttribParameterivNVproc) return;
	glGetMapAttribParameterivNVproc(target, index, pname, params);
}
PFNGLGETMAPATTRIBPARAMETERFVNVPROC glGetMapAttribParameterfvNVproc = 0;
void APIENTRY glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat* params) {
	if (!glGetMapAttribParameterfvNVproc) return;
	glGetMapAttribParameterfvNVproc(target, index, pname, params);
}
PFNGLEVALMAPSNVPROC glEvalMapsNVproc = 0;
void APIENTRY glEvalMapsNV(GLenum target, GLenum mode) {
	if (!glEvalMapsNVproc) return;
	glEvalMapsNVproc(target, mode);
}
PFNGLGETMULTISAMPLEFVNVPROC glGetMultisamplefvNVproc = 0;
void APIENTRY glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat* val) {
	if (!glGetMultisamplefvNVproc) return;
	glGetMultisamplefvNVproc(pname, index, val);
}
PFNGLSAMPLEMASKINDEXEDNVPROC glSampleMaskIndexedNVproc = 0;
void APIENTRY glSampleMaskIndexedNV(GLuint index, GLbitfield mask) {
	if (!glSampleMaskIndexedNVproc) return;
	glSampleMaskIndexedNVproc(index, mask);
}
PFNGLTEXRENDERBUFFERNVPROC glTexRenderbufferNVproc = 0;
void APIENTRY glTexRenderbufferNV(GLenum target, GLuint renderbuffer) {
	if (!glTexRenderbufferNVproc) return;
	glTexRenderbufferNVproc(target, renderbuffer);
}
PFNGLDELETEFENCESNVPROC glDeleteFencesNVproc = 0;
void APIENTRY glDeleteFencesNV(GLsizei n, const GLuint* fences) {
	if (!glDeleteFencesNVproc) return;
	glDeleteFencesNVproc(n, fences);
}
PFNGLGENFENCESNVPROC glGenFencesNVproc = 0;
void APIENTRY glGenFencesNV(GLsizei n, GLuint* fences) {
	if (!glGenFencesNVproc) return;
	glGenFencesNVproc(n, fences);
}
PFNGLISFENCENVPROC glIsFenceNVproc = 0;
GLboolean APIENTRY glIsFenceNV(GLuint fence) {
	if (!glIsFenceNVproc) return 0;
	return glIsFenceNVproc(fence);
}
PFNGLTESTFENCENVPROC glTestFenceNVproc = 0;
GLboolean APIENTRY glTestFenceNV(GLuint fence) {
	if (!glTestFenceNVproc) return 0;
	return glTestFenceNVproc(fence);
}
PFNGLGETFENCEIVNVPROC glGetFenceivNVproc = 0;
void APIENTRY glGetFenceivNV(GLuint fence, GLenum pname, GLint* params) {
	if (!glGetFenceivNVproc) return;
	glGetFenceivNVproc(fence, pname, params);
}
PFNGLFINISHFENCENVPROC glFinishFenceNVproc = 0;
void APIENTRY glFinishFenceNV(GLuint fence) {
	if (!glFinishFenceNVproc) return;
	glFinishFenceNVproc(fence);
}
PFNGLSETFENCENVPROC glSetFenceNVproc = 0;
void APIENTRY glSetFenceNV(GLuint fence, GLenum condition) {
	if (!glSetFenceNVproc) return;
	glSetFenceNVproc(fence, condition);
}
PFNGLFRAGMENTCOVERAGECOLORNVPROC glFragmentCoverageColorNVproc = 0;
void APIENTRY glFragmentCoverageColorNV(GLuint color) {
	if (!glFragmentCoverageColorNVproc) return;
	glFragmentCoverageColorNVproc(color);
}
PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glProgramNamedParameter4fNVproc = 0;
void APIENTRY glProgramNamedParameter4fNV(GLuint id, GLsizei len, const GLubyte* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glProgramNamedParameter4fNVproc) return;
	glProgramNamedParameter4fNVproc(id, len, name, x, y, z, w);
}
PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glProgramNamedParameter4fvNVproc = 0;
void APIENTRY glProgramNamedParameter4fvNV(GLuint id, GLsizei len, const GLubyte* name, const GLfloat* v) {
	if (!glProgramNamedParameter4fvNVproc) return;
	glProgramNamedParameter4fvNVproc(id, len, name, v);
}
PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glProgramNamedParameter4dNVproc = 0;
void APIENTRY glProgramNamedParameter4dNV(GLuint id, GLsizei len, const GLubyte* name, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glProgramNamedParameter4dNVproc) return;
	glProgramNamedParameter4dNVproc(id, len, name, x, y, z, w);
}
PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glProgramNamedParameter4dvNVproc = 0;
void APIENTRY glProgramNamedParameter4dvNV(GLuint id, GLsizei len, const GLubyte* name, const GLdouble* v) {
	if (!glProgramNamedParameter4dvNVproc) return;
	glProgramNamedParameter4dvNVproc(id, len, name, v);
}
PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glGetProgramNamedParameterfvNVproc = 0;
void APIENTRY glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, const GLubyte* name, GLfloat* params) {
	if (!glGetProgramNamedParameterfvNVproc) return;
	glGetProgramNamedParameterfvNVproc(id, len, name, params);
}
PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glGetProgramNamedParameterdvNVproc = 0;
void APIENTRY glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, const GLubyte* name, GLdouble* params) {
	if (!glGetProgramNamedParameterdvNVproc) return;
	glGetProgramNamedParameterdvNVproc(id, len, name, params);
}
PFNGLCOVERAGEMODULATIONTABLENVPROC glCoverageModulationTableNVproc = 0;
void APIENTRY glCoverageModulationTableNV(GLsizei n, const GLfloat* v) {
	if (!glCoverageModulationTableNVproc) return;
	glCoverageModulationTableNVproc(n, v);
}
PFNGLGETCOVERAGEMODULATIONTABLENVPROC glGetCoverageModulationTableNVproc = 0;
void APIENTRY glGetCoverageModulationTableNV(GLsizei bufSize, GLfloat* v) {
	if (!glGetCoverageModulationTableNVproc) return;
	glGetCoverageModulationTableNVproc(bufSize, v);
}
PFNGLCOVERAGEMODULATIONNVPROC glCoverageModulationNVproc = 0;
void APIENTRY glCoverageModulationNV(GLenum components) {
	if (!glCoverageModulationNVproc) return;
	glCoverageModulationNVproc(components);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC glRenderbufferStorageMultisampleCoverageNVproc = 0;
void APIENTRY glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
	if (!glRenderbufferStorageMultisampleCoverageNVproc) return;
	glRenderbufferStorageMultisampleCoverageNVproc(target, coverageSamples, colorSamples, internalformat, width, height);
}
PFNGLPROGRAMVERTEXLIMITNVPROC glProgramVertexLimitNVproc = 0;
void APIENTRY glProgramVertexLimitNV(GLenum target, GLint limit) {
	if (!glProgramVertexLimitNVproc) return;
	glProgramVertexLimitNVproc(target, limit);
}
PFNGLFRAMEBUFFERTEXTUREEXTPROC glFramebufferTextureEXTproc = 0;
void APIENTRY glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level) {
	if (!glFramebufferTextureEXTproc) return;
	glFramebufferTextureEXTproc(target, attachment, texture, level);
}
PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC glFramebufferTextureFaceEXTproc = 0;
void APIENTRY glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
	if (!glFramebufferTextureFaceEXTproc) return;
	glFramebufferTextureFaceEXTproc(target, attachment, texture, level, face);
}
PFNGLRENDERGPUMASKNVPROC glRenderGpuMaskNVproc = 0;
void APIENTRY glRenderGpuMaskNV(GLbitfield mask) {
	if (!glRenderGpuMaskNVproc) return;
	glRenderGpuMaskNVproc(mask);
}
PFNGLMULTICASTBUFFERSUBDATANVPROC glMulticastBufferSubDataNVproc = 0;
void APIENTRY glMulticastBufferSubDataNV(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) {
	if (!glMulticastBufferSubDataNVproc) return;
	glMulticastBufferSubDataNVproc(gpuMask, buffer, offset, size, data);
}
PFNGLMULTICASTCOPYBUFFERSUBDATANVPROC glMulticastCopyBufferSubDataNVproc = 0;
void APIENTRY glMulticastCopyBufferSubDataNV(GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
	if (!glMulticastCopyBufferSubDataNVproc) return;
	glMulticastCopyBufferSubDataNVproc(readGpu, writeGpuMask, readBuffer, writeBuffer, readOffset, writeOffset, size);
}
PFNGLMULTICASTCOPYIMAGESUBDATANVPROC glMulticastCopyImageSubDataNVproc = 0;
void APIENTRY glMulticastCopyImageSubDataNV(GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
	if (!glMulticastCopyImageSubDataNVproc) return;
	glMulticastCopyImageSubDataNVproc(srcGpu, dstGpuMask, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
PFNGLMULTICASTBLITFRAMEBUFFERNVPROC glMulticastBlitFramebufferNVproc = 0;
void APIENTRY glMulticastBlitFramebufferNV(GLuint srcGpu, GLuint dstGpu, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	if (!glMulticastBlitFramebufferNVproc) return;
	glMulticastBlitFramebufferNVproc(srcGpu, dstGpu, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNVPROC glMulticastFramebufferSampleLocationsfvNVproc = 0;
void APIENTRY glMulticastFramebufferSampleLocationsfvNV(GLuint gpu, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v) {
	if (!glMulticastFramebufferSampleLocationsfvNVproc) return;
	glMulticastFramebufferSampleLocationsfvNVproc(gpu, framebuffer, start, count, v);
}
PFNGLMULTICASTBARRIERNVPROC glMulticastBarrierNVproc = 0;
void APIENTRY glMulticastBarrierNV(void) {
	if (!glMulticastBarrierNVproc) return;
	glMulticastBarrierNVproc();
}
PFNGLMULTICASTWAITSYNCNVPROC glMulticastWaitSyncNVproc = 0;
void APIENTRY glMulticastWaitSyncNV(GLuint signalGpu, GLbitfield waitGpuMask) {
	if (!glMulticastWaitSyncNVproc) return;
	glMulticastWaitSyncNVproc(signalGpu, waitGpuMask);
}
PFNGLMULTICASTGETQUERYOBJECTIVNVPROC glMulticastGetQueryObjectivNVproc = 0;
void APIENTRY glMulticastGetQueryObjectivNV(GLuint gpu, GLuint id, GLenum pname, GLint* params) {
	if (!glMulticastGetQueryObjectivNVproc) return;
	glMulticastGetQueryObjectivNVproc(gpu, id, pname, params);
}
PFNGLMULTICASTGETQUERYOBJECTUIVNVPROC glMulticastGetQueryObjectuivNVproc = 0;
void APIENTRY glMulticastGetQueryObjectuivNV(GLuint gpu, GLuint id, GLenum pname, GLuint* params) {
	if (!glMulticastGetQueryObjectuivNVproc) return;
	glMulticastGetQueryObjectuivNVproc(gpu, id, pname, params);
}
PFNGLMULTICASTGETQUERYOBJECTI64VNVPROC glMulticastGetQueryObjecti64vNVproc = 0;
void APIENTRY glMulticastGetQueryObjecti64vNV(GLuint gpu, GLuint id, GLenum pname, GLint64* params) {
	if (!glMulticastGetQueryObjecti64vNVproc) return;
	glMulticastGetQueryObjecti64vNVproc(gpu, id, pname, params);
}
PFNGLMULTICASTGETQUERYOBJECTUI64VNVPROC glMulticastGetQueryObjectui64vNVproc = 0;
void APIENTRY glMulticastGetQueryObjectui64vNV(GLuint gpu, GLuint id, GLenum pname, GLuint64* params) {
	if (!glMulticastGetQueryObjectui64vNVproc) return;
	glMulticastGetQueryObjectui64vNVproc(gpu, id, pname, params);
}
PFNGLPROGRAMLOCALPARAMETERI4INVPROC glProgramLocalParameterI4iNVproc = 0;
void APIENTRY glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
	if (!glProgramLocalParameterI4iNVproc) return;
	glProgramLocalParameterI4iNVproc(target, index, x, y, z, w);
}
PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC glProgramLocalParameterI4ivNVproc = 0;
void APIENTRY glProgramLocalParameterI4ivNV(GLenum target, GLuint index, const GLint* params) {
	if (!glProgramLocalParameterI4ivNVproc) return;
	glProgramLocalParameterI4ivNVproc(target, index, params);
}
PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC glProgramLocalParametersI4ivNVproc = 0;
void APIENTRY glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint* params) {
	if (!glProgramLocalParametersI4ivNVproc) return;
	glProgramLocalParametersI4ivNVproc(target, index, count, params);
}
PFNGLPROGRAMLOCALPARAMETERI4UINVPROC glProgramLocalParameterI4uiNVproc = 0;
void APIENTRY glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
	if (!glProgramLocalParameterI4uiNVproc) return;
	glProgramLocalParameterI4uiNVproc(target, index, x, y, z, w);
}
PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC glProgramLocalParameterI4uivNVproc = 0;
void APIENTRY glProgramLocalParameterI4uivNV(GLenum target, GLuint index, const GLuint* params) {
	if (!glProgramLocalParameterI4uivNVproc) return;
	glProgramLocalParameterI4uivNVproc(target, index, params);
}
PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC glProgramLocalParametersI4uivNVproc = 0;
void APIENTRY glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint* params) {
	if (!glProgramLocalParametersI4uivNVproc) return;
	glProgramLocalParametersI4uivNVproc(target, index, count, params);
}
PFNGLPROGRAMENVPARAMETERI4INVPROC glProgramEnvParameterI4iNVproc = 0;
void APIENTRY glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
	if (!glProgramEnvParameterI4iNVproc) return;
	glProgramEnvParameterI4iNVproc(target, index, x, y, z, w);
}
PFNGLPROGRAMENVPARAMETERI4IVNVPROC glProgramEnvParameterI4ivNVproc = 0;
void APIENTRY glProgramEnvParameterI4ivNV(GLenum target, GLuint index, const GLint* params) {
	if (!glProgramEnvParameterI4ivNVproc) return;
	glProgramEnvParameterI4ivNVproc(target, index, params);
}
PFNGLPROGRAMENVPARAMETERSI4IVNVPROC glProgramEnvParametersI4ivNVproc = 0;
void APIENTRY glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint* params) {
	if (!glProgramEnvParametersI4ivNVproc) return;
	glProgramEnvParametersI4ivNVproc(target, index, count, params);
}
PFNGLPROGRAMENVPARAMETERI4UINVPROC glProgramEnvParameterI4uiNVproc = 0;
void APIENTRY glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
	if (!glProgramEnvParameterI4uiNVproc) return;
	glProgramEnvParameterI4uiNVproc(target, index, x, y, z, w);
}
PFNGLPROGRAMENVPARAMETERI4UIVNVPROC glProgramEnvParameterI4uivNVproc = 0;
void APIENTRY glProgramEnvParameterI4uivNV(GLenum target, GLuint index, const GLuint* params) {
	if (!glProgramEnvParameterI4uivNVproc) return;
	glProgramEnvParameterI4uivNVproc(target, index, params);
}
PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC glProgramEnvParametersI4uivNVproc = 0;
void APIENTRY glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint* params) {
	if (!glProgramEnvParametersI4uivNVproc) return;
	glProgramEnvParametersI4uivNVproc(target, index, count, params);
}
PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC glGetProgramLocalParameterIivNVproc = 0;
void APIENTRY glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint* params) {
	if (!glGetProgramLocalParameterIivNVproc) return;
	glGetProgramLocalParameterIivNVproc(target, index, params);
}
PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC glGetProgramLocalParameterIuivNVproc = 0;
void APIENTRY glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint* params) {
	if (!glGetProgramLocalParameterIuivNVproc) return;
	glGetProgramLocalParameterIuivNVproc(target, index, params);
}
PFNGLGETPROGRAMENVPARAMETERIIVNVPROC glGetProgramEnvParameterIivNVproc = 0;
void APIENTRY glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint* params) {
	if (!glGetProgramEnvParameterIivNVproc) return;
	glGetProgramEnvParameterIivNVproc(target, index, params);
}
PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC glGetProgramEnvParameterIuivNVproc = 0;
void APIENTRY glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint* params) {
	if (!glGetProgramEnvParameterIuivNVproc) return;
	glGetProgramEnvParameterIuivNVproc(target, index, params);
}
PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC glProgramSubroutineParametersuivNVproc = 0;
void APIENTRY glProgramSubroutineParametersuivNV(GLenum target, GLsizei count, const GLuint* params) {
	if (!glProgramSubroutineParametersuivNVproc) return;
	glProgramSubroutineParametersuivNVproc(target, count, params);
}
PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC glGetProgramSubroutineParameteruivNVproc = 0;
void APIENTRY glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint* param) {
	if (!glGetProgramSubroutineParameteruivNVproc) return;
	glGetProgramSubroutineParameteruivNVproc(target, index, param);
}
PFNGLVERTEX2HNVPROC glVertex2hNVproc = 0;
void APIENTRY glVertex2hNV(GLhalfNV x, GLhalfNV y) {
	if (!glVertex2hNVproc) return;
	glVertex2hNVproc(x, y);
}
PFNGLVERTEX2HVNVPROC glVertex2hvNVproc = 0;
void APIENTRY glVertex2hvNV(const GLhalfNV* v) {
	if (!glVertex2hvNVproc) return;
	glVertex2hvNVproc(v);
}
PFNGLVERTEX3HNVPROC glVertex3hNVproc = 0;
void APIENTRY glVertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z) {
	if (!glVertex3hNVproc) return;
	glVertex3hNVproc(x, y, z);
}
PFNGLVERTEX3HVNVPROC glVertex3hvNVproc = 0;
void APIENTRY glVertex3hvNV(const GLhalfNV* v) {
	if (!glVertex3hvNVproc) return;
	glVertex3hvNVproc(v);
}
PFNGLVERTEX4HNVPROC glVertex4hNVproc = 0;
void APIENTRY glVertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
	if (!glVertex4hNVproc) return;
	glVertex4hNVproc(x, y, z, w);
}
PFNGLVERTEX4HVNVPROC glVertex4hvNVproc = 0;
void APIENTRY glVertex4hvNV(const GLhalfNV* v) {
	if (!glVertex4hvNVproc) return;
	glVertex4hvNVproc(v);
}
PFNGLNORMAL3HNVPROC glNormal3hNVproc = 0;
void APIENTRY glNormal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz) {
	if (!glNormal3hNVproc) return;
	glNormal3hNVproc(nx, ny, nz);
}
PFNGLNORMAL3HVNVPROC glNormal3hvNVproc = 0;
void APIENTRY glNormal3hvNV(const GLhalfNV* v) {
	if (!glNormal3hvNVproc) return;
	glNormal3hvNVproc(v);
}
PFNGLCOLOR3HNVPROC glColor3hNVproc = 0;
void APIENTRY glColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
	if (!glColor3hNVproc) return;
	glColor3hNVproc(red, green, blue);
}
PFNGLCOLOR3HVNVPROC glColor3hvNVproc = 0;
void APIENTRY glColor3hvNV(const GLhalfNV* v) {
	if (!glColor3hvNVproc) return;
	glColor3hvNVproc(v);
}
PFNGLCOLOR4HNVPROC glColor4hNVproc = 0;
void APIENTRY glColor4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha) {
	if (!glColor4hNVproc) return;
	glColor4hNVproc(red, green, blue, alpha);
}
PFNGLCOLOR4HVNVPROC glColor4hvNVproc = 0;
void APIENTRY glColor4hvNV(const GLhalfNV* v) {
	if (!glColor4hvNVproc) return;
	glColor4hvNVproc(v);
}
PFNGLTEXCOORD1HNVPROC glTexCoord1hNVproc = 0;
void APIENTRY glTexCoord1hNV(GLhalfNV s) {
	if (!glTexCoord1hNVproc) return;
	glTexCoord1hNVproc(s);
}
PFNGLTEXCOORD1HVNVPROC glTexCoord1hvNVproc = 0;
void APIENTRY glTexCoord1hvNV(const GLhalfNV* v) {
	if (!glTexCoord1hvNVproc) return;
	glTexCoord1hvNVproc(v);
}
PFNGLTEXCOORD2HNVPROC glTexCoord2hNVproc = 0;
void APIENTRY glTexCoord2hNV(GLhalfNV s, GLhalfNV t) {
	if (!glTexCoord2hNVproc) return;
	glTexCoord2hNVproc(s, t);
}
PFNGLTEXCOORD2HVNVPROC glTexCoord2hvNVproc = 0;
void APIENTRY glTexCoord2hvNV(const GLhalfNV* v) {
	if (!glTexCoord2hvNVproc) return;
	glTexCoord2hvNVproc(v);
}
PFNGLTEXCOORD3HNVPROC glTexCoord3hNVproc = 0;
void APIENTRY glTexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r) {
	if (!glTexCoord3hNVproc) return;
	glTexCoord3hNVproc(s, t, r);
}
PFNGLTEXCOORD3HVNVPROC glTexCoord3hvNVproc = 0;
void APIENTRY glTexCoord3hvNV(const GLhalfNV* v) {
	if (!glTexCoord3hvNVproc) return;
	glTexCoord3hvNVproc(v);
}
PFNGLTEXCOORD4HNVPROC glTexCoord4hNVproc = 0;
void APIENTRY glTexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
	if (!glTexCoord4hNVproc) return;
	glTexCoord4hNVproc(s, t, r, q);
}
PFNGLTEXCOORD4HVNVPROC glTexCoord4hvNVproc = 0;
void APIENTRY glTexCoord4hvNV(const GLhalfNV* v) {
	if (!glTexCoord4hvNVproc) return;
	glTexCoord4hvNVproc(v);
}
PFNGLMULTITEXCOORD1HNVPROC glMultiTexCoord1hNVproc = 0;
void APIENTRY glMultiTexCoord1hNV(GLenum target, GLhalfNV s) {
	if (!glMultiTexCoord1hNVproc) return;
	glMultiTexCoord1hNVproc(target, s);
}
PFNGLMULTITEXCOORD1HVNVPROC glMultiTexCoord1hvNVproc = 0;
void APIENTRY glMultiTexCoord1hvNV(GLenum target, const GLhalfNV* v) {
	if (!glMultiTexCoord1hvNVproc) return;
	glMultiTexCoord1hvNVproc(target, v);
}
PFNGLMULTITEXCOORD2HNVPROC glMultiTexCoord2hNVproc = 0;
void APIENTRY glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t) {
	if (!glMultiTexCoord2hNVproc) return;
	glMultiTexCoord2hNVproc(target, s, t);
}
PFNGLMULTITEXCOORD2HVNVPROC glMultiTexCoord2hvNVproc = 0;
void APIENTRY glMultiTexCoord2hvNV(GLenum target, const GLhalfNV* v) {
	if (!glMultiTexCoord2hvNVproc) return;
	glMultiTexCoord2hvNVproc(target, v);
}
PFNGLMULTITEXCOORD3HNVPROC glMultiTexCoord3hNVproc = 0;
void APIENTRY glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r) {
	if (!glMultiTexCoord3hNVproc) return;
	glMultiTexCoord3hNVproc(target, s, t, r);
}
PFNGLMULTITEXCOORD3HVNVPROC glMultiTexCoord3hvNVproc = 0;
void APIENTRY glMultiTexCoord3hvNV(GLenum target, const GLhalfNV* v) {
	if (!glMultiTexCoord3hvNVproc) return;
	glMultiTexCoord3hvNVproc(target, v);
}
PFNGLMULTITEXCOORD4HNVPROC glMultiTexCoord4hNVproc = 0;
void APIENTRY glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
	if (!glMultiTexCoord4hNVproc) return;
	glMultiTexCoord4hNVproc(target, s, t, r, q);
}
PFNGLMULTITEXCOORD4HVNVPROC glMultiTexCoord4hvNVproc = 0;
void APIENTRY glMultiTexCoord4hvNV(GLenum target, const GLhalfNV* v) {
	if (!glMultiTexCoord4hvNVproc) return;
	glMultiTexCoord4hvNVproc(target, v);
}
PFNGLVERTEXATTRIB1HNVPROC glVertexAttrib1hNVproc = 0;
void APIENTRY glVertexAttrib1hNV(GLuint index, GLhalfNV x) {
	if (!glVertexAttrib1hNVproc) return;
	glVertexAttrib1hNVproc(index, x);
}
PFNGLVERTEXATTRIB1HVNVPROC glVertexAttrib1hvNVproc = 0;
void APIENTRY glVertexAttrib1hvNV(GLuint index, const GLhalfNV* v) {
	if (!glVertexAttrib1hvNVproc) return;
	glVertexAttrib1hvNVproc(index, v);
}
PFNGLVERTEXATTRIB2HNVPROC glVertexAttrib2hNVproc = 0;
void APIENTRY glVertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y) {
	if (!glVertexAttrib2hNVproc) return;
	glVertexAttrib2hNVproc(index, x, y);
}
PFNGLVERTEXATTRIB2HVNVPROC glVertexAttrib2hvNVproc = 0;
void APIENTRY glVertexAttrib2hvNV(GLuint index, const GLhalfNV* v) {
	if (!glVertexAttrib2hvNVproc) return;
	glVertexAttrib2hvNVproc(index, v);
}
PFNGLVERTEXATTRIB3HNVPROC glVertexAttrib3hNVproc = 0;
void APIENTRY glVertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z) {
	if (!glVertexAttrib3hNVproc) return;
	glVertexAttrib3hNVproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3HVNVPROC glVertexAttrib3hvNVproc = 0;
void APIENTRY glVertexAttrib3hvNV(GLuint index, const GLhalfNV* v) {
	if (!glVertexAttrib3hvNVproc) return;
	glVertexAttrib3hvNVproc(index, v);
}
PFNGLVERTEXATTRIB4HNVPROC glVertexAttrib4hNVproc = 0;
void APIENTRY glVertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
	if (!glVertexAttrib4hNVproc) return;
	glVertexAttrib4hNVproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4HVNVPROC glVertexAttrib4hvNVproc = 0;
void APIENTRY glVertexAttrib4hvNV(GLuint index, const GLhalfNV* v) {
	if (!glVertexAttrib4hvNVproc) return;
	glVertexAttrib4hvNVproc(index, v);
}
PFNGLVERTEXATTRIBS1HVNVPROC glVertexAttribs1hvNVproc = 0;
void APIENTRY glVertexAttribs1hvNV(GLuint index, GLsizei n, const GLhalfNV* v) {
	if (!glVertexAttribs1hvNVproc) return;
	glVertexAttribs1hvNVproc(index, n, v);
}
PFNGLVERTEXATTRIBS2HVNVPROC glVertexAttribs2hvNVproc = 0;
void APIENTRY glVertexAttribs2hvNV(GLuint index, GLsizei n, const GLhalfNV* v) {
	if (!glVertexAttribs2hvNVproc) return;
	glVertexAttribs2hvNVproc(index, n, v);
}
PFNGLVERTEXATTRIBS3HVNVPROC glVertexAttribs3hvNVproc = 0;
void APIENTRY glVertexAttribs3hvNV(GLuint index, GLsizei n, const GLhalfNV* v) {
	if (!glVertexAttribs3hvNVproc) return;
	glVertexAttribs3hvNVproc(index, n, v);
}
PFNGLVERTEXATTRIBS4HVNVPROC glVertexAttribs4hvNVproc = 0;
void APIENTRY glVertexAttribs4hvNV(GLuint index, GLsizei n, const GLhalfNV* v) {
	if (!glVertexAttribs4hvNVproc) return;
	glVertexAttribs4hvNVproc(index, n, v);
}
PFNGLFOGCOORDHNVPROC glFogCoordhNVproc = 0;
void APIENTRY glFogCoordhNV(GLhalfNV fog) {
	if (!glFogCoordhNVproc) return;
	glFogCoordhNVproc(fog);
}
PFNGLFOGCOORDHVNVPROC glFogCoordhvNVproc = 0;
void APIENTRY glFogCoordhvNV(const GLhalfNV* fog) {
	if (!glFogCoordhvNVproc) return;
	glFogCoordhvNVproc(fog);
}
PFNGLSECONDARYCOLOR3HNVPROC glSecondaryColor3hNVproc = 0;
void APIENTRY glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
	if (!glSecondaryColor3hNVproc) return;
	glSecondaryColor3hNVproc(red, green, blue);
}
PFNGLSECONDARYCOLOR3HVNVPROC glSecondaryColor3hvNVproc = 0;
void APIENTRY glSecondaryColor3hvNV(const GLhalfNV* v) {
	if (!glSecondaryColor3hvNVproc) return;
	glSecondaryColor3hvNVproc(v);
}
PFNGLVERTEXWEIGHTHNVPROC glVertexWeighthNVproc = 0;
void APIENTRY glVertexWeighthNV(GLhalfNV weight) {
	if (!glVertexWeighthNVproc) return;
	glVertexWeighthNVproc(weight);
}
PFNGLVERTEXWEIGHTHVNVPROC glVertexWeighthvNVproc = 0;
void APIENTRY glVertexWeighthvNV(const GLhalfNV* weight) {
	if (!glVertexWeighthvNVproc) return;
	glVertexWeighthvNVproc(weight);
}
PFNGLGETINTERNALFORMATSAMPLEIVNVPROC glGetInternalformatSampleivNVproc = 0;
void APIENTRY glGetInternalformatSampleivNV(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint* params) {
	if (!glGetInternalformatSampleivNVproc) return;
	glGetInternalformatSampleivNVproc(target, internalformat, samples, pname, count, params);
}
PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC glGetMemoryObjectDetachedResourcesuivNVproc = 0;
void APIENTRY glGetMemoryObjectDetachedResourcesuivNV(GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint* params) {
	if (!glGetMemoryObjectDetachedResourcesuivNVproc) return;
	glGetMemoryObjectDetachedResourcesuivNVproc(memory, pname, first, count, params);
}
PFNGLRESETMEMORYOBJECTPARAMETERNVPROC glResetMemoryObjectParameterNVproc = 0;
void APIENTRY glResetMemoryObjectParameterNV(GLuint memory, GLenum pname) {
	if (!glResetMemoryObjectParameterNVproc) return;
	glResetMemoryObjectParameterNVproc(memory, pname);
}
PFNGLTEXATTACHMEMORYNVPROC glTexAttachMemoryNVproc = 0;
void APIENTRY glTexAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset) {
	if (!glTexAttachMemoryNVproc) return;
	glTexAttachMemoryNVproc(target, memory, offset);
}
PFNGLBUFFERATTACHMEMORYNVPROC glBufferAttachMemoryNVproc = 0;
void APIENTRY glBufferAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset) {
	if (!glBufferAttachMemoryNVproc) return;
	glBufferAttachMemoryNVproc(target, memory, offset);
}
PFNGLTEXTUREATTACHMEMORYNVPROC glTextureAttachMemoryNVproc = 0;
void APIENTRY glTextureAttachMemoryNV(GLuint texture, GLuint memory, GLuint64 offset) {
	if (!glTextureAttachMemoryNVproc) return;
	glTextureAttachMemoryNVproc(texture, memory, offset);
}
PFNGLNAMEDBUFFERATTACHMEMORYNVPROC glNamedBufferAttachMemoryNVproc = 0;
void APIENTRY glNamedBufferAttachMemoryNV(GLuint buffer, GLuint memory, GLuint64 offset) {
	if (!glNamedBufferAttachMemoryNVproc) return;
	glNamedBufferAttachMemoryNVproc(buffer, memory, offset);
}
PFNGLBUFFERPAGECOMMITMENTMEMNVPROC glBufferPageCommitmentMemNVproc = 0;
void APIENTRY glBufferPageCommitmentMemNV(GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit) {
	if (!glBufferPageCommitmentMemNVproc) return;
	glBufferPageCommitmentMemNVproc(target, offset, size, memory, memOffset, commit);
}
PFNGLTEXPAGECOMMITMENTMEMNVPROC glTexPageCommitmentMemNVproc = 0;
void APIENTRY glTexPageCommitmentMemNV(GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit) {
	if (!glTexPageCommitmentMemNVproc) return;
	glTexPageCommitmentMemNVproc(target, layer, level, xoffset, yoffset, zoffset, width, height, depth, memory, offset, commit);
}
PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC glNamedBufferPageCommitmentMemNVproc = 0;
void APIENTRY glNamedBufferPageCommitmentMemNV(GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit) {
	if (!glNamedBufferPageCommitmentMemNVproc) return;
	glNamedBufferPageCommitmentMemNVproc(buffer, offset, size, memory, memOffset, commit);
}
PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC glTexturePageCommitmentMemNVproc = 0;
void APIENTRY glTexturePageCommitmentMemNV(GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit) {
	if (!glTexturePageCommitmentMemNVproc) return;
	glTexturePageCommitmentMemNVproc(texture, layer, level, xoffset, yoffset, zoffset, width, height, depth, memory, offset, commit);
}
PFNGLDRAWMESHTASKSNVPROC glDrawMeshTasksNVproc = 0;
void APIENTRY glDrawMeshTasksNV(GLuint first, GLuint count) {
	if (!glDrawMeshTasksNVproc) return;
	glDrawMeshTasksNVproc(first, count);
}
PFNGLDRAWMESHTASKSINDIRECTNVPROC glDrawMeshTasksIndirectNVproc = 0;
void APIENTRY glDrawMeshTasksIndirectNV(GLintptr indirect) {
	if (!glDrawMeshTasksIndirectNVproc) return;
	glDrawMeshTasksIndirectNVproc(indirect);
}
PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC glMultiDrawMeshTasksIndirectNVproc = 0;
void APIENTRY glMultiDrawMeshTasksIndirectNV(GLintptr indirect, GLsizei drawcount, GLsizei stride) {
	if (!glMultiDrawMeshTasksIndirectNVproc) return;
	glMultiDrawMeshTasksIndirectNVproc(indirect, drawcount, stride);
}
PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC glMultiDrawMeshTasksIndirectCountNVproc = 0;
void APIENTRY glMultiDrawMeshTasksIndirectCountNV(GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
	if (!glMultiDrawMeshTasksIndirectCountNVproc) return;
	glMultiDrawMeshTasksIndirectCountNVproc(indirect, drawcount, maxdrawcount, stride);
}
PFNGLGENOCCLUSIONQUERIESNVPROC glGenOcclusionQueriesNVproc = 0;
void APIENTRY glGenOcclusionQueriesNV(GLsizei n, GLuint* ids) {
	if (!glGenOcclusionQueriesNVproc) return;
	glGenOcclusionQueriesNVproc(n, ids);
}
PFNGLDELETEOCCLUSIONQUERIESNVPROC glDeleteOcclusionQueriesNVproc = 0;
void APIENTRY glDeleteOcclusionQueriesNV(GLsizei n, const GLuint* ids) {
	if (!glDeleteOcclusionQueriesNVproc) return;
	glDeleteOcclusionQueriesNVproc(n, ids);
}
PFNGLISOCCLUSIONQUERYNVPROC glIsOcclusionQueryNVproc = 0;
GLboolean APIENTRY glIsOcclusionQueryNV(GLuint id) {
	if (!glIsOcclusionQueryNVproc) return 0;
	return glIsOcclusionQueryNVproc(id);
}
PFNGLBEGINOCCLUSIONQUERYNVPROC glBeginOcclusionQueryNVproc = 0;
void APIENTRY glBeginOcclusionQueryNV(GLuint id) {
	if (!glBeginOcclusionQueryNVproc) return;
	glBeginOcclusionQueryNVproc(id);
}
PFNGLENDOCCLUSIONQUERYNVPROC glEndOcclusionQueryNVproc = 0;
void APIENTRY glEndOcclusionQueryNV(void) {
	if (!glEndOcclusionQueryNVproc) return;
	glEndOcclusionQueryNVproc();
}
PFNGLGETOCCLUSIONQUERYIVNVPROC glGetOcclusionQueryivNVproc = 0;
void APIENTRY glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint* params) {
	if (!glGetOcclusionQueryivNVproc) return;
	glGetOcclusionQueryivNVproc(id, pname, params);
}
PFNGLGETOCCLUSIONQUERYUIVNVPROC glGetOcclusionQueryuivNVproc = 0;
void APIENTRY glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint* params) {
	if (!glGetOcclusionQueryuivNVproc) return;
	glGetOcclusionQueryuivNVproc(id, pname, params);
}
PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC glProgramBufferParametersfvNVproc = 0;
void APIENTRY glProgramBufferParametersfvNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat* params) {
	if (!glProgramBufferParametersfvNVproc) return;
	glProgramBufferParametersfvNVproc(target, bindingIndex, wordIndex, count, params);
}
PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC glProgramBufferParametersIivNVproc = 0;
void APIENTRY glProgramBufferParametersIivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint* params) {
	if (!glProgramBufferParametersIivNVproc) return;
	glProgramBufferParametersIivNVproc(target, bindingIndex, wordIndex, count, params);
}
PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC glProgramBufferParametersIuivNVproc = 0;
void APIENTRY glProgramBufferParametersIuivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint* params) {
	if (!glProgramBufferParametersIuivNVproc) return;
	glProgramBufferParametersIuivNVproc(target, bindingIndex, wordIndex, count, params);
}
PFNGLGENPATHSNVPROC glGenPathsNVproc = 0;
GLuint APIENTRY glGenPathsNV(GLsizei range) {
	if (!glGenPathsNVproc) return 0;
	return glGenPathsNVproc(range);
}
PFNGLDELETEPATHSNVPROC glDeletePathsNVproc = 0;
void APIENTRY glDeletePathsNV(GLuint path, GLsizei range) {
	if (!glDeletePathsNVproc) return;
	glDeletePathsNVproc(path, range);
}
PFNGLISPATHNVPROC glIsPathNVproc = 0;
GLboolean APIENTRY glIsPathNV(GLuint path) {
	if (!glIsPathNVproc) return 0;
	return glIsPathNVproc(path);
}
PFNGLPATHCOMMANDSNVPROC glPathCommandsNVproc = 0;
void APIENTRY glPathCommandsNV(GLuint path, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void* coords) {
	if (!glPathCommandsNVproc) return;
	glPathCommandsNVproc(path, numCommands, commands, numCoords, coordType, coords);
}
PFNGLPATHCOORDSNVPROC glPathCoordsNVproc = 0;
void APIENTRY glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const void* coords) {
	if (!glPathCoordsNVproc) return;
	glPathCoordsNVproc(path, numCoords, coordType, coords);
}
PFNGLPATHSUBCOMMANDSNVPROC glPathSubCommandsNVproc = 0;
void APIENTRY glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void* coords) {
	if (!glPathSubCommandsNVproc) return;
	glPathSubCommandsNVproc(path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords);
}
PFNGLPATHSUBCOORDSNVPROC glPathSubCoordsNVproc = 0;
void APIENTRY glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void* coords) {
	if (!glPathSubCoordsNVproc) return;
	glPathSubCoordsNVproc(path, coordStart, numCoords, coordType, coords);
}
PFNGLPATHSTRINGNVPROC glPathStringNVproc = 0;
void APIENTRY glPathStringNV(GLuint path, GLenum format, GLsizei length, const void* pathString) {
	if (!glPathStringNVproc) return;
	glPathStringNVproc(path, format, length, pathString);
}
PFNGLPATHGLYPHSNVPROC glPathGlyphsNVproc = 0;
void APIENTRY glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void* charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
	if (!glPathGlyphsNVproc) return;
	glPathGlyphsNVproc(firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale);
}
PFNGLPATHGLYPHRANGENVPROC glPathGlyphRangeNVproc = 0;
void APIENTRY glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
	if (!glPathGlyphRangeNVproc) return;
	glPathGlyphRangeNVproc(firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale);
}
PFNGLWEIGHTPATHSNVPROC glWeightPathsNVproc = 0;
void APIENTRY glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights) {
	if (!glWeightPathsNVproc) return;
	glWeightPathsNVproc(resultPath, numPaths, paths, weights);
}
PFNGLCOPYPATHNVPROC glCopyPathNVproc = 0;
void APIENTRY glCopyPathNV(GLuint resultPath, GLuint srcPath) {
	if (!glCopyPathNVproc) return;
	glCopyPathNVproc(resultPath, srcPath);
}
PFNGLINTERPOLATEPATHSNVPROC glInterpolatePathsNVproc = 0;
void APIENTRY glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight) {
	if (!glInterpolatePathsNVproc) return;
	glInterpolatePathsNVproc(resultPath, pathA, pathB, weight);
}
PFNGLTRANSFORMPATHNVPROC glTransformPathNVproc = 0;
void APIENTRY glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues) {
	if (!glTransformPathNVproc) return;
	glTransformPathNVproc(resultPath, srcPath, transformType, transformValues);
}
PFNGLPATHPARAMETERIVNVPROC glPathParameterivNVproc = 0;
void APIENTRY glPathParameterivNV(GLuint path, GLenum pname, const GLint* value) {
	if (!glPathParameterivNVproc) return;
	glPathParameterivNVproc(path, pname, value);
}
PFNGLPATHPARAMETERINVPROC glPathParameteriNVproc = 0;
void APIENTRY glPathParameteriNV(GLuint path, GLenum pname, GLint value) {
	if (!glPathParameteriNVproc) return;
	glPathParameteriNVproc(path, pname, value);
}
PFNGLPATHPARAMETERFVNVPROC glPathParameterfvNVproc = 0;
void APIENTRY glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat* value) {
	if (!glPathParameterfvNVproc) return;
	glPathParameterfvNVproc(path, pname, value);
}
PFNGLPATHPARAMETERFNVPROC glPathParameterfNVproc = 0;
void APIENTRY glPathParameterfNV(GLuint path, GLenum pname, GLfloat value) {
	if (!glPathParameterfNVproc) return;
	glPathParameterfNVproc(path, pname, value);
}
PFNGLPATHDASHARRAYNVPROC glPathDashArrayNVproc = 0;
void APIENTRY glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat* dashArray) {
	if (!glPathDashArrayNVproc) return;
	glPathDashArrayNVproc(path, dashCount, dashArray);
}
PFNGLPATHSTENCILFUNCNVPROC glPathStencilFuncNVproc = 0;
void APIENTRY glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask) {
	if (!glPathStencilFuncNVproc) return;
	glPathStencilFuncNVproc(func, ref, mask);
}
PFNGLPATHSTENCILDEPTHOFFSETNVPROC glPathStencilDepthOffsetNVproc = 0;
void APIENTRY glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units) {
	if (!glPathStencilDepthOffsetNVproc) return;
	glPathStencilDepthOffsetNVproc(factor, units);
}
PFNGLSTENCILFILLPATHNVPROC glStencilFillPathNVproc = 0;
void APIENTRY glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask) {
	if (!glStencilFillPathNVproc) return;
	glStencilFillPathNVproc(path, fillMode, mask);
}
PFNGLSTENCILSTROKEPATHNVPROC glStencilStrokePathNVproc = 0;
void APIENTRY glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask) {
	if (!glStencilStrokePathNVproc) return;
	glStencilStrokePathNVproc(path, reference, mask);
}
PFNGLSTENCILFILLPATHINSTANCEDNVPROC glStencilFillPathInstancedNVproc = 0;
void APIENTRY glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat* transformValues) {
	if (!glStencilFillPathInstancedNVproc) return;
	glStencilFillPathInstancedNVproc(numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues);
}
PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC glStencilStrokePathInstancedNVproc = 0;
void APIENTRY glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat* transformValues) {
	if (!glStencilStrokePathInstancedNVproc) return;
	glStencilStrokePathInstancedNVproc(numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues);
}
PFNGLPATHCOVERDEPTHFUNCNVPROC glPathCoverDepthFuncNVproc = 0;
void APIENTRY glPathCoverDepthFuncNV(GLenum func) {
	if (!glPathCoverDepthFuncNVproc) return;
	glPathCoverDepthFuncNVproc(func);
}
PFNGLCOVERFILLPATHNVPROC glCoverFillPathNVproc = 0;
void APIENTRY glCoverFillPathNV(GLuint path, GLenum coverMode) {
	if (!glCoverFillPathNVproc) return;
	glCoverFillPathNVproc(path, coverMode);
}
PFNGLCOVERSTROKEPATHNVPROC glCoverStrokePathNVproc = 0;
void APIENTRY glCoverStrokePathNV(GLuint path, GLenum coverMode) {
	if (!glCoverStrokePathNVproc) return;
	glCoverStrokePathNVproc(path, coverMode);
}
PFNGLCOVERFILLPATHINSTANCEDNVPROC glCoverFillPathInstancedNVproc = 0;
void APIENTRY glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues) {
	if (!glCoverFillPathInstancedNVproc) return;
	glCoverFillPathInstancedNVproc(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}
PFNGLCOVERSTROKEPATHINSTANCEDNVPROC glCoverStrokePathInstancedNVproc = 0;
void APIENTRY glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues) {
	if (!glCoverStrokePathInstancedNVproc) return;
	glCoverStrokePathInstancedNVproc(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}
PFNGLGETPATHPARAMETERIVNVPROC glGetPathParameterivNVproc = 0;
void APIENTRY glGetPathParameterivNV(GLuint path, GLenum pname, GLint* value) {
	if (!glGetPathParameterivNVproc) return;
	glGetPathParameterivNVproc(path, pname, value);
}
PFNGLGETPATHPARAMETERFVNVPROC glGetPathParameterfvNVproc = 0;
void APIENTRY glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat* value) {
	if (!glGetPathParameterfvNVproc) return;
	glGetPathParameterfvNVproc(path, pname, value);
}
PFNGLGETPATHCOMMANDSNVPROC glGetPathCommandsNVproc = 0;
void APIENTRY glGetPathCommandsNV(GLuint path, GLubyte* commands) {
	if (!glGetPathCommandsNVproc) return;
	glGetPathCommandsNVproc(path, commands);
}
PFNGLGETPATHCOORDSNVPROC glGetPathCoordsNVproc = 0;
void APIENTRY glGetPathCoordsNV(GLuint path, GLfloat* coords) {
	if (!glGetPathCoordsNVproc) return;
	glGetPathCoordsNVproc(path, coords);
}
PFNGLGETPATHDASHARRAYNVPROC glGetPathDashArrayNVproc = 0;
void APIENTRY glGetPathDashArrayNV(GLuint path, GLfloat* dashArray) {
	if (!glGetPathDashArrayNVproc) return;
	glGetPathDashArrayNVproc(path, dashArray);
}
PFNGLGETPATHMETRICSNVPROC glGetPathMetricsNVproc = 0;
void APIENTRY glGetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLsizei stride, GLfloat* metrics) {
	if (!glGetPathMetricsNVproc) return;
	glGetPathMetricsNVproc(metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics);
}
PFNGLGETPATHMETRICRANGENVPROC glGetPathMetricRangeNVproc = 0;
void APIENTRY glGetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat* metrics) {
	if (!glGetPathMetricRangeNVproc) return;
	glGetPathMetricRangeNVproc(metricQueryMask, firstPathName, numPaths, stride, metrics);
}
PFNGLGETPATHSPACINGNVPROC glGetPathSpacingNVproc = 0;
void APIENTRY glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat* returnedSpacing) {
	if (!glGetPathSpacingNVproc) return;
	glGetPathSpacingNVproc(pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing);
}
PFNGLISPOINTINFILLPATHNVPROC glIsPointInFillPathNVproc = 0;
GLboolean APIENTRY glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y) {
	if (!glIsPointInFillPathNVproc) return 0;
	return glIsPointInFillPathNVproc(path, mask, x, y);
}
PFNGLISPOINTINSTROKEPATHNVPROC glIsPointInStrokePathNVproc = 0;
GLboolean APIENTRY glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y) {
	if (!glIsPointInStrokePathNVproc) return 0;
	return glIsPointInStrokePathNVproc(path, x, y);
}
PFNGLGETPATHLENGTHNVPROC glGetPathLengthNVproc = 0;
GLfloat APIENTRY glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments) {
	if (!glGetPathLengthNVproc) return 0;
	return glGetPathLengthNVproc(path, startSegment, numSegments);
}
PFNGLPOINTALONGPATHNVPROC glPointAlongPathNVproc = 0;
GLboolean APIENTRY glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat* x, GLfloat* y, GLfloat* tangentX, GLfloat* tangentY) {
	if (!glPointAlongPathNVproc) return 0;
	return glPointAlongPathNVproc(path, startSegment, numSegments, distance, x, y, tangentX, tangentY);
}
PFNGLMATRIXLOAD3X2FNVPROC glMatrixLoad3x2fNVproc = 0;
void APIENTRY glMatrixLoad3x2fNV(GLenum matrixMode, const GLfloat* m) {
	if (!glMatrixLoad3x2fNVproc) return;
	glMatrixLoad3x2fNVproc(matrixMode, m);
}
PFNGLMATRIXLOAD3X3FNVPROC glMatrixLoad3x3fNVproc = 0;
void APIENTRY glMatrixLoad3x3fNV(GLenum matrixMode, const GLfloat* m) {
	if (!glMatrixLoad3x3fNVproc) return;
	glMatrixLoad3x3fNVproc(matrixMode, m);
}
PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC glMatrixLoadTranspose3x3fNVproc = 0;
void APIENTRY glMatrixLoadTranspose3x3fNV(GLenum matrixMode, const GLfloat* m) {
	if (!glMatrixLoadTranspose3x3fNVproc) return;
	glMatrixLoadTranspose3x3fNVproc(matrixMode, m);
}
PFNGLMATRIXMULT3X2FNVPROC glMatrixMult3x2fNVproc = 0;
void APIENTRY glMatrixMult3x2fNV(GLenum matrixMode, const GLfloat* m) {
	if (!glMatrixMult3x2fNVproc) return;
	glMatrixMult3x2fNVproc(matrixMode, m);
}
PFNGLMATRIXMULT3X3FNVPROC glMatrixMult3x3fNVproc = 0;
void APIENTRY glMatrixMult3x3fNV(GLenum matrixMode, const GLfloat* m) {
	if (!glMatrixMult3x3fNVproc) return;
	glMatrixMult3x3fNVproc(matrixMode, m);
}
PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC glMatrixMultTranspose3x3fNVproc = 0;
void APIENTRY glMatrixMultTranspose3x3fNV(GLenum matrixMode, const GLfloat* m) {
	if (!glMatrixMultTranspose3x3fNVproc) return;
	glMatrixMultTranspose3x3fNVproc(matrixMode, m);
}
PFNGLSTENCILTHENCOVERFILLPATHNVPROC glStencilThenCoverFillPathNVproc = 0;
void APIENTRY glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode) {
	if (!glStencilThenCoverFillPathNVproc) return;
	glStencilThenCoverFillPathNVproc(path, fillMode, mask, coverMode);
}
PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC glStencilThenCoverStrokePathNVproc = 0;
void APIENTRY glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode) {
	if (!glStencilThenCoverStrokePathNVproc) return;
	glStencilThenCoverStrokePathNVproc(path, reference, mask, coverMode);
}
PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC glStencilThenCoverFillPathInstancedNVproc = 0;
void APIENTRY glStencilThenCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues) {
	if (!glStencilThenCoverFillPathInstancedNVproc) return;
	glStencilThenCoverFillPathInstancedNVproc(numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues);
}
PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC glStencilThenCoverStrokePathInstancedNVproc = 0;
void APIENTRY glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues) {
	if (!glStencilThenCoverStrokePathInstancedNVproc) return;
	glStencilThenCoverStrokePathInstancedNVproc(numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues);
}
PFNGLPATHGLYPHINDEXRANGENVPROC glPathGlyphIndexRangeNVproc = 0;
GLenum APIENTRY glPathGlyphIndexRangeNV(GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint* baseAndCount) {
	if (!glPathGlyphIndexRangeNVproc) return 0;
	return glPathGlyphIndexRangeNVproc(fontTarget, fontName, fontStyle, pathParameterTemplate, emScale, baseAndCount);
}
PFNGLPATHGLYPHINDEXARRAYNVPROC glPathGlyphIndexArrayNVproc = 0;
GLenum APIENTRY glPathGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
	if (!glPathGlyphIndexArrayNVproc) return 0;
	return glPathGlyphIndexArrayNVproc(firstPathName, fontTarget, fontName, fontStyle, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}
PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC glPathMemoryGlyphIndexArrayNVproc = 0;
GLenum APIENTRY glPathMemoryGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void* fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
	if (!glPathMemoryGlyphIndexArrayNVproc) return 0;
	return glPathMemoryGlyphIndexArrayNVproc(firstPathName, fontTarget, fontSize, fontData, faceIndex, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}
PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC glProgramPathFragmentInputGenNVproc = 0;
void APIENTRY glProgramPathFragmentInputGenNV(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat* coeffs) {
	if (!glProgramPathFragmentInputGenNVproc) return;
	glProgramPathFragmentInputGenNVproc(program, location, genMode, components, coeffs);
}
PFNGLGETPROGRAMRESOURCEFVNVPROC glGetProgramResourcefvNVproc = 0;
void APIENTRY glGetProgramResourcefvNV(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLfloat* params) {
	if (!glGetProgramResourcefvNVproc) return;
	glGetProgramResourcefvNVproc(program, programInterface, index, propCount, props, count, length, params);
}
PFNGLPATHCOLORGENNVPROC glPathColorGenNVproc = 0;
void APIENTRY glPathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat* coeffs) {
	if (!glPathColorGenNVproc) return;
	glPathColorGenNVproc(color, genMode, colorFormat, coeffs);
}
PFNGLPATHTEXGENNVPROC glPathTexGenNVproc = 0;
void APIENTRY glPathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat* coeffs) {
	if (!glPathTexGenNVproc) return;
	glPathTexGenNVproc(texCoordSet, genMode, components, coeffs);
}
PFNGLPATHFOGGENNVPROC glPathFogGenNVproc = 0;
void APIENTRY glPathFogGenNV(GLenum genMode) {
	if (!glPathFogGenNVproc) return;
	glPathFogGenNVproc(genMode);
}
PFNGLGETPATHCOLORGENIVNVPROC glGetPathColorGenivNVproc = 0;
void APIENTRY glGetPathColorGenivNV(GLenum color, GLenum pname, GLint* value) {
	if (!glGetPathColorGenivNVproc) return;
	glGetPathColorGenivNVproc(color, pname, value);
}
PFNGLGETPATHCOLORGENFVNVPROC glGetPathColorGenfvNVproc = 0;
void APIENTRY glGetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat* value) {
	if (!glGetPathColorGenfvNVproc) return;
	glGetPathColorGenfvNVproc(color, pname, value);
}
PFNGLGETPATHTEXGENIVNVPROC glGetPathTexGenivNVproc = 0;
void APIENTRY glGetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint* value) {
	if (!glGetPathTexGenivNVproc) return;
	glGetPathTexGenivNVproc(texCoordSet, pname, value);
}
PFNGLGETPATHTEXGENFVNVPROC glGetPathTexGenfvNVproc = 0;
void APIENTRY glGetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat* value) {
	if (!glGetPathTexGenfvNVproc) return;
	glGetPathTexGenfvNVproc(texCoordSet, pname, value);
}
PFNGLPIXELDATARANGENVPROC glPixelDataRangeNVproc = 0;
void APIENTRY glPixelDataRangeNV(GLenum target, GLsizei length, const void* pointer) {
	if (!glPixelDataRangeNVproc) return;
	glPixelDataRangeNVproc(target, length, pointer);
}
PFNGLFLUSHPIXELDATARANGENVPROC glFlushPixelDataRangeNVproc = 0;
void APIENTRY glFlushPixelDataRangeNV(GLenum target) {
	if (!glFlushPixelDataRangeNVproc) return;
	glFlushPixelDataRangeNVproc(target);
}
PFNGLPOINTPARAMETERINVPROC glPointParameteriNVproc = 0;
void APIENTRY glPointParameteriNV(GLenum pname, GLint param) {
	if (!glPointParameteriNVproc) return;
	glPointParameteriNVproc(pname, param);
}
PFNGLPOINTPARAMETERIVNVPROC glPointParameterivNVproc = 0;
void APIENTRY glPointParameterivNV(GLenum pname, const GLint* params) {
	if (!glPointParameterivNVproc) return;
	glPointParameterivNVproc(pname, params);
}
PFNGLPRESENTFRAMEKEYEDNVPROC glPresentFrameKeyedNVproc = 0;
void APIENTRY glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1) {
	if (!glPresentFrameKeyedNVproc) return;
	glPresentFrameKeyedNVproc(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, key0, target1, fill1, key1);
}
PFNGLPRESENTFRAMEDUALFILLNVPROC glPresentFrameDualFillNVproc = 0;
void APIENTRY glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3) {
	if (!glPresentFrameDualFillNVproc) return;
	glPresentFrameDualFillNVproc(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, target1, fill1, target2, fill2, target3, fill3);
}
PFNGLGETVIDEOIVNVPROC glGetVideoivNVproc = 0;
void APIENTRY glGetVideoivNV(GLuint video_slot, GLenum pname, GLint* params) {
	if (!glGetVideoivNVproc) return;
	glGetVideoivNVproc(video_slot, pname, params);
}
PFNGLGETVIDEOUIVNVPROC glGetVideouivNVproc = 0;
void APIENTRY glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint* params) {
	if (!glGetVideouivNVproc) return;
	glGetVideouivNVproc(video_slot, pname, params);
}
PFNGLGETVIDEOI64VNVPROC glGetVideoi64vNVproc = 0;
void APIENTRY glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT* params) {
	if (!glGetVideoi64vNVproc) return;
	glGetVideoi64vNVproc(video_slot, pname, params);
}
PFNGLGETVIDEOUI64VNVPROC glGetVideoui64vNVproc = 0;
void APIENTRY glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT* params) {
	if (!glGetVideoui64vNVproc) return;
	glGetVideoui64vNVproc(video_slot, pname, params);
}
PFNGLPRIMITIVERESTARTNVPROC glPrimitiveRestartNVproc = 0;
void APIENTRY glPrimitiveRestartNV(void) {
	if (!glPrimitiveRestartNVproc) return;
	glPrimitiveRestartNVproc();
}
PFNGLPRIMITIVERESTARTINDEXNVPROC glPrimitiveRestartIndexNVproc = 0;
void APIENTRY glPrimitiveRestartIndexNV(GLuint index) {
	if (!glPrimitiveRestartIndexNVproc) return;
	glPrimitiveRestartIndexNVproc(index);
}
PFNGLQUERYRESOURCENVPROC glQueryResourceNVproc = 0;
GLint APIENTRY glQueryResourceNV(GLenum queryType, GLint tagId, GLuint count, GLint* buffer) {
	if (!glQueryResourceNVproc) return 0;
	return glQueryResourceNVproc(queryType, tagId, count, buffer);
}
PFNGLGENQUERYRESOURCETAGNVPROC glGenQueryResourceTagNVproc = 0;
void APIENTRY glGenQueryResourceTagNV(GLsizei n, GLint* tagIds) {
	if (!glGenQueryResourceTagNVproc) return;
	glGenQueryResourceTagNVproc(n, tagIds);
}
PFNGLDELETEQUERYRESOURCETAGNVPROC glDeleteQueryResourceTagNVproc = 0;
void APIENTRY glDeleteQueryResourceTagNV(GLsizei n, const GLint* tagIds) {
	if (!glDeleteQueryResourceTagNVproc) return;
	glDeleteQueryResourceTagNVproc(n, tagIds);
}
PFNGLQUERYRESOURCETAGNVPROC glQueryResourceTagNVproc = 0;
void APIENTRY glQueryResourceTagNV(GLint tagId, const GLchar* tagString) {
	if (!glQueryResourceTagNVproc) return;
	glQueryResourceTagNVproc(tagId, tagString);
}
PFNGLCOMBINERPARAMETERFVNVPROC glCombinerParameterfvNVproc = 0;
void APIENTRY glCombinerParameterfvNV(GLenum pname, const GLfloat* params) {
	if (!glCombinerParameterfvNVproc) return;
	glCombinerParameterfvNVproc(pname, params);
}
PFNGLCOMBINERPARAMETERFNVPROC glCombinerParameterfNVproc = 0;
void APIENTRY glCombinerParameterfNV(GLenum pname, GLfloat param) {
	if (!glCombinerParameterfNVproc) return;
	glCombinerParameterfNVproc(pname, param);
}
PFNGLCOMBINERPARAMETERIVNVPROC glCombinerParameterivNVproc = 0;
void APIENTRY glCombinerParameterivNV(GLenum pname, const GLint* params) {
	if (!glCombinerParameterivNVproc) return;
	glCombinerParameterivNVproc(pname, params);
}
PFNGLCOMBINERPARAMETERINVPROC glCombinerParameteriNVproc = 0;
void APIENTRY glCombinerParameteriNV(GLenum pname, GLint param) {
	if (!glCombinerParameteriNVproc) return;
	glCombinerParameteriNVproc(pname, param);
}
PFNGLCOMBINERINPUTNVPROC glCombinerInputNVproc = 0;
void APIENTRY glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
	if (!glCombinerInputNVproc) return;
	glCombinerInputNVproc(stage, portion, variable, input, mapping, componentUsage);
}
PFNGLCOMBINEROUTPUTNVPROC glCombinerOutputNVproc = 0;
void APIENTRY glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum) {
	if (!glCombinerOutputNVproc) return;
	glCombinerOutputNVproc(stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum);
}
PFNGLFINALCOMBINERINPUTNVPROC glFinalCombinerInputNVproc = 0;
void APIENTRY glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
	if (!glFinalCombinerInputNVproc) return;
	glFinalCombinerInputNVproc(variable, input, mapping, componentUsage);
}
PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glGetCombinerInputParameterfvNVproc = 0;
void APIENTRY glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params) {
	if (!glGetCombinerInputParameterfvNVproc) return;
	glGetCombinerInputParameterfvNVproc(stage, portion, variable, pname, params);
}
PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glGetCombinerInputParameterivNVproc = 0;
void APIENTRY glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params) {
	if (!glGetCombinerInputParameterivNVproc) return;
	glGetCombinerInputParameterivNVproc(stage, portion, variable, pname, params);
}
PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glGetCombinerOutputParameterfvNVproc = 0;
void APIENTRY glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat* params) {
	if (!glGetCombinerOutputParameterfvNVproc) return;
	glGetCombinerOutputParameterfvNVproc(stage, portion, pname, params);
}
PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glGetCombinerOutputParameterivNVproc = 0;
void APIENTRY glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint* params) {
	if (!glGetCombinerOutputParameterivNVproc) return;
	glGetCombinerOutputParameterivNVproc(stage, portion, pname, params);
}
PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glGetFinalCombinerInputParameterfvNVproc = 0;
void APIENTRY glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat* params) {
	if (!glGetFinalCombinerInputParameterfvNVproc) return;
	glGetFinalCombinerInputParameterfvNVproc(variable, pname, params);
}
PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glGetFinalCombinerInputParameterivNVproc = 0;
void APIENTRY glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint* params) {
	if (!glGetFinalCombinerInputParameterivNVproc) return;
	glGetFinalCombinerInputParameterivNVproc(variable, pname, params);
}
PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glCombinerStageParameterfvNVproc = 0;
void APIENTRY glCombinerStageParameterfvNV(GLenum stage, GLenum pname, const GLfloat* params) {
	if (!glCombinerStageParameterfvNVproc) return;
	glCombinerStageParameterfvNVproc(stage, pname, params);
}
PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glGetCombinerStageParameterfvNVproc = 0;
void APIENTRY glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat* params) {
	if (!glGetCombinerStageParameterfvNVproc) return;
	glGetCombinerStageParameterfvNVproc(stage, pname, params);
}
PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC glFramebufferSampleLocationsfvNVproc = 0;
void APIENTRY glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat* v) {
	if (!glFramebufferSampleLocationsfvNVproc) return;
	glFramebufferSampleLocationsfvNVproc(target, start, count, v);
}
PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC glNamedFramebufferSampleLocationsfvNVproc = 0;
void APIENTRY glNamedFramebufferSampleLocationsfvNV(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v) {
	if (!glNamedFramebufferSampleLocationsfvNVproc) return;
	glNamedFramebufferSampleLocationsfvNVproc(framebuffer, start, count, v);
}
PFNGLRESOLVEDEPTHVALUESNVPROC glResolveDepthValuesNVproc = 0;
void APIENTRY glResolveDepthValuesNV(void) {
	if (!glResolveDepthValuesNVproc) return;
	glResolveDepthValuesNVproc();
}
PFNGLSCISSOREXCLUSIVENVPROC glScissorExclusiveNVproc = 0;
void APIENTRY glScissorExclusiveNV(GLint x, GLint y, GLsizei width, GLsizei height) {
	if (!glScissorExclusiveNVproc) return;
	glScissorExclusiveNVproc(x, y, width, height);
}
PFNGLSCISSOREXCLUSIVEARRAYVNVPROC glScissorExclusiveArrayvNVproc = 0;
void APIENTRY glScissorExclusiveArrayvNV(GLuint first, GLsizei count, const GLint* v) {
	if (!glScissorExclusiveArrayvNVproc) return;
	glScissorExclusiveArrayvNVproc(first, count, v);
}
PFNGLMAKEBUFFERRESIDENTNVPROC glMakeBufferResidentNVproc = 0;
void APIENTRY glMakeBufferResidentNV(GLenum target, GLenum access) {
	if (!glMakeBufferResidentNVproc) return;
	glMakeBufferResidentNVproc(target, access);
}
PFNGLMAKEBUFFERNONRESIDENTNVPROC glMakeBufferNonResidentNVproc = 0;
void APIENTRY glMakeBufferNonResidentNV(GLenum target) {
	if (!glMakeBufferNonResidentNVproc) return;
	glMakeBufferNonResidentNVproc(target);
}
PFNGLISBUFFERRESIDENTNVPROC glIsBufferResidentNVproc = 0;
GLboolean APIENTRY glIsBufferResidentNV(GLenum target) {
	if (!glIsBufferResidentNVproc) return 0;
	return glIsBufferResidentNVproc(target);
}
PFNGLMAKENAMEDBUFFERRESIDENTNVPROC glMakeNamedBufferResidentNVproc = 0;
void APIENTRY glMakeNamedBufferResidentNV(GLuint buffer, GLenum access) {
	if (!glMakeNamedBufferResidentNVproc) return;
	glMakeNamedBufferResidentNVproc(buffer, access);
}
PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC glMakeNamedBufferNonResidentNVproc = 0;
void APIENTRY glMakeNamedBufferNonResidentNV(GLuint buffer) {
	if (!glMakeNamedBufferNonResidentNVproc) return;
	glMakeNamedBufferNonResidentNVproc(buffer);
}
PFNGLISNAMEDBUFFERRESIDENTNVPROC glIsNamedBufferResidentNVproc = 0;
GLboolean APIENTRY glIsNamedBufferResidentNV(GLuint buffer) {
	if (!glIsNamedBufferResidentNVproc) return 0;
	return glIsNamedBufferResidentNVproc(buffer);
}
PFNGLGETBUFFERPARAMETERUI64VNVPROC glGetBufferParameterui64vNVproc = 0;
void APIENTRY glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT* params) {
	if (!glGetBufferParameterui64vNVproc) return;
	glGetBufferParameterui64vNVproc(target, pname, params);
}
PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC glGetNamedBufferParameterui64vNVproc = 0;
void APIENTRY glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT* params) {
	if (!glGetNamedBufferParameterui64vNVproc) return;
	glGetNamedBufferParameterui64vNVproc(buffer, pname, params);
}
PFNGLGETINTEGERUI64VNVPROC glGetIntegerui64vNVproc = 0;
void APIENTRY glGetIntegerui64vNV(GLenum value, GLuint64EXT* result) {
	if (!glGetIntegerui64vNVproc) return;
	glGetIntegerui64vNVproc(value, result);
}
PFNGLUNIFORMUI64NVPROC glUniformui64NVproc = 0;
void APIENTRY glUniformui64NV(GLint location, GLuint64EXT value) {
	if (!glUniformui64NVproc) return;
	glUniformui64NVproc(location, value);
}
PFNGLUNIFORMUI64VNVPROC glUniformui64vNVproc = 0;
void APIENTRY glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glUniformui64vNVproc) return;
	glUniformui64vNVproc(location, count, value);
}
PFNGLPROGRAMUNIFORMUI64NVPROC glProgramUniformui64NVproc = 0;
void APIENTRY glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value) {
	if (!glProgramUniformui64NVproc) return;
	glProgramUniformui64NVproc(program, location, value);
}
PFNGLPROGRAMUNIFORMUI64VNVPROC glProgramUniformui64vNVproc = 0;
void APIENTRY glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value) {
	if (!glProgramUniformui64vNVproc) return;
	glProgramUniformui64vNVproc(program, location, count, value);
}
PFNGLBINDSHADINGRATEIMAGENVPROC glBindShadingRateImageNVproc = 0;
void APIENTRY glBindShadingRateImageNV(GLuint texture) {
	if (!glBindShadingRateImageNVproc) return;
	glBindShadingRateImageNVproc(texture);
}
PFNGLGETSHADINGRATEIMAGEPALETTENVPROC glGetShadingRateImagePaletteNVproc = 0;
void APIENTRY glGetShadingRateImagePaletteNV(GLuint viewport, GLuint entry, GLenum* rate) {
	if (!glGetShadingRateImagePaletteNVproc) return;
	glGetShadingRateImagePaletteNVproc(viewport, entry, rate);
}
PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC glGetShadingRateSampleLocationivNVproc = 0;
void APIENTRY glGetShadingRateSampleLocationivNV(GLenum rate, GLuint samples, GLuint index, GLint* location) {
	if (!glGetShadingRateSampleLocationivNVproc) return;
	glGetShadingRateSampleLocationivNVproc(rate, samples, index, location);
}
PFNGLSHADINGRATEIMAGEBARRIERNVPROC glShadingRateImageBarrierNVproc = 0;
void APIENTRY glShadingRateImageBarrierNV(GLboolean synchronize) {
	if (!glShadingRateImageBarrierNVproc) return;
	glShadingRateImageBarrierNVproc(synchronize);
}
PFNGLSHADINGRATEIMAGEPALETTENVPROC glShadingRateImagePaletteNVproc = 0;
void APIENTRY glShadingRateImagePaletteNV(GLuint viewport, GLuint first, GLsizei count, const GLenum* rates) {
	if (!glShadingRateImagePaletteNVproc) return;
	glShadingRateImagePaletteNVproc(viewport, first, count, rates);
}
PFNGLSHADINGRATESAMPLEORDERNVPROC glShadingRateSampleOrderNVproc = 0;
void APIENTRY glShadingRateSampleOrderNV(GLenum order) {
	if (!glShadingRateSampleOrderNVproc) return;
	glShadingRateSampleOrderNVproc(order);
}
PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC glShadingRateSampleOrderCustomNVproc = 0;
void APIENTRY glShadingRateSampleOrderCustomNV(GLenum rate, GLuint samples, const GLint* locations) {
	if (!glShadingRateSampleOrderCustomNVproc) return;
	glShadingRateSampleOrderCustomNVproc(rate, samples, locations);
}
PFNGLTEXTUREBARRIERNVPROC glTextureBarrierNVproc = 0;
void APIENTRY glTextureBarrierNV(void) {
	if (!glTextureBarrierNVproc) return;
	glTextureBarrierNVproc();
}
PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC glTexImage2DMultisampleCoverageNVproc = 0;
void APIENTRY glTexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
	if (!glTexImage2DMultisampleCoverageNVproc) return;
	glTexImage2DMultisampleCoverageNVproc(target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations);
}
PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC glTexImage3DMultisampleCoverageNVproc = 0;
void APIENTRY glTexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
	if (!glTexImage3DMultisampleCoverageNVproc) return;
	glTexImage3DMultisampleCoverageNVproc(target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations);
}
PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC glTextureImage2DMultisampleNVproc = 0;
void APIENTRY glTextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
	if (!glTextureImage2DMultisampleNVproc) return;
	glTextureImage2DMultisampleNVproc(texture, target, samples, internalFormat, width, height, fixedSampleLocations);
}
PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC glTextureImage3DMultisampleNVproc = 0;
void APIENTRY glTextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
	if (!glTextureImage3DMultisampleNVproc) return;
	glTextureImage3DMultisampleNVproc(texture, target, samples, internalFormat, width, height, depth, fixedSampleLocations);
}
PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC glTextureImage2DMultisampleCoverageNVproc = 0;
void APIENTRY glTextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
	if (!glTextureImage2DMultisampleCoverageNVproc) return;
	glTextureImage2DMultisampleCoverageNVproc(texture, target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations);
}
PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC glTextureImage3DMultisampleCoverageNVproc = 0;
void APIENTRY glTextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
	if (!glTextureImage3DMultisampleCoverageNVproc) return;
	glTextureImage3DMultisampleCoverageNVproc(texture, target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations);
}
PFNGLCREATESEMAPHORESNVPROC glCreateSemaphoresNVproc = 0;
void APIENTRY glCreateSemaphoresNV(GLsizei n, GLuint* semaphores) {
	if (!glCreateSemaphoresNVproc) return;
	glCreateSemaphoresNVproc(n, semaphores);
}
PFNGLSEMAPHOREPARAMETERIVNVPROC glSemaphoreParameterivNVproc = 0;
void APIENTRY glSemaphoreParameterivNV(GLuint semaphore, GLenum pname, const GLint* params) {
	if (!glSemaphoreParameterivNVproc) return;
	glSemaphoreParameterivNVproc(semaphore, pname, params);
}
PFNGLGETSEMAPHOREPARAMETERIVNVPROC glGetSemaphoreParameterivNVproc = 0;
void APIENTRY glGetSemaphoreParameterivNV(GLuint semaphore, GLenum pname, GLint* params) {
	if (!glGetSemaphoreParameterivNVproc) return;
	glGetSemaphoreParameterivNVproc(semaphore, pname, params);
}
PFNGLBEGINTRANSFORMFEEDBACKNVPROC glBeginTransformFeedbackNVproc = 0;
void APIENTRY glBeginTransformFeedbackNV(GLenum primitiveMode) {
	if (!glBeginTransformFeedbackNVproc) return;
	glBeginTransformFeedbackNVproc(primitiveMode);
}
PFNGLENDTRANSFORMFEEDBACKNVPROC glEndTransformFeedbackNVproc = 0;
void APIENTRY glEndTransformFeedbackNV(void) {
	if (!glEndTransformFeedbackNVproc) return;
	glEndTransformFeedbackNVproc();
}
PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC glTransformFeedbackAttribsNVproc = 0;
void APIENTRY glTransformFeedbackAttribsNV(GLsizei count, const GLint* attribs, GLenum bufferMode) {
	if (!glTransformFeedbackAttribsNVproc) return;
	glTransformFeedbackAttribsNVproc(count, attribs, bufferMode);
}
PFNGLBINDBUFFERRANGENVPROC glBindBufferRangeNVproc = 0;
void APIENTRY glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
	if (!glBindBufferRangeNVproc) return;
	glBindBufferRangeNVproc(target, index, buffer, offset, size);
}
PFNGLBINDBUFFEROFFSETNVPROC glBindBufferOffsetNVproc = 0;
void APIENTRY glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
	if (!glBindBufferOffsetNVproc) return;
	glBindBufferOffsetNVproc(target, index, buffer, offset);
}
PFNGLBINDBUFFERBASENVPROC glBindBufferBaseNVproc = 0;
void APIENTRY glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer) {
	if (!glBindBufferBaseNVproc) return;
	glBindBufferBaseNVproc(target, index, buffer);
}
PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC glTransformFeedbackVaryingsNVproc = 0;
void APIENTRY glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint* locations, GLenum bufferMode) {
	if (!glTransformFeedbackVaryingsNVproc) return;
	glTransformFeedbackVaryingsNVproc(program, count, locations, bufferMode);
}
PFNGLACTIVEVARYINGNVPROC glActiveVaryingNVproc = 0;
void APIENTRY glActiveVaryingNV(GLuint program, const GLchar* name) {
	if (!glActiveVaryingNVproc) return;
	glActiveVaryingNVproc(program, name);
}
PFNGLGETVARYINGLOCATIONNVPROC glGetVaryingLocationNVproc = 0;
GLint APIENTRY glGetVaryingLocationNV(GLuint program, const GLchar* name) {
	if (!glGetVaryingLocationNVproc) return 0;
	return glGetVaryingLocationNVproc(program, name);
}
PFNGLGETACTIVEVARYINGNVPROC glGetActiveVaryingNVproc = 0;
void APIENTRY glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) {
	if (!glGetActiveVaryingNVproc) return;
	glGetActiveVaryingNVproc(program, index, bufSize, length, size, type, name);
}
PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC glGetTransformFeedbackVaryingNVproc = 0;
void APIENTRY glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint* location) {
	if (!glGetTransformFeedbackVaryingNVproc) return;
	glGetTransformFeedbackVaryingNVproc(program, index, location);
}
PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC glTransformFeedbackStreamAttribsNVproc = 0;
void APIENTRY glTransformFeedbackStreamAttribsNV(GLsizei count, const GLint* attribs, GLsizei nbuffers, const GLint* bufstreams, GLenum bufferMode) {
	if (!glTransformFeedbackStreamAttribsNVproc) return;
	glTransformFeedbackStreamAttribsNVproc(count, attribs, nbuffers, bufstreams, bufferMode);
}
PFNGLBINDTRANSFORMFEEDBACKNVPROC glBindTransformFeedbackNVproc = 0;
void APIENTRY glBindTransformFeedbackNV(GLenum target, GLuint id) {
	if (!glBindTransformFeedbackNVproc) return;
	glBindTransformFeedbackNVproc(target, id);
}
PFNGLDELETETRANSFORMFEEDBACKSNVPROC glDeleteTransformFeedbacksNVproc = 0;
void APIENTRY glDeleteTransformFeedbacksNV(GLsizei n, const GLuint* ids) {
	if (!glDeleteTransformFeedbacksNVproc) return;
	glDeleteTransformFeedbacksNVproc(n, ids);
}
PFNGLGENTRANSFORMFEEDBACKSNVPROC glGenTransformFeedbacksNVproc = 0;
void APIENTRY glGenTransformFeedbacksNV(GLsizei n, GLuint* ids) {
	if (!glGenTransformFeedbacksNVproc) return;
	glGenTransformFeedbacksNVproc(n, ids);
}
PFNGLISTRANSFORMFEEDBACKNVPROC glIsTransformFeedbackNVproc = 0;
GLboolean APIENTRY glIsTransformFeedbackNV(GLuint id) {
	if (!glIsTransformFeedbackNVproc) return 0;
	return glIsTransformFeedbackNVproc(id);
}
PFNGLPAUSETRANSFORMFEEDBACKNVPROC glPauseTransformFeedbackNVproc = 0;
void APIENTRY glPauseTransformFeedbackNV(void) {
	if (!glPauseTransformFeedbackNVproc) return;
	glPauseTransformFeedbackNVproc();
}
PFNGLRESUMETRANSFORMFEEDBACKNVPROC glResumeTransformFeedbackNVproc = 0;
void APIENTRY glResumeTransformFeedbackNV(void) {
	if (!glResumeTransformFeedbackNVproc) return;
	glResumeTransformFeedbackNVproc();
}
PFNGLDRAWTRANSFORMFEEDBACKNVPROC glDrawTransformFeedbackNVproc = 0;
void APIENTRY glDrawTransformFeedbackNV(GLenum mode, GLuint id) {
	if (!glDrawTransformFeedbackNVproc) return;
	glDrawTransformFeedbackNVproc(mode, id);
}
PFNGLVDPAUINITNVPROC glVDPAUInitNVproc = 0;
void APIENTRY glVDPAUInitNV(const void* vdpDevice, const void* getProcAddress) {
	if (!glVDPAUInitNVproc) return;
	glVDPAUInitNVproc(vdpDevice, getProcAddress);
}
PFNGLVDPAUFININVPROC glVDPAUFiniNVproc = 0;
void APIENTRY glVDPAUFiniNV(void) {
	if (!glVDPAUFiniNVproc) return;
	glVDPAUFiniNVproc();
}
PFNGLVDPAUREGISTERVIDEOSURFACENVPROC glVDPAURegisterVideoSurfaceNVproc = 0;
GLvdpauSurfaceNV APIENTRY glVDPAURegisterVideoSurfaceNV(const void* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames) {
	if (!glVDPAURegisterVideoSurfaceNVproc) return 0;
	return glVDPAURegisterVideoSurfaceNVproc(vdpSurface, target, numTextureNames, textureNames);
}
PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC glVDPAURegisterOutputSurfaceNVproc = 0;
GLvdpauSurfaceNV APIENTRY glVDPAURegisterOutputSurfaceNV(const void* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames) {
	if (!glVDPAURegisterOutputSurfaceNVproc) return 0;
	return glVDPAURegisterOutputSurfaceNVproc(vdpSurface, target, numTextureNames, textureNames);
}
PFNGLVDPAUISSURFACENVPROC glVDPAUIsSurfaceNVproc = 0;
GLboolean APIENTRY glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface) {
	if (!glVDPAUIsSurfaceNVproc) return 0;
	return glVDPAUIsSurfaceNVproc(surface);
}
PFNGLVDPAUUNREGISTERSURFACENVPROC glVDPAUUnregisterSurfaceNVproc = 0;
void APIENTRY glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface) {
	if (!glVDPAUUnregisterSurfaceNVproc) return;
	glVDPAUUnregisterSurfaceNVproc(surface);
}
PFNGLVDPAUGETSURFACEIVNVPROC glVDPAUGetSurfaceivNVproc = 0;
void APIENTRY glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei count, GLsizei* length, GLint* values) {
	if (!glVDPAUGetSurfaceivNVproc) return;
	glVDPAUGetSurfaceivNVproc(surface, pname, count, length, values);
}
PFNGLVDPAUSURFACEACCESSNVPROC glVDPAUSurfaceAccessNVproc = 0;
void APIENTRY glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access) {
	if (!glVDPAUSurfaceAccessNVproc) return;
	glVDPAUSurfaceAccessNVproc(surface, access);
}
PFNGLVDPAUMAPSURFACESNVPROC glVDPAUMapSurfacesNVproc = 0;
void APIENTRY glVDPAUMapSurfacesNV(GLsizei numSurfaces, const GLvdpauSurfaceNV* surfaces) {
	if (!glVDPAUMapSurfacesNVproc) return;
	glVDPAUMapSurfacesNVproc(numSurfaces, surfaces);
}
PFNGLVDPAUUNMAPSURFACESNVPROC glVDPAUUnmapSurfacesNVproc = 0;
void APIENTRY glVDPAUUnmapSurfacesNV(GLsizei numSurface, const GLvdpauSurfaceNV* surfaces) {
	if (!glVDPAUUnmapSurfacesNVproc) return;
	glVDPAUUnmapSurfacesNVproc(numSurface, surfaces);
}
PFNGLVDPAUREGISTERVIDEOSURFACEWITHPICTURESTRUCTURENVPROC glVDPAURegisterVideoSurfaceWithPictureStructureNVproc = 0;
GLvdpauSurfaceNV APIENTRY glVDPAURegisterVideoSurfaceWithPictureStructureNV(const void* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames, GLboolean isFrameStructure) {
	if (!glVDPAURegisterVideoSurfaceWithPictureStructureNVproc) return 0;
	return glVDPAURegisterVideoSurfaceWithPictureStructureNVproc(vdpSurface, target, numTextureNames, textureNames, isFrameStructure);
}
PFNGLFLUSHVERTEXARRAYRANGENVPROC glFlushVertexArrayRangeNVproc = 0;
void APIENTRY glFlushVertexArrayRangeNV(void) {
	if (!glFlushVertexArrayRangeNVproc) return;
	glFlushVertexArrayRangeNVproc();
}
PFNGLVERTEXARRAYRANGENVPROC glVertexArrayRangeNVproc = 0;
void APIENTRY glVertexArrayRangeNV(GLsizei length, const void* pointer) {
	if (!glVertexArrayRangeNVproc) return;
	glVertexArrayRangeNVproc(length, pointer);
}
PFNGLVERTEXATTRIBL1I64NVPROC glVertexAttribL1i64NVproc = 0;
void APIENTRY glVertexAttribL1i64NV(GLuint index, GLint64EXT x) {
	if (!glVertexAttribL1i64NVproc) return;
	glVertexAttribL1i64NVproc(index, x);
}
PFNGLVERTEXATTRIBL2I64NVPROC glVertexAttribL2i64NVproc = 0;
void APIENTRY glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y) {
	if (!glVertexAttribL2i64NVproc) return;
	glVertexAttribL2i64NVproc(index, x, y);
}
PFNGLVERTEXATTRIBL3I64NVPROC glVertexAttribL3i64NVproc = 0;
void APIENTRY glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
	if (!glVertexAttribL3i64NVproc) return;
	glVertexAttribL3i64NVproc(index, x, y, z);
}
PFNGLVERTEXATTRIBL4I64NVPROC glVertexAttribL4i64NVproc = 0;
void APIENTRY glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
	if (!glVertexAttribL4i64NVproc) return;
	glVertexAttribL4i64NVproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBL1I64VNVPROC glVertexAttribL1i64vNVproc = 0;
void APIENTRY glVertexAttribL1i64vNV(GLuint index, const GLint64EXT* v) {
	if (!glVertexAttribL1i64vNVproc) return;
	glVertexAttribL1i64vNVproc(index, v);
}
PFNGLVERTEXATTRIBL2I64VNVPROC glVertexAttribL2i64vNVproc = 0;
void APIENTRY glVertexAttribL2i64vNV(GLuint index, const GLint64EXT* v) {
	if (!glVertexAttribL2i64vNVproc) return;
	glVertexAttribL2i64vNVproc(index, v);
}
PFNGLVERTEXATTRIBL3I64VNVPROC glVertexAttribL3i64vNVproc = 0;
void APIENTRY glVertexAttribL3i64vNV(GLuint index, const GLint64EXT* v) {
	if (!glVertexAttribL3i64vNVproc) return;
	glVertexAttribL3i64vNVproc(index, v);
}
PFNGLVERTEXATTRIBL4I64VNVPROC glVertexAttribL4i64vNVproc = 0;
void APIENTRY glVertexAttribL4i64vNV(GLuint index, const GLint64EXT* v) {
	if (!glVertexAttribL4i64vNVproc) return;
	glVertexAttribL4i64vNVproc(index, v);
}
PFNGLVERTEXATTRIBL1UI64NVPROC glVertexAttribL1ui64NVproc = 0;
void APIENTRY glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x) {
	if (!glVertexAttribL1ui64NVproc) return;
	glVertexAttribL1ui64NVproc(index, x);
}
PFNGLVERTEXATTRIBL2UI64NVPROC glVertexAttribL2ui64NVproc = 0;
void APIENTRY glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y) {
	if (!glVertexAttribL2ui64NVproc) return;
	glVertexAttribL2ui64NVproc(index, x, y);
}
PFNGLVERTEXATTRIBL3UI64NVPROC glVertexAttribL3ui64NVproc = 0;
void APIENTRY glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
	if (!glVertexAttribL3ui64NVproc) return;
	glVertexAttribL3ui64NVproc(index, x, y, z);
}
PFNGLVERTEXATTRIBL4UI64NVPROC glVertexAttribL4ui64NVproc = 0;
void APIENTRY glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
	if (!glVertexAttribL4ui64NVproc) return;
	glVertexAttribL4ui64NVproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIBL1UI64VNVPROC glVertexAttribL1ui64vNVproc = 0;
void APIENTRY glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT* v) {
	if (!glVertexAttribL1ui64vNVproc) return;
	glVertexAttribL1ui64vNVproc(index, v);
}
PFNGLVERTEXATTRIBL2UI64VNVPROC glVertexAttribL2ui64vNVproc = 0;
void APIENTRY glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT* v) {
	if (!glVertexAttribL2ui64vNVproc) return;
	glVertexAttribL2ui64vNVproc(index, v);
}
PFNGLVERTEXATTRIBL3UI64VNVPROC glVertexAttribL3ui64vNVproc = 0;
void APIENTRY glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT* v) {
	if (!glVertexAttribL3ui64vNVproc) return;
	glVertexAttribL3ui64vNVproc(index, v);
}
PFNGLVERTEXATTRIBL4UI64VNVPROC glVertexAttribL4ui64vNVproc = 0;
void APIENTRY glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT* v) {
	if (!glVertexAttribL4ui64vNVproc) return;
	glVertexAttribL4ui64vNVproc(index, v);
}
PFNGLGETVERTEXATTRIBLI64VNVPROC glGetVertexAttribLi64vNVproc = 0;
void APIENTRY glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT* params) {
	if (!glGetVertexAttribLi64vNVproc) return;
	glGetVertexAttribLi64vNVproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBLUI64VNVPROC glGetVertexAttribLui64vNVproc = 0;
void APIENTRY glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT* params) {
	if (!glGetVertexAttribLui64vNVproc) return;
	glGetVertexAttribLui64vNVproc(index, pname, params);
}
PFNGLVERTEXATTRIBLFORMATNVPROC glVertexAttribLFormatNVproc = 0;
void APIENTRY glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride) {
	if (!glVertexAttribLFormatNVproc) return;
	glVertexAttribLFormatNVproc(index, size, type, stride);
}
PFNGLBUFFERADDRESSRANGENVPROC glBufferAddressRangeNVproc = 0;
void APIENTRY glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length) {
	if (!glBufferAddressRangeNVproc) return;
	glBufferAddressRangeNVproc(pname, index, address, length);
}
PFNGLVERTEXFORMATNVPROC glVertexFormatNVproc = 0;
void APIENTRY glVertexFormatNV(GLint size, GLenum type, GLsizei stride) {
	if (!glVertexFormatNVproc) return;
	glVertexFormatNVproc(size, type, stride);
}
PFNGLNORMALFORMATNVPROC glNormalFormatNVproc = 0;
void APIENTRY glNormalFormatNV(GLenum type, GLsizei stride) {
	if (!glNormalFormatNVproc) return;
	glNormalFormatNVproc(type, stride);
}
PFNGLCOLORFORMATNVPROC glColorFormatNVproc = 0;
void APIENTRY glColorFormatNV(GLint size, GLenum type, GLsizei stride) {
	if (!glColorFormatNVproc) return;
	glColorFormatNVproc(size, type, stride);
}
PFNGLINDEXFORMATNVPROC glIndexFormatNVproc = 0;
void APIENTRY glIndexFormatNV(GLenum type, GLsizei stride) {
	if (!glIndexFormatNVproc) return;
	glIndexFormatNVproc(type, stride);
}
PFNGLTEXCOORDFORMATNVPROC glTexCoordFormatNVproc = 0;
void APIENTRY glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride) {
	if (!glTexCoordFormatNVproc) return;
	glTexCoordFormatNVproc(size, type, stride);
}
PFNGLEDGEFLAGFORMATNVPROC glEdgeFlagFormatNVproc = 0;
void APIENTRY glEdgeFlagFormatNV(GLsizei stride) {
	if (!glEdgeFlagFormatNVproc) return;
	glEdgeFlagFormatNVproc(stride);
}
PFNGLSECONDARYCOLORFORMATNVPROC glSecondaryColorFormatNVproc = 0;
void APIENTRY glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride) {
	if (!glSecondaryColorFormatNVproc) return;
	glSecondaryColorFormatNVproc(size, type, stride);
}
PFNGLFOGCOORDFORMATNVPROC glFogCoordFormatNVproc = 0;
void APIENTRY glFogCoordFormatNV(GLenum type, GLsizei stride) {
	if (!glFogCoordFormatNVproc) return;
	glFogCoordFormatNVproc(type, stride);
}
PFNGLVERTEXATTRIBFORMATNVPROC glVertexAttribFormatNVproc = 0;
void APIENTRY glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) {
	if (!glVertexAttribFormatNVproc) return;
	glVertexAttribFormatNVproc(index, size, type, normalized, stride);
}
PFNGLVERTEXATTRIBIFORMATNVPROC glVertexAttribIFormatNVproc = 0;
void APIENTRY glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride) {
	if (!glVertexAttribIFormatNVproc) return;
	glVertexAttribIFormatNVproc(index, size, type, stride);
}
PFNGLGETINTEGERUI64I_VNVPROC glGetIntegerui64i_vNVproc = 0;
void APIENTRY glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT* result) {
	if (!glGetIntegerui64i_vNVproc) return;
	glGetIntegerui64i_vNVproc(value, index, result);
}
PFNGLAREPROGRAMSRESIDENTNVPROC glAreProgramsResidentNVproc = 0;
GLboolean APIENTRY glAreProgramsResidentNV(GLsizei n, const GLuint* programs, GLboolean* residences) {
	if (!glAreProgramsResidentNVproc) return 0;
	return glAreProgramsResidentNVproc(n, programs, residences);
}
PFNGLBINDPROGRAMNVPROC glBindProgramNVproc = 0;
void APIENTRY glBindProgramNV(GLenum target, GLuint id) {
	if (!glBindProgramNVproc) return;
	glBindProgramNVproc(target, id);
}
PFNGLDELETEPROGRAMSNVPROC glDeleteProgramsNVproc = 0;
void APIENTRY glDeleteProgramsNV(GLsizei n, const GLuint* programs) {
	if (!glDeleteProgramsNVproc) return;
	glDeleteProgramsNVproc(n, programs);
}
PFNGLEXECUTEPROGRAMNVPROC glExecuteProgramNVproc = 0;
void APIENTRY glExecuteProgramNV(GLenum target, GLuint id, const GLfloat* params) {
	if (!glExecuteProgramNVproc) return;
	glExecuteProgramNVproc(target, id, params);
}
PFNGLGENPROGRAMSNVPROC glGenProgramsNVproc = 0;
void APIENTRY glGenProgramsNV(GLsizei n, GLuint* programs) {
	if (!glGenProgramsNVproc) return;
	glGenProgramsNVproc(n, programs);
}
PFNGLGETPROGRAMPARAMETERDVNVPROC glGetProgramParameterdvNVproc = 0;
void APIENTRY glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble* params) {
	if (!glGetProgramParameterdvNVproc) return;
	glGetProgramParameterdvNVproc(target, index, pname, params);
}
PFNGLGETPROGRAMPARAMETERFVNVPROC glGetProgramParameterfvNVproc = 0;
void APIENTRY glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat* params) {
	if (!glGetProgramParameterfvNVproc) return;
	glGetProgramParameterfvNVproc(target, index, pname, params);
}
PFNGLGETPROGRAMIVNVPROC glGetProgramivNVproc = 0;
void APIENTRY glGetProgramivNV(GLuint id, GLenum pname, GLint* params) {
	if (!glGetProgramivNVproc) return;
	glGetProgramivNVproc(id, pname, params);
}
PFNGLGETPROGRAMSTRINGNVPROC glGetProgramStringNVproc = 0;
void APIENTRY glGetProgramStringNV(GLuint id, GLenum pname, GLubyte* program) {
	if (!glGetProgramStringNVproc) return;
	glGetProgramStringNVproc(id, pname, program);
}
PFNGLGETTRACKMATRIXIVNVPROC glGetTrackMatrixivNVproc = 0;
void APIENTRY glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint* params) {
	if (!glGetTrackMatrixivNVproc) return;
	glGetTrackMatrixivNVproc(target, address, pname, params);
}
PFNGLGETVERTEXATTRIBDVNVPROC glGetVertexAttribdvNVproc = 0;
void APIENTRY glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble* params) {
	if (!glGetVertexAttribdvNVproc) return;
	glGetVertexAttribdvNVproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBFVNVPROC glGetVertexAttribfvNVproc = 0;
void APIENTRY glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat* params) {
	if (!glGetVertexAttribfvNVproc) return;
	glGetVertexAttribfvNVproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBIVNVPROC glGetVertexAttribivNVproc = 0;
void APIENTRY glGetVertexAttribivNV(GLuint index, GLenum pname, GLint* params) {
	if (!glGetVertexAttribivNVproc) return;
	glGetVertexAttribivNVproc(index, pname, params);
}
PFNGLGETVERTEXATTRIBPOINTERVNVPROC glGetVertexAttribPointervNVproc = 0;
void APIENTRY glGetVertexAttribPointervNV(GLuint index, GLenum pname, void** pointer) {
	if (!glGetVertexAttribPointervNVproc) return;
	glGetVertexAttribPointervNVproc(index, pname, pointer);
}
PFNGLISPROGRAMNVPROC glIsProgramNVproc = 0;
GLboolean APIENTRY glIsProgramNV(GLuint id) {
	if (!glIsProgramNVproc) return 0;
	return glIsProgramNVproc(id);
}
PFNGLLOADPROGRAMNVPROC glLoadProgramNVproc = 0;
void APIENTRY glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte* program) {
	if (!glLoadProgramNVproc) return;
	glLoadProgramNVproc(target, id, len, program);
}
PFNGLPROGRAMPARAMETER4DNVPROC glProgramParameter4dNVproc = 0;
void APIENTRY glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glProgramParameter4dNVproc) return;
	glProgramParameter4dNVproc(target, index, x, y, z, w);
}
PFNGLPROGRAMPARAMETER4DVNVPROC glProgramParameter4dvNVproc = 0;
void APIENTRY glProgramParameter4dvNV(GLenum target, GLuint index, const GLdouble* v) {
	if (!glProgramParameter4dvNVproc) return;
	glProgramParameter4dvNVproc(target, index, v);
}
PFNGLPROGRAMPARAMETER4FNVPROC glProgramParameter4fNVproc = 0;
void APIENTRY glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glProgramParameter4fNVproc) return;
	glProgramParameter4fNVproc(target, index, x, y, z, w);
}
PFNGLPROGRAMPARAMETER4FVNVPROC glProgramParameter4fvNVproc = 0;
void APIENTRY glProgramParameter4fvNV(GLenum target, GLuint index, const GLfloat* v) {
	if (!glProgramParameter4fvNVproc) return;
	glProgramParameter4fvNVproc(target, index, v);
}
PFNGLPROGRAMPARAMETERS4DVNVPROC glProgramParameters4dvNVproc = 0;
void APIENTRY glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, const GLdouble* v) {
	if (!glProgramParameters4dvNVproc) return;
	glProgramParameters4dvNVproc(target, index, count, v);
}
PFNGLPROGRAMPARAMETERS4FVNVPROC glProgramParameters4fvNVproc = 0;
void APIENTRY glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, const GLfloat* v) {
	if (!glProgramParameters4fvNVproc) return;
	glProgramParameters4fvNVproc(target, index, count, v);
}
PFNGLREQUESTRESIDENTPROGRAMSNVPROC glRequestResidentProgramsNVproc = 0;
void APIENTRY glRequestResidentProgramsNV(GLsizei n, const GLuint* programs) {
	if (!glRequestResidentProgramsNVproc) return;
	glRequestResidentProgramsNVproc(n, programs);
}
PFNGLTRACKMATRIXNVPROC glTrackMatrixNVproc = 0;
void APIENTRY glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform) {
	if (!glTrackMatrixNVproc) return;
	glTrackMatrixNVproc(target, address, matrix, transform);
}
PFNGLVERTEXATTRIBPOINTERNVPROC glVertexAttribPointerNVproc = 0;
void APIENTRY glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, const void* pointer) {
	if (!glVertexAttribPointerNVproc) return;
	glVertexAttribPointerNVproc(index, fsize, type, stride, pointer);
}
PFNGLVERTEXATTRIB1DNVPROC glVertexAttrib1dNVproc = 0;
void APIENTRY glVertexAttrib1dNV(GLuint index, GLdouble x) {
	if (!glVertexAttrib1dNVproc) return;
	glVertexAttrib1dNVproc(index, x);
}
PFNGLVERTEXATTRIB1DVNVPROC glVertexAttrib1dvNVproc = 0;
void APIENTRY glVertexAttrib1dvNV(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib1dvNVproc) return;
	glVertexAttrib1dvNVproc(index, v);
}
PFNGLVERTEXATTRIB1FNVPROC glVertexAttrib1fNVproc = 0;
void APIENTRY glVertexAttrib1fNV(GLuint index, GLfloat x) {
	if (!glVertexAttrib1fNVproc) return;
	glVertexAttrib1fNVproc(index, x);
}
PFNGLVERTEXATTRIB1FVNVPROC glVertexAttrib1fvNVproc = 0;
void APIENTRY glVertexAttrib1fvNV(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib1fvNVproc) return;
	glVertexAttrib1fvNVproc(index, v);
}
PFNGLVERTEXATTRIB1SNVPROC glVertexAttrib1sNVproc = 0;
void APIENTRY glVertexAttrib1sNV(GLuint index, GLshort x) {
	if (!glVertexAttrib1sNVproc) return;
	glVertexAttrib1sNVproc(index, x);
}
PFNGLVERTEXATTRIB1SVNVPROC glVertexAttrib1svNVproc = 0;
void APIENTRY glVertexAttrib1svNV(GLuint index, const GLshort* v) {
	if (!glVertexAttrib1svNVproc) return;
	glVertexAttrib1svNVproc(index, v);
}
PFNGLVERTEXATTRIB2DNVPROC glVertexAttrib2dNVproc = 0;
void APIENTRY glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y) {
	if (!glVertexAttrib2dNVproc) return;
	glVertexAttrib2dNVproc(index, x, y);
}
PFNGLVERTEXATTRIB2DVNVPROC glVertexAttrib2dvNVproc = 0;
void APIENTRY glVertexAttrib2dvNV(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib2dvNVproc) return;
	glVertexAttrib2dvNVproc(index, v);
}
PFNGLVERTEXATTRIB2FNVPROC glVertexAttrib2fNVproc = 0;
void APIENTRY glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y) {
	if (!glVertexAttrib2fNVproc) return;
	glVertexAttrib2fNVproc(index, x, y);
}
PFNGLVERTEXATTRIB2FVNVPROC glVertexAttrib2fvNVproc = 0;
void APIENTRY glVertexAttrib2fvNV(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib2fvNVproc) return;
	glVertexAttrib2fvNVproc(index, v);
}
PFNGLVERTEXATTRIB2SNVPROC glVertexAttrib2sNVproc = 0;
void APIENTRY glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y) {
	if (!glVertexAttrib2sNVproc) return;
	glVertexAttrib2sNVproc(index, x, y);
}
PFNGLVERTEXATTRIB2SVNVPROC glVertexAttrib2svNVproc = 0;
void APIENTRY glVertexAttrib2svNV(GLuint index, const GLshort* v) {
	if (!glVertexAttrib2svNVproc) return;
	glVertexAttrib2svNVproc(index, v);
}
PFNGLVERTEXATTRIB3DNVPROC glVertexAttrib3dNVproc = 0;
void APIENTRY glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
	if (!glVertexAttrib3dNVproc) return;
	glVertexAttrib3dNVproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3DVNVPROC glVertexAttrib3dvNVproc = 0;
void APIENTRY glVertexAttrib3dvNV(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib3dvNVproc) return;
	glVertexAttrib3dvNVproc(index, v);
}
PFNGLVERTEXATTRIB3FNVPROC glVertexAttrib3fNVproc = 0;
void APIENTRY glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
	if (!glVertexAttrib3fNVproc) return;
	glVertexAttrib3fNVproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3FVNVPROC glVertexAttrib3fvNVproc = 0;
void APIENTRY glVertexAttrib3fvNV(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib3fvNVproc) return;
	glVertexAttrib3fvNVproc(index, v);
}
PFNGLVERTEXATTRIB3SNVPROC glVertexAttrib3sNVproc = 0;
void APIENTRY glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z) {
	if (!glVertexAttrib3sNVproc) return;
	glVertexAttrib3sNVproc(index, x, y, z);
}
PFNGLVERTEXATTRIB3SVNVPROC glVertexAttrib3svNVproc = 0;
void APIENTRY glVertexAttrib3svNV(GLuint index, const GLshort* v) {
	if (!glVertexAttrib3svNVproc) return;
	glVertexAttrib3svNVproc(index, v);
}
PFNGLVERTEXATTRIB4DNVPROC glVertexAttrib4dNVproc = 0;
void APIENTRY glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
	if (!glVertexAttrib4dNVproc) return;
	glVertexAttrib4dNVproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4DVNVPROC glVertexAttrib4dvNVproc = 0;
void APIENTRY glVertexAttrib4dvNV(GLuint index, const GLdouble* v) {
	if (!glVertexAttrib4dvNVproc) return;
	glVertexAttrib4dvNVproc(index, v);
}
PFNGLVERTEXATTRIB4FNVPROC glVertexAttrib4fNVproc = 0;
void APIENTRY glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glVertexAttrib4fNVproc) return;
	glVertexAttrib4fNVproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FVNVPROC glVertexAttrib4fvNVproc = 0;
void APIENTRY glVertexAttrib4fvNV(GLuint index, const GLfloat* v) {
	if (!glVertexAttrib4fvNVproc) return;
	glVertexAttrib4fvNVproc(index, v);
}
PFNGLVERTEXATTRIB4SNVPROC glVertexAttrib4sNVproc = 0;
void APIENTRY glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
	if (!glVertexAttrib4sNVproc) return;
	glVertexAttrib4sNVproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4SVNVPROC glVertexAttrib4svNVproc = 0;
void APIENTRY glVertexAttrib4svNV(GLuint index, const GLshort* v) {
	if (!glVertexAttrib4svNVproc) return;
	glVertexAttrib4svNVproc(index, v);
}
PFNGLVERTEXATTRIB4UBNVPROC glVertexAttrib4ubNVproc = 0;
void APIENTRY glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
	if (!glVertexAttrib4ubNVproc) return;
	glVertexAttrib4ubNVproc(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4UBVNVPROC glVertexAttrib4ubvNVproc = 0;
void APIENTRY glVertexAttrib4ubvNV(GLuint index, const GLubyte* v) {
	if (!glVertexAttrib4ubvNVproc) return;
	glVertexAttrib4ubvNVproc(index, v);
}
PFNGLVERTEXATTRIBS1DVNVPROC glVertexAttribs1dvNVproc = 0;
void APIENTRY glVertexAttribs1dvNV(GLuint index, GLsizei count, const GLdouble* v) {
	if (!glVertexAttribs1dvNVproc) return;
	glVertexAttribs1dvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS1FVNVPROC glVertexAttribs1fvNVproc = 0;
void APIENTRY glVertexAttribs1fvNV(GLuint index, GLsizei count, const GLfloat* v) {
	if (!glVertexAttribs1fvNVproc) return;
	glVertexAttribs1fvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS1SVNVPROC glVertexAttribs1svNVproc = 0;
void APIENTRY glVertexAttribs1svNV(GLuint index, GLsizei count, const GLshort* v) {
	if (!glVertexAttribs1svNVproc) return;
	glVertexAttribs1svNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS2DVNVPROC glVertexAttribs2dvNVproc = 0;
void APIENTRY glVertexAttribs2dvNV(GLuint index, GLsizei count, const GLdouble* v) {
	if (!glVertexAttribs2dvNVproc) return;
	glVertexAttribs2dvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS2FVNVPROC glVertexAttribs2fvNVproc = 0;
void APIENTRY glVertexAttribs2fvNV(GLuint index, GLsizei count, const GLfloat* v) {
	if (!glVertexAttribs2fvNVproc) return;
	glVertexAttribs2fvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS2SVNVPROC glVertexAttribs2svNVproc = 0;
void APIENTRY glVertexAttribs2svNV(GLuint index, GLsizei count, const GLshort* v) {
	if (!glVertexAttribs2svNVproc) return;
	glVertexAttribs2svNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS3DVNVPROC glVertexAttribs3dvNVproc = 0;
void APIENTRY glVertexAttribs3dvNV(GLuint index, GLsizei count, const GLdouble* v) {
	if (!glVertexAttribs3dvNVproc) return;
	glVertexAttribs3dvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS3FVNVPROC glVertexAttribs3fvNVproc = 0;
void APIENTRY glVertexAttribs3fvNV(GLuint index, GLsizei count, const GLfloat* v) {
	if (!glVertexAttribs3fvNVproc) return;
	glVertexAttribs3fvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS3SVNVPROC glVertexAttribs3svNVproc = 0;
void APIENTRY glVertexAttribs3svNV(GLuint index, GLsizei count, const GLshort* v) {
	if (!glVertexAttribs3svNVproc) return;
	glVertexAttribs3svNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS4DVNVPROC glVertexAttribs4dvNVproc = 0;
void APIENTRY glVertexAttribs4dvNV(GLuint index, GLsizei count, const GLdouble* v) {
	if (!glVertexAttribs4dvNVproc) return;
	glVertexAttribs4dvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS4FVNVPROC glVertexAttribs4fvNVproc = 0;
void APIENTRY glVertexAttribs4fvNV(GLuint index, GLsizei count, const GLfloat* v) {
	if (!glVertexAttribs4fvNVproc) return;
	glVertexAttribs4fvNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS4SVNVPROC glVertexAttribs4svNVproc = 0;
void APIENTRY glVertexAttribs4svNV(GLuint index, GLsizei count, const GLshort* v) {
	if (!glVertexAttribs4svNVproc) return;
	glVertexAttribs4svNVproc(index, count, v);
}
PFNGLVERTEXATTRIBS4UBVNVPROC glVertexAttribs4ubvNVproc = 0;
void APIENTRY glVertexAttribs4ubvNV(GLuint index, GLsizei count, const GLubyte* v) {
	if (!glVertexAttribs4ubvNVproc) return;
	glVertexAttribs4ubvNVproc(index, count, v);
}
PFNGLBEGINVIDEOCAPTURENVPROC glBeginVideoCaptureNVproc = 0;
void APIENTRY glBeginVideoCaptureNV(GLuint video_capture_slot) {
	if (!glBeginVideoCaptureNVproc) return;
	glBeginVideoCaptureNVproc(video_capture_slot);
}
PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC glBindVideoCaptureStreamBufferNVproc = 0;
void APIENTRY glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset) {
	if (!glBindVideoCaptureStreamBufferNVproc) return;
	glBindVideoCaptureStreamBufferNVproc(video_capture_slot, stream, frame_region, offset);
}
PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC glBindVideoCaptureStreamTextureNVproc = 0;
void APIENTRY glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture) {
	if (!glBindVideoCaptureStreamTextureNVproc) return;
	glBindVideoCaptureStreamTextureNVproc(video_capture_slot, stream, frame_region, target, texture);
}
PFNGLENDVIDEOCAPTURENVPROC glEndVideoCaptureNVproc = 0;
void APIENTRY glEndVideoCaptureNV(GLuint video_capture_slot) {
	if (!glEndVideoCaptureNVproc) return;
	glEndVideoCaptureNVproc(video_capture_slot);
}
PFNGLGETVIDEOCAPTUREIVNVPROC glGetVideoCaptureivNVproc = 0;
void APIENTRY glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint* params) {
	if (!glGetVideoCaptureivNVproc) return;
	glGetVideoCaptureivNVproc(video_capture_slot, pname, params);
}
PFNGLGETVIDEOCAPTURESTREAMIVNVPROC glGetVideoCaptureStreamivNVproc = 0;
void APIENTRY glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint* params) {
	if (!glGetVideoCaptureStreamivNVproc) return;
	glGetVideoCaptureStreamivNVproc(video_capture_slot, stream, pname, params);
}
PFNGLGETVIDEOCAPTURESTREAMFVNVPROC glGetVideoCaptureStreamfvNVproc = 0;
void APIENTRY glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat* params) {
	if (!glGetVideoCaptureStreamfvNVproc) return;
	glGetVideoCaptureStreamfvNVproc(video_capture_slot, stream, pname, params);
}
PFNGLGETVIDEOCAPTURESTREAMDVNVPROC glGetVideoCaptureStreamdvNVproc = 0;
void APIENTRY glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble* params) {
	if (!glGetVideoCaptureStreamdvNVproc) return;
	glGetVideoCaptureStreamdvNVproc(video_capture_slot, stream, pname, params);
}
PFNGLVIDEOCAPTURENVPROC glVideoCaptureNVproc = 0;
GLenum APIENTRY glVideoCaptureNV(GLuint video_capture_slot, GLuint* sequence_num, GLuint64EXT* capture_time) {
	if (!glVideoCaptureNVproc) return 0;
	return glVideoCaptureNVproc(video_capture_slot, sequence_num, capture_time);
}
PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC glVideoCaptureStreamParameterivNVproc = 0;
void APIENTRY glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint* params) {
	if (!glVideoCaptureStreamParameterivNVproc) return;
	glVideoCaptureStreamParameterivNVproc(video_capture_slot, stream, pname, params);
}
PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC glVideoCaptureStreamParameterfvNVproc = 0;
void APIENTRY glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat* params) {
	if (!glVideoCaptureStreamParameterfvNVproc) return;
	glVideoCaptureStreamParameterfvNVproc(video_capture_slot, stream, pname, params);
}
PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC glVideoCaptureStreamParameterdvNVproc = 0;
void APIENTRY glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble* params) {
	if (!glVideoCaptureStreamParameterdvNVproc) return;
	glVideoCaptureStreamParameterdvNVproc(video_capture_slot, stream, pname, params);
}
PFNGLVIEWPORTSWIZZLENVPROC glViewportSwizzleNVproc = 0;
void APIENTRY glViewportSwizzleNV(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew) {
	if (!glViewportSwizzleNVproc) return;
	glViewportSwizzleNVproc(index, swizzlex, swizzley, swizzlez, swizzlew);
}
PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC glFramebufferTextureMultiviewOVRproc = 0;
void APIENTRY glFramebufferTextureMultiviewOVR(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews) {
	if (!glFramebufferTextureMultiviewOVRproc) return;
	glFramebufferTextureMultiviewOVRproc(target, attachment, texture, level, baseViewIndex, numViews);
}
PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC glNamedFramebufferTextureMultiviewOVRproc = 0;
void APIENTRY glNamedFramebufferTextureMultiviewOVR(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews) {
	if (!glNamedFramebufferTextureMultiviewOVRproc) return;
	glNamedFramebufferTextureMultiviewOVRproc(framebuffer, attachment, texture, level, baseViewIndex, numViews);
}
PFNGLHINTPGIPROC glHintPGIproc = 0;
void APIENTRY glHintPGI(GLenum target, GLint mode) {
	if (!glHintPGIproc) return;
	glHintPGIproc(target, mode);
}
PFNGLDETAILTEXFUNCSGISPROC glDetailTexFuncSGISproc = 0;
void APIENTRY glDetailTexFuncSGIS(GLenum target, GLsizei n, const GLfloat* points) {
	if (!glDetailTexFuncSGISproc) return;
	glDetailTexFuncSGISproc(target, n, points);
}
PFNGLGETDETAILTEXFUNCSGISPROC glGetDetailTexFuncSGISproc = 0;
void APIENTRY glGetDetailTexFuncSGIS(GLenum target, GLfloat* points) {
	if (!glGetDetailTexFuncSGISproc) return;
	glGetDetailTexFuncSGISproc(target, points);
}
PFNGLFOGFUNCSGISPROC glFogFuncSGISproc = 0;
void APIENTRY glFogFuncSGIS(GLsizei n, const GLfloat* points) {
	if (!glFogFuncSGISproc) return;
	glFogFuncSGISproc(n, points);
}
PFNGLGETFOGFUNCSGISPROC glGetFogFuncSGISproc = 0;
void APIENTRY glGetFogFuncSGIS(GLfloat* points) {
	if (!glGetFogFuncSGISproc) return;
	glGetFogFuncSGISproc(points);
}
PFNGLSAMPLEMASKSGISPROC glSampleMaskSGISproc = 0;
void APIENTRY glSampleMaskSGIS(GLclampf value, GLboolean invert) {
	if (!glSampleMaskSGISproc) return;
	glSampleMaskSGISproc(value, invert);
}
PFNGLSAMPLEPATTERNSGISPROC glSamplePatternSGISproc = 0;
void APIENTRY glSamplePatternSGIS(GLenum pattern) {
	if (!glSamplePatternSGISproc) return;
	glSamplePatternSGISproc(pattern);
}
PFNGLPIXELTEXGENPARAMETERISGISPROC glPixelTexGenParameteriSGISproc = 0;
void APIENTRY glPixelTexGenParameteriSGIS(GLenum pname, GLint param) {
	if (!glPixelTexGenParameteriSGISproc) return;
	glPixelTexGenParameteriSGISproc(pname, param);
}
PFNGLPIXELTEXGENPARAMETERIVSGISPROC glPixelTexGenParameterivSGISproc = 0;
void APIENTRY glPixelTexGenParameterivSGIS(GLenum pname, const GLint* params) {
	if (!glPixelTexGenParameterivSGISproc) return;
	glPixelTexGenParameterivSGISproc(pname, params);
}
PFNGLPIXELTEXGENPARAMETERFSGISPROC glPixelTexGenParameterfSGISproc = 0;
void APIENTRY glPixelTexGenParameterfSGIS(GLenum pname, GLfloat param) {
	if (!glPixelTexGenParameterfSGISproc) return;
	glPixelTexGenParameterfSGISproc(pname, param);
}
PFNGLPIXELTEXGENPARAMETERFVSGISPROC glPixelTexGenParameterfvSGISproc = 0;
void APIENTRY glPixelTexGenParameterfvSGIS(GLenum pname, const GLfloat* params) {
	if (!glPixelTexGenParameterfvSGISproc) return;
	glPixelTexGenParameterfvSGISproc(pname, params);
}
PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC glGetPixelTexGenParameterivSGISproc = 0;
void APIENTRY glGetPixelTexGenParameterivSGIS(GLenum pname, GLint* params) {
	if (!glGetPixelTexGenParameterivSGISproc) return;
	glGetPixelTexGenParameterivSGISproc(pname, params);
}
PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC glGetPixelTexGenParameterfvSGISproc = 0;
void APIENTRY glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat* params) {
	if (!glGetPixelTexGenParameterfvSGISproc) return;
	glGetPixelTexGenParameterfvSGISproc(pname, params);
}
PFNGLPOINTPARAMETERFSGISPROC glPointParameterfSGISproc = 0;
void APIENTRY glPointParameterfSGIS(GLenum pname, GLfloat param) {
	if (!glPointParameterfSGISproc) return;
	glPointParameterfSGISproc(pname, param);
}
PFNGLPOINTPARAMETERFVSGISPROC glPointParameterfvSGISproc = 0;
void APIENTRY glPointParameterfvSGIS(GLenum pname, const GLfloat* params) {
	if (!glPointParameterfvSGISproc) return;
	glPointParameterfvSGISproc(pname, params);
}
PFNGLSHARPENTEXFUNCSGISPROC glSharpenTexFuncSGISproc = 0;
void APIENTRY glSharpenTexFuncSGIS(GLenum target, GLsizei n, const GLfloat* points) {
	if (!glSharpenTexFuncSGISproc) return;
	glSharpenTexFuncSGISproc(target, n, points);
}
PFNGLGETSHARPENTEXFUNCSGISPROC glGetSharpenTexFuncSGISproc = 0;
void APIENTRY glGetSharpenTexFuncSGIS(GLenum target, GLfloat* points) {
	if (!glGetSharpenTexFuncSGISproc) return;
	glGetSharpenTexFuncSGISproc(target, points);
}
PFNGLTEXIMAGE4DSGISPROC glTexImage4DSGISproc = 0;
void APIENTRY glTexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void* pixels) {
	if (!glTexImage4DSGISproc) return;
	glTexImage4DSGISproc(target, level, internalformat, width, height, depth, size4d, border, format, type, pixels);
}
PFNGLTEXSUBIMAGE4DSGISPROC glTexSubImage4DSGISproc = 0;
void APIENTRY glTexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void* pixels) {
	if (!glTexSubImage4DSGISproc) return;
	glTexSubImage4DSGISproc(target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels);
}
PFNGLTEXTURECOLORMASKSGISPROC glTextureColorMaskSGISproc = 0;
void APIENTRY glTextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
	if (!glTextureColorMaskSGISproc) return;
	glTextureColorMaskSGISproc(red, green, blue, alpha);
}
PFNGLGETTEXFILTERFUNCSGISPROC glGetTexFilterFuncSGISproc = 0;
void APIENTRY glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat* weights) {
	if (!glGetTexFilterFuncSGISproc) return;
	glGetTexFilterFuncSGISproc(target, filter, weights);
}
PFNGLTEXFILTERFUNCSGISPROC glTexFilterFuncSGISproc = 0;
void APIENTRY glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const GLfloat* weights) {
	if (!glTexFilterFuncSGISproc) return;
	glTexFilterFuncSGISproc(target, filter, n, weights);
}
PFNGLASYNCMARKERSGIXPROC glAsyncMarkerSGIXproc = 0;
void APIENTRY glAsyncMarkerSGIX(GLuint marker) {
	if (!glAsyncMarkerSGIXproc) return;
	glAsyncMarkerSGIXproc(marker);
}
PFNGLFINISHASYNCSGIXPROC glFinishAsyncSGIXproc = 0;
GLint APIENTRY glFinishAsyncSGIX(GLuint* markerp) {
	if (!glFinishAsyncSGIXproc) return 0;
	return glFinishAsyncSGIXproc(markerp);
}
PFNGLPOLLASYNCSGIXPROC glPollAsyncSGIXproc = 0;
GLint APIENTRY glPollAsyncSGIX(GLuint* markerp) {
	if (!glPollAsyncSGIXproc) return 0;
	return glPollAsyncSGIXproc(markerp);
}
PFNGLGENASYNCMARKERSSGIXPROC glGenAsyncMarkersSGIXproc = 0;
GLuint APIENTRY glGenAsyncMarkersSGIX(GLsizei range) {
	if (!glGenAsyncMarkersSGIXproc) return 0;
	return glGenAsyncMarkersSGIXproc(range);
}
PFNGLDELETEASYNCMARKERSSGIXPROC glDeleteAsyncMarkersSGIXproc = 0;
void APIENTRY glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range) {
	if (!glDeleteAsyncMarkersSGIXproc) return;
	glDeleteAsyncMarkersSGIXproc(marker, range);
}
PFNGLISASYNCMARKERSGIXPROC glIsAsyncMarkerSGIXproc = 0;
GLboolean APIENTRY glIsAsyncMarkerSGIX(GLuint marker) {
	if (!glIsAsyncMarkerSGIXproc) return 0;
	return glIsAsyncMarkerSGIXproc(marker);
}
PFNGLFLUSHRASTERSGIXPROC glFlushRasterSGIXproc = 0;
void APIENTRY glFlushRasterSGIX(void) {
	if (!glFlushRasterSGIXproc) return;
	glFlushRasterSGIXproc();
}
PFNGLFRAGMENTCOLORMATERIALSGIXPROC glFragmentColorMaterialSGIXproc = 0;
void APIENTRY glFragmentColorMaterialSGIX(GLenum face, GLenum mode) {
	if (!glFragmentColorMaterialSGIXproc) return;
	glFragmentColorMaterialSGIXproc(face, mode);
}
PFNGLFRAGMENTLIGHTFSGIXPROC glFragmentLightfSGIXproc = 0;
void APIENTRY glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param) {
	if (!glFragmentLightfSGIXproc) return;
	glFragmentLightfSGIXproc(light, pname, param);
}
PFNGLFRAGMENTLIGHTFVSGIXPROC glFragmentLightfvSGIXproc = 0;
void APIENTRY glFragmentLightfvSGIX(GLenum light, GLenum pname, const GLfloat* params) {
	if (!glFragmentLightfvSGIXproc) return;
	glFragmentLightfvSGIXproc(light, pname, params);
}
PFNGLFRAGMENTLIGHTISGIXPROC glFragmentLightiSGIXproc = 0;
void APIENTRY glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param) {
	if (!glFragmentLightiSGIXproc) return;
	glFragmentLightiSGIXproc(light, pname, param);
}
PFNGLFRAGMENTLIGHTIVSGIXPROC glFragmentLightivSGIXproc = 0;
void APIENTRY glFragmentLightivSGIX(GLenum light, GLenum pname, const GLint* params) {
	if (!glFragmentLightivSGIXproc) return;
	glFragmentLightivSGIXproc(light, pname, params);
}
PFNGLFRAGMENTLIGHTMODELFSGIXPROC glFragmentLightModelfSGIXproc = 0;
void APIENTRY glFragmentLightModelfSGIX(GLenum pname, GLfloat param) {
	if (!glFragmentLightModelfSGIXproc) return;
	glFragmentLightModelfSGIXproc(pname, param);
}
PFNGLFRAGMENTLIGHTMODELFVSGIXPROC glFragmentLightModelfvSGIXproc = 0;
void APIENTRY glFragmentLightModelfvSGIX(GLenum pname, const GLfloat* params) {
	if (!glFragmentLightModelfvSGIXproc) return;
	glFragmentLightModelfvSGIXproc(pname, params);
}
PFNGLFRAGMENTLIGHTMODELISGIXPROC glFragmentLightModeliSGIXproc = 0;
void APIENTRY glFragmentLightModeliSGIX(GLenum pname, GLint param) {
	if (!glFragmentLightModeliSGIXproc) return;
	glFragmentLightModeliSGIXproc(pname, param);
}
PFNGLFRAGMENTLIGHTMODELIVSGIXPROC glFragmentLightModelivSGIXproc = 0;
void APIENTRY glFragmentLightModelivSGIX(GLenum pname, const GLint* params) {
	if (!glFragmentLightModelivSGIXproc) return;
	glFragmentLightModelivSGIXproc(pname, params);
}
PFNGLFRAGMENTMATERIALFSGIXPROC glFragmentMaterialfSGIXproc = 0;
void APIENTRY glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param) {
	if (!glFragmentMaterialfSGIXproc) return;
	glFragmentMaterialfSGIXproc(face, pname, param);
}
PFNGLFRAGMENTMATERIALFVSGIXPROC glFragmentMaterialfvSGIXproc = 0;
void APIENTRY glFragmentMaterialfvSGIX(GLenum face, GLenum pname, const GLfloat* params) {
	if (!glFragmentMaterialfvSGIXproc) return;
	glFragmentMaterialfvSGIXproc(face, pname, params);
}
PFNGLFRAGMENTMATERIALISGIXPROC glFragmentMaterialiSGIXproc = 0;
void APIENTRY glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param) {
	if (!glFragmentMaterialiSGIXproc) return;
	glFragmentMaterialiSGIXproc(face, pname, param);
}
PFNGLFRAGMENTMATERIALIVSGIXPROC glFragmentMaterialivSGIXproc = 0;
void APIENTRY glFragmentMaterialivSGIX(GLenum face, GLenum pname, const GLint* params) {
	if (!glFragmentMaterialivSGIXproc) return;
	glFragmentMaterialivSGIXproc(face, pname, params);
}
PFNGLGETFRAGMENTLIGHTFVSGIXPROC glGetFragmentLightfvSGIXproc = 0;
void APIENTRY glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat* params) {
	if (!glGetFragmentLightfvSGIXproc) return;
	glGetFragmentLightfvSGIXproc(light, pname, params);
}
PFNGLGETFRAGMENTLIGHTIVSGIXPROC glGetFragmentLightivSGIXproc = 0;
void APIENTRY glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint* params) {
	if (!glGetFragmentLightivSGIXproc) return;
	glGetFragmentLightivSGIXproc(light, pname, params);
}
PFNGLGETFRAGMENTMATERIALFVSGIXPROC glGetFragmentMaterialfvSGIXproc = 0;
void APIENTRY glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat* params) {
	if (!glGetFragmentMaterialfvSGIXproc) return;
	glGetFragmentMaterialfvSGIXproc(face, pname, params);
}
PFNGLGETFRAGMENTMATERIALIVSGIXPROC glGetFragmentMaterialivSGIXproc = 0;
void APIENTRY glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint* params) {
	if (!glGetFragmentMaterialivSGIXproc) return;
	glGetFragmentMaterialivSGIXproc(face, pname, params);
}
PFNGLLIGHTENVISGIXPROC glLightEnviSGIXproc = 0;
void APIENTRY glLightEnviSGIX(GLenum pname, GLint param) {
	if (!glLightEnviSGIXproc) return;
	glLightEnviSGIXproc(pname, param);
}
PFNGLFRAMEZOOMSGIXPROC glFrameZoomSGIXproc = 0;
void APIENTRY glFrameZoomSGIX(GLint factor) {
	if (!glFrameZoomSGIXproc) return;
	glFrameZoomSGIXproc(factor);
}
PFNGLIGLOOINTERFACESGIXPROC glIglooInterfaceSGIXproc = 0;
void APIENTRY glIglooInterfaceSGIX(GLenum pname, const void* params) {
	if (!glIglooInterfaceSGIXproc) return;
	glIglooInterfaceSGIXproc(pname, params);
}
PFNGLGETINSTRUMENTSSGIXPROC glGetInstrumentsSGIXproc = 0;
GLint APIENTRY glGetInstrumentsSGIX(void) {
	if (!glGetInstrumentsSGIXproc) return 0;
	return glGetInstrumentsSGIXproc();
}
PFNGLINSTRUMENTSBUFFERSGIXPROC glInstrumentsBufferSGIXproc = 0;
void APIENTRY glInstrumentsBufferSGIX(GLsizei size, GLint* buffer) {
	if (!glInstrumentsBufferSGIXproc) return;
	glInstrumentsBufferSGIXproc(size, buffer);
}
PFNGLPOLLINSTRUMENTSSGIXPROC glPollInstrumentsSGIXproc = 0;
GLint APIENTRY glPollInstrumentsSGIX(GLint* marker_p) {
	if (!glPollInstrumentsSGIXproc) return 0;
	return glPollInstrumentsSGIXproc(marker_p);
}
PFNGLREADINSTRUMENTSSGIXPROC glReadInstrumentsSGIXproc = 0;
void APIENTRY glReadInstrumentsSGIX(GLint marker) {
	if (!glReadInstrumentsSGIXproc) return;
	glReadInstrumentsSGIXproc(marker);
}
PFNGLSTARTINSTRUMENTSSGIXPROC glStartInstrumentsSGIXproc = 0;
void APIENTRY glStartInstrumentsSGIX(void) {
	if (!glStartInstrumentsSGIXproc) return;
	glStartInstrumentsSGIXproc();
}
PFNGLSTOPINSTRUMENTSSGIXPROC glStopInstrumentsSGIXproc = 0;
void APIENTRY glStopInstrumentsSGIX(GLint marker) {
	if (!glStopInstrumentsSGIXproc) return;
	glStopInstrumentsSGIXproc(marker);
}
PFNGLGETLISTPARAMETERFVSGIXPROC glGetListParameterfvSGIXproc = 0;
void APIENTRY glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat* params) {
	if (!glGetListParameterfvSGIXproc) return;
	glGetListParameterfvSGIXproc(list, pname, params);
}
PFNGLGETLISTPARAMETERIVSGIXPROC glGetListParameterivSGIXproc = 0;
void APIENTRY glGetListParameterivSGIX(GLuint list, GLenum pname, GLint* params) {
	if (!glGetListParameterivSGIXproc) return;
	glGetListParameterivSGIXproc(list, pname, params);
}
PFNGLLISTPARAMETERFSGIXPROC glListParameterfSGIXproc = 0;
void APIENTRY glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param) {
	if (!glListParameterfSGIXproc) return;
	glListParameterfSGIXproc(list, pname, param);
}
PFNGLLISTPARAMETERFVSGIXPROC glListParameterfvSGIXproc = 0;
void APIENTRY glListParameterfvSGIX(GLuint list, GLenum pname, const GLfloat* params) {
	if (!glListParameterfvSGIXproc) return;
	glListParameterfvSGIXproc(list, pname, params);
}
PFNGLLISTPARAMETERISGIXPROC glListParameteriSGIXproc = 0;
void APIENTRY glListParameteriSGIX(GLuint list, GLenum pname, GLint param) {
	if (!glListParameteriSGIXproc) return;
	glListParameteriSGIXproc(list, pname, param);
}
PFNGLLISTPARAMETERIVSGIXPROC glListParameterivSGIXproc = 0;
void APIENTRY glListParameterivSGIX(GLuint list, GLenum pname, const GLint* params) {
	if (!glListParameterivSGIXproc) return;
	glListParameterivSGIXproc(list, pname, params);
}
PFNGLPIXELTEXGENSGIXPROC glPixelTexGenSGIXproc = 0;
void APIENTRY glPixelTexGenSGIX(GLenum mode) {
	if (!glPixelTexGenSGIXproc) return;
	glPixelTexGenSGIXproc(mode);
}
PFNGLDEFORMATIONMAP3DSGIXPROC glDeformationMap3dSGIXproc = 0;
void APIENTRY glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble* points) {
	if (!glDeformationMap3dSGIXproc) return;
	glDeformationMap3dSGIXproc(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}
PFNGLDEFORMATIONMAP3FSGIXPROC glDeformationMap3fSGIXproc = 0;
void APIENTRY glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat* points) {
	if (!glDeformationMap3fSGIXproc) return;
	glDeformationMap3fSGIXproc(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}
PFNGLDEFORMSGIXPROC glDeformSGIXproc = 0;
void APIENTRY glDeformSGIX(GLbitfield mask) {
	if (!glDeformSGIXproc) return;
	glDeformSGIXproc(mask);
}
PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC glLoadIdentityDeformationMapSGIXproc = 0;
void APIENTRY glLoadIdentityDeformationMapSGIX(GLbitfield mask) {
	if (!glLoadIdentityDeformationMapSGIXproc) return;
	glLoadIdentityDeformationMapSGIXproc(mask);
}
PFNGLREFERENCEPLANESGIXPROC glReferencePlaneSGIXproc = 0;
void APIENTRY glReferencePlaneSGIX(const GLdouble* equation) {
	if (!glReferencePlaneSGIXproc) return;
	glReferencePlaneSGIXproc(equation);
}
PFNGLSPRITEPARAMETERFSGIXPROC glSpriteParameterfSGIXproc = 0;
void APIENTRY glSpriteParameterfSGIX(GLenum pname, GLfloat param) {
	if (!glSpriteParameterfSGIXproc) return;
	glSpriteParameterfSGIXproc(pname, param);
}
PFNGLSPRITEPARAMETERFVSGIXPROC glSpriteParameterfvSGIXproc = 0;
void APIENTRY glSpriteParameterfvSGIX(GLenum pname, const GLfloat* params) {
	if (!glSpriteParameterfvSGIXproc) return;
	glSpriteParameterfvSGIXproc(pname, params);
}
PFNGLSPRITEPARAMETERISGIXPROC glSpriteParameteriSGIXproc = 0;
void APIENTRY glSpriteParameteriSGIX(GLenum pname, GLint param) {
	if (!glSpriteParameteriSGIXproc) return;
	glSpriteParameteriSGIXproc(pname, param);
}
PFNGLSPRITEPARAMETERIVSGIXPROC glSpriteParameterivSGIXproc = 0;
void APIENTRY glSpriteParameterivSGIX(GLenum pname, const GLint* params) {
	if (!glSpriteParameterivSGIXproc) return;
	glSpriteParameterivSGIXproc(pname, params);
}
PFNGLTAGSAMPLEBUFFERSGIXPROC glTagSampleBufferSGIXproc = 0;
void APIENTRY glTagSampleBufferSGIX(void) {
	if (!glTagSampleBufferSGIXproc) return;
	glTagSampleBufferSGIXproc();
}
PFNGLCOLORTABLESGIPROC glColorTableSGIproc = 0;
void APIENTRY glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* table) {
	if (!glColorTableSGIproc) return;
	glColorTableSGIproc(target, internalformat, width, format, type, table);
}
PFNGLCOLORTABLEPARAMETERFVSGIPROC glColorTableParameterfvSGIproc = 0;
void APIENTRY glColorTableParameterfvSGI(GLenum target, GLenum pname, const GLfloat* params) {
	if (!glColorTableParameterfvSGIproc) return;
	glColorTableParameterfvSGIproc(target, pname, params);
}
PFNGLCOLORTABLEPARAMETERIVSGIPROC glColorTableParameterivSGIproc = 0;
void APIENTRY glColorTableParameterivSGI(GLenum target, GLenum pname, const GLint* params) {
	if (!glColorTableParameterivSGIproc) return;
	glColorTableParameterivSGIproc(target, pname, params);
}
PFNGLCOPYCOLORTABLESGIPROC glCopyColorTableSGIproc = 0;
void APIENTRY glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
	if (!glCopyColorTableSGIproc) return;
	glCopyColorTableSGIproc(target, internalformat, x, y, width);
}
PFNGLGETCOLORTABLESGIPROC glGetColorTableSGIproc = 0;
void APIENTRY glGetColorTableSGI(GLenum target, GLenum format, GLenum type, void* table) {
	if (!glGetColorTableSGIproc) return;
	glGetColorTableSGIproc(target, format, type, table);
}
PFNGLGETCOLORTABLEPARAMETERFVSGIPROC glGetColorTableParameterfvSGIproc = 0;
void APIENTRY glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat* params) {
	if (!glGetColorTableParameterfvSGIproc) return;
	glGetColorTableParameterfvSGIproc(target, pname, params);
}
PFNGLGETCOLORTABLEPARAMETERIVSGIPROC glGetColorTableParameterivSGIproc = 0;
void APIENTRY glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint* params) {
	if (!glGetColorTableParameterivSGIproc) return;
	glGetColorTableParameterivSGIproc(target, pname, params);
}
PFNGLFINISHTEXTURESUNXPROC glFinishTextureSUNXproc = 0;
void APIENTRY glFinishTextureSUNX(void) {
	if (!glFinishTextureSUNXproc) return;
	glFinishTextureSUNXproc();
}
PFNGLGLOBALALPHAFACTORBSUNPROC glGlobalAlphaFactorbSUNproc = 0;
void APIENTRY glGlobalAlphaFactorbSUN(GLbyte factor) {
	if (!glGlobalAlphaFactorbSUNproc) return;
	glGlobalAlphaFactorbSUNproc(factor);
}
PFNGLGLOBALALPHAFACTORSSUNPROC glGlobalAlphaFactorsSUNproc = 0;
void APIENTRY glGlobalAlphaFactorsSUN(GLshort factor) {
	if (!glGlobalAlphaFactorsSUNproc) return;
	glGlobalAlphaFactorsSUNproc(factor);
}
PFNGLGLOBALALPHAFACTORISUNPROC glGlobalAlphaFactoriSUNproc = 0;
void APIENTRY glGlobalAlphaFactoriSUN(GLint factor) {
	if (!glGlobalAlphaFactoriSUNproc) return;
	glGlobalAlphaFactoriSUNproc(factor);
}
PFNGLGLOBALALPHAFACTORFSUNPROC glGlobalAlphaFactorfSUNproc = 0;
void APIENTRY glGlobalAlphaFactorfSUN(GLfloat factor) {
	if (!glGlobalAlphaFactorfSUNproc) return;
	glGlobalAlphaFactorfSUNproc(factor);
}
PFNGLGLOBALALPHAFACTORDSUNPROC glGlobalAlphaFactordSUNproc = 0;
void APIENTRY glGlobalAlphaFactordSUN(GLdouble factor) {
	if (!glGlobalAlphaFactordSUNproc) return;
	glGlobalAlphaFactordSUNproc(factor);
}
PFNGLGLOBALALPHAFACTORUBSUNPROC glGlobalAlphaFactorubSUNproc = 0;
void APIENTRY glGlobalAlphaFactorubSUN(GLubyte factor) {
	if (!glGlobalAlphaFactorubSUNproc) return;
	glGlobalAlphaFactorubSUNproc(factor);
}
PFNGLGLOBALALPHAFACTORUSSUNPROC glGlobalAlphaFactorusSUNproc = 0;
void APIENTRY glGlobalAlphaFactorusSUN(GLushort factor) {
	if (!glGlobalAlphaFactorusSUNproc) return;
	glGlobalAlphaFactorusSUNproc(factor);
}
PFNGLGLOBALALPHAFACTORUISUNPROC glGlobalAlphaFactoruiSUNproc = 0;
void APIENTRY glGlobalAlphaFactoruiSUN(GLuint factor) {
	if (!glGlobalAlphaFactoruiSUNproc) return;
	glGlobalAlphaFactoruiSUNproc(factor);
}
PFNGLDRAWMESHARRAYSSUNPROC glDrawMeshArraysSUNproc = 0;
void APIENTRY glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width) {
	if (!glDrawMeshArraysSUNproc) return;
	glDrawMeshArraysSUNproc(mode, first, count, width);
}
PFNGLREPLACEMENTCODEUISUNPROC glReplacementCodeuiSUNproc = 0;
void APIENTRY glReplacementCodeuiSUN(GLuint code) {
	if (!glReplacementCodeuiSUNproc) return;
	glReplacementCodeuiSUNproc(code);
}
PFNGLREPLACEMENTCODEUSSUNPROC glReplacementCodeusSUNproc = 0;
void APIENTRY glReplacementCodeusSUN(GLushort code) {
	if (!glReplacementCodeusSUNproc) return;
	glReplacementCodeusSUNproc(code);
}
PFNGLREPLACEMENTCODEUBSUNPROC glReplacementCodeubSUNproc = 0;
void APIENTRY glReplacementCodeubSUN(GLubyte code) {
	if (!glReplacementCodeubSUNproc) return;
	glReplacementCodeubSUNproc(code);
}
PFNGLREPLACEMENTCODEUIVSUNPROC glReplacementCodeuivSUNproc = 0;
void APIENTRY glReplacementCodeuivSUN(const GLuint* code) {
	if (!glReplacementCodeuivSUNproc) return;
	glReplacementCodeuivSUNproc(code);
}
PFNGLREPLACEMENTCODEUSVSUNPROC glReplacementCodeusvSUNproc = 0;
void APIENTRY glReplacementCodeusvSUN(const GLushort* code) {
	if (!glReplacementCodeusvSUNproc) return;
	glReplacementCodeusvSUNproc(code);
}
PFNGLREPLACEMENTCODEUBVSUNPROC glReplacementCodeubvSUNproc = 0;
void APIENTRY glReplacementCodeubvSUN(const GLubyte* code) {
	if (!glReplacementCodeubvSUNproc) return;
	glReplacementCodeubvSUNproc(code);
}
PFNGLREPLACEMENTCODEPOINTERSUNPROC glReplacementCodePointerSUNproc = 0;
void APIENTRY glReplacementCodePointerSUN(GLenum type, GLsizei stride, const void** pointer) {
	if (!glReplacementCodePointerSUNproc) return;
	glReplacementCodePointerSUNproc(type, stride, pointer);
}
PFNGLCOLOR4UBVERTEX2FSUNPROC glColor4ubVertex2fSUNproc = 0;
void APIENTRY glColor4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y) {
	if (!glColor4ubVertex2fSUNproc) return;
	glColor4ubVertex2fSUNproc(r, g, b, a, x, y);
}
PFNGLCOLOR4UBVERTEX2FVSUNPROC glColor4ubVertex2fvSUNproc = 0;
void APIENTRY glColor4ubVertex2fvSUN(const GLubyte* c, const GLfloat* v) {
	if (!glColor4ubVertex2fvSUNproc) return;
	glColor4ubVertex2fvSUNproc(c, v);
}
PFNGLCOLOR4UBVERTEX3FSUNPROC glColor4ubVertex3fSUNproc = 0;
void APIENTRY glColor4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
	if (!glColor4ubVertex3fSUNproc) return;
	glColor4ubVertex3fSUNproc(r, g, b, a, x, y, z);
}
PFNGLCOLOR4UBVERTEX3FVSUNPROC glColor4ubVertex3fvSUNproc = 0;
void APIENTRY glColor4ubVertex3fvSUN(const GLubyte* c, const GLfloat* v) {
	if (!glColor4ubVertex3fvSUNproc) return;
	glColor4ubVertex3fvSUNproc(c, v);
}
PFNGLCOLOR3FVERTEX3FSUNPROC glColor3fVertex3fSUNproc = 0;
void APIENTRY glColor3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
	if (!glColor3fVertex3fSUNproc) return;
	glColor3fVertex3fSUNproc(r, g, b, x, y, z);
}
PFNGLCOLOR3FVERTEX3FVSUNPROC glColor3fVertex3fvSUNproc = 0;
void APIENTRY glColor3fVertex3fvSUN(const GLfloat* c, const GLfloat* v) {
	if (!glColor3fVertex3fvSUNproc) return;
	glColor3fVertex3fvSUNproc(c, v);
}
PFNGLNORMAL3FVERTEX3FSUNPROC glNormal3fVertex3fSUNproc = 0;
void APIENTRY glNormal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glNormal3fVertex3fSUNproc) return;
	glNormal3fVertex3fSUNproc(nx, ny, nz, x, y, z);
}
PFNGLNORMAL3FVERTEX3FVSUNPROC glNormal3fVertex3fvSUNproc = 0;
void APIENTRY glNormal3fVertex3fvSUN(const GLfloat* n, const GLfloat* v) {
	if (!glNormal3fVertex3fvSUNproc) return;
	glNormal3fVertex3fvSUNproc(n, v);
}
PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glColor4fNormal3fVertex3fSUNproc = 0;
void APIENTRY glColor4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glColor4fNormal3fVertex3fSUNproc) return;
	glColor4fNormal3fVertex3fSUNproc(r, g, b, a, nx, ny, nz, x, y, z);
}
PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glColor4fNormal3fVertex3fvSUNproc = 0;
void APIENTRY glColor4fNormal3fVertex3fvSUN(const GLfloat* c, const GLfloat* n, const GLfloat* v) {
	if (!glColor4fNormal3fVertex3fvSUNproc) return;
	glColor4fNormal3fVertex3fvSUNproc(c, n, v);
}
PFNGLTEXCOORD2FVERTEX3FSUNPROC glTexCoord2fVertex3fSUNproc = 0;
void APIENTRY glTexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
	if (!glTexCoord2fVertex3fSUNproc) return;
	glTexCoord2fVertex3fSUNproc(s, t, x, y, z);
}
PFNGLTEXCOORD2FVERTEX3FVSUNPROC glTexCoord2fVertex3fvSUNproc = 0;
void APIENTRY glTexCoord2fVertex3fvSUN(const GLfloat* tc, const GLfloat* v) {
	if (!glTexCoord2fVertex3fvSUNproc) return;
	glTexCoord2fVertex3fvSUNproc(tc, v);
}
PFNGLTEXCOORD4FVERTEX4FSUNPROC glTexCoord4fVertex4fSUNproc = 0;
void APIENTRY glTexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glTexCoord4fVertex4fSUNproc) return;
	glTexCoord4fVertex4fSUNproc(s, t, p, q, x, y, z, w);
}
PFNGLTEXCOORD4FVERTEX4FVSUNPROC glTexCoord4fVertex4fvSUNproc = 0;
void APIENTRY glTexCoord4fVertex4fvSUN(const GLfloat* tc, const GLfloat* v) {
	if (!glTexCoord4fVertex4fvSUNproc) return;
	glTexCoord4fVertex4fvSUNproc(tc, v);
}
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glTexCoord2fColor4ubVertex3fSUNproc = 0;
void APIENTRY glTexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
	if (!glTexCoord2fColor4ubVertex3fSUNproc) return;
	glTexCoord2fColor4ubVertex3fSUNproc(s, t, r, g, b, a, x, y, z);
}
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glTexCoord2fColor4ubVertex3fvSUNproc = 0;
void APIENTRY glTexCoord2fColor4ubVertex3fvSUN(const GLfloat* tc, const GLubyte* c, const GLfloat* v) {
	if (!glTexCoord2fColor4ubVertex3fvSUNproc) return;
	glTexCoord2fColor4ubVertex3fvSUNproc(tc, c, v);
}
PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glTexCoord2fColor3fVertex3fSUNproc = 0;
void APIENTRY glTexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
	if (!glTexCoord2fColor3fVertex3fSUNproc) return;
	glTexCoord2fColor3fVertex3fSUNproc(s, t, r, g, b, x, y, z);
}
PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glTexCoord2fColor3fVertex3fvSUNproc = 0;
void APIENTRY glTexCoord2fColor3fVertex3fvSUN(const GLfloat* tc, const GLfloat* c, const GLfloat* v) {
	if (!glTexCoord2fColor3fVertex3fvSUNproc) return;
	glTexCoord2fColor3fVertex3fvSUNproc(tc, c, v);
}
PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glTexCoord2fNormal3fVertex3fSUNproc = 0;
void APIENTRY glTexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glTexCoord2fNormal3fVertex3fSUNproc) return;
	glTexCoord2fNormal3fVertex3fSUNproc(s, t, nx, ny, nz, x, y, z);
}
PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fNormal3fVertex3fvSUNproc = 0;
void APIENTRY glTexCoord2fNormal3fVertex3fvSUN(const GLfloat* tc, const GLfloat* n, const GLfloat* v) {
	if (!glTexCoord2fNormal3fVertex3fvSUNproc) return;
	glTexCoord2fNormal3fVertex3fvSUNproc(tc, n, v);
}
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glTexCoord2fColor4fNormal3fVertex3fSUNproc = 0;
void APIENTRY glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glTexCoord2fColor4fNormal3fVertex3fSUNproc) return;
	glTexCoord2fColor4fNormal3fVertex3fSUNproc(s, t, r, g, b, a, nx, ny, nz, x, y, z);
}
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fColor4fNormal3fVertex3fvSUNproc = 0;
void APIENTRY glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v) {
	if (!glTexCoord2fColor4fNormal3fVertex3fvSUNproc) return;
	glTexCoord2fColor4fNormal3fVertex3fvSUNproc(tc, c, n, v);
}
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glTexCoord4fColor4fNormal3fVertex4fSUNproc = 0;
void APIENTRY glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	if (!glTexCoord4fColor4fNormal3fVertex4fSUNproc) return;
	glTexCoord4fColor4fNormal3fVertex4fSUNproc(s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w);
}
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glTexCoord4fColor4fNormal3fVertex4fvSUNproc = 0;
void APIENTRY glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v) {
	if (!glTexCoord4fColor4fNormal3fVertex4fvSUNproc) return;
	glTexCoord4fColor4fNormal3fVertex4fvSUNproc(tc, c, n, v);
}
PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glReplacementCodeuiVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiVertex3fSUNproc) return;
	glReplacementCodeuiVertex3fSUNproc(rc, x, y, z);
}
PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glReplacementCodeuiVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiVertex3fvSUN(const GLuint* rc, const GLfloat* v) {
	if (!glReplacementCodeuiVertex3fvSUNproc) return;
	glReplacementCodeuiVertex3fvSUNproc(rc, v);
}
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glReplacementCodeuiColor4ubVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiColor4ubVertex3fSUNproc) return;
	glReplacementCodeuiColor4ubVertex3fSUNproc(rc, r, g, b, a, x, y, z);
}
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glReplacementCodeuiColor4ubVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint* rc, const GLubyte* c, const GLfloat* v) {
	if (!glReplacementCodeuiColor4ubVertex3fvSUNproc) return;
	glReplacementCodeuiColor4ubVertex3fvSUNproc(rc, c, v);
}
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glReplacementCodeuiColor3fVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiColor3fVertex3fSUNproc) return;
	glReplacementCodeuiColor3fVertex3fSUNproc(rc, r, g, b, x, y, z);
}
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glReplacementCodeuiColor3fVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiColor3fVertex3fvSUN(const GLuint* rc, const GLfloat* c, const GLfloat* v) {
	if (!glReplacementCodeuiColor3fVertex3fvSUNproc) return;
	glReplacementCodeuiColor3fVertex3fvSUNproc(rc, c, v);
}
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glReplacementCodeuiNormal3fVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiNormal3fVertex3fSUNproc) return;
	glReplacementCodeuiNormal3fVertex3fSUNproc(rc, nx, ny, nz, x, y, z);
}
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiNormal3fVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* n, const GLfloat* v) {
	if (!glReplacementCodeuiNormal3fVertex3fvSUNproc) return;
	glReplacementCodeuiNormal3fVertex3fvSUNproc(rc, n, v);
}
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiColor4fNormal3fVertex3fSUNproc) return;
	glReplacementCodeuiColor4fNormal3fVertex3fSUNproc(rc, r, g, b, a, nx, ny, nz, x, y, z);
}
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* c, const GLfloat* n, const GLfloat* v) {
	if (!glReplacementCodeuiColor4fNormal3fVertex3fvSUNproc) return;
	glReplacementCodeuiColor4fNormal3fVertex3fvSUNproc(rc, c, n, v);
}
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiTexCoord2fVertex3fSUNproc) return;
	glReplacementCodeuiTexCoord2fVertex3fSUNproc(rc, s, t, x, y, z);
}
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint* rc, const GLfloat* tc, const GLfloat* v) {
	if (!glReplacementCodeuiTexCoord2fVertex3fvSUNproc) return;
	glReplacementCodeuiTexCoord2fVertex3fvSUNproc(rc, tc, v);
}
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiTexCoord2fNormal3fVertex3fSUNproc) return;
	glReplacementCodeuiTexCoord2fNormal3fVertex3fSUNproc(rc, s, t, nx, ny, nz, x, y, z);
}
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* tc, const GLfloat* n, const GLfloat* v) {
	if (!glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUNproc) return;
	glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUNproc(rc, tc, n, v);
}
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUNproc = 0;
void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
	if (!glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUNproc) return;
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUNproc(rc, s, t, r, g, b, a, nx, ny, nz, x, y, z);
}
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUNproc = 0;
void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v) {
	if (!glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUNproc) return;
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUNproc(rc, tc, c, n, v);
}
void glextInit() {
	glDrawRangeElementsproc = (PFNGLDRAWRANGEELEMENTSPROC)wglGetProcAddress("glDrawRangeElements");
	glTexImage3Dproc = (PFNGLTEXIMAGE3DPROC)wglGetProcAddress("glTexImage3D");
	glTexSubImage3Dproc = (PFNGLTEXSUBIMAGE3DPROC)wglGetProcAddress("glTexSubImage3D");
	glCopyTexSubImage3Dproc = (PFNGLCOPYTEXSUBIMAGE3DPROC)wglGetProcAddress("glCopyTexSubImage3D");
	glActiveTextureproc = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	glSampleCoverageproc = (PFNGLSAMPLECOVERAGEPROC)wglGetProcAddress("glSampleCoverage");
	glCompressedTexImage3Dproc = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)wglGetProcAddress("glCompressedTexImage3D");
	glCompressedTexImage2Dproc = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
	glCompressedTexImage1Dproc = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)wglGetProcAddress("glCompressedTexImage1D");
	glCompressedTexSubImage3Dproc = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)wglGetProcAddress("glCompressedTexSubImage3D");
	glCompressedTexSubImage2Dproc = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)wglGetProcAddress("glCompressedTexSubImage2D");
	glCompressedTexSubImage1Dproc = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)wglGetProcAddress("glCompressedTexSubImage1D");
	glGetCompressedTexImageproc = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetCompressedTexImage");
	glClientActiveTextureproc = (PFNGLCLIENTACTIVETEXTUREPROC)wglGetProcAddress("glClientActiveTexture");
	glMultiTexCoord1dproc = (PFNGLMULTITEXCOORD1DPROC)wglGetProcAddress("glMultiTexCoord1d");
	glMultiTexCoord1dvproc = (PFNGLMULTITEXCOORD1DVPROC)wglGetProcAddress("glMultiTexCoord1dv");
	glMultiTexCoord1fproc = (PFNGLMULTITEXCOORD1FPROC)wglGetProcAddress("glMultiTexCoord1f");
	glMultiTexCoord1fvproc = (PFNGLMULTITEXCOORD1FVPROC)wglGetProcAddress("glMultiTexCoord1fv");
	glMultiTexCoord1iproc = (PFNGLMULTITEXCOORD1IPROC)wglGetProcAddress("glMultiTexCoord1i");
	glMultiTexCoord1ivproc = (PFNGLMULTITEXCOORD1IVPROC)wglGetProcAddress("glMultiTexCoord1iv");
	glMultiTexCoord1sproc = (PFNGLMULTITEXCOORD1SPROC)wglGetProcAddress("glMultiTexCoord1s");
	glMultiTexCoord1svproc = (PFNGLMULTITEXCOORD1SVPROC)wglGetProcAddress("glMultiTexCoord1sv");
	glMultiTexCoord2dproc = (PFNGLMULTITEXCOORD2DPROC)wglGetProcAddress("glMultiTexCoord2d");
	glMultiTexCoord2dvproc = (PFNGLMULTITEXCOORD2DVPROC)wglGetProcAddress("glMultiTexCoord2dv");
	glMultiTexCoord2fproc = (PFNGLMULTITEXCOORD2FPROC)wglGetProcAddress("glMultiTexCoord2f");
	glMultiTexCoord2fvproc = (PFNGLMULTITEXCOORD2FVPROC)wglGetProcAddress("glMultiTexCoord2fv");
	glMultiTexCoord2iproc = (PFNGLMULTITEXCOORD2IPROC)wglGetProcAddress("glMultiTexCoord2i");
	glMultiTexCoord2ivproc = (PFNGLMULTITEXCOORD2IVPROC)wglGetProcAddress("glMultiTexCoord2iv");
	glMultiTexCoord2sproc = (PFNGLMULTITEXCOORD2SPROC)wglGetProcAddress("glMultiTexCoord2s");
	glMultiTexCoord2svproc = (PFNGLMULTITEXCOORD2SVPROC)wglGetProcAddress("glMultiTexCoord2sv");
	glMultiTexCoord3dproc = (PFNGLMULTITEXCOORD3DPROC)wglGetProcAddress("glMultiTexCoord3d");
	glMultiTexCoord3dvproc = (PFNGLMULTITEXCOORD3DVPROC)wglGetProcAddress("glMultiTexCoord3dv");
	glMultiTexCoord3fproc = (PFNGLMULTITEXCOORD3FPROC)wglGetProcAddress("glMultiTexCoord3f");
	glMultiTexCoord3fvproc = (PFNGLMULTITEXCOORD3FVPROC)wglGetProcAddress("glMultiTexCoord3fv");
	glMultiTexCoord3iproc = (PFNGLMULTITEXCOORD3IPROC)wglGetProcAddress("glMultiTexCoord3i");
	glMultiTexCoord3ivproc = (PFNGLMULTITEXCOORD3IVPROC)wglGetProcAddress("glMultiTexCoord3iv");
	glMultiTexCoord3sproc = (PFNGLMULTITEXCOORD3SPROC)wglGetProcAddress("glMultiTexCoord3s");
	glMultiTexCoord3svproc = (PFNGLMULTITEXCOORD3SVPROC)wglGetProcAddress("glMultiTexCoord3sv");
	glMultiTexCoord4dproc = (PFNGLMULTITEXCOORD4DPROC)wglGetProcAddress("glMultiTexCoord4d");
	glMultiTexCoord4dvproc = (PFNGLMULTITEXCOORD4DVPROC)wglGetProcAddress("glMultiTexCoord4dv");
	glMultiTexCoord4fproc = (PFNGLMULTITEXCOORD4FPROC)wglGetProcAddress("glMultiTexCoord4f");
	glMultiTexCoord4fvproc = (PFNGLMULTITEXCOORD4FVPROC)wglGetProcAddress("glMultiTexCoord4fv");
	glMultiTexCoord4iproc = (PFNGLMULTITEXCOORD4IPROC)wglGetProcAddress("glMultiTexCoord4i");
	glMultiTexCoord4ivproc = (PFNGLMULTITEXCOORD4IVPROC)wglGetProcAddress("glMultiTexCoord4iv");
	glMultiTexCoord4sproc = (PFNGLMULTITEXCOORD4SPROC)wglGetProcAddress("glMultiTexCoord4s");
	glMultiTexCoord4svproc = (PFNGLMULTITEXCOORD4SVPROC)wglGetProcAddress("glMultiTexCoord4sv");
	glLoadTransposeMatrixfproc = (PFNGLLOADTRANSPOSEMATRIXFPROC)wglGetProcAddress("glLoadTransposeMatrixf");
	glLoadTransposeMatrixdproc = (PFNGLLOADTRANSPOSEMATRIXDPROC)wglGetProcAddress("glLoadTransposeMatrixd");
	glMultTransposeMatrixfproc = (PFNGLMULTTRANSPOSEMATRIXFPROC)wglGetProcAddress("glMultTransposeMatrixf");
	glMultTransposeMatrixdproc = (PFNGLMULTTRANSPOSEMATRIXDPROC)wglGetProcAddress("glMultTransposeMatrixd");
	glBlendFuncSeparateproc = (PFNGLBLENDFUNCSEPARATEPROC)wglGetProcAddress("glBlendFuncSeparate");
	glMultiDrawArraysproc = (PFNGLMULTIDRAWARRAYSPROC)wglGetProcAddress("glMultiDrawArrays");
	glMultiDrawElementsproc = (PFNGLMULTIDRAWELEMENTSPROC)wglGetProcAddress("glMultiDrawElements");
	glPointParameterfproc = (PFNGLPOINTPARAMETERFPROC)wglGetProcAddress("glPointParameterf");
	glPointParameterfvproc = (PFNGLPOINTPARAMETERFVPROC)wglGetProcAddress("glPointParameterfv");
	glPointParameteriproc = (PFNGLPOINTPARAMETERIPROC)wglGetProcAddress("glPointParameteri");
	glPointParameterivproc = (PFNGLPOINTPARAMETERIVPROC)wglGetProcAddress("glPointParameteriv");
	glFogCoordfproc = (PFNGLFOGCOORDFPROC)wglGetProcAddress("glFogCoordf");
	glFogCoordfvproc = (PFNGLFOGCOORDFVPROC)wglGetProcAddress("glFogCoordfv");
	glFogCoorddproc = (PFNGLFOGCOORDDPROC)wglGetProcAddress("glFogCoordd");
	glFogCoorddvproc = (PFNGLFOGCOORDDVPROC)wglGetProcAddress("glFogCoorddv");
	glFogCoordPointerproc = (PFNGLFOGCOORDPOINTERPROC)wglGetProcAddress("glFogCoordPointer");
	glSecondaryColor3bproc = (PFNGLSECONDARYCOLOR3BPROC)wglGetProcAddress("glSecondaryColor3b");
	glSecondaryColor3bvproc = (PFNGLSECONDARYCOLOR3BVPROC)wglGetProcAddress("glSecondaryColor3bv");
	glSecondaryColor3dproc = (PFNGLSECONDARYCOLOR3DPROC)wglGetProcAddress("glSecondaryColor3d");
	glSecondaryColor3dvproc = (PFNGLSECONDARYCOLOR3DVPROC)wglGetProcAddress("glSecondaryColor3dv");
	glSecondaryColor3fproc = (PFNGLSECONDARYCOLOR3FPROC)wglGetProcAddress("glSecondaryColor3f");
	glSecondaryColor3fvproc = (PFNGLSECONDARYCOLOR3FVPROC)wglGetProcAddress("glSecondaryColor3fv");
	glSecondaryColor3iproc = (PFNGLSECONDARYCOLOR3IPROC)wglGetProcAddress("glSecondaryColor3i");
	glSecondaryColor3ivproc = (PFNGLSECONDARYCOLOR3IVPROC)wglGetProcAddress("glSecondaryColor3iv");
	glSecondaryColor3sproc = (PFNGLSECONDARYCOLOR3SPROC)wglGetProcAddress("glSecondaryColor3s");
	glSecondaryColor3svproc = (PFNGLSECONDARYCOLOR3SVPROC)wglGetProcAddress("glSecondaryColor3sv");
	glSecondaryColor3ubproc = (PFNGLSECONDARYCOLOR3UBPROC)wglGetProcAddress("glSecondaryColor3ub");
	glSecondaryColor3ubvproc = (PFNGLSECONDARYCOLOR3UBVPROC)wglGetProcAddress("glSecondaryColor3ubv");
	glSecondaryColor3uiproc = (PFNGLSECONDARYCOLOR3UIPROC)wglGetProcAddress("glSecondaryColor3ui");
	glSecondaryColor3uivproc = (PFNGLSECONDARYCOLOR3UIVPROC)wglGetProcAddress("glSecondaryColor3uiv");
	glSecondaryColor3usproc = (PFNGLSECONDARYCOLOR3USPROC)wglGetProcAddress("glSecondaryColor3us");
	glSecondaryColor3usvproc = (PFNGLSECONDARYCOLOR3USVPROC)wglGetProcAddress("glSecondaryColor3usv");
	glSecondaryColorPointerproc = (PFNGLSECONDARYCOLORPOINTERPROC)wglGetProcAddress("glSecondaryColorPointer");
	glWindowPos2dproc = (PFNGLWINDOWPOS2DPROC)wglGetProcAddress("glWindowPos2d");
	glWindowPos2dvproc = (PFNGLWINDOWPOS2DVPROC)wglGetProcAddress("glWindowPos2dv");
	glWindowPos2fproc = (PFNGLWINDOWPOS2FPROC)wglGetProcAddress("glWindowPos2f");
	glWindowPos2fvproc = (PFNGLWINDOWPOS2FVPROC)wglGetProcAddress("glWindowPos2fv");
	glWindowPos2iproc = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress("glWindowPos2i");
	glWindowPos2ivproc = (PFNGLWINDOWPOS2IVPROC)wglGetProcAddress("glWindowPos2iv");
	glWindowPos2sproc = (PFNGLWINDOWPOS2SPROC)wglGetProcAddress("glWindowPos2s");
	glWindowPos2svproc = (PFNGLWINDOWPOS2SVPROC)wglGetProcAddress("glWindowPos2sv");
	glWindowPos3dproc = (PFNGLWINDOWPOS3DPROC)wglGetProcAddress("glWindowPos3d");
	glWindowPos3dvproc = (PFNGLWINDOWPOS3DVPROC)wglGetProcAddress("glWindowPos3dv");
	glWindowPos3fproc = (PFNGLWINDOWPOS3FPROC)wglGetProcAddress("glWindowPos3f");
	glWindowPos3fvproc = (PFNGLWINDOWPOS3FVPROC)wglGetProcAddress("glWindowPos3fv");
	glWindowPos3iproc = (PFNGLWINDOWPOS3IPROC)wglGetProcAddress("glWindowPos3i");
	glWindowPos3ivproc = (PFNGLWINDOWPOS3IVPROC)wglGetProcAddress("glWindowPos3iv");
	glWindowPos3sproc = (PFNGLWINDOWPOS3SPROC)wglGetProcAddress("glWindowPos3s");
	glWindowPos3svproc = (PFNGLWINDOWPOS3SVPROC)wglGetProcAddress("glWindowPos3sv");
	glBlendColorproc = (PFNGLBLENDCOLORPROC)wglGetProcAddress("glBlendColor");
	glBlendEquationproc = (PFNGLBLENDEQUATIONPROC)wglGetProcAddress("glBlendEquation");
	glGenQueriesproc = (PFNGLGENQUERIESPROC)wglGetProcAddress("glGenQueries");
	glDeleteQueriesproc = (PFNGLDELETEQUERIESPROC)wglGetProcAddress("glDeleteQueries");
	glIsQueryproc = (PFNGLISQUERYPROC)wglGetProcAddress("glIsQuery");
	glBeginQueryproc = (PFNGLBEGINQUERYPROC)wglGetProcAddress("glBeginQuery");
	glEndQueryproc = (PFNGLENDQUERYPROC)wglGetProcAddress("glEndQuery");
	glGetQueryivproc = (PFNGLGETQUERYIVPROC)wglGetProcAddress("glGetQueryiv");
	glGetQueryObjectivproc = (PFNGLGETQUERYOBJECTIVPROC)wglGetProcAddress("glGetQueryObjectiv");
	glGetQueryObjectuivproc = (PFNGLGETQUERYOBJECTUIVPROC)wglGetProcAddress("glGetQueryObjectuiv");
	glBindBufferproc = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glDeleteBuffersproc = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
	glGenBuffersproc = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	glIsBufferproc = (PFNGLISBUFFERPROC)wglGetProcAddress("glIsBuffer");
	glBufferDataproc = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	glBufferSubDataproc = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
	glGetBufferSubDataproc = (PFNGLGETBUFFERSUBDATAPROC)wglGetProcAddress("glGetBufferSubData");
	glMapBufferproc = (PFNGLMAPBUFFERPROC)wglGetProcAddress("glMapBuffer");
	glUnmapBufferproc = (PFNGLUNMAPBUFFERPROC)wglGetProcAddress("glUnmapBuffer");
	glGetBufferParameterivproc = (PFNGLGETBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetBufferParameteriv");
	glGetBufferPointervproc = (PFNGLGETBUFFERPOINTERVPROC)wglGetProcAddress("glGetBufferPointerv");
	glBlendEquationSeparateproc = (PFNGLBLENDEQUATIONSEPARATEPROC)wglGetProcAddress("glBlendEquationSeparate");
	glDrawBuffersproc = (PFNGLDRAWBUFFERSPROC)wglGetProcAddress("glDrawBuffers");
	glStencilOpSeparateproc = (PFNGLSTENCILOPSEPARATEPROC)wglGetProcAddress("glStencilOpSeparate");
	glStencilFuncSeparateproc = (PFNGLSTENCILFUNCSEPARATEPROC)wglGetProcAddress("glStencilFuncSeparate");
	glStencilMaskSeparateproc = (PFNGLSTENCILMASKSEPARATEPROC)wglGetProcAddress("glStencilMaskSeparate");
	glAttachShaderproc = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	glBindAttribLocationproc = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	glCompileShaderproc = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	glCreateProgramproc = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	glCreateShaderproc = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	glDeleteProgramproc = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	glDeleteShaderproc = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	glDetachShaderproc = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	glDisableVertexAttribArrayproc = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
	glEnableVertexAttribArrayproc = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	glGetActiveAttribproc = (PFNGLGETACTIVEATTRIBPROC)wglGetProcAddress("glGetActiveAttrib");
	glGetActiveUniformproc = (PFNGLGETACTIVEUNIFORMPROC)wglGetProcAddress("glGetActiveUniform");
	glGetAttachedShadersproc = (PFNGLGETATTACHEDSHADERSPROC)wglGetProcAddress("glGetAttachedShaders");
	glGetAttribLocationproc = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	glGetProgramivproc = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	glGetProgramInfoLogproc = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	glGetShaderivproc = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	glGetShaderInfoLogproc = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	glGetShaderSourceproc = (PFNGLGETSHADERSOURCEPROC)wglGetProcAddress("glGetShaderSource");
	glGetUniformLocationproc = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	glGetUniformfvproc = (PFNGLGETUNIFORMFVPROC)wglGetProcAddress("glGetUniformfv");
	glGetUniformivproc = (PFNGLGETUNIFORMIVPROC)wglGetProcAddress("glGetUniformiv");
	glGetVertexAttribdvproc = (PFNGLGETVERTEXATTRIBDVPROC)wglGetProcAddress("glGetVertexAttribdv");
	glGetVertexAttribfvproc = (PFNGLGETVERTEXATTRIBFVPROC)wglGetProcAddress("glGetVertexAttribfv");
	glGetVertexAttribivproc = (PFNGLGETVERTEXATTRIBIVPROC)wglGetProcAddress("glGetVertexAttribiv");
	glGetVertexAttribPointervproc = (PFNGLGETVERTEXATTRIBPOINTERVPROC)wglGetProcAddress("glGetVertexAttribPointerv");
	glIsProgramproc = (PFNGLISPROGRAMPROC)wglGetProcAddress("glIsProgram");
	glIsShaderproc = (PFNGLISSHADERPROC)wglGetProcAddress("glIsShader");
	glLinkProgramproc = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	glShaderSourceproc = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	glUseProgramproc = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	glUniform1fproc = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	glUniform2fproc = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
	glUniform3fproc = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
	glUniform4fproc = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
	glUniform1iproc = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	glUniform2iproc = (PFNGLUNIFORM2IPROC)wglGetProcAddress("glUniform2i");
	glUniform3iproc = (PFNGLUNIFORM3IPROC)wglGetProcAddress("glUniform3i");
	glUniform4iproc = (PFNGLUNIFORM4IPROC)wglGetProcAddress("glUniform4i");
	glUniform1fvproc = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
	glUniform2fvproc = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
	glUniform3fvproc = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	glUniform4fvproc = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	glUniform1ivproc = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
	glUniform2ivproc = (PFNGLUNIFORM2IVPROC)wglGetProcAddress("glUniform2iv");
	glUniform3ivproc = (PFNGLUNIFORM3IVPROC)wglGetProcAddress("glUniform3iv");
	glUniform4ivproc = (PFNGLUNIFORM4IVPROC)wglGetProcAddress("glUniform4iv");
	glUniformMatrix2fvproc = (PFNGLUNIFORMMATRIX2FVPROC)wglGetProcAddress("glUniformMatrix2fv");
	glUniformMatrix3fvproc = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
	glUniformMatrix4fvproc = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	glValidateProgramproc = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
	glVertexAttrib1dproc = (PFNGLVERTEXATTRIB1DPROC)wglGetProcAddress("glVertexAttrib1d");
	glVertexAttrib1dvproc = (PFNGLVERTEXATTRIB1DVPROC)wglGetProcAddress("glVertexAttrib1dv");
	glVertexAttrib1fproc = (PFNGLVERTEXATTRIB1FPROC)wglGetProcAddress("glVertexAttrib1f");
	glVertexAttrib1fvproc = (PFNGLVERTEXATTRIB1FVPROC)wglGetProcAddress("glVertexAttrib1fv");
	glVertexAttrib1sproc = (PFNGLVERTEXATTRIB1SPROC)wglGetProcAddress("glVertexAttrib1s");
	glVertexAttrib1svproc = (PFNGLVERTEXATTRIB1SVPROC)wglGetProcAddress("glVertexAttrib1sv");
	glVertexAttrib2dproc = (PFNGLVERTEXATTRIB2DPROC)wglGetProcAddress("glVertexAttrib2d");
	glVertexAttrib2dvproc = (PFNGLVERTEXATTRIB2DVPROC)wglGetProcAddress("glVertexAttrib2dv");
	glVertexAttrib2fproc = (PFNGLVERTEXATTRIB2FPROC)wglGetProcAddress("glVertexAttrib2f");
	glVertexAttrib2fvproc = (PFNGLVERTEXATTRIB2FVPROC)wglGetProcAddress("glVertexAttrib2fv");
	glVertexAttrib2sproc = (PFNGLVERTEXATTRIB2SPROC)wglGetProcAddress("glVertexAttrib2s");
	glVertexAttrib2svproc = (PFNGLVERTEXATTRIB2SVPROC)wglGetProcAddress("glVertexAttrib2sv");
	glVertexAttrib3dproc = (PFNGLVERTEXATTRIB3DPROC)wglGetProcAddress("glVertexAttrib3d");
	glVertexAttrib3dvproc = (PFNGLVERTEXATTRIB3DVPROC)wglGetProcAddress("glVertexAttrib3dv");
	glVertexAttrib3fproc = (PFNGLVERTEXATTRIB3FPROC)wglGetProcAddress("glVertexAttrib3f");
	glVertexAttrib3fvproc = (PFNGLVERTEXATTRIB3FVPROC)wglGetProcAddress("glVertexAttrib3fv");
	glVertexAttrib3sproc = (PFNGLVERTEXATTRIB3SPROC)wglGetProcAddress("glVertexAttrib3s");
	glVertexAttrib3svproc = (PFNGLVERTEXATTRIB3SVPROC)wglGetProcAddress("glVertexAttrib3sv");
	glVertexAttrib4Nbvproc = (PFNGLVERTEXATTRIB4NBVPROC)wglGetProcAddress("glVertexAttrib4Nbv");
	glVertexAttrib4Nivproc = (PFNGLVERTEXATTRIB4NIVPROC)wglGetProcAddress("glVertexAttrib4Niv");
	glVertexAttrib4Nsvproc = (PFNGLVERTEXATTRIB4NSVPROC)wglGetProcAddress("glVertexAttrib4Nsv");
	glVertexAttrib4Nubproc = (PFNGLVERTEXATTRIB4NUBPROC)wglGetProcAddress("glVertexAttrib4Nub");
	glVertexAttrib4Nubvproc = (PFNGLVERTEXATTRIB4NUBVPROC)wglGetProcAddress("glVertexAttrib4Nubv");
	glVertexAttrib4Nuivproc = (PFNGLVERTEXATTRIB4NUIVPROC)wglGetProcAddress("glVertexAttrib4Nuiv");
	glVertexAttrib4Nusvproc = (PFNGLVERTEXATTRIB4NUSVPROC)wglGetProcAddress("glVertexAttrib4Nusv");
	glVertexAttrib4bvproc = (PFNGLVERTEXATTRIB4BVPROC)wglGetProcAddress("glVertexAttrib4bv");
	glVertexAttrib4dproc = (PFNGLVERTEXATTRIB4DPROC)wglGetProcAddress("glVertexAttrib4d");
	glVertexAttrib4dvproc = (PFNGLVERTEXATTRIB4DVPROC)wglGetProcAddress("glVertexAttrib4dv");
	glVertexAttrib4fproc = (PFNGLVERTEXATTRIB4FPROC)wglGetProcAddress("glVertexAttrib4f");
	glVertexAttrib4fvproc = (PFNGLVERTEXATTRIB4FVPROC)wglGetProcAddress("glVertexAttrib4fv");
	glVertexAttrib4ivproc = (PFNGLVERTEXATTRIB4IVPROC)wglGetProcAddress("glVertexAttrib4iv");
	glVertexAttrib4sproc = (PFNGLVERTEXATTRIB4SPROC)wglGetProcAddress("glVertexAttrib4s");
	glVertexAttrib4svproc = (PFNGLVERTEXATTRIB4SVPROC)wglGetProcAddress("glVertexAttrib4sv");
	glVertexAttrib4ubvproc = (PFNGLVERTEXATTRIB4UBVPROC)wglGetProcAddress("glVertexAttrib4ubv");
	glVertexAttrib4uivproc = (PFNGLVERTEXATTRIB4UIVPROC)wglGetProcAddress("glVertexAttrib4uiv");
	glVertexAttrib4usvproc = (PFNGLVERTEXATTRIB4USVPROC)wglGetProcAddress("glVertexAttrib4usv");
	glVertexAttribPointerproc = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	glUniformMatrix2x3fvproc = (PFNGLUNIFORMMATRIX2X3FVPROC)wglGetProcAddress("glUniformMatrix2x3fv");
	glUniformMatrix3x2fvproc = (PFNGLUNIFORMMATRIX3X2FVPROC)wglGetProcAddress("glUniformMatrix3x2fv");
	glUniformMatrix2x4fvproc = (PFNGLUNIFORMMATRIX2X4FVPROC)wglGetProcAddress("glUniformMatrix2x4fv");
	glUniformMatrix4x2fvproc = (PFNGLUNIFORMMATRIX4X2FVPROC)wglGetProcAddress("glUniformMatrix4x2fv");
	glUniformMatrix3x4fvproc = (PFNGLUNIFORMMATRIX3X4FVPROC)wglGetProcAddress("glUniformMatrix3x4fv");
	glUniformMatrix4x3fvproc = (PFNGLUNIFORMMATRIX4X3FVPROC)wglGetProcAddress("glUniformMatrix4x3fv");
	glColorMaskiproc = (PFNGLCOLORMASKIPROC)wglGetProcAddress("glColorMaski");
	glGetBooleani_vproc = (PFNGLGETBOOLEANI_VPROC)wglGetProcAddress("glGetBooleani_v");
	glGetIntegeri_vproc = (PFNGLGETINTEGERI_VPROC)wglGetProcAddress("glGetIntegeri_v");
	glEnableiproc = (PFNGLENABLEIPROC)wglGetProcAddress("glEnablei");
	glDisableiproc = (PFNGLDISABLEIPROC)wglGetProcAddress("glDisablei");
	glIsEnablediproc = (PFNGLISENABLEDIPROC)wglGetProcAddress("glIsEnabledi");
	glBeginTransformFeedbackproc = (PFNGLBEGINTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBeginTransformFeedback");
	glEndTransformFeedbackproc = (PFNGLENDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glEndTransformFeedback");
	glBindBufferRangeproc = (PFNGLBINDBUFFERRANGEPROC)wglGetProcAddress("glBindBufferRange");
	glBindBufferBaseproc = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase");
	glTransformFeedbackVaryingsproc = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)wglGetProcAddress("glTransformFeedbackVaryings");
	glGetTransformFeedbackVaryingproc = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)wglGetProcAddress("glGetTransformFeedbackVarying");
	glClampColorproc = (PFNGLCLAMPCOLORPROC)wglGetProcAddress("glClampColor");
	glBeginConditionalRenderproc = (PFNGLBEGINCONDITIONALRENDERPROC)wglGetProcAddress("glBeginConditionalRender");
	glEndConditionalRenderproc = (PFNGLENDCONDITIONALRENDERPROC)wglGetProcAddress("glEndConditionalRender");
	glVertexAttribIPointerproc = (PFNGLVERTEXATTRIBIPOINTERPROC)wglGetProcAddress("glVertexAttribIPointer");
	glGetVertexAttribIivproc = (PFNGLGETVERTEXATTRIBIIVPROC)wglGetProcAddress("glGetVertexAttribIiv");
	glGetVertexAttribIuivproc = (PFNGLGETVERTEXATTRIBIUIVPROC)wglGetProcAddress("glGetVertexAttribIuiv");
	glVertexAttribI1iproc = (PFNGLVERTEXATTRIBI1IPROC)wglGetProcAddress("glVertexAttribI1i");
	glVertexAttribI2iproc = (PFNGLVERTEXATTRIBI2IPROC)wglGetProcAddress("glVertexAttribI2i");
	glVertexAttribI3iproc = (PFNGLVERTEXATTRIBI3IPROC)wglGetProcAddress("glVertexAttribI3i");
	glVertexAttribI4iproc = (PFNGLVERTEXATTRIBI4IPROC)wglGetProcAddress("glVertexAttribI4i");
	glVertexAttribI1uiproc = (PFNGLVERTEXATTRIBI1UIPROC)wglGetProcAddress("glVertexAttribI1ui");
	glVertexAttribI2uiproc = (PFNGLVERTEXATTRIBI2UIPROC)wglGetProcAddress("glVertexAttribI2ui");
	glVertexAttribI3uiproc = (PFNGLVERTEXATTRIBI3UIPROC)wglGetProcAddress("glVertexAttribI3ui");
	glVertexAttribI4uiproc = (PFNGLVERTEXATTRIBI4UIPROC)wglGetProcAddress("glVertexAttribI4ui");
	glVertexAttribI1ivproc = (PFNGLVERTEXATTRIBI1IVPROC)wglGetProcAddress("glVertexAttribI1iv");
	glVertexAttribI2ivproc = (PFNGLVERTEXATTRIBI2IVPROC)wglGetProcAddress("glVertexAttribI2iv");
	glVertexAttribI3ivproc = (PFNGLVERTEXATTRIBI3IVPROC)wglGetProcAddress("glVertexAttribI3iv");
	glVertexAttribI4ivproc = (PFNGLVERTEXATTRIBI4IVPROC)wglGetProcAddress("glVertexAttribI4iv");
	glVertexAttribI1uivproc = (PFNGLVERTEXATTRIBI1UIVPROC)wglGetProcAddress("glVertexAttribI1uiv");
	glVertexAttribI2uivproc = (PFNGLVERTEXATTRIBI2UIVPROC)wglGetProcAddress("glVertexAttribI2uiv");
	glVertexAttribI3uivproc = (PFNGLVERTEXATTRIBI3UIVPROC)wglGetProcAddress("glVertexAttribI3uiv");
	glVertexAttribI4uivproc = (PFNGLVERTEXATTRIBI4UIVPROC)wglGetProcAddress("glVertexAttribI4uiv");
	glVertexAttribI4bvproc = (PFNGLVERTEXATTRIBI4BVPROC)wglGetProcAddress("glVertexAttribI4bv");
	glVertexAttribI4svproc = (PFNGLVERTEXATTRIBI4SVPROC)wglGetProcAddress("glVertexAttribI4sv");
	glVertexAttribI4ubvproc = (PFNGLVERTEXATTRIBI4UBVPROC)wglGetProcAddress("glVertexAttribI4ubv");
	glVertexAttribI4usvproc = (PFNGLVERTEXATTRIBI4USVPROC)wglGetProcAddress("glVertexAttribI4usv");
	glGetUniformuivproc = (PFNGLGETUNIFORMUIVPROC)wglGetProcAddress("glGetUniformuiv");
	glBindFragDataLocationproc = (PFNGLBINDFRAGDATALOCATIONPROC)wglGetProcAddress("glBindFragDataLocation");
	glGetFragDataLocationproc = (PFNGLGETFRAGDATALOCATIONPROC)wglGetProcAddress("glGetFragDataLocation");
	glUniform1uiproc = (PFNGLUNIFORM1UIPROC)wglGetProcAddress("glUniform1ui");
	glUniform2uiproc = (PFNGLUNIFORM2UIPROC)wglGetProcAddress("glUniform2ui");
	glUniform3uiproc = (PFNGLUNIFORM3UIPROC)wglGetProcAddress("glUniform3ui");
	glUniform4uiproc = (PFNGLUNIFORM4UIPROC)wglGetProcAddress("glUniform4ui");
	glUniform1uivproc = (PFNGLUNIFORM1UIVPROC)wglGetProcAddress("glUniform1uiv");
	glUniform2uivproc = (PFNGLUNIFORM2UIVPROC)wglGetProcAddress("glUniform2uiv");
	glUniform3uivproc = (PFNGLUNIFORM3UIVPROC)wglGetProcAddress("glUniform3uiv");
	glUniform4uivproc = (PFNGLUNIFORM4UIVPROC)wglGetProcAddress("glUniform4uiv");
	glTexParameterIivproc = (PFNGLTEXPARAMETERIIVPROC)wglGetProcAddress("glTexParameterIiv");
	glTexParameterIuivproc = (PFNGLTEXPARAMETERIUIVPROC)wglGetProcAddress("glTexParameterIuiv");
	glGetTexParameterIivproc = (PFNGLGETTEXPARAMETERIIVPROC)wglGetProcAddress("glGetTexParameterIiv");
	glGetTexParameterIuivproc = (PFNGLGETTEXPARAMETERIUIVPROC)wglGetProcAddress("glGetTexParameterIuiv");
	glClearBufferivproc = (PFNGLCLEARBUFFERIVPROC)wglGetProcAddress("glClearBufferiv");
	glClearBufferuivproc = (PFNGLCLEARBUFFERUIVPROC)wglGetProcAddress("glClearBufferuiv");
	glClearBufferfvproc = (PFNGLCLEARBUFFERFVPROC)wglGetProcAddress("glClearBufferfv");
	glClearBufferfiproc = (PFNGLCLEARBUFFERFIPROC)wglGetProcAddress("glClearBufferfi");
	glGetStringiproc = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
	glIsRenderbufferproc = (PFNGLISRENDERBUFFERPROC)wglGetProcAddress("glIsRenderbuffer");
	glBindRenderbufferproc = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
	glDeleteRenderbuffersproc = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
	glGenRenderbuffersproc = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
	glRenderbufferStorageproc = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
	glGetRenderbufferParameterivproc = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetRenderbufferParameteriv");
	glIsFramebufferproc = (PFNGLISFRAMEBUFFERPROC)wglGetProcAddress("glIsFramebuffer");
	glBindFramebufferproc = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
	glDeleteFramebuffersproc = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
	glGenFramebuffersproc = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
	glCheckFramebufferStatusproc = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
	glFramebufferTexture1Dproc = (PFNGLFRAMEBUFFERTEXTURE1DPROC)wglGetProcAddress("glFramebufferTexture1D");
	glFramebufferTexture2Dproc = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
	glFramebufferTexture3Dproc = (PFNGLFRAMEBUFFERTEXTURE3DPROC)wglGetProcAddress("glFramebufferTexture3D");
	glFramebufferRenderbufferproc = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameterivproc = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferAttachmentParameteriv");
	glGenerateMipmapproc = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
	glBlitFramebufferproc = (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");
	glRenderbufferStorageMultisampleproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
	glFramebufferTextureLayerproc = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glFramebufferTextureLayer");
	glMapBufferRangeproc = (PFNGLMAPBUFFERRANGEPROC)wglGetProcAddress("glMapBufferRange");
	glFlushMappedBufferRangeproc = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedBufferRange");
	glBindVertexArrayproc = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	glDeleteVertexArraysproc = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
	glGenVertexArraysproc = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	glIsVertexArrayproc = (PFNGLISVERTEXARRAYPROC)wglGetProcAddress("glIsVertexArray");
	glDrawArraysInstancedproc = (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
	glDrawElementsInstancedproc = (PFNGLDRAWELEMENTSINSTANCEDPROC)wglGetProcAddress("glDrawElementsInstanced");
	glTexBufferproc = (PFNGLTEXBUFFERPROC)wglGetProcAddress("glTexBuffer");
	glPrimitiveRestartIndexproc = (PFNGLPRIMITIVERESTARTINDEXPROC)wglGetProcAddress("glPrimitiveRestartIndex");
	glCopyBufferSubDataproc = (PFNGLCOPYBUFFERSUBDATAPROC)wglGetProcAddress("glCopyBufferSubData");
	glGetUniformIndicesproc = (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
	glGetActiveUniformsivproc = (PFNGLGETACTIVEUNIFORMSIVPROC)wglGetProcAddress("glGetActiveUniformsiv");
	glGetActiveUniformNameproc = (PFNGLGETACTIVEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveUniformName");
	glGetUniformBlockIndexproc = (PFNGLGETUNIFORMBLOCKINDEXPROC)wglGetProcAddress("glGetUniformBlockIndex");
	glGetActiveUniformBlockivproc = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)wglGetProcAddress("glGetActiveUniformBlockiv");
	glGetActiveUniformBlockNameproc = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)wglGetProcAddress("glGetActiveUniformBlockName");
	glUniformBlockBindingproc = (PFNGLUNIFORMBLOCKBINDINGPROC)wglGetProcAddress("glUniformBlockBinding");
	glDrawElementsBaseVertexproc = (PFNGLDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertexproc = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertexproc = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertexproc = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glMultiDrawElementsBaseVertex");
	glProvokingVertexproc = (PFNGLPROVOKINGVERTEXPROC)wglGetProcAddress("glProvokingVertex");
	glFenceSyncproc = (PFNGLFENCESYNCPROC)wglGetProcAddress("glFenceSync");
	glIsSyncproc = (PFNGLISSYNCPROC)wglGetProcAddress("glIsSync");
	glDeleteSyncproc = (PFNGLDELETESYNCPROC)wglGetProcAddress("glDeleteSync");
	glClientWaitSyncproc = (PFNGLCLIENTWAITSYNCPROC)wglGetProcAddress("glClientWaitSync");
	glWaitSyncproc = (PFNGLWAITSYNCPROC)wglGetProcAddress("glWaitSync");
	glGetInteger64vproc = (PFNGLGETINTEGER64VPROC)wglGetProcAddress("glGetInteger64v");
	glGetSyncivproc = (PFNGLGETSYNCIVPROC)wglGetProcAddress("glGetSynciv");
	glGetInteger64i_vproc = (PFNGLGETINTEGER64I_VPROC)wglGetProcAddress("glGetInteger64i_v");
	glGetBufferParameteri64vproc = (PFNGLGETBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetBufferParameteri64v");
	glFramebufferTextureproc = (PFNGLFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glFramebufferTexture");
	glTexImage2DMultisampleproc = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexImage2DMultisample");
	glTexImage3DMultisampleproc = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexImage3DMultisample");
	glGetMultisamplefvproc = (PFNGLGETMULTISAMPLEFVPROC)wglGetProcAddress("glGetMultisamplefv");
	glSampleMaskiproc = (PFNGLSAMPLEMASKIPROC)wglGetProcAddress("glSampleMaski");
	glBindFragDataLocationIndexedproc = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)wglGetProcAddress("glBindFragDataLocationIndexed");
	glGetFragDataIndexproc = (PFNGLGETFRAGDATAINDEXPROC)wglGetProcAddress("glGetFragDataIndex");
	glGenSamplersproc = (PFNGLGENSAMPLERSPROC)wglGetProcAddress("glGenSamplers");
	glDeleteSamplersproc = (PFNGLDELETESAMPLERSPROC)wglGetProcAddress("glDeleteSamplers");
	glIsSamplerproc = (PFNGLISSAMPLERPROC)wglGetProcAddress("glIsSampler");
	glBindSamplerproc = (PFNGLBINDSAMPLERPROC)wglGetProcAddress("glBindSampler");
	glSamplerParameteriproc = (PFNGLSAMPLERPARAMETERIPROC)wglGetProcAddress("glSamplerParameteri");
	glSamplerParameterivproc = (PFNGLSAMPLERPARAMETERIVPROC)wglGetProcAddress("glSamplerParameteriv");
	glSamplerParameterfproc = (PFNGLSAMPLERPARAMETERFPROC)wglGetProcAddress("glSamplerParameterf");
	glSamplerParameterfvproc = (PFNGLSAMPLERPARAMETERFVPROC)wglGetProcAddress("glSamplerParameterfv");
	glSamplerParameterIivproc = (PFNGLSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glSamplerParameterIiv");
	glSamplerParameterIuivproc = (PFNGLSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glSamplerParameterIuiv");
	glGetSamplerParameterivproc = (PFNGLGETSAMPLERPARAMETERIVPROC)wglGetProcAddress("glGetSamplerParameteriv");
	glGetSamplerParameterIivproc = (PFNGLGETSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glGetSamplerParameterIiv");
	glGetSamplerParameterfvproc = (PFNGLGETSAMPLERPARAMETERFVPROC)wglGetProcAddress("glGetSamplerParameterfv");
	glGetSamplerParameterIuivproc = (PFNGLGETSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glGetSamplerParameterIuiv");
	glQueryCounterproc = (PFNGLQUERYCOUNTERPROC)wglGetProcAddress("glQueryCounter");
	glGetQueryObjecti64vproc = (PFNGLGETQUERYOBJECTI64VPROC)wglGetProcAddress("glGetQueryObjecti64v");
	glGetQueryObjectui64vproc = (PFNGLGETQUERYOBJECTUI64VPROC)wglGetProcAddress("glGetQueryObjectui64v");
	glVertexAttribDivisorproc = (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
	glVertexAttribP1uiproc = (PFNGLVERTEXATTRIBP1UIPROC)wglGetProcAddress("glVertexAttribP1ui");
	glVertexAttribP1uivproc = (PFNGLVERTEXATTRIBP1UIVPROC)wglGetProcAddress("glVertexAttribP1uiv");
	glVertexAttribP2uiproc = (PFNGLVERTEXATTRIBP2UIPROC)wglGetProcAddress("glVertexAttribP2ui");
	glVertexAttribP2uivproc = (PFNGLVERTEXATTRIBP2UIVPROC)wglGetProcAddress("glVertexAttribP2uiv");
	glVertexAttribP3uiproc = (PFNGLVERTEXATTRIBP3UIPROC)wglGetProcAddress("glVertexAttribP3ui");
	glVertexAttribP3uivproc = (PFNGLVERTEXATTRIBP3UIVPROC)wglGetProcAddress("glVertexAttribP3uiv");
	glVertexAttribP4uiproc = (PFNGLVERTEXATTRIBP4UIPROC)wglGetProcAddress("glVertexAttribP4ui");
	glVertexAttribP4uivproc = (PFNGLVERTEXATTRIBP4UIVPROC)wglGetProcAddress("glVertexAttribP4uiv");
	glVertexP2uiproc = (PFNGLVERTEXP2UIPROC)wglGetProcAddress("glVertexP2ui");
	glVertexP2uivproc = (PFNGLVERTEXP2UIVPROC)wglGetProcAddress("glVertexP2uiv");
	glVertexP3uiproc = (PFNGLVERTEXP3UIPROC)wglGetProcAddress("glVertexP3ui");
	glVertexP3uivproc = (PFNGLVERTEXP3UIVPROC)wglGetProcAddress("glVertexP3uiv");
	glVertexP4uiproc = (PFNGLVERTEXP4UIPROC)wglGetProcAddress("glVertexP4ui");
	glVertexP4uivproc = (PFNGLVERTEXP4UIVPROC)wglGetProcAddress("glVertexP4uiv");
	glTexCoordP1uiproc = (PFNGLTEXCOORDP1UIPROC)wglGetProcAddress("glTexCoordP1ui");
	glTexCoordP1uivproc = (PFNGLTEXCOORDP1UIVPROC)wglGetProcAddress("glTexCoordP1uiv");
	glTexCoordP2uiproc = (PFNGLTEXCOORDP2UIPROC)wglGetProcAddress("glTexCoordP2ui");
	glTexCoordP2uivproc = (PFNGLTEXCOORDP2UIVPROC)wglGetProcAddress("glTexCoordP2uiv");
	glTexCoordP3uiproc = (PFNGLTEXCOORDP3UIPROC)wglGetProcAddress("glTexCoordP3ui");
	glTexCoordP3uivproc = (PFNGLTEXCOORDP3UIVPROC)wglGetProcAddress("glTexCoordP3uiv");
	glTexCoordP4uiproc = (PFNGLTEXCOORDP4UIPROC)wglGetProcAddress("glTexCoordP4ui");
	glTexCoordP4uivproc = (PFNGLTEXCOORDP4UIVPROC)wglGetProcAddress("glTexCoordP4uiv");
	glMultiTexCoordP1uiproc = (PFNGLMULTITEXCOORDP1UIPROC)wglGetProcAddress("glMultiTexCoordP1ui");
	glMultiTexCoordP1uivproc = (PFNGLMULTITEXCOORDP1UIVPROC)wglGetProcAddress("glMultiTexCoordP1uiv");
	glMultiTexCoordP2uiproc = (PFNGLMULTITEXCOORDP2UIPROC)wglGetProcAddress("glMultiTexCoordP2ui");
	glMultiTexCoordP2uivproc = (PFNGLMULTITEXCOORDP2UIVPROC)wglGetProcAddress("glMultiTexCoordP2uiv");
	glMultiTexCoordP3uiproc = (PFNGLMULTITEXCOORDP3UIPROC)wglGetProcAddress("glMultiTexCoordP3ui");
	glMultiTexCoordP3uivproc = (PFNGLMULTITEXCOORDP3UIVPROC)wglGetProcAddress("glMultiTexCoordP3uiv");
	glMultiTexCoordP4uiproc = (PFNGLMULTITEXCOORDP4UIPROC)wglGetProcAddress("glMultiTexCoordP4ui");
	glMultiTexCoordP4uivproc = (PFNGLMULTITEXCOORDP4UIVPROC)wglGetProcAddress("glMultiTexCoordP4uiv");
	glNormalP3uiproc = (PFNGLNORMALP3UIPROC)wglGetProcAddress("glNormalP3ui");
	glNormalP3uivproc = (PFNGLNORMALP3UIVPROC)wglGetProcAddress("glNormalP3uiv");
	glColorP3uiproc = (PFNGLCOLORP3UIPROC)wglGetProcAddress("glColorP3ui");
	glColorP3uivproc = (PFNGLCOLORP3UIVPROC)wglGetProcAddress("glColorP3uiv");
	glColorP4uiproc = (PFNGLCOLORP4UIPROC)wglGetProcAddress("glColorP4ui");
	glColorP4uivproc = (PFNGLCOLORP4UIVPROC)wglGetProcAddress("glColorP4uiv");
	glSecondaryColorP3uiproc = (PFNGLSECONDARYCOLORP3UIPROC)wglGetProcAddress("glSecondaryColorP3ui");
	glSecondaryColorP3uivproc = (PFNGLSECONDARYCOLORP3UIVPROC)wglGetProcAddress("glSecondaryColorP3uiv");
	glMinSampleShadingproc = (PFNGLMINSAMPLESHADINGPROC)wglGetProcAddress("glMinSampleShading");
	glBlendEquationiproc = (PFNGLBLENDEQUATIONIPROC)wglGetProcAddress("glBlendEquationi");
	glBlendEquationSeparateiproc = (PFNGLBLENDEQUATIONSEPARATEIPROC)wglGetProcAddress("glBlendEquationSeparatei");
	glBlendFunciproc = (PFNGLBLENDFUNCIPROC)wglGetProcAddress("glBlendFunci");
	glBlendFuncSeparateiproc = (PFNGLBLENDFUNCSEPARATEIPROC)wglGetProcAddress("glBlendFuncSeparatei");
	glDrawArraysIndirectproc = (PFNGLDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glDrawArraysIndirect");
	glDrawElementsIndirectproc = (PFNGLDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glDrawElementsIndirect");
	glUniform1dproc = (PFNGLUNIFORM1DPROC)wglGetProcAddress("glUniform1d");
	glUniform2dproc = (PFNGLUNIFORM2DPROC)wglGetProcAddress("glUniform2d");
	glUniform3dproc = (PFNGLUNIFORM3DPROC)wglGetProcAddress("glUniform3d");
	glUniform4dproc = (PFNGLUNIFORM4DPROC)wglGetProcAddress("glUniform4d");
	glUniform1dvproc = (PFNGLUNIFORM1DVPROC)wglGetProcAddress("glUniform1dv");
	glUniform2dvproc = (PFNGLUNIFORM2DVPROC)wglGetProcAddress("glUniform2dv");
	glUniform3dvproc = (PFNGLUNIFORM3DVPROC)wglGetProcAddress("glUniform3dv");
	glUniform4dvproc = (PFNGLUNIFORM4DVPROC)wglGetProcAddress("glUniform4dv");
	glUniformMatrix2dvproc = (PFNGLUNIFORMMATRIX2DVPROC)wglGetProcAddress("glUniformMatrix2dv");
	glUniformMatrix3dvproc = (PFNGLUNIFORMMATRIX3DVPROC)wglGetProcAddress("glUniformMatrix3dv");
	glUniformMatrix4dvproc = (PFNGLUNIFORMMATRIX4DVPROC)wglGetProcAddress("glUniformMatrix4dv");
	glUniformMatrix2x3dvproc = (PFNGLUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glUniformMatrix2x3dv");
	glUniformMatrix2x4dvproc = (PFNGLUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glUniformMatrix2x4dv");
	glUniformMatrix3x2dvproc = (PFNGLUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glUniformMatrix3x2dv");
	glUniformMatrix3x4dvproc = (PFNGLUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glUniformMatrix3x4dv");
	glUniformMatrix4x2dvproc = (PFNGLUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glUniformMatrix4x2dv");
	glUniformMatrix4x3dvproc = (PFNGLUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glUniformMatrix4x3dv");
	glGetUniformdvproc = (PFNGLGETUNIFORMDVPROC)wglGetProcAddress("glGetUniformdv");
	glGetSubroutineUniformLocationproc = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)wglGetProcAddress("glGetSubroutineUniformLocation");
	glGetSubroutineIndexproc = (PFNGLGETSUBROUTINEINDEXPROC)wglGetProcAddress("glGetSubroutineIndex");
	glGetActiveSubroutineUniformivproc = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)wglGetProcAddress("glGetActiveSubroutineUniformiv");
	glGetActiveSubroutineUniformNameproc = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveSubroutineUniformName");
	glGetActiveSubroutineNameproc = (PFNGLGETACTIVESUBROUTINENAMEPROC)wglGetProcAddress("glGetActiveSubroutineName");
	glUniformSubroutinesuivproc = (PFNGLUNIFORMSUBROUTINESUIVPROC)wglGetProcAddress("glUniformSubroutinesuiv");
	glGetUniformSubroutineuivproc = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)wglGetProcAddress("glGetUniformSubroutineuiv");
	glGetProgramStageivproc = (PFNGLGETPROGRAMSTAGEIVPROC)wglGetProcAddress("glGetProgramStageiv");
	glPatchParameteriproc = (PFNGLPATCHPARAMETERIPROC)wglGetProcAddress("glPatchParameteri");
	glPatchParameterfvproc = (PFNGLPATCHPARAMETERFVPROC)wglGetProcAddress("glPatchParameterfv");
	glBindTransformFeedbackproc = (PFNGLBINDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBindTransformFeedback");
	glDeleteTransformFeedbacksproc = (PFNGLDELETETRANSFORMFEEDBACKSPROC)wglGetProcAddress("glDeleteTransformFeedbacks");
	glGenTransformFeedbacksproc = (PFNGLGENTRANSFORMFEEDBACKSPROC)wglGetProcAddress("glGenTransformFeedbacks");
	glIsTransformFeedbackproc = (PFNGLISTRANSFORMFEEDBACKPROC)wglGetProcAddress("glIsTransformFeedback");
	glPauseTransformFeedbackproc = (PFNGLPAUSETRANSFORMFEEDBACKPROC)wglGetProcAddress("glPauseTransformFeedback");
	glResumeTransformFeedbackproc = (PFNGLRESUMETRANSFORMFEEDBACKPROC)wglGetProcAddress("glResumeTransformFeedback");
	glDrawTransformFeedbackproc = (PFNGLDRAWTRANSFORMFEEDBACKPROC)wglGetProcAddress("glDrawTransformFeedback");
	glDrawTransformFeedbackStreamproc = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)wglGetProcAddress("glDrawTransformFeedbackStream");
	glBeginQueryIndexedproc = (PFNGLBEGINQUERYINDEXEDPROC)wglGetProcAddress("glBeginQueryIndexed");
	glEndQueryIndexedproc = (PFNGLENDQUERYINDEXEDPROC)wglGetProcAddress("glEndQueryIndexed");
	glGetQueryIndexedivproc = (PFNGLGETQUERYINDEXEDIVPROC)wglGetProcAddress("glGetQueryIndexediv");
	glReleaseShaderCompilerproc = (PFNGLRELEASESHADERCOMPILERPROC)wglGetProcAddress("glReleaseShaderCompiler");
	glShaderBinaryproc = (PFNGLSHADERBINARYPROC)wglGetProcAddress("glShaderBinary");
	glGetShaderPrecisionFormatproc = (PFNGLGETSHADERPRECISIONFORMATPROC)wglGetProcAddress("glGetShaderPrecisionFormat");
	glDepthRangefproc = (PFNGLDEPTHRANGEFPROC)wglGetProcAddress("glDepthRangef");
	glClearDepthfproc = (PFNGLCLEARDEPTHFPROC)wglGetProcAddress("glClearDepthf");
	glGetProgramBinaryproc = (PFNGLGETPROGRAMBINARYPROC)wglGetProcAddress("glGetProgramBinary");
	glProgramBinaryproc = (PFNGLPROGRAMBINARYPROC)wglGetProcAddress("glProgramBinary");
	glProgramParameteriproc = (PFNGLPROGRAMPARAMETERIPROC)wglGetProcAddress("glProgramParameteri");
	glUseProgramStagesproc = (PFNGLUSEPROGRAMSTAGESPROC)wglGetProcAddress("glUseProgramStages");
	glActiveShaderProgramproc = (PFNGLACTIVESHADERPROGRAMPROC)wglGetProcAddress("glActiveShaderProgram");
	glCreateShaderProgramvproc = (PFNGLCREATESHADERPROGRAMVPROC)wglGetProcAddress("glCreateShaderProgramv");
	glBindProgramPipelineproc = (PFNGLBINDPROGRAMPIPELINEPROC)wglGetProcAddress("glBindProgramPipeline");
	glDeleteProgramPipelinesproc = (PFNGLDELETEPROGRAMPIPELINESPROC)wglGetProcAddress("glDeleteProgramPipelines");
	glGenProgramPipelinesproc = (PFNGLGENPROGRAMPIPELINESPROC)wglGetProcAddress("glGenProgramPipelines");
	glIsProgramPipelineproc = (PFNGLISPROGRAMPIPELINEPROC)wglGetProcAddress("glIsProgramPipeline");
	glGetProgramPipelineivproc = (PFNGLGETPROGRAMPIPELINEIVPROC)wglGetProcAddress("glGetProgramPipelineiv");
	glProgramUniform1iproc = (PFNGLPROGRAMUNIFORM1IPROC)wglGetProcAddress("glProgramUniform1i");
	glProgramUniform1ivproc = (PFNGLPROGRAMUNIFORM1IVPROC)wglGetProcAddress("glProgramUniform1iv");
	glProgramUniform1fproc = (PFNGLPROGRAMUNIFORM1FPROC)wglGetProcAddress("glProgramUniform1f");
	glProgramUniform1fvproc = (PFNGLPROGRAMUNIFORM1FVPROC)wglGetProcAddress("glProgramUniform1fv");
	glProgramUniform1dproc = (PFNGLPROGRAMUNIFORM1DPROC)wglGetProcAddress("glProgramUniform1d");
	glProgramUniform1dvproc = (PFNGLPROGRAMUNIFORM1DVPROC)wglGetProcAddress("glProgramUniform1dv");
	glProgramUniform1uiproc = (PFNGLPROGRAMUNIFORM1UIPROC)wglGetProcAddress("glProgramUniform1ui");
	glProgramUniform1uivproc = (PFNGLPROGRAMUNIFORM1UIVPROC)wglGetProcAddress("glProgramUniform1uiv");
	glProgramUniform2iproc = (PFNGLPROGRAMUNIFORM2IPROC)wglGetProcAddress("glProgramUniform2i");
	glProgramUniform2ivproc = (PFNGLPROGRAMUNIFORM2IVPROC)wglGetProcAddress("glProgramUniform2iv");
	glProgramUniform2fproc = (PFNGLPROGRAMUNIFORM2FPROC)wglGetProcAddress("glProgramUniform2f");
	glProgramUniform2fvproc = (PFNGLPROGRAMUNIFORM2FVPROC)wglGetProcAddress("glProgramUniform2fv");
	glProgramUniform2dproc = (PFNGLPROGRAMUNIFORM2DPROC)wglGetProcAddress("glProgramUniform2d");
	glProgramUniform2dvproc = (PFNGLPROGRAMUNIFORM2DVPROC)wglGetProcAddress("glProgramUniform2dv");
	glProgramUniform2uiproc = (PFNGLPROGRAMUNIFORM2UIPROC)wglGetProcAddress("glProgramUniform2ui");
	glProgramUniform2uivproc = (PFNGLPROGRAMUNIFORM2UIVPROC)wglGetProcAddress("glProgramUniform2uiv");
	glProgramUniform3iproc = (PFNGLPROGRAMUNIFORM3IPROC)wglGetProcAddress("glProgramUniform3i");
	glProgramUniform3ivproc = (PFNGLPROGRAMUNIFORM3IVPROC)wglGetProcAddress("glProgramUniform3iv");
	glProgramUniform3fproc = (PFNGLPROGRAMUNIFORM3FPROC)wglGetProcAddress("glProgramUniform3f");
	glProgramUniform3fvproc = (PFNGLPROGRAMUNIFORM3FVPROC)wglGetProcAddress("glProgramUniform3fv");
	glProgramUniform3dproc = (PFNGLPROGRAMUNIFORM3DPROC)wglGetProcAddress("glProgramUniform3d");
	glProgramUniform3dvproc = (PFNGLPROGRAMUNIFORM3DVPROC)wglGetProcAddress("glProgramUniform3dv");
	glProgramUniform3uiproc = (PFNGLPROGRAMUNIFORM3UIPROC)wglGetProcAddress("glProgramUniform3ui");
	glProgramUniform3uivproc = (PFNGLPROGRAMUNIFORM3UIVPROC)wglGetProcAddress("glProgramUniform3uiv");
	glProgramUniform4iproc = (PFNGLPROGRAMUNIFORM4IPROC)wglGetProcAddress("glProgramUniform4i");
	glProgramUniform4ivproc = (PFNGLPROGRAMUNIFORM4IVPROC)wglGetProcAddress("glProgramUniform4iv");
	glProgramUniform4fproc = (PFNGLPROGRAMUNIFORM4FPROC)wglGetProcAddress("glProgramUniform4f");
	glProgramUniform4fvproc = (PFNGLPROGRAMUNIFORM4FVPROC)wglGetProcAddress("glProgramUniform4fv");
	glProgramUniform4dproc = (PFNGLPROGRAMUNIFORM4DPROC)wglGetProcAddress("glProgramUniform4d");
	glProgramUniform4dvproc = (PFNGLPROGRAMUNIFORM4DVPROC)wglGetProcAddress("glProgramUniform4dv");
	glProgramUniform4uiproc = (PFNGLPROGRAMUNIFORM4UIPROC)wglGetProcAddress("glProgramUniform4ui");
	glProgramUniform4uivproc = (PFNGLPROGRAMUNIFORM4UIVPROC)wglGetProcAddress("glProgramUniform4uiv");
	glProgramUniformMatrix2fvproc = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)wglGetProcAddress("glProgramUniformMatrix2fv");
	glProgramUniformMatrix3fvproc = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)wglGetProcAddress("glProgramUniformMatrix3fv");
	glProgramUniformMatrix4fvproc = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)wglGetProcAddress("glProgramUniformMatrix4fv");
	glProgramUniformMatrix2dvproc = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)wglGetProcAddress("glProgramUniformMatrix2dv");
	glProgramUniformMatrix3dvproc = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)wglGetProcAddress("glProgramUniformMatrix3dv");
	glProgramUniformMatrix4dvproc = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)wglGetProcAddress("glProgramUniformMatrix4dv");
	glProgramUniformMatrix2x3fvproc = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)wglGetProcAddress("glProgramUniformMatrix2x3fv");
	glProgramUniformMatrix3x2fvproc = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)wglGetProcAddress("glProgramUniformMatrix3x2fv");
	glProgramUniformMatrix2x4fvproc = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)wglGetProcAddress("glProgramUniformMatrix2x4fv");
	glProgramUniformMatrix4x2fvproc = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)wglGetProcAddress("glProgramUniformMatrix4x2fv");
	glProgramUniformMatrix3x4fvproc = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)wglGetProcAddress("glProgramUniformMatrix3x4fv");
	glProgramUniformMatrix4x3fvproc = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)wglGetProcAddress("glProgramUniformMatrix4x3fv");
	glProgramUniformMatrix2x3dvproc = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glProgramUniformMatrix2x3dv");
	glProgramUniformMatrix3x2dvproc = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glProgramUniformMatrix3x2dv");
	glProgramUniformMatrix2x4dvproc = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glProgramUniformMatrix2x4dv");
	glProgramUniformMatrix4x2dvproc = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glProgramUniformMatrix4x2dv");
	glProgramUniformMatrix3x4dvproc = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glProgramUniformMatrix3x4dv");
	glProgramUniformMatrix4x3dvproc = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glProgramUniformMatrix4x3dv");
	glValidateProgramPipelineproc = (PFNGLVALIDATEPROGRAMPIPELINEPROC)wglGetProcAddress("glValidateProgramPipeline");
	glGetProgramPipelineInfoLogproc = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)wglGetProcAddress("glGetProgramPipelineInfoLog");
	glVertexAttribL1dproc = (PFNGLVERTEXATTRIBL1DPROC)wglGetProcAddress("glVertexAttribL1d");
	glVertexAttribL2dproc = (PFNGLVERTEXATTRIBL2DPROC)wglGetProcAddress("glVertexAttribL2d");
	glVertexAttribL3dproc = (PFNGLVERTEXATTRIBL3DPROC)wglGetProcAddress("glVertexAttribL3d");
	glVertexAttribL4dproc = (PFNGLVERTEXATTRIBL4DPROC)wglGetProcAddress("glVertexAttribL4d");
	glVertexAttribL1dvproc = (PFNGLVERTEXATTRIBL1DVPROC)wglGetProcAddress("glVertexAttribL1dv");
	glVertexAttribL2dvproc = (PFNGLVERTEXATTRIBL2DVPROC)wglGetProcAddress("glVertexAttribL2dv");
	glVertexAttribL3dvproc = (PFNGLVERTEXATTRIBL3DVPROC)wglGetProcAddress("glVertexAttribL3dv");
	glVertexAttribL4dvproc = (PFNGLVERTEXATTRIBL4DVPROC)wglGetProcAddress("glVertexAttribL4dv");
	glVertexAttribLPointerproc = (PFNGLVERTEXATTRIBLPOINTERPROC)wglGetProcAddress("glVertexAttribLPointer");
	glGetVertexAttribLdvproc = (PFNGLGETVERTEXATTRIBLDVPROC)wglGetProcAddress("glGetVertexAttribLdv");
	glViewportArrayvproc = (PFNGLVIEWPORTARRAYVPROC)wglGetProcAddress("glViewportArrayv");
	glViewportIndexedfproc = (PFNGLVIEWPORTINDEXEDFPROC)wglGetProcAddress("glViewportIndexedf");
	glViewportIndexedfvproc = (PFNGLVIEWPORTINDEXEDFVPROC)wglGetProcAddress("glViewportIndexedfv");
	glScissorArrayvproc = (PFNGLSCISSORARRAYVPROC)wglGetProcAddress("glScissorArrayv");
	glScissorIndexedproc = (PFNGLSCISSORINDEXEDPROC)wglGetProcAddress("glScissorIndexed");
	glScissorIndexedvproc = (PFNGLSCISSORINDEXEDVPROC)wglGetProcAddress("glScissorIndexedv");
	glDepthRangeArrayvproc = (PFNGLDEPTHRANGEARRAYVPROC)wglGetProcAddress("glDepthRangeArrayv");
	glDepthRangeIndexedproc = (PFNGLDEPTHRANGEINDEXEDPROC)wglGetProcAddress("glDepthRangeIndexed");
	glGetFloati_vproc = (PFNGLGETFLOATI_VPROC)wglGetProcAddress("glGetFloati_v");
	glGetDoublei_vproc = (PFNGLGETDOUBLEI_VPROC)wglGetProcAddress("glGetDoublei_v");
	glDrawArraysInstancedBaseInstanceproc = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawArraysInstancedBaseInstance");
	glDrawElementsInstancedBaseInstanceproc = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseInstance");
	glDrawElementsInstancedBaseVertexBaseInstanceproc = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	glGetInternalformativproc = (PFNGLGETINTERNALFORMATIVPROC)wglGetProcAddress("glGetInternalformativ");
	glGetActiveAtomicCounterBufferivproc = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)wglGetProcAddress("glGetActiveAtomicCounterBufferiv");
	glBindImageTextureproc = (PFNGLBINDIMAGETEXTUREPROC)wglGetProcAddress("glBindImageTexture");
	glMemoryBarrierproc = (PFNGLMEMORYBARRIERPROC)wglGetProcAddress("glMemoryBarrier");
	glTexStorage1Dproc = (PFNGLTEXSTORAGE1DPROC)wglGetProcAddress("glTexStorage1D");
	glTexStorage2Dproc = (PFNGLTEXSTORAGE2DPROC)wglGetProcAddress("glTexStorage2D");
	glTexStorage3Dproc = (PFNGLTEXSTORAGE3DPROC)wglGetProcAddress("glTexStorage3D");
	glDrawTransformFeedbackInstancedproc = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackInstanced");
	glDrawTransformFeedbackStreamInstancedproc = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	glClearBufferDataproc = (PFNGLCLEARBUFFERDATAPROC)wglGetProcAddress("glClearBufferData");
	glClearBufferSubDataproc = (PFNGLCLEARBUFFERSUBDATAPROC)wglGetProcAddress("glClearBufferSubData");
	glDispatchComputeproc = (PFNGLDISPATCHCOMPUTEPROC)wglGetProcAddress("glDispatchCompute");
	glDispatchComputeIndirectproc = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)wglGetProcAddress("glDispatchComputeIndirect");
	glCopyImageSubDataproc = (PFNGLCOPYIMAGESUBDATAPROC)wglGetProcAddress("glCopyImageSubData");
	glFramebufferParameteriproc = (PFNGLFRAMEBUFFERPARAMETERIPROC)wglGetProcAddress("glFramebufferParameteri");
	glGetFramebufferParameterivproc = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferParameteriv");
	glGetInternalformati64vproc = (PFNGLGETINTERNALFORMATI64VPROC)wglGetProcAddress("glGetInternalformati64v");
	glInvalidateTexSubImageproc = (PFNGLINVALIDATETEXSUBIMAGEPROC)wglGetProcAddress("glInvalidateTexSubImage");
	glInvalidateTexImageproc = (PFNGLINVALIDATETEXIMAGEPROC)wglGetProcAddress("glInvalidateTexImage");
	glInvalidateBufferSubDataproc = (PFNGLINVALIDATEBUFFERSUBDATAPROC)wglGetProcAddress("glInvalidateBufferSubData");
	glInvalidateBufferDataproc = (PFNGLINVALIDATEBUFFERDATAPROC)wglGetProcAddress("glInvalidateBufferData");
	glInvalidateFramebufferproc = (PFNGLINVALIDATEFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateFramebuffer");
	glInvalidateSubFramebufferproc = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateSubFramebuffer");
	glMultiDrawArraysIndirectproc = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glMultiDrawArraysIndirect");
	glMultiDrawElementsIndirectproc = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glMultiDrawElementsIndirect");
	glGetProgramInterfaceivproc = (PFNGLGETPROGRAMINTERFACEIVPROC)wglGetProcAddress("glGetProgramInterfaceiv");
	glGetProgramResourceIndexproc = (PFNGLGETPROGRAMRESOURCEINDEXPROC)wglGetProcAddress("glGetProgramResourceIndex");
	glGetProgramResourceNameproc = (PFNGLGETPROGRAMRESOURCENAMEPROC)wglGetProcAddress("glGetProgramResourceName");
	glGetProgramResourceivproc = (PFNGLGETPROGRAMRESOURCEIVPROC)wglGetProcAddress("glGetProgramResourceiv");
	glGetProgramResourceLocationproc = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)wglGetProcAddress("glGetProgramResourceLocation");
	glGetProgramResourceLocationIndexproc = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)wglGetProcAddress("glGetProgramResourceLocationIndex");
	glShaderStorageBlockBindingproc = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)wglGetProcAddress("glShaderStorageBlockBinding");
	glTexBufferRangeproc = (PFNGLTEXBUFFERRANGEPROC)wglGetProcAddress("glTexBufferRange");
	glTexStorage2DMultisampleproc = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage2DMultisample");
	glTexStorage3DMultisampleproc = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage3DMultisample");
	glTextureViewproc = (PFNGLTEXTUREVIEWPROC)wglGetProcAddress("glTextureView");
	glBindVertexBufferproc = (PFNGLBINDVERTEXBUFFERPROC)wglGetProcAddress("glBindVertexBuffer");
	glVertexAttribFormatproc = (PFNGLVERTEXATTRIBFORMATPROC)wglGetProcAddress("glVertexAttribFormat");
	glVertexAttribIFormatproc = (PFNGLVERTEXATTRIBIFORMATPROC)wglGetProcAddress("glVertexAttribIFormat");
	glVertexAttribLFormatproc = (PFNGLVERTEXATTRIBLFORMATPROC)wglGetProcAddress("glVertexAttribLFormat");
	glVertexAttribBindingproc = (PFNGLVERTEXATTRIBBINDINGPROC)wglGetProcAddress("glVertexAttribBinding");
	glVertexBindingDivisorproc = (PFNGLVERTEXBINDINGDIVISORPROC)wglGetProcAddress("glVertexBindingDivisor");
	glDebugMessageControlproc = (PFNGLDEBUGMESSAGECONTROLPROC)wglGetProcAddress("glDebugMessageControl");
	glDebugMessageInsertproc = (PFNGLDEBUGMESSAGEINSERTPROC)wglGetProcAddress("glDebugMessageInsert");
	glDebugMessageCallbackproc = (PFNGLDEBUGMESSAGECALLBACKPROC)wglGetProcAddress("glDebugMessageCallback");
	glGetDebugMessageLogproc = (PFNGLGETDEBUGMESSAGELOGPROC)wglGetProcAddress("glGetDebugMessageLog");
	glPushDebugGroupproc = (PFNGLPUSHDEBUGGROUPPROC)wglGetProcAddress("glPushDebugGroup");
	glPopDebugGroupproc = (PFNGLPOPDEBUGGROUPPROC)wglGetProcAddress("glPopDebugGroup");
	glObjectLabelproc = (PFNGLOBJECTLABELPROC)wglGetProcAddress("glObjectLabel");
	glGetObjectLabelproc = (PFNGLGETOBJECTLABELPROC)wglGetProcAddress("glGetObjectLabel");
	glObjectPtrLabelproc = (PFNGLOBJECTPTRLABELPROC)wglGetProcAddress("glObjectPtrLabel");
	glGetObjectPtrLabelproc = (PFNGLGETOBJECTPTRLABELPROC)wglGetProcAddress("glGetObjectPtrLabel");
	glBufferStorageproc = (PFNGLBUFFERSTORAGEPROC)wglGetProcAddress("glBufferStorage");
	glClearTexImageproc = (PFNGLCLEARTEXIMAGEPROC)wglGetProcAddress("glClearTexImage");
	glClearTexSubImageproc = (PFNGLCLEARTEXSUBIMAGEPROC)wglGetProcAddress("glClearTexSubImage");
	glBindBuffersBaseproc = (PFNGLBINDBUFFERSBASEPROC)wglGetProcAddress("glBindBuffersBase");
	glBindBuffersRangeproc = (PFNGLBINDBUFFERSRANGEPROC)wglGetProcAddress("glBindBuffersRange");
	glBindTexturesproc = (PFNGLBINDTEXTURESPROC)wglGetProcAddress("glBindTextures");
	glBindSamplersproc = (PFNGLBINDSAMPLERSPROC)wglGetProcAddress("glBindSamplers");
	glBindImageTexturesproc = (PFNGLBINDIMAGETEXTURESPROC)wglGetProcAddress("glBindImageTextures");
	glBindVertexBuffersproc = (PFNGLBINDVERTEXBUFFERSPROC)wglGetProcAddress("glBindVertexBuffers");
	glClipControlproc = (PFNGLCLIPCONTROLPROC)wglGetProcAddress("glClipControl");
	glCreateTransformFeedbacksproc = (PFNGLCREATETRANSFORMFEEDBACKSPROC)wglGetProcAddress("glCreateTransformFeedbacks");
	glTransformFeedbackBufferBaseproc = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)wglGetProcAddress("glTransformFeedbackBufferBase");
	glTransformFeedbackBufferRangeproc = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)wglGetProcAddress("glTransformFeedbackBufferRange");
	glGetTransformFeedbackivproc = (PFNGLGETTRANSFORMFEEDBACKIVPROC)wglGetProcAddress("glGetTransformFeedbackiv");
	glGetTransformFeedbacki_vproc = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)wglGetProcAddress("glGetTransformFeedbacki_v");
	glGetTransformFeedbacki64_vproc = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)wglGetProcAddress("glGetTransformFeedbacki64_v");
	glCreateBuffersproc = (PFNGLCREATEBUFFERSPROC)wglGetProcAddress("glCreateBuffers");
	glNamedBufferStorageproc = (PFNGLNAMEDBUFFERSTORAGEPROC)wglGetProcAddress("glNamedBufferStorage");
	glNamedBufferDataproc = (PFNGLNAMEDBUFFERDATAPROC)wglGetProcAddress("glNamedBufferData");
	glNamedBufferSubDataproc = (PFNGLNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glNamedBufferSubData");
	glCopyNamedBufferSubDataproc = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glCopyNamedBufferSubData");
	glClearNamedBufferDataproc = (PFNGLCLEARNAMEDBUFFERDATAPROC)wglGetProcAddress("glClearNamedBufferData");
	glClearNamedBufferSubDataproc = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glClearNamedBufferSubData");
	glMapNamedBufferproc = (PFNGLMAPNAMEDBUFFERPROC)wglGetProcAddress("glMapNamedBuffer");
	glMapNamedBufferRangeproc = (PFNGLMAPNAMEDBUFFERRANGEPROC)wglGetProcAddress("glMapNamedBufferRange");
	glUnmapNamedBufferproc = (PFNGLUNMAPNAMEDBUFFERPROC)wglGetProcAddress("glUnmapNamedBuffer");
	glFlushMappedNamedBufferRangeproc = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedNamedBufferRange");
	glGetNamedBufferParameterivproc = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedBufferParameteriv");
	glGetNamedBufferParameteri64vproc = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetNamedBufferParameteri64v");
	glGetNamedBufferPointervproc = (PFNGLGETNAMEDBUFFERPOINTERVPROC)wglGetProcAddress("glGetNamedBufferPointerv");
	glGetNamedBufferSubDataproc = (PFNGLGETNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glGetNamedBufferSubData");
	glCreateFramebuffersproc = (PFNGLCREATEFRAMEBUFFERSPROC)wglGetProcAddress("glCreateFramebuffers");
	glNamedFramebufferRenderbufferproc = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glNamedFramebufferRenderbuffer");
	glNamedFramebufferParameteriproc = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)wglGetProcAddress("glNamedFramebufferParameteri");
	glNamedFramebufferTextureproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glNamedFramebufferTexture");
	glNamedFramebufferTextureLayerproc = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glNamedFramebufferTextureLayer");
	glNamedFramebufferDrawBufferproc = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)wglGetProcAddress("glNamedFramebufferDrawBuffer");
	glNamedFramebufferDrawBuffersproc = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)wglGetProcAddress("glNamedFramebufferDrawBuffers");
	glNamedFramebufferReadBufferproc = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)wglGetProcAddress("glNamedFramebufferReadBuffer");
	glInvalidateNamedFramebufferDataproc = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)wglGetProcAddress("glInvalidateNamedFramebufferData");
	glInvalidateNamedFramebufferSubDataproc = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)wglGetProcAddress("glInvalidateNamedFramebufferSubData");
	glClearNamedFramebufferivproc = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)wglGetProcAddress("glClearNamedFramebufferiv");
	glClearNamedFramebufferuivproc = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)wglGetProcAddress("glClearNamedFramebufferuiv");
	glClearNamedFramebufferfvproc = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)wglGetProcAddress("glClearNamedFramebufferfv");
	glClearNamedFramebufferfiproc = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)wglGetProcAddress("glClearNamedFramebufferfi");
	glBlitNamedFramebufferproc = (PFNGLBLITNAMEDFRAMEBUFFERPROC)wglGetProcAddress("glBlitNamedFramebuffer");
	glCheckNamedFramebufferStatusproc = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckNamedFramebufferStatus");
	glGetNamedFramebufferParameterivproc = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedFramebufferParameteriv");
	glGetNamedFramebufferAttachmentParameterivproc = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetNamedFramebufferAttachmentParameteriv");
	glCreateRenderbuffersproc = (PFNGLCREATERENDERBUFFERSPROC)wglGetProcAddress("glCreateRenderbuffers");
	glNamedRenderbufferStorageproc = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glNamedRenderbufferStorage");
	glNamedRenderbufferStorageMultisampleproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisample");
	glGetNamedRenderbufferParameterivproc = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedRenderbufferParameteriv");
	glCreateTexturesproc = (PFNGLCREATETEXTURESPROC)wglGetProcAddress("glCreateTextures");
	glTextureBufferproc = (PFNGLTEXTUREBUFFERPROC)wglGetProcAddress("glTextureBuffer");
	glTextureBufferRangeproc = (PFNGLTEXTUREBUFFERRANGEPROC)wglGetProcAddress("glTextureBufferRange");
	glTextureStorage1Dproc = (PFNGLTEXTURESTORAGE1DPROC)wglGetProcAddress("glTextureStorage1D");
	glTextureStorage2Dproc = (PFNGLTEXTURESTORAGE2DPROC)wglGetProcAddress("glTextureStorage2D");
	glTextureStorage3Dproc = (PFNGLTEXTURESTORAGE3DPROC)wglGetProcAddress("glTextureStorage3D");
	glTextureStorage2DMultisampleproc = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTextureStorage2DMultisample");
	glTextureStorage3DMultisampleproc = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTextureStorage3DMultisample");
	glTextureSubImage1Dproc = (PFNGLTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glTextureSubImage1D");
	glTextureSubImage2Dproc = (PFNGLTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glTextureSubImage2D");
	glTextureSubImage3Dproc = (PFNGLTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glTextureSubImage3D");
	glCompressedTextureSubImage1Dproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glCompressedTextureSubImage1D");
	glCompressedTextureSubImage2Dproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glCompressedTextureSubImage2D");
	glCompressedTextureSubImage3Dproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glCompressedTextureSubImage3D");
	glCopyTextureSubImage1Dproc = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glCopyTextureSubImage1D");
	glCopyTextureSubImage2Dproc = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glCopyTextureSubImage2D");
	glCopyTextureSubImage3Dproc = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glCopyTextureSubImage3D");
	glTextureParameterfproc = (PFNGLTEXTUREPARAMETERFPROC)wglGetProcAddress("glTextureParameterf");
	glTextureParameterfvproc = (PFNGLTEXTUREPARAMETERFVPROC)wglGetProcAddress("glTextureParameterfv");
	glTextureParameteriproc = (PFNGLTEXTUREPARAMETERIPROC)wglGetProcAddress("glTextureParameteri");
	glTextureParameterIivproc = (PFNGLTEXTUREPARAMETERIIVPROC)wglGetProcAddress("glTextureParameterIiv");
	glTextureParameterIuivproc = (PFNGLTEXTUREPARAMETERIUIVPROC)wglGetProcAddress("glTextureParameterIuiv");
	glTextureParameterivproc = (PFNGLTEXTUREPARAMETERIVPROC)wglGetProcAddress("glTextureParameteriv");
	glGenerateTextureMipmapproc = (PFNGLGENERATETEXTUREMIPMAPPROC)wglGetProcAddress("glGenerateTextureMipmap");
	glBindTextureUnitproc = (PFNGLBINDTEXTUREUNITPROC)wglGetProcAddress("glBindTextureUnit");
	glGetTextureImageproc = (PFNGLGETTEXTUREIMAGEPROC)wglGetProcAddress("glGetTextureImage");
	glGetCompressedTextureImageproc = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)wglGetProcAddress("glGetCompressedTextureImage");
	glGetTextureLevelParameterfvproc = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)wglGetProcAddress("glGetTextureLevelParameterfv");
	glGetTextureLevelParameterivproc = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)wglGetProcAddress("glGetTextureLevelParameteriv");
	glGetTextureParameterfvproc = (PFNGLGETTEXTUREPARAMETERFVPROC)wglGetProcAddress("glGetTextureParameterfv");
	glGetTextureParameterIivproc = (PFNGLGETTEXTUREPARAMETERIIVPROC)wglGetProcAddress("glGetTextureParameterIiv");
	glGetTextureParameterIuivproc = (PFNGLGETTEXTUREPARAMETERIUIVPROC)wglGetProcAddress("glGetTextureParameterIuiv");
	glGetTextureParameterivproc = (PFNGLGETTEXTUREPARAMETERIVPROC)wglGetProcAddress("glGetTextureParameteriv");
	glCreateVertexArraysproc = (PFNGLCREATEVERTEXARRAYSPROC)wglGetProcAddress("glCreateVertexArrays");
	glDisableVertexArrayAttribproc = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)wglGetProcAddress("glDisableVertexArrayAttrib");
	glEnableVertexArrayAttribproc = (PFNGLENABLEVERTEXARRAYATTRIBPROC)wglGetProcAddress("glEnableVertexArrayAttrib");
	glVertexArrayElementBufferproc = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)wglGetProcAddress("glVertexArrayElementBuffer");
	glVertexArrayVertexBufferproc = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)wglGetProcAddress("glVertexArrayVertexBuffer");
	glVertexArrayVertexBuffersproc = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)wglGetProcAddress("glVertexArrayVertexBuffers");
	glVertexArrayAttribBindingproc = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)wglGetProcAddress("glVertexArrayAttribBinding");
	glVertexArrayAttribFormatproc = (PFNGLVERTEXARRAYATTRIBFORMATPROC)wglGetProcAddress("glVertexArrayAttribFormat");
	glVertexArrayAttribIFormatproc = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)wglGetProcAddress("glVertexArrayAttribIFormat");
	glVertexArrayAttribLFormatproc = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)wglGetProcAddress("glVertexArrayAttribLFormat");
	glVertexArrayBindingDivisorproc = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)wglGetProcAddress("glVertexArrayBindingDivisor");
	glGetVertexArrayivproc = (PFNGLGETVERTEXARRAYIVPROC)wglGetProcAddress("glGetVertexArrayiv");
	glGetVertexArrayIndexedivproc = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)wglGetProcAddress("glGetVertexArrayIndexediv");
	glGetVertexArrayIndexed64ivproc = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)wglGetProcAddress("glGetVertexArrayIndexed64iv");
	glCreateSamplersproc = (PFNGLCREATESAMPLERSPROC)wglGetProcAddress("glCreateSamplers");
	glCreateProgramPipelinesproc = (PFNGLCREATEPROGRAMPIPELINESPROC)wglGetProcAddress("glCreateProgramPipelines");
	glCreateQueriesproc = (PFNGLCREATEQUERIESPROC)wglGetProcAddress("glCreateQueries");
	glGetQueryBufferObjecti64vproc = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)wglGetProcAddress("glGetQueryBufferObjecti64v");
	glGetQueryBufferObjectivproc = (PFNGLGETQUERYBUFFEROBJECTIVPROC)wglGetProcAddress("glGetQueryBufferObjectiv");
	glGetQueryBufferObjectui64vproc = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)wglGetProcAddress("glGetQueryBufferObjectui64v");
	glGetQueryBufferObjectuivproc = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)wglGetProcAddress("glGetQueryBufferObjectuiv");
	glMemoryBarrierByRegionproc = (PFNGLMEMORYBARRIERBYREGIONPROC)wglGetProcAddress("glMemoryBarrierByRegion");
	glGetTextureSubImageproc = (PFNGLGETTEXTURESUBIMAGEPROC)wglGetProcAddress("glGetTextureSubImage");
	glGetCompressedTextureSubImageproc = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)wglGetProcAddress("glGetCompressedTextureSubImage");
	glGetGraphicsResetStatusproc = (PFNGLGETGRAPHICSRESETSTATUSPROC)wglGetProcAddress("glGetGraphicsResetStatus");
	glGetnCompressedTexImageproc = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetnCompressedTexImage");
	glGetnTexImageproc = (PFNGLGETNTEXIMAGEPROC)wglGetProcAddress("glGetnTexImage");
	glGetnUniformdvproc = (PFNGLGETNUNIFORMDVPROC)wglGetProcAddress("glGetnUniformdv");
	glGetnUniformfvproc = (PFNGLGETNUNIFORMFVPROC)wglGetProcAddress("glGetnUniformfv");
	glGetnUniformivproc = (PFNGLGETNUNIFORMIVPROC)wglGetProcAddress("glGetnUniformiv");
	glGetnUniformuivproc = (PFNGLGETNUNIFORMUIVPROC)wglGetProcAddress("glGetnUniformuiv");
	glReadnPixelsproc = (PFNGLREADNPIXELSPROC)wglGetProcAddress("glReadnPixels");
	glGetnMapdvproc = (PFNGLGETNMAPDVPROC)wglGetProcAddress("glGetnMapdv");
	glGetnMapfvproc = (PFNGLGETNMAPFVPROC)wglGetProcAddress("glGetnMapfv");
	glGetnMapivproc = (PFNGLGETNMAPIVPROC)wglGetProcAddress("glGetnMapiv");
	glGetnPixelMapfvproc = (PFNGLGETNPIXELMAPFVPROC)wglGetProcAddress("glGetnPixelMapfv");
	glGetnPixelMapuivproc = (PFNGLGETNPIXELMAPUIVPROC)wglGetProcAddress("glGetnPixelMapuiv");
	glGetnPixelMapusvproc = (PFNGLGETNPIXELMAPUSVPROC)wglGetProcAddress("glGetnPixelMapusv");
	glGetnPolygonStippleproc = (PFNGLGETNPOLYGONSTIPPLEPROC)wglGetProcAddress("glGetnPolygonStipple");
	glGetnColorTableproc = (PFNGLGETNCOLORTABLEPROC)wglGetProcAddress("glGetnColorTable");
	glGetnConvolutionFilterproc = (PFNGLGETNCONVOLUTIONFILTERPROC)wglGetProcAddress("glGetnConvolutionFilter");
	glGetnSeparableFilterproc = (PFNGLGETNSEPARABLEFILTERPROC)wglGetProcAddress("glGetnSeparableFilter");
	glGetnHistogramproc = (PFNGLGETNHISTOGRAMPROC)wglGetProcAddress("glGetnHistogram");
	glGetnMinmaxproc = (PFNGLGETNMINMAXPROC)wglGetProcAddress("glGetnMinmax");
	glTextureBarrierproc = (PFNGLTEXTUREBARRIERPROC)wglGetProcAddress("glTextureBarrier");
	glSpecializeShaderproc = (PFNGLSPECIALIZESHADERPROC)wglGetProcAddress("glSpecializeShader");
	glMultiDrawArraysIndirectCountproc = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)wglGetProcAddress("glMultiDrawArraysIndirectCount");
	glMultiDrawElementsIndirectCountproc = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)wglGetProcAddress("glMultiDrawElementsIndirectCount");
	glPolygonOffsetClampproc = (PFNGLPOLYGONOFFSETCLAMPPROC)wglGetProcAddress("glPolygonOffsetClamp");
	glPrimitiveBoundingBoxARBproc = (PFNGLPRIMITIVEBOUNDINGBOXARBPROC)wglGetProcAddress("glPrimitiveBoundingBoxARB");
	glGetTextureHandleARBproc = (PFNGLGETTEXTUREHANDLEARBPROC)wglGetProcAddress("glGetTextureHandleARB");
	glGetTextureSamplerHandleARBproc = (PFNGLGETTEXTURESAMPLERHANDLEARBPROC)wglGetProcAddress("glGetTextureSamplerHandleARB");
	glMakeTextureHandleResidentARBproc = (PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)wglGetProcAddress("glMakeTextureHandleResidentARB");
	glMakeTextureHandleNonResidentARBproc = (PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)wglGetProcAddress("glMakeTextureHandleNonResidentARB");
	glGetImageHandleARBproc = (PFNGLGETIMAGEHANDLEARBPROC)wglGetProcAddress("glGetImageHandleARB");
	glMakeImageHandleResidentARBproc = (PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)wglGetProcAddress("glMakeImageHandleResidentARB");
	glMakeImageHandleNonResidentARBproc = (PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)wglGetProcAddress("glMakeImageHandleNonResidentARB");
	glUniformHandleui64ARBproc = (PFNGLUNIFORMHANDLEUI64ARBPROC)wglGetProcAddress("glUniformHandleui64ARB");
	glUniformHandleui64vARBproc = (PFNGLUNIFORMHANDLEUI64VARBPROC)wglGetProcAddress("glUniformHandleui64vARB");
	glProgramUniformHandleui64ARBproc = (PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)wglGetProcAddress("glProgramUniformHandleui64ARB");
	glProgramUniformHandleui64vARBproc = (PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)wglGetProcAddress("glProgramUniformHandleui64vARB");
	glIsTextureHandleResidentARBproc = (PFNGLISTEXTUREHANDLERESIDENTARBPROC)wglGetProcAddress("glIsTextureHandleResidentARB");
	glIsImageHandleResidentARBproc = (PFNGLISIMAGEHANDLERESIDENTARBPROC)wglGetProcAddress("glIsImageHandleResidentARB");
	glVertexAttribL1ui64ARBproc = (PFNGLVERTEXATTRIBL1UI64ARBPROC)wglGetProcAddress("glVertexAttribL1ui64ARB");
	glVertexAttribL1ui64vARBproc = (PFNGLVERTEXATTRIBL1UI64VARBPROC)wglGetProcAddress("glVertexAttribL1ui64vARB");
	glGetVertexAttribLui64vARBproc = (PFNGLGETVERTEXATTRIBLUI64VARBPROC)wglGetProcAddress("glGetVertexAttribLui64vARB");
	glCreateSyncFromCLeventARBproc = (PFNGLCREATESYNCFROMCLEVENTARBPROC)wglGetProcAddress("glCreateSyncFromCLeventARB");
	glClampColorARBproc = (PFNGLCLAMPCOLORARBPROC)wglGetProcAddress("glClampColorARB");
	glDispatchComputeGroupSizeARBproc = (PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)wglGetProcAddress("glDispatchComputeGroupSizeARB");
	glDebugMessageControlARBproc = (PFNGLDEBUGMESSAGECONTROLARBPROC)wglGetProcAddress("glDebugMessageControlARB");
	glDebugMessageInsertARBproc = (PFNGLDEBUGMESSAGEINSERTARBPROC)wglGetProcAddress("glDebugMessageInsertARB");
	glDebugMessageCallbackARBproc = (PFNGLDEBUGMESSAGECALLBACKARBPROC)wglGetProcAddress("glDebugMessageCallbackARB");
	glGetDebugMessageLogARBproc = (PFNGLGETDEBUGMESSAGELOGARBPROC)wglGetProcAddress("glGetDebugMessageLogARB");
	glDrawBuffersARBproc = (PFNGLDRAWBUFFERSARBPROC)wglGetProcAddress("glDrawBuffersARB");
	glBlendEquationiARBproc = (PFNGLBLENDEQUATIONIARBPROC)wglGetProcAddress("glBlendEquationiARB");
	glBlendEquationSeparateiARBproc = (PFNGLBLENDEQUATIONSEPARATEIARBPROC)wglGetProcAddress("glBlendEquationSeparateiARB");
	glBlendFunciARBproc = (PFNGLBLENDFUNCIARBPROC)wglGetProcAddress("glBlendFunciARB");
	glBlendFuncSeparateiARBproc = (PFNGLBLENDFUNCSEPARATEIARBPROC)wglGetProcAddress("glBlendFuncSeparateiARB");
	glDrawArraysInstancedARBproc = (PFNGLDRAWARRAYSINSTANCEDARBPROC)wglGetProcAddress("glDrawArraysInstancedARB");
	glDrawElementsInstancedARBproc = (PFNGLDRAWELEMENTSINSTANCEDARBPROC)wglGetProcAddress("glDrawElementsInstancedARB");
	glProgramStringARBproc = (PFNGLPROGRAMSTRINGARBPROC)wglGetProcAddress("glProgramStringARB");
	glBindProgramARBproc = (PFNGLBINDPROGRAMARBPROC)wglGetProcAddress("glBindProgramARB");
	glDeleteProgramsARBproc = (PFNGLDELETEPROGRAMSARBPROC)wglGetProcAddress("glDeleteProgramsARB");
	glGenProgramsARBproc = (PFNGLGENPROGRAMSARBPROC)wglGetProcAddress("glGenProgramsARB");
	glProgramEnvParameter4dARBproc = (PFNGLPROGRAMENVPARAMETER4DARBPROC)wglGetProcAddress("glProgramEnvParameter4dARB");
	glProgramEnvParameter4dvARBproc = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)wglGetProcAddress("glProgramEnvParameter4dvARB");
	glProgramEnvParameter4fARBproc = (PFNGLPROGRAMENVPARAMETER4FARBPROC)wglGetProcAddress("glProgramEnvParameter4fARB");
	glProgramEnvParameter4fvARBproc = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)wglGetProcAddress("glProgramEnvParameter4fvARB");
	glProgramLocalParameter4dARBproc = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)wglGetProcAddress("glProgramLocalParameter4dARB");
	glProgramLocalParameter4dvARBproc = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)wglGetProcAddress("glProgramLocalParameter4dvARB");
	glProgramLocalParameter4fARBproc = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)wglGetProcAddress("glProgramLocalParameter4fARB");
	glProgramLocalParameter4fvARBproc = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)wglGetProcAddress("glProgramLocalParameter4fvARB");
	glGetProgramEnvParameterdvARBproc = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)wglGetProcAddress("glGetProgramEnvParameterdvARB");
	glGetProgramEnvParameterfvARBproc = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)wglGetProcAddress("glGetProgramEnvParameterfvARB");
	glGetProgramLocalParameterdvARBproc = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)wglGetProcAddress("glGetProgramLocalParameterdvARB");
	glGetProgramLocalParameterfvARBproc = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)wglGetProcAddress("glGetProgramLocalParameterfvARB");
	glGetProgramivARBproc = (PFNGLGETPROGRAMIVARBPROC)wglGetProcAddress("glGetProgramivARB");
	glGetProgramStringARBproc = (PFNGLGETPROGRAMSTRINGARBPROC)wglGetProcAddress("glGetProgramStringARB");
	glIsProgramARBproc = (PFNGLISPROGRAMARBPROC)wglGetProcAddress("glIsProgramARB");
	glProgramParameteriARBproc = (PFNGLPROGRAMPARAMETERIARBPROC)wglGetProcAddress("glProgramParameteriARB");
	glFramebufferTextureARBproc = (PFNGLFRAMEBUFFERTEXTUREARBPROC)wglGetProcAddress("glFramebufferTextureARB");
	glFramebufferTextureLayerARBproc = (PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)wglGetProcAddress("glFramebufferTextureLayerARB");
	glFramebufferTextureFaceARBproc = (PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)wglGetProcAddress("glFramebufferTextureFaceARB");
	glSpecializeShaderARBproc = (PFNGLSPECIALIZESHADERARBPROC)wglGetProcAddress("glSpecializeShaderARB");
	glUniform1i64ARBproc = (PFNGLUNIFORM1I64ARBPROC)wglGetProcAddress("glUniform1i64ARB");
	glUniform2i64ARBproc = (PFNGLUNIFORM2I64ARBPROC)wglGetProcAddress("glUniform2i64ARB");
	glUniform3i64ARBproc = (PFNGLUNIFORM3I64ARBPROC)wglGetProcAddress("glUniform3i64ARB");
	glUniform4i64ARBproc = (PFNGLUNIFORM4I64ARBPROC)wglGetProcAddress("glUniform4i64ARB");
	glUniform1i64vARBproc = (PFNGLUNIFORM1I64VARBPROC)wglGetProcAddress("glUniform1i64vARB");
	glUniform2i64vARBproc = (PFNGLUNIFORM2I64VARBPROC)wglGetProcAddress("glUniform2i64vARB");
	glUniform3i64vARBproc = (PFNGLUNIFORM3I64VARBPROC)wglGetProcAddress("glUniform3i64vARB");
	glUniform4i64vARBproc = (PFNGLUNIFORM4I64VARBPROC)wglGetProcAddress("glUniform4i64vARB");
	glUniform1ui64ARBproc = (PFNGLUNIFORM1UI64ARBPROC)wglGetProcAddress("glUniform1ui64ARB");
	glUniform2ui64ARBproc = (PFNGLUNIFORM2UI64ARBPROC)wglGetProcAddress("glUniform2ui64ARB");
	glUniform3ui64ARBproc = (PFNGLUNIFORM3UI64ARBPROC)wglGetProcAddress("glUniform3ui64ARB");
	glUniform4ui64ARBproc = (PFNGLUNIFORM4UI64ARBPROC)wglGetProcAddress("glUniform4ui64ARB");
	glUniform1ui64vARBproc = (PFNGLUNIFORM1UI64VARBPROC)wglGetProcAddress("glUniform1ui64vARB");
	glUniform2ui64vARBproc = (PFNGLUNIFORM2UI64VARBPROC)wglGetProcAddress("glUniform2ui64vARB");
	glUniform3ui64vARBproc = (PFNGLUNIFORM3UI64VARBPROC)wglGetProcAddress("glUniform3ui64vARB");
	glUniform4ui64vARBproc = (PFNGLUNIFORM4UI64VARBPROC)wglGetProcAddress("glUniform4ui64vARB");
	glGetUniformi64vARBproc = (PFNGLGETUNIFORMI64VARBPROC)wglGetProcAddress("glGetUniformi64vARB");
	glGetUniformui64vARBproc = (PFNGLGETUNIFORMUI64VARBPROC)wglGetProcAddress("glGetUniformui64vARB");
	glGetnUniformi64vARBproc = (PFNGLGETNUNIFORMI64VARBPROC)wglGetProcAddress("glGetnUniformi64vARB");
	glGetnUniformui64vARBproc = (PFNGLGETNUNIFORMUI64VARBPROC)wglGetProcAddress("glGetnUniformui64vARB");
	glProgramUniform1i64ARBproc = (PFNGLPROGRAMUNIFORM1I64ARBPROC)wglGetProcAddress("glProgramUniform1i64ARB");
	glProgramUniform2i64ARBproc = (PFNGLPROGRAMUNIFORM2I64ARBPROC)wglGetProcAddress("glProgramUniform2i64ARB");
	glProgramUniform3i64ARBproc = (PFNGLPROGRAMUNIFORM3I64ARBPROC)wglGetProcAddress("glProgramUniform3i64ARB");
	glProgramUniform4i64ARBproc = (PFNGLPROGRAMUNIFORM4I64ARBPROC)wglGetProcAddress("glProgramUniform4i64ARB");
	glProgramUniform1i64vARBproc = (PFNGLPROGRAMUNIFORM1I64VARBPROC)wglGetProcAddress("glProgramUniform1i64vARB");
	glProgramUniform2i64vARBproc = (PFNGLPROGRAMUNIFORM2I64VARBPROC)wglGetProcAddress("glProgramUniform2i64vARB");
	glProgramUniform3i64vARBproc = (PFNGLPROGRAMUNIFORM3I64VARBPROC)wglGetProcAddress("glProgramUniform3i64vARB");
	glProgramUniform4i64vARBproc = (PFNGLPROGRAMUNIFORM4I64VARBPROC)wglGetProcAddress("glProgramUniform4i64vARB");
	glProgramUniform1ui64ARBproc = (PFNGLPROGRAMUNIFORM1UI64ARBPROC)wglGetProcAddress("glProgramUniform1ui64ARB");
	glProgramUniform2ui64ARBproc = (PFNGLPROGRAMUNIFORM2UI64ARBPROC)wglGetProcAddress("glProgramUniform2ui64ARB");
	glProgramUniform3ui64ARBproc = (PFNGLPROGRAMUNIFORM3UI64ARBPROC)wglGetProcAddress("glProgramUniform3ui64ARB");
	glProgramUniform4ui64ARBproc = (PFNGLPROGRAMUNIFORM4UI64ARBPROC)wglGetProcAddress("glProgramUniform4ui64ARB");
	glProgramUniform1ui64vARBproc = (PFNGLPROGRAMUNIFORM1UI64VARBPROC)wglGetProcAddress("glProgramUniform1ui64vARB");
	glProgramUniform2ui64vARBproc = (PFNGLPROGRAMUNIFORM2UI64VARBPROC)wglGetProcAddress("glProgramUniform2ui64vARB");
	glProgramUniform3ui64vARBproc = (PFNGLPROGRAMUNIFORM3UI64VARBPROC)wglGetProcAddress("glProgramUniform3ui64vARB");
	glProgramUniform4ui64vARBproc = (PFNGLPROGRAMUNIFORM4UI64VARBPROC)wglGetProcAddress("glProgramUniform4ui64vARB");
	glColorTableproc = (PFNGLCOLORTABLEPROC)wglGetProcAddress("glColorTable");
	glColorTableParameterfvproc = (PFNGLCOLORTABLEPARAMETERFVPROC)wglGetProcAddress("glColorTableParameterfv");
	glColorTableParameterivproc = (PFNGLCOLORTABLEPARAMETERIVPROC)wglGetProcAddress("glColorTableParameteriv");
	glCopyColorTableproc = (PFNGLCOPYCOLORTABLEPROC)wglGetProcAddress("glCopyColorTable");
	glGetColorTableproc = (PFNGLGETCOLORTABLEPROC)wglGetProcAddress("glGetColorTable");
	glGetColorTableParameterfvproc = (PFNGLGETCOLORTABLEPARAMETERFVPROC)wglGetProcAddress("glGetColorTableParameterfv");
	glGetColorTableParameterivproc = (PFNGLGETCOLORTABLEPARAMETERIVPROC)wglGetProcAddress("glGetColorTableParameteriv");
	glColorSubTableproc = (PFNGLCOLORSUBTABLEPROC)wglGetProcAddress("glColorSubTable");
	glCopyColorSubTableproc = (PFNGLCOPYCOLORSUBTABLEPROC)wglGetProcAddress("glCopyColorSubTable");
	glConvolutionFilter1Dproc = (PFNGLCONVOLUTIONFILTER1DPROC)wglGetProcAddress("glConvolutionFilter1D");
	glConvolutionFilter2Dproc = (PFNGLCONVOLUTIONFILTER2DPROC)wglGetProcAddress("glConvolutionFilter2D");
	glConvolutionParameterfproc = (PFNGLCONVOLUTIONPARAMETERFPROC)wglGetProcAddress("glConvolutionParameterf");
	glConvolutionParameterfvproc = (PFNGLCONVOLUTIONPARAMETERFVPROC)wglGetProcAddress("glConvolutionParameterfv");
	glConvolutionParameteriproc = (PFNGLCONVOLUTIONPARAMETERIPROC)wglGetProcAddress("glConvolutionParameteri");
	glConvolutionParameterivproc = (PFNGLCONVOLUTIONPARAMETERIVPROC)wglGetProcAddress("glConvolutionParameteriv");
	glCopyConvolutionFilter1Dproc = (PFNGLCOPYCONVOLUTIONFILTER1DPROC)wglGetProcAddress("glCopyConvolutionFilter1D");
	glCopyConvolutionFilter2Dproc = (PFNGLCOPYCONVOLUTIONFILTER2DPROC)wglGetProcAddress("glCopyConvolutionFilter2D");
	glGetConvolutionFilterproc = (PFNGLGETCONVOLUTIONFILTERPROC)wglGetProcAddress("glGetConvolutionFilter");
	glGetConvolutionParameterfvproc = (PFNGLGETCONVOLUTIONPARAMETERFVPROC)wglGetProcAddress("glGetConvolutionParameterfv");
	glGetConvolutionParameterivproc = (PFNGLGETCONVOLUTIONPARAMETERIVPROC)wglGetProcAddress("glGetConvolutionParameteriv");
	glGetSeparableFilterproc = (PFNGLGETSEPARABLEFILTERPROC)wglGetProcAddress("glGetSeparableFilter");
	glSeparableFilter2Dproc = (PFNGLSEPARABLEFILTER2DPROC)wglGetProcAddress("glSeparableFilter2D");
	glGetHistogramproc = (PFNGLGETHISTOGRAMPROC)wglGetProcAddress("glGetHistogram");
	glGetHistogramParameterfvproc = (PFNGLGETHISTOGRAMPARAMETERFVPROC)wglGetProcAddress("glGetHistogramParameterfv");
	glGetHistogramParameterivproc = (PFNGLGETHISTOGRAMPARAMETERIVPROC)wglGetProcAddress("glGetHistogramParameteriv");
	glGetMinmaxproc = (PFNGLGETMINMAXPROC)wglGetProcAddress("glGetMinmax");
	glGetMinmaxParameterfvproc = (PFNGLGETMINMAXPARAMETERFVPROC)wglGetProcAddress("glGetMinmaxParameterfv");
	glGetMinmaxParameterivproc = (PFNGLGETMINMAXPARAMETERIVPROC)wglGetProcAddress("glGetMinmaxParameteriv");
	glHistogramproc = (PFNGLHISTOGRAMPROC)wglGetProcAddress("glHistogram");
	glMinmaxproc = (PFNGLMINMAXPROC)wglGetProcAddress("glMinmax");
	glResetHistogramproc = (PFNGLRESETHISTOGRAMPROC)wglGetProcAddress("glResetHistogram");
	glResetMinmaxproc = (PFNGLRESETMINMAXPROC)wglGetProcAddress("glResetMinmax");
	glMultiDrawArraysIndirectCountARBproc = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)wglGetProcAddress("glMultiDrawArraysIndirectCountARB");
	glMultiDrawElementsIndirectCountARBproc = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)wglGetProcAddress("glMultiDrawElementsIndirectCountARB");
	glVertexAttribDivisorARBproc = (PFNGLVERTEXATTRIBDIVISORARBPROC)wglGetProcAddress("glVertexAttribDivisorARB");
	glCurrentPaletteMatrixARBproc = (PFNGLCURRENTPALETTEMATRIXARBPROC)wglGetProcAddress("glCurrentPaletteMatrixARB");
	glMatrixIndexubvARBproc = (PFNGLMATRIXINDEXUBVARBPROC)wglGetProcAddress("glMatrixIndexubvARB");
	glMatrixIndexusvARBproc = (PFNGLMATRIXINDEXUSVARBPROC)wglGetProcAddress("glMatrixIndexusvARB");
	glMatrixIndexuivARBproc = (PFNGLMATRIXINDEXUIVARBPROC)wglGetProcAddress("glMatrixIndexuivARB");
	glMatrixIndexPointerARBproc = (PFNGLMATRIXINDEXPOINTERARBPROC)wglGetProcAddress("glMatrixIndexPointerARB");
	glSampleCoverageARBproc = (PFNGLSAMPLECOVERAGEARBPROC)wglGetProcAddress("glSampleCoverageARB");
	glActiveTextureARBproc = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
	glClientActiveTextureARBproc = (PFNGLCLIENTACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");
	glMultiTexCoord1dARBproc = (PFNGLMULTITEXCOORD1DARBPROC)wglGetProcAddress("glMultiTexCoord1dARB");
	glMultiTexCoord1dvARBproc = (PFNGLMULTITEXCOORD1DVARBPROC)wglGetProcAddress("glMultiTexCoord1dvARB");
	glMultiTexCoord1fARBproc = (PFNGLMULTITEXCOORD1FARBPROC)wglGetProcAddress("glMultiTexCoord1fARB");
	glMultiTexCoord1fvARBproc = (PFNGLMULTITEXCOORD1FVARBPROC)wglGetProcAddress("glMultiTexCoord1fvARB");
	glMultiTexCoord1iARBproc = (PFNGLMULTITEXCOORD1IARBPROC)wglGetProcAddress("glMultiTexCoord1iARB");
	glMultiTexCoord1ivARBproc = (PFNGLMULTITEXCOORD1IVARBPROC)wglGetProcAddress("glMultiTexCoord1ivARB");
	glMultiTexCoord1sARBproc = (PFNGLMULTITEXCOORD1SARBPROC)wglGetProcAddress("glMultiTexCoord1sARB");
	glMultiTexCoord1svARBproc = (PFNGLMULTITEXCOORD1SVARBPROC)wglGetProcAddress("glMultiTexCoord1svARB");
	glMultiTexCoord2dARBproc = (PFNGLMULTITEXCOORD2DARBPROC)wglGetProcAddress("glMultiTexCoord2dARB");
	glMultiTexCoord2dvARBproc = (PFNGLMULTITEXCOORD2DVARBPROC)wglGetProcAddress("glMultiTexCoord2dvARB");
	glMultiTexCoord2fARBproc = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
	glMultiTexCoord2fvARBproc = (PFNGLMULTITEXCOORD2FVARBPROC)wglGetProcAddress("glMultiTexCoord2fvARB");
	glMultiTexCoord2iARBproc = (PFNGLMULTITEXCOORD2IARBPROC)wglGetProcAddress("glMultiTexCoord2iARB");
	glMultiTexCoord2ivARBproc = (PFNGLMULTITEXCOORD2IVARBPROC)wglGetProcAddress("glMultiTexCoord2ivARB");
	glMultiTexCoord2sARBproc = (PFNGLMULTITEXCOORD2SARBPROC)wglGetProcAddress("glMultiTexCoord2sARB");
	glMultiTexCoord2svARBproc = (PFNGLMULTITEXCOORD2SVARBPROC)wglGetProcAddress("glMultiTexCoord2svARB");
	glMultiTexCoord3dARBproc = (PFNGLMULTITEXCOORD3DARBPROC)wglGetProcAddress("glMultiTexCoord3dARB");
	glMultiTexCoord3dvARBproc = (PFNGLMULTITEXCOORD3DVARBPROC)wglGetProcAddress("glMultiTexCoord3dvARB");
	glMultiTexCoord3fARBproc = (PFNGLMULTITEXCOORD3FARBPROC)wglGetProcAddress("glMultiTexCoord3fARB");
	glMultiTexCoord3fvARBproc = (PFNGLMULTITEXCOORD3FVARBPROC)wglGetProcAddress("glMultiTexCoord3fvARB");
	glMultiTexCoord3iARBproc = (PFNGLMULTITEXCOORD3IARBPROC)wglGetProcAddress("glMultiTexCoord3iARB");
	glMultiTexCoord3ivARBproc = (PFNGLMULTITEXCOORD3IVARBPROC)wglGetProcAddress("glMultiTexCoord3ivARB");
	glMultiTexCoord3sARBproc = (PFNGLMULTITEXCOORD3SARBPROC)wglGetProcAddress("glMultiTexCoord3sARB");
	glMultiTexCoord3svARBproc = (PFNGLMULTITEXCOORD3SVARBPROC)wglGetProcAddress("glMultiTexCoord3svARB");
	glMultiTexCoord4dARBproc = (PFNGLMULTITEXCOORD4DARBPROC)wglGetProcAddress("glMultiTexCoord4dARB");
	glMultiTexCoord4dvARBproc = (PFNGLMULTITEXCOORD4DVARBPROC)wglGetProcAddress("glMultiTexCoord4dvARB");
	glMultiTexCoord4fARBproc = (PFNGLMULTITEXCOORD4FARBPROC)wglGetProcAddress("glMultiTexCoord4fARB");
	glMultiTexCoord4fvARBproc = (PFNGLMULTITEXCOORD4FVARBPROC)wglGetProcAddress("glMultiTexCoord4fvARB");
	glMultiTexCoord4iARBproc = (PFNGLMULTITEXCOORD4IARBPROC)wglGetProcAddress("glMultiTexCoord4iARB");
	glMultiTexCoord4ivARBproc = (PFNGLMULTITEXCOORD4IVARBPROC)wglGetProcAddress("glMultiTexCoord4ivARB");
	glMultiTexCoord4sARBproc = (PFNGLMULTITEXCOORD4SARBPROC)wglGetProcAddress("glMultiTexCoord4sARB");
	glMultiTexCoord4svARBproc = (PFNGLMULTITEXCOORD4SVARBPROC)wglGetProcAddress("glMultiTexCoord4svARB");
	glGenQueriesARBproc = (PFNGLGENQUERIESARBPROC)wglGetProcAddress("glGenQueriesARB");
	glDeleteQueriesARBproc = (PFNGLDELETEQUERIESARBPROC)wglGetProcAddress("glDeleteQueriesARB");
	glIsQueryARBproc = (PFNGLISQUERYARBPROC)wglGetProcAddress("glIsQueryARB");
	glBeginQueryARBproc = (PFNGLBEGINQUERYARBPROC)wglGetProcAddress("glBeginQueryARB");
	glEndQueryARBproc = (PFNGLENDQUERYARBPROC)wglGetProcAddress("glEndQueryARB");
	glGetQueryivARBproc = (PFNGLGETQUERYIVARBPROC)wglGetProcAddress("glGetQueryivARB");
	glGetQueryObjectivARBproc = (PFNGLGETQUERYOBJECTIVARBPROC)wglGetProcAddress("glGetQueryObjectivARB");
	glGetQueryObjectuivARBproc = (PFNGLGETQUERYOBJECTUIVARBPROC)wglGetProcAddress("glGetQueryObjectuivARB");
	glMaxShaderCompilerThreadsARBproc = (PFNGLMAXSHADERCOMPILERTHREADSARBPROC)wglGetProcAddress("glMaxShaderCompilerThreadsARB");
	glPointParameterfARBproc = (PFNGLPOINTPARAMETERFARBPROC)wglGetProcAddress("glPointParameterfARB");
	glPointParameterfvARBproc = (PFNGLPOINTPARAMETERFVARBPROC)wglGetProcAddress("glPointParameterfvARB");
	glGetGraphicsResetStatusARBproc = (PFNGLGETGRAPHICSRESETSTATUSARBPROC)wglGetProcAddress("glGetGraphicsResetStatusARB");
	glGetnTexImageARBproc = (PFNGLGETNTEXIMAGEARBPROC)wglGetProcAddress("glGetnTexImageARB");
	glReadnPixelsARBproc = (PFNGLREADNPIXELSARBPROC)wglGetProcAddress("glReadnPixelsARB");
	glGetnCompressedTexImageARBproc = (PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)wglGetProcAddress("glGetnCompressedTexImageARB");
	glGetnUniformfvARBproc = (PFNGLGETNUNIFORMFVARBPROC)wglGetProcAddress("glGetnUniformfvARB");
	glGetnUniformivARBproc = (PFNGLGETNUNIFORMIVARBPROC)wglGetProcAddress("glGetnUniformivARB");
	glGetnUniformuivARBproc = (PFNGLGETNUNIFORMUIVARBPROC)wglGetProcAddress("glGetnUniformuivARB");
	glGetnUniformdvARBproc = (PFNGLGETNUNIFORMDVARBPROC)wglGetProcAddress("glGetnUniformdvARB");
	glGetnMapdvARBproc = (PFNGLGETNMAPDVARBPROC)wglGetProcAddress("glGetnMapdvARB");
	glGetnMapfvARBproc = (PFNGLGETNMAPFVARBPROC)wglGetProcAddress("glGetnMapfvARB");
	glGetnMapivARBproc = (PFNGLGETNMAPIVARBPROC)wglGetProcAddress("glGetnMapivARB");
	glGetnPixelMapfvARBproc = (PFNGLGETNPIXELMAPFVARBPROC)wglGetProcAddress("glGetnPixelMapfvARB");
	glGetnPixelMapuivARBproc = (PFNGLGETNPIXELMAPUIVARBPROC)wglGetProcAddress("glGetnPixelMapuivARB");
	glGetnPixelMapusvARBproc = (PFNGLGETNPIXELMAPUSVARBPROC)wglGetProcAddress("glGetnPixelMapusvARB");
	glGetnPolygonStippleARBproc = (PFNGLGETNPOLYGONSTIPPLEARBPROC)wglGetProcAddress("glGetnPolygonStippleARB");
	glGetnColorTableARBproc = (PFNGLGETNCOLORTABLEARBPROC)wglGetProcAddress("glGetnColorTableARB");
	glGetnConvolutionFilterARBproc = (PFNGLGETNCONVOLUTIONFILTERARBPROC)wglGetProcAddress("glGetnConvolutionFilterARB");
	glGetnSeparableFilterARBproc = (PFNGLGETNSEPARABLEFILTERARBPROC)wglGetProcAddress("glGetnSeparableFilterARB");
	glGetnHistogramARBproc = (PFNGLGETNHISTOGRAMARBPROC)wglGetProcAddress("glGetnHistogramARB");
	glGetnMinmaxARBproc = (PFNGLGETNMINMAXARBPROC)wglGetProcAddress("glGetnMinmaxARB");
	glFramebufferSampleLocationsfvARBproc = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)wglGetProcAddress("glFramebufferSampleLocationsfvARB");
	glNamedFramebufferSampleLocationsfvARBproc = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)wglGetProcAddress("glNamedFramebufferSampleLocationsfvARB");
	glEvaluateDepthValuesARBproc = (PFNGLEVALUATEDEPTHVALUESARBPROC)wglGetProcAddress("glEvaluateDepthValuesARB");
	glMinSampleShadingARBproc = (PFNGLMINSAMPLESHADINGARBPROC)wglGetProcAddress("glMinSampleShadingARB");
	glDeleteObjectARBproc = (PFNGLDELETEOBJECTARBPROC)wglGetProcAddress("glDeleteObjectARB");
	glGetHandleARBproc = (PFNGLGETHANDLEARBPROC)wglGetProcAddress("glGetHandleARB");
	glDetachObjectARBproc = (PFNGLDETACHOBJECTARBPROC)wglGetProcAddress("glDetachObjectARB");
	glCreateShaderObjectARBproc = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
	glShaderSourceARBproc = (PFNGLSHADERSOURCEARBPROC)wglGetProcAddress("glShaderSourceARB");
	glCompileShaderARBproc = (PFNGLCOMPILESHADERARBPROC)wglGetProcAddress("glCompileShaderARB");
	glCreateProgramObjectARBproc = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
	glAttachObjectARBproc = (PFNGLATTACHOBJECTARBPROC)wglGetProcAddress("glAttachObjectARB");
	glLinkProgramARBproc = (PFNGLLINKPROGRAMARBPROC)wglGetProcAddress("glLinkProgramARB");
	glUseProgramObjectARBproc = (PFNGLUSEPROGRAMOBJECTARBPROC)wglGetProcAddress("glUseProgramObjectARB");
	glValidateProgramARBproc = (PFNGLVALIDATEPROGRAMARBPROC)wglGetProcAddress("glValidateProgramARB");
	glUniform1fARBproc = (PFNGLUNIFORM1FARBPROC)wglGetProcAddress("glUniform1fARB");
	glUniform2fARBproc = (PFNGLUNIFORM2FARBPROC)wglGetProcAddress("glUniform2fARB");
	glUniform3fARBproc = (PFNGLUNIFORM3FARBPROC)wglGetProcAddress("glUniform3fARB");
	glUniform4fARBproc = (PFNGLUNIFORM4FARBPROC)wglGetProcAddress("glUniform4fARB");
	glUniform1iARBproc = (PFNGLUNIFORM1IARBPROC)wglGetProcAddress("glUniform1iARB");
	glUniform2iARBproc = (PFNGLUNIFORM2IARBPROC)wglGetProcAddress("glUniform2iARB");
	glUniform3iARBproc = (PFNGLUNIFORM3IARBPROC)wglGetProcAddress("glUniform3iARB");
	glUniform4iARBproc = (PFNGLUNIFORM4IARBPROC)wglGetProcAddress("glUniform4iARB");
	glUniform1fvARBproc = (PFNGLUNIFORM1FVARBPROC)wglGetProcAddress("glUniform1fvARB");
	glUniform2fvARBproc = (PFNGLUNIFORM2FVARBPROC)wglGetProcAddress("glUniform2fvARB");
	glUniform3fvARBproc = (PFNGLUNIFORM3FVARBPROC)wglGetProcAddress("glUniform3fvARB");
	glUniform4fvARBproc = (PFNGLUNIFORM4FVARBPROC)wglGetProcAddress("glUniform4fvARB");
	glUniform1ivARBproc = (PFNGLUNIFORM1IVARBPROC)wglGetProcAddress("glUniform1ivARB");
	glUniform2ivARBproc = (PFNGLUNIFORM2IVARBPROC)wglGetProcAddress("glUniform2ivARB");
	glUniform3ivARBproc = (PFNGLUNIFORM3IVARBPROC)wglGetProcAddress("glUniform3ivARB");
	glUniform4ivARBproc = (PFNGLUNIFORM4IVARBPROC)wglGetProcAddress("glUniform4ivARB");
	glUniformMatrix2fvARBproc = (PFNGLUNIFORMMATRIX2FVARBPROC)wglGetProcAddress("glUniformMatrix2fvARB");
	glUniformMatrix3fvARBproc = (PFNGLUNIFORMMATRIX3FVARBPROC)wglGetProcAddress("glUniformMatrix3fvARB");
	glUniformMatrix4fvARBproc = (PFNGLUNIFORMMATRIX4FVARBPROC)wglGetProcAddress("glUniformMatrix4fvARB");
	glGetObjectParameterfvARBproc = (PFNGLGETOBJECTPARAMETERFVARBPROC)wglGetProcAddress("glGetObjectParameterfvARB");
	glGetObjectParameterivARBproc = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
	glGetInfoLogARBproc = (PFNGLGETINFOLOGARBPROC)wglGetProcAddress("glGetInfoLogARB");
	glGetAttachedObjectsARBproc = (PFNGLGETATTACHEDOBJECTSARBPROC)wglGetProcAddress("glGetAttachedObjectsARB");
	glGetUniformLocationARBproc = (PFNGLGETUNIFORMLOCATIONARBPROC)wglGetProcAddress("glGetUniformLocationARB");
	glGetActiveUniformARBproc = (PFNGLGETACTIVEUNIFORMARBPROC)wglGetProcAddress("glGetActiveUniformARB");
	glGetUniformfvARBproc = (PFNGLGETUNIFORMFVARBPROC)wglGetProcAddress("glGetUniformfvARB");
	glGetUniformivARBproc = (PFNGLGETUNIFORMIVARBPROC)wglGetProcAddress("glGetUniformivARB");
	glGetShaderSourceARBproc = (PFNGLGETSHADERSOURCEARBPROC)wglGetProcAddress("glGetShaderSourceARB");
	glNamedStringARBproc = (PFNGLNAMEDSTRINGARBPROC)wglGetProcAddress("glNamedStringARB");
	glDeleteNamedStringARBproc = (PFNGLDELETENAMEDSTRINGARBPROC)wglGetProcAddress("glDeleteNamedStringARB");
	glCompileShaderIncludeARBproc = (PFNGLCOMPILESHADERINCLUDEARBPROC)wglGetProcAddress("glCompileShaderIncludeARB");
	glIsNamedStringARBproc = (PFNGLISNAMEDSTRINGARBPROC)wglGetProcAddress("glIsNamedStringARB");
	glGetNamedStringARBproc = (PFNGLGETNAMEDSTRINGARBPROC)wglGetProcAddress("glGetNamedStringARB");
	glGetNamedStringivARBproc = (PFNGLGETNAMEDSTRINGIVARBPROC)wglGetProcAddress("glGetNamedStringivARB");
	glBufferPageCommitmentARBproc = (PFNGLBUFFERPAGECOMMITMENTARBPROC)wglGetProcAddress("glBufferPageCommitmentARB");
	glNamedBufferPageCommitmentEXTproc = (PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)wglGetProcAddress("glNamedBufferPageCommitmentEXT");
	glNamedBufferPageCommitmentARBproc = (PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)wglGetProcAddress("glNamedBufferPageCommitmentARB");
	glTexPageCommitmentARBproc = (PFNGLTEXPAGECOMMITMENTARBPROC)wglGetProcAddress("glTexPageCommitmentARB");
	glTexBufferARBproc = (PFNGLTEXBUFFERARBPROC)wglGetProcAddress("glTexBufferARB");
	glCompressedTexImage3DARBproc = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)wglGetProcAddress("glCompressedTexImage3DARB");
	glCompressedTexImage2DARBproc = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)wglGetProcAddress("glCompressedTexImage2DARB");
	glCompressedTexImage1DARBproc = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)wglGetProcAddress("glCompressedTexImage1DARB");
	glCompressedTexSubImage3DARBproc = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)wglGetProcAddress("glCompressedTexSubImage3DARB");
	glCompressedTexSubImage2DARBproc = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)wglGetProcAddress("glCompressedTexSubImage2DARB");
	glCompressedTexSubImage1DARBproc = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)wglGetProcAddress("glCompressedTexSubImage1DARB");
	glGetCompressedTexImageARBproc = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)wglGetProcAddress("glGetCompressedTexImageARB");
	glLoadTransposeMatrixfARBproc = (PFNGLLOADTRANSPOSEMATRIXFARBPROC)wglGetProcAddress("glLoadTransposeMatrixfARB");
	glLoadTransposeMatrixdARBproc = (PFNGLLOADTRANSPOSEMATRIXDARBPROC)wglGetProcAddress("glLoadTransposeMatrixdARB");
	glMultTransposeMatrixfARBproc = (PFNGLMULTTRANSPOSEMATRIXFARBPROC)wglGetProcAddress("glMultTransposeMatrixfARB");
	glMultTransposeMatrixdARBproc = (PFNGLMULTTRANSPOSEMATRIXDARBPROC)wglGetProcAddress("glMultTransposeMatrixdARB");
	glWeightbvARBproc = (PFNGLWEIGHTBVARBPROC)wglGetProcAddress("glWeightbvARB");
	glWeightsvARBproc = (PFNGLWEIGHTSVARBPROC)wglGetProcAddress("glWeightsvARB");
	glWeightivARBproc = (PFNGLWEIGHTIVARBPROC)wglGetProcAddress("glWeightivARB");
	glWeightfvARBproc = (PFNGLWEIGHTFVARBPROC)wglGetProcAddress("glWeightfvARB");
	glWeightdvARBproc = (PFNGLWEIGHTDVARBPROC)wglGetProcAddress("glWeightdvARB");
	glWeightubvARBproc = (PFNGLWEIGHTUBVARBPROC)wglGetProcAddress("glWeightubvARB");
	glWeightusvARBproc = (PFNGLWEIGHTUSVARBPROC)wglGetProcAddress("glWeightusvARB");
	glWeightuivARBproc = (PFNGLWEIGHTUIVARBPROC)wglGetProcAddress("glWeightuivARB");
	glWeightPointerARBproc = (PFNGLWEIGHTPOINTERARBPROC)wglGetProcAddress("glWeightPointerARB");
	glVertexBlendARBproc = (PFNGLVERTEXBLENDARBPROC)wglGetProcAddress("glVertexBlendARB");
	glBindBufferARBproc = (PFNGLBINDBUFFERARBPROC)wglGetProcAddress("glBindBufferARB");
	glDeleteBuffersARBproc = (PFNGLDELETEBUFFERSARBPROC)wglGetProcAddress("glDeleteBuffersARB");
	glGenBuffersARBproc = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffersARB");
	glIsBufferARBproc = (PFNGLISBUFFERARBPROC)wglGetProcAddress("glIsBufferARB");
	glBufferDataARBproc = (PFNGLBUFFERDATAARBPROC)wglGetProcAddress("glBufferDataARB");
	glBufferSubDataARBproc = (PFNGLBUFFERSUBDATAARBPROC)wglGetProcAddress("glBufferSubDataARB");
	glGetBufferSubDataARBproc = (PFNGLGETBUFFERSUBDATAARBPROC)wglGetProcAddress("glGetBufferSubDataARB");
	glMapBufferARBproc = (PFNGLMAPBUFFERARBPROC)wglGetProcAddress("glMapBufferARB");
	glUnmapBufferARBproc = (PFNGLUNMAPBUFFERARBPROC)wglGetProcAddress("glUnmapBufferARB");
	glGetBufferParameterivARBproc = (PFNGLGETBUFFERPARAMETERIVARBPROC)wglGetProcAddress("glGetBufferParameterivARB");
	glGetBufferPointervARBproc = (PFNGLGETBUFFERPOINTERVARBPROC)wglGetProcAddress("glGetBufferPointervARB");
	glVertexAttrib1dARBproc = (PFNGLVERTEXATTRIB1DARBPROC)wglGetProcAddress("glVertexAttrib1dARB");
	glVertexAttrib1dvARBproc = (PFNGLVERTEXATTRIB1DVARBPROC)wglGetProcAddress("glVertexAttrib1dvARB");
	glVertexAttrib1fARBproc = (PFNGLVERTEXATTRIB1FARBPROC)wglGetProcAddress("glVertexAttrib1fARB");
	glVertexAttrib1fvARBproc = (PFNGLVERTEXATTRIB1FVARBPROC)wglGetProcAddress("glVertexAttrib1fvARB");
	glVertexAttrib1sARBproc = (PFNGLVERTEXATTRIB1SARBPROC)wglGetProcAddress("glVertexAttrib1sARB");
	glVertexAttrib1svARBproc = (PFNGLVERTEXATTRIB1SVARBPROC)wglGetProcAddress("glVertexAttrib1svARB");
	glVertexAttrib2dARBproc = (PFNGLVERTEXATTRIB2DARBPROC)wglGetProcAddress("glVertexAttrib2dARB");
	glVertexAttrib2dvARBproc = (PFNGLVERTEXATTRIB2DVARBPROC)wglGetProcAddress("glVertexAttrib2dvARB");
	glVertexAttrib2fARBproc = (PFNGLVERTEXATTRIB2FARBPROC)wglGetProcAddress("glVertexAttrib2fARB");
	glVertexAttrib2fvARBproc = (PFNGLVERTEXATTRIB2FVARBPROC)wglGetProcAddress("glVertexAttrib2fvARB");
	glVertexAttrib2sARBproc = (PFNGLVERTEXATTRIB2SARBPROC)wglGetProcAddress("glVertexAttrib2sARB");
	glVertexAttrib2svARBproc = (PFNGLVERTEXATTRIB2SVARBPROC)wglGetProcAddress("glVertexAttrib2svARB");
	glVertexAttrib3dARBproc = (PFNGLVERTEXATTRIB3DARBPROC)wglGetProcAddress("glVertexAttrib3dARB");
	glVertexAttrib3dvARBproc = (PFNGLVERTEXATTRIB3DVARBPROC)wglGetProcAddress("glVertexAttrib3dvARB");
	glVertexAttrib3fARBproc = (PFNGLVERTEXATTRIB3FARBPROC)wglGetProcAddress("glVertexAttrib3fARB");
	glVertexAttrib3fvARBproc = (PFNGLVERTEXATTRIB3FVARBPROC)wglGetProcAddress("glVertexAttrib3fvARB");
	glVertexAttrib3sARBproc = (PFNGLVERTEXATTRIB3SARBPROC)wglGetProcAddress("glVertexAttrib3sARB");
	glVertexAttrib3svARBproc = (PFNGLVERTEXATTRIB3SVARBPROC)wglGetProcAddress("glVertexAttrib3svARB");
	glVertexAttrib4NbvARBproc = (PFNGLVERTEXATTRIB4NBVARBPROC)wglGetProcAddress("glVertexAttrib4NbvARB");
	glVertexAttrib4NivARBproc = (PFNGLVERTEXATTRIB4NIVARBPROC)wglGetProcAddress("glVertexAttrib4NivARB");
	glVertexAttrib4NsvARBproc = (PFNGLVERTEXATTRIB4NSVARBPROC)wglGetProcAddress("glVertexAttrib4NsvARB");
	glVertexAttrib4NubARBproc = (PFNGLVERTEXATTRIB4NUBARBPROC)wglGetProcAddress("glVertexAttrib4NubARB");
	glVertexAttrib4NubvARBproc = (PFNGLVERTEXATTRIB4NUBVARBPROC)wglGetProcAddress("glVertexAttrib4NubvARB");
	glVertexAttrib4NuivARBproc = (PFNGLVERTEXATTRIB4NUIVARBPROC)wglGetProcAddress("glVertexAttrib4NuivARB");
	glVertexAttrib4NusvARBproc = (PFNGLVERTEXATTRIB4NUSVARBPROC)wglGetProcAddress("glVertexAttrib4NusvARB");
	glVertexAttrib4bvARBproc = (PFNGLVERTEXATTRIB4BVARBPROC)wglGetProcAddress("glVertexAttrib4bvARB");
	glVertexAttrib4dARBproc = (PFNGLVERTEXATTRIB4DARBPROC)wglGetProcAddress("glVertexAttrib4dARB");
	glVertexAttrib4dvARBproc = (PFNGLVERTEXATTRIB4DVARBPROC)wglGetProcAddress("glVertexAttrib4dvARB");
	glVertexAttrib4fARBproc = (PFNGLVERTEXATTRIB4FARBPROC)wglGetProcAddress("glVertexAttrib4fARB");
	glVertexAttrib4fvARBproc = (PFNGLVERTEXATTRIB4FVARBPROC)wglGetProcAddress("glVertexAttrib4fvARB");
	glVertexAttrib4ivARBproc = (PFNGLVERTEXATTRIB4IVARBPROC)wglGetProcAddress("glVertexAttrib4ivARB");
	glVertexAttrib4sARBproc = (PFNGLVERTEXATTRIB4SARBPROC)wglGetProcAddress("glVertexAttrib4sARB");
	glVertexAttrib4svARBproc = (PFNGLVERTEXATTRIB4SVARBPROC)wglGetProcAddress("glVertexAttrib4svARB");
	glVertexAttrib4ubvARBproc = (PFNGLVERTEXATTRIB4UBVARBPROC)wglGetProcAddress("glVertexAttrib4ubvARB");
	glVertexAttrib4uivARBproc = (PFNGLVERTEXATTRIB4UIVARBPROC)wglGetProcAddress("glVertexAttrib4uivARB");
	glVertexAttrib4usvARBproc = (PFNGLVERTEXATTRIB4USVARBPROC)wglGetProcAddress("glVertexAttrib4usvARB");
	glVertexAttribPointerARBproc = (PFNGLVERTEXATTRIBPOINTERARBPROC)wglGetProcAddress("glVertexAttribPointerARB");
	glEnableVertexAttribArrayARBproc = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)wglGetProcAddress("glEnableVertexAttribArrayARB");
	glDisableVertexAttribArrayARBproc = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)wglGetProcAddress("glDisableVertexAttribArrayARB");
	glGetVertexAttribdvARBproc = (PFNGLGETVERTEXATTRIBDVARBPROC)wglGetProcAddress("glGetVertexAttribdvARB");
	glGetVertexAttribfvARBproc = (PFNGLGETVERTEXATTRIBFVARBPROC)wglGetProcAddress("glGetVertexAttribfvARB");
	glGetVertexAttribivARBproc = (PFNGLGETVERTEXATTRIBIVARBPROC)wglGetProcAddress("glGetVertexAttribivARB");
	glGetVertexAttribPointervARBproc = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)wglGetProcAddress("glGetVertexAttribPointervARB");
	glBindAttribLocationARBproc = (PFNGLBINDATTRIBLOCATIONARBPROC)wglGetProcAddress("glBindAttribLocationARB");
	glGetActiveAttribARBproc = (PFNGLGETACTIVEATTRIBARBPROC)wglGetProcAddress("glGetActiveAttribARB");
	glGetAttribLocationARBproc = (PFNGLGETATTRIBLOCATIONARBPROC)wglGetProcAddress("glGetAttribLocationARB");
	glDepthRangeArraydvNVproc = (PFNGLDEPTHRANGEARRAYDVNVPROC)wglGetProcAddress("glDepthRangeArraydvNV");
	glDepthRangeIndexeddNVproc = (PFNGLDEPTHRANGEINDEXEDDNVPROC)wglGetProcAddress("glDepthRangeIndexeddNV");
	glWindowPos2dARBproc = (PFNGLWINDOWPOS2DARBPROC)wglGetProcAddress("glWindowPos2dARB");
	glWindowPos2dvARBproc = (PFNGLWINDOWPOS2DVARBPROC)wglGetProcAddress("glWindowPos2dvARB");
	glWindowPos2fARBproc = (PFNGLWINDOWPOS2FARBPROC)wglGetProcAddress("glWindowPos2fARB");
	glWindowPos2fvARBproc = (PFNGLWINDOWPOS2FVARBPROC)wglGetProcAddress("glWindowPos2fvARB");
	glWindowPos2iARBproc = (PFNGLWINDOWPOS2IARBPROC)wglGetProcAddress("glWindowPos2iARB");
	glWindowPos2ivARBproc = (PFNGLWINDOWPOS2IVARBPROC)wglGetProcAddress("glWindowPos2ivARB");
	glWindowPos2sARBproc = (PFNGLWINDOWPOS2SARBPROC)wglGetProcAddress("glWindowPos2sARB");
	glWindowPos2svARBproc = (PFNGLWINDOWPOS2SVARBPROC)wglGetProcAddress("glWindowPos2svARB");
	glWindowPos3dARBproc = (PFNGLWINDOWPOS3DARBPROC)wglGetProcAddress("glWindowPos3dARB");
	glWindowPos3dvARBproc = (PFNGLWINDOWPOS3DVARBPROC)wglGetProcAddress("glWindowPos3dvARB");
	glWindowPos3fARBproc = (PFNGLWINDOWPOS3FARBPROC)wglGetProcAddress("glWindowPos3fARB");
	glWindowPos3fvARBproc = (PFNGLWINDOWPOS3FVARBPROC)wglGetProcAddress("glWindowPos3fvARB");
	glWindowPos3iARBproc = (PFNGLWINDOWPOS3IARBPROC)wglGetProcAddress("glWindowPos3iARB");
	glWindowPos3ivARBproc = (PFNGLWINDOWPOS3IVARBPROC)wglGetProcAddress("glWindowPos3ivARB");
	glWindowPos3sARBproc = (PFNGLWINDOWPOS3SARBPROC)wglGetProcAddress("glWindowPos3sARB");
	glWindowPos3svARBproc = (PFNGLWINDOWPOS3SVARBPROC)wglGetProcAddress("glWindowPos3svARB");
	glBlendBarrierKHRproc = (PFNGLBLENDBARRIERKHRPROC)wglGetProcAddress("glBlendBarrierKHR");
	glMaxShaderCompilerThreadsKHRproc = (PFNGLMAXSHADERCOMPILERTHREADSKHRPROC)wglGetProcAddress("glMaxShaderCompilerThreadsKHR");
	glMultiTexCoord1bOESproc = (PFNGLMULTITEXCOORD1BOESPROC)wglGetProcAddress("glMultiTexCoord1bOES");
	glMultiTexCoord1bvOESproc = (PFNGLMULTITEXCOORD1BVOESPROC)wglGetProcAddress("glMultiTexCoord1bvOES");
	glMultiTexCoord2bOESproc = (PFNGLMULTITEXCOORD2BOESPROC)wglGetProcAddress("glMultiTexCoord2bOES");
	glMultiTexCoord2bvOESproc = (PFNGLMULTITEXCOORD2BVOESPROC)wglGetProcAddress("glMultiTexCoord2bvOES");
	glMultiTexCoord3bOESproc = (PFNGLMULTITEXCOORD3BOESPROC)wglGetProcAddress("glMultiTexCoord3bOES");
	glMultiTexCoord3bvOESproc = (PFNGLMULTITEXCOORD3BVOESPROC)wglGetProcAddress("glMultiTexCoord3bvOES");
	glMultiTexCoord4bOESproc = (PFNGLMULTITEXCOORD4BOESPROC)wglGetProcAddress("glMultiTexCoord4bOES");
	glMultiTexCoord4bvOESproc = (PFNGLMULTITEXCOORD4BVOESPROC)wglGetProcAddress("glMultiTexCoord4bvOES");
	glTexCoord1bOESproc = (PFNGLTEXCOORD1BOESPROC)wglGetProcAddress("glTexCoord1bOES");
	glTexCoord1bvOESproc = (PFNGLTEXCOORD1BVOESPROC)wglGetProcAddress("glTexCoord1bvOES");
	glTexCoord2bOESproc = (PFNGLTEXCOORD2BOESPROC)wglGetProcAddress("glTexCoord2bOES");
	glTexCoord2bvOESproc = (PFNGLTEXCOORD2BVOESPROC)wglGetProcAddress("glTexCoord2bvOES");
	glTexCoord3bOESproc = (PFNGLTEXCOORD3BOESPROC)wglGetProcAddress("glTexCoord3bOES");
	glTexCoord3bvOESproc = (PFNGLTEXCOORD3BVOESPROC)wglGetProcAddress("glTexCoord3bvOES");
	glTexCoord4bOESproc = (PFNGLTEXCOORD4BOESPROC)wglGetProcAddress("glTexCoord4bOES");
	glTexCoord4bvOESproc = (PFNGLTEXCOORD4BVOESPROC)wglGetProcAddress("glTexCoord4bvOES");
	glVertex2bOESproc = (PFNGLVERTEX2BOESPROC)wglGetProcAddress("glVertex2bOES");
	glVertex2bvOESproc = (PFNGLVERTEX2BVOESPROC)wglGetProcAddress("glVertex2bvOES");
	glVertex3bOESproc = (PFNGLVERTEX3BOESPROC)wglGetProcAddress("glVertex3bOES");
	glVertex3bvOESproc = (PFNGLVERTEX3BVOESPROC)wglGetProcAddress("glVertex3bvOES");
	glVertex4bOESproc = (PFNGLVERTEX4BOESPROC)wglGetProcAddress("glVertex4bOES");
	glVertex4bvOESproc = (PFNGLVERTEX4BVOESPROC)wglGetProcAddress("glVertex4bvOES");
	glAlphaFuncxOESproc = (PFNGLALPHAFUNCXOESPROC)wglGetProcAddress("glAlphaFuncxOES");
	glClearColorxOESproc = (PFNGLCLEARCOLORXOESPROC)wglGetProcAddress("glClearColorxOES");
	glClearDepthxOESproc = (PFNGLCLEARDEPTHXOESPROC)wglGetProcAddress("glClearDepthxOES");
	glClipPlanexOESproc = (PFNGLCLIPPLANEXOESPROC)wglGetProcAddress("glClipPlanexOES");
	glColor4xOESproc = (PFNGLCOLOR4XOESPROC)wglGetProcAddress("glColor4xOES");
	glDepthRangexOESproc = (PFNGLDEPTHRANGEXOESPROC)wglGetProcAddress("glDepthRangexOES");
	glFogxOESproc = (PFNGLFOGXOESPROC)wglGetProcAddress("glFogxOES");
	glFogxvOESproc = (PFNGLFOGXVOESPROC)wglGetProcAddress("glFogxvOES");
	glFrustumxOESproc = (PFNGLFRUSTUMXOESPROC)wglGetProcAddress("glFrustumxOES");
	glGetClipPlanexOESproc = (PFNGLGETCLIPPLANEXOESPROC)wglGetProcAddress("glGetClipPlanexOES");
	glGetFixedvOESproc = (PFNGLGETFIXEDVOESPROC)wglGetProcAddress("glGetFixedvOES");
	glGetTexEnvxvOESproc = (PFNGLGETTEXENVXVOESPROC)wglGetProcAddress("glGetTexEnvxvOES");
	glGetTexParameterxvOESproc = (PFNGLGETTEXPARAMETERXVOESPROC)wglGetProcAddress("glGetTexParameterxvOES");
	glLightModelxOESproc = (PFNGLLIGHTMODELXOESPROC)wglGetProcAddress("glLightModelxOES");
	glLightModelxvOESproc = (PFNGLLIGHTMODELXVOESPROC)wglGetProcAddress("glLightModelxvOES");
	glLightxOESproc = (PFNGLLIGHTXOESPROC)wglGetProcAddress("glLightxOES");
	glLightxvOESproc = (PFNGLLIGHTXVOESPROC)wglGetProcAddress("glLightxvOES");
	glLineWidthxOESproc = (PFNGLLINEWIDTHXOESPROC)wglGetProcAddress("glLineWidthxOES");
	glLoadMatrixxOESproc = (PFNGLLOADMATRIXXOESPROC)wglGetProcAddress("glLoadMatrixxOES");
	glMaterialxOESproc = (PFNGLMATERIALXOESPROC)wglGetProcAddress("glMaterialxOES");
	glMaterialxvOESproc = (PFNGLMATERIALXVOESPROC)wglGetProcAddress("glMaterialxvOES");
	glMultMatrixxOESproc = (PFNGLMULTMATRIXXOESPROC)wglGetProcAddress("glMultMatrixxOES");
	glMultiTexCoord4xOESproc = (PFNGLMULTITEXCOORD4XOESPROC)wglGetProcAddress("glMultiTexCoord4xOES");
	glNormal3xOESproc = (PFNGLNORMAL3XOESPROC)wglGetProcAddress("glNormal3xOES");
	glOrthoxOESproc = (PFNGLORTHOXOESPROC)wglGetProcAddress("glOrthoxOES");
	glPointParameterxvOESproc = (PFNGLPOINTPARAMETERXVOESPROC)wglGetProcAddress("glPointParameterxvOES");
	glPointSizexOESproc = (PFNGLPOINTSIZEXOESPROC)wglGetProcAddress("glPointSizexOES");
	glPolygonOffsetxOESproc = (PFNGLPOLYGONOFFSETXOESPROC)wglGetProcAddress("glPolygonOffsetxOES");
	glRotatexOESproc = (PFNGLROTATEXOESPROC)wglGetProcAddress("glRotatexOES");
	glScalexOESproc = (PFNGLSCALEXOESPROC)wglGetProcAddress("glScalexOES");
	glTexEnvxOESproc = (PFNGLTEXENVXOESPROC)wglGetProcAddress("glTexEnvxOES");
	glTexEnvxvOESproc = (PFNGLTEXENVXVOESPROC)wglGetProcAddress("glTexEnvxvOES");
	glTexParameterxOESproc = (PFNGLTEXPARAMETERXOESPROC)wglGetProcAddress("glTexParameterxOES");
	glTexParameterxvOESproc = (PFNGLTEXPARAMETERXVOESPROC)wglGetProcAddress("glTexParameterxvOES");
	glTranslatexOESproc = (PFNGLTRANSLATEXOESPROC)wglGetProcAddress("glTranslatexOES");
	glAccumxOESproc = (PFNGLACCUMXOESPROC)wglGetProcAddress("glAccumxOES");
	glBitmapxOESproc = (PFNGLBITMAPXOESPROC)wglGetProcAddress("glBitmapxOES");
	glBlendColorxOESproc = (PFNGLBLENDCOLORXOESPROC)wglGetProcAddress("glBlendColorxOES");
	glClearAccumxOESproc = (PFNGLCLEARACCUMXOESPROC)wglGetProcAddress("glClearAccumxOES");
	glColor3xOESproc = (PFNGLCOLOR3XOESPROC)wglGetProcAddress("glColor3xOES");
	glColor3xvOESproc = (PFNGLCOLOR3XVOESPROC)wglGetProcAddress("glColor3xvOES");
	glColor4xvOESproc = (PFNGLCOLOR4XVOESPROC)wglGetProcAddress("glColor4xvOES");
	glConvolutionParameterxOESproc = (PFNGLCONVOLUTIONPARAMETERXOESPROC)wglGetProcAddress("glConvolutionParameterxOES");
	glConvolutionParameterxvOESproc = (PFNGLCONVOLUTIONPARAMETERXVOESPROC)wglGetProcAddress("glConvolutionParameterxvOES");
	glEvalCoord1xOESproc = (PFNGLEVALCOORD1XOESPROC)wglGetProcAddress("glEvalCoord1xOES");
	glEvalCoord1xvOESproc = (PFNGLEVALCOORD1XVOESPROC)wglGetProcAddress("glEvalCoord1xvOES");
	glEvalCoord2xOESproc = (PFNGLEVALCOORD2XOESPROC)wglGetProcAddress("glEvalCoord2xOES");
	glEvalCoord2xvOESproc = (PFNGLEVALCOORD2XVOESPROC)wglGetProcAddress("glEvalCoord2xvOES");
	glFeedbackBufferxOESproc = (PFNGLFEEDBACKBUFFERXOESPROC)wglGetProcAddress("glFeedbackBufferxOES");
	glGetConvolutionParameterxvOESproc = (PFNGLGETCONVOLUTIONPARAMETERXVOESPROC)wglGetProcAddress("glGetConvolutionParameterxvOES");
	glGetHistogramParameterxvOESproc = (PFNGLGETHISTOGRAMPARAMETERXVOESPROC)wglGetProcAddress("glGetHistogramParameterxvOES");
	glGetLightxOESproc = (PFNGLGETLIGHTXOESPROC)wglGetProcAddress("glGetLightxOES");
	glGetMapxvOESproc = (PFNGLGETMAPXVOESPROC)wglGetProcAddress("glGetMapxvOES");
	glGetMaterialxOESproc = (PFNGLGETMATERIALXOESPROC)wglGetProcAddress("glGetMaterialxOES");
	glGetPixelMapxvproc = (PFNGLGETPIXELMAPXVPROC)wglGetProcAddress("glGetPixelMapxv");
	glGetTexGenxvOESproc = (PFNGLGETTEXGENXVOESPROC)wglGetProcAddress("glGetTexGenxvOES");
	glGetTexLevelParameterxvOESproc = (PFNGLGETTEXLEVELPARAMETERXVOESPROC)wglGetProcAddress("glGetTexLevelParameterxvOES");
	glIndexxOESproc = (PFNGLINDEXXOESPROC)wglGetProcAddress("glIndexxOES");
	glIndexxvOESproc = (PFNGLINDEXXVOESPROC)wglGetProcAddress("glIndexxvOES");
	glLoadTransposeMatrixxOESproc = (PFNGLLOADTRANSPOSEMATRIXXOESPROC)wglGetProcAddress("glLoadTransposeMatrixxOES");
	glMap1xOESproc = (PFNGLMAP1XOESPROC)wglGetProcAddress("glMap1xOES");
	glMap2xOESproc = (PFNGLMAP2XOESPROC)wglGetProcAddress("glMap2xOES");
	glMapGrid1xOESproc = (PFNGLMAPGRID1XOESPROC)wglGetProcAddress("glMapGrid1xOES");
	glMapGrid2xOESproc = (PFNGLMAPGRID2XOESPROC)wglGetProcAddress("glMapGrid2xOES");
	glMultTransposeMatrixxOESproc = (PFNGLMULTTRANSPOSEMATRIXXOESPROC)wglGetProcAddress("glMultTransposeMatrixxOES");
	glMultiTexCoord1xOESproc = (PFNGLMULTITEXCOORD1XOESPROC)wglGetProcAddress("glMultiTexCoord1xOES");
	glMultiTexCoord1xvOESproc = (PFNGLMULTITEXCOORD1XVOESPROC)wglGetProcAddress("glMultiTexCoord1xvOES");
	glMultiTexCoord2xOESproc = (PFNGLMULTITEXCOORD2XOESPROC)wglGetProcAddress("glMultiTexCoord2xOES");
	glMultiTexCoord2xvOESproc = (PFNGLMULTITEXCOORD2XVOESPROC)wglGetProcAddress("glMultiTexCoord2xvOES");
	glMultiTexCoord3xOESproc = (PFNGLMULTITEXCOORD3XOESPROC)wglGetProcAddress("glMultiTexCoord3xOES");
	glMultiTexCoord3xvOESproc = (PFNGLMULTITEXCOORD3XVOESPROC)wglGetProcAddress("glMultiTexCoord3xvOES");
	glMultiTexCoord4xvOESproc = (PFNGLMULTITEXCOORD4XVOESPROC)wglGetProcAddress("glMultiTexCoord4xvOES");
	glNormal3xvOESproc = (PFNGLNORMAL3XVOESPROC)wglGetProcAddress("glNormal3xvOES");
	glPassThroughxOESproc = (PFNGLPASSTHROUGHXOESPROC)wglGetProcAddress("glPassThroughxOES");
	glPixelMapxproc = (PFNGLPIXELMAPXPROC)wglGetProcAddress("glPixelMapx");
	glPixelStorexproc = (PFNGLPIXELSTOREXPROC)wglGetProcAddress("glPixelStorex");
	glPixelTransferxOESproc = (PFNGLPIXELTRANSFERXOESPROC)wglGetProcAddress("glPixelTransferxOES");
	glPixelZoomxOESproc = (PFNGLPIXELZOOMXOESPROC)wglGetProcAddress("glPixelZoomxOES");
	glPrioritizeTexturesxOESproc = (PFNGLPRIORITIZETEXTURESXOESPROC)wglGetProcAddress("glPrioritizeTexturesxOES");
	glRasterPos2xOESproc = (PFNGLRASTERPOS2XOESPROC)wglGetProcAddress("glRasterPos2xOES");
	glRasterPos2xvOESproc = (PFNGLRASTERPOS2XVOESPROC)wglGetProcAddress("glRasterPos2xvOES");
	glRasterPos3xOESproc = (PFNGLRASTERPOS3XOESPROC)wglGetProcAddress("glRasterPos3xOES");
	glRasterPos3xvOESproc = (PFNGLRASTERPOS3XVOESPROC)wglGetProcAddress("glRasterPos3xvOES");
	glRasterPos4xOESproc = (PFNGLRASTERPOS4XOESPROC)wglGetProcAddress("glRasterPos4xOES");
	glRasterPos4xvOESproc = (PFNGLRASTERPOS4XVOESPROC)wglGetProcAddress("glRasterPos4xvOES");
	glRectxOESproc = (PFNGLRECTXOESPROC)wglGetProcAddress("glRectxOES");
	glRectxvOESproc = (PFNGLRECTXVOESPROC)wglGetProcAddress("glRectxvOES");
	glTexCoord1xOESproc = (PFNGLTEXCOORD1XOESPROC)wglGetProcAddress("glTexCoord1xOES");
	glTexCoord1xvOESproc = (PFNGLTEXCOORD1XVOESPROC)wglGetProcAddress("glTexCoord1xvOES");
	glTexCoord2xOESproc = (PFNGLTEXCOORD2XOESPROC)wglGetProcAddress("glTexCoord2xOES");
	glTexCoord2xvOESproc = (PFNGLTEXCOORD2XVOESPROC)wglGetProcAddress("glTexCoord2xvOES");
	glTexCoord3xOESproc = (PFNGLTEXCOORD3XOESPROC)wglGetProcAddress("glTexCoord3xOES");
	glTexCoord3xvOESproc = (PFNGLTEXCOORD3XVOESPROC)wglGetProcAddress("glTexCoord3xvOES");
	glTexCoord4xOESproc = (PFNGLTEXCOORD4XOESPROC)wglGetProcAddress("glTexCoord4xOES");
	glTexCoord4xvOESproc = (PFNGLTEXCOORD4XVOESPROC)wglGetProcAddress("glTexCoord4xvOES");
	glTexGenxOESproc = (PFNGLTEXGENXOESPROC)wglGetProcAddress("glTexGenxOES");
	glTexGenxvOESproc = (PFNGLTEXGENXVOESPROC)wglGetProcAddress("glTexGenxvOES");
	glVertex2xOESproc = (PFNGLVERTEX2XOESPROC)wglGetProcAddress("glVertex2xOES");
	glVertex2xvOESproc = (PFNGLVERTEX2XVOESPROC)wglGetProcAddress("glVertex2xvOES");
	glVertex3xOESproc = (PFNGLVERTEX3XOESPROC)wglGetProcAddress("glVertex3xOES");
	glVertex3xvOESproc = (PFNGLVERTEX3XVOESPROC)wglGetProcAddress("glVertex3xvOES");
	glVertex4xOESproc = (PFNGLVERTEX4XOESPROC)wglGetProcAddress("glVertex4xOES");
	glVertex4xvOESproc = (PFNGLVERTEX4XVOESPROC)wglGetProcAddress("glVertex4xvOES");
	glQueryMatrixxOESproc = (PFNGLQUERYMATRIXXOESPROC)wglGetProcAddress("glQueryMatrixxOES");
	glClearDepthfOESproc = (PFNGLCLEARDEPTHFOESPROC)wglGetProcAddress("glClearDepthfOES");
	glClipPlanefOESproc = (PFNGLCLIPPLANEFOESPROC)wglGetProcAddress("glClipPlanefOES");
	glDepthRangefOESproc = (PFNGLDEPTHRANGEFOESPROC)wglGetProcAddress("glDepthRangefOES");
	glFrustumfOESproc = (PFNGLFRUSTUMFOESPROC)wglGetProcAddress("glFrustumfOES");
	glGetClipPlanefOESproc = (PFNGLGETCLIPPLANEFOESPROC)wglGetProcAddress("glGetClipPlanefOES");
	glOrthofOESproc = (PFNGLORTHOFOESPROC)wglGetProcAddress("glOrthofOES");
	glTbufferMask3DFXproc = (PFNGLTBUFFERMASK3DFXPROC)wglGetProcAddress("glTbufferMask3DFX");
	glDebugMessageEnableAMDproc = (PFNGLDEBUGMESSAGEENABLEAMDPROC)wglGetProcAddress("glDebugMessageEnableAMD");
	glDebugMessageInsertAMDproc = (PFNGLDEBUGMESSAGEINSERTAMDPROC)wglGetProcAddress("glDebugMessageInsertAMD");
	glDebugMessageCallbackAMDproc = (PFNGLDEBUGMESSAGECALLBACKAMDPROC)wglGetProcAddress("glDebugMessageCallbackAMD");
	glGetDebugMessageLogAMDproc = (PFNGLGETDEBUGMESSAGELOGAMDPROC)wglGetProcAddress("glGetDebugMessageLogAMD");
	glBlendFuncIndexedAMDproc = (PFNGLBLENDFUNCINDEXEDAMDPROC)wglGetProcAddress("glBlendFuncIndexedAMD");
	glBlendFuncSeparateIndexedAMDproc = (PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)wglGetProcAddress("glBlendFuncSeparateIndexedAMD");
	glBlendEquationIndexedAMDproc = (PFNGLBLENDEQUATIONINDEXEDAMDPROC)wglGetProcAddress("glBlendEquationIndexedAMD");
	glBlendEquationSeparateIndexedAMDproc = (PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)wglGetProcAddress("glBlendEquationSeparateIndexedAMD");
	glRenderbufferStorageMultisampleAdvancedAMDproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)wglGetProcAddress("glRenderbufferStorageMultisampleAdvancedAMD");
	glNamedRenderbufferStorageMultisampleAdvancedAMDproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisampleAdvancedAMD");
	glFramebufferSamplePositionsfvAMDproc = (PFNGLFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC)wglGetProcAddress("glFramebufferSamplePositionsfvAMD");
	glNamedFramebufferSamplePositionsfvAMDproc = (PFNGLNAMEDFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC)wglGetProcAddress("glNamedFramebufferSamplePositionsfvAMD");
	glGetFramebufferParameterfvAMDproc = (PFNGLGETFRAMEBUFFERPARAMETERFVAMDPROC)wglGetProcAddress("glGetFramebufferParameterfvAMD");
	glGetNamedFramebufferParameterfvAMDproc = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERFVAMDPROC)wglGetProcAddress("glGetNamedFramebufferParameterfvAMD");
	glUniform1i64NVproc = (PFNGLUNIFORM1I64NVPROC)wglGetProcAddress("glUniform1i64NV");
	glUniform2i64NVproc = (PFNGLUNIFORM2I64NVPROC)wglGetProcAddress("glUniform2i64NV");
	glUniform3i64NVproc = (PFNGLUNIFORM3I64NVPROC)wglGetProcAddress("glUniform3i64NV");
	glUniform4i64NVproc = (PFNGLUNIFORM4I64NVPROC)wglGetProcAddress("glUniform4i64NV");
	glUniform1i64vNVproc = (PFNGLUNIFORM1I64VNVPROC)wglGetProcAddress("glUniform1i64vNV");
	glUniform2i64vNVproc = (PFNGLUNIFORM2I64VNVPROC)wglGetProcAddress("glUniform2i64vNV");
	glUniform3i64vNVproc = (PFNGLUNIFORM3I64VNVPROC)wglGetProcAddress("glUniform3i64vNV");
	glUniform4i64vNVproc = (PFNGLUNIFORM4I64VNVPROC)wglGetProcAddress("glUniform4i64vNV");
	glUniform1ui64NVproc = (PFNGLUNIFORM1UI64NVPROC)wglGetProcAddress("glUniform1ui64NV");
	glUniform2ui64NVproc = (PFNGLUNIFORM2UI64NVPROC)wglGetProcAddress("glUniform2ui64NV");
	glUniform3ui64NVproc = (PFNGLUNIFORM3UI64NVPROC)wglGetProcAddress("glUniform3ui64NV");
	glUniform4ui64NVproc = (PFNGLUNIFORM4UI64NVPROC)wglGetProcAddress("glUniform4ui64NV");
	glUniform1ui64vNVproc = (PFNGLUNIFORM1UI64VNVPROC)wglGetProcAddress("glUniform1ui64vNV");
	glUniform2ui64vNVproc = (PFNGLUNIFORM2UI64VNVPROC)wglGetProcAddress("glUniform2ui64vNV");
	glUniform3ui64vNVproc = (PFNGLUNIFORM3UI64VNVPROC)wglGetProcAddress("glUniform3ui64vNV");
	glUniform4ui64vNVproc = (PFNGLUNIFORM4UI64VNVPROC)wglGetProcAddress("glUniform4ui64vNV");
	glGetUniformi64vNVproc = (PFNGLGETUNIFORMI64VNVPROC)wglGetProcAddress("glGetUniformi64vNV");
	glGetUniformui64vNVproc = (PFNGLGETUNIFORMUI64VNVPROC)wglGetProcAddress("glGetUniformui64vNV");
	glProgramUniform1i64NVproc = (PFNGLPROGRAMUNIFORM1I64NVPROC)wglGetProcAddress("glProgramUniform1i64NV");
	glProgramUniform2i64NVproc = (PFNGLPROGRAMUNIFORM2I64NVPROC)wglGetProcAddress("glProgramUniform2i64NV");
	glProgramUniform3i64NVproc = (PFNGLPROGRAMUNIFORM3I64NVPROC)wglGetProcAddress("glProgramUniform3i64NV");
	glProgramUniform4i64NVproc = (PFNGLPROGRAMUNIFORM4I64NVPROC)wglGetProcAddress("glProgramUniform4i64NV");
	glProgramUniform1i64vNVproc = (PFNGLPROGRAMUNIFORM1I64VNVPROC)wglGetProcAddress("glProgramUniform1i64vNV");
	glProgramUniform2i64vNVproc = (PFNGLPROGRAMUNIFORM2I64VNVPROC)wglGetProcAddress("glProgramUniform2i64vNV");
	glProgramUniform3i64vNVproc = (PFNGLPROGRAMUNIFORM3I64VNVPROC)wglGetProcAddress("glProgramUniform3i64vNV");
	glProgramUniform4i64vNVproc = (PFNGLPROGRAMUNIFORM4I64VNVPROC)wglGetProcAddress("glProgramUniform4i64vNV");
	glProgramUniform1ui64NVproc = (PFNGLPROGRAMUNIFORM1UI64NVPROC)wglGetProcAddress("glProgramUniform1ui64NV");
	glProgramUniform2ui64NVproc = (PFNGLPROGRAMUNIFORM2UI64NVPROC)wglGetProcAddress("glProgramUniform2ui64NV");
	glProgramUniform3ui64NVproc = (PFNGLPROGRAMUNIFORM3UI64NVPROC)wglGetProcAddress("glProgramUniform3ui64NV");
	glProgramUniform4ui64NVproc = (PFNGLPROGRAMUNIFORM4UI64NVPROC)wglGetProcAddress("glProgramUniform4ui64NV");
	glProgramUniform1ui64vNVproc = (PFNGLPROGRAMUNIFORM1UI64VNVPROC)wglGetProcAddress("glProgramUniform1ui64vNV");
	glProgramUniform2ui64vNVproc = (PFNGLPROGRAMUNIFORM2UI64VNVPROC)wglGetProcAddress("glProgramUniform2ui64vNV");
	glProgramUniform3ui64vNVproc = (PFNGLPROGRAMUNIFORM3UI64VNVPROC)wglGetProcAddress("glProgramUniform3ui64vNV");
	glProgramUniform4ui64vNVproc = (PFNGLPROGRAMUNIFORM4UI64VNVPROC)wglGetProcAddress("glProgramUniform4ui64vNV");
	glVertexAttribParameteriAMDproc = (PFNGLVERTEXATTRIBPARAMETERIAMDPROC)wglGetProcAddress("glVertexAttribParameteriAMD");
	glMultiDrawArraysIndirectAMDproc = (PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)wglGetProcAddress("glMultiDrawArraysIndirectAMD");
	glMultiDrawElementsIndirectAMDproc = (PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)wglGetProcAddress("glMultiDrawElementsIndirectAMD");
	glGenNamesAMDproc = (PFNGLGENNAMESAMDPROC)wglGetProcAddress("glGenNamesAMD");
	glDeleteNamesAMDproc = (PFNGLDELETENAMESAMDPROC)wglGetProcAddress("glDeleteNamesAMD");
	glIsNameAMDproc = (PFNGLISNAMEAMDPROC)wglGetProcAddress("glIsNameAMD");
	glQueryObjectParameteruiAMDproc = (PFNGLQUERYOBJECTPARAMETERUIAMDPROC)wglGetProcAddress("glQueryObjectParameteruiAMD");
	glGetPerfMonitorGroupsAMDproc = (PFNGLGETPERFMONITORGROUPSAMDPROC)wglGetProcAddress("glGetPerfMonitorGroupsAMD");
	glGetPerfMonitorCountersAMDproc = (PFNGLGETPERFMONITORCOUNTERSAMDPROC)wglGetProcAddress("glGetPerfMonitorCountersAMD");
	glGetPerfMonitorGroupStringAMDproc = (PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)wglGetProcAddress("glGetPerfMonitorGroupStringAMD");
	glGetPerfMonitorCounterStringAMDproc = (PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)wglGetProcAddress("glGetPerfMonitorCounterStringAMD");
	glGetPerfMonitorCounterInfoAMDproc = (PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)wglGetProcAddress("glGetPerfMonitorCounterInfoAMD");
	glGenPerfMonitorsAMDproc = (PFNGLGENPERFMONITORSAMDPROC)wglGetProcAddress("glGenPerfMonitorsAMD");
	glDeletePerfMonitorsAMDproc = (PFNGLDELETEPERFMONITORSAMDPROC)wglGetProcAddress("glDeletePerfMonitorsAMD");
	glSelectPerfMonitorCountersAMDproc = (PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)wglGetProcAddress("glSelectPerfMonitorCountersAMD");
	glBeginPerfMonitorAMDproc = (PFNGLBEGINPERFMONITORAMDPROC)wglGetProcAddress("glBeginPerfMonitorAMD");
	glEndPerfMonitorAMDproc = (PFNGLENDPERFMONITORAMDPROC)wglGetProcAddress("glEndPerfMonitorAMD");
	glGetPerfMonitorCounterDataAMDproc = (PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)wglGetProcAddress("glGetPerfMonitorCounterDataAMD");
	glSetMultisamplefvAMDproc = (PFNGLSETMULTISAMPLEFVAMDPROC)wglGetProcAddress("glSetMultisamplefvAMD");
	glTexStorageSparseAMDproc = (PFNGLTEXSTORAGESPARSEAMDPROC)wglGetProcAddress("glTexStorageSparseAMD");
	glTextureStorageSparseAMDproc = (PFNGLTEXTURESTORAGESPARSEAMDPROC)wglGetProcAddress("glTextureStorageSparseAMD");
	glStencilOpValueAMDproc = (PFNGLSTENCILOPVALUEAMDPROC)wglGetProcAddress("glStencilOpValueAMD");
	glTessellationFactorAMDproc = (PFNGLTESSELLATIONFACTORAMDPROC)wglGetProcAddress("glTessellationFactorAMD");
	glTessellationModeAMDproc = (PFNGLTESSELLATIONMODEAMDPROC)wglGetProcAddress("glTessellationModeAMD");
	glElementPointerAPPLEproc = (PFNGLELEMENTPOINTERAPPLEPROC)wglGetProcAddress("glElementPointerAPPLE");
	glDrawElementArrayAPPLEproc = (PFNGLDRAWELEMENTARRAYAPPLEPROC)wglGetProcAddress("glDrawElementArrayAPPLE");
	glDrawRangeElementArrayAPPLEproc = (PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)wglGetProcAddress("glDrawRangeElementArrayAPPLE");
	glMultiDrawElementArrayAPPLEproc = (PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)wglGetProcAddress("glMultiDrawElementArrayAPPLE");
	glMultiDrawRangeElementArrayAPPLEproc = (PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)wglGetProcAddress("glMultiDrawRangeElementArrayAPPLE");
	glGenFencesAPPLEproc = (PFNGLGENFENCESAPPLEPROC)wglGetProcAddress("glGenFencesAPPLE");
	glDeleteFencesAPPLEproc = (PFNGLDELETEFENCESAPPLEPROC)wglGetProcAddress("glDeleteFencesAPPLE");
	glSetFenceAPPLEproc = (PFNGLSETFENCEAPPLEPROC)wglGetProcAddress("glSetFenceAPPLE");
	glIsFenceAPPLEproc = (PFNGLISFENCEAPPLEPROC)wglGetProcAddress("glIsFenceAPPLE");
	glTestFenceAPPLEproc = (PFNGLTESTFENCEAPPLEPROC)wglGetProcAddress("glTestFenceAPPLE");
	glFinishFenceAPPLEproc = (PFNGLFINISHFENCEAPPLEPROC)wglGetProcAddress("glFinishFenceAPPLE");
	glTestObjectAPPLEproc = (PFNGLTESTOBJECTAPPLEPROC)wglGetProcAddress("glTestObjectAPPLE");
	glFinishObjectAPPLEproc = (PFNGLFINISHOBJECTAPPLEPROC)wglGetProcAddress("glFinishObjectAPPLE");
	glBufferParameteriAPPLEproc = (PFNGLBUFFERPARAMETERIAPPLEPROC)wglGetProcAddress("glBufferParameteriAPPLE");
	glFlushMappedBufferRangeAPPLEproc = (PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)wglGetProcAddress("glFlushMappedBufferRangeAPPLE");
	glObjectPurgeableAPPLEproc = (PFNGLOBJECTPURGEABLEAPPLEPROC)wglGetProcAddress("glObjectPurgeableAPPLE");
	glObjectUnpurgeableAPPLEproc = (PFNGLOBJECTUNPURGEABLEAPPLEPROC)wglGetProcAddress("glObjectUnpurgeableAPPLE");
	glGetObjectParameterivAPPLEproc = (PFNGLGETOBJECTPARAMETERIVAPPLEPROC)wglGetProcAddress("glGetObjectParameterivAPPLE");
	glTextureRangeAPPLEproc = (PFNGLTEXTURERANGEAPPLEPROC)wglGetProcAddress("glTextureRangeAPPLE");
	glGetTexParameterPointervAPPLEproc = (PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)wglGetProcAddress("glGetTexParameterPointervAPPLE");
	glBindVertexArrayAPPLEproc = (PFNGLBINDVERTEXARRAYAPPLEPROC)wglGetProcAddress("glBindVertexArrayAPPLE");
	glDeleteVertexArraysAPPLEproc = (PFNGLDELETEVERTEXARRAYSAPPLEPROC)wglGetProcAddress("glDeleteVertexArraysAPPLE");
	glGenVertexArraysAPPLEproc = (PFNGLGENVERTEXARRAYSAPPLEPROC)wglGetProcAddress("glGenVertexArraysAPPLE");
	glIsVertexArrayAPPLEproc = (PFNGLISVERTEXARRAYAPPLEPROC)wglGetProcAddress("glIsVertexArrayAPPLE");
	glVertexArrayRangeAPPLEproc = (PFNGLVERTEXARRAYRANGEAPPLEPROC)wglGetProcAddress("glVertexArrayRangeAPPLE");
	glFlushVertexArrayRangeAPPLEproc = (PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)wglGetProcAddress("glFlushVertexArrayRangeAPPLE");
	glVertexArrayParameteriAPPLEproc = (PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)wglGetProcAddress("glVertexArrayParameteriAPPLE");
	glEnableVertexAttribAPPLEproc = (PFNGLENABLEVERTEXATTRIBAPPLEPROC)wglGetProcAddress("glEnableVertexAttribAPPLE");
	glDisableVertexAttribAPPLEproc = (PFNGLDISABLEVERTEXATTRIBAPPLEPROC)wglGetProcAddress("glDisableVertexAttribAPPLE");
	glIsVertexAttribEnabledAPPLEproc = (PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)wglGetProcAddress("glIsVertexAttribEnabledAPPLE");
	glMapVertexAttrib1dAPPLEproc = (PFNGLMAPVERTEXATTRIB1DAPPLEPROC)wglGetProcAddress("glMapVertexAttrib1dAPPLE");
	glMapVertexAttrib1fAPPLEproc = (PFNGLMAPVERTEXATTRIB1FAPPLEPROC)wglGetProcAddress("glMapVertexAttrib1fAPPLE");
	glMapVertexAttrib2dAPPLEproc = (PFNGLMAPVERTEXATTRIB2DAPPLEPROC)wglGetProcAddress("glMapVertexAttrib2dAPPLE");
	glMapVertexAttrib2fAPPLEproc = (PFNGLMAPVERTEXATTRIB2FAPPLEPROC)wglGetProcAddress("glMapVertexAttrib2fAPPLE");
	glDrawBuffersATIproc = (PFNGLDRAWBUFFERSATIPROC)wglGetProcAddress("glDrawBuffersATI");
	glElementPointerATIproc = (PFNGLELEMENTPOINTERATIPROC)wglGetProcAddress("glElementPointerATI");
	glDrawElementArrayATIproc = (PFNGLDRAWELEMENTARRAYATIPROC)wglGetProcAddress("glDrawElementArrayATI");
	glDrawRangeElementArrayATIproc = (PFNGLDRAWRANGEELEMENTARRAYATIPROC)wglGetProcAddress("glDrawRangeElementArrayATI");
	glTexBumpParameterivATIproc = (PFNGLTEXBUMPPARAMETERIVATIPROC)wglGetProcAddress("glTexBumpParameterivATI");
	glTexBumpParameterfvATIproc = (PFNGLTEXBUMPPARAMETERFVATIPROC)wglGetProcAddress("glTexBumpParameterfvATI");
	glGetTexBumpParameterivATIproc = (PFNGLGETTEXBUMPPARAMETERIVATIPROC)wglGetProcAddress("glGetTexBumpParameterivATI");
	glGetTexBumpParameterfvATIproc = (PFNGLGETTEXBUMPPARAMETERFVATIPROC)wglGetProcAddress("glGetTexBumpParameterfvATI");
	glGenFragmentShadersATIproc = (PFNGLGENFRAGMENTSHADERSATIPROC)wglGetProcAddress("glGenFragmentShadersATI");
	glBindFragmentShaderATIproc = (PFNGLBINDFRAGMENTSHADERATIPROC)wglGetProcAddress("glBindFragmentShaderATI");
	glDeleteFragmentShaderATIproc = (PFNGLDELETEFRAGMENTSHADERATIPROC)wglGetProcAddress("glDeleteFragmentShaderATI");
	glBeginFragmentShaderATIproc = (PFNGLBEGINFRAGMENTSHADERATIPROC)wglGetProcAddress("glBeginFragmentShaderATI");
	glEndFragmentShaderATIproc = (PFNGLENDFRAGMENTSHADERATIPROC)wglGetProcAddress("glEndFragmentShaderATI");
	glPassTexCoordATIproc = (PFNGLPASSTEXCOORDATIPROC)wglGetProcAddress("glPassTexCoordATI");
	glSampleMapATIproc = (PFNGLSAMPLEMAPATIPROC)wglGetProcAddress("glSampleMapATI");
	glColorFragmentOp1ATIproc = (PFNGLCOLORFRAGMENTOP1ATIPROC)wglGetProcAddress("glColorFragmentOp1ATI");
	glColorFragmentOp2ATIproc = (PFNGLCOLORFRAGMENTOP2ATIPROC)wglGetProcAddress("glColorFragmentOp2ATI");
	glColorFragmentOp3ATIproc = (PFNGLCOLORFRAGMENTOP3ATIPROC)wglGetProcAddress("glColorFragmentOp3ATI");
	glAlphaFragmentOp1ATIproc = (PFNGLALPHAFRAGMENTOP1ATIPROC)wglGetProcAddress("glAlphaFragmentOp1ATI");
	glAlphaFragmentOp2ATIproc = (PFNGLALPHAFRAGMENTOP2ATIPROC)wglGetProcAddress("glAlphaFragmentOp2ATI");
	glAlphaFragmentOp3ATIproc = (PFNGLALPHAFRAGMENTOP3ATIPROC)wglGetProcAddress("glAlphaFragmentOp3ATI");
	glSetFragmentShaderConstantATIproc = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)wglGetProcAddress("glSetFragmentShaderConstantATI");
	glMapObjectBufferATIproc = (PFNGLMAPOBJECTBUFFERATIPROC)wglGetProcAddress("glMapObjectBufferATI");
	glUnmapObjectBufferATIproc = (PFNGLUNMAPOBJECTBUFFERATIPROC)wglGetProcAddress("glUnmapObjectBufferATI");
	glPNTrianglesiATIproc = (PFNGLPNTRIANGLESIATIPROC)wglGetProcAddress("glPNTrianglesiATI");
	glPNTrianglesfATIproc = (PFNGLPNTRIANGLESFATIPROC)wglGetProcAddress("glPNTrianglesfATI");
	glStencilOpSeparateATIproc = (PFNGLSTENCILOPSEPARATEATIPROC)wglGetProcAddress("glStencilOpSeparateATI");
	glStencilFuncSeparateATIproc = (PFNGLSTENCILFUNCSEPARATEATIPROC)wglGetProcAddress("glStencilFuncSeparateATI");
	glNewObjectBufferATIproc = (PFNGLNEWOBJECTBUFFERATIPROC)wglGetProcAddress("glNewObjectBufferATI");
	glIsObjectBufferATIproc = (PFNGLISOBJECTBUFFERATIPROC)wglGetProcAddress("glIsObjectBufferATI");
	glUpdateObjectBufferATIproc = (PFNGLUPDATEOBJECTBUFFERATIPROC)wglGetProcAddress("glUpdateObjectBufferATI");
	glGetObjectBufferfvATIproc = (PFNGLGETOBJECTBUFFERFVATIPROC)wglGetProcAddress("glGetObjectBufferfvATI");
	glGetObjectBufferivATIproc = (PFNGLGETOBJECTBUFFERIVATIPROC)wglGetProcAddress("glGetObjectBufferivATI");
	glFreeObjectBufferATIproc = (PFNGLFREEOBJECTBUFFERATIPROC)wglGetProcAddress("glFreeObjectBufferATI");
	glArrayObjectATIproc = (PFNGLARRAYOBJECTATIPROC)wglGetProcAddress("glArrayObjectATI");
	glGetArrayObjectfvATIproc = (PFNGLGETARRAYOBJECTFVATIPROC)wglGetProcAddress("glGetArrayObjectfvATI");
	glGetArrayObjectivATIproc = (PFNGLGETARRAYOBJECTIVATIPROC)wglGetProcAddress("glGetArrayObjectivATI");
	glVariantArrayObjectATIproc = (PFNGLVARIANTARRAYOBJECTATIPROC)wglGetProcAddress("glVariantArrayObjectATI");
	glGetVariantArrayObjectfvATIproc = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC)wglGetProcAddress("glGetVariantArrayObjectfvATI");
	glGetVariantArrayObjectivATIproc = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC)wglGetProcAddress("glGetVariantArrayObjectivATI");
	glVertexAttribArrayObjectATIproc = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)wglGetProcAddress("glVertexAttribArrayObjectATI");
	glGetVertexAttribArrayObjectfvATIproc = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)wglGetProcAddress("glGetVertexAttribArrayObjectfvATI");
	glGetVertexAttribArrayObjectivATIproc = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)wglGetProcAddress("glGetVertexAttribArrayObjectivATI");
	glVertexStream1sATIproc = (PFNGLVERTEXSTREAM1SATIPROC)wglGetProcAddress("glVertexStream1sATI");
	glVertexStream1svATIproc = (PFNGLVERTEXSTREAM1SVATIPROC)wglGetProcAddress("glVertexStream1svATI");
	glVertexStream1iATIproc = (PFNGLVERTEXSTREAM1IATIPROC)wglGetProcAddress("glVertexStream1iATI");
	glVertexStream1ivATIproc = (PFNGLVERTEXSTREAM1IVATIPROC)wglGetProcAddress("glVertexStream1ivATI");
	glVertexStream1fATIproc = (PFNGLVERTEXSTREAM1FATIPROC)wglGetProcAddress("glVertexStream1fATI");
	glVertexStream1fvATIproc = (PFNGLVERTEXSTREAM1FVATIPROC)wglGetProcAddress("glVertexStream1fvATI");
	glVertexStream1dATIproc = (PFNGLVERTEXSTREAM1DATIPROC)wglGetProcAddress("glVertexStream1dATI");
	glVertexStream1dvATIproc = (PFNGLVERTEXSTREAM1DVATIPROC)wglGetProcAddress("glVertexStream1dvATI");
	glVertexStream2sATIproc = (PFNGLVERTEXSTREAM2SATIPROC)wglGetProcAddress("glVertexStream2sATI");
	glVertexStream2svATIproc = (PFNGLVERTEXSTREAM2SVATIPROC)wglGetProcAddress("glVertexStream2svATI");
	glVertexStream2iATIproc = (PFNGLVERTEXSTREAM2IATIPROC)wglGetProcAddress("glVertexStream2iATI");
	glVertexStream2ivATIproc = (PFNGLVERTEXSTREAM2IVATIPROC)wglGetProcAddress("glVertexStream2ivATI");
	glVertexStream2fATIproc = (PFNGLVERTEXSTREAM2FATIPROC)wglGetProcAddress("glVertexStream2fATI");
	glVertexStream2fvATIproc = (PFNGLVERTEXSTREAM2FVATIPROC)wglGetProcAddress("glVertexStream2fvATI");
	glVertexStream2dATIproc = (PFNGLVERTEXSTREAM2DATIPROC)wglGetProcAddress("glVertexStream2dATI");
	glVertexStream2dvATIproc = (PFNGLVERTEXSTREAM2DVATIPROC)wglGetProcAddress("glVertexStream2dvATI");
	glVertexStream3sATIproc = (PFNGLVERTEXSTREAM3SATIPROC)wglGetProcAddress("glVertexStream3sATI");
	glVertexStream3svATIproc = (PFNGLVERTEXSTREAM3SVATIPROC)wglGetProcAddress("glVertexStream3svATI");
	glVertexStream3iATIproc = (PFNGLVERTEXSTREAM3IATIPROC)wglGetProcAddress("glVertexStream3iATI");
	glVertexStream3ivATIproc = (PFNGLVERTEXSTREAM3IVATIPROC)wglGetProcAddress("glVertexStream3ivATI");
	glVertexStream3fATIproc = (PFNGLVERTEXSTREAM3FATIPROC)wglGetProcAddress("glVertexStream3fATI");
	glVertexStream3fvATIproc = (PFNGLVERTEXSTREAM3FVATIPROC)wglGetProcAddress("glVertexStream3fvATI");
	glVertexStream3dATIproc = (PFNGLVERTEXSTREAM3DATIPROC)wglGetProcAddress("glVertexStream3dATI");
	glVertexStream3dvATIproc = (PFNGLVERTEXSTREAM3DVATIPROC)wglGetProcAddress("glVertexStream3dvATI");
	glVertexStream4sATIproc = (PFNGLVERTEXSTREAM4SATIPROC)wglGetProcAddress("glVertexStream4sATI");
	glVertexStream4svATIproc = (PFNGLVERTEXSTREAM4SVATIPROC)wglGetProcAddress("glVertexStream4svATI");
	glVertexStream4iATIproc = (PFNGLVERTEXSTREAM4IATIPROC)wglGetProcAddress("glVertexStream4iATI");
	glVertexStream4ivATIproc = (PFNGLVERTEXSTREAM4IVATIPROC)wglGetProcAddress("glVertexStream4ivATI");
	glVertexStream4fATIproc = (PFNGLVERTEXSTREAM4FATIPROC)wglGetProcAddress("glVertexStream4fATI");
	glVertexStream4fvATIproc = (PFNGLVERTEXSTREAM4FVATIPROC)wglGetProcAddress("glVertexStream4fvATI");
	glVertexStream4dATIproc = (PFNGLVERTEXSTREAM4DATIPROC)wglGetProcAddress("glVertexStream4dATI");
	glVertexStream4dvATIproc = (PFNGLVERTEXSTREAM4DVATIPROC)wglGetProcAddress("glVertexStream4dvATI");
	glNormalStream3bATIproc = (PFNGLNORMALSTREAM3BATIPROC)wglGetProcAddress("glNormalStream3bATI");
	glNormalStream3bvATIproc = (PFNGLNORMALSTREAM3BVATIPROC)wglGetProcAddress("glNormalStream3bvATI");
	glNormalStream3sATIproc = (PFNGLNORMALSTREAM3SATIPROC)wglGetProcAddress("glNormalStream3sATI");
	glNormalStream3svATIproc = (PFNGLNORMALSTREAM3SVATIPROC)wglGetProcAddress("glNormalStream3svATI");
	glNormalStream3iATIproc = (PFNGLNORMALSTREAM3IATIPROC)wglGetProcAddress("glNormalStream3iATI");
	glNormalStream3ivATIproc = (PFNGLNORMALSTREAM3IVATIPROC)wglGetProcAddress("glNormalStream3ivATI");
	glNormalStream3fATIproc = (PFNGLNORMALSTREAM3FATIPROC)wglGetProcAddress("glNormalStream3fATI");
	glNormalStream3fvATIproc = (PFNGLNORMALSTREAM3FVATIPROC)wglGetProcAddress("glNormalStream3fvATI");
	glNormalStream3dATIproc = (PFNGLNORMALSTREAM3DATIPROC)wglGetProcAddress("glNormalStream3dATI");
	glNormalStream3dvATIproc = (PFNGLNORMALSTREAM3DVATIPROC)wglGetProcAddress("glNormalStream3dvATI");
	glClientActiveVertexStreamATIproc = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)wglGetProcAddress("glClientActiveVertexStreamATI");
	glVertexBlendEnviATIproc = (PFNGLVERTEXBLENDENVIATIPROC)wglGetProcAddress("glVertexBlendEnviATI");
	glVertexBlendEnvfATIproc = (PFNGLVERTEXBLENDENVFATIPROC)wglGetProcAddress("glVertexBlendEnvfATI");
	glEGLImageTargetTexStorageEXTproc = (PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC)wglGetProcAddress("glEGLImageTargetTexStorageEXT");
	glEGLImageTargetTextureStorageEXTproc = (PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC)wglGetProcAddress("glEGLImageTargetTextureStorageEXT");
	glUniformBufferEXTproc = (PFNGLUNIFORMBUFFEREXTPROC)wglGetProcAddress("glUniformBufferEXT");
	glGetUniformBufferSizeEXTproc = (PFNGLGETUNIFORMBUFFERSIZEEXTPROC)wglGetProcAddress("glGetUniformBufferSizeEXT");
	glGetUniformOffsetEXTproc = (PFNGLGETUNIFORMOFFSETEXTPROC)wglGetProcAddress("glGetUniformOffsetEXT");
	glBlendColorEXTproc = (PFNGLBLENDCOLOREXTPROC)wglGetProcAddress("glBlendColorEXT");
	glBlendEquationSeparateEXTproc = (PFNGLBLENDEQUATIONSEPARATEEXTPROC)wglGetProcAddress("glBlendEquationSeparateEXT");
	glBlendFuncSeparateEXTproc = (PFNGLBLENDFUNCSEPARATEEXTPROC)wglGetProcAddress("glBlendFuncSeparateEXT");
	glBlendEquationEXTproc = (PFNGLBLENDEQUATIONEXTPROC)wglGetProcAddress("glBlendEquationEXT");
	glColorSubTableEXTproc = (PFNGLCOLORSUBTABLEEXTPROC)wglGetProcAddress("glColorSubTableEXT");
	glCopyColorSubTableEXTproc = (PFNGLCOPYCOLORSUBTABLEEXTPROC)wglGetProcAddress("glCopyColorSubTableEXT");
	glLockArraysEXTproc = (PFNGLLOCKARRAYSEXTPROC)wglGetProcAddress("glLockArraysEXT");
	glUnlockArraysEXTproc = (PFNGLUNLOCKARRAYSEXTPROC)wglGetProcAddress("glUnlockArraysEXT");
	glConvolutionFilter1DEXTproc = (PFNGLCONVOLUTIONFILTER1DEXTPROC)wglGetProcAddress("glConvolutionFilter1DEXT");
	glConvolutionFilter2DEXTproc = (PFNGLCONVOLUTIONFILTER2DEXTPROC)wglGetProcAddress("glConvolutionFilter2DEXT");
	glConvolutionParameterfEXTproc = (PFNGLCONVOLUTIONPARAMETERFEXTPROC)wglGetProcAddress("glConvolutionParameterfEXT");
	glConvolutionParameterfvEXTproc = (PFNGLCONVOLUTIONPARAMETERFVEXTPROC)wglGetProcAddress("glConvolutionParameterfvEXT");
	glConvolutionParameteriEXTproc = (PFNGLCONVOLUTIONPARAMETERIEXTPROC)wglGetProcAddress("glConvolutionParameteriEXT");
	glConvolutionParameterivEXTproc = (PFNGLCONVOLUTIONPARAMETERIVEXTPROC)wglGetProcAddress("glConvolutionParameterivEXT");
	glCopyConvolutionFilter1DEXTproc = (PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)wglGetProcAddress("glCopyConvolutionFilter1DEXT");
	glCopyConvolutionFilter2DEXTproc = (PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)wglGetProcAddress("glCopyConvolutionFilter2DEXT");
	glGetConvolutionFilterEXTproc = (PFNGLGETCONVOLUTIONFILTEREXTPROC)wglGetProcAddress("glGetConvolutionFilterEXT");
	glGetConvolutionParameterfvEXTproc = (PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)wglGetProcAddress("glGetConvolutionParameterfvEXT");
	glGetConvolutionParameterivEXTproc = (PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)wglGetProcAddress("glGetConvolutionParameterivEXT");
	glGetSeparableFilterEXTproc = (PFNGLGETSEPARABLEFILTEREXTPROC)wglGetProcAddress("glGetSeparableFilterEXT");
	glSeparableFilter2DEXTproc = (PFNGLSEPARABLEFILTER2DEXTPROC)wglGetProcAddress("glSeparableFilter2DEXT");
	glTangent3bEXTproc = (PFNGLTANGENT3BEXTPROC)wglGetProcAddress("glTangent3bEXT");
	glTangent3bvEXTproc = (PFNGLTANGENT3BVEXTPROC)wglGetProcAddress("glTangent3bvEXT");
	glTangent3dEXTproc = (PFNGLTANGENT3DEXTPROC)wglGetProcAddress("glTangent3dEXT");
	glTangent3dvEXTproc = (PFNGLTANGENT3DVEXTPROC)wglGetProcAddress("glTangent3dvEXT");
	glTangent3fEXTproc = (PFNGLTANGENT3FEXTPROC)wglGetProcAddress("glTangent3fEXT");
	glTangent3fvEXTproc = (PFNGLTANGENT3FVEXTPROC)wglGetProcAddress("glTangent3fvEXT");
	glTangent3iEXTproc = (PFNGLTANGENT3IEXTPROC)wglGetProcAddress("glTangent3iEXT");
	glTangent3ivEXTproc = (PFNGLTANGENT3IVEXTPROC)wglGetProcAddress("glTangent3ivEXT");
	glTangent3sEXTproc = (PFNGLTANGENT3SEXTPROC)wglGetProcAddress("glTangent3sEXT");
	glTangent3svEXTproc = (PFNGLTANGENT3SVEXTPROC)wglGetProcAddress("glTangent3svEXT");
	glBinormal3bEXTproc = (PFNGLBINORMAL3BEXTPROC)wglGetProcAddress("glBinormal3bEXT");
	glBinormal3bvEXTproc = (PFNGLBINORMAL3BVEXTPROC)wglGetProcAddress("glBinormal3bvEXT");
	glBinormal3dEXTproc = (PFNGLBINORMAL3DEXTPROC)wglGetProcAddress("glBinormal3dEXT");
	glBinormal3dvEXTproc = (PFNGLBINORMAL3DVEXTPROC)wglGetProcAddress("glBinormal3dvEXT");
	glBinormal3fEXTproc = (PFNGLBINORMAL3FEXTPROC)wglGetProcAddress("glBinormal3fEXT");
	glBinormal3fvEXTproc = (PFNGLBINORMAL3FVEXTPROC)wglGetProcAddress("glBinormal3fvEXT");
	glBinormal3iEXTproc = (PFNGLBINORMAL3IEXTPROC)wglGetProcAddress("glBinormal3iEXT");
	glBinormal3ivEXTproc = (PFNGLBINORMAL3IVEXTPROC)wglGetProcAddress("glBinormal3ivEXT");
	glBinormal3sEXTproc = (PFNGLBINORMAL3SEXTPROC)wglGetProcAddress("glBinormal3sEXT");
	glBinormal3svEXTproc = (PFNGLBINORMAL3SVEXTPROC)wglGetProcAddress("glBinormal3svEXT");
	glTangentPointerEXTproc = (PFNGLTANGENTPOINTEREXTPROC)wglGetProcAddress("glTangentPointerEXT");
	glBinormalPointerEXTproc = (PFNGLBINORMALPOINTEREXTPROC)wglGetProcAddress("glBinormalPointerEXT");
	glCopyTexImage1DEXTproc = (PFNGLCOPYTEXIMAGE1DEXTPROC)wglGetProcAddress("glCopyTexImage1DEXT");
	glCopyTexImage2DEXTproc = (PFNGLCOPYTEXIMAGE2DEXTPROC)wglGetProcAddress("glCopyTexImage2DEXT");
	glCopyTexSubImage1DEXTproc = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glCopyTexSubImage1DEXT");
	glCopyTexSubImage2DEXTproc = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glCopyTexSubImage2DEXT");
	glCopyTexSubImage3DEXTproc = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glCopyTexSubImage3DEXT");
	glCullParameterdvEXTproc = (PFNGLCULLPARAMETERDVEXTPROC)wglGetProcAddress("glCullParameterdvEXT");
	glCullParameterfvEXTproc = (PFNGLCULLPARAMETERFVEXTPROC)wglGetProcAddress("glCullParameterfvEXT");
	glLabelObjectEXTproc = (PFNGLLABELOBJECTEXTPROC)wglGetProcAddress("glLabelObjectEXT");
	glGetObjectLabelEXTproc = (PFNGLGETOBJECTLABELEXTPROC)wglGetProcAddress("glGetObjectLabelEXT");
	glInsertEventMarkerEXTproc = (PFNGLINSERTEVENTMARKEREXTPROC)wglGetProcAddress("glInsertEventMarkerEXT");
	glPushGroupMarkerEXTproc = (PFNGLPUSHGROUPMARKEREXTPROC)wglGetProcAddress("glPushGroupMarkerEXT");
	glPopGroupMarkerEXTproc = (PFNGLPOPGROUPMARKEREXTPROC)wglGetProcAddress("glPopGroupMarkerEXT");
	glDepthBoundsEXTproc = (PFNGLDEPTHBOUNDSEXTPROC)wglGetProcAddress("glDepthBoundsEXT");
	glMatrixLoadfEXTproc = (PFNGLMATRIXLOADFEXTPROC)wglGetProcAddress("glMatrixLoadfEXT");
	glMatrixLoaddEXTproc = (PFNGLMATRIXLOADDEXTPROC)wglGetProcAddress("glMatrixLoaddEXT");
	glMatrixMultfEXTproc = (PFNGLMATRIXMULTFEXTPROC)wglGetProcAddress("glMatrixMultfEXT");
	glMatrixMultdEXTproc = (PFNGLMATRIXMULTDEXTPROC)wglGetProcAddress("glMatrixMultdEXT");
	glMatrixLoadIdentityEXTproc = (PFNGLMATRIXLOADIDENTITYEXTPROC)wglGetProcAddress("glMatrixLoadIdentityEXT");
	glMatrixRotatefEXTproc = (PFNGLMATRIXROTATEFEXTPROC)wglGetProcAddress("glMatrixRotatefEXT");
	glMatrixRotatedEXTproc = (PFNGLMATRIXROTATEDEXTPROC)wglGetProcAddress("glMatrixRotatedEXT");
	glMatrixScalefEXTproc = (PFNGLMATRIXSCALEFEXTPROC)wglGetProcAddress("glMatrixScalefEXT");
	glMatrixScaledEXTproc = (PFNGLMATRIXSCALEDEXTPROC)wglGetProcAddress("glMatrixScaledEXT");
	glMatrixTranslatefEXTproc = (PFNGLMATRIXTRANSLATEFEXTPROC)wglGetProcAddress("glMatrixTranslatefEXT");
	glMatrixTranslatedEXTproc = (PFNGLMATRIXTRANSLATEDEXTPROC)wglGetProcAddress("glMatrixTranslatedEXT");
	glMatrixFrustumEXTproc = (PFNGLMATRIXFRUSTUMEXTPROC)wglGetProcAddress("glMatrixFrustumEXT");
	glMatrixOrthoEXTproc = (PFNGLMATRIXORTHOEXTPROC)wglGetProcAddress("glMatrixOrthoEXT");
	glMatrixPopEXTproc = (PFNGLMATRIXPOPEXTPROC)wglGetProcAddress("glMatrixPopEXT");
	glMatrixPushEXTproc = (PFNGLMATRIXPUSHEXTPROC)wglGetProcAddress("glMatrixPushEXT");
	glClientAttribDefaultEXTproc = (PFNGLCLIENTATTRIBDEFAULTEXTPROC)wglGetProcAddress("glClientAttribDefaultEXT");
	glPushClientAttribDefaultEXTproc = (PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)wglGetProcAddress("glPushClientAttribDefaultEXT");
	glTextureParameterfEXTproc = (PFNGLTEXTUREPARAMETERFEXTPROC)wglGetProcAddress("glTextureParameterfEXT");
	glTextureParameterfvEXTproc = (PFNGLTEXTUREPARAMETERFVEXTPROC)wglGetProcAddress("glTextureParameterfvEXT");
	glTextureParameteriEXTproc = (PFNGLTEXTUREPARAMETERIEXTPROC)wglGetProcAddress("glTextureParameteriEXT");
	glTextureParameterivEXTproc = (PFNGLTEXTUREPARAMETERIVEXTPROC)wglGetProcAddress("glTextureParameterivEXT");
	glTextureImage1DEXTproc = (PFNGLTEXTUREIMAGE1DEXTPROC)wglGetProcAddress("glTextureImage1DEXT");
	glTextureImage2DEXTproc = (PFNGLTEXTUREIMAGE2DEXTPROC)wglGetProcAddress("glTextureImage2DEXT");
	glTextureSubImage1DEXTproc = (PFNGLTEXTURESUBIMAGE1DEXTPROC)wglGetProcAddress("glTextureSubImage1DEXT");
	glTextureSubImage2DEXTproc = (PFNGLTEXTURESUBIMAGE2DEXTPROC)wglGetProcAddress("glTextureSubImage2DEXT");
	glCopyTextureImage1DEXTproc = (PFNGLCOPYTEXTUREIMAGE1DEXTPROC)wglGetProcAddress("glCopyTextureImage1DEXT");
	glCopyTextureImage2DEXTproc = (PFNGLCOPYTEXTUREIMAGE2DEXTPROC)wglGetProcAddress("glCopyTextureImage2DEXT");
	glCopyTextureSubImage1DEXTproc = (PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)wglGetProcAddress("glCopyTextureSubImage1DEXT");
	glCopyTextureSubImage2DEXTproc = (PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)wglGetProcAddress("glCopyTextureSubImage2DEXT");
	glGetTextureImageEXTproc = (PFNGLGETTEXTUREIMAGEEXTPROC)wglGetProcAddress("glGetTextureImageEXT");
	glGetTextureParameterfvEXTproc = (PFNGLGETTEXTUREPARAMETERFVEXTPROC)wglGetProcAddress("glGetTextureParameterfvEXT");
	glGetTextureParameterivEXTproc = (PFNGLGETTEXTUREPARAMETERIVEXTPROC)wglGetProcAddress("glGetTextureParameterivEXT");
	glGetTextureLevelParameterfvEXTproc = (PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)wglGetProcAddress("glGetTextureLevelParameterfvEXT");
	glGetTextureLevelParameterivEXTproc = (PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)wglGetProcAddress("glGetTextureLevelParameterivEXT");
	glTextureImage3DEXTproc = (PFNGLTEXTUREIMAGE3DEXTPROC)wglGetProcAddress("glTextureImage3DEXT");
	glTextureSubImage3DEXTproc = (PFNGLTEXTURESUBIMAGE3DEXTPROC)wglGetProcAddress("glTextureSubImage3DEXT");
	glCopyTextureSubImage3DEXTproc = (PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)wglGetProcAddress("glCopyTextureSubImage3DEXT");
	glBindMultiTextureEXTproc = (PFNGLBINDMULTITEXTUREEXTPROC)wglGetProcAddress("glBindMultiTextureEXT");
	glMultiTexCoordPointerEXTproc = (PFNGLMULTITEXCOORDPOINTEREXTPROC)wglGetProcAddress("glMultiTexCoordPointerEXT");
	glMultiTexEnvfEXTproc = (PFNGLMULTITEXENVFEXTPROC)wglGetProcAddress("glMultiTexEnvfEXT");
	glMultiTexEnvfvEXTproc = (PFNGLMULTITEXENVFVEXTPROC)wglGetProcAddress("glMultiTexEnvfvEXT");
	glMultiTexEnviEXTproc = (PFNGLMULTITEXENVIEXTPROC)wglGetProcAddress("glMultiTexEnviEXT");
	glMultiTexEnvivEXTproc = (PFNGLMULTITEXENVIVEXTPROC)wglGetProcAddress("glMultiTexEnvivEXT");
	glMultiTexGendEXTproc = (PFNGLMULTITEXGENDEXTPROC)wglGetProcAddress("glMultiTexGendEXT");
	glMultiTexGendvEXTproc = (PFNGLMULTITEXGENDVEXTPROC)wglGetProcAddress("glMultiTexGendvEXT");
	glMultiTexGenfEXTproc = (PFNGLMULTITEXGENFEXTPROC)wglGetProcAddress("glMultiTexGenfEXT");
	glMultiTexGenfvEXTproc = (PFNGLMULTITEXGENFVEXTPROC)wglGetProcAddress("glMultiTexGenfvEXT");
	glMultiTexGeniEXTproc = (PFNGLMULTITEXGENIEXTPROC)wglGetProcAddress("glMultiTexGeniEXT");
	glMultiTexGenivEXTproc = (PFNGLMULTITEXGENIVEXTPROC)wglGetProcAddress("glMultiTexGenivEXT");
	glGetMultiTexEnvfvEXTproc = (PFNGLGETMULTITEXENVFVEXTPROC)wglGetProcAddress("glGetMultiTexEnvfvEXT");
	glGetMultiTexEnvivEXTproc = (PFNGLGETMULTITEXENVIVEXTPROC)wglGetProcAddress("glGetMultiTexEnvivEXT");
	glGetMultiTexGendvEXTproc = (PFNGLGETMULTITEXGENDVEXTPROC)wglGetProcAddress("glGetMultiTexGendvEXT");
	glGetMultiTexGenfvEXTproc = (PFNGLGETMULTITEXGENFVEXTPROC)wglGetProcAddress("glGetMultiTexGenfvEXT");
	glGetMultiTexGenivEXTproc = (PFNGLGETMULTITEXGENIVEXTPROC)wglGetProcAddress("glGetMultiTexGenivEXT");
	glMultiTexParameteriEXTproc = (PFNGLMULTITEXPARAMETERIEXTPROC)wglGetProcAddress("glMultiTexParameteriEXT");
	glMultiTexParameterivEXTproc = (PFNGLMULTITEXPARAMETERIVEXTPROC)wglGetProcAddress("glMultiTexParameterivEXT");
	glMultiTexParameterfEXTproc = (PFNGLMULTITEXPARAMETERFEXTPROC)wglGetProcAddress("glMultiTexParameterfEXT");
	glMultiTexParameterfvEXTproc = (PFNGLMULTITEXPARAMETERFVEXTPROC)wglGetProcAddress("glMultiTexParameterfvEXT");
	glMultiTexImage1DEXTproc = (PFNGLMULTITEXIMAGE1DEXTPROC)wglGetProcAddress("glMultiTexImage1DEXT");
	glMultiTexImage2DEXTproc = (PFNGLMULTITEXIMAGE2DEXTPROC)wglGetProcAddress("glMultiTexImage2DEXT");
	glMultiTexSubImage1DEXTproc = (PFNGLMULTITEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glMultiTexSubImage1DEXT");
	glMultiTexSubImage2DEXTproc = (PFNGLMULTITEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glMultiTexSubImage2DEXT");
	glCopyMultiTexImage1DEXTproc = (PFNGLCOPYMULTITEXIMAGE1DEXTPROC)wglGetProcAddress("glCopyMultiTexImage1DEXT");
	glCopyMultiTexImage2DEXTproc = (PFNGLCOPYMULTITEXIMAGE2DEXTPROC)wglGetProcAddress("glCopyMultiTexImage2DEXT");
	glCopyMultiTexSubImage1DEXTproc = (PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glCopyMultiTexSubImage1DEXT");
	glCopyMultiTexSubImage2DEXTproc = (PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glCopyMultiTexSubImage2DEXT");
	glGetMultiTexImageEXTproc = (PFNGLGETMULTITEXIMAGEEXTPROC)wglGetProcAddress("glGetMultiTexImageEXT");
	glGetMultiTexParameterfvEXTproc = (PFNGLGETMULTITEXPARAMETERFVEXTPROC)wglGetProcAddress("glGetMultiTexParameterfvEXT");
	glGetMultiTexParameterivEXTproc = (PFNGLGETMULTITEXPARAMETERIVEXTPROC)wglGetProcAddress("glGetMultiTexParameterivEXT");
	glGetMultiTexLevelParameterfvEXTproc = (PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)wglGetProcAddress("glGetMultiTexLevelParameterfvEXT");
	glGetMultiTexLevelParameterivEXTproc = (PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)wglGetProcAddress("glGetMultiTexLevelParameterivEXT");
	glMultiTexImage3DEXTproc = (PFNGLMULTITEXIMAGE3DEXTPROC)wglGetProcAddress("glMultiTexImage3DEXT");
	glMultiTexSubImage3DEXTproc = (PFNGLMULTITEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glMultiTexSubImage3DEXT");
	glCopyMultiTexSubImage3DEXTproc = (PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glCopyMultiTexSubImage3DEXT");
	glEnableClientStateIndexedEXTproc = (PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)wglGetProcAddress("glEnableClientStateIndexedEXT");
	glDisableClientStateIndexedEXTproc = (PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)wglGetProcAddress("glDisableClientStateIndexedEXT");
	glGetFloatIndexedvEXTproc = (PFNGLGETFLOATINDEXEDVEXTPROC)wglGetProcAddress("glGetFloatIndexedvEXT");
	glGetDoubleIndexedvEXTproc = (PFNGLGETDOUBLEINDEXEDVEXTPROC)wglGetProcAddress("glGetDoubleIndexedvEXT");
	glGetPointerIndexedvEXTproc = (PFNGLGETPOINTERINDEXEDVEXTPROC)wglGetProcAddress("glGetPointerIndexedvEXT");
	glEnableIndexedEXTproc = (PFNGLENABLEINDEXEDEXTPROC)wglGetProcAddress("glEnableIndexedEXT");
	glDisableIndexedEXTproc = (PFNGLDISABLEINDEXEDEXTPROC)wglGetProcAddress("glDisableIndexedEXT");
	glIsEnabledIndexedEXTproc = (PFNGLISENABLEDINDEXEDEXTPROC)wglGetProcAddress("glIsEnabledIndexedEXT");
	glGetIntegerIndexedvEXTproc = (PFNGLGETINTEGERINDEXEDVEXTPROC)wglGetProcAddress("glGetIntegerIndexedvEXT");
	glGetBooleanIndexedvEXTproc = (PFNGLGETBOOLEANINDEXEDVEXTPROC)wglGetProcAddress("glGetBooleanIndexedvEXT");
	glCompressedTextureImage3DEXTproc = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)wglGetProcAddress("glCompressedTextureImage3DEXT");
	glCompressedTextureImage2DEXTproc = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)wglGetProcAddress("glCompressedTextureImage2DEXT");
	glCompressedTextureImage1DEXTproc = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)wglGetProcAddress("glCompressedTextureImage1DEXT");
	glCompressedTextureSubImage3DEXTproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)wglGetProcAddress("glCompressedTextureSubImage3DEXT");
	glCompressedTextureSubImage2DEXTproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)wglGetProcAddress("glCompressedTextureSubImage2DEXT");
	glCompressedTextureSubImage1DEXTproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)wglGetProcAddress("glCompressedTextureSubImage1DEXT");
	glGetCompressedTextureImageEXTproc = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)wglGetProcAddress("glGetCompressedTextureImageEXT");
	glCompressedMultiTexImage3DEXTproc = (PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)wglGetProcAddress("glCompressedMultiTexImage3DEXT");
	glCompressedMultiTexImage2DEXTproc = (PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)wglGetProcAddress("glCompressedMultiTexImage2DEXT");
	glCompressedMultiTexImage1DEXTproc = (PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)wglGetProcAddress("glCompressedMultiTexImage1DEXT");
	glCompressedMultiTexSubImage3DEXTproc = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glCompressedMultiTexSubImage3DEXT");
	glCompressedMultiTexSubImage2DEXTproc = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glCompressedMultiTexSubImage2DEXT");
	glCompressedMultiTexSubImage1DEXTproc = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glCompressedMultiTexSubImage1DEXT");
	glGetCompressedMultiTexImageEXTproc = (PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)wglGetProcAddress("glGetCompressedMultiTexImageEXT");
	glMatrixLoadTransposefEXTproc = (PFNGLMATRIXLOADTRANSPOSEFEXTPROC)wglGetProcAddress("glMatrixLoadTransposefEXT");
	glMatrixLoadTransposedEXTproc = (PFNGLMATRIXLOADTRANSPOSEDEXTPROC)wglGetProcAddress("glMatrixLoadTransposedEXT");
	glMatrixMultTransposefEXTproc = (PFNGLMATRIXMULTTRANSPOSEFEXTPROC)wglGetProcAddress("glMatrixMultTransposefEXT");
	glMatrixMultTransposedEXTproc = (PFNGLMATRIXMULTTRANSPOSEDEXTPROC)wglGetProcAddress("glMatrixMultTransposedEXT");
	glNamedBufferDataEXTproc = (PFNGLNAMEDBUFFERDATAEXTPROC)wglGetProcAddress("glNamedBufferDataEXT");
	glNamedBufferSubDataEXTproc = (PFNGLNAMEDBUFFERSUBDATAEXTPROC)wglGetProcAddress("glNamedBufferSubDataEXT");
	glMapNamedBufferEXTproc = (PFNGLMAPNAMEDBUFFEREXTPROC)wglGetProcAddress("glMapNamedBufferEXT");
	glUnmapNamedBufferEXTproc = (PFNGLUNMAPNAMEDBUFFEREXTPROC)wglGetProcAddress("glUnmapNamedBufferEXT");
	glGetNamedBufferParameterivEXTproc = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedBufferParameterivEXT");
	glGetNamedBufferPointervEXTproc = (PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)wglGetProcAddress("glGetNamedBufferPointervEXT");
	glGetNamedBufferSubDataEXTproc = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)wglGetProcAddress("glGetNamedBufferSubDataEXT");
	glProgramUniform1fEXTproc = (PFNGLPROGRAMUNIFORM1FEXTPROC)wglGetProcAddress("glProgramUniform1fEXT");
	glProgramUniform2fEXTproc = (PFNGLPROGRAMUNIFORM2FEXTPROC)wglGetProcAddress("glProgramUniform2fEXT");
	glProgramUniform3fEXTproc = (PFNGLPROGRAMUNIFORM3FEXTPROC)wglGetProcAddress("glProgramUniform3fEXT");
	glProgramUniform4fEXTproc = (PFNGLPROGRAMUNIFORM4FEXTPROC)wglGetProcAddress("glProgramUniform4fEXT");
	glProgramUniform1iEXTproc = (PFNGLPROGRAMUNIFORM1IEXTPROC)wglGetProcAddress("glProgramUniform1iEXT");
	glProgramUniform2iEXTproc = (PFNGLPROGRAMUNIFORM2IEXTPROC)wglGetProcAddress("glProgramUniform2iEXT");
	glProgramUniform3iEXTproc = (PFNGLPROGRAMUNIFORM3IEXTPROC)wglGetProcAddress("glProgramUniform3iEXT");
	glProgramUniform4iEXTproc = (PFNGLPROGRAMUNIFORM4IEXTPROC)wglGetProcAddress("glProgramUniform4iEXT");
	glProgramUniform1fvEXTproc = (PFNGLPROGRAMUNIFORM1FVEXTPROC)wglGetProcAddress("glProgramUniform1fvEXT");
	glProgramUniform2fvEXTproc = (PFNGLPROGRAMUNIFORM2FVEXTPROC)wglGetProcAddress("glProgramUniform2fvEXT");
	glProgramUniform3fvEXTproc = (PFNGLPROGRAMUNIFORM3FVEXTPROC)wglGetProcAddress("glProgramUniform3fvEXT");
	glProgramUniform4fvEXTproc = (PFNGLPROGRAMUNIFORM4FVEXTPROC)wglGetProcAddress("glProgramUniform4fvEXT");
	glProgramUniform1ivEXTproc = (PFNGLPROGRAMUNIFORM1IVEXTPROC)wglGetProcAddress("glProgramUniform1ivEXT");
	glProgramUniform2ivEXTproc = (PFNGLPROGRAMUNIFORM2IVEXTPROC)wglGetProcAddress("glProgramUniform2ivEXT");
	glProgramUniform3ivEXTproc = (PFNGLPROGRAMUNIFORM3IVEXTPROC)wglGetProcAddress("glProgramUniform3ivEXT");
	glProgramUniform4ivEXTproc = (PFNGLPROGRAMUNIFORM4IVEXTPROC)wglGetProcAddress("glProgramUniform4ivEXT");
	glProgramUniformMatrix2fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2fvEXT");
	glProgramUniformMatrix3fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3fvEXT");
	glProgramUniformMatrix4fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4fvEXT");
	glProgramUniformMatrix2x3fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x3fvEXT");
	glProgramUniformMatrix3x2fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x2fvEXT");
	glProgramUniformMatrix2x4fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x4fvEXT");
	glProgramUniformMatrix4x2fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x2fvEXT");
	glProgramUniformMatrix3x4fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x4fvEXT");
	glProgramUniformMatrix4x3fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x3fvEXT");
	glTextureBufferEXTproc = (PFNGLTEXTUREBUFFEREXTPROC)wglGetProcAddress("glTextureBufferEXT");
	glMultiTexBufferEXTproc = (PFNGLMULTITEXBUFFEREXTPROC)wglGetProcAddress("glMultiTexBufferEXT");
	glTextureParameterIivEXTproc = (PFNGLTEXTUREPARAMETERIIVEXTPROC)wglGetProcAddress("glTextureParameterIivEXT");
	glTextureParameterIuivEXTproc = (PFNGLTEXTUREPARAMETERIUIVEXTPROC)wglGetProcAddress("glTextureParameterIuivEXT");
	glGetTextureParameterIivEXTproc = (PFNGLGETTEXTUREPARAMETERIIVEXTPROC)wglGetProcAddress("glGetTextureParameterIivEXT");
	glGetTextureParameterIuivEXTproc = (PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetTextureParameterIuivEXT");
	glMultiTexParameterIivEXTproc = (PFNGLMULTITEXPARAMETERIIVEXTPROC)wglGetProcAddress("glMultiTexParameterIivEXT");
	glMultiTexParameterIuivEXTproc = (PFNGLMULTITEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glMultiTexParameterIuivEXT");
	glGetMultiTexParameterIivEXTproc = (PFNGLGETMULTITEXPARAMETERIIVEXTPROC)wglGetProcAddress("glGetMultiTexParameterIivEXT");
	glGetMultiTexParameterIuivEXTproc = (PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetMultiTexParameterIuivEXT");
	glProgramUniform1uiEXTproc = (PFNGLPROGRAMUNIFORM1UIEXTPROC)wglGetProcAddress("glProgramUniform1uiEXT");
	glProgramUniform2uiEXTproc = (PFNGLPROGRAMUNIFORM2UIEXTPROC)wglGetProcAddress("glProgramUniform2uiEXT");
	glProgramUniform3uiEXTproc = (PFNGLPROGRAMUNIFORM3UIEXTPROC)wglGetProcAddress("glProgramUniform3uiEXT");
	glProgramUniform4uiEXTproc = (PFNGLPROGRAMUNIFORM4UIEXTPROC)wglGetProcAddress("glProgramUniform4uiEXT");
	glProgramUniform1uivEXTproc = (PFNGLPROGRAMUNIFORM1UIVEXTPROC)wglGetProcAddress("glProgramUniform1uivEXT");
	glProgramUniform2uivEXTproc = (PFNGLPROGRAMUNIFORM2UIVEXTPROC)wglGetProcAddress("glProgramUniform2uivEXT");
	glProgramUniform3uivEXTproc = (PFNGLPROGRAMUNIFORM3UIVEXTPROC)wglGetProcAddress("glProgramUniform3uivEXT");
	glProgramUniform4uivEXTproc = (PFNGLPROGRAMUNIFORM4UIVEXTPROC)wglGetProcAddress("glProgramUniform4uivEXT");
	glNamedProgramLocalParameters4fvEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameters4fvEXT");
	glNamedProgramLocalParameterI4iEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4iEXT");
	glNamedProgramLocalParameterI4ivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4ivEXT");
	glNamedProgramLocalParametersI4ivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)wglGetProcAddress("glNamedProgramLocalParametersI4ivEXT");
	glNamedProgramLocalParameterI4uiEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4uiEXT");
	glNamedProgramLocalParameterI4uivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4uivEXT");
	glNamedProgramLocalParametersI4uivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)wglGetProcAddress("glNamedProgramLocalParametersI4uivEXT");
	glGetNamedProgramLocalParameterIivEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterIivEXT");
	glGetNamedProgramLocalParameterIuivEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterIuivEXT");
	glEnableClientStateiEXTproc = (PFNGLENABLECLIENTSTATEIEXTPROC)wglGetProcAddress("glEnableClientStateiEXT");
	glDisableClientStateiEXTproc = (PFNGLDISABLECLIENTSTATEIEXTPROC)wglGetProcAddress("glDisableClientStateiEXT");
	glGetFloati_vEXTproc = (PFNGLGETFLOATI_VEXTPROC)wglGetProcAddress("glGetFloati_vEXT");
	glGetDoublei_vEXTproc = (PFNGLGETDOUBLEI_VEXTPROC)wglGetProcAddress("glGetDoublei_vEXT");
	glGetPointeri_vEXTproc = (PFNGLGETPOINTERI_VEXTPROC)wglGetProcAddress("glGetPointeri_vEXT");
	glNamedProgramStringEXTproc = (PFNGLNAMEDPROGRAMSTRINGEXTPROC)wglGetProcAddress("glNamedProgramStringEXT");
	glNamedProgramLocalParameter4dEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4dEXT");
	glNamedProgramLocalParameter4dvEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4dvEXT");
	glNamedProgramLocalParameter4fEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4fEXT");
	glNamedProgramLocalParameter4fvEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4fvEXT");
	glGetNamedProgramLocalParameterdvEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterdvEXT");
	glGetNamedProgramLocalParameterfvEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterfvEXT");
	glGetNamedProgramivEXTproc = (PFNGLGETNAMEDPROGRAMIVEXTPROC)wglGetProcAddress("glGetNamedProgramivEXT");
	glGetNamedProgramStringEXTproc = (PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)wglGetProcAddress("glGetNamedProgramStringEXT");
	glNamedRenderbufferStorageEXTproc = (PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glNamedRenderbufferStorageEXT");
	glGetNamedRenderbufferParameterivEXTproc = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedRenderbufferParameterivEXT");
	glNamedRenderbufferStorageMultisampleEXTproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisampleEXT");
	glNamedRenderbufferStorageMultisampleCoverageEXTproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisampleCoverageEXT");
	glCheckNamedFramebufferStatusEXTproc = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckNamedFramebufferStatusEXT");
	glNamedFramebufferTexture1DEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)wglGetProcAddress("glNamedFramebufferTexture1DEXT");
	glNamedFramebufferTexture2DEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glNamedFramebufferTexture2DEXT");
	glNamedFramebufferTexture3DEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)wglGetProcAddress("glNamedFramebufferTexture3DEXT");
	glNamedFramebufferRenderbufferEXTproc = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glNamedFramebufferRenderbufferEXT");
	glGetNamedFramebufferAttachmentParameterivEXTproc = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedFramebufferAttachmentParameterivEXT");
	glGenerateTextureMipmapEXTproc = (PFNGLGENERATETEXTUREMIPMAPEXTPROC)wglGetProcAddress("glGenerateTextureMipmapEXT");
	glGenerateMultiTexMipmapEXTproc = (PFNGLGENERATEMULTITEXMIPMAPEXTPROC)wglGetProcAddress("glGenerateMultiTexMipmapEXT");
	glFramebufferDrawBufferEXTproc = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)wglGetProcAddress("glFramebufferDrawBufferEXT");
	glFramebufferDrawBuffersEXTproc = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)wglGetProcAddress("glFramebufferDrawBuffersEXT");
	glFramebufferReadBufferEXTproc = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC)wglGetProcAddress("glFramebufferReadBufferEXT");
	glGetFramebufferParameterivEXTproc = (PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferParameterivEXT");
	glNamedCopyBufferSubDataEXTproc = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)wglGetProcAddress("glNamedCopyBufferSubDataEXT");
	glNamedFramebufferTextureEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)wglGetProcAddress("glNamedFramebufferTextureEXT");
	glNamedFramebufferTextureLayerEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)wglGetProcAddress("glNamedFramebufferTextureLayerEXT");
	glNamedFramebufferTextureFaceEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)wglGetProcAddress("glNamedFramebufferTextureFaceEXT");
	glTextureRenderbufferEXTproc = (PFNGLTEXTURERENDERBUFFEREXTPROC)wglGetProcAddress("glTextureRenderbufferEXT");
	glMultiTexRenderbufferEXTproc = (PFNGLMULTITEXRENDERBUFFEREXTPROC)wglGetProcAddress("glMultiTexRenderbufferEXT");
	glVertexArrayVertexOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexOffsetEXT");
	glVertexArrayColorOffsetEXTproc = (PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)wglGetProcAddress("glVertexArrayColorOffsetEXT");
	glVertexArrayEdgeFlagOffsetEXTproc = (PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)wglGetProcAddress("glVertexArrayEdgeFlagOffsetEXT");
	glVertexArrayIndexOffsetEXTproc = (PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)wglGetProcAddress("glVertexArrayIndexOffsetEXT");
	glVertexArrayNormalOffsetEXTproc = (PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)wglGetProcAddress("glVertexArrayNormalOffsetEXT");
	glVertexArrayTexCoordOffsetEXTproc = (PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)wglGetProcAddress("glVertexArrayTexCoordOffsetEXT");
	glVertexArrayMultiTexCoordOffsetEXTproc = (PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)wglGetProcAddress("glVertexArrayMultiTexCoordOffsetEXT");
	glVertexArrayFogCoordOffsetEXTproc = (PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)wglGetProcAddress("glVertexArrayFogCoordOffsetEXT");
	glVertexArraySecondaryColorOffsetEXTproc = (PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)wglGetProcAddress("glVertexArraySecondaryColorOffsetEXT");
	glVertexArrayVertexAttribOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribOffsetEXT");
	glVertexArrayVertexAttribIOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribIOffsetEXT");
	glEnableVertexArrayEXTproc = (PFNGLENABLEVERTEXARRAYEXTPROC)wglGetProcAddress("glEnableVertexArrayEXT");
	glDisableVertexArrayEXTproc = (PFNGLDISABLEVERTEXARRAYEXTPROC)wglGetProcAddress("glDisableVertexArrayEXT");
	glEnableVertexArrayAttribEXTproc = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)wglGetProcAddress("glEnableVertexArrayAttribEXT");
	glDisableVertexArrayAttribEXTproc = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)wglGetProcAddress("glDisableVertexArrayAttribEXT");
	glGetVertexArrayIntegervEXTproc = (PFNGLGETVERTEXARRAYINTEGERVEXTPROC)wglGetProcAddress("glGetVertexArrayIntegervEXT");
	glGetVertexArrayPointervEXTproc = (PFNGLGETVERTEXARRAYPOINTERVEXTPROC)wglGetProcAddress("glGetVertexArrayPointervEXT");
	glGetVertexArrayIntegeri_vEXTproc = (PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)wglGetProcAddress("glGetVertexArrayIntegeri_vEXT");
	glGetVertexArrayPointeri_vEXTproc = (PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)wglGetProcAddress("glGetVertexArrayPointeri_vEXT");
	glMapNamedBufferRangeEXTproc = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC)wglGetProcAddress("glMapNamedBufferRangeEXT");
	glFlushMappedNamedBufferRangeEXTproc = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)wglGetProcAddress("glFlushMappedNamedBufferRangeEXT");
	glNamedBufferStorageEXTproc = (PFNGLNAMEDBUFFERSTORAGEEXTPROC)wglGetProcAddress("glNamedBufferStorageEXT");
	glClearNamedBufferDataEXTproc = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)wglGetProcAddress("glClearNamedBufferDataEXT");
	glClearNamedBufferSubDataEXTproc = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)wglGetProcAddress("glClearNamedBufferSubDataEXT");
	glNamedFramebufferParameteriEXTproc = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)wglGetProcAddress("glNamedFramebufferParameteriEXT");
	glGetNamedFramebufferParameterivEXTproc = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedFramebufferParameterivEXT");
	glProgramUniform1dEXTproc = (PFNGLPROGRAMUNIFORM1DEXTPROC)wglGetProcAddress("glProgramUniform1dEXT");
	glProgramUniform2dEXTproc = (PFNGLPROGRAMUNIFORM2DEXTPROC)wglGetProcAddress("glProgramUniform2dEXT");
	glProgramUniform3dEXTproc = (PFNGLPROGRAMUNIFORM3DEXTPROC)wglGetProcAddress("glProgramUniform3dEXT");
	glProgramUniform4dEXTproc = (PFNGLPROGRAMUNIFORM4DEXTPROC)wglGetProcAddress("glProgramUniform4dEXT");
	glProgramUniform1dvEXTproc = (PFNGLPROGRAMUNIFORM1DVEXTPROC)wglGetProcAddress("glProgramUniform1dvEXT");
	glProgramUniform2dvEXTproc = (PFNGLPROGRAMUNIFORM2DVEXTPROC)wglGetProcAddress("glProgramUniform2dvEXT");
	glProgramUniform3dvEXTproc = (PFNGLPROGRAMUNIFORM3DVEXTPROC)wglGetProcAddress("glProgramUniform3dvEXT");
	glProgramUniform4dvEXTproc = (PFNGLPROGRAMUNIFORM4DVEXTPROC)wglGetProcAddress("glProgramUniform4dvEXT");
	glProgramUniformMatrix2dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2dvEXT");
	glProgramUniformMatrix3dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3dvEXT");
	glProgramUniformMatrix4dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4dvEXT");
	glProgramUniformMatrix2x3dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x3dvEXT");
	glProgramUniformMatrix2x4dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x4dvEXT");
	glProgramUniformMatrix3x2dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x2dvEXT");
	glProgramUniformMatrix3x4dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x4dvEXT");
	glProgramUniformMatrix4x2dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x2dvEXT");
	glProgramUniformMatrix4x3dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x3dvEXT");
	glTextureBufferRangeEXTproc = (PFNGLTEXTUREBUFFERRANGEEXTPROC)wglGetProcAddress("glTextureBufferRangeEXT");
	glTextureStorage1DEXTproc = (PFNGLTEXTURESTORAGE1DEXTPROC)wglGetProcAddress("glTextureStorage1DEXT");
	glTextureStorage2DEXTproc = (PFNGLTEXTURESTORAGE2DEXTPROC)wglGetProcAddress("glTextureStorage2DEXT");
	glTextureStorage3DEXTproc = (PFNGLTEXTURESTORAGE3DEXTPROC)wglGetProcAddress("glTextureStorage3DEXT");
	glTextureStorage2DMultisampleEXTproc = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorage2DMultisampleEXT");
	glTextureStorage3DMultisampleEXTproc = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorage3DMultisampleEXT");
	glVertexArrayBindVertexBufferEXTproc = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)wglGetProcAddress("glVertexArrayBindVertexBufferEXT");
	glVertexArrayVertexAttribFormatEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribFormatEXT");
	glVertexArrayVertexAttribIFormatEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribIFormatEXT");
	glVertexArrayVertexAttribLFormatEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribLFormatEXT");
	glVertexArrayVertexAttribBindingEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribBindingEXT");
	glVertexArrayVertexBindingDivisorEXTproc = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)wglGetProcAddress("glVertexArrayVertexBindingDivisorEXT");
	glVertexArrayVertexAttribLOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribLOffsetEXT");
	glTexturePageCommitmentEXTproc = (PFNGLTEXTUREPAGECOMMITMENTEXTPROC)wglGetProcAddress("glTexturePageCommitmentEXT");
	glVertexArrayVertexAttribDivisorEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)wglGetProcAddress("glVertexArrayVertexAttribDivisorEXT");
	glColorMaskIndexedEXTproc = (PFNGLCOLORMASKINDEXEDEXTPROC)wglGetProcAddress("glColorMaskIndexedEXT");
	glDrawArraysInstancedEXTproc = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)wglGetProcAddress("glDrawArraysInstancedEXT");
	glDrawElementsInstancedEXTproc = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)wglGetProcAddress("glDrawElementsInstancedEXT");
	glDrawRangeElementsEXTproc = (PFNGLDRAWRANGEELEMENTSEXTPROC)wglGetProcAddress("glDrawRangeElementsEXT");
	glBufferStorageExternalEXTproc = (PFNGLBUFFERSTORAGEEXTERNALEXTPROC)wglGetProcAddress("glBufferStorageExternalEXT");
	glNamedBufferStorageExternalEXTproc = (PFNGLNAMEDBUFFERSTORAGEEXTERNALEXTPROC)wglGetProcAddress("glNamedBufferStorageExternalEXT");
	glFogCoordfEXTproc = (PFNGLFOGCOORDFEXTPROC)wglGetProcAddress("glFogCoordfEXT");
	glFogCoordfvEXTproc = (PFNGLFOGCOORDFVEXTPROC)wglGetProcAddress("glFogCoordfvEXT");
	glFogCoorddEXTproc = (PFNGLFOGCOORDDEXTPROC)wglGetProcAddress("glFogCoorddEXT");
	glFogCoorddvEXTproc = (PFNGLFOGCOORDDVEXTPROC)wglGetProcAddress("glFogCoorddvEXT");
	glFogCoordPointerEXTproc = (PFNGLFOGCOORDPOINTEREXTPROC)wglGetProcAddress("glFogCoordPointerEXT");
	glBlitFramebufferEXTproc = (PFNGLBLITFRAMEBUFFEREXTPROC)wglGetProcAddress("glBlitFramebufferEXT");
	glBlitFramebufferLayersEXTproc = (PFNGLBLITFRAMEBUFFERLAYERSEXTPROC)wglGetProcAddress("glBlitFramebufferLayersEXT");
	glBlitFramebufferLayerEXTproc = (PFNGLBLITFRAMEBUFFERLAYEREXTPROC)wglGetProcAddress("glBlitFramebufferLayerEXT");
	glRenderbufferStorageMultisampleEXTproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)wglGetProcAddress("glRenderbufferStorageMultisampleEXT");
	glIsRenderbufferEXTproc = (PFNGLISRENDERBUFFEREXTPROC)wglGetProcAddress("glIsRenderbufferEXT");
	glBindRenderbufferEXTproc = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbufferEXT");
	glDeleteRenderbuffersEXTproc = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffersEXT");
	glGenRenderbuffersEXTproc = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffersEXT");
	glRenderbufferStorageEXTproc = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorageEXT");
	glGetRenderbufferParameterivEXTproc = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetRenderbufferParameterivEXT");
	glIsFramebufferEXTproc = (PFNGLISFRAMEBUFFEREXTPROC)wglGetProcAddress("glIsFramebufferEXT");
	glBindFramebufferEXTproc = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
	glDeleteFramebuffersEXTproc = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
	glGenFramebuffersEXTproc = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffersEXT");
	glCheckFramebufferStatusEXTproc = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
	glFramebufferTexture1DEXTproc = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)wglGetProcAddress("glFramebufferTexture1DEXT");
	glFramebufferTexture2DEXTproc = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2DEXT");
	glFramebufferTexture3DEXTproc = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)wglGetProcAddress("glFramebufferTexture3DEXT");
	glFramebufferRenderbufferEXTproc = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbufferEXT");
	glGetFramebufferAttachmentParameterivEXTproc = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
	glGenerateMipmapEXTproc = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmapEXT");
	glProgramParameteriEXTproc = (PFNGLPROGRAMPARAMETERIEXTPROC)wglGetProcAddress("glProgramParameteriEXT");
	glProgramEnvParameters4fvEXTproc = (PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)wglGetProcAddress("glProgramEnvParameters4fvEXT");
	glProgramLocalParameters4fvEXTproc = (PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)wglGetProcAddress("glProgramLocalParameters4fvEXT");
	glGetUniformuivEXTproc = (PFNGLGETUNIFORMUIVEXTPROC)wglGetProcAddress("glGetUniformuivEXT");
	glBindFragDataLocationEXTproc = (PFNGLBINDFRAGDATALOCATIONEXTPROC)wglGetProcAddress("glBindFragDataLocationEXT");
	glGetFragDataLocationEXTproc = (PFNGLGETFRAGDATALOCATIONEXTPROC)wglGetProcAddress("glGetFragDataLocationEXT");
	glUniform1uiEXTproc = (PFNGLUNIFORM1UIEXTPROC)wglGetProcAddress("glUniform1uiEXT");
	glUniform2uiEXTproc = (PFNGLUNIFORM2UIEXTPROC)wglGetProcAddress("glUniform2uiEXT");
	glUniform3uiEXTproc = (PFNGLUNIFORM3UIEXTPROC)wglGetProcAddress("glUniform3uiEXT");
	glUniform4uiEXTproc = (PFNGLUNIFORM4UIEXTPROC)wglGetProcAddress("glUniform4uiEXT");
	glUniform1uivEXTproc = (PFNGLUNIFORM1UIVEXTPROC)wglGetProcAddress("glUniform1uivEXT");
	glUniform2uivEXTproc = (PFNGLUNIFORM2UIVEXTPROC)wglGetProcAddress("glUniform2uivEXT");
	glUniform3uivEXTproc = (PFNGLUNIFORM3UIVEXTPROC)wglGetProcAddress("glUniform3uivEXT");
	glUniform4uivEXTproc = (PFNGLUNIFORM4UIVEXTPROC)wglGetProcAddress("glUniform4uivEXT");
	glVertexAttribI1iEXTproc = (PFNGLVERTEXATTRIBI1IEXTPROC)wglGetProcAddress("glVertexAttribI1iEXT");
	glVertexAttribI2iEXTproc = (PFNGLVERTEXATTRIBI2IEXTPROC)wglGetProcAddress("glVertexAttribI2iEXT");
	glVertexAttribI3iEXTproc = (PFNGLVERTEXATTRIBI3IEXTPROC)wglGetProcAddress("glVertexAttribI3iEXT");
	glVertexAttribI4iEXTproc = (PFNGLVERTEXATTRIBI4IEXTPROC)wglGetProcAddress("glVertexAttribI4iEXT");
	glVertexAttribI1uiEXTproc = (PFNGLVERTEXATTRIBI1UIEXTPROC)wglGetProcAddress("glVertexAttribI1uiEXT");
	glVertexAttribI2uiEXTproc = (PFNGLVERTEXATTRIBI2UIEXTPROC)wglGetProcAddress("glVertexAttribI2uiEXT");
	glVertexAttribI3uiEXTproc = (PFNGLVERTEXATTRIBI3UIEXTPROC)wglGetProcAddress("glVertexAttribI3uiEXT");
	glVertexAttribI4uiEXTproc = (PFNGLVERTEXATTRIBI4UIEXTPROC)wglGetProcAddress("glVertexAttribI4uiEXT");
	glVertexAttribI1ivEXTproc = (PFNGLVERTEXATTRIBI1IVEXTPROC)wglGetProcAddress("glVertexAttribI1ivEXT");
	glVertexAttribI2ivEXTproc = (PFNGLVERTEXATTRIBI2IVEXTPROC)wglGetProcAddress("glVertexAttribI2ivEXT");
	glVertexAttribI3ivEXTproc = (PFNGLVERTEXATTRIBI3IVEXTPROC)wglGetProcAddress("glVertexAttribI3ivEXT");
	glVertexAttribI4ivEXTproc = (PFNGLVERTEXATTRIBI4IVEXTPROC)wglGetProcAddress("glVertexAttribI4ivEXT");
	glVertexAttribI1uivEXTproc = (PFNGLVERTEXATTRIBI1UIVEXTPROC)wglGetProcAddress("glVertexAttribI1uivEXT");
	glVertexAttribI2uivEXTproc = (PFNGLVERTEXATTRIBI2UIVEXTPROC)wglGetProcAddress("glVertexAttribI2uivEXT");
	glVertexAttribI3uivEXTproc = (PFNGLVERTEXATTRIBI3UIVEXTPROC)wglGetProcAddress("glVertexAttribI3uivEXT");
	glVertexAttribI4uivEXTproc = (PFNGLVERTEXATTRIBI4UIVEXTPROC)wglGetProcAddress("glVertexAttribI4uivEXT");
	glVertexAttribI4bvEXTproc = (PFNGLVERTEXATTRIBI4BVEXTPROC)wglGetProcAddress("glVertexAttribI4bvEXT");
	glVertexAttribI4svEXTproc = (PFNGLVERTEXATTRIBI4SVEXTPROC)wglGetProcAddress("glVertexAttribI4svEXT");
	glVertexAttribI4ubvEXTproc = (PFNGLVERTEXATTRIBI4UBVEXTPROC)wglGetProcAddress("glVertexAttribI4ubvEXT");
	glVertexAttribI4usvEXTproc = (PFNGLVERTEXATTRIBI4USVEXTPROC)wglGetProcAddress("glVertexAttribI4usvEXT");
	glVertexAttribIPointerEXTproc = (PFNGLVERTEXATTRIBIPOINTEREXTPROC)wglGetProcAddress("glVertexAttribIPointerEXT");
	glGetVertexAttribIivEXTproc = (PFNGLGETVERTEXATTRIBIIVEXTPROC)wglGetProcAddress("glGetVertexAttribIivEXT");
	glGetVertexAttribIuivEXTproc = (PFNGLGETVERTEXATTRIBIUIVEXTPROC)wglGetProcAddress("glGetVertexAttribIuivEXT");
	glGetHistogramEXTproc = (PFNGLGETHISTOGRAMEXTPROC)wglGetProcAddress("glGetHistogramEXT");
	glGetHistogramParameterfvEXTproc = (PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)wglGetProcAddress("glGetHistogramParameterfvEXT");
	glGetHistogramParameterivEXTproc = (PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)wglGetProcAddress("glGetHistogramParameterivEXT");
	glGetMinmaxEXTproc = (PFNGLGETMINMAXEXTPROC)wglGetProcAddress("glGetMinmaxEXT");
	glGetMinmaxParameterfvEXTproc = (PFNGLGETMINMAXPARAMETERFVEXTPROC)wglGetProcAddress("glGetMinmaxParameterfvEXT");
	glGetMinmaxParameterivEXTproc = (PFNGLGETMINMAXPARAMETERIVEXTPROC)wglGetProcAddress("glGetMinmaxParameterivEXT");
	glHistogramEXTproc = (PFNGLHISTOGRAMEXTPROC)wglGetProcAddress("glHistogramEXT");
	glMinmaxEXTproc = (PFNGLMINMAXEXTPROC)wglGetProcAddress("glMinmaxEXT");
	glResetHistogramEXTproc = (PFNGLRESETHISTOGRAMEXTPROC)wglGetProcAddress("glResetHistogramEXT");
	glResetMinmaxEXTproc = (PFNGLRESETMINMAXEXTPROC)wglGetProcAddress("glResetMinmaxEXT");
	glIndexFuncEXTproc = (PFNGLINDEXFUNCEXTPROC)wglGetProcAddress("glIndexFuncEXT");
	glIndexMaterialEXTproc = (PFNGLINDEXMATERIALEXTPROC)wglGetProcAddress("glIndexMaterialEXT");
	glApplyTextureEXTproc = (PFNGLAPPLYTEXTUREEXTPROC)wglGetProcAddress("glApplyTextureEXT");
	glTextureLightEXTproc = (PFNGLTEXTURELIGHTEXTPROC)wglGetProcAddress("glTextureLightEXT");
	glTextureMaterialEXTproc = (PFNGLTEXTUREMATERIALEXTPROC)wglGetProcAddress("glTextureMaterialEXT");
	glGetUnsignedBytevEXTproc = (PFNGLGETUNSIGNEDBYTEVEXTPROC)wglGetProcAddress("glGetUnsignedBytevEXT");
	glGetUnsignedBytei_vEXTproc = (PFNGLGETUNSIGNEDBYTEI_VEXTPROC)wglGetProcAddress("glGetUnsignedBytei_vEXT");
	glDeleteMemoryObjectsEXTproc = (PFNGLDELETEMEMORYOBJECTSEXTPROC)wglGetProcAddress("glDeleteMemoryObjectsEXT");
	glIsMemoryObjectEXTproc = (PFNGLISMEMORYOBJECTEXTPROC)wglGetProcAddress("glIsMemoryObjectEXT");
	glCreateMemoryObjectsEXTproc = (PFNGLCREATEMEMORYOBJECTSEXTPROC)wglGetProcAddress("glCreateMemoryObjectsEXT");
	glMemoryObjectParameterivEXTproc = (PFNGLMEMORYOBJECTPARAMETERIVEXTPROC)wglGetProcAddress("glMemoryObjectParameterivEXT");
	glGetMemoryObjectParameterivEXTproc = (PFNGLGETMEMORYOBJECTPARAMETERIVEXTPROC)wglGetProcAddress("glGetMemoryObjectParameterivEXT");
	glTexStorageMem2DEXTproc = (PFNGLTEXSTORAGEMEM2DEXTPROC)wglGetProcAddress("glTexStorageMem2DEXT");
	glTexStorageMem2DMultisampleEXTproc = (PFNGLTEXSTORAGEMEM2DMULTISAMPLEEXTPROC)wglGetProcAddress("glTexStorageMem2DMultisampleEXT");
	glTexStorageMem3DEXTproc = (PFNGLTEXSTORAGEMEM3DEXTPROC)wglGetProcAddress("glTexStorageMem3DEXT");
	glTexStorageMem3DMultisampleEXTproc = (PFNGLTEXSTORAGEMEM3DMULTISAMPLEEXTPROC)wglGetProcAddress("glTexStorageMem3DMultisampleEXT");
	glBufferStorageMemEXTproc = (PFNGLBUFFERSTORAGEMEMEXTPROC)wglGetProcAddress("glBufferStorageMemEXT");
	glTextureStorageMem2DEXTproc = (PFNGLTEXTURESTORAGEMEM2DEXTPROC)wglGetProcAddress("glTextureStorageMem2DEXT");
	glTextureStorageMem2DMultisampleEXTproc = (PFNGLTEXTURESTORAGEMEM2DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorageMem2DMultisampleEXT");
	glTextureStorageMem3DEXTproc = (PFNGLTEXTURESTORAGEMEM3DEXTPROC)wglGetProcAddress("glTextureStorageMem3DEXT");
	glTextureStorageMem3DMultisampleEXTproc = (PFNGLTEXTURESTORAGEMEM3DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorageMem3DMultisampleEXT");
	glNamedBufferStorageMemEXTproc = (PFNGLNAMEDBUFFERSTORAGEMEMEXTPROC)wglGetProcAddress("glNamedBufferStorageMemEXT");
	glTexStorageMem1DEXTproc = (PFNGLTEXSTORAGEMEM1DEXTPROC)wglGetProcAddress("glTexStorageMem1DEXT");
	glTextureStorageMem1DEXTproc = (PFNGLTEXTURESTORAGEMEM1DEXTPROC)wglGetProcAddress("glTextureStorageMem1DEXT");
	glImportMemoryFdEXTproc = (PFNGLIMPORTMEMORYFDEXTPROC)wglGetProcAddress("glImportMemoryFdEXT");
	glImportMemoryWin32HandleEXTproc = (PFNGLIMPORTMEMORYWIN32HANDLEEXTPROC)wglGetProcAddress("glImportMemoryWin32HandleEXT");
	glImportMemoryWin32NameEXTproc = (PFNGLIMPORTMEMORYWIN32NAMEEXTPROC)wglGetProcAddress("glImportMemoryWin32NameEXT");
	glMultiDrawArraysEXTproc = (PFNGLMULTIDRAWARRAYSEXTPROC)wglGetProcAddress("glMultiDrawArraysEXT");
	glMultiDrawElementsEXTproc = (PFNGLMULTIDRAWELEMENTSEXTPROC)wglGetProcAddress("glMultiDrawElementsEXT");
	glSampleMaskEXTproc = (PFNGLSAMPLEMASKEXTPROC)wglGetProcAddress("glSampleMaskEXT");
	glSamplePatternEXTproc = (PFNGLSAMPLEPATTERNEXTPROC)wglGetProcAddress("glSamplePatternEXT");
	glColorTableEXTproc = (PFNGLCOLORTABLEEXTPROC)wglGetProcAddress("glColorTableEXT");
	glGetColorTableEXTproc = (PFNGLGETCOLORTABLEEXTPROC)wglGetProcAddress("glGetColorTableEXT");
	glGetColorTableParameterivEXTproc = (PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)wglGetProcAddress("glGetColorTableParameterivEXT");
	glGetColorTableParameterfvEXTproc = (PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)wglGetProcAddress("glGetColorTableParameterfvEXT");
	glPixelTransformParameteriEXTproc = (PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)wglGetProcAddress("glPixelTransformParameteriEXT");
	glPixelTransformParameterfEXTproc = (PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)wglGetProcAddress("glPixelTransformParameterfEXT");
	glPixelTransformParameterivEXTproc = (PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)wglGetProcAddress("glPixelTransformParameterivEXT");
	glPixelTransformParameterfvEXTproc = (PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)wglGetProcAddress("glPixelTransformParameterfvEXT");
	glGetPixelTransformParameterivEXTproc = (PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)wglGetProcAddress("glGetPixelTransformParameterivEXT");
	glGetPixelTransformParameterfvEXTproc = (PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)wglGetProcAddress("glGetPixelTransformParameterfvEXT");
	glPointParameterfEXTproc = (PFNGLPOINTPARAMETERFEXTPROC)wglGetProcAddress("glPointParameterfEXT");
	glPointParameterfvEXTproc = (PFNGLPOINTPARAMETERFVEXTPROC)wglGetProcAddress("glPointParameterfvEXT");
	glPolygonOffsetEXTproc = (PFNGLPOLYGONOFFSETEXTPROC)wglGetProcAddress("glPolygonOffsetEXT");
	glPolygonOffsetClampEXTproc = (PFNGLPOLYGONOFFSETCLAMPEXTPROC)wglGetProcAddress("glPolygonOffsetClampEXT");
	glProvokingVertexEXTproc = (PFNGLPROVOKINGVERTEXEXTPROC)wglGetProcAddress("glProvokingVertexEXT");
	glRasterSamplesEXTproc = (PFNGLRASTERSAMPLESEXTPROC)wglGetProcAddress("glRasterSamplesEXT");
	glSecondaryColor3bEXTproc = (PFNGLSECONDARYCOLOR3BEXTPROC)wglGetProcAddress("glSecondaryColor3bEXT");
	glSecondaryColor3bvEXTproc = (PFNGLSECONDARYCOLOR3BVEXTPROC)wglGetProcAddress("glSecondaryColor3bvEXT");
	glSecondaryColor3dEXTproc = (PFNGLSECONDARYCOLOR3DEXTPROC)wglGetProcAddress("glSecondaryColor3dEXT");
	glSecondaryColor3dvEXTproc = (PFNGLSECONDARYCOLOR3DVEXTPROC)wglGetProcAddress("glSecondaryColor3dvEXT");
	glSecondaryColor3fEXTproc = (PFNGLSECONDARYCOLOR3FEXTPROC)wglGetProcAddress("glSecondaryColor3fEXT");
	glSecondaryColor3fvEXTproc = (PFNGLSECONDARYCOLOR3FVEXTPROC)wglGetProcAddress("glSecondaryColor3fvEXT");
	glSecondaryColor3iEXTproc = (PFNGLSECONDARYCOLOR3IEXTPROC)wglGetProcAddress("glSecondaryColor3iEXT");
	glSecondaryColor3ivEXTproc = (PFNGLSECONDARYCOLOR3IVEXTPROC)wglGetProcAddress("glSecondaryColor3ivEXT");
	glSecondaryColor3sEXTproc = (PFNGLSECONDARYCOLOR3SEXTPROC)wglGetProcAddress("glSecondaryColor3sEXT");
	glSecondaryColor3svEXTproc = (PFNGLSECONDARYCOLOR3SVEXTPROC)wglGetProcAddress("glSecondaryColor3svEXT");
	glSecondaryColor3ubEXTproc = (PFNGLSECONDARYCOLOR3UBEXTPROC)wglGetProcAddress("glSecondaryColor3ubEXT");
	glSecondaryColor3ubvEXTproc = (PFNGLSECONDARYCOLOR3UBVEXTPROC)wglGetProcAddress("glSecondaryColor3ubvEXT");
	glSecondaryColor3uiEXTproc = (PFNGLSECONDARYCOLOR3UIEXTPROC)wglGetProcAddress("glSecondaryColor3uiEXT");
	glSecondaryColor3uivEXTproc = (PFNGLSECONDARYCOLOR3UIVEXTPROC)wglGetProcAddress("glSecondaryColor3uivEXT");
	glSecondaryColor3usEXTproc = (PFNGLSECONDARYCOLOR3USEXTPROC)wglGetProcAddress("glSecondaryColor3usEXT");
	glSecondaryColor3usvEXTproc = (PFNGLSECONDARYCOLOR3USVEXTPROC)wglGetProcAddress("glSecondaryColor3usvEXT");
	glSecondaryColorPointerEXTproc = (PFNGLSECONDARYCOLORPOINTEREXTPROC)wglGetProcAddress("glSecondaryColorPointerEXT");
	glGenSemaphoresEXTproc = (PFNGLGENSEMAPHORESEXTPROC)wglGetProcAddress("glGenSemaphoresEXT");
	glDeleteSemaphoresEXTproc = (PFNGLDELETESEMAPHORESEXTPROC)wglGetProcAddress("glDeleteSemaphoresEXT");
	glIsSemaphoreEXTproc = (PFNGLISSEMAPHOREEXTPROC)wglGetProcAddress("glIsSemaphoreEXT");
	glSemaphoreParameterui64vEXTproc = (PFNGLSEMAPHOREPARAMETERUI64VEXTPROC)wglGetProcAddress("glSemaphoreParameterui64vEXT");
	glGetSemaphoreParameterui64vEXTproc = (PFNGLGETSEMAPHOREPARAMETERUI64VEXTPROC)wglGetProcAddress("glGetSemaphoreParameterui64vEXT");
	glWaitSemaphoreEXTproc = (PFNGLWAITSEMAPHOREEXTPROC)wglGetProcAddress("glWaitSemaphoreEXT");
	glSignalSemaphoreEXTproc = (PFNGLSIGNALSEMAPHOREEXTPROC)wglGetProcAddress("glSignalSemaphoreEXT");
	glImportSemaphoreFdEXTproc = (PFNGLIMPORTSEMAPHOREFDEXTPROC)wglGetProcAddress("glImportSemaphoreFdEXT");
	glImportSemaphoreWin32HandleEXTproc = (PFNGLIMPORTSEMAPHOREWIN32HANDLEEXTPROC)wglGetProcAddress("glImportSemaphoreWin32HandleEXT");
	glImportSemaphoreWin32NameEXTproc = (PFNGLIMPORTSEMAPHOREWIN32NAMEEXTPROC)wglGetProcAddress("glImportSemaphoreWin32NameEXT");
	glUseShaderProgramEXTproc = (PFNGLUSESHADERPROGRAMEXTPROC)wglGetProcAddress("glUseShaderProgramEXT");
	glActiveProgramEXTproc = (PFNGLACTIVEPROGRAMEXTPROC)wglGetProcAddress("glActiveProgramEXT");
	glCreateShaderProgramEXTproc = (PFNGLCREATESHADERPROGRAMEXTPROC)wglGetProcAddress("glCreateShaderProgramEXT");
	glFramebufferFetchBarrierEXTproc = (PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC)wglGetProcAddress("glFramebufferFetchBarrierEXT");
	glBindImageTextureEXTproc = (PFNGLBINDIMAGETEXTUREEXTPROC)wglGetProcAddress("glBindImageTextureEXT");
	glMemoryBarrierEXTproc = (PFNGLMEMORYBARRIEREXTPROC)wglGetProcAddress("glMemoryBarrierEXT");
	glStencilClearTagEXTproc = (PFNGLSTENCILCLEARTAGEXTPROC)wglGetProcAddress("glStencilClearTagEXT");
	glActiveStencilFaceEXTproc = (PFNGLACTIVESTENCILFACEEXTPROC)wglGetProcAddress("glActiveStencilFaceEXT");
	glTexSubImage1DEXTproc = (PFNGLTEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glTexSubImage1DEXT");
	glTexSubImage2DEXTproc = (PFNGLTEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glTexSubImage2DEXT");
	glTexImage3DEXTproc = (PFNGLTEXIMAGE3DEXTPROC)wglGetProcAddress("glTexImage3DEXT");
	glTexSubImage3DEXTproc = (PFNGLTEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glTexSubImage3DEXT");
	glFramebufferTextureLayerEXTproc = (PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)wglGetProcAddress("glFramebufferTextureLayerEXT");
	glTexBufferEXTproc = (PFNGLTEXBUFFEREXTPROC)wglGetProcAddress("glTexBufferEXT");
	glTexParameterIivEXTproc = (PFNGLTEXPARAMETERIIVEXTPROC)wglGetProcAddress("glTexParameterIivEXT");
	glTexParameterIuivEXTproc = (PFNGLTEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glTexParameterIuivEXT");
	glGetTexParameterIivEXTproc = (PFNGLGETTEXPARAMETERIIVEXTPROC)wglGetProcAddress("glGetTexParameterIivEXT");
	glGetTexParameterIuivEXTproc = (PFNGLGETTEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetTexParameterIuivEXT");
	glClearColorIiEXTproc = (PFNGLCLEARCOLORIIEXTPROC)wglGetProcAddress("glClearColorIiEXT");
	glClearColorIuiEXTproc = (PFNGLCLEARCOLORIUIEXTPROC)wglGetProcAddress("glClearColorIuiEXT");
	glAreTexturesResidentEXTproc = (PFNGLARETEXTURESRESIDENTEXTPROC)wglGetProcAddress("glAreTexturesResidentEXT");
	glBindTextureEXTproc = (PFNGLBINDTEXTUREEXTPROC)wglGetProcAddress("glBindTextureEXT");
	glDeleteTexturesEXTproc = (PFNGLDELETETEXTURESEXTPROC)wglGetProcAddress("glDeleteTexturesEXT");
	glGenTexturesEXTproc = (PFNGLGENTEXTURESEXTPROC)wglGetProcAddress("glGenTexturesEXT");
	glIsTextureEXTproc = (PFNGLISTEXTUREEXTPROC)wglGetProcAddress("glIsTextureEXT");
	glPrioritizeTexturesEXTproc = (PFNGLPRIORITIZETEXTURESEXTPROC)wglGetProcAddress("glPrioritizeTexturesEXT");
	glTextureNormalEXTproc = (PFNGLTEXTURENORMALEXTPROC)wglGetProcAddress("glTextureNormalEXT");
	glTexStorage1DEXTproc = (PFNGLTEXSTORAGE1DEXTPROC)wglGetProcAddress("glTexStorage1DEXT");
	glTexStorage2DEXTproc = (PFNGLTEXSTORAGE2DEXTPROC)wglGetProcAddress("glTexStorage2DEXT");
	glTexStorage3DEXTproc = (PFNGLTEXSTORAGE3DEXTPROC)wglGetProcAddress("glTexStorage3DEXT");
	glGetQueryObjecti64vEXTproc = (PFNGLGETQUERYOBJECTI64VEXTPROC)wglGetProcAddress("glGetQueryObjecti64vEXT");
	glGetQueryObjectui64vEXTproc = (PFNGLGETQUERYOBJECTUI64VEXTPROC)wglGetProcAddress("glGetQueryObjectui64vEXT");
	glBeginTransformFeedbackEXTproc = (PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)wglGetProcAddress("glBeginTransformFeedbackEXT");
	glEndTransformFeedbackEXTproc = (PFNGLENDTRANSFORMFEEDBACKEXTPROC)wglGetProcAddress("glEndTransformFeedbackEXT");
	glBindBufferRangeEXTproc = (PFNGLBINDBUFFERRANGEEXTPROC)wglGetProcAddress("glBindBufferRangeEXT");
	glBindBufferOffsetEXTproc = (PFNGLBINDBUFFEROFFSETEXTPROC)wglGetProcAddress("glBindBufferOffsetEXT");
	glBindBufferBaseEXTproc = (PFNGLBINDBUFFERBASEEXTPROC)wglGetProcAddress("glBindBufferBaseEXT");
	glTransformFeedbackVaryingsEXTproc = (PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)wglGetProcAddress("glTransformFeedbackVaryingsEXT");
	glGetTransformFeedbackVaryingEXTproc = (PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)wglGetProcAddress("glGetTransformFeedbackVaryingEXT");
	glArrayElementEXTproc = (PFNGLARRAYELEMENTEXTPROC)wglGetProcAddress("glArrayElementEXT");
	glColorPointerEXTproc = (PFNGLCOLORPOINTEREXTPROC)wglGetProcAddress("glColorPointerEXT");
	glDrawArraysEXTproc = (PFNGLDRAWARRAYSEXTPROC)wglGetProcAddress("glDrawArraysEXT");
	glEdgeFlagPointerEXTproc = (PFNGLEDGEFLAGPOINTEREXTPROC)wglGetProcAddress("glEdgeFlagPointerEXT");
	glGetPointervEXTproc = (PFNGLGETPOINTERVEXTPROC)wglGetProcAddress("glGetPointervEXT");
	glIndexPointerEXTproc = (PFNGLINDEXPOINTEREXTPROC)wglGetProcAddress("glIndexPointerEXT");
	glNormalPointerEXTproc = (PFNGLNORMALPOINTEREXTPROC)wglGetProcAddress("glNormalPointerEXT");
	glTexCoordPointerEXTproc = (PFNGLTEXCOORDPOINTEREXTPROC)wglGetProcAddress("glTexCoordPointerEXT");
	glVertexPointerEXTproc = (PFNGLVERTEXPOINTEREXTPROC)wglGetProcAddress("glVertexPointerEXT");
	glVertexAttribL1dEXTproc = (PFNGLVERTEXATTRIBL1DEXTPROC)wglGetProcAddress("glVertexAttribL1dEXT");
	glVertexAttribL2dEXTproc = (PFNGLVERTEXATTRIBL2DEXTPROC)wglGetProcAddress("glVertexAttribL2dEXT");
	glVertexAttribL3dEXTproc = (PFNGLVERTEXATTRIBL3DEXTPROC)wglGetProcAddress("glVertexAttribL3dEXT");
	glVertexAttribL4dEXTproc = (PFNGLVERTEXATTRIBL4DEXTPROC)wglGetProcAddress("glVertexAttribL4dEXT");
	glVertexAttribL1dvEXTproc = (PFNGLVERTEXATTRIBL1DVEXTPROC)wglGetProcAddress("glVertexAttribL1dvEXT");
	glVertexAttribL2dvEXTproc = (PFNGLVERTEXATTRIBL2DVEXTPROC)wglGetProcAddress("glVertexAttribL2dvEXT");
	glVertexAttribL3dvEXTproc = (PFNGLVERTEXATTRIBL3DVEXTPROC)wglGetProcAddress("glVertexAttribL3dvEXT");
	glVertexAttribL4dvEXTproc = (PFNGLVERTEXATTRIBL4DVEXTPROC)wglGetProcAddress("glVertexAttribL4dvEXT");
	glVertexAttribLPointerEXTproc = (PFNGLVERTEXATTRIBLPOINTEREXTPROC)wglGetProcAddress("glVertexAttribLPointerEXT");
	glGetVertexAttribLdvEXTproc = (PFNGLGETVERTEXATTRIBLDVEXTPROC)wglGetProcAddress("glGetVertexAttribLdvEXT");
	glBeginVertexShaderEXTproc = (PFNGLBEGINVERTEXSHADEREXTPROC)wglGetProcAddress("glBeginVertexShaderEXT");
	glEndVertexShaderEXTproc = (PFNGLENDVERTEXSHADEREXTPROC)wglGetProcAddress("glEndVertexShaderEXT");
	glBindVertexShaderEXTproc = (PFNGLBINDVERTEXSHADEREXTPROC)wglGetProcAddress("glBindVertexShaderEXT");
	glGenVertexShadersEXTproc = (PFNGLGENVERTEXSHADERSEXTPROC)wglGetProcAddress("glGenVertexShadersEXT");
	glDeleteVertexShaderEXTproc = (PFNGLDELETEVERTEXSHADEREXTPROC)wglGetProcAddress("glDeleteVertexShaderEXT");
	glShaderOp1EXTproc = (PFNGLSHADEROP1EXTPROC)wglGetProcAddress("glShaderOp1EXT");
	glShaderOp2EXTproc = (PFNGLSHADEROP2EXTPROC)wglGetProcAddress("glShaderOp2EXT");
	glShaderOp3EXTproc = (PFNGLSHADEROP3EXTPROC)wglGetProcAddress("glShaderOp3EXT");
	glSwizzleEXTproc = (PFNGLSWIZZLEEXTPROC)wglGetProcAddress("glSwizzleEXT");
	glWriteMaskEXTproc = (PFNGLWRITEMASKEXTPROC)wglGetProcAddress("glWriteMaskEXT");
	glInsertComponentEXTproc = (PFNGLINSERTCOMPONENTEXTPROC)wglGetProcAddress("glInsertComponentEXT");
	glExtractComponentEXTproc = (PFNGLEXTRACTCOMPONENTEXTPROC)wglGetProcAddress("glExtractComponentEXT");
	glGenSymbolsEXTproc = (PFNGLGENSYMBOLSEXTPROC)wglGetProcAddress("glGenSymbolsEXT");
	glSetInvariantEXTproc = (PFNGLSETINVARIANTEXTPROC)wglGetProcAddress("glSetInvariantEXT");
	glSetLocalConstantEXTproc = (PFNGLSETLOCALCONSTANTEXTPROC)wglGetProcAddress("glSetLocalConstantEXT");
	glVariantbvEXTproc = (PFNGLVARIANTBVEXTPROC)wglGetProcAddress("glVariantbvEXT");
	glVariantsvEXTproc = (PFNGLVARIANTSVEXTPROC)wglGetProcAddress("glVariantsvEXT");
	glVariantivEXTproc = (PFNGLVARIANTIVEXTPROC)wglGetProcAddress("glVariantivEXT");
	glVariantfvEXTproc = (PFNGLVARIANTFVEXTPROC)wglGetProcAddress("glVariantfvEXT");
	glVariantdvEXTproc = (PFNGLVARIANTDVEXTPROC)wglGetProcAddress("glVariantdvEXT");
	glVariantubvEXTproc = (PFNGLVARIANTUBVEXTPROC)wglGetProcAddress("glVariantubvEXT");
	glVariantusvEXTproc = (PFNGLVARIANTUSVEXTPROC)wglGetProcAddress("glVariantusvEXT");
	glVariantuivEXTproc = (PFNGLVARIANTUIVEXTPROC)wglGetProcAddress("glVariantuivEXT");
	glVariantPointerEXTproc = (PFNGLVARIANTPOINTEREXTPROC)wglGetProcAddress("glVariantPointerEXT");
	glEnableVariantClientStateEXTproc = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)wglGetProcAddress("glEnableVariantClientStateEXT");
	glDisableVariantClientStateEXTproc = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)wglGetProcAddress("glDisableVariantClientStateEXT");
	glBindLightParameterEXTproc = (PFNGLBINDLIGHTPARAMETEREXTPROC)wglGetProcAddress("glBindLightParameterEXT");
	glBindMaterialParameterEXTproc = (PFNGLBINDMATERIALPARAMETEREXTPROC)wglGetProcAddress("glBindMaterialParameterEXT");
	glBindTexGenParameterEXTproc = (PFNGLBINDTEXGENPARAMETEREXTPROC)wglGetProcAddress("glBindTexGenParameterEXT");
	glBindTextureUnitParameterEXTproc = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)wglGetProcAddress("glBindTextureUnitParameterEXT");
	glBindParameterEXTproc = (PFNGLBINDPARAMETEREXTPROC)wglGetProcAddress("glBindParameterEXT");
	glIsVariantEnabledEXTproc = (PFNGLISVARIANTENABLEDEXTPROC)wglGetProcAddress("glIsVariantEnabledEXT");
	glGetVariantBooleanvEXTproc = (PFNGLGETVARIANTBOOLEANVEXTPROC)wglGetProcAddress("glGetVariantBooleanvEXT");
	glGetVariantIntegervEXTproc = (PFNGLGETVARIANTINTEGERVEXTPROC)wglGetProcAddress("glGetVariantIntegervEXT");
	glGetVariantFloatvEXTproc = (PFNGLGETVARIANTFLOATVEXTPROC)wglGetProcAddress("glGetVariantFloatvEXT");
	glGetVariantPointervEXTproc = (PFNGLGETVARIANTPOINTERVEXTPROC)wglGetProcAddress("glGetVariantPointervEXT");
	glGetInvariantBooleanvEXTproc = (PFNGLGETINVARIANTBOOLEANVEXTPROC)wglGetProcAddress("glGetInvariantBooleanvEXT");
	glGetInvariantIntegervEXTproc = (PFNGLGETINVARIANTINTEGERVEXTPROC)wglGetProcAddress("glGetInvariantIntegervEXT");
	glGetInvariantFloatvEXTproc = (PFNGLGETINVARIANTFLOATVEXTPROC)wglGetProcAddress("glGetInvariantFloatvEXT");
	glGetLocalConstantBooleanvEXTproc = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)wglGetProcAddress("glGetLocalConstantBooleanvEXT");
	glGetLocalConstantIntegervEXTproc = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)wglGetProcAddress("glGetLocalConstantIntegervEXT");
	glGetLocalConstantFloatvEXTproc = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC)wglGetProcAddress("glGetLocalConstantFloatvEXT");
	glVertexWeightfEXTproc = (PFNGLVERTEXWEIGHTFEXTPROC)wglGetProcAddress("glVertexWeightfEXT");
	glVertexWeightfvEXTproc = (PFNGLVERTEXWEIGHTFVEXTPROC)wglGetProcAddress("glVertexWeightfvEXT");
	glVertexWeightPointerEXTproc = (PFNGLVERTEXWEIGHTPOINTEREXTPROC)wglGetProcAddress("glVertexWeightPointerEXT");
	glAcquireKeyedMutexWin32EXTproc = (PFNGLACQUIREKEYEDMUTEXWIN32EXTPROC)wglGetProcAddress("glAcquireKeyedMutexWin32EXT");
	glReleaseKeyedMutexWin32EXTproc = (PFNGLRELEASEKEYEDMUTEXWIN32EXTPROC)wglGetProcAddress("glReleaseKeyedMutexWin32EXT");
	glWindowRectanglesEXTproc = (PFNGLWINDOWRECTANGLESEXTPROC)wglGetProcAddress("glWindowRectanglesEXT");
	glImportSyncEXTproc = (PFNGLIMPORTSYNCEXTPROC)wglGetProcAddress("glImportSyncEXT");
	glFrameTerminatorGREMEDYproc = (PFNGLFRAMETERMINATORGREMEDYPROC)wglGetProcAddress("glFrameTerminatorGREMEDY");
	glStringMarkerGREMEDYproc = (PFNGLSTRINGMARKERGREMEDYPROC)wglGetProcAddress("glStringMarkerGREMEDY");
	glImageTransformParameteriHPproc = (PFNGLIMAGETRANSFORMPARAMETERIHPPROC)wglGetProcAddress("glImageTransformParameteriHP");
	glImageTransformParameterfHPproc = (PFNGLIMAGETRANSFORMPARAMETERFHPPROC)wglGetProcAddress("glImageTransformParameterfHP");
	glImageTransformParameterivHPproc = (PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)wglGetProcAddress("glImageTransformParameterivHP");
	glImageTransformParameterfvHPproc = (PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)wglGetProcAddress("glImageTransformParameterfvHP");
	glGetImageTransformParameterivHPproc = (PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)wglGetProcAddress("glGetImageTransformParameterivHP");
	glGetImageTransformParameterfvHPproc = (PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)wglGetProcAddress("glGetImageTransformParameterfvHP");
	glMultiModeDrawArraysIBMproc = (PFNGLMULTIMODEDRAWARRAYSIBMPROC)wglGetProcAddress("glMultiModeDrawArraysIBM");
	glMultiModeDrawElementsIBMproc = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC)wglGetProcAddress("glMultiModeDrawElementsIBM");
	glFlushStaticDataIBMproc = (PFNGLFLUSHSTATICDATAIBMPROC)wglGetProcAddress("glFlushStaticDataIBM");
	glColorPointerListIBMproc = (PFNGLCOLORPOINTERLISTIBMPROC)wglGetProcAddress("glColorPointerListIBM");
	glSecondaryColorPointerListIBMproc = (PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)wglGetProcAddress("glSecondaryColorPointerListIBM");
	glEdgeFlagPointerListIBMproc = (PFNGLEDGEFLAGPOINTERLISTIBMPROC)wglGetProcAddress("glEdgeFlagPointerListIBM");
	glFogCoordPointerListIBMproc = (PFNGLFOGCOORDPOINTERLISTIBMPROC)wglGetProcAddress("glFogCoordPointerListIBM");
	glIndexPointerListIBMproc = (PFNGLINDEXPOINTERLISTIBMPROC)wglGetProcAddress("glIndexPointerListIBM");
	glNormalPointerListIBMproc = (PFNGLNORMALPOINTERLISTIBMPROC)wglGetProcAddress("glNormalPointerListIBM");
	glTexCoordPointerListIBMproc = (PFNGLTEXCOORDPOINTERLISTIBMPROC)wglGetProcAddress("glTexCoordPointerListIBM");
	glVertexPointerListIBMproc = (PFNGLVERTEXPOINTERLISTIBMPROC)wglGetProcAddress("glVertexPointerListIBM");
	glBlendFuncSeparateINGRproc = (PFNGLBLENDFUNCSEPARATEINGRPROC)wglGetProcAddress("glBlendFuncSeparateINGR");
	glApplyFramebufferAttachmentCMAAINTELproc = (PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC)wglGetProcAddress("glApplyFramebufferAttachmentCMAAINTEL");
	glSyncTextureINTELproc = (PFNGLSYNCTEXTUREINTELPROC)wglGetProcAddress("glSyncTextureINTEL");
	glUnmapTexture2DINTELproc = (PFNGLUNMAPTEXTURE2DINTELPROC)wglGetProcAddress("glUnmapTexture2DINTEL");
	glMapTexture2DINTELproc = (PFNGLMAPTEXTURE2DINTELPROC)wglGetProcAddress("glMapTexture2DINTEL");
	glVertexPointervINTELproc = (PFNGLVERTEXPOINTERVINTELPROC)wglGetProcAddress("glVertexPointervINTEL");
	glNormalPointervINTELproc = (PFNGLNORMALPOINTERVINTELPROC)wglGetProcAddress("glNormalPointervINTEL");
	glColorPointervINTELproc = (PFNGLCOLORPOINTERVINTELPROC)wglGetProcAddress("glColorPointervINTEL");
	glTexCoordPointervINTELproc = (PFNGLTEXCOORDPOINTERVINTELPROC)wglGetProcAddress("glTexCoordPointervINTEL");
	glBeginPerfQueryINTELproc = (PFNGLBEGINPERFQUERYINTELPROC)wglGetProcAddress("glBeginPerfQueryINTEL");
	glCreatePerfQueryINTELproc = (PFNGLCREATEPERFQUERYINTELPROC)wglGetProcAddress("glCreatePerfQueryINTEL");
	glDeletePerfQueryINTELproc = (PFNGLDELETEPERFQUERYINTELPROC)wglGetProcAddress("glDeletePerfQueryINTEL");
	glEndPerfQueryINTELproc = (PFNGLENDPERFQUERYINTELPROC)wglGetProcAddress("glEndPerfQueryINTEL");
	glGetFirstPerfQueryIdINTELproc = (PFNGLGETFIRSTPERFQUERYIDINTELPROC)wglGetProcAddress("glGetFirstPerfQueryIdINTEL");
	glGetNextPerfQueryIdINTELproc = (PFNGLGETNEXTPERFQUERYIDINTELPROC)wglGetProcAddress("glGetNextPerfQueryIdINTEL");
	glGetPerfCounterInfoINTELproc = (PFNGLGETPERFCOUNTERINFOINTELPROC)wglGetProcAddress("glGetPerfCounterInfoINTEL");
	glGetPerfQueryDataINTELproc = (PFNGLGETPERFQUERYDATAINTELPROC)wglGetProcAddress("glGetPerfQueryDataINTEL");
	glGetPerfQueryIdByNameINTELproc = (PFNGLGETPERFQUERYIDBYNAMEINTELPROC)wglGetProcAddress("glGetPerfQueryIdByNameINTEL");
	glGetPerfQueryInfoINTELproc = (PFNGLGETPERFQUERYINFOINTELPROC)wglGetProcAddress("glGetPerfQueryInfoINTEL");
	glFramebufferParameteriMESAproc = (PFNGLFRAMEBUFFERPARAMETERIMESAPROC)wglGetProcAddress("glFramebufferParameteriMESA");
	glGetFramebufferParameterivMESAproc = (PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC)wglGetProcAddress("glGetFramebufferParameterivMESA");
	glResizeBuffersMESAproc = (PFNGLRESIZEBUFFERSMESAPROC)wglGetProcAddress("glResizeBuffersMESA");
	glWindowPos2dMESAproc = (PFNGLWINDOWPOS2DMESAPROC)wglGetProcAddress("glWindowPos2dMESA");
	glWindowPos2dvMESAproc = (PFNGLWINDOWPOS2DVMESAPROC)wglGetProcAddress("glWindowPos2dvMESA");
	glWindowPos2fMESAproc = (PFNGLWINDOWPOS2FMESAPROC)wglGetProcAddress("glWindowPos2fMESA");
	glWindowPos2fvMESAproc = (PFNGLWINDOWPOS2FVMESAPROC)wglGetProcAddress("glWindowPos2fvMESA");
	glWindowPos2iMESAproc = (PFNGLWINDOWPOS2IMESAPROC)wglGetProcAddress("glWindowPos2iMESA");
	glWindowPos2ivMESAproc = (PFNGLWINDOWPOS2IVMESAPROC)wglGetProcAddress("glWindowPos2ivMESA");
	glWindowPos2sMESAproc = (PFNGLWINDOWPOS2SMESAPROC)wglGetProcAddress("glWindowPos2sMESA");
	glWindowPos2svMESAproc = (PFNGLWINDOWPOS2SVMESAPROC)wglGetProcAddress("glWindowPos2svMESA");
	glWindowPos3dMESAproc = (PFNGLWINDOWPOS3DMESAPROC)wglGetProcAddress("glWindowPos3dMESA");
	glWindowPos3dvMESAproc = (PFNGLWINDOWPOS3DVMESAPROC)wglGetProcAddress("glWindowPos3dvMESA");
	glWindowPos3fMESAproc = (PFNGLWINDOWPOS3FMESAPROC)wglGetProcAddress("glWindowPos3fMESA");
	glWindowPos3fvMESAproc = (PFNGLWINDOWPOS3FVMESAPROC)wglGetProcAddress("glWindowPos3fvMESA");
	glWindowPos3iMESAproc = (PFNGLWINDOWPOS3IMESAPROC)wglGetProcAddress("glWindowPos3iMESA");
	glWindowPos3ivMESAproc = (PFNGLWINDOWPOS3IVMESAPROC)wglGetProcAddress("glWindowPos3ivMESA");
	glWindowPos3sMESAproc = (PFNGLWINDOWPOS3SMESAPROC)wglGetProcAddress("glWindowPos3sMESA");
	glWindowPos3svMESAproc = (PFNGLWINDOWPOS3SVMESAPROC)wglGetProcAddress("glWindowPos3svMESA");
	glWindowPos4dMESAproc = (PFNGLWINDOWPOS4DMESAPROC)wglGetProcAddress("glWindowPos4dMESA");
	glWindowPos4dvMESAproc = (PFNGLWINDOWPOS4DVMESAPROC)wglGetProcAddress("glWindowPos4dvMESA");
	glWindowPos4fMESAproc = (PFNGLWINDOWPOS4FMESAPROC)wglGetProcAddress("glWindowPos4fMESA");
	glWindowPos4fvMESAproc = (PFNGLWINDOWPOS4FVMESAPROC)wglGetProcAddress("glWindowPos4fvMESA");
	glWindowPos4iMESAproc = (PFNGLWINDOWPOS4IMESAPROC)wglGetProcAddress("glWindowPos4iMESA");
	glWindowPos4ivMESAproc = (PFNGLWINDOWPOS4IVMESAPROC)wglGetProcAddress("glWindowPos4ivMESA");
	glWindowPos4sMESAproc = (PFNGLWINDOWPOS4SMESAPROC)wglGetProcAddress("glWindowPos4sMESA");
	glWindowPos4svMESAproc = (PFNGLWINDOWPOS4SVMESAPROC)wglGetProcAddress("glWindowPos4svMESA");
	glBeginConditionalRenderNVXproc = (PFNGLBEGINCONDITIONALRENDERNVXPROC)wglGetProcAddress("glBeginConditionalRenderNVX");
	glEndConditionalRenderNVXproc = (PFNGLENDCONDITIONALRENDERNVXPROC)wglGetProcAddress("glEndConditionalRenderNVX");
	glUploadGpuMaskNVXproc = (PFNGLUPLOADGPUMASKNVXPROC)wglGetProcAddress("glUploadGpuMaskNVX");
	glMulticastViewportArrayvNVXproc = (PFNGLMULTICASTVIEWPORTARRAYVNVXPROC)wglGetProcAddress("glMulticastViewportArrayvNVX");
	glMulticastViewportPositionWScaleNVXproc = (PFNGLMULTICASTVIEWPORTPOSITIONWSCALENVXPROC)wglGetProcAddress("glMulticastViewportPositionWScaleNVX");
	glMulticastScissorArrayvNVXproc = (PFNGLMULTICASTSCISSORARRAYVNVXPROC)wglGetProcAddress("glMulticastScissorArrayvNVX");
	glAsyncCopyBufferSubDataNVXproc = (PFNGLASYNCCOPYBUFFERSUBDATANVXPROC)wglGetProcAddress("glAsyncCopyBufferSubDataNVX");
	glAsyncCopyImageSubDataNVXproc = (PFNGLASYNCCOPYIMAGESUBDATANVXPROC)wglGetProcAddress("glAsyncCopyImageSubDataNVX");
	glLGPUNamedBufferSubDataNVXproc = (PFNGLLGPUNAMEDBUFFERSUBDATANVXPROC)wglGetProcAddress("glLGPUNamedBufferSubDataNVX");
	glLGPUCopyImageSubDataNVXproc = (PFNGLLGPUCOPYIMAGESUBDATANVXPROC)wglGetProcAddress("glLGPUCopyImageSubDataNVX");
	glLGPUInterlockNVXproc = (PFNGLLGPUINTERLOCKNVXPROC)wglGetProcAddress("glLGPUInterlockNVX");
	glCreateProgressFenceNVXproc = (PFNGLCREATEPROGRESSFENCENVXPROC)wglGetProcAddress("glCreateProgressFenceNVX");
	glSignalSemaphoreui64NVXproc = (PFNGLSIGNALSEMAPHOREUI64NVXPROC)wglGetProcAddress("glSignalSemaphoreui64NVX");
	glWaitSemaphoreui64NVXproc = (PFNGLWAITSEMAPHOREUI64NVXPROC)wglGetProcAddress("glWaitSemaphoreui64NVX");
	glClientWaitSemaphoreui64NVXproc = (PFNGLCLIENTWAITSEMAPHOREUI64NVXPROC)wglGetProcAddress("glClientWaitSemaphoreui64NVX");
	glAlphaToCoverageDitherControlNVproc = (PFNGLALPHATOCOVERAGEDITHERCONTROLNVPROC)wglGetProcAddress("glAlphaToCoverageDitherControlNV");
	glMultiDrawArraysIndirectBindlessNVproc = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)wglGetProcAddress("glMultiDrawArraysIndirectBindlessNV");
	glMultiDrawElementsIndirectBindlessNVproc = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)wglGetProcAddress("glMultiDrawElementsIndirectBindlessNV");
	glMultiDrawArraysIndirectBindlessCountNVproc = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)wglGetProcAddress("glMultiDrawArraysIndirectBindlessCountNV");
	glMultiDrawElementsIndirectBindlessCountNVproc = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)wglGetProcAddress("glMultiDrawElementsIndirectBindlessCountNV");
	glGetTextureHandleNVproc = (PFNGLGETTEXTUREHANDLENVPROC)wglGetProcAddress("glGetTextureHandleNV");
	glGetTextureSamplerHandleNVproc = (PFNGLGETTEXTURESAMPLERHANDLENVPROC)wglGetProcAddress("glGetTextureSamplerHandleNV");
	glMakeTextureHandleResidentNVproc = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)wglGetProcAddress("glMakeTextureHandleResidentNV");
	glMakeTextureHandleNonResidentNVproc = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)wglGetProcAddress("glMakeTextureHandleNonResidentNV");
	glGetImageHandleNVproc = (PFNGLGETIMAGEHANDLENVPROC)wglGetProcAddress("glGetImageHandleNV");
	glMakeImageHandleResidentNVproc = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)wglGetProcAddress("glMakeImageHandleResidentNV");
	glMakeImageHandleNonResidentNVproc = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)wglGetProcAddress("glMakeImageHandleNonResidentNV");
	glUniformHandleui64NVproc = (PFNGLUNIFORMHANDLEUI64NVPROC)wglGetProcAddress("glUniformHandleui64NV");
	glUniformHandleui64vNVproc = (PFNGLUNIFORMHANDLEUI64VNVPROC)wglGetProcAddress("glUniformHandleui64vNV");
	glProgramUniformHandleui64NVproc = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)wglGetProcAddress("glProgramUniformHandleui64NV");
	glProgramUniformHandleui64vNVproc = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)wglGetProcAddress("glProgramUniformHandleui64vNV");
	glIsTextureHandleResidentNVproc = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)wglGetProcAddress("glIsTextureHandleResidentNV");
	glIsImageHandleResidentNVproc = (PFNGLISIMAGEHANDLERESIDENTNVPROC)wglGetProcAddress("glIsImageHandleResidentNV");
	glBlendParameteriNVproc = (PFNGLBLENDPARAMETERINVPROC)wglGetProcAddress("glBlendParameteriNV");
	glBlendBarrierNVproc = (PFNGLBLENDBARRIERNVPROC)wglGetProcAddress("glBlendBarrierNV");
	glViewportPositionWScaleNVproc = (PFNGLVIEWPORTPOSITIONWSCALENVPROC)wglGetProcAddress("glViewportPositionWScaleNV");
	glCreateStatesNVproc = (PFNGLCREATESTATESNVPROC)wglGetProcAddress("glCreateStatesNV");
	glDeleteStatesNVproc = (PFNGLDELETESTATESNVPROC)wglGetProcAddress("glDeleteStatesNV");
	glIsStateNVproc = (PFNGLISSTATENVPROC)wglGetProcAddress("glIsStateNV");
	glStateCaptureNVproc = (PFNGLSTATECAPTURENVPROC)wglGetProcAddress("glStateCaptureNV");
	glGetCommandHeaderNVproc = (PFNGLGETCOMMANDHEADERNVPROC)wglGetProcAddress("glGetCommandHeaderNV");
	glGetStageIndexNVproc = (PFNGLGETSTAGEINDEXNVPROC)wglGetProcAddress("glGetStageIndexNV");
	glDrawCommandsNVproc = (PFNGLDRAWCOMMANDSNVPROC)wglGetProcAddress("glDrawCommandsNV");
	glDrawCommandsAddressNVproc = (PFNGLDRAWCOMMANDSADDRESSNVPROC)wglGetProcAddress("glDrawCommandsAddressNV");
	glDrawCommandsStatesNVproc = (PFNGLDRAWCOMMANDSSTATESNVPROC)wglGetProcAddress("glDrawCommandsStatesNV");
	glDrawCommandsStatesAddressNVproc = (PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)wglGetProcAddress("glDrawCommandsStatesAddressNV");
	glCreateCommandListsNVproc = (PFNGLCREATECOMMANDLISTSNVPROC)wglGetProcAddress("glCreateCommandListsNV");
	glDeleteCommandListsNVproc = (PFNGLDELETECOMMANDLISTSNVPROC)wglGetProcAddress("glDeleteCommandListsNV");
	glIsCommandListNVproc = (PFNGLISCOMMANDLISTNVPROC)wglGetProcAddress("glIsCommandListNV");
	glListDrawCommandsStatesClientNVproc = (PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)wglGetProcAddress("glListDrawCommandsStatesClientNV");
	glCommandListSegmentsNVproc = (PFNGLCOMMANDLISTSEGMENTSNVPROC)wglGetProcAddress("glCommandListSegmentsNV");
	glCompileCommandListNVproc = (PFNGLCOMPILECOMMANDLISTNVPROC)wglGetProcAddress("glCompileCommandListNV");
	glCallCommandListNVproc = (PFNGLCALLCOMMANDLISTNVPROC)wglGetProcAddress("glCallCommandListNV");
	glBeginConditionalRenderNVproc = (PFNGLBEGINCONDITIONALRENDERNVPROC)wglGetProcAddress("glBeginConditionalRenderNV");
	glEndConditionalRenderNVproc = (PFNGLENDCONDITIONALRENDERNVPROC)wglGetProcAddress("glEndConditionalRenderNV");
	glSubpixelPrecisionBiasNVproc = (PFNGLSUBPIXELPRECISIONBIASNVPROC)wglGetProcAddress("glSubpixelPrecisionBiasNV");
	glConservativeRasterParameterfNVproc = (PFNGLCONSERVATIVERASTERPARAMETERFNVPROC)wglGetProcAddress("glConservativeRasterParameterfNV");
	glConservativeRasterParameteriNVproc = (PFNGLCONSERVATIVERASTERPARAMETERINVPROC)wglGetProcAddress("glConservativeRasterParameteriNV");
	glCopyImageSubDataNVproc = (PFNGLCOPYIMAGESUBDATANVPROC)wglGetProcAddress("glCopyImageSubDataNV");
	glDepthRangedNVproc = (PFNGLDEPTHRANGEDNVPROC)wglGetProcAddress("glDepthRangedNV");
	glClearDepthdNVproc = (PFNGLCLEARDEPTHDNVPROC)wglGetProcAddress("glClearDepthdNV");
	glDepthBoundsdNVproc = (PFNGLDEPTHBOUNDSDNVPROC)wglGetProcAddress("glDepthBoundsdNV");
	glDrawTextureNVproc = (PFNGLDRAWTEXTURENVPROC)wglGetProcAddress("glDrawTextureNV");
	glDrawVkImageNVproc = (PFNGLDRAWVKIMAGENVPROC)wglGetProcAddress("glDrawVkImageNV");
	glGetVkProcAddrNVproc = (PFNGLGETVKPROCADDRNVPROC)wglGetProcAddress("glGetVkProcAddrNV");
	glWaitVkSemaphoreNVproc = (PFNGLWAITVKSEMAPHORENVPROC)wglGetProcAddress("glWaitVkSemaphoreNV");
	glSignalVkSemaphoreNVproc = (PFNGLSIGNALVKSEMAPHORENVPROC)wglGetProcAddress("glSignalVkSemaphoreNV");
	glSignalVkFenceNVproc = (PFNGLSIGNALVKFENCENVPROC)wglGetProcAddress("glSignalVkFenceNV");
	glMapControlPointsNVproc = (PFNGLMAPCONTROLPOINTSNVPROC)wglGetProcAddress("glMapControlPointsNV");
	glMapParameterivNVproc = (PFNGLMAPPARAMETERIVNVPROC)wglGetProcAddress("glMapParameterivNV");
	glMapParameterfvNVproc = (PFNGLMAPPARAMETERFVNVPROC)wglGetProcAddress("glMapParameterfvNV");
	glGetMapControlPointsNVproc = (PFNGLGETMAPCONTROLPOINTSNVPROC)wglGetProcAddress("glGetMapControlPointsNV");
	glGetMapParameterivNVproc = (PFNGLGETMAPPARAMETERIVNVPROC)wglGetProcAddress("glGetMapParameterivNV");
	glGetMapParameterfvNVproc = (PFNGLGETMAPPARAMETERFVNVPROC)wglGetProcAddress("glGetMapParameterfvNV");
	glGetMapAttribParameterivNVproc = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC)wglGetProcAddress("glGetMapAttribParameterivNV");
	glGetMapAttribParameterfvNVproc = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC)wglGetProcAddress("glGetMapAttribParameterfvNV");
	glEvalMapsNVproc = (PFNGLEVALMAPSNVPROC)wglGetProcAddress("glEvalMapsNV");
	glGetMultisamplefvNVproc = (PFNGLGETMULTISAMPLEFVNVPROC)wglGetProcAddress("glGetMultisamplefvNV");
	glSampleMaskIndexedNVproc = (PFNGLSAMPLEMASKINDEXEDNVPROC)wglGetProcAddress("glSampleMaskIndexedNV");
	glTexRenderbufferNVproc = (PFNGLTEXRENDERBUFFERNVPROC)wglGetProcAddress("glTexRenderbufferNV");
	glDeleteFencesNVproc = (PFNGLDELETEFENCESNVPROC)wglGetProcAddress("glDeleteFencesNV");
	glGenFencesNVproc = (PFNGLGENFENCESNVPROC)wglGetProcAddress("glGenFencesNV");
	glIsFenceNVproc = (PFNGLISFENCENVPROC)wglGetProcAddress("glIsFenceNV");
	glTestFenceNVproc = (PFNGLTESTFENCENVPROC)wglGetProcAddress("glTestFenceNV");
	glGetFenceivNVproc = (PFNGLGETFENCEIVNVPROC)wglGetProcAddress("glGetFenceivNV");
	glFinishFenceNVproc = (PFNGLFINISHFENCENVPROC)wglGetProcAddress("glFinishFenceNV");
	glSetFenceNVproc = (PFNGLSETFENCENVPROC)wglGetProcAddress("glSetFenceNV");
	glFragmentCoverageColorNVproc = (PFNGLFRAGMENTCOVERAGECOLORNVPROC)wglGetProcAddress("glFragmentCoverageColorNV");
	glProgramNamedParameter4fNVproc = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)wglGetProcAddress("glProgramNamedParameter4fNV");
	glProgramNamedParameter4fvNVproc = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)wglGetProcAddress("glProgramNamedParameter4fvNV");
	glProgramNamedParameter4dNVproc = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)wglGetProcAddress("glProgramNamedParameter4dNV");
	glProgramNamedParameter4dvNVproc = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)wglGetProcAddress("glProgramNamedParameter4dvNV");
	glGetProgramNamedParameterfvNVproc = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)wglGetProcAddress("glGetProgramNamedParameterfvNV");
	glGetProgramNamedParameterdvNVproc = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)wglGetProcAddress("glGetProgramNamedParameterdvNV");
	glCoverageModulationTableNVproc = (PFNGLCOVERAGEMODULATIONTABLENVPROC)wglGetProcAddress("glCoverageModulationTableNV");
	glGetCoverageModulationTableNVproc = (PFNGLGETCOVERAGEMODULATIONTABLENVPROC)wglGetProcAddress("glGetCoverageModulationTableNV");
	glCoverageModulationNVproc = (PFNGLCOVERAGEMODULATIONNVPROC)wglGetProcAddress("glCoverageModulationNV");
	glRenderbufferStorageMultisampleCoverageNVproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glRenderbufferStorageMultisampleCoverageNV");
	glProgramVertexLimitNVproc = (PFNGLPROGRAMVERTEXLIMITNVPROC)wglGetProcAddress("glProgramVertexLimitNV");
	glFramebufferTextureEXTproc = (PFNGLFRAMEBUFFERTEXTUREEXTPROC)wglGetProcAddress("glFramebufferTextureEXT");
	glFramebufferTextureFaceEXTproc = (PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)wglGetProcAddress("glFramebufferTextureFaceEXT");
	glRenderGpuMaskNVproc = (PFNGLRENDERGPUMASKNVPROC)wglGetProcAddress("glRenderGpuMaskNV");
	glMulticastBufferSubDataNVproc = (PFNGLMULTICASTBUFFERSUBDATANVPROC)wglGetProcAddress("glMulticastBufferSubDataNV");
	glMulticastCopyBufferSubDataNVproc = (PFNGLMULTICASTCOPYBUFFERSUBDATANVPROC)wglGetProcAddress("glMulticastCopyBufferSubDataNV");
	glMulticastCopyImageSubDataNVproc = (PFNGLMULTICASTCOPYIMAGESUBDATANVPROC)wglGetProcAddress("glMulticastCopyImageSubDataNV");
	glMulticastBlitFramebufferNVproc = (PFNGLMULTICASTBLITFRAMEBUFFERNVPROC)wglGetProcAddress("glMulticastBlitFramebufferNV");
	glMulticastFramebufferSampleLocationsfvNVproc = (PFNGLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)wglGetProcAddress("glMulticastFramebufferSampleLocationsfvNV");
	glMulticastBarrierNVproc = (PFNGLMULTICASTBARRIERNVPROC)wglGetProcAddress("glMulticastBarrierNV");
	glMulticastWaitSyncNVproc = (PFNGLMULTICASTWAITSYNCNVPROC)wglGetProcAddress("glMulticastWaitSyncNV");
	glMulticastGetQueryObjectivNVproc = (PFNGLMULTICASTGETQUERYOBJECTIVNVPROC)wglGetProcAddress("glMulticastGetQueryObjectivNV");
	glMulticastGetQueryObjectuivNVproc = (PFNGLMULTICASTGETQUERYOBJECTUIVNVPROC)wglGetProcAddress("glMulticastGetQueryObjectuivNV");
	glMulticastGetQueryObjecti64vNVproc = (PFNGLMULTICASTGETQUERYOBJECTI64VNVPROC)wglGetProcAddress("glMulticastGetQueryObjecti64vNV");
	glMulticastGetQueryObjectui64vNVproc = (PFNGLMULTICASTGETQUERYOBJECTUI64VNVPROC)wglGetProcAddress("glMulticastGetQueryObjectui64vNV");
	glProgramLocalParameterI4iNVproc = (PFNGLPROGRAMLOCALPARAMETERI4INVPROC)wglGetProcAddress("glProgramLocalParameterI4iNV");
	glProgramLocalParameterI4ivNVproc = (PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)wglGetProcAddress("glProgramLocalParameterI4ivNV");
	glProgramLocalParametersI4ivNVproc = (PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)wglGetProcAddress("glProgramLocalParametersI4ivNV");
	glProgramLocalParameterI4uiNVproc = (PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)wglGetProcAddress("glProgramLocalParameterI4uiNV");
	glProgramLocalParameterI4uivNVproc = (PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)wglGetProcAddress("glProgramLocalParameterI4uivNV");
	glProgramLocalParametersI4uivNVproc = (PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)wglGetProcAddress("glProgramLocalParametersI4uivNV");
	glProgramEnvParameterI4iNVproc = (PFNGLPROGRAMENVPARAMETERI4INVPROC)wglGetProcAddress("glProgramEnvParameterI4iNV");
	glProgramEnvParameterI4ivNVproc = (PFNGLPROGRAMENVPARAMETERI4IVNVPROC)wglGetProcAddress("glProgramEnvParameterI4ivNV");
	glProgramEnvParametersI4ivNVproc = (PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)wglGetProcAddress("glProgramEnvParametersI4ivNV");
	glProgramEnvParameterI4uiNVproc = (PFNGLPROGRAMENVPARAMETERI4UINVPROC)wglGetProcAddress("glProgramEnvParameterI4uiNV");
	glProgramEnvParameterI4uivNVproc = (PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)wglGetProcAddress("glProgramEnvParameterI4uivNV");
	glProgramEnvParametersI4uivNVproc = (PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)wglGetProcAddress("glProgramEnvParametersI4uivNV");
	glGetProgramLocalParameterIivNVproc = (PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)wglGetProcAddress("glGetProgramLocalParameterIivNV");
	glGetProgramLocalParameterIuivNVproc = (PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)wglGetProcAddress("glGetProgramLocalParameterIuivNV");
	glGetProgramEnvParameterIivNVproc = (PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)wglGetProcAddress("glGetProgramEnvParameterIivNV");
	glGetProgramEnvParameterIuivNVproc = (PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)wglGetProcAddress("glGetProgramEnvParameterIuivNV");
	glProgramSubroutineParametersuivNVproc = (PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)wglGetProcAddress("glProgramSubroutineParametersuivNV");
	glGetProgramSubroutineParameteruivNVproc = (PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)wglGetProcAddress("glGetProgramSubroutineParameteruivNV");
	glVertex2hNVproc = (PFNGLVERTEX2HNVPROC)wglGetProcAddress("glVertex2hNV");
	glVertex2hvNVproc = (PFNGLVERTEX2HVNVPROC)wglGetProcAddress("glVertex2hvNV");
	glVertex3hNVproc = (PFNGLVERTEX3HNVPROC)wglGetProcAddress("glVertex3hNV");
	glVertex3hvNVproc = (PFNGLVERTEX3HVNVPROC)wglGetProcAddress("glVertex3hvNV");
	glVertex4hNVproc = (PFNGLVERTEX4HNVPROC)wglGetProcAddress("glVertex4hNV");
	glVertex4hvNVproc = (PFNGLVERTEX4HVNVPROC)wglGetProcAddress("glVertex4hvNV");
	glNormal3hNVproc = (PFNGLNORMAL3HNVPROC)wglGetProcAddress("glNormal3hNV");
	glNormal3hvNVproc = (PFNGLNORMAL3HVNVPROC)wglGetProcAddress("glNormal3hvNV");
	glColor3hNVproc = (PFNGLCOLOR3HNVPROC)wglGetProcAddress("glColor3hNV");
	glColor3hvNVproc = (PFNGLCOLOR3HVNVPROC)wglGetProcAddress("glColor3hvNV");
	glColor4hNVproc = (PFNGLCOLOR4HNVPROC)wglGetProcAddress("glColor4hNV");
	glColor4hvNVproc = (PFNGLCOLOR4HVNVPROC)wglGetProcAddress("glColor4hvNV");
	glTexCoord1hNVproc = (PFNGLTEXCOORD1HNVPROC)wglGetProcAddress("glTexCoord1hNV");
	glTexCoord1hvNVproc = (PFNGLTEXCOORD1HVNVPROC)wglGetProcAddress("glTexCoord1hvNV");
	glTexCoord2hNVproc = (PFNGLTEXCOORD2HNVPROC)wglGetProcAddress("glTexCoord2hNV");
	glTexCoord2hvNVproc = (PFNGLTEXCOORD2HVNVPROC)wglGetProcAddress("glTexCoord2hvNV");
	glTexCoord3hNVproc = (PFNGLTEXCOORD3HNVPROC)wglGetProcAddress("glTexCoord3hNV");
	glTexCoord3hvNVproc = (PFNGLTEXCOORD3HVNVPROC)wglGetProcAddress("glTexCoord3hvNV");
	glTexCoord4hNVproc = (PFNGLTEXCOORD4HNVPROC)wglGetProcAddress("glTexCoord4hNV");
	glTexCoord4hvNVproc = (PFNGLTEXCOORD4HVNVPROC)wglGetProcAddress("glTexCoord4hvNV");
	glMultiTexCoord1hNVproc = (PFNGLMULTITEXCOORD1HNVPROC)wglGetProcAddress("glMultiTexCoord1hNV");
	glMultiTexCoord1hvNVproc = (PFNGLMULTITEXCOORD1HVNVPROC)wglGetProcAddress("glMultiTexCoord1hvNV");
	glMultiTexCoord2hNVproc = (PFNGLMULTITEXCOORD2HNVPROC)wglGetProcAddress("glMultiTexCoord2hNV");
	glMultiTexCoord2hvNVproc = (PFNGLMULTITEXCOORD2HVNVPROC)wglGetProcAddress("glMultiTexCoord2hvNV");
	glMultiTexCoord3hNVproc = (PFNGLMULTITEXCOORD3HNVPROC)wglGetProcAddress("glMultiTexCoord3hNV");
	glMultiTexCoord3hvNVproc = (PFNGLMULTITEXCOORD3HVNVPROC)wglGetProcAddress("glMultiTexCoord3hvNV");
	glMultiTexCoord4hNVproc = (PFNGLMULTITEXCOORD4HNVPROC)wglGetProcAddress("glMultiTexCoord4hNV");
	glMultiTexCoord4hvNVproc = (PFNGLMULTITEXCOORD4HVNVPROC)wglGetProcAddress("glMultiTexCoord4hvNV");
	glVertexAttrib1hNVproc = (PFNGLVERTEXATTRIB1HNVPROC)wglGetProcAddress("glVertexAttrib1hNV");
	glVertexAttrib1hvNVproc = (PFNGLVERTEXATTRIB1HVNVPROC)wglGetProcAddress("glVertexAttrib1hvNV");
	glVertexAttrib2hNVproc = (PFNGLVERTEXATTRIB2HNVPROC)wglGetProcAddress("glVertexAttrib2hNV");
	glVertexAttrib2hvNVproc = (PFNGLVERTEXATTRIB2HVNVPROC)wglGetProcAddress("glVertexAttrib2hvNV");
	glVertexAttrib3hNVproc = (PFNGLVERTEXATTRIB3HNVPROC)wglGetProcAddress("glVertexAttrib3hNV");
	glVertexAttrib3hvNVproc = (PFNGLVERTEXATTRIB3HVNVPROC)wglGetProcAddress("glVertexAttrib3hvNV");
	glVertexAttrib4hNVproc = (PFNGLVERTEXATTRIB4HNVPROC)wglGetProcAddress("glVertexAttrib4hNV");
	glVertexAttrib4hvNVproc = (PFNGLVERTEXATTRIB4HVNVPROC)wglGetProcAddress("glVertexAttrib4hvNV");
	glVertexAttribs1hvNVproc = (PFNGLVERTEXATTRIBS1HVNVPROC)wglGetProcAddress("glVertexAttribs1hvNV");
	glVertexAttribs2hvNVproc = (PFNGLVERTEXATTRIBS2HVNVPROC)wglGetProcAddress("glVertexAttribs2hvNV");
	glVertexAttribs3hvNVproc = (PFNGLVERTEXATTRIBS3HVNVPROC)wglGetProcAddress("glVertexAttribs3hvNV");
	glVertexAttribs4hvNVproc = (PFNGLVERTEXATTRIBS4HVNVPROC)wglGetProcAddress("glVertexAttribs4hvNV");
	glFogCoordhNVproc = (PFNGLFOGCOORDHNVPROC)wglGetProcAddress("glFogCoordhNV");
	glFogCoordhvNVproc = (PFNGLFOGCOORDHVNVPROC)wglGetProcAddress("glFogCoordhvNV");
	glSecondaryColor3hNVproc = (PFNGLSECONDARYCOLOR3HNVPROC)wglGetProcAddress("glSecondaryColor3hNV");
	glSecondaryColor3hvNVproc = (PFNGLSECONDARYCOLOR3HVNVPROC)wglGetProcAddress("glSecondaryColor3hvNV");
	glVertexWeighthNVproc = (PFNGLVERTEXWEIGHTHNVPROC)wglGetProcAddress("glVertexWeighthNV");
	glVertexWeighthvNVproc = (PFNGLVERTEXWEIGHTHVNVPROC)wglGetProcAddress("glVertexWeighthvNV");
	glGetInternalformatSampleivNVproc = (PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)wglGetProcAddress("glGetInternalformatSampleivNV");
	glGetMemoryObjectDetachedResourcesuivNVproc = (PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC)wglGetProcAddress("glGetMemoryObjectDetachedResourcesuivNV");
	glResetMemoryObjectParameterNVproc = (PFNGLRESETMEMORYOBJECTPARAMETERNVPROC)wglGetProcAddress("glResetMemoryObjectParameterNV");
	glTexAttachMemoryNVproc = (PFNGLTEXATTACHMEMORYNVPROC)wglGetProcAddress("glTexAttachMemoryNV");
	glBufferAttachMemoryNVproc = (PFNGLBUFFERATTACHMEMORYNVPROC)wglGetProcAddress("glBufferAttachMemoryNV");
	glTextureAttachMemoryNVproc = (PFNGLTEXTUREATTACHMEMORYNVPROC)wglGetProcAddress("glTextureAttachMemoryNV");
	glNamedBufferAttachMemoryNVproc = (PFNGLNAMEDBUFFERATTACHMEMORYNVPROC)wglGetProcAddress("glNamedBufferAttachMemoryNV");
	glBufferPageCommitmentMemNVproc = (PFNGLBUFFERPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glBufferPageCommitmentMemNV");
	glTexPageCommitmentMemNVproc = (PFNGLTEXPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glTexPageCommitmentMemNV");
	glNamedBufferPageCommitmentMemNVproc = (PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glNamedBufferPageCommitmentMemNV");
	glTexturePageCommitmentMemNVproc = (PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glTexturePageCommitmentMemNV");
	glDrawMeshTasksNVproc = (PFNGLDRAWMESHTASKSNVPROC)wglGetProcAddress("glDrawMeshTasksNV");
	glDrawMeshTasksIndirectNVproc = (PFNGLDRAWMESHTASKSINDIRECTNVPROC)wglGetProcAddress("glDrawMeshTasksIndirectNV");
	glMultiDrawMeshTasksIndirectNVproc = (PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC)wglGetProcAddress("glMultiDrawMeshTasksIndirectNV");
	glMultiDrawMeshTasksIndirectCountNVproc = (PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC)wglGetProcAddress("glMultiDrawMeshTasksIndirectCountNV");
	glGenOcclusionQueriesNVproc = (PFNGLGENOCCLUSIONQUERIESNVPROC)wglGetProcAddress("glGenOcclusionQueriesNV");
	glDeleteOcclusionQueriesNVproc = (PFNGLDELETEOCCLUSIONQUERIESNVPROC)wglGetProcAddress("glDeleteOcclusionQueriesNV");
	glIsOcclusionQueryNVproc = (PFNGLISOCCLUSIONQUERYNVPROC)wglGetProcAddress("glIsOcclusionQueryNV");
	glBeginOcclusionQueryNVproc = (PFNGLBEGINOCCLUSIONQUERYNVPROC)wglGetProcAddress("glBeginOcclusionQueryNV");
	glEndOcclusionQueryNVproc = (PFNGLENDOCCLUSIONQUERYNVPROC)wglGetProcAddress("glEndOcclusionQueryNV");
	glGetOcclusionQueryivNVproc = (PFNGLGETOCCLUSIONQUERYIVNVPROC)wglGetProcAddress("glGetOcclusionQueryivNV");
	glGetOcclusionQueryuivNVproc = (PFNGLGETOCCLUSIONQUERYUIVNVPROC)wglGetProcAddress("glGetOcclusionQueryuivNV");
	glProgramBufferParametersfvNVproc = (PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)wglGetProcAddress("glProgramBufferParametersfvNV");
	glProgramBufferParametersIivNVproc = (PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)wglGetProcAddress("glProgramBufferParametersIivNV");
	glProgramBufferParametersIuivNVproc = (PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)wglGetProcAddress("glProgramBufferParametersIuivNV");
	glGenPathsNVproc = (PFNGLGENPATHSNVPROC)wglGetProcAddress("glGenPathsNV");
	glDeletePathsNVproc = (PFNGLDELETEPATHSNVPROC)wglGetProcAddress("glDeletePathsNV");
	glIsPathNVproc = (PFNGLISPATHNVPROC)wglGetProcAddress("glIsPathNV");
	glPathCommandsNVproc = (PFNGLPATHCOMMANDSNVPROC)wglGetProcAddress("glPathCommandsNV");
	glPathCoordsNVproc = (PFNGLPATHCOORDSNVPROC)wglGetProcAddress("glPathCoordsNV");
	glPathSubCommandsNVproc = (PFNGLPATHSUBCOMMANDSNVPROC)wglGetProcAddress("glPathSubCommandsNV");
	glPathSubCoordsNVproc = (PFNGLPATHSUBCOORDSNVPROC)wglGetProcAddress("glPathSubCoordsNV");
	glPathStringNVproc = (PFNGLPATHSTRINGNVPROC)wglGetProcAddress("glPathStringNV");
	glPathGlyphsNVproc = (PFNGLPATHGLYPHSNVPROC)wglGetProcAddress("glPathGlyphsNV");
	glPathGlyphRangeNVproc = (PFNGLPATHGLYPHRANGENVPROC)wglGetProcAddress("glPathGlyphRangeNV");
	glWeightPathsNVproc = (PFNGLWEIGHTPATHSNVPROC)wglGetProcAddress("glWeightPathsNV");
	glCopyPathNVproc = (PFNGLCOPYPATHNVPROC)wglGetProcAddress("glCopyPathNV");
	glInterpolatePathsNVproc = (PFNGLINTERPOLATEPATHSNVPROC)wglGetProcAddress("glInterpolatePathsNV");
	glTransformPathNVproc = (PFNGLTRANSFORMPATHNVPROC)wglGetProcAddress("glTransformPathNV");
	glPathParameterivNVproc = (PFNGLPATHPARAMETERIVNVPROC)wglGetProcAddress("glPathParameterivNV");
	glPathParameteriNVproc = (PFNGLPATHPARAMETERINVPROC)wglGetProcAddress("glPathParameteriNV");
	glPathParameterfvNVproc = (PFNGLPATHPARAMETERFVNVPROC)wglGetProcAddress("glPathParameterfvNV");
	glPathParameterfNVproc = (PFNGLPATHPARAMETERFNVPROC)wglGetProcAddress("glPathParameterfNV");
	glPathDashArrayNVproc = (PFNGLPATHDASHARRAYNVPROC)wglGetProcAddress("glPathDashArrayNV");
	glPathStencilFuncNVproc = (PFNGLPATHSTENCILFUNCNVPROC)wglGetProcAddress("glPathStencilFuncNV");
	glPathStencilDepthOffsetNVproc = (PFNGLPATHSTENCILDEPTHOFFSETNVPROC)wglGetProcAddress("glPathStencilDepthOffsetNV");
	glStencilFillPathNVproc = (PFNGLSTENCILFILLPATHNVPROC)wglGetProcAddress("glStencilFillPathNV");
	glStencilStrokePathNVproc = (PFNGLSTENCILSTROKEPATHNVPROC)wglGetProcAddress("glStencilStrokePathNV");
	glStencilFillPathInstancedNVproc = (PFNGLSTENCILFILLPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilFillPathInstancedNV");
	glStencilStrokePathInstancedNVproc = (PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilStrokePathInstancedNV");
	glPathCoverDepthFuncNVproc = (PFNGLPATHCOVERDEPTHFUNCNVPROC)wglGetProcAddress("glPathCoverDepthFuncNV");
	glCoverFillPathNVproc = (PFNGLCOVERFILLPATHNVPROC)wglGetProcAddress("glCoverFillPathNV");
	glCoverStrokePathNVproc = (PFNGLCOVERSTROKEPATHNVPROC)wglGetProcAddress("glCoverStrokePathNV");
	glCoverFillPathInstancedNVproc = (PFNGLCOVERFILLPATHINSTANCEDNVPROC)wglGetProcAddress("glCoverFillPathInstancedNV");
	glCoverStrokePathInstancedNVproc = (PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)wglGetProcAddress("glCoverStrokePathInstancedNV");
	glGetPathParameterivNVproc = (PFNGLGETPATHPARAMETERIVNVPROC)wglGetProcAddress("glGetPathParameterivNV");
	glGetPathParameterfvNVproc = (PFNGLGETPATHPARAMETERFVNVPROC)wglGetProcAddress("glGetPathParameterfvNV");
	glGetPathCommandsNVproc = (PFNGLGETPATHCOMMANDSNVPROC)wglGetProcAddress("glGetPathCommandsNV");
	glGetPathCoordsNVproc = (PFNGLGETPATHCOORDSNVPROC)wglGetProcAddress("glGetPathCoordsNV");
	glGetPathDashArrayNVproc = (PFNGLGETPATHDASHARRAYNVPROC)wglGetProcAddress("glGetPathDashArrayNV");
	glGetPathMetricsNVproc = (PFNGLGETPATHMETRICSNVPROC)wglGetProcAddress("glGetPathMetricsNV");
	glGetPathMetricRangeNVproc = (PFNGLGETPATHMETRICRANGENVPROC)wglGetProcAddress("glGetPathMetricRangeNV");
	glGetPathSpacingNVproc = (PFNGLGETPATHSPACINGNVPROC)wglGetProcAddress("glGetPathSpacingNV");
	glIsPointInFillPathNVproc = (PFNGLISPOINTINFILLPATHNVPROC)wglGetProcAddress("glIsPointInFillPathNV");
	glIsPointInStrokePathNVproc = (PFNGLISPOINTINSTROKEPATHNVPROC)wglGetProcAddress("glIsPointInStrokePathNV");
	glGetPathLengthNVproc = (PFNGLGETPATHLENGTHNVPROC)wglGetProcAddress("glGetPathLengthNV");
	glPointAlongPathNVproc = (PFNGLPOINTALONGPATHNVPROC)wglGetProcAddress("glPointAlongPathNV");
	glMatrixLoad3x2fNVproc = (PFNGLMATRIXLOAD3X2FNVPROC)wglGetProcAddress("glMatrixLoad3x2fNV");
	glMatrixLoad3x3fNVproc = (PFNGLMATRIXLOAD3X3FNVPROC)wglGetProcAddress("glMatrixLoad3x3fNV");
	glMatrixLoadTranspose3x3fNVproc = (PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)wglGetProcAddress("glMatrixLoadTranspose3x3fNV");
	glMatrixMult3x2fNVproc = (PFNGLMATRIXMULT3X2FNVPROC)wglGetProcAddress("glMatrixMult3x2fNV");
	glMatrixMult3x3fNVproc = (PFNGLMATRIXMULT3X3FNVPROC)wglGetProcAddress("glMatrixMult3x3fNV");
	glMatrixMultTranspose3x3fNVproc = (PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)wglGetProcAddress("glMatrixMultTranspose3x3fNV");
	glStencilThenCoverFillPathNVproc = (PFNGLSTENCILTHENCOVERFILLPATHNVPROC)wglGetProcAddress("glStencilThenCoverFillPathNV");
	glStencilThenCoverStrokePathNVproc = (PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)wglGetProcAddress("glStencilThenCoverStrokePathNV");
	glStencilThenCoverFillPathInstancedNVproc = (PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilThenCoverFillPathInstancedNV");
	glStencilThenCoverStrokePathInstancedNVproc = (PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilThenCoverStrokePathInstancedNV");
	glPathGlyphIndexRangeNVproc = (PFNGLPATHGLYPHINDEXRANGENVPROC)wglGetProcAddress("glPathGlyphIndexRangeNV");
	glPathGlyphIndexArrayNVproc = (PFNGLPATHGLYPHINDEXARRAYNVPROC)wglGetProcAddress("glPathGlyphIndexArrayNV");
	glPathMemoryGlyphIndexArrayNVproc = (PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)wglGetProcAddress("glPathMemoryGlyphIndexArrayNV");
	glProgramPathFragmentInputGenNVproc = (PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)wglGetProcAddress("glProgramPathFragmentInputGenNV");
	glGetProgramResourcefvNVproc = (PFNGLGETPROGRAMRESOURCEFVNVPROC)wglGetProcAddress("glGetProgramResourcefvNV");
	glPathColorGenNVproc = (PFNGLPATHCOLORGENNVPROC)wglGetProcAddress("glPathColorGenNV");
	glPathTexGenNVproc = (PFNGLPATHTEXGENNVPROC)wglGetProcAddress("glPathTexGenNV");
	glPathFogGenNVproc = (PFNGLPATHFOGGENNVPROC)wglGetProcAddress("glPathFogGenNV");
	glGetPathColorGenivNVproc = (PFNGLGETPATHCOLORGENIVNVPROC)wglGetProcAddress("glGetPathColorGenivNV");
	glGetPathColorGenfvNVproc = (PFNGLGETPATHCOLORGENFVNVPROC)wglGetProcAddress("glGetPathColorGenfvNV");
	glGetPathTexGenivNVproc = (PFNGLGETPATHTEXGENIVNVPROC)wglGetProcAddress("glGetPathTexGenivNV");
	glGetPathTexGenfvNVproc = (PFNGLGETPATHTEXGENFVNVPROC)wglGetProcAddress("glGetPathTexGenfvNV");
	glPixelDataRangeNVproc = (PFNGLPIXELDATARANGENVPROC)wglGetProcAddress("glPixelDataRangeNV");
	glFlushPixelDataRangeNVproc = (PFNGLFLUSHPIXELDATARANGENVPROC)wglGetProcAddress("glFlushPixelDataRangeNV");
	glPointParameteriNVproc = (PFNGLPOINTPARAMETERINVPROC)wglGetProcAddress("glPointParameteriNV");
	glPointParameterivNVproc = (PFNGLPOINTPARAMETERIVNVPROC)wglGetProcAddress("glPointParameterivNV");
	glPresentFrameKeyedNVproc = (PFNGLPRESENTFRAMEKEYEDNVPROC)wglGetProcAddress("glPresentFrameKeyedNV");
	glPresentFrameDualFillNVproc = (PFNGLPRESENTFRAMEDUALFILLNVPROC)wglGetProcAddress("glPresentFrameDualFillNV");
	glGetVideoivNVproc = (PFNGLGETVIDEOIVNVPROC)wglGetProcAddress("glGetVideoivNV");
	glGetVideouivNVproc = (PFNGLGETVIDEOUIVNVPROC)wglGetProcAddress("glGetVideouivNV");
	glGetVideoi64vNVproc = (PFNGLGETVIDEOI64VNVPROC)wglGetProcAddress("glGetVideoi64vNV");
	glGetVideoui64vNVproc = (PFNGLGETVIDEOUI64VNVPROC)wglGetProcAddress("glGetVideoui64vNV");
	glPrimitiveRestartNVproc = (PFNGLPRIMITIVERESTARTNVPROC)wglGetProcAddress("glPrimitiveRestartNV");
	glPrimitiveRestartIndexNVproc = (PFNGLPRIMITIVERESTARTINDEXNVPROC)wglGetProcAddress("glPrimitiveRestartIndexNV");
	glQueryResourceNVproc = (PFNGLQUERYRESOURCENVPROC)wglGetProcAddress("glQueryResourceNV");
	glGenQueryResourceTagNVproc = (PFNGLGENQUERYRESOURCETAGNVPROC)wglGetProcAddress("glGenQueryResourceTagNV");
	glDeleteQueryResourceTagNVproc = (PFNGLDELETEQUERYRESOURCETAGNVPROC)wglGetProcAddress("glDeleteQueryResourceTagNV");
	glQueryResourceTagNVproc = (PFNGLQUERYRESOURCETAGNVPROC)wglGetProcAddress("glQueryResourceTagNV");
	glCombinerParameterfvNVproc = (PFNGLCOMBINERPARAMETERFVNVPROC)wglGetProcAddress("glCombinerParameterfvNV");
	glCombinerParameterfNVproc = (PFNGLCOMBINERPARAMETERFNVPROC)wglGetProcAddress("glCombinerParameterfNV");
	glCombinerParameterivNVproc = (PFNGLCOMBINERPARAMETERIVNVPROC)wglGetProcAddress("glCombinerParameterivNV");
	glCombinerParameteriNVproc = (PFNGLCOMBINERPARAMETERINVPROC)wglGetProcAddress("glCombinerParameteriNV");
	glCombinerInputNVproc = (PFNGLCOMBINERINPUTNVPROC)wglGetProcAddress("glCombinerInputNV");
	glCombinerOutputNVproc = (PFNGLCOMBINEROUTPUTNVPROC)wglGetProcAddress("glCombinerOutputNV");
	glFinalCombinerInputNVproc = (PFNGLFINALCOMBINERINPUTNVPROC)wglGetProcAddress("glFinalCombinerInputNV");
	glGetCombinerInputParameterfvNVproc = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)wglGetProcAddress("glGetCombinerInputParameterfvNV");
	glGetCombinerInputParameterivNVproc = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)wglGetProcAddress("glGetCombinerInputParameterivNV");
	glGetCombinerOutputParameterfvNVproc = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)wglGetProcAddress("glGetCombinerOutputParameterfvNV");
	glGetCombinerOutputParameterivNVproc = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)wglGetProcAddress("glGetCombinerOutputParameterivNV");
	glGetFinalCombinerInputParameterfvNVproc = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)wglGetProcAddress("glGetFinalCombinerInputParameterfvNV");
	glGetFinalCombinerInputParameterivNVproc = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)wglGetProcAddress("glGetFinalCombinerInputParameterivNV");
	glCombinerStageParameterfvNVproc = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)wglGetProcAddress("glCombinerStageParameterfvNV");
	glGetCombinerStageParameterfvNVproc = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)wglGetProcAddress("glGetCombinerStageParameterfvNV");
	glFramebufferSampleLocationsfvNVproc = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)wglGetProcAddress("glFramebufferSampleLocationsfvNV");
	glNamedFramebufferSampleLocationsfvNVproc = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)wglGetProcAddress("glNamedFramebufferSampleLocationsfvNV");
	glResolveDepthValuesNVproc = (PFNGLRESOLVEDEPTHVALUESNVPROC)wglGetProcAddress("glResolveDepthValuesNV");
	glScissorExclusiveNVproc = (PFNGLSCISSOREXCLUSIVENVPROC)wglGetProcAddress("glScissorExclusiveNV");
	glScissorExclusiveArrayvNVproc = (PFNGLSCISSOREXCLUSIVEARRAYVNVPROC)wglGetProcAddress("glScissorExclusiveArrayvNV");
	glMakeBufferResidentNVproc = (PFNGLMAKEBUFFERRESIDENTNVPROC)wglGetProcAddress("glMakeBufferResidentNV");
	glMakeBufferNonResidentNVproc = (PFNGLMAKEBUFFERNONRESIDENTNVPROC)wglGetProcAddress("glMakeBufferNonResidentNV");
	glIsBufferResidentNVproc = (PFNGLISBUFFERRESIDENTNVPROC)wglGetProcAddress("glIsBufferResidentNV");
	glMakeNamedBufferResidentNVproc = (PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)wglGetProcAddress("glMakeNamedBufferResidentNV");
	glMakeNamedBufferNonResidentNVproc = (PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)wglGetProcAddress("glMakeNamedBufferNonResidentNV");
	glIsNamedBufferResidentNVproc = (PFNGLISNAMEDBUFFERRESIDENTNVPROC)wglGetProcAddress("glIsNamedBufferResidentNV");
	glGetBufferParameterui64vNVproc = (PFNGLGETBUFFERPARAMETERUI64VNVPROC)wglGetProcAddress("glGetBufferParameterui64vNV");
	glGetNamedBufferParameterui64vNVproc = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)wglGetProcAddress("glGetNamedBufferParameterui64vNV");
	glGetIntegerui64vNVproc = (PFNGLGETINTEGERUI64VNVPROC)wglGetProcAddress("glGetIntegerui64vNV");
	glUniformui64NVproc = (PFNGLUNIFORMUI64NVPROC)wglGetProcAddress("glUniformui64NV");
	glUniformui64vNVproc = (PFNGLUNIFORMUI64VNVPROC)wglGetProcAddress("glUniformui64vNV");
	glProgramUniformui64NVproc = (PFNGLPROGRAMUNIFORMUI64NVPROC)wglGetProcAddress("glProgramUniformui64NV");
	glProgramUniformui64vNVproc = (PFNGLPROGRAMUNIFORMUI64VNVPROC)wglGetProcAddress("glProgramUniformui64vNV");
	glBindShadingRateImageNVproc = (PFNGLBINDSHADINGRATEIMAGENVPROC)wglGetProcAddress("glBindShadingRateImageNV");
	glGetShadingRateImagePaletteNVproc = (PFNGLGETSHADINGRATEIMAGEPALETTENVPROC)wglGetProcAddress("glGetShadingRateImagePaletteNV");
	glGetShadingRateSampleLocationivNVproc = (PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC)wglGetProcAddress("glGetShadingRateSampleLocationivNV");
	glShadingRateImageBarrierNVproc = (PFNGLSHADINGRATEIMAGEBARRIERNVPROC)wglGetProcAddress("glShadingRateImageBarrierNV");
	glShadingRateImagePaletteNVproc = (PFNGLSHADINGRATEIMAGEPALETTENVPROC)wglGetProcAddress("glShadingRateImagePaletteNV");
	glShadingRateSampleOrderNVproc = (PFNGLSHADINGRATESAMPLEORDERNVPROC)wglGetProcAddress("glShadingRateSampleOrderNV");
	glShadingRateSampleOrderCustomNVproc = (PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC)wglGetProcAddress("glShadingRateSampleOrderCustomNV");
	glTextureBarrierNVproc = (PFNGLTEXTUREBARRIERNVPROC)wglGetProcAddress("glTextureBarrierNV");
	glTexImage2DMultisampleCoverageNVproc = (PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTexImage2DMultisampleCoverageNV");
	glTexImage3DMultisampleCoverageNVproc = (PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTexImage3DMultisampleCoverageNV");
	glTextureImage2DMultisampleNVproc = (PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)wglGetProcAddress("glTextureImage2DMultisampleNV");
	glTextureImage3DMultisampleNVproc = (PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)wglGetProcAddress("glTextureImage3DMultisampleNV");
	glTextureImage2DMultisampleCoverageNVproc = (PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTextureImage2DMultisampleCoverageNV");
	glTextureImage3DMultisampleCoverageNVproc = (PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTextureImage3DMultisampleCoverageNV");
	glCreateSemaphoresNVproc = (PFNGLCREATESEMAPHORESNVPROC)wglGetProcAddress("glCreateSemaphoresNV");
	glSemaphoreParameterivNVproc = (PFNGLSEMAPHOREPARAMETERIVNVPROC)wglGetProcAddress("glSemaphoreParameterivNV");
	glGetSemaphoreParameterivNVproc = (PFNGLGETSEMAPHOREPARAMETERIVNVPROC)wglGetProcAddress("glGetSemaphoreParameterivNV");
	glBeginTransformFeedbackNVproc = (PFNGLBEGINTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glBeginTransformFeedbackNV");
	glEndTransformFeedbackNVproc = (PFNGLENDTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glEndTransformFeedbackNV");
	glTransformFeedbackAttribsNVproc = (PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)wglGetProcAddress("glTransformFeedbackAttribsNV");
	glBindBufferRangeNVproc = (PFNGLBINDBUFFERRANGENVPROC)wglGetProcAddress("glBindBufferRangeNV");
	glBindBufferOffsetNVproc = (PFNGLBINDBUFFEROFFSETNVPROC)wglGetProcAddress("glBindBufferOffsetNV");
	glBindBufferBaseNVproc = (PFNGLBINDBUFFERBASENVPROC)wglGetProcAddress("glBindBufferBaseNV");
	glTransformFeedbackVaryingsNVproc = (PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)wglGetProcAddress("glTransformFeedbackVaryingsNV");
	glActiveVaryingNVproc = (PFNGLACTIVEVARYINGNVPROC)wglGetProcAddress("glActiveVaryingNV");
	glGetVaryingLocationNVproc = (PFNGLGETVARYINGLOCATIONNVPROC)wglGetProcAddress("glGetVaryingLocationNV");
	glGetActiveVaryingNVproc = (PFNGLGETACTIVEVARYINGNVPROC)wglGetProcAddress("glGetActiveVaryingNV");
	glGetTransformFeedbackVaryingNVproc = (PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)wglGetProcAddress("glGetTransformFeedbackVaryingNV");
	glTransformFeedbackStreamAttribsNVproc = (PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)wglGetProcAddress("glTransformFeedbackStreamAttribsNV");
	glBindTransformFeedbackNVproc = (PFNGLBINDTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glBindTransformFeedbackNV");
	glDeleteTransformFeedbacksNVproc = (PFNGLDELETETRANSFORMFEEDBACKSNVPROC)wglGetProcAddress("glDeleteTransformFeedbacksNV");
	glGenTransformFeedbacksNVproc = (PFNGLGENTRANSFORMFEEDBACKSNVPROC)wglGetProcAddress("glGenTransformFeedbacksNV");
	glIsTransformFeedbackNVproc = (PFNGLISTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glIsTransformFeedbackNV");
	glPauseTransformFeedbackNVproc = (PFNGLPAUSETRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glPauseTransformFeedbackNV");
	glResumeTransformFeedbackNVproc = (PFNGLRESUMETRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glResumeTransformFeedbackNV");
	glDrawTransformFeedbackNVproc = (PFNGLDRAWTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glDrawTransformFeedbackNV");
	glVDPAUInitNVproc = (PFNGLVDPAUINITNVPROC)wglGetProcAddress("glVDPAUInitNV");
	glVDPAUFiniNVproc = (PFNGLVDPAUFININVPROC)wglGetProcAddress("glVDPAUFiniNV");
	glVDPAURegisterVideoSurfaceNVproc = (PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)wglGetProcAddress("glVDPAURegisterVideoSurfaceNV");
	glVDPAURegisterOutputSurfaceNVproc = (PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)wglGetProcAddress("glVDPAURegisterOutputSurfaceNV");
	glVDPAUIsSurfaceNVproc = (PFNGLVDPAUISSURFACENVPROC)wglGetProcAddress("glVDPAUIsSurfaceNV");
	glVDPAUUnregisterSurfaceNVproc = (PFNGLVDPAUUNREGISTERSURFACENVPROC)wglGetProcAddress("glVDPAUUnregisterSurfaceNV");
	glVDPAUGetSurfaceivNVproc = (PFNGLVDPAUGETSURFACEIVNVPROC)wglGetProcAddress("glVDPAUGetSurfaceivNV");
	glVDPAUSurfaceAccessNVproc = (PFNGLVDPAUSURFACEACCESSNVPROC)wglGetProcAddress("glVDPAUSurfaceAccessNV");
	glVDPAUMapSurfacesNVproc = (PFNGLVDPAUMAPSURFACESNVPROC)wglGetProcAddress("glVDPAUMapSurfacesNV");
	glVDPAUUnmapSurfacesNVproc = (PFNGLVDPAUUNMAPSURFACESNVPROC)wglGetProcAddress("glVDPAUUnmapSurfacesNV");
	glVDPAURegisterVideoSurfaceWithPictureStructureNVproc = (PFNGLVDPAUREGISTERVIDEOSURFACEWITHPICTURESTRUCTURENVPROC)wglGetProcAddress("glVDPAURegisterVideoSurfaceWithPictureStructureNV");
	glFlushVertexArrayRangeNVproc = (PFNGLFLUSHVERTEXARRAYRANGENVPROC)wglGetProcAddress("glFlushVertexArrayRangeNV");
	glVertexArrayRangeNVproc = (PFNGLVERTEXARRAYRANGENVPROC)wglGetProcAddress("glVertexArrayRangeNV");
	glVertexAttribL1i64NVproc = (PFNGLVERTEXATTRIBL1I64NVPROC)wglGetProcAddress("glVertexAttribL1i64NV");
	glVertexAttribL2i64NVproc = (PFNGLVERTEXATTRIBL2I64NVPROC)wglGetProcAddress("glVertexAttribL2i64NV");
	glVertexAttribL3i64NVproc = (PFNGLVERTEXATTRIBL3I64NVPROC)wglGetProcAddress("glVertexAttribL3i64NV");
	glVertexAttribL4i64NVproc = (PFNGLVERTEXATTRIBL4I64NVPROC)wglGetProcAddress("glVertexAttribL4i64NV");
	glVertexAttribL1i64vNVproc = (PFNGLVERTEXATTRIBL1I64VNVPROC)wglGetProcAddress("glVertexAttribL1i64vNV");
	glVertexAttribL2i64vNVproc = (PFNGLVERTEXATTRIBL2I64VNVPROC)wglGetProcAddress("glVertexAttribL2i64vNV");
	glVertexAttribL3i64vNVproc = (PFNGLVERTEXATTRIBL3I64VNVPROC)wglGetProcAddress("glVertexAttribL3i64vNV");
	glVertexAttribL4i64vNVproc = (PFNGLVERTEXATTRIBL4I64VNVPROC)wglGetProcAddress("glVertexAttribL4i64vNV");
	glVertexAttribL1ui64NVproc = (PFNGLVERTEXATTRIBL1UI64NVPROC)wglGetProcAddress("glVertexAttribL1ui64NV");
	glVertexAttribL2ui64NVproc = (PFNGLVERTEXATTRIBL2UI64NVPROC)wglGetProcAddress("glVertexAttribL2ui64NV");
	glVertexAttribL3ui64NVproc = (PFNGLVERTEXATTRIBL3UI64NVPROC)wglGetProcAddress("glVertexAttribL3ui64NV");
	glVertexAttribL4ui64NVproc = (PFNGLVERTEXATTRIBL4UI64NVPROC)wglGetProcAddress("glVertexAttribL4ui64NV");
	glVertexAttribL1ui64vNVproc = (PFNGLVERTEXATTRIBL1UI64VNVPROC)wglGetProcAddress("glVertexAttribL1ui64vNV");
	glVertexAttribL2ui64vNVproc = (PFNGLVERTEXATTRIBL2UI64VNVPROC)wglGetProcAddress("glVertexAttribL2ui64vNV");
	glVertexAttribL3ui64vNVproc = (PFNGLVERTEXATTRIBL3UI64VNVPROC)wglGetProcAddress("glVertexAttribL3ui64vNV");
	glVertexAttribL4ui64vNVproc = (PFNGLVERTEXATTRIBL4UI64VNVPROC)wglGetProcAddress("glVertexAttribL4ui64vNV");
	glGetVertexAttribLi64vNVproc = (PFNGLGETVERTEXATTRIBLI64VNVPROC)wglGetProcAddress("glGetVertexAttribLi64vNV");
	glGetVertexAttribLui64vNVproc = (PFNGLGETVERTEXATTRIBLUI64VNVPROC)wglGetProcAddress("glGetVertexAttribLui64vNV");
	glVertexAttribLFormatNVproc = (PFNGLVERTEXATTRIBLFORMATNVPROC)wglGetProcAddress("glVertexAttribLFormatNV");
	glBufferAddressRangeNVproc = (PFNGLBUFFERADDRESSRANGENVPROC)wglGetProcAddress("glBufferAddressRangeNV");
	glVertexFormatNVproc = (PFNGLVERTEXFORMATNVPROC)wglGetProcAddress("glVertexFormatNV");
	glNormalFormatNVproc = (PFNGLNORMALFORMATNVPROC)wglGetProcAddress("glNormalFormatNV");
	glColorFormatNVproc = (PFNGLCOLORFORMATNVPROC)wglGetProcAddress("glColorFormatNV");
	glIndexFormatNVproc = (PFNGLINDEXFORMATNVPROC)wglGetProcAddress("glIndexFormatNV");
	glTexCoordFormatNVproc = (PFNGLTEXCOORDFORMATNVPROC)wglGetProcAddress("glTexCoordFormatNV");
	glEdgeFlagFormatNVproc = (PFNGLEDGEFLAGFORMATNVPROC)wglGetProcAddress("glEdgeFlagFormatNV");
	glSecondaryColorFormatNVproc = (PFNGLSECONDARYCOLORFORMATNVPROC)wglGetProcAddress("glSecondaryColorFormatNV");
	glFogCoordFormatNVproc = (PFNGLFOGCOORDFORMATNVPROC)wglGetProcAddress("glFogCoordFormatNV");
	glVertexAttribFormatNVproc = (PFNGLVERTEXATTRIBFORMATNVPROC)wglGetProcAddress("glVertexAttribFormatNV");
	glVertexAttribIFormatNVproc = (PFNGLVERTEXATTRIBIFORMATNVPROC)wglGetProcAddress("glVertexAttribIFormatNV");
	glGetIntegerui64i_vNVproc = (PFNGLGETINTEGERUI64I_VNVPROC)wglGetProcAddress("glGetIntegerui64i_vNV");
	glAreProgramsResidentNVproc = (PFNGLAREPROGRAMSRESIDENTNVPROC)wglGetProcAddress("glAreProgramsResidentNV");
	glBindProgramNVproc = (PFNGLBINDPROGRAMNVPROC)wglGetProcAddress("glBindProgramNV");
	glDeleteProgramsNVproc = (PFNGLDELETEPROGRAMSNVPROC)wglGetProcAddress("glDeleteProgramsNV");
	glExecuteProgramNVproc = (PFNGLEXECUTEPROGRAMNVPROC)wglGetProcAddress("glExecuteProgramNV");
	glGenProgramsNVproc = (PFNGLGENPROGRAMSNVPROC)wglGetProcAddress("glGenProgramsNV");
	glGetProgramParameterdvNVproc = (PFNGLGETPROGRAMPARAMETERDVNVPROC)wglGetProcAddress("glGetProgramParameterdvNV");
	glGetProgramParameterfvNVproc = (PFNGLGETPROGRAMPARAMETERFVNVPROC)wglGetProcAddress("glGetProgramParameterfvNV");
	glGetProgramivNVproc = (PFNGLGETPROGRAMIVNVPROC)wglGetProcAddress("glGetProgramivNV");
	glGetProgramStringNVproc = (PFNGLGETPROGRAMSTRINGNVPROC)wglGetProcAddress("glGetProgramStringNV");
	glGetTrackMatrixivNVproc = (PFNGLGETTRACKMATRIXIVNVPROC)wglGetProcAddress("glGetTrackMatrixivNV");
	glGetVertexAttribdvNVproc = (PFNGLGETVERTEXATTRIBDVNVPROC)wglGetProcAddress("glGetVertexAttribdvNV");
	glGetVertexAttribfvNVproc = (PFNGLGETVERTEXATTRIBFVNVPROC)wglGetProcAddress("glGetVertexAttribfvNV");
	glGetVertexAttribivNVproc = (PFNGLGETVERTEXATTRIBIVNVPROC)wglGetProcAddress("glGetVertexAttribivNV");
	glGetVertexAttribPointervNVproc = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)wglGetProcAddress("glGetVertexAttribPointervNV");
	glIsProgramNVproc = (PFNGLISPROGRAMNVPROC)wglGetProcAddress("glIsProgramNV");
	glLoadProgramNVproc = (PFNGLLOADPROGRAMNVPROC)wglGetProcAddress("glLoadProgramNV");
	glProgramParameter4dNVproc = (PFNGLPROGRAMPARAMETER4DNVPROC)wglGetProcAddress("glProgramParameter4dNV");
	glProgramParameter4dvNVproc = (PFNGLPROGRAMPARAMETER4DVNVPROC)wglGetProcAddress("glProgramParameter4dvNV");
	glProgramParameter4fNVproc = (PFNGLPROGRAMPARAMETER4FNVPROC)wglGetProcAddress("glProgramParameter4fNV");
	glProgramParameter4fvNVproc = (PFNGLPROGRAMPARAMETER4FVNVPROC)wglGetProcAddress("glProgramParameter4fvNV");
	glProgramParameters4dvNVproc = (PFNGLPROGRAMPARAMETERS4DVNVPROC)wglGetProcAddress("glProgramParameters4dvNV");
	glProgramParameters4fvNVproc = (PFNGLPROGRAMPARAMETERS4FVNVPROC)wglGetProcAddress("glProgramParameters4fvNV");
	glRequestResidentProgramsNVproc = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC)wglGetProcAddress("glRequestResidentProgramsNV");
	glTrackMatrixNVproc = (PFNGLTRACKMATRIXNVPROC)wglGetProcAddress("glTrackMatrixNV");
	glVertexAttribPointerNVproc = (PFNGLVERTEXATTRIBPOINTERNVPROC)wglGetProcAddress("glVertexAttribPointerNV");
	glVertexAttrib1dNVproc = (PFNGLVERTEXATTRIB1DNVPROC)wglGetProcAddress("glVertexAttrib1dNV");
	glVertexAttrib1dvNVproc = (PFNGLVERTEXATTRIB1DVNVPROC)wglGetProcAddress("glVertexAttrib1dvNV");
	glVertexAttrib1fNVproc = (PFNGLVERTEXATTRIB1FNVPROC)wglGetProcAddress("glVertexAttrib1fNV");
	glVertexAttrib1fvNVproc = (PFNGLVERTEXATTRIB1FVNVPROC)wglGetProcAddress("glVertexAttrib1fvNV");
	glVertexAttrib1sNVproc = (PFNGLVERTEXATTRIB1SNVPROC)wglGetProcAddress("glVertexAttrib1sNV");
	glVertexAttrib1svNVproc = (PFNGLVERTEXATTRIB1SVNVPROC)wglGetProcAddress("glVertexAttrib1svNV");
	glVertexAttrib2dNVproc = (PFNGLVERTEXATTRIB2DNVPROC)wglGetProcAddress("glVertexAttrib2dNV");
	glVertexAttrib2dvNVproc = (PFNGLVERTEXATTRIB2DVNVPROC)wglGetProcAddress("glVertexAttrib2dvNV");
	glVertexAttrib2fNVproc = (PFNGLVERTEXATTRIB2FNVPROC)wglGetProcAddress("glVertexAttrib2fNV");
	glVertexAttrib2fvNVproc = (PFNGLVERTEXATTRIB2FVNVPROC)wglGetProcAddress("glVertexAttrib2fvNV");
	glVertexAttrib2sNVproc = (PFNGLVERTEXATTRIB2SNVPROC)wglGetProcAddress("glVertexAttrib2sNV");
	glVertexAttrib2svNVproc = (PFNGLVERTEXATTRIB2SVNVPROC)wglGetProcAddress("glVertexAttrib2svNV");
	glVertexAttrib3dNVproc = (PFNGLVERTEXATTRIB3DNVPROC)wglGetProcAddress("glVertexAttrib3dNV");
	glVertexAttrib3dvNVproc = (PFNGLVERTEXATTRIB3DVNVPROC)wglGetProcAddress("glVertexAttrib3dvNV");
	glVertexAttrib3fNVproc = (PFNGLVERTEXATTRIB3FNVPROC)wglGetProcAddress("glVertexAttrib3fNV");
	glVertexAttrib3fvNVproc = (PFNGLVERTEXATTRIB3FVNVPROC)wglGetProcAddress("glVertexAttrib3fvNV");
	glVertexAttrib3sNVproc = (PFNGLVERTEXATTRIB3SNVPROC)wglGetProcAddress("glVertexAttrib3sNV");
	glVertexAttrib3svNVproc = (PFNGLVERTEXATTRIB3SVNVPROC)wglGetProcAddress("glVertexAttrib3svNV");
	glVertexAttrib4dNVproc = (PFNGLVERTEXATTRIB4DNVPROC)wglGetProcAddress("glVertexAttrib4dNV");
	glVertexAttrib4dvNVproc = (PFNGLVERTEXATTRIB4DVNVPROC)wglGetProcAddress("glVertexAttrib4dvNV");
	glVertexAttrib4fNVproc = (PFNGLVERTEXATTRIB4FNVPROC)wglGetProcAddress("glVertexAttrib4fNV");
	glVertexAttrib4fvNVproc = (PFNGLVERTEXATTRIB4FVNVPROC)wglGetProcAddress("glVertexAttrib4fvNV");
	glVertexAttrib4sNVproc = (PFNGLVERTEXATTRIB4SNVPROC)wglGetProcAddress("glVertexAttrib4sNV");
	glVertexAttrib4svNVproc = (PFNGLVERTEXATTRIB4SVNVPROC)wglGetProcAddress("glVertexAttrib4svNV");
	glVertexAttrib4ubNVproc = (PFNGLVERTEXATTRIB4UBNVPROC)wglGetProcAddress("glVertexAttrib4ubNV");
	glVertexAttrib4ubvNVproc = (PFNGLVERTEXATTRIB4UBVNVPROC)wglGetProcAddress("glVertexAttrib4ubvNV");
	glVertexAttribs1dvNVproc = (PFNGLVERTEXATTRIBS1DVNVPROC)wglGetProcAddress("glVertexAttribs1dvNV");
	glVertexAttribs1fvNVproc = (PFNGLVERTEXATTRIBS1FVNVPROC)wglGetProcAddress("glVertexAttribs1fvNV");
	glVertexAttribs1svNVproc = (PFNGLVERTEXATTRIBS1SVNVPROC)wglGetProcAddress("glVertexAttribs1svNV");
	glVertexAttribs2dvNVproc = (PFNGLVERTEXATTRIBS2DVNVPROC)wglGetProcAddress("glVertexAttribs2dvNV");
	glVertexAttribs2fvNVproc = (PFNGLVERTEXATTRIBS2FVNVPROC)wglGetProcAddress("glVertexAttribs2fvNV");
	glVertexAttribs2svNVproc = (PFNGLVERTEXATTRIBS2SVNVPROC)wglGetProcAddress("glVertexAttribs2svNV");
	glVertexAttribs3dvNVproc = (PFNGLVERTEXATTRIBS3DVNVPROC)wglGetProcAddress("glVertexAttribs3dvNV");
	glVertexAttribs3fvNVproc = (PFNGLVERTEXATTRIBS3FVNVPROC)wglGetProcAddress("glVertexAttribs3fvNV");
	glVertexAttribs3svNVproc = (PFNGLVERTEXATTRIBS3SVNVPROC)wglGetProcAddress("glVertexAttribs3svNV");
	glVertexAttribs4dvNVproc = (PFNGLVERTEXATTRIBS4DVNVPROC)wglGetProcAddress("glVertexAttribs4dvNV");
	glVertexAttribs4fvNVproc = (PFNGLVERTEXATTRIBS4FVNVPROC)wglGetProcAddress("glVertexAttribs4fvNV");
	glVertexAttribs4svNVproc = (PFNGLVERTEXATTRIBS4SVNVPROC)wglGetProcAddress("glVertexAttribs4svNV");
	glVertexAttribs4ubvNVproc = (PFNGLVERTEXATTRIBS4UBVNVPROC)wglGetProcAddress("glVertexAttribs4ubvNV");
	glBeginVideoCaptureNVproc = (PFNGLBEGINVIDEOCAPTURENVPROC)wglGetProcAddress("glBeginVideoCaptureNV");
	glBindVideoCaptureStreamBufferNVproc = (PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)wglGetProcAddress("glBindVideoCaptureStreamBufferNV");
	glBindVideoCaptureStreamTextureNVproc = (PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)wglGetProcAddress("glBindVideoCaptureStreamTextureNV");
	glEndVideoCaptureNVproc = (PFNGLENDVIDEOCAPTURENVPROC)wglGetProcAddress("glEndVideoCaptureNV");
	glGetVideoCaptureivNVproc = (PFNGLGETVIDEOCAPTUREIVNVPROC)wglGetProcAddress("glGetVideoCaptureivNV");
	glGetVideoCaptureStreamivNVproc = (PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)wglGetProcAddress("glGetVideoCaptureStreamivNV");
	glGetVideoCaptureStreamfvNVproc = (PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)wglGetProcAddress("glGetVideoCaptureStreamfvNV");
	glGetVideoCaptureStreamdvNVproc = (PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)wglGetProcAddress("glGetVideoCaptureStreamdvNV");
	glVideoCaptureNVproc = (PFNGLVIDEOCAPTURENVPROC)wglGetProcAddress("glVideoCaptureNV");
	glVideoCaptureStreamParameterivNVproc = (PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)wglGetProcAddress("glVideoCaptureStreamParameterivNV");
	glVideoCaptureStreamParameterfvNVproc = (PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)wglGetProcAddress("glVideoCaptureStreamParameterfvNV");
	glVideoCaptureStreamParameterdvNVproc = (PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)wglGetProcAddress("glVideoCaptureStreamParameterdvNV");
	glViewportSwizzleNVproc = (PFNGLVIEWPORTSWIZZLENVPROC)wglGetProcAddress("glViewportSwizzleNV");
	glFramebufferTextureMultiviewOVRproc = (PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)wglGetProcAddress("glFramebufferTextureMultiviewOVR");
	glNamedFramebufferTextureMultiviewOVRproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)wglGetProcAddress("glNamedFramebufferTextureMultiviewOVR");
	glHintPGIproc = (PFNGLHINTPGIPROC)wglGetProcAddress("glHintPGI");
	glDetailTexFuncSGISproc = (PFNGLDETAILTEXFUNCSGISPROC)wglGetProcAddress("glDetailTexFuncSGIS");
	glGetDetailTexFuncSGISproc = (PFNGLGETDETAILTEXFUNCSGISPROC)wglGetProcAddress("glGetDetailTexFuncSGIS");
	glFogFuncSGISproc = (PFNGLFOGFUNCSGISPROC)wglGetProcAddress("glFogFuncSGIS");
	glGetFogFuncSGISproc = (PFNGLGETFOGFUNCSGISPROC)wglGetProcAddress("glGetFogFuncSGIS");
	glSampleMaskSGISproc = (PFNGLSAMPLEMASKSGISPROC)wglGetProcAddress("glSampleMaskSGIS");
	glSamplePatternSGISproc = (PFNGLSAMPLEPATTERNSGISPROC)wglGetProcAddress("glSamplePatternSGIS");
	glPixelTexGenParameteriSGISproc = (PFNGLPIXELTEXGENPARAMETERISGISPROC)wglGetProcAddress("glPixelTexGenParameteriSGIS");
	glPixelTexGenParameterivSGISproc = (PFNGLPIXELTEXGENPARAMETERIVSGISPROC)wglGetProcAddress("glPixelTexGenParameterivSGIS");
	glPixelTexGenParameterfSGISproc = (PFNGLPIXELTEXGENPARAMETERFSGISPROC)wglGetProcAddress("glPixelTexGenParameterfSGIS");
	glPixelTexGenParameterfvSGISproc = (PFNGLPIXELTEXGENPARAMETERFVSGISPROC)wglGetProcAddress("glPixelTexGenParameterfvSGIS");
	glGetPixelTexGenParameterivSGISproc = (PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)wglGetProcAddress("glGetPixelTexGenParameterivSGIS");
	glGetPixelTexGenParameterfvSGISproc = (PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)wglGetProcAddress("glGetPixelTexGenParameterfvSGIS");
	glPointParameterfSGISproc = (PFNGLPOINTPARAMETERFSGISPROC)wglGetProcAddress("glPointParameterfSGIS");
	glPointParameterfvSGISproc = (PFNGLPOINTPARAMETERFVSGISPROC)wglGetProcAddress("glPointParameterfvSGIS");
	glSharpenTexFuncSGISproc = (PFNGLSHARPENTEXFUNCSGISPROC)wglGetProcAddress("glSharpenTexFuncSGIS");
	glGetSharpenTexFuncSGISproc = (PFNGLGETSHARPENTEXFUNCSGISPROC)wglGetProcAddress("glGetSharpenTexFuncSGIS");
	glTexImage4DSGISproc = (PFNGLTEXIMAGE4DSGISPROC)wglGetProcAddress("glTexImage4DSGIS");
	glTexSubImage4DSGISproc = (PFNGLTEXSUBIMAGE4DSGISPROC)wglGetProcAddress("glTexSubImage4DSGIS");
	glTextureColorMaskSGISproc = (PFNGLTEXTURECOLORMASKSGISPROC)wglGetProcAddress("glTextureColorMaskSGIS");
	glGetTexFilterFuncSGISproc = (PFNGLGETTEXFILTERFUNCSGISPROC)wglGetProcAddress("glGetTexFilterFuncSGIS");
	glTexFilterFuncSGISproc = (PFNGLTEXFILTERFUNCSGISPROC)wglGetProcAddress("glTexFilterFuncSGIS");
	glAsyncMarkerSGIXproc = (PFNGLASYNCMARKERSGIXPROC)wglGetProcAddress("glAsyncMarkerSGIX");
	glFinishAsyncSGIXproc = (PFNGLFINISHASYNCSGIXPROC)wglGetProcAddress("glFinishAsyncSGIX");
	glPollAsyncSGIXproc = (PFNGLPOLLASYNCSGIXPROC)wglGetProcAddress("glPollAsyncSGIX");
	glGenAsyncMarkersSGIXproc = (PFNGLGENASYNCMARKERSSGIXPROC)wglGetProcAddress("glGenAsyncMarkersSGIX");
	glDeleteAsyncMarkersSGIXproc = (PFNGLDELETEASYNCMARKERSSGIXPROC)wglGetProcAddress("glDeleteAsyncMarkersSGIX");
	glIsAsyncMarkerSGIXproc = (PFNGLISASYNCMARKERSGIXPROC)wglGetProcAddress("glIsAsyncMarkerSGIX");
	glFlushRasterSGIXproc = (PFNGLFLUSHRASTERSGIXPROC)wglGetProcAddress("glFlushRasterSGIX");
	glFragmentColorMaterialSGIXproc = (PFNGLFRAGMENTCOLORMATERIALSGIXPROC)wglGetProcAddress("glFragmentColorMaterialSGIX");
	glFragmentLightfSGIXproc = (PFNGLFRAGMENTLIGHTFSGIXPROC)wglGetProcAddress("glFragmentLightfSGIX");
	glFragmentLightfvSGIXproc = (PFNGLFRAGMENTLIGHTFVSGIXPROC)wglGetProcAddress("glFragmentLightfvSGIX");
	glFragmentLightiSGIXproc = (PFNGLFRAGMENTLIGHTISGIXPROC)wglGetProcAddress("glFragmentLightiSGIX");
	glFragmentLightivSGIXproc = (PFNGLFRAGMENTLIGHTIVSGIXPROC)wglGetProcAddress("glFragmentLightivSGIX");
	glFragmentLightModelfSGIXproc = (PFNGLFRAGMENTLIGHTMODELFSGIXPROC)wglGetProcAddress("glFragmentLightModelfSGIX");
	glFragmentLightModelfvSGIXproc = (PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)wglGetProcAddress("glFragmentLightModelfvSGIX");
	glFragmentLightModeliSGIXproc = (PFNGLFRAGMENTLIGHTMODELISGIXPROC)wglGetProcAddress("glFragmentLightModeliSGIX");
	glFragmentLightModelivSGIXproc = (PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)wglGetProcAddress("glFragmentLightModelivSGIX");
	glFragmentMaterialfSGIXproc = (PFNGLFRAGMENTMATERIALFSGIXPROC)wglGetProcAddress("glFragmentMaterialfSGIX");
	glFragmentMaterialfvSGIXproc = (PFNGLFRAGMENTMATERIALFVSGIXPROC)wglGetProcAddress("glFragmentMaterialfvSGIX");
	glFragmentMaterialiSGIXproc = (PFNGLFRAGMENTMATERIALISGIXPROC)wglGetProcAddress("glFragmentMaterialiSGIX");
	glFragmentMaterialivSGIXproc = (PFNGLFRAGMENTMATERIALIVSGIXPROC)wglGetProcAddress("glFragmentMaterialivSGIX");
	glGetFragmentLightfvSGIXproc = (PFNGLGETFRAGMENTLIGHTFVSGIXPROC)wglGetProcAddress("glGetFragmentLightfvSGIX");
	glGetFragmentLightivSGIXproc = (PFNGLGETFRAGMENTLIGHTIVSGIXPROC)wglGetProcAddress("glGetFragmentLightivSGIX");
	glGetFragmentMaterialfvSGIXproc = (PFNGLGETFRAGMENTMATERIALFVSGIXPROC)wglGetProcAddress("glGetFragmentMaterialfvSGIX");
	glGetFragmentMaterialivSGIXproc = (PFNGLGETFRAGMENTMATERIALIVSGIXPROC)wglGetProcAddress("glGetFragmentMaterialivSGIX");
	glLightEnviSGIXproc = (PFNGLLIGHTENVISGIXPROC)wglGetProcAddress("glLightEnviSGIX");
	glFrameZoomSGIXproc = (PFNGLFRAMEZOOMSGIXPROC)wglGetProcAddress("glFrameZoomSGIX");
	glIglooInterfaceSGIXproc = (PFNGLIGLOOINTERFACESGIXPROC)wglGetProcAddress("glIglooInterfaceSGIX");
	glGetInstrumentsSGIXproc = (PFNGLGETINSTRUMENTSSGIXPROC)wglGetProcAddress("glGetInstrumentsSGIX");
	glInstrumentsBufferSGIXproc = (PFNGLINSTRUMENTSBUFFERSGIXPROC)wglGetProcAddress("glInstrumentsBufferSGIX");
	glPollInstrumentsSGIXproc = (PFNGLPOLLINSTRUMENTSSGIXPROC)wglGetProcAddress("glPollInstrumentsSGIX");
	glReadInstrumentsSGIXproc = (PFNGLREADINSTRUMENTSSGIXPROC)wglGetProcAddress("glReadInstrumentsSGIX");
	glStartInstrumentsSGIXproc = (PFNGLSTARTINSTRUMENTSSGIXPROC)wglGetProcAddress("glStartInstrumentsSGIX");
	glStopInstrumentsSGIXproc = (PFNGLSTOPINSTRUMENTSSGIXPROC)wglGetProcAddress("glStopInstrumentsSGIX");
	glGetListParameterfvSGIXproc = (PFNGLGETLISTPARAMETERFVSGIXPROC)wglGetProcAddress("glGetListParameterfvSGIX");
	glGetListParameterivSGIXproc = (PFNGLGETLISTPARAMETERIVSGIXPROC)wglGetProcAddress("glGetListParameterivSGIX");
	glListParameterfSGIXproc = (PFNGLLISTPARAMETERFSGIXPROC)wglGetProcAddress("glListParameterfSGIX");
	glListParameterfvSGIXproc = (PFNGLLISTPARAMETERFVSGIXPROC)wglGetProcAddress("glListParameterfvSGIX");
	glListParameteriSGIXproc = (PFNGLLISTPARAMETERISGIXPROC)wglGetProcAddress("glListParameteriSGIX");
	glListParameterivSGIXproc = (PFNGLLISTPARAMETERIVSGIXPROC)wglGetProcAddress("glListParameterivSGIX");
	glPixelTexGenSGIXproc = (PFNGLPIXELTEXGENSGIXPROC)wglGetProcAddress("glPixelTexGenSGIX");
	glDeformationMap3dSGIXproc = (PFNGLDEFORMATIONMAP3DSGIXPROC)wglGetProcAddress("glDeformationMap3dSGIX");
	glDeformationMap3fSGIXproc = (PFNGLDEFORMATIONMAP3FSGIXPROC)wglGetProcAddress("glDeformationMap3fSGIX");
	glDeformSGIXproc = (PFNGLDEFORMSGIXPROC)wglGetProcAddress("glDeformSGIX");
	glLoadIdentityDeformationMapSGIXproc = (PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)wglGetProcAddress("glLoadIdentityDeformationMapSGIX");
	glReferencePlaneSGIXproc = (PFNGLREFERENCEPLANESGIXPROC)wglGetProcAddress("glReferencePlaneSGIX");
	glSpriteParameterfSGIXproc = (PFNGLSPRITEPARAMETERFSGIXPROC)wglGetProcAddress("glSpriteParameterfSGIX");
	glSpriteParameterfvSGIXproc = (PFNGLSPRITEPARAMETERFVSGIXPROC)wglGetProcAddress("glSpriteParameterfvSGIX");
	glSpriteParameteriSGIXproc = (PFNGLSPRITEPARAMETERISGIXPROC)wglGetProcAddress("glSpriteParameteriSGIX");
	glSpriteParameterivSGIXproc = (PFNGLSPRITEPARAMETERIVSGIXPROC)wglGetProcAddress("glSpriteParameterivSGIX");
	glTagSampleBufferSGIXproc = (PFNGLTAGSAMPLEBUFFERSGIXPROC)wglGetProcAddress("glTagSampleBufferSGIX");
	glColorTableSGIproc = (PFNGLCOLORTABLESGIPROC)wglGetProcAddress("glColorTableSGI");
	glColorTableParameterfvSGIproc = (PFNGLCOLORTABLEPARAMETERFVSGIPROC)wglGetProcAddress("glColorTableParameterfvSGI");
	glColorTableParameterivSGIproc = (PFNGLCOLORTABLEPARAMETERIVSGIPROC)wglGetProcAddress("glColorTableParameterivSGI");
	glCopyColorTableSGIproc = (PFNGLCOPYCOLORTABLESGIPROC)wglGetProcAddress("glCopyColorTableSGI");
	glGetColorTableSGIproc = (PFNGLGETCOLORTABLESGIPROC)wglGetProcAddress("glGetColorTableSGI");
	glGetColorTableParameterfvSGIproc = (PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)wglGetProcAddress("glGetColorTableParameterfvSGI");
	glGetColorTableParameterivSGIproc = (PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)wglGetProcAddress("glGetColorTableParameterivSGI");
	glFinishTextureSUNXproc = (PFNGLFINISHTEXTURESUNXPROC)wglGetProcAddress("glFinishTextureSUNX");
	glGlobalAlphaFactorbSUNproc = (PFNGLGLOBALALPHAFACTORBSUNPROC)wglGetProcAddress("glGlobalAlphaFactorbSUN");
	glGlobalAlphaFactorsSUNproc = (PFNGLGLOBALALPHAFACTORSSUNPROC)wglGetProcAddress("glGlobalAlphaFactorsSUN");
	glGlobalAlphaFactoriSUNproc = (PFNGLGLOBALALPHAFACTORISUNPROC)wglGetProcAddress("glGlobalAlphaFactoriSUN");
	glGlobalAlphaFactorfSUNproc = (PFNGLGLOBALALPHAFACTORFSUNPROC)wglGetProcAddress("glGlobalAlphaFactorfSUN");
	glGlobalAlphaFactordSUNproc = (PFNGLGLOBALALPHAFACTORDSUNPROC)wglGetProcAddress("glGlobalAlphaFactordSUN");
	glGlobalAlphaFactorubSUNproc = (PFNGLGLOBALALPHAFACTORUBSUNPROC)wglGetProcAddress("glGlobalAlphaFactorubSUN");
	glGlobalAlphaFactorusSUNproc = (PFNGLGLOBALALPHAFACTORUSSUNPROC)wglGetProcAddress("glGlobalAlphaFactorusSUN");
	glGlobalAlphaFactoruiSUNproc = (PFNGLGLOBALALPHAFACTORUISUNPROC)wglGetProcAddress("glGlobalAlphaFactoruiSUN");
	glDrawMeshArraysSUNproc = (PFNGLDRAWMESHARRAYSSUNPROC)wglGetProcAddress("glDrawMeshArraysSUN");
	glReplacementCodeuiSUNproc = (PFNGLREPLACEMENTCODEUISUNPROC)wglGetProcAddress("glReplacementCodeuiSUN");
	glReplacementCodeusSUNproc = (PFNGLREPLACEMENTCODEUSSUNPROC)wglGetProcAddress("glReplacementCodeusSUN");
	glReplacementCodeubSUNproc = (PFNGLREPLACEMENTCODEUBSUNPROC)wglGetProcAddress("glReplacementCodeubSUN");
	glReplacementCodeuivSUNproc = (PFNGLREPLACEMENTCODEUIVSUNPROC)wglGetProcAddress("glReplacementCodeuivSUN");
	glReplacementCodeusvSUNproc = (PFNGLREPLACEMENTCODEUSVSUNPROC)wglGetProcAddress("glReplacementCodeusvSUN");
	glReplacementCodeubvSUNproc = (PFNGLREPLACEMENTCODEUBVSUNPROC)wglGetProcAddress("glReplacementCodeubvSUN");
	glReplacementCodePointerSUNproc = (PFNGLREPLACEMENTCODEPOINTERSUNPROC)wglGetProcAddress("glReplacementCodePointerSUN");
	glColor4ubVertex2fSUNproc = (PFNGLCOLOR4UBVERTEX2FSUNPROC)wglGetProcAddress("glColor4ubVertex2fSUN");
	glColor4ubVertex2fvSUNproc = (PFNGLCOLOR4UBVERTEX2FVSUNPROC)wglGetProcAddress("glColor4ubVertex2fvSUN");
	glColor4ubVertex3fSUNproc = (PFNGLCOLOR4UBVERTEX3FSUNPROC)wglGetProcAddress("glColor4ubVertex3fSUN");
	glColor4ubVertex3fvSUNproc = (PFNGLCOLOR4UBVERTEX3FVSUNPROC)wglGetProcAddress("glColor4ubVertex3fvSUN");
	glColor3fVertex3fSUNproc = (PFNGLCOLOR3FVERTEX3FSUNPROC)wglGetProcAddress("glColor3fVertex3fSUN");
	glColor3fVertex3fvSUNproc = (PFNGLCOLOR3FVERTEX3FVSUNPROC)wglGetProcAddress("glColor3fVertex3fvSUN");
	glNormal3fVertex3fSUNproc = (PFNGLNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glNormal3fVertex3fSUN");
	glNormal3fVertex3fvSUNproc = (PFNGLNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glNormal3fVertex3fvSUN");
	glColor4fNormal3fVertex3fSUNproc = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glColor4fNormal3fVertex3fSUN");
	glColor4fNormal3fVertex3fvSUNproc = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glColor4fNormal3fVertex3fvSUN");
	glTexCoord2fVertex3fSUNproc = (PFNGLTEXCOORD2FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fVertex3fSUN");
	glTexCoord2fVertex3fvSUNproc = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fVertex3fvSUN");
	glTexCoord4fVertex4fSUNproc = (PFNGLTEXCOORD4FVERTEX4FSUNPROC)wglGetProcAddress("glTexCoord4fVertex4fSUN");
	glTexCoord4fVertex4fvSUNproc = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC)wglGetProcAddress("glTexCoord4fVertex4fvSUN");
	glTexCoord2fColor4ubVertex3fSUNproc = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fColor4ubVertex3fSUN");
	glTexCoord2fColor4ubVertex3fvSUNproc = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fColor4ubVertex3fvSUN");
	glTexCoord2fColor3fVertex3fSUNproc = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fColor3fVertex3fSUN");
	glTexCoord2fColor3fVertex3fvSUNproc = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fColor3fVertex3fvSUN");
	glTexCoord2fNormal3fVertex3fSUNproc = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fNormal3fVertex3fSUN");
	glTexCoord2fNormal3fVertex3fvSUNproc = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fNormal3fVertex3fvSUN");
	glTexCoord2fColor4fNormal3fVertex3fSUNproc = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fSUN");
	glTexCoord2fColor4fNormal3fVertex3fvSUNproc = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fvSUN");
	glTexCoord4fColor4fNormal3fVertex4fSUNproc = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)wglGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fSUN");
	glTexCoord4fColor4fNormal3fVertex4fvSUNproc = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)wglGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fvSUN");
	glReplacementCodeuiVertex3fSUNproc = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiVertex3fSUN");
	glReplacementCodeuiVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiVertex3fvSUN");
	glReplacementCodeuiColor4ubVertex3fSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4ubVertex3fSUN");
	glReplacementCodeuiColor4ubVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4ubVertex3fvSUN");
	glReplacementCodeuiColor3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiColor3fVertex3fSUN");
	glReplacementCodeuiColor3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiColor3fVertex3fvSUN");
	glReplacementCodeuiNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiNormal3fVertex3fSUN");
	glReplacementCodeuiNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiNormal3fVertex3fvSUN");
	glReplacementCodeuiColor4fNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fSUN");
	glReplacementCodeuiColor4fNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fvSUN");
	glReplacementCodeuiTexCoord2fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fSUN");
	glReplacementCodeuiTexCoord2fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fvSUN");
	glReplacementCodeuiTexCoord2fNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN");
	glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN");
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN");
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN");
}
void glmInit() {
	glextInit();
	wglextInit();
}