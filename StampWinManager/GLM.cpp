#include "glm.h"

HANDLE WINAPI wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType){
	if(!GLM_struct->wglCreateBufferRegionARBproc) return 0;
	return GLM_struct->wglCreateBufferRegionARBproc(hDC, iLayerPlane, uType);
}
VOID WINAPI wglDeleteBufferRegionARB(HANDLE hRegion){
	if(!GLM_struct->wglDeleteBufferRegionARBproc) return;
	GLM_struct->wglDeleteBufferRegionARBproc(hRegion);
}
BOOL WINAPI wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height){
	if(!GLM_struct->wglSaveBufferRegionARBproc) return 0;
	return GLM_struct->wglSaveBufferRegionARBproc(hRegion, x, y, width, height);
}
BOOL WINAPI wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc){
	if(!GLM_struct->wglRestoreBufferRegionARBproc) return 0;
	return GLM_struct->wglRestoreBufferRegionARBproc(hRegion, x, y, width, height, xSrc, ySrc);
}
HGLRC WINAPI wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList){
	if(!GLM_struct->wglCreateContextAttribsARBproc) return 0;
	return GLM_struct->wglCreateContextAttribsARBproc(hDC, hShareContext, attribList);
}
const char* WINAPI wglGetExtensionsStringARB(HDC hdc){
	if(!GLM_struct->wglGetExtensionsStringARBproc) return 0;
	return GLM_struct->wglGetExtensionsStringARBproc(hdc);
}
BOOL WINAPI wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc){
	if(!GLM_struct->wglMakeContextCurrentARBproc) return 0;
	return GLM_struct->wglMakeContextCurrentARBproc(hDrawDC, hReadDC, hglrc);
}
HDC WINAPI wglGetCurrentReadDCARB(void){
	if(!GLM_struct->wglGetCurrentReadDCARBproc) return 0;
	return GLM_struct->wglGetCurrentReadDCARBproc();
}
HPBUFFERARB WINAPI wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList){
	if(!GLM_struct->wglCreatePbufferARBproc) return 0;
	return GLM_struct->wglCreatePbufferARBproc(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}
HDC WINAPI wglGetPbufferDCARB(HPBUFFERARB hPbuffer){
	if(!GLM_struct->wglGetPbufferDCARBproc) return 0;
	return GLM_struct->wglGetPbufferDCARBproc(hPbuffer);
}
int WINAPI wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC){
	if(!GLM_struct->wglReleasePbufferDCARBproc) return 0;
	return GLM_struct->wglReleasePbufferDCARBproc(hPbuffer, hDC);
}
BOOL WINAPI wglDestroyPbufferARB(HPBUFFERARB hPbuffer){
	if(!GLM_struct->wglDestroyPbufferARBproc) return 0;
	return GLM_struct->wglDestroyPbufferARBproc(hPbuffer);
}
BOOL WINAPI wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int* piValue){
	if(!GLM_struct->wglQueryPbufferARBproc) return 0;
	return GLM_struct->wglQueryPbufferARBproc(hPbuffer, iAttribute, piValue);
}
BOOL WINAPI wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues){
	if(!GLM_struct->wglGetPixelFormatAttribivARBproc) return 0;
	return GLM_struct->wglGetPixelFormatAttribivARBproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}
BOOL WINAPI wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues){
	if(!GLM_struct->wglGetPixelFormatAttribfvARBproc) return 0;
	return GLM_struct->wglGetPixelFormatAttribfvARBproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}
BOOL WINAPI wglChoosePixelFormatARB(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats){
	if(!GLM_struct->wglChoosePixelFormatARBproc) return 0;
	return GLM_struct->wglChoosePixelFormatARBproc(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}
BOOL WINAPI wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer){
	if(!GLM_struct->wglBindTexImageARBproc) return 0;
	return GLM_struct->wglBindTexImageARBproc(hPbuffer, iBuffer);
}
BOOL WINAPI wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer){
	if(!GLM_struct->wglReleaseTexImageARBproc) return 0;
	return GLM_struct->wglReleaseTexImageARBproc(hPbuffer, iBuffer);
}
BOOL WINAPI wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int* piAttribList){
	if(!GLM_struct->wglSetPbufferAttribARBproc) return 0;
	return GLM_struct->wglSetPbufferAttribARBproc(hPbuffer, piAttribList);
}
BOOL WINAPI wglSetStereoEmitterState3DL(HDC hDC, UINT uState){
	if(!GLM_struct->wglSetStereoEmitterState3DLproc) return 0;
	return GLM_struct->wglSetStereoEmitterState3DLproc(hDC, uState);
}
UINT WINAPI wglGetGPUIDsAMD(UINT maxCount, UINT* ids){
	if(!GLM_struct->wglGetGPUIDsAMDproc) return 0;
	return GLM_struct->wglGetGPUIDsAMDproc(maxCount, ids);
}
INT WINAPI wglGetGPUInfoAMD(UINT id, INT property, GLenum dataType, UINT size, void* data){
	if(!GLM_struct->wglGetGPUInfoAMDproc) return 0;
	return GLM_struct->wglGetGPUInfoAMDproc(id, property, dataType, size, data);
}
UINT WINAPI wglGetContextGPUIDAMD(HGLRC hglrc){
	if(!GLM_struct->wglGetContextGPUIDAMDproc) return 0;
	return GLM_struct->wglGetContextGPUIDAMDproc(hglrc);
}
HGLRC WINAPI wglCreateAssociatedContextAMD(UINT id){
	if(!GLM_struct->wglCreateAssociatedContextAMDproc) return 0;
	return GLM_struct->wglCreateAssociatedContextAMDproc(id);
}
HGLRC WINAPI wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int* attribList){
	if(!GLM_struct->wglCreateAssociatedContextAttribsAMDproc) return 0;
	return GLM_struct->wglCreateAssociatedContextAttribsAMDproc(id, hShareContext, attribList);
}
BOOL WINAPI wglDeleteAssociatedContextAMD(HGLRC hglrc){
	if(!GLM_struct->wglDeleteAssociatedContextAMDproc) return 0;
	return GLM_struct->wglDeleteAssociatedContextAMDproc(hglrc);
}
BOOL WINAPI wglMakeAssociatedContextCurrentAMD(HGLRC hglrc){
	if(!GLM_struct->wglMakeAssociatedContextCurrentAMDproc) return 0;
	return GLM_struct->wglMakeAssociatedContextCurrentAMDproc(hglrc);
}
HGLRC WINAPI wglGetCurrentAssociatedContextAMD(void){
	if(!GLM_struct->wglGetCurrentAssociatedContextAMDproc) return 0;
	return GLM_struct->wglGetCurrentAssociatedContextAMDproc();
}
VOID WINAPI wglBlitContextFramebufferAMD(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){
	if(!GLM_struct->wglBlitContextFramebufferAMDproc) return;
	GLM_struct->wglBlitContextFramebufferAMDproc(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
GLboolean WINAPI wglCreateDisplayColorTableEXT(GLushort id){
	if(!GLM_struct->wglCreateDisplayColorTableEXTproc) return 0;
	return GLM_struct->wglCreateDisplayColorTableEXTproc(id);
}
GLboolean WINAPI wglLoadDisplayColorTableEXT(const GLushort* table, GLuint length){
	if(!GLM_struct->wglLoadDisplayColorTableEXTproc) return 0;
	return GLM_struct->wglLoadDisplayColorTableEXTproc(table, length);
}
GLboolean WINAPI wglBindDisplayColorTableEXT(GLushort id){
	if(!GLM_struct->wglBindDisplayColorTableEXTproc) return 0;
	return GLM_struct->wglBindDisplayColorTableEXTproc(id);
}
VOID WINAPI wglDestroyDisplayColorTableEXT(GLushort id){
	if(!GLM_struct->wglDestroyDisplayColorTableEXTproc) return;
	GLM_struct->wglDestroyDisplayColorTableEXTproc(id);
}
const char* WINAPI wglGetExtensionsStringEXT(void){
	if(!GLM_struct->wglGetExtensionsStringEXTproc) return 0;
	return GLM_struct->wglGetExtensionsStringEXTproc();
}
BOOL WINAPI wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc){
	if(!GLM_struct->wglMakeContextCurrentEXTproc) return 0;
	return GLM_struct->wglMakeContextCurrentEXTproc(hDrawDC, hReadDC, hglrc);
}
HDC WINAPI wglGetCurrentReadDCEXT(void){
	if(!GLM_struct->wglGetCurrentReadDCEXTproc) return 0;
	return GLM_struct->wglGetCurrentReadDCEXTproc();
}
HPBUFFEREXT WINAPI wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList){
	if(!GLM_struct->wglCreatePbufferEXTproc) return 0;
	return GLM_struct->wglCreatePbufferEXTproc(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
}
HDC WINAPI wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer){
	if(!GLM_struct->wglGetPbufferDCEXTproc) return 0;
	return GLM_struct->wglGetPbufferDCEXTproc(hPbuffer);
}
int WINAPI wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC){
	if(!GLM_struct->wglReleasePbufferDCEXTproc) return 0;
	return GLM_struct->wglReleasePbufferDCEXTproc(hPbuffer, hDC);
}
BOOL WINAPI wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer){
	if(!GLM_struct->wglDestroyPbufferEXTproc) return 0;
	return GLM_struct->wglDestroyPbufferEXTproc(hPbuffer);
}
BOOL WINAPI wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue){
	if(!GLM_struct->wglQueryPbufferEXTproc) return 0;
	return GLM_struct->wglQueryPbufferEXTproc(hPbuffer, iAttribute, piValue);
}
BOOL WINAPI wglGetPixelFormatAttribivEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues){
	if(!GLM_struct->wglGetPixelFormatAttribivEXTproc) return 0;
	return GLM_struct->wglGetPixelFormatAttribivEXTproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
}
BOOL WINAPI wglGetPixelFormatAttribfvEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues){
	if(!GLM_struct->wglGetPixelFormatAttribfvEXTproc) return 0;
	return GLM_struct->wglGetPixelFormatAttribfvEXTproc(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
}
BOOL WINAPI wglChoosePixelFormatEXT(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats){
	if(!GLM_struct->wglChoosePixelFormatEXTproc) return 0;
	return GLM_struct->wglChoosePixelFormatEXTproc(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}
BOOL WINAPI wglSwapIntervalEXT(int interval){
	if(!GLM_struct->wglSwapIntervalEXTproc) return 0;
	return GLM_struct->wglSwapIntervalEXTproc(interval);
}
int WINAPI wglGetSwapIntervalEXT(void){
	if(!GLM_struct->wglGetSwapIntervalEXTproc) return 0;
	return GLM_struct->wglGetSwapIntervalEXTproc();
}
BOOL WINAPI wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int* piValue){
	if(!GLM_struct->wglGetDigitalVideoParametersI3Dproc) return 0;
	return GLM_struct->wglGetDigitalVideoParametersI3Dproc(hDC, iAttribute, piValue);
}
BOOL WINAPI wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int* piValue){
	if(!GLM_struct->wglSetDigitalVideoParametersI3Dproc) return 0;
	return GLM_struct->wglSetDigitalVideoParametersI3Dproc(hDC, iAttribute, piValue);
}
BOOL WINAPI wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int* piValue){
	if(!GLM_struct->wglGetGammaTableParametersI3Dproc) return 0;
	return GLM_struct->wglGetGammaTableParametersI3Dproc(hDC, iAttribute, piValue);
}
BOOL WINAPI wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int* piValue){
	if(!GLM_struct->wglSetGammaTableParametersI3Dproc) return 0;
	return GLM_struct->wglSetGammaTableParametersI3Dproc(hDC, iAttribute, piValue);
}
BOOL WINAPI wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue){
	if(!GLM_struct->wglGetGammaTableI3Dproc) return 0;
	return GLM_struct->wglGetGammaTableI3Dproc(hDC, iEntries, puRed, puGreen, puBlue);
}
BOOL WINAPI wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue){
	if(!GLM_struct->wglSetGammaTableI3Dproc) return 0;
	return GLM_struct->wglSetGammaTableI3Dproc(hDC, iEntries, puRed, puGreen, puBlue);
}
BOOL WINAPI wglEnableGenlockI3D(HDC hDC){
	if(!GLM_struct->wglEnableGenlockI3Dproc) return 0;
	return GLM_struct->wglEnableGenlockI3Dproc(hDC);
}
BOOL WINAPI wglDisableGenlockI3D(HDC hDC){
	if(!GLM_struct->wglDisableGenlockI3Dproc) return 0;
	return GLM_struct->wglDisableGenlockI3Dproc(hDC);
}
BOOL WINAPI wglIsEnabledGenlockI3D(HDC hDC, BOOL* pFlag){
	if(!GLM_struct->wglIsEnabledGenlockI3Dproc) return 0;
	return GLM_struct->wglIsEnabledGenlockI3Dproc(hDC, pFlag);
}
BOOL WINAPI wglGenlockSourceI3D(HDC hDC, UINT uSource){
	if(!GLM_struct->wglGenlockSourceI3Dproc) return 0;
	return GLM_struct->wglGenlockSourceI3Dproc(hDC, uSource);
}
BOOL WINAPI wglGetGenlockSourceI3D(HDC hDC, UINT* uSource){
	if(!GLM_struct->wglGetGenlockSourceI3Dproc) return 0;
	return GLM_struct->wglGetGenlockSourceI3Dproc(hDC, uSource);
}
BOOL WINAPI wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge){
	if(!GLM_struct->wglGenlockSourceEdgeI3Dproc) return 0;
	return GLM_struct->wglGenlockSourceEdgeI3Dproc(hDC, uEdge);
}
BOOL WINAPI wglGetGenlockSourceEdgeI3D(HDC hDC, UINT* uEdge){
	if(!GLM_struct->wglGetGenlockSourceEdgeI3Dproc) return 0;
	return GLM_struct->wglGetGenlockSourceEdgeI3Dproc(hDC, uEdge);
}
BOOL WINAPI wglGenlockSampleRateI3D(HDC hDC, UINT uRate){
	if(!GLM_struct->wglGenlockSampleRateI3Dproc) return 0;
	return GLM_struct->wglGenlockSampleRateI3Dproc(hDC, uRate);
}
BOOL WINAPI wglGetGenlockSampleRateI3D(HDC hDC, UINT* uRate){
	if(!GLM_struct->wglGetGenlockSampleRateI3Dproc) return 0;
	return GLM_struct->wglGetGenlockSampleRateI3Dproc(hDC, uRate);
}
BOOL WINAPI wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay){
	if(!GLM_struct->wglGenlockSourceDelayI3Dproc) return 0;
	return GLM_struct->wglGenlockSourceDelayI3Dproc(hDC, uDelay);
}
BOOL WINAPI wglGetGenlockSourceDelayI3D(HDC hDC, UINT* uDelay){
	if(!GLM_struct->wglGetGenlockSourceDelayI3Dproc) return 0;
	return GLM_struct->wglGetGenlockSourceDelayI3Dproc(hDC, uDelay);
}
BOOL WINAPI wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay){
	if(!GLM_struct->wglQueryGenlockMaxSourceDelayI3Dproc) return 0;
	return GLM_struct->wglQueryGenlockMaxSourceDelayI3Dproc(hDC, uMaxLineDelay, uMaxPixelDelay);
}
LPVOID WINAPI wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags){
	if(!GLM_struct->wglCreateImageBufferI3Dproc) return 0;
	return GLM_struct->wglCreateImageBufferI3Dproc(hDC, dwSize, uFlags);
}
BOOL WINAPI wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress){
	if(!GLM_struct->wglDestroyImageBufferI3Dproc) return 0;
	return GLM_struct->wglDestroyImageBufferI3Dproc(hDC, pAddress);
}
BOOL WINAPI wglAssociateImageBufferEventsI3D(HDC hDC, const HANDLE* pEvent, const LPVOID* pAddress, const DWORD* pSize, UINT count){
	if(!GLM_struct->wglAssociateImageBufferEventsI3Dproc) return 0;
	return GLM_struct->wglAssociateImageBufferEventsI3Dproc(hDC, pEvent, pAddress, pSize, count);
}
BOOL WINAPI wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID* pAddress, UINT count){
	if(!GLM_struct->wglReleaseImageBufferEventsI3Dproc) return 0;
	return GLM_struct->wglReleaseImageBufferEventsI3Dproc(hDC, pAddress, count);
}
BOOL WINAPI wglEnableFrameLockI3D(void){
	if(!GLM_struct->wglEnableFrameLockI3Dproc) return 0;
	return GLM_struct->wglEnableFrameLockI3Dproc();
}
BOOL WINAPI wglDisableFrameLockI3D(void){
	if(!GLM_struct->wglDisableFrameLockI3Dproc) return 0;
	return GLM_struct->wglDisableFrameLockI3Dproc();
}
BOOL WINAPI wglIsEnabledFrameLockI3D(BOOL* pFlag){
	if(!GLM_struct->wglIsEnabledFrameLockI3Dproc) return 0;
	return GLM_struct->wglIsEnabledFrameLockI3Dproc(pFlag);
}
BOOL WINAPI wglQueryFrameLockMasterI3D(BOOL* pFlag){
	if(!GLM_struct->wglQueryFrameLockMasterI3Dproc) return 0;
	return GLM_struct->wglQueryFrameLockMasterI3Dproc(pFlag);
}
BOOL WINAPI wglGetFrameUsageI3D(float* pUsage){
	if(!GLM_struct->wglGetFrameUsageI3Dproc) return 0;
	return GLM_struct->wglGetFrameUsageI3Dproc(pUsage);
}
BOOL WINAPI wglBeginFrameTrackingI3D(void){
	if(!GLM_struct->wglBeginFrameTrackingI3Dproc) return 0;
	return GLM_struct->wglBeginFrameTrackingI3Dproc();
}
BOOL WINAPI wglEndFrameTrackingI3D(void){
	if(!GLM_struct->wglEndFrameTrackingI3Dproc) return 0;
	return GLM_struct->wglEndFrameTrackingI3Dproc();
}
BOOL WINAPI wglQueryFrameTrackingI3D(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage){
	if(!GLM_struct->wglQueryFrameTrackingI3Dproc) return 0;
	return GLM_struct->wglQueryFrameTrackingI3Dproc(pFrameCount, pMissedFrames, pLastMissedUsage);
}
BOOL WINAPI wglDXSetResourceShareHandleNV(void* dxObject, HANDLE shareHandle){
	if(!GLM_struct->wglDXSetResourceShareHandleNVproc) return 0;
	return GLM_struct->wglDXSetResourceShareHandleNVproc(dxObject, shareHandle);
}
HANDLE WINAPI wglDXOpenDeviceNV(void* dxDevice){
	if(!GLM_struct->wglDXOpenDeviceNVproc) return 0;
	return GLM_struct->wglDXOpenDeviceNVproc(dxDevice);
}
BOOL WINAPI wglDXCloseDeviceNV(HANDLE hDevice){
	if(!GLM_struct->wglDXCloseDeviceNVproc) return 0;
	return GLM_struct->wglDXCloseDeviceNVproc(hDevice);
}
HANDLE WINAPI wglDXRegisterObjectNV(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access){
	if(!GLM_struct->wglDXRegisterObjectNVproc) return 0;
	return GLM_struct->wglDXRegisterObjectNVproc(hDevice, dxObject, name, type, access);
}
BOOL WINAPI wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject){
	if(!GLM_struct->wglDXUnregisterObjectNVproc) return 0;
	return GLM_struct->wglDXUnregisterObjectNVproc(hDevice, hObject);
}
BOOL WINAPI wglDXObjectAccessNV(HANDLE hObject, GLenum access){
	if(!GLM_struct->wglDXObjectAccessNVproc) return 0;
	return GLM_struct->wglDXObjectAccessNVproc(hObject, access);
}
BOOL WINAPI wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects){
	if(!GLM_struct->wglDXLockObjectsNVproc) return 0;
	return GLM_struct->wglDXLockObjectsNVproc(hDevice, count, hObjects);
}
BOOL WINAPI wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects){
	if(!GLM_struct->wglDXUnlockObjectsNVproc) return 0;
	return GLM_struct->wglDXUnlockObjectsNVproc(hDevice, count, hObjects);
}
BOOL WINAPI wglCopyImageSubDataNV(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->wglCopyImageSubDataNVproc) return 0;
	return GLM_struct->wglCopyImageSubDataNVproc(hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}
BOOL WINAPI wglDelayBeforeSwapNV(HDC hDC, GLfloat seconds){
	if(!GLM_struct->wglDelayBeforeSwapNVproc) return 0;
	return GLM_struct->wglDelayBeforeSwapNVproc(hDC, seconds);
}
BOOL WINAPI wglEnumGpusNV(UINT iGpuIndex, HGPUNV* phGpu){
	if(!GLM_struct->wglEnumGpusNVproc) return 0;
	return GLM_struct->wglEnumGpusNVproc(iGpuIndex, phGpu);
}
BOOL WINAPI wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice){
	if(!GLM_struct->wglEnumGpuDevicesNVproc) return 0;
	return GLM_struct->wglEnumGpuDevicesNVproc(hGpu, iDeviceIndex, lpGpuDevice);
}
HDC WINAPI wglCreateAffinityDCNV(const HGPUNV* phGpuList){
	if(!GLM_struct->wglCreateAffinityDCNVproc) return 0;
	return GLM_struct->wglCreateAffinityDCNVproc(phGpuList);
}
BOOL WINAPI wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu){
	if(!GLM_struct->wglEnumGpusFromAffinityDCNVproc) return 0;
	return GLM_struct->wglEnumGpusFromAffinityDCNVproc(hAffinityDC, iGpuIndex, hGpu);
}
BOOL WINAPI wglDeleteDCNV(HDC hdc){
	if(!GLM_struct->wglDeleteDCNVproc) return 0;
	return GLM_struct->wglDeleteDCNVproc(hdc);
}
int WINAPI wglEnumerateVideoDevicesNV(HDC hDc, HVIDEOOUTPUTDEVICENV* phDeviceList){
	if(!GLM_struct->wglEnumerateVideoDevicesNVproc) return 0;
	return GLM_struct->wglEnumerateVideoDevicesNVproc(hDc, phDeviceList);
}
BOOL WINAPI wglBindVideoDeviceNV(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList){
	if(!GLM_struct->wglBindVideoDeviceNVproc) return 0;
	return GLM_struct->wglBindVideoDeviceNVproc(hDc, uVideoSlot, hVideoDevice, piAttribList);
}
BOOL WINAPI wglQueryCurrentContextNV(int iAttribute, int* piValue){
	if(!GLM_struct->wglQueryCurrentContextNVproc) return 0;
	return GLM_struct->wglQueryCurrentContextNVproc(iAttribute, piValue);
}
BOOL WINAPI wglJoinSwapGroupNV(HDC hDC, GLuint group){
	if(!GLM_struct->wglJoinSwapGroupNVproc) return 0;
	return GLM_struct->wglJoinSwapGroupNVproc(hDC, group);
}
BOOL WINAPI wglBindSwapBarrierNV(GLuint group, GLuint barrier){
	if(!GLM_struct->wglBindSwapBarrierNVproc) return 0;
	return GLM_struct->wglBindSwapBarrierNVproc(group, barrier);
}
BOOL WINAPI wglQuerySwapGroupNV(HDC hDC, GLuint* group, GLuint* barrier){
	if(!GLM_struct->wglQuerySwapGroupNVproc) return 0;
	return GLM_struct->wglQuerySwapGroupNVproc(hDC, group, barrier);
}
BOOL WINAPI wglQueryMaxSwapGroupsNV(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers){
	if(!GLM_struct->wglQueryMaxSwapGroupsNVproc) return 0;
	return GLM_struct->wglQueryMaxSwapGroupsNVproc(hDC, maxGroups, maxBarriers);
}
BOOL WINAPI wglQueryFrameCountNV(HDC hDC, GLuint* count){
	if(!GLM_struct->wglQueryFrameCountNVproc) return 0;
	return GLM_struct->wglQueryFrameCountNVproc(hDC, count);
}
BOOL WINAPI wglResetFrameCountNV(HDC hDC){
	if(!GLM_struct->wglResetFrameCountNVproc) return 0;
	return GLM_struct->wglResetFrameCountNVproc(hDC);
}
void* WINAPI wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority){
	if(!GLM_struct->wglAllocateMemoryNVproc) return 0;
	return GLM_struct->wglAllocateMemoryNVproc(size, readfreq, writefreq, priority);
}
void WINAPI wglFreeMemoryNV(void* pointer){
	if(!GLM_struct->wglFreeMemoryNVproc) return;
	GLM_struct->wglFreeMemoryNVproc(pointer);
}
BOOL WINAPI wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice){
	if(!GLM_struct->wglBindVideoCaptureDeviceNVproc) return 0;
	return GLM_struct->wglBindVideoCaptureDeviceNVproc(uVideoSlot, hDevice);
}
UINT WINAPI wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList){
	if(!GLM_struct->wglEnumerateVideoCaptureDevicesNVproc) return 0;
	return GLM_struct->wglEnumerateVideoCaptureDevicesNVproc(hDc, phDeviceList);
}
BOOL WINAPI wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice){
	if(!GLM_struct->wglLockVideoCaptureDeviceNVproc) return 0;
	return GLM_struct->wglLockVideoCaptureDeviceNVproc(hDc, hDevice);
}
BOOL WINAPI wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue){
	if(!GLM_struct->wglQueryVideoCaptureDeviceNVproc) return 0;
	return GLM_struct->wglQueryVideoCaptureDeviceNVproc(hDc, hDevice, iAttribute, piValue);
}
BOOL WINAPI wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice){
	if(!GLM_struct->wglReleaseVideoCaptureDeviceNVproc) return 0;
	return GLM_struct->wglReleaseVideoCaptureDeviceNVproc(hDc, hDevice);
}
BOOL WINAPI wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice){
	if(!GLM_struct->wglGetVideoDeviceNVproc) return 0;
	return GLM_struct->wglGetVideoDeviceNVproc(hDC, numDevices, hVideoDevice);
}
BOOL WINAPI wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice){
	if(!GLM_struct->wglReleaseVideoDeviceNVproc) return 0;
	return GLM_struct->wglReleaseVideoDeviceNVproc(hVideoDevice);
}
BOOL WINAPI wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer){
	if(!GLM_struct->wglBindVideoImageNVproc) return 0;
	return GLM_struct->wglBindVideoImageNVproc(hVideoDevice, hPbuffer, iVideoBuffer);
}
BOOL WINAPI wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer){
	if(!GLM_struct->wglReleaseVideoImageNVproc) return 0;
	return GLM_struct->wglReleaseVideoImageNVproc(hPbuffer, iVideoBuffer);
}
BOOL WINAPI wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock){
	if(!GLM_struct->wglSendPbufferToVideoNVproc) return 0;
	return GLM_struct->wglSendPbufferToVideoNVproc(hPbuffer, iBufferType, pulCounterPbuffer, bBlock);
}
BOOL WINAPI wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo){
	if(!GLM_struct->wglGetVideoInfoNVproc) return 0;
	return GLM_struct->wglGetVideoInfoNVproc(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);
}
BOOL WINAPI wglGetSyncValuesOML(HDC hdc, INT64* ust, INT64* msc, INT64* sbc){
	if(!GLM_struct->wglGetSyncValuesOMLproc) return 0;
	return GLM_struct->wglGetSyncValuesOMLproc(hdc, ust, msc, sbc);
}
BOOL WINAPI wglGetMscRateOML(HDC hdc, INT32* numerator, INT32* denominator){
	if(!GLM_struct->wglGetMscRateOMLproc) return 0;
	return GLM_struct->wglGetMscRateOMLproc(hdc, numerator, denominator);
}
INT64 WINAPI wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder){
	if(!GLM_struct->wglSwapBuffersMscOMLproc) return 0;
	return GLM_struct->wglSwapBuffersMscOMLproc(hdc, target_msc, divisor, remainder);
}
INT64 WINAPI wglSwapLayerBuffersMscOML(HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder){
	if(!GLM_struct->wglSwapLayerBuffersMscOMLproc) return 0;
	return GLM_struct->wglSwapLayerBuffersMscOMLproc(hdc, fuPlanes, target_msc, divisor, remainder);
}
BOOL WINAPI wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc){
	if(!GLM_struct->wglWaitForMscOMLproc) return 0;
	return GLM_struct->wglWaitForMscOMLproc(hdc, target_msc, divisor, remainder, ust, msc, sbc);
}
BOOL WINAPI wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc){
	if(!GLM_struct->wglWaitForSbcOMLproc) return 0;
	return GLM_struct->wglWaitForSbcOMLproc(hdc, target_sbc, ust, msc, sbc);
}
void APIENTRY glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices){
	if(!GLM_struct->glDrawRangeElementsproc) return;
	GLM_struct->glDrawRangeElementsproc(mode, start, end, count, type, indices);
}
void APIENTRY glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexImage3Dproc) return;
	GLM_struct->glTexImage3Dproc(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void APIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexSubImage3Dproc) return;
	GLM_struct->glTexSubImage3Dproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void APIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyTexSubImage3Dproc) return;
	GLM_struct->glCopyTexSubImage3Dproc(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void APIENTRY glActiveTexture(GLenum texture){
	if(!GLM_struct->glActiveTextureproc) return;
	GLM_struct->glActiveTextureproc(texture);
}
void APIENTRY glSampleCoverage(GLfloat value, GLboolean invert){
	if(!GLM_struct->glSampleCoverageproc) return;
	GLM_struct->glSampleCoverageproc(value, invert);
}
void APIENTRY glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexImage3Dproc) return;
	GLM_struct->glCompressedTexImage3Dproc(target, level, internalformat, width, height, depth, border, imageSize, data);
}
void APIENTRY glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexImage2Dproc) return;
	GLM_struct->glCompressedTexImage2Dproc(target, level, internalformat, width, height, border, imageSize, data);
}
void APIENTRY glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexImage1Dproc) return;
	GLM_struct->glCompressedTexImage1Dproc(target, level, internalformat, width, border, imageSize, data);
}
void APIENTRY glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexSubImage3Dproc) return;
	GLM_struct->glCompressedTexSubImage3Dproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void APIENTRY glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexSubImage2Dproc) return;
	GLM_struct->glCompressedTexSubImage2Dproc(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void APIENTRY glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexSubImage1Dproc) return;
	GLM_struct->glCompressedTexSubImage1Dproc(target, level, xoffset, width, format, imageSize, data);
}
void APIENTRY glGetCompressedTexImage(GLenum target, GLint level, void* img){
	if(!GLM_struct->glGetCompressedTexImageproc) return;
	GLM_struct->glGetCompressedTexImageproc(target, level, img);
}
void APIENTRY glClientActiveTexture(GLenum texture){
	if(!GLM_struct->glClientActiveTextureproc) return;
	GLM_struct->glClientActiveTextureproc(texture);
}
void APIENTRY glMultiTexCoord1d(GLenum target, GLdouble s){
	if(!GLM_struct->glMultiTexCoord1dproc) return;
	GLM_struct->glMultiTexCoord1dproc(target, s);
}
void APIENTRY glMultiTexCoord1dv(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord1dvproc) return;
	GLM_struct->glMultiTexCoord1dvproc(target, v);
}
void APIENTRY glMultiTexCoord1f(GLenum target, GLfloat s){
	if(!GLM_struct->glMultiTexCoord1fproc) return;
	GLM_struct->glMultiTexCoord1fproc(target, s);
}
void APIENTRY glMultiTexCoord1fv(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord1fvproc) return;
	GLM_struct->glMultiTexCoord1fvproc(target, v);
}
void APIENTRY glMultiTexCoord1i(GLenum target, GLint s){
	if(!GLM_struct->glMultiTexCoord1iproc) return;
	GLM_struct->glMultiTexCoord1iproc(target, s);
}
void APIENTRY glMultiTexCoord1iv(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord1ivproc) return;
	GLM_struct->glMultiTexCoord1ivproc(target, v);
}
void APIENTRY glMultiTexCoord1s(GLenum target, GLshort s){
	if(!GLM_struct->glMultiTexCoord1sproc) return;
	GLM_struct->glMultiTexCoord1sproc(target, s);
}
void APIENTRY glMultiTexCoord1sv(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord1svproc) return;
	GLM_struct->glMultiTexCoord1svproc(target, v);
}
void APIENTRY glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t){
	if(!GLM_struct->glMultiTexCoord2dproc) return;
	GLM_struct->glMultiTexCoord2dproc(target, s, t);
}
void APIENTRY glMultiTexCoord2dv(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord2dvproc) return;
	GLM_struct->glMultiTexCoord2dvproc(target, v);
}
void APIENTRY glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t){
	if(!GLM_struct->glMultiTexCoord2fproc) return;
	GLM_struct->glMultiTexCoord2fproc(target, s, t);
}
void APIENTRY glMultiTexCoord2fv(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord2fvproc) return;
	GLM_struct->glMultiTexCoord2fvproc(target, v);
}
void APIENTRY glMultiTexCoord2i(GLenum target, GLint s, GLint t){
	if(!GLM_struct->glMultiTexCoord2iproc) return;
	GLM_struct->glMultiTexCoord2iproc(target, s, t);
}
void APIENTRY glMultiTexCoord2iv(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord2ivproc) return;
	GLM_struct->glMultiTexCoord2ivproc(target, v);
}
void APIENTRY glMultiTexCoord2s(GLenum target, GLshort s, GLshort t){
	if(!GLM_struct->glMultiTexCoord2sproc) return;
	GLM_struct->glMultiTexCoord2sproc(target, s, t);
}
void APIENTRY glMultiTexCoord2sv(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord2svproc) return;
	GLM_struct->glMultiTexCoord2svproc(target, v);
}
void APIENTRY glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r){
	if(!GLM_struct->glMultiTexCoord3dproc) return;
	GLM_struct->glMultiTexCoord3dproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3dv(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord3dvproc) return;
	GLM_struct->glMultiTexCoord3dvproc(target, v);
}
void APIENTRY glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r){
	if(!GLM_struct->glMultiTexCoord3fproc) return;
	GLM_struct->glMultiTexCoord3fproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3fv(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord3fvproc) return;
	GLM_struct->glMultiTexCoord3fvproc(target, v);
}
void APIENTRY glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r){
	if(!GLM_struct->glMultiTexCoord3iproc) return;
	GLM_struct->glMultiTexCoord3iproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3iv(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord3ivproc) return;
	GLM_struct->glMultiTexCoord3ivproc(target, v);
}
void APIENTRY glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r){
	if(!GLM_struct->glMultiTexCoord3sproc) return;
	GLM_struct->glMultiTexCoord3sproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3sv(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord3svproc) return;
	GLM_struct->glMultiTexCoord3svproc(target, v);
}
void APIENTRY glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q){
	if(!GLM_struct->glMultiTexCoord4dproc) return;
	GLM_struct->glMultiTexCoord4dproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4dv(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord4dvproc) return;
	GLM_struct->glMultiTexCoord4dvproc(target, v);
}
void APIENTRY glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q){
	if(!GLM_struct->glMultiTexCoord4fproc) return;
	GLM_struct->glMultiTexCoord4fproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4fv(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord4fvproc) return;
	GLM_struct->glMultiTexCoord4fvproc(target, v);
}
void APIENTRY glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q){
	if(!GLM_struct->glMultiTexCoord4iproc) return;
	GLM_struct->glMultiTexCoord4iproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4iv(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord4ivproc) return;
	GLM_struct->glMultiTexCoord4ivproc(target, v);
}
void APIENTRY glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q){
	if(!GLM_struct->glMultiTexCoord4sproc) return;
	GLM_struct->glMultiTexCoord4sproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4sv(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord4svproc) return;
	GLM_struct->glMultiTexCoord4svproc(target, v);
}
void APIENTRY glLoadTransposeMatrixf(const GLfloat* m){
	if(!GLM_struct->glLoadTransposeMatrixfproc) return;
	GLM_struct->glLoadTransposeMatrixfproc(m);
}
void APIENTRY glLoadTransposeMatrixd(const GLdouble* m){
	if(!GLM_struct->glLoadTransposeMatrixdproc) return;
	GLM_struct->glLoadTransposeMatrixdproc(m);
}
void APIENTRY glMultTransposeMatrixf(const GLfloat* m){
	if(!GLM_struct->glMultTransposeMatrixfproc) return;
	GLM_struct->glMultTransposeMatrixfproc(m);
}
void APIENTRY glMultTransposeMatrixd(const GLdouble* m){
	if(!GLM_struct->glMultTransposeMatrixdproc) return;
	GLM_struct->glMultTransposeMatrixdproc(m);
}
void APIENTRY glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha){
	if(!GLM_struct->glBlendFuncSeparateproc) return;
	GLM_struct->glBlendFuncSeparateproc(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void APIENTRY glMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount){
	if(!GLM_struct->glMultiDrawArraysproc) return;
	GLM_struct->glMultiDrawArraysproc(mode, first, count, drawcount);
}
void APIENTRY glMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount){
	if(!GLM_struct->glMultiDrawElementsproc) return;
	GLM_struct->glMultiDrawElementsproc(mode, count, type, indices, drawcount);
}
void APIENTRY glPointParameterf(GLenum pname, GLfloat param){
	if(!GLM_struct->glPointParameterfproc) return;
	GLM_struct->glPointParameterfproc(pname, param);
}
void APIENTRY glPointParameterfv(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glPointParameterfvproc) return;
	GLM_struct->glPointParameterfvproc(pname, params);
}
void APIENTRY glPointParameteri(GLenum pname, GLint param){
	if(!GLM_struct->glPointParameteriproc) return;
	GLM_struct->glPointParameteriproc(pname, param);
}
void APIENTRY glPointParameteriv(GLenum pname, const GLint* params){
	if(!GLM_struct->glPointParameterivproc) return;
	GLM_struct->glPointParameterivproc(pname, params);
}
void APIENTRY glFogCoordf(GLfloat coord){
	if(!GLM_struct->glFogCoordfproc) return;
	GLM_struct->glFogCoordfproc(coord);
}
void APIENTRY glFogCoordfv(const GLfloat* coord){
	if(!GLM_struct->glFogCoordfvproc) return;
	GLM_struct->glFogCoordfvproc(coord);
}
void APIENTRY glFogCoordd(GLdouble coord){
	if(!GLM_struct->glFogCoorddproc) return;
	GLM_struct->glFogCoorddproc(coord);
}
void APIENTRY glFogCoorddv(const GLdouble* coord){
	if(!GLM_struct->glFogCoorddvproc) return;
	GLM_struct->glFogCoorddvproc(coord);
}
void APIENTRY glFogCoordPointer(GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glFogCoordPointerproc) return;
	GLM_struct->glFogCoordPointerproc(type, stride, pointer);
}
void APIENTRY glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue){
	if(!GLM_struct->glSecondaryColor3bproc) return;
	GLM_struct->glSecondaryColor3bproc(red, green, blue);
}
void APIENTRY glSecondaryColor3bv(const GLbyte* v){
	if(!GLM_struct->glSecondaryColor3bvproc) return;
	GLM_struct->glSecondaryColor3bvproc(v);
}
void APIENTRY glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue){
	if(!GLM_struct->glSecondaryColor3dproc) return;
	GLM_struct->glSecondaryColor3dproc(red, green, blue);
}
void APIENTRY glSecondaryColor3dv(const GLdouble* v){
	if(!GLM_struct->glSecondaryColor3dvproc) return;
	GLM_struct->glSecondaryColor3dvproc(v);
}
void APIENTRY glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue){
	if(!GLM_struct->glSecondaryColor3fproc) return;
	GLM_struct->glSecondaryColor3fproc(red, green, blue);
}
void APIENTRY glSecondaryColor3fv(const GLfloat* v){
	if(!GLM_struct->glSecondaryColor3fvproc) return;
	GLM_struct->glSecondaryColor3fvproc(v);
}
void APIENTRY glSecondaryColor3i(GLint red, GLint green, GLint blue){
	if(!GLM_struct->glSecondaryColor3iproc) return;
	GLM_struct->glSecondaryColor3iproc(red, green, blue);
}
void APIENTRY glSecondaryColor3iv(const GLint* v){
	if(!GLM_struct->glSecondaryColor3ivproc) return;
	GLM_struct->glSecondaryColor3ivproc(v);
}
void APIENTRY glSecondaryColor3s(GLshort red, GLshort green, GLshort blue){
	if(!GLM_struct->glSecondaryColor3sproc) return;
	GLM_struct->glSecondaryColor3sproc(red, green, blue);
}
void APIENTRY glSecondaryColor3sv(const GLshort* v){
	if(!GLM_struct->glSecondaryColor3svproc) return;
	GLM_struct->glSecondaryColor3svproc(v);
}
void APIENTRY glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue){
	if(!GLM_struct->glSecondaryColor3ubproc) return;
	GLM_struct->glSecondaryColor3ubproc(red, green, blue);
}
void APIENTRY glSecondaryColor3ubv(const GLubyte* v){
	if(!GLM_struct->glSecondaryColor3ubvproc) return;
	GLM_struct->glSecondaryColor3ubvproc(v);
}
void APIENTRY glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue){
	if(!GLM_struct->glSecondaryColor3uiproc) return;
	GLM_struct->glSecondaryColor3uiproc(red, green, blue);
}
void APIENTRY glSecondaryColor3uiv(const GLuint* v){
	if(!GLM_struct->glSecondaryColor3uivproc) return;
	GLM_struct->glSecondaryColor3uivproc(v);
}
void APIENTRY glSecondaryColor3us(GLushort red, GLushort green, GLushort blue){
	if(!GLM_struct->glSecondaryColor3usproc) return;
	GLM_struct->glSecondaryColor3usproc(red, green, blue);
}
void APIENTRY glSecondaryColor3usv(const GLushort* v){
	if(!GLM_struct->glSecondaryColor3usvproc) return;
	GLM_struct->glSecondaryColor3usvproc(v);
}
void APIENTRY glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glSecondaryColorPointerproc) return;
	GLM_struct->glSecondaryColorPointerproc(size, type, stride, pointer);
}
void APIENTRY glWindowPos2d(GLdouble x, GLdouble y){
	if(!GLM_struct->glWindowPos2dproc) return;
	GLM_struct->glWindowPos2dproc(x, y);
}
void APIENTRY glWindowPos2dv(const GLdouble* v){
	if(!GLM_struct->glWindowPos2dvproc) return;
	GLM_struct->glWindowPos2dvproc(v);
}
void APIENTRY glWindowPos2f(GLfloat x, GLfloat y){
	if(!GLM_struct->glWindowPos2fproc) return;
	GLM_struct->glWindowPos2fproc(x, y);
}
void APIENTRY glWindowPos2fv(const GLfloat* v){
	if(!GLM_struct->glWindowPos2fvproc) return;
	GLM_struct->glWindowPos2fvproc(v);
}
void APIENTRY glWindowPos2i(GLint x, GLint y){
	if(!GLM_struct->glWindowPos2iproc) return;
	GLM_struct->glWindowPos2iproc(x, y);
}
void APIENTRY glWindowPos2iv(const GLint* v){
	if(!GLM_struct->glWindowPos2ivproc) return;
	GLM_struct->glWindowPos2ivproc(v);
}
void APIENTRY glWindowPos2s(GLshort x, GLshort y){
	if(!GLM_struct->glWindowPos2sproc) return;
	GLM_struct->glWindowPos2sproc(x, y);
}
void APIENTRY glWindowPos2sv(const GLshort* v){
	if(!GLM_struct->glWindowPos2svproc) return;
	GLM_struct->glWindowPos2svproc(v);
}
void APIENTRY glWindowPos3d(GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glWindowPos3dproc) return;
	GLM_struct->glWindowPos3dproc(x, y, z);
}
void APIENTRY glWindowPos3dv(const GLdouble* v){
	if(!GLM_struct->glWindowPos3dvproc) return;
	GLM_struct->glWindowPos3dvproc(v);
}
void APIENTRY glWindowPos3f(GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glWindowPos3fproc) return;
	GLM_struct->glWindowPos3fproc(x, y, z);
}
void APIENTRY glWindowPos3fv(const GLfloat* v){
	if(!GLM_struct->glWindowPos3fvproc) return;
	GLM_struct->glWindowPos3fvproc(v);
}
void APIENTRY glWindowPos3i(GLint x, GLint y, GLint z){
	if(!GLM_struct->glWindowPos3iproc) return;
	GLM_struct->glWindowPos3iproc(x, y, z);
}
void APIENTRY glWindowPos3iv(const GLint* v){
	if(!GLM_struct->glWindowPos3ivproc) return;
	GLM_struct->glWindowPos3ivproc(v);
}
void APIENTRY glWindowPos3s(GLshort x, GLshort y, GLshort z){
	if(!GLM_struct->glWindowPos3sproc) return;
	GLM_struct->glWindowPos3sproc(x, y, z);
}
void APIENTRY glWindowPos3sv(const GLshort* v){
	if(!GLM_struct->glWindowPos3svproc) return;
	GLM_struct->glWindowPos3svproc(v);
}
void APIENTRY glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){
	if(!GLM_struct->glBlendColorproc) return;
	GLM_struct->glBlendColorproc(red, green, blue, alpha);
}
void APIENTRY glBlendEquation(GLenum mode){
	if(!GLM_struct->glBlendEquationproc) return;
	GLM_struct->glBlendEquationproc(mode);
}
void APIENTRY glGenQueries(GLsizei n, GLuint* ids){
	if(!GLM_struct->glGenQueriesproc) return;
	GLM_struct->glGenQueriesproc(n, ids);
}
void APIENTRY glDeleteQueries(GLsizei n, const GLuint* ids){
	if(!GLM_struct->glDeleteQueriesproc) return;
	GLM_struct->glDeleteQueriesproc(n, ids);
}
GLboolean APIENTRY glIsQuery(GLuint id){
	if(!GLM_struct->glIsQueryproc) return 0;
	return GLM_struct->glIsQueryproc(id);
}
void APIENTRY glBeginQuery(GLenum target, GLuint id){
	if(!GLM_struct->glBeginQueryproc) return;
	GLM_struct->glBeginQueryproc(target, id);
}
void APIENTRY glEndQuery(GLenum target){
	if(!GLM_struct->glEndQueryproc) return;
	GLM_struct->glEndQueryproc(target);
}
void APIENTRY glGetQueryiv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetQueryivproc) return;
	GLM_struct->glGetQueryivproc(target, pname, params);
}
void APIENTRY glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params){
	if(!GLM_struct->glGetQueryObjectivproc) return;
	GLM_struct->glGetQueryObjectivproc(id, pname, params);
}
void APIENTRY glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetQueryObjectuivproc) return;
	GLM_struct->glGetQueryObjectuivproc(id, pname, params);
}
void APIENTRY glBindBuffer(GLenum target, GLuint buffer){
	if(!GLM_struct->glBindBufferproc) return;
	GLM_struct->glBindBufferproc(target, buffer);
}
void APIENTRY glDeleteBuffers(GLsizei n, const GLuint* buffers){
	if(!GLM_struct->glDeleteBuffersproc) return;
	GLM_struct->glDeleteBuffersproc(n, buffers);
}
void APIENTRY glGenBuffers(GLsizei n, GLuint* buffers){
	if(!GLM_struct->glGenBuffersproc) return;
	GLM_struct->glGenBuffersproc(n, buffers);
}
GLboolean APIENTRY glIsBuffer(GLuint buffer){
	if(!GLM_struct->glIsBufferproc) return 0;
	return GLM_struct->glIsBufferproc(buffer);
}
void APIENTRY glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage){
	if(!GLM_struct->glBufferDataproc) return;
	GLM_struct->glBufferDataproc(target, size, data, usage);
}
void APIENTRY glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data){
	if(!GLM_struct->glBufferSubDataproc) return;
	GLM_struct->glBufferSubDataproc(target, offset, size, data);
}
void APIENTRY glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data){
	if(!GLM_struct->glGetBufferSubDataproc) return;
	GLM_struct->glGetBufferSubDataproc(target, offset, size, data);
}
void* APIENTRY glMapBuffer(GLenum target, GLenum access){
	if(!GLM_struct->glMapBufferproc) return 0;
	return GLM_struct->glMapBufferproc(target, access);
}
GLboolean APIENTRY glUnmapBuffer(GLenum target){
	if(!GLM_struct->glUnmapBufferproc) return 0;
	return GLM_struct->glUnmapBufferproc(target);
}
void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetBufferParameterivproc) return;
	GLM_struct->glGetBufferParameterivproc(target, pname, params);
}
void APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, void** params){
	if(!GLM_struct->glGetBufferPointervproc) return;
	GLM_struct->glGetBufferPointervproc(target, pname, params);
}
void APIENTRY glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha){
	if(!GLM_struct->glBlendEquationSeparateproc) return;
	GLM_struct->glBlendEquationSeparateproc(modeRGB, modeAlpha);
}
void APIENTRY glDrawBuffers(GLsizei n, const GLenum* bufs){
	if(!GLM_struct->glDrawBuffersproc) return;
	GLM_struct->glDrawBuffersproc(n, bufs);
}
void APIENTRY glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass){
	if(!GLM_struct->glStencilOpSeparateproc) return;
	GLM_struct->glStencilOpSeparateproc(face, sfail, dpfail, dppass);
}
void APIENTRY glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask){
	if(!GLM_struct->glStencilFuncSeparateproc) return;
	GLM_struct->glStencilFuncSeparateproc(face, func, ref, mask);
}
void APIENTRY glStencilMaskSeparate(GLenum face, GLuint mask){
	if(!GLM_struct->glStencilMaskSeparateproc) return;
	GLM_struct->glStencilMaskSeparateproc(face, mask);
}
void APIENTRY glAttachShader(GLuint program, GLuint shader){
	if(!GLM_struct->glAttachShaderproc) return;
	GLM_struct->glAttachShaderproc(program, shader);
}
void APIENTRY glBindAttribLocation(GLuint program, GLuint index, const GLchar* name){
	if(!GLM_struct->glBindAttribLocationproc) return;
	GLM_struct->glBindAttribLocationproc(program, index, name);
}
void APIENTRY glCompileShader(GLuint shader){
	if(!GLM_struct->glCompileShaderproc) return;
	GLM_struct->glCompileShaderproc(shader);
}
GLuint APIENTRY glCreateProgram(void){
	if(!GLM_struct->glCreateProgramproc) return 0;
	return GLM_struct->glCreateProgramproc();
}
GLuint APIENTRY glCreateShader(GLenum type){
	if(!GLM_struct->glCreateShaderproc) return 0;
	return GLM_struct->glCreateShaderproc(type);
}
void APIENTRY glDeleteProgram(GLuint program){
	if(!GLM_struct->glDeleteProgramproc) return;
	GLM_struct->glDeleteProgramproc(program);
}
void APIENTRY glDeleteShader(GLuint shader){
	if(!GLM_struct->glDeleteShaderproc) return;
	GLM_struct->glDeleteShaderproc(shader);
}
void APIENTRY glDetachShader(GLuint program, GLuint shader){
	if(!GLM_struct->glDetachShaderproc) return;
	GLM_struct->glDetachShaderproc(program, shader);
}
void APIENTRY glDisableVertexAttribArray(GLuint index){
	if(!GLM_struct->glDisableVertexAttribArrayproc) return;
	GLM_struct->glDisableVertexAttribArrayproc(index);
}
void APIENTRY glEnableVertexAttribArray(GLuint index){
	if(!GLM_struct->glEnableVertexAttribArrayproc) return;
	GLM_struct->glEnableVertexAttribArrayproc(index);
}
void APIENTRY glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name){
	if(!GLM_struct->glGetActiveAttribproc) return;
	GLM_struct->glGetActiveAttribproc(program, index, bufSize, length, size, type, name);
}
void APIENTRY glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name){
	if(!GLM_struct->glGetActiveUniformproc) return;
	GLM_struct->glGetActiveUniformproc(program, index, bufSize, length, size, type, name);
}
void APIENTRY glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders){
	if(!GLM_struct->glGetAttachedShadersproc) return;
	GLM_struct->glGetAttachedShadersproc(program, maxCount, count, shaders);
}
GLint APIENTRY glGetAttribLocation(GLuint program, const GLchar* name){
	if(!GLM_struct->glGetAttribLocationproc) return 0;
	return GLM_struct->glGetAttribLocationproc(program, name);
}
void APIENTRY glGetProgramiv(GLuint program, GLenum pname, GLint* params){
	if(!GLM_struct->glGetProgramivproc) return;
	GLM_struct->glGetProgramivproc(program, pname, params);
}
void APIENTRY glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog){
	if(!GLM_struct->glGetProgramInfoLogproc) return;
	GLM_struct->glGetProgramInfoLogproc(program, bufSize, length, infoLog);
}
void APIENTRY glGetShaderiv(GLuint shader, GLenum pname, GLint* params){
	if(!GLM_struct->glGetShaderivproc) return;
	GLM_struct->glGetShaderivproc(shader, pname, params);
}
void APIENTRY glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog){
	if(!GLM_struct->glGetShaderInfoLogproc) return;
	GLM_struct->glGetShaderInfoLogproc(shader, bufSize, length, infoLog);
}
void APIENTRY glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source){
	if(!GLM_struct->glGetShaderSourceproc) return;
	GLM_struct->glGetShaderSourceproc(shader, bufSize, length, source);
}
GLint APIENTRY glGetUniformLocation(GLuint program, const GLchar* name){
	if(!GLM_struct->glGetUniformLocationproc) return 0;
	return GLM_struct->glGetUniformLocationproc(program, name);
}
void APIENTRY glGetUniformfv(GLuint program, GLint location, GLfloat* params){
	if(!GLM_struct->glGetUniformfvproc) return;
	GLM_struct->glGetUniformfvproc(program, location, params);
}
void APIENTRY glGetUniformiv(GLuint program, GLint location, GLint* params){
	if(!GLM_struct->glGetUniformivproc) return;
	GLM_struct->glGetUniformivproc(program, location, params);
}
void APIENTRY glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetVertexAttribdvproc) return;
	GLM_struct->glGetVertexAttribdvproc(index, pname, params);
}
void APIENTRY glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetVertexAttribfvproc) return;
	GLM_struct->glGetVertexAttribfvproc(index, pname, params);
}
void APIENTRY glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVertexAttribivproc) return;
	GLM_struct->glGetVertexAttribivproc(index, pname, params);
}
void APIENTRY glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer){
	if(!GLM_struct->glGetVertexAttribPointervproc) return;
	GLM_struct->glGetVertexAttribPointervproc(index, pname, pointer);
}
GLboolean APIENTRY glIsProgram(GLuint program){
	if(!GLM_struct->glIsProgramproc) return 0;
	return GLM_struct->glIsProgramproc(program);
}
GLboolean APIENTRY glIsShader(GLuint shader){
	if(!GLM_struct->glIsShaderproc) return 0;
	return GLM_struct->glIsShaderproc(shader);
}
void APIENTRY glLinkProgram(GLuint program){
	if(!GLM_struct->glLinkProgramproc) return;
	GLM_struct->glLinkProgramproc(program);
}
void APIENTRY glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length){
	if(!GLM_struct->glShaderSourceproc) return;
	GLM_struct->glShaderSourceproc(shader, count, string, length);
}
void APIENTRY glUseProgram(GLuint program){
	if(!GLM_struct->glUseProgramproc) return;
	GLM_struct->glUseProgramproc(program);
}
void APIENTRY glUniform1f(GLint location, GLfloat v0){
	if(!GLM_struct->glUniform1fproc) return;
	GLM_struct->glUniform1fproc(location, v0);
}
void APIENTRY glUniform2f(GLint location, GLfloat v0, GLfloat v1){
	if(!GLM_struct->glUniform2fproc) return;
	GLM_struct->glUniform2fproc(location, v0, v1);
}
void APIENTRY glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2){
	if(!GLM_struct->glUniform3fproc) return;
	GLM_struct->glUniform3fproc(location, v0, v1, v2);
}
void APIENTRY glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3){
	if(!GLM_struct->glUniform4fproc) return;
	GLM_struct->glUniform4fproc(location, v0, v1, v2, v3);
}
void APIENTRY glUniform1i(GLint location, GLint v0){
	if(!GLM_struct->glUniform1iproc) return;
	GLM_struct->glUniform1iproc(location, v0);
}
void APIENTRY glUniform2i(GLint location, GLint v0, GLint v1){
	if(!GLM_struct->glUniform2iproc) return;
	GLM_struct->glUniform2iproc(location, v0, v1);
}
void APIENTRY glUniform3i(GLint location, GLint v0, GLint v1, GLint v2){
	if(!GLM_struct->glUniform3iproc) return;
	GLM_struct->glUniform3iproc(location, v0, v1, v2);
}
void APIENTRY glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3){
	if(!GLM_struct->glUniform4iproc) return;
	GLM_struct->glUniform4iproc(location, v0, v1, v2, v3);
}
void APIENTRY glUniform1fv(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform1fvproc) return;
	GLM_struct->glUniform1fvproc(location, count, value);
}
void APIENTRY glUniform2fv(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform2fvproc) return;
	GLM_struct->glUniform2fvproc(location, count, value);
}
void APIENTRY glUniform3fv(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform3fvproc) return;
	GLM_struct->glUniform3fvproc(location, count, value);
}
void APIENTRY glUniform4fv(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform4fvproc) return;
	GLM_struct->glUniform4fvproc(location, count, value);
}
void APIENTRY glUniform1iv(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform1ivproc) return;
	GLM_struct->glUniform1ivproc(location, count, value);
}
void APIENTRY glUniform2iv(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform2ivproc) return;
	GLM_struct->glUniform2ivproc(location, count, value);
}
void APIENTRY glUniform3iv(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform3ivproc) return;
	GLM_struct->glUniform3ivproc(location, count, value);
}
void APIENTRY glUniform4iv(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform4ivproc) return;
	GLM_struct->glUniform4ivproc(location, count, value);
}
void APIENTRY glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix2fvproc) return;
	GLM_struct->glUniformMatrix2fvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix3fvproc) return;
	GLM_struct->glUniformMatrix3fvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix4fvproc) return;
	GLM_struct->glUniformMatrix4fvproc(location, count, transpose, value);
}
void APIENTRY glValidateProgram(GLuint program){
	if(!GLM_struct->glValidateProgramproc) return;
	GLM_struct->glValidateProgramproc(program);
}
void APIENTRY glVertexAttrib1d(GLuint index, GLdouble x){
	if(!GLM_struct->glVertexAttrib1dproc) return;
	GLM_struct->glVertexAttrib1dproc(index, x);
}
void APIENTRY glVertexAttrib1dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib1dvproc) return;
	GLM_struct->glVertexAttrib1dvproc(index, v);
}
void APIENTRY glVertexAttrib1f(GLuint index, GLfloat x){
	if(!GLM_struct->glVertexAttrib1fproc) return;
	GLM_struct->glVertexAttrib1fproc(index, x);
}
void APIENTRY glVertexAttrib1fv(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib1fvproc) return;
	GLM_struct->glVertexAttrib1fvproc(index, v);
}
void APIENTRY glVertexAttrib1s(GLuint index, GLshort x){
	if(!GLM_struct->glVertexAttrib1sproc) return;
	GLM_struct->glVertexAttrib1sproc(index, x);
}
void APIENTRY glVertexAttrib1sv(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib1svproc) return;
	GLM_struct->glVertexAttrib1svproc(index, v);
}
void APIENTRY glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y){
	if(!GLM_struct->glVertexAttrib2dproc) return;
	GLM_struct->glVertexAttrib2dproc(index, x, y);
}
void APIENTRY glVertexAttrib2dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib2dvproc) return;
	GLM_struct->glVertexAttrib2dvproc(index, v);
}
void APIENTRY glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y){
	if(!GLM_struct->glVertexAttrib2fproc) return;
	GLM_struct->glVertexAttrib2fproc(index, x, y);
}
void APIENTRY glVertexAttrib2fv(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib2fvproc) return;
	GLM_struct->glVertexAttrib2fvproc(index, v);
}
void APIENTRY glVertexAttrib2s(GLuint index, GLshort x, GLshort y){
	if(!GLM_struct->glVertexAttrib2sproc) return;
	GLM_struct->glVertexAttrib2sproc(index, x, y);
}
void APIENTRY glVertexAttrib2sv(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib2svproc) return;
	GLM_struct->glVertexAttrib2svproc(index, v);
}
void APIENTRY glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glVertexAttrib3dproc) return;
	GLM_struct->glVertexAttrib3dproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib3dvproc) return;
	GLM_struct->glVertexAttrib3dvproc(index, v);
}
void APIENTRY glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glVertexAttrib3fproc) return;
	GLM_struct->glVertexAttrib3fproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3fv(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib3fvproc) return;
	GLM_struct->glVertexAttrib3fvproc(index, v);
}
void APIENTRY glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z){
	if(!GLM_struct->glVertexAttrib3sproc) return;
	GLM_struct->glVertexAttrib3sproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3sv(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib3svproc) return;
	GLM_struct->glVertexAttrib3svproc(index, v);
}
void APIENTRY glVertexAttrib4Nbv(GLuint index, const GLbyte* v){
	if(!GLM_struct->glVertexAttrib4Nbvproc) return;
	GLM_struct->glVertexAttrib4Nbvproc(index, v);
}
void APIENTRY glVertexAttrib4Niv(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttrib4Nivproc) return;
	GLM_struct->glVertexAttrib4Nivproc(index, v);
}
void APIENTRY glVertexAttrib4Nsv(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib4Nsvproc) return;
	GLM_struct->glVertexAttrib4Nsvproc(index, v);
}
void APIENTRY glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w){
	if(!GLM_struct->glVertexAttrib4Nubproc) return;
	GLM_struct->glVertexAttrib4Nubproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4Nubv(GLuint index, const GLubyte* v){
	if(!GLM_struct->glVertexAttrib4Nubvproc) return;
	GLM_struct->glVertexAttrib4Nubvproc(index, v);
}
void APIENTRY glVertexAttrib4Nuiv(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttrib4Nuivproc) return;
	GLM_struct->glVertexAttrib4Nuivproc(index, v);
}
void APIENTRY glVertexAttrib4Nusv(GLuint index, const GLushort* v){
	if(!GLM_struct->glVertexAttrib4Nusvproc) return;
	GLM_struct->glVertexAttrib4Nusvproc(index, v);
}
void APIENTRY glVertexAttrib4bv(GLuint index, const GLbyte* v){
	if(!GLM_struct->glVertexAttrib4bvproc) return;
	GLM_struct->glVertexAttrib4bvproc(index, v);
}
void APIENTRY glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glVertexAttrib4dproc) return;
	GLM_struct->glVertexAttrib4dproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib4dvproc) return;
	GLM_struct->glVertexAttrib4dvproc(index, v);
}
void APIENTRY glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glVertexAttrib4fproc) return;
	GLM_struct->glVertexAttrib4fproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4fv(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib4fvproc) return;
	GLM_struct->glVertexAttrib4fvproc(index, v);
}
void APIENTRY glVertexAttrib4iv(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttrib4ivproc) return;
	GLM_struct->glVertexAttrib4ivproc(index, v);
}
void APIENTRY glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w){
	if(!GLM_struct->glVertexAttrib4sproc) return;
	GLM_struct->glVertexAttrib4sproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4sv(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib4svproc) return;
	GLM_struct->glVertexAttrib4svproc(index, v);
}
void APIENTRY glVertexAttrib4ubv(GLuint index, const GLubyte* v){
	if(!GLM_struct->glVertexAttrib4ubvproc) return;
	GLM_struct->glVertexAttrib4ubvproc(index, v);
}
void APIENTRY glVertexAttrib4uiv(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttrib4uivproc) return;
	GLM_struct->glVertexAttrib4uivproc(index, v);
}
void APIENTRY glVertexAttrib4usv(GLuint index, const GLushort* v){
	if(!GLM_struct->glVertexAttrib4usvproc) return;
	GLM_struct->glVertexAttrib4usvproc(index, v);
}
void APIENTRY glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexAttribPointerproc) return;
	GLM_struct->glVertexAttribPointerproc(index, size, type, normalized, stride, pointer);
}
void APIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix2x3fvproc) return;
	GLM_struct->glUniformMatrix2x3fvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix3x2fvproc) return;
	GLM_struct->glUniformMatrix3x2fvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix2x4fvproc) return;
	GLM_struct->glUniformMatrix2x4fvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix4x2fvproc) return;
	GLM_struct->glUniformMatrix4x2fvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix3x4fvproc) return;
	GLM_struct->glUniformMatrix3x4fvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix4x3fvproc) return;
	GLM_struct->glUniformMatrix4x3fvproc(location, count, transpose, value);
}
void APIENTRY glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a){
	if(!GLM_struct->glColorMaskiproc) return;
	GLM_struct->glColorMaskiproc(index, r, g, b, a);
}
void APIENTRY glGetBooleani_v(GLenum target, GLuint index, GLboolean* data){
	if(!GLM_struct->glGetBooleani_vproc) return;
	GLM_struct->glGetBooleani_vproc(target, index, data);
}
void APIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint* data){
	if(!GLM_struct->glGetIntegeri_vproc) return;
	GLM_struct->glGetIntegeri_vproc(target, index, data);
}
void APIENTRY glEnablei(GLenum target, GLuint index){
	if(!GLM_struct->glEnableiproc) return;
	GLM_struct->glEnableiproc(target, index);
}
void APIENTRY glDisablei(GLenum target, GLuint index){
	if(!GLM_struct->glDisableiproc) return;
	GLM_struct->glDisableiproc(target, index);
}
GLboolean APIENTRY glIsEnabledi(GLenum target, GLuint index){
	if(!GLM_struct->glIsEnablediproc) return 0;
	return GLM_struct->glIsEnablediproc(target, index);
}
void APIENTRY glBeginTransformFeedback(GLenum primitiveMode){
	if(!GLM_struct->glBeginTransformFeedbackproc) return;
	GLM_struct->glBeginTransformFeedbackproc(primitiveMode);
}
void APIENTRY glEndTransformFeedback(void){
	if(!GLM_struct->glEndTransformFeedbackproc) return;
	GLM_struct->glEndTransformFeedbackproc();
}
void APIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glBindBufferRangeproc) return;
	GLM_struct->glBindBufferRangeproc(target, index, buffer, offset, size);
}
void APIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer){
	if(!GLM_struct->glBindBufferBaseproc) return;
	GLM_struct->glBindBufferBaseproc(target, index, buffer);
}
void APIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode){
	if(!GLM_struct->glTransformFeedbackVaryingsproc) return;
	GLM_struct->glTransformFeedbackVaryingsproc(program, count, varyings, bufferMode);
}
void APIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name){
	if(!GLM_struct->glGetTransformFeedbackVaryingproc) return;
	GLM_struct->glGetTransformFeedbackVaryingproc(program, index, bufSize, length, size, type, name);
}
void APIENTRY glClampColor(GLenum target, GLenum clamp){
	if(!GLM_struct->glClampColorproc) return;
	GLM_struct->glClampColorproc(target, clamp);
}
void APIENTRY glBeginConditionalRender(GLuint id, GLenum mode){
	if(!GLM_struct->glBeginConditionalRenderproc) return;
	GLM_struct->glBeginConditionalRenderproc(id, mode);
}
void APIENTRY glEndConditionalRender(void){
	if(!GLM_struct->glEndConditionalRenderproc) return;
	GLM_struct->glEndConditionalRenderproc();
}
void APIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexAttribIPointerproc) return;
	GLM_struct->glVertexAttribIPointerproc(index, size, type, stride, pointer);
}
void APIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVertexAttribIivproc) return;
	GLM_struct->glGetVertexAttribIivproc(index, pname, params);
}
void APIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetVertexAttribIuivproc) return;
	GLM_struct->glGetVertexAttribIuivproc(index, pname, params);
}
void APIENTRY glVertexAttribI1i(GLuint index, GLint x){
	if(!GLM_struct->glVertexAttribI1iproc) return;
	GLM_struct->glVertexAttribI1iproc(index, x);
}
void APIENTRY glVertexAttribI2i(GLuint index, GLint x, GLint y){
	if(!GLM_struct->glVertexAttribI2iproc) return;
	GLM_struct->glVertexAttribI2iproc(index, x, y);
}
void APIENTRY glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z){
	if(!GLM_struct->glVertexAttribI3iproc) return;
	GLM_struct->glVertexAttribI3iproc(index, x, y, z);
}
void APIENTRY glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w){
	if(!GLM_struct->glVertexAttribI4iproc) return;
	GLM_struct->glVertexAttribI4iproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribI1ui(GLuint index, GLuint x){
	if(!GLM_struct->glVertexAttribI1uiproc) return;
	GLM_struct->glVertexAttribI1uiproc(index, x);
}
void APIENTRY glVertexAttribI2ui(GLuint index, GLuint x, GLuint y){
	if(!GLM_struct->glVertexAttribI2uiproc) return;
	GLM_struct->glVertexAttribI2uiproc(index, x, y);
}
void APIENTRY glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z){
	if(!GLM_struct->glVertexAttribI3uiproc) return;
	GLM_struct->glVertexAttribI3uiproc(index, x, y, z);
}
void APIENTRY glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w){
	if(!GLM_struct->glVertexAttribI4uiproc) return;
	GLM_struct->glVertexAttribI4uiproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribI1iv(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI1ivproc) return;
	GLM_struct->glVertexAttribI1ivproc(index, v);
}
void APIENTRY glVertexAttribI2iv(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI2ivproc) return;
	GLM_struct->glVertexAttribI2ivproc(index, v);
}
void APIENTRY glVertexAttribI3iv(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI3ivproc) return;
	GLM_struct->glVertexAttribI3ivproc(index, v);
}
void APIENTRY glVertexAttribI4iv(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI4ivproc) return;
	GLM_struct->glVertexAttribI4ivproc(index, v);
}
void APIENTRY glVertexAttribI1uiv(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI1uivproc) return;
	GLM_struct->glVertexAttribI1uivproc(index, v);
}
void APIENTRY glVertexAttribI2uiv(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI2uivproc) return;
	GLM_struct->glVertexAttribI2uivproc(index, v);
}
void APIENTRY glVertexAttribI3uiv(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI3uivproc) return;
	GLM_struct->glVertexAttribI3uivproc(index, v);
}
void APIENTRY glVertexAttribI4uiv(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI4uivproc) return;
	GLM_struct->glVertexAttribI4uivproc(index, v);
}
void APIENTRY glVertexAttribI4bv(GLuint index, const GLbyte* v){
	if(!GLM_struct->glVertexAttribI4bvproc) return;
	GLM_struct->glVertexAttribI4bvproc(index, v);
}
void APIENTRY glVertexAttribI4sv(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttribI4svproc) return;
	GLM_struct->glVertexAttribI4svproc(index, v);
}
void APIENTRY glVertexAttribI4ubv(GLuint index, const GLubyte* v){
	if(!GLM_struct->glVertexAttribI4ubvproc) return;
	GLM_struct->glVertexAttribI4ubvproc(index, v);
}
void APIENTRY glVertexAttribI4usv(GLuint index, const GLushort* v){
	if(!GLM_struct->glVertexAttribI4usvproc) return;
	GLM_struct->glVertexAttribI4usvproc(index, v);
}
void APIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint* params){
	if(!GLM_struct->glGetUniformuivproc) return;
	GLM_struct->glGetUniformuivproc(program, location, params);
}
void APIENTRY glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name){
	if(!GLM_struct->glBindFragDataLocationproc) return;
	GLM_struct->glBindFragDataLocationproc(program, color, name);
}
GLint APIENTRY glGetFragDataLocation(GLuint program, const GLchar* name){
	if(!GLM_struct->glGetFragDataLocationproc) return 0;
	return GLM_struct->glGetFragDataLocationproc(program, name);
}
void APIENTRY glUniform1ui(GLint location, GLuint v0){
	if(!GLM_struct->glUniform1uiproc) return;
	GLM_struct->glUniform1uiproc(location, v0);
}
void APIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1){
	if(!GLM_struct->glUniform2uiproc) return;
	GLM_struct->glUniform2uiproc(location, v0, v1);
}
void APIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2){
	if(!GLM_struct->glUniform3uiproc) return;
	GLM_struct->glUniform3uiproc(location, v0, v1, v2);
}
void APIENTRY glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3){
	if(!GLM_struct->glUniform4uiproc) return;
	GLM_struct->glUniform4uiproc(location, v0, v1, v2, v3);
}
void APIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform1uivproc) return;
	GLM_struct->glUniform1uivproc(location, count, value);
}
void APIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform2uivproc) return;
	GLM_struct->glUniform2uivproc(location, count, value);
}
void APIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform3uivproc) return;
	GLM_struct->glUniform3uivproc(location, count, value);
}
void APIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform4uivproc) return;
	GLM_struct->glUniform4uivproc(location, count, value);
}
void APIENTRY glTexParameterIiv(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glTexParameterIivproc) return;
	GLM_struct->glTexParameterIivproc(target, pname, params);
}
void APIENTRY glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params){
	if(!GLM_struct->glTexParameterIuivproc) return;
	GLM_struct->glTexParameterIuivproc(target, pname, params);
}
void APIENTRY glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTexParameterIivproc) return;
	GLM_struct->glGetTexParameterIivproc(target, pname, params);
}
void APIENTRY glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetTexParameterIuivproc) return;
	GLM_struct->glGetTexParameterIuivproc(target, pname, params);
}
void APIENTRY glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value){
	if(!GLM_struct->glClearBufferivproc) return;
	GLM_struct->glClearBufferivproc(buffer, drawbuffer, value);
}
void APIENTRY glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value){
	if(!GLM_struct->glClearBufferuivproc) return;
	GLM_struct->glClearBufferuivproc(buffer, drawbuffer, value);
}
void APIENTRY glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value){
	if(!GLM_struct->glClearBufferfvproc) return;
	GLM_struct->glClearBufferfvproc(buffer, drawbuffer, value);
}
void APIENTRY glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil){
	if(!GLM_struct->glClearBufferfiproc) return;
	GLM_struct->glClearBufferfiproc(buffer, drawbuffer, depth, stencil);
}
const GLubyte* APIENTRY glGetStringi(GLenum name, GLuint index){
	if(!GLM_struct->glGetStringiproc) return 0;
	return GLM_struct->glGetStringiproc(name, index);
}
GLboolean APIENTRY glIsRenderbuffer(GLuint renderbuffer){
	if(!GLM_struct->glIsRenderbufferproc) return 0;
	return GLM_struct->glIsRenderbufferproc(renderbuffer);
}
void APIENTRY glBindRenderbuffer(GLenum target, GLuint renderbuffer){
	if(!GLM_struct->glBindRenderbufferproc) return;
	GLM_struct->glBindRenderbufferproc(target, renderbuffer);
}
void APIENTRY glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers){
	if(!GLM_struct->glDeleteRenderbuffersproc) return;
	GLM_struct->glDeleteRenderbuffersproc(n, renderbuffers);
}
void APIENTRY glGenRenderbuffers(GLsizei n, GLuint* renderbuffers){
	if(!GLM_struct->glGenRenderbuffersproc) return;
	GLM_struct->glGenRenderbuffersproc(n, renderbuffers);
}
void APIENTRY glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glRenderbufferStorageproc) return;
	GLM_struct->glRenderbufferStorageproc(target, internalformat, width, height);
}
void APIENTRY glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetRenderbufferParameterivproc) return;
	GLM_struct->glGetRenderbufferParameterivproc(target, pname, params);
}
GLboolean APIENTRY glIsFramebuffer(GLuint framebuffer){
	if(!GLM_struct->glIsFramebufferproc) return 0;
	return GLM_struct->glIsFramebufferproc(framebuffer);
}
void APIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer){
	if(!GLM_struct->glBindFramebufferproc) return;
	GLM_struct->glBindFramebufferproc(target, framebuffer);
}
void APIENTRY glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers){
	if(!GLM_struct->glDeleteFramebuffersproc) return;
	GLM_struct->glDeleteFramebuffersproc(n, framebuffers);
}
void APIENTRY glGenFramebuffers(GLsizei n, GLuint* framebuffers){
	if(!GLM_struct->glGenFramebuffersproc) return;
	GLM_struct->glGenFramebuffersproc(n, framebuffers);
}
GLenum APIENTRY glCheckFramebufferStatus(GLenum target){
	if(!GLM_struct->glCheckFramebufferStatusproc) return 0;
	return GLM_struct->glCheckFramebufferStatusproc(target);
}
void APIENTRY glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){
	if(!GLM_struct->glFramebufferTexture1Dproc) return;
	GLM_struct->glFramebufferTexture1Dproc(target, attachment, textarget, texture, level);
}
void APIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){
	if(!GLM_struct->glFramebufferTexture2Dproc) return;
	GLM_struct->glFramebufferTexture2Dproc(target, attachment, textarget, texture, level);
}
void APIENTRY glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset){
	if(!GLM_struct->glFramebufferTexture3Dproc) return;
	GLM_struct->glFramebufferTexture3Dproc(target, attachment, textarget, texture, level, zoffset);
}
void APIENTRY glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer){
	if(!GLM_struct->glFramebufferRenderbufferproc) return;
	GLM_struct->glFramebufferRenderbufferproc(target, attachment, renderbuffertarget, renderbuffer);
}
void APIENTRY glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFramebufferAttachmentParameterivproc) return;
	GLM_struct->glGetFramebufferAttachmentParameterivproc(target, attachment, pname, params);
}
void APIENTRY glGenerateMipmap(GLenum target){
	if(!GLM_struct->glGenerateMipmapproc) return;
	GLM_struct->glGenerateMipmapproc(target);
}
void APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){
	if(!GLM_struct->glBlitFramebufferproc) return;
	GLM_struct->glBlitFramebufferproc(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
void APIENTRY glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glRenderbufferStorageMultisampleproc) return;
	GLM_struct->glRenderbufferStorageMultisampleproc(target, samples, internalformat, width, height);
}
void APIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer){
	if(!GLM_struct->glFramebufferTextureLayerproc) return;
	GLM_struct->glFramebufferTextureLayerproc(target, attachment, texture, level, layer);
}
void* APIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access){
	if(!GLM_struct->glMapBufferRangeproc) return 0;
	return GLM_struct->glMapBufferRangeproc(target, offset, length, access);
}
void APIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length){
	if(!GLM_struct->glFlushMappedBufferRangeproc) return;
	GLM_struct->glFlushMappedBufferRangeproc(target, offset, length);
}
void APIENTRY glBindVertexArray(GLuint array){
	if(!GLM_struct->glBindVertexArrayproc) return;
	GLM_struct->glBindVertexArrayproc(array);
}
void APIENTRY glDeleteVertexArrays(GLsizei n, const GLuint* arrays){
	if(!GLM_struct->glDeleteVertexArraysproc) return;
	GLM_struct->glDeleteVertexArraysproc(n, arrays);
}
void APIENTRY glGenVertexArrays(GLsizei n, GLuint* arrays){
	if(!GLM_struct->glGenVertexArraysproc) return;
	GLM_struct->glGenVertexArraysproc(n, arrays);
}
GLboolean APIENTRY glIsVertexArray(GLuint array){
	if(!GLM_struct->glIsVertexArrayproc) return 0;
	return GLM_struct->glIsVertexArrayproc(array);
}
void APIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount){
	if(!GLM_struct->glDrawArraysInstancedproc) return;
	GLM_struct->glDrawArraysInstancedproc(mode, first, count, instancecount);
}
void APIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount){
	if(!GLM_struct->glDrawElementsInstancedproc) return;
	GLM_struct->glDrawElementsInstancedproc(mode, count, type, indices, instancecount);
}
void APIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer){
	if(!GLM_struct->glTexBufferproc) return;
	GLM_struct->glTexBufferproc(target, internalformat, buffer);
}
void APIENTRY glPrimitiveRestartIndex(GLuint index){
	if(!GLM_struct->glPrimitiveRestartIndexproc) return;
	GLM_struct->glPrimitiveRestartIndexproc(index);
}
void APIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size){
	if(!GLM_struct->glCopyBufferSubDataproc) return;
	GLM_struct->glCopyBufferSubDataproc(readTarget, writeTarget, readOffset, writeOffset, size);
}
void APIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices){
	if(!GLM_struct->glGetUniformIndicesproc) return;
	GLM_struct->glGetUniformIndicesproc(program, uniformCount, uniformNames, uniformIndices);
}
void APIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params){
	if(!GLM_struct->glGetActiveUniformsivproc) return;
	GLM_struct->glGetActiveUniformsivproc(program, uniformCount, uniformIndices, pname, params);
}
void APIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName){
	if(!GLM_struct->glGetActiveUniformNameproc) return;
	GLM_struct->glGetActiveUniformNameproc(program, uniformIndex, bufSize, length, uniformName);
}
GLuint APIENTRY glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName){
	if(!GLM_struct->glGetUniformBlockIndexproc) return 0;
	return GLM_struct->glGetUniformBlockIndexproc(program, uniformBlockName);
}
void APIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params){
	if(!GLM_struct->glGetActiveUniformBlockivproc) return;
	GLM_struct->glGetActiveUniformBlockivproc(program, uniformBlockIndex, pname, params);
}
void APIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName){
	if(!GLM_struct->glGetActiveUniformBlockNameproc) return;
	GLM_struct->glGetActiveUniformBlockNameproc(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
void APIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding){
	if(!GLM_struct->glUniformBlockBindingproc) return;
	GLM_struct->glUniformBlockBindingproc(program, uniformBlockIndex, uniformBlockBinding);
}
void APIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex){
	if(!GLM_struct->glDrawElementsBaseVertexproc) return;
	GLM_struct->glDrawElementsBaseVertexproc(mode, count, type, indices, basevertex);
}
void APIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex){
	if(!GLM_struct->glDrawRangeElementsBaseVertexproc) return;
	GLM_struct->glDrawRangeElementsBaseVertexproc(mode, start, end, count, type, indices, basevertex);
}
void APIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex){
	if(!GLM_struct->glDrawElementsInstancedBaseVertexproc) return;
	GLM_struct->glDrawElementsInstancedBaseVertexproc(mode, count, type, indices, instancecount, basevertex);
}
void APIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex){
	if(!GLM_struct->glMultiDrawElementsBaseVertexproc) return;
	GLM_struct->glMultiDrawElementsBaseVertexproc(mode, count, type, indices, drawcount, basevertex);
}
void APIENTRY glProvokingVertex(GLenum mode){
	if(!GLM_struct->glProvokingVertexproc) return;
	GLM_struct->glProvokingVertexproc(mode);
}
GLsync APIENTRY glFenceSync(GLenum condition, GLbitfield flags){
	if(!GLM_struct->glFenceSyncproc) return 0;
	return GLM_struct->glFenceSyncproc(condition, flags);
}
GLboolean APIENTRY glIsSync(GLsync sync){
	if(!GLM_struct->glIsSyncproc) return 0;
	return GLM_struct->glIsSyncproc(sync);
}
void APIENTRY glDeleteSync(GLsync sync){
	if(!GLM_struct->glDeleteSyncproc) return;
	GLM_struct->glDeleteSyncproc(sync);
}
GLenum APIENTRY glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout){
	if(!GLM_struct->glClientWaitSyncproc) return 0;
	return GLM_struct->glClientWaitSyncproc(sync, flags, timeout);
}
void APIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout){
	if(!GLM_struct->glWaitSyncproc) return;
	GLM_struct->glWaitSyncproc(sync, flags, timeout);
}
void APIENTRY glGetInteger64v(GLenum pname, GLint64* data){
	if(!GLM_struct->glGetInteger64vproc) return;
	GLM_struct->glGetInteger64vproc(pname, data);
}
void APIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values){
	if(!GLM_struct->glGetSyncivproc) return;
	GLM_struct->glGetSyncivproc(sync, pname, count, length, values);
}
void APIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64* data){
	if(!GLM_struct->glGetInteger64i_vproc) return;
	GLM_struct->glGetInteger64i_vproc(target, index, data);
}
void APIENTRY glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params){
	if(!GLM_struct->glGetBufferParameteri64vproc) return;
	GLM_struct->glGetBufferParameteri64vproc(target, pname, params);
}
void APIENTRY glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level){
	if(!GLM_struct->glFramebufferTextureproc) return;
	GLM_struct->glFramebufferTextureproc(target, attachment, texture, level);
}
void APIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTexImage2DMultisampleproc) return;
	GLM_struct->glTexImage2DMultisampleproc(target, samples, internalformat, width, height, fixedsamplelocations);
}
void APIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTexImage3DMultisampleproc) return;
	GLM_struct->glTexImage3DMultisampleproc(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void APIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val){
	if(!GLM_struct->glGetMultisamplefvproc) return;
	GLM_struct->glGetMultisamplefvproc(pname, index, val);
}
void APIENTRY glSampleMaski(GLuint maskNumber, GLbitfield mask){
	if(!GLM_struct->glSampleMaskiproc) return;
	GLM_struct->glSampleMaskiproc(maskNumber, mask);
}
void APIENTRY glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name){
	if(!GLM_struct->glBindFragDataLocationIndexedproc) return;
	GLM_struct->glBindFragDataLocationIndexedproc(program, colorNumber, index, name);
}
GLint APIENTRY glGetFragDataIndex(GLuint program, const GLchar* name){
	if(!GLM_struct->glGetFragDataIndexproc) return 0;
	return GLM_struct->glGetFragDataIndexproc(program, name);
}
void APIENTRY glGenSamplers(GLsizei count, GLuint* samplers){
	if(!GLM_struct->glGenSamplersproc) return;
	GLM_struct->glGenSamplersproc(count, samplers);
}
void APIENTRY glDeleteSamplers(GLsizei count, const GLuint* samplers){
	if(!GLM_struct->glDeleteSamplersproc) return;
	GLM_struct->glDeleteSamplersproc(count, samplers);
}
GLboolean APIENTRY glIsSampler(GLuint sampler){
	if(!GLM_struct->glIsSamplerproc) return 0;
	return GLM_struct->glIsSamplerproc(sampler);
}
void APIENTRY glBindSampler(GLuint unit, GLuint sampler){
	if(!GLM_struct->glBindSamplerproc) return;
	GLM_struct->glBindSamplerproc(unit, sampler);
}
void APIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param){
	if(!GLM_struct->glSamplerParameteriproc) return;
	GLM_struct->glSamplerParameteriproc(sampler, pname, param);
}
void APIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param){
	if(!GLM_struct->glSamplerParameterivproc) return;
	GLM_struct->glSamplerParameterivproc(sampler, pname, param);
}
void APIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param){
	if(!GLM_struct->glSamplerParameterfproc) return;
	GLM_struct->glSamplerParameterfproc(sampler, pname, param);
}
void APIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param){
	if(!GLM_struct->glSamplerParameterfvproc) return;
	GLM_struct->glSamplerParameterfvproc(sampler, pname, param);
}
void APIENTRY glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param){
	if(!GLM_struct->glSamplerParameterIivproc) return;
	GLM_struct->glSamplerParameterIivproc(sampler, pname, param);
}
void APIENTRY glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param){
	if(!GLM_struct->glSamplerParameterIuivproc) return;
	GLM_struct->glSamplerParameterIuivproc(sampler, pname, param);
}
void APIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params){
	if(!GLM_struct->glGetSamplerParameterivproc) return;
	GLM_struct->glGetSamplerParameterivproc(sampler, pname, params);
}
void APIENTRY glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params){
	if(!GLM_struct->glGetSamplerParameterIivproc) return;
	GLM_struct->glGetSamplerParameterIivproc(sampler, pname, params);
}
void APIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetSamplerParameterfvproc) return;
	GLM_struct->glGetSamplerParameterfvproc(sampler, pname, params);
}
void APIENTRY glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetSamplerParameterIuivproc) return;
	GLM_struct->glGetSamplerParameterIuivproc(sampler, pname, params);
}
void APIENTRY glQueryCounter(GLuint id, GLenum target){
	if(!GLM_struct->glQueryCounterproc) return;
	GLM_struct->glQueryCounterproc(id, target);
}
void APIENTRY glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params){
	if(!GLM_struct->glGetQueryObjecti64vproc) return;
	GLM_struct->glGetQueryObjecti64vproc(id, pname, params);
}
void APIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params){
	if(!GLM_struct->glGetQueryObjectui64vproc) return;
	GLM_struct->glGetQueryObjectui64vproc(id, pname, params);
}
void APIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor){
	if(!GLM_struct->glVertexAttribDivisorproc) return;
	GLM_struct->glVertexAttribDivisorproc(index, divisor);
}
void APIENTRY glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){
	if(!GLM_struct->glVertexAttribP1uiproc) return;
	GLM_struct->glVertexAttribP1uiproc(index, type, normalized, value);
}
void APIENTRY glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value){
	if(!GLM_struct->glVertexAttribP1uivproc) return;
	GLM_struct->glVertexAttribP1uivproc(index, type, normalized, value);
}
void APIENTRY glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){
	if(!GLM_struct->glVertexAttribP2uiproc) return;
	GLM_struct->glVertexAttribP2uiproc(index, type, normalized, value);
}
void APIENTRY glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value){
	if(!GLM_struct->glVertexAttribP2uivproc) return;
	GLM_struct->glVertexAttribP2uivproc(index, type, normalized, value);
}
void APIENTRY glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){
	if(!GLM_struct->glVertexAttribP3uiproc) return;
	GLM_struct->glVertexAttribP3uiproc(index, type, normalized, value);
}
void APIENTRY glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value){
	if(!GLM_struct->glVertexAttribP3uivproc) return;
	GLM_struct->glVertexAttribP3uivproc(index, type, normalized, value);
}
void APIENTRY glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value){
	if(!GLM_struct->glVertexAttribP4uiproc) return;
	GLM_struct->glVertexAttribP4uiproc(index, type, normalized, value);
}
void APIENTRY glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value){
	if(!GLM_struct->glVertexAttribP4uivproc) return;
	GLM_struct->glVertexAttribP4uivproc(index, type, normalized, value);
}
void APIENTRY glVertexP2ui(GLenum type, GLuint value){
	if(!GLM_struct->glVertexP2uiproc) return;
	GLM_struct->glVertexP2uiproc(type, value);
}
void APIENTRY glVertexP2uiv(GLenum type, const GLuint* value){
	if(!GLM_struct->glVertexP2uivproc) return;
	GLM_struct->glVertexP2uivproc(type, value);
}
void APIENTRY glVertexP3ui(GLenum type, GLuint value){
	if(!GLM_struct->glVertexP3uiproc) return;
	GLM_struct->glVertexP3uiproc(type, value);
}
void APIENTRY glVertexP3uiv(GLenum type, const GLuint* value){
	if(!GLM_struct->glVertexP3uivproc) return;
	GLM_struct->glVertexP3uivproc(type, value);
}
void APIENTRY glVertexP4ui(GLenum type, GLuint value){
	if(!GLM_struct->glVertexP4uiproc) return;
	GLM_struct->glVertexP4uiproc(type, value);
}
void APIENTRY glVertexP4uiv(GLenum type, const GLuint* value){
	if(!GLM_struct->glVertexP4uivproc) return;
	GLM_struct->glVertexP4uivproc(type, value);
}
void APIENTRY glTexCoordP1ui(GLenum type, GLuint coords){
	if(!GLM_struct->glTexCoordP1uiproc) return;
	GLM_struct->glTexCoordP1uiproc(type, coords);
}
void APIENTRY glTexCoordP1uiv(GLenum type, const GLuint* coords){
	if(!GLM_struct->glTexCoordP1uivproc) return;
	GLM_struct->glTexCoordP1uivproc(type, coords);
}
void APIENTRY glTexCoordP2ui(GLenum type, GLuint coords){
	if(!GLM_struct->glTexCoordP2uiproc) return;
	GLM_struct->glTexCoordP2uiproc(type, coords);
}
void APIENTRY glTexCoordP2uiv(GLenum type, const GLuint* coords){
	if(!GLM_struct->glTexCoordP2uivproc) return;
	GLM_struct->glTexCoordP2uivproc(type, coords);
}
void APIENTRY glTexCoordP3ui(GLenum type, GLuint coords){
	if(!GLM_struct->glTexCoordP3uiproc) return;
	GLM_struct->glTexCoordP3uiproc(type, coords);
}
void APIENTRY glTexCoordP3uiv(GLenum type, const GLuint* coords){
	if(!GLM_struct->glTexCoordP3uivproc) return;
	GLM_struct->glTexCoordP3uivproc(type, coords);
}
void APIENTRY glTexCoordP4ui(GLenum type, GLuint coords){
	if(!GLM_struct->glTexCoordP4uiproc) return;
	GLM_struct->glTexCoordP4uiproc(type, coords);
}
void APIENTRY glTexCoordP4uiv(GLenum type, const GLuint* coords){
	if(!GLM_struct->glTexCoordP4uivproc) return;
	GLM_struct->glTexCoordP4uivproc(type, coords);
}
void APIENTRY glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords){
	if(!GLM_struct->glMultiTexCoordP1uiproc) return;
	GLM_struct->glMultiTexCoordP1uiproc(texture, type, coords);
}
void APIENTRY glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint* coords){
	if(!GLM_struct->glMultiTexCoordP1uivproc) return;
	GLM_struct->glMultiTexCoordP1uivproc(texture, type, coords);
}
void APIENTRY glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords){
	if(!GLM_struct->glMultiTexCoordP2uiproc) return;
	GLM_struct->glMultiTexCoordP2uiproc(texture, type, coords);
}
void APIENTRY glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint* coords){
	if(!GLM_struct->glMultiTexCoordP2uivproc) return;
	GLM_struct->glMultiTexCoordP2uivproc(texture, type, coords);
}
void APIENTRY glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords){
	if(!GLM_struct->glMultiTexCoordP3uiproc) return;
	GLM_struct->glMultiTexCoordP3uiproc(texture, type, coords);
}
void APIENTRY glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint* coords){
	if(!GLM_struct->glMultiTexCoordP3uivproc) return;
	GLM_struct->glMultiTexCoordP3uivproc(texture, type, coords);
}
void APIENTRY glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords){
	if(!GLM_struct->glMultiTexCoordP4uiproc) return;
	GLM_struct->glMultiTexCoordP4uiproc(texture, type, coords);
}
void APIENTRY glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint* coords){
	if(!GLM_struct->glMultiTexCoordP4uivproc) return;
	GLM_struct->glMultiTexCoordP4uivproc(texture, type, coords);
}
void APIENTRY glNormalP3ui(GLenum type, GLuint coords){
	if(!GLM_struct->glNormalP3uiproc) return;
	GLM_struct->glNormalP3uiproc(type, coords);
}
void APIENTRY glNormalP3uiv(GLenum type, const GLuint* coords){
	if(!GLM_struct->glNormalP3uivproc) return;
	GLM_struct->glNormalP3uivproc(type, coords);
}
void APIENTRY glColorP3ui(GLenum type, GLuint color){
	if(!GLM_struct->glColorP3uiproc) return;
	GLM_struct->glColorP3uiproc(type, color);
}
void APIENTRY glColorP3uiv(GLenum type, const GLuint* color){
	if(!GLM_struct->glColorP3uivproc) return;
	GLM_struct->glColorP3uivproc(type, color);
}
void APIENTRY glColorP4ui(GLenum type, GLuint color){
	if(!GLM_struct->glColorP4uiproc) return;
	GLM_struct->glColorP4uiproc(type, color);
}
void APIENTRY glColorP4uiv(GLenum type, const GLuint* color){
	if(!GLM_struct->glColorP4uivproc) return;
	GLM_struct->glColorP4uivproc(type, color);
}
void APIENTRY glSecondaryColorP3ui(GLenum type, GLuint color){
	if(!GLM_struct->glSecondaryColorP3uiproc) return;
	GLM_struct->glSecondaryColorP3uiproc(type, color);
}
void APIENTRY glSecondaryColorP3uiv(GLenum type, const GLuint* color){
	if(!GLM_struct->glSecondaryColorP3uivproc) return;
	GLM_struct->glSecondaryColorP3uivproc(type, color);
}
void APIENTRY glMinSampleShading(GLfloat value){
	if(!GLM_struct->glMinSampleShadingproc) return;
	GLM_struct->glMinSampleShadingproc(value);
}
void APIENTRY glBlendEquationi(GLuint buf, GLenum mode){
	if(!GLM_struct->glBlendEquationiproc) return;
	GLM_struct->glBlendEquationiproc(buf, mode);
}
void APIENTRY glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha){
	if(!GLM_struct->glBlendEquationSeparateiproc) return;
	GLM_struct->glBlendEquationSeparateiproc(buf, modeRGB, modeAlpha);
}
void APIENTRY glBlendFunci(GLuint buf, GLenum src, GLenum dst){
	if(!GLM_struct->glBlendFunciproc) return;
	GLM_struct->glBlendFunciproc(buf, src, dst);
}
void APIENTRY glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha){
	if(!GLM_struct->glBlendFuncSeparateiproc) return;
	GLM_struct->glBlendFuncSeparateiproc(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void APIENTRY glDrawArraysIndirect(GLenum mode, const void* indirect){
	if(!GLM_struct->glDrawArraysIndirectproc) return;
	GLM_struct->glDrawArraysIndirectproc(mode, indirect);
}
void APIENTRY glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect){
	if(!GLM_struct->glDrawElementsIndirectproc) return;
	GLM_struct->glDrawElementsIndirectproc(mode, type, indirect);
}
void APIENTRY glUniform1d(GLint location, GLdouble x){
	if(!GLM_struct->glUniform1dproc) return;
	GLM_struct->glUniform1dproc(location, x);
}
void APIENTRY glUniform2d(GLint location, GLdouble x, GLdouble y){
	if(!GLM_struct->glUniform2dproc) return;
	GLM_struct->glUniform2dproc(location, x, y);
}
void APIENTRY glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glUniform3dproc) return;
	GLM_struct->glUniform3dproc(location, x, y, z);
}
void APIENTRY glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glUniform4dproc) return;
	GLM_struct->glUniform4dproc(location, x, y, z, w);
}
void APIENTRY glUniform1dv(GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glUniform1dvproc) return;
	GLM_struct->glUniform1dvproc(location, count, value);
}
void APIENTRY glUniform2dv(GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glUniform2dvproc) return;
	GLM_struct->glUniform2dvproc(location, count, value);
}
void APIENTRY glUniform3dv(GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glUniform3dvproc) return;
	GLM_struct->glUniform3dvproc(location, count, value);
}
void APIENTRY glUniform4dv(GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glUniform4dvproc) return;
	GLM_struct->glUniform4dvproc(location, count, value);
}
void APIENTRY glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix2dvproc) return;
	GLM_struct->glUniformMatrix2dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix3dvproc) return;
	GLM_struct->glUniformMatrix3dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix4dvproc) return;
	GLM_struct->glUniformMatrix4dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix2x3dvproc) return;
	GLM_struct->glUniformMatrix2x3dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix2x4dvproc) return;
	GLM_struct->glUniformMatrix2x4dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix3x2dvproc) return;
	GLM_struct->glUniformMatrix3x2dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix3x4dvproc) return;
	GLM_struct->glUniformMatrix3x4dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix4x2dvproc) return;
	GLM_struct->glUniformMatrix4x2dvproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glUniformMatrix4x3dvproc) return;
	GLM_struct->glUniformMatrix4x3dvproc(location, count, transpose, value);
}
void APIENTRY glGetUniformdv(GLuint program, GLint location, GLdouble* params){
	if(!GLM_struct->glGetUniformdvproc) return;
	GLM_struct->glGetUniformdvproc(program, location, params);
}
GLint APIENTRY glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name){
	if(!GLM_struct->glGetSubroutineUniformLocationproc) return 0;
	return GLM_struct->glGetSubroutineUniformLocationproc(program, shadertype, name);
}
GLuint APIENTRY glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name){
	if(!GLM_struct->glGetSubroutineIndexproc) return 0;
	return GLM_struct->glGetSubroutineIndexproc(program, shadertype, name);
}
void APIENTRY glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values){
	if(!GLM_struct->glGetActiveSubroutineUniformivproc) return;
	GLM_struct->glGetActiveSubroutineUniformivproc(program, shadertype, index, pname, values);
}
void APIENTRY glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name){
	if(!GLM_struct->glGetActiveSubroutineUniformNameproc) return;
	GLM_struct->glGetActiveSubroutineUniformNameproc(program, shadertype, index, bufSize, length, name);
}
void APIENTRY glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name){
	if(!GLM_struct->glGetActiveSubroutineNameproc) return;
	GLM_struct->glGetActiveSubroutineNameproc(program, shadertype, index, bufSize, length, name);
}
void APIENTRY glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices){
	if(!GLM_struct->glUniformSubroutinesuivproc) return;
	GLM_struct->glUniformSubroutinesuivproc(shadertype, count, indices);
}
void APIENTRY glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params){
	if(!GLM_struct->glGetUniformSubroutineuivproc) return;
	GLM_struct->glGetUniformSubroutineuivproc(shadertype, location, params);
}
void APIENTRY glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values){
	if(!GLM_struct->glGetProgramStageivproc) return;
	GLM_struct->glGetProgramStageivproc(program, shadertype, pname, values);
}
void APIENTRY glPatchParameteri(GLenum pname, GLint value){
	if(!GLM_struct->glPatchParameteriproc) return;
	GLM_struct->glPatchParameteriproc(pname, value);
}
void APIENTRY glPatchParameterfv(GLenum pname, const GLfloat* values){
	if(!GLM_struct->glPatchParameterfvproc) return;
	GLM_struct->glPatchParameterfvproc(pname, values);
}
void APIENTRY glBindTransformFeedback(GLenum target, GLuint id){
	if(!GLM_struct->glBindTransformFeedbackproc) return;
	GLM_struct->glBindTransformFeedbackproc(target, id);
}
void APIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids){
	if(!GLM_struct->glDeleteTransformFeedbacksproc) return;
	GLM_struct->glDeleteTransformFeedbacksproc(n, ids);
}
void APIENTRY glGenTransformFeedbacks(GLsizei n, GLuint* ids){
	if(!GLM_struct->glGenTransformFeedbacksproc) return;
	GLM_struct->glGenTransformFeedbacksproc(n, ids);
}
GLboolean APIENTRY glIsTransformFeedback(GLuint id){
	if(!GLM_struct->glIsTransformFeedbackproc) return 0;
	return GLM_struct->glIsTransformFeedbackproc(id);
}
void APIENTRY glPauseTransformFeedback(void){
	if(!GLM_struct->glPauseTransformFeedbackproc) return;
	GLM_struct->glPauseTransformFeedbackproc();
}
void APIENTRY glResumeTransformFeedback(void){
	if(!GLM_struct->glResumeTransformFeedbackproc) return;
	GLM_struct->glResumeTransformFeedbackproc();
}
void APIENTRY glDrawTransformFeedback(GLenum mode, GLuint id){
	if(!GLM_struct->glDrawTransformFeedbackproc) return;
	GLM_struct->glDrawTransformFeedbackproc(mode, id);
}
void APIENTRY glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream){
	if(!GLM_struct->glDrawTransformFeedbackStreamproc) return;
	GLM_struct->glDrawTransformFeedbackStreamproc(mode, id, stream);
}
void APIENTRY glBeginQueryIndexed(GLenum target, GLuint index, GLuint id){
	if(!GLM_struct->glBeginQueryIndexedproc) return;
	GLM_struct->glBeginQueryIndexedproc(target, index, id);
}
void APIENTRY glEndQueryIndexed(GLenum target, GLuint index){
	if(!GLM_struct->glEndQueryIndexedproc) return;
	GLM_struct->glEndQueryIndexedproc(target, index);
}
void APIENTRY glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetQueryIndexedivproc) return;
	GLM_struct->glGetQueryIndexedivproc(target, index, pname, params);
}
void APIENTRY glReleaseShaderCompiler(void){
	if(!GLM_struct->glReleaseShaderCompilerproc) return;
	GLM_struct->glReleaseShaderCompilerproc();
}
void APIENTRY glShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length){
	if(!GLM_struct->glShaderBinaryproc) return;
	GLM_struct->glShaderBinaryproc(count, shaders, binaryFormat, binary, length);
}
void APIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision){
	if(!GLM_struct->glGetShaderPrecisionFormatproc) return;
	GLM_struct->glGetShaderPrecisionFormatproc(shadertype, precisiontype, range, precision);
}
void APIENTRY glDepthRangef(GLfloat n, GLfloat f){
	if(!GLM_struct->glDepthRangefproc) return;
	GLM_struct->glDepthRangefproc(n, f);
}
void APIENTRY glClearDepthf(GLfloat d){
	if(!GLM_struct->glClearDepthfproc) return;
	GLM_struct->glClearDepthfproc(d);
}
void APIENTRY glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary){
	if(!GLM_struct->glGetProgramBinaryproc) return;
	GLM_struct->glGetProgramBinaryproc(program, bufSize, length, binaryFormat, binary);
}
void APIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length){
	if(!GLM_struct->glProgramBinaryproc) return;
	GLM_struct->glProgramBinaryproc(program, binaryFormat, binary, length);
}
void APIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value){
	if(!GLM_struct->glProgramParameteriproc) return;
	GLM_struct->glProgramParameteriproc(program, pname, value);
}
void APIENTRY glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program){
	if(!GLM_struct->glUseProgramStagesproc) return;
	GLM_struct->glUseProgramStagesproc(pipeline, stages, program);
}
void APIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program){
	if(!GLM_struct->glActiveShaderProgramproc) return;
	GLM_struct->glActiveShaderProgramproc(pipeline, program);
}
GLuint APIENTRY glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* const* strings){
	if(!GLM_struct->glCreateShaderProgramvproc) return 0;
	return GLM_struct->glCreateShaderProgramvproc(type, count, strings);
}
void APIENTRY glBindProgramPipeline(GLuint pipeline){
	if(!GLM_struct->glBindProgramPipelineproc) return;
	GLM_struct->glBindProgramPipelineproc(pipeline);
}
void APIENTRY glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines){
	if(!GLM_struct->glDeleteProgramPipelinesproc) return;
	GLM_struct->glDeleteProgramPipelinesproc(n, pipelines);
}
void APIENTRY glGenProgramPipelines(GLsizei n, GLuint* pipelines){
	if(!GLM_struct->glGenProgramPipelinesproc) return;
	GLM_struct->glGenProgramPipelinesproc(n, pipelines);
}
GLboolean APIENTRY glIsProgramPipeline(GLuint pipeline){
	if(!GLM_struct->glIsProgramPipelineproc) return 0;
	return GLM_struct->glIsProgramPipelineproc(pipeline);
}
void APIENTRY glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params){
	if(!GLM_struct->glGetProgramPipelineivproc) return;
	GLM_struct->glGetProgramPipelineivproc(pipeline, pname, params);
}
void APIENTRY glProgramUniform1i(GLuint program, GLint location, GLint v0){
	if(!GLM_struct->glProgramUniform1iproc) return;
	GLM_struct->glProgramUniform1iproc(program, location, v0);
}
void APIENTRY glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform1ivproc) return;
	GLM_struct->glProgramUniform1ivproc(program, location, count, value);
}
void APIENTRY glProgramUniform1f(GLuint program, GLint location, GLfloat v0){
	if(!GLM_struct->glProgramUniform1fproc) return;
	GLM_struct->glProgramUniform1fproc(program, location, v0);
}
void APIENTRY glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform1fvproc) return;
	GLM_struct->glProgramUniform1fvproc(program, location, count, value);
}
void APIENTRY glProgramUniform1d(GLuint program, GLint location, GLdouble v0){
	if(!GLM_struct->glProgramUniform1dproc) return;
	GLM_struct->glProgramUniform1dproc(program, location, v0);
}
void APIENTRY glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform1dvproc) return;
	GLM_struct->glProgramUniform1dvproc(program, location, count, value);
}
void APIENTRY glProgramUniform1ui(GLuint program, GLint location, GLuint v0){
	if(!GLM_struct->glProgramUniform1uiproc) return;
	GLM_struct->glProgramUniform1uiproc(program, location, v0);
}
void APIENTRY glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform1uivproc) return;
	GLM_struct->glProgramUniform1uivproc(program, location, count, value);
}
void APIENTRY glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1){
	if(!GLM_struct->glProgramUniform2iproc) return;
	GLM_struct->glProgramUniform2iproc(program, location, v0, v1);
}
void APIENTRY glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform2ivproc) return;
	GLM_struct->glProgramUniform2ivproc(program, location, count, value);
}
void APIENTRY glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1){
	if(!GLM_struct->glProgramUniform2fproc) return;
	GLM_struct->glProgramUniform2fproc(program, location, v0, v1);
}
void APIENTRY glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform2fvproc) return;
	GLM_struct->glProgramUniform2fvproc(program, location, count, value);
}
void APIENTRY glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1){
	if(!GLM_struct->glProgramUniform2dproc) return;
	GLM_struct->glProgramUniform2dproc(program, location, v0, v1);
}
void APIENTRY glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform2dvproc) return;
	GLM_struct->glProgramUniform2dvproc(program, location, count, value);
}
void APIENTRY glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1){
	if(!GLM_struct->glProgramUniform2uiproc) return;
	GLM_struct->glProgramUniform2uiproc(program, location, v0, v1);
}
void APIENTRY glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform2uivproc) return;
	GLM_struct->glProgramUniform2uivproc(program, location, count, value);
}
void APIENTRY glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2){
	if(!GLM_struct->glProgramUniform3iproc) return;
	GLM_struct->glProgramUniform3iproc(program, location, v0, v1, v2);
}
void APIENTRY glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform3ivproc) return;
	GLM_struct->glProgramUniform3ivproc(program, location, count, value);
}
void APIENTRY glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2){
	if(!GLM_struct->glProgramUniform3fproc) return;
	GLM_struct->glProgramUniform3fproc(program, location, v0, v1, v2);
}
void APIENTRY glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform3fvproc) return;
	GLM_struct->glProgramUniform3fvproc(program, location, count, value);
}
void APIENTRY glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2){
	if(!GLM_struct->glProgramUniform3dproc) return;
	GLM_struct->glProgramUniform3dproc(program, location, v0, v1, v2);
}
void APIENTRY glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform3dvproc) return;
	GLM_struct->glProgramUniform3dvproc(program, location, count, value);
}
void APIENTRY glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2){
	if(!GLM_struct->glProgramUniform3uiproc) return;
	GLM_struct->glProgramUniform3uiproc(program, location, v0, v1, v2);
}
void APIENTRY glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform3uivproc) return;
	GLM_struct->glProgramUniform3uivproc(program, location, count, value);
}
void APIENTRY glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3){
	if(!GLM_struct->glProgramUniform4iproc) return;
	GLM_struct->glProgramUniform4iproc(program, location, v0, v1, v2, v3);
}
void APIENTRY glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform4ivproc) return;
	GLM_struct->glProgramUniform4ivproc(program, location, count, value);
}
void APIENTRY glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3){
	if(!GLM_struct->glProgramUniform4fproc) return;
	GLM_struct->glProgramUniform4fproc(program, location, v0, v1, v2, v3);
}
void APIENTRY glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform4fvproc) return;
	GLM_struct->glProgramUniform4fvproc(program, location, count, value);
}
void APIENTRY glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3){
	if(!GLM_struct->glProgramUniform4dproc) return;
	GLM_struct->glProgramUniform4dproc(program, location, v0, v1, v2, v3);
}
void APIENTRY glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform4dvproc) return;
	GLM_struct->glProgramUniform4dvproc(program, location, count, value);
}
void APIENTRY glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3){
	if(!GLM_struct->glProgramUniform4uiproc) return;
	GLM_struct->glProgramUniform4uiproc(program, location, v0, v1, v2, v3);
}
void APIENTRY glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform4uivproc) return;
	GLM_struct->glProgramUniform4uivproc(program, location, count, value);
}
void APIENTRY glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix2fvproc) return;
	GLM_struct->glProgramUniformMatrix2fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix3fvproc) return;
	GLM_struct->glProgramUniformMatrix3fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix4fvproc) return;
	GLM_struct->glProgramUniformMatrix4fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix2dvproc) return;
	GLM_struct->glProgramUniformMatrix2dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix3dvproc) return;
	GLM_struct->glProgramUniformMatrix3dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix4dvproc) return;
	GLM_struct->glProgramUniformMatrix4dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix2x3fvproc) return;
	GLM_struct->glProgramUniformMatrix2x3fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix3x2fvproc) return;
	GLM_struct->glProgramUniformMatrix3x2fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix2x4fvproc) return;
	GLM_struct->glProgramUniformMatrix2x4fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix4x2fvproc) return;
	GLM_struct->glProgramUniformMatrix4x2fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix3x4fvproc) return;
	GLM_struct->glProgramUniformMatrix3x4fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix4x3fvproc) return;
	GLM_struct->glProgramUniformMatrix4x3fvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix2x3dvproc) return;
	GLM_struct->glProgramUniformMatrix2x3dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix3x2dvproc) return;
	GLM_struct->glProgramUniformMatrix3x2dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix2x4dvproc) return;
	GLM_struct->glProgramUniformMatrix2x4dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix4x2dvproc) return;
	GLM_struct->glProgramUniformMatrix4x2dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix3x4dvproc) return;
	GLM_struct->glProgramUniformMatrix3x4dvproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix4x3dvproc) return;
	GLM_struct->glProgramUniformMatrix4x3dvproc(program, location, count, transpose, value);
}
void APIENTRY glValidateProgramPipeline(GLuint pipeline){
	if(!GLM_struct->glValidateProgramPipelineproc) return;
	GLM_struct->glValidateProgramPipelineproc(pipeline);
}
void APIENTRY glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog){
	if(!GLM_struct->glGetProgramPipelineInfoLogproc) return;
	GLM_struct->glGetProgramPipelineInfoLogproc(pipeline, bufSize, length, infoLog);
}
void APIENTRY glVertexAttribL1d(GLuint index, GLdouble x){
	if(!GLM_struct->glVertexAttribL1dproc) return;
	GLM_struct->glVertexAttribL1dproc(index, x);
}
void APIENTRY glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y){
	if(!GLM_struct->glVertexAttribL2dproc) return;
	GLM_struct->glVertexAttribL2dproc(index, x, y);
}
void APIENTRY glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glVertexAttribL3dproc) return;
	GLM_struct->glVertexAttribL3dproc(index, x, y, z);
}
void APIENTRY glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glVertexAttribL4dproc) return;
	GLM_struct->glVertexAttribL4dproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribL1dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL1dvproc) return;
	GLM_struct->glVertexAttribL1dvproc(index, v);
}
void APIENTRY glVertexAttribL2dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL2dvproc) return;
	GLM_struct->glVertexAttribL2dvproc(index, v);
}
void APIENTRY glVertexAttribL3dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL3dvproc) return;
	GLM_struct->glVertexAttribL3dvproc(index, v);
}
void APIENTRY glVertexAttribL4dv(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL4dvproc) return;
	GLM_struct->glVertexAttribL4dvproc(index, v);
}
void APIENTRY glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexAttribLPointerproc) return;
	GLM_struct->glVertexAttribLPointerproc(index, size, type, stride, pointer);
}
void APIENTRY glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetVertexAttribLdvproc) return;
	GLM_struct->glGetVertexAttribLdvproc(index, pname, params);
}
void APIENTRY glViewportArrayv(GLuint first, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glViewportArrayvproc) return;
	GLM_struct->glViewportArrayvproc(first, count, v);
}
void APIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h){
	if(!GLM_struct->glViewportIndexedfproc) return;
	GLM_struct->glViewportIndexedfproc(index, x, y, w, h);
}
void APIENTRY glViewportIndexedfv(GLuint index, const GLfloat* v){
	if(!GLM_struct->glViewportIndexedfvproc) return;
	GLM_struct->glViewportIndexedfvproc(index, v);
}
void APIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint* v){
	if(!GLM_struct->glScissorArrayvproc) return;
	GLM_struct->glScissorArrayvproc(first, count, v);
}
void APIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height){
	if(!GLM_struct->glScissorIndexedproc) return;
	GLM_struct->glScissorIndexedproc(index, left, bottom, width, height);
}
void APIENTRY glScissorIndexedv(GLuint index, const GLint* v){
	if(!GLM_struct->glScissorIndexedvproc) return;
	GLM_struct->glScissorIndexedvproc(index, v);
}
void APIENTRY glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v){
	if(!GLM_struct->glDepthRangeArrayvproc) return;
	GLM_struct->glDepthRangeArrayvproc(first, count, v);
}
void APIENTRY glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f){
	if(!GLM_struct->glDepthRangeIndexedproc) return;
	GLM_struct->glDepthRangeIndexedproc(index, n, f);
}
void APIENTRY glGetFloati_v(GLenum target, GLuint index, GLfloat* data){
	if(!GLM_struct->glGetFloati_vproc) return;
	GLM_struct->glGetFloati_vproc(target, index, data);
}
void APIENTRY glGetDoublei_v(GLenum target, GLuint index, GLdouble* data){
	if(!GLM_struct->glGetDoublei_vproc) return;
	GLM_struct->glGetDoublei_vproc(target, index, data);
}
void APIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance){
	if(!GLM_struct->glDrawArraysInstancedBaseInstanceproc) return;
	GLM_struct->glDrawArraysInstancedBaseInstanceproc(mode, first, count, instancecount, baseinstance);
}
void APIENTRY glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance){
	if(!GLM_struct->glDrawElementsInstancedBaseInstanceproc) return;
	GLM_struct->glDrawElementsInstancedBaseInstanceproc(mode, count, type, indices, instancecount, baseinstance);
}
void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance){
	if(!GLM_struct->glDrawElementsInstancedBaseVertexBaseInstanceproc) return;
	GLM_struct->glDrawElementsInstancedBaseVertexBaseInstanceproc(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
void APIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params){
	if(!GLM_struct->glGetInternalformativproc) return;
	GLM_struct->glGetInternalformativproc(target, internalformat, pname, count, params);
}
void APIENTRY glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params){
	if(!GLM_struct->glGetActiveAtomicCounterBufferivproc) return;
	GLM_struct->glGetActiveAtomicCounterBufferivproc(program, bufferIndex, pname, params);
}
void APIENTRY glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format){
	if(!GLM_struct->glBindImageTextureproc) return;
	GLM_struct->glBindImageTextureproc(unit, texture, level, layered, layer, access, format);
}
void APIENTRY glMemoryBarrier(GLbitfield barriers){
	if(!GLM_struct->glMemoryBarrierproc) return;
	GLM_struct->glMemoryBarrierproc(barriers);
}
void APIENTRY glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width){
	if(!GLM_struct->glTexStorage1Dproc) return;
	GLM_struct->glTexStorage1Dproc(target, levels, internalformat, width);
}
void APIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glTexStorage2Dproc) return;
	GLM_struct->glTexStorage2Dproc(target, levels, internalformat, width, height);
}
void APIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->glTexStorage3Dproc) return;
	GLM_struct->glTexStorage3Dproc(target, levels, internalformat, width, height, depth);
}
void APIENTRY glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount){
	if(!GLM_struct->glDrawTransformFeedbackInstancedproc) return;
	GLM_struct->glDrawTransformFeedbackInstancedproc(mode, id, instancecount);
}
void APIENTRY glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount){
	if(!GLM_struct->glDrawTransformFeedbackStreamInstancedproc) return;
	GLM_struct->glDrawTransformFeedbackStreamInstancedproc(mode, id, stream, instancecount);
}
void APIENTRY glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearBufferDataproc) return;
	GLM_struct->glClearBufferDataproc(target, internalformat, format, type, data);
}
void APIENTRY glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearBufferSubDataproc) return;
	GLM_struct->glClearBufferSubDataproc(target, internalformat, offset, size, format, type, data);
}
void APIENTRY glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z){
	if(!GLM_struct->glDispatchComputeproc) return;
	GLM_struct->glDispatchComputeproc(num_groups_x, num_groups_y, num_groups_z);
}
void APIENTRY glDispatchComputeIndirect(GLintptr indirect){
	if(!GLM_struct->glDispatchComputeIndirectproc) return;
	GLM_struct->glDispatchComputeIndirectproc(indirect);
}
void APIENTRY glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth){
	if(!GLM_struct->glCopyImageSubDataproc) return;
	GLM_struct->glCopyImageSubDataproc(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
void APIENTRY glFramebufferParameteri(GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glFramebufferParameteriproc) return;
	GLM_struct->glFramebufferParameteriproc(target, pname, param);
}
void APIENTRY glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFramebufferParameterivproc) return;
	GLM_struct->glGetFramebufferParameterivproc(target, pname, params);
}
void APIENTRY glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params){
	if(!GLM_struct->glGetInternalformati64vproc) return;
	GLM_struct->glGetInternalformati64vproc(target, internalformat, pname, count, params);
}
void APIENTRY glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->glInvalidateTexSubImageproc) return;
	GLM_struct->glInvalidateTexSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}
void APIENTRY glInvalidateTexImage(GLuint texture, GLint level){
	if(!GLM_struct->glInvalidateTexImageproc) return;
	GLM_struct->glInvalidateTexImageproc(texture, level);
}
void APIENTRY glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length){
	if(!GLM_struct->glInvalidateBufferSubDataproc) return;
	GLM_struct->glInvalidateBufferSubDataproc(buffer, offset, length);
}
void APIENTRY glInvalidateBufferData(GLuint buffer){
	if(!GLM_struct->glInvalidateBufferDataproc) return;
	GLM_struct->glInvalidateBufferDataproc(buffer);
}
void APIENTRY glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments){
	if(!GLM_struct->glInvalidateFramebufferproc) return;
	GLM_struct->glInvalidateFramebufferproc(target, numAttachments, attachments);
}
void APIENTRY glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glInvalidateSubFramebufferproc) return;
	GLM_struct->glInvalidateSubFramebufferproc(target, numAttachments, attachments, x, y, width, height);
}
void APIENTRY glMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawArraysIndirectproc) return;
	GLM_struct->glMultiDrawArraysIndirectproc(mode, indirect, drawcount, stride);
}
void APIENTRY glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawElementsIndirectproc) return;
	GLM_struct->glMultiDrawElementsIndirectproc(mode, type, indirect, drawcount, stride);
}
void APIENTRY glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params){
	if(!GLM_struct->glGetProgramInterfaceivproc) return;
	GLM_struct->glGetProgramInterfaceivproc(program, programInterface, pname, params);
}
GLuint APIENTRY glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name){
	if(!GLM_struct->glGetProgramResourceIndexproc) return 0;
	return GLM_struct->glGetProgramResourceIndexproc(program, programInterface, name);
}
void APIENTRY glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name){
	if(!GLM_struct->glGetProgramResourceNameproc) return;
	GLM_struct->glGetProgramResourceNameproc(program, programInterface, index, bufSize, length, name);
}
void APIENTRY glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params){
	if(!GLM_struct->glGetProgramResourceivproc) return;
	GLM_struct->glGetProgramResourceivproc(program, programInterface, index, propCount, props, count, length, params);
}
GLint APIENTRY glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name){
	if(!GLM_struct->glGetProgramResourceLocationproc) return 0;
	return GLM_struct->glGetProgramResourceLocationproc(program, programInterface, name);
}
GLint APIENTRY glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name){
	if(!GLM_struct->glGetProgramResourceLocationIndexproc) return 0;
	return GLM_struct->glGetProgramResourceLocationIndexproc(program, programInterface, name);
}
void APIENTRY glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding){
	if(!GLM_struct->glShaderStorageBlockBindingproc) return;
	GLM_struct->glShaderStorageBlockBindingproc(program, storageBlockIndex, storageBlockBinding);
}
void APIENTRY glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glTexBufferRangeproc) return;
	GLM_struct->glTexBufferRangeproc(target, internalformat, buffer, offset, size);
}
void APIENTRY glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTexStorage2DMultisampleproc) return;
	GLM_struct->glTexStorage2DMultisampleproc(target, samples, internalformat, width, height, fixedsamplelocations);
}
void APIENTRY glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTexStorage3DMultisampleproc) return;
	GLM_struct->glTexStorage3DMultisampleproc(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void APIENTRY glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers){
	if(!GLM_struct->glTextureViewproc) return;
	GLM_struct->glTextureViewproc(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
void APIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride){
	if(!GLM_struct->glBindVertexBufferproc) return;
	GLM_struct->glBindVertexBufferproc(bindingindex, buffer, offset, stride);
}
void APIENTRY glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset){
	if(!GLM_struct->glVertexAttribFormatproc) return;
	GLM_struct->glVertexAttribFormatproc(attribindex, size, type, normalized, relativeoffset);
}
void APIENTRY glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset){
	if(!GLM_struct->glVertexAttribIFormatproc) return;
	GLM_struct->glVertexAttribIFormatproc(attribindex, size, type, relativeoffset);
}
void APIENTRY glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset){
	if(!GLM_struct->glVertexAttribLFormatproc) return;
	GLM_struct->glVertexAttribLFormatproc(attribindex, size, type, relativeoffset);
}
void APIENTRY glVertexAttribBinding(GLuint attribindex, GLuint bindingindex){
	if(!GLM_struct->glVertexAttribBindingproc) return;
	GLM_struct->glVertexAttribBindingproc(attribindex, bindingindex);
}
void APIENTRY glVertexBindingDivisor(GLuint bindingindex, GLuint divisor){
	if(!GLM_struct->glVertexBindingDivisorproc) return;
	GLM_struct->glVertexBindingDivisorproc(bindingindex, divisor);
}
void APIENTRY glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled){
	if(!GLM_struct->glDebugMessageControlproc) return;
	GLM_struct->glDebugMessageControlproc(source, type, severity, count, ids, enabled);
}
void APIENTRY glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf){
	if(!GLM_struct->glDebugMessageInsertproc) return;
	GLM_struct->glDebugMessageInsertproc(source, type, id, severity, length, buf);
}
void APIENTRY glDebugMessageCallback(GLDEBUGPROC callback, const void* userParam){
	if(!GLM_struct->glDebugMessageCallbackproc) return;
	GLM_struct->glDebugMessageCallbackproc(callback, userParam);
}
GLuint APIENTRY glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog){
	if(!GLM_struct->glGetDebugMessageLogproc) return 0;
	return GLM_struct->glGetDebugMessageLogproc(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
void APIENTRY glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message){
	if(!GLM_struct->glPushDebugGroupproc) return;
	GLM_struct->glPushDebugGroupproc(source, id, length, message);
}
void APIENTRY glPopDebugGroup(void){
	if(!GLM_struct->glPopDebugGroupproc) return;
	GLM_struct->glPopDebugGroupproc();
}
void APIENTRY glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label){
	if(!GLM_struct->glObjectLabelproc) return;
	GLM_struct->glObjectLabelproc(identifier, name, length, label);
}
void APIENTRY glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label){
	if(!GLM_struct->glGetObjectLabelproc) return;
	GLM_struct->glGetObjectLabelproc(identifier, name, bufSize, length, label);
}
void APIENTRY glObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label){
	if(!GLM_struct->glObjectPtrLabelproc) return;
	GLM_struct->glObjectPtrLabelproc(ptr, length, label);
}
void APIENTRY glGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label){
	if(!GLM_struct->glGetObjectPtrLabelproc) return;
	GLM_struct->glGetObjectPtrLabelproc(ptr, bufSize, length, label);
}
void APIENTRY glBufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags){
	if(!GLM_struct->glBufferStorageproc) return;
	GLM_struct->glBufferStorageproc(target, size, data, flags);
}
void APIENTRY glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearTexImageproc) return;
	GLM_struct->glClearTexImageproc(texture, level, format, type, data);
}
void APIENTRY glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearTexSubImageproc) return;
	GLM_struct->glClearTexSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}
void APIENTRY glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers){
	if(!GLM_struct->glBindBuffersBaseproc) return;
	GLM_struct->glBindBuffersBaseproc(target, first, count, buffers);
}
void APIENTRY glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes){
	if(!GLM_struct->glBindBuffersRangeproc) return;
	GLM_struct->glBindBuffersRangeproc(target, first, count, buffers, offsets, sizes);
}
void APIENTRY glBindTextures(GLuint first, GLsizei count, const GLuint* textures){
	if(!GLM_struct->glBindTexturesproc) return;
	GLM_struct->glBindTexturesproc(first, count, textures);
}
void APIENTRY glBindSamplers(GLuint first, GLsizei count, const GLuint* samplers){
	if(!GLM_struct->glBindSamplersproc) return;
	GLM_struct->glBindSamplersproc(first, count, samplers);
}
void APIENTRY glBindImageTextures(GLuint first, GLsizei count, const GLuint* textures){
	if(!GLM_struct->glBindImageTexturesproc) return;
	GLM_struct->glBindImageTexturesproc(first, count, textures);
}
void APIENTRY glBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides){
	if(!GLM_struct->glBindVertexBuffersproc) return;
	GLM_struct->glBindVertexBuffersproc(first, count, buffers, offsets, strides);
}
void APIENTRY glClipControl(GLenum origin, GLenum depth){
	if(!GLM_struct->glClipControlproc) return;
	GLM_struct->glClipControlproc(origin, depth);
}
void APIENTRY glCreateTransformFeedbacks(GLsizei n, GLuint* ids){
	if(!GLM_struct->glCreateTransformFeedbacksproc) return;
	GLM_struct->glCreateTransformFeedbacksproc(n, ids);
}
void APIENTRY glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer){
	if(!GLM_struct->glTransformFeedbackBufferBaseproc) return;
	GLM_struct->glTransformFeedbackBufferBaseproc(xfb, index, buffer);
}
void APIENTRY glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glTransformFeedbackBufferRangeproc) return;
	GLM_struct->glTransformFeedbackBufferRangeproc(xfb, index, buffer, offset, size);
}
void APIENTRY glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param){
	if(!GLM_struct->glGetTransformFeedbackivproc) return;
	GLM_struct->glGetTransformFeedbackivproc(xfb, pname, param);
}
void APIENTRY glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param){
	if(!GLM_struct->glGetTransformFeedbacki_vproc) return;
	GLM_struct->glGetTransformFeedbacki_vproc(xfb, pname, index, param);
}
void APIENTRY glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param){
	if(!GLM_struct->glGetTransformFeedbacki64_vproc) return;
	GLM_struct->glGetTransformFeedbacki64_vproc(xfb, pname, index, param);
}
void APIENTRY glCreateBuffers(GLsizei n, GLuint* buffers){
	if(!GLM_struct->glCreateBuffersproc) return;
	GLM_struct->glCreateBuffersproc(n, buffers);
}
void APIENTRY glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags){
	if(!GLM_struct->glNamedBufferStorageproc) return;
	GLM_struct->glNamedBufferStorageproc(buffer, size, data, flags);
}
void APIENTRY glNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage){
	if(!GLM_struct->glNamedBufferDataproc) return;
	GLM_struct->glNamedBufferDataproc(buffer, size, data, usage);
}
void APIENTRY glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data){
	if(!GLM_struct->glNamedBufferSubDataproc) return;
	GLM_struct->glNamedBufferSubDataproc(buffer, offset, size, data);
}
void APIENTRY glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size){
	if(!GLM_struct->glCopyNamedBufferSubDataproc) return;
	GLM_struct->glCopyNamedBufferSubDataproc(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
void APIENTRY glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearNamedBufferDataproc) return;
	GLM_struct->glClearNamedBufferDataproc(buffer, internalformat, format, type, data);
}
void APIENTRY glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearNamedBufferSubDataproc) return;
	GLM_struct->glClearNamedBufferSubDataproc(buffer, internalformat, offset, size, format, type, data);
}
void* APIENTRY glMapNamedBuffer(GLuint buffer, GLenum access){
	if(!GLM_struct->glMapNamedBufferproc) return 0;
	return GLM_struct->glMapNamedBufferproc(buffer, access);
}
void* APIENTRY glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access){
	if(!GLM_struct->glMapNamedBufferRangeproc) return 0;
	return GLM_struct->glMapNamedBufferRangeproc(buffer, offset, length, access);
}
GLboolean APIENTRY glUnmapNamedBuffer(GLuint buffer){
	if(!GLM_struct->glUnmapNamedBufferproc) return 0;
	return GLM_struct->glUnmapNamedBufferproc(buffer);
}
void APIENTRY glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length){
	if(!GLM_struct->glFlushMappedNamedBufferRangeproc) return;
	GLM_struct->glFlushMappedNamedBufferRangeproc(buffer, offset, length);
}
void APIENTRY glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedBufferParameterivproc) return;
	GLM_struct->glGetNamedBufferParameterivproc(buffer, pname, params);
}
void APIENTRY glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params){
	if(!GLM_struct->glGetNamedBufferParameteri64vproc) return;
	GLM_struct->glGetNamedBufferParameteri64vproc(buffer, pname, params);
}
void APIENTRY glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params){
	if(!GLM_struct->glGetNamedBufferPointervproc) return;
	GLM_struct->glGetNamedBufferPointervproc(buffer, pname, params);
}
void APIENTRY glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data){
	if(!GLM_struct->glGetNamedBufferSubDataproc) return;
	GLM_struct->glGetNamedBufferSubDataproc(buffer, offset, size, data);
}
void APIENTRY glCreateFramebuffers(GLsizei n, GLuint* framebuffers){
	if(!GLM_struct->glCreateFramebuffersproc) return;
	GLM_struct->glCreateFramebuffersproc(n, framebuffers);
}
void APIENTRY glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer){
	if(!GLM_struct->glNamedFramebufferRenderbufferproc) return;
	GLM_struct->glNamedFramebufferRenderbufferproc(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
void APIENTRY glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param){
	if(!GLM_struct->glNamedFramebufferParameteriproc) return;
	GLM_struct->glNamedFramebufferParameteriproc(framebuffer, pname, param);
}
void APIENTRY glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level){
	if(!GLM_struct->glNamedFramebufferTextureproc) return;
	GLM_struct->glNamedFramebufferTextureproc(framebuffer, attachment, texture, level);
}
void APIENTRY glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer){
	if(!GLM_struct->glNamedFramebufferTextureLayerproc) return;
	GLM_struct->glNamedFramebufferTextureLayerproc(framebuffer, attachment, texture, level, layer);
}
void APIENTRY glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf){
	if(!GLM_struct->glNamedFramebufferDrawBufferproc) return;
	GLM_struct->glNamedFramebufferDrawBufferproc(framebuffer, buf);
}
void APIENTRY glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs){
	if(!GLM_struct->glNamedFramebufferDrawBuffersproc) return;
	GLM_struct->glNamedFramebufferDrawBuffersproc(framebuffer, n, bufs);
}
void APIENTRY glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src){
	if(!GLM_struct->glNamedFramebufferReadBufferproc) return;
	GLM_struct->glNamedFramebufferReadBufferproc(framebuffer, src);
}
void APIENTRY glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments){
	if(!GLM_struct->glInvalidateNamedFramebufferDataproc) return;
	GLM_struct->glInvalidateNamedFramebufferDataproc(framebuffer, numAttachments, attachments);
}
void APIENTRY glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glInvalidateNamedFramebufferSubDataproc) return;
	GLM_struct->glInvalidateNamedFramebufferSubDataproc(framebuffer, numAttachments, attachments, x, y, width, height);
}
void APIENTRY glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value){
	if(!GLM_struct->glClearNamedFramebufferivproc) return;
	GLM_struct->glClearNamedFramebufferivproc(framebuffer, buffer, drawbuffer, value);
}
void APIENTRY glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value){
	if(!GLM_struct->glClearNamedFramebufferuivproc) return;
	GLM_struct->glClearNamedFramebufferuivproc(framebuffer, buffer, drawbuffer, value);
}
void APIENTRY glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value){
	if(!GLM_struct->glClearNamedFramebufferfvproc) return;
	GLM_struct->glClearNamedFramebufferfvproc(framebuffer, buffer, drawbuffer, value);
}
void APIENTRY glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil){
	if(!GLM_struct->glClearNamedFramebufferfiproc) return;
	GLM_struct->glClearNamedFramebufferfiproc(framebuffer, buffer, drawbuffer, depth, stencil);
}
void APIENTRY glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){
	if(!GLM_struct->glBlitNamedFramebufferproc) return;
	GLM_struct->glBlitNamedFramebufferproc(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
GLenum APIENTRY glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target){
	if(!GLM_struct->glCheckNamedFramebufferStatusproc) return 0;
	return GLM_struct->glCheckNamedFramebufferStatusproc(framebuffer, target);
}
void APIENTRY glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param){
	if(!GLM_struct->glGetNamedFramebufferParameterivproc) return;
	GLM_struct->glGetNamedFramebufferParameterivproc(framebuffer, pname, param);
}
void APIENTRY glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedFramebufferAttachmentParameterivproc) return;
	GLM_struct->glGetNamedFramebufferAttachmentParameterivproc(framebuffer, attachment, pname, params);
}
void APIENTRY glCreateRenderbuffers(GLsizei n, GLuint* renderbuffers){
	if(!GLM_struct->glCreateRenderbuffersproc) return;
	GLM_struct->glCreateRenderbuffersproc(n, renderbuffers);
}
void APIENTRY glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glNamedRenderbufferStorageproc) return;
	GLM_struct->glNamedRenderbufferStorageproc(renderbuffer, internalformat, width, height);
}
void APIENTRY glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glNamedRenderbufferStorageMultisampleproc) return;
	GLM_struct->glNamedRenderbufferStorageMultisampleproc(renderbuffer, samples, internalformat, width, height);
}
void APIENTRY glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedRenderbufferParameterivproc) return;
	GLM_struct->glGetNamedRenderbufferParameterivproc(renderbuffer, pname, params);
}
void APIENTRY glCreateTextures(GLenum target, GLsizei n, GLuint* textures){
	if(!GLM_struct->glCreateTexturesproc) return;
	GLM_struct->glCreateTexturesproc(target, n, textures);
}
void APIENTRY glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer){
	if(!GLM_struct->glTextureBufferproc) return;
	GLM_struct->glTextureBufferproc(texture, internalformat, buffer);
}
void APIENTRY glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glTextureBufferRangeproc) return;
	GLM_struct->glTextureBufferRangeproc(texture, internalformat, buffer, offset, size);
}
void APIENTRY glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width){
	if(!GLM_struct->glTextureStorage1Dproc) return;
	GLM_struct->glTextureStorage1Dproc(texture, levels, internalformat, width);
}
void APIENTRY glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glTextureStorage2Dproc) return;
	GLM_struct->glTextureStorage2Dproc(texture, levels, internalformat, width, height);
}
void APIENTRY glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->glTextureStorage3Dproc) return;
	GLM_struct->glTextureStorage3Dproc(texture, levels, internalformat, width, height, depth);
}
void APIENTRY glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTextureStorage2DMultisampleproc) return;
	GLM_struct->glTextureStorage2DMultisampleproc(texture, samples, internalformat, width, height, fixedsamplelocations);
}
void APIENTRY glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTextureStorage3DMultisampleproc) return;
	GLM_struct->glTextureStorage3DMultisampleproc(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void APIENTRY glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureSubImage1Dproc) return;
	GLM_struct->glTextureSubImage1Dproc(texture, level, xoffset, width, format, type, pixels);
}
void APIENTRY glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureSubImage2Dproc) return;
	GLM_struct->glTextureSubImage2Dproc(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}
void APIENTRY glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureSubImage3Dproc) return;
	GLM_struct->glTextureSubImage3Dproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void APIENTRY glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTextureSubImage1Dproc) return;
	GLM_struct->glCompressedTextureSubImage1Dproc(texture, level, xoffset, width, format, imageSize, data);
}
void APIENTRY glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTextureSubImage2Dproc) return;
	GLM_struct->glCompressedTextureSubImage2Dproc(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void APIENTRY glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTextureSubImage3Dproc) return;
	GLM_struct->glCompressedTextureSubImage3Dproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void APIENTRY glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyTextureSubImage1Dproc) return;
	GLM_struct->glCopyTextureSubImage1Dproc(texture, level, xoffset, x, y, width);
}
void APIENTRY glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyTextureSubImage2Dproc) return;
	GLM_struct->glCopyTextureSubImage2Dproc(texture, level, xoffset, yoffset, x, y, width, height);
}
void APIENTRY glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyTextureSubImage3Dproc) return;
	GLM_struct->glCopyTextureSubImage3Dproc(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void APIENTRY glTextureParameterf(GLuint texture, GLenum pname, GLfloat param){
	if(!GLM_struct->glTextureParameterfproc) return;
	GLM_struct->glTextureParameterfproc(texture, pname, param);
}
void APIENTRY glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param){
	if(!GLM_struct->glTextureParameterfvproc) return;
	GLM_struct->glTextureParameterfvproc(texture, pname, param);
}
void APIENTRY glTextureParameteri(GLuint texture, GLenum pname, GLint param){
	if(!GLM_struct->glTextureParameteriproc) return;
	GLM_struct->glTextureParameteriproc(texture, pname, param);
}
void APIENTRY glTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params){
	if(!GLM_struct->glTextureParameterIivproc) return;
	GLM_struct->glTextureParameterIivproc(texture, pname, params);
}
void APIENTRY glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params){
	if(!GLM_struct->glTextureParameterIuivproc) return;
	GLM_struct->glTextureParameterIuivproc(texture, pname, params);
}
void APIENTRY glTextureParameteriv(GLuint texture, GLenum pname, const GLint* param){
	if(!GLM_struct->glTextureParameterivproc) return;
	GLM_struct->glTextureParameterivproc(texture, pname, param);
}
void APIENTRY glGenerateTextureMipmap(GLuint texture){
	if(!GLM_struct->glGenerateTextureMipmapproc) return;
	GLM_struct->glGenerateTextureMipmapproc(texture);
}
void APIENTRY glBindTextureUnit(GLuint unit, GLuint texture){
	if(!GLM_struct->glBindTextureUnitproc) return;
	GLM_struct->glBindTextureUnitproc(unit, texture);
}
void APIENTRY glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels){
	if(!GLM_struct->glGetTextureImageproc) return;
	GLM_struct->glGetTextureImageproc(texture, level, format, type, bufSize, pixels);
}
void APIENTRY glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels){
	if(!GLM_struct->glGetCompressedTextureImageproc) return;
	GLM_struct->glGetCompressedTextureImageproc(texture, level, bufSize, pixels);
}
void APIENTRY glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetTextureLevelParameterfvproc) return;
	GLM_struct->glGetTextureLevelParameterfvproc(texture, level, pname, params);
}
void APIENTRY glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTextureLevelParameterivproc) return;
	GLM_struct->glGetTextureLevelParameterivproc(texture, level, pname, params);
}
void APIENTRY glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetTextureParameterfvproc) return;
	GLM_struct->glGetTextureParameterfvproc(texture, pname, params);
}
void APIENTRY glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTextureParameterIivproc) return;
	GLM_struct->glGetTextureParameterIivproc(texture, pname, params);
}
void APIENTRY glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetTextureParameterIuivproc) return;
	GLM_struct->glGetTextureParameterIuivproc(texture, pname, params);
}
void APIENTRY glGetTextureParameteriv(GLuint texture, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTextureParameterivproc) return;
	GLM_struct->glGetTextureParameterivproc(texture, pname, params);
}
void APIENTRY glCreateVertexArrays(GLsizei n, GLuint* arrays){
	if(!GLM_struct->glCreateVertexArraysproc) return;
	GLM_struct->glCreateVertexArraysproc(n, arrays);
}
void APIENTRY glDisableVertexArrayAttrib(GLuint vaobj, GLuint index){
	if(!GLM_struct->glDisableVertexArrayAttribproc) return;
	GLM_struct->glDisableVertexArrayAttribproc(vaobj, index);
}
void APIENTRY glEnableVertexArrayAttrib(GLuint vaobj, GLuint index){
	if(!GLM_struct->glEnableVertexArrayAttribproc) return;
	GLM_struct->glEnableVertexArrayAttribproc(vaobj, index);
}
void APIENTRY glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer){
	if(!GLM_struct->glVertexArrayElementBufferproc) return;
	GLM_struct->glVertexArrayElementBufferproc(vaobj, buffer);
}
void APIENTRY glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride){
	if(!GLM_struct->glVertexArrayVertexBufferproc) return;
	GLM_struct->glVertexArrayVertexBufferproc(vaobj, bindingindex, buffer, offset, stride);
}
void APIENTRY glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides){
	if(!GLM_struct->glVertexArrayVertexBuffersproc) return;
	GLM_struct->glVertexArrayVertexBuffersproc(vaobj, first, count, buffers, offsets, strides);
}
void APIENTRY glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex){
	if(!GLM_struct->glVertexArrayAttribBindingproc) return;
	GLM_struct->glVertexArrayAttribBindingproc(vaobj, attribindex, bindingindex);
}
void APIENTRY glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset){
	if(!GLM_struct->glVertexArrayAttribFormatproc) return;
	GLM_struct->glVertexArrayAttribFormatproc(vaobj, attribindex, size, type, normalized, relativeoffset);
}
void APIENTRY glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset){
	if(!GLM_struct->glVertexArrayAttribIFormatproc) return;
	GLM_struct->glVertexArrayAttribIFormatproc(vaobj, attribindex, size, type, relativeoffset);
}
void APIENTRY glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset){
	if(!GLM_struct->glVertexArrayAttribLFormatproc) return;
	GLM_struct->glVertexArrayAttribLFormatproc(vaobj, attribindex, size, type, relativeoffset);
}
void APIENTRY glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor){
	if(!GLM_struct->glVertexArrayBindingDivisorproc) return;
	GLM_struct->glVertexArrayBindingDivisorproc(vaobj, bindingindex, divisor);
}
void APIENTRY glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param){
	if(!GLM_struct->glGetVertexArrayivproc) return;
	GLM_struct->glGetVertexArrayivproc(vaobj, pname, param);
}
void APIENTRY glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param){
	if(!GLM_struct->glGetVertexArrayIndexedivproc) return;
	GLM_struct->glGetVertexArrayIndexedivproc(vaobj, index, pname, param);
}
void APIENTRY glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param){
	if(!GLM_struct->glGetVertexArrayIndexed64ivproc) return;
	GLM_struct->glGetVertexArrayIndexed64ivproc(vaobj, index, pname, param);
}
void APIENTRY glCreateSamplers(GLsizei n, GLuint* samplers){
	if(!GLM_struct->glCreateSamplersproc) return;
	GLM_struct->glCreateSamplersproc(n, samplers);
}
void APIENTRY glCreateProgramPipelines(GLsizei n, GLuint* pipelines){
	if(!GLM_struct->glCreateProgramPipelinesproc) return;
	GLM_struct->glCreateProgramPipelinesproc(n, pipelines);
}
void APIENTRY glCreateQueries(GLenum target, GLsizei n, GLuint* ids){
	if(!GLM_struct->glCreateQueriesproc) return;
	GLM_struct->glCreateQueriesproc(target, n, ids);
}
void APIENTRY glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset){
	if(!GLM_struct->glGetQueryBufferObjecti64vproc) return;
	GLM_struct->glGetQueryBufferObjecti64vproc(id, buffer, pname, offset);
}
void APIENTRY glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset){
	if(!GLM_struct->glGetQueryBufferObjectivproc) return;
	GLM_struct->glGetQueryBufferObjectivproc(id, buffer, pname, offset);
}
void APIENTRY glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset){
	if(!GLM_struct->glGetQueryBufferObjectui64vproc) return;
	GLM_struct->glGetQueryBufferObjectui64vproc(id, buffer, pname, offset);
}
void APIENTRY glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset){
	if(!GLM_struct->glGetQueryBufferObjectuivproc) return;
	GLM_struct->glGetQueryBufferObjectuivproc(id, buffer, pname, offset);
}
void APIENTRY glMemoryBarrierByRegion(GLbitfield barriers){
	if(!GLM_struct->glMemoryBarrierByRegionproc) return;
	GLM_struct->glMemoryBarrierByRegionproc(barriers);
}
void APIENTRY glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels){
	if(!GLM_struct->glGetTextureSubImageproc) return;
	GLM_struct->glGetTextureSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}
void APIENTRY glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels){
	if(!GLM_struct->glGetCompressedTextureSubImageproc) return;
	GLM_struct->glGetCompressedTextureSubImageproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}
GLenum APIENTRY glGetGraphicsResetStatus(void){
	if(!GLM_struct->glGetGraphicsResetStatusproc) return 0;
	return GLM_struct->glGetGraphicsResetStatusproc();
}
void APIENTRY glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels){
	if(!GLM_struct->glGetnCompressedTexImageproc) return;
	GLM_struct->glGetnCompressedTexImageproc(target, lod, bufSize, pixels);
}
void APIENTRY glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels){
	if(!GLM_struct->glGetnTexImageproc) return;
	GLM_struct->glGetnTexImageproc(target, level, format, type, bufSize, pixels);
}
void APIENTRY glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params){
	if(!GLM_struct->glGetnUniformdvproc) return;
	GLM_struct->glGetnUniformdvproc(program, location, bufSize, params);
}
void APIENTRY glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params){
	if(!GLM_struct->glGetnUniformfvproc) return;
	GLM_struct->glGetnUniformfvproc(program, location, bufSize, params);
}
void APIENTRY glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params){
	if(!GLM_struct->glGetnUniformivproc) return;
	GLM_struct->glGetnUniformivproc(program, location, bufSize, params);
}
void APIENTRY glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params){
	if(!GLM_struct->glGetnUniformuivproc) return;
	GLM_struct->glGetnUniformuivproc(program, location, bufSize, params);
}
void APIENTRY glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data){
	if(!GLM_struct->glReadnPixelsproc) return;
	GLM_struct->glReadnPixelsproc(x, y, width, height, format, type, bufSize, data);
}
void APIENTRY glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v){
	if(!GLM_struct->glGetnMapdvproc) return;
	GLM_struct->glGetnMapdvproc(target, query, bufSize, v);
}
void APIENTRY glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v){
	if(!GLM_struct->glGetnMapfvproc) return;
	GLM_struct->glGetnMapfvproc(target, query, bufSize, v);
}
void APIENTRY glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint* v){
	if(!GLM_struct->glGetnMapivproc) return;
	GLM_struct->glGetnMapivproc(target, query, bufSize, v);
}
void APIENTRY glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat* values){
	if(!GLM_struct->glGetnPixelMapfvproc) return;
	GLM_struct->glGetnPixelMapfvproc(map, bufSize, values);
}
void APIENTRY glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint* values){
	if(!GLM_struct->glGetnPixelMapuivproc) return;
	GLM_struct->glGetnPixelMapuivproc(map, bufSize, values);
}
void APIENTRY glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort* values){
	if(!GLM_struct->glGetnPixelMapusvproc) return;
	GLM_struct->glGetnPixelMapusvproc(map, bufSize, values);
}
void APIENTRY glGetnPolygonStipple(GLsizei bufSize, GLubyte* pattern){
	if(!GLM_struct->glGetnPolygonStippleproc) return;
	GLM_struct->glGetnPolygonStippleproc(bufSize, pattern);
}
void APIENTRY glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table){
	if(!GLM_struct->glGetnColorTableproc) return;
	GLM_struct->glGetnColorTableproc(target, format, type, bufSize, table);
}
void APIENTRY glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image){
	if(!GLM_struct->glGetnConvolutionFilterproc) return;
	GLM_struct->glGetnConvolutionFilterproc(target, format, type, bufSize, image);
}
void APIENTRY glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, void* column, void* span){
	if(!GLM_struct->glGetnSeparableFilterproc) return;
	GLM_struct->glGetnSeparableFilterproc(target, format, type, rowBufSize, row, columnBufSize, column, span);
}
void APIENTRY glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values){
	if(!GLM_struct->glGetnHistogramproc) return;
	GLM_struct->glGetnHistogramproc(target, reset, format, type, bufSize, values);
}
void APIENTRY glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values){
	if(!GLM_struct->glGetnMinmaxproc) return;
	GLM_struct->glGetnMinmaxproc(target, reset, format, type, bufSize, values);
}
void APIENTRY glTextureBarrier(void){
	if(!GLM_struct->glTextureBarrierproc) return;
	GLM_struct->glTextureBarrierproc();
}
void APIENTRY glSpecializeShader(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue){
	if(!GLM_struct->glSpecializeShaderproc) return;
	GLM_struct->glSpecializeShaderproc(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}
void APIENTRY glMultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawArraysIndirectCountproc) return;
	GLM_struct->glMultiDrawArraysIndirectCountproc(mode, indirect, drawcount, maxdrawcount, stride);
}
void APIENTRY glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawElementsIndirectCountproc) return;
	GLM_struct->glMultiDrawElementsIndirectCountproc(mode, type, indirect, drawcount, maxdrawcount, stride);
}
void APIENTRY glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp){
	if(!GLM_struct->glPolygonOffsetClampproc) return;
	GLM_struct->glPolygonOffsetClampproc(factor, units, clamp);
}
void APIENTRY glPrimitiveBoundingBoxARB(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW){
	if(!GLM_struct->glPrimitiveBoundingBoxARBproc) return;
	GLM_struct->glPrimitiveBoundingBoxARBproc(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
GLuint64 APIENTRY glGetTextureHandleARB(GLuint texture){
	if(!GLM_struct->glGetTextureHandleARBproc) return 0;
	return GLM_struct->glGetTextureHandleARBproc(texture);
}
GLuint64 APIENTRY glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler){
	if(!GLM_struct->glGetTextureSamplerHandleARBproc) return 0;
	return GLM_struct->glGetTextureSamplerHandleARBproc(texture, sampler);
}
void APIENTRY glMakeTextureHandleResidentARB(GLuint64 handle){
	if(!GLM_struct->glMakeTextureHandleResidentARBproc) return;
	GLM_struct->glMakeTextureHandleResidentARBproc(handle);
}
void APIENTRY glMakeTextureHandleNonResidentARB(GLuint64 handle){
	if(!GLM_struct->glMakeTextureHandleNonResidentARBproc) return;
	GLM_struct->glMakeTextureHandleNonResidentARBproc(handle);
}
GLuint64 APIENTRY glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format){
	if(!GLM_struct->glGetImageHandleARBproc) return 0;
	return GLM_struct->glGetImageHandleARBproc(texture, level, layered, layer, format);
}
void APIENTRY glMakeImageHandleResidentARB(GLuint64 handle, GLenum access){
	if(!GLM_struct->glMakeImageHandleResidentARBproc) return;
	GLM_struct->glMakeImageHandleResidentARBproc(handle, access);
}
void APIENTRY glMakeImageHandleNonResidentARB(GLuint64 handle){
	if(!GLM_struct->glMakeImageHandleNonResidentARBproc) return;
	GLM_struct->glMakeImageHandleNonResidentARBproc(handle);
}
void APIENTRY glUniformHandleui64ARB(GLint location, GLuint64 value){
	if(!GLM_struct->glUniformHandleui64ARBproc) return;
	GLM_struct->glUniformHandleui64ARBproc(location, value);
}
void APIENTRY glUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glUniformHandleui64vARBproc) return;
	GLM_struct->glUniformHandleui64vARBproc(location, count, value);
}
void APIENTRY glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value){
	if(!GLM_struct->glProgramUniformHandleui64ARBproc) return;
	GLM_struct->glProgramUniformHandleui64ARBproc(program, location, value);
}
void APIENTRY glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* values){
	if(!GLM_struct->glProgramUniformHandleui64vARBproc) return;
	GLM_struct->glProgramUniformHandleui64vARBproc(program, location, count, values);
}
GLboolean APIENTRY glIsTextureHandleResidentARB(GLuint64 handle){
	if(!GLM_struct->glIsTextureHandleResidentARBproc) return 0;
	return GLM_struct->glIsTextureHandleResidentARBproc(handle);
}
GLboolean APIENTRY glIsImageHandleResidentARB(GLuint64 handle){
	if(!GLM_struct->glIsImageHandleResidentARBproc) return 0;
	return GLM_struct->glIsImageHandleResidentARBproc(handle);
}
void APIENTRY glVertexAttribL1ui64ARB(GLuint index, GLuint64EXT x){
	if(!GLM_struct->glVertexAttribL1ui64ARBproc) return;
	GLM_struct->glVertexAttribL1ui64ARBproc(index, x);
}
void APIENTRY glVertexAttribL1ui64vARB(GLuint index, const GLuint64EXT* v){
	if(!GLM_struct->glVertexAttribL1ui64vARBproc) return;
	GLM_struct->glVertexAttribL1ui64vARBproc(index, v);
}
void APIENTRY glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT* params){
	if(!GLM_struct->glGetVertexAttribLui64vARBproc) return;
	GLM_struct->glGetVertexAttribLui64vARBproc(index, pname, params);
}
GLsync APIENTRY glCreateSyncFromCLeventARB(struct _cl_context* context, struct _cl_event* event, GLbitfield flags){
	if(!GLM_struct->glCreateSyncFromCLeventARBproc) return 0;
	return GLM_struct->glCreateSyncFromCLeventARBproc(context, event, flags);
}
void APIENTRY glClampColorARB(GLenum target, GLenum clamp){
	if(!GLM_struct->glClampColorARBproc) return;
	GLM_struct->glClampColorARBproc(target, clamp);
}
void APIENTRY glDispatchComputeGroupSizeARB(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z){
	if(!GLM_struct->glDispatchComputeGroupSizeARBproc) return;
	GLM_struct->glDispatchComputeGroupSizeARBproc(num_groups_x, num_groups_y, num_groups_z, group_size_x, group_size_y, group_size_z);
}
void APIENTRY glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled){
	if(!GLM_struct->glDebugMessageControlARBproc) return;
	GLM_struct->glDebugMessageControlARBproc(source, type, severity, count, ids, enabled);
}
void APIENTRY glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf){
	if(!GLM_struct->glDebugMessageInsertARBproc) return;
	GLM_struct->glDebugMessageInsertARBproc(source, type, id, severity, length, buf);
}
void APIENTRY glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void* userParam){
	if(!GLM_struct->glDebugMessageCallbackARBproc) return;
	GLM_struct->glDebugMessageCallbackARBproc(callback, userParam);
}
GLuint APIENTRY glGetDebugMessageLogARB(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog){
	if(!GLM_struct->glGetDebugMessageLogARBproc) return 0;
	return GLM_struct->glGetDebugMessageLogARBproc(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
void APIENTRY glDrawBuffersARB(GLsizei n, const GLenum* bufs){
	if(!GLM_struct->glDrawBuffersARBproc) return;
	GLM_struct->glDrawBuffersARBproc(n, bufs);
}
void APIENTRY glBlendEquationiARB(GLuint buf, GLenum mode){
	if(!GLM_struct->glBlendEquationiARBproc) return;
	GLM_struct->glBlendEquationiARBproc(buf, mode);
}
void APIENTRY glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha){
	if(!GLM_struct->glBlendEquationSeparateiARBproc) return;
	GLM_struct->glBlendEquationSeparateiARBproc(buf, modeRGB, modeAlpha);
}
void APIENTRY glBlendFunciARB(GLuint buf, GLenum src, GLenum dst){
	if(!GLM_struct->glBlendFunciARBproc) return;
	GLM_struct->glBlendFunciARBproc(buf, src, dst);
}
void APIENTRY glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha){
	if(!GLM_struct->glBlendFuncSeparateiARBproc) return;
	GLM_struct->glBlendFuncSeparateiARBproc(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void APIENTRY glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount){
	if(!GLM_struct->glDrawArraysInstancedARBproc) return;
	GLM_struct->glDrawArraysInstancedARBproc(mode, first, count, primcount);
}
void APIENTRY glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount){
	if(!GLM_struct->glDrawElementsInstancedARBproc) return;
	GLM_struct->glDrawElementsInstancedARBproc(mode, count, type, indices, primcount);
}
void APIENTRY glProgramStringARB(GLenum target, GLenum format, GLsizei len, const void* string){
	if(!GLM_struct->glProgramStringARBproc) return;
	GLM_struct->glProgramStringARBproc(target, format, len, string);
}
void APIENTRY glBindProgramARB(GLenum target, GLuint program){
	if(!GLM_struct->glBindProgramARBproc) return;
	GLM_struct->glBindProgramARBproc(target, program);
}
void APIENTRY glDeleteProgramsARB(GLsizei n, const GLuint* programs){
	if(!GLM_struct->glDeleteProgramsARBproc) return;
	GLM_struct->glDeleteProgramsARBproc(n, programs);
}
void APIENTRY glGenProgramsARB(GLsizei n, GLuint* programs){
	if(!GLM_struct->glGenProgramsARBproc) return;
	GLM_struct->glGenProgramsARBproc(n, programs);
}
void APIENTRY glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glProgramEnvParameter4dARBproc) return;
	GLM_struct->glProgramEnvParameter4dARBproc(target, index, x, y, z, w);
}
void APIENTRY glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble* params){
	if(!GLM_struct->glProgramEnvParameter4dvARBproc) return;
	GLM_struct->glProgramEnvParameter4dvARBproc(target, index, params);
}
void APIENTRY glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glProgramEnvParameter4fARBproc) return;
	GLM_struct->glProgramEnvParameter4fARBproc(target, index, x, y, z, w);
}
void APIENTRY glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat* params){
	if(!GLM_struct->glProgramEnvParameter4fvARBproc) return;
	GLM_struct->glProgramEnvParameter4fvARBproc(target, index, params);
}
void APIENTRY glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glProgramLocalParameter4dARBproc) return;
	GLM_struct->glProgramLocalParameter4dARBproc(target, index, x, y, z, w);
}
void APIENTRY glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble* params){
	if(!GLM_struct->glProgramLocalParameter4dvARBproc) return;
	GLM_struct->glProgramLocalParameter4dvARBproc(target, index, params);
}
void APIENTRY glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glProgramLocalParameter4fARBproc) return;
	GLM_struct->glProgramLocalParameter4fARBproc(target, index, x, y, z, w);
}
void APIENTRY glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat* params){
	if(!GLM_struct->glProgramLocalParameter4fvARBproc) return;
	GLM_struct->glProgramLocalParameter4fvARBproc(target, index, params);
}
void APIENTRY glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble* params){
	if(!GLM_struct->glGetProgramEnvParameterdvARBproc) return;
	GLM_struct->glGetProgramEnvParameterdvARBproc(target, index, params);
}
void APIENTRY glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat* params){
	if(!GLM_struct->glGetProgramEnvParameterfvARBproc) return;
	GLM_struct->glGetProgramEnvParameterfvARBproc(target, index, params);
}
void APIENTRY glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble* params){
	if(!GLM_struct->glGetProgramLocalParameterdvARBproc) return;
	GLM_struct->glGetProgramLocalParameterdvARBproc(target, index, params);
}
void APIENTRY glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat* params){
	if(!GLM_struct->glGetProgramLocalParameterfvARBproc) return;
	GLM_struct->glGetProgramLocalParameterfvARBproc(target, index, params);
}
void APIENTRY glGetProgramivARB(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetProgramivARBproc) return;
	GLM_struct->glGetProgramivARBproc(target, pname, params);
}
void APIENTRY glGetProgramStringARB(GLenum target, GLenum pname, void* string){
	if(!GLM_struct->glGetProgramStringARBproc) return;
	GLM_struct->glGetProgramStringARBproc(target, pname, string);
}
GLboolean APIENTRY glIsProgramARB(GLuint program){
	if(!GLM_struct->glIsProgramARBproc) return 0;
	return GLM_struct->glIsProgramARBproc(program);
}
void APIENTRY glProgramParameteriARB(GLuint program, GLenum pname, GLint value){
	if(!GLM_struct->glProgramParameteriARBproc) return;
	GLM_struct->glProgramParameteriARBproc(program, pname, value);
}
void APIENTRY glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level){
	if(!GLM_struct->glFramebufferTextureARBproc) return;
	GLM_struct->glFramebufferTextureARBproc(target, attachment, texture, level);
}
void APIENTRY glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer){
	if(!GLM_struct->glFramebufferTextureLayerARBproc) return;
	GLM_struct->glFramebufferTextureLayerARBproc(target, attachment, texture, level, layer);
}
void APIENTRY glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face){
	if(!GLM_struct->glFramebufferTextureFaceARBproc) return;
	GLM_struct->glFramebufferTextureFaceARBproc(target, attachment, texture, level, face);
}
void APIENTRY glSpecializeShaderARB(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue){
	if(!GLM_struct->glSpecializeShaderARBproc) return;
	GLM_struct->glSpecializeShaderARBproc(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}
void APIENTRY glUniform1i64ARB(GLint location, GLint64 x){
	if(!GLM_struct->glUniform1i64ARBproc) return;
	GLM_struct->glUniform1i64ARBproc(location, x);
}
void APIENTRY glUniform2i64ARB(GLint location, GLint64 x, GLint64 y){
	if(!GLM_struct->glUniform2i64ARBproc) return;
	GLM_struct->glUniform2i64ARBproc(location, x, y);
}
void APIENTRY glUniform3i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z){
	if(!GLM_struct->glUniform3i64ARBproc) return;
	GLM_struct->glUniform3i64ARBproc(location, x, y, z);
}
void APIENTRY glUniform4i64ARB(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w){
	if(!GLM_struct->glUniform4i64ARBproc) return;
	GLM_struct->glUniform4i64ARBproc(location, x, y, z, w);
}
void APIENTRY glUniform1i64vARB(GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glUniform1i64vARBproc) return;
	GLM_struct->glUniform1i64vARBproc(location, count, value);
}
void APIENTRY glUniform2i64vARB(GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glUniform2i64vARBproc) return;
	GLM_struct->glUniform2i64vARBproc(location, count, value);
}
void APIENTRY glUniform3i64vARB(GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glUniform3i64vARBproc) return;
	GLM_struct->glUniform3i64vARBproc(location, count, value);
}
void APIENTRY glUniform4i64vARB(GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glUniform4i64vARBproc) return;
	GLM_struct->glUniform4i64vARBproc(location, count, value);
}
void APIENTRY glUniform1ui64ARB(GLint location, GLuint64 x){
	if(!GLM_struct->glUniform1ui64ARBproc) return;
	GLM_struct->glUniform1ui64ARBproc(location, x);
}
void APIENTRY glUniform2ui64ARB(GLint location, GLuint64 x, GLuint64 y){
	if(!GLM_struct->glUniform2ui64ARBproc) return;
	GLM_struct->glUniform2ui64ARBproc(location, x, y);
}
void APIENTRY glUniform3ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z){
	if(!GLM_struct->glUniform3ui64ARBproc) return;
	GLM_struct->glUniform3ui64ARBproc(location, x, y, z);
}
void APIENTRY glUniform4ui64ARB(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w){
	if(!GLM_struct->glUniform4ui64ARBproc) return;
	GLM_struct->glUniform4ui64ARBproc(location, x, y, z, w);
}
void APIENTRY glUniform1ui64vARB(GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glUniform1ui64vARBproc) return;
	GLM_struct->glUniform1ui64vARBproc(location, count, value);
}
void APIENTRY glUniform2ui64vARB(GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glUniform2ui64vARBproc) return;
	GLM_struct->glUniform2ui64vARBproc(location, count, value);
}
void APIENTRY glUniform3ui64vARB(GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glUniform3ui64vARBproc) return;
	GLM_struct->glUniform3ui64vARBproc(location, count, value);
}
void APIENTRY glUniform4ui64vARB(GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glUniform4ui64vARBproc) return;
	GLM_struct->glUniform4ui64vARBproc(location, count, value);
}
void APIENTRY glGetUniformi64vARB(GLuint program, GLint location, GLint64* params){
	if(!GLM_struct->glGetUniformi64vARBproc) return;
	GLM_struct->glGetUniformi64vARBproc(program, location, params);
}
void APIENTRY glGetUniformui64vARB(GLuint program, GLint location, GLuint64* params){
	if(!GLM_struct->glGetUniformui64vARBproc) return;
	GLM_struct->glGetUniformui64vARBproc(program, location, params);
}
void APIENTRY glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64* params){
	if(!GLM_struct->glGetnUniformi64vARBproc) return;
	GLM_struct->glGetnUniformi64vARBproc(program, location, bufSize, params);
}
void APIENTRY glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64* params){
	if(!GLM_struct->glGetnUniformui64vARBproc) return;
	GLM_struct->glGetnUniformui64vARBproc(program, location, bufSize, params);
}
void APIENTRY glProgramUniform1i64ARB(GLuint program, GLint location, GLint64 x){
	if(!GLM_struct->glProgramUniform1i64ARBproc) return;
	GLM_struct->glProgramUniform1i64ARBproc(program, location, x);
}
void APIENTRY glProgramUniform2i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y){
	if(!GLM_struct->glProgramUniform2i64ARBproc) return;
	GLM_struct->glProgramUniform2i64ARBproc(program, location, x, y);
}
void APIENTRY glProgramUniform3i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z){
	if(!GLM_struct->glProgramUniform3i64ARBproc) return;
	GLM_struct->glProgramUniform3i64ARBproc(program, location, x, y, z);
}
void APIENTRY glProgramUniform4i64ARB(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w){
	if(!GLM_struct->glProgramUniform4i64ARBproc) return;
	GLM_struct->glProgramUniform4i64ARBproc(program, location, x, y, z, w);
}
void APIENTRY glProgramUniform1i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glProgramUniform1i64vARBproc) return;
	GLM_struct->glProgramUniform1i64vARBproc(program, location, count, value);
}
void APIENTRY glProgramUniform2i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glProgramUniform2i64vARBproc) return;
	GLM_struct->glProgramUniform2i64vARBproc(program, location, count, value);
}
void APIENTRY glProgramUniform3i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glProgramUniform3i64vARBproc) return;
	GLM_struct->glProgramUniform3i64vARBproc(program, location, count, value);
}
void APIENTRY glProgramUniform4i64vARB(GLuint program, GLint location, GLsizei count, const GLint64* value){
	if(!GLM_struct->glProgramUniform4i64vARBproc) return;
	GLM_struct->glProgramUniform4i64vARBproc(program, location, count, value);
}
void APIENTRY glProgramUniform1ui64ARB(GLuint program, GLint location, GLuint64 x){
	if(!GLM_struct->glProgramUniform1ui64ARBproc) return;
	GLM_struct->glProgramUniform1ui64ARBproc(program, location, x);
}
void APIENTRY glProgramUniform2ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y){
	if(!GLM_struct->glProgramUniform2ui64ARBproc) return;
	GLM_struct->glProgramUniform2ui64ARBproc(program, location, x, y);
}
void APIENTRY glProgramUniform3ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z){
	if(!GLM_struct->glProgramUniform3ui64ARBproc) return;
	GLM_struct->glProgramUniform3ui64ARBproc(program, location, x, y, z);
}
void APIENTRY glProgramUniform4ui64ARB(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w){
	if(!GLM_struct->glProgramUniform4ui64ARBproc) return;
	GLM_struct->glProgramUniform4ui64ARBproc(program, location, x, y, z, w);
}
void APIENTRY glProgramUniform1ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glProgramUniform1ui64vARBproc) return;
	GLM_struct->glProgramUniform1ui64vARBproc(program, location, count, value);
}
void APIENTRY glProgramUniform2ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glProgramUniform2ui64vARBproc) return;
	GLM_struct->glProgramUniform2ui64vARBproc(program, location, count, value);
}
void APIENTRY glProgramUniform3ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glProgramUniform3ui64vARBproc) return;
	GLM_struct->glProgramUniform3ui64vARBproc(program, location, count, value);
}
void APIENTRY glProgramUniform4ui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glProgramUniform4ui64vARBproc) return;
	GLM_struct->glProgramUniform4ui64vARBproc(program, location, count, value);
}
void APIENTRY glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* table){
	if(!GLM_struct->glColorTableproc) return;
	GLM_struct->glColorTableproc(target, internalformat, width, format, type, table);
}
void APIENTRY glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glColorTableParameterfvproc) return;
	GLM_struct->glColorTableParameterfvproc(target, pname, params);
}
void APIENTRY glColorTableParameteriv(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glColorTableParameterivproc) return;
	GLM_struct->glColorTableParameterivproc(target, pname, params);
}
void APIENTRY glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyColorTableproc) return;
	GLM_struct->glCopyColorTableproc(target, internalformat, x, y, width);
}
void APIENTRY glGetColorTable(GLenum target, GLenum format, GLenum type, void* table){
	if(!GLM_struct->glGetColorTableproc) return;
	GLM_struct->glGetColorTableproc(target, format, type, table);
}
void APIENTRY glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetColorTableParameterfvproc) return;
	GLM_struct->glGetColorTableParameterfvproc(target, pname, params);
}
void APIENTRY glGetColorTableParameteriv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetColorTableParameterivproc) return;
	GLM_struct->glGetColorTableParameterivproc(target, pname, params);
}
void APIENTRY glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glColorSubTableproc) return;
	GLM_struct->glColorSubTableproc(target, start, count, format, type, data);
}
void APIENTRY glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyColorSubTableproc) return;
	GLM_struct->glCopyColorSubTableproc(target, start, x, y, width);
}
void APIENTRY glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* image){
	if(!GLM_struct->glConvolutionFilter1Dproc) return;
	GLM_struct->glConvolutionFilter1Dproc(target, internalformat, width, format, type, image);
}
void APIENTRY glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* image){
	if(!GLM_struct->glConvolutionFilter2Dproc) return;
	GLM_struct->glConvolutionFilter2Dproc(target, internalformat, width, height, format, type, image);
}
void APIENTRY glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params){
	if(!GLM_struct->glConvolutionParameterfproc) return;
	GLM_struct->glConvolutionParameterfproc(target, pname, params);
}
void APIENTRY glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glConvolutionParameterfvproc) return;
	GLM_struct->glConvolutionParameterfvproc(target, pname, params);
}
void APIENTRY glConvolutionParameteri(GLenum target, GLenum pname, GLint params){
	if(!GLM_struct->glConvolutionParameteriproc) return;
	GLM_struct->glConvolutionParameteriproc(target, pname, params);
}
void APIENTRY glConvolutionParameteriv(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glConvolutionParameterivproc) return;
	GLM_struct->glConvolutionParameterivproc(target, pname, params);
}
void APIENTRY glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyConvolutionFilter1Dproc) return;
	GLM_struct->glCopyConvolutionFilter1Dproc(target, internalformat, x, y, width);
}
void APIENTRY glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyConvolutionFilter2Dproc) return;
	GLM_struct->glCopyConvolutionFilter2Dproc(target, internalformat, x, y, width, height);
}
void APIENTRY glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, void* image){
	if(!GLM_struct->glGetConvolutionFilterproc) return;
	GLM_struct->glGetConvolutionFilterproc(target, format, type, image);
}
void APIENTRY glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetConvolutionParameterfvproc) return;
	GLM_struct->glGetConvolutionParameterfvproc(target, pname, params);
}
void APIENTRY glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetConvolutionParameterivproc) return;
	GLM_struct->glGetConvolutionParameterivproc(target, pname, params);
}
void APIENTRY glGetSeparableFilter(GLenum target, GLenum format, GLenum type, void* row, void* column, void* span){
	if(!GLM_struct->glGetSeparableFilterproc) return;
	GLM_struct->glGetSeparableFilterproc(target, format, type, row, column, span);
}
void APIENTRY glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* row, const void* column){
	if(!GLM_struct->glSeparableFilter2Dproc) return;
	GLM_struct->glSeparableFilter2Dproc(target, internalformat, width, height, format, type, row, column);
}
void APIENTRY glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values){
	if(!GLM_struct->glGetHistogramproc) return;
	GLM_struct->glGetHistogramproc(target, reset, format, type, values);
}
void APIENTRY glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetHistogramParameterfvproc) return;
	GLM_struct->glGetHistogramParameterfvproc(target, pname, params);
}
void APIENTRY glGetHistogramParameteriv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetHistogramParameterivproc) return;
	GLM_struct->glGetHistogramParameterivproc(target, pname, params);
}
void APIENTRY glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values){
	if(!GLM_struct->glGetMinmaxproc) return;
	GLM_struct->glGetMinmaxproc(target, reset, format, type, values);
}
void APIENTRY glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMinmaxParameterfvproc) return;
	GLM_struct->glGetMinmaxParameterfvproc(target, pname, params);
}
void APIENTRY glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMinmaxParameterivproc) return;
	GLM_struct->glGetMinmaxParameterivproc(target, pname, params);
}
void APIENTRY glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink){
	if(!GLM_struct->glHistogramproc) return;
	GLM_struct->glHistogramproc(target, width, internalformat, sink);
}
void APIENTRY glMinmax(GLenum target, GLenum internalformat, GLboolean sink){
	if(!GLM_struct->glMinmaxproc) return;
	GLM_struct->glMinmaxproc(target, internalformat, sink);
}
void APIENTRY glResetHistogram(GLenum target){
	if(!GLM_struct->glResetHistogramproc) return;
	GLM_struct->glResetHistogramproc(target);
}
void APIENTRY glResetMinmax(GLenum target){
	if(!GLM_struct->glResetMinmaxproc) return;
	GLM_struct->glResetMinmaxproc(target);
}
void APIENTRY glMultiDrawArraysIndirectCountARB(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawArraysIndirectCountARBproc) return;
	GLM_struct->glMultiDrawArraysIndirectCountARBproc(mode, indirect, drawcount, maxdrawcount, stride);
}
void APIENTRY glMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawElementsIndirectCountARBproc) return;
	GLM_struct->glMultiDrawElementsIndirectCountARBproc(mode, type, indirect, drawcount, maxdrawcount, stride);
}
void APIENTRY glVertexAttribDivisorARB(GLuint index, GLuint divisor){
	if(!GLM_struct->glVertexAttribDivisorARBproc) return;
	GLM_struct->glVertexAttribDivisorARBproc(index, divisor);
}
void APIENTRY glCurrentPaletteMatrixARB(GLint index){
	if(!GLM_struct->glCurrentPaletteMatrixARBproc) return;
	GLM_struct->glCurrentPaletteMatrixARBproc(index);
}
void APIENTRY glMatrixIndexubvARB(GLint size, const GLubyte* indices){
	if(!GLM_struct->glMatrixIndexubvARBproc) return;
	GLM_struct->glMatrixIndexubvARBproc(size, indices);
}
void APIENTRY glMatrixIndexusvARB(GLint size, const GLushort* indices){
	if(!GLM_struct->glMatrixIndexusvARBproc) return;
	GLM_struct->glMatrixIndexusvARBproc(size, indices);
}
void APIENTRY glMatrixIndexuivARB(GLint size, const GLuint* indices){
	if(!GLM_struct->glMatrixIndexuivARBproc) return;
	GLM_struct->glMatrixIndexuivARBproc(size, indices);
}
void APIENTRY glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glMatrixIndexPointerARBproc) return;
	GLM_struct->glMatrixIndexPointerARBproc(size, type, stride, pointer);
}
void APIENTRY glSampleCoverageARB(GLfloat value, GLboolean invert){
	if(!GLM_struct->glSampleCoverageARBproc) return;
	GLM_struct->glSampleCoverageARBproc(value, invert);
}
void APIENTRY glActiveTextureARB(GLenum texture){
	if(!GLM_struct->glActiveTextureARBproc) return;
	GLM_struct->glActiveTextureARBproc(texture);
}
void APIENTRY glClientActiveTextureARB(GLenum texture){
	if(!GLM_struct->glClientActiveTextureARBproc) return;
	GLM_struct->glClientActiveTextureARBproc(texture);
}
void APIENTRY glMultiTexCoord1dARB(GLenum target, GLdouble s){
	if(!GLM_struct->glMultiTexCoord1dARBproc) return;
	GLM_struct->glMultiTexCoord1dARBproc(target, s);
}
void APIENTRY glMultiTexCoord1dvARB(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord1dvARBproc) return;
	GLM_struct->glMultiTexCoord1dvARBproc(target, v);
}
void APIENTRY glMultiTexCoord1fARB(GLenum target, GLfloat s){
	if(!GLM_struct->glMultiTexCoord1fARBproc) return;
	GLM_struct->glMultiTexCoord1fARBproc(target, s);
}
void APIENTRY glMultiTexCoord1fvARB(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord1fvARBproc) return;
	GLM_struct->glMultiTexCoord1fvARBproc(target, v);
}
void APIENTRY glMultiTexCoord1iARB(GLenum target, GLint s){
	if(!GLM_struct->glMultiTexCoord1iARBproc) return;
	GLM_struct->glMultiTexCoord1iARBproc(target, s);
}
void APIENTRY glMultiTexCoord1ivARB(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord1ivARBproc) return;
	GLM_struct->glMultiTexCoord1ivARBproc(target, v);
}
void APIENTRY glMultiTexCoord1sARB(GLenum target, GLshort s){
	if(!GLM_struct->glMultiTexCoord1sARBproc) return;
	GLM_struct->glMultiTexCoord1sARBproc(target, s);
}
void APIENTRY glMultiTexCoord1svARB(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord1svARBproc) return;
	GLM_struct->glMultiTexCoord1svARBproc(target, v);
}
void APIENTRY glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t){
	if(!GLM_struct->glMultiTexCoord2dARBproc) return;
	GLM_struct->glMultiTexCoord2dARBproc(target, s, t);
}
void APIENTRY glMultiTexCoord2dvARB(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord2dvARBproc) return;
	GLM_struct->glMultiTexCoord2dvARBproc(target, v);
}
void APIENTRY glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t){
	if(!GLM_struct->glMultiTexCoord2fARBproc) return;
	GLM_struct->glMultiTexCoord2fARBproc(target, s, t);
}
void APIENTRY glMultiTexCoord2fvARB(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord2fvARBproc) return;
	GLM_struct->glMultiTexCoord2fvARBproc(target, v);
}
void APIENTRY glMultiTexCoord2iARB(GLenum target, GLint s, GLint t){
	if(!GLM_struct->glMultiTexCoord2iARBproc) return;
	GLM_struct->glMultiTexCoord2iARBproc(target, s, t);
}
void APIENTRY glMultiTexCoord2ivARB(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord2ivARBproc) return;
	GLM_struct->glMultiTexCoord2ivARBproc(target, v);
}
void APIENTRY glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t){
	if(!GLM_struct->glMultiTexCoord2sARBproc) return;
	GLM_struct->glMultiTexCoord2sARBproc(target, s, t);
}
void APIENTRY glMultiTexCoord2svARB(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord2svARBproc) return;
	GLM_struct->glMultiTexCoord2svARBproc(target, v);
}
void APIENTRY glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r){
	if(!GLM_struct->glMultiTexCoord3dARBproc) return;
	GLM_struct->glMultiTexCoord3dARBproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3dvARB(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord3dvARBproc) return;
	GLM_struct->glMultiTexCoord3dvARBproc(target, v);
}
void APIENTRY glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r){
	if(!GLM_struct->glMultiTexCoord3fARBproc) return;
	GLM_struct->glMultiTexCoord3fARBproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3fvARB(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord3fvARBproc) return;
	GLM_struct->glMultiTexCoord3fvARBproc(target, v);
}
void APIENTRY glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r){
	if(!GLM_struct->glMultiTexCoord3iARBproc) return;
	GLM_struct->glMultiTexCoord3iARBproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3ivARB(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord3ivARBproc) return;
	GLM_struct->glMultiTexCoord3ivARBproc(target, v);
}
void APIENTRY glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r){
	if(!GLM_struct->glMultiTexCoord3sARBproc) return;
	GLM_struct->glMultiTexCoord3sARBproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3svARB(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord3svARBproc) return;
	GLM_struct->glMultiTexCoord3svARBproc(target, v);
}
void APIENTRY glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q){
	if(!GLM_struct->glMultiTexCoord4dARBproc) return;
	GLM_struct->glMultiTexCoord4dARBproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4dvARB(GLenum target, const GLdouble* v){
	if(!GLM_struct->glMultiTexCoord4dvARBproc) return;
	GLM_struct->glMultiTexCoord4dvARBproc(target, v);
}
void APIENTRY glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q){
	if(!GLM_struct->glMultiTexCoord4fARBproc) return;
	GLM_struct->glMultiTexCoord4fARBproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4fvARB(GLenum target, const GLfloat* v){
	if(!GLM_struct->glMultiTexCoord4fvARBproc) return;
	GLM_struct->glMultiTexCoord4fvARBproc(target, v);
}
void APIENTRY glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q){
	if(!GLM_struct->glMultiTexCoord4iARBproc) return;
	GLM_struct->glMultiTexCoord4iARBproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4ivARB(GLenum target, const GLint* v){
	if(!GLM_struct->glMultiTexCoord4ivARBproc) return;
	GLM_struct->glMultiTexCoord4ivARBproc(target, v);
}
void APIENTRY glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q){
	if(!GLM_struct->glMultiTexCoord4sARBproc) return;
	GLM_struct->glMultiTexCoord4sARBproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4svARB(GLenum target, const GLshort* v){
	if(!GLM_struct->glMultiTexCoord4svARBproc) return;
	GLM_struct->glMultiTexCoord4svARBproc(target, v);
}
void APIENTRY glGenQueriesARB(GLsizei n, GLuint* ids){
	if(!GLM_struct->glGenQueriesARBproc) return;
	GLM_struct->glGenQueriesARBproc(n, ids);
}
void APIENTRY glDeleteQueriesARB(GLsizei n, const GLuint* ids){
	if(!GLM_struct->glDeleteQueriesARBproc) return;
	GLM_struct->glDeleteQueriesARBproc(n, ids);
}
GLboolean APIENTRY glIsQueryARB(GLuint id){
	if(!GLM_struct->glIsQueryARBproc) return 0;
	return GLM_struct->glIsQueryARBproc(id);
}
void APIENTRY glBeginQueryARB(GLenum target, GLuint id){
	if(!GLM_struct->glBeginQueryARBproc) return;
	GLM_struct->glBeginQueryARBproc(target, id);
}
void APIENTRY glEndQueryARB(GLenum target){
	if(!GLM_struct->glEndQueryARBproc) return;
	GLM_struct->glEndQueryARBproc(target);
}
void APIENTRY glGetQueryivARB(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetQueryivARBproc) return;
	GLM_struct->glGetQueryivARBproc(target, pname, params);
}
void APIENTRY glGetQueryObjectivARB(GLuint id, GLenum pname, GLint* params){
	if(!GLM_struct->glGetQueryObjectivARBproc) return;
	GLM_struct->glGetQueryObjectivARBproc(id, pname, params);
}
void APIENTRY glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetQueryObjectuivARBproc) return;
	GLM_struct->glGetQueryObjectuivARBproc(id, pname, params);
}
void APIENTRY glMaxShaderCompilerThreadsARB(GLuint count){
	if(!GLM_struct->glMaxShaderCompilerThreadsARBproc) return;
	GLM_struct->glMaxShaderCompilerThreadsARBproc(count);
}
void APIENTRY glPointParameterfARB(GLenum pname, GLfloat param){
	if(!GLM_struct->glPointParameterfARBproc) return;
	GLM_struct->glPointParameterfARBproc(pname, param);
}
void APIENTRY glPointParameterfvARB(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glPointParameterfvARBproc) return;
	GLM_struct->glPointParameterfvARBproc(pname, params);
}
GLenum APIENTRY glGetGraphicsResetStatusARB(void){
	if(!GLM_struct->glGetGraphicsResetStatusARBproc) return 0;
	return GLM_struct->glGetGraphicsResetStatusARBproc();
}
void APIENTRY glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img){
	if(!GLM_struct->glGetnTexImageARBproc) return;
	GLM_struct->glGetnTexImageARBproc(target, level, format, type, bufSize, img);
}
void APIENTRY glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data){
	if(!GLM_struct->glReadnPixelsARBproc) return;
	GLM_struct->glReadnPixelsARBproc(x, y, width, height, format, type, bufSize, data);
}
void APIENTRY glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void* img){
	if(!GLM_struct->glGetnCompressedTexImageARBproc) return;
	GLM_struct->glGetnCompressedTexImageARBproc(target, lod, bufSize, img);
}
void APIENTRY glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params){
	if(!GLM_struct->glGetnUniformfvARBproc) return;
	GLM_struct->glGetnUniformfvARBproc(program, location, bufSize, params);
}
void APIENTRY glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params){
	if(!GLM_struct->glGetnUniformivARBproc) return;
	GLM_struct->glGetnUniformivARBproc(program, location, bufSize, params);
}
void APIENTRY glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params){
	if(!GLM_struct->glGetnUniformuivARBproc) return;
	GLM_struct->glGetnUniformuivARBproc(program, location, bufSize, params);
}
void APIENTRY glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params){
	if(!GLM_struct->glGetnUniformdvARBproc) return;
	GLM_struct->glGetnUniformdvARBproc(program, location, bufSize, params);
}
void APIENTRY glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v){
	if(!GLM_struct->glGetnMapdvARBproc) return;
	GLM_struct->glGetnMapdvARBproc(target, query, bufSize, v);
}
void APIENTRY glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v){
	if(!GLM_struct->glGetnMapfvARBproc) return;
	GLM_struct->glGetnMapfvARBproc(target, query, bufSize, v);
}
void APIENTRY glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint* v){
	if(!GLM_struct->glGetnMapivARBproc) return;
	GLM_struct->glGetnMapivARBproc(target, query, bufSize, v);
}
void APIENTRY glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat* values){
	if(!GLM_struct->glGetnPixelMapfvARBproc) return;
	GLM_struct->glGetnPixelMapfvARBproc(map, bufSize, values);
}
void APIENTRY glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint* values){
	if(!GLM_struct->glGetnPixelMapuivARBproc) return;
	GLM_struct->glGetnPixelMapuivARBproc(map, bufSize, values);
}
void APIENTRY glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort* values){
	if(!GLM_struct->glGetnPixelMapusvARBproc) return;
	GLM_struct->glGetnPixelMapusvARBproc(map, bufSize, values);
}
void APIENTRY glGetnPolygonStippleARB(GLsizei bufSize, GLubyte* pattern){
	if(!GLM_struct->glGetnPolygonStippleARBproc) return;
	GLM_struct->glGetnPolygonStippleARBproc(bufSize, pattern);
}
void APIENTRY glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table){
	if(!GLM_struct->glGetnColorTableARBproc) return;
	GLM_struct->glGetnColorTableARBproc(target, format, type, bufSize, table);
}
void APIENTRY glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image){
	if(!GLM_struct->glGetnConvolutionFilterARBproc) return;
	GLM_struct->glGetnConvolutionFilterARBproc(target, format, type, bufSize, image);
}
void APIENTRY glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, void* column, void* span){
	if(!GLM_struct->glGetnSeparableFilterARBproc) return;
	GLM_struct->glGetnSeparableFilterARBproc(target, format, type, rowBufSize, row, columnBufSize, column, span);
}
void APIENTRY glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values){
	if(!GLM_struct->glGetnHistogramARBproc) return;
	GLM_struct->glGetnHistogramARBproc(target, reset, format, type, bufSize, values);
}
void APIENTRY glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values){
	if(!GLM_struct->glGetnMinmaxARBproc) return;
	GLM_struct->glGetnMinmaxARBproc(target, reset, format, type, bufSize, values);
}
void APIENTRY glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glFramebufferSampleLocationsfvARBproc) return;
	GLM_struct->glFramebufferSampleLocationsfvARBproc(target, start, count, v);
}
void APIENTRY glNamedFramebufferSampleLocationsfvARB(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glNamedFramebufferSampleLocationsfvARBproc) return;
	GLM_struct->glNamedFramebufferSampleLocationsfvARBproc(framebuffer, start, count, v);
}
void APIENTRY glEvaluateDepthValuesARB(void){
	if(!GLM_struct->glEvaluateDepthValuesARBproc) return;
	GLM_struct->glEvaluateDepthValuesARBproc();
}
void APIENTRY glMinSampleShadingARB(GLfloat value){
	if(!GLM_struct->glMinSampleShadingARBproc) return;
	GLM_struct->glMinSampleShadingARBproc(value);
}
void APIENTRY glDeleteObjectARB(GLhandleARB obj){
	if(!GLM_struct->glDeleteObjectARBproc) return;
	GLM_struct->glDeleteObjectARBproc(obj);
}
GLhandleARB APIENTRY glGetHandleARB(GLenum pname){
	if(!GLM_struct->glGetHandleARBproc) return 0;
	return GLM_struct->glGetHandleARBproc(pname);
}
void APIENTRY glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj){
	if(!GLM_struct->glDetachObjectARBproc) return;
	GLM_struct->glDetachObjectARBproc(containerObj, attachedObj);
}
GLhandleARB APIENTRY glCreateShaderObjectARB(GLenum shaderType){
	if(!GLM_struct->glCreateShaderObjectARBproc) return 0;
	return GLM_struct->glCreateShaderObjectARBproc(shaderType);
}
void APIENTRY glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB** string, const GLint* length){
	if(!GLM_struct->glShaderSourceARBproc) return;
	GLM_struct->glShaderSourceARBproc(shaderObj, count, string, length);
}
void APIENTRY glCompileShaderARB(GLhandleARB shaderObj){
	if(!GLM_struct->glCompileShaderARBproc) return;
	GLM_struct->glCompileShaderARBproc(shaderObj);
}
GLhandleARB APIENTRY glCreateProgramObjectARB(void){
	if(!GLM_struct->glCreateProgramObjectARBproc) return 0;
	return GLM_struct->glCreateProgramObjectARBproc();
}
void APIENTRY glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj){
	if(!GLM_struct->glAttachObjectARBproc) return;
	GLM_struct->glAttachObjectARBproc(containerObj, obj);
}
void APIENTRY glLinkProgramARB(GLhandleARB programObj){
	if(!GLM_struct->glLinkProgramARBproc) return;
	GLM_struct->glLinkProgramARBproc(programObj);
}
void APIENTRY glUseProgramObjectARB(GLhandleARB programObj){
	if(!GLM_struct->glUseProgramObjectARBproc) return;
	GLM_struct->glUseProgramObjectARBproc(programObj);
}
void APIENTRY glValidateProgramARB(GLhandleARB programObj){
	if(!GLM_struct->glValidateProgramARBproc) return;
	GLM_struct->glValidateProgramARBproc(programObj);
}
void APIENTRY glUniform1fARB(GLint location, GLfloat v0){
	if(!GLM_struct->glUniform1fARBproc) return;
	GLM_struct->glUniform1fARBproc(location, v0);
}
void APIENTRY glUniform2fARB(GLint location, GLfloat v0, GLfloat v1){
	if(!GLM_struct->glUniform2fARBproc) return;
	GLM_struct->glUniform2fARBproc(location, v0, v1);
}
void APIENTRY glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2){
	if(!GLM_struct->glUniform3fARBproc) return;
	GLM_struct->glUniform3fARBproc(location, v0, v1, v2);
}
void APIENTRY glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3){
	if(!GLM_struct->glUniform4fARBproc) return;
	GLM_struct->glUniform4fARBproc(location, v0, v1, v2, v3);
}
void APIENTRY glUniform1iARB(GLint location, GLint v0){
	if(!GLM_struct->glUniform1iARBproc) return;
	GLM_struct->glUniform1iARBproc(location, v0);
}
void APIENTRY glUniform2iARB(GLint location, GLint v0, GLint v1){
	if(!GLM_struct->glUniform2iARBproc) return;
	GLM_struct->glUniform2iARBproc(location, v0, v1);
}
void APIENTRY glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2){
	if(!GLM_struct->glUniform3iARBproc) return;
	GLM_struct->glUniform3iARBproc(location, v0, v1, v2);
}
void APIENTRY glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3){
	if(!GLM_struct->glUniform4iARBproc) return;
	GLM_struct->glUniform4iARBproc(location, v0, v1, v2, v3);
}
void APIENTRY glUniform1fvARB(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform1fvARBproc) return;
	GLM_struct->glUniform1fvARBproc(location, count, value);
}
void APIENTRY glUniform2fvARB(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform2fvARBproc) return;
	GLM_struct->glUniform2fvARBproc(location, count, value);
}
void APIENTRY glUniform3fvARB(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform3fvARBproc) return;
	GLM_struct->glUniform3fvARBproc(location, count, value);
}
void APIENTRY glUniform4fvARB(GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glUniform4fvARBproc) return;
	GLM_struct->glUniform4fvARBproc(location, count, value);
}
void APIENTRY glUniform1ivARB(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform1ivARBproc) return;
	GLM_struct->glUniform1ivARBproc(location, count, value);
}
void APIENTRY glUniform2ivARB(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform2ivARBproc) return;
	GLM_struct->glUniform2ivARBproc(location, count, value);
}
void APIENTRY glUniform3ivARB(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform3ivARBproc) return;
	GLM_struct->glUniform3ivARBproc(location, count, value);
}
void APIENTRY glUniform4ivARB(GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glUniform4ivARBproc) return;
	GLM_struct->glUniform4ivARBproc(location, count, value);
}
void APIENTRY glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix2fvARBproc) return;
	GLM_struct->glUniformMatrix2fvARBproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix3fvARBproc) return;
	GLM_struct->glUniformMatrix3fvARBproc(location, count, transpose, value);
}
void APIENTRY glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glUniformMatrix4fvARBproc) return;
	GLM_struct->glUniformMatrix4fvARBproc(location, count, transpose, value);
}
void APIENTRY glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetObjectParameterfvARBproc) return;
	GLM_struct->glGetObjectParameterfvARBproc(obj, pname, params);
}
void APIENTRY glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint* params){
	if(!GLM_struct->glGetObjectParameterivARBproc) return;
	GLM_struct->glGetObjectParameterivARBproc(obj, pname, params);
}
void APIENTRY glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog){
	if(!GLM_struct->glGetInfoLogARBproc) return;
	GLM_struct->glGetInfoLogARBproc(obj, maxLength, length, infoLog);
}
void APIENTRY glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei* count, GLhandleARB* obj){
	if(!GLM_struct->glGetAttachedObjectsARBproc) return;
	GLM_struct->glGetAttachedObjectsARBproc(containerObj, maxCount, count, obj);
}
GLint APIENTRY glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB* name){
	if(!GLM_struct->glGetUniformLocationARBproc) return 0;
	return GLM_struct->glGetUniformLocationARBproc(programObj, name);
}
void APIENTRY glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name){
	if(!GLM_struct->glGetActiveUniformARBproc) return;
	GLM_struct->glGetActiveUniformARBproc(programObj, index, maxLength, length, size, type, name);
}
void APIENTRY glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat* params){
	if(!GLM_struct->glGetUniformfvARBproc) return;
	GLM_struct->glGetUniformfvARBproc(programObj, location, params);
}
void APIENTRY glGetUniformivARB(GLhandleARB programObj, GLint location, GLint* params){
	if(!GLM_struct->glGetUniformivARBproc) return;
	GLM_struct->glGetUniformivARBproc(programObj, location, params);
}
void APIENTRY glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* source){
	if(!GLM_struct->glGetShaderSourceARBproc) return;
	GLM_struct->glGetShaderSourceARBproc(obj, maxLength, length, source);
}
void APIENTRY glNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string){
	if(!GLM_struct->glNamedStringARBproc) return;
	GLM_struct->glNamedStringARBproc(type, namelen, name, stringlen, string);
}
void APIENTRY glDeleteNamedStringARB(GLint namelen, const GLchar* name){
	if(!GLM_struct->glDeleteNamedStringARBproc) return;
	GLM_struct->glDeleteNamedStringARBproc(namelen, name);
}
void APIENTRY glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length){
	if(!GLM_struct->glCompileShaderIncludeARBproc) return;
	GLM_struct->glCompileShaderIncludeARBproc(shader, count, path, length);
}
GLboolean APIENTRY glIsNamedStringARB(GLint namelen, const GLchar* name){
	if(!GLM_struct->glIsNamedStringARBproc) return 0;
	return GLM_struct->glIsNamedStringARBproc(namelen, name);
}
void APIENTRY glGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string){
	if(!GLM_struct->glGetNamedStringARBproc) return;
	GLM_struct->glGetNamedStringARBproc(namelen, name, bufSize, stringlen, string);
}
void APIENTRY glGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedStringivARBproc) return;
	GLM_struct->glGetNamedStringivARBproc(namelen, name, pname, params);
}
void APIENTRY glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit){
	if(!GLM_struct->glBufferPageCommitmentARBproc) return;
	GLM_struct->glBufferPageCommitmentARBproc(target, offset, size, commit);
}
void APIENTRY glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit){
	if(!GLM_struct->glNamedBufferPageCommitmentEXTproc) return;
	GLM_struct->glNamedBufferPageCommitmentEXTproc(buffer, offset, size, commit);
}
void APIENTRY glNamedBufferPageCommitmentARB(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit){
	if(!GLM_struct->glNamedBufferPageCommitmentARBproc) return;
	GLM_struct->glNamedBufferPageCommitmentARBproc(buffer, offset, size, commit);
}
void APIENTRY glTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit){
	if(!GLM_struct->glTexPageCommitmentARBproc) return;
	GLM_struct->glTexPageCommitmentARBproc(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
void APIENTRY glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer){
	if(!GLM_struct->glTexBufferARBproc) return;
	GLM_struct->glTexBufferARBproc(target, internalformat, buffer);
}
void APIENTRY glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexImage3DARBproc) return;
	GLM_struct->glCompressedTexImage3DARBproc(target, level, internalformat, width, height, depth, border, imageSize, data);
}
void APIENTRY glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexImage2DARBproc) return;
	GLM_struct->glCompressedTexImage2DARBproc(target, level, internalformat, width, height, border, imageSize, data);
}
void APIENTRY glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexImage1DARBproc) return;
	GLM_struct->glCompressedTexImage1DARBproc(target, level, internalformat, width, border, imageSize, data);
}
void APIENTRY glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexSubImage3DARBproc) return;
	GLM_struct->glCompressedTexSubImage3DARBproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void APIENTRY glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexSubImage2DARBproc) return;
	GLM_struct->glCompressedTexSubImage2DARBproc(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void APIENTRY glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data){
	if(!GLM_struct->glCompressedTexSubImage1DARBproc) return;
	GLM_struct->glCompressedTexSubImage1DARBproc(target, level, xoffset, width, format, imageSize, data);
}
void APIENTRY glGetCompressedTexImageARB(GLenum target, GLint level, void* img){
	if(!GLM_struct->glGetCompressedTexImageARBproc) return;
	GLM_struct->glGetCompressedTexImageARBproc(target, level, img);
}
void APIENTRY glLoadTransposeMatrixfARB(const GLfloat* m){
	if(!GLM_struct->glLoadTransposeMatrixfARBproc) return;
	GLM_struct->glLoadTransposeMatrixfARBproc(m);
}
void APIENTRY glLoadTransposeMatrixdARB(const GLdouble* m){
	if(!GLM_struct->glLoadTransposeMatrixdARBproc) return;
	GLM_struct->glLoadTransposeMatrixdARBproc(m);
}
void APIENTRY glMultTransposeMatrixfARB(const GLfloat* m){
	if(!GLM_struct->glMultTransposeMatrixfARBproc) return;
	GLM_struct->glMultTransposeMatrixfARBproc(m);
}
void APIENTRY glMultTransposeMatrixdARB(const GLdouble* m){
	if(!GLM_struct->glMultTransposeMatrixdARBproc) return;
	GLM_struct->glMultTransposeMatrixdARBproc(m);
}
void APIENTRY glWeightbvARB(GLint size, const GLbyte* weights){
	if(!GLM_struct->glWeightbvARBproc) return;
	GLM_struct->glWeightbvARBproc(size, weights);
}
void APIENTRY glWeightsvARB(GLint size, const GLshort* weights){
	if(!GLM_struct->glWeightsvARBproc) return;
	GLM_struct->glWeightsvARBproc(size, weights);
}
void APIENTRY glWeightivARB(GLint size, const GLint* weights){
	if(!GLM_struct->glWeightivARBproc) return;
	GLM_struct->glWeightivARBproc(size, weights);
}
void APIENTRY glWeightfvARB(GLint size, const GLfloat* weights){
	if(!GLM_struct->glWeightfvARBproc) return;
	GLM_struct->glWeightfvARBproc(size, weights);
}
void APIENTRY glWeightdvARB(GLint size, const GLdouble* weights){
	if(!GLM_struct->glWeightdvARBproc) return;
	GLM_struct->glWeightdvARBproc(size, weights);
}
void APIENTRY glWeightubvARB(GLint size, const GLubyte* weights){
	if(!GLM_struct->glWeightubvARBproc) return;
	GLM_struct->glWeightubvARBproc(size, weights);
}
void APIENTRY glWeightusvARB(GLint size, const GLushort* weights){
	if(!GLM_struct->glWeightusvARBproc) return;
	GLM_struct->glWeightusvARBproc(size, weights);
}
void APIENTRY glWeightuivARB(GLint size, const GLuint* weights){
	if(!GLM_struct->glWeightuivARBproc) return;
	GLM_struct->glWeightuivARBproc(size, weights);
}
void APIENTRY glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glWeightPointerARBproc) return;
	GLM_struct->glWeightPointerARBproc(size, type, stride, pointer);
}
void APIENTRY glVertexBlendARB(GLint count){
	if(!GLM_struct->glVertexBlendARBproc) return;
	GLM_struct->glVertexBlendARBproc(count);
}
void APIENTRY glBindBufferARB(GLenum target, GLuint buffer){
	if(!GLM_struct->glBindBufferARBproc) return;
	GLM_struct->glBindBufferARBproc(target, buffer);
}
void APIENTRY glDeleteBuffersARB(GLsizei n, const GLuint* buffers){
	if(!GLM_struct->glDeleteBuffersARBproc) return;
	GLM_struct->glDeleteBuffersARBproc(n, buffers);
}
void APIENTRY glGenBuffersARB(GLsizei n, GLuint* buffers){
	if(!GLM_struct->glGenBuffersARBproc) return;
	GLM_struct->glGenBuffersARBproc(n, buffers);
}
GLboolean APIENTRY glIsBufferARB(GLuint buffer){
	if(!GLM_struct->glIsBufferARBproc) return 0;
	return GLM_struct->glIsBufferARBproc(buffer);
}
void APIENTRY glBufferDataARB(GLenum target, GLsizeiptrARB size, const void* data, GLenum usage){
	if(!GLM_struct->glBufferDataARBproc) return;
	GLM_struct->glBufferDataARBproc(target, size, data, usage);
}
void APIENTRY glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void* data){
	if(!GLM_struct->glBufferSubDataARBproc) return;
	GLM_struct->glBufferSubDataARBproc(target, offset, size, data);
}
void APIENTRY glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void* data){
	if(!GLM_struct->glGetBufferSubDataARBproc) return;
	GLM_struct->glGetBufferSubDataARBproc(target, offset, size, data);
}
void* APIENTRY glMapBufferARB(GLenum target, GLenum access){
	if(!GLM_struct->glMapBufferARBproc) return 0;
	return GLM_struct->glMapBufferARBproc(target, access);
}
GLboolean APIENTRY glUnmapBufferARB(GLenum target){
	if(!GLM_struct->glUnmapBufferARBproc) return 0;
	return GLM_struct->glUnmapBufferARBproc(target);
}
void APIENTRY glGetBufferParameterivARB(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetBufferParameterivARBproc) return;
	GLM_struct->glGetBufferParameterivARBproc(target, pname, params);
}
void APIENTRY glGetBufferPointervARB(GLenum target, GLenum pname, void** params){
	if(!GLM_struct->glGetBufferPointervARBproc) return;
	GLM_struct->glGetBufferPointervARBproc(target, pname, params);
}
void APIENTRY glVertexAttrib1dARB(GLuint index, GLdouble x){
	if(!GLM_struct->glVertexAttrib1dARBproc) return;
	GLM_struct->glVertexAttrib1dARBproc(index, x);
}
void APIENTRY glVertexAttrib1dvARB(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib1dvARBproc) return;
	GLM_struct->glVertexAttrib1dvARBproc(index, v);
}
void APIENTRY glVertexAttrib1fARB(GLuint index, GLfloat x){
	if(!GLM_struct->glVertexAttrib1fARBproc) return;
	GLM_struct->glVertexAttrib1fARBproc(index, x);
}
void APIENTRY glVertexAttrib1fvARB(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib1fvARBproc) return;
	GLM_struct->glVertexAttrib1fvARBproc(index, v);
}
void APIENTRY glVertexAttrib1sARB(GLuint index, GLshort x){
	if(!GLM_struct->glVertexAttrib1sARBproc) return;
	GLM_struct->glVertexAttrib1sARBproc(index, x);
}
void APIENTRY glVertexAttrib1svARB(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib1svARBproc) return;
	GLM_struct->glVertexAttrib1svARBproc(index, v);
}
void APIENTRY glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y){
	if(!GLM_struct->glVertexAttrib2dARBproc) return;
	GLM_struct->glVertexAttrib2dARBproc(index, x, y);
}
void APIENTRY glVertexAttrib2dvARB(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib2dvARBproc) return;
	GLM_struct->glVertexAttrib2dvARBproc(index, v);
}
void APIENTRY glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y){
	if(!GLM_struct->glVertexAttrib2fARBproc) return;
	GLM_struct->glVertexAttrib2fARBproc(index, x, y);
}
void APIENTRY glVertexAttrib2fvARB(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib2fvARBproc) return;
	GLM_struct->glVertexAttrib2fvARBproc(index, v);
}
void APIENTRY glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y){
	if(!GLM_struct->glVertexAttrib2sARBproc) return;
	GLM_struct->glVertexAttrib2sARBproc(index, x, y);
}
void APIENTRY glVertexAttrib2svARB(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib2svARBproc) return;
	GLM_struct->glVertexAttrib2svARBproc(index, v);
}
void APIENTRY glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glVertexAttrib3dARBproc) return;
	GLM_struct->glVertexAttrib3dARBproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3dvARB(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib3dvARBproc) return;
	GLM_struct->glVertexAttrib3dvARBproc(index, v);
}
void APIENTRY glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glVertexAttrib3fARBproc) return;
	GLM_struct->glVertexAttrib3fARBproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3fvARB(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib3fvARBproc) return;
	GLM_struct->glVertexAttrib3fvARBproc(index, v);
}
void APIENTRY glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z){
	if(!GLM_struct->glVertexAttrib3sARBproc) return;
	GLM_struct->glVertexAttrib3sARBproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3svARB(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib3svARBproc) return;
	GLM_struct->glVertexAttrib3svARBproc(index, v);
}
void APIENTRY glVertexAttrib4NbvARB(GLuint index, const GLbyte* v){
	if(!GLM_struct->glVertexAttrib4NbvARBproc) return;
	GLM_struct->glVertexAttrib4NbvARBproc(index, v);
}
void APIENTRY glVertexAttrib4NivARB(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttrib4NivARBproc) return;
	GLM_struct->glVertexAttrib4NivARBproc(index, v);
}
void APIENTRY glVertexAttrib4NsvARB(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib4NsvARBproc) return;
	GLM_struct->glVertexAttrib4NsvARBproc(index, v);
}
void APIENTRY glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w){
	if(!GLM_struct->glVertexAttrib4NubARBproc) return;
	GLM_struct->glVertexAttrib4NubARBproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4NubvARB(GLuint index, const GLubyte* v){
	if(!GLM_struct->glVertexAttrib4NubvARBproc) return;
	GLM_struct->glVertexAttrib4NubvARBproc(index, v);
}
void APIENTRY glVertexAttrib4NuivARB(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttrib4NuivARBproc) return;
	GLM_struct->glVertexAttrib4NuivARBproc(index, v);
}
void APIENTRY glVertexAttrib4NusvARB(GLuint index, const GLushort* v){
	if(!GLM_struct->glVertexAttrib4NusvARBproc) return;
	GLM_struct->glVertexAttrib4NusvARBproc(index, v);
}
void APIENTRY glVertexAttrib4bvARB(GLuint index, const GLbyte* v){
	if(!GLM_struct->glVertexAttrib4bvARBproc) return;
	GLM_struct->glVertexAttrib4bvARBproc(index, v);
}
void APIENTRY glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glVertexAttrib4dARBproc) return;
	GLM_struct->glVertexAttrib4dARBproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4dvARB(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib4dvARBproc) return;
	GLM_struct->glVertexAttrib4dvARBproc(index, v);
}
void APIENTRY glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glVertexAttrib4fARBproc) return;
	GLM_struct->glVertexAttrib4fARBproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4fvARB(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib4fvARBproc) return;
	GLM_struct->glVertexAttrib4fvARBproc(index, v);
}
void APIENTRY glVertexAttrib4ivARB(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttrib4ivARBproc) return;
	GLM_struct->glVertexAttrib4ivARBproc(index, v);
}
void APIENTRY glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w){
	if(!GLM_struct->glVertexAttrib4sARBproc) return;
	GLM_struct->glVertexAttrib4sARBproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4svARB(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib4svARBproc) return;
	GLM_struct->glVertexAttrib4svARBproc(index, v);
}
void APIENTRY glVertexAttrib4ubvARB(GLuint index, const GLubyte* v){
	if(!GLM_struct->glVertexAttrib4ubvARBproc) return;
	GLM_struct->glVertexAttrib4ubvARBproc(index, v);
}
void APIENTRY glVertexAttrib4uivARB(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttrib4uivARBproc) return;
	GLM_struct->glVertexAttrib4uivARBproc(index, v);
}
void APIENTRY glVertexAttrib4usvARB(GLuint index, const GLushort* v){
	if(!GLM_struct->glVertexAttrib4usvARBproc) return;
	GLM_struct->glVertexAttrib4usvARBproc(index, v);
}
void APIENTRY glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexAttribPointerARBproc) return;
	GLM_struct->glVertexAttribPointerARBproc(index, size, type, normalized, stride, pointer);
}
void APIENTRY glEnableVertexAttribArrayARB(GLuint index){
	if(!GLM_struct->glEnableVertexAttribArrayARBproc) return;
	GLM_struct->glEnableVertexAttribArrayARBproc(index);
}
void APIENTRY glDisableVertexAttribArrayARB(GLuint index){
	if(!GLM_struct->glDisableVertexAttribArrayARBproc) return;
	GLM_struct->glDisableVertexAttribArrayARBproc(index);
}
void APIENTRY glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetVertexAttribdvARBproc) return;
	GLM_struct->glGetVertexAttribdvARBproc(index, pname, params);
}
void APIENTRY glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetVertexAttribfvARBproc) return;
	GLM_struct->glGetVertexAttribfvARBproc(index, pname, params);
}
void APIENTRY glGetVertexAttribivARB(GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVertexAttribivARBproc) return;
	GLM_struct->glGetVertexAttribivARBproc(index, pname, params);
}
void APIENTRY glGetVertexAttribPointervARB(GLuint index, GLenum pname, void** pointer){
	if(!GLM_struct->glGetVertexAttribPointervARBproc) return;
	GLM_struct->glGetVertexAttribPointervARBproc(index, pname, pointer);
}
void APIENTRY glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB* name){
	if(!GLM_struct->glBindAttribLocationARBproc) return;
	GLM_struct->glBindAttribLocationARBproc(programObj, index, name);
}
void APIENTRY glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name){
	if(!GLM_struct->glGetActiveAttribARBproc) return;
	GLM_struct->glGetActiveAttribARBproc(programObj, index, maxLength, length, size, type, name);
}
GLint APIENTRY glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB* name){
	if(!GLM_struct->glGetAttribLocationARBproc) return 0;
	return GLM_struct->glGetAttribLocationARBproc(programObj, name);
}
void APIENTRY glDepthRangeArraydvNV(GLuint first, GLsizei count, const GLdouble* v){
	if(!GLM_struct->glDepthRangeArraydvNVproc) return;
	GLM_struct->glDepthRangeArraydvNVproc(first, count, v);
}
void APIENTRY glDepthRangeIndexeddNV(GLuint index, GLdouble n, GLdouble f){
	if(!GLM_struct->glDepthRangeIndexeddNVproc) return;
	GLM_struct->glDepthRangeIndexeddNVproc(index, n, f);
}
void APIENTRY glWindowPos2dARB(GLdouble x, GLdouble y){
	if(!GLM_struct->glWindowPos2dARBproc) return;
	GLM_struct->glWindowPos2dARBproc(x, y);
}
void APIENTRY glWindowPos2dvARB(const GLdouble* v){
	if(!GLM_struct->glWindowPos2dvARBproc) return;
	GLM_struct->glWindowPos2dvARBproc(v);
}
void APIENTRY glWindowPos2fARB(GLfloat x, GLfloat y){
	if(!GLM_struct->glWindowPos2fARBproc) return;
	GLM_struct->glWindowPos2fARBproc(x, y);
}
void APIENTRY glWindowPos2fvARB(const GLfloat* v){
	if(!GLM_struct->glWindowPos2fvARBproc) return;
	GLM_struct->glWindowPos2fvARBproc(v);
}
void APIENTRY glWindowPos2iARB(GLint x, GLint y){
	if(!GLM_struct->glWindowPos2iARBproc) return;
	GLM_struct->glWindowPos2iARBproc(x, y);
}
void APIENTRY glWindowPos2ivARB(const GLint* v){
	if(!GLM_struct->glWindowPos2ivARBproc) return;
	GLM_struct->glWindowPos2ivARBproc(v);
}
void APIENTRY glWindowPos2sARB(GLshort x, GLshort y){
	if(!GLM_struct->glWindowPos2sARBproc) return;
	GLM_struct->glWindowPos2sARBproc(x, y);
}
void APIENTRY glWindowPos2svARB(const GLshort* v){
	if(!GLM_struct->glWindowPos2svARBproc) return;
	GLM_struct->glWindowPos2svARBproc(v);
}
void APIENTRY glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glWindowPos3dARBproc) return;
	GLM_struct->glWindowPos3dARBproc(x, y, z);
}
void APIENTRY glWindowPos3dvARB(const GLdouble* v){
	if(!GLM_struct->glWindowPos3dvARBproc) return;
	GLM_struct->glWindowPos3dvARBproc(v);
}
void APIENTRY glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glWindowPos3fARBproc) return;
	GLM_struct->glWindowPos3fARBproc(x, y, z);
}
void APIENTRY glWindowPos3fvARB(const GLfloat* v){
	if(!GLM_struct->glWindowPos3fvARBproc) return;
	GLM_struct->glWindowPos3fvARBproc(v);
}
void APIENTRY glWindowPos3iARB(GLint x, GLint y, GLint z){
	if(!GLM_struct->glWindowPos3iARBproc) return;
	GLM_struct->glWindowPos3iARBproc(x, y, z);
}
void APIENTRY glWindowPos3ivARB(const GLint* v){
	if(!GLM_struct->glWindowPos3ivARBproc) return;
	GLM_struct->glWindowPos3ivARBproc(v);
}
void APIENTRY glWindowPos3sARB(GLshort x, GLshort y, GLshort z){
	if(!GLM_struct->glWindowPos3sARBproc) return;
	GLM_struct->glWindowPos3sARBproc(x, y, z);
}
void APIENTRY glWindowPos3svARB(const GLshort* v){
	if(!GLM_struct->glWindowPos3svARBproc) return;
	GLM_struct->glWindowPos3svARBproc(v);
}
void APIENTRY glBlendBarrierKHR(void){
	if(!GLM_struct->glBlendBarrierKHRproc) return;
	GLM_struct->glBlendBarrierKHRproc();
}
void APIENTRY glMaxShaderCompilerThreadsKHR(GLuint count){
	if(!GLM_struct->glMaxShaderCompilerThreadsKHRproc) return;
	GLM_struct->glMaxShaderCompilerThreadsKHRproc(count);
}
void APIENTRY glMultiTexCoord1bOES(GLenum texture, GLbyte s){
	if(!GLM_struct->glMultiTexCoord1bOESproc) return;
	GLM_struct->glMultiTexCoord1bOESproc(texture, s);
}
void APIENTRY glMultiTexCoord1bvOES(GLenum texture, const GLbyte* coords){
	if(!GLM_struct->glMultiTexCoord1bvOESproc) return;
	GLM_struct->glMultiTexCoord1bvOESproc(texture, coords);
}
void APIENTRY glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t){
	if(!GLM_struct->glMultiTexCoord2bOESproc) return;
	GLM_struct->glMultiTexCoord2bOESproc(texture, s, t);
}
void APIENTRY glMultiTexCoord2bvOES(GLenum texture, const GLbyte* coords){
	if(!GLM_struct->glMultiTexCoord2bvOESproc) return;
	GLM_struct->glMultiTexCoord2bvOESproc(texture, coords);
}
void APIENTRY glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r){
	if(!GLM_struct->glMultiTexCoord3bOESproc) return;
	GLM_struct->glMultiTexCoord3bOESproc(texture, s, t, r);
}
void APIENTRY glMultiTexCoord3bvOES(GLenum texture, const GLbyte* coords){
	if(!GLM_struct->glMultiTexCoord3bvOESproc) return;
	GLM_struct->glMultiTexCoord3bvOESproc(texture, coords);
}
void APIENTRY glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q){
	if(!GLM_struct->glMultiTexCoord4bOESproc) return;
	GLM_struct->glMultiTexCoord4bOESproc(texture, s, t, r, q);
}
void APIENTRY glMultiTexCoord4bvOES(GLenum texture, const GLbyte* coords){
	if(!GLM_struct->glMultiTexCoord4bvOESproc) return;
	GLM_struct->glMultiTexCoord4bvOESproc(texture, coords);
}
void APIENTRY glTexCoord1bOES(GLbyte s){
	if(!GLM_struct->glTexCoord1bOESproc) return;
	GLM_struct->glTexCoord1bOESproc(s);
}
void APIENTRY glTexCoord1bvOES(const GLbyte* coords){
	if(!GLM_struct->glTexCoord1bvOESproc) return;
	GLM_struct->glTexCoord1bvOESproc(coords);
}
void APIENTRY glTexCoord2bOES(GLbyte s, GLbyte t){
	if(!GLM_struct->glTexCoord2bOESproc) return;
	GLM_struct->glTexCoord2bOESproc(s, t);
}
void APIENTRY glTexCoord2bvOES(const GLbyte* coords){
	if(!GLM_struct->glTexCoord2bvOESproc) return;
	GLM_struct->glTexCoord2bvOESproc(coords);
}
void APIENTRY glTexCoord3bOES(GLbyte s, GLbyte t, GLbyte r){
	if(!GLM_struct->glTexCoord3bOESproc) return;
	GLM_struct->glTexCoord3bOESproc(s, t, r);
}
void APIENTRY glTexCoord3bvOES(const GLbyte* coords){
	if(!GLM_struct->glTexCoord3bvOESproc) return;
	GLM_struct->glTexCoord3bvOESproc(coords);
}
void APIENTRY glTexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q){
	if(!GLM_struct->glTexCoord4bOESproc) return;
	GLM_struct->glTexCoord4bOESproc(s, t, r, q);
}
void APIENTRY glTexCoord4bvOES(const GLbyte* coords){
	if(!GLM_struct->glTexCoord4bvOESproc) return;
	GLM_struct->glTexCoord4bvOESproc(coords);
}
void APIENTRY glVertex2bOES(GLbyte x, GLbyte y){
	if(!GLM_struct->glVertex2bOESproc) return;
	GLM_struct->glVertex2bOESproc(x, y);
}
void APIENTRY glVertex2bvOES(const GLbyte* coords){
	if(!GLM_struct->glVertex2bvOESproc) return;
	GLM_struct->glVertex2bvOESproc(coords);
}
void APIENTRY glVertex3bOES(GLbyte x, GLbyte y, GLbyte z){
	if(!GLM_struct->glVertex3bOESproc) return;
	GLM_struct->glVertex3bOESproc(x, y, z);
}
void APIENTRY glVertex3bvOES(const GLbyte* coords){
	if(!GLM_struct->glVertex3bvOESproc) return;
	GLM_struct->glVertex3bvOESproc(coords);
}
void APIENTRY glVertex4bOES(GLbyte x, GLbyte y, GLbyte z, GLbyte w){
	if(!GLM_struct->glVertex4bOESproc) return;
	GLM_struct->glVertex4bOESproc(x, y, z, w);
}
void APIENTRY glVertex4bvOES(const GLbyte* coords){
	if(!GLM_struct->glVertex4bvOESproc) return;
	GLM_struct->glVertex4bvOESproc(coords);
}
void APIENTRY glAlphaFuncxOES(GLenum func, GLfixed ref){
	if(!GLM_struct->glAlphaFuncxOESproc) return;
	GLM_struct->glAlphaFuncxOESproc(func, ref);
}
void APIENTRY glClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha){
	if(!GLM_struct->glClearColorxOESproc) return;
	GLM_struct->glClearColorxOESproc(red, green, blue, alpha);
}
void APIENTRY glClearDepthxOES(GLfixed depth){
	if(!GLM_struct->glClearDepthxOESproc) return;
	GLM_struct->glClearDepthxOESproc(depth);
}
void APIENTRY glClipPlanexOES(GLenum plane, const GLfixed* equation){
	if(!GLM_struct->glClipPlanexOESproc) return;
	GLM_struct->glClipPlanexOESproc(plane, equation);
}
void APIENTRY glColor4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha){
	if(!GLM_struct->glColor4xOESproc) return;
	GLM_struct->glColor4xOESproc(red, green, blue, alpha);
}
void APIENTRY glDepthRangexOES(GLfixed n, GLfixed f){
	if(!GLM_struct->glDepthRangexOESproc) return;
	GLM_struct->glDepthRangexOESproc(n, f);
}
void APIENTRY glFogxOES(GLenum pname, GLfixed param){
	if(!GLM_struct->glFogxOESproc) return;
	GLM_struct->glFogxOESproc(pname, param);
}
void APIENTRY glFogxvOES(GLenum pname, const GLfixed* param){
	if(!GLM_struct->glFogxvOESproc) return;
	GLM_struct->glFogxvOESproc(pname, param);
}
void APIENTRY glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f){
	if(!GLM_struct->glFrustumxOESproc) return;
	GLM_struct->glFrustumxOESproc(l, r, b, t, n, f);
}
void APIENTRY glGetClipPlanexOES(GLenum plane, GLfixed* equation){
	if(!GLM_struct->glGetClipPlanexOESproc) return;
	GLM_struct->glGetClipPlanexOESproc(plane, equation);
}
void APIENTRY glGetFixedvOES(GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetFixedvOESproc) return;
	GLM_struct->glGetFixedvOESproc(pname, params);
}
void APIENTRY glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetTexEnvxvOESproc) return;
	GLM_struct->glGetTexEnvxvOESproc(target, pname, params);
}
void APIENTRY glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetTexParameterxvOESproc) return;
	GLM_struct->glGetTexParameterxvOESproc(target, pname, params);
}
void APIENTRY glLightModelxOES(GLenum pname, GLfixed param){
	if(!GLM_struct->glLightModelxOESproc) return;
	GLM_struct->glLightModelxOESproc(pname, param);
}
void APIENTRY glLightModelxvOES(GLenum pname, const GLfixed* param){
	if(!GLM_struct->glLightModelxvOESproc) return;
	GLM_struct->glLightModelxvOESproc(pname, param);
}
void APIENTRY glLightxOES(GLenum light, GLenum pname, GLfixed param){
	if(!GLM_struct->glLightxOESproc) return;
	GLM_struct->glLightxOESproc(light, pname, param);
}
void APIENTRY glLightxvOES(GLenum light, GLenum pname, const GLfixed* params){
	if(!GLM_struct->glLightxvOESproc) return;
	GLM_struct->glLightxvOESproc(light, pname, params);
}
void APIENTRY glLineWidthxOES(GLfixed width){
	if(!GLM_struct->glLineWidthxOESproc) return;
	GLM_struct->glLineWidthxOESproc(width);
}
void APIENTRY glLoadMatrixxOES(const GLfixed* m){
	if(!GLM_struct->glLoadMatrixxOESproc) return;
	GLM_struct->glLoadMatrixxOESproc(m);
}
void APIENTRY glMaterialxOES(GLenum face, GLenum pname, GLfixed param){
	if(!GLM_struct->glMaterialxOESproc) return;
	GLM_struct->glMaterialxOESproc(face, pname, param);
}
void APIENTRY glMaterialxvOES(GLenum face, GLenum pname, const GLfixed* param){
	if(!GLM_struct->glMaterialxvOESproc) return;
	GLM_struct->glMaterialxvOESproc(face, pname, param);
}
void APIENTRY glMultMatrixxOES(const GLfixed* m){
	if(!GLM_struct->glMultMatrixxOESproc) return;
	GLM_struct->glMultMatrixxOESproc(m);
}
void APIENTRY glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q){
	if(!GLM_struct->glMultiTexCoord4xOESproc) return;
	GLM_struct->glMultiTexCoord4xOESproc(texture, s, t, r, q);
}
void APIENTRY glNormal3xOES(GLfixed nx, GLfixed ny, GLfixed nz){
	if(!GLM_struct->glNormal3xOESproc) return;
	GLM_struct->glNormal3xOESproc(nx, ny, nz);
}
void APIENTRY glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f){
	if(!GLM_struct->glOrthoxOESproc) return;
	GLM_struct->glOrthoxOESproc(l, r, b, t, n, f);
}
void APIENTRY glPointParameterxvOES(GLenum pname, const GLfixed* params){
	if(!GLM_struct->glPointParameterxvOESproc) return;
	GLM_struct->glPointParameterxvOESproc(pname, params);
}
void APIENTRY glPointSizexOES(GLfixed size){
	if(!GLM_struct->glPointSizexOESproc) return;
	GLM_struct->glPointSizexOESproc(size);
}
void APIENTRY glPolygonOffsetxOES(GLfixed factor, GLfixed units){
	if(!GLM_struct->glPolygonOffsetxOESproc) return;
	GLM_struct->glPolygonOffsetxOESproc(factor, units);
}
void APIENTRY glRotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z){
	if(!GLM_struct->glRotatexOESproc) return;
	GLM_struct->glRotatexOESproc(angle, x, y, z);
}
void APIENTRY glScalexOES(GLfixed x, GLfixed y, GLfixed z){
	if(!GLM_struct->glScalexOESproc) return;
	GLM_struct->glScalexOESproc(x, y, z);
}
void APIENTRY glTexEnvxOES(GLenum target, GLenum pname, GLfixed param){
	if(!GLM_struct->glTexEnvxOESproc) return;
	GLM_struct->glTexEnvxOESproc(target, pname, param);
}
void APIENTRY glTexEnvxvOES(GLenum target, GLenum pname, const GLfixed* params){
	if(!GLM_struct->glTexEnvxvOESproc) return;
	GLM_struct->glTexEnvxvOESproc(target, pname, params);
}
void APIENTRY glTexParameterxOES(GLenum target, GLenum pname, GLfixed param){
	if(!GLM_struct->glTexParameterxOESproc) return;
	GLM_struct->glTexParameterxOESproc(target, pname, param);
}
void APIENTRY glTexParameterxvOES(GLenum target, GLenum pname, const GLfixed* params){
	if(!GLM_struct->glTexParameterxvOESproc) return;
	GLM_struct->glTexParameterxvOESproc(target, pname, params);
}
void APIENTRY glTranslatexOES(GLfixed x, GLfixed y, GLfixed z){
	if(!GLM_struct->glTranslatexOESproc) return;
	GLM_struct->glTranslatexOESproc(x, y, z);
}
void APIENTRY glAccumxOES(GLenum op, GLfixed value){
	if(!GLM_struct->glAccumxOESproc) return;
	GLM_struct->glAccumxOESproc(op, value);
}
void APIENTRY glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte* bitmap){
	if(!GLM_struct->glBitmapxOESproc) return;
	GLM_struct->glBitmapxOESproc(width, height, xorig, yorig, xmove, ymove, bitmap);
}
void APIENTRY glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha){
	if(!GLM_struct->glBlendColorxOESproc) return;
	GLM_struct->glBlendColorxOESproc(red, green, blue, alpha);
}
void APIENTRY glClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha){
	if(!GLM_struct->glClearAccumxOESproc) return;
	GLM_struct->glClearAccumxOESproc(red, green, blue, alpha);
}
void APIENTRY glColor3xOES(GLfixed red, GLfixed green, GLfixed blue){
	if(!GLM_struct->glColor3xOESproc) return;
	GLM_struct->glColor3xOESproc(red, green, blue);
}
void APIENTRY glColor3xvOES(const GLfixed* components){
	if(!GLM_struct->glColor3xvOESproc) return;
	GLM_struct->glColor3xvOESproc(components);
}
void APIENTRY glColor4xvOES(const GLfixed* components){
	if(!GLM_struct->glColor4xvOESproc) return;
	GLM_struct->glColor4xvOESproc(components);
}
void APIENTRY glConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param){
	if(!GLM_struct->glConvolutionParameterxOESproc) return;
	GLM_struct->glConvolutionParameterxOESproc(target, pname, param);
}
void APIENTRY glConvolutionParameterxvOES(GLenum target, GLenum pname, const GLfixed* params){
	if(!GLM_struct->glConvolutionParameterxvOESproc) return;
	GLM_struct->glConvolutionParameterxvOESproc(target, pname, params);
}
void APIENTRY glEvalCoord1xOES(GLfixed u){
	if(!GLM_struct->glEvalCoord1xOESproc) return;
	GLM_struct->glEvalCoord1xOESproc(u);
}
void APIENTRY glEvalCoord1xvOES(const GLfixed* coords){
	if(!GLM_struct->glEvalCoord1xvOESproc) return;
	GLM_struct->glEvalCoord1xvOESproc(coords);
}
void APIENTRY glEvalCoord2xOES(GLfixed u, GLfixed v){
	if(!GLM_struct->glEvalCoord2xOESproc) return;
	GLM_struct->glEvalCoord2xOESproc(u, v);
}
void APIENTRY glEvalCoord2xvOES(const GLfixed* coords){
	if(!GLM_struct->glEvalCoord2xvOESproc) return;
	GLM_struct->glEvalCoord2xvOESproc(coords);
}
void APIENTRY glFeedbackBufferxOES(GLsizei n, GLenum type, const GLfixed* buffer){
	if(!GLM_struct->glFeedbackBufferxOESproc) return;
	GLM_struct->glFeedbackBufferxOESproc(n, type, buffer);
}
void APIENTRY glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetConvolutionParameterxvOESproc) return;
	GLM_struct->glGetConvolutionParameterxvOESproc(target, pname, params);
}
void APIENTRY glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetHistogramParameterxvOESproc) return;
	GLM_struct->glGetHistogramParameterxvOESproc(target, pname, params);
}
void APIENTRY glGetLightxOES(GLenum light, GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetLightxOESproc) return;
	GLM_struct->glGetLightxOESproc(light, pname, params);
}
void APIENTRY glGetMapxvOES(GLenum target, GLenum query, GLfixed* v){
	if(!GLM_struct->glGetMapxvOESproc) return;
	GLM_struct->glGetMapxvOESproc(target, query, v);
}
void APIENTRY glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param){
	if(!GLM_struct->glGetMaterialxOESproc) return;
	GLM_struct->glGetMaterialxOESproc(face, pname, param);
}
void APIENTRY glGetPixelMapxv(GLenum map, GLint size, GLfixed* values){
	if(!GLM_struct->glGetPixelMapxvproc) return;
	GLM_struct->glGetPixelMapxvproc(map, size, values);
}
void APIENTRY glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetTexGenxvOESproc) return;
	GLM_struct->glGetTexGenxvOESproc(coord, pname, params);
}
void APIENTRY glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed* params){
	if(!GLM_struct->glGetTexLevelParameterxvOESproc) return;
	GLM_struct->glGetTexLevelParameterxvOESproc(target, level, pname, params);
}
void APIENTRY glIndexxOES(GLfixed component){
	if(!GLM_struct->glIndexxOESproc) return;
	GLM_struct->glIndexxOESproc(component);
}
void APIENTRY glIndexxvOES(const GLfixed* component){
	if(!GLM_struct->glIndexxvOESproc) return;
	GLM_struct->glIndexxvOESproc(component);
}
void APIENTRY glLoadTransposeMatrixxOES(const GLfixed* m){
	if(!GLM_struct->glLoadTransposeMatrixxOESproc) return;
	GLM_struct->glLoadTransposeMatrixxOESproc(m);
}
void APIENTRY glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points){
	if(!GLM_struct->glMap1xOESproc) return;
	GLM_struct->glMap1xOESproc(target, u1, u2, stride, order, points);
}
void APIENTRY glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points){
	if(!GLM_struct->glMap2xOESproc) return;
	GLM_struct->glMap2xOESproc(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
void APIENTRY glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2){
	if(!GLM_struct->glMapGrid1xOESproc) return;
	GLM_struct->glMapGrid1xOESproc(n, u1, u2);
}
void APIENTRY glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2){
	if(!GLM_struct->glMapGrid2xOESproc) return;
	GLM_struct->glMapGrid2xOESproc(n, u1, u2, v1, v2);
}
void APIENTRY glMultTransposeMatrixxOES(const GLfixed* m){
	if(!GLM_struct->glMultTransposeMatrixxOESproc) return;
	GLM_struct->glMultTransposeMatrixxOESproc(m);
}
void APIENTRY glMultiTexCoord1xOES(GLenum texture, GLfixed s){
	if(!GLM_struct->glMultiTexCoord1xOESproc) return;
	GLM_struct->glMultiTexCoord1xOESproc(texture, s);
}
void APIENTRY glMultiTexCoord1xvOES(GLenum texture, const GLfixed* coords){
	if(!GLM_struct->glMultiTexCoord1xvOESproc) return;
	GLM_struct->glMultiTexCoord1xvOESproc(texture, coords);
}
void APIENTRY glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t){
	if(!GLM_struct->glMultiTexCoord2xOESproc) return;
	GLM_struct->glMultiTexCoord2xOESproc(texture, s, t);
}
void APIENTRY glMultiTexCoord2xvOES(GLenum texture, const GLfixed* coords){
	if(!GLM_struct->glMultiTexCoord2xvOESproc) return;
	GLM_struct->glMultiTexCoord2xvOESproc(texture, coords);
}
void APIENTRY glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r){
	if(!GLM_struct->glMultiTexCoord3xOESproc) return;
	GLM_struct->glMultiTexCoord3xOESproc(texture, s, t, r);
}
void APIENTRY glMultiTexCoord3xvOES(GLenum texture, const GLfixed* coords){
	if(!GLM_struct->glMultiTexCoord3xvOESproc) return;
	GLM_struct->glMultiTexCoord3xvOESproc(texture, coords);
}
void APIENTRY glMultiTexCoord4xvOES(GLenum texture, const GLfixed* coords){
	if(!GLM_struct->glMultiTexCoord4xvOESproc) return;
	GLM_struct->glMultiTexCoord4xvOESproc(texture, coords);
}
void APIENTRY glNormal3xvOES(const GLfixed* coords){
	if(!GLM_struct->glNormal3xvOESproc) return;
	GLM_struct->glNormal3xvOESproc(coords);
}
void APIENTRY glPassThroughxOES(GLfixed token){
	if(!GLM_struct->glPassThroughxOESproc) return;
	GLM_struct->glPassThroughxOESproc(token);
}
void APIENTRY glPixelMapx(GLenum map, GLint size, const GLfixed* values){
	if(!GLM_struct->glPixelMapxproc) return;
	GLM_struct->glPixelMapxproc(map, size, values);
}
void APIENTRY glPixelStorex(GLenum pname, GLfixed param){
	if(!GLM_struct->glPixelStorexproc) return;
	GLM_struct->glPixelStorexproc(pname, param);
}
void APIENTRY glPixelTransferxOES(GLenum pname, GLfixed param){
	if(!GLM_struct->glPixelTransferxOESproc) return;
	GLM_struct->glPixelTransferxOESproc(pname, param);
}
void APIENTRY glPixelZoomxOES(GLfixed xfactor, GLfixed yfactor){
	if(!GLM_struct->glPixelZoomxOESproc) return;
	GLM_struct->glPixelZoomxOESproc(xfactor, yfactor);
}
void APIENTRY glPrioritizeTexturesxOES(GLsizei n, const GLuint* textures, const GLfixed* priorities){
	if(!GLM_struct->glPrioritizeTexturesxOESproc) return;
	GLM_struct->glPrioritizeTexturesxOESproc(n, textures, priorities);
}
void APIENTRY glRasterPos2xOES(GLfixed x, GLfixed y){
	if(!GLM_struct->glRasterPos2xOESproc) return;
	GLM_struct->glRasterPos2xOESproc(x, y);
}
void APIENTRY glRasterPos2xvOES(const GLfixed* coords){
	if(!GLM_struct->glRasterPos2xvOESproc) return;
	GLM_struct->glRasterPos2xvOESproc(coords);
}
void APIENTRY glRasterPos3xOES(GLfixed x, GLfixed y, GLfixed z){
	if(!GLM_struct->glRasterPos3xOESproc) return;
	GLM_struct->glRasterPos3xOESproc(x, y, z);
}
void APIENTRY glRasterPos3xvOES(const GLfixed* coords){
	if(!GLM_struct->glRasterPos3xvOESproc) return;
	GLM_struct->glRasterPos3xvOESproc(coords);
}
void APIENTRY glRasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w){
	if(!GLM_struct->glRasterPos4xOESproc) return;
	GLM_struct->glRasterPos4xOESproc(x, y, z, w);
}
void APIENTRY glRasterPos4xvOES(const GLfixed* coords){
	if(!GLM_struct->glRasterPos4xvOESproc) return;
	GLM_struct->glRasterPos4xvOESproc(coords);
}
void APIENTRY glRectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2){
	if(!GLM_struct->glRectxOESproc) return;
	GLM_struct->glRectxOESproc(x1, y1, x2, y2);
}
void APIENTRY glRectxvOES(const GLfixed* v1, const GLfixed* v2){
	if(!GLM_struct->glRectxvOESproc) return;
	GLM_struct->glRectxvOESproc(v1, v2);
}
void APIENTRY glTexCoord1xOES(GLfixed s){
	if(!GLM_struct->glTexCoord1xOESproc) return;
	GLM_struct->glTexCoord1xOESproc(s);
}
void APIENTRY glTexCoord1xvOES(const GLfixed* coords){
	if(!GLM_struct->glTexCoord1xvOESproc) return;
	GLM_struct->glTexCoord1xvOESproc(coords);
}
void APIENTRY glTexCoord2xOES(GLfixed s, GLfixed t){
	if(!GLM_struct->glTexCoord2xOESproc) return;
	GLM_struct->glTexCoord2xOESproc(s, t);
}
void APIENTRY glTexCoord2xvOES(const GLfixed* coords){
	if(!GLM_struct->glTexCoord2xvOESproc) return;
	GLM_struct->glTexCoord2xvOESproc(coords);
}
void APIENTRY glTexCoord3xOES(GLfixed s, GLfixed t, GLfixed r){
	if(!GLM_struct->glTexCoord3xOESproc) return;
	GLM_struct->glTexCoord3xOESproc(s, t, r);
}
void APIENTRY glTexCoord3xvOES(const GLfixed* coords){
	if(!GLM_struct->glTexCoord3xvOESproc) return;
	GLM_struct->glTexCoord3xvOESproc(coords);
}
void APIENTRY glTexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q){
	if(!GLM_struct->glTexCoord4xOESproc) return;
	GLM_struct->glTexCoord4xOESproc(s, t, r, q);
}
void APIENTRY glTexCoord4xvOES(const GLfixed* coords){
	if(!GLM_struct->glTexCoord4xvOESproc) return;
	GLM_struct->glTexCoord4xvOESproc(coords);
}
void APIENTRY glTexGenxOES(GLenum coord, GLenum pname, GLfixed param){
	if(!GLM_struct->glTexGenxOESproc) return;
	GLM_struct->glTexGenxOESproc(coord, pname, param);
}
void APIENTRY glTexGenxvOES(GLenum coord, GLenum pname, const GLfixed* params){
	if(!GLM_struct->glTexGenxvOESproc) return;
	GLM_struct->glTexGenxvOESproc(coord, pname, params);
}
void APIENTRY glVertex2xOES(GLfixed x){
	if(!GLM_struct->glVertex2xOESproc) return;
	GLM_struct->glVertex2xOESproc(x);
}
void APIENTRY glVertex2xvOES(const GLfixed* coords){
	if(!GLM_struct->glVertex2xvOESproc) return;
	GLM_struct->glVertex2xvOESproc(coords);
}
void APIENTRY glVertex3xOES(GLfixed x, GLfixed y){
	if(!GLM_struct->glVertex3xOESproc) return;
	GLM_struct->glVertex3xOESproc(x, y);
}
void APIENTRY glVertex3xvOES(const GLfixed* coords){
	if(!GLM_struct->glVertex3xvOESproc) return;
	GLM_struct->glVertex3xvOESproc(coords);
}
void APIENTRY glVertex4xOES(GLfixed x, GLfixed y, GLfixed z){
	if(!GLM_struct->glVertex4xOESproc) return;
	GLM_struct->glVertex4xOESproc(x, y, z);
}
void APIENTRY glVertex4xvOES(const GLfixed* coords){
	if(!GLM_struct->glVertex4xvOESproc) return;
	GLM_struct->glVertex4xvOESproc(coords);
}
GLbitfield APIENTRY glQueryMatrixxOES(GLfixed* mantissa, GLint* exponent){
	if(!GLM_struct->glQueryMatrixxOESproc) return 0;
	return GLM_struct->glQueryMatrixxOESproc(mantissa, exponent);
}
void APIENTRY glClearDepthfOES(GLclampf depth){
	if(!GLM_struct->glClearDepthfOESproc) return;
	GLM_struct->glClearDepthfOESproc(depth);
}
void APIENTRY glClipPlanefOES(GLenum plane, const GLfloat* equation){
	if(!GLM_struct->glClipPlanefOESproc) return;
	GLM_struct->glClipPlanefOESproc(plane, equation);
}
void APIENTRY glDepthRangefOES(GLclampf n, GLclampf f){
	if(!GLM_struct->glDepthRangefOESproc) return;
	GLM_struct->glDepthRangefOESproc(n, f);
}
void APIENTRY glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f){
	if(!GLM_struct->glFrustumfOESproc) return;
	GLM_struct->glFrustumfOESproc(l, r, b, t, n, f);
}
void APIENTRY glGetClipPlanefOES(GLenum plane, GLfloat* equation){
	if(!GLM_struct->glGetClipPlanefOESproc) return;
	GLM_struct->glGetClipPlanefOESproc(plane, equation);
}
void APIENTRY glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f){
	if(!GLM_struct->glOrthofOESproc) return;
	GLM_struct->glOrthofOESproc(l, r, b, t, n, f);
}
void APIENTRY glTbufferMask3DFX(GLuint mask){
	if(!GLM_struct->glTbufferMask3DFXproc) return;
	GLM_struct->glTbufferMask3DFXproc(mask);
}
void APIENTRY glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled){
	if(!GLM_struct->glDebugMessageEnableAMDproc) return;
	GLM_struct->glDebugMessageEnableAMDproc(category, severity, count, ids, enabled);
}
void APIENTRY glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar* buf){
	if(!GLM_struct->glDebugMessageInsertAMDproc) return;
	GLM_struct->glDebugMessageInsertAMDproc(category, severity, id, length, buf);
}
void APIENTRY glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, void* userParam){
	if(!GLM_struct->glDebugMessageCallbackAMDproc) return;
	GLM_struct->glDebugMessageCallbackAMDproc(callback, userParam);
}
GLuint APIENTRY glGetDebugMessageLogAMD(GLuint count, GLsizei bufSize, GLenum* categories, GLenum* severities, GLuint* ids, GLsizei* lengths, GLchar* message){
	if(!GLM_struct->glGetDebugMessageLogAMDproc) return 0;
	return GLM_struct->glGetDebugMessageLogAMDproc(count, bufSize, categories, severities, ids, lengths, message);
}
void APIENTRY glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst){
	if(!GLM_struct->glBlendFuncIndexedAMDproc) return;
	GLM_struct->glBlendFuncIndexedAMDproc(buf, src, dst);
}
void APIENTRY glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha){
	if(!GLM_struct->glBlendFuncSeparateIndexedAMDproc) return;
	GLM_struct->glBlendFuncSeparateIndexedAMDproc(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void APIENTRY glBlendEquationIndexedAMD(GLuint buf, GLenum mode){
	if(!GLM_struct->glBlendEquationIndexedAMDproc) return;
	GLM_struct->glBlendEquationIndexedAMDproc(buf, mode);
}
void APIENTRY glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha){
	if(!GLM_struct->glBlendEquationSeparateIndexedAMDproc) return;
	GLM_struct->glBlendEquationSeparateIndexedAMDproc(buf, modeRGB, modeAlpha);
}
void APIENTRY glRenderbufferStorageMultisampleAdvancedAMD(GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glRenderbufferStorageMultisampleAdvancedAMDproc) return;
	GLM_struct->glRenderbufferStorageMultisampleAdvancedAMDproc(target, samples, storageSamples, internalformat, width, height);
}
void APIENTRY glNamedRenderbufferStorageMultisampleAdvancedAMD(GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glNamedRenderbufferStorageMultisampleAdvancedAMDproc) return;
	GLM_struct->glNamedRenderbufferStorageMultisampleAdvancedAMDproc(renderbuffer, samples, storageSamples, internalformat, width, height);
}
void APIENTRY glFramebufferSamplePositionsfvAMD(GLenum target, GLuint numsamples, GLuint pixelindex, const GLfloat* values){
	if(!GLM_struct->glFramebufferSamplePositionsfvAMDproc) return;
	GLM_struct->glFramebufferSamplePositionsfvAMDproc(target, numsamples, pixelindex, values);
}
void APIENTRY glNamedFramebufferSamplePositionsfvAMD(GLuint framebuffer, GLuint numsamples, GLuint pixelindex, const GLfloat* values){
	if(!GLM_struct->glNamedFramebufferSamplePositionsfvAMDproc) return;
	GLM_struct->glNamedFramebufferSamplePositionsfvAMDproc(framebuffer, numsamples, pixelindex, values);
}
void APIENTRY glGetFramebufferParameterfvAMD(GLenum target, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat* values){
	if(!GLM_struct->glGetFramebufferParameterfvAMDproc) return;
	GLM_struct->glGetFramebufferParameterfvAMDproc(target, pname, numsamples, pixelindex, size, values);
}
void APIENTRY glGetNamedFramebufferParameterfvAMD(GLuint framebuffer, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat* values){
	if(!GLM_struct->glGetNamedFramebufferParameterfvAMDproc) return;
	GLM_struct->glGetNamedFramebufferParameterfvAMDproc(framebuffer, pname, numsamples, pixelindex, size, values);
}
void APIENTRY glUniform1i64NV(GLint location, GLint64EXT x){
	if(!GLM_struct->glUniform1i64NVproc) return;
	GLM_struct->glUniform1i64NVproc(location, x);
}
void APIENTRY glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y){
	if(!GLM_struct->glUniform2i64NVproc) return;
	GLM_struct->glUniform2i64NVproc(location, x, y);
}
void APIENTRY glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z){
	if(!GLM_struct->glUniform3i64NVproc) return;
	GLM_struct->glUniform3i64NVproc(location, x, y, z);
}
void APIENTRY glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w){
	if(!GLM_struct->glUniform4i64NVproc) return;
	GLM_struct->glUniform4i64NVproc(location, x, y, z, w);
}
void APIENTRY glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glUniform1i64vNVproc) return;
	GLM_struct->glUniform1i64vNVproc(location, count, value);
}
void APIENTRY glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glUniform2i64vNVproc) return;
	GLM_struct->glUniform2i64vNVproc(location, count, value);
}
void APIENTRY glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glUniform3i64vNVproc) return;
	GLM_struct->glUniform3i64vNVproc(location, count, value);
}
void APIENTRY glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glUniform4i64vNVproc) return;
	GLM_struct->glUniform4i64vNVproc(location, count, value);
}
void APIENTRY glUniform1ui64NV(GLint location, GLuint64EXT x){
	if(!GLM_struct->glUniform1ui64NVproc) return;
	GLM_struct->glUniform1ui64NVproc(location, x);
}
void APIENTRY glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y){
	if(!GLM_struct->glUniform2ui64NVproc) return;
	GLM_struct->glUniform2ui64NVproc(location, x, y);
}
void APIENTRY glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z){
	if(!GLM_struct->glUniform3ui64NVproc) return;
	GLM_struct->glUniform3ui64NVproc(location, x, y, z);
}
void APIENTRY glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w){
	if(!GLM_struct->glUniform4ui64NVproc) return;
	GLM_struct->glUniform4ui64NVproc(location, x, y, z, w);
}
void APIENTRY glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glUniform1ui64vNVproc) return;
	GLM_struct->glUniform1ui64vNVproc(location, count, value);
}
void APIENTRY glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glUniform2ui64vNVproc) return;
	GLM_struct->glUniform2ui64vNVproc(location, count, value);
}
void APIENTRY glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glUniform3ui64vNVproc) return;
	GLM_struct->glUniform3ui64vNVproc(location, count, value);
}
void APIENTRY glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glUniform4ui64vNVproc) return;
	GLM_struct->glUniform4ui64vNVproc(location, count, value);
}
void APIENTRY glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT* params){
	if(!GLM_struct->glGetUniformi64vNVproc) return;
	GLM_struct->glGetUniformi64vNVproc(program, location, params);
}
void APIENTRY glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT* params){
	if(!GLM_struct->glGetUniformui64vNVproc) return;
	GLM_struct->glGetUniformui64vNVproc(program, location, params);
}
void APIENTRY glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x){
	if(!GLM_struct->glProgramUniform1i64NVproc) return;
	GLM_struct->glProgramUniform1i64NVproc(program, location, x);
}
void APIENTRY glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y){
	if(!GLM_struct->glProgramUniform2i64NVproc) return;
	GLM_struct->glProgramUniform2i64NVproc(program, location, x, y);
}
void APIENTRY glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z){
	if(!GLM_struct->glProgramUniform3i64NVproc) return;
	GLM_struct->glProgramUniform3i64NVproc(program, location, x, y, z);
}
void APIENTRY glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w){
	if(!GLM_struct->glProgramUniform4i64NVproc) return;
	GLM_struct->glProgramUniform4i64NVproc(program, location, x, y, z, w);
}
void APIENTRY glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glProgramUniform1i64vNVproc) return;
	GLM_struct->glProgramUniform1i64vNVproc(program, location, count, value);
}
void APIENTRY glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glProgramUniform2i64vNVproc) return;
	GLM_struct->glProgramUniform2i64vNVproc(program, location, count, value);
}
void APIENTRY glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glProgramUniform3i64vNVproc) return;
	GLM_struct->glProgramUniform3i64vNVproc(program, location, count, value);
}
void APIENTRY glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value){
	if(!GLM_struct->glProgramUniform4i64vNVproc) return;
	GLM_struct->glProgramUniform4i64vNVproc(program, location, count, value);
}
void APIENTRY glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x){
	if(!GLM_struct->glProgramUniform1ui64NVproc) return;
	GLM_struct->glProgramUniform1ui64NVproc(program, location, x);
}
void APIENTRY glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y){
	if(!GLM_struct->glProgramUniform2ui64NVproc) return;
	GLM_struct->glProgramUniform2ui64NVproc(program, location, x, y);
}
void APIENTRY glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z){
	if(!GLM_struct->glProgramUniform3ui64NVproc) return;
	GLM_struct->glProgramUniform3ui64NVproc(program, location, x, y, z);
}
void APIENTRY glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w){
	if(!GLM_struct->glProgramUniform4ui64NVproc) return;
	GLM_struct->glProgramUniform4ui64NVproc(program, location, x, y, z, w);
}
void APIENTRY glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glProgramUniform1ui64vNVproc) return;
	GLM_struct->glProgramUniform1ui64vNVproc(program, location, count, value);
}
void APIENTRY glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glProgramUniform2ui64vNVproc) return;
	GLM_struct->glProgramUniform2ui64vNVproc(program, location, count, value);
}
void APIENTRY glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glProgramUniform3ui64vNVproc) return;
	GLM_struct->glProgramUniform3ui64vNVproc(program, location, count, value);
}
void APIENTRY glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glProgramUniform4ui64vNVproc) return;
	GLM_struct->glProgramUniform4ui64vNVproc(program, location, count, value);
}
void APIENTRY glVertexAttribParameteriAMD(GLuint index, GLenum pname, GLint param){
	if(!GLM_struct->glVertexAttribParameteriAMDproc) return;
	GLM_struct->glVertexAttribParameteriAMDproc(index, pname, param);
}
void APIENTRY glMultiDrawArraysIndirectAMD(GLenum mode, const void* indirect, GLsizei primcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawArraysIndirectAMDproc) return;
	GLM_struct->glMultiDrawArraysIndirectAMDproc(mode, indirect, primcount, stride);
}
void APIENTRY glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, const void* indirect, GLsizei primcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawElementsIndirectAMDproc) return;
	GLM_struct->glMultiDrawElementsIndirectAMDproc(mode, type, indirect, primcount, stride);
}
void APIENTRY glGenNamesAMD(GLenum identifier, GLuint num, GLuint* names){
	if(!GLM_struct->glGenNamesAMDproc) return;
	GLM_struct->glGenNamesAMDproc(identifier, num, names);
}
void APIENTRY glDeleteNamesAMD(GLenum identifier, GLuint num, const GLuint* names){
	if(!GLM_struct->glDeleteNamesAMDproc) return;
	GLM_struct->glDeleteNamesAMDproc(identifier, num, names);
}
GLboolean APIENTRY glIsNameAMD(GLenum identifier, GLuint name){
	if(!GLM_struct->glIsNameAMDproc) return 0;
	return GLM_struct->glIsNameAMDproc(identifier, name);
}
void APIENTRY glQueryObjectParameteruiAMD(GLenum target, GLuint id, GLenum pname, GLuint param){
	if(!GLM_struct->glQueryObjectParameteruiAMDproc) return;
	GLM_struct->glQueryObjectParameteruiAMDproc(target, id, pname, param);
}
void APIENTRY glGetPerfMonitorGroupsAMD(GLint* numGroups, GLsizei groupsSize, GLuint* groups){
	if(!GLM_struct->glGetPerfMonitorGroupsAMDproc) return;
	GLM_struct->glGetPerfMonitorGroupsAMDproc(numGroups, groupsSize, groups);
}
void APIENTRY glGetPerfMonitorCountersAMD(GLuint group, GLint* numCounters, GLint* maxActiveCounters, GLsizei counterSize, GLuint* counters){
	if(!GLM_struct->glGetPerfMonitorCountersAMDproc) return;
	GLM_struct->glGetPerfMonitorCountersAMDproc(group, numCounters, maxActiveCounters, counterSize, counters);
}
void APIENTRY glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei* length, GLchar* groupString){
	if(!GLM_struct->glGetPerfMonitorGroupStringAMDproc) return;
	GLM_struct->glGetPerfMonitorGroupStringAMDproc(group, bufSize, length, groupString);
}
void APIENTRY glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei* length, GLchar* counterString){
	if(!GLM_struct->glGetPerfMonitorCounterStringAMDproc) return;
	GLM_struct->glGetPerfMonitorCounterStringAMDproc(group, counter, bufSize, length, counterString);
}
void APIENTRY glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, void* data){
	if(!GLM_struct->glGetPerfMonitorCounterInfoAMDproc) return;
	GLM_struct->glGetPerfMonitorCounterInfoAMDproc(group, counter, pname, data);
}
void APIENTRY glGenPerfMonitorsAMD(GLsizei n, GLuint* monitors){
	if(!GLM_struct->glGenPerfMonitorsAMDproc) return;
	GLM_struct->glGenPerfMonitorsAMDproc(n, monitors);
}
void APIENTRY glDeletePerfMonitorsAMD(GLsizei n, GLuint* monitors){
	if(!GLM_struct->glDeletePerfMonitorsAMDproc) return;
	GLM_struct->glDeletePerfMonitorsAMDproc(n, monitors);
}
void APIENTRY glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint* counterList){
	if(!GLM_struct->glSelectPerfMonitorCountersAMDproc) return;
	GLM_struct->glSelectPerfMonitorCountersAMDproc(monitor, enable, group, numCounters, counterList);
}
void APIENTRY glBeginPerfMonitorAMD(GLuint monitor){
	if(!GLM_struct->glBeginPerfMonitorAMDproc) return;
	GLM_struct->glBeginPerfMonitorAMDproc(monitor);
}
void APIENTRY glEndPerfMonitorAMD(GLuint monitor){
	if(!GLM_struct->glEndPerfMonitorAMDproc) return;
	GLM_struct->glEndPerfMonitorAMDproc(monitor);
}
void APIENTRY glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint* data, GLint* bytesWritten){
	if(!GLM_struct->glGetPerfMonitorCounterDataAMDproc) return;
	GLM_struct->glGetPerfMonitorCounterDataAMDproc(monitor, pname, dataSize, data, bytesWritten);
}
void APIENTRY glSetMultisamplefvAMD(GLenum pname, GLuint index, const GLfloat* val){
	if(!GLM_struct->glSetMultisamplefvAMDproc) return;
	GLM_struct->glSetMultisamplefvAMDproc(pname, index, val);
}
void APIENTRY glTexStorageSparseAMD(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags){
	if(!GLM_struct->glTexStorageSparseAMDproc) return;
	GLM_struct->glTexStorageSparseAMDproc(target, internalFormat, width, height, depth, layers, flags);
}
void APIENTRY glTextureStorageSparseAMD(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags){
	if(!GLM_struct->glTextureStorageSparseAMDproc) return;
	GLM_struct->glTextureStorageSparseAMDproc(texture, target, internalFormat, width, height, depth, layers, flags);
}
void APIENTRY glStencilOpValueAMD(GLenum face, GLuint value){
	if(!GLM_struct->glStencilOpValueAMDproc) return;
	GLM_struct->glStencilOpValueAMDproc(face, value);
}
void APIENTRY glTessellationFactorAMD(GLfloat factor){
	if(!GLM_struct->glTessellationFactorAMDproc) return;
	GLM_struct->glTessellationFactorAMDproc(factor);
}
void APIENTRY glTessellationModeAMD(GLenum mode){
	if(!GLM_struct->glTessellationModeAMDproc) return;
	GLM_struct->glTessellationModeAMDproc(mode);
}
void APIENTRY glElementPointerAPPLE(GLenum type, const void* pointer){
	if(!GLM_struct->glElementPointerAPPLEproc) return;
	GLM_struct->glElementPointerAPPLEproc(type, pointer);
}
void APIENTRY glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count){
	if(!GLM_struct->glDrawElementArrayAPPLEproc) return;
	GLM_struct->glDrawElementArrayAPPLEproc(mode, first, count);
}
void APIENTRY glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count){
	if(!GLM_struct->glDrawRangeElementArrayAPPLEproc) return;
	GLM_struct->glDrawRangeElementArrayAPPLEproc(mode, start, end, first, count);
}
void APIENTRY glMultiDrawElementArrayAPPLE(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount){
	if(!GLM_struct->glMultiDrawElementArrayAPPLEproc) return;
	GLM_struct->glMultiDrawElementArrayAPPLEproc(mode, first, count, primcount);
}
void APIENTRY glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint* first, const GLsizei* count, GLsizei primcount){
	if(!GLM_struct->glMultiDrawRangeElementArrayAPPLEproc) return;
	GLM_struct->glMultiDrawRangeElementArrayAPPLEproc(mode, start, end, first, count, primcount);
}
void APIENTRY glGenFencesAPPLE(GLsizei n, GLuint* fences){
	if(!GLM_struct->glGenFencesAPPLEproc) return;
	GLM_struct->glGenFencesAPPLEproc(n, fences);
}
void APIENTRY glDeleteFencesAPPLE(GLsizei n, const GLuint* fences){
	if(!GLM_struct->glDeleteFencesAPPLEproc) return;
	GLM_struct->glDeleteFencesAPPLEproc(n, fences);
}
void APIENTRY glSetFenceAPPLE(GLuint fence){
	if(!GLM_struct->glSetFenceAPPLEproc) return;
	GLM_struct->glSetFenceAPPLEproc(fence);
}
GLboolean APIENTRY glIsFenceAPPLE(GLuint fence){
	if(!GLM_struct->glIsFenceAPPLEproc) return 0;
	return GLM_struct->glIsFenceAPPLEproc(fence);
}
GLboolean APIENTRY glTestFenceAPPLE(GLuint fence){
	if(!GLM_struct->glTestFenceAPPLEproc) return 0;
	return GLM_struct->glTestFenceAPPLEproc(fence);
}
void APIENTRY glFinishFenceAPPLE(GLuint fence){
	if(!GLM_struct->glFinishFenceAPPLEproc) return;
	GLM_struct->glFinishFenceAPPLEproc(fence);
}
GLboolean APIENTRY glTestObjectAPPLE(GLenum object, GLuint name){
	if(!GLM_struct->glTestObjectAPPLEproc) return 0;
	return GLM_struct->glTestObjectAPPLEproc(object, name);
}
void APIENTRY glFinishObjectAPPLE(GLenum object, GLint name){
	if(!GLM_struct->glFinishObjectAPPLEproc) return;
	GLM_struct->glFinishObjectAPPLEproc(object, name);
}
void APIENTRY glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glBufferParameteriAPPLEproc) return;
	GLM_struct->glBufferParameteriAPPLEproc(target, pname, param);
}
void APIENTRY glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glFlushMappedBufferRangeAPPLEproc) return;
	GLM_struct->glFlushMappedBufferRangeAPPLEproc(target, offset, size);
}
GLenum APIENTRY glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option){
	if(!GLM_struct->glObjectPurgeableAPPLEproc) return 0;
	return GLM_struct->glObjectPurgeableAPPLEproc(objectType, name, option);
}
GLenum APIENTRY glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option){
	if(!GLM_struct->glObjectUnpurgeableAPPLEproc) return 0;
	return GLM_struct->glObjectUnpurgeableAPPLEproc(objectType, name, option);
}
void APIENTRY glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint* params){
	if(!GLM_struct->glGetObjectParameterivAPPLEproc) return;
	GLM_struct->glGetObjectParameterivAPPLEproc(objectType, name, pname, params);
}
void APIENTRY glTextureRangeAPPLE(GLenum target, GLsizei length, const void* pointer){
	if(!GLM_struct->glTextureRangeAPPLEproc) return;
	GLM_struct->glTextureRangeAPPLEproc(target, length, pointer);
}
void APIENTRY glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, void** params){
	if(!GLM_struct->glGetTexParameterPointervAPPLEproc) return;
	GLM_struct->glGetTexParameterPointervAPPLEproc(target, pname, params);
}
void APIENTRY glBindVertexArrayAPPLE(GLuint array){
	if(!GLM_struct->glBindVertexArrayAPPLEproc) return;
	GLM_struct->glBindVertexArrayAPPLEproc(array);
}
void APIENTRY glDeleteVertexArraysAPPLE(GLsizei n, const GLuint* arrays){
	if(!GLM_struct->glDeleteVertexArraysAPPLEproc) return;
	GLM_struct->glDeleteVertexArraysAPPLEproc(n, arrays);
}
void APIENTRY glGenVertexArraysAPPLE(GLsizei n, GLuint* arrays){
	if(!GLM_struct->glGenVertexArraysAPPLEproc) return;
	GLM_struct->glGenVertexArraysAPPLEproc(n, arrays);
}
GLboolean APIENTRY glIsVertexArrayAPPLE(GLuint array){
	if(!GLM_struct->glIsVertexArrayAPPLEproc) return 0;
	return GLM_struct->glIsVertexArrayAPPLEproc(array);
}
void APIENTRY glVertexArrayRangeAPPLE(GLsizei length, void* pointer){
	if(!GLM_struct->glVertexArrayRangeAPPLEproc) return;
	GLM_struct->glVertexArrayRangeAPPLEproc(length, pointer);
}
void APIENTRY glFlushVertexArrayRangeAPPLE(GLsizei length, void* pointer){
	if(!GLM_struct->glFlushVertexArrayRangeAPPLEproc) return;
	GLM_struct->glFlushVertexArrayRangeAPPLEproc(length, pointer);
}
void APIENTRY glVertexArrayParameteriAPPLE(GLenum pname, GLint param){
	if(!GLM_struct->glVertexArrayParameteriAPPLEproc) return;
	GLM_struct->glVertexArrayParameteriAPPLEproc(pname, param);
}
void APIENTRY glEnableVertexAttribAPPLE(GLuint index, GLenum pname){
	if(!GLM_struct->glEnableVertexAttribAPPLEproc) return;
	GLM_struct->glEnableVertexAttribAPPLEproc(index, pname);
}
void APIENTRY glDisableVertexAttribAPPLE(GLuint index, GLenum pname){
	if(!GLM_struct->glDisableVertexAttribAPPLEproc) return;
	GLM_struct->glDisableVertexAttribAPPLEproc(index, pname);
}
GLboolean APIENTRY glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname){
	if(!GLM_struct->glIsVertexAttribEnabledAPPLEproc) return 0;
	return GLM_struct->glIsVertexAttribEnabledAPPLEproc(index, pname);
}
void APIENTRY glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points){
	if(!GLM_struct->glMapVertexAttrib1dAPPLEproc) return;
	GLM_struct->glMapVertexAttrib1dAPPLEproc(index, size, u1, u2, stride, order, points);
}
void APIENTRY glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points){
	if(!GLM_struct->glMapVertexAttrib1fAPPLEproc) return;
	GLM_struct->glMapVertexAttrib1fAPPLEproc(index, size, u1, u2, stride, order, points);
}
void APIENTRY glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points){
	if(!GLM_struct->glMapVertexAttrib2dAPPLEproc) return;
	GLM_struct->glMapVertexAttrib2dAPPLEproc(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
void APIENTRY glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points){
	if(!GLM_struct->glMapVertexAttrib2fAPPLEproc) return;
	GLM_struct->glMapVertexAttrib2fAPPLEproc(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
void APIENTRY glDrawBuffersATI(GLsizei n, const GLenum* bufs){
	if(!GLM_struct->glDrawBuffersATIproc) return;
	GLM_struct->glDrawBuffersATIproc(n, bufs);
}
void APIENTRY glElementPointerATI(GLenum type, const void* pointer){
	if(!GLM_struct->glElementPointerATIproc) return;
	GLM_struct->glElementPointerATIproc(type, pointer);
}
void APIENTRY glDrawElementArrayATI(GLenum mode, GLsizei count){
	if(!GLM_struct->glDrawElementArrayATIproc) return;
	GLM_struct->glDrawElementArrayATIproc(mode, count);
}
void APIENTRY glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count){
	if(!GLM_struct->glDrawRangeElementArrayATIproc) return;
	GLM_struct->glDrawRangeElementArrayATIproc(mode, start, end, count);
}
void APIENTRY glTexBumpParameterivATI(GLenum pname, const GLint* param){
	if(!GLM_struct->glTexBumpParameterivATIproc) return;
	GLM_struct->glTexBumpParameterivATIproc(pname, param);
}
void APIENTRY glTexBumpParameterfvATI(GLenum pname, const GLfloat* param){
	if(!GLM_struct->glTexBumpParameterfvATIproc) return;
	GLM_struct->glTexBumpParameterfvATIproc(pname, param);
}
void APIENTRY glGetTexBumpParameterivATI(GLenum pname, GLint* param){
	if(!GLM_struct->glGetTexBumpParameterivATIproc) return;
	GLM_struct->glGetTexBumpParameterivATIproc(pname, param);
}
void APIENTRY glGetTexBumpParameterfvATI(GLenum pname, GLfloat* param){
	if(!GLM_struct->glGetTexBumpParameterfvATIproc) return;
	GLM_struct->glGetTexBumpParameterfvATIproc(pname, param);
}
GLuint APIENTRY glGenFragmentShadersATI(GLuint range){
	if(!GLM_struct->glGenFragmentShadersATIproc) return 0;
	return GLM_struct->glGenFragmentShadersATIproc(range);
}
void APIENTRY glBindFragmentShaderATI(GLuint id){
	if(!GLM_struct->glBindFragmentShaderATIproc) return;
	GLM_struct->glBindFragmentShaderATIproc(id);
}
void APIENTRY glDeleteFragmentShaderATI(GLuint id){
	if(!GLM_struct->glDeleteFragmentShaderATIproc) return;
	GLM_struct->glDeleteFragmentShaderATIproc(id);
}
void APIENTRY glBeginFragmentShaderATI(void){
	if(!GLM_struct->glBeginFragmentShaderATIproc) return;
	GLM_struct->glBeginFragmentShaderATIproc();
}
void APIENTRY glEndFragmentShaderATI(void){
	if(!GLM_struct->glEndFragmentShaderATIproc) return;
	GLM_struct->glEndFragmentShaderATIproc();
}
void APIENTRY glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle){
	if(!GLM_struct->glPassTexCoordATIproc) return;
	GLM_struct->glPassTexCoordATIproc(dst, coord, swizzle);
}
void APIENTRY glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle){
	if(!GLM_struct->glSampleMapATIproc) return;
	GLM_struct->glSampleMapATIproc(dst, interp, swizzle);
}
void APIENTRY glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod){
	if(!GLM_struct->glColorFragmentOp1ATIproc) return;
	GLM_struct->glColorFragmentOp1ATIproc(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod);
}
void APIENTRY glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod){
	if(!GLM_struct->glColorFragmentOp2ATIproc) return;
	GLM_struct->glColorFragmentOp2ATIproc(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);
}
void APIENTRY glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod){
	if(!GLM_struct->glColorFragmentOp3ATIproc) return;
	GLM_struct->glColorFragmentOp3ATIproc(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);
}
void APIENTRY glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod){
	if(!GLM_struct->glAlphaFragmentOp1ATIproc) return;
	GLM_struct->glAlphaFragmentOp1ATIproc(op, dst, dstMod, arg1, arg1Rep, arg1Mod);
}
void APIENTRY glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod){
	if(!GLM_struct->glAlphaFragmentOp2ATIproc) return;
	GLM_struct->glAlphaFragmentOp2ATIproc(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);
}
void APIENTRY glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod){
	if(!GLM_struct->glAlphaFragmentOp3ATIproc) return;
	GLM_struct->glAlphaFragmentOp3ATIproc(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);
}
void APIENTRY glSetFragmentShaderConstantATI(GLuint dst, const GLfloat* value){
	if(!GLM_struct->glSetFragmentShaderConstantATIproc) return;
	GLM_struct->glSetFragmentShaderConstantATIproc(dst, value);
}
void* APIENTRY glMapObjectBufferATI(GLuint buffer){
	if(!GLM_struct->glMapObjectBufferATIproc) return 0;
	return GLM_struct->glMapObjectBufferATIproc(buffer);
}
void APIENTRY glUnmapObjectBufferATI(GLuint buffer){
	if(!GLM_struct->glUnmapObjectBufferATIproc) return;
	GLM_struct->glUnmapObjectBufferATIproc(buffer);
}
void APIENTRY glPNTrianglesiATI(GLenum pname, GLint param){
	if(!GLM_struct->glPNTrianglesiATIproc) return;
	GLM_struct->glPNTrianglesiATIproc(pname, param);
}
void APIENTRY glPNTrianglesfATI(GLenum pname, GLfloat param){
	if(!GLM_struct->glPNTrianglesfATIproc) return;
	GLM_struct->glPNTrianglesfATIproc(pname, param);
}
void APIENTRY glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass){
	if(!GLM_struct->glStencilOpSeparateATIproc) return;
	GLM_struct->glStencilOpSeparateATIproc(face, sfail, dpfail, dppass);
}
void APIENTRY glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask){
	if(!GLM_struct->glStencilFuncSeparateATIproc) return;
	GLM_struct->glStencilFuncSeparateATIproc(frontfunc, backfunc, ref, mask);
}
GLuint APIENTRY glNewObjectBufferATI(GLsizei size, const void* pointer, GLenum usage){
	if(!GLM_struct->glNewObjectBufferATIproc) return 0;
	return GLM_struct->glNewObjectBufferATIproc(size, pointer, usage);
}
GLboolean APIENTRY glIsObjectBufferATI(GLuint buffer){
	if(!GLM_struct->glIsObjectBufferATIproc) return 0;
	return GLM_struct->glIsObjectBufferATIproc(buffer);
}
void APIENTRY glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, const void* pointer, GLenum preserve){
	if(!GLM_struct->glUpdateObjectBufferATIproc) return;
	GLM_struct->glUpdateObjectBufferATIproc(buffer, offset, size, pointer, preserve);
}
void APIENTRY glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetObjectBufferfvATIproc) return;
	GLM_struct->glGetObjectBufferfvATIproc(buffer, pname, params);
}
void APIENTRY glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint* params){
	if(!GLM_struct->glGetObjectBufferivATIproc) return;
	GLM_struct->glGetObjectBufferivATIproc(buffer, pname, params);
}
void APIENTRY glFreeObjectBufferATI(GLuint buffer){
	if(!GLM_struct->glFreeObjectBufferATIproc) return;
	GLM_struct->glFreeObjectBufferATIproc(buffer);
}
void APIENTRY glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset){
	if(!GLM_struct->glArrayObjectATIproc) return;
	GLM_struct->glArrayObjectATIproc(array, size, type, stride, buffer, offset);
}
void APIENTRY glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetArrayObjectfvATIproc) return;
	GLM_struct->glGetArrayObjectfvATIproc(array, pname, params);
}
void APIENTRY glGetArrayObjectivATI(GLenum array, GLenum pname, GLint* params){
	if(!GLM_struct->glGetArrayObjectivATIproc) return;
	GLM_struct->glGetArrayObjectivATIproc(array, pname, params);
}
void APIENTRY glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset){
	if(!GLM_struct->glVariantArrayObjectATIproc) return;
	GLM_struct->glVariantArrayObjectATIproc(id, type, stride, buffer, offset);
}
void APIENTRY glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetVariantArrayObjectfvATIproc) return;
	GLM_struct->glGetVariantArrayObjectfvATIproc(id, pname, params);
}
void APIENTRY glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVariantArrayObjectivATIproc) return;
	GLM_struct->glGetVariantArrayObjectivATIproc(id, pname, params);
}
void APIENTRY glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset){
	if(!GLM_struct->glVertexAttribArrayObjectATIproc) return;
	GLM_struct->glVertexAttribArrayObjectATIproc(index, size, type, normalized, stride, buffer, offset);
}
void APIENTRY glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetVertexAttribArrayObjectfvATIproc) return;
	GLM_struct->glGetVertexAttribArrayObjectfvATIproc(index, pname, params);
}
void APIENTRY glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVertexAttribArrayObjectivATIproc) return;
	GLM_struct->glGetVertexAttribArrayObjectivATIproc(index, pname, params);
}
void APIENTRY glVertexStream1sATI(GLenum stream, GLshort x){
	if(!GLM_struct->glVertexStream1sATIproc) return;
	GLM_struct->glVertexStream1sATIproc(stream, x);
}
void APIENTRY glVertexStream1svATI(GLenum stream, const GLshort* coords){
	if(!GLM_struct->glVertexStream1svATIproc) return;
	GLM_struct->glVertexStream1svATIproc(stream, coords);
}
void APIENTRY glVertexStream1iATI(GLenum stream, GLint x){
	if(!GLM_struct->glVertexStream1iATIproc) return;
	GLM_struct->glVertexStream1iATIproc(stream, x);
}
void APIENTRY glVertexStream1ivATI(GLenum stream, const GLint* coords){
	if(!GLM_struct->glVertexStream1ivATIproc) return;
	GLM_struct->glVertexStream1ivATIproc(stream, coords);
}
void APIENTRY glVertexStream1fATI(GLenum stream, GLfloat x){
	if(!GLM_struct->glVertexStream1fATIproc) return;
	GLM_struct->glVertexStream1fATIproc(stream, x);
}
void APIENTRY glVertexStream1fvATI(GLenum stream, const GLfloat* coords){
	if(!GLM_struct->glVertexStream1fvATIproc) return;
	GLM_struct->glVertexStream1fvATIproc(stream, coords);
}
void APIENTRY glVertexStream1dATI(GLenum stream, GLdouble x){
	if(!GLM_struct->glVertexStream1dATIproc) return;
	GLM_struct->glVertexStream1dATIproc(stream, x);
}
void APIENTRY glVertexStream1dvATI(GLenum stream, const GLdouble* coords){
	if(!GLM_struct->glVertexStream1dvATIproc) return;
	GLM_struct->glVertexStream1dvATIproc(stream, coords);
}
void APIENTRY glVertexStream2sATI(GLenum stream, GLshort x, GLshort y){
	if(!GLM_struct->glVertexStream2sATIproc) return;
	GLM_struct->glVertexStream2sATIproc(stream, x, y);
}
void APIENTRY glVertexStream2svATI(GLenum stream, const GLshort* coords){
	if(!GLM_struct->glVertexStream2svATIproc) return;
	GLM_struct->glVertexStream2svATIproc(stream, coords);
}
void APIENTRY glVertexStream2iATI(GLenum stream, GLint x, GLint y){
	if(!GLM_struct->glVertexStream2iATIproc) return;
	GLM_struct->glVertexStream2iATIproc(stream, x, y);
}
void APIENTRY glVertexStream2ivATI(GLenum stream, const GLint* coords){
	if(!GLM_struct->glVertexStream2ivATIproc) return;
	GLM_struct->glVertexStream2ivATIproc(stream, coords);
}
void APIENTRY glVertexStream2fATI(GLenum stream, GLfloat x, GLfloat y){
	if(!GLM_struct->glVertexStream2fATIproc) return;
	GLM_struct->glVertexStream2fATIproc(stream, x, y);
}
void APIENTRY glVertexStream2fvATI(GLenum stream, const GLfloat* coords){
	if(!GLM_struct->glVertexStream2fvATIproc) return;
	GLM_struct->glVertexStream2fvATIproc(stream, coords);
}
void APIENTRY glVertexStream2dATI(GLenum stream, GLdouble x, GLdouble y){
	if(!GLM_struct->glVertexStream2dATIproc) return;
	GLM_struct->glVertexStream2dATIproc(stream, x, y);
}
void APIENTRY glVertexStream2dvATI(GLenum stream, const GLdouble* coords){
	if(!GLM_struct->glVertexStream2dvATIproc) return;
	GLM_struct->glVertexStream2dvATIproc(stream, coords);
}
void APIENTRY glVertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z){
	if(!GLM_struct->glVertexStream3sATIproc) return;
	GLM_struct->glVertexStream3sATIproc(stream, x, y, z);
}
void APIENTRY glVertexStream3svATI(GLenum stream, const GLshort* coords){
	if(!GLM_struct->glVertexStream3svATIproc) return;
	GLM_struct->glVertexStream3svATIproc(stream, coords);
}
void APIENTRY glVertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z){
	if(!GLM_struct->glVertexStream3iATIproc) return;
	GLM_struct->glVertexStream3iATIproc(stream, x, y, z);
}
void APIENTRY glVertexStream3ivATI(GLenum stream, const GLint* coords){
	if(!GLM_struct->glVertexStream3ivATIproc) return;
	GLM_struct->glVertexStream3ivATIproc(stream, coords);
}
void APIENTRY glVertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glVertexStream3fATIproc) return;
	GLM_struct->glVertexStream3fATIproc(stream, x, y, z);
}
void APIENTRY glVertexStream3fvATI(GLenum stream, const GLfloat* coords){
	if(!GLM_struct->glVertexStream3fvATIproc) return;
	GLM_struct->glVertexStream3fvATIproc(stream, coords);
}
void APIENTRY glVertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glVertexStream3dATIproc) return;
	GLM_struct->glVertexStream3dATIproc(stream, x, y, z);
}
void APIENTRY glVertexStream3dvATI(GLenum stream, const GLdouble* coords){
	if(!GLM_struct->glVertexStream3dvATIproc) return;
	GLM_struct->glVertexStream3dvATIproc(stream, coords);
}
void APIENTRY glVertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w){
	if(!GLM_struct->glVertexStream4sATIproc) return;
	GLM_struct->glVertexStream4sATIproc(stream, x, y, z, w);
}
void APIENTRY glVertexStream4svATI(GLenum stream, const GLshort* coords){
	if(!GLM_struct->glVertexStream4svATIproc) return;
	GLM_struct->glVertexStream4svATIproc(stream, coords);
}
void APIENTRY glVertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w){
	if(!GLM_struct->glVertexStream4iATIproc) return;
	GLM_struct->glVertexStream4iATIproc(stream, x, y, z, w);
}
void APIENTRY glVertexStream4ivATI(GLenum stream, const GLint* coords){
	if(!GLM_struct->glVertexStream4ivATIproc) return;
	GLM_struct->glVertexStream4ivATIproc(stream, coords);
}
void APIENTRY glVertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glVertexStream4fATIproc) return;
	GLM_struct->glVertexStream4fATIproc(stream, x, y, z, w);
}
void APIENTRY glVertexStream4fvATI(GLenum stream, const GLfloat* coords){
	if(!GLM_struct->glVertexStream4fvATIproc) return;
	GLM_struct->glVertexStream4fvATIproc(stream, coords);
}
void APIENTRY glVertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glVertexStream4dATIproc) return;
	GLM_struct->glVertexStream4dATIproc(stream, x, y, z, w);
}
void APIENTRY glVertexStream4dvATI(GLenum stream, const GLdouble* coords){
	if(!GLM_struct->glVertexStream4dvATIproc) return;
	GLM_struct->glVertexStream4dvATIproc(stream, coords);
}
void APIENTRY glNormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz){
	if(!GLM_struct->glNormalStream3bATIproc) return;
	GLM_struct->glNormalStream3bATIproc(stream, nx, ny, nz);
}
void APIENTRY glNormalStream3bvATI(GLenum stream, const GLbyte* coords){
	if(!GLM_struct->glNormalStream3bvATIproc) return;
	GLM_struct->glNormalStream3bvATIproc(stream, coords);
}
void APIENTRY glNormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz){
	if(!GLM_struct->glNormalStream3sATIproc) return;
	GLM_struct->glNormalStream3sATIproc(stream, nx, ny, nz);
}
void APIENTRY glNormalStream3svATI(GLenum stream, const GLshort* coords){
	if(!GLM_struct->glNormalStream3svATIproc) return;
	GLM_struct->glNormalStream3svATIproc(stream, coords);
}
void APIENTRY glNormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz){
	if(!GLM_struct->glNormalStream3iATIproc) return;
	GLM_struct->glNormalStream3iATIproc(stream, nx, ny, nz);
}
void APIENTRY glNormalStream3ivATI(GLenum stream, const GLint* coords){
	if(!GLM_struct->glNormalStream3ivATIproc) return;
	GLM_struct->glNormalStream3ivATIproc(stream, coords);
}
void APIENTRY glNormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz){
	if(!GLM_struct->glNormalStream3fATIproc) return;
	GLM_struct->glNormalStream3fATIproc(stream, nx, ny, nz);
}
void APIENTRY glNormalStream3fvATI(GLenum stream, const GLfloat* coords){
	if(!GLM_struct->glNormalStream3fvATIproc) return;
	GLM_struct->glNormalStream3fvATIproc(stream, coords);
}
void APIENTRY glNormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz){
	if(!GLM_struct->glNormalStream3dATIproc) return;
	GLM_struct->glNormalStream3dATIproc(stream, nx, ny, nz);
}
void APIENTRY glNormalStream3dvATI(GLenum stream, const GLdouble* coords){
	if(!GLM_struct->glNormalStream3dvATIproc) return;
	GLM_struct->glNormalStream3dvATIproc(stream, coords);
}
void APIENTRY glClientActiveVertexStreamATI(GLenum stream){
	if(!GLM_struct->glClientActiveVertexStreamATIproc) return;
	GLM_struct->glClientActiveVertexStreamATIproc(stream);
}
void APIENTRY glVertexBlendEnviATI(GLenum pname, GLint param){
	if(!GLM_struct->glVertexBlendEnviATIproc) return;
	GLM_struct->glVertexBlendEnviATIproc(pname, param);
}
void APIENTRY glVertexBlendEnvfATI(GLenum pname, GLfloat param){
	if(!GLM_struct->glVertexBlendEnvfATIproc) return;
	GLM_struct->glVertexBlendEnvfATIproc(pname, param);
}
void APIENTRY glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, const GLint* attrib_list){
	if(!GLM_struct->glEGLImageTargetTexStorageEXTproc) return;
	GLM_struct->glEGLImageTargetTexStorageEXTproc(target, image, attrib_list);
}
void APIENTRY glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, const GLint* attrib_list){
	if(!GLM_struct->glEGLImageTargetTextureStorageEXTproc) return;
	GLM_struct->glEGLImageTargetTextureStorageEXTproc(texture, image, attrib_list);
}
void APIENTRY glUniformBufferEXT(GLuint program, GLint location, GLuint buffer){
	if(!GLM_struct->glUniformBufferEXTproc) return;
	GLM_struct->glUniformBufferEXTproc(program, location, buffer);
}
GLint APIENTRY glGetUniformBufferSizeEXT(GLuint program, GLint location){
	if(!GLM_struct->glGetUniformBufferSizeEXTproc) return 0;
	return GLM_struct->glGetUniformBufferSizeEXTproc(program, location);
}
GLintptr APIENTRY glGetUniformOffsetEXT(GLuint program, GLint location){
	if(!GLM_struct->glGetUniformOffsetEXTproc) return 0;
	return GLM_struct->glGetUniformOffsetEXTproc(program, location);
}
void APIENTRY glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){
	if(!GLM_struct->glBlendColorEXTproc) return;
	GLM_struct->glBlendColorEXTproc(red, green, blue, alpha);
}
void APIENTRY glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha){
	if(!GLM_struct->glBlendEquationSeparateEXTproc) return;
	GLM_struct->glBlendEquationSeparateEXTproc(modeRGB, modeAlpha);
}
void APIENTRY glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha){
	if(!GLM_struct->glBlendFuncSeparateEXTproc) return;
	GLM_struct->glBlendFuncSeparateEXTproc(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void APIENTRY glBlendEquationEXT(GLenum mode){
	if(!GLM_struct->glBlendEquationEXTproc) return;
	GLM_struct->glBlendEquationEXTproc(mode);
}
void APIENTRY glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glColorSubTableEXTproc) return;
	GLM_struct->glColorSubTableEXTproc(target, start, count, format, type, data);
}
void APIENTRY glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyColorSubTableEXTproc) return;
	GLM_struct->glCopyColorSubTableEXTproc(target, start, x, y, width);
}
void APIENTRY glLockArraysEXT(GLint first, GLsizei count){
	if(!GLM_struct->glLockArraysEXTproc) return;
	GLM_struct->glLockArraysEXTproc(first, count);
}
void APIENTRY glUnlockArraysEXT(void){
	if(!GLM_struct->glUnlockArraysEXTproc) return;
	GLM_struct->glUnlockArraysEXTproc();
}
void APIENTRY glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* image){
	if(!GLM_struct->glConvolutionFilter1DEXTproc) return;
	GLM_struct->glConvolutionFilter1DEXTproc(target, internalformat, width, format, type, image);
}
void APIENTRY glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* image){
	if(!GLM_struct->glConvolutionFilter2DEXTproc) return;
	GLM_struct->glConvolutionFilter2DEXTproc(target, internalformat, width, height, format, type, image);
}
void APIENTRY glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params){
	if(!GLM_struct->glConvolutionParameterfEXTproc) return;
	GLM_struct->glConvolutionParameterfEXTproc(target, pname, params);
}
void APIENTRY glConvolutionParameterfvEXT(GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glConvolutionParameterfvEXTproc) return;
	GLM_struct->glConvolutionParameterfvEXTproc(target, pname, params);
}
void APIENTRY glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params){
	if(!GLM_struct->glConvolutionParameteriEXTproc) return;
	GLM_struct->glConvolutionParameteriEXTproc(target, pname, params);
}
void APIENTRY glConvolutionParameterivEXT(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glConvolutionParameterivEXTproc) return;
	GLM_struct->glConvolutionParameterivEXTproc(target, pname, params);
}
void APIENTRY glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyConvolutionFilter1DEXTproc) return;
	GLM_struct->glCopyConvolutionFilter1DEXTproc(target, internalformat, x, y, width);
}
void APIENTRY glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyConvolutionFilter2DEXTproc) return;
	GLM_struct->glCopyConvolutionFilter2DEXTproc(target, internalformat, x, y, width, height);
}
void APIENTRY glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, void* image){
	if(!GLM_struct->glGetConvolutionFilterEXTproc) return;
	GLM_struct->glGetConvolutionFilterEXTproc(target, format, type, image);
}
void APIENTRY glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetConvolutionParameterfvEXTproc) return;
	GLM_struct->glGetConvolutionParameterfvEXTproc(target, pname, params);
}
void APIENTRY glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetConvolutionParameterivEXTproc) return;
	GLM_struct->glGetConvolutionParameterivEXTproc(target, pname, params);
}
void APIENTRY glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, void* row, void* column, void* span){
	if(!GLM_struct->glGetSeparableFilterEXTproc) return;
	GLM_struct->glGetSeparableFilterEXTproc(target, format, type, row, column, span);
}
void APIENTRY glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* row, const void* column){
	if(!GLM_struct->glSeparableFilter2DEXTproc) return;
	GLM_struct->glSeparableFilter2DEXTproc(target, internalformat, width, height, format, type, row, column);
}
void APIENTRY glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz){
	if(!GLM_struct->glTangent3bEXTproc) return;
	GLM_struct->glTangent3bEXTproc(tx, ty, tz);
}
void APIENTRY glTangent3bvEXT(const GLbyte* v){
	if(!GLM_struct->glTangent3bvEXTproc) return;
	GLM_struct->glTangent3bvEXTproc(v);
}
void APIENTRY glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz){
	if(!GLM_struct->glTangent3dEXTproc) return;
	GLM_struct->glTangent3dEXTproc(tx, ty, tz);
}
void APIENTRY glTangent3dvEXT(const GLdouble* v){
	if(!GLM_struct->glTangent3dvEXTproc) return;
	GLM_struct->glTangent3dvEXTproc(v);
}
void APIENTRY glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz){
	if(!GLM_struct->glTangent3fEXTproc) return;
	GLM_struct->glTangent3fEXTproc(tx, ty, tz);
}
void APIENTRY glTangent3fvEXT(const GLfloat* v){
	if(!GLM_struct->glTangent3fvEXTproc) return;
	GLM_struct->glTangent3fvEXTproc(v);
}
void APIENTRY glTangent3iEXT(GLint tx, GLint ty, GLint tz){
	if(!GLM_struct->glTangent3iEXTproc) return;
	GLM_struct->glTangent3iEXTproc(tx, ty, tz);
}
void APIENTRY glTangent3ivEXT(const GLint* v){
	if(!GLM_struct->glTangent3ivEXTproc) return;
	GLM_struct->glTangent3ivEXTproc(v);
}
void APIENTRY glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz){
	if(!GLM_struct->glTangent3sEXTproc) return;
	GLM_struct->glTangent3sEXTproc(tx, ty, tz);
}
void APIENTRY glTangent3svEXT(const GLshort* v){
	if(!GLM_struct->glTangent3svEXTproc) return;
	GLM_struct->glTangent3svEXTproc(v);
}
void APIENTRY glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz){
	if(!GLM_struct->glBinormal3bEXTproc) return;
	GLM_struct->glBinormal3bEXTproc(bx, by, bz);
}
void APIENTRY glBinormal3bvEXT(const GLbyte* v){
	if(!GLM_struct->glBinormal3bvEXTproc) return;
	GLM_struct->glBinormal3bvEXTproc(v);
}
void APIENTRY glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz){
	if(!GLM_struct->glBinormal3dEXTproc) return;
	GLM_struct->glBinormal3dEXTproc(bx, by, bz);
}
void APIENTRY glBinormal3dvEXT(const GLdouble* v){
	if(!GLM_struct->glBinormal3dvEXTproc) return;
	GLM_struct->glBinormal3dvEXTproc(v);
}
void APIENTRY glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz){
	if(!GLM_struct->glBinormal3fEXTproc) return;
	GLM_struct->glBinormal3fEXTproc(bx, by, bz);
}
void APIENTRY glBinormal3fvEXT(const GLfloat* v){
	if(!GLM_struct->glBinormal3fvEXTproc) return;
	GLM_struct->glBinormal3fvEXTproc(v);
}
void APIENTRY glBinormal3iEXT(GLint bx, GLint by, GLint bz){
	if(!GLM_struct->glBinormal3iEXTproc) return;
	GLM_struct->glBinormal3iEXTproc(bx, by, bz);
}
void APIENTRY glBinormal3ivEXT(const GLint* v){
	if(!GLM_struct->glBinormal3ivEXTproc) return;
	GLM_struct->glBinormal3ivEXTproc(v);
}
void APIENTRY glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz){
	if(!GLM_struct->glBinormal3sEXTproc) return;
	GLM_struct->glBinormal3sEXTproc(bx, by, bz);
}
void APIENTRY glBinormal3svEXT(const GLshort* v){
	if(!GLM_struct->glBinormal3svEXTproc) return;
	GLM_struct->glBinormal3svEXTproc(v);
}
void APIENTRY glTangentPointerEXT(GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glTangentPointerEXTproc) return;
	GLM_struct->glTangentPointerEXTproc(type, stride, pointer);
}
void APIENTRY glBinormalPointerEXT(GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glBinormalPointerEXTproc) return;
	GLM_struct->glBinormalPointerEXTproc(type, stride, pointer);
}
void APIENTRY glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border){
	if(!GLM_struct->glCopyTexImage1DEXTproc) return;
	GLM_struct->glCopyTexImage1DEXTproc(target, level, internalformat, x, y, width, border);
}
void APIENTRY glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border){
	if(!GLM_struct->glCopyTexImage2DEXTproc) return;
	GLM_struct->glCopyTexImage2DEXTproc(target, level, internalformat, x, y, width, height, border);
}
void APIENTRY glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyTexSubImage1DEXTproc) return;
	GLM_struct->glCopyTexSubImage1DEXTproc(target, level, xoffset, x, y, width);
}
void APIENTRY glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyTexSubImage2DEXTproc) return;
	GLM_struct->glCopyTexSubImage2DEXTproc(target, level, xoffset, yoffset, x, y, width, height);
}
void APIENTRY glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyTexSubImage3DEXTproc) return;
	GLM_struct->glCopyTexSubImage3DEXTproc(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void APIENTRY glCullParameterdvEXT(GLenum pname, GLdouble* params){
	if(!GLM_struct->glCullParameterdvEXTproc) return;
	GLM_struct->glCullParameterdvEXTproc(pname, params);
}
void APIENTRY glCullParameterfvEXT(GLenum pname, GLfloat* params){
	if(!GLM_struct->glCullParameterfvEXTproc) return;
	GLM_struct->glCullParameterfvEXTproc(pname, params);
}
void APIENTRY glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label){
	if(!GLM_struct->glLabelObjectEXTproc) return;
	GLM_struct->glLabelObjectEXTproc(type, object, length, label);
}
void APIENTRY glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label){
	if(!GLM_struct->glGetObjectLabelEXTproc) return;
	GLM_struct->glGetObjectLabelEXTproc(type, object, bufSize, length, label);
}
void APIENTRY glInsertEventMarkerEXT(GLsizei length, const GLchar* marker){
	if(!GLM_struct->glInsertEventMarkerEXTproc) return;
	GLM_struct->glInsertEventMarkerEXTproc(length, marker);
}
void APIENTRY glPushGroupMarkerEXT(GLsizei length, const GLchar* marker){
	if(!GLM_struct->glPushGroupMarkerEXTproc) return;
	GLM_struct->glPushGroupMarkerEXTproc(length, marker);
}
void APIENTRY glPopGroupMarkerEXT(void){
	if(!GLM_struct->glPopGroupMarkerEXTproc) return;
	GLM_struct->glPopGroupMarkerEXTproc();
}
void APIENTRY glDepthBoundsEXT(GLclampd zmin, GLclampd zmax){
	if(!GLM_struct->glDepthBoundsEXTproc) return;
	GLM_struct->glDepthBoundsEXTproc(zmin, zmax);
}
void APIENTRY glMatrixLoadfEXT(GLenum mode, const GLfloat* m){
	if(!GLM_struct->glMatrixLoadfEXTproc) return;
	GLM_struct->glMatrixLoadfEXTproc(mode, m);
}
void APIENTRY glMatrixLoaddEXT(GLenum mode, const GLdouble* m){
	if(!GLM_struct->glMatrixLoaddEXTproc) return;
	GLM_struct->glMatrixLoaddEXTproc(mode, m);
}
void APIENTRY glMatrixMultfEXT(GLenum mode, const GLfloat* m){
	if(!GLM_struct->glMatrixMultfEXTproc) return;
	GLM_struct->glMatrixMultfEXTproc(mode, m);
}
void APIENTRY glMatrixMultdEXT(GLenum mode, const GLdouble* m){
	if(!GLM_struct->glMatrixMultdEXTproc) return;
	GLM_struct->glMatrixMultdEXTproc(mode, m);
}
void APIENTRY glMatrixLoadIdentityEXT(GLenum mode){
	if(!GLM_struct->glMatrixLoadIdentityEXTproc) return;
	GLM_struct->glMatrixLoadIdentityEXTproc(mode);
}
void APIENTRY glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glMatrixRotatefEXTproc) return;
	GLM_struct->glMatrixRotatefEXTproc(mode, angle, x, y, z);
}
void APIENTRY glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glMatrixRotatedEXTproc) return;
	GLM_struct->glMatrixRotatedEXTproc(mode, angle, x, y, z);
}
void APIENTRY glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glMatrixScalefEXTproc) return;
	GLM_struct->glMatrixScalefEXTproc(mode, x, y, z);
}
void APIENTRY glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glMatrixScaledEXTproc) return;
	GLM_struct->glMatrixScaledEXTproc(mode, x, y, z);
}
void APIENTRY glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glMatrixTranslatefEXTproc) return;
	GLM_struct->glMatrixTranslatefEXTproc(mode, x, y, z);
}
void APIENTRY glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glMatrixTranslatedEXTproc) return;
	GLM_struct->glMatrixTranslatedEXTproc(mode, x, y, z);
}
void APIENTRY glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar){
	if(!GLM_struct->glMatrixFrustumEXTproc) return;
	GLM_struct->glMatrixFrustumEXTproc(mode, left, right, bottom, top, zNear, zFar);
}
void APIENTRY glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar){
	if(!GLM_struct->glMatrixOrthoEXTproc) return;
	GLM_struct->glMatrixOrthoEXTproc(mode, left, right, bottom, top, zNear, zFar);
}
void APIENTRY glMatrixPopEXT(GLenum mode){
	if(!GLM_struct->glMatrixPopEXTproc) return;
	GLM_struct->glMatrixPopEXTproc(mode);
}
void APIENTRY glMatrixPushEXT(GLenum mode){
	if(!GLM_struct->glMatrixPushEXTproc) return;
	GLM_struct->glMatrixPushEXTproc(mode);
}
void APIENTRY glClientAttribDefaultEXT(GLbitfield mask){
	if(!GLM_struct->glClientAttribDefaultEXTproc) return;
	GLM_struct->glClientAttribDefaultEXTproc(mask);
}
void APIENTRY glPushClientAttribDefaultEXT(GLbitfield mask){
	if(!GLM_struct->glPushClientAttribDefaultEXTproc) return;
	GLM_struct->glPushClientAttribDefaultEXTproc(mask);
}
void APIENTRY glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param){
	if(!GLM_struct->glTextureParameterfEXTproc) return;
	GLM_struct->glTextureParameterfEXTproc(texture, target, pname, param);
}
void APIENTRY glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glTextureParameterfvEXTproc) return;
	GLM_struct->glTextureParameterfvEXTproc(texture, target, pname, params);
}
void APIENTRY glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glTextureParameteriEXTproc) return;
	GLM_struct->glTextureParameteriEXTproc(texture, target, pname, param);
}
void APIENTRY glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glTextureParameterivEXTproc) return;
	GLM_struct->glTextureParameterivEXTproc(texture, target, pname, params);
}
void APIENTRY glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureImage1DEXTproc) return;
	GLM_struct->glTextureImage1DEXTproc(texture, target, level, internalformat, width, border, format, type, pixels);
}
void APIENTRY glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureImage2DEXTproc) return;
	GLM_struct->glTextureImage2DEXTproc(texture, target, level, internalformat, width, height, border, format, type, pixels);
}
void APIENTRY glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureSubImage1DEXTproc) return;
	GLM_struct->glTextureSubImage1DEXTproc(texture, target, level, xoffset, width, format, type, pixels);
}
void APIENTRY glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureSubImage2DEXTproc) return;
	GLM_struct->glTextureSubImage2DEXTproc(texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void APIENTRY glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border){
	if(!GLM_struct->glCopyTextureImage1DEXTproc) return;
	GLM_struct->glCopyTextureImage1DEXTproc(texture, target, level, internalformat, x, y, width, border);
}
void APIENTRY glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border){
	if(!GLM_struct->glCopyTextureImage2DEXTproc) return;
	GLM_struct->glCopyTextureImage2DEXTproc(texture, target, level, internalformat, x, y, width, height, border);
}
void APIENTRY glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyTextureSubImage1DEXTproc) return;
	GLM_struct->glCopyTextureSubImage1DEXTproc(texture, target, level, xoffset, x, y, width);
}
void APIENTRY glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyTextureSubImage2DEXTproc) return;
	GLM_struct->glCopyTextureSubImage2DEXTproc(texture, target, level, xoffset, yoffset, x, y, width, height);
}
void APIENTRY glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels){
	if(!GLM_struct->glGetTextureImageEXTproc) return;
	GLM_struct->glGetTextureImageEXTproc(texture, target, level, format, type, pixels);
}
void APIENTRY glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetTextureParameterfvEXTproc) return;
	GLM_struct->glGetTextureParameterfvEXTproc(texture, target, pname, params);
}
void APIENTRY glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTextureParameterivEXTproc) return;
	GLM_struct->glGetTextureParameterivEXTproc(texture, target, pname, params);
}
void APIENTRY glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetTextureLevelParameterfvEXTproc) return;
	GLM_struct->glGetTextureLevelParameterfvEXTproc(texture, target, level, pname, params);
}
void APIENTRY glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTextureLevelParameterivEXTproc) return;
	GLM_struct->glGetTextureLevelParameterivEXTproc(texture, target, level, pname, params);
}
void APIENTRY glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureImage3DEXTproc) return;
	GLM_struct->glTextureImage3DEXTproc(texture, target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void APIENTRY glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTextureSubImage3DEXTproc) return;
	GLM_struct->glTextureSubImage3DEXTproc(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void APIENTRY glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyTextureSubImage3DEXTproc) return;
	GLM_struct->glCopyTextureSubImage3DEXTproc(texture, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void APIENTRY glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture){
	if(!GLM_struct->glBindMultiTextureEXTproc) return;
	GLM_struct->glBindMultiTextureEXTproc(texunit, target, texture);
}
void APIENTRY glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glMultiTexCoordPointerEXTproc) return;
	GLM_struct->glMultiTexCoordPointerEXTproc(texunit, size, type, stride, pointer);
}
void APIENTRY glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param){
	if(!GLM_struct->glMultiTexEnvfEXTproc) return;
	GLM_struct->glMultiTexEnvfEXTproc(texunit, target, pname, param);
}
void APIENTRY glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glMultiTexEnvfvEXTproc) return;
	GLM_struct->glMultiTexEnvfvEXTproc(texunit, target, pname, params);
}
void APIENTRY glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glMultiTexEnviEXTproc) return;
	GLM_struct->glMultiTexEnviEXTproc(texunit, target, pname, param);
}
void APIENTRY glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glMultiTexEnvivEXTproc) return;
	GLM_struct->glMultiTexEnvivEXTproc(texunit, target, pname, params);
}
void APIENTRY glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param){
	if(!GLM_struct->glMultiTexGendEXTproc) return;
	GLM_struct->glMultiTexGendEXTproc(texunit, coord, pname, param);
}
void APIENTRY glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params){
	if(!GLM_struct->glMultiTexGendvEXTproc) return;
	GLM_struct->glMultiTexGendvEXTproc(texunit, coord, pname, params);
}
void APIENTRY glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param){
	if(!GLM_struct->glMultiTexGenfEXTproc) return;
	GLM_struct->glMultiTexGenfEXTproc(texunit, coord, pname, param);
}
void APIENTRY glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glMultiTexGenfvEXTproc) return;
	GLM_struct->glMultiTexGenfvEXTproc(texunit, coord, pname, params);
}
void APIENTRY glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param){
	if(!GLM_struct->glMultiTexGeniEXTproc) return;
	GLM_struct->glMultiTexGeniEXTproc(texunit, coord, pname, param);
}
void APIENTRY glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint* params){
	if(!GLM_struct->glMultiTexGenivEXTproc) return;
	GLM_struct->glMultiTexGenivEXTproc(texunit, coord, pname, params);
}
void APIENTRY glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMultiTexEnvfvEXTproc) return;
	GLM_struct->glGetMultiTexEnvfvEXTproc(texunit, target, pname, params);
}
void APIENTRY glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMultiTexEnvivEXTproc) return;
	GLM_struct->glGetMultiTexEnvivEXTproc(texunit, target, pname, params);
}
void APIENTRY glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetMultiTexGendvEXTproc) return;
	GLM_struct->glGetMultiTexGendvEXTproc(texunit, coord, pname, params);
}
void APIENTRY glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMultiTexGenfvEXTproc) return;
	GLM_struct->glGetMultiTexGenfvEXTproc(texunit, coord, pname, params);
}
void APIENTRY glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMultiTexGenivEXTproc) return;
	GLM_struct->glGetMultiTexGenivEXTproc(texunit, coord, pname, params);
}
void APIENTRY glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glMultiTexParameteriEXTproc) return;
	GLM_struct->glMultiTexParameteriEXTproc(texunit, target, pname, param);
}
void APIENTRY glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glMultiTexParameterivEXTproc) return;
	GLM_struct->glMultiTexParameterivEXTproc(texunit, target, pname, params);
}
void APIENTRY glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param){
	if(!GLM_struct->glMultiTexParameterfEXTproc) return;
	GLM_struct->glMultiTexParameterfEXTproc(texunit, target, pname, param);
}
void APIENTRY glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glMultiTexParameterfvEXTproc) return;
	GLM_struct->glMultiTexParameterfvEXTproc(texunit, target, pname, params);
}
void APIENTRY glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glMultiTexImage1DEXTproc) return;
	GLM_struct->glMultiTexImage1DEXTproc(texunit, target, level, internalformat, width, border, format, type, pixels);
}
void APIENTRY glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glMultiTexImage2DEXTproc) return;
	GLM_struct->glMultiTexImage2DEXTproc(texunit, target, level, internalformat, width, height, border, format, type, pixels);
}
void APIENTRY glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glMultiTexSubImage1DEXTproc) return;
	GLM_struct->glMultiTexSubImage1DEXTproc(texunit, target, level, xoffset, width, format, type, pixels);
}
void APIENTRY glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glMultiTexSubImage2DEXTproc) return;
	GLM_struct->glMultiTexSubImage2DEXTproc(texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void APIENTRY glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border){
	if(!GLM_struct->glCopyMultiTexImage1DEXTproc) return;
	GLM_struct->glCopyMultiTexImage1DEXTproc(texunit, target, level, internalformat, x, y, width, border);
}
void APIENTRY glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border){
	if(!GLM_struct->glCopyMultiTexImage2DEXTproc) return;
	GLM_struct->glCopyMultiTexImage2DEXTproc(texunit, target, level, internalformat, x, y, width, height, border);
}
void APIENTRY glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyMultiTexSubImage1DEXTproc) return;
	GLM_struct->glCopyMultiTexSubImage1DEXTproc(texunit, target, level, xoffset, x, y, width);
}
void APIENTRY glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyMultiTexSubImage2DEXTproc) return;
	GLM_struct->glCopyMultiTexSubImage2DEXTproc(texunit, target, level, xoffset, yoffset, x, y, width, height);
}
void APIENTRY glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels){
	if(!GLM_struct->glGetMultiTexImageEXTproc) return;
	GLM_struct->glGetMultiTexImageEXTproc(texunit, target, level, format, type, pixels);
}
void APIENTRY glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMultiTexParameterfvEXTproc) return;
	GLM_struct->glGetMultiTexParameterfvEXTproc(texunit, target, pname, params);
}
void APIENTRY glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMultiTexParameterivEXTproc) return;
	GLM_struct->glGetMultiTexParameterivEXTproc(texunit, target, pname, params);
}
void APIENTRY glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMultiTexLevelParameterfvEXTproc) return;
	GLM_struct->glGetMultiTexLevelParameterfvEXTproc(texunit, target, level, pname, params);
}
void APIENTRY glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMultiTexLevelParameterivEXTproc) return;
	GLM_struct->glGetMultiTexLevelParameterivEXTproc(texunit, target, level, pname, params);
}
void APIENTRY glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glMultiTexImage3DEXTproc) return;
	GLM_struct->glMultiTexImage3DEXTproc(texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void APIENTRY glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glMultiTexSubImage3DEXTproc) return;
	GLM_struct->glMultiTexSubImage3DEXTproc(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void APIENTRY glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glCopyMultiTexSubImage3DEXTproc) return;
	GLM_struct->glCopyMultiTexSubImage3DEXTproc(texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void APIENTRY glEnableClientStateIndexedEXT(GLenum array, GLuint index){
	if(!GLM_struct->glEnableClientStateIndexedEXTproc) return;
	GLM_struct->glEnableClientStateIndexedEXTproc(array, index);
}
void APIENTRY glDisableClientStateIndexedEXT(GLenum array, GLuint index){
	if(!GLM_struct->glDisableClientStateIndexedEXTproc) return;
	GLM_struct->glDisableClientStateIndexedEXTproc(array, index);
}
void APIENTRY glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* data){
	if(!GLM_struct->glGetFloatIndexedvEXTproc) return;
	GLM_struct->glGetFloatIndexedvEXTproc(target, index, data);
}
void APIENTRY glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* data){
	if(!GLM_struct->glGetDoubleIndexedvEXTproc) return;
	GLM_struct->glGetDoubleIndexedvEXTproc(target, index, data);
}
void APIENTRY glGetPointerIndexedvEXT(GLenum target, GLuint index, void** data){
	if(!GLM_struct->glGetPointerIndexedvEXTproc) return;
	GLM_struct->glGetPointerIndexedvEXTproc(target, index, data);
}
void APIENTRY glEnableIndexedEXT(GLenum target, GLuint index){
	if(!GLM_struct->glEnableIndexedEXTproc) return;
	GLM_struct->glEnableIndexedEXTproc(target, index);
}
void APIENTRY glDisableIndexedEXT(GLenum target, GLuint index){
	if(!GLM_struct->glDisableIndexedEXTproc) return;
	GLM_struct->glDisableIndexedEXTproc(target, index);
}
GLboolean APIENTRY glIsEnabledIndexedEXT(GLenum target, GLuint index){
	if(!GLM_struct->glIsEnabledIndexedEXTproc) return 0;
	return GLM_struct->glIsEnabledIndexedEXTproc(target, index);
}
void APIENTRY glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint* data){
	if(!GLM_struct->glGetIntegerIndexedvEXTproc) return;
	GLM_struct->glGetIntegerIndexedvEXTproc(target, index, data);
}
void APIENTRY glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean* data){
	if(!GLM_struct->glGetBooleanIndexedvEXTproc) return;
	GLM_struct->glGetBooleanIndexedvEXTproc(target, index, data);
}
void APIENTRY glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedTextureImage3DEXTproc) return;
	GLM_struct->glCompressedTextureImage3DEXTproc(texture, target, level, internalformat, width, height, depth, border, imageSize, bits);
}
void APIENTRY glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedTextureImage2DEXTproc) return;
	GLM_struct->glCompressedTextureImage2DEXTproc(texture, target, level, internalformat, width, height, border, imageSize, bits);
}
void APIENTRY glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedTextureImage1DEXTproc) return;
	GLM_struct->glCompressedTextureImage1DEXTproc(texture, target, level, internalformat, width, border, imageSize, bits);
}
void APIENTRY glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedTextureSubImage3DEXTproc) return;
	GLM_struct->glCompressedTextureSubImage3DEXTproc(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}
void APIENTRY glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedTextureSubImage2DEXTproc) return;
	GLM_struct->glCompressedTextureSubImage2DEXTproc(texture, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}
void APIENTRY glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedTextureSubImage1DEXTproc) return;
	GLM_struct->glCompressedTextureSubImage1DEXTproc(texture, target, level, xoffset, width, format, imageSize, bits);
}
void APIENTRY glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void* img){
	if(!GLM_struct->glGetCompressedTextureImageEXTproc) return;
	GLM_struct->glGetCompressedTextureImageEXTproc(texture, target, lod, img);
}
void APIENTRY glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedMultiTexImage3DEXTproc) return;
	GLM_struct->glCompressedMultiTexImage3DEXTproc(texunit, target, level, internalformat, width, height, depth, border, imageSize, bits);
}
void APIENTRY glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedMultiTexImage2DEXTproc) return;
	GLM_struct->glCompressedMultiTexImage2DEXTproc(texunit, target, level, internalformat, width, height, border, imageSize, bits);
}
void APIENTRY glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedMultiTexImage1DEXTproc) return;
	GLM_struct->glCompressedMultiTexImage1DEXTproc(texunit, target, level, internalformat, width, border, imageSize, bits);
}
void APIENTRY glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedMultiTexSubImage3DEXTproc) return;
	GLM_struct->glCompressedMultiTexSubImage3DEXTproc(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}
void APIENTRY glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedMultiTexSubImage2DEXTproc) return;
	GLM_struct->glCompressedMultiTexSubImage2DEXTproc(texunit, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}
void APIENTRY glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits){
	if(!GLM_struct->glCompressedMultiTexSubImage1DEXTproc) return;
	GLM_struct->glCompressedMultiTexSubImage1DEXTproc(texunit, target, level, xoffset, width, format, imageSize, bits);
}
void APIENTRY glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void* img){
	if(!GLM_struct->glGetCompressedMultiTexImageEXTproc) return;
	GLM_struct->glGetCompressedMultiTexImageEXTproc(texunit, target, lod, img);
}
void APIENTRY glMatrixLoadTransposefEXT(GLenum mode, const GLfloat* m){
	if(!GLM_struct->glMatrixLoadTransposefEXTproc) return;
	GLM_struct->glMatrixLoadTransposefEXTproc(mode, m);
}
void APIENTRY glMatrixLoadTransposedEXT(GLenum mode, const GLdouble* m){
	if(!GLM_struct->glMatrixLoadTransposedEXTproc) return;
	GLM_struct->glMatrixLoadTransposedEXTproc(mode, m);
}
void APIENTRY glMatrixMultTransposefEXT(GLenum mode, const GLfloat* m){
	if(!GLM_struct->glMatrixMultTransposefEXTproc) return;
	GLM_struct->glMatrixMultTransposefEXTproc(mode, m);
}
void APIENTRY glMatrixMultTransposedEXT(GLenum mode, const GLdouble* m){
	if(!GLM_struct->glMatrixMultTransposedEXTproc) return;
	GLM_struct->glMatrixMultTransposedEXTproc(mode, m);
}
void APIENTRY glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage){
	if(!GLM_struct->glNamedBufferDataEXTproc) return;
	GLM_struct->glNamedBufferDataEXTproc(buffer, size, data, usage);
}
void APIENTRY glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data){
	if(!GLM_struct->glNamedBufferSubDataEXTproc) return;
	GLM_struct->glNamedBufferSubDataEXTproc(buffer, offset, size, data);
}
void* APIENTRY glMapNamedBufferEXT(GLuint buffer, GLenum access){
	if(!GLM_struct->glMapNamedBufferEXTproc) return 0;
	return GLM_struct->glMapNamedBufferEXTproc(buffer, access);
}
GLboolean APIENTRY glUnmapNamedBufferEXT(GLuint buffer){
	if(!GLM_struct->glUnmapNamedBufferEXTproc) return 0;
	return GLM_struct->glUnmapNamedBufferEXTproc(buffer);
}
void APIENTRY glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedBufferParameterivEXTproc) return;
	GLM_struct->glGetNamedBufferParameterivEXTproc(buffer, pname, params);
}
void APIENTRY glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void** params){
	if(!GLM_struct->glGetNamedBufferPointervEXTproc) return;
	GLM_struct->glGetNamedBufferPointervEXTproc(buffer, pname, params);
}
void APIENTRY glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data){
	if(!GLM_struct->glGetNamedBufferSubDataEXTproc) return;
	GLM_struct->glGetNamedBufferSubDataEXTproc(buffer, offset, size, data);
}
void APIENTRY glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0){
	if(!GLM_struct->glProgramUniform1fEXTproc) return;
	GLM_struct->glProgramUniform1fEXTproc(program, location, v0);
}
void APIENTRY glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1){
	if(!GLM_struct->glProgramUniform2fEXTproc) return;
	GLM_struct->glProgramUniform2fEXTproc(program, location, v0, v1);
}
void APIENTRY glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2){
	if(!GLM_struct->glProgramUniform3fEXTproc) return;
	GLM_struct->glProgramUniform3fEXTproc(program, location, v0, v1, v2);
}
void APIENTRY glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3){
	if(!GLM_struct->glProgramUniform4fEXTproc) return;
	GLM_struct->glProgramUniform4fEXTproc(program, location, v0, v1, v2, v3);
}
void APIENTRY glProgramUniform1iEXT(GLuint program, GLint location, GLint v0){
	if(!GLM_struct->glProgramUniform1iEXTproc) return;
	GLM_struct->glProgramUniform1iEXTproc(program, location, v0);
}
void APIENTRY glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1){
	if(!GLM_struct->glProgramUniform2iEXTproc) return;
	GLM_struct->glProgramUniform2iEXTproc(program, location, v0, v1);
}
void APIENTRY glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2){
	if(!GLM_struct->glProgramUniform3iEXTproc) return;
	GLM_struct->glProgramUniform3iEXTproc(program, location, v0, v1, v2);
}
void APIENTRY glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3){
	if(!GLM_struct->glProgramUniform4iEXTproc) return;
	GLM_struct->glProgramUniform4iEXTproc(program, location, v0, v1, v2, v3);
}
void APIENTRY glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform1fvEXTproc) return;
	GLM_struct->glProgramUniform1fvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform2fvEXTproc) return;
	GLM_struct->glProgramUniform2fvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform3fvEXTproc) return;
	GLM_struct->glProgramUniform3fvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value){
	if(!GLM_struct->glProgramUniform4fvEXTproc) return;
	GLM_struct->glProgramUniform4fvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform1ivEXTproc) return;
	GLM_struct->glProgramUniform1ivEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform2ivEXTproc) return;
	GLM_struct->glProgramUniform2ivEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform3ivEXTproc) return;
	GLM_struct->glProgramUniform3ivEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value){
	if(!GLM_struct->glProgramUniform4ivEXTproc) return;
	GLM_struct->glProgramUniform4ivEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix2fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix2fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix3fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix3fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix4fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix4fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix2x3fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix2x3fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix3x2fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix3x2fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix2x4fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix2x4fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix4x2fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix4x2fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix3x4fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix3x4fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	if(!GLM_struct->glProgramUniformMatrix4x3fvEXTproc) return;
	GLM_struct->glProgramUniformMatrix4x3fvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer){
	if(!GLM_struct->glTextureBufferEXTproc) return;
	GLM_struct->glTextureBufferEXTproc(texture, target, internalformat, buffer);
}
void APIENTRY glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer){
	if(!GLM_struct->glMultiTexBufferEXTproc) return;
	GLM_struct->glMultiTexBufferEXTproc(texunit, target, internalformat, buffer);
}
void APIENTRY glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glTextureParameterIivEXTproc) return;
	GLM_struct->glTextureParameterIivEXTproc(texture, target, pname, params);
}
void APIENTRY glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint* params){
	if(!GLM_struct->glTextureParameterIuivEXTproc) return;
	GLM_struct->glTextureParameterIuivEXTproc(texture, target, pname, params);
}
void APIENTRY glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTextureParameterIivEXTproc) return;
	GLM_struct->glGetTextureParameterIivEXTproc(texture, target, pname, params);
}
void APIENTRY glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetTextureParameterIuivEXTproc) return;
	GLM_struct->glGetTextureParameterIuivEXTproc(texture, target, pname, params);
}
void APIENTRY glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glMultiTexParameterIivEXTproc) return;
	GLM_struct->glMultiTexParameterIivEXTproc(texunit, target, pname, params);
}
void APIENTRY glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint* params){
	if(!GLM_struct->glMultiTexParameterIuivEXTproc) return;
	GLM_struct->glMultiTexParameterIuivEXTproc(texunit, target, pname, params);
}
void APIENTRY glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMultiTexParameterIivEXTproc) return;
	GLM_struct->glGetMultiTexParameterIivEXTproc(texunit, target, pname, params);
}
void APIENTRY glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetMultiTexParameterIuivEXTproc) return;
	GLM_struct->glGetMultiTexParameterIuivEXTproc(texunit, target, pname, params);
}
void APIENTRY glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0){
	if(!GLM_struct->glProgramUniform1uiEXTproc) return;
	GLM_struct->glProgramUniform1uiEXTproc(program, location, v0);
}
void APIENTRY glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1){
	if(!GLM_struct->glProgramUniform2uiEXTproc) return;
	GLM_struct->glProgramUniform2uiEXTproc(program, location, v0, v1);
}
void APIENTRY glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2){
	if(!GLM_struct->glProgramUniform3uiEXTproc) return;
	GLM_struct->glProgramUniform3uiEXTproc(program, location, v0, v1, v2);
}
void APIENTRY glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3){
	if(!GLM_struct->glProgramUniform4uiEXTproc) return;
	GLM_struct->glProgramUniform4uiEXTproc(program, location, v0, v1, v2, v3);
}
void APIENTRY glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform1uivEXTproc) return;
	GLM_struct->glProgramUniform1uivEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform2uivEXTproc) return;
	GLM_struct->glProgramUniform2uivEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform3uivEXTproc) return;
	GLM_struct->glProgramUniform3uivEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glProgramUniform4uivEXTproc) return;
	GLM_struct->glProgramUniform4uivEXTproc(program, location, count, value);
}
void APIENTRY glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params){
	if(!GLM_struct->glNamedProgramLocalParameters4fvEXTproc) return;
	GLM_struct->glNamedProgramLocalParameters4fvEXTproc(program, target, index, count, params);
}
void APIENTRY glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w){
	if(!GLM_struct->glNamedProgramLocalParameterI4iEXTproc) return;
	GLM_struct->glNamedProgramLocalParameterI4iEXTproc(program, target, index, x, y, z, w);
}
void APIENTRY glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint* params){
	if(!GLM_struct->glNamedProgramLocalParameterI4ivEXTproc) return;
	GLM_struct->glNamedProgramLocalParameterI4ivEXTproc(program, target, index, params);
}
void APIENTRY glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params){
	if(!GLM_struct->glNamedProgramLocalParametersI4ivEXTproc) return;
	GLM_struct->glNamedProgramLocalParametersI4ivEXTproc(program, target, index, count, params);
}
void APIENTRY glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w){
	if(!GLM_struct->glNamedProgramLocalParameterI4uiEXTproc) return;
	GLM_struct->glNamedProgramLocalParameterI4uiEXTproc(program, target, index, x, y, z, w);
}
void APIENTRY glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint* params){
	if(!GLM_struct->glNamedProgramLocalParameterI4uivEXTproc) return;
	GLM_struct->glNamedProgramLocalParameterI4uivEXTproc(program, target, index, params);
}
void APIENTRY glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params){
	if(!GLM_struct->glNamedProgramLocalParametersI4uivEXTproc) return;
	GLM_struct->glNamedProgramLocalParametersI4uivEXTproc(program, target, index, count, params);
}
void APIENTRY glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params){
	if(!GLM_struct->glGetNamedProgramLocalParameterIivEXTproc) return;
	GLM_struct->glGetNamedProgramLocalParameterIivEXTproc(program, target, index, params);
}
void APIENTRY glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params){
	if(!GLM_struct->glGetNamedProgramLocalParameterIuivEXTproc) return;
	GLM_struct->glGetNamedProgramLocalParameterIuivEXTproc(program, target, index, params);
}
void APIENTRY glEnableClientStateiEXT(GLenum array, GLuint index){
	if(!GLM_struct->glEnableClientStateiEXTproc) return;
	GLM_struct->glEnableClientStateiEXTproc(array, index);
}
void APIENTRY glDisableClientStateiEXT(GLenum array, GLuint index){
	if(!GLM_struct->glDisableClientStateiEXTproc) return;
	GLM_struct->glDisableClientStateiEXTproc(array, index);
}
void APIENTRY glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat* params){
	if(!GLM_struct->glGetFloati_vEXTproc) return;
	GLM_struct->glGetFloati_vEXTproc(pname, index, params);
}
void APIENTRY glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble* params){
	if(!GLM_struct->glGetDoublei_vEXTproc) return;
	GLM_struct->glGetDoublei_vEXTproc(pname, index, params);
}
void APIENTRY glGetPointeri_vEXT(GLenum pname, GLuint index, void** params){
	if(!GLM_struct->glGetPointeri_vEXTproc) return;
	GLM_struct->glGetPointeri_vEXTproc(pname, index, params);
}
void APIENTRY glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void* string){
	if(!GLM_struct->glNamedProgramStringEXTproc) return;
	GLM_struct->glNamedProgramStringEXTproc(program, target, format, len, string);
}
void APIENTRY glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glNamedProgramLocalParameter4dEXTproc) return;
	GLM_struct->glNamedProgramLocalParameter4dEXTproc(program, target, index, x, y, z, w);
}
void APIENTRY glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble* params){
	if(!GLM_struct->glNamedProgramLocalParameter4dvEXTproc) return;
	GLM_struct->glNamedProgramLocalParameter4dvEXTproc(program, target, index, params);
}
void APIENTRY glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glNamedProgramLocalParameter4fEXTproc) return;
	GLM_struct->glNamedProgramLocalParameter4fEXTproc(program, target, index, x, y, z, w);
}
void APIENTRY glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat* params){
	if(!GLM_struct->glNamedProgramLocalParameter4fvEXTproc) return;
	GLM_struct->glNamedProgramLocalParameter4fvEXTproc(program, target, index, params);
}
void APIENTRY glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params){
	if(!GLM_struct->glGetNamedProgramLocalParameterdvEXTproc) return;
	GLM_struct->glGetNamedProgramLocalParameterdvEXTproc(program, target, index, params);
}
void APIENTRY glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params){
	if(!GLM_struct->glGetNamedProgramLocalParameterfvEXTproc) return;
	GLM_struct->glGetNamedProgramLocalParameterfvEXTproc(program, target, index, params);
}
void APIENTRY glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedProgramivEXTproc) return;
	GLM_struct->glGetNamedProgramivEXTproc(program, target, pname, params);
}
void APIENTRY glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void* string){
	if(!GLM_struct->glGetNamedProgramStringEXTproc) return;
	GLM_struct->glGetNamedProgramStringEXTproc(program, target, pname, string);
}
void APIENTRY glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glNamedRenderbufferStorageEXTproc) return;
	GLM_struct->glNamedRenderbufferStorageEXTproc(renderbuffer, internalformat, width, height);
}
void APIENTRY glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedRenderbufferParameterivEXTproc) return;
	GLM_struct->glGetNamedRenderbufferParameterivEXTproc(renderbuffer, pname, params);
}
void APIENTRY glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glNamedRenderbufferStorageMultisampleEXTproc) return;
	GLM_struct->glNamedRenderbufferStorageMultisampleEXTproc(renderbuffer, samples, internalformat, width, height);
}
void APIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glNamedRenderbufferStorageMultisampleCoverageEXTproc) return;
	GLM_struct->glNamedRenderbufferStorageMultisampleCoverageEXTproc(renderbuffer, coverageSamples, colorSamples, internalformat, width, height);
}
GLenum APIENTRY glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target){
	if(!GLM_struct->glCheckNamedFramebufferStatusEXTproc) return 0;
	return GLM_struct->glCheckNamedFramebufferStatusEXTproc(framebuffer, target);
}
void APIENTRY glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level){
	if(!GLM_struct->glNamedFramebufferTexture1DEXTproc) return;
	GLM_struct->glNamedFramebufferTexture1DEXTproc(framebuffer, attachment, textarget, texture, level);
}
void APIENTRY glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level){
	if(!GLM_struct->glNamedFramebufferTexture2DEXTproc) return;
	GLM_struct->glNamedFramebufferTexture2DEXTproc(framebuffer, attachment, textarget, texture, level);
}
void APIENTRY glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset){
	if(!GLM_struct->glNamedFramebufferTexture3DEXTproc) return;
	GLM_struct->glNamedFramebufferTexture3DEXTproc(framebuffer, attachment, textarget, texture, level, zoffset);
}
void APIENTRY glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer){
	if(!GLM_struct->glNamedFramebufferRenderbufferEXTproc) return;
	GLM_struct->glNamedFramebufferRenderbufferEXTproc(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
void APIENTRY glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedFramebufferAttachmentParameterivEXTproc) return;
	GLM_struct->glGetNamedFramebufferAttachmentParameterivEXTproc(framebuffer, attachment, pname, params);
}
void APIENTRY glGenerateTextureMipmapEXT(GLuint texture, GLenum target){
	if(!GLM_struct->glGenerateTextureMipmapEXTproc) return;
	GLM_struct->glGenerateTextureMipmapEXTproc(texture, target);
}
void APIENTRY glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target){
	if(!GLM_struct->glGenerateMultiTexMipmapEXTproc) return;
	GLM_struct->glGenerateMultiTexMipmapEXTproc(texunit, target);
}
void APIENTRY glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode){
	if(!GLM_struct->glFramebufferDrawBufferEXTproc) return;
	GLM_struct->glFramebufferDrawBufferEXTproc(framebuffer, mode);
}
void APIENTRY glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs){
	if(!GLM_struct->glFramebufferDrawBuffersEXTproc) return;
	GLM_struct->glFramebufferDrawBuffersEXTproc(framebuffer, n, bufs);
}
void APIENTRY glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode){
	if(!GLM_struct->glFramebufferReadBufferEXTproc) return;
	GLM_struct->glFramebufferReadBufferEXTproc(framebuffer, mode);
}
void APIENTRY glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFramebufferParameterivEXTproc) return;
	GLM_struct->glGetFramebufferParameterivEXTproc(framebuffer, pname, params);
}
void APIENTRY glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size){
	if(!GLM_struct->glNamedCopyBufferSubDataEXTproc) return;
	GLM_struct->glNamedCopyBufferSubDataEXTproc(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
void APIENTRY glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level){
	if(!GLM_struct->glNamedFramebufferTextureEXTproc) return;
	GLM_struct->glNamedFramebufferTextureEXTproc(framebuffer, attachment, texture, level);
}
void APIENTRY glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer){
	if(!GLM_struct->glNamedFramebufferTextureLayerEXTproc) return;
	GLM_struct->glNamedFramebufferTextureLayerEXTproc(framebuffer, attachment, texture, level, layer);
}
void APIENTRY glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face){
	if(!GLM_struct->glNamedFramebufferTextureFaceEXTproc) return;
	GLM_struct->glNamedFramebufferTextureFaceEXTproc(framebuffer, attachment, texture, level, face);
}
void APIENTRY glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer){
	if(!GLM_struct->glTextureRenderbufferEXTproc) return;
	GLM_struct->glTextureRenderbufferEXTproc(texture, target, renderbuffer);
}
void APIENTRY glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer){
	if(!GLM_struct->glMultiTexRenderbufferEXTproc) return;
	GLM_struct->glMultiTexRenderbufferEXTproc(texunit, target, renderbuffer);
}
void APIENTRY glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayVertexOffsetEXTproc) return;
	GLM_struct->glVertexArrayVertexOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
void APIENTRY glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayColorOffsetEXTproc) return;
	GLM_struct->glVertexArrayColorOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
void APIENTRY glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayEdgeFlagOffsetEXTproc) return;
	GLM_struct->glVertexArrayEdgeFlagOffsetEXTproc(vaobj, buffer, stride, offset);
}
void APIENTRY glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayIndexOffsetEXTproc) return;
	GLM_struct->glVertexArrayIndexOffsetEXTproc(vaobj, buffer, type, stride, offset);
}
void APIENTRY glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayNormalOffsetEXTproc) return;
	GLM_struct->glVertexArrayNormalOffsetEXTproc(vaobj, buffer, type, stride, offset);
}
void APIENTRY glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayTexCoordOffsetEXTproc) return;
	GLM_struct->glVertexArrayTexCoordOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
void APIENTRY glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayMultiTexCoordOffsetEXTproc) return;
	GLM_struct->glVertexArrayMultiTexCoordOffsetEXTproc(vaobj, buffer, texunit, size, type, stride, offset);
}
void APIENTRY glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayFogCoordOffsetEXTproc) return;
	GLM_struct->glVertexArrayFogCoordOffsetEXTproc(vaobj, buffer, type, stride, offset);
}
void APIENTRY glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArraySecondaryColorOffsetEXTproc) return;
	GLM_struct->glVertexArraySecondaryColorOffsetEXTproc(vaobj, buffer, size, type, stride, offset);
}
void APIENTRY glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayVertexAttribOffsetEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribOffsetEXTproc(vaobj, buffer, index, size, type, normalized, stride, offset);
}
void APIENTRY glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayVertexAttribIOffsetEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribIOffsetEXTproc(vaobj, buffer, index, size, type, stride, offset);
}
void APIENTRY glEnableVertexArrayEXT(GLuint vaobj, GLenum array){
	if(!GLM_struct->glEnableVertexArrayEXTproc) return;
	GLM_struct->glEnableVertexArrayEXTproc(vaobj, array);
}
void APIENTRY glDisableVertexArrayEXT(GLuint vaobj, GLenum array){
	if(!GLM_struct->glDisableVertexArrayEXTproc) return;
	GLM_struct->glDisableVertexArrayEXTproc(vaobj, array);
}
void APIENTRY glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index){
	if(!GLM_struct->glEnableVertexArrayAttribEXTproc) return;
	GLM_struct->glEnableVertexArrayAttribEXTproc(vaobj, index);
}
void APIENTRY glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index){
	if(!GLM_struct->glDisableVertexArrayAttribEXTproc) return;
	GLM_struct->glDisableVertexArrayAttribEXTproc(vaobj, index);
}
void APIENTRY glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint* param){
	if(!GLM_struct->glGetVertexArrayIntegervEXTproc) return;
	GLM_struct->glGetVertexArrayIntegervEXTproc(vaobj, pname, param);
}
void APIENTRY glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void** param){
	if(!GLM_struct->glGetVertexArrayPointervEXTproc) return;
	GLM_struct->glGetVertexArrayPointervEXTproc(vaobj, pname, param);
}
void APIENTRY glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint* param){
	if(!GLM_struct->glGetVertexArrayIntegeri_vEXTproc) return;
	GLM_struct->glGetVertexArrayIntegeri_vEXTproc(vaobj, index, pname, param);
}
void APIENTRY glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void** param){
	if(!GLM_struct->glGetVertexArrayPointeri_vEXTproc) return;
	GLM_struct->glGetVertexArrayPointeri_vEXTproc(vaobj, index, pname, param);
}
void* APIENTRY glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access){
	if(!GLM_struct->glMapNamedBufferRangeEXTproc) return 0;
	return GLM_struct->glMapNamedBufferRangeEXTproc(buffer, offset, length, access);
}
void APIENTRY glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length){
	if(!GLM_struct->glFlushMappedNamedBufferRangeEXTproc) return;
	GLM_struct->glFlushMappedNamedBufferRangeEXTproc(buffer, offset, length);
}
void APIENTRY glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags){
	if(!GLM_struct->glNamedBufferStorageEXTproc) return;
	GLM_struct->glNamedBufferStorageEXTproc(buffer, size, data, flags);
}
void APIENTRY glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearNamedBufferDataEXTproc) return;
	GLM_struct->glClearNamedBufferDataEXTproc(buffer, internalformat, format, type, data);
}
void APIENTRY glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data){
	if(!GLM_struct->glClearNamedBufferSubDataEXTproc) return;
	GLM_struct->glClearNamedBufferSubDataEXTproc(buffer, internalformat, offset, size, format, type, data);
}
void APIENTRY glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param){
	if(!GLM_struct->glNamedFramebufferParameteriEXTproc) return;
	GLM_struct->glNamedFramebufferParameteriEXTproc(framebuffer, pname, param);
}
void APIENTRY glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params){
	if(!GLM_struct->glGetNamedFramebufferParameterivEXTproc) return;
	GLM_struct->glGetNamedFramebufferParameterivEXTproc(framebuffer, pname, params);
}
void APIENTRY glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x){
	if(!GLM_struct->glProgramUniform1dEXTproc) return;
	GLM_struct->glProgramUniform1dEXTproc(program, location, x);
}
void APIENTRY glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y){
	if(!GLM_struct->glProgramUniform2dEXTproc) return;
	GLM_struct->glProgramUniform2dEXTproc(program, location, x, y);
}
void APIENTRY glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glProgramUniform3dEXTproc) return;
	GLM_struct->glProgramUniform3dEXTproc(program, location, x, y, z);
}
void APIENTRY glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glProgramUniform4dEXTproc) return;
	GLM_struct->glProgramUniform4dEXTproc(program, location, x, y, z, w);
}
void APIENTRY glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform1dvEXTproc) return;
	GLM_struct->glProgramUniform1dvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform2dvEXTproc) return;
	GLM_struct->glProgramUniform2dvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform3dvEXTproc) return;
	GLM_struct->glProgramUniform3dvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value){
	if(!GLM_struct->glProgramUniform4dvEXTproc) return;
	GLM_struct->glProgramUniform4dvEXTproc(program, location, count, value);
}
void APIENTRY glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix2dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix2dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix3dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix3dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix4dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix4dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix2x3dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix2x3dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix2x4dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix2x4dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix3x2dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix3x2dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix3x4dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix3x4dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix4x2dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix4x2dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value){
	if(!GLM_struct->glProgramUniformMatrix4x3dvEXTproc) return;
	GLM_struct->glProgramUniformMatrix4x3dvEXTproc(program, location, count, transpose, value);
}
void APIENTRY glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glTextureBufferRangeEXTproc) return;
	GLM_struct->glTextureBufferRangeEXTproc(texture, target, internalformat, buffer, offset, size);
}
void APIENTRY glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width){
	if(!GLM_struct->glTextureStorage1DEXTproc) return;
	GLM_struct->glTextureStorage1DEXTproc(texture, target, levels, internalformat, width);
}
void APIENTRY glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glTextureStorage2DEXTproc) return;
	GLM_struct->glTextureStorage2DEXTproc(texture, target, levels, internalformat, width, height);
}
void APIENTRY glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->glTextureStorage3DEXTproc) return;
	GLM_struct->glTextureStorage3DEXTproc(texture, target, levels, internalformat, width, height, depth);
}
void APIENTRY glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTextureStorage2DMultisampleEXTproc) return;
	GLM_struct->glTextureStorage2DMultisampleEXTproc(texture, target, samples, internalformat, width, height, fixedsamplelocations);
}
void APIENTRY glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations){
	if(!GLM_struct->glTextureStorage3DMultisampleEXTproc) return;
	GLM_struct->glTextureStorage3DMultisampleEXTproc(texture, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
void APIENTRY glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride){
	if(!GLM_struct->glVertexArrayBindVertexBufferEXTproc) return;
	GLM_struct->glVertexArrayBindVertexBufferEXTproc(vaobj, bindingindex, buffer, offset, stride);
}
void APIENTRY glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset){
	if(!GLM_struct->glVertexArrayVertexAttribFormatEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribFormatEXTproc(vaobj, attribindex, size, type, normalized, relativeoffset);
}
void APIENTRY glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset){
	if(!GLM_struct->glVertexArrayVertexAttribIFormatEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribIFormatEXTproc(vaobj, attribindex, size, type, relativeoffset);
}
void APIENTRY glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset){
	if(!GLM_struct->glVertexArrayVertexAttribLFormatEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribLFormatEXTproc(vaobj, attribindex, size, type, relativeoffset);
}
void APIENTRY glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex){
	if(!GLM_struct->glVertexArrayVertexAttribBindingEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribBindingEXTproc(vaobj, attribindex, bindingindex);
}
void APIENTRY glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor){
	if(!GLM_struct->glVertexArrayVertexBindingDivisorEXTproc) return;
	GLM_struct->glVertexArrayVertexBindingDivisorEXTproc(vaobj, bindingindex, divisor);
}
void APIENTRY glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset){
	if(!GLM_struct->glVertexArrayVertexAttribLOffsetEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribLOffsetEXTproc(vaobj, buffer, index, size, type, stride, offset);
}
void APIENTRY glTexturePageCommitmentEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit){
	if(!GLM_struct->glTexturePageCommitmentEXTproc) return;
	GLM_struct->glTexturePageCommitmentEXTproc(texture, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}
void APIENTRY glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor){
	if(!GLM_struct->glVertexArrayVertexAttribDivisorEXTproc) return;
	GLM_struct->glVertexArrayVertexAttribDivisorEXTproc(vaobj, index, divisor);
}
void APIENTRY glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a){
	if(!GLM_struct->glColorMaskIndexedEXTproc) return;
	GLM_struct->glColorMaskIndexedEXTproc(index, r, g, b, a);
}
void APIENTRY glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount){
	if(!GLM_struct->glDrawArraysInstancedEXTproc) return;
	GLM_struct->glDrawArraysInstancedEXTproc(mode, start, count, primcount);
}
void APIENTRY glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount){
	if(!GLM_struct->glDrawElementsInstancedEXTproc) return;
	GLM_struct->glDrawElementsInstancedEXTproc(mode, count, type, indices, primcount);
}
void APIENTRY glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices){
	if(!GLM_struct->glDrawRangeElementsEXTproc) return;
	GLM_struct->glDrawRangeElementsEXTproc(mode, start, end, count, type, indices);
}
void APIENTRY glBufferStorageExternalEXT(GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags){
	if(!GLM_struct->glBufferStorageExternalEXTproc) return;
	GLM_struct->glBufferStorageExternalEXTproc(target, offset, size, clientBuffer, flags);
}
void APIENTRY glNamedBufferStorageExternalEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags){
	if(!GLM_struct->glNamedBufferStorageExternalEXTproc) return;
	GLM_struct->glNamedBufferStorageExternalEXTproc(buffer, offset, size, clientBuffer, flags);
}
void APIENTRY glFogCoordfEXT(GLfloat coord){
	if(!GLM_struct->glFogCoordfEXTproc) return;
	GLM_struct->glFogCoordfEXTproc(coord);
}
void APIENTRY glFogCoordfvEXT(const GLfloat* coord){
	if(!GLM_struct->glFogCoordfvEXTproc) return;
	GLM_struct->glFogCoordfvEXTproc(coord);
}
void APIENTRY glFogCoorddEXT(GLdouble coord){
	if(!GLM_struct->glFogCoorddEXTproc) return;
	GLM_struct->glFogCoorddEXTproc(coord);
}
void APIENTRY glFogCoorddvEXT(const GLdouble* coord){
	if(!GLM_struct->glFogCoorddvEXTproc) return;
	GLM_struct->glFogCoorddvEXTproc(coord);
}
void APIENTRY glFogCoordPointerEXT(GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glFogCoordPointerEXTproc) return;
	GLM_struct->glFogCoordPointerEXTproc(type, stride, pointer);
}
void APIENTRY glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){
	if(!GLM_struct->glBlitFramebufferEXTproc) return;
	GLM_struct->glBlitFramebufferEXTproc(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
void APIENTRY glBlitFramebufferLayersEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){
	if(!GLM_struct->glBlitFramebufferLayersEXTproc) return;
	GLM_struct->glBlitFramebufferLayersEXTproc(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
void APIENTRY glBlitFramebufferLayerEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint srcLayer, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLint dstLayer, GLbitfield mask, GLenum filter){
	if(!GLM_struct->glBlitFramebufferLayerEXTproc) return;
	GLM_struct->glBlitFramebufferLayerEXTproc(srcX0, srcY0, srcX1, srcY1, srcLayer, dstX0, dstY0, dstX1, dstY1, dstLayer, mask, filter);
}
void APIENTRY glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glRenderbufferStorageMultisampleEXTproc) return;
	GLM_struct->glRenderbufferStorageMultisampleEXTproc(target, samples, internalformat, width, height);
}
GLboolean APIENTRY glIsRenderbufferEXT(GLuint renderbuffer){
	if(!GLM_struct->glIsRenderbufferEXTproc) return 0;
	return GLM_struct->glIsRenderbufferEXTproc(renderbuffer);
}
void APIENTRY glBindRenderbufferEXT(GLenum target, GLuint renderbuffer){
	if(!GLM_struct->glBindRenderbufferEXTproc) return;
	GLM_struct->glBindRenderbufferEXTproc(target, renderbuffer);
}
void APIENTRY glDeleteRenderbuffersEXT(GLsizei n, const GLuint* renderbuffers){
	if(!GLM_struct->glDeleteRenderbuffersEXTproc) return;
	GLM_struct->glDeleteRenderbuffersEXTproc(n, renderbuffers);
}
void APIENTRY glGenRenderbuffersEXT(GLsizei n, GLuint* renderbuffers){
	if(!GLM_struct->glGenRenderbuffersEXTproc) return;
	GLM_struct->glGenRenderbuffersEXTproc(n, renderbuffers);
}
void APIENTRY glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glRenderbufferStorageEXTproc) return;
	GLM_struct->glRenderbufferStorageEXTproc(target, internalformat, width, height);
}
void APIENTRY glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetRenderbufferParameterivEXTproc) return;
	GLM_struct->glGetRenderbufferParameterivEXTproc(target, pname, params);
}
GLboolean APIENTRY glIsFramebufferEXT(GLuint framebuffer){
	if(!GLM_struct->glIsFramebufferEXTproc) return 0;
	return GLM_struct->glIsFramebufferEXTproc(framebuffer);
}
void APIENTRY glBindFramebufferEXT(GLenum target, GLuint framebuffer){
	if(!GLM_struct->glBindFramebufferEXTproc) return;
	GLM_struct->glBindFramebufferEXTproc(target, framebuffer);
}
void APIENTRY glDeleteFramebuffersEXT(GLsizei n, const GLuint* framebuffers){
	if(!GLM_struct->glDeleteFramebuffersEXTproc) return;
	GLM_struct->glDeleteFramebuffersEXTproc(n, framebuffers);
}
void APIENTRY glGenFramebuffersEXT(GLsizei n, GLuint* framebuffers){
	if(!GLM_struct->glGenFramebuffersEXTproc) return;
	GLM_struct->glGenFramebuffersEXTproc(n, framebuffers);
}
GLenum APIENTRY glCheckFramebufferStatusEXT(GLenum target){
	if(!GLM_struct->glCheckFramebufferStatusEXTproc) return 0;
	return GLM_struct->glCheckFramebufferStatusEXTproc(target);
}
void APIENTRY glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){
	if(!GLM_struct->glFramebufferTexture1DEXTproc) return;
	GLM_struct->glFramebufferTexture1DEXTproc(target, attachment, textarget, texture, level);
}
void APIENTRY glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){
	if(!GLM_struct->glFramebufferTexture2DEXTproc) return;
	GLM_struct->glFramebufferTexture2DEXTproc(target, attachment, textarget, texture, level);
}
void APIENTRY glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset){
	if(!GLM_struct->glFramebufferTexture3DEXTproc) return;
	GLM_struct->glFramebufferTexture3DEXTproc(target, attachment, textarget, texture, level, zoffset);
}
void APIENTRY glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer){
	if(!GLM_struct->glFramebufferRenderbufferEXTproc) return;
	GLM_struct->glFramebufferRenderbufferEXTproc(target, attachment, renderbuffertarget, renderbuffer);
}
void APIENTRY glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFramebufferAttachmentParameterivEXTproc) return;
	GLM_struct->glGetFramebufferAttachmentParameterivEXTproc(target, attachment, pname, params);
}
void APIENTRY glGenerateMipmapEXT(GLenum target){
	if(!GLM_struct->glGenerateMipmapEXTproc) return;
	GLM_struct->glGenerateMipmapEXTproc(target);
}
void APIENTRY glProgramParameteriEXT(GLuint program, GLenum pname, GLint value){
	if(!GLM_struct->glProgramParameteriEXTproc) return;
	GLM_struct->glProgramParameteriEXTproc(program, pname, value);
}
void APIENTRY glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params){
	if(!GLM_struct->glProgramEnvParameters4fvEXTproc) return;
	GLM_struct->glProgramEnvParameters4fvEXTproc(target, index, count, params);
}
void APIENTRY glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params){
	if(!GLM_struct->glProgramLocalParameters4fvEXTproc) return;
	GLM_struct->glProgramLocalParameters4fvEXTproc(target, index, count, params);
}
void APIENTRY glGetUniformuivEXT(GLuint program, GLint location, GLuint* params){
	if(!GLM_struct->glGetUniformuivEXTproc) return;
	GLM_struct->glGetUniformuivEXTproc(program, location, params);
}
void APIENTRY glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar* name){
	if(!GLM_struct->glBindFragDataLocationEXTproc) return;
	GLM_struct->glBindFragDataLocationEXTproc(program, color, name);
}
GLint APIENTRY glGetFragDataLocationEXT(GLuint program, const GLchar* name){
	if(!GLM_struct->glGetFragDataLocationEXTproc) return 0;
	return GLM_struct->glGetFragDataLocationEXTproc(program, name);
}
void APIENTRY glUniform1uiEXT(GLint location, GLuint v0){
	if(!GLM_struct->glUniform1uiEXTproc) return;
	GLM_struct->glUniform1uiEXTproc(location, v0);
}
void APIENTRY glUniform2uiEXT(GLint location, GLuint v0, GLuint v1){
	if(!GLM_struct->glUniform2uiEXTproc) return;
	GLM_struct->glUniform2uiEXTproc(location, v0, v1);
}
void APIENTRY glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2){
	if(!GLM_struct->glUniform3uiEXTproc) return;
	GLM_struct->glUniform3uiEXTproc(location, v0, v1, v2);
}
void APIENTRY glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3){
	if(!GLM_struct->glUniform4uiEXTproc) return;
	GLM_struct->glUniform4uiEXTproc(location, v0, v1, v2, v3);
}
void APIENTRY glUniform1uivEXT(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform1uivEXTproc) return;
	GLM_struct->glUniform1uivEXTproc(location, count, value);
}
void APIENTRY glUniform2uivEXT(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform2uivEXTproc) return;
	GLM_struct->glUniform2uivEXTproc(location, count, value);
}
void APIENTRY glUniform3uivEXT(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform3uivEXTproc) return;
	GLM_struct->glUniform3uivEXTproc(location, count, value);
}
void APIENTRY glUniform4uivEXT(GLint location, GLsizei count, const GLuint* value){
	if(!GLM_struct->glUniform4uivEXTproc) return;
	GLM_struct->glUniform4uivEXTproc(location, count, value);
}
void APIENTRY glVertexAttribI1iEXT(GLuint index, GLint x){
	if(!GLM_struct->glVertexAttribI1iEXTproc) return;
	GLM_struct->glVertexAttribI1iEXTproc(index, x);
}
void APIENTRY glVertexAttribI2iEXT(GLuint index, GLint x, GLint y){
	if(!GLM_struct->glVertexAttribI2iEXTproc) return;
	GLM_struct->glVertexAttribI2iEXTproc(index, x, y);
}
void APIENTRY glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z){
	if(!GLM_struct->glVertexAttribI3iEXTproc) return;
	GLM_struct->glVertexAttribI3iEXTproc(index, x, y, z);
}
void APIENTRY glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w){
	if(!GLM_struct->glVertexAttribI4iEXTproc) return;
	GLM_struct->glVertexAttribI4iEXTproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribI1uiEXT(GLuint index, GLuint x){
	if(!GLM_struct->glVertexAttribI1uiEXTproc) return;
	GLM_struct->glVertexAttribI1uiEXTproc(index, x);
}
void APIENTRY glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y){
	if(!GLM_struct->glVertexAttribI2uiEXTproc) return;
	GLM_struct->glVertexAttribI2uiEXTproc(index, x, y);
}
void APIENTRY glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z){
	if(!GLM_struct->glVertexAttribI3uiEXTproc) return;
	GLM_struct->glVertexAttribI3uiEXTproc(index, x, y, z);
}
void APIENTRY glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w){
	if(!GLM_struct->glVertexAttribI4uiEXTproc) return;
	GLM_struct->glVertexAttribI4uiEXTproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribI1ivEXT(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI1ivEXTproc) return;
	GLM_struct->glVertexAttribI1ivEXTproc(index, v);
}
void APIENTRY glVertexAttribI2ivEXT(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI2ivEXTproc) return;
	GLM_struct->glVertexAttribI2ivEXTproc(index, v);
}
void APIENTRY glVertexAttribI3ivEXT(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI3ivEXTproc) return;
	GLM_struct->glVertexAttribI3ivEXTproc(index, v);
}
void APIENTRY glVertexAttribI4ivEXT(GLuint index, const GLint* v){
	if(!GLM_struct->glVertexAttribI4ivEXTproc) return;
	GLM_struct->glVertexAttribI4ivEXTproc(index, v);
}
void APIENTRY glVertexAttribI1uivEXT(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI1uivEXTproc) return;
	GLM_struct->glVertexAttribI1uivEXTproc(index, v);
}
void APIENTRY glVertexAttribI2uivEXT(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI2uivEXTproc) return;
	GLM_struct->glVertexAttribI2uivEXTproc(index, v);
}
void APIENTRY glVertexAttribI3uivEXT(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI3uivEXTproc) return;
	GLM_struct->glVertexAttribI3uivEXTproc(index, v);
}
void APIENTRY glVertexAttribI4uivEXT(GLuint index, const GLuint* v){
	if(!GLM_struct->glVertexAttribI4uivEXTproc) return;
	GLM_struct->glVertexAttribI4uivEXTproc(index, v);
}
void APIENTRY glVertexAttribI4bvEXT(GLuint index, const GLbyte* v){
	if(!GLM_struct->glVertexAttribI4bvEXTproc) return;
	GLM_struct->glVertexAttribI4bvEXTproc(index, v);
}
void APIENTRY glVertexAttribI4svEXT(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttribI4svEXTproc) return;
	GLM_struct->glVertexAttribI4svEXTproc(index, v);
}
void APIENTRY glVertexAttribI4ubvEXT(GLuint index, const GLubyte* v){
	if(!GLM_struct->glVertexAttribI4ubvEXTproc) return;
	GLM_struct->glVertexAttribI4ubvEXTproc(index, v);
}
void APIENTRY glVertexAttribI4usvEXT(GLuint index, const GLushort* v){
	if(!GLM_struct->glVertexAttribI4usvEXTproc) return;
	GLM_struct->glVertexAttribI4usvEXTproc(index, v);
}
void APIENTRY glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexAttribIPointerEXTproc) return;
	GLM_struct->glVertexAttribIPointerEXTproc(index, size, type, stride, pointer);
}
void APIENTRY glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVertexAttribIivEXTproc) return;
	GLM_struct->glGetVertexAttribIivEXTproc(index, pname, params);
}
void APIENTRY glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetVertexAttribIuivEXTproc) return;
	GLM_struct->glGetVertexAttribIuivEXTproc(index, pname, params);
}
void APIENTRY glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values){
	if(!GLM_struct->glGetHistogramEXTproc) return;
	GLM_struct->glGetHistogramEXTproc(target, reset, format, type, values);
}
void APIENTRY glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetHistogramParameterfvEXTproc) return;
	GLM_struct->glGetHistogramParameterfvEXTproc(target, pname, params);
}
void APIENTRY glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetHistogramParameterivEXTproc) return;
	GLM_struct->glGetHistogramParameterivEXTproc(target, pname, params);
}
void APIENTRY glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void* values){
	if(!GLM_struct->glGetMinmaxEXTproc) return;
	GLM_struct->glGetMinmaxEXTproc(target, reset, format, type, values);
}
void APIENTRY glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMinmaxParameterfvEXTproc) return;
	GLM_struct->glGetMinmaxParameterfvEXTproc(target, pname, params);
}
void APIENTRY glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMinmaxParameterivEXTproc) return;
	GLM_struct->glGetMinmaxParameterivEXTproc(target, pname, params);
}
void APIENTRY glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink){
	if(!GLM_struct->glHistogramEXTproc) return;
	GLM_struct->glHistogramEXTproc(target, width, internalformat, sink);
}
void APIENTRY glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink){
	if(!GLM_struct->glMinmaxEXTproc) return;
	GLM_struct->glMinmaxEXTproc(target, internalformat, sink);
}
void APIENTRY glResetHistogramEXT(GLenum target){
	if(!GLM_struct->glResetHistogramEXTproc) return;
	GLM_struct->glResetHistogramEXTproc(target);
}
void APIENTRY glResetMinmaxEXT(GLenum target){
	if(!GLM_struct->glResetMinmaxEXTproc) return;
	GLM_struct->glResetMinmaxEXTproc(target);
}
void APIENTRY glIndexFuncEXT(GLenum func, GLclampf ref){
	if(!GLM_struct->glIndexFuncEXTproc) return;
	GLM_struct->glIndexFuncEXTproc(func, ref);
}
void APIENTRY glIndexMaterialEXT(GLenum face, GLenum mode){
	if(!GLM_struct->glIndexMaterialEXTproc) return;
	GLM_struct->glIndexMaterialEXTproc(face, mode);
}
void APIENTRY glApplyTextureEXT(GLenum mode){
	if(!GLM_struct->glApplyTextureEXTproc) return;
	GLM_struct->glApplyTextureEXTproc(mode);
}
void APIENTRY glTextureLightEXT(GLenum pname){
	if(!GLM_struct->glTextureLightEXTproc) return;
	GLM_struct->glTextureLightEXTproc(pname);
}
void APIENTRY glTextureMaterialEXT(GLenum face, GLenum mode){
	if(!GLM_struct->glTextureMaterialEXTproc) return;
	GLM_struct->glTextureMaterialEXTproc(face, mode);
}
void APIENTRY glGetUnsignedBytevEXT(GLenum pname, GLubyte* data){
	if(!GLM_struct->glGetUnsignedBytevEXTproc) return;
	GLM_struct->glGetUnsignedBytevEXTproc(pname, data);
}
void APIENTRY glGetUnsignedBytei_vEXT(GLenum target, GLuint index, GLubyte* data){
	if(!GLM_struct->glGetUnsignedBytei_vEXTproc) return;
	GLM_struct->glGetUnsignedBytei_vEXTproc(target, index, data);
}
void APIENTRY glDeleteMemoryObjectsEXT(GLsizei n, const GLuint* memoryObjects){
	if(!GLM_struct->glDeleteMemoryObjectsEXTproc) return;
	GLM_struct->glDeleteMemoryObjectsEXTproc(n, memoryObjects);
}
GLboolean APIENTRY glIsMemoryObjectEXT(GLuint memoryObject){
	if(!GLM_struct->glIsMemoryObjectEXTproc) return 0;
	return GLM_struct->glIsMemoryObjectEXTproc(memoryObject);
}
void APIENTRY glCreateMemoryObjectsEXT(GLsizei n, GLuint* memoryObjects){
	if(!GLM_struct->glCreateMemoryObjectsEXTproc) return;
	GLM_struct->glCreateMemoryObjectsEXTproc(n, memoryObjects);
}
void APIENTRY glMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, const GLint* params){
	if(!GLM_struct->glMemoryObjectParameterivEXTproc) return;
	GLM_struct->glMemoryObjectParameterivEXTproc(memoryObject, pname, params);
}
void APIENTRY glGetMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMemoryObjectParameterivEXTproc) return;
	GLM_struct->glGetMemoryObjectParameterivEXTproc(memoryObject, pname, params);
}
void APIENTRY glTexStorageMem2DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTexStorageMem2DEXTproc) return;
	GLM_struct->glTexStorageMem2DEXTproc(target, levels, internalFormat, width, height, memory, offset);
}
void APIENTRY glTexStorageMem2DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTexStorageMem2DMultisampleEXTproc) return;
	GLM_struct->glTexStorageMem2DMultisampleEXTproc(target, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
void APIENTRY glTexStorageMem3DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTexStorageMem3DEXTproc) return;
	GLM_struct->glTexStorageMem3DEXTproc(target, levels, internalFormat, width, height, depth, memory, offset);
}
void APIENTRY glTexStorageMem3DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTexStorageMem3DMultisampleEXTproc) return;
	GLM_struct->glTexStorageMem3DMultisampleEXTproc(target, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
void APIENTRY glBufferStorageMemEXT(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glBufferStorageMemEXTproc) return;
	GLM_struct->glBufferStorageMemEXTproc(target, size, memory, offset);
}
void APIENTRY glTextureStorageMem2DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTextureStorageMem2DEXTproc) return;
	GLM_struct->glTextureStorageMem2DEXTproc(texture, levels, internalFormat, width, height, memory, offset);
}
void APIENTRY glTextureStorageMem2DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTextureStorageMem2DMultisampleEXTproc) return;
	GLM_struct->glTextureStorageMem2DMultisampleEXTproc(texture, samples, internalFormat, width, height, fixedSampleLocations, memory, offset);
}
void APIENTRY glTextureStorageMem3DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTextureStorageMem3DEXTproc) return;
	GLM_struct->glTextureStorageMem3DEXTproc(texture, levels, internalFormat, width, height, depth, memory, offset);
}
void APIENTRY glTextureStorageMem3DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTextureStorageMem3DMultisampleEXTproc) return;
	GLM_struct->glTextureStorageMem3DMultisampleEXTproc(texture, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset);
}
void APIENTRY glNamedBufferStorageMemEXT(GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glNamedBufferStorageMemEXTproc) return;
	GLM_struct->glNamedBufferStorageMemEXTproc(buffer, size, memory, offset);
}
void APIENTRY glTexStorageMem1DEXT(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTexStorageMem1DEXTproc) return;
	GLM_struct->glTexStorageMem1DEXTproc(target, levels, internalFormat, width, memory, offset);
}
void APIENTRY glTextureStorageMem1DEXT(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTextureStorageMem1DEXTproc) return;
	GLM_struct->glTextureStorageMem1DEXTproc(texture, levels, internalFormat, width, memory, offset);
}
void APIENTRY glImportMemoryFdEXT(GLuint memory, GLuint64 size, GLenum handleType, GLint fd){
	if(!GLM_struct->glImportMemoryFdEXTproc) return;
	GLM_struct->glImportMemoryFdEXTproc(memory, size, handleType, fd);
}
void APIENTRY glImportMemoryWin32HandleEXT(GLuint memory, GLuint64 size, GLenum handleType, void* handle){
	if(!GLM_struct->glImportMemoryWin32HandleEXTproc) return;
	GLM_struct->glImportMemoryWin32HandleEXTproc(memory, size, handleType, handle);
}
void APIENTRY glImportMemoryWin32NameEXT(GLuint memory, GLuint64 size, GLenum handleType, const void* name){
	if(!GLM_struct->glImportMemoryWin32NameEXTproc) return;
	GLM_struct->glImportMemoryWin32NameEXTproc(memory, size, handleType, name);
}
void APIENTRY glMultiDrawArraysEXT(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount){
	if(!GLM_struct->glMultiDrawArraysEXTproc) return;
	GLM_struct->glMultiDrawArraysEXTproc(mode, first, count, primcount);
}
void APIENTRY glMultiDrawElementsEXT(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei primcount){
	if(!GLM_struct->glMultiDrawElementsEXTproc) return;
	GLM_struct->glMultiDrawElementsEXTproc(mode, count, type, indices, primcount);
}
void APIENTRY glSampleMaskEXT(GLclampf value, GLboolean invert){
	if(!GLM_struct->glSampleMaskEXTproc) return;
	GLM_struct->glSampleMaskEXTproc(value, invert);
}
void APIENTRY glSamplePatternEXT(GLenum pattern){
	if(!GLM_struct->glSamplePatternEXTproc) return;
	GLM_struct->glSamplePatternEXTproc(pattern);
}
void APIENTRY glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void* table){
	if(!GLM_struct->glColorTableEXTproc) return;
	GLM_struct->glColorTableEXTproc(target, internalFormat, width, format, type, table);
}
void APIENTRY glGetColorTableEXT(GLenum target, GLenum format, GLenum type, void* data){
	if(!GLM_struct->glGetColorTableEXTproc) return;
	GLM_struct->glGetColorTableEXTproc(target, format, type, data);
}
void APIENTRY glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetColorTableParameterivEXTproc) return;
	GLM_struct->glGetColorTableParameterivEXTproc(target, pname, params);
}
void APIENTRY glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetColorTableParameterfvEXTproc) return;
	GLM_struct->glGetColorTableParameterfvEXTproc(target, pname, params);
}
void APIENTRY glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glPixelTransformParameteriEXTproc) return;
	GLM_struct->glPixelTransformParameteriEXTproc(target, pname, param);
}
void APIENTRY glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param){
	if(!GLM_struct->glPixelTransformParameterfEXTproc) return;
	GLM_struct->glPixelTransformParameterfEXTproc(target, pname, param);
}
void APIENTRY glPixelTransformParameterivEXT(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glPixelTransformParameterivEXTproc) return;
	GLM_struct->glPixelTransformParameterivEXTproc(target, pname, params);
}
void APIENTRY glPixelTransformParameterfvEXT(GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glPixelTransformParameterfvEXTproc) return;
	GLM_struct->glPixelTransformParameterfvEXTproc(target, pname, params);
}
void APIENTRY glGetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetPixelTransformParameterivEXTproc) return;
	GLM_struct->glGetPixelTransformParameterivEXTproc(target, pname, params);
}
void APIENTRY glGetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetPixelTransformParameterfvEXTproc) return;
	GLM_struct->glGetPixelTransformParameterfvEXTproc(target, pname, params);
}
void APIENTRY glPointParameterfEXT(GLenum pname, GLfloat param){
	if(!GLM_struct->glPointParameterfEXTproc) return;
	GLM_struct->glPointParameterfEXTproc(pname, param);
}
void APIENTRY glPointParameterfvEXT(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glPointParameterfvEXTproc) return;
	GLM_struct->glPointParameterfvEXTproc(pname, params);
}
void APIENTRY glPolygonOffsetEXT(GLfloat factor, GLfloat bias){
	if(!GLM_struct->glPolygonOffsetEXTproc) return;
	GLM_struct->glPolygonOffsetEXTproc(factor, bias);
}
void APIENTRY glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp){
	if(!GLM_struct->glPolygonOffsetClampEXTproc) return;
	GLM_struct->glPolygonOffsetClampEXTproc(factor, units, clamp);
}
void APIENTRY glProvokingVertexEXT(GLenum mode){
	if(!GLM_struct->glProvokingVertexEXTproc) return;
	GLM_struct->glProvokingVertexEXTproc(mode);
}
void APIENTRY glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations){
	if(!GLM_struct->glRasterSamplesEXTproc) return;
	GLM_struct->glRasterSamplesEXTproc(samples, fixedsamplelocations);
}
void APIENTRY glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue){
	if(!GLM_struct->glSecondaryColor3bEXTproc) return;
	GLM_struct->glSecondaryColor3bEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3bvEXT(const GLbyte* v){
	if(!GLM_struct->glSecondaryColor3bvEXTproc) return;
	GLM_struct->glSecondaryColor3bvEXTproc(v);
}
void APIENTRY glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue){
	if(!GLM_struct->glSecondaryColor3dEXTproc) return;
	GLM_struct->glSecondaryColor3dEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3dvEXT(const GLdouble* v){
	if(!GLM_struct->glSecondaryColor3dvEXTproc) return;
	GLM_struct->glSecondaryColor3dvEXTproc(v);
}
void APIENTRY glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue){
	if(!GLM_struct->glSecondaryColor3fEXTproc) return;
	GLM_struct->glSecondaryColor3fEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3fvEXT(const GLfloat* v){
	if(!GLM_struct->glSecondaryColor3fvEXTproc) return;
	GLM_struct->glSecondaryColor3fvEXTproc(v);
}
void APIENTRY glSecondaryColor3iEXT(GLint red, GLint green, GLint blue){
	if(!GLM_struct->glSecondaryColor3iEXTproc) return;
	GLM_struct->glSecondaryColor3iEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3ivEXT(const GLint* v){
	if(!GLM_struct->glSecondaryColor3ivEXTproc) return;
	GLM_struct->glSecondaryColor3ivEXTproc(v);
}
void APIENTRY glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue){
	if(!GLM_struct->glSecondaryColor3sEXTproc) return;
	GLM_struct->glSecondaryColor3sEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3svEXT(const GLshort* v){
	if(!GLM_struct->glSecondaryColor3svEXTproc) return;
	GLM_struct->glSecondaryColor3svEXTproc(v);
}
void APIENTRY glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue){
	if(!GLM_struct->glSecondaryColor3ubEXTproc) return;
	GLM_struct->glSecondaryColor3ubEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3ubvEXT(const GLubyte* v){
	if(!GLM_struct->glSecondaryColor3ubvEXTproc) return;
	GLM_struct->glSecondaryColor3ubvEXTproc(v);
}
void APIENTRY glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue){
	if(!GLM_struct->glSecondaryColor3uiEXTproc) return;
	GLM_struct->glSecondaryColor3uiEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3uivEXT(const GLuint* v){
	if(!GLM_struct->glSecondaryColor3uivEXTproc) return;
	GLM_struct->glSecondaryColor3uivEXTproc(v);
}
void APIENTRY glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue){
	if(!GLM_struct->glSecondaryColor3usEXTproc) return;
	GLM_struct->glSecondaryColor3usEXTproc(red, green, blue);
}
void APIENTRY glSecondaryColor3usvEXT(const GLushort* v){
	if(!GLM_struct->glSecondaryColor3usvEXTproc) return;
	GLM_struct->glSecondaryColor3usvEXTproc(v);
}
void APIENTRY glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glSecondaryColorPointerEXTproc) return;
	GLM_struct->glSecondaryColorPointerEXTproc(size, type, stride, pointer);
}
void APIENTRY glGenSemaphoresEXT(GLsizei n, GLuint* semaphores){
	if(!GLM_struct->glGenSemaphoresEXTproc) return;
	GLM_struct->glGenSemaphoresEXTproc(n, semaphores);
}
void APIENTRY glDeleteSemaphoresEXT(GLsizei n, const GLuint* semaphores){
	if(!GLM_struct->glDeleteSemaphoresEXTproc) return;
	GLM_struct->glDeleteSemaphoresEXTproc(n, semaphores);
}
GLboolean APIENTRY glIsSemaphoreEXT(GLuint semaphore){
	if(!GLM_struct->glIsSemaphoreEXTproc) return 0;
	return GLM_struct->glIsSemaphoreEXTproc(semaphore);
}
void APIENTRY glSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, const GLuint64* params){
	if(!GLM_struct->glSemaphoreParameterui64vEXTproc) return;
	GLM_struct->glSemaphoreParameterui64vEXTproc(semaphore, pname, params);
}
void APIENTRY glGetSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64* params){
	if(!GLM_struct->glGetSemaphoreParameterui64vEXTproc) return;
	GLM_struct->glGetSemaphoreParameterui64vEXTproc(semaphore, pname, params);
}
void APIENTRY glWaitSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* srcLayouts){
	if(!GLM_struct->glWaitSemaphoreEXTproc) return;
	GLM_struct->glWaitSemaphoreEXTproc(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts);
}
void APIENTRY glSignalSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* dstLayouts){
	if(!GLM_struct->glSignalSemaphoreEXTproc) return;
	GLM_struct->glSignalSemaphoreEXTproc(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts);
}
void APIENTRY glImportSemaphoreFdEXT(GLuint semaphore, GLenum handleType, GLint fd){
	if(!GLM_struct->glImportSemaphoreFdEXTproc) return;
	GLM_struct->glImportSemaphoreFdEXTproc(semaphore, handleType, fd);
}
void APIENTRY glImportSemaphoreWin32HandleEXT(GLuint semaphore, GLenum handleType, void* handle){
	if(!GLM_struct->glImportSemaphoreWin32HandleEXTproc) return;
	GLM_struct->glImportSemaphoreWin32HandleEXTproc(semaphore, handleType, handle);
}
void APIENTRY glImportSemaphoreWin32NameEXT(GLuint semaphore, GLenum handleType, const void* name){
	if(!GLM_struct->glImportSemaphoreWin32NameEXTproc) return;
	GLM_struct->glImportSemaphoreWin32NameEXTproc(semaphore, handleType, name);
}
void APIENTRY glUseShaderProgramEXT(GLenum type, GLuint program){
	if(!GLM_struct->glUseShaderProgramEXTproc) return;
	GLM_struct->glUseShaderProgramEXTproc(type, program);
}
void APIENTRY glActiveProgramEXT(GLuint program){
	if(!GLM_struct->glActiveProgramEXTproc) return;
	GLM_struct->glActiveProgramEXTproc(program);
}
GLuint APIENTRY glCreateShaderProgramEXT(GLenum type, const GLchar* string){
	if(!GLM_struct->glCreateShaderProgramEXTproc) return 0;
	return GLM_struct->glCreateShaderProgramEXTproc(type, string);
}
void APIENTRY glFramebufferFetchBarrierEXT(void){
	if(!GLM_struct->glFramebufferFetchBarrierEXTproc) return;
	GLM_struct->glFramebufferFetchBarrierEXTproc();
}
void APIENTRY glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format){
	if(!GLM_struct->glBindImageTextureEXTproc) return;
	GLM_struct->glBindImageTextureEXTproc(index, texture, level, layered, layer, access, format);
}
void APIENTRY glMemoryBarrierEXT(GLbitfield barriers){
	if(!GLM_struct->glMemoryBarrierEXTproc) return;
	GLM_struct->glMemoryBarrierEXTproc(barriers);
}
void APIENTRY glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag){
	if(!GLM_struct->glStencilClearTagEXTproc) return;
	GLM_struct->glStencilClearTagEXTproc(stencilTagBits, stencilClearTag);
}
void APIENTRY glActiveStencilFaceEXT(GLenum face){
	if(!GLM_struct->glActiveStencilFaceEXTproc) return;
	GLM_struct->glActiveStencilFaceEXTproc(face);
}
void APIENTRY glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexSubImage1DEXTproc) return;
	GLM_struct->glTexSubImage1DEXTproc(target, level, xoffset, width, format, type, pixels);
}
void APIENTRY glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexSubImage2DEXTproc) return;
	GLM_struct->glTexSubImage2DEXTproc(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void APIENTRY glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexImage3DEXTproc) return;
	GLM_struct->glTexImage3DEXTproc(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void APIENTRY glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexSubImage3DEXTproc) return;
	GLM_struct->glTexSubImage3DEXTproc(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void APIENTRY glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer){
	if(!GLM_struct->glFramebufferTextureLayerEXTproc) return;
	GLM_struct->glFramebufferTextureLayerEXTproc(target, attachment, texture, level, layer);
}
void APIENTRY glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer){
	if(!GLM_struct->glTexBufferEXTproc) return;
	GLM_struct->glTexBufferEXTproc(target, internalformat, buffer);
}
void APIENTRY glTexParameterIivEXT(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glTexParameterIivEXTproc) return;
	GLM_struct->glTexParameterIivEXTproc(target, pname, params);
}
void APIENTRY glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint* params){
	if(!GLM_struct->glTexParameterIuivEXTproc) return;
	GLM_struct->glTexParameterIuivEXTproc(target, pname, params);
}
void APIENTRY glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTexParameterIivEXTproc) return;
	GLM_struct->glGetTexParameterIivEXTproc(target, pname, params);
}
void APIENTRY glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetTexParameterIuivEXTproc) return;
	GLM_struct->glGetTexParameterIuivEXTproc(target, pname, params);
}
void APIENTRY glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha){
	if(!GLM_struct->glClearColorIiEXTproc) return;
	GLM_struct->glClearColorIiEXTproc(red, green, blue, alpha);
}
void APIENTRY glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha){
	if(!GLM_struct->glClearColorIuiEXTproc) return;
	GLM_struct->glClearColorIuiEXTproc(red, green, blue, alpha);
}
GLboolean APIENTRY glAreTexturesResidentEXT(GLsizei n, const GLuint* textures, GLboolean* residences){
	if(!GLM_struct->glAreTexturesResidentEXTproc) return 0;
	return GLM_struct->glAreTexturesResidentEXTproc(n, textures, residences);
}
void APIENTRY glBindTextureEXT(GLenum target, GLuint texture){
	if(!GLM_struct->glBindTextureEXTproc) return;
	GLM_struct->glBindTextureEXTproc(target, texture);
}
void APIENTRY glDeleteTexturesEXT(GLsizei n, const GLuint* textures){
	if(!GLM_struct->glDeleteTexturesEXTproc) return;
	GLM_struct->glDeleteTexturesEXTproc(n, textures);
}
void APIENTRY glGenTexturesEXT(GLsizei n, GLuint* textures){
	if(!GLM_struct->glGenTexturesEXTproc) return;
	GLM_struct->glGenTexturesEXTproc(n, textures);
}
GLboolean APIENTRY glIsTextureEXT(GLuint texture){
	if(!GLM_struct->glIsTextureEXTproc) return 0;
	return GLM_struct->glIsTextureEXTproc(texture);
}
void APIENTRY glPrioritizeTexturesEXT(GLsizei n, const GLuint* textures, const GLclampf* priorities){
	if(!GLM_struct->glPrioritizeTexturesEXTproc) return;
	GLM_struct->glPrioritizeTexturesEXTproc(n, textures, priorities);
}
void APIENTRY glTextureNormalEXT(GLenum mode){
	if(!GLM_struct->glTextureNormalEXTproc) return;
	GLM_struct->glTextureNormalEXTproc(mode);
}
void APIENTRY glTexStorage1DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width){
	if(!GLM_struct->glTexStorage1DEXTproc) return;
	GLM_struct->glTexStorage1DEXTproc(target, levels, internalformat, width);
}
void APIENTRY glTexStorage2DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glTexStorage2DEXTproc) return;
	GLM_struct->glTexStorage2DEXTproc(target, levels, internalformat, width, height);
}
void APIENTRY glTexStorage3DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->glTexStorage3DEXTproc) return;
	GLM_struct->glTexStorage3DEXTproc(target, levels, internalformat, width, height, depth);
}
void APIENTRY glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64* params){
	if(!GLM_struct->glGetQueryObjecti64vEXTproc) return;
	GLM_struct->glGetQueryObjecti64vEXTproc(id, pname, params);
}
void APIENTRY glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64* params){
	if(!GLM_struct->glGetQueryObjectui64vEXTproc) return;
	GLM_struct->glGetQueryObjectui64vEXTproc(id, pname, params);
}
void APIENTRY glBeginTransformFeedbackEXT(GLenum primitiveMode){
	if(!GLM_struct->glBeginTransformFeedbackEXTproc) return;
	GLM_struct->glBeginTransformFeedbackEXTproc(primitiveMode);
}
void APIENTRY glEndTransformFeedbackEXT(void){
	if(!GLM_struct->glEndTransformFeedbackEXTproc) return;
	GLM_struct->glEndTransformFeedbackEXTproc();
}
void APIENTRY glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glBindBufferRangeEXTproc) return;
	GLM_struct->glBindBufferRangeEXTproc(target, index, buffer, offset, size);
}
void APIENTRY glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset){
	if(!GLM_struct->glBindBufferOffsetEXTproc) return;
	GLM_struct->glBindBufferOffsetEXTproc(target, index, buffer, offset);
}
void APIENTRY glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer){
	if(!GLM_struct->glBindBufferBaseEXTproc) return;
	GLM_struct->glBindBufferBaseEXTproc(target, index, buffer);
}
void APIENTRY glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode){
	if(!GLM_struct->glTransformFeedbackVaryingsEXTproc) return;
	GLM_struct->glTransformFeedbackVaryingsEXTproc(program, count, varyings, bufferMode);
}
void APIENTRY glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name){
	if(!GLM_struct->glGetTransformFeedbackVaryingEXTproc) return;
	GLM_struct->glGetTransformFeedbackVaryingEXTproc(program, index, bufSize, length, size, type, name);
}
void APIENTRY glArrayElementEXT(GLint i){
	if(!GLM_struct->glArrayElementEXTproc) return;
	GLM_struct->glArrayElementEXTproc(i);
}
void APIENTRY glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void* pointer){
	if(!GLM_struct->glColorPointerEXTproc) return;
	GLM_struct->glColorPointerEXTproc(size, type, stride, count, pointer);
}
void APIENTRY glDrawArraysEXT(GLenum mode, GLint first, GLsizei count){
	if(!GLM_struct->glDrawArraysEXTproc) return;
	GLM_struct->glDrawArraysEXTproc(mode, first, count);
}
void APIENTRY glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean* pointer){
	if(!GLM_struct->glEdgeFlagPointerEXTproc) return;
	GLM_struct->glEdgeFlagPointerEXTproc(stride, count, pointer);
}
void APIENTRY glGetPointervEXT(GLenum pname, void** params){
	if(!GLM_struct->glGetPointervEXTproc) return;
	GLM_struct->glGetPointervEXTproc(pname, params);
}
void APIENTRY glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void* pointer){
	if(!GLM_struct->glIndexPointerEXTproc) return;
	GLM_struct->glIndexPointerEXTproc(type, stride, count, pointer);
}
void APIENTRY glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void* pointer){
	if(!GLM_struct->glNormalPointerEXTproc) return;
	GLM_struct->glNormalPointerEXTproc(type, stride, count, pointer);
}
void APIENTRY glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void* pointer){
	if(!GLM_struct->glTexCoordPointerEXTproc) return;
	GLM_struct->glTexCoordPointerEXTproc(size, type, stride, count, pointer);
}
void APIENTRY glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void* pointer){
	if(!GLM_struct->glVertexPointerEXTproc) return;
	GLM_struct->glVertexPointerEXTproc(size, type, stride, count, pointer);
}
void APIENTRY glVertexAttribL1dEXT(GLuint index, GLdouble x){
	if(!GLM_struct->glVertexAttribL1dEXTproc) return;
	GLM_struct->glVertexAttribL1dEXTproc(index, x);
}
void APIENTRY glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y){
	if(!GLM_struct->glVertexAttribL2dEXTproc) return;
	GLM_struct->glVertexAttribL2dEXTproc(index, x, y);
}
void APIENTRY glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glVertexAttribL3dEXTproc) return;
	GLM_struct->glVertexAttribL3dEXTproc(index, x, y, z);
}
void APIENTRY glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glVertexAttribL4dEXTproc) return;
	GLM_struct->glVertexAttribL4dEXTproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribL1dvEXT(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL1dvEXTproc) return;
	GLM_struct->glVertexAttribL1dvEXTproc(index, v);
}
void APIENTRY glVertexAttribL2dvEXT(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL2dvEXTproc) return;
	GLM_struct->glVertexAttribL2dvEXTproc(index, v);
}
void APIENTRY glVertexAttribL3dvEXT(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL3dvEXTproc) return;
	GLM_struct->glVertexAttribL3dvEXTproc(index, v);
}
void APIENTRY glVertexAttribL4dvEXT(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttribL4dvEXTproc) return;
	GLM_struct->glVertexAttribL4dvEXTproc(index, v);
}
void APIENTRY glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexAttribLPointerEXTproc) return;
	GLM_struct->glVertexAttribLPointerEXTproc(index, size, type, stride, pointer);
}
void APIENTRY glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetVertexAttribLdvEXTproc) return;
	GLM_struct->glGetVertexAttribLdvEXTproc(index, pname, params);
}
void APIENTRY glBeginVertexShaderEXT(void){
	if(!GLM_struct->glBeginVertexShaderEXTproc) return;
	GLM_struct->glBeginVertexShaderEXTproc();
}
void APIENTRY glEndVertexShaderEXT(void){
	if(!GLM_struct->glEndVertexShaderEXTproc) return;
	GLM_struct->glEndVertexShaderEXTproc();
}
void APIENTRY glBindVertexShaderEXT(GLuint id){
	if(!GLM_struct->glBindVertexShaderEXTproc) return;
	GLM_struct->glBindVertexShaderEXTproc(id);
}
GLuint APIENTRY glGenVertexShadersEXT(GLuint range){
	if(!GLM_struct->glGenVertexShadersEXTproc) return 0;
	return GLM_struct->glGenVertexShadersEXTproc(range);
}
void APIENTRY glDeleteVertexShaderEXT(GLuint id){
	if(!GLM_struct->glDeleteVertexShaderEXTproc) return;
	GLM_struct->glDeleteVertexShaderEXTproc(id);
}
void APIENTRY glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1){
	if(!GLM_struct->glShaderOp1EXTproc) return;
	GLM_struct->glShaderOp1EXTproc(op, res, arg1);
}
void APIENTRY glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2){
	if(!GLM_struct->glShaderOp2EXTproc) return;
	GLM_struct->glShaderOp2EXTproc(op, res, arg1, arg2);
}
void APIENTRY glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3){
	if(!GLM_struct->glShaderOp3EXTproc) return;
	GLM_struct->glShaderOp3EXTproc(op, res, arg1, arg2, arg3);
}
void APIENTRY glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW){
	if(!GLM_struct->glSwizzleEXTproc) return;
	GLM_struct->glSwizzleEXTproc(res, in, outX, outY, outZ, outW);
}
void APIENTRY glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW){
	if(!GLM_struct->glWriteMaskEXTproc) return;
	GLM_struct->glWriteMaskEXTproc(res, in, outX, outY, outZ, outW);
}
void APIENTRY glInsertComponentEXT(GLuint res, GLuint src, GLuint num){
	if(!GLM_struct->glInsertComponentEXTproc) return;
	GLM_struct->glInsertComponentEXTproc(res, src, num);
}
void APIENTRY glExtractComponentEXT(GLuint res, GLuint src, GLuint num){
	if(!GLM_struct->glExtractComponentEXTproc) return;
	GLM_struct->glExtractComponentEXTproc(res, src, num);
}
GLuint APIENTRY glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components){
	if(!GLM_struct->glGenSymbolsEXTproc) return 0;
	return GLM_struct->glGenSymbolsEXTproc(datatype, storagetype, range, components);
}
void APIENTRY glSetInvariantEXT(GLuint id, GLenum type, const void* addr){
	if(!GLM_struct->glSetInvariantEXTproc) return;
	GLM_struct->glSetInvariantEXTproc(id, type, addr);
}
void APIENTRY glSetLocalConstantEXT(GLuint id, GLenum type, const void* addr){
	if(!GLM_struct->glSetLocalConstantEXTproc) return;
	GLM_struct->glSetLocalConstantEXTproc(id, type, addr);
}
void APIENTRY glVariantbvEXT(GLuint id, const GLbyte* addr){
	if(!GLM_struct->glVariantbvEXTproc) return;
	GLM_struct->glVariantbvEXTproc(id, addr);
}
void APIENTRY glVariantsvEXT(GLuint id, const GLshort* addr){
	if(!GLM_struct->glVariantsvEXTproc) return;
	GLM_struct->glVariantsvEXTproc(id, addr);
}
void APIENTRY glVariantivEXT(GLuint id, const GLint* addr){
	if(!GLM_struct->glVariantivEXTproc) return;
	GLM_struct->glVariantivEXTproc(id, addr);
}
void APIENTRY glVariantfvEXT(GLuint id, const GLfloat* addr){
	if(!GLM_struct->glVariantfvEXTproc) return;
	GLM_struct->glVariantfvEXTproc(id, addr);
}
void APIENTRY glVariantdvEXT(GLuint id, const GLdouble* addr){
	if(!GLM_struct->glVariantdvEXTproc) return;
	GLM_struct->glVariantdvEXTproc(id, addr);
}
void APIENTRY glVariantubvEXT(GLuint id, const GLubyte* addr){
	if(!GLM_struct->glVariantubvEXTproc) return;
	GLM_struct->glVariantubvEXTproc(id, addr);
}
void APIENTRY glVariantusvEXT(GLuint id, const GLushort* addr){
	if(!GLM_struct->glVariantusvEXTproc) return;
	GLM_struct->glVariantusvEXTproc(id, addr);
}
void APIENTRY glVariantuivEXT(GLuint id, const GLuint* addr){
	if(!GLM_struct->glVariantuivEXTproc) return;
	GLM_struct->glVariantuivEXTproc(id, addr);
}
void APIENTRY glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, const void* addr){
	if(!GLM_struct->glVariantPointerEXTproc) return;
	GLM_struct->glVariantPointerEXTproc(id, type, stride, addr);
}
void APIENTRY glEnableVariantClientStateEXT(GLuint id){
	if(!GLM_struct->glEnableVariantClientStateEXTproc) return;
	GLM_struct->glEnableVariantClientStateEXTproc(id);
}
void APIENTRY glDisableVariantClientStateEXT(GLuint id){
	if(!GLM_struct->glDisableVariantClientStateEXTproc) return;
	GLM_struct->glDisableVariantClientStateEXTproc(id);
}
GLuint APIENTRY glBindLightParameterEXT(GLenum light, GLenum value){
	if(!GLM_struct->glBindLightParameterEXTproc) return 0;
	return GLM_struct->glBindLightParameterEXTproc(light, value);
}
GLuint APIENTRY glBindMaterialParameterEXT(GLenum face, GLenum value){
	if(!GLM_struct->glBindMaterialParameterEXTproc) return 0;
	return GLM_struct->glBindMaterialParameterEXTproc(face, value);
}
GLuint APIENTRY glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value){
	if(!GLM_struct->glBindTexGenParameterEXTproc) return 0;
	return GLM_struct->glBindTexGenParameterEXTproc(unit, coord, value);
}
GLuint APIENTRY glBindTextureUnitParameterEXT(GLenum unit, GLenum value){
	if(!GLM_struct->glBindTextureUnitParameterEXTproc) return 0;
	return GLM_struct->glBindTextureUnitParameterEXTproc(unit, value);
}
GLuint APIENTRY glBindParameterEXT(GLenum value){
	if(!GLM_struct->glBindParameterEXTproc) return 0;
	return GLM_struct->glBindParameterEXTproc(value);
}
GLboolean APIENTRY glIsVariantEnabledEXT(GLuint id, GLenum cap){
	if(!GLM_struct->glIsVariantEnabledEXTproc) return 0;
	return GLM_struct->glIsVariantEnabledEXTproc(id, cap);
}
void APIENTRY glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data){
	if(!GLM_struct->glGetVariantBooleanvEXTproc) return;
	GLM_struct->glGetVariantBooleanvEXTproc(id, value, data);
}
void APIENTRY glGetVariantIntegervEXT(GLuint id, GLenum value, GLint* data){
	if(!GLM_struct->glGetVariantIntegervEXTproc) return;
	GLM_struct->glGetVariantIntegervEXTproc(id, value, data);
}
void APIENTRY glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat* data){
	if(!GLM_struct->glGetVariantFloatvEXTproc) return;
	GLM_struct->glGetVariantFloatvEXTproc(id, value, data);
}
void APIENTRY glGetVariantPointervEXT(GLuint id, GLenum value, void** data){
	if(!GLM_struct->glGetVariantPointervEXTproc) return;
	GLM_struct->glGetVariantPointervEXTproc(id, value, data);
}
void APIENTRY glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data){
	if(!GLM_struct->glGetInvariantBooleanvEXTproc) return;
	GLM_struct->glGetInvariantBooleanvEXTproc(id, value, data);
}
void APIENTRY glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint* data){
	if(!GLM_struct->glGetInvariantIntegervEXTproc) return;
	GLM_struct->glGetInvariantIntegervEXTproc(id, value, data);
}
void APIENTRY glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat* data){
	if(!GLM_struct->glGetInvariantFloatvEXTproc) return;
	GLM_struct->glGetInvariantFloatvEXTproc(id, value, data);
}
void APIENTRY glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean* data){
	if(!GLM_struct->glGetLocalConstantBooleanvEXTproc) return;
	GLM_struct->glGetLocalConstantBooleanvEXTproc(id, value, data);
}
void APIENTRY glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint* data){
	if(!GLM_struct->glGetLocalConstantIntegervEXTproc) return;
	GLM_struct->glGetLocalConstantIntegervEXTproc(id, value, data);
}
void APIENTRY glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat* data){
	if(!GLM_struct->glGetLocalConstantFloatvEXTproc) return;
	GLM_struct->glGetLocalConstantFloatvEXTproc(id, value, data);
}
void APIENTRY glVertexWeightfEXT(GLfloat weight){
	if(!GLM_struct->glVertexWeightfEXTproc) return;
	GLM_struct->glVertexWeightfEXTproc(weight);
}
void APIENTRY glVertexWeightfvEXT(const GLfloat* weight){
	if(!GLM_struct->glVertexWeightfvEXTproc) return;
	GLM_struct->glVertexWeightfvEXTproc(weight);
}
void APIENTRY glVertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexWeightPointerEXTproc) return;
	GLM_struct->glVertexWeightPointerEXTproc(size, type, stride, pointer);
}
GLboolean APIENTRY glAcquireKeyedMutexWin32EXT(GLuint memory, GLuint64 key, GLuint timeout){
	if(!GLM_struct->glAcquireKeyedMutexWin32EXTproc) return 0;
	return GLM_struct->glAcquireKeyedMutexWin32EXTproc(memory, key, timeout);
}
GLboolean APIENTRY glReleaseKeyedMutexWin32EXT(GLuint memory, GLuint64 key){
	if(!GLM_struct->glReleaseKeyedMutexWin32EXTproc) return 0;
	return GLM_struct->glReleaseKeyedMutexWin32EXTproc(memory, key);
}
void APIENTRY glWindowRectanglesEXT(GLenum mode, GLsizei count, const GLint* box){
	if(!GLM_struct->glWindowRectanglesEXTproc) return;
	GLM_struct->glWindowRectanglesEXTproc(mode, count, box);
}
GLsync APIENTRY glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags){
	if(!GLM_struct->glImportSyncEXTproc) return 0;
	return GLM_struct->glImportSyncEXTproc(external_sync_type, external_sync, flags);
}
void APIENTRY glFrameTerminatorGREMEDY(void){
	if(!GLM_struct->glFrameTerminatorGREMEDYproc) return;
	GLM_struct->glFrameTerminatorGREMEDYproc();
}
void APIENTRY glStringMarkerGREMEDY(GLsizei len, const void* string){
	if(!GLM_struct->glStringMarkerGREMEDYproc) return;
	GLM_struct->glStringMarkerGREMEDYproc(len, string);
}
void APIENTRY glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glImageTransformParameteriHPproc) return;
	GLM_struct->glImageTransformParameteriHPproc(target, pname, param);
}
void APIENTRY glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param){
	if(!GLM_struct->glImageTransformParameterfHPproc) return;
	GLM_struct->glImageTransformParameterfHPproc(target, pname, param);
}
void APIENTRY glImageTransformParameterivHP(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glImageTransformParameterivHPproc) return;
	GLM_struct->glImageTransformParameterivHPproc(target, pname, params);
}
void APIENTRY glImageTransformParameterfvHP(GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glImageTransformParameterfvHPproc) return;
	GLM_struct->glImageTransformParameterfvHPproc(target, pname, params);
}
void APIENTRY glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetImageTransformParameterivHPproc) return;
	GLM_struct->glGetImageTransformParameterivHPproc(target, pname, params);
}
void APIENTRY glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetImageTransformParameterfvHPproc) return;
	GLM_struct->glGetImageTransformParameterfvHPproc(target, pname, params);
}
void APIENTRY glMultiModeDrawArraysIBM(const GLenum* mode, const GLint* first, const GLsizei* count, GLsizei primcount, GLint modestride){
	if(!GLM_struct->glMultiModeDrawArraysIBMproc) return;
	GLM_struct->glMultiModeDrawArraysIBMproc(mode, first, count, primcount, modestride);
}
void APIENTRY glMultiModeDrawElementsIBM(const GLenum* mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei primcount, GLint modestride){
	if(!GLM_struct->glMultiModeDrawElementsIBMproc) return;
	GLM_struct->glMultiModeDrawElementsIBMproc(mode, count, type, indices, primcount, modestride);
}
void APIENTRY glFlushStaticDataIBM(GLenum target){
	if(!GLM_struct->glFlushStaticDataIBMproc) return;
	GLM_struct->glFlushStaticDataIBMproc(target);
}
void APIENTRY glColorPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride){
	if(!GLM_struct->glColorPointerListIBMproc) return;
	GLM_struct->glColorPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
void APIENTRY glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride){
	if(!GLM_struct->glSecondaryColorPointerListIBMproc) return;
	GLM_struct->glSecondaryColorPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
void APIENTRY glEdgeFlagPointerListIBM(GLint stride, const GLboolean** pointer, GLint ptrstride){
	if(!GLM_struct->glEdgeFlagPointerListIBMproc) return;
	GLM_struct->glEdgeFlagPointerListIBMproc(stride, pointer, ptrstride);
}
void APIENTRY glFogCoordPointerListIBM(GLenum type, GLint stride, const void** pointer, GLint ptrstride){
	if(!GLM_struct->glFogCoordPointerListIBMproc) return;
	GLM_struct->glFogCoordPointerListIBMproc(type, stride, pointer, ptrstride);
}
void APIENTRY glIndexPointerListIBM(GLenum type, GLint stride, const void** pointer, GLint ptrstride){
	if(!GLM_struct->glIndexPointerListIBMproc) return;
	GLM_struct->glIndexPointerListIBMproc(type, stride, pointer, ptrstride);
}
void APIENTRY glNormalPointerListIBM(GLenum type, GLint stride, const void** pointer, GLint ptrstride){
	if(!GLM_struct->glNormalPointerListIBMproc) return;
	GLM_struct->glNormalPointerListIBMproc(type, stride, pointer, ptrstride);
}
void APIENTRY glTexCoordPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride){
	if(!GLM_struct->glTexCoordPointerListIBMproc) return;
	GLM_struct->glTexCoordPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
void APIENTRY glVertexPointerListIBM(GLint size, GLenum type, GLint stride, const void** pointer, GLint ptrstride){
	if(!GLM_struct->glVertexPointerListIBMproc) return;
	GLM_struct->glVertexPointerListIBMproc(size, type, stride, pointer, ptrstride);
}
void APIENTRY glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha){
	if(!GLM_struct->glBlendFuncSeparateINGRproc) return;
	GLM_struct->glBlendFuncSeparateINGRproc(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void APIENTRY glApplyFramebufferAttachmentCMAAINTEL(void){
	if(!GLM_struct->glApplyFramebufferAttachmentCMAAINTELproc) return;
	GLM_struct->glApplyFramebufferAttachmentCMAAINTELproc();
}
void APIENTRY glSyncTextureINTEL(GLuint texture){
	if(!GLM_struct->glSyncTextureINTELproc) return;
	GLM_struct->glSyncTextureINTELproc(texture);
}
void APIENTRY glUnmapTexture2DINTEL(GLuint texture, GLint level){
	if(!GLM_struct->glUnmapTexture2DINTELproc) return;
	GLM_struct->glUnmapTexture2DINTELproc(texture, level);
}
void* APIENTRY glMapTexture2DINTEL(GLuint texture, GLint level, GLbitfield access, GLint* stride, GLenum* layout){
	if(!GLM_struct->glMapTexture2DINTELproc) return 0;
	return GLM_struct->glMapTexture2DINTELproc(texture, level, access, stride, layout);
}
void APIENTRY glVertexPointervINTEL(GLint size, GLenum type, const void** pointer){
	if(!GLM_struct->glVertexPointervINTELproc) return;
	GLM_struct->glVertexPointervINTELproc(size, type, pointer);
}
void APIENTRY glNormalPointervINTEL(GLenum type, const void** pointer){
	if(!GLM_struct->glNormalPointervINTELproc) return;
	GLM_struct->glNormalPointervINTELproc(type, pointer);
}
void APIENTRY glColorPointervINTEL(GLint size, GLenum type, const void** pointer){
	if(!GLM_struct->glColorPointervINTELproc) return;
	GLM_struct->glColorPointervINTELproc(size, type, pointer);
}
void APIENTRY glTexCoordPointervINTEL(GLint size, GLenum type, const void** pointer){
	if(!GLM_struct->glTexCoordPointervINTELproc) return;
	GLM_struct->glTexCoordPointervINTELproc(size, type, pointer);
}
void APIENTRY glBeginPerfQueryINTEL(GLuint queryHandle){
	if(!GLM_struct->glBeginPerfQueryINTELproc) return;
	GLM_struct->glBeginPerfQueryINTELproc(queryHandle);
}
void APIENTRY glCreatePerfQueryINTEL(GLuint queryId, GLuint* queryHandle){
	if(!GLM_struct->glCreatePerfQueryINTELproc) return;
	GLM_struct->glCreatePerfQueryINTELproc(queryId, queryHandle);
}
void APIENTRY glDeletePerfQueryINTEL(GLuint queryHandle){
	if(!GLM_struct->glDeletePerfQueryINTELproc) return;
	GLM_struct->glDeletePerfQueryINTELproc(queryHandle);
}
void APIENTRY glEndPerfQueryINTEL(GLuint queryHandle){
	if(!GLM_struct->glEndPerfQueryINTELproc) return;
	GLM_struct->glEndPerfQueryINTELproc(queryHandle);
}
void APIENTRY glGetFirstPerfQueryIdINTEL(GLuint* queryId){
	if(!GLM_struct->glGetFirstPerfQueryIdINTELproc) return;
	GLM_struct->glGetFirstPerfQueryIdINTELproc(queryId);
}
void APIENTRY glGetNextPerfQueryIdINTEL(GLuint queryId, GLuint* nextQueryId){
	if(!GLM_struct->glGetNextPerfQueryIdINTELproc) return;
	GLM_struct->glGetNextPerfQueryIdINTELproc(queryId, nextQueryId);
}
void APIENTRY glGetPerfCounterInfoINTEL(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar* counterName, GLuint counterDescLength, GLchar* counterDesc, GLuint* counterOffset, GLuint* counterDataSize, GLuint* counterTypeEnum, GLuint* counterDataTypeEnum, GLuint64* rawCounterMaxValue){
	if(!GLM_struct->glGetPerfCounterInfoINTELproc) return;
	GLM_struct->glGetPerfCounterInfoINTELproc(queryId, counterId, counterNameLength, counterName, counterDescLength, counterDesc, counterOffset, counterDataSize, counterTypeEnum, counterDataTypeEnum, rawCounterMaxValue);
}
void APIENTRY glGetPerfQueryDataINTEL(GLuint queryHandle, GLuint flags, GLsizei dataSize, void* data, GLuint* bytesWritten){
	if(!GLM_struct->glGetPerfQueryDataINTELproc) return;
	GLM_struct->glGetPerfQueryDataINTELproc(queryHandle, flags, dataSize, data, bytesWritten);
}
void APIENTRY glGetPerfQueryIdByNameINTEL(GLchar* queryName, GLuint* queryId){
	if(!GLM_struct->glGetPerfQueryIdByNameINTELproc) return;
	GLM_struct->glGetPerfQueryIdByNameINTELproc(queryName, queryId);
}
void APIENTRY glGetPerfQueryInfoINTEL(GLuint queryId, GLuint queryNameLength, GLchar* queryName, GLuint* dataSize, GLuint* noCounters, GLuint* noInstances, GLuint* capsMask){
	if(!GLM_struct->glGetPerfQueryInfoINTELproc) return;
	GLM_struct->glGetPerfQueryInfoINTELproc(queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask);
}
void APIENTRY glFramebufferParameteriMESA(GLenum target, GLenum pname, GLint param){
	if(!GLM_struct->glFramebufferParameteriMESAproc) return;
	GLM_struct->glFramebufferParameteriMESAproc(target, pname, param);
}
void APIENTRY glGetFramebufferParameterivMESA(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFramebufferParameterivMESAproc) return;
	GLM_struct->glGetFramebufferParameterivMESAproc(target, pname, params);
}
void APIENTRY glResizeBuffersMESA(void){
	if(!GLM_struct->glResizeBuffersMESAproc) return;
	GLM_struct->glResizeBuffersMESAproc();
}
void APIENTRY glWindowPos2dMESA(GLdouble x, GLdouble y){
	if(!GLM_struct->glWindowPos2dMESAproc) return;
	GLM_struct->glWindowPos2dMESAproc(x, y);
}
void APIENTRY glWindowPos2dvMESA(const GLdouble* v){
	if(!GLM_struct->glWindowPos2dvMESAproc) return;
	GLM_struct->glWindowPos2dvMESAproc(v);
}
void APIENTRY glWindowPos2fMESA(GLfloat x, GLfloat y){
	if(!GLM_struct->glWindowPos2fMESAproc) return;
	GLM_struct->glWindowPos2fMESAproc(x, y);
}
void APIENTRY glWindowPos2fvMESA(const GLfloat* v){
	if(!GLM_struct->glWindowPos2fvMESAproc) return;
	GLM_struct->glWindowPos2fvMESAproc(v);
}
void APIENTRY glWindowPos2iMESA(GLint x, GLint y){
	if(!GLM_struct->glWindowPos2iMESAproc) return;
	GLM_struct->glWindowPos2iMESAproc(x, y);
}
void APIENTRY glWindowPos2ivMESA(const GLint* v){
	if(!GLM_struct->glWindowPos2ivMESAproc) return;
	GLM_struct->glWindowPos2ivMESAproc(v);
}
void APIENTRY glWindowPos2sMESA(GLshort x, GLshort y){
	if(!GLM_struct->glWindowPos2sMESAproc) return;
	GLM_struct->glWindowPos2sMESAproc(x, y);
}
void APIENTRY glWindowPos2svMESA(const GLshort* v){
	if(!GLM_struct->glWindowPos2svMESAproc) return;
	GLM_struct->glWindowPos2svMESAproc(v);
}
void APIENTRY glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glWindowPos3dMESAproc) return;
	GLM_struct->glWindowPos3dMESAproc(x, y, z);
}
void APIENTRY glWindowPos3dvMESA(const GLdouble* v){
	if(!GLM_struct->glWindowPos3dvMESAproc) return;
	GLM_struct->glWindowPos3dvMESAproc(v);
}
void APIENTRY glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glWindowPos3fMESAproc) return;
	GLM_struct->glWindowPos3fMESAproc(x, y, z);
}
void APIENTRY glWindowPos3fvMESA(const GLfloat* v){
	if(!GLM_struct->glWindowPos3fvMESAproc) return;
	GLM_struct->glWindowPos3fvMESAproc(v);
}
void APIENTRY glWindowPos3iMESA(GLint x, GLint y, GLint z){
	if(!GLM_struct->glWindowPos3iMESAproc) return;
	GLM_struct->glWindowPos3iMESAproc(x, y, z);
}
void APIENTRY glWindowPos3ivMESA(const GLint* v){
	if(!GLM_struct->glWindowPos3ivMESAproc) return;
	GLM_struct->glWindowPos3ivMESAproc(v);
}
void APIENTRY glWindowPos3sMESA(GLshort x, GLshort y, GLshort z){
	if(!GLM_struct->glWindowPos3sMESAproc) return;
	GLM_struct->glWindowPos3sMESAproc(x, y, z);
}
void APIENTRY glWindowPos3svMESA(const GLshort* v){
	if(!GLM_struct->glWindowPos3svMESAproc) return;
	GLM_struct->glWindowPos3svMESAproc(v);
}
void APIENTRY glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glWindowPos4dMESAproc) return;
	GLM_struct->glWindowPos4dMESAproc(x, y, z, w);
}
void APIENTRY glWindowPos4dvMESA(const GLdouble* v){
	if(!GLM_struct->glWindowPos4dvMESAproc) return;
	GLM_struct->glWindowPos4dvMESAproc(v);
}
void APIENTRY glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glWindowPos4fMESAproc) return;
	GLM_struct->glWindowPos4fMESAproc(x, y, z, w);
}
void APIENTRY glWindowPos4fvMESA(const GLfloat* v){
	if(!GLM_struct->glWindowPos4fvMESAproc) return;
	GLM_struct->glWindowPos4fvMESAproc(v);
}
void APIENTRY glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w){
	if(!GLM_struct->glWindowPos4iMESAproc) return;
	GLM_struct->glWindowPos4iMESAproc(x, y, z, w);
}
void APIENTRY glWindowPos4ivMESA(const GLint* v){
	if(!GLM_struct->glWindowPos4ivMESAproc) return;
	GLM_struct->glWindowPos4ivMESAproc(v);
}
void APIENTRY glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w){
	if(!GLM_struct->glWindowPos4sMESAproc) return;
	GLM_struct->glWindowPos4sMESAproc(x, y, z, w);
}
void APIENTRY glWindowPos4svMESA(const GLshort* v){
	if(!GLM_struct->glWindowPos4svMESAproc) return;
	GLM_struct->glWindowPos4svMESAproc(v);
}
void APIENTRY glBeginConditionalRenderNVX(GLuint id){
	if(!GLM_struct->glBeginConditionalRenderNVXproc) return;
	GLM_struct->glBeginConditionalRenderNVXproc(id);
}
void APIENTRY glEndConditionalRenderNVX(void){
	if(!GLM_struct->glEndConditionalRenderNVXproc) return;
	GLM_struct->glEndConditionalRenderNVXproc();
}
void APIENTRY glUploadGpuMaskNVX(GLbitfield mask){
	if(!GLM_struct->glUploadGpuMaskNVXproc) return;
	GLM_struct->glUploadGpuMaskNVXproc(mask);
}
void APIENTRY glMulticastViewportArrayvNVX(GLuint gpu, GLuint first, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glMulticastViewportArrayvNVXproc) return;
	GLM_struct->glMulticastViewportArrayvNVXproc(gpu, first, count, v);
}
void APIENTRY glMulticastViewportPositionWScaleNVX(GLuint gpu, GLuint index, GLfloat xcoeff, GLfloat ycoeff){
	if(!GLM_struct->glMulticastViewportPositionWScaleNVXproc) return;
	GLM_struct->glMulticastViewportPositionWScaleNVXproc(gpu, index, xcoeff, ycoeff);
}
void APIENTRY glMulticastScissorArrayvNVX(GLuint gpu, GLuint first, GLsizei count, const GLint* v){
	if(!GLM_struct->glMulticastScissorArrayvNVXproc) return;
	GLM_struct->glMulticastScissorArrayvNVXproc(gpu, first, count, v);
}
GLuint APIENTRY glAsyncCopyBufferSubDataNVX(GLsizei waitSemaphoreCount, const GLuint* waitSemaphoreArray, const GLuint64* fenceValueArray, GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsizei signalSemaphoreCount, const GLuint* signalSemaphoreArray, const GLuint64* signalValueArray){
	if(!GLM_struct->glAsyncCopyBufferSubDataNVXproc) return 0;
	return GLM_struct->glAsyncCopyBufferSubDataNVXproc(waitSemaphoreCount, waitSemaphoreArray, fenceValueArray, readGpu, writeGpuMask, readBuffer, writeBuffer, readOffset, writeOffset, size, signalSemaphoreCount, signalSemaphoreArray, signalValueArray);
}
GLuint APIENTRY glAsyncCopyImageSubDataNVX(GLsizei waitSemaphoreCount, const GLuint* waitSemaphoreArray, const GLuint64* waitValueArray, GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, GLsizei signalSemaphoreCount, const GLuint* signalSemaphoreArray, const GLuint64* signalValueArray){
	if(!GLM_struct->glAsyncCopyImageSubDataNVXproc) return 0;
	return GLM_struct->glAsyncCopyImageSubDataNVXproc(waitSemaphoreCount, waitSemaphoreArray, waitValueArray, srcGpu, dstGpuMask, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth, signalSemaphoreCount, signalSemaphoreArray, signalValueArray);
}
void APIENTRY glLGPUNamedBufferSubDataNVX(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data){
	if(!GLM_struct->glLGPUNamedBufferSubDataNVXproc) return;
	GLM_struct->glLGPUNamedBufferSubDataNVXproc(gpuMask, buffer, offset, size, data);
}
void APIENTRY glLGPUCopyImageSubDataNVX(GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srxY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->glLGPUCopyImageSubDataNVXproc) return;
	GLM_struct->glLGPUCopyImageSubDataNVXproc(sourceGpu, destinationGpuMask, srcName, srcTarget, srcLevel, srcX, srxY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}
void APIENTRY glLGPUInterlockNVX(void){
	if(!GLM_struct->glLGPUInterlockNVXproc) return;
	GLM_struct->glLGPUInterlockNVXproc();
}
GLuint APIENTRY glCreateProgressFenceNVX(void){
	if(!GLM_struct->glCreateProgressFenceNVXproc) return 0;
	return GLM_struct->glCreateProgressFenceNVXproc();
}
void APIENTRY glSignalSemaphoreui64NVX(GLuint signalGpu, GLsizei fenceObjectCount, const GLuint* semaphoreArray, const GLuint64* fenceValueArray){
	if(!GLM_struct->glSignalSemaphoreui64NVXproc) return;
	GLM_struct->glSignalSemaphoreui64NVXproc(signalGpu, fenceObjectCount, semaphoreArray, fenceValueArray);
}
void APIENTRY glWaitSemaphoreui64NVX(GLuint waitGpu, GLsizei fenceObjectCount, const GLuint* semaphoreArray, const GLuint64* fenceValueArray){
	if(!GLM_struct->glWaitSemaphoreui64NVXproc) return;
	GLM_struct->glWaitSemaphoreui64NVXproc(waitGpu, fenceObjectCount, semaphoreArray, fenceValueArray);
}
void APIENTRY glClientWaitSemaphoreui64NVX(GLsizei fenceObjectCount, const GLuint* semaphoreArray, const GLuint64* fenceValueArray){
	if(!GLM_struct->glClientWaitSemaphoreui64NVXproc) return;
	GLM_struct->glClientWaitSemaphoreui64NVXproc(fenceObjectCount, semaphoreArray, fenceValueArray);
}
void APIENTRY glAlphaToCoverageDitherControlNV(GLenum mode){
	if(!GLM_struct->glAlphaToCoverageDitherControlNVproc) return;
	GLM_struct->glAlphaToCoverageDitherControlNVproc(mode);
}
void APIENTRY glMultiDrawArraysIndirectBindlessNV(GLenum mode, const void* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount){
	if(!GLM_struct->glMultiDrawArraysIndirectBindlessNVproc) return;
	GLM_struct->glMultiDrawArraysIndirectBindlessNVproc(mode, indirect, drawCount, stride, vertexBufferCount);
}
void APIENTRY glMultiDrawElementsIndirectBindlessNV(GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount){
	if(!GLM_struct->glMultiDrawElementsIndirectBindlessNVproc) return;
	GLM_struct->glMultiDrawElementsIndirectBindlessNVproc(mode, type, indirect, drawCount, stride, vertexBufferCount);
}
void APIENTRY glMultiDrawArraysIndirectBindlessCountNV(GLenum mode, const void* indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount){
	if(!GLM_struct->glMultiDrawArraysIndirectBindlessCountNVproc) return;
	GLM_struct->glMultiDrawArraysIndirectBindlessCountNVproc(mode, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}
void APIENTRY glMultiDrawElementsIndirectBindlessCountNV(GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount){
	if(!GLM_struct->glMultiDrawElementsIndirectBindlessCountNVproc) return;
	GLM_struct->glMultiDrawElementsIndirectBindlessCountNVproc(mode, type, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}
GLuint64 APIENTRY glGetTextureHandleNV(GLuint texture){
	if(!GLM_struct->glGetTextureHandleNVproc) return 0;
	return GLM_struct->glGetTextureHandleNVproc(texture);
}
GLuint64 APIENTRY glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler){
	if(!GLM_struct->glGetTextureSamplerHandleNVproc) return 0;
	return GLM_struct->glGetTextureSamplerHandleNVproc(texture, sampler);
}
void APIENTRY glMakeTextureHandleResidentNV(GLuint64 handle){
	if(!GLM_struct->glMakeTextureHandleResidentNVproc) return;
	GLM_struct->glMakeTextureHandleResidentNVproc(handle);
}
void APIENTRY glMakeTextureHandleNonResidentNV(GLuint64 handle){
	if(!GLM_struct->glMakeTextureHandleNonResidentNVproc) return;
	GLM_struct->glMakeTextureHandleNonResidentNVproc(handle);
}
GLuint64 APIENTRY glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format){
	if(!GLM_struct->glGetImageHandleNVproc) return 0;
	return GLM_struct->glGetImageHandleNVproc(texture, level, layered, layer, format);
}
void APIENTRY glMakeImageHandleResidentNV(GLuint64 handle, GLenum access){
	if(!GLM_struct->glMakeImageHandleResidentNVproc) return;
	GLM_struct->glMakeImageHandleResidentNVproc(handle, access);
}
void APIENTRY glMakeImageHandleNonResidentNV(GLuint64 handle){
	if(!GLM_struct->glMakeImageHandleNonResidentNVproc) return;
	GLM_struct->glMakeImageHandleNonResidentNVproc(handle);
}
void APIENTRY glUniformHandleui64NV(GLint location, GLuint64 value){
	if(!GLM_struct->glUniformHandleui64NVproc) return;
	GLM_struct->glUniformHandleui64NVproc(location, value);
}
void APIENTRY glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64* value){
	if(!GLM_struct->glUniformHandleui64vNVproc) return;
	GLM_struct->glUniformHandleui64vNVproc(location, count, value);
}
void APIENTRY glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value){
	if(!GLM_struct->glProgramUniformHandleui64NVproc) return;
	GLM_struct->glProgramUniformHandleui64NVproc(program, location, value);
}
void APIENTRY glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64* values){
	if(!GLM_struct->glProgramUniformHandleui64vNVproc) return;
	GLM_struct->glProgramUniformHandleui64vNVproc(program, location, count, values);
}
GLboolean APIENTRY glIsTextureHandleResidentNV(GLuint64 handle){
	if(!GLM_struct->glIsTextureHandleResidentNVproc) return 0;
	return GLM_struct->glIsTextureHandleResidentNVproc(handle);
}
GLboolean APIENTRY glIsImageHandleResidentNV(GLuint64 handle){
	if(!GLM_struct->glIsImageHandleResidentNVproc) return 0;
	return GLM_struct->glIsImageHandleResidentNVproc(handle);
}
void APIENTRY glBlendParameteriNV(GLenum pname, GLint value){
	if(!GLM_struct->glBlendParameteriNVproc) return;
	GLM_struct->glBlendParameteriNVproc(pname, value);
}
void APIENTRY glBlendBarrierNV(void){
	if(!GLM_struct->glBlendBarrierNVproc) return;
	GLM_struct->glBlendBarrierNVproc();
}
void APIENTRY glViewportPositionWScaleNV(GLuint index, GLfloat xcoeff, GLfloat ycoeff){
	if(!GLM_struct->glViewportPositionWScaleNVproc) return;
	GLM_struct->glViewportPositionWScaleNVproc(index, xcoeff, ycoeff);
}
void APIENTRY glCreateStatesNV(GLsizei n, GLuint* states){
	if(!GLM_struct->glCreateStatesNVproc) return;
	GLM_struct->glCreateStatesNVproc(n, states);
}
void APIENTRY glDeleteStatesNV(GLsizei n, const GLuint* states){
	if(!GLM_struct->glDeleteStatesNVproc) return;
	GLM_struct->glDeleteStatesNVproc(n, states);
}
GLboolean APIENTRY glIsStateNV(GLuint state){
	if(!GLM_struct->glIsStateNVproc) return 0;
	return GLM_struct->glIsStateNVproc(state);
}
void APIENTRY glStateCaptureNV(GLuint state, GLenum mode){
	if(!GLM_struct->glStateCaptureNVproc) return;
	GLM_struct->glStateCaptureNVproc(state, mode);
}
GLuint APIENTRY glGetCommandHeaderNV(GLenum tokenID, GLuint size){
	if(!GLM_struct->glGetCommandHeaderNVproc) return 0;
	return GLM_struct->glGetCommandHeaderNVproc(tokenID, size);
}
GLushort APIENTRY glGetStageIndexNV(GLenum shadertype){
	if(!GLM_struct->glGetStageIndexNVproc) return 0;
	return GLM_struct->glGetStageIndexNVproc(shadertype);
}
void APIENTRY glDrawCommandsNV(GLenum primitiveMode, GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, GLuint count){
	if(!GLM_struct->glDrawCommandsNVproc) return;
	GLM_struct->glDrawCommandsNVproc(primitiveMode, buffer, indirects, sizes, count);
}
void APIENTRY glDrawCommandsAddressNV(GLenum primitiveMode, const GLuint64* indirects, const GLsizei* sizes, GLuint count){
	if(!GLM_struct->glDrawCommandsAddressNVproc) return;
	GLM_struct->glDrawCommandsAddressNVproc(primitiveMode, indirects, sizes, count);
}
void APIENTRY glDrawCommandsStatesNV(GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count){
	if(!GLM_struct->glDrawCommandsStatesNVproc) return;
	GLM_struct->glDrawCommandsStatesNVproc(buffer, indirects, sizes, states, fbos, count);
}
void APIENTRY glDrawCommandsStatesAddressNV(const GLuint64* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count){
	if(!GLM_struct->glDrawCommandsStatesAddressNVproc) return;
	GLM_struct->glDrawCommandsStatesAddressNVproc(indirects, sizes, states, fbos, count);
}
void APIENTRY glCreateCommandListsNV(GLsizei n, GLuint* lists){
	if(!GLM_struct->glCreateCommandListsNVproc) return;
	GLM_struct->glCreateCommandListsNVproc(n, lists);
}
void APIENTRY glDeleteCommandListsNV(GLsizei n, const GLuint* lists){
	if(!GLM_struct->glDeleteCommandListsNVproc) return;
	GLM_struct->glDeleteCommandListsNVproc(n, lists);
}
GLboolean APIENTRY glIsCommandListNV(GLuint list){
	if(!GLM_struct->glIsCommandListNVproc) return 0;
	return GLM_struct->glIsCommandListNVproc(list);
}
void APIENTRY glListDrawCommandsStatesClientNV(GLuint list, GLuint segment, const void** indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count){
	if(!GLM_struct->glListDrawCommandsStatesClientNVproc) return;
	GLM_struct->glListDrawCommandsStatesClientNVproc(list, segment, indirects, sizes, states, fbos, count);
}
void APIENTRY glCommandListSegmentsNV(GLuint list, GLuint segments){
	if(!GLM_struct->glCommandListSegmentsNVproc) return;
	GLM_struct->glCommandListSegmentsNVproc(list, segments);
}
void APIENTRY glCompileCommandListNV(GLuint list){
	if(!GLM_struct->glCompileCommandListNVproc) return;
	GLM_struct->glCompileCommandListNVproc(list);
}
void APIENTRY glCallCommandListNV(GLuint list){
	if(!GLM_struct->glCallCommandListNVproc) return;
	GLM_struct->glCallCommandListNVproc(list);
}
void APIENTRY glBeginConditionalRenderNV(GLuint id, GLenum mode){
	if(!GLM_struct->glBeginConditionalRenderNVproc) return;
	GLM_struct->glBeginConditionalRenderNVproc(id, mode);
}
void APIENTRY glEndConditionalRenderNV(void){
	if(!GLM_struct->glEndConditionalRenderNVproc) return;
	GLM_struct->glEndConditionalRenderNVproc();
}
void APIENTRY glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits){
	if(!GLM_struct->glSubpixelPrecisionBiasNVproc) return;
	GLM_struct->glSubpixelPrecisionBiasNVproc(xbits, ybits);
}
void APIENTRY glConservativeRasterParameterfNV(GLenum pname, GLfloat value){
	if(!GLM_struct->glConservativeRasterParameterfNVproc) return;
	GLM_struct->glConservativeRasterParameterfNVproc(pname, value);
}
void APIENTRY glConservativeRasterParameteriNV(GLenum pname, GLint param){
	if(!GLM_struct->glConservativeRasterParameteriNVproc) return;
	GLM_struct->glConservativeRasterParameteriNVproc(pname, param);
}
void APIENTRY glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth){
	if(!GLM_struct->glCopyImageSubDataNVproc) return;
	GLM_struct->glCopyImageSubDataNVproc(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}
void APIENTRY glDepthRangedNV(GLdouble zNear, GLdouble zFar){
	if(!GLM_struct->glDepthRangedNVproc) return;
	GLM_struct->glDepthRangedNVproc(zNear, zFar);
}
void APIENTRY glClearDepthdNV(GLdouble depth){
	if(!GLM_struct->glClearDepthdNVproc) return;
	GLM_struct->glClearDepthdNVproc(depth);
}
void APIENTRY glDepthBoundsdNV(GLdouble zmin, GLdouble zmax){
	if(!GLM_struct->glDepthBoundsdNVproc) return;
	GLM_struct->glDepthBoundsdNVproc(zmin, zmax);
}
void APIENTRY glDrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1){
	if(!GLM_struct->glDrawTextureNVproc) return;
	GLM_struct->glDrawTextureNVproc(texture, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}
void APIENTRY glDrawVkImageNV(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1){
	if(!GLM_struct->glDrawVkImageNVproc) return;
	GLM_struct->glDrawVkImageNVproc(vkImage, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}
GLVULKANPROCNV APIENTRY glGetVkProcAddrNV(const GLchar* name){
	if(!GLM_struct->glGetVkProcAddrNVproc) return 0;
	return GLM_struct->glGetVkProcAddrNVproc(name);
}
void APIENTRY glWaitVkSemaphoreNV(GLuint64 vkSemaphore){
	if(!GLM_struct->glWaitVkSemaphoreNVproc) return;
	GLM_struct->glWaitVkSemaphoreNVproc(vkSemaphore);
}
void APIENTRY glSignalVkSemaphoreNV(GLuint64 vkSemaphore){
	if(!GLM_struct->glSignalVkSemaphoreNVproc) return;
	GLM_struct->glSignalVkSemaphoreNVproc(vkSemaphore);
}
void APIENTRY glSignalVkFenceNV(GLuint64 vkFence){
	if(!GLM_struct->glSignalVkFenceNVproc) return;
	GLM_struct->glSignalVkFenceNVproc(vkFence);
}
void APIENTRY glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void* points){
	if(!GLM_struct->glMapControlPointsNVproc) return;
	GLM_struct->glMapControlPointsNVproc(target, index, type, ustride, vstride, uorder, vorder, packed, points);
}
void APIENTRY glMapParameterivNV(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glMapParameterivNVproc) return;
	GLM_struct->glMapParameterivNVproc(target, pname, params);
}
void APIENTRY glMapParameterfvNV(GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glMapParameterfvNVproc) return;
	GLM_struct->glMapParameterfvNVproc(target, pname, params);
}
void APIENTRY glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void* points){
	if(!GLM_struct->glGetMapControlPointsNVproc) return;
	GLM_struct->glGetMapControlPointsNVproc(target, index, type, ustride, vstride, packed, points);
}
void APIENTRY glGetMapParameterivNV(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMapParameterivNVproc) return;
	GLM_struct->glGetMapParameterivNVproc(target, pname, params);
}
void APIENTRY glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMapParameterfvNVproc) return;
	GLM_struct->glGetMapParameterfvNVproc(target, pname, params);
}
void APIENTRY glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetMapAttribParameterivNVproc) return;
	GLM_struct->glGetMapAttribParameterivNVproc(target, index, pname, params);
}
void APIENTRY glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetMapAttribParameterfvNVproc) return;
	GLM_struct->glGetMapAttribParameterfvNVproc(target, index, pname, params);
}
void APIENTRY glEvalMapsNV(GLenum target, GLenum mode){
	if(!GLM_struct->glEvalMapsNVproc) return;
	GLM_struct->glEvalMapsNVproc(target, mode);
}
void APIENTRY glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat* val){
	if(!GLM_struct->glGetMultisamplefvNVproc) return;
	GLM_struct->glGetMultisamplefvNVproc(pname, index, val);
}
void APIENTRY glSampleMaskIndexedNV(GLuint index, GLbitfield mask){
	if(!GLM_struct->glSampleMaskIndexedNVproc) return;
	GLM_struct->glSampleMaskIndexedNVproc(index, mask);
}
void APIENTRY glTexRenderbufferNV(GLenum target, GLuint renderbuffer){
	if(!GLM_struct->glTexRenderbufferNVproc) return;
	GLM_struct->glTexRenderbufferNVproc(target, renderbuffer);
}
void APIENTRY glDeleteFencesNV(GLsizei n, const GLuint* fences){
	if(!GLM_struct->glDeleteFencesNVproc) return;
	GLM_struct->glDeleteFencesNVproc(n, fences);
}
void APIENTRY glGenFencesNV(GLsizei n, GLuint* fences){
	if(!GLM_struct->glGenFencesNVproc) return;
	GLM_struct->glGenFencesNVproc(n, fences);
}
GLboolean APIENTRY glIsFenceNV(GLuint fence){
	if(!GLM_struct->glIsFenceNVproc) return 0;
	return GLM_struct->glIsFenceNVproc(fence);
}
GLboolean APIENTRY glTestFenceNV(GLuint fence){
	if(!GLM_struct->glTestFenceNVproc) return 0;
	return GLM_struct->glTestFenceNVproc(fence);
}
void APIENTRY glGetFenceivNV(GLuint fence, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFenceivNVproc) return;
	GLM_struct->glGetFenceivNVproc(fence, pname, params);
}
void APIENTRY glFinishFenceNV(GLuint fence){
	if(!GLM_struct->glFinishFenceNVproc) return;
	GLM_struct->glFinishFenceNVproc(fence);
}
void APIENTRY glSetFenceNV(GLuint fence, GLenum condition){
	if(!GLM_struct->glSetFenceNVproc) return;
	GLM_struct->glSetFenceNVproc(fence, condition);
}
void APIENTRY glFragmentCoverageColorNV(GLuint color){
	if(!GLM_struct->glFragmentCoverageColorNVproc) return;
	GLM_struct->glFragmentCoverageColorNVproc(color);
}
void APIENTRY glProgramNamedParameter4fNV(GLuint id, GLsizei len, const GLubyte* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glProgramNamedParameter4fNVproc) return;
	GLM_struct->glProgramNamedParameter4fNVproc(id, len, name, x, y, z, w);
}
void APIENTRY glProgramNamedParameter4fvNV(GLuint id, GLsizei len, const GLubyte* name, const GLfloat* v){
	if(!GLM_struct->glProgramNamedParameter4fvNVproc) return;
	GLM_struct->glProgramNamedParameter4fvNVproc(id, len, name, v);
}
void APIENTRY glProgramNamedParameter4dNV(GLuint id, GLsizei len, const GLubyte* name, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glProgramNamedParameter4dNVproc) return;
	GLM_struct->glProgramNamedParameter4dNVproc(id, len, name, x, y, z, w);
}
void APIENTRY glProgramNamedParameter4dvNV(GLuint id, GLsizei len, const GLubyte* name, const GLdouble* v){
	if(!GLM_struct->glProgramNamedParameter4dvNVproc) return;
	GLM_struct->glProgramNamedParameter4dvNVproc(id, len, name, v);
}
void APIENTRY glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, const GLubyte* name, GLfloat* params){
	if(!GLM_struct->glGetProgramNamedParameterfvNVproc) return;
	GLM_struct->glGetProgramNamedParameterfvNVproc(id, len, name, params);
}
void APIENTRY glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, const GLubyte* name, GLdouble* params){
	if(!GLM_struct->glGetProgramNamedParameterdvNVproc) return;
	GLM_struct->glGetProgramNamedParameterdvNVproc(id, len, name, params);
}
void APIENTRY glCoverageModulationTableNV(GLsizei n, const GLfloat* v){
	if(!GLM_struct->glCoverageModulationTableNVproc) return;
	GLM_struct->glCoverageModulationTableNVproc(n, v);
}
void APIENTRY glGetCoverageModulationTableNV(GLsizei bufSize, GLfloat* v){
	if(!GLM_struct->glGetCoverageModulationTableNVproc) return;
	GLM_struct->glGetCoverageModulationTableNVproc(bufSize, v);
}
void APIENTRY glCoverageModulationNV(GLenum components){
	if(!GLM_struct->glCoverageModulationNVproc) return;
	GLM_struct->glCoverageModulationNVproc(components);
}
void APIENTRY glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height){
	if(!GLM_struct->glRenderbufferStorageMultisampleCoverageNVproc) return;
	GLM_struct->glRenderbufferStorageMultisampleCoverageNVproc(target, coverageSamples, colorSamples, internalformat, width, height);
}
void APIENTRY glProgramVertexLimitNV(GLenum target, GLint limit){
	if(!GLM_struct->glProgramVertexLimitNVproc) return;
	GLM_struct->glProgramVertexLimitNVproc(target, limit);
}
void APIENTRY glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level){
	if(!GLM_struct->glFramebufferTextureEXTproc) return;
	GLM_struct->glFramebufferTextureEXTproc(target, attachment, texture, level);
}
void APIENTRY glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face){
	if(!GLM_struct->glFramebufferTextureFaceEXTproc) return;
	GLM_struct->glFramebufferTextureFaceEXTproc(target, attachment, texture, level, face);
}
void APIENTRY glRenderGpuMaskNV(GLbitfield mask){
	if(!GLM_struct->glRenderGpuMaskNVproc) return;
	GLM_struct->glRenderGpuMaskNVproc(mask);
}
void APIENTRY glMulticastBufferSubDataNV(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data){
	if(!GLM_struct->glMulticastBufferSubDataNVproc) return;
	GLM_struct->glMulticastBufferSubDataNVproc(gpuMask, buffer, offset, size, data);
}
void APIENTRY glMulticastCopyBufferSubDataNV(GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size){
	if(!GLM_struct->glMulticastCopyBufferSubDataNVproc) return;
	GLM_struct->glMulticastCopyBufferSubDataNVproc(readGpu, writeGpuMask, readBuffer, writeBuffer, readOffset, writeOffset, size);
}
void APIENTRY glMulticastCopyImageSubDataNV(GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth){
	if(!GLM_struct->glMulticastCopyImageSubDataNVproc) return;
	GLM_struct->glMulticastCopyImageSubDataNVproc(srcGpu, dstGpuMask, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
void APIENTRY glMulticastBlitFramebufferNV(GLuint srcGpu, GLuint dstGpu, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter){
	if(!GLM_struct->glMulticastBlitFramebufferNVproc) return;
	GLM_struct->glMulticastBlitFramebufferNVproc(srcGpu, dstGpu, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
void APIENTRY glMulticastFramebufferSampleLocationsfvNV(GLuint gpu, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glMulticastFramebufferSampleLocationsfvNVproc) return;
	GLM_struct->glMulticastFramebufferSampleLocationsfvNVproc(gpu, framebuffer, start, count, v);
}
void APIENTRY glMulticastBarrierNV(void){
	if(!GLM_struct->glMulticastBarrierNVproc) return;
	GLM_struct->glMulticastBarrierNVproc();
}
void APIENTRY glMulticastWaitSyncNV(GLuint signalGpu, GLbitfield waitGpuMask){
	if(!GLM_struct->glMulticastWaitSyncNVproc) return;
	GLM_struct->glMulticastWaitSyncNVproc(signalGpu, waitGpuMask);
}
void APIENTRY glMulticastGetQueryObjectivNV(GLuint gpu, GLuint id, GLenum pname, GLint* params){
	if(!GLM_struct->glMulticastGetQueryObjectivNVproc) return;
	GLM_struct->glMulticastGetQueryObjectivNVproc(gpu, id, pname, params);
}
void APIENTRY glMulticastGetQueryObjectuivNV(GLuint gpu, GLuint id, GLenum pname, GLuint* params){
	if(!GLM_struct->glMulticastGetQueryObjectuivNVproc) return;
	GLM_struct->glMulticastGetQueryObjectuivNVproc(gpu, id, pname, params);
}
void APIENTRY glMulticastGetQueryObjecti64vNV(GLuint gpu, GLuint id, GLenum pname, GLint64* params){
	if(!GLM_struct->glMulticastGetQueryObjecti64vNVproc) return;
	GLM_struct->glMulticastGetQueryObjecti64vNVproc(gpu, id, pname, params);
}
void APIENTRY glMulticastGetQueryObjectui64vNV(GLuint gpu, GLuint id, GLenum pname, GLuint64* params){
	if(!GLM_struct->glMulticastGetQueryObjectui64vNVproc) return;
	GLM_struct->glMulticastGetQueryObjectui64vNVproc(gpu, id, pname, params);
}
void APIENTRY glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w){
	if(!GLM_struct->glProgramLocalParameterI4iNVproc) return;
	GLM_struct->glProgramLocalParameterI4iNVproc(target, index, x, y, z, w);
}
void APIENTRY glProgramLocalParameterI4ivNV(GLenum target, GLuint index, const GLint* params){
	if(!GLM_struct->glProgramLocalParameterI4ivNVproc) return;
	GLM_struct->glProgramLocalParameterI4ivNVproc(target, index, params);
}
void APIENTRY glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint* params){
	if(!GLM_struct->glProgramLocalParametersI4ivNVproc) return;
	GLM_struct->glProgramLocalParametersI4ivNVproc(target, index, count, params);
}
void APIENTRY glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w){
	if(!GLM_struct->glProgramLocalParameterI4uiNVproc) return;
	GLM_struct->glProgramLocalParameterI4uiNVproc(target, index, x, y, z, w);
}
void APIENTRY glProgramLocalParameterI4uivNV(GLenum target, GLuint index, const GLuint* params){
	if(!GLM_struct->glProgramLocalParameterI4uivNVproc) return;
	GLM_struct->glProgramLocalParameterI4uivNVproc(target, index, params);
}
void APIENTRY glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint* params){
	if(!GLM_struct->glProgramLocalParametersI4uivNVproc) return;
	GLM_struct->glProgramLocalParametersI4uivNVproc(target, index, count, params);
}
void APIENTRY glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w){
	if(!GLM_struct->glProgramEnvParameterI4iNVproc) return;
	GLM_struct->glProgramEnvParameterI4iNVproc(target, index, x, y, z, w);
}
void APIENTRY glProgramEnvParameterI4ivNV(GLenum target, GLuint index, const GLint* params){
	if(!GLM_struct->glProgramEnvParameterI4ivNVproc) return;
	GLM_struct->glProgramEnvParameterI4ivNVproc(target, index, params);
}
void APIENTRY glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint* params){
	if(!GLM_struct->glProgramEnvParametersI4ivNVproc) return;
	GLM_struct->glProgramEnvParametersI4ivNVproc(target, index, count, params);
}
void APIENTRY glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w){
	if(!GLM_struct->glProgramEnvParameterI4uiNVproc) return;
	GLM_struct->glProgramEnvParameterI4uiNVproc(target, index, x, y, z, w);
}
void APIENTRY glProgramEnvParameterI4uivNV(GLenum target, GLuint index, const GLuint* params){
	if(!GLM_struct->glProgramEnvParameterI4uivNVproc) return;
	GLM_struct->glProgramEnvParameterI4uivNVproc(target, index, params);
}
void APIENTRY glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint* params){
	if(!GLM_struct->glProgramEnvParametersI4uivNVproc) return;
	GLM_struct->glProgramEnvParametersI4uivNVproc(target, index, count, params);
}
void APIENTRY glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint* params){
	if(!GLM_struct->glGetProgramLocalParameterIivNVproc) return;
	GLM_struct->glGetProgramLocalParameterIivNVproc(target, index, params);
}
void APIENTRY glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint* params){
	if(!GLM_struct->glGetProgramLocalParameterIuivNVproc) return;
	GLM_struct->glGetProgramLocalParameterIuivNVproc(target, index, params);
}
void APIENTRY glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint* params){
	if(!GLM_struct->glGetProgramEnvParameterIivNVproc) return;
	GLM_struct->glGetProgramEnvParameterIivNVproc(target, index, params);
}
void APIENTRY glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint* params){
	if(!GLM_struct->glGetProgramEnvParameterIuivNVproc) return;
	GLM_struct->glGetProgramEnvParameterIuivNVproc(target, index, params);
}
void APIENTRY glProgramSubroutineParametersuivNV(GLenum target, GLsizei count, const GLuint* params){
	if(!GLM_struct->glProgramSubroutineParametersuivNVproc) return;
	GLM_struct->glProgramSubroutineParametersuivNVproc(target, count, params);
}
void APIENTRY glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint* param){
	if(!GLM_struct->glGetProgramSubroutineParameteruivNVproc) return;
	GLM_struct->glGetProgramSubroutineParameteruivNVproc(target, index, param);
}
void APIENTRY glVertex2hNV(GLhalfNV x, GLhalfNV y){
	if(!GLM_struct->glVertex2hNVproc) return;
	GLM_struct->glVertex2hNVproc(x, y);
}
void APIENTRY glVertex2hvNV(const GLhalfNV* v){
	if(!GLM_struct->glVertex2hvNVproc) return;
	GLM_struct->glVertex2hvNVproc(v);
}
void APIENTRY glVertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z){
	if(!GLM_struct->glVertex3hNVproc) return;
	GLM_struct->glVertex3hNVproc(x, y, z);
}
void APIENTRY glVertex3hvNV(const GLhalfNV* v){
	if(!GLM_struct->glVertex3hvNVproc) return;
	GLM_struct->glVertex3hvNVproc(v);
}
void APIENTRY glVertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w){
	if(!GLM_struct->glVertex4hNVproc) return;
	GLM_struct->glVertex4hNVproc(x, y, z, w);
}
void APIENTRY glVertex4hvNV(const GLhalfNV* v){
	if(!GLM_struct->glVertex4hvNVproc) return;
	GLM_struct->glVertex4hvNVproc(v);
}
void APIENTRY glNormal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz){
	if(!GLM_struct->glNormal3hNVproc) return;
	GLM_struct->glNormal3hNVproc(nx, ny, nz);
}
void APIENTRY glNormal3hvNV(const GLhalfNV* v){
	if(!GLM_struct->glNormal3hvNVproc) return;
	GLM_struct->glNormal3hvNVproc(v);
}
void APIENTRY glColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue){
	if(!GLM_struct->glColor3hNVproc) return;
	GLM_struct->glColor3hNVproc(red, green, blue);
}
void APIENTRY glColor3hvNV(const GLhalfNV* v){
	if(!GLM_struct->glColor3hvNVproc) return;
	GLM_struct->glColor3hvNVproc(v);
}
void APIENTRY glColor4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha){
	if(!GLM_struct->glColor4hNVproc) return;
	GLM_struct->glColor4hNVproc(red, green, blue, alpha);
}
void APIENTRY glColor4hvNV(const GLhalfNV* v){
	if(!GLM_struct->glColor4hvNVproc) return;
	GLM_struct->glColor4hvNVproc(v);
}
void APIENTRY glTexCoord1hNV(GLhalfNV s){
	if(!GLM_struct->glTexCoord1hNVproc) return;
	GLM_struct->glTexCoord1hNVproc(s);
}
void APIENTRY glTexCoord1hvNV(const GLhalfNV* v){
	if(!GLM_struct->glTexCoord1hvNVproc) return;
	GLM_struct->glTexCoord1hvNVproc(v);
}
void APIENTRY glTexCoord2hNV(GLhalfNV s, GLhalfNV t){
	if(!GLM_struct->glTexCoord2hNVproc) return;
	GLM_struct->glTexCoord2hNVproc(s, t);
}
void APIENTRY glTexCoord2hvNV(const GLhalfNV* v){
	if(!GLM_struct->glTexCoord2hvNVproc) return;
	GLM_struct->glTexCoord2hvNVproc(v);
}
void APIENTRY glTexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r){
	if(!GLM_struct->glTexCoord3hNVproc) return;
	GLM_struct->glTexCoord3hNVproc(s, t, r);
}
void APIENTRY glTexCoord3hvNV(const GLhalfNV* v){
	if(!GLM_struct->glTexCoord3hvNVproc) return;
	GLM_struct->glTexCoord3hvNVproc(v);
}
void APIENTRY glTexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q){
	if(!GLM_struct->glTexCoord4hNVproc) return;
	GLM_struct->glTexCoord4hNVproc(s, t, r, q);
}
void APIENTRY glTexCoord4hvNV(const GLhalfNV* v){
	if(!GLM_struct->glTexCoord4hvNVproc) return;
	GLM_struct->glTexCoord4hvNVproc(v);
}
void APIENTRY glMultiTexCoord1hNV(GLenum target, GLhalfNV s){
	if(!GLM_struct->glMultiTexCoord1hNVproc) return;
	GLM_struct->glMultiTexCoord1hNVproc(target, s);
}
void APIENTRY glMultiTexCoord1hvNV(GLenum target, const GLhalfNV* v){
	if(!GLM_struct->glMultiTexCoord1hvNVproc) return;
	GLM_struct->glMultiTexCoord1hvNVproc(target, v);
}
void APIENTRY glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t){
	if(!GLM_struct->glMultiTexCoord2hNVproc) return;
	GLM_struct->glMultiTexCoord2hNVproc(target, s, t);
}
void APIENTRY glMultiTexCoord2hvNV(GLenum target, const GLhalfNV* v){
	if(!GLM_struct->glMultiTexCoord2hvNVproc) return;
	GLM_struct->glMultiTexCoord2hvNVproc(target, v);
}
void APIENTRY glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r){
	if(!GLM_struct->glMultiTexCoord3hNVproc) return;
	GLM_struct->glMultiTexCoord3hNVproc(target, s, t, r);
}
void APIENTRY glMultiTexCoord3hvNV(GLenum target, const GLhalfNV* v){
	if(!GLM_struct->glMultiTexCoord3hvNVproc) return;
	GLM_struct->glMultiTexCoord3hvNVproc(target, v);
}
void APIENTRY glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q){
	if(!GLM_struct->glMultiTexCoord4hNVproc) return;
	GLM_struct->glMultiTexCoord4hNVproc(target, s, t, r, q);
}
void APIENTRY glMultiTexCoord4hvNV(GLenum target, const GLhalfNV* v){
	if(!GLM_struct->glMultiTexCoord4hvNVproc) return;
	GLM_struct->glMultiTexCoord4hvNVproc(target, v);
}
void APIENTRY glVertexAttrib1hNV(GLuint index, GLhalfNV x){
	if(!GLM_struct->glVertexAttrib1hNVproc) return;
	GLM_struct->glVertexAttrib1hNVproc(index, x);
}
void APIENTRY glVertexAttrib1hvNV(GLuint index, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttrib1hvNVproc) return;
	GLM_struct->glVertexAttrib1hvNVproc(index, v);
}
void APIENTRY glVertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y){
	if(!GLM_struct->glVertexAttrib2hNVproc) return;
	GLM_struct->glVertexAttrib2hNVproc(index, x, y);
}
void APIENTRY glVertexAttrib2hvNV(GLuint index, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttrib2hvNVproc) return;
	GLM_struct->glVertexAttrib2hvNVproc(index, v);
}
void APIENTRY glVertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z){
	if(!GLM_struct->glVertexAttrib3hNVproc) return;
	GLM_struct->glVertexAttrib3hNVproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3hvNV(GLuint index, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttrib3hvNVproc) return;
	GLM_struct->glVertexAttrib3hvNVproc(index, v);
}
void APIENTRY glVertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w){
	if(!GLM_struct->glVertexAttrib4hNVproc) return;
	GLM_struct->glVertexAttrib4hNVproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4hvNV(GLuint index, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttrib4hvNVproc) return;
	GLM_struct->glVertexAttrib4hvNVproc(index, v);
}
void APIENTRY glVertexAttribs1hvNV(GLuint index, GLsizei n, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttribs1hvNVproc) return;
	GLM_struct->glVertexAttribs1hvNVproc(index, n, v);
}
void APIENTRY glVertexAttribs2hvNV(GLuint index, GLsizei n, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttribs2hvNVproc) return;
	GLM_struct->glVertexAttribs2hvNVproc(index, n, v);
}
void APIENTRY glVertexAttribs3hvNV(GLuint index, GLsizei n, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttribs3hvNVproc) return;
	GLM_struct->glVertexAttribs3hvNVproc(index, n, v);
}
void APIENTRY glVertexAttribs4hvNV(GLuint index, GLsizei n, const GLhalfNV* v){
	if(!GLM_struct->glVertexAttribs4hvNVproc) return;
	GLM_struct->glVertexAttribs4hvNVproc(index, n, v);
}
void APIENTRY glFogCoordhNV(GLhalfNV fog){
	if(!GLM_struct->glFogCoordhNVproc) return;
	GLM_struct->glFogCoordhNVproc(fog);
}
void APIENTRY glFogCoordhvNV(const GLhalfNV* fog){
	if(!GLM_struct->glFogCoordhvNVproc) return;
	GLM_struct->glFogCoordhvNVproc(fog);
}
void APIENTRY glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue){
	if(!GLM_struct->glSecondaryColor3hNVproc) return;
	GLM_struct->glSecondaryColor3hNVproc(red, green, blue);
}
void APIENTRY glSecondaryColor3hvNV(const GLhalfNV* v){
	if(!GLM_struct->glSecondaryColor3hvNVproc) return;
	GLM_struct->glSecondaryColor3hvNVproc(v);
}
void APIENTRY glVertexWeighthNV(GLhalfNV weight){
	if(!GLM_struct->glVertexWeighthNVproc) return;
	GLM_struct->glVertexWeighthNVproc(weight);
}
void APIENTRY glVertexWeighthvNV(const GLhalfNV* weight){
	if(!GLM_struct->glVertexWeighthvNVproc) return;
	GLM_struct->glVertexWeighthvNVproc(weight);
}
void APIENTRY glGetInternalformatSampleivNV(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint* params){
	if(!GLM_struct->glGetInternalformatSampleivNVproc) return;
	GLM_struct->glGetInternalformatSampleivNVproc(target, internalformat, samples, pname, count, params);
}
void APIENTRY glGetMemoryObjectDetachedResourcesuivNV(GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint* params){
	if(!GLM_struct->glGetMemoryObjectDetachedResourcesuivNVproc) return;
	GLM_struct->glGetMemoryObjectDetachedResourcesuivNVproc(memory, pname, first, count, params);
}
void APIENTRY glResetMemoryObjectParameterNV(GLuint memory, GLenum pname){
	if(!GLM_struct->glResetMemoryObjectParameterNVproc) return;
	GLM_struct->glResetMemoryObjectParameterNVproc(memory, pname);
}
void APIENTRY glTexAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTexAttachMemoryNVproc) return;
	GLM_struct->glTexAttachMemoryNVproc(target, memory, offset);
}
void APIENTRY glBufferAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glBufferAttachMemoryNVproc) return;
	GLM_struct->glBufferAttachMemoryNVproc(target, memory, offset);
}
void APIENTRY glTextureAttachMemoryNV(GLuint texture, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glTextureAttachMemoryNVproc) return;
	GLM_struct->glTextureAttachMemoryNVproc(texture, memory, offset);
}
void APIENTRY glNamedBufferAttachMemoryNV(GLuint buffer, GLuint memory, GLuint64 offset){
	if(!GLM_struct->glNamedBufferAttachMemoryNVproc) return;
	GLM_struct->glNamedBufferAttachMemoryNVproc(buffer, memory, offset);
}
void APIENTRY glBufferPageCommitmentMemNV(GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit){
	if(!GLM_struct->glBufferPageCommitmentMemNVproc) return;
	GLM_struct->glBufferPageCommitmentMemNVproc(target, offset, size, memory, memOffset, commit);
}
void APIENTRY glTexPageCommitmentMemNV(GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit){
	if(!GLM_struct->glTexPageCommitmentMemNVproc) return;
	GLM_struct->glTexPageCommitmentMemNVproc(target, layer, level, xoffset, yoffset, zoffset, width, height, depth, memory, offset, commit);
}
void APIENTRY glNamedBufferPageCommitmentMemNV(GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit){
	if(!GLM_struct->glNamedBufferPageCommitmentMemNVproc) return;
	GLM_struct->glNamedBufferPageCommitmentMemNVproc(buffer, offset, size, memory, memOffset, commit);
}
void APIENTRY glTexturePageCommitmentMemNV(GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit){
	if(!GLM_struct->glTexturePageCommitmentMemNVproc) return;
	GLM_struct->glTexturePageCommitmentMemNVproc(texture, layer, level, xoffset, yoffset, zoffset, width, height, depth, memory, offset, commit);
}
void APIENTRY glDrawMeshTasksNV(GLuint first, GLuint count){
	if(!GLM_struct->glDrawMeshTasksNVproc) return;
	GLM_struct->glDrawMeshTasksNVproc(first, count);
}
void APIENTRY glDrawMeshTasksIndirectNV(GLintptr indirect){
	if(!GLM_struct->glDrawMeshTasksIndirectNVproc) return;
	GLM_struct->glDrawMeshTasksIndirectNVproc(indirect);
}
void APIENTRY glMultiDrawMeshTasksIndirectNV(GLintptr indirect, GLsizei drawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawMeshTasksIndirectNVproc) return;
	GLM_struct->glMultiDrawMeshTasksIndirectNVproc(indirect, drawcount, stride);
}
void APIENTRY glMultiDrawMeshTasksIndirectCountNV(GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride){
	if(!GLM_struct->glMultiDrawMeshTasksIndirectCountNVproc) return;
	GLM_struct->glMultiDrawMeshTasksIndirectCountNVproc(indirect, drawcount, maxdrawcount, stride);
}
void APIENTRY glGenOcclusionQueriesNV(GLsizei n, GLuint* ids){
	if(!GLM_struct->glGenOcclusionQueriesNVproc) return;
	GLM_struct->glGenOcclusionQueriesNVproc(n, ids);
}
void APIENTRY glDeleteOcclusionQueriesNV(GLsizei n, const GLuint* ids){
	if(!GLM_struct->glDeleteOcclusionQueriesNVproc) return;
	GLM_struct->glDeleteOcclusionQueriesNVproc(n, ids);
}
GLboolean APIENTRY glIsOcclusionQueryNV(GLuint id){
	if(!GLM_struct->glIsOcclusionQueryNVproc) return 0;
	return GLM_struct->glIsOcclusionQueryNVproc(id);
}
void APIENTRY glBeginOcclusionQueryNV(GLuint id){
	if(!GLM_struct->glBeginOcclusionQueryNVproc) return;
	GLM_struct->glBeginOcclusionQueryNVproc(id);
}
void APIENTRY glEndOcclusionQueryNV(void){
	if(!GLM_struct->glEndOcclusionQueryNVproc) return;
	GLM_struct->glEndOcclusionQueryNVproc();
}
void APIENTRY glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint* params){
	if(!GLM_struct->glGetOcclusionQueryivNVproc) return;
	GLM_struct->glGetOcclusionQueryivNVproc(id, pname, params);
}
void APIENTRY glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetOcclusionQueryuivNVproc) return;
	GLM_struct->glGetOcclusionQueryuivNVproc(id, pname, params);
}
void APIENTRY glProgramBufferParametersfvNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat* params){
	if(!GLM_struct->glProgramBufferParametersfvNVproc) return;
	GLM_struct->glProgramBufferParametersfvNVproc(target, bindingIndex, wordIndex, count, params);
}
void APIENTRY glProgramBufferParametersIivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint* params){
	if(!GLM_struct->glProgramBufferParametersIivNVproc) return;
	GLM_struct->glProgramBufferParametersIivNVproc(target, bindingIndex, wordIndex, count, params);
}
void APIENTRY glProgramBufferParametersIuivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint* params){
	if(!GLM_struct->glProgramBufferParametersIuivNVproc) return;
	GLM_struct->glProgramBufferParametersIuivNVproc(target, bindingIndex, wordIndex, count, params);
}
GLuint APIENTRY glGenPathsNV(GLsizei range){
	if(!GLM_struct->glGenPathsNVproc) return 0;
	return GLM_struct->glGenPathsNVproc(range);
}
void APIENTRY glDeletePathsNV(GLuint path, GLsizei range){
	if(!GLM_struct->glDeletePathsNVproc) return;
	GLM_struct->glDeletePathsNVproc(path, range);
}
GLboolean APIENTRY glIsPathNV(GLuint path){
	if(!GLM_struct->glIsPathNVproc) return 0;
	return GLM_struct->glIsPathNVproc(path);
}
void APIENTRY glPathCommandsNV(GLuint path, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void* coords){
	if(!GLM_struct->glPathCommandsNVproc) return;
	GLM_struct->glPathCommandsNVproc(path, numCommands, commands, numCoords, coordType, coords);
}
void APIENTRY glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const void* coords){
	if(!GLM_struct->glPathCoordsNVproc) return;
	GLM_struct->glPathCoordsNVproc(path, numCoords, coordType, coords);
}
void APIENTRY glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void* coords){
	if(!GLM_struct->glPathSubCommandsNVproc) return;
	GLM_struct->glPathSubCommandsNVproc(path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords);
}
void APIENTRY glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void* coords){
	if(!GLM_struct->glPathSubCoordsNVproc) return;
	GLM_struct->glPathSubCoordsNVproc(path, coordStart, numCoords, coordType, coords);
}
void APIENTRY glPathStringNV(GLuint path, GLenum format, GLsizei length, const void* pathString){
	if(!GLM_struct->glPathStringNVproc) return;
	GLM_struct->glPathStringNVproc(path, format, length, pathString);
}
void APIENTRY glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void* charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale){
	if(!GLM_struct->glPathGlyphsNVproc) return;
	GLM_struct->glPathGlyphsNVproc(firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale);
}
void APIENTRY glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale){
	if(!GLM_struct->glPathGlyphRangeNVproc) return;
	GLM_struct->glPathGlyphRangeNVproc(firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale);
}
void APIENTRY glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights){
	if(!GLM_struct->glWeightPathsNVproc) return;
	GLM_struct->glWeightPathsNVproc(resultPath, numPaths, paths, weights);
}
void APIENTRY glCopyPathNV(GLuint resultPath, GLuint srcPath){
	if(!GLM_struct->glCopyPathNVproc) return;
	GLM_struct->glCopyPathNVproc(resultPath, srcPath);
}
void APIENTRY glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight){
	if(!GLM_struct->glInterpolatePathsNVproc) return;
	GLM_struct->glInterpolatePathsNVproc(resultPath, pathA, pathB, weight);
}
void APIENTRY glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues){
	if(!GLM_struct->glTransformPathNVproc) return;
	GLM_struct->glTransformPathNVproc(resultPath, srcPath, transformType, transformValues);
}
void APIENTRY glPathParameterivNV(GLuint path, GLenum pname, const GLint* value){
	if(!GLM_struct->glPathParameterivNVproc) return;
	GLM_struct->glPathParameterivNVproc(path, pname, value);
}
void APIENTRY glPathParameteriNV(GLuint path, GLenum pname, GLint value){
	if(!GLM_struct->glPathParameteriNVproc) return;
	GLM_struct->glPathParameteriNVproc(path, pname, value);
}
void APIENTRY glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat* value){
	if(!GLM_struct->glPathParameterfvNVproc) return;
	GLM_struct->glPathParameterfvNVproc(path, pname, value);
}
void APIENTRY glPathParameterfNV(GLuint path, GLenum pname, GLfloat value){
	if(!GLM_struct->glPathParameterfNVproc) return;
	GLM_struct->glPathParameterfNVproc(path, pname, value);
}
void APIENTRY glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat* dashArray){
	if(!GLM_struct->glPathDashArrayNVproc) return;
	GLM_struct->glPathDashArrayNVproc(path, dashCount, dashArray);
}
void APIENTRY glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask){
	if(!GLM_struct->glPathStencilFuncNVproc) return;
	GLM_struct->glPathStencilFuncNVproc(func, ref, mask);
}
void APIENTRY glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units){
	if(!GLM_struct->glPathStencilDepthOffsetNVproc) return;
	GLM_struct->glPathStencilDepthOffsetNVproc(factor, units);
}
void APIENTRY glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask){
	if(!GLM_struct->glStencilFillPathNVproc) return;
	GLM_struct->glStencilFillPathNVproc(path, fillMode, mask);
}
void APIENTRY glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask){
	if(!GLM_struct->glStencilStrokePathNVproc) return;
	GLM_struct->glStencilStrokePathNVproc(path, reference, mask);
}
void APIENTRY glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat* transformValues){
	if(!GLM_struct->glStencilFillPathInstancedNVproc) return;
	GLM_struct->glStencilFillPathInstancedNVproc(numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues);
}
void APIENTRY glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat* transformValues){
	if(!GLM_struct->glStencilStrokePathInstancedNVproc) return;
	GLM_struct->glStencilStrokePathInstancedNVproc(numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues);
}
void APIENTRY glPathCoverDepthFuncNV(GLenum func){
	if(!GLM_struct->glPathCoverDepthFuncNVproc) return;
	GLM_struct->glPathCoverDepthFuncNVproc(func);
}
void APIENTRY glCoverFillPathNV(GLuint path, GLenum coverMode){
	if(!GLM_struct->glCoverFillPathNVproc) return;
	GLM_struct->glCoverFillPathNVproc(path, coverMode);
}
void APIENTRY glCoverStrokePathNV(GLuint path, GLenum coverMode){
	if(!GLM_struct->glCoverStrokePathNVproc) return;
	GLM_struct->glCoverStrokePathNVproc(path, coverMode);
}
void APIENTRY glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues){
	if(!GLM_struct->glCoverFillPathInstancedNVproc) return;
	GLM_struct->glCoverFillPathInstancedNVproc(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}
void APIENTRY glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues){
	if(!GLM_struct->glCoverStrokePathInstancedNVproc) return;
	GLM_struct->glCoverStrokePathInstancedNVproc(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}
void APIENTRY glGetPathParameterivNV(GLuint path, GLenum pname, GLint* value){
	if(!GLM_struct->glGetPathParameterivNVproc) return;
	GLM_struct->glGetPathParameterivNVproc(path, pname, value);
}
void APIENTRY glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat* value){
	if(!GLM_struct->glGetPathParameterfvNVproc) return;
	GLM_struct->glGetPathParameterfvNVproc(path, pname, value);
}
void APIENTRY glGetPathCommandsNV(GLuint path, GLubyte* commands){
	if(!GLM_struct->glGetPathCommandsNVproc) return;
	GLM_struct->glGetPathCommandsNVproc(path, commands);
}
void APIENTRY glGetPathCoordsNV(GLuint path, GLfloat* coords){
	if(!GLM_struct->glGetPathCoordsNVproc) return;
	GLM_struct->glGetPathCoordsNVproc(path, coords);
}
void APIENTRY glGetPathDashArrayNV(GLuint path, GLfloat* dashArray){
	if(!GLM_struct->glGetPathDashArrayNVproc) return;
	GLM_struct->glGetPathDashArrayNVproc(path, dashArray);
}
void APIENTRY glGetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLsizei stride, GLfloat* metrics){
	if(!GLM_struct->glGetPathMetricsNVproc) return;
	GLM_struct->glGetPathMetricsNVproc(metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics);
}
void APIENTRY glGetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat* metrics){
	if(!GLM_struct->glGetPathMetricRangeNVproc) return;
	GLM_struct->glGetPathMetricRangeNVproc(metricQueryMask, firstPathName, numPaths, stride, metrics);
}
void APIENTRY glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat* returnedSpacing){
	if(!GLM_struct->glGetPathSpacingNVproc) return;
	GLM_struct->glGetPathSpacingNVproc(pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing);
}
GLboolean APIENTRY glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y){
	if(!GLM_struct->glIsPointInFillPathNVproc) return 0;
	return GLM_struct->glIsPointInFillPathNVproc(path, mask, x, y);
}
GLboolean APIENTRY glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y){
	if(!GLM_struct->glIsPointInStrokePathNVproc) return 0;
	return GLM_struct->glIsPointInStrokePathNVproc(path, x, y);
}
GLfloat APIENTRY glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments){
	if(!GLM_struct->glGetPathLengthNVproc) return 0;
	return GLM_struct->glGetPathLengthNVproc(path, startSegment, numSegments);
}
GLboolean APIENTRY glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat* x, GLfloat* y, GLfloat* tangentX, GLfloat* tangentY){
	if(!GLM_struct->glPointAlongPathNVproc) return 0;
	return GLM_struct->glPointAlongPathNVproc(path, startSegment, numSegments, distance, x, y, tangentX, tangentY);
}
void APIENTRY glMatrixLoad3x2fNV(GLenum matrixMode, const GLfloat* m){
	if(!GLM_struct->glMatrixLoad3x2fNVproc) return;
	GLM_struct->glMatrixLoad3x2fNVproc(matrixMode, m);
}
void APIENTRY glMatrixLoad3x3fNV(GLenum matrixMode, const GLfloat* m){
	if(!GLM_struct->glMatrixLoad3x3fNVproc) return;
	GLM_struct->glMatrixLoad3x3fNVproc(matrixMode, m);
}
void APIENTRY glMatrixLoadTranspose3x3fNV(GLenum matrixMode, const GLfloat* m){
	if(!GLM_struct->glMatrixLoadTranspose3x3fNVproc) return;
	GLM_struct->glMatrixLoadTranspose3x3fNVproc(matrixMode, m);
}
void APIENTRY glMatrixMult3x2fNV(GLenum matrixMode, const GLfloat* m){
	if(!GLM_struct->glMatrixMult3x2fNVproc) return;
	GLM_struct->glMatrixMult3x2fNVproc(matrixMode, m);
}
void APIENTRY glMatrixMult3x3fNV(GLenum matrixMode, const GLfloat* m){
	if(!GLM_struct->glMatrixMult3x3fNVproc) return;
	GLM_struct->glMatrixMult3x3fNVproc(matrixMode, m);
}
void APIENTRY glMatrixMultTranspose3x3fNV(GLenum matrixMode, const GLfloat* m){
	if(!GLM_struct->glMatrixMultTranspose3x3fNVproc) return;
	GLM_struct->glMatrixMultTranspose3x3fNVproc(matrixMode, m);
}
void APIENTRY glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode){
	if(!GLM_struct->glStencilThenCoverFillPathNVproc) return;
	GLM_struct->glStencilThenCoverFillPathNVproc(path, fillMode, mask, coverMode);
}
void APIENTRY glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode){
	if(!GLM_struct->glStencilThenCoverStrokePathNVproc) return;
	GLM_struct->glStencilThenCoverStrokePathNVproc(path, reference, mask, coverMode);
}
void APIENTRY glStencilThenCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues){
	if(!GLM_struct->glStencilThenCoverFillPathInstancedNVproc) return;
	GLM_struct->glStencilThenCoverFillPathInstancedNVproc(numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues);
}
void APIENTRY glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues){
	if(!GLM_struct->glStencilThenCoverStrokePathInstancedNVproc) return;
	GLM_struct->glStencilThenCoverStrokePathInstancedNVproc(numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues);
}
GLenum APIENTRY glPathGlyphIndexRangeNV(GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint* baseAndCount){
	if(!GLM_struct->glPathGlyphIndexRangeNVproc) return 0;
	return GLM_struct->glPathGlyphIndexRangeNVproc(fontTarget, fontName, fontStyle, pathParameterTemplate, emScale, baseAndCount);
}
GLenum APIENTRY glPathGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale){
	if(!GLM_struct->glPathGlyphIndexArrayNVproc) return 0;
	return GLM_struct->glPathGlyphIndexArrayNVproc(firstPathName, fontTarget, fontName, fontStyle, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}
GLenum APIENTRY glPathMemoryGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void* fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale){
	if(!GLM_struct->glPathMemoryGlyphIndexArrayNVproc) return 0;
	return GLM_struct->glPathMemoryGlyphIndexArrayNVproc(firstPathName, fontTarget, fontSize, fontData, faceIndex, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}
void APIENTRY glProgramPathFragmentInputGenNV(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat* coeffs){
	if(!GLM_struct->glProgramPathFragmentInputGenNVproc) return;
	GLM_struct->glProgramPathFragmentInputGenNVproc(program, location, genMode, components, coeffs);
}
void APIENTRY glGetProgramResourcefvNV(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLfloat* params){
	if(!GLM_struct->glGetProgramResourcefvNVproc) return;
	GLM_struct->glGetProgramResourcefvNVproc(program, programInterface, index, propCount, props, count, length, params);
}
void APIENTRY glPathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat* coeffs){
	if(!GLM_struct->glPathColorGenNVproc) return;
	GLM_struct->glPathColorGenNVproc(color, genMode, colorFormat, coeffs);
}
void APIENTRY glPathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat* coeffs){
	if(!GLM_struct->glPathTexGenNVproc) return;
	GLM_struct->glPathTexGenNVproc(texCoordSet, genMode, components, coeffs);
}
void APIENTRY glPathFogGenNV(GLenum genMode){
	if(!GLM_struct->glPathFogGenNVproc) return;
	GLM_struct->glPathFogGenNVproc(genMode);
}
void APIENTRY glGetPathColorGenivNV(GLenum color, GLenum pname, GLint* value){
	if(!GLM_struct->glGetPathColorGenivNVproc) return;
	GLM_struct->glGetPathColorGenivNVproc(color, pname, value);
}
void APIENTRY glGetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat* value){
	if(!GLM_struct->glGetPathColorGenfvNVproc) return;
	GLM_struct->glGetPathColorGenfvNVproc(color, pname, value);
}
void APIENTRY glGetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint* value){
	if(!GLM_struct->glGetPathTexGenivNVproc) return;
	GLM_struct->glGetPathTexGenivNVproc(texCoordSet, pname, value);
}
void APIENTRY glGetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat* value){
	if(!GLM_struct->glGetPathTexGenfvNVproc) return;
	GLM_struct->glGetPathTexGenfvNVproc(texCoordSet, pname, value);
}
void APIENTRY glPixelDataRangeNV(GLenum target, GLsizei length, const void* pointer){
	if(!GLM_struct->glPixelDataRangeNVproc) return;
	GLM_struct->glPixelDataRangeNVproc(target, length, pointer);
}
void APIENTRY glFlushPixelDataRangeNV(GLenum target){
	if(!GLM_struct->glFlushPixelDataRangeNVproc) return;
	GLM_struct->glFlushPixelDataRangeNVproc(target);
}
void APIENTRY glPointParameteriNV(GLenum pname, GLint param){
	if(!GLM_struct->glPointParameteriNVproc) return;
	GLM_struct->glPointParameteriNVproc(pname, param);
}
void APIENTRY glPointParameterivNV(GLenum pname, const GLint* params){
	if(!GLM_struct->glPointParameterivNVproc) return;
	GLM_struct->glPointParameterivNVproc(pname, params);
}
void APIENTRY glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1){
	if(!GLM_struct->glPresentFrameKeyedNVproc) return;
	GLM_struct->glPresentFrameKeyedNVproc(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, key0, target1, fill1, key1);
}
void APIENTRY glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3){
	if(!GLM_struct->glPresentFrameDualFillNVproc) return;
	GLM_struct->glPresentFrameDualFillNVproc(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, target1, fill1, target2, fill2, target3, fill3);
}
void APIENTRY glGetVideoivNV(GLuint video_slot, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVideoivNVproc) return;
	GLM_struct->glGetVideoivNVproc(video_slot, pname, params);
}
void APIENTRY glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint* params){
	if(!GLM_struct->glGetVideouivNVproc) return;
	GLM_struct->glGetVideouivNVproc(video_slot, pname, params);
}
void APIENTRY glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT* params){
	if(!GLM_struct->glGetVideoi64vNVproc) return;
	GLM_struct->glGetVideoi64vNVproc(video_slot, pname, params);
}
void APIENTRY glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT* params){
	if(!GLM_struct->glGetVideoui64vNVproc) return;
	GLM_struct->glGetVideoui64vNVproc(video_slot, pname, params);
}
void APIENTRY glPrimitiveRestartNV(void){
	if(!GLM_struct->glPrimitiveRestartNVproc) return;
	GLM_struct->glPrimitiveRestartNVproc();
}
void APIENTRY glPrimitiveRestartIndexNV(GLuint index){
	if(!GLM_struct->glPrimitiveRestartIndexNVproc) return;
	GLM_struct->glPrimitiveRestartIndexNVproc(index);
}
GLint APIENTRY glQueryResourceNV(GLenum queryType, GLint tagId, GLuint count, GLint* buffer){
	if(!GLM_struct->glQueryResourceNVproc) return 0;
	return GLM_struct->glQueryResourceNVproc(queryType, tagId, count, buffer);
}
void APIENTRY glGenQueryResourceTagNV(GLsizei n, GLint* tagIds){
	if(!GLM_struct->glGenQueryResourceTagNVproc) return;
	GLM_struct->glGenQueryResourceTagNVproc(n, tagIds);
}
void APIENTRY glDeleteQueryResourceTagNV(GLsizei n, const GLint* tagIds){
	if(!GLM_struct->glDeleteQueryResourceTagNVproc) return;
	GLM_struct->glDeleteQueryResourceTagNVproc(n, tagIds);
}
void APIENTRY glQueryResourceTagNV(GLint tagId, const GLchar* tagString){
	if(!GLM_struct->glQueryResourceTagNVproc) return;
	GLM_struct->glQueryResourceTagNVproc(tagId, tagString);
}
void APIENTRY glCombinerParameterfvNV(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glCombinerParameterfvNVproc) return;
	GLM_struct->glCombinerParameterfvNVproc(pname, params);
}
void APIENTRY glCombinerParameterfNV(GLenum pname, GLfloat param){
	if(!GLM_struct->glCombinerParameterfNVproc) return;
	GLM_struct->glCombinerParameterfNVproc(pname, param);
}
void APIENTRY glCombinerParameterivNV(GLenum pname, const GLint* params){
	if(!GLM_struct->glCombinerParameterivNVproc) return;
	GLM_struct->glCombinerParameterivNVproc(pname, params);
}
void APIENTRY glCombinerParameteriNV(GLenum pname, GLint param){
	if(!GLM_struct->glCombinerParameteriNVproc) return;
	GLM_struct->glCombinerParameteriNVproc(pname, param);
}
void APIENTRY glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage){
	if(!GLM_struct->glCombinerInputNVproc) return;
	GLM_struct->glCombinerInputNVproc(stage, portion, variable, input, mapping, componentUsage);
}
void APIENTRY glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum){
	if(!GLM_struct->glCombinerOutputNVproc) return;
	GLM_struct->glCombinerOutputNVproc(stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum);
}
void APIENTRY glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage){
	if(!GLM_struct->glFinalCombinerInputNVproc) return;
	GLM_struct->glFinalCombinerInputNVproc(variable, input, mapping, componentUsage);
}
void APIENTRY glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetCombinerInputParameterfvNVproc) return;
	GLM_struct->glGetCombinerInputParameterfvNVproc(stage, portion, variable, pname, params);
}
void APIENTRY glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params){
	if(!GLM_struct->glGetCombinerInputParameterivNVproc) return;
	GLM_struct->glGetCombinerInputParameterivNVproc(stage, portion, variable, pname, params);
}
void APIENTRY glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetCombinerOutputParameterfvNVproc) return;
	GLM_struct->glGetCombinerOutputParameterfvNVproc(stage, portion, pname, params);
}
void APIENTRY glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint* params){
	if(!GLM_struct->glGetCombinerOutputParameterivNVproc) return;
	GLM_struct->glGetCombinerOutputParameterivNVproc(stage, portion, pname, params);
}
void APIENTRY glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetFinalCombinerInputParameterfvNVproc) return;
	GLM_struct->glGetFinalCombinerInputParameterfvNVproc(variable, pname, params);
}
void APIENTRY glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFinalCombinerInputParameterivNVproc) return;
	GLM_struct->glGetFinalCombinerInputParameterivNVproc(variable, pname, params);
}
void APIENTRY glCombinerStageParameterfvNV(GLenum stage, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glCombinerStageParameterfvNVproc) return;
	GLM_struct->glCombinerStageParameterfvNVproc(stage, pname, params);
}
void APIENTRY glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetCombinerStageParameterfvNVproc) return;
	GLM_struct->glGetCombinerStageParameterfvNVproc(stage, pname, params);
}
void APIENTRY glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glFramebufferSampleLocationsfvNVproc) return;
	GLM_struct->glFramebufferSampleLocationsfvNVproc(target, start, count, v);
}
void APIENTRY glNamedFramebufferSampleLocationsfvNV(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glNamedFramebufferSampleLocationsfvNVproc) return;
	GLM_struct->glNamedFramebufferSampleLocationsfvNVproc(framebuffer, start, count, v);
}
void APIENTRY glResolveDepthValuesNV(void){
	if(!GLM_struct->glResolveDepthValuesNVproc) return;
	GLM_struct->glResolveDepthValuesNVproc();
}
void APIENTRY glScissorExclusiveNV(GLint x, GLint y, GLsizei width, GLsizei height){
	if(!GLM_struct->glScissorExclusiveNVproc) return;
	GLM_struct->glScissorExclusiveNVproc(x, y, width, height);
}
void APIENTRY glScissorExclusiveArrayvNV(GLuint first, GLsizei count, const GLint* v){
	if(!GLM_struct->glScissorExclusiveArrayvNVproc) return;
	GLM_struct->glScissorExclusiveArrayvNVproc(first, count, v);
}
void APIENTRY glMakeBufferResidentNV(GLenum target, GLenum access){
	if(!GLM_struct->glMakeBufferResidentNVproc) return;
	GLM_struct->glMakeBufferResidentNVproc(target, access);
}
void APIENTRY glMakeBufferNonResidentNV(GLenum target){
	if(!GLM_struct->glMakeBufferNonResidentNVproc) return;
	GLM_struct->glMakeBufferNonResidentNVproc(target);
}
GLboolean APIENTRY glIsBufferResidentNV(GLenum target){
	if(!GLM_struct->glIsBufferResidentNVproc) return 0;
	return GLM_struct->glIsBufferResidentNVproc(target);
}
void APIENTRY glMakeNamedBufferResidentNV(GLuint buffer, GLenum access){
	if(!GLM_struct->glMakeNamedBufferResidentNVproc) return;
	GLM_struct->glMakeNamedBufferResidentNVproc(buffer, access);
}
void APIENTRY glMakeNamedBufferNonResidentNV(GLuint buffer){
	if(!GLM_struct->glMakeNamedBufferNonResidentNVproc) return;
	GLM_struct->glMakeNamedBufferNonResidentNVproc(buffer);
}
GLboolean APIENTRY glIsNamedBufferResidentNV(GLuint buffer){
	if(!GLM_struct->glIsNamedBufferResidentNVproc) return 0;
	return GLM_struct->glIsNamedBufferResidentNVproc(buffer);
}
void APIENTRY glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT* params){
	if(!GLM_struct->glGetBufferParameterui64vNVproc) return;
	GLM_struct->glGetBufferParameterui64vNVproc(target, pname, params);
}
void APIENTRY glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT* params){
	if(!GLM_struct->glGetNamedBufferParameterui64vNVproc) return;
	GLM_struct->glGetNamedBufferParameterui64vNVproc(buffer, pname, params);
}
void APIENTRY glGetIntegerui64vNV(GLenum value, GLuint64EXT* result){
	if(!GLM_struct->glGetIntegerui64vNVproc) return;
	GLM_struct->glGetIntegerui64vNVproc(value, result);
}
void APIENTRY glUniformui64NV(GLint location, GLuint64EXT value){
	if(!GLM_struct->glUniformui64NVproc) return;
	GLM_struct->glUniformui64NVproc(location, value);
}
void APIENTRY glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glUniformui64vNVproc) return;
	GLM_struct->glUniformui64vNVproc(location, count, value);
}
void APIENTRY glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value){
	if(!GLM_struct->glProgramUniformui64NVproc) return;
	GLM_struct->glProgramUniformui64NVproc(program, location, value);
}
void APIENTRY glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value){
	if(!GLM_struct->glProgramUniformui64vNVproc) return;
	GLM_struct->glProgramUniformui64vNVproc(program, location, count, value);
}
void APIENTRY glBindShadingRateImageNV(GLuint texture){
	if(!GLM_struct->glBindShadingRateImageNVproc) return;
	GLM_struct->glBindShadingRateImageNVproc(texture);
}
void APIENTRY glGetShadingRateImagePaletteNV(GLuint viewport, GLuint entry, GLenum* rate){
	if(!GLM_struct->glGetShadingRateImagePaletteNVproc) return;
	GLM_struct->glGetShadingRateImagePaletteNVproc(viewport, entry, rate);
}
void APIENTRY glGetShadingRateSampleLocationivNV(GLenum rate, GLuint samples, GLuint index, GLint* location){
	if(!GLM_struct->glGetShadingRateSampleLocationivNVproc) return;
	GLM_struct->glGetShadingRateSampleLocationivNVproc(rate, samples, index, location);
}
void APIENTRY glShadingRateImageBarrierNV(GLboolean synchronize){
	if(!GLM_struct->glShadingRateImageBarrierNVproc) return;
	GLM_struct->glShadingRateImageBarrierNVproc(synchronize);
}
void APIENTRY glShadingRateImagePaletteNV(GLuint viewport, GLuint first, GLsizei count, const GLenum* rates){
	if(!GLM_struct->glShadingRateImagePaletteNVproc) return;
	GLM_struct->glShadingRateImagePaletteNVproc(viewport, first, count, rates);
}
void APIENTRY glShadingRateSampleOrderNV(GLenum order){
	if(!GLM_struct->glShadingRateSampleOrderNVproc) return;
	GLM_struct->glShadingRateSampleOrderNVproc(order);
}
void APIENTRY glShadingRateSampleOrderCustomNV(GLenum rate, GLuint samples, const GLint* locations){
	if(!GLM_struct->glShadingRateSampleOrderCustomNVproc) return;
	GLM_struct->glShadingRateSampleOrderCustomNVproc(rate, samples, locations);
}
void APIENTRY glTextureBarrierNV(void){
	if(!GLM_struct->glTextureBarrierNVproc) return;
	GLM_struct->glTextureBarrierNVproc();
}
void APIENTRY glTexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations){
	if(!GLM_struct->glTexImage2DMultisampleCoverageNVproc) return;
	GLM_struct->glTexImage2DMultisampleCoverageNVproc(target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations);
}
void APIENTRY glTexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations){
	if(!GLM_struct->glTexImage3DMultisampleCoverageNVproc) return;
	GLM_struct->glTexImage3DMultisampleCoverageNVproc(target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations);
}
void APIENTRY glTextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations){
	if(!GLM_struct->glTextureImage2DMultisampleNVproc) return;
	GLM_struct->glTextureImage2DMultisampleNVproc(texture, target, samples, internalFormat, width, height, fixedSampleLocations);
}
void APIENTRY glTextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations){
	if(!GLM_struct->glTextureImage3DMultisampleNVproc) return;
	GLM_struct->glTextureImage3DMultisampleNVproc(texture, target, samples, internalFormat, width, height, depth, fixedSampleLocations);
}
void APIENTRY glTextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations){
	if(!GLM_struct->glTextureImage2DMultisampleCoverageNVproc) return;
	GLM_struct->glTextureImage2DMultisampleCoverageNVproc(texture, target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations);
}
void APIENTRY glTextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations){
	if(!GLM_struct->glTextureImage3DMultisampleCoverageNVproc) return;
	GLM_struct->glTextureImage3DMultisampleCoverageNVproc(texture, target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations);
}
void APIENTRY glCreateSemaphoresNV(GLsizei n, GLuint* semaphores){
	if(!GLM_struct->glCreateSemaphoresNVproc) return;
	GLM_struct->glCreateSemaphoresNVproc(n, semaphores);
}
void APIENTRY glSemaphoreParameterivNV(GLuint semaphore, GLenum pname, const GLint* params){
	if(!GLM_struct->glSemaphoreParameterivNVproc) return;
	GLM_struct->glSemaphoreParameterivNVproc(semaphore, pname, params);
}
void APIENTRY glGetSemaphoreParameterivNV(GLuint semaphore, GLenum pname, GLint* params){
	if(!GLM_struct->glGetSemaphoreParameterivNVproc) return;
	GLM_struct->glGetSemaphoreParameterivNVproc(semaphore, pname, params);
}
void APIENTRY glBeginTransformFeedbackNV(GLenum primitiveMode){
	if(!GLM_struct->glBeginTransformFeedbackNVproc) return;
	GLM_struct->glBeginTransformFeedbackNVproc(primitiveMode);
}
void APIENTRY glEndTransformFeedbackNV(void){
	if(!GLM_struct->glEndTransformFeedbackNVproc) return;
	GLM_struct->glEndTransformFeedbackNVproc();
}
void APIENTRY glTransformFeedbackAttribsNV(GLsizei count, const GLint* attribs, GLenum bufferMode){
	if(!GLM_struct->glTransformFeedbackAttribsNVproc) return;
	GLM_struct->glTransformFeedbackAttribsNVproc(count, attribs, bufferMode);
}
void APIENTRY glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size){
	if(!GLM_struct->glBindBufferRangeNVproc) return;
	GLM_struct->glBindBufferRangeNVproc(target, index, buffer, offset, size);
}
void APIENTRY glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset){
	if(!GLM_struct->glBindBufferOffsetNVproc) return;
	GLM_struct->glBindBufferOffsetNVproc(target, index, buffer, offset);
}
void APIENTRY glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer){
	if(!GLM_struct->glBindBufferBaseNVproc) return;
	GLM_struct->glBindBufferBaseNVproc(target, index, buffer);
}
void APIENTRY glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint* locations, GLenum bufferMode){
	if(!GLM_struct->glTransformFeedbackVaryingsNVproc) return;
	GLM_struct->glTransformFeedbackVaryingsNVproc(program, count, locations, bufferMode);
}
void APIENTRY glActiveVaryingNV(GLuint program, const GLchar* name){
	if(!GLM_struct->glActiveVaryingNVproc) return;
	GLM_struct->glActiveVaryingNVproc(program, name);
}
GLint APIENTRY glGetVaryingLocationNV(GLuint program, const GLchar* name){
	if(!GLM_struct->glGetVaryingLocationNVproc) return 0;
	return GLM_struct->glGetVaryingLocationNVproc(program, name);
}
void APIENTRY glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name){
	if(!GLM_struct->glGetActiveVaryingNVproc) return;
	GLM_struct->glGetActiveVaryingNVproc(program, index, bufSize, length, size, type, name);
}
void APIENTRY glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint* location){
	if(!GLM_struct->glGetTransformFeedbackVaryingNVproc) return;
	GLM_struct->glGetTransformFeedbackVaryingNVproc(program, index, location);
}
void APIENTRY glTransformFeedbackStreamAttribsNV(GLsizei count, const GLint* attribs, GLsizei nbuffers, const GLint* bufstreams, GLenum bufferMode){
	if(!GLM_struct->glTransformFeedbackStreamAttribsNVproc) return;
	GLM_struct->glTransformFeedbackStreamAttribsNVproc(count, attribs, nbuffers, bufstreams, bufferMode);
}
void APIENTRY glBindTransformFeedbackNV(GLenum target, GLuint id){
	if(!GLM_struct->glBindTransformFeedbackNVproc) return;
	GLM_struct->glBindTransformFeedbackNVproc(target, id);
}
void APIENTRY glDeleteTransformFeedbacksNV(GLsizei n, const GLuint* ids){
	if(!GLM_struct->glDeleteTransformFeedbacksNVproc) return;
	GLM_struct->glDeleteTransformFeedbacksNVproc(n, ids);
}
void APIENTRY glGenTransformFeedbacksNV(GLsizei n, GLuint* ids){
	if(!GLM_struct->glGenTransformFeedbacksNVproc) return;
	GLM_struct->glGenTransformFeedbacksNVproc(n, ids);
}
GLboolean APIENTRY glIsTransformFeedbackNV(GLuint id){
	if(!GLM_struct->glIsTransformFeedbackNVproc) return 0;
	return GLM_struct->glIsTransformFeedbackNVproc(id);
}
void APIENTRY glPauseTransformFeedbackNV(void){
	if(!GLM_struct->glPauseTransformFeedbackNVproc) return;
	GLM_struct->glPauseTransformFeedbackNVproc();
}
void APIENTRY glResumeTransformFeedbackNV(void){
	if(!GLM_struct->glResumeTransformFeedbackNVproc) return;
	GLM_struct->glResumeTransformFeedbackNVproc();
}
void APIENTRY glDrawTransformFeedbackNV(GLenum mode, GLuint id){
	if(!GLM_struct->glDrawTransformFeedbackNVproc) return;
	GLM_struct->glDrawTransformFeedbackNVproc(mode, id);
}
void APIENTRY glVDPAUInitNV(const void* vdpDevice, const void* getProcAddress){
	if(!GLM_struct->glVDPAUInitNVproc) return;
	GLM_struct->glVDPAUInitNVproc(vdpDevice, getProcAddress);
}
void APIENTRY glVDPAUFiniNV(void){
	if(!GLM_struct->glVDPAUFiniNVproc) return;
	GLM_struct->glVDPAUFiniNVproc();
}
GLvdpauSurfaceNV APIENTRY glVDPAURegisterVideoSurfaceNV(const void* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames){
	if(!GLM_struct->glVDPAURegisterVideoSurfaceNVproc) return 0;
	return GLM_struct->glVDPAURegisterVideoSurfaceNVproc(vdpSurface, target, numTextureNames, textureNames);
}
GLvdpauSurfaceNV APIENTRY glVDPAURegisterOutputSurfaceNV(const void* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames){
	if(!GLM_struct->glVDPAURegisterOutputSurfaceNVproc) return 0;
	return GLM_struct->glVDPAURegisterOutputSurfaceNVproc(vdpSurface, target, numTextureNames, textureNames);
}
GLboolean APIENTRY glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface){
	if(!GLM_struct->glVDPAUIsSurfaceNVproc) return 0;
	return GLM_struct->glVDPAUIsSurfaceNVproc(surface);
}
void APIENTRY glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface){
	if(!GLM_struct->glVDPAUUnregisterSurfaceNVproc) return;
	GLM_struct->glVDPAUUnregisterSurfaceNVproc(surface);
}
void APIENTRY glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei count, GLsizei* length, GLint* values){
	if(!GLM_struct->glVDPAUGetSurfaceivNVproc) return;
	GLM_struct->glVDPAUGetSurfaceivNVproc(surface, pname, count, length, values);
}
void APIENTRY glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access){
	if(!GLM_struct->glVDPAUSurfaceAccessNVproc) return;
	GLM_struct->glVDPAUSurfaceAccessNVproc(surface, access);
}
void APIENTRY glVDPAUMapSurfacesNV(GLsizei numSurfaces, const GLvdpauSurfaceNV* surfaces){
	if(!GLM_struct->glVDPAUMapSurfacesNVproc) return;
	GLM_struct->glVDPAUMapSurfacesNVproc(numSurfaces, surfaces);
}
void APIENTRY glVDPAUUnmapSurfacesNV(GLsizei numSurface, const GLvdpauSurfaceNV* surfaces){
	if(!GLM_struct->glVDPAUUnmapSurfacesNVproc) return;
	GLM_struct->glVDPAUUnmapSurfacesNVproc(numSurface, surfaces);
}
GLvdpauSurfaceNV APIENTRY glVDPAURegisterVideoSurfaceWithPictureStructureNV(const void* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames, GLboolean isFrameStructure){
	if(!GLM_struct->glVDPAURegisterVideoSurfaceWithPictureStructureNVproc) return 0;
	return GLM_struct->glVDPAURegisterVideoSurfaceWithPictureStructureNVproc(vdpSurface, target, numTextureNames, textureNames, isFrameStructure);
}
void APIENTRY glFlushVertexArrayRangeNV(void){
	if(!GLM_struct->glFlushVertexArrayRangeNVproc) return;
	GLM_struct->glFlushVertexArrayRangeNVproc();
}
void APIENTRY glVertexArrayRangeNV(GLsizei length, const void* pointer){
	if(!GLM_struct->glVertexArrayRangeNVproc) return;
	GLM_struct->glVertexArrayRangeNVproc(length, pointer);
}
void APIENTRY glVertexAttribL1i64NV(GLuint index, GLint64EXT x){
	if(!GLM_struct->glVertexAttribL1i64NVproc) return;
	GLM_struct->glVertexAttribL1i64NVproc(index, x);
}
void APIENTRY glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y){
	if(!GLM_struct->glVertexAttribL2i64NVproc) return;
	GLM_struct->glVertexAttribL2i64NVproc(index, x, y);
}
void APIENTRY glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z){
	if(!GLM_struct->glVertexAttribL3i64NVproc) return;
	GLM_struct->glVertexAttribL3i64NVproc(index, x, y, z);
}
void APIENTRY glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w){
	if(!GLM_struct->glVertexAttribL4i64NVproc) return;
	GLM_struct->glVertexAttribL4i64NVproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribL1i64vNV(GLuint index, const GLint64EXT* v){
	if(!GLM_struct->glVertexAttribL1i64vNVproc) return;
	GLM_struct->glVertexAttribL1i64vNVproc(index, v);
}
void APIENTRY glVertexAttribL2i64vNV(GLuint index, const GLint64EXT* v){
	if(!GLM_struct->glVertexAttribL2i64vNVproc) return;
	GLM_struct->glVertexAttribL2i64vNVproc(index, v);
}
void APIENTRY glVertexAttribL3i64vNV(GLuint index, const GLint64EXT* v){
	if(!GLM_struct->glVertexAttribL3i64vNVproc) return;
	GLM_struct->glVertexAttribL3i64vNVproc(index, v);
}
void APIENTRY glVertexAttribL4i64vNV(GLuint index, const GLint64EXT* v){
	if(!GLM_struct->glVertexAttribL4i64vNVproc) return;
	GLM_struct->glVertexAttribL4i64vNVproc(index, v);
}
void APIENTRY glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x){
	if(!GLM_struct->glVertexAttribL1ui64NVproc) return;
	GLM_struct->glVertexAttribL1ui64NVproc(index, x);
}
void APIENTRY glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y){
	if(!GLM_struct->glVertexAttribL2ui64NVproc) return;
	GLM_struct->glVertexAttribL2ui64NVproc(index, x, y);
}
void APIENTRY glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z){
	if(!GLM_struct->glVertexAttribL3ui64NVproc) return;
	GLM_struct->glVertexAttribL3ui64NVproc(index, x, y, z);
}
void APIENTRY glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w){
	if(!GLM_struct->glVertexAttribL4ui64NVproc) return;
	GLM_struct->glVertexAttribL4ui64NVproc(index, x, y, z, w);
}
void APIENTRY glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT* v){
	if(!GLM_struct->glVertexAttribL1ui64vNVproc) return;
	GLM_struct->glVertexAttribL1ui64vNVproc(index, v);
}
void APIENTRY glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT* v){
	if(!GLM_struct->glVertexAttribL2ui64vNVproc) return;
	GLM_struct->glVertexAttribL2ui64vNVproc(index, v);
}
void APIENTRY glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT* v){
	if(!GLM_struct->glVertexAttribL3ui64vNVproc) return;
	GLM_struct->glVertexAttribL3ui64vNVproc(index, v);
}
void APIENTRY glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT* v){
	if(!GLM_struct->glVertexAttribL4ui64vNVproc) return;
	GLM_struct->glVertexAttribL4ui64vNVproc(index, v);
}
void APIENTRY glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT* params){
	if(!GLM_struct->glGetVertexAttribLi64vNVproc) return;
	GLM_struct->glGetVertexAttribLi64vNVproc(index, pname, params);
}
void APIENTRY glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT* params){
	if(!GLM_struct->glGetVertexAttribLui64vNVproc) return;
	GLM_struct->glGetVertexAttribLui64vNVproc(index, pname, params);
}
void APIENTRY glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride){
	if(!GLM_struct->glVertexAttribLFormatNVproc) return;
	GLM_struct->glVertexAttribLFormatNVproc(index, size, type, stride);
}
void APIENTRY glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length){
	if(!GLM_struct->glBufferAddressRangeNVproc) return;
	GLM_struct->glBufferAddressRangeNVproc(pname, index, address, length);
}
void APIENTRY glVertexFormatNV(GLint size, GLenum type, GLsizei stride){
	if(!GLM_struct->glVertexFormatNVproc) return;
	GLM_struct->glVertexFormatNVproc(size, type, stride);
}
void APIENTRY glNormalFormatNV(GLenum type, GLsizei stride){
	if(!GLM_struct->glNormalFormatNVproc) return;
	GLM_struct->glNormalFormatNVproc(type, stride);
}
void APIENTRY glColorFormatNV(GLint size, GLenum type, GLsizei stride){
	if(!GLM_struct->glColorFormatNVproc) return;
	GLM_struct->glColorFormatNVproc(size, type, stride);
}
void APIENTRY glIndexFormatNV(GLenum type, GLsizei stride){
	if(!GLM_struct->glIndexFormatNVproc) return;
	GLM_struct->glIndexFormatNVproc(type, stride);
}
void APIENTRY glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride){
	if(!GLM_struct->glTexCoordFormatNVproc) return;
	GLM_struct->glTexCoordFormatNVproc(size, type, stride);
}
void APIENTRY glEdgeFlagFormatNV(GLsizei stride){
	if(!GLM_struct->glEdgeFlagFormatNVproc) return;
	GLM_struct->glEdgeFlagFormatNVproc(stride);
}
void APIENTRY glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride){
	if(!GLM_struct->glSecondaryColorFormatNVproc) return;
	GLM_struct->glSecondaryColorFormatNVproc(size, type, stride);
}
void APIENTRY glFogCoordFormatNV(GLenum type, GLsizei stride){
	if(!GLM_struct->glFogCoordFormatNVproc) return;
	GLM_struct->glFogCoordFormatNVproc(type, stride);
}
void APIENTRY glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride){
	if(!GLM_struct->glVertexAttribFormatNVproc) return;
	GLM_struct->glVertexAttribFormatNVproc(index, size, type, normalized, stride);
}
void APIENTRY glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride){
	if(!GLM_struct->glVertexAttribIFormatNVproc) return;
	GLM_struct->glVertexAttribIFormatNVproc(index, size, type, stride);
}
void APIENTRY glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT* result){
	if(!GLM_struct->glGetIntegerui64i_vNVproc) return;
	GLM_struct->glGetIntegerui64i_vNVproc(value, index, result);
}
GLboolean APIENTRY glAreProgramsResidentNV(GLsizei n, const GLuint* programs, GLboolean* residences){
	if(!GLM_struct->glAreProgramsResidentNVproc) return 0;
	return GLM_struct->glAreProgramsResidentNVproc(n, programs, residences);
}
void APIENTRY glBindProgramNV(GLenum target, GLuint id){
	if(!GLM_struct->glBindProgramNVproc) return;
	GLM_struct->glBindProgramNVproc(target, id);
}
void APIENTRY glDeleteProgramsNV(GLsizei n, const GLuint* programs){
	if(!GLM_struct->glDeleteProgramsNVproc) return;
	GLM_struct->glDeleteProgramsNVproc(n, programs);
}
void APIENTRY glExecuteProgramNV(GLenum target, GLuint id, const GLfloat* params){
	if(!GLM_struct->glExecuteProgramNVproc) return;
	GLM_struct->glExecuteProgramNVproc(target, id, params);
}
void APIENTRY glGenProgramsNV(GLsizei n, GLuint* programs){
	if(!GLM_struct->glGenProgramsNVproc) return;
	GLM_struct->glGenProgramsNVproc(n, programs);
}
void APIENTRY glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetProgramParameterdvNVproc) return;
	GLM_struct->glGetProgramParameterdvNVproc(target, index, pname, params);
}
void APIENTRY glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetProgramParameterfvNVproc) return;
	GLM_struct->glGetProgramParameterfvNVproc(target, index, pname, params);
}
void APIENTRY glGetProgramivNV(GLuint id, GLenum pname, GLint* params){
	if(!GLM_struct->glGetProgramivNVproc) return;
	GLM_struct->glGetProgramivNVproc(id, pname, params);
}
void APIENTRY glGetProgramStringNV(GLuint id, GLenum pname, GLubyte* program){
	if(!GLM_struct->glGetProgramStringNVproc) return;
	GLM_struct->glGetProgramStringNVproc(id, pname, program);
}
void APIENTRY glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint* params){
	if(!GLM_struct->glGetTrackMatrixivNVproc) return;
	GLM_struct->glGetTrackMatrixivNVproc(target, address, pname, params);
}
void APIENTRY glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetVertexAttribdvNVproc) return;
	GLM_struct->glGetVertexAttribdvNVproc(index, pname, params);
}
void APIENTRY glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetVertexAttribfvNVproc) return;
	GLM_struct->glGetVertexAttribfvNVproc(index, pname, params);
}
void APIENTRY glGetVertexAttribivNV(GLuint index, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVertexAttribivNVproc) return;
	GLM_struct->glGetVertexAttribivNVproc(index, pname, params);
}
void APIENTRY glGetVertexAttribPointervNV(GLuint index, GLenum pname, void** pointer){
	if(!GLM_struct->glGetVertexAttribPointervNVproc) return;
	GLM_struct->glGetVertexAttribPointervNVproc(index, pname, pointer);
}
GLboolean APIENTRY glIsProgramNV(GLuint id){
	if(!GLM_struct->glIsProgramNVproc) return 0;
	return GLM_struct->glIsProgramNVproc(id);
}
void APIENTRY glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte* program){
	if(!GLM_struct->glLoadProgramNVproc) return;
	GLM_struct->glLoadProgramNVproc(target, id, len, program);
}
void APIENTRY glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glProgramParameter4dNVproc) return;
	GLM_struct->glProgramParameter4dNVproc(target, index, x, y, z, w);
}
void APIENTRY glProgramParameter4dvNV(GLenum target, GLuint index, const GLdouble* v){
	if(!GLM_struct->glProgramParameter4dvNVproc) return;
	GLM_struct->glProgramParameter4dvNVproc(target, index, v);
}
void APIENTRY glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glProgramParameter4fNVproc) return;
	GLM_struct->glProgramParameter4fNVproc(target, index, x, y, z, w);
}
void APIENTRY glProgramParameter4fvNV(GLenum target, GLuint index, const GLfloat* v){
	if(!GLM_struct->glProgramParameter4fvNVproc) return;
	GLM_struct->glProgramParameter4fvNVproc(target, index, v);
}
void APIENTRY glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, const GLdouble* v){
	if(!GLM_struct->glProgramParameters4dvNVproc) return;
	GLM_struct->glProgramParameters4dvNVproc(target, index, count, v);
}
void APIENTRY glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glProgramParameters4fvNVproc) return;
	GLM_struct->glProgramParameters4fvNVproc(target, index, count, v);
}
void APIENTRY glRequestResidentProgramsNV(GLsizei n, const GLuint* programs){
	if(!GLM_struct->glRequestResidentProgramsNVproc) return;
	GLM_struct->glRequestResidentProgramsNVproc(n, programs);
}
void APIENTRY glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform){
	if(!GLM_struct->glTrackMatrixNVproc) return;
	GLM_struct->glTrackMatrixNVproc(target, address, matrix, transform);
}
void APIENTRY glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, const void* pointer){
	if(!GLM_struct->glVertexAttribPointerNVproc) return;
	GLM_struct->glVertexAttribPointerNVproc(index, fsize, type, stride, pointer);
}
void APIENTRY glVertexAttrib1dNV(GLuint index, GLdouble x){
	if(!GLM_struct->glVertexAttrib1dNVproc) return;
	GLM_struct->glVertexAttrib1dNVproc(index, x);
}
void APIENTRY glVertexAttrib1dvNV(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib1dvNVproc) return;
	GLM_struct->glVertexAttrib1dvNVproc(index, v);
}
void APIENTRY glVertexAttrib1fNV(GLuint index, GLfloat x){
	if(!GLM_struct->glVertexAttrib1fNVproc) return;
	GLM_struct->glVertexAttrib1fNVproc(index, x);
}
void APIENTRY glVertexAttrib1fvNV(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib1fvNVproc) return;
	GLM_struct->glVertexAttrib1fvNVproc(index, v);
}
void APIENTRY glVertexAttrib1sNV(GLuint index, GLshort x){
	if(!GLM_struct->glVertexAttrib1sNVproc) return;
	GLM_struct->glVertexAttrib1sNVproc(index, x);
}
void APIENTRY glVertexAttrib1svNV(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib1svNVproc) return;
	GLM_struct->glVertexAttrib1svNVproc(index, v);
}
void APIENTRY glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y){
	if(!GLM_struct->glVertexAttrib2dNVproc) return;
	GLM_struct->glVertexAttrib2dNVproc(index, x, y);
}
void APIENTRY glVertexAttrib2dvNV(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib2dvNVproc) return;
	GLM_struct->glVertexAttrib2dvNVproc(index, v);
}
void APIENTRY glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y){
	if(!GLM_struct->glVertexAttrib2fNVproc) return;
	GLM_struct->glVertexAttrib2fNVproc(index, x, y);
}
void APIENTRY glVertexAttrib2fvNV(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib2fvNVproc) return;
	GLM_struct->glVertexAttrib2fvNVproc(index, v);
}
void APIENTRY glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y){
	if(!GLM_struct->glVertexAttrib2sNVproc) return;
	GLM_struct->glVertexAttrib2sNVproc(index, x, y);
}
void APIENTRY glVertexAttrib2svNV(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib2svNVproc) return;
	GLM_struct->glVertexAttrib2svNVproc(index, v);
}
void APIENTRY glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z){
	if(!GLM_struct->glVertexAttrib3dNVproc) return;
	GLM_struct->glVertexAttrib3dNVproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3dvNV(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib3dvNVproc) return;
	GLM_struct->glVertexAttrib3dvNVproc(index, v);
}
void APIENTRY glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glVertexAttrib3fNVproc) return;
	GLM_struct->glVertexAttrib3fNVproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3fvNV(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib3fvNVproc) return;
	GLM_struct->glVertexAttrib3fvNVproc(index, v);
}
void APIENTRY glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z){
	if(!GLM_struct->glVertexAttrib3sNVproc) return;
	GLM_struct->glVertexAttrib3sNVproc(index, x, y, z);
}
void APIENTRY glVertexAttrib3svNV(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib3svNVproc) return;
	GLM_struct->glVertexAttrib3svNVproc(index, v);
}
void APIENTRY glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){
	if(!GLM_struct->glVertexAttrib4dNVproc) return;
	GLM_struct->glVertexAttrib4dNVproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4dvNV(GLuint index, const GLdouble* v){
	if(!GLM_struct->glVertexAttrib4dvNVproc) return;
	GLM_struct->glVertexAttrib4dvNVproc(index, v);
}
void APIENTRY glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glVertexAttrib4fNVproc) return;
	GLM_struct->glVertexAttrib4fNVproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4fvNV(GLuint index, const GLfloat* v){
	if(!GLM_struct->glVertexAttrib4fvNVproc) return;
	GLM_struct->glVertexAttrib4fvNVproc(index, v);
}
void APIENTRY glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w){
	if(!GLM_struct->glVertexAttrib4sNVproc) return;
	GLM_struct->glVertexAttrib4sNVproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4svNV(GLuint index, const GLshort* v){
	if(!GLM_struct->glVertexAttrib4svNVproc) return;
	GLM_struct->glVertexAttrib4svNVproc(index, v);
}
void APIENTRY glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w){
	if(!GLM_struct->glVertexAttrib4ubNVproc) return;
	GLM_struct->glVertexAttrib4ubNVproc(index, x, y, z, w);
}
void APIENTRY glVertexAttrib4ubvNV(GLuint index, const GLubyte* v){
	if(!GLM_struct->glVertexAttrib4ubvNVproc) return;
	GLM_struct->glVertexAttrib4ubvNVproc(index, v);
}
void APIENTRY glVertexAttribs1dvNV(GLuint index, GLsizei count, const GLdouble* v){
	if(!GLM_struct->glVertexAttribs1dvNVproc) return;
	GLM_struct->glVertexAttribs1dvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs1fvNV(GLuint index, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glVertexAttribs1fvNVproc) return;
	GLM_struct->glVertexAttribs1fvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs1svNV(GLuint index, GLsizei count, const GLshort* v){
	if(!GLM_struct->glVertexAttribs1svNVproc) return;
	GLM_struct->glVertexAttribs1svNVproc(index, count, v);
}
void APIENTRY glVertexAttribs2dvNV(GLuint index, GLsizei count, const GLdouble* v){
	if(!GLM_struct->glVertexAttribs2dvNVproc) return;
	GLM_struct->glVertexAttribs2dvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs2fvNV(GLuint index, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glVertexAttribs2fvNVproc) return;
	GLM_struct->glVertexAttribs2fvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs2svNV(GLuint index, GLsizei count, const GLshort* v){
	if(!GLM_struct->glVertexAttribs2svNVproc) return;
	GLM_struct->glVertexAttribs2svNVproc(index, count, v);
}
void APIENTRY glVertexAttribs3dvNV(GLuint index, GLsizei count, const GLdouble* v){
	if(!GLM_struct->glVertexAttribs3dvNVproc) return;
	GLM_struct->glVertexAttribs3dvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs3fvNV(GLuint index, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glVertexAttribs3fvNVproc) return;
	GLM_struct->glVertexAttribs3fvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs3svNV(GLuint index, GLsizei count, const GLshort* v){
	if(!GLM_struct->glVertexAttribs3svNVproc) return;
	GLM_struct->glVertexAttribs3svNVproc(index, count, v);
}
void APIENTRY glVertexAttribs4dvNV(GLuint index, GLsizei count, const GLdouble* v){
	if(!GLM_struct->glVertexAttribs4dvNVproc) return;
	GLM_struct->glVertexAttribs4dvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs4fvNV(GLuint index, GLsizei count, const GLfloat* v){
	if(!GLM_struct->glVertexAttribs4fvNVproc) return;
	GLM_struct->glVertexAttribs4fvNVproc(index, count, v);
}
void APIENTRY glVertexAttribs4svNV(GLuint index, GLsizei count, const GLshort* v){
	if(!GLM_struct->glVertexAttribs4svNVproc) return;
	GLM_struct->glVertexAttribs4svNVproc(index, count, v);
}
void APIENTRY glVertexAttribs4ubvNV(GLuint index, GLsizei count, const GLubyte* v){
	if(!GLM_struct->glVertexAttribs4ubvNVproc) return;
	GLM_struct->glVertexAttribs4ubvNVproc(index, count, v);
}
void APIENTRY glBeginVideoCaptureNV(GLuint video_capture_slot){
	if(!GLM_struct->glBeginVideoCaptureNVproc) return;
	GLM_struct->glBeginVideoCaptureNVproc(video_capture_slot);
}
void APIENTRY glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset){
	if(!GLM_struct->glBindVideoCaptureStreamBufferNVproc) return;
	GLM_struct->glBindVideoCaptureStreamBufferNVproc(video_capture_slot, stream, frame_region, offset);
}
void APIENTRY glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture){
	if(!GLM_struct->glBindVideoCaptureStreamTextureNVproc) return;
	GLM_struct->glBindVideoCaptureStreamTextureNVproc(video_capture_slot, stream, frame_region, target, texture);
}
void APIENTRY glEndVideoCaptureNV(GLuint video_capture_slot){
	if(!GLM_struct->glEndVideoCaptureNVproc) return;
	GLM_struct->glEndVideoCaptureNVproc(video_capture_slot);
}
void APIENTRY glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVideoCaptureivNVproc) return;
	GLM_struct->glGetVideoCaptureivNVproc(video_capture_slot, pname, params);
}
void APIENTRY glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint* params){
	if(!GLM_struct->glGetVideoCaptureStreamivNVproc) return;
	GLM_struct->glGetVideoCaptureStreamivNVproc(video_capture_slot, stream, pname, params);
}
void APIENTRY glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetVideoCaptureStreamfvNVproc) return;
	GLM_struct->glGetVideoCaptureStreamfvNVproc(video_capture_slot, stream, pname, params);
}
void APIENTRY glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble* params){
	if(!GLM_struct->glGetVideoCaptureStreamdvNVproc) return;
	GLM_struct->glGetVideoCaptureStreamdvNVproc(video_capture_slot, stream, pname, params);
}
GLenum APIENTRY glVideoCaptureNV(GLuint video_capture_slot, GLuint* sequence_num, GLuint64EXT* capture_time){
	if(!GLM_struct->glVideoCaptureNVproc) return 0;
	return GLM_struct->glVideoCaptureNVproc(video_capture_slot, sequence_num, capture_time);
}
void APIENTRY glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint* params){
	if(!GLM_struct->glVideoCaptureStreamParameterivNVproc) return;
	GLM_struct->glVideoCaptureStreamParameterivNVproc(video_capture_slot, stream, pname, params);
}
void APIENTRY glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glVideoCaptureStreamParameterfvNVproc) return;
	GLM_struct->glVideoCaptureStreamParameterfvNVproc(video_capture_slot, stream, pname, params);
}
void APIENTRY glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble* params){
	if(!GLM_struct->glVideoCaptureStreamParameterdvNVproc) return;
	GLM_struct->glVideoCaptureStreamParameterdvNVproc(video_capture_slot, stream, pname, params);
}
void APIENTRY glViewportSwizzleNV(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew){
	if(!GLM_struct->glViewportSwizzleNVproc) return;
	GLM_struct->glViewportSwizzleNVproc(index, swizzlex, swizzley, swizzlez, swizzlew);
}
void APIENTRY glFramebufferTextureMultiviewOVR(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews){
	if(!GLM_struct->glFramebufferTextureMultiviewOVRproc) return;
	GLM_struct->glFramebufferTextureMultiviewOVRproc(target, attachment, texture, level, baseViewIndex, numViews);
}
void APIENTRY glNamedFramebufferTextureMultiviewOVR(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews){
	if(!GLM_struct->glNamedFramebufferTextureMultiviewOVRproc) return;
	GLM_struct->glNamedFramebufferTextureMultiviewOVRproc(framebuffer, attachment, texture, level, baseViewIndex, numViews);
}
void APIENTRY glHintPGI(GLenum target, GLint mode){
	if(!GLM_struct->glHintPGIproc) return;
	GLM_struct->glHintPGIproc(target, mode);
}
void APIENTRY glDetailTexFuncSGIS(GLenum target, GLsizei n, const GLfloat* points){
	if(!GLM_struct->glDetailTexFuncSGISproc) return;
	GLM_struct->glDetailTexFuncSGISproc(target, n, points);
}
void APIENTRY glGetDetailTexFuncSGIS(GLenum target, GLfloat* points){
	if(!GLM_struct->glGetDetailTexFuncSGISproc) return;
	GLM_struct->glGetDetailTexFuncSGISproc(target, points);
}
void APIENTRY glFogFuncSGIS(GLsizei n, const GLfloat* points){
	if(!GLM_struct->glFogFuncSGISproc) return;
	GLM_struct->glFogFuncSGISproc(n, points);
}
void APIENTRY glGetFogFuncSGIS(GLfloat* points){
	if(!GLM_struct->glGetFogFuncSGISproc) return;
	GLM_struct->glGetFogFuncSGISproc(points);
}
void APIENTRY glSampleMaskSGIS(GLclampf value, GLboolean invert){
	if(!GLM_struct->glSampleMaskSGISproc) return;
	GLM_struct->glSampleMaskSGISproc(value, invert);
}
void APIENTRY glSamplePatternSGIS(GLenum pattern){
	if(!GLM_struct->glSamplePatternSGISproc) return;
	GLM_struct->glSamplePatternSGISproc(pattern);
}
void APIENTRY glPixelTexGenParameteriSGIS(GLenum pname, GLint param){
	if(!GLM_struct->glPixelTexGenParameteriSGISproc) return;
	GLM_struct->glPixelTexGenParameteriSGISproc(pname, param);
}
void APIENTRY glPixelTexGenParameterivSGIS(GLenum pname, const GLint* params){
	if(!GLM_struct->glPixelTexGenParameterivSGISproc) return;
	GLM_struct->glPixelTexGenParameterivSGISproc(pname, params);
}
void APIENTRY glPixelTexGenParameterfSGIS(GLenum pname, GLfloat param){
	if(!GLM_struct->glPixelTexGenParameterfSGISproc) return;
	GLM_struct->glPixelTexGenParameterfSGISproc(pname, param);
}
void APIENTRY glPixelTexGenParameterfvSGIS(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glPixelTexGenParameterfvSGISproc) return;
	GLM_struct->glPixelTexGenParameterfvSGISproc(pname, params);
}
void APIENTRY glGetPixelTexGenParameterivSGIS(GLenum pname, GLint* params){
	if(!GLM_struct->glGetPixelTexGenParameterivSGISproc) return;
	GLM_struct->glGetPixelTexGenParameterivSGISproc(pname, params);
}
void APIENTRY glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetPixelTexGenParameterfvSGISproc) return;
	GLM_struct->glGetPixelTexGenParameterfvSGISproc(pname, params);
}
void APIENTRY glPointParameterfSGIS(GLenum pname, GLfloat param){
	if(!GLM_struct->glPointParameterfSGISproc) return;
	GLM_struct->glPointParameterfSGISproc(pname, param);
}
void APIENTRY glPointParameterfvSGIS(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glPointParameterfvSGISproc) return;
	GLM_struct->glPointParameterfvSGISproc(pname, params);
}
void APIENTRY glSharpenTexFuncSGIS(GLenum target, GLsizei n, const GLfloat* points){
	if(!GLM_struct->glSharpenTexFuncSGISproc) return;
	GLM_struct->glSharpenTexFuncSGISproc(target, n, points);
}
void APIENTRY glGetSharpenTexFuncSGIS(GLenum target, GLfloat* points){
	if(!GLM_struct->glGetSharpenTexFuncSGISproc) return;
	GLM_struct->glGetSharpenTexFuncSGISproc(target, points);
}
void APIENTRY glTexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexImage4DSGISproc) return;
	GLM_struct->glTexImage4DSGISproc(target, level, internalformat, width, height, depth, size4d, border, format, type, pixels);
}
void APIENTRY glTexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void* pixels){
	if(!GLM_struct->glTexSubImage4DSGISproc) return;
	GLM_struct->glTexSubImage4DSGISproc(target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels);
}
void APIENTRY glTextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha){
	if(!GLM_struct->glTextureColorMaskSGISproc) return;
	GLM_struct->glTextureColorMaskSGISproc(red, green, blue, alpha);
}
void APIENTRY glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat* weights){
	if(!GLM_struct->glGetTexFilterFuncSGISproc) return;
	GLM_struct->glGetTexFilterFuncSGISproc(target, filter, weights);
}
void APIENTRY glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const GLfloat* weights){
	if(!GLM_struct->glTexFilterFuncSGISproc) return;
	GLM_struct->glTexFilterFuncSGISproc(target, filter, n, weights);
}
void APIENTRY glAsyncMarkerSGIX(GLuint marker){
	if(!GLM_struct->glAsyncMarkerSGIXproc) return;
	GLM_struct->glAsyncMarkerSGIXproc(marker);
}
GLint APIENTRY glFinishAsyncSGIX(GLuint* markerp){
	if(!GLM_struct->glFinishAsyncSGIXproc) return 0;
	return GLM_struct->glFinishAsyncSGIXproc(markerp);
}
GLint APIENTRY glPollAsyncSGIX(GLuint* markerp){
	if(!GLM_struct->glPollAsyncSGIXproc) return 0;
	return GLM_struct->glPollAsyncSGIXproc(markerp);
}
GLuint APIENTRY glGenAsyncMarkersSGIX(GLsizei range){
	if(!GLM_struct->glGenAsyncMarkersSGIXproc) return 0;
	return GLM_struct->glGenAsyncMarkersSGIXproc(range);
}
void APIENTRY glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range){
	if(!GLM_struct->glDeleteAsyncMarkersSGIXproc) return;
	GLM_struct->glDeleteAsyncMarkersSGIXproc(marker, range);
}
GLboolean APIENTRY glIsAsyncMarkerSGIX(GLuint marker){
	if(!GLM_struct->glIsAsyncMarkerSGIXproc) return 0;
	return GLM_struct->glIsAsyncMarkerSGIXproc(marker);
}
void APIENTRY glFlushRasterSGIX(void){
	if(!GLM_struct->glFlushRasterSGIXproc) return;
	GLM_struct->glFlushRasterSGIXproc();
}
void APIENTRY glFragmentColorMaterialSGIX(GLenum face, GLenum mode){
	if(!GLM_struct->glFragmentColorMaterialSGIXproc) return;
	GLM_struct->glFragmentColorMaterialSGIXproc(face, mode);
}
void APIENTRY glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param){
	if(!GLM_struct->glFragmentLightfSGIXproc) return;
	GLM_struct->glFragmentLightfSGIXproc(light, pname, param);
}
void APIENTRY glFragmentLightfvSGIX(GLenum light, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glFragmentLightfvSGIXproc) return;
	GLM_struct->glFragmentLightfvSGIXproc(light, pname, params);
}
void APIENTRY glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param){
	if(!GLM_struct->glFragmentLightiSGIXproc) return;
	GLM_struct->glFragmentLightiSGIXproc(light, pname, param);
}
void APIENTRY glFragmentLightivSGIX(GLenum light, GLenum pname, const GLint* params){
	if(!GLM_struct->glFragmentLightivSGIXproc) return;
	GLM_struct->glFragmentLightivSGIXproc(light, pname, params);
}
void APIENTRY glFragmentLightModelfSGIX(GLenum pname, GLfloat param){
	if(!GLM_struct->glFragmentLightModelfSGIXproc) return;
	GLM_struct->glFragmentLightModelfSGIXproc(pname, param);
}
void APIENTRY glFragmentLightModelfvSGIX(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glFragmentLightModelfvSGIXproc) return;
	GLM_struct->glFragmentLightModelfvSGIXproc(pname, params);
}
void APIENTRY glFragmentLightModeliSGIX(GLenum pname, GLint param){
	if(!GLM_struct->glFragmentLightModeliSGIXproc) return;
	GLM_struct->glFragmentLightModeliSGIXproc(pname, param);
}
void APIENTRY glFragmentLightModelivSGIX(GLenum pname, const GLint* params){
	if(!GLM_struct->glFragmentLightModelivSGIXproc) return;
	GLM_struct->glFragmentLightModelivSGIXproc(pname, params);
}
void APIENTRY glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param){
	if(!GLM_struct->glFragmentMaterialfSGIXproc) return;
	GLM_struct->glFragmentMaterialfSGIXproc(face, pname, param);
}
void APIENTRY glFragmentMaterialfvSGIX(GLenum face, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glFragmentMaterialfvSGIXproc) return;
	GLM_struct->glFragmentMaterialfvSGIXproc(face, pname, params);
}
void APIENTRY glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param){
	if(!GLM_struct->glFragmentMaterialiSGIXproc) return;
	GLM_struct->glFragmentMaterialiSGIXproc(face, pname, param);
}
void APIENTRY glFragmentMaterialivSGIX(GLenum face, GLenum pname, const GLint* params){
	if(!GLM_struct->glFragmentMaterialivSGIXproc) return;
	GLM_struct->glFragmentMaterialivSGIXproc(face, pname, params);
}
void APIENTRY glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetFragmentLightfvSGIXproc) return;
	GLM_struct->glGetFragmentLightfvSGIXproc(light, pname, params);
}
void APIENTRY glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFragmentLightivSGIXproc) return;
	GLM_struct->glGetFragmentLightivSGIXproc(light, pname, params);
}
void APIENTRY glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetFragmentMaterialfvSGIXproc) return;
	GLM_struct->glGetFragmentMaterialfvSGIXproc(face, pname, params);
}
void APIENTRY glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint* params){
	if(!GLM_struct->glGetFragmentMaterialivSGIXproc) return;
	GLM_struct->glGetFragmentMaterialivSGIXproc(face, pname, params);
}
void APIENTRY glLightEnviSGIX(GLenum pname, GLint param){
	if(!GLM_struct->glLightEnviSGIXproc) return;
	GLM_struct->glLightEnviSGIXproc(pname, param);
}
void APIENTRY glFrameZoomSGIX(GLint factor){
	if(!GLM_struct->glFrameZoomSGIXproc) return;
	GLM_struct->glFrameZoomSGIXproc(factor);
}
void APIENTRY glIglooInterfaceSGIX(GLenum pname, const void* params){
	if(!GLM_struct->glIglooInterfaceSGIXproc) return;
	GLM_struct->glIglooInterfaceSGIXproc(pname, params);
}
GLint APIENTRY glGetInstrumentsSGIX(void){
	if(!GLM_struct->glGetInstrumentsSGIXproc) return 0;
	return GLM_struct->glGetInstrumentsSGIXproc();
}
void APIENTRY glInstrumentsBufferSGIX(GLsizei size, GLint* buffer){
	if(!GLM_struct->glInstrumentsBufferSGIXproc) return;
	GLM_struct->glInstrumentsBufferSGIXproc(size, buffer);
}
GLint APIENTRY glPollInstrumentsSGIX(GLint* marker_p){
	if(!GLM_struct->glPollInstrumentsSGIXproc) return 0;
	return GLM_struct->glPollInstrumentsSGIXproc(marker_p);
}
void APIENTRY glReadInstrumentsSGIX(GLint marker){
	if(!GLM_struct->glReadInstrumentsSGIXproc) return;
	GLM_struct->glReadInstrumentsSGIXproc(marker);
}
void APIENTRY glStartInstrumentsSGIX(void){
	if(!GLM_struct->glStartInstrumentsSGIXproc) return;
	GLM_struct->glStartInstrumentsSGIXproc();
}
void APIENTRY glStopInstrumentsSGIX(GLint marker){
	if(!GLM_struct->glStopInstrumentsSGIXproc) return;
	GLM_struct->glStopInstrumentsSGIXproc(marker);
}
void APIENTRY glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetListParameterfvSGIXproc) return;
	GLM_struct->glGetListParameterfvSGIXproc(list, pname, params);
}
void APIENTRY glGetListParameterivSGIX(GLuint list, GLenum pname, GLint* params){
	if(!GLM_struct->glGetListParameterivSGIXproc) return;
	GLM_struct->glGetListParameterivSGIXproc(list, pname, params);
}
void APIENTRY glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param){
	if(!GLM_struct->glListParameterfSGIXproc) return;
	GLM_struct->glListParameterfSGIXproc(list, pname, param);
}
void APIENTRY glListParameterfvSGIX(GLuint list, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glListParameterfvSGIXproc) return;
	GLM_struct->glListParameterfvSGIXproc(list, pname, params);
}
void APIENTRY glListParameteriSGIX(GLuint list, GLenum pname, GLint param){
	if(!GLM_struct->glListParameteriSGIXproc) return;
	GLM_struct->glListParameteriSGIXproc(list, pname, param);
}
void APIENTRY glListParameterivSGIX(GLuint list, GLenum pname, const GLint* params){
	if(!GLM_struct->glListParameterivSGIXproc) return;
	GLM_struct->glListParameterivSGIXproc(list, pname, params);
}
void APIENTRY glPixelTexGenSGIX(GLenum mode){
	if(!GLM_struct->glPixelTexGenSGIXproc) return;
	GLM_struct->glPixelTexGenSGIXproc(mode);
}
void APIENTRY glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble* points){
	if(!GLM_struct->glDeformationMap3dSGIXproc) return;
	GLM_struct->glDeformationMap3dSGIXproc(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}
void APIENTRY glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat* points){
	if(!GLM_struct->glDeformationMap3fSGIXproc) return;
	GLM_struct->glDeformationMap3fSGIXproc(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}
void APIENTRY glDeformSGIX(GLbitfield mask){
	if(!GLM_struct->glDeformSGIXproc) return;
	GLM_struct->glDeformSGIXproc(mask);
}
void APIENTRY glLoadIdentityDeformationMapSGIX(GLbitfield mask){
	if(!GLM_struct->glLoadIdentityDeformationMapSGIXproc) return;
	GLM_struct->glLoadIdentityDeformationMapSGIXproc(mask);
}
void APIENTRY glReferencePlaneSGIX(const GLdouble* equation){
	if(!GLM_struct->glReferencePlaneSGIXproc) return;
	GLM_struct->glReferencePlaneSGIXproc(equation);
}
void APIENTRY glSpriteParameterfSGIX(GLenum pname, GLfloat param){
	if(!GLM_struct->glSpriteParameterfSGIXproc) return;
	GLM_struct->glSpriteParameterfSGIXproc(pname, param);
}
void APIENTRY glSpriteParameterfvSGIX(GLenum pname, const GLfloat* params){
	if(!GLM_struct->glSpriteParameterfvSGIXproc) return;
	GLM_struct->glSpriteParameterfvSGIXproc(pname, params);
}
void APIENTRY glSpriteParameteriSGIX(GLenum pname, GLint param){
	if(!GLM_struct->glSpriteParameteriSGIXproc) return;
	GLM_struct->glSpriteParameteriSGIXproc(pname, param);
}
void APIENTRY glSpriteParameterivSGIX(GLenum pname, const GLint* params){
	if(!GLM_struct->glSpriteParameterivSGIXproc) return;
	GLM_struct->glSpriteParameterivSGIXproc(pname, params);
}
void APIENTRY glTagSampleBufferSGIX(void){
	if(!GLM_struct->glTagSampleBufferSGIXproc) return;
	GLM_struct->glTagSampleBufferSGIXproc();
}
void APIENTRY glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void* table){
	if(!GLM_struct->glColorTableSGIproc) return;
	GLM_struct->glColorTableSGIproc(target, internalformat, width, format, type, table);
}
void APIENTRY glColorTableParameterfvSGI(GLenum target, GLenum pname, const GLfloat* params){
	if(!GLM_struct->glColorTableParameterfvSGIproc) return;
	GLM_struct->glColorTableParameterfvSGIproc(target, pname, params);
}
void APIENTRY glColorTableParameterivSGI(GLenum target, GLenum pname, const GLint* params){
	if(!GLM_struct->glColorTableParameterivSGIproc) return;
	GLM_struct->glColorTableParameterivSGIproc(target, pname, params);
}
void APIENTRY glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width){
	if(!GLM_struct->glCopyColorTableSGIproc) return;
	GLM_struct->glCopyColorTableSGIproc(target, internalformat, x, y, width);
}
void APIENTRY glGetColorTableSGI(GLenum target, GLenum format, GLenum type, void* table){
	if(!GLM_struct->glGetColorTableSGIproc) return;
	GLM_struct->glGetColorTableSGIproc(target, format, type, table);
}
void APIENTRY glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat* params){
	if(!GLM_struct->glGetColorTableParameterfvSGIproc) return;
	GLM_struct->glGetColorTableParameterfvSGIproc(target, pname, params);
}
void APIENTRY glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint* params){
	if(!GLM_struct->glGetColorTableParameterivSGIproc) return;
	GLM_struct->glGetColorTableParameterivSGIproc(target, pname, params);
}
void APIENTRY glFinishTextureSUNX(void){
	if(!GLM_struct->glFinishTextureSUNXproc) return;
	GLM_struct->glFinishTextureSUNXproc();
}
void APIENTRY glGlobalAlphaFactorbSUN(GLbyte factor){
	if(!GLM_struct->glGlobalAlphaFactorbSUNproc) return;
	GLM_struct->glGlobalAlphaFactorbSUNproc(factor);
}
void APIENTRY glGlobalAlphaFactorsSUN(GLshort factor){
	if(!GLM_struct->glGlobalAlphaFactorsSUNproc) return;
	GLM_struct->glGlobalAlphaFactorsSUNproc(factor);
}
void APIENTRY glGlobalAlphaFactoriSUN(GLint factor){
	if(!GLM_struct->glGlobalAlphaFactoriSUNproc) return;
	GLM_struct->glGlobalAlphaFactoriSUNproc(factor);
}
void APIENTRY glGlobalAlphaFactorfSUN(GLfloat factor){
	if(!GLM_struct->glGlobalAlphaFactorfSUNproc) return;
	GLM_struct->glGlobalAlphaFactorfSUNproc(factor);
}
void APIENTRY glGlobalAlphaFactordSUN(GLdouble factor){
	if(!GLM_struct->glGlobalAlphaFactordSUNproc) return;
	GLM_struct->glGlobalAlphaFactordSUNproc(factor);
}
void APIENTRY glGlobalAlphaFactorubSUN(GLubyte factor){
	if(!GLM_struct->glGlobalAlphaFactorubSUNproc) return;
	GLM_struct->glGlobalAlphaFactorubSUNproc(factor);
}
void APIENTRY glGlobalAlphaFactorusSUN(GLushort factor){
	if(!GLM_struct->glGlobalAlphaFactorusSUNproc) return;
	GLM_struct->glGlobalAlphaFactorusSUNproc(factor);
}
void APIENTRY glGlobalAlphaFactoruiSUN(GLuint factor){
	if(!GLM_struct->glGlobalAlphaFactoruiSUNproc) return;
	GLM_struct->glGlobalAlphaFactoruiSUNproc(factor);
}
void APIENTRY glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width){
	if(!GLM_struct->glDrawMeshArraysSUNproc) return;
	GLM_struct->glDrawMeshArraysSUNproc(mode, first, count, width);
}
void APIENTRY glReplacementCodeuiSUN(GLuint code){
	if(!GLM_struct->glReplacementCodeuiSUNproc) return;
	GLM_struct->glReplacementCodeuiSUNproc(code);
}
void APIENTRY glReplacementCodeusSUN(GLushort code){
	if(!GLM_struct->glReplacementCodeusSUNproc) return;
	GLM_struct->glReplacementCodeusSUNproc(code);
}
void APIENTRY glReplacementCodeubSUN(GLubyte code){
	if(!GLM_struct->glReplacementCodeubSUNproc) return;
	GLM_struct->glReplacementCodeubSUNproc(code);
}
void APIENTRY glReplacementCodeuivSUN(const GLuint* code){
	if(!GLM_struct->glReplacementCodeuivSUNproc) return;
	GLM_struct->glReplacementCodeuivSUNproc(code);
}
void APIENTRY glReplacementCodeusvSUN(const GLushort* code){
	if(!GLM_struct->glReplacementCodeusvSUNproc) return;
	GLM_struct->glReplacementCodeusvSUNproc(code);
}
void APIENTRY glReplacementCodeubvSUN(const GLubyte* code){
	if(!GLM_struct->glReplacementCodeubvSUNproc) return;
	GLM_struct->glReplacementCodeubvSUNproc(code);
}
void APIENTRY glReplacementCodePointerSUN(GLenum type, GLsizei stride, const void** pointer){
	if(!GLM_struct->glReplacementCodePointerSUNproc) return;
	GLM_struct->glReplacementCodePointerSUNproc(type, stride, pointer);
}
void APIENTRY glColor4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y){
	if(!GLM_struct->glColor4ubVertex2fSUNproc) return;
	GLM_struct->glColor4ubVertex2fSUNproc(r, g, b, a, x, y);
}
void APIENTRY glColor4ubVertex2fvSUN(const GLubyte* c, const GLfloat* v){
	if(!GLM_struct->glColor4ubVertex2fvSUNproc) return;
	GLM_struct->glColor4ubVertex2fvSUNproc(c, v);
}
void APIENTRY glColor4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glColor4ubVertex3fSUNproc) return;
	GLM_struct->glColor4ubVertex3fSUNproc(r, g, b, a, x, y, z);
}
void APIENTRY glColor4ubVertex3fvSUN(const GLubyte* c, const GLfloat* v){
	if(!GLM_struct->glColor4ubVertex3fvSUNproc) return;
	GLM_struct->glColor4ubVertex3fvSUNproc(c, v);
}
void APIENTRY glColor3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glColor3fVertex3fSUNproc) return;
	GLM_struct->glColor3fVertex3fSUNproc(r, g, b, x, y, z);
}
void APIENTRY glColor3fVertex3fvSUN(const GLfloat* c, const GLfloat* v){
	if(!GLM_struct->glColor3fVertex3fvSUNproc) return;
	GLM_struct->glColor3fVertex3fvSUNproc(c, v);
}
void APIENTRY glNormal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glNormal3fVertex3fSUNproc) return;
	GLM_struct->glNormal3fVertex3fSUNproc(nx, ny, nz, x, y, z);
}
void APIENTRY glNormal3fVertex3fvSUN(const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glNormal3fVertex3fvSUNproc) return;
	GLM_struct->glNormal3fVertex3fvSUNproc(n, v);
}
void APIENTRY glColor4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glColor4fNormal3fVertex3fSUNproc) return;
	GLM_struct->glColor4fNormal3fVertex3fSUNproc(r, g, b, a, nx, ny, nz, x, y, z);
}
void APIENTRY glColor4fNormal3fVertex3fvSUN(const GLfloat* c, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glColor4fNormal3fVertex3fvSUNproc) return;
	GLM_struct->glColor4fNormal3fVertex3fvSUNproc(c, n, v);
}
void APIENTRY glTexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glTexCoord2fVertex3fSUNproc) return;
	GLM_struct->glTexCoord2fVertex3fSUNproc(s, t, x, y, z);
}
void APIENTRY glTexCoord2fVertex3fvSUN(const GLfloat* tc, const GLfloat* v){
	if(!GLM_struct->glTexCoord2fVertex3fvSUNproc) return;
	GLM_struct->glTexCoord2fVertex3fvSUNproc(tc, v);
}
void APIENTRY glTexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glTexCoord4fVertex4fSUNproc) return;
	GLM_struct->glTexCoord4fVertex4fSUNproc(s, t, p, q, x, y, z, w);
}
void APIENTRY glTexCoord4fVertex4fvSUN(const GLfloat* tc, const GLfloat* v){
	if(!GLM_struct->glTexCoord4fVertex4fvSUNproc) return;
	GLM_struct->glTexCoord4fVertex4fvSUNproc(tc, v);
}
void APIENTRY glTexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glTexCoord2fColor4ubVertex3fSUNproc) return;
	GLM_struct->glTexCoord2fColor4ubVertex3fSUNproc(s, t, r, g, b, a, x, y, z);
}
void APIENTRY glTexCoord2fColor4ubVertex3fvSUN(const GLfloat* tc, const GLubyte* c, const GLfloat* v){
	if(!GLM_struct->glTexCoord2fColor4ubVertex3fvSUNproc) return;
	GLM_struct->glTexCoord2fColor4ubVertex3fvSUNproc(tc, c, v);
}
void APIENTRY glTexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glTexCoord2fColor3fVertex3fSUNproc) return;
	GLM_struct->glTexCoord2fColor3fVertex3fSUNproc(s, t, r, g, b, x, y, z);
}
void APIENTRY glTexCoord2fColor3fVertex3fvSUN(const GLfloat* tc, const GLfloat* c, const GLfloat* v){
	if(!GLM_struct->glTexCoord2fColor3fVertex3fvSUNproc) return;
	GLM_struct->glTexCoord2fColor3fVertex3fvSUNproc(tc, c, v);
}
void APIENTRY glTexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glTexCoord2fNormal3fVertex3fSUNproc) return;
	GLM_struct->glTexCoord2fNormal3fVertex3fSUNproc(s, t, nx, ny, nz, x, y, z);
}
void APIENTRY glTexCoord2fNormal3fVertex3fvSUN(const GLfloat* tc, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glTexCoord2fNormal3fVertex3fvSUNproc) return;
	GLM_struct->glTexCoord2fNormal3fVertex3fvSUNproc(tc, n, v);
}
void APIENTRY glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glTexCoord2fColor4fNormal3fVertex3fSUNproc) return;
	GLM_struct->glTexCoord2fColor4fNormal3fVertex3fSUNproc(s, t, r, g, b, a, nx, ny, nz, x, y, z);
}
void APIENTRY glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glTexCoord2fColor4fNormal3fVertex3fvSUNproc) return;
	GLM_struct->glTexCoord2fColor4fNormal3fVertex3fvSUNproc(tc, c, n, v);
}
void APIENTRY glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	if(!GLM_struct->glTexCoord4fColor4fNormal3fVertex4fSUNproc) return;
	GLM_struct->glTexCoord4fColor4fNormal3fVertex4fSUNproc(s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w);
}
void APIENTRY glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glTexCoord4fColor4fNormal3fVertex4fvSUNproc) return;
	GLM_struct->glTexCoord4fColor4fNormal3fVertex4fvSUNproc(tc, c, n, v);
}
void APIENTRY glReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiVertex3fSUNproc(rc, x, y, z);
}
void APIENTRY glReplacementCodeuiVertex3fvSUN(const GLuint* rc, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiVertex3fvSUNproc(rc, v);
}
void APIENTRY glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiColor4ubVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiColor4ubVertex3fSUNproc(rc, r, g, b, a, x, y, z);
}
void APIENTRY glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint* rc, const GLubyte* c, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiColor4ubVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiColor4ubVertex3fvSUNproc(rc, c, v);
}
void APIENTRY glReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiColor3fVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiColor3fVertex3fSUNproc(rc, r, g, b, x, y, z);
}
void APIENTRY glReplacementCodeuiColor3fVertex3fvSUN(const GLuint* rc, const GLfloat* c, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiColor3fVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiColor3fVertex3fvSUNproc(rc, c, v);
}
void APIENTRY glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiNormal3fVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiNormal3fVertex3fSUNproc(rc, nx, ny, nz, x, y, z);
}
void APIENTRY glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiNormal3fVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiNormal3fVertex3fvSUNproc(rc, n, v);
}
void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiColor4fNormal3fVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiColor4fNormal3fVertex3fSUNproc(rc, r, g, b, a, nx, ny, nz, x, y, z);
}
void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* c, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiColor4fNormal3fVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiColor4fNormal3fVertex3fvSUNproc(rc, c, n, v);
}
void APIENTRY glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiTexCoord2fVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiTexCoord2fVertex3fSUNproc(rc, s, t, x, y, z);
}
void APIENTRY glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint* rc, const GLfloat* tc, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiTexCoord2fVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiTexCoord2fVertex3fvSUNproc(rc, tc, v);
}
void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiTexCoord2fNormal3fVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiTexCoord2fNormal3fVertex3fSUNproc(rc, s, t, nx, ny, nz, x, y, z);
}
void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* tc, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUNproc(rc, tc, n, v);
}
void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z){
	if(!GLM_struct->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUNproc) return;
	GLM_struct->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUNproc(rc, s, t, r, g, b, a, nx, ny, nz, x, y, z);
}
void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint* rc, const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v){
	if(!GLM_struct->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUNproc) return;
	GLM_struct->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUNproc(rc, tc, c, n, v);
}
void GLMInit() {
	delete GLM_struct;
	GLM_struct = new GLM_struct_t{};
	GLM_struct->wglCreateBufferRegionARBproc = (PFNWGLCREATEBUFFERREGIONARBPROC)wglGetProcAddress("wglCreateBufferRegionARB");
	GLM_struct->wglDeleteBufferRegionARBproc = (PFNWGLDELETEBUFFERREGIONARBPROC)wglGetProcAddress("wglDeleteBufferRegionARB");
	GLM_struct->wglSaveBufferRegionARBproc = (PFNWGLSAVEBUFFERREGIONARBPROC)wglGetProcAddress("wglSaveBufferRegionARB");
	GLM_struct->wglRestoreBufferRegionARBproc = (PFNWGLRESTOREBUFFERREGIONARBPROC)wglGetProcAddress("wglRestoreBufferRegionARB");
	GLM_struct->wglCreateContextAttribsARBproc = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	GLM_struct->wglGetExtensionsStringARBproc = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");
	GLM_struct->wglMakeContextCurrentARBproc = (PFNWGLMAKECONTEXTCURRENTARBPROC)wglGetProcAddress("wglMakeContextCurrentARB");
	GLM_struct->wglGetCurrentReadDCARBproc = (PFNWGLGETCURRENTREADDCARBPROC)wglGetProcAddress("wglGetCurrentReadDCARB");
	GLM_struct->wglCreatePbufferARBproc = (PFNWGLCREATEPBUFFERARBPROC)wglGetProcAddress("wglCreatePbufferARB");
	GLM_struct->wglGetPbufferDCARBproc = (PFNWGLGETPBUFFERDCARBPROC)wglGetProcAddress("wglGetPbufferDCARB");
	GLM_struct->wglReleasePbufferDCARBproc = (PFNWGLRELEASEPBUFFERDCARBPROC)wglGetProcAddress("wglReleasePbufferDCARB");
	GLM_struct->wglDestroyPbufferARBproc = (PFNWGLDESTROYPBUFFERARBPROC)wglGetProcAddress("wglDestroyPbufferARB");
	GLM_struct->wglQueryPbufferARBproc = (PFNWGLQUERYPBUFFERARBPROC)wglGetProcAddress("wglQueryPbufferARB");
	GLM_struct->wglGetPixelFormatAttribivARBproc = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribivARB");
	GLM_struct->wglGetPixelFormatAttribfvARBproc = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribfvARB");
	GLM_struct->wglChoosePixelFormatARBproc = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
	GLM_struct->wglBindTexImageARBproc = (PFNWGLBINDTEXIMAGEARBPROC)wglGetProcAddress("wglBindTexImageARB");
	GLM_struct->wglReleaseTexImageARBproc = (PFNWGLRELEASETEXIMAGEARBPROC)wglGetProcAddress("wglReleaseTexImageARB");
	GLM_struct->wglSetPbufferAttribARBproc = (PFNWGLSETPBUFFERATTRIBARBPROC)wglGetProcAddress("wglSetPbufferAttribARB");
	GLM_struct->wglSetStereoEmitterState3DLproc = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC)wglGetProcAddress("wglSetStereoEmitterState3DL");
	GLM_struct->wglGetGPUIDsAMDproc = (PFNWGLGETGPUIDSAMDPROC)wglGetProcAddress("wglGetGPUIDsAMD");
	GLM_struct->wglGetGPUInfoAMDproc = (PFNWGLGETGPUINFOAMDPROC)wglGetProcAddress("wglGetGPUInfoAMD");
	GLM_struct->wglGetContextGPUIDAMDproc = (PFNWGLGETCONTEXTGPUIDAMDPROC)wglGetProcAddress("wglGetContextGPUIDAMD");
	GLM_struct->wglCreateAssociatedContextAMDproc = (PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglCreateAssociatedContextAMD");
	GLM_struct->wglCreateAssociatedContextAttribsAMDproc = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)wglGetProcAddress("wglCreateAssociatedContextAttribsAMD");
	GLM_struct->wglDeleteAssociatedContextAMDproc = (PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglDeleteAssociatedContextAMD");
	GLM_struct->wglMakeAssociatedContextCurrentAMDproc = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)wglGetProcAddress("wglMakeAssociatedContextCurrentAMD");
	GLM_struct->wglGetCurrentAssociatedContextAMDproc = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglGetCurrentAssociatedContextAMD");
	GLM_struct->wglBlitContextFramebufferAMDproc = (PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)wglGetProcAddress("wglBlitContextFramebufferAMD");
	GLM_struct->wglCreateDisplayColorTableEXTproc = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglCreateDisplayColorTableEXT");
	GLM_struct->wglLoadDisplayColorTableEXTproc = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglLoadDisplayColorTableEXT");
	GLM_struct->wglBindDisplayColorTableEXTproc = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglBindDisplayColorTableEXT");
	GLM_struct->wglDestroyDisplayColorTableEXTproc = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglDestroyDisplayColorTableEXT");
	GLM_struct->wglGetExtensionsStringEXTproc = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT");
	GLM_struct->wglMakeContextCurrentEXTproc = (PFNWGLMAKECONTEXTCURRENTEXTPROC)wglGetProcAddress("wglMakeContextCurrentEXT");
	GLM_struct->wglGetCurrentReadDCEXTproc = (PFNWGLGETCURRENTREADDCEXTPROC)wglGetProcAddress("wglGetCurrentReadDCEXT");
	GLM_struct->wglCreatePbufferEXTproc = (PFNWGLCREATEPBUFFEREXTPROC)wglGetProcAddress("wglCreatePbufferEXT");
	GLM_struct->wglGetPbufferDCEXTproc = (PFNWGLGETPBUFFERDCEXTPROC)wglGetProcAddress("wglGetPbufferDCEXT");
	GLM_struct->wglReleasePbufferDCEXTproc = (PFNWGLRELEASEPBUFFERDCEXTPROC)wglGetProcAddress("wglReleasePbufferDCEXT");
	GLM_struct->wglDestroyPbufferEXTproc = (PFNWGLDESTROYPBUFFEREXTPROC)wglGetProcAddress("wglDestroyPbufferEXT");
	GLM_struct->wglQueryPbufferEXTproc = (PFNWGLQUERYPBUFFEREXTPROC)wglGetProcAddress("wglQueryPbufferEXT");
	GLM_struct->wglGetPixelFormatAttribivEXTproc = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)wglGetProcAddress("wglGetPixelFormatAttribivEXT");
	GLM_struct->wglGetPixelFormatAttribfvEXTproc = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)wglGetProcAddress("wglGetPixelFormatAttribfvEXT");
	GLM_struct->wglChoosePixelFormatEXTproc = (PFNWGLCHOOSEPIXELFORMATEXTPROC)wglGetProcAddress("wglChoosePixelFormatEXT");
	GLM_struct->wglSwapIntervalEXTproc = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
	GLM_struct->wglGetSwapIntervalEXTproc = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
	GLM_struct->wglGetDigitalVideoParametersI3Dproc = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)wglGetProcAddress("wglGetDigitalVideoParametersI3D");
	GLM_struct->wglSetDigitalVideoParametersI3Dproc = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)wglGetProcAddress("wglSetDigitalVideoParametersI3D");
	GLM_struct->wglGetGammaTableParametersI3Dproc = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)wglGetProcAddress("wglGetGammaTableParametersI3D");
	GLM_struct->wglSetGammaTableParametersI3Dproc = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)wglGetProcAddress("wglSetGammaTableParametersI3D");
	GLM_struct->wglGetGammaTableI3Dproc = (PFNWGLGETGAMMATABLEI3DPROC)wglGetProcAddress("wglGetGammaTableI3D");
	GLM_struct->wglSetGammaTableI3Dproc = (PFNWGLSETGAMMATABLEI3DPROC)wglGetProcAddress("wglSetGammaTableI3D");
	GLM_struct->wglEnableGenlockI3Dproc = (PFNWGLENABLEGENLOCKI3DPROC)wglGetProcAddress("wglEnableGenlockI3D");
	GLM_struct->wglDisableGenlockI3Dproc = (PFNWGLDISABLEGENLOCKI3DPROC)wglGetProcAddress("wglDisableGenlockI3D");
	GLM_struct->wglIsEnabledGenlockI3Dproc = (PFNWGLISENABLEDGENLOCKI3DPROC)wglGetProcAddress("wglIsEnabledGenlockI3D");
	GLM_struct->wglGenlockSourceI3Dproc = (PFNWGLGENLOCKSOURCEI3DPROC)wglGetProcAddress("wglGenlockSourceI3D");
	GLM_struct->wglGetGenlockSourceI3Dproc = (PFNWGLGETGENLOCKSOURCEI3DPROC)wglGetProcAddress("wglGetGenlockSourceI3D");
	GLM_struct->wglGenlockSourceEdgeI3Dproc = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)wglGetProcAddress("wglGenlockSourceEdgeI3D");
	GLM_struct->wglGetGenlockSourceEdgeI3Dproc = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)wglGetProcAddress("wglGetGenlockSourceEdgeI3D");
	GLM_struct->wglGenlockSampleRateI3Dproc = (PFNWGLGENLOCKSAMPLERATEI3DPROC)wglGetProcAddress("wglGenlockSampleRateI3D");
	GLM_struct->wglGetGenlockSampleRateI3Dproc = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)wglGetProcAddress("wglGetGenlockSampleRateI3D");
	GLM_struct->wglGenlockSourceDelayI3Dproc = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)wglGetProcAddress("wglGenlockSourceDelayI3D");
	GLM_struct->wglGetGenlockSourceDelayI3Dproc = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)wglGetProcAddress("wglGetGenlockSourceDelayI3D");
	GLM_struct->wglQueryGenlockMaxSourceDelayI3Dproc = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)wglGetProcAddress("wglQueryGenlockMaxSourceDelayI3D");
	GLM_struct->wglCreateImageBufferI3Dproc = (PFNWGLCREATEIMAGEBUFFERI3DPROC)wglGetProcAddress("wglCreateImageBufferI3D");
	GLM_struct->wglDestroyImageBufferI3Dproc = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)wglGetProcAddress("wglDestroyImageBufferI3D");
	GLM_struct->wglAssociateImageBufferEventsI3Dproc = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)wglGetProcAddress("wglAssociateImageBufferEventsI3D");
	GLM_struct->wglReleaseImageBufferEventsI3Dproc = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)wglGetProcAddress("wglReleaseImageBufferEventsI3D");
	GLM_struct->wglEnableFrameLockI3Dproc = (PFNWGLENABLEFRAMELOCKI3DPROC)wglGetProcAddress("wglEnableFrameLockI3D");
	GLM_struct->wglDisableFrameLockI3Dproc = (PFNWGLDISABLEFRAMELOCKI3DPROC)wglGetProcAddress("wglDisableFrameLockI3D");
	GLM_struct->wglIsEnabledFrameLockI3Dproc = (PFNWGLISENABLEDFRAMELOCKI3DPROC)wglGetProcAddress("wglIsEnabledFrameLockI3D");
	GLM_struct->wglQueryFrameLockMasterI3Dproc = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)wglGetProcAddress("wglQueryFrameLockMasterI3D");
	GLM_struct->wglGetFrameUsageI3Dproc = (PFNWGLGETFRAMEUSAGEI3DPROC)wglGetProcAddress("wglGetFrameUsageI3D");
	GLM_struct->wglBeginFrameTrackingI3Dproc = (PFNWGLBEGINFRAMETRACKINGI3DPROC)wglGetProcAddress("wglBeginFrameTrackingI3D");
	GLM_struct->wglEndFrameTrackingI3Dproc = (PFNWGLENDFRAMETRACKINGI3DPROC)wglGetProcAddress("wglEndFrameTrackingI3D");
	GLM_struct->wglQueryFrameTrackingI3Dproc = (PFNWGLQUERYFRAMETRACKINGI3DPROC)wglGetProcAddress("wglQueryFrameTrackingI3D");
	GLM_struct->wglDXSetResourceShareHandleNVproc = (PFNWGLDXSETRESOURCESHAREHANDLENVPROC)wglGetProcAddress("wglDXSetResourceShareHandleNV");
	GLM_struct->wglDXOpenDeviceNVproc = (PFNWGLDXOPENDEVICENVPROC)wglGetProcAddress("wglDXOpenDeviceNV");
	GLM_struct->wglDXCloseDeviceNVproc = (PFNWGLDXCLOSEDEVICENVPROC)wglGetProcAddress("wglDXCloseDeviceNV");
	GLM_struct->wglDXRegisterObjectNVproc = (PFNWGLDXREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXRegisterObjectNV");
	GLM_struct->wglDXUnregisterObjectNVproc = (PFNWGLDXUNREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXUnregisterObjectNV");
	GLM_struct->wglDXObjectAccessNVproc = (PFNWGLDXOBJECTACCESSNVPROC)wglGetProcAddress("wglDXObjectAccessNV");
	GLM_struct->wglDXLockObjectsNVproc = (PFNWGLDXLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXLockObjectsNV");
	GLM_struct->wglDXUnlockObjectsNVproc = (PFNWGLDXUNLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXUnlockObjectsNV");
	GLM_struct->wglCopyImageSubDataNVproc = (PFNWGLCOPYIMAGESUBDATANVPROC)wglGetProcAddress("wglCopyImageSubDataNV");
	GLM_struct->wglDelayBeforeSwapNVproc = (PFNWGLDELAYBEFORESWAPNVPROC)wglGetProcAddress("wglDelayBeforeSwapNV");
	GLM_struct->wglEnumGpusNVproc = (PFNWGLENUMGPUSNVPROC)wglGetProcAddress("wglEnumGpusNV");
	GLM_struct->wglEnumGpuDevicesNVproc = (PFNWGLENUMGPUDEVICESNVPROC)wglGetProcAddress("wglEnumGpuDevicesNV");
	GLM_struct->wglCreateAffinityDCNVproc = (PFNWGLCREATEAFFINITYDCNVPROC)wglGetProcAddress("wglCreateAffinityDCNV");
	GLM_struct->wglEnumGpusFromAffinityDCNVproc = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)wglGetProcAddress("wglEnumGpusFromAffinityDCNV");
	GLM_struct->wglDeleteDCNVproc = (PFNWGLDELETEDCNVPROC)wglGetProcAddress("wglDeleteDCNV");
	GLM_struct->wglEnumerateVideoDevicesNVproc = (PFNWGLENUMERATEVIDEODEVICESNVPROC)wglGetProcAddress("wglEnumerateVideoDevicesNV");
	GLM_struct->wglBindVideoDeviceNVproc = (PFNWGLBINDVIDEODEVICENVPROC)wglGetProcAddress("wglBindVideoDeviceNV");
	GLM_struct->wglQueryCurrentContextNVproc = (PFNWGLQUERYCURRENTCONTEXTNVPROC)wglGetProcAddress("wglQueryCurrentContextNV");
	GLM_struct->wglJoinSwapGroupNVproc = (PFNWGLJOINSWAPGROUPNVPROC)wglGetProcAddress("wglJoinSwapGroupNV");
	GLM_struct->wglBindSwapBarrierNVproc = (PFNWGLBINDSWAPBARRIERNVPROC)wglGetProcAddress("wglBindSwapBarrierNV");
	GLM_struct->wglQuerySwapGroupNVproc = (PFNWGLQUERYSWAPGROUPNVPROC)wglGetProcAddress("wglQuerySwapGroupNV");
	GLM_struct->wglQueryMaxSwapGroupsNVproc = (PFNWGLQUERYMAXSWAPGROUPSNVPROC)wglGetProcAddress("wglQueryMaxSwapGroupsNV");
	GLM_struct->wglQueryFrameCountNVproc = (PFNWGLQUERYFRAMECOUNTNVPROC)wglGetProcAddress("wglQueryFrameCountNV");
	GLM_struct->wglResetFrameCountNVproc = (PFNWGLRESETFRAMECOUNTNVPROC)wglGetProcAddress("wglResetFrameCountNV");
	GLM_struct->wglAllocateMemoryNVproc = (PFNWGLALLOCATEMEMORYNVPROC)wglGetProcAddress("wglAllocateMemoryNV");
	GLM_struct->wglFreeMemoryNVproc = (PFNWGLFREEMEMORYNVPROC)wglGetProcAddress("wglFreeMemoryNV");
	GLM_struct->wglBindVideoCaptureDeviceNVproc = (PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglBindVideoCaptureDeviceNV");
	GLM_struct->wglEnumerateVideoCaptureDevicesNVproc = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)wglGetProcAddress("wglEnumerateVideoCaptureDevicesNV");
	GLM_struct->wglLockVideoCaptureDeviceNVproc = (PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglLockVideoCaptureDeviceNV");
	GLM_struct->wglQueryVideoCaptureDeviceNVproc = (PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglQueryVideoCaptureDeviceNV");
	GLM_struct->wglReleaseVideoCaptureDeviceNVproc = (PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglReleaseVideoCaptureDeviceNV");
	GLM_struct->wglGetVideoDeviceNVproc = (PFNWGLGETVIDEODEVICENVPROC)wglGetProcAddress("wglGetVideoDeviceNV");
	GLM_struct->wglReleaseVideoDeviceNVproc = (PFNWGLRELEASEVIDEODEVICENVPROC)wglGetProcAddress("wglReleaseVideoDeviceNV");
	GLM_struct->wglBindVideoImageNVproc = (PFNWGLBINDVIDEOIMAGENVPROC)wglGetProcAddress("wglBindVideoImageNV");
	GLM_struct->wglReleaseVideoImageNVproc = (PFNWGLRELEASEVIDEOIMAGENVPROC)wglGetProcAddress("wglReleaseVideoImageNV");
	GLM_struct->wglSendPbufferToVideoNVproc = (PFNWGLSENDPBUFFERTOVIDEONVPROC)wglGetProcAddress("wglSendPbufferToVideoNV");
	GLM_struct->wglGetVideoInfoNVproc = (PFNWGLGETVIDEOINFONVPROC)wglGetProcAddress("wglGetVideoInfoNV");
	GLM_struct->wglGetSyncValuesOMLproc = (PFNWGLGETSYNCVALUESOMLPROC)wglGetProcAddress("wglGetSyncValuesOML");
	GLM_struct->wglGetMscRateOMLproc = (PFNWGLGETMSCRATEOMLPROC)wglGetProcAddress("wglGetMscRateOML");
	GLM_struct->wglSwapBuffersMscOMLproc = (PFNWGLSWAPBUFFERSMSCOMLPROC)wglGetProcAddress("wglSwapBuffersMscOML");
	GLM_struct->wglSwapLayerBuffersMscOMLproc = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)wglGetProcAddress("wglSwapLayerBuffersMscOML");
	GLM_struct->wglWaitForMscOMLproc = (PFNWGLWAITFORMSCOMLPROC)wglGetProcAddress("wglWaitForMscOML");
	GLM_struct->wglWaitForSbcOMLproc = (PFNWGLWAITFORSBCOMLPROC)wglGetProcAddress("wglWaitForSbcOML");
	GLM_struct->glDrawRangeElementsproc = (PFNGLDRAWRANGEELEMENTSPROC)wglGetProcAddress("glDrawRangeElements");
	GLM_struct->glTexImage3Dproc = (PFNGLTEXIMAGE3DPROC)wglGetProcAddress("glTexImage3D");
	GLM_struct->glTexSubImage3Dproc = (PFNGLTEXSUBIMAGE3DPROC)wglGetProcAddress("glTexSubImage3D");
	GLM_struct->glCopyTexSubImage3Dproc = (PFNGLCOPYTEXSUBIMAGE3DPROC)wglGetProcAddress("glCopyTexSubImage3D");
	GLM_struct->glActiveTextureproc = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	GLM_struct->glSampleCoverageproc = (PFNGLSAMPLECOVERAGEPROC)wglGetProcAddress("glSampleCoverage");
	GLM_struct->glCompressedTexImage3Dproc = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)wglGetProcAddress("glCompressedTexImage3D");
	GLM_struct->glCompressedTexImage2Dproc = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
	GLM_struct->glCompressedTexImage1Dproc = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)wglGetProcAddress("glCompressedTexImage1D");
	GLM_struct->glCompressedTexSubImage3Dproc = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)wglGetProcAddress("glCompressedTexSubImage3D");
	GLM_struct->glCompressedTexSubImage2Dproc = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)wglGetProcAddress("glCompressedTexSubImage2D");
	GLM_struct->glCompressedTexSubImage1Dproc = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)wglGetProcAddress("glCompressedTexSubImage1D");
	GLM_struct->glGetCompressedTexImageproc = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetCompressedTexImage");
	GLM_struct->glClientActiveTextureproc = (PFNGLCLIENTACTIVETEXTUREPROC)wglGetProcAddress("glClientActiveTexture");
	GLM_struct->glMultiTexCoord1dproc = (PFNGLMULTITEXCOORD1DPROC)wglGetProcAddress("glMultiTexCoord1d");
	GLM_struct->glMultiTexCoord1dvproc = (PFNGLMULTITEXCOORD1DVPROC)wglGetProcAddress("glMultiTexCoord1dv");
	GLM_struct->glMultiTexCoord1fproc = (PFNGLMULTITEXCOORD1FPROC)wglGetProcAddress("glMultiTexCoord1f");
	GLM_struct->glMultiTexCoord1fvproc = (PFNGLMULTITEXCOORD1FVPROC)wglGetProcAddress("glMultiTexCoord1fv");
	GLM_struct->glMultiTexCoord1iproc = (PFNGLMULTITEXCOORD1IPROC)wglGetProcAddress("glMultiTexCoord1i");
	GLM_struct->glMultiTexCoord1ivproc = (PFNGLMULTITEXCOORD1IVPROC)wglGetProcAddress("glMultiTexCoord1iv");
	GLM_struct->glMultiTexCoord1sproc = (PFNGLMULTITEXCOORD1SPROC)wglGetProcAddress("glMultiTexCoord1s");
	GLM_struct->glMultiTexCoord1svproc = (PFNGLMULTITEXCOORD1SVPROC)wglGetProcAddress("glMultiTexCoord1sv");
	GLM_struct->glMultiTexCoord2dproc = (PFNGLMULTITEXCOORD2DPROC)wglGetProcAddress("glMultiTexCoord2d");
	GLM_struct->glMultiTexCoord2dvproc = (PFNGLMULTITEXCOORD2DVPROC)wglGetProcAddress("glMultiTexCoord2dv");
	GLM_struct->glMultiTexCoord2fproc = (PFNGLMULTITEXCOORD2FPROC)wglGetProcAddress("glMultiTexCoord2f");
	GLM_struct->glMultiTexCoord2fvproc = (PFNGLMULTITEXCOORD2FVPROC)wglGetProcAddress("glMultiTexCoord2fv");
	GLM_struct->glMultiTexCoord2iproc = (PFNGLMULTITEXCOORD2IPROC)wglGetProcAddress("glMultiTexCoord2i");
	GLM_struct->glMultiTexCoord2ivproc = (PFNGLMULTITEXCOORD2IVPROC)wglGetProcAddress("glMultiTexCoord2iv");
	GLM_struct->glMultiTexCoord2sproc = (PFNGLMULTITEXCOORD2SPROC)wglGetProcAddress("glMultiTexCoord2s");
	GLM_struct->glMultiTexCoord2svproc = (PFNGLMULTITEXCOORD2SVPROC)wglGetProcAddress("glMultiTexCoord2sv");
	GLM_struct->glMultiTexCoord3dproc = (PFNGLMULTITEXCOORD3DPROC)wglGetProcAddress("glMultiTexCoord3d");
	GLM_struct->glMultiTexCoord3dvproc = (PFNGLMULTITEXCOORD3DVPROC)wglGetProcAddress("glMultiTexCoord3dv");
	GLM_struct->glMultiTexCoord3fproc = (PFNGLMULTITEXCOORD3FPROC)wglGetProcAddress("glMultiTexCoord3f");
	GLM_struct->glMultiTexCoord3fvproc = (PFNGLMULTITEXCOORD3FVPROC)wglGetProcAddress("glMultiTexCoord3fv");
	GLM_struct->glMultiTexCoord3iproc = (PFNGLMULTITEXCOORD3IPROC)wglGetProcAddress("glMultiTexCoord3i");
	GLM_struct->glMultiTexCoord3ivproc = (PFNGLMULTITEXCOORD3IVPROC)wglGetProcAddress("glMultiTexCoord3iv");
	GLM_struct->glMultiTexCoord3sproc = (PFNGLMULTITEXCOORD3SPROC)wglGetProcAddress("glMultiTexCoord3s");
	GLM_struct->glMultiTexCoord3svproc = (PFNGLMULTITEXCOORD3SVPROC)wglGetProcAddress("glMultiTexCoord3sv");
	GLM_struct->glMultiTexCoord4dproc = (PFNGLMULTITEXCOORD4DPROC)wglGetProcAddress("glMultiTexCoord4d");
	GLM_struct->glMultiTexCoord4dvproc = (PFNGLMULTITEXCOORD4DVPROC)wglGetProcAddress("glMultiTexCoord4dv");
	GLM_struct->glMultiTexCoord4fproc = (PFNGLMULTITEXCOORD4FPROC)wglGetProcAddress("glMultiTexCoord4f");
	GLM_struct->glMultiTexCoord4fvproc = (PFNGLMULTITEXCOORD4FVPROC)wglGetProcAddress("glMultiTexCoord4fv");
	GLM_struct->glMultiTexCoord4iproc = (PFNGLMULTITEXCOORD4IPROC)wglGetProcAddress("glMultiTexCoord4i");
	GLM_struct->glMultiTexCoord4ivproc = (PFNGLMULTITEXCOORD4IVPROC)wglGetProcAddress("glMultiTexCoord4iv");
	GLM_struct->glMultiTexCoord4sproc = (PFNGLMULTITEXCOORD4SPROC)wglGetProcAddress("glMultiTexCoord4s");
	GLM_struct->glMultiTexCoord4svproc = (PFNGLMULTITEXCOORD4SVPROC)wglGetProcAddress("glMultiTexCoord4sv");
	GLM_struct->glLoadTransposeMatrixfproc = (PFNGLLOADTRANSPOSEMATRIXFPROC)wglGetProcAddress("glLoadTransposeMatrixf");
	GLM_struct->glLoadTransposeMatrixdproc = (PFNGLLOADTRANSPOSEMATRIXDPROC)wglGetProcAddress("glLoadTransposeMatrixd");
	GLM_struct->glMultTransposeMatrixfproc = (PFNGLMULTTRANSPOSEMATRIXFPROC)wglGetProcAddress("glMultTransposeMatrixf");
	GLM_struct->glMultTransposeMatrixdproc = (PFNGLMULTTRANSPOSEMATRIXDPROC)wglGetProcAddress("glMultTransposeMatrixd");
	GLM_struct->glBlendFuncSeparateproc = (PFNGLBLENDFUNCSEPARATEPROC)wglGetProcAddress("glBlendFuncSeparate");
	GLM_struct->glMultiDrawArraysproc = (PFNGLMULTIDRAWARRAYSPROC)wglGetProcAddress("glMultiDrawArrays");
	GLM_struct->glMultiDrawElementsproc = (PFNGLMULTIDRAWELEMENTSPROC)wglGetProcAddress("glMultiDrawElements");
	GLM_struct->glPointParameterfproc = (PFNGLPOINTPARAMETERFPROC)wglGetProcAddress("glPointParameterf");
	GLM_struct->glPointParameterfvproc = (PFNGLPOINTPARAMETERFVPROC)wglGetProcAddress("glPointParameterfv");
	GLM_struct->glPointParameteriproc = (PFNGLPOINTPARAMETERIPROC)wglGetProcAddress("glPointParameteri");
	GLM_struct->glPointParameterivproc = (PFNGLPOINTPARAMETERIVPROC)wglGetProcAddress("glPointParameteriv");
	GLM_struct->glFogCoordfproc = (PFNGLFOGCOORDFPROC)wglGetProcAddress("glFogCoordf");
	GLM_struct->glFogCoordfvproc = (PFNGLFOGCOORDFVPROC)wglGetProcAddress("glFogCoordfv");
	GLM_struct->glFogCoorddproc = (PFNGLFOGCOORDDPROC)wglGetProcAddress("glFogCoordd");
	GLM_struct->glFogCoorddvproc = (PFNGLFOGCOORDDVPROC)wglGetProcAddress("glFogCoorddv");
	GLM_struct->glFogCoordPointerproc = (PFNGLFOGCOORDPOINTERPROC)wglGetProcAddress("glFogCoordPointer");
	GLM_struct->glSecondaryColor3bproc = (PFNGLSECONDARYCOLOR3BPROC)wglGetProcAddress("glSecondaryColor3b");
	GLM_struct->glSecondaryColor3bvproc = (PFNGLSECONDARYCOLOR3BVPROC)wglGetProcAddress("glSecondaryColor3bv");
	GLM_struct->glSecondaryColor3dproc = (PFNGLSECONDARYCOLOR3DPROC)wglGetProcAddress("glSecondaryColor3d");
	GLM_struct->glSecondaryColor3dvproc = (PFNGLSECONDARYCOLOR3DVPROC)wglGetProcAddress("glSecondaryColor3dv");
	GLM_struct->glSecondaryColor3fproc = (PFNGLSECONDARYCOLOR3FPROC)wglGetProcAddress("glSecondaryColor3f");
	GLM_struct->glSecondaryColor3fvproc = (PFNGLSECONDARYCOLOR3FVPROC)wglGetProcAddress("glSecondaryColor3fv");
	GLM_struct->glSecondaryColor3iproc = (PFNGLSECONDARYCOLOR3IPROC)wglGetProcAddress("glSecondaryColor3i");
	GLM_struct->glSecondaryColor3ivproc = (PFNGLSECONDARYCOLOR3IVPROC)wglGetProcAddress("glSecondaryColor3iv");
	GLM_struct->glSecondaryColor3sproc = (PFNGLSECONDARYCOLOR3SPROC)wglGetProcAddress("glSecondaryColor3s");
	GLM_struct->glSecondaryColor3svproc = (PFNGLSECONDARYCOLOR3SVPROC)wglGetProcAddress("glSecondaryColor3sv");
	GLM_struct->glSecondaryColor3ubproc = (PFNGLSECONDARYCOLOR3UBPROC)wglGetProcAddress("glSecondaryColor3ub");
	GLM_struct->glSecondaryColor3ubvproc = (PFNGLSECONDARYCOLOR3UBVPROC)wglGetProcAddress("glSecondaryColor3ubv");
	GLM_struct->glSecondaryColor3uiproc = (PFNGLSECONDARYCOLOR3UIPROC)wglGetProcAddress("glSecondaryColor3ui");
	GLM_struct->glSecondaryColor3uivproc = (PFNGLSECONDARYCOLOR3UIVPROC)wglGetProcAddress("glSecondaryColor3uiv");
	GLM_struct->glSecondaryColor3usproc = (PFNGLSECONDARYCOLOR3USPROC)wglGetProcAddress("glSecondaryColor3us");
	GLM_struct->glSecondaryColor3usvproc = (PFNGLSECONDARYCOLOR3USVPROC)wglGetProcAddress("glSecondaryColor3usv");
	GLM_struct->glSecondaryColorPointerproc = (PFNGLSECONDARYCOLORPOINTERPROC)wglGetProcAddress("glSecondaryColorPointer");
	GLM_struct->glWindowPos2dproc = (PFNGLWINDOWPOS2DPROC)wglGetProcAddress("glWindowPos2d");
	GLM_struct->glWindowPos2dvproc = (PFNGLWINDOWPOS2DVPROC)wglGetProcAddress("glWindowPos2dv");
	GLM_struct->glWindowPos2fproc = (PFNGLWINDOWPOS2FPROC)wglGetProcAddress("glWindowPos2f");
	GLM_struct->glWindowPos2fvproc = (PFNGLWINDOWPOS2FVPROC)wglGetProcAddress("glWindowPos2fv");
	GLM_struct->glWindowPos2iproc = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress("glWindowPos2i");
	GLM_struct->glWindowPos2ivproc = (PFNGLWINDOWPOS2IVPROC)wglGetProcAddress("glWindowPos2iv");
	GLM_struct->glWindowPos2sproc = (PFNGLWINDOWPOS2SPROC)wglGetProcAddress("glWindowPos2s");
	GLM_struct->glWindowPos2svproc = (PFNGLWINDOWPOS2SVPROC)wglGetProcAddress("glWindowPos2sv");
	GLM_struct->glWindowPos3dproc = (PFNGLWINDOWPOS3DPROC)wglGetProcAddress("glWindowPos3d");
	GLM_struct->glWindowPos3dvproc = (PFNGLWINDOWPOS3DVPROC)wglGetProcAddress("glWindowPos3dv");
	GLM_struct->glWindowPos3fproc = (PFNGLWINDOWPOS3FPROC)wglGetProcAddress("glWindowPos3f");
	GLM_struct->glWindowPos3fvproc = (PFNGLWINDOWPOS3FVPROC)wglGetProcAddress("glWindowPos3fv");
	GLM_struct->glWindowPos3iproc = (PFNGLWINDOWPOS3IPROC)wglGetProcAddress("glWindowPos3i");
	GLM_struct->glWindowPos3ivproc = (PFNGLWINDOWPOS3IVPROC)wglGetProcAddress("glWindowPos3iv");
	GLM_struct->glWindowPos3sproc = (PFNGLWINDOWPOS3SPROC)wglGetProcAddress("glWindowPos3s");
	GLM_struct->glWindowPos3svproc = (PFNGLWINDOWPOS3SVPROC)wglGetProcAddress("glWindowPos3sv");
	GLM_struct->glBlendColorproc = (PFNGLBLENDCOLORPROC)wglGetProcAddress("glBlendColor");
	GLM_struct->glBlendEquationproc = (PFNGLBLENDEQUATIONPROC)wglGetProcAddress("glBlendEquation");
	GLM_struct->glGenQueriesproc = (PFNGLGENQUERIESPROC)wglGetProcAddress("glGenQueries");
	GLM_struct->glDeleteQueriesproc = (PFNGLDELETEQUERIESPROC)wglGetProcAddress("glDeleteQueries");
	GLM_struct->glIsQueryproc = (PFNGLISQUERYPROC)wglGetProcAddress("glIsQuery");
	GLM_struct->glBeginQueryproc = (PFNGLBEGINQUERYPROC)wglGetProcAddress("glBeginQuery");
	GLM_struct->glEndQueryproc = (PFNGLENDQUERYPROC)wglGetProcAddress("glEndQuery");
	GLM_struct->glGetQueryivproc = (PFNGLGETQUERYIVPROC)wglGetProcAddress("glGetQueryiv");
	GLM_struct->glGetQueryObjectivproc = (PFNGLGETQUERYOBJECTIVPROC)wglGetProcAddress("glGetQueryObjectiv");
	GLM_struct->glGetQueryObjectuivproc = (PFNGLGETQUERYOBJECTUIVPROC)wglGetProcAddress("glGetQueryObjectuiv");
	GLM_struct->glBindBufferproc = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	GLM_struct->glDeleteBuffersproc = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
	GLM_struct->glGenBuffersproc = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	GLM_struct->glIsBufferproc = (PFNGLISBUFFERPROC)wglGetProcAddress("glIsBuffer");
	GLM_struct->glBufferDataproc = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	GLM_struct->glBufferSubDataproc = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
	GLM_struct->glGetBufferSubDataproc = (PFNGLGETBUFFERSUBDATAPROC)wglGetProcAddress("glGetBufferSubData");
	GLM_struct->glMapBufferproc = (PFNGLMAPBUFFERPROC)wglGetProcAddress("glMapBuffer");
	GLM_struct->glUnmapBufferproc = (PFNGLUNMAPBUFFERPROC)wglGetProcAddress("glUnmapBuffer");
	GLM_struct->glGetBufferParameterivproc = (PFNGLGETBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetBufferParameteriv");
	GLM_struct->glGetBufferPointervproc = (PFNGLGETBUFFERPOINTERVPROC)wglGetProcAddress("glGetBufferPointerv");
	GLM_struct->glBlendEquationSeparateproc = (PFNGLBLENDEQUATIONSEPARATEPROC)wglGetProcAddress("glBlendEquationSeparate");
	GLM_struct->glDrawBuffersproc = (PFNGLDRAWBUFFERSPROC)wglGetProcAddress("glDrawBuffers");
	GLM_struct->glStencilOpSeparateproc = (PFNGLSTENCILOPSEPARATEPROC)wglGetProcAddress("glStencilOpSeparate");
	GLM_struct->glStencilFuncSeparateproc = (PFNGLSTENCILFUNCSEPARATEPROC)wglGetProcAddress("glStencilFuncSeparate");
	GLM_struct->glStencilMaskSeparateproc = (PFNGLSTENCILMASKSEPARATEPROC)wglGetProcAddress("glStencilMaskSeparate");
	GLM_struct->glAttachShaderproc = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	GLM_struct->glBindAttribLocationproc = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	GLM_struct->glCompileShaderproc = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	GLM_struct->glCreateProgramproc = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	GLM_struct->glCreateShaderproc = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	GLM_struct->glDeleteProgramproc = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	GLM_struct->glDeleteShaderproc = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	GLM_struct->glDetachShaderproc = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	GLM_struct->glDisableVertexAttribArrayproc = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
	GLM_struct->glEnableVertexAttribArrayproc = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	GLM_struct->glGetActiveAttribproc = (PFNGLGETACTIVEATTRIBPROC)wglGetProcAddress("glGetActiveAttrib");
	GLM_struct->glGetActiveUniformproc = (PFNGLGETACTIVEUNIFORMPROC)wglGetProcAddress("glGetActiveUniform");
	GLM_struct->glGetAttachedShadersproc = (PFNGLGETATTACHEDSHADERSPROC)wglGetProcAddress("glGetAttachedShaders");
	GLM_struct->glGetAttribLocationproc = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	GLM_struct->glGetProgramivproc = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	GLM_struct->glGetProgramInfoLogproc = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	GLM_struct->glGetShaderivproc = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	GLM_struct->glGetShaderInfoLogproc = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	GLM_struct->glGetShaderSourceproc = (PFNGLGETSHADERSOURCEPROC)wglGetProcAddress("glGetShaderSource");
	GLM_struct->glGetUniformLocationproc = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	GLM_struct->glGetUniformfvproc = (PFNGLGETUNIFORMFVPROC)wglGetProcAddress("glGetUniformfv");
	GLM_struct->glGetUniformivproc = (PFNGLGETUNIFORMIVPROC)wglGetProcAddress("glGetUniformiv");
	GLM_struct->glGetVertexAttribdvproc = (PFNGLGETVERTEXATTRIBDVPROC)wglGetProcAddress("glGetVertexAttribdv");
	GLM_struct->glGetVertexAttribfvproc = (PFNGLGETVERTEXATTRIBFVPROC)wglGetProcAddress("glGetVertexAttribfv");
	GLM_struct->glGetVertexAttribivproc = (PFNGLGETVERTEXATTRIBIVPROC)wglGetProcAddress("glGetVertexAttribiv");
	GLM_struct->glGetVertexAttribPointervproc = (PFNGLGETVERTEXATTRIBPOINTERVPROC)wglGetProcAddress("glGetVertexAttribPointerv");
	GLM_struct->glIsProgramproc = (PFNGLISPROGRAMPROC)wglGetProcAddress("glIsProgram");
	GLM_struct->glIsShaderproc = (PFNGLISSHADERPROC)wglGetProcAddress("glIsShader");
	GLM_struct->glLinkProgramproc = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	GLM_struct->glShaderSourceproc = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	GLM_struct->glUseProgramproc = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	GLM_struct->glUniform1fproc = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	GLM_struct->glUniform2fproc = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
	GLM_struct->glUniform3fproc = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
	GLM_struct->glUniform4fproc = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
	GLM_struct->glUniform1iproc = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	GLM_struct->glUniform2iproc = (PFNGLUNIFORM2IPROC)wglGetProcAddress("glUniform2i");
	GLM_struct->glUniform3iproc = (PFNGLUNIFORM3IPROC)wglGetProcAddress("glUniform3i");
	GLM_struct->glUniform4iproc = (PFNGLUNIFORM4IPROC)wglGetProcAddress("glUniform4i");
	GLM_struct->glUniform1fvproc = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
	GLM_struct->glUniform2fvproc = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
	GLM_struct->glUniform3fvproc = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	GLM_struct->glUniform4fvproc = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	GLM_struct->glUniform1ivproc = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
	GLM_struct->glUniform2ivproc = (PFNGLUNIFORM2IVPROC)wglGetProcAddress("glUniform2iv");
	GLM_struct->glUniform3ivproc = (PFNGLUNIFORM3IVPROC)wglGetProcAddress("glUniform3iv");
	GLM_struct->glUniform4ivproc = (PFNGLUNIFORM4IVPROC)wglGetProcAddress("glUniform4iv");
	GLM_struct->glUniformMatrix2fvproc = (PFNGLUNIFORMMATRIX2FVPROC)wglGetProcAddress("glUniformMatrix2fv");
	GLM_struct->glUniformMatrix3fvproc = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
	GLM_struct->glUniformMatrix4fvproc = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	GLM_struct->glValidateProgramproc = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
	GLM_struct->glVertexAttrib1dproc = (PFNGLVERTEXATTRIB1DPROC)wglGetProcAddress("glVertexAttrib1d");
	GLM_struct->glVertexAttrib1dvproc = (PFNGLVERTEXATTRIB1DVPROC)wglGetProcAddress("glVertexAttrib1dv");
	GLM_struct->glVertexAttrib1fproc = (PFNGLVERTEXATTRIB1FPROC)wglGetProcAddress("glVertexAttrib1f");
	GLM_struct->glVertexAttrib1fvproc = (PFNGLVERTEXATTRIB1FVPROC)wglGetProcAddress("glVertexAttrib1fv");
	GLM_struct->glVertexAttrib1sproc = (PFNGLVERTEXATTRIB1SPROC)wglGetProcAddress("glVertexAttrib1s");
	GLM_struct->glVertexAttrib1svproc = (PFNGLVERTEXATTRIB1SVPROC)wglGetProcAddress("glVertexAttrib1sv");
	GLM_struct->glVertexAttrib2dproc = (PFNGLVERTEXATTRIB2DPROC)wglGetProcAddress("glVertexAttrib2d");
	GLM_struct->glVertexAttrib2dvproc = (PFNGLVERTEXATTRIB2DVPROC)wglGetProcAddress("glVertexAttrib2dv");
	GLM_struct->glVertexAttrib2fproc = (PFNGLVERTEXATTRIB2FPROC)wglGetProcAddress("glVertexAttrib2f");
	GLM_struct->glVertexAttrib2fvproc = (PFNGLVERTEXATTRIB2FVPROC)wglGetProcAddress("glVertexAttrib2fv");
	GLM_struct->glVertexAttrib2sproc = (PFNGLVERTEXATTRIB2SPROC)wglGetProcAddress("glVertexAttrib2s");
	GLM_struct->glVertexAttrib2svproc = (PFNGLVERTEXATTRIB2SVPROC)wglGetProcAddress("glVertexAttrib2sv");
	GLM_struct->glVertexAttrib3dproc = (PFNGLVERTEXATTRIB3DPROC)wglGetProcAddress("glVertexAttrib3d");
	GLM_struct->glVertexAttrib3dvproc = (PFNGLVERTEXATTRIB3DVPROC)wglGetProcAddress("glVertexAttrib3dv");
	GLM_struct->glVertexAttrib3fproc = (PFNGLVERTEXATTRIB3FPROC)wglGetProcAddress("glVertexAttrib3f");
	GLM_struct->glVertexAttrib3fvproc = (PFNGLVERTEXATTRIB3FVPROC)wglGetProcAddress("glVertexAttrib3fv");
	GLM_struct->glVertexAttrib3sproc = (PFNGLVERTEXATTRIB3SPROC)wglGetProcAddress("glVertexAttrib3s");
	GLM_struct->glVertexAttrib3svproc = (PFNGLVERTEXATTRIB3SVPROC)wglGetProcAddress("glVertexAttrib3sv");
	GLM_struct->glVertexAttrib4Nbvproc = (PFNGLVERTEXATTRIB4NBVPROC)wglGetProcAddress("glVertexAttrib4Nbv");
	GLM_struct->glVertexAttrib4Nivproc = (PFNGLVERTEXATTRIB4NIVPROC)wglGetProcAddress("glVertexAttrib4Niv");
	GLM_struct->glVertexAttrib4Nsvproc = (PFNGLVERTEXATTRIB4NSVPROC)wglGetProcAddress("glVertexAttrib4Nsv");
	GLM_struct->glVertexAttrib4Nubproc = (PFNGLVERTEXATTRIB4NUBPROC)wglGetProcAddress("glVertexAttrib4Nub");
	GLM_struct->glVertexAttrib4Nubvproc = (PFNGLVERTEXATTRIB4NUBVPROC)wglGetProcAddress("glVertexAttrib4Nubv");
	GLM_struct->glVertexAttrib4Nuivproc = (PFNGLVERTEXATTRIB4NUIVPROC)wglGetProcAddress("glVertexAttrib4Nuiv");
	GLM_struct->glVertexAttrib4Nusvproc = (PFNGLVERTEXATTRIB4NUSVPROC)wglGetProcAddress("glVertexAttrib4Nusv");
	GLM_struct->glVertexAttrib4bvproc = (PFNGLVERTEXATTRIB4BVPROC)wglGetProcAddress("glVertexAttrib4bv");
	GLM_struct->glVertexAttrib4dproc = (PFNGLVERTEXATTRIB4DPROC)wglGetProcAddress("glVertexAttrib4d");
	GLM_struct->glVertexAttrib4dvproc = (PFNGLVERTEXATTRIB4DVPROC)wglGetProcAddress("glVertexAttrib4dv");
	GLM_struct->glVertexAttrib4fproc = (PFNGLVERTEXATTRIB4FPROC)wglGetProcAddress("glVertexAttrib4f");
	GLM_struct->glVertexAttrib4fvproc = (PFNGLVERTEXATTRIB4FVPROC)wglGetProcAddress("glVertexAttrib4fv");
	GLM_struct->glVertexAttrib4ivproc = (PFNGLVERTEXATTRIB4IVPROC)wglGetProcAddress("glVertexAttrib4iv");
	GLM_struct->glVertexAttrib4sproc = (PFNGLVERTEXATTRIB4SPROC)wglGetProcAddress("glVertexAttrib4s");
	GLM_struct->glVertexAttrib4svproc = (PFNGLVERTEXATTRIB4SVPROC)wglGetProcAddress("glVertexAttrib4sv");
	GLM_struct->glVertexAttrib4ubvproc = (PFNGLVERTEXATTRIB4UBVPROC)wglGetProcAddress("glVertexAttrib4ubv");
	GLM_struct->glVertexAttrib4uivproc = (PFNGLVERTEXATTRIB4UIVPROC)wglGetProcAddress("glVertexAttrib4uiv");
	GLM_struct->glVertexAttrib4usvproc = (PFNGLVERTEXATTRIB4USVPROC)wglGetProcAddress("glVertexAttrib4usv");
	GLM_struct->glVertexAttribPointerproc = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	GLM_struct->glUniformMatrix2x3fvproc = (PFNGLUNIFORMMATRIX2X3FVPROC)wglGetProcAddress("glUniformMatrix2x3fv");
	GLM_struct->glUniformMatrix3x2fvproc = (PFNGLUNIFORMMATRIX3X2FVPROC)wglGetProcAddress("glUniformMatrix3x2fv");
	GLM_struct->glUniformMatrix2x4fvproc = (PFNGLUNIFORMMATRIX2X4FVPROC)wglGetProcAddress("glUniformMatrix2x4fv");
	GLM_struct->glUniformMatrix4x2fvproc = (PFNGLUNIFORMMATRIX4X2FVPROC)wglGetProcAddress("glUniformMatrix4x2fv");
	GLM_struct->glUniformMatrix3x4fvproc = (PFNGLUNIFORMMATRIX3X4FVPROC)wglGetProcAddress("glUniformMatrix3x4fv");
	GLM_struct->glUniformMatrix4x3fvproc = (PFNGLUNIFORMMATRIX4X3FVPROC)wglGetProcAddress("glUniformMatrix4x3fv");
	GLM_struct->glColorMaskiproc = (PFNGLCOLORMASKIPROC)wglGetProcAddress("glColorMaski");
	GLM_struct->glGetBooleani_vproc = (PFNGLGETBOOLEANI_VPROC)wglGetProcAddress("glGetBooleani_v");
	GLM_struct->glGetIntegeri_vproc = (PFNGLGETINTEGERI_VPROC)wglGetProcAddress("glGetIntegeri_v");
	GLM_struct->glEnableiproc = (PFNGLENABLEIPROC)wglGetProcAddress("glEnablei");
	GLM_struct->glDisableiproc = (PFNGLDISABLEIPROC)wglGetProcAddress("glDisablei");
	GLM_struct->glIsEnablediproc = (PFNGLISENABLEDIPROC)wglGetProcAddress("glIsEnabledi");
	GLM_struct->glBeginTransformFeedbackproc = (PFNGLBEGINTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBeginTransformFeedback");
	GLM_struct->glEndTransformFeedbackproc = (PFNGLENDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glEndTransformFeedback");
	GLM_struct->glBindBufferRangeproc = (PFNGLBINDBUFFERRANGEPROC)wglGetProcAddress("glBindBufferRange");
	GLM_struct->glBindBufferBaseproc = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase");
	GLM_struct->glTransformFeedbackVaryingsproc = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)wglGetProcAddress("glTransformFeedbackVaryings");
	GLM_struct->glGetTransformFeedbackVaryingproc = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)wglGetProcAddress("glGetTransformFeedbackVarying");
	GLM_struct->glClampColorproc = (PFNGLCLAMPCOLORPROC)wglGetProcAddress("glClampColor");
	GLM_struct->glBeginConditionalRenderproc = (PFNGLBEGINCONDITIONALRENDERPROC)wglGetProcAddress("glBeginConditionalRender");
	GLM_struct->glEndConditionalRenderproc = (PFNGLENDCONDITIONALRENDERPROC)wglGetProcAddress("glEndConditionalRender");
	GLM_struct->glVertexAttribIPointerproc = (PFNGLVERTEXATTRIBIPOINTERPROC)wglGetProcAddress("glVertexAttribIPointer");
	GLM_struct->glGetVertexAttribIivproc = (PFNGLGETVERTEXATTRIBIIVPROC)wglGetProcAddress("glGetVertexAttribIiv");
	GLM_struct->glGetVertexAttribIuivproc = (PFNGLGETVERTEXATTRIBIUIVPROC)wglGetProcAddress("glGetVertexAttribIuiv");
	GLM_struct->glVertexAttribI1iproc = (PFNGLVERTEXATTRIBI1IPROC)wglGetProcAddress("glVertexAttribI1i");
	GLM_struct->glVertexAttribI2iproc = (PFNGLVERTEXATTRIBI2IPROC)wglGetProcAddress("glVertexAttribI2i");
	GLM_struct->glVertexAttribI3iproc = (PFNGLVERTEXATTRIBI3IPROC)wglGetProcAddress("glVertexAttribI3i");
	GLM_struct->glVertexAttribI4iproc = (PFNGLVERTEXATTRIBI4IPROC)wglGetProcAddress("glVertexAttribI4i");
	GLM_struct->glVertexAttribI1uiproc = (PFNGLVERTEXATTRIBI1UIPROC)wglGetProcAddress("glVertexAttribI1ui");
	GLM_struct->glVertexAttribI2uiproc = (PFNGLVERTEXATTRIBI2UIPROC)wglGetProcAddress("glVertexAttribI2ui");
	GLM_struct->glVertexAttribI3uiproc = (PFNGLVERTEXATTRIBI3UIPROC)wglGetProcAddress("glVertexAttribI3ui");
	GLM_struct->glVertexAttribI4uiproc = (PFNGLVERTEXATTRIBI4UIPROC)wglGetProcAddress("glVertexAttribI4ui");
	GLM_struct->glVertexAttribI1ivproc = (PFNGLVERTEXATTRIBI1IVPROC)wglGetProcAddress("glVertexAttribI1iv");
	GLM_struct->glVertexAttribI2ivproc = (PFNGLVERTEXATTRIBI2IVPROC)wglGetProcAddress("glVertexAttribI2iv");
	GLM_struct->glVertexAttribI3ivproc = (PFNGLVERTEXATTRIBI3IVPROC)wglGetProcAddress("glVertexAttribI3iv");
	GLM_struct->glVertexAttribI4ivproc = (PFNGLVERTEXATTRIBI4IVPROC)wglGetProcAddress("glVertexAttribI4iv");
	GLM_struct->glVertexAttribI1uivproc = (PFNGLVERTEXATTRIBI1UIVPROC)wglGetProcAddress("glVertexAttribI1uiv");
	GLM_struct->glVertexAttribI2uivproc = (PFNGLVERTEXATTRIBI2UIVPROC)wglGetProcAddress("glVertexAttribI2uiv");
	GLM_struct->glVertexAttribI3uivproc = (PFNGLVERTEXATTRIBI3UIVPROC)wglGetProcAddress("glVertexAttribI3uiv");
	GLM_struct->glVertexAttribI4uivproc = (PFNGLVERTEXATTRIBI4UIVPROC)wglGetProcAddress("glVertexAttribI4uiv");
	GLM_struct->glVertexAttribI4bvproc = (PFNGLVERTEXATTRIBI4BVPROC)wglGetProcAddress("glVertexAttribI4bv");
	GLM_struct->glVertexAttribI4svproc = (PFNGLVERTEXATTRIBI4SVPROC)wglGetProcAddress("glVertexAttribI4sv");
	GLM_struct->glVertexAttribI4ubvproc = (PFNGLVERTEXATTRIBI4UBVPROC)wglGetProcAddress("glVertexAttribI4ubv");
	GLM_struct->glVertexAttribI4usvproc = (PFNGLVERTEXATTRIBI4USVPROC)wglGetProcAddress("glVertexAttribI4usv");
	GLM_struct->glGetUniformuivproc = (PFNGLGETUNIFORMUIVPROC)wglGetProcAddress("glGetUniformuiv");
	GLM_struct->glBindFragDataLocationproc = (PFNGLBINDFRAGDATALOCATIONPROC)wglGetProcAddress("glBindFragDataLocation");
	GLM_struct->glGetFragDataLocationproc = (PFNGLGETFRAGDATALOCATIONPROC)wglGetProcAddress("glGetFragDataLocation");
	GLM_struct->glUniform1uiproc = (PFNGLUNIFORM1UIPROC)wglGetProcAddress("glUniform1ui");
	GLM_struct->glUniform2uiproc = (PFNGLUNIFORM2UIPROC)wglGetProcAddress("glUniform2ui");
	GLM_struct->glUniform3uiproc = (PFNGLUNIFORM3UIPROC)wglGetProcAddress("glUniform3ui");
	GLM_struct->glUniform4uiproc = (PFNGLUNIFORM4UIPROC)wglGetProcAddress("glUniform4ui");
	GLM_struct->glUniform1uivproc = (PFNGLUNIFORM1UIVPROC)wglGetProcAddress("glUniform1uiv");
	GLM_struct->glUniform2uivproc = (PFNGLUNIFORM2UIVPROC)wglGetProcAddress("glUniform2uiv");
	GLM_struct->glUniform3uivproc = (PFNGLUNIFORM3UIVPROC)wglGetProcAddress("glUniform3uiv");
	GLM_struct->glUniform4uivproc = (PFNGLUNIFORM4UIVPROC)wglGetProcAddress("glUniform4uiv");
	GLM_struct->glTexParameterIivproc = (PFNGLTEXPARAMETERIIVPROC)wglGetProcAddress("glTexParameterIiv");
	GLM_struct->glTexParameterIuivproc = (PFNGLTEXPARAMETERIUIVPROC)wglGetProcAddress("glTexParameterIuiv");
	GLM_struct->glGetTexParameterIivproc = (PFNGLGETTEXPARAMETERIIVPROC)wglGetProcAddress("glGetTexParameterIiv");
	GLM_struct->glGetTexParameterIuivproc = (PFNGLGETTEXPARAMETERIUIVPROC)wglGetProcAddress("glGetTexParameterIuiv");
	GLM_struct->glClearBufferivproc = (PFNGLCLEARBUFFERIVPROC)wglGetProcAddress("glClearBufferiv");
	GLM_struct->glClearBufferuivproc = (PFNGLCLEARBUFFERUIVPROC)wglGetProcAddress("glClearBufferuiv");
	GLM_struct->glClearBufferfvproc = (PFNGLCLEARBUFFERFVPROC)wglGetProcAddress("glClearBufferfv");
	GLM_struct->glClearBufferfiproc = (PFNGLCLEARBUFFERFIPROC)wglGetProcAddress("glClearBufferfi");
	GLM_struct->glGetStringiproc = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
	GLM_struct->glIsRenderbufferproc = (PFNGLISRENDERBUFFERPROC)wglGetProcAddress("glIsRenderbuffer");
	GLM_struct->glBindRenderbufferproc = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
	GLM_struct->glDeleteRenderbuffersproc = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
	GLM_struct->glGenRenderbuffersproc = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
	GLM_struct->glRenderbufferStorageproc = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
	GLM_struct->glGetRenderbufferParameterivproc = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetRenderbufferParameteriv");
	GLM_struct->glIsFramebufferproc = (PFNGLISFRAMEBUFFERPROC)wglGetProcAddress("glIsFramebuffer");
	GLM_struct->glBindFramebufferproc = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
	GLM_struct->glDeleteFramebuffersproc = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
	GLM_struct->glGenFramebuffersproc = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
	GLM_struct->glCheckFramebufferStatusproc = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
	GLM_struct->glFramebufferTexture1Dproc = (PFNGLFRAMEBUFFERTEXTURE1DPROC)wglGetProcAddress("glFramebufferTexture1D");
	GLM_struct->glFramebufferTexture2Dproc = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
	GLM_struct->glFramebufferTexture3Dproc = (PFNGLFRAMEBUFFERTEXTURE3DPROC)wglGetProcAddress("glFramebufferTexture3D");
	GLM_struct->glFramebufferRenderbufferproc = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
	GLM_struct->glGetFramebufferAttachmentParameterivproc = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferAttachmentParameteriv");
	GLM_struct->glGenerateMipmapproc = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
	GLM_struct->glBlitFramebufferproc = (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");
	GLM_struct->glRenderbufferStorageMultisampleproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
	GLM_struct->glFramebufferTextureLayerproc = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glFramebufferTextureLayer");
	GLM_struct->glMapBufferRangeproc = (PFNGLMAPBUFFERRANGEPROC)wglGetProcAddress("glMapBufferRange");
	GLM_struct->glFlushMappedBufferRangeproc = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedBufferRange");
	GLM_struct->glBindVertexArrayproc = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	GLM_struct->glDeleteVertexArraysproc = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
	GLM_struct->glGenVertexArraysproc = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	GLM_struct->glIsVertexArrayproc = (PFNGLISVERTEXARRAYPROC)wglGetProcAddress("glIsVertexArray");
	GLM_struct->glDrawArraysInstancedproc = (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
	GLM_struct->glDrawElementsInstancedproc = (PFNGLDRAWELEMENTSINSTANCEDPROC)wglGetProcAddress("glDrawElementsInstanced");
	GLM_struct->glTexBufferproc = (PFNGLTEXBUFFERPROC)wglGetProcAddress("glTexBuffer");
	GLM_struct->glPrimitiveRestartIndexproc = (PFNGLPRIMITIVERESTARTINDEXPROC)wglGetProcAddress("glPrimitiveRestartIndex");
	GLM_struct->glCopyBufferSubDataproc = (PFNGLCOPYBUFFERSUBDATAPROC)wglGetProcAddress("glCopyBufferSubData");
	GLM_struct->glGetUniformIndicesproc = (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
	GLM_struct->glGetActiveUniformsivproc = (PFNGLGETACTIVEUNIFORMSIVPROC)wglGetProcAddress("glGetActiveUniformsiv");
	GLM_struct->glGetActiveUniformNameproc = (PFNGLGETACTIVEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveUniformName");
	GLM_struct->glGetUniformBlockIndexproc = (PFNGLGETUNIFORMBLOCKINDEXPROC)wglGetProcAddress("glGetUniformBlockIndex");
	GLM_struct->glGetActiveUniformBlockivproc = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)wglGetProcAddress("glGetActiveUniformBlockiv");
	GLM_struct->glGetActiveUniformBlockNameproc = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)wglGetProcAddress("glGetActiveUniformBlockName");
	GLM_struct->glUniformBlockBindingproc = (PFNGLUNIFORMBLOCKBINDINGPROC)wglGetProcAddress("glUniformBlockBinding");
	GLM_struct->glDrawElementsBaseVertexproc = (PFNGLDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawElementsBaseVertex");
	GLM_struct->glDrawRangeElementsBaseVertexproc = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawRangeElementsBaseVertex");
	GLM_struct->glDrawElementsInstancedBaseVertexproc = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertex");
	GLM_struct->glMultiDrawElementsBaseVertexproc = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glMultiDrawElementsBaseVertex");
	GLM_struct->glProvokingVertexproc = (PFNGLPROVOKINGVERTEXPROC)wglGetProcAddress("glProvokingVertex");
	GLM_struct->glFenceSyncproc = (PFNGLFENCESYNCPROC)wglGetProcAddress("glFenceSync");
	GLM_struct->glIsSyncproc = (PFNGLISSYNCPROC)wglGetProcAddress("glIsSync");
	GLM_struct->glDeleteSyncproc = (PFNGLDELETESYNCPROC)wglGetProcAddress("glDeleteSync");
	GLM_struct->glClientWaitSyncproc = (PFNGLCLIENTWAITSYNCPROC)wglGetProcAddress("glClientWaitSync");
	GLM_struct->glWaitSyncproc = (PFNGLWAITSYNCPROC)wglGetProcAddress("glWaitSync");
	GLM_struct->glGetInteger64vproc = (PFNGLGETINTEGER64VPROC)wglGetProcAddress("glGetInteger64v");
	GLM_struct->glGetSyncivproc = (PFNGLGETSYNCIVPROC)wglGetProcAddress("glGetSynciv");
	GLM_struct->glGetInteger64i_vproc = (PFNGLGETINTEGER64I_VPROC)wglGetProcAddress("glGetInteger64i_v");
	GLM_struct->glGetBufferParameteri64vproc = (PFNGLGETBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetBufferParameteri64v");
	GLM_struct->glFramebufferTextureproc = (PFNGLFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glFramebufferTexture");
	GLM_struct->glTexImage2DMultisampleproc = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexImage2DMultisample");
	GLM_struct->glTexImage3DMultisampleproc = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexImage3DMultisample");
	GLM_struct->glGetMultisamplefvproc = (PFNGLGETMULTISAMPLEFVPROC)wglGetProcAddress("glGetMultisamplefv");
	GLM_struct->glSampleMaskiproc = (PFNGLSAMPLEMASKIPROC)wglGetProcAddress("glSampleMaski");
	GLM_struct->glBindFragDataLocationIndexedproc = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)wglGetProcAddress("glBindFragDataLocationIndexed");
	GLM_struct->glGetFragDataIndexproc = (PFNGLGETFRAGDATAINDEXPROC)wglGetProcAddress("glGetFragDataIndex");
	GLM_struct->glGenSamplersproc = (PFNGLGENSAMPLERSPROC)wglGetProcAddress("glGenSamplers");
	GLM_struct->glDeleteSamplersproc = (PFNGLDELETESAMPLERSPROC)wglGetProcAddress("glDeleteSamplers");
	GLM_struct->glIsSamplerproc = (PFNGLISSAMPLERPROC)wglGetProcAddress("glIsSampler");
	GLM_struct->glBindSamplerproc = (PFNGLBINDSAMPLERPROC)wglGetProcAddress("glBindSampler");
	GLM_struct->glSamplerParameteriproc = (PFNGLSAMPLERPARAMETERIPROC)wglGetProcAddress("glSamplerParameteri");
	GLM_struct->glSamplerParameterivproc = (PFNGLSAMPLERPARAMETERIVPROC)wglGetProcAddress("glSamplerParameteriv");
	GLM_struct->glSamplerParameterfproc = (PFNGLSAMPLERPARAMETERFPROC)wglGetProcAddress("glSamplerParameterf");
	GLM_struct->glSamplerParameterfvproc = (PFNGLSAMPLERPARAMETERFVPROC)wglGetProcAddress("glSamplerParameterfv");
	GLM_struct->glSamplerParameterIivproc = (PFNGLSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glSamplerParameterIiv");
	GLM_struct->glSamplerParameterIuivproc = (PFNGLSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glSamplerParameterIuiv");
	GLM_struct->glGetSamplerParameterivproc = (PFNGLGETSAMPLERPARAMETERIVPROC)wglGetProcAddress("glGetSamplerParameteriv");
	GLM_struct->glGetSamplerParameterIivproc = (PFNGLGETSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glGetSamplerParameterIiv");
	GLM_struct->glGetSamplerParameterfvproc = (PFNGLGETSAMPLERPARAMETERFVPROC)wglGetProcAddress("glGetSamplerParameterfv");
	GLM_struct->glGetSamplerParameterIuivproc = (PFNGLGETSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glGetSamplerParameterIuiv");
	GLM_struct->glQueryCounterproc = (PFNGLQUERYCOUNTERPROC)wglGetProcAddress("glQueryCounter");
	GLM_struct->glGetQueryObjecti64vproc = (PFNGLGETQUERYOBJECTI64VPROC)wglGetProcAddress("glGetQueryObjecti64v");
	GLM_struct->glGetQueryObjectui64vproc = (PFNGLGETQUERYOBJECTUI64VPROC)wglGetProcAddress("glGetQueryObjectui64v");
	GLM_struct->glVertexAttribDivisorproc = (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
	GLM_struct->glVertexAttribP1uiproc = (PFNGLVERTEXATTRIBP1UIPROC)wglGetProcAddress("glVertexAttribP1ui");
	GLM_struct->glVertexAttribP1uivproc = (PFNGLVERTEXATTRIBP1UIVPROC)wglGetProcAddress("glVertexAttribP1uiv");
	GLM_struct->glVertexAttribP2uiproc = (PFNGLVERTEXATTRIBP2UIPROC)wglGetProcAddress("glVertexAttribP2ui");
	GLM_struct->glVertexAttribP2uivproc = (PFNGLVERTEXATTRIBP2UIVPROC)wglGetProcAddress("glVertexAttribP2uiv");
	GLM_struct->glVertexAttribP3uiproc = (PFNGLVERTEXATTRIBP3UIPROC)wglGetProcAddress("glVertexAttribP3ui");
	GLM_struct->glVertexAttribP3uivproc = (PFNGLVERTEXATTRIBP3UIVPROC)wglGetProcAddress("glVertexAttribP3uiv");
	GLM_struct->glVertexAttribP4uiproc = (PFNGLVERTEXATTRIBP4UIPROC)wglGetProcAddress("glVertexAttribP4ui");
	GLM_struct->glVertexAttribP4uivproc = (PFNGLVERTEXATTRIBP4UIVPROC)wglGetProcAddress("glVertexAttribP4uiv");
	GLM_struct->glVertexP2uiproc = (PFNGLVERTEXP2UIPROC)wglGetProcAddress("glVertexP2ui");
	GLM_struct->glVertexP2uivproc = (PFNGLVERTEXP2UIVPROC)wglGetProcAddress("glVertexP2uiv");
	GLM_struct->glVertexP3uiproc = (PFNGLVERTEXP3UIPROC)wglGetProcAddress("glVertexP3ui");
	GLM_struct->glVertexP3uivproc = (PFNGLVERTEXP3UIVPROC)wglGetProcAddress("glVertexP3uiv");
	GLM_struct->glVertexP4uiproc = (PFNGLVERTEXP4UIPROC)wglGetProcAddress("glVertexP4ui");
	GLM_struct->glVertexP4uivproc = (PFNGLVERTEXP4UIVPROC)wglGetProcAddress("glVertexP4uiv");
	GLM_struct->glTexCoordP1uiproc = (PFNGLTEXCOORDP1UIPROC)wglGetProcAddress("glTexCoordP1ui");
	GLM_struct->glTexCoordP1uivproc = (PFNGLTEXCOORDP1UIVPROC)wglGetProcAddress("glTexCoordP1uiv");
	GLM_struct->glTexCoordP2uiproc = (PFNGLTEXCOORDP2UIPROC)wglGetProcAddress("glTexCoordP2ui");
	GLM_struct->glTexCoordP2uivproc = (PFNGLTEXCOORDP2UIVPROC)wglGetProcAddress("glTexCoordP2uiv");
	GLM_struct->glTexCoordP3uiproc = (PFNGLTEXCOORDP3UIPROC)wglGetProcAddress("glTexCoordP3ui");
	GLM_struct->glTexCoordP3uivproc = (PFNGLTEXCOORDP3UIVPROC)wglGetProcAddress("glTexCoordP3uiv");
	GLM_struct->glTexCoordP4uiproc = (PFNGLTEXCOORDP4UIPROC)wglGetProcAddress("glTexCoordP4ui");
	GLM_struct->glTexCoordP4uivproc = (PFNGLTEXCOORDP4UIVPROC)wglGetProcAddress("glTexCoordP4uiv");
	GLM_struct->glMultiTexCoordP1uiproc = (PFNGLMULTITEXCOORDP1UIPROC)wglGetProcAddress("glMultiTexCoordP1ui");
	GLM_struct->glMultiTexCoordP1uivproc = (PFNGLMULTITEXCOORDP1UIVPROC)wglGetProcAddress("glMultiTexCoordP1uiv");
	GLM_struct->glMultiTexCoordP2uiproc = (PFNGLMULTITEXCOORDP2UIPROC)wglGetProcAddress("glMultiTexCoordP2ui");
	GLM_struct->glMultiTexCoordP2uivproc = (PFNGLMULTITEXCOORDP2UIVPROC)wglGetProcAddress("glMultiTexCoordP2uiv");
	GLM_struct->glMultiTexCoordP3uiproc = (PFNGLMULTITEXCOORDP3UIPROC)wglGetProcAddress("glMultiTexCoordP3ui");
	GLM_struct->glMultiTexCoordP3uivproc = (PFNGLMULTITEXCOORDP3UIVPROC)wglGetProcAddress("glMultiTexCoordP3uiv");
	GLM_struct->glMultiTexCoordP4uiproc = (PFNGLMULTITEXCOORDP4UIPROC)wglGetProcAddress("glMultiTexCoordP4ui");
	GLM_struct->glMultiTexCoordP4uivproc = (PFNGLMULTITEXCOORDP4UIVPROC)wglGetProcAddress("glMultiTexCoordP4uiv");
	GLM_struct->glNormalP3uiproc = (PFNGLNORMALP3UIPROC)wglGetProcAddress("glNormalP3ui");
	GLM_struct->glNormalP3uivproc = (PFNGLNORMALP3UIVPROC)wglGetProcAddress("glNormalP3uiv");
	GLM_struct->glColorP3uiproc = (PFNGLCOLORP3UIPROC)wglGetProcAddress("glColorP3ui");
	GLM_struct->glColorP3uivproc = (PFNGLCOLORP3UIVPROC)wglGetProcAddress("glColorP3uiv");
	GLM_struct->glColorP4uiproc = (PFNGLCOLORP4UIPROC)wglGetProcAddress("glColorP4ui");
	GLM_struct->glColorP4uivproc = (PFNGLCOLORP4UIVPROC)wglGetProcAddress("glColorP4uiv");
	GLM_struct->glSecondaryColorP3uiproc = (PFNGLSECONDARYCOLORP3UIPROC)wglGetProcAddress("glSecondaryColorP3ui");
	GLM_struct->glSecondaryColorP3uivproc = (PFNGLSECONDARYCOLORP3UIVPROC)wglGetProcAddress("glSecondaryColorP3uiv");
	GLM_struct->glMinSampleShadingproc = (PFNGLMINSAMPLESHADINGPROC)wglGetProcAddress("glMinSampleShading");
	GLM_struct->glBlendEquationiproc = (PFNGLBLENDEQUATIONIPROC)wglGetProcAddress("glBlendEquationi");
	GLM_struct->glBlendEquationSeparateiproc = (PFNGLBLENDEQUATIONSEPARATEIPROC)wglGetProcAddress("glBlendEquationSeparatei");
	GLM_struct->glBlendFunciproc = (PFNGLBLENDFUNCIPROC)wglGetProcAddress("glBlendFunci");
	GLM_struct->glBlendFuncSeparateiproc = (PFNGLBLENDFUNCSEPARATEIPROC)wglGetProcAddress("glBlendFuncSeparatei");
	GLM_struct->glDrawArraysIndirectproc = (PFNGLDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glDrawArraysIndirect");
	GLM_struct->glDrawElementsIndirectproc = (PFNGLDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glDrawElementsIndirect");
	GLM_struct->glUniform1dproc = (PFNGLUNIFORM1DPROC)wglGetProcAddress("glUniform1d");
	GLM_struct->glUniform2dproc = (PFNGLUNIFORM2DPROC)wglGetProcAddress("glUniform2d");
	GLM_struct->glUniform3dproc = (PFNGLUNIFORM3DPROC)wglGetProcAddress("glUniform3d");
	GLM_struct->glUniform4dproc = (PFNGLUNIFORM4DPROC)wglGetProcAddress("glUniform4d");
	GLM_struct->glUniform1dvproc = (PFNGLUNIFORM1DVPROC)wglGetProcAddress("glUniform1dv");
	GLM_struct->glUniform2dvproc = (PFNGLUNIFORM2DVPROC)wglGetProcAddress("glUniform2dv");
	GLM_struct->glUniform3dvproc = (PFNGLUNIFORM3DVPROC)wglGetProcAddress("glUniform3dv");
	GLM_struct->glUniform4dvproc = (PFNGLUNIFORM4DVPROC)wglGetProcAddress("glUniform4dv");
	GLM_struct->glUniformMatrix2dvproc = (PFNGLUNIFORMMATRIX2DVPROC)wglGetProcAddress("glUniformMatrix2dv");
	GLM_struct->glUniformMatrix3dvproc = (PFNGLUNIFORMMATRIX3DVPROC)wglGetProcAddress("glUniformMatrix3dv");
	GLM_struct->glUniformMatrix4dvproc = (PFNGLUNIFORMMATRIX4DVPROC)wglGetProcAddress("glUniformMatrix4dv");
	GLM_struct->glUniformMatrix2x3dvproc = (PFNGLUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glUniformMatrix2x3dv");
	GLM_struct->glUniformMatrix2x4dvproc = (PFNGLUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glUniformMatrix2x4dv");
	GLM_struct->glUniformMatrix3x2dvproc = (PFNGLUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glUniformMatrix3x2dv");
	GLM_struct->glUniformMatrix3x4dvproc = (PFNGLUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glUniformMatrix3x4dv");
	GLM_struct->glUniformMatrix4x2dvproc = (PFNGLUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glUniformMatrix4x2dv");
	GLM_struct->glUniformMatrix4x3dvproc = (PFNGLUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glUniformMatrix4x3dv");
	GLM_struct->glGetUniformdvproc = (PFNGLGETUNIFORMDVPROC)wglGetProcAddress("glGetUniformdv");
	GLM_struct->glGetSubroutineUniformLocationproc = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)wglGetProcAddress("glGetSubroutineUniformLocation");
	GLM_struct->glGetSubroutineIndexproc = (PFNGLGETSUBROUTINEINDEXPROC)wglGetProcAddress("glGetSubroutineIndex");
	GLM_struct->glGetActiveSubroutineUniformivproc = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)wglGetProcAddress("glGetActiveSubroutineUniformiv");
	GLM_struct->glGetActiveSubroutineUniformNameproc = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveSubroutineUniformName");
	GLM_struct->glGetActiveSubroutineNameproc = (PFNGLGETACTIVESUBROUTINENAMEPROC)wglGetProcAddress("glGetActiveSubroutineName");
	GLM_struct->glUniformSubroutinesuivproc = (PFNGLUNIFORMSUBROUTINESUIVPROC)wglGetProcAddress("glUniformSubroutinesuiv");
	GLM_struct->glGetUniformSubroutineuivproc = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)wglGetProcAddress("glGetUniformSubroutineuiv");
	GLM_struct->glGetProgramStageivproc = (PFNGLGETPROGRAMSTAGEIVPROC)wglGetProcAddress("glGetProgramStageiv");
	GLM_struct->glPatchParameteriproc = (PFNGLPATCHPARAMETERIPROC)wglGetProcAddress("glPatchParameteri");
	GLM_struct->glPatchParameterfvproc = (PFNGLPATCHPARAMETERFVPROC)wglGetProcAddress("glPatchParameterfv");
	GLM_struct->glBindTransformFeedbackproc = (PFNGLBINDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBindTransformFeedback");
	GLM_struct->glDeleteTransformFeedbacksproc = (PFNGLDELETETRANSFORMFEEDBACKSPROC)wglGetProcAddress("glDeleteTransformFeedbacks");
	GLM_struct->glGenTransformFeedbacksproc = (PFNGLGENTRANSFORMFEEDBACKSPROC)wglGetProcAddress("glGenTransformFeedbacks");
	GLM_struct->glIsTransformFeedbackproc = (PFNGLISTRANSFORMFEEDBACKPROC)wglGetProcAddress("glIsTransformFeedback");
	GLM_struct->glPauseTransformFeedbackproc = (PFNGLPAUSETRANSFORMFEEDBACKPROC)wglGetProcAddress("glPauseTransformFeedback");
	GLM_struct->glResumeTransformFeedbackproc = (PFNGLRESUMETRANSFORMFEEDBACKPROC)wglGetProcAddress("glResumeTransformFeedback");
	GLM_struct->glDrawTransformFeedbackproc = (PFNGLDRAWTRANSFORMFEEDBACKPROC)wglGetProcAddress("glDrawTransformFeedback");
	GLM_struct->glDrawTransformFeedbackStreamproc = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)wglGetProcAddress("glDrawTransformFeedbackStream");
	GLM_struct->glBeginQueryIndexedproc = (PFNGLBEGINQUERYINDEXEDPROC)wglGetProcAddress("glBeginQueryIndexed");
	GLM_struct->glEndQueryIndexedproc = (PFNGLENDQUERYINDEXEDPROC)wglGetProcAddress("glEndQueryIndexed");
	GLM_struct->glGetQueryIndexedivproc = (PFNGLGETQUERYINDEXEDIVPROC)wglGetProcAddress("glGetQueryIndexediv");
	GLM_struct->glReleaseShaderCompilerproc = (PFNGLRELEASESHADERCOMPILERPROC)wglGetProcAddress("glReleaseShaderCompiler");
	GLM_struct->glShaderBinaryproc = (PFNGLSHADERBINARYPROC)wglGetProcAddress("glShaderBinary");
	GLM_struct->glGetShaderPrecisionFormatproc = (PFNGLGETSHADERPRECISIONFORMATPROC)wglGetProcAddress("glGetShaderPrecisionFormat");
	GLM_struct->glDepthRangefproc = (PFNGLDEPTHRANGEFPROC)wglGetProcAddress("glDepthRangef");
	GLM_struct->glClearDepthfproc = (PFNGLCLEARDEPTHFPROC)wglGetProcAddress("glClearDepthf");
	GLM_struct->glGetProgramBinaryproc = (PFNGLGETPROGRAMBINARYPROC)wglGetProcAddress("glGetProgramBinary");
	GLM_struct->glProgramBinaryproc = (PFNGLPROGRAMBINARYPROC)wglGetProcAddress("glProgramBinary");
	GLM_struct->glProgramParameteriproc = (PFNGLPROGRAMPARAMETERIPROC)wglGetProcAddress("glProgramParameteri");
	GLM_struct->glUseProgramStagesproc = (PFNGLUSEPROGRAMSTAGESPROC)wglGetProcAddress("glUseProgramStages");
	GLM_struct->glActiveShaderProgramproc = (PFNGLACTIVESHADERPROGRAMPROC)wglGetProcAddress("glActiveShaderProgram");
	GLM_struct->glCreateShaderProgramvproc = (PFNGLCREATESHADERPROGRAMVPROC)wglGetProcAddress("glCreateShaderProgramv");
	GLM_struct->glBindProgramPipelineproc = (PFNGLBINDPROGRAMPIPELINEPROC)wglGetProcAddress("glBindProgramPipeline");
	GLM_struct->glDeleteProgramPipelinesproc = (PFNGLDELETEPROGRAMPIPELINESPROC)wglGetProcAddress("glDeleteProgramPipelines");
	GLM_struct->glGenProgramPipelinesproc = (PFNGLGENPROGRAMPIPELINESPROC)wglGetProcAddress("glGenProgramPipelines");
	GLM_struct->glIsProgramPipelineproc = (PFNGLISPROGRAMPIPELINEPROC)wglGetProcAddress("glIsProgramPipeline");
	GLM_struct->glGetProgramPipelineivproc = (PFNGLGETPROGRAMPIPELINEIVPROC)wglGetProcAddress("glGetProgramPipelineiv");
	GLM_struct->glProgramUniform1iproc = (PFNGLPROGRAMUNIFORM1IPROC)wglGetProcAddress("glProgramUniform1i");
	GLM_struct->glProgramUniform1ivproc = (PFNGLPROGRAMUNIFORM1IVPROC)wglGetProcAddress("glProgramUniform1iv");
	GLM_struct->glProgramUniform1fproc = (PFNGLPROGRAMUNIFORM1FPROC)wglGetProcAddress("glProgramUniform1f");
	GLM_struct->glProgramUniform1fvproc = (PFNGLPROGRAMUNIFORM1FVPROC)wglGetProcAddress("glProgramUniform1fv");
	GLM_struct->glProgramUniform1dproc = (PFNGLPROGRAMUNIFORM1DPROC)wglGetProcAddress("glProgramUniform1d");
	GLM_struct->glProgramUniform1dvproc = (PFNGLPROGRAMUNIFORM1DVPROC)wglGetProcAddress("glProgramUniform1dv");
	GLM_struct->glProgramUniform1uiproc = (PFNGLPROGRAMUNIFORM1UIPROC)wglGetProcAddress("glProgramUniform1ui");
	GLM_struct->glProgramUniform1uivproc = (PFNGLPROGRAMUNIFORM1UIVPROC)wglGetProcAddress("glProgramUniform1uiv");
	GLM_struct->glProgramUniform2iproc = (PFNGLPROGRAMUNIFORM2IPROC)wglGetProcAddress("glProgramUniform2i");
	GLM_struct->glProgramUniform2ivproc = (PFNGLPROGRAMUNIFORM2IVPROC)wglGetProcAddress("glProgramUniform2iv");
	GLM_struct->glProgramUniform2fproc = (PFNGLPROGRAMUNIFORM2FPROC)wglGetProcAddress("glProgramUniform2f");
	GLM_struct->glProgramUniform2fvproc = (PFNGLPROGRAMUNIFORM2FVPROC)wglGetProcAddress("glProgramUniform2fv");
	GLM_struct->glProgramUniform2dproc = (PFNGLPROGRAMUNIFORM2DPROC)wglGetProcAddress("glProgramUniform2d");
	GLM_struct->glProgramUniform2dvproc = (PFNGLPROGRAMUNIFORM2DVPROC)wglGetProcAddress("glProgramUniform2dv");
	GLM_struct->glProgramUniform2uiproc = (PFNGLPROGRAMUNIFORM2UIPROC)wglGetProcAddress("glProgramUniform2ui");
	GLM_struct->glProgramUniform2uivproc = (PFNGLPROGRAMUNIFORM2UIVPROC)wglGetProcAddress("glProgramUniform2uiv");
	GLM_struct->glProgramUniform3iproc = (PFNGLPROGRAMUNIFORM3IPROC)wglGetProcAddress("glProgramUniform3i");
	GLM_struct->glProgramUniform3ivproc = (PFNGLPROGRAMUNIFORM3IVPROC)wglGetProcAddress("glProgramUniform3iv");
	GLM_struct->glProgramUniform3fproc = (PFNGLPROGRAMUNIFORM3FPROC)wglGetProcAddress("glProgramUniform3f");
	GLM_struct->glProgramUniform3fvproc = (PFNGLPROGRAMUNIFORM3FVPROC)wglGetProcAddress("glProgramUniform3fv");
	GLM_struct->glProgramUniform3dproc = (PFNGLPROGRAMUNIFORM3DPROC)wglGetProcAddress("glProgramUniform3d");
	GLM_struct->glProgramUniform3dvproc = (PFNGLPROGRAMUNIFORM3DVPROC)wglGetProcAddress("glProgramUniform3dv");
	GLM_struct->glProgramUniform3uiproc = (PFNGLPROGRAMUNIFORM3UIPROC)wglGetProcAddress("glProgramUniform3ui");
	GLM_struct->glProgramUniform3uivproc = (PFNGLPROGRAMUNIFORM3UIVPROC)wglGetProcAddress("glProgramUniform3uiv");
	GLM_struct->glProgramUniform4iproc = (PFNGLPROGRAMUNIFORM4IPROC)wglGetProcAddress("glProgramUniform4i");
	GLM_struct->glProgramUniform4ivproc = (PFNGLPROGRAMUNIFORM4IVPROC)wglGetProcAddress("glProgramUniform4iv");
	GLM_struct->glProgramUniform4fproc = (PFNGLPROGRAMUNIFORM4FPROC)wglGetProcAddress("glProgramUniform4f");
	GLM_struct->glProgramUniform4fvproc = (PFNGLPROGRAMUNIFORM4FVPROC)wglGetProcAddress("glProgramUniform4fv");
	GLM_struct->glProgramUniform4dproc = (PFNGLPROGRAMUNIFORM4DPROC)wglGetProcAddress("glProgramUniform4d");
	GLM_struct->glProgramUniform4dvproc = (PFNGLPROGRAMUNIFORM4DVPROC)wglGetProcAddress("glProgramUniform4dv");
	GLM_struct->glProgramUniform4uiproc = (PFNGLPROGRAMUNIFORM4UIPROC)wglGetProcAddress("glProgramUniform4ui");
	GLM_struct->glProgramUniform4uivproc = (PFNGLPROGRAMUNIFORM4UIVPROC)wglGetProcAddress("glProgramUniform4uiv");
	GLM_struct->glProgramUniformMatrix2fvproc = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)wglGetProcAddress("glProgramUniformMatrix2fv");
	GLM_struct->glProgramUniformMatrix3fvproc = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)wglGetProcAddress("glProgramUniformMatrix3fv");
	GLM_struct->glProgramUniformMatrix4fvproc = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)wglGetProcAddress("glProgramUniformMatrix4fv");
	GLM_struct->glProgramUniformMatrix2dvproc = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)wglGetProcAddress("glProgramUniformMatrix2dv");
	GLM_struct->glProgramUniformMatrix3dvproc = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)wglGetProcAddress("glProgramUniformMatrix3dv");
	GLM_struct->glProgramUniformMatrix4dvproc = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)wglGetProcAddress("glProgramUniformMatrix4dv");
	GLM_struct->glProgramUniformMatrix2x3fvproc = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)wglGetProcAddress("glProgramUniformMatrix2x3fv");
	GLM_struct->glProgramUniformMatrix3x2fvproc = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)wglGetProcAddress("glProgramUniformMatrix3x2fv");
	GLM_struct->glProgramUniformMatrix2x4fvproc = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)wglGetProcAddress("glProgramUniformMatrix2x4fv");
	GLM_struct->glProgramUniformMatrix4x2fvproc = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)wglGetProcAddress("glProgramUniformMatrix4x2fv");
	GLM_struct->glProgramUniformMatrix3x4fvproc = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)wglGetProcAddress("glProgramUniformMatrix3x4fv");
	GLM_struct->glProgramUniformMatrix4x3fvproc = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)wglGetProcAddress("glProgramUniformMatrix4x3fv");
	GLM_struct->glProgramUniformMatrix2x3dvproc = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glProgramUniformMatrix2x3dv");
	GLM_struct->glProgramUniformMatrix3x2dvproc = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glProgramUniformMatrix3x2dv");
	GLM_struct->glProgramUniformMatrix2x4dvproc = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glProgramUniformMatrix2x4dv");
	GLM_struct->glProgramUniformMatrix4x2dvproc = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glProgramUniformMatrix4x2dv");
	GLM_struct->glProgramUniformMatrix3x4dvproc = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glProgramUniformMatrix3x4dv");
	GLM_struct->glProgramUniformMatrix4x3dvproc = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glProgramUniformMatrix4x3dv");
	GLM_struct->glValidateProgramPipelineproc = (PFNGLVALIDATEPROGRAMPIPELINEPROC)wglGetProcAddress("glValidateProgramPipeline");
	GLM_struct->glGetProgramPipelineInfoLogproc = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)wglGetProcAddress("glGetProgramPipelineInfoLog");
	GLM_struct->glVertexAttribL1dproc = (PFNGLVERTEXATTRIBL1DPROC)wglGetProcAddress("glVertexAttribL1d");
	GLM_struct->glVertexAttribL2dproc = (PFNGLVERTEXATTRIBL2DPROC)wglGetProcAddress("glVertexAttribL2d");
	GLM_struct->glVertexAttribL3dproc = (PFNGLVERTEXATTRIBL3DPROC)wglGetProcAddress("glVertexAttribL3d");
	GLM_struct->glVertexAttribL4dproc = (PFNGLVERTEXATTRIBL4DPROC)wglGetProcAddress("glVertexAttribL4d");
	GLM_struct->glVertexAttribL1dvproc = (PFNGLVERTEXATTRIBL1DVPROC)wglGetProcAddress("glVertexAttribL1dv");
	GLM_struct->glVertexAttribL2dvproc = (PFNGLVERTEXATTRIBL2DVPROC)wglGetProcAddress("glVertexAttribL2dv");
	GLM_struct->glVertexAttribL3dvproc = (PFNGLVERTEXATTRIBL3DVPROC)wglGetProcAddress("glVertexAttribL3dv");
	GLM_struct->glVertexAttribL4dvproc = (PFNGLVERTEXATTRIBL4DVPROC)wglGetProcAddress("glVertexAttribL4dv");
	GLM_struct->glVertexAttribLPointerproc = (PFNGLVERTEXATTRIBLPOINTERPROC)wglGetProcAddress("glVertexAttribLPointer");
	GLM_struct->glGetVertexAttribLdvproc = (PFNGLGETVERTEXATTRIBLDVPROC)wglGetProcAddress("glGetVertexAttribLdv");
	GLM_struct->glViewportArrayvproc = (PFNGLVIEWPORTARRAYVPROC)wglGetProcAddress("glViewportArrayv");
	GLM_struct->glViewportIndexedfproc = (PFNGLVIEWPORTINDEXEDFPROC)wglGetProcAddress("glViewportIndexedf");
	GLM_struct->glViewportIndexedfvproc = (PFNGLVIEWPORTINDEXEDFVPROC)wglGetProcAddress("glViewportIndexedfv");
	GLM_struct->glScissorArrayvproc = (PFNGLSCISSORARRAYVPROC)wglGetProcAddress("glScissorArrayv");
	GLM_struct->glScissorIndexedproc = (PFNGLSCISSORINDEXEDPROC)wglGetProcAddress("glScissorIndexed");
	GLM_struct->glScissorIndexedvproc = (PFNGLSCISSORINDEXEDVPROC)wglGetProcAddress("glScissorIndexedv");
	GLM_struct->glDepthRangeArrayvproc = (PFNGLDEPTHRANGEARRAYVPROC)wglGetProcAddress("glDepthRangeArrayv");
	GLM_struct->glDepthRangeIndexedproc = (PFNGLDEPTHRANGEINDEXEDPROC)wglGetProcAddress("glDepthRangeIndexed");
	GLM_struct->glGetFloati_vproc = (PFNGLGETFLOATI_VPROC)wglGetProcAddress("glGetFloati_v");
	GLM_struct->glGetDoublei_vproc = (PFNGLGETDOUBLEI_VPROC)wglGetProcAddress("glGetDoublei_v");
	GLM_struct->glDrawArraysInstancedBaseInstanceproc = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawArraysInstancedBaseInstance");
	GLM_struct->glDrawElementsInstancedBaseInstanceproc = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseInstance");
	GLM_struct->glDrawElementsInstancedBaseVertexBaseInstanceproc = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	GLM_struct->glGetInternalformativproc = (PFNGLGETINTERNALFORMATIVPROC)wglGetProcAddress("glGetInternalformativ");
	GLM_struct->glGetActiveAtomicCounterBufferivproc = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)wglGetProcAddress("glGetActiveAtomicCounterBufferiv");
	GLM_struct->glBindImageTextureproc = (PFNGLBINDIMAGETEXTUREPROC)wglGetProcAddress("glBindImageTexture");
	GLM_struct->glMemoryBarrierproc = (PFNGLMEMORYBARRIERPROC)wglGetProcAddress("glMemoryBarrier");
	GLM_struct->glTexStorage1Dproc = (PFNGLTEXSTORAGE1DPROC)wglGetProcAddress("glTexStorage1D");
	GLM_struct->glTexStorage2Dproc = (PFNGLTEXSTORAGE2DPROC)wglGetProcAddress("glTexStorage2D");
	GLM_struct->glTexStorage3Dproc = (PFNGLTEXSTORAGE3DPROC)wglGetProcAddress("glTexStorage3D");
	GLM_struct->glDrawTransformFeedbackInstancedproc = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackInstanced");
	GLM_struct->glDrawTransformFeedbackStreamInstancedproc = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	GLM_struct->glClearBufferDataproc = (PFNGLCLEARBUFFERDATAPROC)wglGetProcAddress("glClearBufferData");
	GLM_struct->glClearBufferSubDataproc = (PFNGLCLEARBUFFERSUBDATAPROC)wglGetProcAddress("glClearBufferSubData");
	GLM_struct->glDispatchComputeproc = (PFNGLDISPATCHCOMPUTEPROC)wglGetProcAddress("glDispatchCompute");
	GLM_struct->glDispatchComputeIndirectproc = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)wglGetProcAddress("glDispatchComputeIndirect");
	GLM_struct->glCopyImageSubDataproc = (PFNGLCOPYIMAGESUBDATAPROC)wglGetProcAddress("glCopyImageSubData");
	GLM_struct->glFramebufferParameteriproc = (PFNGLFRAMEBUFFERPARAMETERIPROC)wglGetProcAddress("glFramebufferParameteri");
	GLM_struct->glGetFramebufferParameterivproc = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferParameteriv");
	GLM_struct->glGetInternalformati64vproc = (PFNGLGETINTERNALFORMATI64VPROC)wglGetProcAddress("glGetInternalformati64v");
	GLM_struct->glInvalidateTexSubImageproc = (PFNGLINVALIDATETEXSUBIMAGEPROC)wglGetProcAddress("glInvalidateTexSubImage");
	GLM_struct->glInvalidateTexImageproc = (PFNGLINVALIDATETEXIMAGEPROC)wglGetProcAddress("glInvalidateTexImage");
	GLM_struct->glInvalidateBufferSubDataproc = (PFNGLINVALIDATEBUFFERSUBDATAPROC)wglGetProcAddress("glInvalidateBufferSubData");
	GLM_struct->glInvalidateBufferDataproc = (PFNGLINVALIDATEBUFFERDATAPROC)wglGetProcAddress("glInvalidateBufferData");
	GLM_struct->glInvalidateFramebufferproc = (PFNGLINVALIDATEFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateFramebuffer");
	GLM_struct->glInvalidateSubFramebufferproc = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateSubFramebuffer");
	GLM_struct->glMultiDrawArraysIndirectproc = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glMultiDrawArraysIndirect");
	GLM_struct->glMultiDrawElementsIndirectproc = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glMultiDrawElementsIndirect");
	GLM_struct->glGetProgramInterfaceivproc = (PFNGLGETPROGRAMINTERFACEIVPROC)wglGetProcAddress("glGetProgramInterfaceiv");
	GLM_struct->glGetProgramResourceIndexproc = (PFNGLGETPROGRAMRESOURCEINDEXPROC)wglGetProcAddress("glGetProgramResourceIndex");
	GLM_struct->glGetProgramResourceNameproc = (PFNGLGETPROGRAMRESOURCENAMEPROC)wglGetProcAddress("glGetProgramResourceName");
	GLM_struct->glGetProgramResourceivproc = (PFNGLGETPROGRAMRESOURCEIVPROC)wglGetProcAddress("glGetProgramResourceiv");
	GLM_struct->glGetProgramResourceLocationproc = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)wglGetProcAddress("glGetProgramResourceLocation");
	GLM_struct->glGetProgramResourceLocationIndexproc = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)wglGetProcAddress("glGetProgramResourceLocationIndex");
	GLM_struct->glShaderStorageBlockBindingproc = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)wglGetProcAddress("glShaderStorageBlockBinding");
	GLM_struct->glTexBufferRangeproc = (PFNGLTEXBUFFERRANGEPROC)wglGetProcAddress("glTexBufferRange");
	GLM_struct->glTexStorage2DMultisampleproc = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage2DMultisample");
	GLM_struct->glTexStorage3DMultisampleproc = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage3DMultisample");
	GLM_struct->glTextureViewproc = (PFNGLTEXTUREVIEWPROC)wglGetProcAddress("glTextureView");
	GLM_struct->glBindVertexBufferproc = (PFNGLBINDVERTEXBUFFERPROC)wglGetProcAddress("glBindVertexBuffer");
	GLM_struct->glVertexAttribFormatproc = (PFNGLVERTEXATTRIBFORMATPROC)wglGetProcAddress("glVertexAttribFormat");
	GLM_struct->glVertexAttribIFormatproc = (PFNGLVERTEXATTRIBIFORMATPROC)wglGetProcAddress("glVertexAttribIFormat");
	GLM_struct->glVertexAttribLFormatproc = (PFNGLVERTEXATTRIBLFORMATPROC)wglGetProcAddress("glVertexAttribLFormat");
	GLM_struct->glVertexAttribBindingproc = (PFNGLVERTEXATTRIBBINDINGPROC)wglGetProcAddress("glVertexAttribBinding");
	GLM_struct->glVertexBindingDivisorproc = (PFNGLVERTEXBINDINGDIVISORPROC)wglGetProcAddress("glVertexBindingDivisor");
	GLM_struct->glDebugMessageControlproc = (PFNGLDEBUGMESSAGECONTROLPROC)wglGetProcAddress("glDebugMessageControl");
	GLM_struct->glDebugMessageInsertproc = (PFNGLDEBUGMESSAGEINSERTPROC)wglGetProcAddress("glDebugMessageInsert");
	GLM_struct->glDebugMessageCallbackproc = (PFNGLDEBUGMESSAGECALLBACKPROC)wglGetProcAddress("glDebugMessageCallback");
	GLM_struct->glGetDebugMessageLogproc = (PFNGLGETDEBUGMESSAGELOGPROC)wglGetProcAddress("glGetDebugMessageLog");
	GLM_struct->glPushDebugGroupproc = (PFNGLPUSHDEBUGGROUPPROC)wglGetProcAddress("glPushDebugGroup");
	GLM_struct->glPopDebugGroupproc = (PFNGLPOPDEBUGGROUPPROC)wglGetProcAddress("glPopDebugGroup");
	GLM_struct->glObjectLabelproc = (PFNGLOBJECTLABELPROC)wglGetProcAddress("glObjectLabel");
	GLM_struct->glGetObjectLabelproc = (PFNGLGETOBJECTLABELPROC)wglGetProcAddress("glGetObjectLabel");
	GLM_struct->glObjectPtrLabelproc = (PFNGLOBJECTPTRLABELPROC)wglGetProcAddress("glObjectPtrLabel");
	GLM_struct->glGetObjectPtrLabelproc = (PFNGLGETOBJECTPTRLABELPROC)wglGetProcAddress("glGetObjectPtrLabel");
	GLM_struct->glBufferStorageproc = (PFNGLBUFFERSTORAGEPROC)wglGetProcAddress("glBufferStorage");
	GLM_struct->glClearTexImageproc = (PFNGLCLEARTEXIMAGEPROC)wglGetProcAddress("glClearTexImage");
	GLM_struct->glClearTexSubImageproc = (PFNGLCLEARTEXSUBIMAGEPROC)wglGetProcAddress("glClearTexSubImage");
	GLM_struct->glBindBuffersBaseproc = (PFNGLBINDBUFFERSBASEPROC)wglGetProcAddress("glBindBuffersBase");
	GLM_struct->glBindBuffersRangeproc = (PFNGLBINDBUFFERSRANGEPROC)wglGetProcAddress("glBindBuffersRange");
	GLM_struct->glBindTexturesproc = (PFNGLBINDTEXTURESPROC)wglGetProcAddress("glBindTextures");
	GLM_struct->glBindSamplersproc = (PFNGLBINDSAMPLERSPROC)wglGetProcAddress("glBindSamplers");
	GLM_struct->glBindImageTexturesproc = (PFNGLBINDIMAGETEXTURESPROC)wglGetProcAddress("glBindImageTextures");
	GLM_struct->glBindVertexBuffersproc = (PFNGLBINDVERTEXBUFFERSPROC)wglGetProcAddress("glBindVertexBuffers");
	GLM_struct->glClipControlproc = (PFNGLCLIPCONTROLPROC)wglGetProcAddress("glClipControl");
	GLM_struct->glCreateTransformFeedbacksproc = (PFNGLCREATETRANSFORMFEEDBACKSPROC)wglGetProcAddress("glCreateTransformFeedbacks");
	GLM_struct->glTransformFeedbackBufferBaseproc = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)wglGetProcAddress("glTransformFeedbackBufferBase");
	GLM_struct->glTransformFeedbackBufferRangeproc = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)wglGetProcAddress("glTransformFeedbackBufferRange");
	GLM_struct->glGetTransformFeedbackivproc = (PFNGLGETTRANSFORMFEEDBACKIVPROC)wglGetProcAddress("glGetTransformFeedbackiv");
	GLM_struct->glGetTransformFeedbacki_vproc = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)wglGetProcAddress("glGetTransformFeedbacki_v");
	GLM_struct->glGetTransformFeedbacki64_vproc = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)wglGetProcAddress("glGetTransformFeedbacki64_v");
	GLM_struct->glCreateBuffersproc = (PFNGLCREATEBUFFERSPROC)wglGetProcAddress("glCreateBuffers");
	GLM_struct->glNamedBufferStorageproc = (PFNGLNAMEDBUFFERSTORAGEPROC)wglGetProcAddress("glNamedBufferStorage");
	GLM_struct->glNamedBufferDataproc = (PFNGLNAMEDBUFFERDATAPROC)wglGetProcAddress("glNamedBufferData");
	GLM_struct->glNamedBufferSubDataproc = (PFNGLNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glNamedBufferSubData");
	GLM_struct->glCopyNamedBufferSubDataproc = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glCopyNamedBufferSubData");
	GLM_struct->glClearNamedBufferDataproc = (PFNGLCLEARNAMEDBUFFERDATAPROC)wglGetProcAddress("glClearNamedBufferData");
	GLM_struct->glClearNamedBufferSubDataproc = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glClearNamedBufferSubData");
	GLM_struct->glMapNamedBufferproc = (PFNGLMAPNAMEDBUFFERPROC)wglGetProcAddress("glMapNamedBuffer");
	GLM_struct->glMapNamedBufferRangeproc = (PFNGLMAPNAMEDBUFFERRANGEPROC)wglGetProcAddress("glMapNamedBufferRange");
	GLM_struct->glUnmapNamedBufferproc = (PFNGLUNMAPNAMEDBUFFERPROC)wglGetProcAddress("glUnmapNamedBuffer");
	GLM_struct->glFlushMappedNamedBufferRangeproc = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedNamedBufferRange");
	GLM_struct->glGetNamedBufferParameterivproc = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedBufferParameteriv");
	GLM_struct->glGetNamedBufferParameteri64vproc = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetNamedBufferParameteri64v");
	GLM_struct->glGetNamedBufferPointervproc = (PFNGLGETNAMEDBUFFERPOINTERVPROC)wglGetProcAddress("glGetNamedBufferPointerv");
	GLM_struct->glGetNamedBufferSubDataproc = (PFNGLGETNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glGetNamedBufferSubData");
	GLM_struct->glCreateFramebuffersproc = (PFNGLCREATEFRAMEBUFFERSPROC)wglGetProcAddress("glCreateFramebuffers");
	GLM_struct->glNamedFramebufferRenderbufferproc = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glNamedFramebufferRenderbuffer");
	GLM_struct->glNamedFramebufferParameteriproc = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)wglGetProcAddress("glNamedFramebufferParameteri");
	GLM_struct->glNamedFramebufferTextureproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glNamedFramebufferTexture");
	GLM_struct->glNamedFramebufferTextureLayerproc = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glNamedFramebufferTextureLayer");
	GLM_struct->glNamedFramebufferDrawBufferproc = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)wglGetProcAddress("glNamedFramebufferDrawBuffer");
	GLM_struct->glNamedFramebufferDrawBuffersproc = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)wglGetProcAddress("glNamedFramebufferDrawBuffers");
	GLM_struct->glNamedFramebufferReadBufferproc = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)wglGetProcAddress("glNamedFramebufferReadBuffer");
	GLM_struct->glInvalidateNamedFramebufferDataproc = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)wglGetProcAddress("glInvalidateNamedFramebufferData");
	GLM_struct->glInvalidateNamedFramebufferSubDataproc = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)wglGetProcAddress("glInvalidateNamedFramebufferSubData");
	GLM_struct->glClearNamedFramebufferivproc = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)wglGetProcAddress("glClearNamedFramebufferiv");
	GLM_struct->glClearNamedFramebufferuivproc = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)wglGetProcAddress("glClearNamedFramebufferuiv");
	GLM_struct->glClearNamedFramebufferfvproc = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)wglGetProcAddress("glClearNamedFramebufferfv");
	GLM_struct->glClearNamedFramebufferfiproc = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)wglGetProcAddress("glClearNamedFramebufferfi");
	GLM_struct->glBlitNamedFramebufferproc = (PFNGLBLITNAMEDFRAMEBUFFERPROC)wglGetProcAddress("glBlitNamedFramebuffer");
	GLM_struct->glCheckNamedFramebufferStatusproc = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckNamedFramebufferStatus");
	GLM_struct->glGetNamedFramebufferParameterivproc = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedFramebufferParameteriv");
	GLM_struct->glGetNamedFramebufferAttachmentParameterivproc = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetNamedFramebufferAttachmentParameteriv");
	GLM_struct->glCreateRenderbuffersproc = (PFNGLCREATERENDERBUFFERSPROC)wglGetProcAddress("glCreateRenderbuffers");
	GLM_struct->glNamedRenderbufferStorageproc = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glNamedRenderbufferStorage");
	GLM_struct->glNamedRenderbufferStorageMultisampleproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisample");
	GLM_struct->glGetNamedRenderbufferParameterivproc = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedRenderbufferParameteriv");
	GLM_struct->glCreateTexturesproc = (PFNGLCREATETEXTURESPROC)wglGetProcAddress("glCreateTextures");
	GLM_struct->glTextureBufferproc = (PFNGLTEXTUREBUFFERPROC)wglGetProcAddress("glTextureBuffer");
	GLM_struct->glTextureBufferRangeproc = (PFNGLTEXTUREBUFFERRANGEPROC)wglGetProcAddress("glTextureBufferRange");
	GLM_struct->glTextureStorage1Dproc = (PFNGLTEXTURESTORAGE1DPROC)wglGetProcAddress("glTextureStorage1D");
	GLM_struct->glTextureStorage2Dproc = (PFNGLTEXTURESTORAGE2DPROC)wglGetProcAddress("glTextureStorage2D");
	GLM_struct->glTextureStorage3Dproc = (PFNGLTEXTURESTORAGE3DPROC)wglGetProcAddress("glTextureStorage3D");
	GLM_struct->glTextureStorage2DMultisampleproc = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTextureStorage2DMultisample");
	GLM_struct->glTextureStorage3DMultisampleproc = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTextureStorage3DMultisample");
	GLM_struct->glTextureSubImage1Dproc = (PFNGLTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glTextureSubImage1D");
	GLM_struct->glTextureSubImage2Dproc = (PFNGLTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glTextureSubImage2D");
	GLM_struct->glTextureSubImage3Dproc = (PFNGLTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glTextureSubImage3D");
	GLM_struct->glCompressedTextureSubImage1Dproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glCompressedTextureSubImage1D");
	GLM_struct->glCompressedTextureSubImage2Dproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glCompressedTextureSubImage2D");
	GLM_struct->glCompressedTextureSubImage3Dproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glCompressedTextureSubImage3D");
	GLM_struct->glCopyTextureSubImage1Dproc = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glCopyTextureSubImage1D");
	GLM_struct->glCopyTextureSubImage2Dproc = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glCopyTextureSubImage2D");
	GLM_struct->glCopyTextureSubImage3Dproc = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glCopyTextureSubImage3D");
	GLM_struct->glTextureParameterfproc = (PFNGLTEXTUREPARAMETERFPROC)wglGetProcAddress("glTextureParameterf");
	GLM_struct->glTextureParameterfvproc = (PFNGLTEXTUREPARAMETERFVPROC)wglGetProcAddress("glTextureParameterfv");
	GLM_struct->glTextureParameteriproc = (PFNGLTEXTUREPARAMETERIPROC)wglGetProcAddress("glTextureParameteri");
	GLM_struct->glTextureParameterIivproc = (PFNGLTEXTUREPARAMETERIIVPROC)wglGetProcAddress("glTextureParameterIiv");
	GLM_struct->glTextureParameterIuivproc = (PFNGLTEXTUREPARAMETERIUIVPROC)wglGetProcAddress("glTextureParameterIuiv");
	GLM_struct->glTextureParameterivproc = (PFNGLTEXTUREPARAMETERIVPROC)wglGetProcAddress("glTextureParameteriv");
	GLM_struct->glGenerateTextureMipmapproc = (PFNGLGENERATETEXTUREMIPMAPPROC)wglGetProcAddress("glGenerateTextureMipmap");
	GLM_struct->glBindTextureUnitproc = (PFNGLBINDTEXTUREUNITPROC)wglGetProcAddress("glBindTextureUnit");
	GLM_struct->glGetTextureImageproc = (PFNGLGETTEXTUREIMAGEPROC)wglGetProcAddress("glGetTextureImage");
	GLM_struct->glGetCompressedTextureImageproc = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)wglGetProcAddress("glGetCompressedTextureImage");
	GLM_struct->glGetTextureLevelParameterfvproc = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)wglGetProcAddress("glGetTextureLevelParameterfv");
	GLM_struct->glGetTextureLevelParameterivproc = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)wglGetProcAddress("glGetTextureLevelParameteriv");
	GLM_struct->glGetTextureParameterfvproc = (PFNGLGETTEXTUREPARAMETERFVPROC)wglGetProcAddress("glGetTextureParameterfv");
	GLM_struct->glGetTextureParameterIivproc = (PFNGLGETTEXTUREPARAMETERIIVPROC)wglGetProcAddress("glGetTextureParameterIiv");
	GLM_struct->glGetTextureParameterIuivproc = (PFNGLGETTEXTUREPARAMETERIUIVPROC)wglGetProcAddress("glGetTextureParameterIuiv");
	GLM_struct->glGetTextureParameterivproc = (PFNGLGETTEXTUREPARAMETERIVPROC)wglGetProcAddress("glGetTextureParameteriv");
	GLM_struct->glCreateVertexArraysproc = (PFNGLCREATEVERTEXARRAYSPROC)wglGetProcAddress("glCreateVertexArrays");
	GLM_struct->glDisableVertexArrayAttribproc = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)wglGetProcAddress("glDisableVertexArrayAttrib");
	GLM_struct->glEnableVertexArrayAttribproc = (PFNGLENABLEVERTEXARRAYATTRIBPROC)wglGetProcAddress("glEnableVertexArrayAttrib");
	GLM_struct->glVertexArrayElementBufferproc = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)wglGetProcAddress("glVertexArrayElementBuffer");
	GLM_struct->glVertexArrayVertexBufferproc = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)wglGetProcAddress("glVertexArrayVertexBuffer");
	GLM_struct->glVertexArrayVertexBuffersproc = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)wglGetProcAddress("glVertexArrayVertexBuffers");
	GLM_struct->glVertexArrayAttribBindingproc = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)wglGetProcAddress("glVertexArrayAttribBinding");
	GLM_struct->glVertexArrayAttribFormatproc = (PFNGLVERTEXARRAYATTRIBFORMATPROC)wglGetProcAddress("glVertexArrayAttribFormat");
	GLM_struct->glVertexArrayAttribIFormatproc = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)wglGetProcAddress("glVertexArrayAttribIFormat");
	GLM_struct->glVertexArrayAttribLFormatproc = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)wglGetProcAddress("glVertexArrayAttribLFormat");
	GLM_struct->glVertexArrayBindingDivisorproc = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)wglGetProcAddress("glVertexArrayBindingDivisor");
	GLM_struct->glGetVertexArrayivproc = (PFNGLGETVERTEXARRAYIVPROC)wglGetProcAddress("glGetVertexArrayiv");
	GLM_struct->glGetVertexArrayIndexedivproc = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)wglGetProcAddress("glGetVertexArrayIndexediv");
	GLM_struct->glGetVertexArrayIndexed64ivproc = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)wglGetProcAddress("glGetVertexArrayIndexed64iv");
	GLM_struct->glCreateSamplersproc = (PFNGLCREATESAMPLERSPROC)wglGetProcAddress("glCreateSamplers");
	GLM_struct->glCreateProgramPipelinesproc = (PFNGLCREATEPROGRAMPIPELINESPROC)wglGetProcAddress("glCreateProgramPipelines");
	GLM_struct->glCreateQueriesproc = (PFNGLCREATEQUERIESPROC)wglGetProcAddress("glCreateQueries");
	GLM_struct->glGetQueryBufferObjecti64vproc = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)wglGetProcAddress("glGetQueryBufferObjecti64v");
	GLM_struct->glGetQueryBufferObjectivproc = (PFNGLGETQUERYBUFFEROBJECTIVPROC)wglGetProcAddress("glGetQueryBufferObjectiv");
	GLM_struct->glGetQueryBufferObjectui64vproc = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)wglGetProcAddress("glGetQueryBufferObjectui64v");
	GLM_struct->glGetQueryBufferObjectuivproc = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)wglGetProcAddress("glGetQueryBufferObjectuiv");
	GLM_struct->glMemoryBarrierByRegionproc = (PFNGLMEMORYBARRIERBYREGIONPROC)wglGetProcAddress("glMemoryBarrierByRegion");
	GLM_struct->glGetTextureSubImageproc = (PFNGLGETTEXTURESUBIMAGEPROC)wglGetProcAddress("glGetTextureSubImage");
	GLM_struct->glGetCompressedTextureSubImageproc = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)wglGetProcAddress("glGetCompressedTextureSubImage");
	GLM_struct->glGetGraphicsResetStatusproc = (PFNGLGETGRAPHICSRESETSTATUSPROC)wglGetProcAddress("glGetGraphicsResetStatus");
	GLM_struct->glGetnCompressedTexImageproc = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetnCompressedTexImage");
	GLM_struct->glGetnTexImageproc = (PFNGLGETNTEXIMAGEPROC)wglGetProcAddress("glGetnTexImage");
	GLM_struct->glGetnUniformdvproc = (PFNGLGETNUNIFORMDVPROC)wglGetProcAddress("glGetnUniformdv");
	GLM_struct->glGetnUniformfvproc = (PFNGLGETNUNIFORMFVPROC)wglGetProcAddress("glGetnUniformfv");
	GLM_struct->glGetnUniformivproc = (PFNGLGETNUNIFORMIVPROC)wglGetProcAddress("glGetnUniformiv");
	GLM_struct->glGetnUniformuivproc = (PFNGLGETNUNIFORMUIVPROC)wglGetProcAddress("glGetnUniformuiv");
	GLM_struct->glReadnPixelsproc = (PFNGLREADNPIXELSPROC)wglGetProcAddress("glReadnPixels");
	GLM_struct->glGetnMapdvproc = (PFNGLGETNMAPDVPROC)wglGetProcAddress("glGetnMapdv");
	GLM_struct->glGetnMapfvproc = (PFNGLGETNMAPFVPROC)wglGetProcAddress("glGetnMapfv");
	GLM_struct->glGetnMapivproc = (PFNGLGETNMAPIVPROC)wglGetProcAddress("glGetnMapiv");
	GLM_struct->glGetnPixelMapfvproc = (PFNGLGETNPIXELMAPFVPROC)wglGetProcAddress("glGetnPixelMapfv");
	GLM_struct->glGetnPixelMapuivproc = (PFNGLGETNPIXELMAPUIVPROC)wglGetProcAddress("glGetnPixelMapuiv");
	GLM_struct->glGetnPixelMapusvproc = (PFNGLGETNPIXELMAPUSVPROC)wglGetProcAddress("glGetnPixelMapusv");
	GLM_struct->glGetnPolygonStippleproc = (PFNGLGETNPOLYGONSTIPPLEPROC)wglGetProcAddress("glGetnPolygonStipple");
	GLM_struct->glGetnColorTableproc = (PFNGLGETNCOLORTABLEPROC)wglGetProcAddress("glGetnColorTable");
	GLM_struct->glGetnConvolutionFilterproc = (PFNGLGETNCONVOLUTIONFILTERPROC)wglGetProcAddress("glGetnConvolutionFilter");
	GLM_struct->glGetnSeparableFilterproc = (PFNGLGETNSEPARABLEFILTERPROC)wglGetProcAddress("glGetnSeparableFilter");
	GLM_struct->glGetnHistogramproc = (PFNGLGETNHISTOGRAMPROC)wglGetProcAddress("glGetnHistogram");
	GLM_struct->glGetnMinmaxproc = (PFNGLGETNMINMAXPROC)wglGetProcAddress("glGetnMinmax");
	GLM_struct->glTextureBarrierproc = (PFNGLTEXTUREBARRIERPROC)wglGetProcAddress("glTextureBarrier");
	GLM_struct->glSpecializeShaderproc = (PFNGLSPECIALIZESHADERPROC)wglGetProcAddress("glSpecializeShader");
	GLM_struct->glMultiDrawArraysIndirectCountproc = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)wglGetProcAddress("glMultiDrawArraysIndirectCount");
	GLM_struct->glMultiDrawElementsIndirectCountproc = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)wglGetProcAddress("glMultiDrawElementsIndirectCount");
	GLM_struct->glPolygonOffsetClampproc = (PFNGLPOLYGONOFFSETCLAMPPROC)wglGetProcAddress("glPolygonOffsetClamp");
	GLM_struct->glPrimitiveBoundingBoxARBproc = (PFNGLPRIMITIVEBOUNDINGBOXARBPROC)wglGetProcAddress("glPrimitiveBoundingBoxARB");
	GLM_struct->glGetTextureHandleARBproc = (PFNGLGETTEXTUREHANDLEARBPROC)wglGetProcAddress("glGetTextureHandleARB");
	GLM_struct->glGetTextureSamplerHandleARBproc = (PFNGLGETTEXTURESAMPLERHANDLEARBPROC)wglGetProcAddress("glGetTextureSamplerHandleARB");
	GLM_struct->glMakeTextureHandleResidentARBproc = (PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)wglGetProcAddress("glMakeTextureHandleResidentARB");
	GLM_struct->glMakeTextureHandleNonResidentARBproc = (PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)wglGetProcAddress("glMakeTextureHandleNonResidentARB");
	GLM_struct->glGetImageHandleARBproc = (PFNGLGETIMAGEHANDLEARBPROC)wglGetProcAddress("glGetImageHandleARB");
	GLM_struct->glMakeImageHandleResidentARBproc = (PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)wglGetProcAddress("glMakeImageHandleResidentARB");
	GLM_struct->glMakeImageHandleNonResidentARBproc = (PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)wglGetProcAddress("glMakeImageHandleNonResidentARB");
	GLM_struct->glUniformHandleui64ARBproc = (PFNGLUNIFORMHANDLEUI64ARBPROC)wglGetProcAddress("glUniformHandleui64ARB");
	GLM_struct->glUniformHandleui64vARBproc = (PFNGLUNIFORMHANDLEUI64VARBPROC)wglGetProcAddress("glUniformHandleui64vARB");
	GLM_struct->glProgramUniformHandleui64ARBproc = (PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)wglGetProcAddress("glProgramUniformHandleui64ARB");
	GLM_struct->glProgramUniformHandleui64vARBproc = (PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)wglGetProcAddress("glProgramUniformHandleui64vARB");
	GLM_struct->glIsTextureHandleResidentARBproc = (PFNGLISTEXTUREHANDLERESIDENTARBPROC)wglGetProcAddress("glIsTextureHandleResidentARB");
	GLM_struct->glIsImageHandleResidentARBproc = (PFNGLISIMAGEHANDLERESIDENTARBPROC)wglGetProcAddress("glIsImageHandleResidentARB");
	GLM_struct->glVertexAttribL1ui64ARBproc = (PFNGLVERTEXATTRIBL1UI64ARBPROC)wglGetProcAddress("glVertexAttribL1ui64ARB");
	GLM_struct->glVertexAttribL1ui64vARBproc = (PFNGLVERTEXATTRIBL1UI64VARBPROC)wglGetProcAddress("glVertexAttribL1ui64vARB");
	GLM_struct->glGetVertexAttribLui64vARBproc = (PFNGLGETVERTEXATTRIBLUI64VARBPROC)wglGetProcAddress("glGetVertexAttribLui64vARB");
	GLM_struct->glCreateSyncFromCLeventARBproc = (PFNGLCREATESYNCFROMCLEVENTARBPROC)wglGetProcAddress("glCreateSyncFromCLeventARB");
	GLM_struct->glClampColorARBproc = (PFNGLCLAMPCOLORARBPROC)wglGetProcAddress("glClampColorARB");
	GLM_struct->glDispatchComputeGroupSizeARBproc = (PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)wglGetProcAddress("glDispatchComputeGroupSizeARB");
	GLM_struct->glDebugMessageControlARBproc = (PFNGLDEBUGMESSAGECONTROLARBPROC)wglGetProcAddress("glDebugMessageControlARB");
	GLM_struct->glDebugMessageInsertARBproc = (PFNGLDEBUGMESSAGEINSERTARBPROC)wglGetProcAddress("glDebugMessageInsertARB");
	GLM_struct->glDebugMessageCallbackARBproc = (PFNGLDEBUGMESSAGECALLBACKARBPROC)wglGetProcAddress("glDebugMessageCallbackARB");
	GLM_struct->glGetDebugMessageLogARBproc = (PFNGLGETDEBUGMESSAGELOGARBPROC)wglGetProcAddress("glGetDebugMessageLogARB");
	GLM_struct->glDrawBuffersARBproc = (PFNGLDRAWBUFFERSARBPROC)wglGetProcAddress("glDrawBuffersARB");
	GLM_struct->glBlendEquationiARBproc = (PFNGLBLENDEQUATIONIARBPROC)wglGetProcAddress("glBlendEquationiARB");
	GLM_struct->glBlendEquationSeparateiARBproc = (PFNGLBLENDEQUATIONSEPARATEIARBPROC)wglGetProcAddress("glBlendEquationSeparateiARB");
	GLM_struct->glBlendFunciARBproc = (PFNGLBLENDFUNCIARBPROC)wglGetProcAddress("glBlendFunciARB");
	GLM_struct->glBlendFuncSeparateiARBproc = (PFNGLBLENDFUNCSEPARATEIARBPROC)wglGetProcAddress("glBlendFuncSeparateiARB");
	GLM_struct->glDrawArraysInstancedARBproc = (PFNGLDRAWARRAYSINSTANCEDARBPROC)wglGetProcAddress("glDrawArraysInstancedARB");
	GLM_struct->glDrawElementsInstancedARBproc = (PFNGLDRAWELEMENTSINSTANCEDARBPROC)wglGetProcAddress("glDrawElementsInstancedARB");
	GLM_struct->glProgramStringARBproc = (PFNGLPROGRAMSTRINGARBPROC)wglGetProcAddress("glProgramStringARB");
	GLM_struct->glBindProgramARBproc = (PFNGLBINDPROGRAMARBPROC)wglGetProcAddress("glBindProgramARB");
	GLM_struct->glDeleteProgramsARBproc = (PFNGLDELETEPROGRAMSARBPROC)wglGetProcAddress("glDeleteProgramsARB");
	GLM_struct->glGenProgramsARBproc = (PFNGLGENPROGRAMSARBPROC)wglGetProcAddress("glGenProgramsARB");
	GLM_struct->glProgramEnvParameter4dARBproc = (PFNGLPROGRAMENVPARAMETER4DARBPROC)wglGetProcAddress("glProgramEnvParameter4dARB");
	GLM_struct->glProgramEnvParameter4dvARBproc = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)wglGetProcAddress("glProgramEnvParameter4dvARB");
	GLM_struct->glProgramEnvParameter4fARBproc = (PFNGLPROGRAMENVPARAMETER4FARBPROC)wglGetProcAddress("glProgramEnvParameter4fARB");
	GLM_struct->glProgramEnvParameter4fvARBproc = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)wglGetProcAddress("glProgramEnvParameter4fvARB");
	GLM_struct->glProgramLocalParameter4dARBproc = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)wglGetProcAddress("glProgramLocalParameter4dARB");
	GLM_struct->glProgramLocalParameter4dvARBproc = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)wglGetProcAddress("glProgramLocalParameter4dvARB");
	GLM_struct->glProgramLocalParameter4fARBproc = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)wglGetProcAddress("glProgramLocalParameter4fARB");
	GLM_struct->glProgramLocalParameter4fvARBproc = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)wglGetProcAddress("glProgramLocalParameter4fvARB");
	GLM_struct->glGetProgramEnvParameterdvARBproc = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)wglGetProcAddress("glGetProgramEnvParameterdvARB");
	GLM_struct->glGetProgramEnvParameterfvARBproc = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)wglGetProcAddress("glGetProgramEnvParameterfvARB");
	GLM_struct->glGetProgramLocalParameterdvARBproc = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)wglGetProcAddress("glGetProgramLocalParameterdvARB");
	GLM_struct->glGetProgramLocalParameterfvARBproc = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)wglGetProcAddress("glGetProgramLocalParameterfvARB");
	GLM_struct->glGetProgramivARBproc = (PFNGLGETPROGRAMIVARBPROC)wglGetProcAddress("glGetProgramivARB");
	GLM_struct->glGetProgramStringARBproc = (PFNGLGETPROGRAMSTRINGARBPROC)wglGetProcAddress("glGetProgramStringARB");
	GLM_struct->glIsProgramARBproc = (PFNGLISPROGRAMARBPROC)wglGetProcAddress("glIsProgramARB");
	GLM_struct->glProgramParameteriARBproc = (PFNGLPROGRAMPARAMETERIARBPROC)wglGetProcAddress("glProgramParameteriARB");
	GLM_struct->glFramebufferTextureARBproc = (PFNGLFRAMEBUFFERTEXTUREARBPROC)wglGetProcAddress("glFramebufferTextureARB");
	GLM_struct->glFramebufferTextureLayerARBproc = (PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)wglGetProcAddress("glFramebufferTextureLayerARB");
	GLM_struct->glFramebufferTextureFaceARBproc = (PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)wglGetProcAddress("glFramebufferTextureFaceARB");
	GLM_struct->glSpecializeShaderARBproc = (PFNGLSPECIALIZESHADERARBPROC)wglGetProcAddress("glSpecializeShaderARB");
	GLM_struct->glUniform1i64ARBproc = (PFNGLUNIFORM1I64ARBPROC)wglGetProcAddress("glUniform1i64ARB");
	GLM_struct->glUniform2i64ARBproc = (PFNGLUNIFORM2I64ARBPROC)wglGetProcAddress("glUniform2i64ARB");
	GLM_struct->glUniform3i64ARBproc = (PFNGLUNIFORM3I64ARBPROC)wglGetProcAddress("glUniform3i64ARB");
	GLM_struct->glUniform4i64ARBproc = (PFNGLUNIFORM4I64ARBPROC)wglGetProcAddress("glUniform4i64ARB");
	GLM_struct->glUniform1i64vARBproc = (PFNGLUNIFORM1I64VARBPROC)wglGetProcAddress("glUniform1i64vARB");
	GLM_struct->glUniform2i64vARBproc = (PFNGLUNIFORM2I64VARBPROC)wglGetProcAddress("glUniform2i64vARB");
	GLM_struct->glUniform3i64vARBproc = (PFNGLUNIFORM3I64VARBPROC)wglGetProcAddress("glUniform3i64vARB");
	GLM_struct->glUniform4i64vARBproc = (PFNGLUNIFORM4I64VARBPROC)wglGetProcAddress("glUniform4i64vARB");
	GLM_struct->glUniform1ui64ARBproc = (PFNGLUNIFORM1UI64ARBPROC)wglGetProcAddress("glUniform1ui64ARB");
	GLM_struct->glUniform2ui64ARBproc = (PFNGLUNIFORM2UI64ARBPROC)wglGetProcAddress("glUniform2ui64ARB");
	GLM_struct->glUniform3ui64ARBproc = (PFNGLUNIFORM3UI64ARBPROC)wglGetProcAddress("glUniform3ui64ARB");
	GLM_struct->glUniform4ui64ARBproc = (PFNGLUNIFORM4UI64ARBPROC)wglGetProcAddress("glUniform4ui64ARB");
	GLM_struct->glUniform1ui64vARBproc = (PFNGLUNIFORM1UI64VARBPROC)wglGetProcAddress("glUniform1ui64vARB");
	GLM_struct->glUniform2ui64vARBproc = (PFNGLUNIFORM2UI64VARBPROC)wglGetProcAddress("glUniform2ui64vARB");
	GLM_struct->glUniform3ui64vARBproc = (PFNGLUNIFORM3UI64VARBPROC)wglGetProcAddress("glUniform3ui64vARB");
	GLM_struct->glUniform4ui64vARBproc = (PFNGLUNIFORM4UI64VARBPROC)wglGetProcAddress("glUniform4ui64vARB");
	GLM_struct->glGetUniformi64vARBproc = (PFNGLGETUNIFORMI64VARBPROC)wglGetProcAddress("glGetUniformi64vARB");
	GLM_struct->glGetUniformui64vARBproc = (PFNGLGETUNIFORMUI64VARBPROC)wglGetProcAddress("glGetUniformui64vARB");
	GLM_struct->glGetnUniformi64vARBproc = (PFNGLGETNUNIFORMI64VARBPROC)wglGetProcAddress("glGetnUniformi64vARB");
	GLM_struct->glGetnUniformui64vARBproc = (PFNGLGETNUNIFORMUI64VARBPROC)wglGetProcAddress("glGetnUniformui64vARB");
	GLM_struct->glProgramUniform1i64ARBproc = (PFNGLPROGRAMUNIFORM1I64ARBPROC)wglGetProcAddress("glProgramUniform1i64ARB");
	GLM_struct->glProgramUniform2i64ARBproc = (PFNGLPROGRAMUNIFORM2I64ARBPROC)wglGetProcAddress("glProgramUniform2i64ARB");
	GLM_struct->glProgramUniform3i64ARBproc = (PFNGLPROGRAMUNIFORM3I64ARBPROC)wglGetProcAddress("glProgramUniform3i64ARB");
	GLM_struct->glProgramUniform4i64ARBproc = (PFNGLPROGRAMUNIFORM4I64ARBPROC)wglGetProcAddress("glProgramUniform4i64ARB");
	GLM_struct->glProgramUniform1i64vARBproc = (PFNGLPROGRAMUNIFORM1I64VARBPROC)wglGetProcAddress("glProgramUniform1i64vARB");
	GLM_struct->glProgramUniform2i64vARBproc = (PFNGLPROGRAMUNIFORM2I64VARBPROC)wglGetProcAddress("glProgramUniform2i64vARB");
	GLM_struct->glProgramUniform3i64vARBproc = (PFNGLPROGRAMUNIFORM3I64VARBPROC)wglGetProcAddress("glProgramUniform3i64vARB");
	GLM_struct->glProgramUniform4i64vARBproc = (PFNGLPROGRAMUNIFORM4I64VARBPROC)wglGetProcAddress("glProgramUniform4i64vARB");
	GLM_struct->glProgramUniform1ui64ARBproc = (PFNGLPROGRAMUNIFORM1UI64ARBPROC)wglGetProcAddress("glProgramUniform1ui64ARB");
	GLM_struct->glProgramUniform2ui64ARBproc = (PFNGLPROGRAMUNIFORM2UI64ARBPROC)wglGetProcAddress("glProgramUniform2ui64ARB");
	GLM_struct->glProgramUniform3ui64ARBproc = (PFNGLPROGRAMUNIFORM3UI64ARBPROC)wglGetProcAddress("glProgramUniform3ui64ARB");
	GLM_struct->glProgramUniform4ui64ARBproc = (PFNGLPROGRAMUNIFORM4UI64ARBPROC)wglGetProcAddress("glProgramUniform4ui64ARB");
	GLM_struct->glProgramUniform1ui64vARBproc = (PFNGLPROGRAMUNIFORM1UI64VARBPROC)wglGetProcAddress("glProgramUniform1ui64vARB");
	GLM_struct->glProgramUniform2ui64vARBproc = (PFNGLPROGRAMUNIFORM2UI64VARBPROC)wglGetProcAddress("glProgramUniform2ui64vARB");
	GLM_struct->glProgramUniform3ui64vARBproc = (PFNGLPROGRAMUNIFORM3UI64VARBPROC)wglGetProcAddress("glProgramUniform3ui64vARB");
	GLM_struct->glProgramUniform4ui64vARBproc = (PFNGLPROGRAMUNIFORM4UI64VARBPROC)wglGetProcAddress("glProgramUniform4ui64vARB");
	GLM_struct->glColorTableproc = (PFNGLCOLORTABLEPROC)wglGetProcAddress("glColorTable");
	GLM_struct->glColorTableParameterfvproc = (PFNGLCOLORTABLEPARAMETERFVPROC)wglGetProcAddress("glColorTableParameterfv");
	GLM_struct->glColorTableParameterivproc = (PFNGLCOLORTABLEPARAMETERIVPROC)wglGetProcAddress("glColorTableParameteriv");
	GLM_struct->glCopyColorTableproc = (PFNGLCOPYCOLORTABLEPROC)wglGetProcAddress("glCopyColorTable");
	GLM_struct->glGetColorTableproc = (PFNGLGETCOLORTABLEPROC)wglGetProcAddress("glGetColorTable");
	GLM_struct->glGetColorTableParameterfvproc = (PFNGLGETCOLORTABLEPARAMETERFVPROC)wglGetProcAddress("glGetColorTableParameterfv");
	GLM_struct->glGetColorTableParameterivproc = (PFNGLGETCOLORTABLEPARAMETERIVPROC)wglGetProcAddress("glGetColorTableParameteriv");
	GLM_struct->glColorSubTableproc = (PFNGLCOLORSUBTABLEPROC)wglGetProcAddress("glColorSubTable");
	GLM_struct->glCopyColorSubTableproc = (PFNGLCOPYCOLORSUBTABLEPROC)wglGetProcAddress("glCopyColorSubTable");
	GLM_struct->glConvolutionFilter1Dproc = (PFNGLCONVOLUTIONFILTER1DPROC)wglGetProcAddress("glConvolutionFilter1D");
	GLM_struct->glConvolutionFilter2Dproc = (PFNGLCONVOLUTIONFILTER2DPROC)wglGetProcAddress("glConvolutionFilter2D");
	GLM_struct->glConvolutionParameterfproc = (PFNGLCONVOLUTIONPARAMETERFPROC)wglGetProcAddress("glConvolutionParameterf");
	GLM_struct->glConvolutionParameterfvproc = (PFNGLCONVOLUTIONPARAMETERFVPROC)wglGetProcAddress("glConvolutionParameterfv");
	GLM_struct->glConvolutionParameteriproc = (PFNGLCONVOLUTIONPARAMETERIPROC)wglGetProcAddress("glConvolutionParameteri");
	GLM_struct->glConvolutionParameterivproc = (PFNGLCONVOLUTIONPARAMETERIVPROC)wglGetProcAddress("glConvolutionParameteriv");
	GLM_struct->glCopyConvolutionFilter1Dproc = (PFNGLCOPYCONVOLUTIONFILTER1DPROC)wglGetProcAddress("glCopyConvolutionFilter1D");
	GLM_struct->glCopyConvolutionFilter2Dproc = (PFNGLCOPYCONVOLUTIONFILTER2DPROC)wglGetProcAddress("glCopyConvolutionFilter2D");
	GLM_struct->glGetConvolutionFilterproc = (PFNGLGETCONVOLUTIONFILTERPROC)wglGetProcAddress("glGetConvolutionFilter");
	GLM_struct->glGetConvolutionParameterfvproc = (PFNGLGETCONVOLUTIONPARAMETERFVPROC)wglGetProcAddress("glGetConvolutionParameterfv");
	GLM_struct->glGetConvolutionParameterivproc = (PFNGLGETCONVOLUTIONPARAMETERIVPROC)wglGetProcAddress("glGetConvolutionParameteriv");
	GLM_struct->glGetSeparableFilterproc = (PFNGLGETSEPARABLEFILTERPROC)wglGetProcAddress("glGetSeparableFilter");
	GLM_struct->glSeparableFilter2Dproc = (PFNGLSEPARABLEFILTER2DPROC)wglGetProcAddress("glSeparableFilter2D");
	GLM_struct->glGetHistogramproc = (PFNGLGETHISTOGRAMPROC)wglGetProcAddress("glGetHistogram");
	GLM_struct->glGetHistogramParameterfvproc = (PFNGLGETHISTOGRAMPARAMETERFVPROC)wglGetProcAddress("glGetHistogramParameterfv");
	GLM_struct->glGetHistogramParameterivproc = (PFNGLGETHISTOGRAMPARAMETERIVPROC)wglGetProcAddress("glGetHistogramParameteriv");
	GLM_struct->glGetMinmaxproc = (PFNGLGETMINMAXPROC)wglGetProcAddress("glGetMinmax");
	GLM_struct->glGetMinmaxParameterfvproc = (PFNGLGETMINMAXPARAMETERFVPROC)wglGetProcAddress("glGetMinmaxParameterfv");
	GLM_struct->glGetMinmaxParameterivproc = (PFNGLGETMINMAXPARAMETERIVPROC)wglGetProcAddress("glGetMinmaxParameteriv");
	GLM_struct->glHistogramproc = (PFNGLHISTOGRAMPROC)wglGetProcAddress("glHistogram");
	GLM_struct->glMinmaxproc = (PFNGLMINMAXPROC)wglGetProcAddress("glMinmax");
	GLM_struct->glResetHistogramproc = (PFNGLRESETHISTOGRAMPROC)wglGetProcAddress("glResetHistogram");
	GLM_struct->glResetMinmaxproc = (PFNGLRESETMINMAXPROC)wglGetProcAddress("glResetMinmax");
	GLM_struct->glMultiDrawArraysIndirectCountARBproc = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)wglGetProcAddress("glMultiDrawArraysIndirectCountARB");
	GLM_struct->glMultiDrawElementsIndirectCountARBproc = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)wglGetProcAddress("glMultiDrawElementsIndirectCountARB");
	GLM_struct->glVertexAttribDivisorARBproc = (PFNGLVERTEXATTRIBDIVISORARBPROC)wglGetProcAddress("glVertexAttribDivisorARB");
	GLM_struct->glCurrentPaletteMatrixARBproc = (PFNGLCURRENTPALETTEMATRIXARBPROC)wglGetProcAddress("glCurrentPaletteMatrixARB");
	GLM_struct->glMatrixIndexubvARBproc = (PFNGLMATRIXINDEXUBVARBPROC)wglGetProcAddress("glMatrixIndexubvARB");
	GLM_struct->glMatrixIndexusvARBproc = (PFNGLMATRIXINDEXUSVARBPROC)wglGetProcAddress("glMatrixIndexusvARB");
	GLM_struct->glMatrixIndexuivARBproc = (PFNGLMATRIXINDEXUIVARBPROC)wglGetProcAddress("glMatrixIndexuivARB");
	GLM_struct->glMatrixIndexPointerARBproc = (PFNGLMATRIXINDEXPOINTERARBPROC)wglGetProcAddress("glMatrixIndexPointerARB");
	GLM_struct->glSampleCoverageARBproc = (PFNGLSAMPLECOVERAGEARBPROC)wglGetProcAddress("glSampleCoverageARB");
	GLM_struct->glActiveTextureARBproc = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
	GLM_struct->glClientActiveTextureARBproc = (PFNGLCLIENTACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");
	GLM_struct->glMultiTexCoord1dARBproc = (PFNGLMULTITEXCOORD1DARBPROC)wglGetProcAddress("glMultiTexCoord1dARB");
	GLM_struct->glMultiTexCoord1dvARBproc = (PFNGLMULTITEXCOORD1DVARBPROC)wglGetProcAddress("glMultiTexCoord1dvARB");
	GLM_struct->glMultiTexCoord1fARBproc = (PFNGLMULTITEXCOORD1FARBPROC)wglGetProcAddress("glMultiTexCoord1fARB");
	GLM_struct->glMultiTexCoord1fvARBproc = (PFNGLMULTITEXCOORD1FVARBPROC)wglGetProcAddress("glMultiTexCoord1fvARB");
	GLM_struct->glMultiTexCoord1iARBproc = (PFNGLMULTITEXCOORD1IARBPROC)wglGetProcAddress("glMultiTexCoord1iARB");
	GLM_struct->glMultiTexCoord1ivARBproc = (PFNGLMULTITEXCOORD1IVARBPROC)wglGetProcAddress("glMultiTexCoord1ivARB");
	GLM_struct->glMultiTexCoord1sARBproc = (PFNGLMULTITEXCOORD1SARBPROC)wglGetProcAddress("glMultiTexCoord1sARB");
	GLM_struct->glMultiTexCoord1svARBproc = (PFNGLMULTITEXCOORD1SVARBPROC)wglGetProcAddress("glMultiTexCoord1svARB");
	GLM_struct->glMultiTexCoord2dARBproc = (PFNGLMULTITEXCOORD2DARBPROC)wglGetProcAddress("glMultiTexCoord2dARB");
	GLM_struct->glMultiTexCoord2dvARBproc = (PFNGLMULTITEXCOORD2DVARBPROC)wglGetProcAddress("glMultiTexCoord2dvARB");
	GLM_struct->glMultiTexCoord2fARBproc = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
	GLM_struct->glMultiTexCoord2fvARBproc = (PFNGLMULTITEXCOORD2FVARBPROC)wglGetProcAddress("glMultiTexCoord2fvARB");
	GLM_struct->glMultiTexCoord2iARBproc = (PFNGLMULTITEXCOORD2IARBPROC)wglGetProcAddress("glMultiTexCoord2iARB");
	GLM_struct->glMultiTexCoord2ivARBproc = (PFNGLMULTITEXCOORD2IVARBPROC)wglGetProcAddress("glMultiTexCoord2ivARB");
	GLM_struct->glMultiTexCoord2sARBproc = (PFNGLMULTITEXCOORD2SARBPROC)wglGetProcAddress("glMultiTexCoord2sARB");
	GLM_struct->glMultiTexCoord2svARBproc = (PFNGLMULTITEXCOORD2SVARBPROC)wglGetProcAddress("glMultiTexCoord2svARB");
	GLM_struct->glMultiTexCoord3dARBproc = (PFNGLMULTITEXCOORD3DARBPROC)wglGetProcAddress("glMultiTexCoord3dARB");
	GLM_struct->glMultiTexCoord3dvARBproc = (PFNGLMULTITEXCOORD3DVARBPROC)wglGetProcAddress("glMultiTexCoord3dvARB");
	GLM_struct->glMultiTexCoord3fARBproc = (PFNGLMULTITEXCOORD3FARBPROC)wglGetProcAddress("glMultiTexCoord3fARB");
	GLM_struct->glMultiTexCoord3fvARBproc = (PFNGLMULTITEXCOORD3FVARBPROC)wglGetProcAddress("glMultiTexCoord3fvARB");
	GLM_struct->glMultiTexCoord3iARBproc = (PFNGLMULTITEXCOORD3IARBPROC)wglGetProcAddress("glMultiTexCoord3iARB");
	GLM_struct->glMultiTexCoord3ivARBproc = (PFNGLMULTITEXCOORD3IVARBPROC)wglGetProcAddress("glMultiTexCoord3ivARB");
	GLM_struct->glMultiTexCoord3sARBproc = (PFNGLMULTITEXCOORD3SARBPROC)wglGetProcAddress("glMultiTexCoord3sARB");
	GLM_struct->glMultiTexCoord3svARBproc = (PFNGLMULTITEXCOORD3SVARBPROC)wglGetProcAddress("glMultiTexCoord3svARB");
	GLM_struct->glMultiTexCoord4dARBproc = (PFNGLMULTITEXCOORD4DARBPROC)wglGetProcAddress("glMultiTexCoord4dARB");
	GLM_struct->glMultiTexCoord4dvARBproc = (PFNGLMULTITEXCOORD4DVARBPROC)wglGetProcAddress("glMultiTexCoord4dvARB");
	GLM_struct->glMultiTexCoord4fARBproc = (PFNGLMULTITEXCOORD4FARBPROC)wglGetProcAddress("glMultiTexCoord4fARB");
	GLM_struct->glMultiTexCoord4fvARBproc = (PFNGLMULTITEXCOORD4FVARBPROC)wglGetProcAddress("glMultiTexCoord4fvARB");
	GLM_struct->glMultiTexCoord4iARBproc = (PFNGLMULTITEXCOORD4IARBPROC)wglGetProcAddress("glMultiTexCoord4iARB");
	GLM_struct->glMultiTexCoord4ivARBproc = (PFNGLMULTITEXCOORD4IVARBPROC)wglGetProcAddress("glMultiTexCoord4ivARB");
	GLM_struct->glMultiTexCoord4sARBproc = (PFNGLMULTITEXCOORD4SARBPROC)wglGetProcAddress("glMultiTexCoord4sARB");
	GLM_struct->glMultiTexCoord4svARBproc = (PFNGLMULTITEXCOORD4SVARBPROC)wglGetProcAddress("glMultiTexCoord4svARB");
	GLM_struct->glGenQueriesARBproc = (PFNGLGENQUERIESARBPROC)wglGetProcAddress("glGenQueriesARB");
	GLM_struct->glDeleteQueriesARBproc = (PFNGLDELETEQUERIESARBPROC)wglGetProcAddress("glDeleteQueriesARB");
	GLM_struct->glIsQueryARBproc = (PFNGLISQUERYARBPROC)wglGetProcAddress("glIsQueryARB");
	GLM_struct->glBeginQueryARBproc = (PFNGLBEGINQUERYARBPROC)wglGetProcAddress("glBeginQueryARB");
	GLM_struct->glEndQueryARBproc = (PFNGLENDQUERYARBPROC)wglGetProcAddress("glEndQueryARB");
	GLM_struct->glGetQueryivARBproc = (PFNGLGETQUERYIVARBPROC)wglGetProcAddress("glGetQueryivARB");
	GLM_struct->glGetQueryObjectivARBproc = (PFNGLGETQUERYOBJECTIVARBPROC)wglGetProcAddress("glGetQueryObjectivARB");
	GLM_struct->glGetQueryObjectuivARBproc = (PFNGLGETQUERYOBJECTUIVARBPROC)wglGetProcAddress("glGetQueryObjectuivARB");
	GLM_struct->glMaxShaderCompilerThreadsARBproc = (PFNGLMAXSHADERCOMPILERTHREADSARBPROC)wglGetProcAddress("glMaxShaderCompilerThreadsARB");
	GLM_struct->glPointParameterfARBproc = (PFNGLPOINTPARAMETERFARBPROC)wglGetProcAddress("glPointParameterfARB");
	GLM_struct->glPointParameterfvARBproc = (PFNGLPOINTPARAMETERFVARBPROC)wglGetProcAddress("glPointParameterfvARB");
	GLM_struct->glGetGraphicsResetStatusARBproc = (PFNGLGETGRAPHICSRESETSTATUSARBPROC)wglGetProcAddress("glGetGraphicsResetStatusARB");
	GLM_struct->glGetnTexImageARBproc = (PFNGLGETNTEXIMAGEARBPROC)wglGetProcAddress("glGetnTexImageARB");
	GLM_struct->glReadnPixelsARBproc = (PFNGLREADNPIXELSARBPROC)wglGetProcAddress("glReadnPixelsARB");
	GLM_struct->glGetnCompressedTexImageARBproc = (PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)wglGetProcAddress("glGetnCompressedTexImageARB");
	GLM_struct->glGetnUniformfvARBproc = (PFNGLGETNUNIFORMFVARBPROC)wglGetProcAddress("glGetnUniformfvARB");
	GLM_struct->glGetnUniformivARBproc = (PFNGLGETNUNIFORMIVARBPROC)wglGetProcAddress("glGetnUniformivARB");
	GLM_struct->glGetnUniformuivARBproc = (PFNGLGETNUNIFORMUIVARBPROC)wglGetProcAddress("glGetnUniformuivARB");
	GLM_struct->glGetnUniformdvARBproc = (PFNGLGETNUNIFORMDVARBPROC)wglGetProcAddress("glGetnUniformdvARB");
	GLM_struct->glGetnMapdvARBproc = (PFNGLGETNMAPDVARBPROC)wglGetProcAddress("glGetnMapdvARB");
	GLM_struct->glGetnMapfvARBproc = (PFNGLGETNMAPFVARBPROC)wglGetProcAddress("glGetnMapfvARB");
	GLM_struct->glGetnMapivARBproc = (PFNGLGETNMAPIVARBPROC)wglGetProcAddress("glGetnMapivARB");
	GLM_struct->glGetnPixelMapfvARBproc = (PFNGLGETNPIXELMAPFVARBPROC)wglGetProcAddress("glGetnPixelMapfvARB");
	GLM_struct->glGetnPixelMapuivARBproc = (PFNGLGETNPIXELMAPUIVARBPROC)wglGetProcAddress("glGetnPixelMapuivARB");
	GLM_struct->glGetnPixelMapusvARBproc = (PFNGLGETNPIXELMAPUSVARBPROC)wglGetProcAddress("glGetnPixelMapusvARB");
	GLM_struct->glGetnPolygonStippleARBproc = (PFNGLGETNPOLYGONSTIPPLEARBPROC)wglGetProcAddress("glGetnPolygonStippleARB");
	GLM_struct->glGetnColorTableARBproc = (PFNGLGETNCOLORTABLEARBPROC)wglGetProcAddress("glGetnColorTableARB");
	GLM_struct->glGetnConvolutionFilterARBproc = (PFNGLGETNCONVOLUTIONFILTERARBPROC)wglGetProcAddress("glGetnConvolutionFilterARB");
	GLM_struct->glGetnSeparableFilterARBproc = (PFNGLGETNSEPARABLEFILTERARBPROC)wglGetProcAddress("glGetnSeparableFilterARB");
	GLM_struct->glGetnHistogramARBproc = (PFNGLGETNHISTOGRAMARBPROC)wglGetProcAddress("glGetnHistogramARB");
	GLM_struct->glGetnMinmaxARBproc = (PFNGLGETNMINMAXARBPROC)wglGetProcAddress("glGetnMinmaxARB");
	GLM_struct->glFramebufferSampleLocationsfvARBproc = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)wglGetProcAddress("glFramebufferSampleLocationsfvARB");
	GLM_struct->glNamedFramebufferSampleLocationsfvARBproc = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)wglGetProcAddress("glNamedFramebufferSampleLocationsfvARB");
	GLM_struct->glEvaluateDepthValuesARBproc = (PFNGLEVALUATEDEPTHVALUESARBPROC)wglGetProcAddress("glEvaluateDepthValuesARB");
	GLM_struct->glMinSampleShadingARBproc = (PFNGLMINSAMPLESHADINGARBPROC)wglGetProcAddress("glMinSampleShadingARB");
	GLM_struct->glDeleteObjectARBproc = (PFNGLDELETEOBJECTARBPROC)wglGetProcAddress("glDeleteObjectARB");
	GLM_struct->glGetHandleARBproc = (PFNGLGETHANDLEARBPROC)wglGetProcAddress("glGetHandleARB");
	GLM_struct->glDetachObjectARBproc = (PFNGLDETACHOBJECTARBPROC)wglGetProcAddress("glDetachObjectARB");
	GLM_struct->glCreateShaderObjectARBproc = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
	GLM_struct->glShaderSourceARBproc = (PFNGLSHADERSOURCEARBPROC)wglGetProcAddress("glShaderSourceARB");
	GLM_struct->glCompileShaderARBproc = (PFNGLCOMPILESHADERARBPROC)wglGetProcAddress("glCompileShaderARB");
	GLM_struct->glCreateProgramObjectARBproc = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
	GLM_struct->glAttachObjectARBproc = (PFNGLATTACHOBJECTARBPROC)wglGetProcAddress("glAttachObjectARB");
	GLM_struct->glLinkProgramARBproc = (PFNGLLINKPROGRAMARBPROC)wglGetProcAddress("glLinkProgramARB");
	GLM_struct->glUseProgramObjectARBproc = (PFNGLUSEPROGRAMOBJECTARBPROC)wglGetProcAddress("glUseProgramObjectARB");
	GLM_struct->glValidateProgramARBproc = (PFNGLVALIDATEPROGRAMARBPROC)wglGetProcAddress("glValidateProgramARB");
	GLM_struct->glUniform1fARBproc = (PFNGLUNIFORM1FARBPROC)wglGetProcAddress("glUniform1fARB");
	GLM_struct->glUniform2fARBproc = (PFNGLUNIFORM2FARBPROC)wglGetProcAddress("glUniform2fARB");
	GLM_struct->glUniform3fARBproc = (PFNGLUNIFORM3FARBPROC)wglGetProcAddress("glUniform3fARB");
	GLM_struct->glUniform4fARBproc = (PFNGLUNIFORM4FARBPROC)wglGetProcAddress("glUniform4fARB");
	GLM_struct->glUniform1iARBproc = (PFNGLUNIFORM1IARBPROC)wglGetProcAddress("glUniform1iARB");
	GLM_struct->glUniform2iARBproc = (PFNGLUNIFORM2IARBPROC)wglGetProcAddress("glUniform2iARB");
	GLM_struct->glUniform3iARBproc = (PFNGLUNIFORM3IARBPROC)wglGetProcAddress("glUniform3iARB");
	GLM_struct->glUniform4iARBproc = (PFNGLUNIFORM4IARBPROC)wglGetProcAddress("glUniform4iARB");
	GLM_struct->glUniform1fvARBproc = (PFNGLUNIFORM1FVARBPROC)wglGetProcAddress("glUniform1fvARB");
	GLM_struct->glUniform2fvARBproc = (PFNGLUNIFORM2FVARBPROC)wglGetProcAddress("glUniform2fvARB");
	GLM_struct->glUniform3fvARBproc = (PFNGLUNIFORM3FVARBPROC)wglGetProcAddress("glUniform3fvARB");
	GLM_struct->glUniform4fvARBproc = (PFNGLUNIFORM4FVARBPROC)wglGetProcAddress("glUniform4fvARB");
	GLM_struct->glUniform1ivARBproc = (PFNGLUNIFORM1IVARBPROC)wglGetProcAddress("glUniform1ivARB");
	GLM_struct->glUniform2ivARBproc = (PFNGLUNIFORM2IVARBPROC)wglGetProcAddress("glUniform2ivARB");
	GLM_struct->glUniform3ivARBproc = (PFNGLUNIFORM3IVARBPROC)wglGetProcAddress("glUniform3ivARB");
	GLM_struct->glUniform4ivARBproc = (PFNGLUNIFORM4IVARBPROC)wglGetProcAddress("glUniform4ivARB");
	GLM_struct->glUniformMatrix2fvARBproc = (PFNGLUNIFORMMATRIX2FVARBPROC)wglGetProcAddress("glUniformMatrix2fvARB");
	GLM_struct->glUniformMatrix3fvARBproc = (PFNGLUNIFORMMATRIX3FVARBPROC)wglGetProcAddress("glUniformMatrix3fvARB");
	GLM_struct->glUniformMatrix4fvARBproc = (PFNGLUNIFORMMATRIX4FVARBPROC)wglGetProcAddress("glUniformMatrix4fvARB");
	GLM_struct->glGetObjectParameterfvARBproc = (PFNGLGETOBJECTPARAMETERFVARBPROC)wglGetProcAddress("glGetObjectParameterfvARB");
	GLM_struct->glGetObjectParameterivARBproc = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
	GLM_struct->glGetInfoLogARBproc = (PFNGLGETINFOLOGARBPROC)wglGetProcAddress("glGetInfoLogARB");
	GLM_struct->glGetAttachedObjectsARBproc = (PFNGLGETATTACHEDOBJECTSARBPROC)wglGetProcAddress("glGetAttachedObjectsARB");
	GLM_struct->glGetUniformLocationARBproc = (PFNGLGETUNIFORMLOCATIONARBPROC)wglGetProcAddress("glGetUniformLocationARB");
	GLM_struct->glGetActiveUniformARBproc = (PFNGLGETACTIVEUNIFORMARBPROC)wglGetProcAddress("glGetActiveUniformARB");
	GLM_struct->glGetUniformfvARBproc = (PFNGLGETUNIFORMFVARBPROC)wglGetProcAddress("glGetUniformfvARB");
	GLM_struct->glGetUniformivARBproc = (PFNGLGETUNIFORMIVARBPROC)wglGetProcAddress("glGetUniformivARB");
	GLM_struct->glGetShaderSourceARBproc = (PFNGLGETSHADERSOURCEARBPROC)wglGetProcAddress("glGetShaderSourceARB");
	GLM_struct->glNamedStringARBproc = (PFNGLNAMEDSTRINGARBPROC)wglGetProcAddress("glNamedStringARB");
	GLM_struct->glDeleteNamedStringARBproc = (PFNGLDELETENAMEDSTRINGARBPROC)wglGetProcAddress("glDeleteNamedStringARB");
	GLM_struct->glCompileShaderIncludeARBproc = (PFNGLCOMPILESHADERINCLUDEARBPROC)wglGetProcAddress("glCompileShaderIncludeARB");
	GLM_struct->glIsNamedStringARBproc = (PFNGLISNAMEDSTRINGARBPROC)wglGetProcAddress("glIsNamedStringARB");
	GLM_struct->glGetNamedStringARBproc = (PFNGLGETNAMEDSTRINGARBPROC)wglGetProcAddress("glGetNamedStringARB");
	GLM_struct->glGetNamedStringivARBproc = (PFNGLGETNAMEDSTRINGIVARBPROC)wglGetProcAddress("glGetNamedStringivARB");
	GLM_struct->glBufferPageCommitmentARBproc = (PFNGLBUFFERPAGECOMMITMENTARBPROC)wglGetProcAddress("glBufferPageCommitmentARB");
	GLM_struct->glNamedBufferPageCommitmentEXTproc = (PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)wglGetProcAddress("glNamedBufferPageCommitmentEXT");
	GLM_struct->glNamedBufferPageCommitmentARBproc = (PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)wglGetProcAddress("glNamedBufferPageCommitmentARB");
	GLM_struct->glTexPageCommitmentARBproc = (PFNGLTEXPAGECOMMITMENTARBPROC)wglGetProcAddress("glTexPageCommitmentARB");
	GLM_struct->glTexBufferARBproc = (PFNGLTEXBUFFERARBPROC)wglGetProcAddress("glTexBufferARB");
	GLM_struct->glCompressedTexImage3DARBproc = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)wglGetProcAddress("glCompressedTexImage3DARB");
	GLM_struct->glCompressedTexImage2DARBproc = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)wglGetProcAddress("glCompressedTexImage2DARB");
	GLM_struct->glCompressedTexImage1DARBproc = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)wglGetProcAddress("glCompressedTexImage1DARB");
	GLM_struct->glCompressedTexSubImage3DARBproc = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)wglGetProcAddress("glCompressedTexSubImage3DARB");
	GLM_struct->glCompressedTexSubImage2DARBproc = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)wglGetProcAddress("glCompressedTexSubImage2DARB");
	GLM_struct->glCompressedTexSubImage1DARBproc = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)wglGetProcAddress("glCompressedTexSubImage1DARB");
	GLM_struct->glGetCompressedTexImageARBproc = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)wglGetProcAddress("glGetCompressedTexImageARB");
	GLM_struct->glLoadTransposeMatrixfARBproc = (PFNGLLOADTRANSPOSEMATRIXFARBPROC)wglGetProcAddress("glLoadTransposeMatrixfARB");
	GLM_struct->glLoadTransposeMatrixdARBproc = (PFNGLLOADTRANSPOSEMATRIXDARBPROC)wglGetProcAddress("glLoadTransposeMatrixdARB");
	GLM_struct->glMultTransposeMatrixfARBproc = (PFNGLMULTTRANSPOSEMATRIXFARBPROC)wglGetProcAddress("glMultTransposeMatrixfARB");
	GLM_struct->glMultTransposeMatrixdARBproc = (PFNGLMULTTRANSPOSEMATRIXDARBPROC)wglGetProcAddress("glMultTransposeMatrixdARB");
	GLM_struct->glWeightbvARBproc = (PFNGLWEIGHTBVARBPROC)wglGetProcAddress("glWeightbvARB");
	GLM_struct->glWeightsvARBproc = (PFNGLWEIGHTSVARBPROC)wglGetProcAddress("glWeightsvARB");
	GLM_struct->glWeightivARBproc = (PFNGLWEIGHTIVARBPROC)wglGetProcAddress("glWeightivARB");
	GLM_struct->glWeightfvARBproc = (PFNGLWEIGHTFVARBPROC)wglGetProcAddress("glWeightfvARB");
	GLM_struct->glWeightdvARBproc = (PFNGLWEIGHTDVARBPROC)wglGetProcAddress("glWeightdvARB");
	GLM_struct->glWeightubvARBproc = (PFNGLWEIGHTUBVARBPROC)wglGetProcAddress("glWeightubvARB");
	GLM_struct->glWeightusvARBproc = (PFNGLWEIGHTUSVARBPROC)wglGetProcAddress("glWeightusvARB");
	GLM_struct->glWeightuivARBproc = (PFNGLWEIGHTUIVARBPROC)wglGetProcAddress("glWeightuivARB");
	GLM_struct->glWeightPointerARBproc = (PFNGLWEIGHTPOINTERARBPROC)wglGetProcAddress("glWeightPointerARB");
	GLM_struct->glVertexBlendARBproc = (PFNGLVERTEXBLENDARBPROC)wglGetProcAddress("glVertexBlendARB");
	GLM_struct->glBindBufferARBproc = (PFNGLBINDBUFFERARBPROC)wglGetProcAddress("glBindBufferARB");
	GLM_struct->glDeleteBuffersARBproc = (PFNGLDELETEBUFFERSARBPROC)wglGetProcAddress("glDeleteBuffersARB");
	GLM_struct->glGenBuffersARBproc = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffersARB");
	GLM_struct->glIsBufferARBproc = (PFNGLISBUFFERARBPROC)wglGetProcAddress("glIsBufferARB");
	GLM_struct->glBufferDataARBproc = (PFNGLBUFFERDATAARBPROC)wglGetProcAddress("glBufferDataARB");
	GLM_struct->glBufferSubDataARBproc = (PFNGLBUFFERSUBDATAARBPROC)wglGetProcAddress("glBufferSubDataARB");
	GLM_struct->glGetBufferSubDataARBproc = (PFNGLGETBUFFERSUBDATAARBPROC)wglGetProcAddress("glGetBufferSubDataARB");
	GLM_struct->glMapBufferARBproc = (PFNGLMAPBUFFERARBPROC)wglGetProcAddress("glMapBufferARB");
	GLM_struct->glUnmapBufferARBproc = (PFNGLUNMAPBUFFERARBPROC)wglGetProcAddress("glUnmapBufferARB");
	GLM_struct->glGetBufferParameterivARBproc = (PFNGLGETBUFFERPARAMETERIVARBPROC)wglGetProcAddress("glGetBufferParameterivARB");
	GLM_struct->glGetBufferPointervARBproc = (PFNGLGETBUFFERPOINTERVARBPROC)wglGetProcAddress("glGetBufferPointervARB");
	GLM_struct->glVertexAttrib1dARBproc = (PFNGLVERTEXATTRIB1DARBPROC)wglGetProcAddress("glVertexAttrib1dARB");
	GLM_struct->glVertexAttrib1dvARBproc = (PFNGLVERTEXATTRIB1DVARBPROC)wglGetProcAddress("glVertexAttrib1dvARB");
	GLM_struct->glVertexAttrib1fARBproc = (PFNGLVERTEXATTRIB1FARBPROC)wglGetProcAddress("glVertexAttrib1fARB");
	GLM_struct->glVertexAttrib1fvARBproc = (PFNGLVERTEXATTRIB1FVARBPROC)wglGetProcAddress("glVertexAttrib1fvARB");
	GLM_struct->glVertexAttrib1sARBproc = (PFNGLVERTEXATTRIB1SARBPROC)wglGetProcAddress("glVertexAttrib1sARB");
	GLM_struct->glVertexAttrib1svARBproc = (PFNGLVERTEXATTRIB1SVARBPROC)wglGetProcAddress("glVertexAttrib1svARB");
	GLM_struct->glVertexAttrib2dARBproc = (PFNGLVERTEXATTRIB2DARBPROC)wglGetProcAddress("glVertexAttrib2dARB");
	GLM_struct->glVertexAttrib2dvARBproc = (PFNGLVERTEXATTRIB2DVARBPROC)wglGetProcAddress("glVertexAttrib2dvARB");
	GLM_struct->glVertexAttrib2fARBproc = (PFNGLVERTEXATTRIB2FARBPROC)wglGetProcAddress("glVertexAttrib2fARB");
	GLM_struct->glVertexAttrib2fvARBproc = (PFNGLVERTEXATTRIB2FVARBPROC)wglGetProcAddress("glVertexAttrib2fvARB");
	GLM_struct->glVertexAttrib2sARBproc = (PFNGLVERTEXATTRIB2SARBPROC)wglGetProcAddress("glVertexAttrib2sARB");
	GLM_struct->glVertexAttrib2svARBproc = (PFNGLVERTEXATTRIB2SVARBPROC)wglGetProcAddress("glVertexAttrib2svARB");
	GLM_struct->glVertexAttrib3dARBproc = (PFNGLVERTEXATTRIB3DARBPROC)wglGetProcAddress("glVertexAttrib3dARB");
	GLM_struct->glVertexAttrib3dvARBproc = (PFNGLVERTEXATTRIB3DVARBPROC)wglGetProcAddress("glVertexAttrib3dvARB");
	GLM_struct->glVertexAttrib3fARBproc = (PFNGLVERTEXATTRIB3FARBPROC)wglGetProcAddress("glVertexAttrib3fARB");
	GLM_struct->glVertexAttrib3fvARBproc = (PFNGLVERTEXATTRIB3FVARBPROC)wglGetProcAddress("glVertexAttrib3fvARB");
	GLM_struct->glVertexAttrib3sARBproc = (PFNGLVERTEXATTRIB3SARBPROC)wglGetProcAddress("glVertexAttrib3sARB");
	GLM_struct->glVertexAttrib3svARBproc = (PFNGLVERTEXATTRIB3SVARBPROC)wglGetProcAddress("glVertexAttrib3svARB");
	GLM_struct->glVertexAttrib4NbvARBproc = (PFNGLVERTEXATTRIB4NBVARBPROC)wglGetProcAddress("glVertexAttrib4NbvARB");
	GLM_struct->glVertexAttrib4NivARBproc = (PFNGLVERTEXATTRIB4NIVARBPROC)wglGetProcAddress("glVertexAttrib4NivARB");
	GLM_struct->glVertexAttrib4NsvARBproc = (PFNGLVERTEXATTRIB4NSVARBPROC)wglGetProcAddress("glVertexAttrib4NsvARB");
	GLM_struct->glVertexAttrib4NubARBproc = (PFNGLVERTEXATTRIB4NUBARBPROC)wglGetProcAddress("glVertexAttrib4NubARB");
	GLM_struct->glVertexAttrib4NubvARBproc = (PFNGLVERTEXATTRIB4NUBVARBPROC)wglGetProcAddress("glVertexAttrib4NubvARB");
	GLM_struct->glVertexAttrib4NuivARBproc = (PFNGLVERTEXATTRIB4NUIVARBPROC)wglGetProcAddress("glVertexAttrib4NuivARB");
	GLM_struct->glVertexAttrib4NusvARBproc = (PFNGLVERTEXATTRIB4NUSVARBPROC)wglGetProcAddress("glVertexAttrib4NusvARB");
	GLM_struct->glVertexAttrib4bvARBproc = (PFNGLVERTEXATTRIB4BVARBPROC)wglGetProcAddress("glVertexAttrib4bvARB");
	GLM_struct->glVertexAttrib4dARBproc = (PFNGLVERTEXATTRIB4DARBPROC)wglGetProcAddress("glVertexAttrib4dARB");
	GLM_struct->glVertexAttrib4dvARBproc = (PFNGLVERTEXATTRIB4DVARBPROC)wglGetProcAddress("glVertexAttrib4dvARB");
	GLM_struct->glVertexAttrib4fARBproc = (PFNGLVERTEXATTRIB4FARBPROC)wglGetProcAddress("glVertexAttrib4fARB");
	GLM_struct->glVertexAttrib4fvARBproc = (PFNGLVERTEXATTRIB4FVARBPROC)wglGetProcAddress("glVertexAttrib4fvARB");
	GLM_struct->glVertexAttrib4ivARBproc = (PFNGLVERTEXATTRIB4IVARBPROC)wglGetProcAddress("glVertexAttrib4ivARB");
	GLM_struct->glVertexAttrib4sARBproc = (PFNGLVERTEXATTRIB4SARBPROC)wglGetProcAddress("glVertexAttrib4sARB");
	GLM_struct->glVertexAttrib4svARBproc = (PFNGLVERTEXATTRIB4SVARBPROC)wglGetProcAddress("glVertexAttrib4svARB");
	GLM_struct->glVertexAttrib4ubvARBproc = (PFNGLVERTEXATTRIB4UBVARBPROC)wglGetProcAddress("glVertexAttrib4ubvARB");
	GLM_struct->glVertexAttrib4uivARBproc = (PFNGLVERTEXATTRIB4UIVARBPROC)wglGetProcAddress("glVertexAttrib4uivARB");
	GLM_struct->glVertexAttrib4usvARBproc = (PFNGLVERTEXATTRIB4USVARBPROC)wglGetProcAddress("glVertexAttrib4usvARB");
	GLM_struct->glVertexAttribPointerARBproc = (PFNGLVERTEXATTRIBPOINTERARBPROC)wglGetProcAddress("glVertexAttribPointerARB");
	GLM_struct->glEnableVertexAttribArrayARBproc = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)wglGetProcAddress("glEnableVertexAttribArrayARB");
	GLM_struct->glDisableVertexAttribArrayARBproc = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)wglGetProcAddress("glDisableVertexAttribArrayARB");
	GLM_struct->glGetVertexAttribdvARBproc = (PFNGLGETVERTEXATTRIBDVARBPROC)wglGetProcAddress("glGetVertexAttribdvARB");
	GLM_struct->glGetVertexAttribfvARBproc = (PFNGLGETVERTEXATTRIBFVARBPROC)wglGetProcAddress("glGetVertexAttribfvARB");
	GLM_struct->glGetVertexAttribivARBproc = (PFNGLGETVERTEXATTRIBIVARBPROC)wglGetProcAddress("glGetVertexAttribivARB");
	GLM_struct->glGetVertexAttribPointervARBproc = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)wglGetProcAddress("glGetVertexAttribPointervARB");
	GLM_struct->glBindAttribLocationARBproc = (PFNGLBINDATTRIBLOCATIONARBPROC)wglGetProcAddress("glBindAttribLocationARB");
	GLM_struct->glGetActiveAttribARBproc = (PFNGLGETACTIVEATTRIBARBPROC)wglGetProcAddress("glGetActiveAttribARB");
	GLM_struct->glGetAttribLocationARBproc = (PFNGLGETATTRIBLOCATIONARBPROC)wglGetProcAddress("glGetAttribLocationARB");
	GLM_struct->glDepthRangeArraydvNVproc = (PFNGLDEPTHRANGEARRAYDVNVPROC)wglGetProcAddress("glDepthRangeArraydvNV");
	GLM_struct->glDepthRangeIndexeddNVproc = (PFNGLDEPTHRANGEINDEXEDDNVPROC)wglGetProcAddress("glDepthRangeIndexeddNV");
	GLM_struct->glWindowPos2dARBproc = (PFNGLWINDOWPOS2DARBPROC)wglGetProcAddress("glWindowPos2dARB");
	GLM_struct->glWindowPos2dvARBproc = (PFNGLWINDOWPOS2DVARBPROC)wglGetProcAddress("glWindowPos2dvARB");
	GLM_struct->glWindowPos2fARBproc = (PFNGLWINDOWPOS2FARBPROC)wglGetProcAddress("glWindowPos2fARB");
	GLM_struct->glWindowPos2fvARBproc = (PFNGLWINDOWPOS2FVARBPROC)wglGetProcAddress("glWindowPos2fvARB");
	GLM_struct->glWindowPos2iARBproc = (PFNGLWINDOWPOS2IARBPROC)wglGetProcAddress("glWindowPos2iARB");
	GLM_struct->glWindowPos2ivARBproc = (PFNGLWINDOWPOS2IVARBPROC)wglGetProcAddress("glWindowPos2ivARB");
	GLM_struct->glWindowPos2sARBproc = (PFNGLWINDOWPOS2SARBPROC)wglGetProcAddress("glWindowPos2sARB");
	GLM_struct->glWindowPos2svARBproc = (PFNGLWINDOWPOS2SVARBPROC)wglGetProcAddress("glWindowPos2svARB");
	GLM_struct->glWindowPos3dARBproc = (PFNGLWINDOWPOS3DARBPROC)wglGetProcAddress("glWindowPos3dARB");
	GLM_struct->glWindowPos3dvARBproc = (PFNGLWINDOWPOS3DVARBPROC)wglGetProcAddress("glWindowPos3dvARB");
	GLM_struct->glWindowPos3fARBproc = (PFNGLWINDOWPOS3FARBPROC)wglGetProcAddress("glWindowPos3fARB");
	GLM_struct->glWindowPos3fvARBproc = (PFNGLWINDOWPOS3FVARBPROC)wglGetProcAddress("glWindowPos3fvARB");
	GLM_struct->glWindowPos3iARBproc = (PFNGLWINDOWPOS3IARBPROC)wglGetProcAddress("glWindowPos3iARB");
	GLM_struct->glWindowPos3ivARBproc = (PFNGLWINDOWPOS3IVARBPROC)wglGetProcAddress("glWindowPos3ivARB");
	GLM_struct->glWindowPos3sARBproc = (PFNGLWINDOWPOS3SARBPROC)wglGetProcAddress("glWindowPos3sARB");
	GLM_struct->glWindowPos3svARBproc = (PFNGLWINDOWPOS3SVARBPROC)wglGetProcAddress("glWindowPos3svARB");
	GLM_struct->glBlendBarrierKHRproc = (PFNGLBLENDBARRIERKHRPROC)wglGetProcAddress("glBlendBarrierKHR");
	GLM_struct->glMaxShaderCompilerThreadsKHRproc = (PFNGLMAXSHADERCOMPILERTHREADSKHRPROC)wglGetProcAddress("glMaxShaderCompilerThreadsKHR");
	GLM_struct->glMultiTexCoord1bOESproc = (PFNGLMULTITEXCOORD1BOESPROC)wglGetProcAddress("glMultiTexCoord1bOES");
	GLM_struct->glMultiTexCoord1bvOESproc = (PFNGLMULTITEXCOORD1BVOESPROC)wglGetProcAddress("glMultiTexCoord1bvOES");
	GLM_struct->glMultiTexCoord2bOESproc = (PFNGLMULTITEXCOORD2BOESPROC)wglGetProcAddress("glMultiTexCoord2bOES");
	GLM_struct->glMultiTexCoord2bvOESproc = (PFNGLMULTITEXCOORD2BVOESPROC)wglGetProcAddress("glMultiTexCoord2bvOES");
	GLM_struct->glMultiTexCoord3bOESproc = (PFNGLMULTITEXCOORD3BOESPROC)wglGetProcAddress("glMultiTexCoord3bOES");
	GLM_struct->glMultiTexCoord3bvOESproc = (PFNGLMULTITEXCOORD3BVOESPROC)wglGetProcAddress("glMultiTexCoord3bvOES");
	GLM_struct->glMultiTexCoord4bOESproc = (PFNGLMULTITEXCOORD4BOESPROC)wglGetProcAddress("glMultiTexCoord4bOES");
	GLM_struct->glMultiTexCoord4bvOESproc = (PFNGLMULTITEXCOORD4BVOESPROC)wglGetProcAddress("glMultiTexCoord4bvOES");
	GLM_struct->glTexCoord1bOESproc = (PFNGLTEXCOORD1BOESPROC)wglGetProcAddress("glTexCoord1bOES");
	GLM_struct->glTexCoord1bvOESproc = (PFNGLTEXCOORD1BVOESPROC)wglGetProcAddress("glTexCoord1bvOES");
	GLM_struct->glTexCoord2bOESproc = (PFNGLTEXCOORD2BOESPROC)wglGetProcAddress("glTexCoord2bOES");
	GLM_struct->glTexCoord2bvOESproc = (PFNGLTEXCOORD2BVOESPROC)wglGetProcAddress("glTexCoord2bvOES");
	GLM_struct->glTexCoord3bOESproc = (PFNGLTEXCOORD3BOESPROC)wglGetProcAddress("glTexCoord3bOES");
	GLM_struct->glTexCoord3bvOESproc = (PFNGLTEXCOORD3BVOESPROC)wglGetProcAddress("glTexCoord3bvOES");
	GLM_struct->glTexCoord4bOESproc = (PFNGLTEXCOORD4BOESPROC)wglGetProcAddress("glTexCoord4bOES");
	GLM_struct->glTexCoord4bvOESproc = (PFNGLTEXCOORD4BVOESPROC)wglGetProcAddress("glTexCoord4bvOES");
	GLM_struct->glVertex2bOESproc = (PFNGLVERTEX2BOESPROC)wglGetProcAddress("glVertex2bOES");
	GLM_struct->glVertex2bvOESproc = (PFNGLVERTEX2BVOESPROC)wglGetProcAddress("glVertex2bvOES");
	GLM_struct->glVertex3bOESproc = (PFNGLVERTEX3BOESPROC)wglGetProcAddress("glVertex3bOES");
	GLM_struct->glVertex3bvOESproc = (PFNGLVERTEX3BVOESPROC)wglGetProcAddress("glVertex3bvOES");
	GLM_struct->glVertex4bOESproc = (PFNGLVERTEX4BOESPROC)wglGetProcAddress("glVertex4bOES");
	GLM_struct->glVertex4bvOESproc = (PFNGLVERTEX4BVOESPROC)wglGetProcAddress("glVertex4bvOES");
	GLM_struct->glAlphaFuncxOESproc = (PFNGLALPHAFUNCXOESPROC)wglGetProcAddress("glAlphaFuncxOES");
	GLM_struct->glClearColorxOESproc = (PFNGLCLEARCOLORXOESPROC)wglGetProcAddress("glClearColorxOES");
	GLM_struct->glClearDepthxOESproc = (PFNGLCLEARDEPTHXOESPROC)wglGetProcAddress("glClearDepthxOES");
	GLM_struct->glClipPlanexOESproc = (PFNGLCLIPPLANEXOESPROC)wglGetProcAddress("glClipPlanexOES");
	GLM_struct->glColor4xOESproc = (PFNGLCOLOR4XOESPROC)wglGetProcAddress("glColor4xOES");
	GLM_struct->glDepthRangexOESproc = (PFNGLDEPTHRANGEXOESPROC)wglGetProcAddress("glDepthRangexOES");
	GLM_struct->glFogxOESproc = (PFNGLFOGXOESPROC)wglGetProcAddress("glFogxOES");
	GLM_struct->glFogxvOESproc = (PFNGLFOGXVOESPROC)wglGetProcAddress("glFogxvOES");
	GLM_struct->glFrustumxOESproc = (PFNGLFRUSTUMXOESPROC)wglGetProcAddress("glFrustumxOES");
	GLM_struct->glGetClipPlanexOESproc = (PFNGLGETCLIPPLANEXOESPROC)wglGetProcAddress("glGetClipPlanexOES");
	GLM_struct->glGetFixedvOESproc = (PFNGLGETFIXEDVOESPROC)wglGetProcAddress("glGetFixedvOES");
	GLM_struct->glGetTexEnvxvOESproc = (PFNGLGETTEXENVXVOESPROC)wglGetProcAddress("glGetTexEnvxvOES");
	GLM_struct->glGetTexParameterxvOESproc = (PFNGLGETTEXPARAMETERXVOESPROC)wglGetProcAddress("glGetTexParameterxvOES");
	GLM_struct->glLightModelxOESproc = (PFNGLLIGHTMODELXOESPROC)wglGetProcAddress("glLightModelxOES");
	GLM_struct->glLightModelxvOESproc = (PFNGLLIGHTMODELXVOESPROC)wglGetProcAddress("glLightModelxvOES");
	GLM_struct->glLightxOESproc = (PFNGLLIGHTXOESPROC)wglGetProcAddress("glLightxOES");
	GLM_struct->glLightxvOESproc = (PFNGLLIGHTXVOESPROC)wglGetProcAddress("glLightxvOES");
	GLM_struct->glLineWidthxOESproc = (PFNGLLINEWIDTHXOESPROC)wglGetProcAddress("glLineWidthxOES");
	GLM_struct->glLoadMatrixxOESproc = (PFNGLLOADMATRIXXOESPROC)wglGetProcAddress("glLoadMatrixxOES");
	GLM_struct->glMaterialxOESproc = (PFNGLMATERIALXOESPROC)wglGetProcAddress("glMaterialxOES");
	GLM_struct->glMaterialxvOESproc = (PFNGLMATERIALXVOESPROC)wglGetProcAddress("glMaterialxvOES");
	GLM_struct->glMultMatrixxOESproc = (PFNGLMULTMATRIXXOESPROC)wglGetProcAddress("glMultMatrixxOES");
	GLM_struct->glMultiTexCoord4xOESproc = (PFNGLMULTITEXCOORD4XOESPROC)wglGetProcAddress("glMultiTexCoord4xOES");
	GLM_struct->glNormal3xOESproc = (PFNGLNORMAL3XOESPROC)wglGetProcAddress("glNormal3xOES");
	GLM_struct->glOrthoxOESproc = (PFNGLORTHOXOESPROC)wglGetProcAddress("glOrthoxOES");
	GLM_struct->glPointParameterxvOESproc = (PFNGLPOINTPARAMETERXVOESPROC)wglGetProcAddress("glPointParameterxvOES");
	GLM_struct->glPointSizexOESproc = (PFNGLPOINTSIZEXOESPROC)wglGetProcAddress("glPointSizexOES");
	GLM_struct->glPolygonOffsetxOESproc = (PFNGLPOLYGONOFFSETXOESPROC)wglGetProcAddress("glPolygonOffsetxOES");
	GLM_struct->glRotatexOESproc = (PFNGLROTATEXOESPROC)wglGetProcAddress("glRotatexOES");
	GLM_struct->glScalexOESproc = (PFNGLSCALEXOESPROC)wglGetProcAddress("glScalexOES");
	GLM_struct->glTexEnvxOESproc = (PFNGLTEXENVXOESPROC)wglGetProcAddress("glTexEnvxOES");
	GLM_struct->glTexEnvxvOESproc = (PFNGLTEXENVXVOESPROC)wglGetProcAddress("glTexEnvxvOES");
	GLM_struct->glTexParameterxOESproc = (PFNGLTEXPARAMETERXOESPROC)wglGetProcAddress("glTexParameterxOES");
	GLM_struct->glTexParameterxvOESproc = (PFNGLTEXPARAMETERXVOESPROC)wglGetProcAddress("glTexParameterxvOES");
	GLM_struct->glTranslatexOESproc = (PFNGLTRANSLATEXOESPROC)wglGetProcAddress("glTranslatexOES");
	GLM_struct->glAccumxOESproc = (PFNGLACCUMXOESPROC)wglGetProcAddress("glAccumxOES");
	GLM_struct->glBitmapxOESproc = (PFNGLBITMAPXOESPROC)wglGetProcAddress("glBitmapxOES");
	GLM_struct->glBlendColorxOESproc = (PFNGLBLENDCOLORXOESPROC)wglGetProcAddress("glBlendColorxOES");
	GLM_struct->glClearAccumxOESproc = (PFNGLCLEARACCUMXOESPROC)wglGetProcAddress("glClearAccumxOES");
	GLM_struct->glColor3xOESproc = (PFNGLCOLOR3XOESPROC)wglGetProcAddress("glColor3xOES");
	GLM_struct->glColor3xvOESproc = (PFNGLCOLOR3XVOESPROC)wglGetProcAddress("glColor3xvOES");
	GLM_struct->glColor4xvOESproc = (PFNGLCOLOR4XVOESPROC)wglGetProcAddress("glColor4xvOES");
	GLM_struct->glConvolutionParameterxOESproc = (PFNGLCONVOLUTIONPARAMETERXOESPROC)wglGetProcAddress("glConvolutionParameterxOES");
	GLM_struct->glConvolutionParameterxvOESproc = (PFNGLCONVOLUTIONPARAMETERXVOESPROC)wglGetProcAddress("glConvolutionParameterxvOES");
	GLM_struct->glEvalCoord1xOESproc = (PFNGLEVALCOORD1XOESPROC)wglGetProcAddress("glEvalCoord1xOES");
	GLM_struct->glEvalCoord1xvOESproc = (PFNGLEVALCOORD1XVOESPROC)wglGetProcAddress("glEvalCoord1xvOES");
	GLM_struct->glEvalCoord2xOESproc = (PFNGLEVALCOORD2XOESPROC)wglGetProcAddress("glEvalCoord2xOES");
	GLM_struct->glEvalCoord2xvOESproc = (PFNGLEVALCOORD2XVOESPROC)wglGetProcAddress("glEvalCoord2xvOES");
	GLM_struct->glFeedbackBufferxOESproc = (PFNGLFEEDBACKBUFFERXOESPROC)wglGetProcAddress("glFeedbackBufferxOES");
	GLM_struct->glGetConvolutionParameterxvOESproc = (PFNGLGETCONVOLUTIONPARAMETERXVOESPROC)wglGetProcAddress("glGetConvolutionParameterxvOES");
	GLM_struct->glGetHistogramParameterxvOESproc = (PFNGLGETHISTOGRAMPARAMETERXVOESPROC)wglGetProcAddress("glGetHistogramParameterxvOES");
	GLM_struct->glGetLightxOESproc = (PFNGLGETLIGHTXOESPROC)wglGetProcAddress("glGetLightxOES");
	GLM_struct->glGetMapxvOESproc = (PFNGLGETMAPXVOESPROC)wglGetProcAddress("glGetMapxvOES");
	GLM_struct->glGetMaterialxOESproc = (PFNGLGETMATERIALXOESPROC)wglGetProcAddress("glGetMaterialxOES");
	GLM_struct->glGetPixelMapxvproc = (PFNGLGETPIXELMAPXVPROC)wglGetProcAddress("glGetPixelMapxv");
	GLM_struct->glGetTexGenxvOESproc = (PFNGLGETTEXGENXVOESPROC)wglGetProcAddress("glGetTexGenxvOES");
	GLM_struct->glGetTexLevelParameterxvOESproc = (PFNGLGETTEXLEVELPARAMETERXVOESPROC)wglGetProcAddress("glGetTexLevelParameterxvOES");
	GLM_struct->glIndexxOESproc = (PFNGLINDEXXOESPROC)wglGetProcAddress("glIndexxOES");
	GLM_struct->glIndexxvOESproc = (PFNGLINDEXXVOESPROC)wglGetProcAddress("glIndexxvOES");
	GLM_struct->glLoadTransposeMatrixxOESproc = (PFNGLLOADTRANSPOSEMATRIXXOESPROC)wglGetProcAddress("glLoadTransposeMatrixxOES");
	GLM_struct->glMap1xOESproc = (PFNGLMAP1XOESPROC)wglGetProcAddress("glMap1xOES");
	GLM_struct->glMap2xOESproc = (PFNGLMAP2XOESPROC)wglGetProcAddress("glMap2xOES");
	GLM_struct->glMapGrid1xOESproc = (PFNGLMAPGRID1XOESPROC)wglGetProcAddress("glMapGrid1xOES");
	GLM_struct->glMapGrid2xOESproc = (PFNGLMAPGRID2XOESPROC)wglGetProcAddress("glMapGrid2xOES");
	GLM_struct->glMultTransposeMatrixxOESproc = (PFNGLMULTTRANSPOSEMATRIXXOESPROC)wglGetProcAddress("glMultTransposeMatrixxOES");
	GLM_struct->glMultiTexCoord1xOESproc = (PFNGLMULTITEXCOORD1XOESPROC)wglGetProcAddress("glMultiTexCoord1xOES");
	GLM_struct->glMultiTexCoord1xvOESproc = (PFNGLMULTITEXCOORD1XVOESPROC)wglGetProcAddress("glMultiTexCoord1xvOES");
	GLM_struct->glMultiTexCoord2xOESproc = (PFNGLMULTITEXCOORD2XOESPROC)wglGetProcAddress("glMultiTexCoord2xOES");
	GLM_struct->glMultiTexCoord2xvOESproc = (PFNGLMULTITEXCOORD2XVOESPROC)wglGetProcAddress("glMultiTexCoord2xvOES");
	GLM_struct->glMultiTexCoord3xOESproc = (PFNGLMULTITEXCOORD3XOESPROC)wglGetProcAddress("glMultiTexCoord3xOES");
	GLM_struct->glMultiTexCoord3xvOESproc = (PFNGLMULTITEXCOORD3XVOESPROC)wglGetProcAddress("glMultiTexCoord3xvOES");
	GLM_struct->glMultiTexCoord4xvOESproc = (PFNGLMULTITEXCOORD4XVOESPROC)wglGetProcAddress("glMultiTexCoord4xvOES");
	GLM_struct->glNormal3xvOESproc = (PFNGLNORMAL3XVOESPROC)wglGetProcAddress("glNormal3xvOES");
	GLM_struct->glPassThroughxOESproc = (PFNGLPASSTHROUGHXOESPROC)wglGetProcAddress("glPassThroughxOES");
	GLM_struct->glPixelMapxproc = (PFNGLPIXELMAPXPROC)wglGetProcAddress("glPixelMapx");
	GLM_struct->glPixelStorexproc = (PFNGLPIXELSTOREXPROC)wglGetProcAddress("glPixelStorex");
	GLM_struct->glPixelTransferxOESproc = (PFNGLPIXELTRANSFERXOESPROC)wglGetProcAddress("glPixelTransferxOES");
	GLM_struct->glPixelZoomxOESproc = (PFNGLPIXELZOOMXOESPROC)wglGetProcAddress("glPixelZoomxOES");
	GLM_struct->glPrioritizeTexturesxOESproc = (PFNGLPRIORITIZETEXTURESXOESPROC)wglGetProcAddress("glPrioritizeTexturesxOES");
	GLM_struct->glRasterPos2xOESproc = (PFNGLRASTERPOS2XOESPROC)wglGetProcAddress("glRasterPos2xOES");
	GLM_struct->glRasterPos2xvOESproc = (PFNGLRASTERPOS2XVOESPROC)wglGetProcAddress("glRasterPos2xvOES");
	GLM_struct->glRasterPos3xOESproc = (PFNGLRASTERPOS3XOESPROC)wglGetProcAddress("glRasterPos3xOES");
	GLM_struct->glRasterPos3xvOESproc = (PFNGLRASTERPOS3XVOESPROC)wglGetProcAddress("glRasterPos3xvOES");
	GLM_struct->glRasterPos4xOESproc = (PFNGLRASTERPOS4XOESPROC)wglGetProcAddress("glRasterPos4xOES");
	GLM_struct->glRasterPos4xvOESproc = (PFNGLRASTERPOS4XVOESPROC)wglGetProcAddress("glRasterPos4xvOES");
	GLM_struct->glRectxOESproc = (PFNGLRECTXOESPROC)wglGetProcAddress("glRectxOES");
	GLM_struct->glRectxvOESproc = (PFNGLRECTXVOESPROC)wglGetProcAddress("glRectxvOES");
	GLM_struct->glTexCoord1xOESproc = (PFNGLTEXCOORD1XOESPROC)wglGetProcAddress("glTexCoord1xOES");
	GLM_struct->glTexCoord1xvOESproc = (PFNGLTEXCOORD1XVOESPROC)wglGetProcAddress("glTexCoord1xvOES");
	GLM_struct->glTexCoord2xOESproc = (PFNGLTEXCOORD2XOESPROC)wglGetProcAddress("glTexCoord2xOES");
	GLM_struct->glTexCoord2xvOESproc = (PFNGLTEXCOORD2XVOESPROC)wglGetProcAddress("glTexCoord2xvOES");
	GLM_struct->glTexCoord3xOESproc = (PFNGLTEXCOORD3XOESPROC)wglGetProcAddress("glTexCoord3xOES");
	GLM_struct->glTexCoord3xvOESproc = (PFNGLTEXCOORD3XVOESPROC)wglGetProcAddress("glTexCoord3xvOES");
	GLM_struct->glTexCoord4xOESproc = (PFNGLTEXCOORD4XOESPROC)wglGetProcAddress("glTexCoord4xOES");
	GLM_struct->glTexCoord4xvOESproc = (PFNGLTEXCOORD4XVOESPROC)wglGetProcAddress("glTexCoord4xvOES");
	GLM_struct->glTexGenxOESproc = (PFNGLTEXGENXOESPROC)wglGetProcAddress("glTexGenxOES");
	GLM_struct->glTexGenxvOESproc = (PFNGLTEXGENXVOESPROC)wglGetProcAddress("glTexGenxvOES");
	GLM_struct->glVertex2xOESproc = (PFNGLVERTEX2XOESPROC)wglGetProcAddress("glVertex2xOES");
	GLM_struct->glVertex2xvOESproc = (PFNGLVERTEX2XVOESPROC)wglGetProcAddress("glVertex2xvOES");
	GLM_struct->glVertex3xOESproc = (PFNGLVERTEX3XOESPROC)wglGetProcAddress("glVertex3xOES");
	GLM_struct->glVertex3xvOESproc = (PFNGLVERTEX3XVOESPROC)wglGetProcAddress("glVertex3xvOES");
	GLM_struct->glVertex4xOESproc = (PFNGLVERTEX4XOESPROC)wglGetProcAddress("glVertex4xOES");
	GLM_struct->glVertex4xvOESproc = (PFNGLVERTEX4XVOESPROC)wglGetProcAddress("glVertex4xvOES");
	GLM_struct->glQueryMatrixxOESproc = (PFNGLQUERYMATRIXXOESPROC)wglGetProcAddress("glQueryMatrixxOES");
	GLM_struct->glClearDepthfOESproc = (PFNGLCLEARDEPTHFOESPROC)wglGetProcAddress("glClearDepthfOES");
	GLM_struct->glClipPlanefOESproc = (PFNGLCLIPPLANEFOESPROC)wglGetProcAddress("glClipPlanefOES");
	GLM_struct->glDepthRangefOESproc = (PFNGLDEPTHRANGEFOESPROC)wglGetProcAddress("glDepthRangefOES");
	GLM_struct->glFrustumfOESproc = (PFNGLFRUSTUMFOESPROC)wglGetProcAddress("glFrustumfOES");
	GLM_struct->glGetClipPlanefOESproc = (PFNGLGETCLIPPLANEFOESPROC)wglGetProcAddress("glGetClipPlanefOES");
	GLM_struct->glOrthofOESproc = (PFNGLORTHOFOESPROC)wglGetProcAddress("glOrthofOES");
	GLM_struct->glTbufferMask3DFXproc = (PFNGLTBUFFERMASK3DFXPROC)wglGetProcAddress("glTbufferMask3DFX");
	GLM_struct->glDebugMessageEnableAMDproc = (PFNGLDEBUGMESSAGEENABLEAMDPROC)wglGetProcAddress("glDebugMessageEnableAMD");
	GLM_struct->glDebugMessageInsertAMDproc = (PFNGLDEBUGMESSAGEINSERTAMDPROC)wglGetProcAddress("glDebugMessageInsertAMD");
	GLM_struct->glDebugMessageCallbackAMDproc = (PFNGLDEBUGMESSAGECALLBACKAMDPROC)wglGetProcAddress("glDebugMessageCallbackAMD");
	GLM_struct->glGetDebugMessageLogAMDproc = (PFNGLGETDEBUGMESSAGELOGAMDPROC)wglGetProcAddress("glGetDebugMessageLogAMD");
	GLM_struct->glBlendFuncIndexedAMDproc = (PFNGLBLENDFUNCINDEXEDAMDPROC)wglGetProcAddress("glBlendFuncIndexedAMD");
	GLM_struct->glBlendFuncSeparateIndexedAMDproc = (PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)wglGetProcAddress("glBlendFuncSeparateIndexedAMD");
	GLM_struct->glBlendEquationIndexedAMDproc = (PFNGLBLENDEQUATIONINDEXEDAMDPROC)wglGetProcAddress("glBlendEquationIndexedAMD");
	GLM_struct->glBlendEquationSeparateIndexedAMDproc = (PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)wglGetProcAddress("glBlendEquationSeparateIndexedAMD");
	GLM_struct->glRenderbufferStorageMultisampleAdvancedAMDproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)wglGetProcAddress("glRenderbufferStorageMultisampleAdvancedAMD");
	GLM_struct->glNamedRenderbufferStorageMultisampleAdvancedAMDproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisampleAdvancedAMD");
	GLM_struct->glFramebufferSamplePositionsfvAMDproc = (PFNGLFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC)wglGetProcAddress("glFramebufferSamplePositionsfvAMD");
	GLM_struct->glNamedFramebufferSamplePositionsfvAMDproc = (PFNGLNAMEDFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC)wglGetProcAddress("glNamedFramebufferSamplePositionsfvAMD");
	GLM_struct->glGetFramebufferParameterfvAMDproc = (PFNGLGETFRAMEBUFFERPARAMETERFVAMDPROC)wglGetProcAddress("glGetFramebufferParameterfvAMD");
	GLM_struct->glGetNamedFramebufferParameterfvAMDproc = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERFVAMDPROC)wglGetProcAddress("glGetNamedFramebufferParameterfvAMD");
	GLM_struct->glUniform1i64NVproc = (PFNGLUNIFORM1I64NVPROC)wglGetProcAddress("glUniform1i64NV");
	GLM_struct->glUniform2i64NVproc = (PFNGLUNIFORM2I64NVPROC)wglGetProcAddress("glUniform2i64NV");
	GLM_struct->glUniform3i64NVproc = (PFNGLUNIFORM3I64NVPROC)wglGetProcAddress("glUniform3i64NV");
	GLM_struct->glUniform4i64NVproc = (PFNGLUNIFORM4I64NVPROC)wglGetProcAddress("glUniform4i64NV");
	GLM_struct->glUniform1i64vNVproc = (PFNGLUNIFORM1I64VNVPROC)wglGetProcAddress("glUniform1i64vNV");
	GLM_struct->glUniform2i64vNVproc = (PFNGLUNIFORM2I64VNVPROC)wglGetProcAddress("glUniform2i64vNV");
	GLM_struct->glUniform3i64vNVproc = (PFNGLUNIFORM3I64VNVPROC)wglGetProcAddress("glUniform3i64vNV");
	GLM_struct->glUniform4i64vNVproc = (PFNGLUNIFORM4I64VNVPROC)wglGetProcAddress("glUniform4i64vNV");
	GLM_struct->glUniform1ui64NVproc = (PFNGLUNIFORM1UI64NVPROC)wglGetProcAddress("glUniform1ui64NV");
	GLM_struct->glUniform2ui64NVproc = (PFNGLUNIFORM2UI64NVPROC)wglGetProcAddress("glUniform2ui64NV");
	GLM_struct->glUniform3ui64NVproc = (PFNGLUNIFORM3UI64NVPROC)wglGetProcAddress("glUniform3ui64NV");
	GLM_struct->glUniform4ui64NVproc = (PFNGLUNIFORM4UI64NVPROC)wglGetProcAddress("glUniform4ui64NV");
	GLM_struct->glUniform1ui64vNVproc = (PFNGLUNIFORM1UI64VNVPROC)wglGetProcAddress("glUniform1ui64vNV");
	GLM_struct->glUniform2ui64vNVproc = (PFNGLUNIFORM2UI64VNVPROC)wglGetProcAddress("glUniform2ui64vNV");
	GLM_struct->glUniform3ui64vNVproc = (PFNGLUNIFORM3UI64VNVPROC)wglGetProcAddress("glUniform3ui64vNV");
	GLM_struct->glUniform4ui64vNVproc = (PFNGLUNIFORM4UI64VNVPROC)wglGetProcAddress("glUniform4ui64vNV");
	GLM_struct->glGetUniformi64vNVproc = (PFNGLGETUNIFORMI64VNVPROC)wglGetProcAddress("glGetUniformi64vNV");
	GLM_struct->glGetUniformui64vNVproc = (PFNGLGETUNIFORMUI64VNVPROC)wglGetProcAddress("glGetUniformui64vNV");
	GLM_struct->glProgramUniform1i64NVproc = (PFNGLPROGRAMUNIFORM1I64NVPROC)wglGetProcAddress("glProgramUniform1i64NV");
	GLM_struct->glProgramUniform2i64NVproc = (PFNGLPROGRAMUNIFORM2I64NVPROC)wglGetProcAddress("glProgramUniform2i64NV");
	GLM_struct->glProgramUniform3i64NVproc = (PFNGLPROGRAMUNIFORM3I64NVPROC)wglGetProcAddress("glProgramUniform3i64NV");
	GLM_struct->glProgramUniform4i64NVproc = (PFNGLPROGRAMUNIFORM4I64NVPROC)wglGetProcAddress("glProgramUniform4i64NV");
	GLM_struct->glProgramUniform1i64vNVproc = (PFNGLPROGRAMUNIFORM1I64VNVPROC)wglGetProcAddress("glProgramUniform1i64vNV");
	GLM_struct->glProgramUniform2i64vNVproc = (PFNGLPROGRAMUNIFORM2I64VNVPROC)wglGetProcAddress("glProgramUniform2i64vNV");
	GLM_struct->glProgramUniform3i64vNVproc = (PFNGLPROGRAMUNIFORM3I64VNVPROC)wglGetProcAddress("glProgramUniform3i64vNV");
	GLM_struct->glProgramUniform4i64vNVproc = (PFNGLPROGRAMUNIFORM4I64VNVPROC)wglGetProcAddress("glProgramUniform4i64vNV");
	GLM_struct->glProgramUniform1ui64NVproc = (PFNGLPROGRAMUNIFORM1UI64NVPROC)wglGetProcAddress("glProgramUniform1ui64NV");
	GLM_struct->glProgramUniform2ui64NVproc = (PFNGLPROGRAMUNIFORM2UI64NVPROC)wglGetProcAddress("glProgramUniform2ui64NV");
	GLM_struct->glProgramUniform3ui64NVproc = (PFNGLPROGRAMUNIFORM3UI64NVPROC)wglGetProcAddress("glProgramUniform3ui64NV");
	GLM_struct->glProgramUniform4ui64NVproc = (PFNGLPROGRAMUNIFORM4UI64NVPROC)wglGetProcAddress("glProgramUniform4ui64NV");
	GLM_struct->glProgramUniform1ui64vNVproc = (PFNGLPROGRAMUNIFORM1UI64VNVPROC)wglGetProcAddress("glProgramUniform1ui64vNV");
	GLM_struct->glProgramUniform2ui64vNVproc = (PFNGLPROGRAMUNIFORM2UI64VNVPROC)wglGetProcAddress("glProgramUniform2ui64vNV");
	GLM_struct->glProgramUniform3ui64vNVproc = (PFNGLPROGRAMUNIFORM3UI64VNVPROC)wglGetProcAddress("glProgramUniform3ui64vNV");
	GLM_struct->glProgramUniform4ui64vNVproc = (PFNGLPROGRAMUNIFORM4UI64VNVPROC)wglGetProcAddress("glProgramUniform4ui64vNV");
	GLM_struct->glVertexAttribParameteriAMDproc = (PFNGLVERTEXATTRIBPARAMETERIAMDPROC)wglGetProcAddress("glVertexAttribParameteriAMD");
	GLM_struct->glMultiDrawArraysIndirectAMDproc = (PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)wglGetProcAddress("glMultiDrawArraysIndirectAMD");
	GLM_struct->glMultiDrawElementsIndirectAMDproc = (PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)wglGetProcAddress("glMultiDrawElementsIndirectAMD");
	GLM_struct->glGenNamesAMDproc = (PFNGLGENNAMESAMDPROC)wglGetProcAddress("glGenNamesAMD");
	GLM_struct->glDeleteNamesAMDproc = (PFNGLDELETENAMESAMDPROC)wglGetProcAddress("glDeleteNamesAMD");
	GLM_struct->glIsNameAMDproc = (PFNGLISNAMEAMDPROC)wglGetProcAddress("glIsNameAMD");
	GLM_struct->glQueryObjectParameteruiAMDproc = (PFNGLQUERYOBJECTPARAMETERUIAMDPROC)wglGetProcAddress("glQueryObjectParameteruiAMD");
	GLM_struct->glGetPerfMonitorGroupsAMDproc = (PFNGLGETPERFMONITORGROUPSAMDPROC)wglGetProcAddress("glGetPerfMonitorGroupsAMD");
	GLM_struct->glGetPerfMonitorCountersAMDproc = (PFNGLGETPERFMONITORCOUNTERSAMDPROC)wglGetProcAddress("glGetPerfMonitorCountersAMD");
	GLM_struct->glGetPerfMonitorGroupStringAMDproc = (PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)wglGetProcAddress("glGetPerfMonitorGroupStringAMD");
	GLM_struct->glGetPerfMonitorCounterStringAMDproc = (PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)wglGetProcAddress("glGetPerfMonitorCounterStringAMD");
	GLM_struct->glGetPerfMonitorCounterInfoAMDproc = (PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)wglGetProcAddress("glGetPerfMonitorCounterInfoAMD");
	GLM_struct->glGenPerfMonitorsAMDproc = (PFNGLGENPERFMONITORSAMDPROC)wglGetProcAddress("glGenPerfMonitorsAMD");
	GLM_struct->glDeletePerfMonitorsAMDproc = (PFNGLDELETEPERFMONITORSAMDPROC)wglGetProcAddress("glDeletePerfMonitorsAMD");
	GLM_struct->glSelectPerfMonitorCountersAMDproc = (PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)wglGetProcAddress("glSelectPerfMonitorCountersAMD");
	GLM_struct->glBeginPerfMonitorAMDproc = (PFNGLBEGINPERFMONITORAMDPROC)wglGetProcAddress("glBeginPerfMonitorAMD");
	GLM_struct->glEndPerfMonitorAMDproc = (PFNGLENDPERFMONITORAMDPROC)wglGetProcAddress("glEndPerfMonitorAMD");
	GLM_struct->glGetPerfMonitorCounterDataAMDproc = (PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)wglGetProcAddress("glGetPerfMonitorCounterDataAMD");
	GLM_struct->glSetMultisamplefvAMDproc = (PFNGLSETMULTISAMPLEFVAMDPROC)wglGetProcAddress("glSetMultisamplefvAMD");
	GLM_struct->glTexStorageSparseAMDproc = (PFNGLTEXSTORAGESPARSEAMDPROC)wglGetProcAddress("glTexStorageSparseAMD");
	GLM_struct->glTextureStorageSparseAMDproc = (PFNGLTEXTURESTORAGESPARSEAMDPROC)wglGetProcAddress("glTextureStorageSparseAMD");
	GLM_struct->glStencilOpValueAMDproc = (PFNGLSTENCILOPVALUEAMDPROC)wglGetProcAddress("glStencilOpValueAMD");
	GLM_struct->glTessellationFactorAMDproc = (PFNGLTESSELLATIONFACTORAMDPROC)wglGetProcAddress("glTessellationFactorAMD");
	GLM_struct->glTessellationModeAMDproc = (PFNGLTESSELLATIONMODEAMDPROC)wglGetProcAddress("glTessellationModeAMD");
	GLM_struct->glElementPointerAPPLEproc = (PFNGLELEMENTPOINTERAPPLEPROC)wglGetProcAddress("glElementPointerAPPLE");
	GLM_struct->glDrawElementArrayAPPLEproc = (PFNGLDRAWELEMENTARRAYAPPLEPROC)wglGetProcAddress("glDrawElementArrayAPPLE");
	GLM_struct->glDrawRangeElementArrayAPPLEproc = (PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)wglGetProcAddress("glDrawRangeElementArrayAPPLE");
	GLM_struct->glMultiDrawElementArrayAPPLEproc = (PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)wglGetProcAddress("glMultiDrawElementArrayAPPLE");
	GLM_struct->glMultiDrawRangeElementArrayAPPLEproc = (PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)wglGetProcAddress("glMultiDrawRangeElementArrayAPPLE");
	GLM_struct->glGenFencesAPPLEproc = (PFNGLGENFENCESAPPLEPROC)wglGetProcAddress("glGenFencesAPPLE");
	GLM_struct->glDeleteFencesAPPLEproc = (PFNGLDELETEFENCESAPPLEPROC)wglGetProcAddress("glDeleteFencesAPPLE");
	GLM_struct->glSetFenceAPPLEproc = (PFNGLSETFENCEAPPLEPROC)wglGetProcAddress("glSetFenceAPPLE");
	GLM_struct->glIsFenceAPPLEproc = (PFNGLISFENCEAPPLEPROC)wglGetProcAddress("glIsFenceAPPLE");
	GLM_struct->glTestFenceAPPLEproc = (PFNGLTESTFENCEAPPLEPROC)wglGetProcAddress("glTestFenceAPPLE");
	GLM_struct->glFinishFenceAPPLEproc = (PFNGLFINISHFENCEAPPLEPROC)wglGetProcAddress("glFinishFenceAPPLE");
	GLM_struct->glTestObjectAPPLEproc = (PFNGLTESTOBJECTAPPLEPROC)wglGetProcAddress("glTestObjectAPPLE");
	GLM_struct->glFinishObjectAPPLEproc = (PFNGLFINISHOBJECTAPPLEPROC)wglGetProcAddress("glFinishObjectAPPLE");
	GLM_struct->glBufferParameteriAPPLEproc = (PFNGLBUFFERPARAMETERIAPPLEPROC)wglGetProcAddress("glBufferParameteriAPPLE");
	GLM_struct->glFlushMappedBufferRangeAPPLEproc = (PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)wglGetProcAddress("glFlushMappedBufferRangeAPPLE");
	GLM_struct->glObjectPurgeableAPPLEproc = (PFNGLOBJECTPURGEABLEAPPLEPROC)wglGetProcAddress("glObjectPurgeableAPPLE");
	GLM_struct->glObjectUnpurgeableAPPLEproc = (PFNGLOBJECTUNPURGEABLEAPPLEPROC)wglGetProcAddress("glObjectUnpurgeableAPPLE");
	GLM_struct->glGetObjectParameterivAPPLEproc = (PFNGLGETOBJECTPARAMETERIVAPPLEPROC)wglGetProcAddress("glGetObjectParameterivAPPLE");
	GLM_struct->glTextureRangeAPPLEproc = (PFNGLTEXTURERANGEAPPLEPROC)wglGetProcAddress("glTextureRangeAPPLE");
	GLM_struct->glGetTexParameterPointervAPPLEproc = (PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)wglGetProcAddress("glGetTexParameterPointervAPPLE");
	GLM_struct->glBindVertexArrayAPPLEproc = (PFNGLBINDVERTEXARRAYAPPLEPROC)wglGetProcAddress("glBindVertexArrayAPPLE");
	GLM_struct->glDeleteVertexArraysAPPLEproc = (PFNGLDELETEVERTEXARRAYSAPPLEPROC)wglGetProcAddress("glDeleteVertexArraysAPPLE");
	GLM_struct->glGenVertexArraysAPPLEproc = (PFNGLGENVERTEXARRAYSAPPLEPROC)wglGetProcAddress("glGenVertexArraysAPPLE");
	GLM_struct->glIsVertexArrayAPPLEproc = (PFNGLISVERTEXARRAYAPPLEPROC)wglGetProcAddress("glIsVertexArrayAPPLE");
	GLM_struct->glVertexArrayRangeAPPLEproc = (PFNGLVERTEXARRAYRANGEAPPLEPROC)wglGetProcAddress("glVertexArrayRangeAPPLE");
	GLM_struct->glFlushVertexArrayRangeAPPLEproc = (PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)wglGetProcAddress("glFlushVertexArrayRangeAPPLE");
	GLM_struct->glVertexArrayParameteriAPPLEproc = (PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)wglGetProcAddress("glVertexArrayParameteriAPPLE");
	GLM_struct->glEnableVertexAttribAPPLEproc = (PFNGLENABLEVERTEXATTRIBAPPLEPROC)wglGetProcAddress("glEnableVertexAttribAPPLE");
	GLM_struct->glDisableVertexAttribAPPLEproc = (PFNGLDISABLEVERTEXATTRIBAPPLEPROC)wglGetProcAddress("glDisableVertexAttribAPPLE");
	GLM_struct->glIsVertexAttribEnabledAPPLEproc = (PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)wglGetProcAddress("glIsVertexAttribEnabledAPPLE");
	GLM_struct->glMapVertexAttrib1dAPPLEproc = (PFNGLMAPVERTEXATTRIB1DAPPLEPROC)wglGetProcAddress("glMapVertexAttrib1dAPPLE");
	GLM_struct->glMapVertexAttrib1fAPPLEproc = (PFNGLMAPVERTEXATTRIB1FAPPLEPROC)wglGetProcAddress("glMapVertexAttrib1fAPPLE");
	GLM_struct->glMapVertexAttrib2dAPPLEproc = (PFNGLMAPVERTEXATTRIB2DAPPLEPROC)wglGetProcAddress("glMapVertexAttrib2dAPPLE");
	GLM_struct->glMapVertexAttrib2fAPPLEproc = (PFNGLMAPVERTEXATTRIB2FAPPLEPROC)wglGetProcAddress("glMapVertexAttrib2fAPPLE");
	GLM_struct->glDrawBuffersATIproc = (PFNGLDRAWBUFFERSATIPROC)wglGetProcAddress("glDrawBuffersATI");
	GLM_struct->glElementPointerATIproc = (PFNGLELEMENTPOINTERATIPROC)wglGetProcAddress("glElementPointerATI");
	GLM_struct->glDrawElementArrayATIproc = (PFNGLDRAWELEMENTARRAYATIPROC)wglGetProcAddress("glDrawElementArrayATI");
	GLM_struct->glDrawRangeElementArrayATIproc = (PFNGLDRAWRANGEELEMENTARRAYATIPROC)wglGetProcAddress("glDrawRangeElementArrayATI");
	GLM_struct->glTexBumpParameterivATIproc = (PFNGLTEXBUMPPARAMETERIVATIPROC)wglGetProcAddress("glTexBumpParameterivATI");
	GLM_struct->glTexBumpParameterfvATIproc = (PFNGLTEXBUMPPARAMETERFVATIPROC)wglGetProcAddress("glTexBumpParameterfvATI");
	GLM_struct->glGetTexBumpParameterivATIproc = (PFNGLGETTEXBUMPPARAMETERIVATIPROC)wglGetProcAddress("glGetTexBumpParameterivATI");
	GLM_struct->glGetTexBumpParameterfvATIproc = (PFNGLGETTEXBUMPPARAMETERFVATIPROC)wglGetProcAddress("glGetTexBumpParameterfvATI");
	GLM_struct->glGenFragmentShadersATIproc = (PFNGLGENFRAGMENTSHADERSATIPROC)wglGetProcAddress("glGenFragmentShadersATI");
	GLM_struct->glBindFragmentShaderATIproc = (PFNGLBINDFRAGMENTSHADERATIPROC)wglGetProcAddress("glBindFragmentShaderATI");
	GLM_struct->glDeleteFragmentShaderATIproc = (PFNGLDELETEFRAGMENTSHADERATIPROC)wglGetProcAddress("glDeleteFragmentShaderATI");
	GLM_struct->glBeginFragmentShaderATIproc = (PFNGLBEGINFRAGMENTSHADERATIPROC)wglGetProcAddress("glBeginFragmentShaderATI");
	GLM_struct->glEndFragmentShaderATIproc = (PFNGLENDFRAGMENTSHADERATIPROC)wglGetProcAddress("glEndFragmentShaderATI");
	GLM_struct->glPassTexCoordATIproc = (PFNGLPASSTEXCOORDATIPROC)wglGetProcAddress("glPassTexCoordATI");
	GLM_struct->glSampleMapATIproc = (PFNGLSAMPLEMAPATIPROC)wglGetProcAddress("glSampleMapATI");
	GLM_struct->glColorFragmentOp1ATIproc = (PFNGLCOLORFRAGMENTOP1ATIPROC)wglGetProcAddress("glColorFragmentOp1ATI");
	GLM_struct->glColorFragmentOp2ATIproc = (PFNGLCOLORFRAGMENTOP2ATIPROC)wglGetProcAddress("glColorFragmentOp2ATI");
	GLM_struct->glColorFragmentOp3ATIproc = (PFNGLCOLORFRAGMENTOP3ATIPROC)wglGetProcAddress("glColorFragmentOp3ATI");
	GLM_struct->glAlphaFragmentOp1ATIproc = (PFNGLALPHAFRAGMENTOP1ATIPROC)wglGetProcAddress("glAlphaFragmentOp1ATI");
	GLM_struct->glAlphaFragmentOp2ATIproc = (PFNGLALPHAFRAGMENTOP2ATIPROC)wglGetProcAddress("glAlphaFragmentOp2ATI");
	GLM_struct->glAlphaFragmentOp3ATIproc = (PFNGLALPHAFRAGMENTOP3ATIPROC)wglGetProcAddress("glAlphaFragmentOp3ATI");
	GLM_struct->glSetFragmentShaderConstantATIproc = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)wglGetProcAddress("glSetFragmentShaderConstantATI");
	GLM_struct->glMapObjectBufferATIproc = (PFNGLMAPOBJECTBUFFERATIPROC)wglGetProcAddress("glMapObjectBufferATI");
	GLM_struct->glUnmapObjectBufferATIproc = (PFNGLUNMAPOBJECTBUFFERATIPROC)wglGetProcAddress("glUnmapObjectBufferATI");
	GLM_struct->glPNTrianglesiATIproc = (PFNGLPNTRIANGLESIATIPROC)wglGetProcAddress("glPNTrianglesiATI");
	GLM_struct->glPNTrianglesfATIproc = (PFNGLPNTRIANGLESFATIPROC)wglGetProcAddress("glPNTrianglesfATI");
	GLM_struct->glStencilOpSeparateATIproc = (PFNGLSTENCILOPSEPARATEATIPROC)wglGetProcAddress("glStencilOpSeparateATI");
	GLM_struct->glStencilFuncSeparateATIproc = (PFNGLSTENCILFUNCSEPARATEATIPROC)wglGetProcAddress("glStencilFuncSeparateATI");
	GLM_struct->glNewObjectBufferATIproc = (PFNGLNEWOBJECTBUFFERATIPROC)wglGetProcAddress("glNewObjectBufferATI");
	GLM_struct->glIsObjectBufferATIproc = (PFNGLISOBJECTBUFFERATIPROC)wglGetProcAddress("glIsObjectBufferATI");
	GLM_struct->glUpdateObjectBufferATIproc = (PFNGLUPDATEOBJECTBUFFERATIPROC)wglGetProcAddress("glUpdateObjectBufferATI");
	GLM_struct->glGetObjectBufferfvATIproc = (PFNGLGETOBJECTBUFFERFVATIPROC)wglGetProcAddress("glGetObjectBufferfvATI");
	GLM_struct->glGetObjectBufferivATIproc = (PFNGLGETOBJECTBUFFERIVATIPROC)wglGetProcAddress("glGetObjectBufferivATI");
	GLM_struct->glFreeObjectBufferATIproc = (PFNGLFREEOBJECTBUFFERATIPROC)wglGetProcAddress("glFreeObjectBufferATI");
	GLM_struct->glArrayObjectATIproc = (PFNGLARRAYOBJECTATIPROC)wglGetProcAddress("glArrayObjectATI");
	GLM_struct->glGetArrayObjectfvATIproc = (PFNGLGETARRAYOBJECTFVATIPROC)wglGetProcAddress("glGetArrayObjectfvATI");
	GLM_struct->glGetArrayObjectivATIproc = (PFNGLGETARRAYOBJECTIVATIPROC)wglGetProcAddress("glGetArrayObjectivATI");
	GLM_struct->glVariantArrayObjectATIproc = (PFNGLVARIANTARRAYOBJECTATIPROC)wglGetProcAddress("glVariantArrayObjectATI");
	GLM_struct->glGetVariantArrayObjectfvATIproc = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC)wglGetProcAddress("glGetVariantArrayObjectfvATI");
	GLM_struct->glGetVariantArrayObjectivATIproc = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC)wglGetProcAddress("glGetVariantArrayObjectivATI");
	GLM_struct->glVertexAttribArrayObjectATIproc = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)wglGetProcAddress("glVertexAttribArrayObjectATI");
	GLM_struct->glGetVertexAttribArrayObjectfvATIproc = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)wglGetProcAddress("glGetVertexAttribArrayObjectfvATI");
	GLM_struct->glGetVertexAttribArrayObjectivATIproc = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)wglGetProcAddress("glGetVertexAttribArrayObjectivATI");
	GLM_struct->glVertexStream1sATIproc = (PFNGLVERTEXSTREAM1SATIPROC)wglGetProcAddress("glVertexStream1sATI");
	GLM_struct->glVertexStream1svATIproc = (PFNGLVERTEXSTREAM1SVATIPROC)wglGetProcAddress("glVertexStream1svATI");
	GLM_struct->glVertexStream1iATIproc = (PFNGLVERTEXSTREAM1IATIPROC)wglGetProcAddress("glVertexStream1iATI");
	GLM_struct->glVertexStream1ivATIproc = (PFNGLVERTEXSTREAM1IVATIPROC)wglGetProcAddress("glVertexStream1ivATI");
	GLM_struct->glVertexStream1fATIproc = (PFNGLVERTEXSTREAM1FATIPROC)wglGetProcAddress("glVertexStream1fATI");
	GLM_struct->glVertexStream1fvATIproc = (PFNGLVERTEXSTREAM1FVATIPROC)wglGetProcAddress("glVertexStream1fvATI");
	GLM_struct->glVertexStream1dATIproc = (PFNGLVERTEXSTREAM1DATIPROC)wglGetProcAddress("glVertexStream1dATI");
	GLM_struct->glVertexStream1dvATIproc = (PFNGLVERTEXSTREAM1DVATIPROC)wglGetProcAddress("glVertexStream1dvATI");
	GLM_struct->glVertexStream2sATIproc = (PFNGLVERTEXSTREAM2SATIPROC)wglGetProcAddress("glVertexStream2sATI");
	GLM_struct->glVertexStream2svATIproc = (PFNGLVERTEXSTREAM2SVATIPROC)wglGetProcAddress("glVertexStream2svATI");
	GLM_struct->glVertexStream2iATIproc = (PFNGLVERTEXSTREAM2IATIPROC)wglGetProcAddress("glVertexStream2iATI");
	GLM_struct->glVertexStream2ivATIproc = (PFNGLVERTEXSTREAM2IVATIPROC)wglGetProcAddress("glVertexStream2ivATI");
	GLM_struct->glVertexStream2fATIproc = (PFNGLVERTEXSTREAM2FATIPROC)wglGetProcAddress("glVertexStream2fATI");
	GLM_struct->glVertexStream2fvATIproc = (PFNGLVERTEXSTREAM2FVATIPROC)wglGetProcAddress("glVertexStream2fvATI");
	GLM_struct->glVertexStream2dATIproc = (PFNGLVERTEXSTREAM2DATIPROC)wglGetProcAddress("glVertexStream2dATI");
	GLM_struct->glVertexStream2dvATIproc = (PFNGLVERTEXSTREAM2DVATIPROC)wglGetProcAddress("glVertexStream2dvATI");
	GLM_struct->glVertexStream3sATIproc = (PFNGLVERTEXSTREAM3SATIPROC)wglGetProcAddress("glVertexStream3sATI");
	GLM_struct->glVertexStream3svATIproc = (PFNGLVERTEXSTREAM3SVATIPROC)wglGetProcAddress("glVertexStream3svATI");
	GLM_struct->glVertexStream3iATIproc = (PFNGLVERTEXSTREAM3IATIPROC)wglGetProcAddress("glVertexStream3iATI");
	GLM_struct->glVertexStream3ivATIproc = (PFNGLVERTEXSTREAM3IVATIPROC)wglGetProcAddress("glVertexStream3ivATI");
	GLM_struct->glVertexStream3fATIproc = (PFNGLVERTEXSTREAM3FATIPROC)wglGetProcAddress("glVertexStream3fATI");
	GLM_struct->glVertexStream3fvATIproc = (PFNGLVERTEXSTREAM3FVATIPROC)wglGetProcAddress("glVertexStream3fvATI");
	GLM_struct->glVertexStream3dATIproc = (PFNGLVERTEXSTREAM3DATIPROC)wglGetProcAddress("glVertexStream3dATI");
	GLM_struct->glVertexStream3dvATIproc = (PFNGLVERTEXSTREAM3DVATIPROC)wglGetProcAddress("glVertexStream3dvATI");
	GLM_struct->glVertexStream4sATIproc = (PFNGLVERTEXSTREAM4SATIPROC)wglGetProcAddress("glVertexStream4sATI");
	GLM_struct->glVertexStream4svATIproc = (PFNGLVERTEXSTREAM4SVATIPROC)wglGetProcAddress("glVertexStream4svATI");
	GLM_struct->glVertexStream4iATIproc = (PFNGLVERTEXSTREAM4IATIPROC)wglGetProcAddress("glVertexStream4iATI");
	GLM_struct->glVertexStream4ivATIproc = (PFNGLVERTEXSTREAM4IVATIPROC)wglGetProcAddress("glVertexStream4ivATI");
	GLM_struct->glVertexStream4fATIproc = (PFNGLVERTEXSTREAM4FATIPROC)wglGetProcAddress("glVertexStream4fATI");
	GLM_struct->glVertexStream4fvATIproc = (PFNGLVERTEXSTREAM4FVATIPROC)wglGetProcAddress("glVertexStream4fvATI");
	GLM_struct->glVertexStream4dATIproc = (PFNGLVERTEXSTREAM4DATIPROC)wglGetProcAddress("glVertexStream4dATI");
	GLM_struct->glVertexStream4dvATIproc = (PFNGLVERTEXSTREAM4DVATIPROC)wglGetProcAddress("glVertexStream4dvATI");
	GLM_struct->glNormalStream3bATIproc = (PFNGLNORMALSTREAM3BATIPROC)wglGetProcAddress("glNormalStream3bATI");
	GLM_struct->glNormalStream3bvATIproc = (PFNGLNORMALSTREAM3BVATIPROC)wglGetProcAddress("glNormalStream3bvATI");
	GLM_struct->glNormalStream3sATIproc = (PFNGLNORMALSTREAM3SATIPROC)wglGetProcAddress("glNormalStream3sATI");
	GLM_struct->glNormalStream3svATIproc = (PFNGLNORMALSTREAM3SVATIPROC)wglGetProcAddress("glNormalStream3svATI");
	GLM_struct->glNormalStream3iATIproc = (PFNGLNORMALSTREAM3IATIPROC)wglGetProcAddress("glNormalStream3iATI");
	GLM_struct->glNormalStream3ivATIproc = (PFNGLNORMALSTREAM3IVATIPROC)wglGetProcAddress("glNormalStream3ivATI");
	GLM_struct->glNormalStream3fATIproc = (PFNGLNORMALSTREAM3FATIPROC)wglGetProcAddress("glNormalStream3fATI");
	GLM_struct->glNormalStream3fvATIproc = (PFNGLNORMALSTREAM3FVATIPROC)wglGetProcAddress("glNormalStream3fvATI");
	GLM_struct->glNormalStream3dATIproc = (PFNGLNORMALSTREAM3DATIPROC)wglGetProcAddress("glNormalStream3dATI");
	GLM_struct->glNormalStream3dvATIproc = (PFNGLNORMALSTREAM3DVATIPROC)wglGetProcAddress("glNormalStream3dvATI");
	GLM_struct->glClientActiveVertexStreamATIproc = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)wglGetProcAddress("glClientActiveVertexStreamATI");
	GLM_struct->glVertexBlendEnviATIproc = (PFNGLVERTEXBLENDENVIATIPROC)wglGetProcAddress("glVertexBlendEnviATI");
	GLM_struct->glVertexBlendEnvfATIproc = (PFNGLVERTEXBLENDENVFATIPROC)wglGetProcAddress("glVertexBlendEnvfATI");
	GLM_struct->glEGLImageTargetTexStorageEXTproc = (PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC)wglGetProcAddress("glEGLImageTargetTexStorageEXT");
	GLM_struct->glEGLImageTargetTextureStorageEXTproc = (PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC)wglGetProcAddress("glEGLImageTargetTextureStorageEXT");
	GLM_struct->glUniformBufferEXTproc = (PFNGLUNIFORMBUFFEREXTPROC)wglGetProcAddress("glUniformBufferEXT");
	GLM_struct->glGetUniformBufferSizeEXTproc = (PFNGLGETUNIFORMBUFFERSIZEEXTPROC)wglGetProcAddress("glGetUniformBufferSizeEXT");
	GLM_struct->glGetUniformOffsetEXTproc = (PFNGLGETUNIFORMOFFSETEXTPROC)wglGetProcAddress("glGetUniformOffsetEXT");
	GLM_struct->glBlendColorEXTproc = (PFNGLBLENDCOLOREXTPROC)wglGetProcAddress("glBlendColorEXT");
	GLM_struct->glBlendEquationSeparateEXTproc = (PFNGLBLENDEQUATIONSEPARATEEXTPROC)wglGetProcAddress("glBlendEquationSeparateEXT");
	GLM_struct->glBlendFuncSeparateEXTproc = (PFNGLBLENDFUNCSEPARATEEXTPROC)wglGetProcAddress("glBlendFuncSeparateEXT");
	GLM_struct->glBlendEquationEXTproc = (PFNGLBLENDEQUATIONEXTPROC)wglGetProcAddress("glBlendEquationEXT");
	GLM_struct->glColorSubTableEXTproc = (PFNGLCOLORSUBTABLEEXTPROC)wglGetProcAddress("glColorSubTableEXT");
	GLM_struct->glCopyColorSubTableEXTproc = (PFNGLCOPYCOLORSUBTABLEEXTPROC)wglGetProcAddress("glCopyColorSubTableEXT");
	GLM_struct->glLockArraysEXTproc = (PFNGLLOCKARRAYSEXTPROC)wglGetProcAddress("glLockArraysEXT");
	GLM_struct->glUnlockArraysEXTproc = (PFNGLUNLOCKARRAYSEXTPROC)wglGetProcAddress("glUnlockArraysEXT");
	GLM_struct->glConvolutionFilter1DEXTproc = (PFNGLCONVOLUTIONFILTER1DEXTPROC)wglGetProcAddress("glConvolutionFilter1DEXT");
	GLM_struct->glConvolutionFilter2DEXTproc = (PFNGLCONVOLUTIONFILTER2DEXTPROC)wglGetProcAddress("glConvolutionFilter2DEXT");
	GLM_struct->glConvolutionParameterfEXTproc = (PFNGLCONVOLUTIONPARAMETERFEXTPROC)wglGetProcAddress("glConvolutionParameterfEXT");
	GLM_struct->glConvolutionParameterfvEXTproc = (PFNGLCONVOLUTIONPARAMETERFVEXTPROC)wglGetProcAddress("glConvolutionParameterfvEXT");
	GLM_struct->glConvolutionParameteriEXTproc = (PFNGLCONVOLUTIONPARAMETERIEXTPROC)wglGetProcAddress("glConvolutionParameteriEXT");
	GLM_struct->glConvolutionParameterivEXTproc = (PFNGLCONVOLUTIONPARAMETERIVEXTPROC)wglGetProcAddress("glConvolutionParameterivEXT");
	GLM_struct->glCopyConvolutionFilter1DEXTproc = (PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)wglGetProcAddress("glCopyConvolutionFilter1DEXT");
	GLM_struct->glCopyConvolutionFilter2DEXTproc = (PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)wglGetProcAddress("glCopyConvolutionFilter2DEXT");
	GLM_struct->glGetConvolutionFilterEXTproc = (PFNGLGETCONVOLUTIONFILTEREXTPROC)wglGetProcAddress("glGetConvolutionFilterEXT");
	GLM_struct->glGetConvolutionParameterfvEXTproc = (PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)wglGetProcAddress("glGetConvolutionParameterfvEXT");
	GLM_struct->glGetConvolutionParameterivEXTproc = (PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)wglGetProcAddress("glGetConvolutionParameterivEXT");
	GLM_struct->glGetSeparableFilterEXTproc = (PFNGLGETSEPARABLEFILTEREXTPROC)wglGetProcAddress("glGetSeparableFilterEXT");
	GLM_struct->glSeparableFilter2DEXTproc = (PFNGLSEPARABLEFILTER2DEXTPROC)wglGetProcAddress("glSeparableFilter2DEXT");
	GLM_struct->glTangent3bEXTproc = (PFNGLTANGENT3BEXTPROC)wglGetProcAddress("glTangent3bEXT");
	GLM_struct->glTangent3bvEXTproc = (PFNGLTANGENT3BVEXTPROC)wglGetProcAddress("glTangent3bvEXT");
	GLM_struct->glTangent3dEXTproc = (PFNGLTANGENT3DEXTPROC)wglGetProcAddress("glTangent3dEXT");
	GLM_struct->glTangent3dvEXTproc = (PFNGLTANGENT3DVEXTPROC)wglGetProcAddress("glTangent3dvEXT");
	GLM_struct->glTangent3fEXTproc = (PFNGLTANGENT3FEXTPROC)wglGetProcAddress("glTangent3fEXT");
	GLM_struct->glTangent3fvEXTproc = (PFNGLTANGENT3FVEXTPROC)wglGetProcAddress("glTangent3fvEXT");
	GLM_struct->glTangent3iEXTproc = (PFNGLTANGENT3IEXTPROC)wglGetProcAddress("glTangent3iEXT");
	GLM_struct->glTangent3ivEXTproc = (PFNGLTANGENT3IVEXTPROC)wglGetProcAddress("glTangent3ivEXT");
	GLM_struct->glTangent3sEXTproc = (PFNGLTANGENT3SEXTPROC)wglGetProcAddress("glTangent3sEXT");
	GLM_struct->glTangent3svEXTproc = (PFNGLTANGENT3SVEXTPROC)wglGetProcAddress("glTangent3svEXT");
	GLM_struct->glBinormal3bEXTproc = (PFNGLBINORMAL3BEXTPROC)wglGetProcAddress("glBinormal3bEXT");
	GLM_struct->glBinormal3bvEXTproc = (PFNGLBINORMAL3BVEXTPROC)wglGetProcAddress("glBinormal3bvEXT");
	GLM_struct->glBinormal3dEXTproc = (PFNGLBINORMAL3DEXTPROC)wglGetProcAddress("glBinormal3dEXT");
	GLM_struct->glBinormal3dvEXTproc = (PFNGLBINORMAL3DVEXTPROC)wglGetProcAddress("glBinormal3dvEXT");
	GLM_struct->glBinormal3fEXTproc = (PFNGLBINORMAL3FEXTPROC)wglGetProcAddress("glBinormal3fEXT");
	GLM_struct->glBinormal3fvEXTproc = (PFNGLBINORMAL3FVEXTPROC)wglGetProcAddress("glBinormal3fvEXT");
	GLM_struct->glBinormal3iEXTproc = (PFNGLBINORMAL3IEXTPROC)wglGetProcAddress("glBinormal3iEXT");
	GLM_struct->glBinormal3ivEXTproc = (PFNGLBINORMAL3IVEXTPROC)wglGetProcAddress("glBinormal3ivEXT");
	GLM_struct->glBinormal3sEXTproc = (PFNGLBINORMAL3SEXTPROC)wglGetProcAddress("glBinormal3sEXT");
	GLM_struct->glBinormal3svEXTproc = (PFNGLBINORMAL3SVEXTPROC)wglGetProcAddress("glBinormal3svEXT");
	GLM_struct->glTangentPointerEXTproc = (PFNGLTANGENTPOINTEREXTPROC)wglGetProcAddress("glTangentPointerEXT");
	GLM_struct->glBinormalPointerEXTproc = (PFNGLBINORMALPOINTEREXTPROC)wglGetProcAddress("glBinormalPointerEXT");
	GLM_struct->glCopyTexImage1DEXTproc = (PFNGLCOPYTEXIMAGE1DEXTPROC)wglGetProcAddress("glCopyTexImage1DEXT");
	GLM_struct->glCopyTexImage2DEXTproc = (PFNGLCOPYTEXIMAGE2DEXTPROC)wglGetProcAddress("glCopyTexImage2DEXT");
	GLM_struct->glCopyTexSubImage1DEXTproc = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glCopyTexSubImage1DEXT");
	GLM_struct->glCopyTexSubImage2DEXTproc = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glCopyTexSubImage2DEXT");
	GLM_struct->glCopyTexSubImage3DEXTproc = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glCopyTexSubImage3DEXT");
	GLM_struct->glCullParameterdvEXTproc = (PFNGLCULLPARAMETERDVEXTPROC)wglGetProcAddress("glCullParameterdvEXT");
	GLM_struct->glCullParameterfvEXTproc = (PFNGLCULLPARAMETERFVEXTPROC)wglGetProcAddress("glCullParameterfvEXT");
	GLM_struct->glLabelObjectEXTproc = (PFNGLLABELOBJECTEXTPROC)wglGetProcAddress("glLabelObjectEXT");
	GLM_struct->glGetObjectLabelEXTproc = (PFNGLGETOBJECTLABELEXTPROC)wglGetProcAddress("glGetObjectLabelEXT");
	GLM_struct->glInsertEventMarkerEXTproc = (PFNGLINSERTEVENTMARKEREXTPROC)wglGetProcAddress("glInsertEventMarkerEXT");
	GLM_struct->glPushGroupMarkerEXTproc = (PFNGLPUSHGROUPMARKEREXTPROC)wglGetProcAddress("glPushGroupMarkerEXT");
	GLM_struct->glPopGroupMarkerEXTproc = (PFNGLPOPGROUPMARKEREXTPROC)wglGetProcAddress("glPopGroupMarkerEXT");
	GLM_struct->glDepthBoundsEXTproc = (PFNGLDEPTHBOUNDSEXTPROC)wglGetProcAddress("glDepthBoundsEXT");
	GLM_struct->glMatrixLoadfEXTproc = (PFNGLMATRIXLOADFEXTPROC)wglGetProcAddress("glMatrixLoadfEXT");
	GLM_struct->glMatrixLoaddEXTproc = (PFNGLMATRIXLOADDEXTPROC)wglGetProcAddress("glMatrixLoaddEXT");
	GLM_struct->glMatrixMultfEXTproc = (PFNGLMATRIXMULTFEXTPROC)wglGetProcAddress("glMatrixMultfEXT");
	GLM_struct->glMatrixMultdEXTproc = (PFNGLMATRIXMULTDEXTPROC)wglGetProcAddress("glMatrixMultdEXT");
	GLM_struct->glMatrixLoadIdentityEXTproc = (PFNGLMATRIXLOADIDENTITYEXTPROC)wglGetProcAddress("glMatrixLoadIdentityEXT");
	GLM_struct->glMatrixRotatefEXTproc = (PFNGLMATRIXROTATEFEXTPROC)wglGetProcAddress("glMatrixRotatefEXT");
	GLM_struct->glMatrixRotatedEXTproc = (PFNGLMATRIXROTATEDEXTPROC)wglGetProcAddress("glMatrixRotatedEXT");
	GLM_struct->glMatrixScalefEXTproc = (PFNGLMATRIXSCALEFEXTPROC)wglGetProcAddress("glMatrixScalefEXT");
	GLM_struct->glMatrixScaledEXTproc = (PFNGLMATRIXSCALEDEXTPROC)wglGetProcAddress("glMatrixScaledEXT");
	GLM_struct->glMatrixTranslatefEXTproc = (PFNGLMATRIXTRANSLATEFEXTPROC)wglGetProcAddress("glMatrixTranslatefEXT");
	GLM_struct->glMatrixTranslatedEXTproc = (PFNGLMATRIXTRANSLATEDEXTPROC)wglGetProcAddress("glMatrixTranslatedEXT");
	GLM_struct->glMatrixFrustumEXTproc = (PFNGLMATRIXFRUSTUMEXTPROC)wglGetProcAddress("glMatrixFrustumEXT");
	GLM_struct->glMatrixOrthoEXTproc = (PFNGLMATRIXORTHOEXTPROC)wglGetProcAddress("glMatrixOrthoEXT");
	GLM_struct->glMatrixPopEXTproc = (PFNGLMATRIXPOPEXTPROC)wglGetProcAddress("glMatrixPopEXT");
	GLM_struct->glMatrixPushEXTproc = (PFNGLMATRIXPUSHEXTPROC)wglGetProcAddress("glMatrixPushEXT");
	GLM_struct->glClientAttribDefaultEXTproc = (PFNGLCLIENTATTRIBDEFAULTEXTPROC)wglGetProcAddress("glClientAttribDefaultEXT");
	GLM_struct->glPushClientAttribDefaultEXTproc = (PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)wglGetProcAddress("glPushClientAttribDefaultEXT");
	GLM_struct->glTextureParameterfEXTproc = (PFNGLTEXTUREPARAMETERFEXTPROC)wglGetProcAddress("glTextureParameterfEXT");
	GLM_struct->glTextureParameterfvEXTproc = (PFNGLTEXTUREPARAMETERFVEXTPROC)wglGetProcAddress("glTextureParameterfvEXT");
	GLM_struct->glTextureParameteriEXTproc = (PFNGLTEXTUREPARAMETERIEXTPROC)wglGetProcAddress("glTextureParameteriEXT");
	GLM_struct->glTextureParameterivEXTproc = (PFNGLTEXTUREPARAMETERIVEXTPROC)wglGetProcAddress("glTextureParameterivEXT");
	GLM_struct->glTextureImage1DEXTproc = (PFNGLTEXTUREIMAGE1DEXTPROC)wglGetProcAddress("glTextureImage1DEXT");
	GLM_struct->glTextureImage2DEXTproc = (PFNGLTEXTUREIMAGE2DEXTPROC)wglGetProcAddress("glTextureImage2DEXT");
	GLM_struct->glTextureSubImage1DEXTproc = (PFNGLTEXTURESUBIMAGE1DEXTPROC)wglGetProcAddress("glTextureSubImage1DEXT");
	GLM_struct->glTextureSubImage2DEXTproc = (PFNGLTEXTURESUBIMAGE2DEXTPROC)wglGetProcAddress("glTextureSubImage2DEXT");
	GLM_struct->glCopyTextureImage1DEXTproc = (PFNGLCOPYTEXTUREIMAGE1DEXTPROC)wglGetProcAddress("glCopyTextureImage1DEXT");
	GLM_struct->glCopyTextureImage2DEXTproc = (PFNGLCOPYTEXTUREIMAGE2DEXTPROC)wglGetProcAddress("glCopyTextureImage2DEXT");
	GLM_struct->glCopyTextureSubImage1DEXTproc = (PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)wglGetProcAddress("glCopyTextureSubImage1DEXT");
	GLM_struct->glCopyTextureSubImage2DEXTproc = (PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)wglGetProcAddress("glCopyTextureSubImage2DEXT");
	GLM_struct->glGetTextureImageEXTproc = (PFNGLGETTEXTUREIMAGEEXTPROC)wglGetProcAddress("glGetTextureImageEXT");
	GLM_struct->glGetTextureParameterfvEXTproc = (PFNGLGETTEXTUREPARAMETERFVEXTPROC)wglGetProcAddress("glGetTextureParameterfvEXT");
	GLM_struct->glGetTextureParameterivEXTproc = (PFNGLGETTEXTUREPARAMETERIVEXTPROC)wglGetProcAddress("glGetTextureParameterivEXT");
	GLM_struct->glGetTextureLevelParameterfvEXTproc = (PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)wglGetProcAddress("glGetTextureLevelParameterfvEXT");
	GLM_struct->glGetTextureLevelParameterivEXTproc = (PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)wglGetProcAddress("glGetTextureLevelParameterivEXT");
	GLM_struct->glTextureImage3DEXTproc = (PFNGLTEXTUREIMAGE3DEXTPROC)wglGetProcAddress("glTextureImage3DEXT");
	GLM_struct->glTextureSubImage3DEXTproc = (PFNGLTEXTURESUBIMAGE3DEXTPROC)wglGetProcAddress("glTextureSubImage3DEXT");
	GLM_struct->glCopyTextureSubImage3DEXTproc = (PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)wglGetProcAddress("glCopyTextureSubImage3DEXT");
	GLM_struct->glBindMultiTextureEXTproc = (PFNGLBINDMULTITEXTUREEXTPROC)wglGetProcAddress("glBindMultiTextureEXT");
	GLM_struct->glMultiTexCoordPointerEXTproc = (PFNGLMULTITEXCOORDPOINTEREXTPROC)wglGetProcAddress("glMultiTexCoordPointerEXT");
	GLM_struct->glMultiTexEnvfEXTproc = (PFNGLMULTITEXENVFEXTPROC)wglGetProcAddress("glMultiTexEnvfEXT");
	GLM_struct->glMultiTexEnvfvEXTproc = (PFNGLMULTITEXENVFVEXTPROC)wglGetProcAddress("glMultiTexEnvfvEXT");
	GLM_struct->glMultiTexEnviEXTproc = (PFNGLMULTITEXENVIEXTPROC)wglGetProcAddress("glMultiTexEnviEXT");
	GLM_struct->glMultiTexEnvivEXTproc = (PFNGLMULTITEXENVIVEXTPROC)wglGetProcAddress("glMultiTexEnvivEXT");
	GLM_struct->glMultiTexGendEXTproc = (PFNGLMULTITEXGENDEXTPROC)wglGetProcAddress("glMultiTexGendEXT");
	GLM_struct->glMultiTexGendvEXTproc = (PFNGLMULTITEXGENDVEXTPROC)wglGetProcAddress("glMultiTexGendvEXT");
	GLM_struct->glMultiTexGenfEXTproc = (PFNGLMULTITEXGENFEXTPROC)wglGetProcAddress("glMultiTexGenfEXT");
	GLM_struct->glMultiTexGenfvEXTproc = (PFNGLMULTITEXGENFVEXTPROC)wglGetProcAddress("glMultiTexGenfvEXT");
	GLM_struct->glMultiTexGeniEXTproc = (PFNGLMULTITEXGENIEXTPROC)wglGetProcAddress("glMultiTexGeniEXT");
	GLM_struct->glMultiTexGenivEXTproc = (PFNGLMULTITEXGENIVEXTPROC)wglGetProcAddress("glMultiTexGenivEXT");
	GLM_struct->glGetMultiTexEnvfvEXTproc = (PFNGLGETMULTITEXENVFVEXTPROC)wglGetProcAddress("glGetMultiTexEnvfvEXT");
	GLM_struct->glGetMultiTexEnvivEXTproc = (PFNGLGETMULTITEXENVIVEXTPROC)wglGetProcAddress("glGetMultiTexEnvivEXT");
	GLM_struct->glGetMultiTexGendvEXTproc = (PFNGLGETMULTITEXGENDVEXTPROC)wglGetProcAddress("glGetMultiTexGendvEXT");
	GLM_struct->glGetMultiTexGenfvEXTproc = (PFNGLGETMULTITEXGENFVEXTPROC)wglGetProcAddress("glGetMultiTexGenfvEXT");
	GLM_struct->glGetMultiTexGenivEXTproc = (PFNGLGETMULTITEXGENIVEXTPROC)wglGetProcAddress("glGetMultiTexGenivEXT");
	GLM_struct->glMultiTexParameteriEXTproc = (PFNGLMULTITEXPARAMETERIEXTPROC)wglGetProcAddress("glMultiTexParameteriEXT");
	GLM_struct->glMultiTexParameterivEXTproc = (PFNGLMULTITEXPARAMETERIVEXTPROC)wglGetProcAddress("glMultiTexParameterivEXT");
	GLM_struct->glMultiTexParameterfEXTproc = (PFNGLMULTITEXPARAMETERFEXTPROC)wglGetProcAddress("glMultiTexParameterfEXT");
	GLM_struct->glMultiTexParameterfvEXTproc = (PFNGLMULTITEXPARAMETERFVEXTPROC)wglGetProcAddress("glMultiTexParameterfvEXT");
	GLM_struct->glMultiTexImage1DEXTproc = (PFNGLMULTITEXIMAGE1DEXTPROC)wglGetProcAddress("glMultiTexImage1DEXT");
	GLM_struct->glMultiTexImage2DEXTproc = (PFNGLMULTITEXIMAGE2DEXTPROC)wglGetProcAddress("glMultiTexImage2DEXT");
	GLM_struct->glMultiTexSubImage1DEXTproc = (PFNGLMULTITEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glMultiTexSubImage1DEXT");
	GLM_struct->glMultiTexSubImage2DEXTproc = (PFNGLMULTITEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glMultiTexSubImage2DEXT");
	GLM_struct->glCopyMultiTexImage1DEXTproc = (PFNGLCOPYMULTITEXIMAGE1DEXTPROC)wglGetProcAddress("glCopyMultiTexImage1DEXT");
	GLM_struct->glCopyMultiTexImage2DEXTproc = (PFNGLCOPYMULTITEXIMAGE2DEXTPROC)wglGetProcAddress("glCopyMultiTexImage2DEXT");
	GLM_struct->glCopyMultiTexSubImage1DEXTproc = (PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glCopyMultiTexSubImage1DEXT");
	GLM_struct->glCopyMultiTexSubImage2DEXTproc = (PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glCopyMultiTexSubImage2DEXT");
	GLM_struct->glGetMultiTexImageEXTproc = (PFNGLGETMULTITEXIMAGEEXTPROC)wglGetProcAddress("glGetMultiTexImageEXT");
	GLM_struct->glGetMultiTexParameterfvEXTproc = (PFNGLGETMULTITEXPARAMETERFVEXTPROC)wglGetProcAddress("glGetMultiTexParameterfvEXT");
	GLM_struct->glGetMultiTexParameterivEXTproc = (PFNGLGETMULTITEXPARAMETERIVEXTPROC)wglGetProcAddress("glGetMultiTexParameterivEXT");
	GLM_struct->glGetMultiTexLevelParameterfvEXTproc = (PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)wglGetProcAddress("glGetMultiTexLevelParameterfvEXT");
	GLM_struct->glGetMultiTexLevelParameterivEXTproc = (PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)wglGetProcAddress("glGetMultiTexLevelParameterivEXT");
	GLM_struct->glMultiTexImage3DEXTproc = (PFNGLMULTITEXIMAGE3DEXTPROC)wglGetProcAddress("glMultiTexImage3DEXT");
	GLM_struct->glMultiTexSubImage3DEXTproc = (PFNGLMULTITEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glMultiTexSubImage3DEXT");
	GLM_struct->glCopyMultiTexSubImage3DEXTproc = (PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glCopyMultiTexSubImage3DEXT");
	GLM_struct->glEnableClientStateIndexedEXTproc = (PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)wglGetProcAddress("glEnableClientStateIndexedEXT");
	GLM_struct->glDisableClientStateIndexedEXTproc = (PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)wglGetProcAddress("glDisableClientStateIndexedEXT");
	GLM_struct->glGetFloatIndexedvEXTproc = (PFNGLGETFLOATINDEXEDVEXTPROC)wglGetProcAddress("glGetFloatIndexedvEXT");
	GLM_struct->glGetDoubleIndexedvEXTproc = (PFNGLGETDOUBLEINDEXEDVEXTPROC)wglGetProcAddress("glGetDoubleIndexedvEXT");
	GLM_struct->glGetPointerIndexedvEXTproc = (PFNGLGETPOINTERINDEXEDVEXTPROC)wglGetProcAddress("glGetPointerIndexedvEXT");
	GLM_struct->glEnableIndexedEXTproc = (PFNGLENABLEINDEXEDEXTPROC)wglGetProcAddress("glEnableIndexedEXT");
	GLM_struct->glDisableIndexedEXTproc = (PFNGLDISABLEINDEXEDEXTPROC)wglGetProcAddress("glDisableIndexedEXT");
	GLM_struct->glIsEnabledIndexedEXTproc = (PFNGLISENABLEDINDEXEDEXTPROC)wglGetProcAddress("glIsEnabledIndexedEXT");
	GLM_struct->glGetIntegerIndexedvEXTproc = (PFNGLGETINTEGERINDEXEDVEXTPROC)wglGetProcAddress("glGetIntegerIndexedvEXT");
	GLM_struct->glGetBooleanIndexedvEXTproc = (PFNGLGETBOOLEANINDEXEDVEXTPROC)wglGetProcAddress("glGetBooleanIndexedvEXT");
	GLM_struct->glCompressedTextureImage3DEXTproc = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)wglGetProcAddress("glCompressedTextureImage3DEXT");
	GLM_struct->glCompressedTextureImage2DEXTproc = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)wglGetProcAddress("glCompressedTextureImage2DEXT");
	GLM_struct->glCompressedTextureImage1DEXTproc = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)wglGetProcAddress("glCompressedTextureImage1DEXT");
	GLM_struct->glCompressedTextureSubImage3DEXTproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)wglGetProcAddress("glCompressedTextureSubImage3DEXT");
	GLM_struct->glCompressedTextureSubImage2DEXTproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)wglGetProcAddress("glCompressedTextureSubImage2DEXT");
	GLM_struct->glCompressedTextureSubImage1DEXTproc = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)wglGetProcAddress("glCompressedTextureSubImage1DEXT");
	GLM_struct->glGetCompressedTextureImageEXTproc = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)wglGetProcAddress("glGetCompressedTextureImageEXT");
	GLM_struct->glCompressedMultiTexImage3DEXTproc = (PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)wglGetProcAddress("glCompressedMultiTexImage3DEXT");
	GLM_struct->glCompressedMultiTexImage2DEXTproc = (PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)wglGetProcAddress("glCompressedMultiTexImage2DEXT");
	GLM_struct->glCompressedMultiTexImage1DEXTproc = (PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)wglGetProcAddress("glCompressedMultiTexImage1DEXT");
	GLM_struct->glCompressedMultiTexSubImage3DEXTproc = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glCompressedMultiTexSubImage3DEXT");
	GLM_struct->glCompressedMultiTexSubImage2DEXTproc = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glCompressedMultiTexSubImage2DEXT");
	GLM_struct->glCompressedMultiTexSubImage1DEXTproc = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glCompressedMultiTexSubImage1DEXT");
	GLM_struct->glGetCompressedMultiTexImageEXTproc = (PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)wglGetProcAddress("glGetCompressedMultiTexImageEXT");
	GLM_struct->glMatrixLoadTransposefEXTproc = (PFNGLMATRIXLOADTRANSPOSEFEXTPROC)wglGetProcAddress("glMatrixLoadTransposefEXT");
	GLM_struct->glMatrixLoadTransposedEXTproc = (PFNGLMATRIXLOADTRANSPOSEDEXTPROC)wglGetProcAddress("glMatrixLoadTransposedEXT");
	GLM_struct->glMatrixMultTransposefEXTproc = (PFNGLMATRIXMULTTRANSPOSEFEXTPROC)wglGetProcAddress("glMatrixMultTransposefEXT");
	GLM_struct->glMatrixMultTransposedEXTproc = (PFNGLMATRIXMULTTRANSPOSEDEXTPROC)wglGetProcAddress("glMatrixMultTransposedEXT");
	GLM_struct->glNamedBufferDataEXTproc = (PFNGLNAMEDBUFFERDATAEXTPROC)wglGetProcAddress("glNamedBufferDataEXT");
	GLM_struct->glNamedBufferSubDataEXTproc = (PFNGLNAMEDBUFFERSUBDATAEXTPROC)wglGetProcAddress("glNamedBufferSubDataEXT");
	GLM_struct->glMapNamedBufferEXTproc = (PFNGLMAPNAMEDBUFFEREXTPROC)wglGetProcAddress("glMapNamedBufferEXT");
	GLM_struct->glUnmapNamedBufferEXTproc = (PFNGLUNMAPNAMEDBUFFEREXTPROC)wglGetProcAddress("glUnmapNamedBufferEXT");
	GLM_struct->glGetNamedBufferParameterivEXTproc = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedBufferParameterivEXT");
	GLM_struct->glGetNamedBufferPointervEXTproc = (PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)wglGetProcAddress("glGetNamedBufferPointervEXT");
	GLM_struct->glGetNamedBufferSubDataEXTproc = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)wglGetProcAddress("glGetNamedBufferSubDataEXT");
	GLM_struct->glProgramUniform1fEXTproc = (PFNGLPROGRAMUNIFORM1FEXTPROC)wglGetProcAddress("glProgramUniform1fEXT");
	GLM_struct->glProgramUniform2fEXTproc = (PFNGLPROGRAMUNIFORM2FEXTPROC)wglGetProcAddress("glProgramUniform2fEXT");
	GLM_struct->glProgramUniform3fEXTproc = (PFNGLPROGRAMUNIFORM3FEXTPROC)wglGetProcAddress("glProgramUniform3fEXT");
	GLM_struct->glProgramUniform4fEXTproc = (PFNGLPROGRAMUNIFORM4FEXTPROC)wglGetProcAddress("glProgramUniform4fEXT");
	GLM_struct->glProgramUniform1iEXTproc = (PFNGLPROGRAMUNIFORM1IEXTPROC)wglGetProcAddress("glProgramUniform1iEXT");
	GLM_struct->glProgramUniform2iEXTproc = (PFNGLPROGRAMUNIFORM2IEXTPROC)wglGetProcAddress("glProgramUniform2iEXT");
	GLM_struct->glProgramUniform3iEXTproc = (PFNGLPROGRAMUNIFORM3IEXTPROC)wglGetProcAddress("glProgramUniform3iEXT");
	GLM_struct->glProgramUniform4iEXTproc = (PFNGLPROGRAMUNIFORM4IEXTPROC)wglGetProcAddress("glProgramUniform4iEXT");
	GLM_struct->glProgramUniform1fvEXTproc = (PFNGLPROGRAMUNIFORM1FVEXTPROC)wglGetProcAddress("glProgramUniform1fvEXT");
	GLM_struct->glProgramUniform2fvEXTproc = (PFNGLPROGRAMUNIFORM2FVEXTPROC)wglGetProcAddress("glProgramUniform2fvEXT");
	GLM_struct->glProgramUniform3fvEXTproc = (PFNGLPROGRAMUNIFORM3FVEXTPROC)wglGetProcAddress("glProgramUniform3fvEXT");
	GLM_struct->glProgramUniform4fvEXTproc = (PFNGLPROGRAMUNIFORM4FVEXTPROC)wglGetProcAddress("glProgramUniform4fvEXT");
	GLM_struct->glProgramUniform1ivEXTproc = (PFNGLPROGRAMUNIFORM1IVEXTPROC)wglGetProcAddress("glProgramUniform1ivEXT");
	GLM_struct->glProgramUniform2ivEXTproc = (PFNGLPROGRAMUNIFORM2IVEXTPROC)wglGetProcAddress("glProgramUniform2ivEXT");
	GLM_struct->glProgramUniform3ivEXTproc = (PFNGLPROGRAMUNIFORM3IVEXTPROC)wglGetProcAddress("glProgramUniform3ivEXT");
	GLM_struct->glProgramUniform4ivEXTproc = (PFNGLPROGRAMUNIFORM4IVEXTPROC)wglGetProcAddress("glProgramUniform4ivEXT");
	GLM_struct->glProgramUniformMatrix2fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2fvEXT");
	GLM_struct->glProgramUniformMatrix3fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3fvEXT");
	GLM_struct->glProgramUniformMatrix4fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4fvEXT");
	GLM_struct->glProgramUniformMatrix2x3fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x3fvEXT");
	GLM_struct->glProgramUniformMatrix3x2fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x2fvEXT");
	GLM_struct->glProgramUniformMatrix2x4fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x4fvEXT");
	GLM_struct->glProgramUniformMatrix4x2fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x2fvEXT");
	GLM_struct->glProgramUniformMatrix3x4fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x4fvEXT");
	GLM_struct->glProgramUniformMatrix4x3fvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x3fvEXT");
	GLM_struct->glTextureBufferEXTproc = (PFNGLTEXTUREBUFFEREXTPROC)wglGetProcAddress("glTextureBufferEXT");
	GLM_struct->glMultiTexBufferEXTproc = (PFNGLMULTITEXBUFFEREXTPROC)wglGetProcAddress("glMultiTexBufferEXT");
	GLM_struct->glTextureParameterIivEXTproc = (PFNGLTEXTUREPARAMETERIIVEXTPROC)wglGetProcAddress("glTextureParameterIivEXT");
	GLM_struct->glTextureParameterIuivEXTproc = (PFNGLTEXTUREPARAMETERIUIVEXTPROC)wglGetProcAddress("glTextureParameterIuivEXT");
	GLM_struct->glGetTextureParameterIivEXTproc = (PFNGLGETTEXTUREPARAMETERIIVEXTPROC)wglGetProcAddress("glGetTextureParameterIivEXT");
	GLM_struct->glGetTextureParameterIuivEXTproc = (PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetTextureParameterIuivEXT");
	GLM_struct->glMultiTexParameterIivEXTproc = (PFNGLMULTITEXPARAMETERIIVEXTPROC)wglGetProcAddress("glMultiTexParameterIivEXT");
	GLM_struct->glMultiTexParameterIuivEXTproc = (PFNGLMULTITEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glMultiTexParameterIuivEXT");
	GLM_struct->glGetMultiTexParameterIivEXTproc = (PFNGLGETMULTITEXPARAMETERIIVEXTPROC)wglGetProcAddress("glGetMultiTexParameterIivEXT");
	GLM_struct->glGetMultiTexParameterIuivEXTproc = (PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetMultiTexParameterIuivEXT");
	GLM_struct->glProgramUniform1uiEXTproc = (PFNGLPROGRAMUNIFORM1UIEXTPROC)wglGetProcAddress("glProgramUniform1uiEXT");
	GLM_struct->glProgramUniform2uiEXTproc = (PFNGLPROGRAMUNIFORM2UIEXTPROC)wglGetProcAddress("glProgramUniform2uiEXT");
	GLM_struct->glProgramUniform3uiEXTproc = (PFNGLPROGRAMUNIFORM3UIEXTPROC)wglGetProcAddress("glProgramUniform3uiEXT");
	GLM_struct->glProgramUniform4uiEXTproc = (PFNGLPROGRAMUNIFORM4UIEXTPROC)wglGetProcAddress("glProgramUniform4uiEXT");
	GLM_struct->glProgramUniform1uivEXTproc = (PFNGLPROGRAMUNIFORM1UIVEXTPROC)wglGetProcAddress("glProgramUniform1uivEXT");
	GLM_struct->glProgramUniform2uivEXTproc = (PFNGLPROGRAMUNIFORM2UIVEXTPROC)wglGetProcAddress("glProgramUniform2uivEXT");
	GLM_struct->glProgramUniform3uivEXTproc = (PFNGLPROGRAMUNIFORM3UIVEXTPROC)wglGetProcAddress("glProgramUniform3uivEXT");
	GLM_struct->glProgramUniform4uivEXTproc = (PFNGLPROGRAMUNIFORM4UIVEXTPROC)wglGetProcAddress("glProgramUniform4uivEXT");
	GLM_struct->glNamedProgramLocalParameters4fvEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameters4fvEXT");
	GLM_struct->glNamedProgramLocalParameterI4iEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4iEXT");
	GLM_struct->glNamedProgramLocalParameterI4ivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4ivEXT");
	GLM_struct->glNamedProgramLocalParametersI4ivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)wglGetProcAddress("glNamedProgramLocalParametersI4ivEXT");
	GLM_struct->glNamedProgramLocalParameterI4uiEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4uiEXT");
	GLM_struct->glNamedProgramLocalParameterI4uivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameterI4uivEXT");
	GLM_struct->glNamedProgramLocalParametersI4uivEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)wglGetProcAddress("glNamedProgramLocalParametersI4uivEXT");
	GLM_struct->glGetNamedProgramLocalParameterIivEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterIivEXT");
	GLM_struct->glGetNamedProgramLocalParameterIuivEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterIuivEXT");
	GLM_struct->glEnableClientStateiEXTproc = (PFNGLENABLECLIENTSTATEIEXTPROC)wglGetProcAddress("glEnableClientStateiEXT");
	GLM_struct->glDisableClientStateiEXTproc = (PFNGLDISABLECLIENTSTATEIEXTPROC)wglGetProcAddress("glDisableClientStateiEXT");
	GLM_struct->glGetFloati_vEXTproc = (PFNGLGETFLOATI_VEXTPROC)wglGetProcAddress("glGetFloati_vEXT");
	GLM_struct->glGetDoublei_vEXTproc = (PFNGLGETDOUBLEI_VEXTPROC)wglGetProcAddress("glGetDoublei_vEXT");
	GLM_struct->glGetPointeri_vEXTproc = (PFNGLGETPOINTERI_VEXTPROC)wglGetProcAddress("glGetPointeri_vEXT");
	GLM_struct->glNamedProgramStringEXTproc = (PFNGLNAMEDPROGRAMSTRINGEXTPROC)wglGetProcAddress("glNamedProgramStringEXT");
	GLM_struct->glNamedProgramLocalParameter4dEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4dEXT");
	GLM_struct->glNamedProgramLocalParameter4dvEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4dvEXT");
	GLM_struct->glNamedProgramLocalParameter4fEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4fEXT");
	GLM_struct->glNamedProgramLocalParameter4fvEXTproc = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)wglGetProcAddress("glNamedProgramLocalParameter4fvEXT");
	GLM_struct->glGetNamedProgramLocalParameterdvEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterdvEXT");
	GLM_struct->glGetNamedProgramLocalParameterfvEXTproc = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)wglGetProcAddress("glGetNamedProgramLocalParameterfvEXT");
	GLM_struct->glGetNamedProgramivEXTproc = (PFNGLGETNAMEDPROGRAMIVEXTPROC)wglGetProcAddress("glGetNamedProgramivEXT");
	GLM_struct->glGetNamedProgramStringEXTproc = (PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)wglGetProcAddress("glGetNamedProgramStringEXT");
	GLM_struct->glNamedRenderbufferStorageEXTproc = (PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glNamedRenderbufferStorageEXT");
	GLM_struct->glGetNamedRenderbufferParameterivEXTproc = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedRenderbufferParameterivEXT");
	GLM_struct->glNamedRenderbufferStorageMultisampleEXTproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisampleEXT");
	GLM_struct->glNamedRenderbufferStorageMultisampleCoverageEXTproc = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisampleCoverageEXT");
	GLM_struct->glCheckNamedFramebufferStatusEXTproc = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckNamedFramebufferStatusEXT");
	GLM_struct->glNamedFramebufferTexture1DEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)wglGetProcAddress("glNamedFramebufferTexture1DEXT");
	GLM_struct->glNamedFramebufferTexture2DEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glNamedFramebufferTexture2DEXT");
	GLM_struct->glNamedFramebufferTexture3DEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)wglGetProcAddress("glNamedFramebufferTexture3DEXT");
	GLM_struct->glNamedFramebufferRenderbufferEXTproc = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glNamedFramebufferRenderbufferEXT");
	GLM_struct->glGetNamedFramebufferAttachmentParameterivEXTproc = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedFramebufferAttachmentParameterivEXT");
	GLM_struct->glGenerateTextureMipmapEXTproc = (PFNGLGENERATETEXTUREMIPMAPEXTPROC)wglGetProcAddress("glGenerateTextureMipmapEXT");
	GLM_struct->glGenerateMultiTexMipmapEXTproc = (PFNGLGENERATEMULTITEXMIPMAPEXTPROC)wglGetProcAddress("glGenerateMultiTexMipmapEXT");
	GLM_struct->glFramebufferDrawBufferEXTproc = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)wglGetProcAddress("glFramebufferDrawBufferEXT");
	GLM_struct->glFramebufferDrawBuffersEXTproc = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)wglGetProcAddress("glFramebufferDrawBuffersEXT");
	GLM_struct->glFramebufferReadBufferEXTproc = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC)wglGetProcAddress("glFramebufferReadBufferEXT");
	GLM_struct->glGetFramebufferParameterivEXTproc = (PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferParameterivEXT");
	GLM_struct->glNamedCopyBufferSubDataEXTproc = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)wglGetProcAddress("glNamedCopyBufferSubDataEXT");
	GLM_struct->glNamedFramebufferTextureEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)wglGetProcAddress("glNamedFramebufferTextureEXT");
	GLM_struct->glNamedFramebufferTextureLayerEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)wglGetProcAddress("glNamedFramebufferTextureLayerEXT");
	GLM_struct->glNamedFramebufferTextureFaceEXTproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)wglGetProcAddress("glNamedFramebufferTextureFaceEXT");
	GLM_struct->glTextureRenderbufferEXTproc = (PFNGLTEXTURERENDERBUFFEREXTPROC)wglGetProcAddress("glTextureRenderbufferEXT");
	GLM_struct->glMultiTexRenderbufferEXTproc = (PFNGLMULTITEXRENDERBUFFEREXTPROC)wglGetProcAddress("glMultiTexRenderbufferEXT");
	GLM_struct->glVertexArrayVertexOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexOffsetEXT");
	GLM_struct->glVertexArrayColorOffsetEXTproc = (PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)wglGetProcAddress("glVertexArrayColorOffsetEXT");
	GLM_struct->glVertexArrayEdgeFlagOffsetEXTproc = (PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)wglGetProcAddress("glVertexArrayEdgeFlagOffsetEXT");
	GLM_struct->glVertexArrayIndexOffsetEXTproc = (PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)wglGetProcAddress("glVertexArrayIndexOffsetEXT");
	GLM_struct->glVertexArrayNormalOffsetEXTproc = (PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)wglGetProcAddress("glVertexArrayNormalOffsetEXT");
	GLM_struct->glVertexArrayTexCoordOffsetEXTproc = (PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)wglGetProcAddress("glVertexArrayTexCoordOffsetEXT");
	GLM_struct->glVertexArrayMultiTexCoordOffsetEXTproc = (PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)wglGetProcAddress("glVertexArrayMultiTexCoordOffsetEXT");
	GLM_struct->glVertexArrayFogCoordOffsetEXTproc = (PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)wglGetProcAddress("glVertexArrayFogCoordOffsetEXT");
	GLM_struct->glVertexArraySecondaryColorOffsetEXTproc = (PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)wglGetProcAddress("glVertexArraySecondaryColorOffsetEXT");
	GLM_struct->glVertexArrayVertexAttribOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribOffsetEXT");
	GLM_struct->glVertexArrayVertexAttribIOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribIOffsetEXT");
	GLM_struct->glEnableVertexArrayEXTproc = (PFNGLENABLEVERTEXARRAYEXTPROC)wglGetProcAddress("glEnableVertexArrayEXT");
	GLM_struct->glDisableVertexArrayEXTproc = (PFNGLDISABLEVERTEXARRAYEXTPROC)wglGetProcAddress("glDisableVertexArrayEXT");
	GLM_struct->glEnableVertexArrayAttribEXTproc = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)wglGetProcAddress("glEnableVertexArrayAttribEXT");
	GLM_struct->glDisableVertexArrayAttribEXTproc = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)wglGetProcAddress("glDisableVertexArrayAttribEXT");
	GLM_struct->glGetVertexArrayIntegervEXTproc = (PFNGLGETVERTEXARRAYINTEGERVEXTPROC)wglGetProcAddress("glGetVertexArrayIntegervEXT");
	GLM_struct->glGetVertexArrayPointervEXTproc = (PFNGLGETVERTEXARRAYPOINTERVEXTPROC)wglGetProcAddress("glGetVertexArrayPointervEXT");
	GLM_struct->glGetVertexArrayIntegeri_vEXTproc = (PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)wglGetProcAddress("glGetVertexArrayIntegeri_vEXT");
	GLM_struct->glGetVertexArrayPointeri_vEXTproc = (PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)wglGetProcAddress("glGetVertexArrayPointeri_vEXT");
	GLM_struct->glMapNamedBufferRangeEXTproc = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC)wglGetProcAddress("glMapNamedBufferRangeEXT");
	GLM_struct->glFlushMappedNamedBufferRangeEXTproc = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)wglGetProcAddress("glFlushMappedNamedBufferRangeEXT");
	GLM_struct->glNamedBufferStorageEXTproc = (PFNGLNAMEDBUFFERSTORAGEEXTPROC)wglGetProcAddress("glNamedBufferStorageEXT");
	GLM_struct->glClearNamedBufferDataEXTproc = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)wglGetProcAddress("glClearNamedBufferDataEXT");
	GLM_struct->glClearNamedBufferSubDataEXTproc = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)wglGetProcAddress("glClearNamedBufferSubDataEXT");
	GLM_struct->glNamedFramebufferParameteriEXTproc = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)wglGetProcAddress("glNamedFramebufferParameteriEXT");
	GLM_struct->glGetNamedFramebufferParameterivEXTproc = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetNamedFramebufferParameterivEXT");
	GLM_struct->glProgramUniform1dEXTproc = (PFNGLPROGRAMUNIFORM1DEXTPROC)wglGetProcAddress("glProgramUniform1dEXT");
	GLM_struct->glProgramUniform2dEXTproc = (PFNGLPROGRAMUNIFORM2DEXTPROC)wglGetProcAddress("glProgramUniform2dEXT");
	GLM_struct->glProgramUniform3dEXTproc = (PFNGLPROGRAMUNIFORM3DEXTPROC)wglGetProcAddress("glProgramUniform3dEXT");
	GLM_struct->glProgramUniform4dEXTproc = (PFNGLPROGRAMUNIFORM4DEXTPROC)wglGetProcAddress("glProgramUniform4dEXT");
	GLM_struct->glProgramUniform1dvEXTproc = (PFNGLPROGRAMUNIFORM1DVEXTPROC)wglGetProcAddress("glProgramUniform1dvEXT");
	GLM_struct->glProgramUniform2dvEXTproc = (PFNGLPROGRAMUNIFORM2DVEXTPROC)wglGetProcAddress("glProgramUniform2dvEXT");
	GLM_struct->glProgramUniform3dvEXTproc = (PFNGLPROGRAMUNIFORM3DVEXTPROC)wglGetProcAddress("glProgramUniform3dvEXT");
	GLM_struct->glProgramUniform4dvEXTproc = (PFNGLPROGRAMUNIFORM4DVEXTPROC)wglGetProcAddress("glProgramUniform4dvEXT");
	GLM_struct->glProgramUniformMatrix2dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2dvEXT");
	GLM_struct->glProgramUniformMatrix3dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3dvEXT");
	GLM_struct->glProgramUniformMatrix4dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4dvEXT");
	GLM_struct->glProgramUniformMatrix2x3dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x3dvEXT");
	GLM_struct->glProgramUniformMatrix2x4dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix2x4dvEXT");
	GLM_struct->glProgramUniformMatrix3x2dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x2dvEXT");
	GLM_struct->glProgramUniformMatrix3x4dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix3x4dvEXT");
	GLM_struct->glProgramUniformMatrix4x2dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x2dvEXT");
	GLM_struct->glProgramUniformMatrix4x3dvEXTproc = (PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)wglGetProcAddress("glProgramUniformMatrix4x3dvEXT");
	GLM_struct->glTextureBufferRangeEXTproc = (PFNGLTEXTUREBUFFERRANGEEXTPROC)wglGetProcAddress("glTextureBufferRangeEXT");
	GLM_struct->glTextureStorage1DEXTproc = (PFNGLTEXTURESTORAGE1DEXTPROC)wglGetProcAddress("glTextureStorage1DEXT");
	GLM_struct->glTextureStorage2DEXTproc = (PFNGLTEXTURESTORAGE2DEXTPROC)wglGetProcAddress("glTextureStorage2DEXT");
	GLM_struct->glTextureStorage3DEXTproc = (PFNGLTEXTURESTORAGE3DEXTPROC)wglGetProcAddress("glTextureStorage3DEXT");
	GLM_struct->glTextureStorage2DMultisampleEXTproc = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorage2DMultisampleEXT");
	GLM_struct->glTextureStorage3DMultisampleEXTproc = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorage3DMultisampleEXT");
	GLM_struct->glVertexArrayBindVertexBufferEXTproc = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)wglGetProcAddress("glVertexArrayBindVertexBufferEXT");
	GLM_struct->glVertexArrayVertexAttribFormatEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribFormatEXT");
	GLM_struct->glVertexArrayVertexAttribIFormatEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribIFormatEXT");
	GLM_struct->glVertexArrayVertexAttribLFormatEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribLFormatEXT");
	GLM_struct->glVertexArrayVertexAttribBindingEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribBindingEXT");
	GLM_struct->glVertexArrayVertexBindingDivisorEXTproc = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)wglGetProcAddress("glVertexArrayVertexBindingDivisorEXT");
	GLM_struct->glVertexArrayVertexAttribLOffsetEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)wglGetProcAddress("glVertexArrayVertexAttribLOffsetEXT");
	GLM_struct->glTexturePageCommitmentEXTproc = (PFNGLTEXTUREPAGECOMMITMENTEXTPROC)wglGetProcAddress("glTexturePageCommitmentEXT");
	GLM_struct->glVertexArrayVertexAttribDivisorEXTproc = (PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)wglGetProcAddress("glVertexArrayVertexAttribDivisorEXT");
	GLM_struct->glColorMaskIndexedEXTproc = (PFNGLCOLORMASKINDEXEDEXTPROC)wglGetProcAddress("glColorMaskIndexedEXT");
	GLM_struct->glDrawArraysInstancedEXTproc = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)wglGetProcAddress("glDrawArraysInstancedEXT");
	GLM_struct->glDrawElementsInstancedEXTproc = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)wglGetProcAddress("glDrawElementsInstancedEXT");
	GLM_struct->glDrawRangeElementsEXTproc = (PFNGLDRAWRANGEELEMENTSEXTPROC)wglGetProcAddress("glDrawRangeElementsEXT");
	GLM_struct->glBufferStorageExternalEXTproc = (PFNGLBUFFERSTORAGEEXTERNALEXTPROC)wglGetProcAddress("glBufferStorageExternalEXT");
	GLM_struct->glNamedBufferStorageExternalEXTproc = (PFNGLNAMEDBUFFERSTORAGEEXTERNALEXTPROC)wglGetProcAddress("glNamedBufferStorageExternalEXT");
	GLM_struct->glFogCoordfEXTproc = (PFNGLFOGCOORDFEXTPROC)wglGetProcAddress("glFogCoordfEXT");
	GLM_struct->glFogCoordfvEXTproc = (PFNGLFOGCOORDFVEXTPROC)wglGetProcAddress("glFogCoordfvEXT");
	GLM_struct->glFogCoorddEXTproc = (PFNGLFOGCOORDDEXTPROC)wglGetProcAddress("glFogCoorddEXT");
	GLM_struct->glFogCoorddvEXTproc = (PFNGLFOGCOORDDVEXTPROC)wglGetProcAddress("glFogCoorddvEXT");
	GLM_struct->glFogCoordPointerEXTproc = (PFNGLFOGCOORDPOINTEREXTPROC)wglGetProcAddress("glFogCoordPointerEXT");
	GLM_struct->glBlitFramebufferEXTproc = (PFNGLBLITFRAMEBUFFEREXTPROC)wglGetProcAddress("glBlitFramebufferEXT");
	GLM_struct->glBlitFramebufferLayersEXTproc = (PFNGLBLITFRAMEBUFFERLAYERSEXTPROC)wglGetProcAddress("glBlitFramebufferLayersEXT");
	GLM_struct->glBlitFramebufferLayerEXTproc = (PFNGLBLITFRAMEBUFFERLAYEREXTPROC)wglGetProcAddress("glBlitFramebufferLayerEXT");
	GLM_struct->glRenderbufferStorageMultisampleEXTproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)wglGetProcAddress("glRenderbufferStorageMultisampleEXT");
	GLM_struct->glIsRenderbufferEXTproc = (PFNGLISRENDERBUFFEREXTPROC)wglGetProcAddress("glIsRenderbufferEXT");
	GLM_struct->glBindRenderbufferEXTproc = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbufferEXT");
	GLM_struct->glDeleteRenderbuffersEXTproc = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffersEXT");
	GLM_struct->glGenRenderbuffersEXTproc = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffersEXT");
	GLM_struct->glRenderbufferStorageEXTproc = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorageEXT");
	GLM_struct->glGetRenderbufferParameterivEXTproc = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetRenderbufferParameterivEXT");
	GLM_struct->glIsFramebufferEXTproc = (PFNGLISFRAMEBUFFEREXTPROC)wglGetProcAddress("glIsFramebufferEXT");
	GLM_struct->glBindFramebufferEXTproc = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
	GLM_struct->glDeleteFramebuffersEXTproc = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
	GLM_struct->glGenFramebuffersEXTproc = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffersEXT");
	GLM_struct->glCheckFramebufferStatusEXTproc = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
	GLM_struct->glFramebufferTexture1DEXTproc = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)wglGetProcAddress("glFramebufferTexture1DEXT");
	GLM_struct->glFramebufferTexture2DEXTproc = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2DEXT");
	GLM_struct->glFramebufferTexture3DEXTproc = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)wglGetProcAddress("glFramebufferTexture3DEXT");
	GLM_struct->glFramebufferRenderbufferEXTproc = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbufferEXT");
	GLM_struct->glGetFramebufferAttachmentParameterivEXTproc = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
	GLM_struct->glGenerateMipmapEXTproc = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmapEXT");
	GLM_struct->glProgramParameteriEXTproc = (PFNGLPROGRAMPARAMETERIEXTPROC)wglGetProcAddress("glProgramParameteriEXT");
	GLM_struct->glProgramEnvParameters4fvEXTproc = (PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)wglGetProcAddress("glProgramEnvParameters4fvEXT");
	GLM_struct->glProgramLocalParameters4fvEXTproc = (PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)wglGetProcAddress("glProgramLocalParameters4fvEXT");
	GLM_struct->glGetUniformuivEXTproc = (PFNGLGETUNIFORMUIVEXTPROC)wglGetProcAddress("glGetUniformuivEXT");
	GLM_struct->glBindFragDataLocationEXTproc = (PFNGLBINDFRAGDATALOCATIONEXTPROC)wglGetProcAddress("glBindFragDataLocationEXT");
	GLM_struct->glGetFragDataLocationEXTproc = (PFNGLGETFRAGDATALOCATIONEXTPROC)wglGetProcAddress("glGetFragDataLocationEXT");
	GLM_struct->glUniform1uiEXTproc = (PFNGLUNIFORM1UIEXTPROC)wglGetProcAddress("glUniform1uiEXT");
	GLM_struct->glUniform2uiEXTproc = (PFNGLUNIFORM2UIEXTPROC)wglGetProcAddress("glUniform2uiEXT");
	GLM_struct->glUniform3uiEXTproc = (PFNGLUNIFORM3UIEXTPROC)wglGetProcAddress("glUniform3uiEXT");
	GLM_struct->glUniform4uiEXTproc = (PFNGLUNIFORM4UIEXTPROC)wglGetProcAddress("glUniform4uiEXT");
	GLM_struct->glUniform1uivEXTproc = (PFNGLUNIFORM1UIVEXTPROC)wglGetProcAddress("glUniform1uivEXT");
	GLM_struct->glUniform2uivEXTproc = (PFNGLUNIFORM2UIVEXTPROC)wglGetProcAddress("glUniform2uivEXT");
	GLM_struct->glUniform3uivEXTproc = (PFNGLUNIFORM3UIVEXTPROC)wglGetProcAddress("glUniform3uivEXT");
	GLM_struct->glUniform4uivEXTproc = (PFNGLUNIFORM4UIVEXTPROC)wglGetProcAddress("glUniform4uivEXT");
	GLM_struct->glVertexAttribI1iEXTproc = (PFNGLVERTEXATTRIBI1IEXTPROC)wglGetProcAddress("glVertexAttribI1iEXT");
	GLM_struct->glVertexAttribI2iEXTproc = (PFNGLVERTEXATTRIBI2IEXTPROC)wglGetProcAddress("glVertexAttribI2iEXT");
	GLM_struct->glVertexAttribI3iEXTproc = (PFNGLVERTEXATTRIBI3IEXTPROC)wglGetProcAddress("glVertexAttribI3iEXT");
	GLM_struct->glVertexAttribI4iEXTproc = (PFNGLVERTEXATTRIBI4IEXTPROC)wglGetProcAddress("glVertexAttribI4iEXT");
	GLM_struct->glVertexAttribI1uiEXTproc = (PFNGLVERTEXATTRIBI1UIEXTPROC)wglGetProcAddress("glVertexAttribI1uiEXT");
	GLM_struct->glVertexAttribI2uiEXTproc = (PFNGLVERTEXATTRIBI2UIEXTPROC)wglGetProcAddress("glVertexAttribI2uiEXT");
	GLM_struct->glVertexAttribI3uiEXTproc = (PFNGLVERTEXATTRIBI3UIEXTPROC)wglGetProcAddress("glVertexAttribI3uiEXT");
	GLM_struct->glVertexAttribI4uiEXTproc = (PFNGLVERTEXATTRIBI4UIEXTPROC)wglGetProcAddress("glVertexAttribI4uiEXT");
	GLM_struct->glVertexAttribI1ivEXTproc = (PFNGLVERTEXATTRIBI1IVEXTPROC)wglGetProcAddress("glVertexAttribI1ivEXT");
	GLM_struct->glVertexAttribI2ivEXTproc = (PFNGLVERTEXATTRIBI2IVEXTPROC)wglGetProcAddress("glVertexAttribI2ivEXT");
	GLM_struct->glVertexAttribI3ivEXTproc = (PFNGLVERTEXATTRIBI3IVEXTPROC)wglGetProcAddress("glVertexAttribI3ivEXT");
	GLM_struct->glVertexAttribI4ivEXTproc = (PFNGLVERTEXATTRIBI4IVEXTPROC)wglGetProcAddress("glVertexAttribI4ivEXT");
	GLM_struct->glVertexAttribI1uivEXTproc = (PFNGLVERTEXATTRIBI1UIVEXTPROC)wglGetProcAddress("glVertexAttribI1uivEXT");
	GLM_struct->glVertexAttribI2uivEXTproc = (PFNGLVERTEXATTRIBI2UIVEXTPROC)wglGetProcAddress("glVertexAttribI2uivEXT");
	GLM_struct->glVertexAttribI3uivEXTproc = (PFNGLVERTEXATTRIBI3UIVEXTPROC)wglGetProcAddress("glVertexAttribI3uivEXT");
	GLM_struct->glVertexAttribI4uivEXTproc = (PFNGLVERTEXATTRIBI4UIVEXTPROC)wglGetProcAddress("glVertexAttribI4uivEXT");
	GLM_struct->glVertexAttribI4bvEXTproc = (PFNGLVERTEXATTRIBI4BVEXTPROC)wglGetProcAddress("glVertexAttribI4bvEXT");
	GLM_struct->glVertexAttribI4svEXTproc = (PFNGLVERTEXATTRIBI4SVEXTPROC)wglGetProcAddress("glVertexAttribI4svEXT");
	GLM_struct->glVertexAttribI4ubvEXTproc = (PFNGLVERTEXATTRIBI4UBVEXTPROC)wglGetProcAddress("glVertexAttribI4ubvEXT");
	GLM_struct->glVertexAttribI4usvEXTproc = (PFNGLVERTEXATTRIBI4USVEXTPROC)wglGetProcAddress("glVertexAttribI4usvEXT");
	GLM_struct->glVertexAttribIPointerEXTproc = (PFNGLVERTEXATTRIBIPOINTEREXTPROC)wglGetProcAddress("glVertexAttribIPointerEXT");
	GLM_struct->glGetVertexAttribIivEXTproc = (PFNGLGETVERTEXATTRIBIIVEXTPROC)wglGetProcAddress("glGetVertexAttribIivEXT");
	GLM_struct->glGetVertexAttribIuivEXTproc = (PFNGLGETVERTEXATTRIBIUIVEXTPROC)wglGetProcAddress("glGetVertexAttribIuivEXT");
	GLM_struct->glGetHistogramEXTproc = (PFNGLGETHISTOGRAMEXTPROC)wglGetProcAddress("glGetHistogramEXT");
	GLM_struct->glGetHistogramParameterfvEXTproc = (PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)wglGetProcAddress("glGetHistogramParameterfvEXT");
	GLM_struct->glGetHistogramParameterivEXTproc = (PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)wglGetProcAddress("glGetHistogramParameterivEXT");
	GLM_struct->glGetMinmaxEXTproc = (PFNGLGETMINMAXEXTPROC)wglGetProcAddress("glGetMinmaxEXT");
	GLM_struct->glGetMinmaxParameterfvEXTproc = (PFNGLGETMINMAXPARAMETERFVEXTPROC)wglGetProcAddress("glGetMinmaxParameterfvEXT");
	GLM_struct->glGetMinmaxParameterivEXTproc = (PFNGLGETMINMAXPARAMETERIVEXTPROC)wglGetProcAddress("glGetMinmaxParameterivEXT");
	GLM_struct->glHistogramEXTproc = (PFNGLHISTOGRAMEXTPROC)wglGetProcAddress("glHistogramEXT");
	GLM_struct->glMinmaxEXTproc = (PFNGLMINMAXEXTPROC)wglGetProcAddress("glMinmaxEXT");
	GLM_struct->glResetHistogramEXTproc = (PFNGLRESETHISTOGRAMEXTPROC)wglGetProcAddress("glResetHistogramEXT");
	GLM_struct->glResetMinmaxEXTproc = (PFNGLRESETMINMAXEXTPROC)wglGetProcAddress("glResetMinmaxEXT");
	GLM_struct->glIndexFuncEXTproc = (PFNGLINDEXFUNCEXTPROC)wglGetProcAddress("glIndexFuncEXT");
	GLM_struct->glIndexMaterialEXTproc = (PFNGLINDEXMATERIALEXTPROC)wglGetProcAddress("glIndexMaterialEXT");
	GLM_struct->glApplyTextureEXTproc = (PFNGLAPPLYTEXTUREEXTPROC)wglGetProcAddress("glApplyTextureEXT");
	GLM_struct->glTextureLightEXTproc = (PFNGLTEXTURELIGHTEXTPROC)wglGetProcAddress("glTextureLightEXT");
	GLM_struct->glTextureMaterialEXTproc = (PFNGLTEXTUREMATERIALEXTPROC)wglGetProcAddress("glTextureMaterialEXT");
	GLM_struct->glGetUnsignedBytevEXTproc = (PFNGLGETUNSIGNEDBYTEVEXTPROC)wglGetProcAddress("glGetUnsignedBytevEXT");
	GLM_struct->glGetUnsignedBytei_vEXTproc = (PFNGLGETUNSIGNEDBYTEI_VEXTPROC)wglGetProcAddress("glGetUnsignedBytei_vEXT");
	GLM_struct->glDeleteMemoryObjectsEXTproc = (PFNGLDELETEMEMORYOBJECTSEXTPROC)wglGetProcAddress("glDeleteMemoryObjectsEXT");
	GLM_struct->glIsMemoryObjectEXTproc = (PFNGLISMEMORYOBJECTEXTPROC)wglGetProcAddress("glIsMemoryObjectEXT");
	GLM_struct->glCreateMemoryObjectsEXTproc = (PFNGLCREATEMEMORYOBJECTSEXTPROC)wglGetProcAddress("glCreateMemoryObjectsEXT");
	GLM_struct->glMemoryObjectParameterivEXTproc = (PFNGLMEMORYOBJECTPARAMETERIVEXTPROC)wglGetProcAddress("glMemoryObjectParameterivEXT");
	GLM_struct->glGetMemoryObjectParameterivEXTproc = (PFNGLGETMEMORYOBJECTPARAMETERIVEXTPROC)wglGetProcAddress("glGetMemoryObjectParameterivEXT");
	GLM_struct->glTexStorageMem2DEXTproc = (PFNGLTEXSTORAGEMEM2DEXTPROC)wglGetProcAddress("glTexStorageMem2DEXT");
	GLM_struct->glTexStorageMem2DMultisampleEXTproc = (PFNGLTEXSTORAGEMEM2DMULTISAMPLEEXTPROC)wglGetProcAddress("glTexStorageMem2DMultisampleEXT");
	GLM_struct->glTexStorageMem3DEXTproc = (PFNGLTEXSTORAGEMEM3DEXTPROC)wglGetProcAddress("glTexStorageMem3DEXT");
	GLM_struct->glTexStorageMem3DMultisampleEXTproc = (PFNGLTEXSTORAGEMEM3DMULTISAMPLEEXTPROC)wglGetProcAddress("glTexStorageMem3DMultisampleEXT");
	GLM_struct->glBufferStorageMemEXTproc = (PFNGLBUFFERSTORAGEMEMEXTPROC)wglGetProcAddress("glBufferStorageMemEXT");
	GLM_struct->glTextureStorageMem2DEXTproc = (PFNGLTEXTURESTORAGEMEM2DEXTPROC)wglGetProcAddress("glTextureStorageMem2DEXT");
	GLM_struct->glTextureStorageMem2DMultisampleEXTproc = (PFNGLTEXTURESTORAGEMEM2DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorageMem2DMultisampleEXT");
	GLM_struct->glTextureStorageMem3DEXTproc = (PFNGLTEXTURESTORAGEMEM3DEXTPROC)wglGetProcAddress("glTextureStorageMem3DEXT");
	GLM_struct->glTextureStorageMem3DMultisampleEXTproc = (PFNGLTEXTURESTORAGEMEM3DMULTISAMPLEEXTPROC)wglGetProcAddress("glTextureStorageMem3DMultisampleEXT");
	GLM_struct->glNamedBufferStorageMemEXTproc = (PFNGLNAMEDBUFFERSTORAGEMEMEXTPROC)wglGetProcAddress("glNamedBufferStorageMemEXT");
	GLM_struct->glTexStorageMem1DEXTproc = (PFNGLTEXSTORAGEMEM1DEXTPROC)wglGetProcAddress("glTexStorageMem1DEXT");
	GLM_struct->glTextureStorageMem1DEXTproc = (PFNGLTEXTURESTORAGEMEM1DEXTPROC)wglGetProcAddress("glTextureStorageMem1DEXT");
	GLM_struct->glImportMemoryFdEXTproc = (PFNGLIMPORTMEMORYFDEXTPROC)wglGetProcAddress("glImportMemoryFdEXT");
	GLM_struct->glImportMemoryWin32HandleEXTproc = (PFNGLIMPORTMEMORYWIN32HANDLEEXTPROC)wglGetProcAddress("glImportMemoryWin32HandleEXT");
	GLM_struct->glImportMemoryWin32NameEXTproc = (PFNGLIMPORTMEMORYWIN32NAMEEXTPROC)wglGetProcAddress("glImportMemoryWin32NameEXT");
	GLM_struct->glMultiDrawArraysEXTproc = (PFNGLMULTIDRAWARRAYSEXTPROC)wglGetProcAddress("glMultiDrawArraysEXT");
	GLM_struct->glMultiDrawElementsEXTproc = (PFNGLMULTIDRAWELEMENTSEXTPROC)wglGetProcAddress("glMultiDrawElementsEXT");
	GLM_struct->glSampleMaskEXTproc = (PFNGLSAMPLEMASKEXTPROC)wglGetProcAddress("glSampleMaskEXT");
	GLM_struct->glSamplePatternEXTproc = (PFNGLSAMPLEPATTERNEXTPROC)wglGetProcAddress("glSamplePatternEXT");
	GLM_struct->glColorTableEXTproc = (PFNGLCOLORTABLEEXTPROC)wglGetProcAddress("glColorTableEXT");
	GLM_struct->glGetColorTableEXTproc = (PFNGLGETCOLORTABLEEXTPROC)wglGetProcAddress("glGetColorTableEXT");
	GLM_struct->glGetColorTableParameterivEXTproc = (PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)wglGetProcAddress("glGetColorTableParameterivEXT");
	GLM_struct->glGetColorTableParameterfvEXTproc = (PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)wglGetProcAddress("glGetColorTableParameterfvEXT");
	GLM_struct->glPixelTransformParameteriEXTproc = (PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)wglGetProcAddress("glPixelTransformParameteriEXT");
	GLM_struct->glPixelTransformParameterfEXTproc = (PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)wglGetProcAddress("glPixelTransformParameterfEXT");
	GLM_struct->glPixelTransformParameterivEXTproc = (PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)wglGetProcAddress("glPixelTransformParameterivEXT");
	GLM_struct->glPixelTransformParameterfvEXTproc = (PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)wglGetProcAddress("glPixelTransformParameterfvEXT");
	GLM_struct->glGetPixelTransformParameterivEXTproc = (PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)wglGetProcAddress("glGetPixelTransformParameterivEXT");
	GLM_struct->glGetPixelTransformParameterfvEXTproc = (PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)wglGetProcAddress("glGetPixelTransformParameterfvEXT");
	GLM_struct->glPointParameterfEXTproc = (PFNGLPOINTPARAMETERFEXTPROC)wglGetProcAddress("glPointParameterfEXT");
	GLM_struct->glPointParameterfvEXTproc = (PFNGLPOINTPARAMETERFVEXTPROC)wglGetProcAddress("glPointParameterfvEXT");
	GLM_struct->glPolygonOffsetEXTproc = (PFNGLPOLYGONOFFSETEXTPROC)wglGetProcAddress("glPolygonOffsetEXT");
	GLM_struct->glPolygonOffsetClampEXTproc = (PFNGLPOLYGONOFFSETCLAMPEXTPROC)wglGetProcAddress("glPolygonOffsetClampEXT");
	GLM_struct->glProvokingVertexEXTproc = (PFNGLPROVOKINGVERTEXEXTPROC)wglGetProcAddress("glProvokingVertexEXT");
	GLM_struct->glRasterSamplesEXTproc = (PFNGLRASTERSAMPLESEXTPROC)wglGetProcAddress("glRasterSamplesEXT");
	GLM_struct->glSecondaryColor3bEXTproc = (PFNGLSECONDARYCOLOR3BEXTPROC)wglGetProcAddress("glSecondaryColor3bEXT");
	GLM_struct->glSecondaryColor3bvEXTproc = (PFNGLSECONDARYCOLOR3BVEXTPROC)wglGetProcAddress("glSecondaryColor3bvEXT");
	GLM_struct->glSecondaryColor3dEXTproc = (PFNGLSECONDARYCOLOR3DEXTPROC)wglGetProcAddress("glSecondaryColor3dEXT");
	GLM_struct->glSecondaryColor3dvEXTproc = (PFNGLSECONDARYCOLOR3DVEXTPROC)wglGetProcAddress("glSecondaryColor3dvEXT");
	GLM_struct->glSecondaryColor3fEXTproc = (PFNGLSECONDARYCOLOR3FEXTPROC)wglGetProcAddress("glSecondaryColor3fEXT");
	GLM_struct->glSecondaryColor3fvEXTproc = (PFNGLSECONDARYCOLOR3FVEXTPROC)wglGetProcAddress("glSecondaryColor3fvEXT");
	GLM_struct->glSecondaryColor3iEXTproc = (PFNGLSECONDARYCOLOR3IEXTPROC)wglGetProcAddress("glSecondaryColor3iEXT");
	GLM_struct->glSecondaryColor3ivEXTproc = (PFNGLSECONDARYCOLOR3IVEXTPROC)wglGetProcAddress("glSecondaryColor3ivEXT");
	GLM_struct->glSecondaryColor3sEXTproc = (PFNGLSECONDARYCOLOR3SEXTPROC)wglGetProcAddress("glSecondaryColor3sEXT");
	GLM_struct->glSecondaryColor3svEXTproc = (PFNGLSECONDARYCOLOR3SVEXTPROC)wglGetProcAddress("glSecondaryColor3svEXT");
	GLM_struct->glSecondaryColor3ubEXTproc = (PFNGLSECONDARYCOLOR3UBEXTPROC)wglGetProcAddress("glSecondaryColor3ubEXT");
	GLM_struct->glSecondaryColor3ubvEXTproc = (PFNGLSECONDARYCOLOR3UBVEXTPROC)wglGetProcAddress("glSecondaryColor3ubvEXT");
	GLM_struct->glSecondaryColor3uiEXTproc = (PFNGLSECONDARYCOLOR3UIEXTPROC)wglGetProcAddress("glSecondaryColor3uiEXT");
	GLM_struct->glSecondaryColor3uivEXTproc = (PFNGLSECONDARYCOLOR3UIVEXTPROC)wglGetProcAddress("glSecondaryColor3uivEXT");
	GLM_struct->glSecondaryColor3usEXTproc = (PFNGLSECONDARYCOLOR3USEXTPROC)wglGetProcAddress("glSecondaryColor3usEXT");
	GLM_struct->glSecondaryColor3usvEXTproc = (PFNGLSECONDARYCOLOR3USVEXTPROC)wglGetProcAddress("glSecondaryColor3usvEXT");
	GLM_struct->glSecondaryColorPointerEXTproc = (PFNGLSECONDARYCOLORPOINTEREXTPROC)wglGetProcAddress("glSecondaryColorPointerEXT");
	GLM_struct->glGenSemaphoresEXTproc = (PFNGLGENSEMAPHORESEXTPROC)wglGetProcAddress("glGenSemaphoresEXT");
	GLM_struct->glDeleteSemaphoresEXTproc = (PFNGLDELETESEMAPHORESEXTPROC)wglGetProcAddress("glDeleteSemaphoresEXT");
	GLM_struct->glIsSemaphoreEXTproc = (PFNGLISSEMAPHOREEXTPROC)wglGetProcAddress("glIsSemaphoreEXT");
	GLM_struct->glSemaphoreParameterui64vEXTproc = (PFNGLSEMAPHOREPARAMETERUI64VEXTPROC)wglGetProcAddress("glSemaphoreParameterui64vEXT");
	GLM_struct->glGetSemaphoreParameterui64vEXTproc = (PFNGLGETSEMAPHOREPARAMETERUI64VEXTPROC)wglGetProcAddress("glGetSemaphoreParameterui64vEXT");
	GLM_struct->glWaitSemaphoreEXTproc = (PFNGLWAITSEMAPHOREEXTPROC)wglGetProcAddress("glWaitSemaphoreEXT");
	GLM_struct->glSignalSemaphoreEXTproc = (PFNGLSIGNALSEMAPHOREEXTPROC)wglGetProcAddress("glSignalSemaphoreEXT");
	GLM_struct->glImportSemaphoreFdEXTproc = (PFNGLIMPORTSEMAPHOREFDEXTPROC)wglGetProcAddress("glImportSemaphoreFdEXT");
	GLM_struct->glImportSemaphoreWin32HandleEXTproc = (PFNGLIMPORTSEMAPHOREWIN32HANDLEEXTPROC)wglGetProcAddress("glImportSemaphoreWin32HandleEXT");
	GLM_struct->glImportSemaphoreWin32NameEXTproc = (PFNGLIMPORTSEMAPHOREWIN32NAMEEXTPROC)wglGetProcAddress("glImportSemaphoreWin32NameEXT");
	GLM_struct->glUseShaderProgramEXTproc = (PFNGLUSESHADERPROGRAMEXTPROC)wglGetProcAddress("glUseShaderProgramEXT");
	GLM_struct->glActiveProgramEXTproc = (PFNGLACTIVEPROGRAMEXTPROC)wglGetProcAddress("glActiveProgramEXT");
	GLM_struct->glCreateShaderProgramEXTproc = (PFNGLCREATESHADERPROGRAMEXTPROC)wglGetProcAddress("glCreateShaderProgramEXT");
	GLM_struct->glFramebufferFetchBarrierEXTproc = (PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC)wglGetProcAddress("glFramebufferFetchBarrierEXT");
	GLM_struct->glBindImageTextureEXTproc = (PFNGLBINDIMAGETEXTUREEXTPROC)wglGetProcAddress("glBindImageTextureEXT");
	GLM_struct->glMemoryBarrierEXTproc = (PFNGLMEMORYBARRIEREXTPROC)wglGetProcAddress("glMemoryBarrierEXT");
	GLM_struct->glStencilClearTagEXTproc = (PFNGLSTENCILCLEARTAGEXTPROC)wglGetProcAddress("glStencilClearTagEXT");
	GLM_struct->glActiveStencilFaceEXTproc = (PFNGLACTIVESTENCILFACEEXTPROC)wglGetProcAddress("glActiveStencilFaceEXT");
	GLM_struct->glTexSubImage1DEXTproc = (PFNGLTEXSUBIMAGE1DEXTPROC)wglGetProcAddress("glTexSubImage1DEXT");
	GLM_struct->glTexSubImage2DEXTproc = (PFNGLTEXSUBIMAGE2DEXTPROC)wglGetProcAddress("glTexSubImage2DEXT");
	GLM_struct->glTexImage3DEXTproc = (PFNGLTEXIMAGE3DEXTPROC)wglGetProcAddress("glTexImage3DEXT");
	GLM_struct->glTexSubImage3DEXTproc = (PFNGLTEXSUBIMAGE3DEXTPROC)wglGetProcAddress("glTexSubImage3DEXT");
	GLM_struct->glFramebufferTextureLayerEXTproc = (PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)wglGetProcAddress("glFramebufferTextureLayerEXT");
	GLM_struct->glTexBufferEXTproc = (PFNGLTEXBUFFEREXTPROC)wglGetProcAddress("glTexBufferEXT");
	GLM_struct->glTexParameterIivEXTproc = (PFNGLTEXPARAMETERIIVEXTPROC)wglGetProcAddress("glTexParameterIivEXT");
	GLM_struct->glTexParameterIuivEXTproc = (PFNGLTEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glTexParameterIuivEXT");
	GLM_struct->glGetTexParameterIivEXTproc = (PFNGLGETTEXPARAMETERIIVEXTPROC)wglGetProcAddress("glGetTexParameterIivEXT");
	GLM_struct->glGetTexParameterIuivEXTproc = (PFNGLGETTEXPARAMETERIUIVEXTPROC)wglGetProcAddress("glGetTexParameterIuivEXT");
	GLM_struct->glClearColorIiEXTproc = (PFNGLCLEARCOLORIIEXTPROC)wglGetProcAddress("glClearColorIiEXT");
	GLM_struct->glClearColorIuiEXTproc = (PFNGLCLEARCOLORIUIEXTPROC)wglGetProcAddress("glClearColorIuiEXT");
	GLM_struct->glAreTexturesResidentEXTproc = (PFNGLARETEXTURESRESIDENTEXTPROC)wglGetProcAddress("glAreTexturesResidentEXT");
	GLM_struct->glBindTextureEXTproc = (PFNGLBINDTEXTUREEXTPROC)wglGetProcAddress("glBindTextureEXT");
	GLM_struct->glDeleteTexturesEXTproc = (PFNGLDELETETEXTURESEXTPROC)wglGetProcAddress("glDeleteTexturesEXT");
	GLM_struct->glGenTexturesEXTproc = (PFNGLGENTEXTURESEXTPROC)wglGetProcAddress("glGenTexturesEXT");
	GLM_struct->glIsTextureEXTproc = (PFNGLISTEXTUREEXTPROC)wglGetProcAddress("glIsTextureEXT");
	GLM_struct->glPrioritizeTexturesEXTproc = (PFNGLPRIORITIZETEXTURESEXTPROC)wglGetProcAddress("glPrioritizeTexturesEXT");
	GLM_struct->glTextureNormalEXTproc = (PFNGLTEXTURENORMALEXTPROC)wglGetProcAddress("glTextureNormalEXT");
	GLM_struct->glTexStorage1DEXTproc = (PFNGLTEXSTORAGE1DEXTPROC)wglGetProcAddress("glTexStorage1DEXT");
	GLM_struct->glTexStorage2DEXTproc = (PFNGLTEXSTORAGE2DEXTPROC)wglGetProcAddress("glTexStorage2DEXT");
	GLM_struct->glTexStorage3DEXTproc = (PFNGLTEXSTORAGE3DEXTPROC)wglGetProcAddress("glTexStorage3DEXT");
	GLM_struct->glGetQueryObjecti64vEXTproc = (PFNGLGETQUERYOBJECTI64VEXTPROC)wglGetProcAddress("glGetQueryObjecti64vEXT");
	GLM_struct->glGetQueryObjectui64vEXTproc = (PFNGLGETQUERYOBJECTUI64VEXTPROC)wglGetProcAddress("glGetQueryObjectui64vEXT");
	GLM_struct->glBeginTransformFeedbackEXTproc = (PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)wglGetProcAddress("glBeginTransformFeedbackEXT");
	GLM_struct->glEndTransformFeedbackEXTproc = (PFNGLENDTRANSFORMFEEDBACKEXTPROC)wglGetProcAddress("glEndTransformFeedbackEXT");
	GLM_struct->glBindBufferRangeEXTproc = (PFNGLBINDBUFFERRANGEEXTPROC)wglGetProcAddress("glBindBufferRangeEXT");
	GLM_struct->glBindBufferOffsetEXTproc = (PFNGLBINDBUFFEROFFSETEXTPROC)wglGetProcAddress("glBindBufferOffsetEXT");
	GLM_struct->glBindBufferBaseEXTproc = (PFNGLBINDBUFFERBASEEXTPROC)wglGetProcAddress("glBindBufferBaseEXT");
	GLM_struct->glTransformFeedbackVaryingsEXTproc = (PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)wglGetProcAddress("glTransformFeedbackVaryingsEXT");
	GLM_struct->glGetTransformFeedbackVaryingEXTproc = (PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)wglGetProcAddress("glGetTransformFeedbackVaryingEXT");
	GLM_struct->glArrayElementEXTproc = (PFNGLARRAYELEMENTEXTPROC)wglGetProcAddress("glArrayElementEXT");
	GLM_struct->glColorPointerEXTproc = (PFNGLCOLORPOINTEREXTPROC)wglGetProcAddress("glColorPointerEXT");
	GLM_struct->glDrawArraysEXTproc = (PFNGLDRAWARRAYSEXTPROC)wglGetProcAddress("glDrawArraysEXT");
	GLM_struct->glEdgeFlagPointerEXTproc = (PFNGLEDGEFLAGPOINTEREXTPROC)wglGetProcAddress("glEdgeFlagPointerEXT");
	GLM_struct->glGetPointervEXTproc = (PFNGLGETPOINTERVEXTPROC)wglGetProcAddress("glGetPointervEXT");
	GLM_struct->glIndexPointerEXTproc = (PFNGLINDEXPOINTEREXTPROC)wglGetProcAddress("glIndexPointerEXT");
	GLM_struct->glNormalPointerEXTproc = (PFNGLNORMALPOINTEREXTPROC)wglGetProcAddress("glNormalPointerEXT");
	GLM_struct->glTexCoordPointerEXTproc = (PFNGLTEXCOORDPOINTEREXTPROC)wglGetProcAddress("glTexCoordPointerEXT");
	GLM_struct->glVertexPointerEXTproc = (PFNGLVERTEXPOINTEREXTPROC)wglGetProcAddress("glVertexPointerEXT");
	GLM_struct->glVertexAttribL1dEXTproc = (PFNGLVERTEXATTRIBL1DEXTPROC)wglGetProcAddress("glVertexAttribL1dEXT");
	GLM_struct->glVertexAttribL2dEXTproc = (PFNGLVERTEXATTRIBL2DEXTPROC)wglGetProcAddress("glVertexAttribL2dEXT");
	GLM_struct->glVertexAttribL3dEXTproc = (PFNGLVERTEXATTRIBL3DEXTPROC)wglGetProcAddress("glVertexAttribL3dEXT");
	GLM_struct->glVertexAttribL4dEXTproc = (PFNGLVERTEXATTRIBL4DEXTPROC)wglGetProcAddress("glVertexAttribL4dEXT");
	GLM_struct->glVertexAttribL1dvEXTproc = (PFNGLVERTEXATTRIBL1DVEXTPROC)wglGetProcAddress("glVertexAttribL1dvEXT");
	GLM_struct->glVertexAttribL2dvEXTproc = (PFNGLVERTEXATTRIBL2DVEXTPROC)wglGetProcAddress("glVertexAttribL2dvEXT");
	GLM_struct->glVertexAttribL3dvEXTproc = (PFNGLVERTEXATTRIBL3DVEXTPROC)wglGetProcAddress("glVertexAttribL3dvEXT");
	GLM_struct->glVertexAttribL4dvEXTproc = (PFNGLVERTEXATTRIBL4DVEXTPROC)wglGetProcAddress("glVertexAttribL4dvEXT");
	GLM_struct->glVertexAttribLPointerEXTproc = (PFNGLVERTEXATTRIBLPOINTEREXTPROC)wglGetProcAddress("glVertexAttribLPointerEXT");
	GLM_struct->glGetVertexAttribLdvEXTproc = (PFNGLGETVERTEXATTRIBLDVEXTPROC)wglGetProcAddress("glGetVertexAttribLdvEXT");
	GLM_struct->glBeginVertexShaderEXTproc = (PFNGLBEGINVERTEXSHADEREXTPROC)wglGetProcAddress("glBeginVertexShaderEXT");
	GLM_struct->glEndVertexShaderEXTproc = (PFNGLENDVERTEXSHADEREXTPROC)wglGetProcAddress("glEndVertexShaderEXT");
	GLM_struct->glBindVertexShaderEXTproc = (PFNGLBINDVERTEXSHADEREXTPROC)wglGetProcAddress("glBindVertexShaderEXT");
	GLM_struct->glGenVertexShadersEXTproc = (PFNGLGENVERTEXSHADERSEXTPROC)wglGetProcAddress("glGenVertexShadersEXT");
	GLM_struct->glDeleteVertexShaderEXTproc = (PFNGLDELETEVERTEXSHADEREXTPROC)wglGetProcAddress("glDeleteVertexShaderEXT");
	GLM_struct->glShaderOp1EXTproc = (PFNGLSHADEROP1EXTPROC)wglGetProcAddress("glShaderOp1EXT");
	GLM_struct->glShaderOp2EXTproc = (PFNGLSHADEROP2EXTPROC)wglGetProcAddress("glShaderOp2EXT");
	GLM_struct->glShaderOp3EXTproc = (PFNGLSHADEROP3EXTPROC)wglGetProcAddress("glShaderOp3EXT");
	GLM_struct->glSwizzleEXTproc = (PFNGLSWIZZLEEXTPROC)wglGetProcAddress("glSwizzleEXT");
	GLM_struct->glWriteMaskEXTproc = (PFNGLWRITEMASKEXTPROC)wglGetProcAddress("glWriteMaskEXT");
	GLM_struct->glInsertComponentEXTproc = (PFNGLINSERTCOMPONENTEXTPROC)wglGetProcAddress("glInsertComponentEXT");
	GLM_struct->glExtractComponentEXTproc = (PFNGLEXTRACTCOMPONENTEXTPROC)wglGetProcAddress("glExtractComponentEXT");
	GLM_struct->glGenSymbolsEXTproc = (PFNGLGENSYMBOLSEXTPROC)wglGetProcAddress("glGenSymbolsEXT");
	GLM_struct->glSetInvariantEXTproc = (PFNGLSETINVARIANTEXTPROC)wglGetProcAddress("glSetInvariantEXT");
	GLM_struct->glSetLocalConstantEXTproc = (PFNGLSETLOCALCONSTANTEXTPROC)wglGetProcAddress("glSetLocalConstantEXT");
	GLM_struct->glVariantbvEXTproc = (PFNGLVARIANTBVEXTPROC)wglGetProcAddress("glVariantbvEXT");
	GLM_struct->glVariantsvEXTproc = (PFNGLVARIANTSVEXTPROC)wglGetProcAddress("glVariantsvEXT");
	GLM_struct->glVariantivEXTproc = (PFNGLVARIANTIVEXTPROC)wglGetProcAddress("glVariantivEXT");
	GLM_struct->glVariantfvEXTproc = (PFNGLVARIANTFVEXTPROC)wglGetProcAddress("glVariantfvEXT");
	GLM_struct->glVariantdvEXTproc = (PFNGLVARIANTDVEXTPROC)wglGetProcAddress("glVariantdvEXT");
	GLM_struct->glVariantubvEXTproc = (PFNGLVARIANTUBVEXTPROC)wglGetProcAddress("glVariantubvEXT");
	GLM_struct->glVariantusvEXTproc = (PFNGLVARIANTUSVEXTPROC)wglGetProcAddress("glVariantusvEXT");
	GLM_struct->glVariantuivEXTproc = (PFNGLVARIANTUIVEXTPROC)wglGetProcAddress("glVariantuivEXT");
	GLM_struct->glVariantPointerEXTproc = (PFNGLVARIANTPOINTEREXTPROC)wglGetProcAddress("glVariantPointerEXT");
	GLM_struct->glEnableVariantClientStateEXTproc = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)wglGetProcAddress("glEnableVariantClientStateEXT");
	GLM_struct->glDisableVariantClientStateEXTproc = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)wglGetProcAddress("glDisableVariantClientStateEXT");
	GLM_struct->glBindLightParameterEXTproc = (PFNGLBINDLIGHTPARAMETEREXTPROC)wglGetProcAddress("glBindLightParameterEXT");
	GLM_struct->glBindMaterialParameterEXTproc = (PFNGLBINDMATERIALPARAMETEREXTPROC)wglGetProcAddress("glBindMaterialParameterEXT");
	GLM_struct->glBindTexGenParameterEXTproc = (PFNGLBINDTEXGENPARAMETEREXTPROC)wglGetProcAddress("glBindTexGenParameterEXT");
	GLM_struct->glBindTextureUnitParameterEXTproc = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)wglGetProcAddress("glBindTextureUnitParameterEXT");
	GLM_struct->glBindParameterEXTproc = (PFNGLBINDPARAMETEREXTPROC)wglGetProcAddress("glBindParameterEXT");
	GLM_struct->glIsVariantEnabledEXTproc = (PFNGLISVARIANTENABLEDEXTPROC)wglGetProcAddress("glIsVariantEnabledEXT");
	GLM_struct->glGetVariantBooleanvEXTproc = (PFNGLGETVARIANTBOOLEANVEXTPROC)wglGetProcAddress("glGetVariantBooleanvEXT");
	GLM_struct->glGetVariantIntegervEXTproc = (PFNGLGETVARIANTINTEGERVEXTPROC)wglGetProcAddress("glGetVariantIntegervEXT");
	GLM_struct->glGetVariantFloatvEXTproc = (PFNGLGETVARIANTFLOATVEXTPROC)wglGetProcAddress("glGetVariantFloatvEXT");
	GLM_struct->glGetVariantPointervEXTproc = (PFNGLGETVARIANTPOINTERVEXTPROC)wglGetProcAddress("glGetVariantPointervEXT");
	GLM_struct->glGetInvariantBooleanvEXTproc = (PFNGLGETINVARIANTBOOLEANVEXTPROC)wglGetProcAddress("glGetInvariantBooleanvEXT");
	GLM_struct->glGetInvariantIntegervEXTproc = (PFNGLGETINVARIANTINTEGERVEXTPROC)wglGetProcAddress("glGetInvariantIntegervEXT");
	GLM_struct->glGetInvariantFloatvEXTproc = (PFNGLGETINVARIANTFLOATVEXTPROC)wglGetProcAddress("glGetInvariantFloatvEXT");
	GLM_struct->glGetLocalConstantBooleanvEXTproc = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)wglGetProcAddress("glGetLocalConstantBooleanvEXT");
	GLM_struct->glGetLocalConstantIntegervEXTproc = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)wglGetProcAddress("glGetLocalConstantIntegervEXT");
	GLM_struct->glGetLocalConstantFloatvEXTproc = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC)wglGetProcAddress("glGetLocalConstantFloatvEXT");
	GLM_struct->glVertexWeightfEXTproc = (PFNGLVERTEXWEIGHTFEXTPROC)wglGetProcAddress("glVertexWeightfEXT");
	GLM_struct->glVertexWeightfvEXTproc = (PFNGLVERTEXWEIGHTFVEXTPROC)wglGetProcAddress("glVertexWeightfvEXT");
	GLM_struct->glVertexWeightPointerEXTproc = (PFNGLVERTEXWEIGHTPOINTEREXTPROC)wglGetProcAddress("glVertexWeightPointerEXT");
	GLM_struct->glAcquireKeyedMutexWin32EXTproc = (PFNGLACQUIREKEYEDMUTEXWIN32EXTPROC)wglGetProcAddress("glAcquireKeyedMutexWin32EXT");
	GLM_struct->glReleaseKeyedMutexWin32EXTproc = (PFNGLRELEASEKEYEDMUTEXWIN32EXTPROC)wglGetProcAddress("glReleaseKeyedMutexWin32EXT");
	GLM_struct->glWindowRectanglesEXTproc = (PFNGLWINDOWRECTANGLESEXTPROC)wglGetProcAddress("glWindowRectanglesEXT");
	GLM_struct->glImportSyncEXTproc = (PFNGLIMPORTSYNCEXTPROC)wglGetProcAddress("glImportSyncEXT");
	GLM_struct->glFrameTerminatorGREMEDYproc = (PFNGLFRAMETERMINATORGREMEDYPROC)wglGetProcAddress("glFrameTerminatorGREMEDY");
	GLM_struct->glStringMarkerGREMEDYproc = (PFNGLSTRINGMARKERGREMEDYPROC)wglGetProcAddress("glStringMarkerGREMEDY");
	GLM_struct->glImageTransformParameteriHPproc = (PFNGLIMAGETRANSFORMPARAMETERIHPPROC)wglGetProcAddress("glImageTransformParameteriHP");
	GLM_struct->glImageTransformParameterfHPproc = (PFNGLIMAGETRANSFORMPARAMETERFHPPROC)wglGetProcAddress("glImageTransformParameterfHP");
	GLM_struct->glImageTransformParameterivHPproc = (PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)wglGetProcAddress("glImageTransformParameterivHP");
	GLM_struct->glImageTransformParameterfvHPproc = (PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)wglGetProcAddress("glImageTransformParameterfvHP");
	GLM_struct->glGetImageTransformParameterivHPproc = (PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)wglGetProcAddress("glGetImageTransformParameterivHP");
	GLM_struct->glGetImageTransformParameterfvHPproc = (PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)wglGetProcAddress("glGetImageTransformParameterfvHP");
	GLM_struct->glMultiModeDrawArraysIBMproc = (PFNGLMULTIMODEDRAWARRAYSIBMPROC)wglGetProcAddress("glMultiModeDrawArraysIBM");
	GLM_struct->glMultiModeDrawElementsIBMproc = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC)wglGetProcAddress("glMultiModeDrawElementsIBM");
	GLM_struct->glFlushStaticDataIBMproc = (PFNGLFLUSHSTATICDATAIBMPROC)wglGetProcAddress("glFlushStaticDataIBM");
	GLM_struct->glColorPointerListIBMproc = (PFNGLCOLORPOINTERLISTIBMPROC)wglGetProcAddress("glColorPointerListIBM");
	GLM_struct->glSecondaryColorPointerListIBMproc = (PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)wglGetProcAddress("glSecondaryColorPointerListIBM");
	GLM_struct->glEdgeFlagPointerListIBMproc = (PFNGLEDGEFLAGPOINTERLISTIBMPROC)wglGetProcAddress("glEdgeFlagPointerListIBM");
	GLM_struct->glFogCoordPointerListIBMproc = (PFNGLFOGCOORDPOINTERLISTIBMPROC)wglGetProcAddress("glFogCoordPointerListIBM");
	GLM_struct->glIndexPointerListIBMproc = (PFNGLINDEXPOINTERLISTIBMPROC)wglGetProcAddress("glIndexPointerListIBM");
	GLM_struct->glNormalPointerListIBMproc = (PFNGLNORMALPOINTERLISTIBMPROC)wglGetProcAddress("glNormalPointerListIBM");
	GLM_struct->glTexCoordPointerListIBMproc = (PFNGLTEXCOORDPOINTERLISTIBMPROC)wglGetProcAddress("glTexCoordPointerListIBM");
	GLM_struct->glVertexPointerListIBMproc = (PFNGLVERTEXPOINTERLISTIBMPROC)wglGetProcAddress("glVertexPointerListIBM");
	GLM_struct->glBlendFuncSeparateINGRproc = (PFNGLBLENDFUNCSEPARATEINGRPROC)wglGetProcAddress("glBlendFuncSeparateINGR");
	GLM_struct->glApplyFramebufferAttachmentCMAAINTELproc = (PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC)wglGetProcAddress("glApplyFramebufferAttachmentCMAAINTEL");
	GLM_struct->glSyncTextureINTELproc = (PFNGLSYNCTEXTUREINTELPROC)wglGetProcAddress("glSyncTextureINTEL");
	GLM_struct->glUnmapTexture2DINTELproc = (PFNGLUNMAPTEXTURE2DINTELPROC)wglGetProcAddress("glUnmapTexture2DINTEL");
	GLM_struct->glMapTexture2DINTELproc = (PFNGLMAPTEXTURE2DINTELPROC)wglGetProcAddress("glMapTexture2DINTEL");
	GLM_struct->glVertexPointervINTELproc = (PFNGLVERTEXPOINTERVINTELPROC)wglGetProcAddress("glVertexPointervINTEL");
	GLM_struct->glNormalPointervINTELproc = (PFNGLNORMALPOINTERVINTELPROC)wglGetProcAddress("glNormalPointervINTEL");
	GLM_struct->glColorPointervINTELproc = (PFNGLCOLORPOINTERVINTELPROC)wglGetProcAddress("glColorPointervINTEL");
	GLM_struct->glTexCoordPointervINTELproc = (PFNGLTEXCOORDPOINTERVINTELPROC)wglGetProcAddress("glTexCoordPointervINTEL");
	GLM_struct->glBeginPerfQueryINTELproc = (PFNGLBEGINPERFQUERYINTELPROC)wglGetProcAddress("glBeginPerfQueryINTEL");
	GLM_struct->glCreatePerfQueryINTELproc = (PFNGLCREATEPERFQUERYINTELPROC)wglGetProcAddress("glCreatePerfQueryINTEL");
	GLM_struct->glDeletePerfQueryINTELproc = (PFNGLDELETEPERFQUERYINTELPROC)wglGetProcAddress("glDeletePerfQueryINTEL");
	GLM_struct->glEndPerfQueryINTELproc = (PFNGLENDPERFQUERYINTELPROC)wglGetProcAddress("glEndPerfQueryINTEL");
	GLM_struct->glGetFirstPerfQueryIdINTELproc = (PFNGLGETFIRSTPERFQUERYIDINTELPROC)wglGetProcAddress("glGetFirstPerfQueryIdINTEL");
	GLM_struct->glGetNextPerfQueryIdINTELproc = (PFNGLGETNEXTPERFQUERYIDINTELPROC)wglGetProcAddress("glGetNextPerfQueryIdINTEL");
	GLM_struct->glGetPerfCounterInfoINTELproc = (PFNGLGETPERFCOUNTERINFOINTELPROC)wglGetProcAddress("glGetPerfCounterInfoINTEL");
	GLM_struct->glGetPerfQueryDataINTELproc = (PFNGLGETPERFQUERYDATAINTELPROC)wglGetProcAddress("glGetPerfQueryDataINTEL");
	GLM_struct->glGetPerfQueryIdByNameINTELproc = (PFNGLGETPERFQUERYIDBYNAMEINTELPROC)wglGetProcAddress("glGetPerfQueryIdByNameINTEL");
	GLM_struct->glGetPerfQueryInfoINTELproc = (PFNGLGETPERFQUERYINFOINTELPROC)wglGetProcAddress("glGetPerfQueryInfoINTEL");
	GLM_struct->glFramebufferParameteriMESAproc = (PFNGLFRAMEBUFFERPARAMETERIMESAPROC)wglGetProcAddress("glFramebufferParameteriMESA");
	GLM_struct->glGetFramebufferParameterivMESAproc = (PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC)wglGetProcAddress("glGetFramebufferParameterivMESA");
	GLM_struct->glResizeBuffersMESAproc = (PFNGLRESIZEBUFFERSMESAPROC)wglGetProcAddress("glResizeBuffersMESA");
	GLM_struct->glWindowPos2dMESAproc = (PFNGLWINDOWPOS2DMESAPROC)wglGetProcAddress("glWindowPos2dMESA");
	GLM_struct->glWindowPos2dvMESAproc = (PFNGLWINDOWPOS2DVMESAPROC)wglGetProcAddress("glWindowPos2dvMESA");
	GLM_struct->glWindowPos2fMESAproc = (PFNGLWINDOWPOS2FMESAPROC)wglGetProcAddress("glWindowPos2fMESA");
	GLM_struct->glWindowPos2fvMESAproc = (PFNGLWINDOWPOS2FVMESAPROC)wglGetProcAddress("glWindowPos2fvMESA");
	GLM_struct->glWindowPos2iMESAproc = (PFNGLWINDOWPOS2IMESAPROC)wglGetProcAddress("glWindowPos2iMESA");
	GLM_struct->glWindowPos2ivMESAproc = (PFNGLWINDOWPOS2IVMESAPROC)wglGetProcAddress("glWindowPos2ivMESA");
	GLM_struct->glWindowPos2sMESAproc = (PFNGLWINDOWPOS2SMESAPROC)wglGetProcAddress("glWindowPos2sMESA");
	GLM_struct->glWindowPos2svMESAproc = (PFNGLWINDOWPOS2SVMESAPROC)wglGetProcAddress("glWindowPos2svMESA");
	GLM_struct->glWindowPos3dMESAproc = (PFNGLWINDOWPOS3DMESAPROC)wglGetProcAddress("glWindowPos3dMESA");
	GLM_struct->glWindowPos3dvMESAproc = (PFNGLWINDOWPOS3DVMESAPROC)wglGetProcAddress("glWindowPos3dvMESA");
	GLM_struct->glWindowPos3fMESAproc = (PFNGLWINDOWPOS3FMESAPROC)wglGetProcAddress("glWindowPos3fMESA");
	GLM_struct->glWindowPos3fvMESAproc = (PFNGLWINDOWPOS3FVMESAPROC)wglGetProcAddress("glWindowPos3fvMESA");
	GLM_struct->glWindowPos3iMESAproc = (PFNGLWINDOWPOS3IMESAPROC)wglGetProcAddress("glWindowPos3iMESA");
	GLM_struct->glWindowPos3ivMESAproc = (PFNGLWINDOWPOS3IVMESAPROC)wglGetProcAddress("glWindowPos3ivMESA");
	GLM_struct->glWindowPos3sMESAproc = (PFNGLWINDOWPOS3SMESAPROC)wglGetProcAddress("glWindowPos3sMESA");
	GLM_struct->glWindowPos3svMESAproc = (PFNGLWINDOWPOS3SVMESAPROC)wglGetProcAddress("glWindowPos3svMESA");
	GLM_struct->glWindowPos4dMESAproc = (PFNGLWINDOWPOS4DMESAPROC)wglGetProcAddress("glWindowPos4dMESA");
	GLM_struct->glWindowPos4dvMESAproc = (PFNGLWINDOWPOS4DVMESAPROC)wglGetProcAddress("glWindowPos4dvMESA");
	GLM_struct->glWindowPos4fMESAproc = (PFNGLWINDOWPOS4FMESAPROC)wglGetProcAddress("glWindowPos4fMESA");
	GLM_struct->glWindowPos4fvMESAproc = (PFNGLWINDOWPOS4FVMESAPROC)wglGetProcAddress("glWindowPos4fvMESA");
	GLM_struct->glWindowPos4iMESAproc = (PFNGLWINDOWPOS4IMESAPROC)wglGetProcAddress("glWindowPos4iMESA");
	GLM_struct->glWindowPos4ivMESAproc = (PFNGLWINDOWPOS4IVMESAPROC)wglGetProcAddress("glWindowPos4ivMESA");
	GLM_struct->glWindowPos4sMESAproc = (PFNGLWINDOWPOS4SMESAPROC)wglGetProcAddress("glWindowPos4sMESA");
	GLM_struct->glWindowPos4svMESAproc = (PFNGLWINDOWPOS4SVMESAPROC)wglGetProcAddress("glWindowPos4svMESA");
	GLM_struct->glBeginConditionalRenderNVXproc = (PFNGLBEGINCONDITIONALRENDERNVXPROC)wglGetProcAddress("glBeginConditionalRenderNVX");
	GLM_struct->glEndConditionalRenderNVXproc = (PFNGLENDCONDITIONALRENDERNVXPROC)wglGetProcAddress("glEndConditionalRenderNVX");
	GLM_struct->glUploadGpuMaskNVXproc = (PFNGLUPLOADGPUMASKNVXPROC)wglGetProcAddress("glUploadGpuMaskNVX");
	GLM_struct->glMulticastViewportArrayvNVXproc = (PFNGLMULTICASTVIEWPORTARRAYVNVXPROC)wglGetProcAddress("glMulticastViewportArrayvNVX");
	GLM_struct->glMulticastViewportPositionWScaleNVXproc = (PFNGLMULTICASTVIEWPORTPOSITIONWSCALENVXPROC)wglGetProcAddress("glMulticastViewportPositionWScaleNVX");
	GLM_struct->glMulticastScissorArrayvNVXproc = (PFNGLMULTICASTSCISSORARRAYVNVXPROC)wglGetProcAddress("glMulticastScissorArrayvNVX");
	GLM_struct->glAsyncCopyBufferSubDataNVXproc = (PFNGLASYNCCOPYBUFFERSUBDATANVXPROC)wglGetProcAddress("glAsyncCopyBufferSubDataNVX");
	GLM_struct->glAsyncCopyImageSubDataNVXproc = (PFNGLASYNCCOPYIMAGESUBDATANVXPROC)wglGetProcAddress("glAsyncCopyImageSubDataNVX");
	GLM_struct->glLGPUNamedBufferSubDataNVXproc = (PFNGLLGPUNAMEDBUFFERSUBDATANVXPROC)wglGetProcAddress("glLGPUNamedBufferSubDataNVX");
	GLM_struct->glLGPUCopyImageSubDataNVXproc = (PFNGLLGPUCOPYIMAGESUBDATANVXPROC)wglGetProcAddress("glLGPUCopyImageSubDataNVX");
	GLM_struct->glLGPUInterlockNVXproc = (PFNGLLGPUINTERLOCKNVXPROC)wglGetProcAddress("glLGPUInterlockNVX");
	GLM_struct->glCreateProgressFenceNVXproc = (PFNGLCREATEPROGRESSFENCENVXPROC)wglGetProcAddress("glCreateProgressFenceNVX");
	GLM_struct->glSignalSemaphoreui64NVXproc = (PFNGLSIGNALSEMAPHOREUI64NVXPROC)wglGetProcAddress("glSignalSemaphoreui64NVX");
	GLM_struct->glWaitSemaphoreui64NVXproc = (PFNGLWAITSEMAPHOREUI64NVXPROC)wglGetProcAddress("glWaitSemaphoreui64NVX");
	GLM_struct->glClientWaitSemaphoreui64NVXproc = (PFNGLCLIENTWAITSEMAPHOREUI64NVXPROC)wglGetProcAddress("glClientWaitSemaphoreui64NVX");
	GLM_struct->glAlphaToCoverageDitherControlNVproc = (PFNGLALPHATOCOVERAGEDITHERCONTROLNVPROC)wglGetProcAddress("glAlphaToCoverageDitherControlNV");
	GLM_struct->glMultiDrawArraysIndirectBindlessNVproc = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)wglGetProcAddress("glMultiDrawArraysIndirectBindlessNV");
	GLM_struct->glMultiDrawElementsIndirectBindlessNVproc = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)wglGetProcAddress("glMultiDrawElementsIndirectBindlessNV");
	GLM_struct->glMultiDrawArraysIndirectBindlessCountNVproc = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)wglGetProcAddress("glMultiDrawArraysIndirectBindlessCountNV");
	GLM_struct->glMultiDrawElementsIndirectBindlessCountNVproc = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)wglGetProcAddress("glMultiDrawElementsIndirectBindlessCountNV");
	GLM_struct->glGetTextureHandleNVproc = (PFNGLGETTEXTUREHANDLENVPROC)wglGetProcAddress("glGetTextureHandleNV");
	GLM_struct->glGetTextureSamplerHandleNVproc = (PFNGLGETTEXTURESAMPLERHANDLENVPROC)wglGetProcAddress("glGetTextureSamplerHandleNV");
	GLM_struct->glMakeTextureHandleResidentNVproc = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)wglGetProcAddress("glMakeTextureHandleResidentNV");
	GLM_struct->glMakeTextureHandleNonResidentNVproc = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)wglGetProcAddress("glMakeTextureHandleNonResidentNV");
	GLM_struct->glGetImageHandleNVproc = (PFNGLGETIMAGEHANDLENVPROC)wglGetProcAddress("glGetImageHandleNV");
	GLM_struct->glMakeImageHandleResidentNVproc = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)wglGetProcAddress("glMakeImageHandleResidentNV");
	GLM_struct->glMakeImageHandleNonResidentNVproc = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)wglGetProcAddress("glMakeImageHandleNonResidentNV");
	GLM_struct->glUniformHandleui64NVproc = (PFNGLUNIFORMHANDLEUI64NVPROC)wglGetProcAddress("glUniformHandleui64NV");
	GLM_struct->glUniformHandleui64vNVproc = (PFNGLUNIFORMHANDLEUI64VNVPROC)wglGetProcAddress("glUniformHandleui64vNV");
	GLM_struct->glProgramUniformHandleui64NVproc = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)wglGetProcAddress("glProgramUniformHandleui64NV");
	GLM_struct->glProgramUniformHandleui64vNVproc = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)wglGetProcAddress("glProgramUniformHandleui64vNV");
	GLM_struct->glIsTextureHandleResidentNVproc = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)wglGetProcAddress("glIsTextureHandleResidentNV");
	GLM_struct->glIsImageHandleResidentNVproc = (PFNGLISIMAGEHANDLERESIDENTNVPROC)wglGetProcAddress("glIsImageHandleResidentNV");
	GLM_struct->glBlendParameteriNVproc = (PFNGLBLENDPARAMETERINVPROC)wglGetProcAddress("glBlendParameteriNV");
	GLM_struct->glBlendBarrierNVproc = (PFNGLBLENDBARRIERNVPROC)wglGetProcAddress("glBlendBarrierNV");
	GLM_struct->glViewportPositionWScaleNVproc = (PFNGLVIEWPORTPOSITIONWSCALENVPROC)wglGetProcAddress("glViewportPositionWScaleNV");
	GLM_struct->glCreateStatesNVproc = (PFNGLCREATESTATESNVPROC)wglGetProcAddress("glCreateStatesNV");
	GLM_struct->glDeleteStatesNVproc = (PFNGLDELETESTATESNVPROC)wglGetProcAddress("glDeleteStatesNV");
	GLM_struct->glIsStateNVproc = (PFNGLISSTATENVPROC)wglGetProcAddress("glIsStateNV");
	GLM_struct->glStateCaptureNVproc = (PFNGLSTATECAPTURENVPROC)wglGetProcAddress("glStateCaptureNV");
	GLM_struct->glGetCommandHeaderNVproc = (PFNGLGETCOMMANDHEADERNVPROC)wglGetProcAddress("glGetCommandHeaderNV");
	GLM_struct->glGetStageIndexNVproc = (PFNGLGETSTAGEINDEXNVPROC)wglGetProcAddress("glGetStageIndexNV");
	GLM_struct->glDrawCommandsNVproc = (PFNGLDRAWCOMMANDSNVPROC)wglGetProcAddress("glDrawCommandsNV");
	GLM_struct->glDrawCommandsAddressNVproc = (PFNGLDRAWCOMMANDSADDRESSNVPROC)wglGetProcAddress("glDrawCommandsAddressNV");
	GLM_struct->glDrawCommandsStatesNVproc = (PFNGLDRAWCOMMANDSSTATESNVPROC)wglGetProcAddress("glDrawCommandsStatesNV");
	GLM_struct->glDrawCommandsStatesAddressNVproc = (PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)wglGetProcAddress("glDrawCommandsStatesAddressNV");
	GLM_struct->glCreateCommandListsNVproc = (PFNGLCREATECOMMANDLISTSNVPROC)wglGetProcAddress("glCreateCommandListsNV");
	GLM_struct->glDeleteCommandListsNVproc = (PFNGLDELETECOMMANDLISTSNVPROC)wglGetProcAddress("glDeleteCommandListsNV");
	GLM_struct->glIsCommandListNVproc = (PFNGLISCOMMANDLISTNVPROC)wglGetProcAddress("glIsCommandListNV");
	GLM_struct->glListDrawCommandsStatesClientNVproc = (PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)wglGetProcAddress("glListDrawCommandsStatesClientNV");
	GLM_struct->glCommandListSegmentsNVproc = (PFNGLCOMMANDLISTSEGMENTSNVPROC)wglGetProcAddress("glCommandListSegmentsNV");
	GLM_struct->glCompileCommandListNVproc = (PFNGLCOMPILECOMMANDLISTNVPROC)wglGetProcAddress("glCompileCommandListNV");
	GLM_struct->glCallCommandListNVproc = (PFNGLCALLCOMMANDLISTNVPROC)wglGetProcAddress("glCallCommandListNV");
	GLM_struct->glBeginConditionalRenderNVproc = (PFNGLBEGINCONDITIONALRENDERNVPROC)wglGetProcAddress("glBeginConditionalRenderNV");
	GLM_struct->glEndConditionalRenderNVproc = (PFNGLENDCONDITIONALRENDERNVPROC)wglGetProcAddress("glEndConditionalRenderNV");
	GLM_struct->glSubpixelPrecisionBiasNVproc = (PFNGLSUBPIXELPRECISIONBIASNVPROC)wglGetProcAddress("glSubpixelPrecisionBiasNV");
	GLM_struct->glConservativeRasterParameterfNVproc = (PFNGLCONSERVATIVERASTERPARAMETERFNVPROC)wglGetProcAddress("glConservativeRasterParameterfNV");
	GLM_struct->glConservativeRasterParameteriNVproc = (PFNGLCONSERVATIVERASTERPARAMETERINVPROC)wglGetProcAddress("glConservativeRasterParameteriNV");
	GLM_struct->glCopyImageSubDataNVproc = (PFNGLCOPYIMAGESUBDATANVPROC)wglGetProcAddress("glCopyImageSubDataNV");
	GLM_struct->glDepthRangedNVproc = (PFNGLDEPTHRANGEDNVPROC)wglGetProcAddress("glDepthRangedNV");
	GLM_struct->glClearDepthdNVproc = (PFNGLCLEARDEPTHDNVPROC)wglGetProcAddress("glClearDepthdNV");
	GLM_struct->glDepthBoundsdNVproc = (PFNGLDEPTHBOUNDSDNVPROC)wglGetProcAddress("glDepthBoundsdNV");
	GLM_struct->glDrawTextureNVproc = (PFNGLDRAWTEXTURENVPROC)wglGetProcAddress("glDrawTextureNV");
	GLM_struct->glDrawVkImageNVproc = (PFNGLDRAWVKIMAGENVPROC)wglGetProcAddress("glDrawVkImageNV");
	GLM_struct->glGetVkProcAddrNVproc = (PFNGLGETVKPROCADDRNVPROC)wglGetProcAddress("glGetVkProcAddrNV");
	GLM_struct->glWaitVkSemaphoreNVproc = (PFNGLWAITVKSEMAPHORENVPROC)wglGetProcAddress("glWaitVkSemaphoreNV");
	GLM_struct->glSignalVkSemaphoreNVproc = (PFNGLSIGNALVKSEMAPHORENVPROC)wglGetProcAddress("glSignalVkSemaphoreNV");
	GLM_struct->glSignalVkFenceNVproc = (PFNGLSIGNALVKFENCENVPROC)wglGetProcAddress("glSignalVkFenceNV");
	GLM_struct->glMapControlPointsNVproc = (PFNGLMAPCONTROLPOINTSNVPROC)wglGetProcAddress("glMapControlPointsNV");
	GLM_struct->glMapParameterivNVproc = (PFNGLMAPPARAMETERIVNVPROC)wglGetProcAddress("glMapParameterivNV");
	GLM_struct->glMapParameterfvNVproc = (PFNGLMAPPARAMETERFVNVPROC)wglGetProcAddress("glMapParameterfvNV");
	GLM_struct->glGetMapControlPointsNVproc = (PFNGLGETMAPCONTROLPOINTSNVPROC)wglGetProcAddress("glGetMapControlPointsNV");
	GLM_struct->glGetMapParameterivNVproc = (PFNGLGETMAPPARAMETERIVNVPROC)wglGetProcAddress("glGetMapParameterivNV");
	GLM_struct->glGetMapParameterfvNVproc = (PFNGLGETMAPPARAMETERFVNVPROC)wglGetProcAddress("glGetMapParameterfvNV");
	GLM_struct->glGetMapAttribParameterivNVproc = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC)wglGetProcAddress("glGetMapAttribParameterivNV");
	GLM_struct->glGetMapAttribParameterfvNVproc = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC)wglGetProcAddress("glGetMapAttribParameterfvNV");
	GLM_struct->glEvalMapsNVproc = (PFNGLEVALMAPSNVPROC)wglGetProcAddress("glEvalMapsNV");
	GLM_struct->glGetMultisamplefvNVproc = (PFNGLGETMULTISAMPLEFVNVPROC)wglGetProcAddress("glGetMultisamplefvNV");
	GLM_struct->glSampleMaskIndexedNVproc = (PFNGLSAMPLEMASKINDEXEDNVPROC)wglGetProcAddress("glSampleMaskIndexedNV");
	GLM_struct->glTexRenderbufferNVproc = (PFNGLTEXRENDERBUFFERNVPROC)wglGetProcAddress("glTexRenderbufferNV");
	GLM_struct->glDeleteFencesNVproc = (PFNGLDELETEFENCESNVPROC)wglGetProcAddress("glDeleteFencesNV");
	GLM_struct->glGenFencesNVproc = (PFNGLGENFENCESNVPROC)wglGetProcAddress("glGenFencesNV");
	GLM_struct->glIsFenceNVproc = (PFNGLISFENCENVPROC)wglGetProcAddress("glIsFenceNV");
	GLM_struct->glTestFenceNVproc = (PFNGLTESTFENCENVPROC)wglGetProcAddress("glTestFenceNV");
	GLM_struct->glGetFenceivNVproc = (PFNGLGETFENCEIVNVPROC)wglGetProcAddress("glGetFenceivNV");
	GLM_struct->glFinishFenceNVproc = (PFNGLFINISHFENCENVPROC)wglGetProcAddress("glFinishFenceNV");
	GLM_struct->glSetFenceNVproc = (PFNGLSETFENCENVPROC)wglGetProcAddress("glSetFenceNV");
	GLM_struct->glFragmentCoverageColorNVproc = (PFNGLFRAGMENTCOVERAGECOLORNVPROC)wglGetProcAddress("glFragmentCoverageColorNV");
	GLM_struct->glProgramNamedParameter4fNVproc = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)wglGetProcAddress("glProgramNamedParameter4fNV");
	GLM_struct->glProgramNamedParameter4fvNVproc = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)wglGetProcAddress("glProgramNamedParameter4fvNV");
	GLM_struct->glProgramNamedParameter4dNVproc = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)wglGetProcAddress("glProgramNamedParameter4dNV");
	GLM_struct->glProgramNamedParameter4dvNVproc = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)wglGetProcAddress("glProgramNamedParameter4dvNV");
	GLM_struct->glGetProgramNamedParameterfvNVproc = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)wglGetProcAddress("glGetProgramNamedParameterfvNV");
	GLM_struct->glGetProgramNamedParameterdvNVproc = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)wglGetProcAddress("glGetProgramNamedParameterdvNV");
	GLM_struct->glCoverageModulationTableNVproc = (PFNGLCOVERAGEMODULATIONTABLENVPROC)wglGetProcAddress("glCoverageModulationTableNV");
	GLM_struct->glGetCoverageModulationTableNVproc = (PFNGLGETCOVERAGEMODULATIONTABLENVPROC)wglGetProcAddress("glGetCoverageModulationTableNV");
	GLM_struct->glCoverageModulationNVproc = (PFNGLCOVERAGEMODULATIONNVPROC)wglGetProcAddress("glCoverageModulationNV");
	GLM_struct->glRenderbufferStorageMultisampleCoverageNVproc = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glRenderbufferStorageMultisampleCoverageNV");
	GLM_struct->glProgramVertexLimitNVproc = (PFNGLPROGRAMVERTEXLIMITNVPROC)wglGetProcAddress("glProgramVertexLimitNV");
	GLM_struct->glFramebufferTextureEXTproc = (PFNGLFRAMEBUFFERTEXTUREEXTPROC)wglGetProcAddress("glFramebufferTextureEXT");
	GLM_struct->glFramebufferTextureFaceEXTproc = (PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)wglGetProcAddress("glFramebufferTextureFaceEXT");
	GLM_struct->glRenderGpuMaskNVproc = (PFNGLRENDERGPUMASKNVPROC)wglGetProcAddress("glRenderGpuMaskNV");
	GLM_struct->glMulticastBufferSubDataNVproc = (PFNGLMULTICASTBUFFERSUBDATANVPROC)wglGetProcAddress("glMulticastBufferSubDataNV");
	GLM_struct->glMulticastCopyBufferSubDataNVproc = (PFNGLMULTICASTCOPYBUFFERSUBDATANVPROC)wglGetProcAddress("glMulticastCopyBufferSubDataNV");
	GLM_struct->glMulticastCopyImageSubDataNVproc = (PFNGLMULTICASTCOPYIMAGESUBDATANVPROC)wglGetProcAddress("glMulticastCopyImageSubDataNV");
	GLM_struct->glMulticastBlitFramebufferNVproc = (PFNGLMULTICASTBLITFRAMEBUFFERNVPROC)wglGetProcAddress("glMulticastBlitFramebufferNV");
	GLM_struct->glMulticastFramebufferSampleLocationsfvNVproc = (PFNGLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)wglGetProcAddress("glMulticastFramebufferSampleLocationsfvNV");
	GLM_struct->glMulticastBarrierNVproc = (PFNGLMULTICASTBARRIERNVPROC)wglGetProcAddress("glMulticastBarrierNV");
	GLM_struct->glMulticastWaitSyncNVproc = (PFNGLMULTICASTWAITSYNCNVPROC)wglGetProcAddress("glMulticastWaitSyncNV");
	GLM_struct->glMulticastGetQueryObjectivNVproc = (PFNGLMULTICASTGETQUERYOBJECTIVNVPROC)wglGetProcAddress("glMulticastGetQueryObjectivNV");
	GLM_struct->glMulticastGetQueryObjectuivNVproc = (PFNGLMULTICASTGETQUERYOBJECTUIVNVPROC)wglGetProcAddress("glMulticastGetQueryObjectuivNV");
	GLM_struct->glMulticastGetQueryObjecti64vNVproc = (PFNGLMULTICASTGETQUERYOBJECTI64VNVPROC)wglGetProcAddress("glMulticastGetQueryObjecti64vNV");
	GLM_struct->glMulticastGetQueryObjectui64vNVproc = (PFNGLMULTICASTGETQUERYOBJECTUI64VNVPROC)wglGetProcAddress("glMulticastGetQueryObjectui64vNV");
	GLM_struct->glProgramLocalParameterI4iNVproc = (PFNGLPROGRAMLOCALPARAMETERI4INVPROC)wglGetProcAddress("glProgramLocalParameterI4iNV");
	GLM_struct->glProgramLocalParameterI4ivNVproc = (PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)wglGetProcAddress("glProgramLocalParameterI4ivNV");
	GLM_struct->glProgramLocalParametersI4ivNVproc = (PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)wglGetProcAddress("glProgramLocalParametersI4ivNV");
	GLM_struct->glProgramLocalParameterI4uiNVproc = (PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)wglGetProcAddress("glProgramLocalParameterI4uiNV");
	GLM_struct->glProgramLocalParameterI4uivNVproc = (PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)wglGetProcAddress("glProgramLocalParameterI4uivNV");
	GLM_struct->glProgramLocalParametersI4uivNVproc = (PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)wglGetProcAddress("glProgramLocalParametersI4uivNV");
	GLM_struct->glProgramEnvParameterI4iNVproc = (PFNGLPROGRAMENVPARAMETERI4INVPROC)wglGetProcAddress("glProgramEnvParameterI4iNV");
	GLM_struct->glProgramEnvParameterI4ivNVproc = (PFNGLPROGRAMENVPARAMETERI4IVNVPROC)wglGetProcAddress("glProgramEnvParameterI4ivNV");
	GLM_struct->glProgramEnvParametersI4ivNVproc = (PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)wglGetProcAddress("glProgramEnvParametersI4ivNV");
	GLM_struct->glProgramEnvParameterI4uiNVproc = (PFNGLPROGRAMENVPARAMETERI4UINVPROC)wglGetProcAddress("glProgramEnvParameterI4uiNV");
	GLM_struct->glProgramEnvParameterI4uivNVproc = (PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)wglGetProcAddress("glProgramEnvParameterI4uivNV");
	GLM_struct->glProgramEnvParametersI4uivNVproc = (PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)wglGetProcAddress("glProgramEnvParametersI4uivNV");
	GLM_struct->glGetProgramLocalParameterIivNVproc = (PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)wglGetProcAddress("glGetProgramLocalParameterIivNV");
	GLM_struct->glGetProgramLocalParameterIuivNVproc = (PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)wglGetProcAddress("glGetProgramLocalParameterIuivNV");
	GLM_struct->glGetProgramEnvParameterIivNVproc = (PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)wglGetProcAddress("glGetProgramEnvParameterIivNV");
	GLM_struct->glGetProgramEnvParameterIuivNVproc = (PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)wglGetProcAddress("glGetProgramEnvParameterIuivNV");
	GLM_struct->glProgramSubroutineParametersuivNVproc = (PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)wglGetProcAddress("glProgramSubroutineParametersuivNV");
	GLM_struct->glGetProgramSubroutineParameteruivNVproc = (PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)wglGetProcAddress("glGetProgramSubroutineParameteruivNV");
	GLM_struct->glVertex2hNVproc = (PFNGLVERTEX2HNVPROC)wglGetProcAddress("glVertex2hNV");
	GLM_struct->glVertex2hvNVproc = (PFNGLVERTEX2HVNVPROC)wglGetProcAddress("glVertex2hvNV");
	GLM_struct->glVertex3hNVproc = (PFNGLVERTEX3HNVPROC)wglGetProcAddress("glVertex3hNV");
	GLM_struct->glVertex3hvNVproc = (PFNGLVERTEX3HVNVPROC)wglGetProcAddress("glVertex3hvNV");
	GLM_struct->glVertex4hNVproc = (PFNGLVERTEX4HNVPROC)wglGetProcAddress("glVertex4hNV");
	GLM_struct->glVertex4hvNVproc = (PFNGLVERTEX4HVNVPROC)wglGetProcAddress("glVertex4hvNV");
	GLM_struct->glNormal3hNVproc = (PFNGLNORMAL3HNVPROC)wglGetProcAddress("glNormal3hNV");
	GLM_struct->glNormal3hvNVproc = (PFNGLNORMAL3HVNVPROC)wglGetProcAddress("glNormal3hvNV");
	GLM_struct->glColor3hNVproc = (PFNGLCOLOR3HNVPROC)wglGetProcAddress("glColor3hNV");
	GLM_struct->glColor3hvNVproc = (PFNGLCOLOR3HVNVPROC)wglGetProcAddress("glColor3hvNV");
	GLM_struct->glColor4hNVproc = (PFNGLCOLOR4HNVPROC)wglGetProcAddress("glColor4hNV");
	GLM_struct->glColor4hvNVproc = (PFNGLCOLOR4HVNVPROC)wglGetProcAddress("glColor4hvNV");
	GLM_struct->glTexCoord1hNVproc = (PFNGLTEXCOORD1HNVPROC)wglGetProcAddress("glTexCoord1hNV");
	GLM_struct->glTexCoord1hvNVproc = (PFNGLTEXCOORD1HVNVPROC)wglGetProcAddress("glTexCoord1hvNV");
	GLM_struct->glTexCoord2hNVproc = (PFNGLTEXCOORD2HNVPROC)wglGetProcAddress("glTexCoord2hNV");
	GLM_struct->glTexCoord2hvNVproc = (PFNGLTEXCOORD2HVNVPROC)wglGetProcAddress("glTexCoord2hvNV");
	GLM_struct->glTexCoord3hNVproc = (PFNGLTEXCOORD3HNVPROC)wglGetProcAddress("glTexCoord3hNV");
	GLM_struct->glTexCoord3hvNVproc = (PFNGLTEXCOORD3HVNVPROC)wglGetProcAddress("glTexCoord3hvNV");
	GLM_struct->glTexCoord4hNVproc = (PFNGLTEXCOORD4HNVPROC)wglGetProcAddress("glTexCoord4hNV");
	GLM_struct->glTexCoord4hvNVproc = (PFNGLTEXCOORD4HVNVPROC)wglGetProcAddress("glTexCoord4hvNV");
	GLM_struct->glMultiTexCoord1hNVproc = (PFNGLMULTITEXCOORD1HNVPROC)wglGetProcAddress("glMultiTexCoord1hNV");
	GLM_struct->glMultiTexCoord1hvNVproc = (PFNGLMULTITEXCOORD1HVNVPROC)wglGetProcAddress("glMultiTexCoord1hvNV");
	GLM_struct->glMultiTexCoord2hNVproc = (PFNGLMULTITEXCOORD2HNVPROC)wglGetProcAddress("glMultiTexCoord2hNV");
	GLM_struct->glMultiTexCoord2hvNVproc = (PFNGLMULTITEXCOORD2HVNVPROC)wglGetProcAddress("glMultiTexCoord2hvNV");
	GLM_struct->glMultiTexCoord3hNVproc = (PFNGLMULTITEXCOORD3HNVPROC)wglGetProcAddress("glMultiTexCoord3hNV");
	GLM_struct->glMultiTexCoord3hvNVproc = (PFNGLMULTITEXCOORD3HVNVPROC)wglGetProcAddress("glMultiTexCoord3hvNV");
	GLM_struct->glMultiTexCoord4hNVproc = (PFNGLMULTITEXCOORD4HNVPROC)wglGetProcAddress("glMultiTexCoord4hNV");
	GLM_struct->glMultiTexCoord4hvNVproc = (PFNGLMULTITEXCOORD4HVNVPROC)wglGetProcAddress("glMultiTexCoord4hvNV");
	GLM_struct->glVertexAttrib1hNVproc = (PFNGLVERTEXATTRIB1HNVPROC)wglGetProcAddress("glVertexAttrib1hNV");
	GLM_struct->glVertexAttrib1hvNVproc = (PFNGLVERTEXATTRIB1HVNVPROC)wglGetProcAddress("glVertexAttrib1hvNV");
	GLM_struct->glVertexAttrib2hNVproc = (PFNGLVERTEXATTRIB2HNVPROC)wglGetProcAddress("glVertexAttrib2hNV");
	GLM_struct->glVertexAttrib2hvNVproc = (PFNGLVERTEXATTRIB2HVNVPROC)wglGetProcAddress("glVertexAttrib2hvNV");
	GLM_struct->glVertexAttrib3hNVproc = (PFNGLVERTEXATTRIB3HNVPROC)wglGetProcAddress("glVertexAttrib3hNV");
	GLM_struct->glVertexAttrib3hvNVproc = (PFNGLVERTEXATTRIB3HVNVPROC)wglGetProcAddress("glVertexAttrib3hvNV");
	GLM_struct->glVertexAttrib4hNVproc = (PFNGLVERTEXATTRIB4HNVPROC)wglGetProcAddress("glVertexAttrib4hNV");
	GLM_struct->glVertexAttrib4hvNVproc = (PFNGLVERTEXATTRIB4HVNVPROC)wglGetProcAddress("glVertexAttrib4hvNV");
	GLM_struct->glVertexAttribs1hvNVproc = (PFNGLVERTEXATTRIBS1HVNVPROC)wglGetProcAddress("glVertexAttribs1hvNV");
	GLM_struct->glVertexAttribs2hvNVproc = (PFNGLVERTEXATTRIBS2HVNVPROC)wglGetProcAddress("glVertexAttribs2hvNV");
	GLM_struct->glVertexAttribs3hvNVproc = (PFNGLVERTEXATTRIBS3HVNVPROC)wglGetProcAddress("glVertexAttribs3hvNV");
	GLM_struct->glVertexAttribs4hvNVproc = (PFNGLVERTEXATTRIBS4HVNVPROC)wglGetProcAddress("glVertexAttribs4hvNV");
	GLM_struct->glFogCoordhNVproc = (PFNGLFOGCOORDHNVPROC)wglGetProcAddress("glFogCoordhNV");
	GLM_struct->glFogCoordhvNVproc = (PFNGLFOGCOORDHVNVPROC)wglGetProcAddress("glFogCoordhvNV");
	GLM_struct->glSecondaryColor3hNVproc = (PFNGLSECONDARYCOLOR3HNVPROC)wglGetProcAddress("glSecondaryColor3hNV");
	GLM_struct->glSecondaryColor3hvNVproc = (PFNGLSECONDARYCOLOR3HVNVPROC)wglGetProcAddress("glSecondaryColor3hvNV");
	GLM_struct->glVertexWeighthNVproc = (PFNGLVERTEXWEIGHTHNVPROC)wglGetProcAddress("glVertexWeighthNV");
	GLM_struct->glVertexWeighthvNVproc = (PFNGLVERTEXWEIGHTHVNVPROC)wglGetProcAddress("glVertexWeighthvNV");
	GLM_struct->glGetInternalformatSampleivNVproc = (PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)wglGetProcAddress("glGetInternalformatSampleivNV");
	GLM_struct->glGetMemoryObjectDetachedResourcesuivNVproc = (PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC)wglGetProcAddress("glGetMemoryObjectDetachedResourcesuivNV");
	GLM_struct->glResetMemoryObjectParameterNVproc = (PFNGLRESETMEMORYOBJECTPARAMETERNVPROC)wglGetProcAddress("glResetMemoryObjectParameterNV");
	GLM_struct->glTexAttachMemoryNVproc = (PFNGLTEXATTACHMEMORYNVPROC)wglGetProcAddress("glTexAttachMemoryNV");
	GLM_struct->glBufferAttachMemoryNVproc = (PFNGLBUFFERATTACHMEMORYNVPROC)wglGetProcAddress("glBufferAttachMemoryNV");
	GLM_struct->glTextureAttachMemoryNVproc = (PFNGLTEXTUREATTACHMEMORYNVPROC)wglGetProcAddress("glTextureAttachMemoryNV");
	GLM_struct->glNamedBufferAttachMemoryNVproc = (PFNGLNAMEDBUFFERATTACHMEMORYNVPROC)wglGetProcAddress("glNamedBufferAttachMemoryNV");
	GLM_struct->glBufferPageCommitmentMemNVproc = (PFNGLBUFFERPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glBufferPageCommitmentMemNV");
	GLM_struct->glTexPageCommitmentMemNVproc = (PFNGLTEXPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glTexPageCommitmentMemNV");
	GLM_struct->glNamedBufferPageCommitmentMemNVproc = (PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glNamedBufferPageCommitmentMemNV");
	GLM_struct->glTexturePageCommitmentMemNVproc = (PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC)wglGetProcAddress("glTexturePageCommitmentMemNV");
	GLM_struct->glDrawMeshTasksNVproc = (PFNGLDRAWMESHTASKSNVPROC)wglGetProcAddress("glDrawMeshTasksNV");
	GLM_struct->glDrawMeshTasksIndirectNVproc = (PFNGLDRAWMESHTASKSINDIRECTNVPROC)wglGetProcAddress("glDrawMeshTasksIndirectNV");
	GLM_struct->glMultiDrawMeshTasksIndirectNVproc = (PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC)wglGetProcAddress("glMultiDrawMeshTasksIndirectNV");
	GLM_struct->glMultiDrawMeshTasksIndirectCountNVproc = (PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC)wglGetProcAddress("glMultiDrawMeshTasksIndirectCountNV");
	GLM_struct->glGenOcclusionQueriesNVproc = (PFNGLGENOCCLUSIONQUERIESNVPROC)wglGetProcAddress("glGenOcclusionQueriesNV");
	GLM_struct->glDeleteOcclusionQueriesNVproc = (PFNGLDELETEOCCLUSIONQUERIESNVPROC)wglGetProcAddress("glDeleteOcclusionQueriesNV");
	GLM_struct->glIsOcclusionQueryNVproc = (PFNGLISOCCLUSIONQUERYNVPROC)wglGetProcAddress("glIsOcclusionQueryNV");
	GLM_struct->glBeginOcclusionQueryNVproc = (PFNGLBEGINOCCLUSIONQUERYNVPROC)wglGetProcAddress("glBeginOcclusionQueryNV");
	GLM_struct->glEndOcclusionQueryNVproc = (PFNGLENDOCCLUSIONQUERYNVPROC)wglGetProcAddress("glEndOcclusionQueryNV");
	GLM_struct->glGetOcclusionQueryivNVproc = (PFNGLGETOCCLUSIONQUERYIVNVPROC)wglGetProcAddress("glGetOcclusionQueryivNV");
	GLM_struct->glGetOcclusionQueryuivNVproc = (PFNGLGETOCCLUSIONQUERYUIVNVPROC)wglGetProcAddress("glGetOcclusionQueryuivNV");
	GLM_struct->glProgramBufferParametersfvNVproc = (PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)wglGetProcAddress("glProgramBufferParametersfvNV");
	GLM_struct->glProgramBufferParametersIivNVproc = (PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)wglGetProcAddress("glProgramBufferParametersIivNV");
	GLM_struct->glProgramBufferParametersIuivNVproc = (PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)wglGetProcAddress("glProgramBufferParametersIuivNV");
	GLM_struct->glGenPathsNVproc = (PFNGLGENPATHSNVPROC)wglGetProcAddress("glGenPathsNV");
	GLM_struct->glDeletePathsNVproc = (PFNGLDELETEPATHSNVPROC)wglGetProcAddress("glDeletePathsNV");
	GLM_struct->glIsPathNVproc = (PFNGLISPATHNVPROC)wglGetProcAddress("glIsPathNV");
	GLM_struct->glPathCommandsNVproc = (PFNGLPATHCOMMANDSNVPROC)wglGetProcAddress("glPathCommandsNV");
	GLM_struct->glPathCoordsNVproc = (PFNGLPATHCOORDSNVPROC)wglGetProcAddress("glPathCoordsNV");
	GLM_struct->glPathSubCommandsNVproc = (PFNGLPATHSUBCOMMANDSNVPROC)wglGetProcAddress("glPathSubCommandsNV");
	GLM_struct->glPathSubCoordsNVproc = (PFNGLPATHSUBCOORDSNVPROC)wglGetProcAddress("glPathSubCoordsNV");
	GLM_struct->glPathStringNVproc = (PFNGLPATHSTRINGNVPROC)wglGetProcAddress("glPathStringNV");
	GLM_struct->glPathGlyphsNVproc = (PFNGLPATHGLYPHSNVPROC)wglGetProcAddress("glPathGlyphsNV");
	GLM_struct->glPathGlyphRangeNVproc = (PFNGLPATHGLYPHRANGENVPROC)wglGetProcAddress("glPathGlyphRangeNV");
	GLM_struct->glWeightPathsNVproc = (PFNGLWEIGHTPATHSNVPROC)wglGetProcAddress("glWeightPathsNV");
	GLM_struct->glCopyPathNVproc = (PFNGLCOPYPATHNVPROC)wglGetProcAddress("glCopyPathNV");
	GLM_struct->glInterpolatePathsNVproc = (PFNGLINTERPOLATEPATHSNVPROC)wglGetProcAddress("glInterpolatePathsNV");
	GLM_struct->glTransformPathNVproc = (PFNGLTRANSFORMPATHNVPROC)wglGetProcAddress("glTransformPathNV");
	GLM_struct->glPathParameterivNVproc = (PFNGLPATHPARAMETERIVNVPROC)wglGetProcAddress("glPathParameterivNV");
	GLM_struct->glPathParameteriNVproc = (PFNGLPATHPARAMETERINVPROC)wglGetProcAddress("glPathParameteriNV");
	GLM_struct->glPathParameterfvNVproc = (PFNGLPATHPARAMETERFVNVPROC)wglGetProcAddress("glPathParameterfvNV");
	GLM_struct->glPathParameterfNVproc = (PFNGLPATHPARAMETERFNVPROC)wglGetProcAddress("glPathParameterfNV");
	GLM_struct->glPathDashArrayNVproc = (PFNGLPATHDASHARRAYNVPROC)wglGetProcAddress("glPathDashArrayNV");
	GLM_struct->glPathStencilFuncNVproc = (PFNGLPATHSTENCILFUNCNVPROC)wglGetProcAddress("glPathStencilFuncNV");
	GLM_struct->glPathStencilDepthOffsetNVproc = (PFNGLPATHSTENCILDEPTHOFFSETNVPROC)wglGetProcAddress("glPathStencilDepthOffsetNV");
	GLM_struct->glStencilFillPathNVproc = (PFNGLSTENCILFILLPATHNVPROC)wglGetProcAddress("glStencilFillPathNV");
	GLM_struct->glStencilStrokePathNVproc = (PFNGLSTENCILSTROKEPATHNVPROC)wglGetProcAddress("glStencilStrokePathNV");
	GLM_struct->glStencilFillPathInstancedNVproc = (PFNGLSTENCILFILLPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilFillPathInstancedNV");
	GLM_struct->glStencilStrokePathInstancedNVproc = (PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilStrokePathInstancedNV");
	GLM_struct->glPathCoverDepthFuncNVproc = (PFNGLPATHCOVERDEPTHFUNCNVPROC)wglGetProcAddress("glPathCoverDepthFuncNV");
	GLM_struct->glCoverFillPathNVproc = (PFNGLCOVERFILLPATHNVPROC)wglGetProcAddress("glCoverFillPathNV");
	GLM_struct->glCoverStrokePathNVproc = (PFNGLCOVERSTROKEPATHNVPROC)wglGetProcAddress("glCoverStrokePathNV");
	GLM_struct->glCoverFillPathInstancedNVproc = (PFNGLCOVERFILLPATHINSTANCEDNVPROC)wglGetProcAddress("glCoverFillPathInstancedNV");
	GLM_struct->glCoverStrokePathInstancedNVproc = (PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)wglGetProcAddress("glCoverStrokePathInstancedNV");
	GLM_struct->glGetPathParameterivNVproc = (PFNGLGETPATHPARAMETERIVNVPROC)wglGetProcAddress("glGetPathParameterivNV");
	GLM_struct->glGetPathParameterfvNVproc = (PFNGLGETPATHPARAMETERFVNVPROC)wglGetProcAddress("glGetPathParameterfvNV");
	GLM_struct->glGetPathCommandsNVproc = (PFNGLGETPATHCOMMANDSNVPROC)wglGetProcAddress("glGetPathCommandsNV");
	GLM_struct->glGetPathCoordsNVproc = (PFNGLGETPATHCOORDSNVPROC)wglGetProcAddress("glGetPathCoordsNV");
	GLM_struct->glGetPathDashArrayNVproc = (PFNGLGETPATHDASHARRAYNVPROC)wglGetProcAddress("glGetPathDashArrayNV");
	GLM_struct->glGetPathMetricsNVproc = (PFNGLGETPATHMETRICSNVPROC)wglGetProcAddress("glGetPathMetricsNV");
	GLM_struct->glGetPathMetricRangeNVproc = (PFNGLGETPATHMETRICRANGENVPROC)wglGetProcAddress("glGetPathMetricRangeNV");
	GLM_struct->glGetPathSpacingNVproc = (PFNGLGETPATHSPACINGNVPROC)wglGetProcAddress("glGetPathSpacingNV");
	GLM_struct->glIsPointInFillPathNVproc = (PFNGLISPOINTINFILLPATHNVPROC)wglGetProcAddress("glIsPointInFillPathNV");
	GLM_struct->glIsPointInStrokePathNVproc = (PFNGLISPOINTINSTROKEPATHNVPROC)wglGetProcAddress("glIsPointInStrokePathNV");
	GLM_struct->glGetPathLengthNVproc = (PFNGLGETPATHLENGTHNVPROC)wglGetProcAddress("glGetPathLengthNV");
	GLM_struct->glPointAlongPathNVproc = (PFNGLPOINTALONGPATHNVPROC)wglGetProcAddress("glPointAlongPathNV");
	GLM_struct->glMatrixLoad3x2fNVproc = (PFNGLMATRIXLOAD3X2FNVPROC)wglGetProcAddress("glMatrixLoad3x2fNV");
	GLM_struct->glMatrixLoad3x3fNVproc = (PFNGLMATRIXLOAD3X3FNVPROC)wglGetProcAddress("glMatrixLoad3x3fNV");
	GLM_struct->glMatrixLoadTranspose3x3fNVproc = (PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)wglGetProcAddress("glMatrixLoadTranspose3x3fNV");
	GLM_struct->glMatrixMult3x2fNVproc = (PFNGLMATRIXMULT3X2FNVPROC)wglGetProcAddress("glMatrixMult3x2fNV");
	GLM_struct->glMatrixMult3x3fNVproc = (PFNGLMATRIXMULT3X3FNVPROC)wglGetProcAddress("glMatrixMult3x3fNV");
	GLM_struct->glMatrixMultTranspose3x3fNVproc = (PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)wglGetProcAddress("glMatrixMultTranspose3x3fNV");
	GLM_struct->glStencilThenCoverFillPathNVproc = (PFNGLSTENCILTHENCOVERFILLPATHNVPROC)wglGetProcAddress("glStencilThenCoverFillPathNV");
	GLM_struct->glStencilThenCoverStrokePathNVproc = (PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)wglGetProcAddress("glStencilThenCoverStrokePathNV");
	GLM_struct->glStencilThenCoverFillPathInstancedNVproc = (PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilThenCoverFillPathInstancedNV");
	GLM_struct->glStencilThenCoverStrokePathInstancedNVproc = (PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)wglGetProcAddress("glStencilThenCoverStrokePathInstancedNV");
	GLM_struct->glPathGlyphIndexRangeNVproc = (PFNGLPATHGLYPHINDEXRANGENVPROC)wglGetProcAddress("glPathGlyphIndexRangeNV");
	GLM_struct->glPathGlyphIndexArrayNVproc = (PFNGLPATHGLYPHINDEXARRAYNVPROC)wglGetProcAddress("glPathGlyphIndexArrayNV");
	GLM_struct->glPathMemoryGlyphIndexArrayNVproc = (PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)wglGetProcAddress("glPathMemoryGlyphIndexArrayNV");
	GLM_struct->glProgramPathFragmentInputGenNVproc = (PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)wglGetProcAddress("glProgramPathFragmentInputGenNV");
	GLM_struct->glGetProgramResourcefvNVproc = (PFNGLGETPROGRAMRESOURCEFVNVPROC)wglGetProcAddress("glGetProgramResourcefvNV");
	GLM_struct->glPathColorGenNVproc = (PFNGLPATHCOLORGENNVPROC)wglGetProcAddress("glPathColorGenNV");
	GLM_struct->glPathTexGenNVproc = (PFNGLPATHTEXGENNVPROC)wglGetProcAddress("glPathTexGenNV");
	GLM_struct->glPathFogGenNVproc = (PFNGLPATHFOGGENNVPROC)wglGetProcAddress("glPathFogGenNV");
	GLM_struct->glGetPathColorGenivNVproc = (PFNGLGETPATHCOLORGENIVNVPROC)wglGetProcAddress("glGetPathColorGenivNV");
	GLM_struct->glGetPathColorGenfvNVproc = (PFNGLGETPATHCOLORGENFVNVPROC)wglGetProcAddress("glGetPathColorGenfvNV");
	GLM_struct->glGetPathTexGenivNVproc = (PFNGLGETPATHTEXGENIVNVPROC)wglGetProcAddress("glGetPathTexGenivNV");
	GLM_struct->glGetPathTexGenfvNVproc = (PFNGLGETPATHTEXGENFVNVPROC)wglGetProcAddress("glGetPathTexGenfvNV");
	GLM_struct->glPixelDataRangeNVproc = (PFNGLPIXELDATARANGENVPROC)wglGetProcAddress("glPixelDataRangeNV");
	GLM_struct->glFlushPixelDataRangeNVproc = (PFNGLFLUSHPIXELDATARANGENVPROC)wglGetProcAddress("glFlushPixelDataRangeNV");
	GLM_struct->glPointParameteriNVproc = (PFNGLPOINTPARAMETERINVPROC)wglGetProcAddress("glPointParameteriNV");
	GLM_struct->glPointParameterivNVproc = (PFNGLPOINTPARAMETERIVNVPROC)wglGetProcAddress("glPointParameterivNV");
	GLM_struct->glPresentFrameKeyedNVproc = (PFNGLPRESENTFRAMEKEYEDNVPROC)wglGetProcAddress("glPresentFrameKeyedNV");
	GLM_struct->glPresentFrameDualFillNVproc = (PFNGLPRESENTFRAMEDUALFILLNVPROC)wglGetProcAddress("glPresentFrameDualFillNV");
	GLM_struct->glGetVideoivNVproc = (PFNGLGETVIDEOIVNVPROC)wglGetProcAddress("glGetVideoivNV");
	GLM_struct->glGetVideouivNVproc = (PFNGLGETVIDEOUIVNVPROC)wglGetProcAddress("glGetVideouivNV");
	GLM_struct->glGetVideoi64vNVproc = (PFNGLGETVIDEOI64VNVPROC)wglGetProcAddress("glGetVideoi64vNV");
	GLM_struct->glGetVideoui64vNVproc = (PFNGLGETVIDEOUI64VNVPROC)wglGetProcAddress("glGetVideoui64vNV");
	GLM_struct->glPrimitiveRestartNVproc = (PFNGLPRIMITIVERESTARTNVPROC)wglGetProcAddress("glPrimitiveRestartNV");
	GLM_struct->glPrimitiveRestartIndexNVproc = (PFNGLPRIMITIVERESTARTINDEXNVPROC)wglGetProcAddress("glPrimitiveRestartIndexNV");
	GLM_struct->glQueryResourceNVproc = (PFNGLQUERYRESOURCENVPROC)wglGetProcAddress("glQueryResourceNV");
	GLM_struct->glGenQueryResourceTagNVproc = (PFNGLGENQUERYRESOURCETAGNVPROC)wglGetProcAddress("glGenQueryResourceTagNV");
	GLM_struct->glDeleteQueryResourceTagNVproc = (PFNGLDELETEQUERYRESOURCETAGNVPROC)wglGetProcAddress("glDeleteQueryResourceTagNV");
	GLM_struct->glQueryResourceTagNVproc = (PFNGLQUERYRESOURCETAGNVPROC)wglGetProcAddress("glQueryResourceTagNV");
	GLM_struct->glCombinerParameterfvNVproc = (PFNGLCOMBINERPARAMETERFVNVPROC)wglGetProcAddress("glCombinerParameterfvNV");
	GLM_struct->glCombinerParameterfNVproc = (PFNGLCOMBINERPARAMETERFNVPROC)wglGetProcAddress("glCombinerParameterfNV");
	GLM_struct->glCombinerParameterivNVproc = (PFNGLCOMBINERPARAMETERIVNVPROC)wglGetProcAddress("glCombinerParameterivNV");
	GLM_struct->glCombinerParameteriNVproc = (PFNGLCOMBINERPARAMETERINVPROC)wglGetProcAddress("glCombinerParameteriNV");
	GLM_struct->glCombinerInputNVproc = (PFNGLCOMBINERINPUTNVPROC)wglGetProcAddress("glCombinerInputNV");
	GLM_struct->glCombinerOutputNVproc = (PFNGLCOMBINEROUTPUTNVPROC)wglGetProcAddress("glCombinerOutputNV");
	GLM_struct->glFinalCombinerInputNVproc = (PFNGLFINALCOMBINERINPUTNVPROC)wglGetProcAddress("glFinalCombinerInputNV");
	GLM_struct->glGetCombinerInputParameterfvNVproc = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)wglGetProcAddress("glGetCombinerInputParameterfvNV");
	GLM_struct->glGetCombinerInputParameterivNVproc = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)wglGetProcAddress("glGetCombinerInputParameterivNV");
	GLM_struct->glGetCombinerOutputParameterfvNVproc = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)wglGetProcAddress("glGetCombinerOutputParameterfvNV");
	GLM_struct->glGetCombinerOutputParameterivNVproc = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)wglGetProcAddress("glGetCombinerOutputParameterivNV");
	GLM_struct->glGetFinalCombinerInputParameterfvNVproc = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)wglGetProcAddress("glGetFinalCombinerInputParameterfvNV");
	GLM_struct->glGetFinalCombinerInputParameterivNVproc = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)wglGetProcAddress("glGetFinalCombinerInputParameterivNV");
	GLM_struct->glCombinerStageParameterfvNVproc = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)wglGetProcAddress("glCombinerStageParameterfvNV");
	GLM_struct->glGetCombinerStageParameterfvNVproc = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)wglGetProcAddress("glGetCombinerStageParameterfvNV");
	GLM_struct->glFramebufferSampleLocationsfvNVproc = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)wglGetProcAddress("glFramebufferSampleLocationsfvNV");
	GLM_struct->glNamedFramebufferSampleLocationsfvNVproc = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)wglGetProcAddress("glNamedFramebufferSampleLocationsfvNV");
	GLM_struct->glResolveDepthValuesNVproc = (PFNGLRESOLVEDEPTHVALUESNVPROC)wglGetProcAddress("glResolveDepthValuesNV");
	GLM_struct->glScissorExclusiveNVproc = (PFNGLSCISSOREXCLUSIVENVPROC)wglGetProcAddress("glScissorExclusiveNV");
	GLM_struct->glScissorExclusiveArrayvNVproc = (PFNGLSCISSOREXCLUSIVEARRAYVNVPROC)wglGetProcAddress("glScissorExclusiveArrayvNV");
	GLM_struct->glMakeBufferResidentNVproc = (PFNGLMAKEBUFFERRESIDENTNVPROC)wglGetProcAddress("glMakeBufferResidentNV");
	GLM_struct->glMakeBufferNonResidentNVproc = (PFNGLMAKEBUFFERNONRESIDENTNVPROC)wglGetProcAddress("glMakeBufferNonResidentNV");
	GLM_struct->glIsBufferResidentNVproc = (PFNGLISBUFFERRESIDENTNVPROC)wglGetProcAddress("glIsBufferResidentNV");
	GLM_struct->glMakeNamedBufferResidentNVproc = (PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)wglGetProcAddress("glMakeNamedBufferResidentNV");
	GLM_struct->glMakeNamedBufferNonResidentNVproc = (PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)wglGetProcAddress("glMakeNamedBufferNonResidentNV");
	GLM_struct->glIsNamedBufferResidentNVproc = (PFNGLISNAMEDBUFFERRESIDENTNVPROC)wglGetProcAddress("glIsNamedBufferResidentNV");
	GLM_struct->glGetBufferParameterui64vNVproc = (PFNGLGETBUFFERPARAMETERUI64VNVPROC)wglGetProcAddress("glGetBufferParameterui64vNV");
	GLM_struct->glGetNamedBufferParameterui64vNVproc = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)wglGetProcAddress("glGetNamedBufferParameterui64vNV");
	GLM_struct->glGetIntegerui64vNVproc = (PFNGLGETINTEGERUI64VNVPROC)wglGetProcAddress("glGetIntegerui64vNV");
	GLM_struct->glUniformui64NVproc = (PFNGLUNIFORMUI64NVPROC)wglGetProcAddress("glUniformui64NV");
	GLM_struct->glUniformui64vNVproc = (PFNGLUNIFORMUI64VNVPROC)wglGetProcAddress("glUniformui64vNV");
	GLM_struct->glProgramUniformui64NVproc = (PFNGLPROGRAMUNIFORMUI64NVPROC)wglGetProcAddress("glProgramUniformui64NV");
	GLM_struct->glProgramUniformui64vNVproc = (PFNGLPROGRAMUNIFORMUI64VNVPROC)wglGetProcAddress("glProgramUniformui64vNV");
	GLM_struct->glBindShadingRateImageNVproc = (PFNGLBINDSHADINGRATEIMAGENVPROC)wglGetProcAddress("glBindShadingRateImageNV");
	GLM_struct->glGetShadingRateImagePaletteNVproc = (PFNGLGETSHADINGRATEIMAGEPALETTENVPROC)wglGetProcAddress("glGetShadingRateImagePaletteNV");
	GLM_struct->glGetShadingRateSampleLocationivNVproc = (PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC)wglGetProcAddress("glGetShadingRateSampleLocationivNV");
	GLM_struct->glShadingRateImageBarrierNVproc = (PFNGLSHADINGRATEIMAGEBARRIERNVPROC)wglGetProcAddress("glShadingRateImageBarrierNV");
	GLM_struct->glShadingRateImagePaletteNVproc = (PFNGLSHADINGRATEIMAGEPALETTENVPROC)wglGetProcAddress("glShadingRateImagePaletteNV");
	GLM_struct->glShadingRateSampleOrderNVproc = (PFNGLSHADINGRATESAMPLEORDERNVPROC)wglGetProcAddress("glShadingRateSampleOrderNV");
	GLM_struct->glShadingRateSampleOrderCustomNVproc = (PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC)wglGetProcAddress("glShadingRateSampleOrderCustomNV");
	GLM_struct->glTextureBarrierNVproc = (PFNGLTEXTUREBARRIERNVPROC)wglGetProcAddress("glTextureBarrierNV");
	GLM_struct->glTexImage2DMultisampleCoverageNVproc = (PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTexImage2DMultisampleCoverageNV");
	GLM_struct->glTexImage3DMultisampleCoverageNVproc = (PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTexImage3DMultisampleCoverageNV");
	GLM_struct->glTextureImage2DMultisampleNVproc = (PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)wglGetProcAddress("glTextureImage2DMultisampleNV");
	GLM_struct->glTextureImage3DMultisampleNVproc = (PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)wglGetProcAddress("glTextureImage3DMultisampleNV");
	GLM_struct->glTextureImage2DMultisampleCoverageNVproc = (PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTextureImage2DMultisampleCoverageNV");
	GLM_struct->glTextureImage3DMultisampleCoverageNVproc = (PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)wglGetProcAddress("glTextureImage3DMultisampleCoverageNV");
	GLM_struct->glCreateSemaphoresNVproc = (PFNGLCREATESEMAPHORESNVPROC)wglGetProcAddress("glCreateSemaphoresNV");
	GLM_struct->glSemaphoreParameterivNVproc = (PFNGLSEMAPHOREPARAMETERIVNVPROC)wglGetProcAddress("glSemaphoreParameterivNV");
	GLM_struct->glGetSemaphoreParameterivNVproc = (PFNGLGETSEMAPHOREPARAMETERIVNVPROC)wglGetProcAddress("glGetSemaphoreParameterivNV");
	GLM_struct->glBeginTransformFeedbackNVproc = (PFNGLBEGINTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glBeginTransformFeedbackNV");
	GLM_struct->glEndTransformFeedbackNVproc = (PFNGLENDTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glEndTransformFeedbackNV");
	GLM_struct->glTransformFeedbackAttribsNVproc = (PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)wglGetProcAddress("glTransformFeedbackAttribsNV");
	GLM_struct->glBindBufferRangeNVproc = (PFNGLBINDBUFFERRANGENVPROC)wglGetProcAddress("glBindBufferRangeNV");
	GLM_struct->glBindBufferOffsetNVproc = (PFNGLBINDBUFFEROFFSETNVPROC)wglGetProcAddress("glBindBufferOffsetNV");
	GLM_struct->glBindBufferBaseNVproc = (PFNGLBINDBUFFERBASENVPROC)wglGetProcAddress("glBindBufferBaseNV");
	GLM_struct->glTransformFeedbackVaryingsNVproc = (PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)wglGetProcAddress("glTransformFeedbackVaryingsNV");
	GLM_struct->glActiveVaryingNVproc = (PFNGLACTIVEVARYINGNVPROC)wglGetProcAddress("glActiveVaryingNV");
	GLM_struct->glGetVaryingLocationNVproc = (PFNGLGETVARYINGLOCATIONNVPROC)wglGetProcAddress("glGetVaryingLocationNV");
	GLM_struct->glGetActiveVaryingNVproc = (PFNGLGETACTIVEVARYINGNVPROC)wglGetProcAddress("glGetActiveVaryingNV");
	GLM_struct->glGetTransformFeedbackVaryingNVproc = (PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)wglGetProcAddress("glGetTransformFeedbackVaryingNV");
	GLM_struct->glTransformFeedbackStreamAttribsNVproc = (PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)wglGetProcAddress("glTransformFeedbackStreamAttribsNV");
	GLM_struct->glBindTransformFeedbackNVproc = (PFNGLBINDTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glBindTransformFeedbackNV");
	GLM_struct->glDeleteTransformFeedbacksNVproc = (PFNGLDELETETRANSFORMFEEDBACKSNVPROC)wglGetProcAddress("glDeleteTransformFeedbacksNV");
	GLM_struct->glGenTransformFeedbacksNVproc = (PFNGLGENTRANSFORMFEEDBACKSNVPROC)wglGetProcAddress("glGenTransformFeedbacksNV");
	GLM_struct->glIsTransformFeedbackNVproc = (PFNGLISTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glIsTransformFeedbackNV");
	GLM_struct->glPauseTransformFeedbackNVproc = (PFNGLPAUSETRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glPauseTransformFeedbackNV");
	GLM_struct->glResumeTransformFeedbackNVproc = (PFNGLRESUMETRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glResumeTransformFeedbackNV");
	GLM_struct->glDrawTransformFeedbackNVproc = (PFNGLDRAWTRANSFORMFEEDBACKNVPROC)wglGetProcAddress("glDrawTransformFeedbackNV");
	GLM_struct->glVDPAUInitNVproc = (PFNGLVDPAUINITNVPROC)wglGetProcAddress("glVDPAUInitNV");
	GLM_struct->glVDPAUFiniNVproc = (PFNGLVDPAUFININVPROC)wglGetProcAddress("glVDPAUFiniNV");
	GLM_struct->glVDPAURegisterVideoSurfaceNVproc = (PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)wglGetProcAddress("glVDPAURegisterVideoSurfaceNV");
	GLM_struct->glVDPAURegisterOutputSurfaceNVproc = (PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)wglGetProcAddress("glVDPAURegisterOutputSurfaceNV");
	GLM_struct->glVDPAUIsSurfaceNVproc = (PFNGLVDPAUISSURFACENVPROC)wglGetProcAddress("glVDPAUIsSurfaceNV");
	GLM_struct->glVDPAUUnregisterSurfaceNVproc = (PFNGLVDPAUUNREGISTERSURFACENVPROC)wglGetProcAddress("glVDPAUUnregisterSurfaceNV");
	GLM_struct->glVDPAUGetSurfaceivNVproc = (PFNGLVDPAUGETSURFACEIVNVPROC)wglGetProcAddress("glVDPAUGetSurfaceivNV");
	GLM_struct->glVDPAUSurfaceAccessNVproc = (PFNGLVDPAUSURFACEACCESSNVPROC)wglGetProcAddress("glVDPAUSurfaceAccessNV");
	GLM_struct->glVDPAUMapSurfacesNVproc = (PFNGLVDPAUMAPSURFACESNVPROC)wglGetProcAddress("glVDPAUMapSurfacesNV");
	GLM_struct->glVDPAUUnmapSurfacesNVproc = (PFNGLVDPAUUNMAPSURFACESNVPROC)wglGetProcAddress("glVDPAUUnmapSurfacesNV");
	GLM_struct->glVDPAURegisterVideoSurfaceWithPictureStructureNVproc = (PFNGLVDPAUREGISTERVIDEOSURFACEWITHPICTURESTRUCTURENVPROC)wglGetProcAddress("glVDPAURegisterVideoSurfaceWithPictureStructureNV");
	GLM_struct->glFlushVertexArrayRangeNVproc = (PFNGLFLUSHVERTEXARRAYRANGENVPROC)wglGetProcAddress("glFlushVertexArrayRangeNV");
	GLM_struct->glVertexArrayRangeNVproc = (PFNGLVERTEXARRAYRANGENVPROC)wglGetProcAddress("glVertexArrayRangeNV");
	GLM_struct->glVertexAttribL1i64NVproc = (PFNGLVERTEXATTRIBL1I64NVPROC)wglGetProcAddress("glVertexAttribL1i64NV");
	GLM_struct->glVertexAttribL2i64NVproc = (PFNGLVERTEXATTRIBL2I64NVPROC)wglGetProcAddress("glVertexAttribL2i64NV");
	GLM_struct->glVertexAttribL3i64NVproc = (PFNGLVERTEXATTRIBL3I64NVPROC)wglGetProcAddress("glVertexAttribL3i64NV");
	GLM_struct->glVertexAttribL4i64NVproc = (PFNGLVERTEXATTRIBL4I64NVPROC)wglGetProcAddress("glVertexAttribL4i64NV");
	GLM_struct->glVertexAttribL1i64vNVproc = (PFNGLVERTEXATTRIBL1I64VNVPROC)wglGetProcAddress("glVertexAttribL1i64vNV");
	GLM_struct->glVertexAttribL2i64vNVproc = (PFNGLVERTEXATTRIBL2I64VNVPROC)wglGetProcAddress("glVertexAttribL2i64vNV");
	GLM_struct->glVertexAttribL3i64vNVproc = (PFNGLVERTEXATTRIBL3I64VNVPROC)wglGetProcAddress("glVertexAttribL3i64vNV");
	GLM_struct->glVertexAttribL4i64vNVproc = (PFNGLVERTEXATTRIBL4I64VNVPROC)wglGetProcAddress("glVertexAttribL4i64vNV");
	GLM_struct->glVertexAttribL1ui64NVproc = (PFNGLVERTEXATTRIBL1UI64NVPROC)wglGetProcAddress("glVertexAttribL1ui64NV");
	GLM_struct->glVertexAttribL2ui64NVproc = (PFNGLVERTEXATTRIBL2UI64NVPROC)wglGetProcAddress("glVertexAttribL2ui64NV");
	GLM_struct->glVertexAttribL3ui64NVproc = (PFNGLVERTEXATTRIBL3UI64NVPROC)wglGetProcAddress("glVertexAttribL3ui64NV");
	GLM_struct->glVertexAttribL4ui64NVproc = (PFNGLVERTEXATTRIBL4UI64NVPROC)wglGetProcAddress("glVertexAttribL4ui64NV");
	GLM_struct->glVertexAttribL1ui64vNVproc = (PFNGLVERTEXATTRIBL1UI64VNVPROC)wglGetProcAddress("glVertexAttribL1ui64vNV");
	GLM_struct->glVertexAttribL2ui64vNVproc = (PFNGLVERTEXATTRIBL2UI64VNVPROC)wglGetProcAddress("glVertexAttribL2ui64vNV");
	GLM_struct->glVertexAttribL3ui64vNVproc = (PFNGLVERTEXATTRIBL3UI64VNVPROC)wglGetProcAddress("glVertexAttribL3ui64vNV");
	GLM_struct->glVertexAttribL4ui64vNVproc = (PFNGLVERTEXATTRIBL4UI64VNVPROC)wglGetProcAddress("glVertexAttribL4ui64vNV");
	GLM_struct->glGetVertexAttribLi64vNVproc = (PFNGLGETVERTEXATTRIBLI64VNVPROC)wglGetProcAddress("glGetVertexAttribLi64vNV");
	GLM_struct->glGetVertexAttribLui64vNVproc = (PFNGLGETVERTEXATTRIBLUI64VNVPROC)wglGetProcAddress("glGetVertexAttribLui64vNV");
	GLM_struct->glVertexAttribLFormatNVproc = (PFNGLVERTEXATTRIBLFORMATNVPROC)wglGetProcAddress("glVertexAttribLFormatNV");
	GLM_struct->glBufferAddressRangeNVproc = (PFNGLBUFFERADDRESSRANGENVPROC)wglGetProcAddress("glBufferAddressRangeNV");
	GLM_struct->glVertexFormatNVproc = (PFNGLVERTEXFORMATNVPROC)wglGetProcAddress("glVertexFormatNV");
	GLM_struct->glNormalFormatNVproc = (PFNGLNORMALFORMATNVPROC)wglGetProcAddress("glNormalFormatNV");
	GLM_struct->glColorFormatNVproc = (PFNGLCOLORFORMATNVPROC)wglGetProcAddress("glColorFormatNV");
	GLM_struct->glIndexFormatNVproc = (PFNGLINDEXFORMATNVPROC)wglGetProcAddress("glIndexFormatNV");
	GLM_struct->glTexCoordFormatNVproc = (PFNGLTEXCOORDFORMATNVPROC)wglGetProcAddress("glTexCoordFormatNV");
	GLM_struct->glEdgeFlagFormatNVproc = (PFNGLEDGEFLAGFORMATNVPROC)wglGetProcAddress("glEdgeFlagFormatNV");
	GLM_struct->glSecondaryColorFormatNVproc = (PFNGLSECONDARYCOLORFORMATNVPROC)wglGetProcAddress("glSecondaryColorFormatNV");
	GLM_struct->glFogCoordFormatNVproc = (PFNGLFOGCOORDFORMATNVPROC)wglGetProcAddress("glFogCoordFormatNV");
	GLM_struct->glVertexAttribFormatNVproc = (PFNGLVERTEXATTRIBFORMATNVPROC)wglGetProcAddress("glVertexAttribFormatNV");
	GLM_struct->glVertexAttribIFormatNVproc = (PFNGLVERTEXATTRIBIFORMATNVPROC)wglGetProcAddress("glVertexAttribIFormatNV");
	GLM_struct->glGetIntegerui64i_vNVproc = (PFNGLGETINTEGERUI64I_VNVPROC)wglGetProcAddress("glGetIntegerui64i_vNV");
	GLM_struct->glAreProgramsResidentNVproc = (PFNGLAREPROGRAMSRESIDENTNVPROC)wglGetProcAddress("glAreProgramsResidentNV");
	GLM_struct->glBindProgramNVproc = (PFNGLBINDPROGRAMNVPROC)wglGetProcAddress("glBindProgramNV");
	GLM_struct->glDeleteProgramsNVproc = (PFNGLDELETEPROGRAMSNVPROC)wglGetProcAddress("glDeleteProgramsNV");
	GLM_struct->glExecuteProgramNVproc = (PFNGLEXECUTEPROGRAMNVPROC)wglGetProcAddress("glExecuteProgramNV");
	GLM_struct->glGenProgramsNVproc = (PFNGLGENPROGRAMSNVPROC)wglGetProcAddress("glGenProgramsNV");
	GLM_struct->glGetProgramParameterdvNVproc = (PFNGLGETPROGRAMPARAMETERDVNVPROC)wglGetProcAddress("glGetProgramParameterdvNV");
	GLM_struct->glGetProgramParameterfvNVproc = (PFNGLGETPROGRAMPARAMETERFVNVPROC)wglGetProcAddress("glGetProgramParameterfvNV");
	GLM_struct->glGetProgramivNVproc = (PFNGLGETPROGRAMIVNVPROC)wglGetProcAddress("glGetProgramivNV");
	GLM_struct->glGetProgramStringNVproc = (PFNGLGETPROGRAMSTRINGNVPROC)wglGetProcAddress("glGetProgramStringNV");
	GLM_struct->glGetTrackMatrixivNVproc = (PFNGLGETTRACKMATRIXIVNVPROC)wglGetProcAddress("glGetTrackMatrixivNV");
	GLM_struct->glGetVertexAttribdvNVproc = (PFNGLGETVERTEXATTRIBDVNVPROC)wglGetProcAddress("glGetVertexAttribdvNV");
	GLM_struct->glGetVertexAttribfvNVproc = (PFNGLGETVERTEXATTRIBFVNVPROC)wglGetProcAddress("glGetVertexAttribfvNV");
	GLM_struct->glGetVertexAttribivNVproc = (PFNGLGETVERTEXATTRIBIVNVPROC)wglGetProcAddress("glGetVertexAttribivNV");
	GLM_struct->glGetVertexAttribPointervNVproc = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)wglGetProcAddress("glGetVertexAttribPointervNV");
	GLM_struct->glIsProgramNVproc = (PFNGLISPROGRAMNVPROC)wglGetProcAddress("glIsProgramNV");
	GLM_struct->glLoadProgramNVproc = (PFNGLLOADPROGRAMNVPROC)wglGetProcAddress("glLoadProgramNV");
	GLM_struct->glProgramParameter4dNVproc = (PFNGLPROGRAMPARAMETER4DNVPROC)wglGetProcAddress("glProgramParameter4dNV");
	GLM_struct->glProgramParameter4dvNVproc = (PFNGLPROGRAMPARAMETER4DVNVPROC)wglGetProcAddress("glProgramParameter4dvNV");
	GLM_struct->glProgramParameter4fNVproc = (PFNGLPROGRAMPARAMETER4FNVPROC)wglGetProcAddress("glProgramParameter4fNV");
	GLM_struct->glProgramParameter4fvNVproc = (PFNGLPROGRAMPARAMETER4FVNVPROC)wglGetProcAddress("glProgramParameter4fvNV");
	GLM_struct->glProgramParameters4dvNVproc = (PFNGLPROGRAMPARAMETERS4DVNVPROC)wglGetProcAddress("glProgramParameters4dvNV");
	GLM_struct->glProgramParameters4fvNVproc = (PFNGLPROGRAMPARAMETERS4FVNVPROC)wglGetProcAddress("glProgramParameters4fvNV");
	GLM_struct->glRequestResidentProgramsNVproc = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC)wglGetProcAddress("glRequestResidentProgramsNV");
	GLM_struct->glTrackMatrixNVproc = (PFNGLTRACKMATRIXNVPROC)wglGetProcAddress("glTrackMatrixNV");
	GLM_struct->glVertexAttribPointerNVproc = (PFNGLVERTEXATTRIBPOINTERNVPROC)wglGetProcAddress("glVertexAttribPointerNV");
	GLM_struct->glVertexAttrib1dNVproc = (PFNGLVERTEXATTRIB1DNVPROC)wglGetProcAddress("glVertexAttrib1dNV");
	GLM_struct->glVertexAttrib1dvNVproc = (PFNGLVERTEXATTRIB1DVNVPROC)wglGetProcAddress("glVertexAttrib1dvNV");
	GLM_struct->glVertexAttrib1fNVproc = (PFNGLVERTEXATTRIB1FNVPROC)wglGetProcAddress("glVertexAttrib1fNV");
	GLM_struct->glVertexAttrib1fvNVproc = (PFNGLVERTEXATTRIB1FVNVPROC)wglGetProcAddress("glVertexAttrib1fvNV");
	GLM_struct->glVertexAttrib1sNVproc = (PFNGLVERTEXATTRIB1SNVPROC)wglGetProcAddress("glVertexAttrib1sNV");
	GLM_struct->glVertexAttrib1svNVproc = (PFNGLVERTEXATTRIB1SVNVPROC)wglGetProcAddress("glVertexAttrib1svNV");
	GLM_struct->glVertexAttrib2dNVproc = (PFNGLVERTEXATTRIB2DNVPROC)wglGetProcAddress("glVertexAttrib2dNV");
	GLM_struct->glVertexAttrib2dvNVproc = (PFNGLVERTEXATTRIB2DVNVPROC)wglGetProcAddress("glVertexAttrib2dvNV");
	GLM_struct->glVertexAttrib2fNVproc = (PFNGLVERTEXATTRIB2FNVPROC)wglGetProcAddress("glVertexAttrib2fNV");
	GLM_struct->glVertexAttrib2fvNVproc = (PFNGLVERTEXATTRIB2FVNVPROC)wglGetProcAddress("glVertexAttrib2fvNV");
	GLM_struct->glVertexAttrib2sNVproc = (PFNGLVERTEXATTRIB2SNVPROC)wglGetProcAddress("glVertexAttrib2sNV");
	GLM_struct->glVertexAttrib2svNVproc = (PFNGLVERTEXATTRIB2SVNVPROC)wglGetProcAddress("glVertexAttrib2svNV");
	GLM_struct->glVertexAttrib3dNVproc = (PFNGLVERTEXATTRIB3DNVPROC)wglGetProcAddress("glVertexAttrib3dNV");
	GLM_struct->glVertexAttrib3dvNVproc = (PFNGLVERTEXATTRIB3DVNVPROC)wglGetProcAddress("glVertexAttrib3dvNV");
	GLM_struct->glVertexAttrib3fNVproc = (PFNGLVERTEXATTRIB3FNVPROC)wglGetProcAddress("glVertexAttrib3fNV");
	GLM_struct->glVertexAttrib3fvNVproc = (PFNGLVERTEXATTRIB3FVNVPROC)wglGetProcAddress("glVertexAttrib3fvNV");
	GLM_struct->glVertexAttrib3sNVproc = (PFNGLVERTEXATTRIB3SNVPROC)wglGetProcAddress("glVertexAttrib3sNV");
	GLM_struct->glVertexAttrib3svNVproc = (PFNGLVERTEXATTRIB3SVNVPROC)wglGetProcAddress("glVertexAttrib3svNV");
	GLM_struct->glVertexAttrib4dNVproc = (PFNGLVERTEXATTRIB4DNVPROC)wglGetProcAddress("glVertexAttrib4dNV");
	GLM_struct->glVertexAttrib4dvNVproc = (PFNGLVERTEXATTRIB4DVNVPROC)wglGetProcAddress("glVertexAttrib4dvNV");
	GLM_struct->glVertexAttrib4fNVproc = (PFNGLVERTEXATTRIB4FNVPROC)wglGetProcAddress("glVertexAttrib4fNV");
	GLM_struct->glVertexAttrib4fvNVproc = (PFNGLVERTEXATTRIB4FVNVPROC)wglGetProcAddress("glVertexAttrib4fvNV");
	GLM_struct->glVertexAttrib4sNVproc = (PFNGLVERTEXATTRIB4SNVPROC)wglGetProcAddress("glVertexAttrib4sNV");
	GLM_struct->glVertexAttrib4svNVproc = (PFNGLVERTEXATTRIB4SVNVPROC)wglGetProcAddress("glVertexAttrib4svNV");
	GLM_struct->glVertexAttrib4ubNVproc = (PFNGLVERTEXATTRIB4UBNVPROC)wglGetProcAddress("glVertexAttrib4ubNV");
	GLM_struct->glVertexAttrib4ubvNVproc = (PFNGLVERTEXATTRIB4UBVNVPROC)wglGetProcAddress("glVertexAttrib4ubvNV");
	GLM_struct->glVertexAttribs1dvNVproc = (PFNGLVERTEXATTRIBS1DVNVPROC)wglGetProcAddress("glVertexAttribs1dvNV");
	GLM_struct->glVertexAttribs1fvNVproc = (PFNGLVERTEXATTRIBS1FVNVPROC)wglGetProcAddress("glVertexAttribs1fvNV");
	GLM_struct->glVertexAttribs1svNVproc = (PFNGLVERTEXATTRIBS1SVNVPROC)wglGetProcAddress("glVertexAttribs1svNV");
	GLM_struct->glVertexAttribs2dvNVproc = (PFNGLVERTEXATTRIBS2DVNVPROC)wglGetProcAddress("glVertexAttribs2dvNV");
	GLM_struct->glVertexAttribs2fvNVproc = (PFNGLVERTEXATTRIBS2FVNVPROC)wglGetProcAddress("glVertexAttribs2fvNV");
	GLM_struct->glVertexAttribs2svNVproc = (PFNGLVERTEXATTRIBS2SVNVPROC)wglGetProcAddress("glVertexAttribs2svNV");
	GLM_struct->glVertexAttribs3dvNVproc = (PFNGLVERTEXATTRIBS3DVNVPROC)wglGetProcAddress("glVertexAttribs3dvNV");
	GLM_struct->glVertexAttribs3fvNVproc = (PFNGLVERTEXATTRIBS3FVNVPROC)wglGetProcAddress("glVertexAttribs3fvNV");
	GLM_struct->glVertexAttribs3svNVproc = (PFNGLVERTEXATTRIBS3SVNVPROC)wglGetProcAddress("glVertexAttribs3svNV");
	GLM_struct->glVertexAttribs4dvNVproc = (PFNGLVERTEXATTRIBS4DVNVPROC)wglGetProcAddress("glVertexAttribs4dvNV");
	GLM_struct->glVertexAttribs4fvNVproc = (PFNGLVERTEXATTRIBS4FVNVPROC)wglGetProcAddress("glVertexAttribs4fvNV");
	GLM_struct->glVertexAttribs4svNVproc = (PFNGLVERTEXATTRIBS4SVNVPROC)wglGetProcAddress("glVertexAttribs4svNV");
	GLM_struct->glVertexAttribs4ubvNVproc = (PFNGLVERTEXATTRIBS4UBVNVPROC)wglGetProcAddress("glVertexAttribs4ubvNV");
	GLM_struct->glBeginVideoCaptureNVproc = (PFNGLBEGINVIDEOCAPTURENVPROC)wglGetProcAddress("glBeginVideoCaptureNV");
	GLM_struct->glBindVideoCaptureStreamBufferNVproc = (PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)wglGetProcAddress("glBindVideoCaptureStreamBufferNV");
	GLM_struct->glBindVideoCaptureStreamTextureNVproc = (PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)wglGetProcAddress("glBindVideoCaptureStreamTextureNV");
	GLM_struct->glEndVideoCaptureNVproc = (PFNGLENDVIDEOCAPTURENVPROC)wglGetProcAddress("glEndVideoCaptureNV");
	GLM_struct->glGetVideoCaptureivNVproc = (PFNGLGETVIDEOCAPTUREIVNVPROC)wglGetProcAddress("glGetVideoCaptureivNV");
	GLM_struct->glGetVideoCaptureStreamivNVproc = (PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)wglGetProcAddress("glGetVideoCaptureStreamivNV");
	GLM_struct->glGetVideoCaptureStreamfvNVproc = (PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)wglGetProcAddress("glGetVideoCaptureStreamfvNV");
	GLM_struct->glGetVideoCaptureStreamdvNVproc = (PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)wglGetProcAddress("glGetVideoCaptureStreamdvNV");
	GLM_struct->glVideoCaptureNVproc = (PFNGLVIDEOCAPTURENVPROC)wglGetProcAddress("glVideoCaptureNV");
	GLM_struct->glVideoCaptureStreamParameterivNVproc = (PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)wglGetProcAddress("glVideoCaptureStreamParameterivNV");
	GLM_struct->glVideoCaptureStreamParameterfvNVproc = (PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)wglGetProcAddress("glVideoCaptureStreamParameterfvNV");
	GLM_struct->glVideoCaptureStreamParameterdvNVproc = (PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)wglGetProcAddress("glVideoCaptureStreamParameterdvNV");
	GLM_struct->glViewportSwizzleNVproc = (PFNGLVIEWPORTSWIZZLENVPROC)wglGetProcAddress("glViewportSwizzleNV");
	GLM_struct->glFramebufferTextureMultiviewOVRproc = (PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)wglGetProcAddress("glFramebufferTextureMultiviewOVR");
	GLM_struct->glNamedFramebufferTextureMultiviewOVRproc = (PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)wglGetProcAddress("glNamedFramebufferTextureMultiviewOVR");
	GLM_struct->glHintPGIproc = (PFNGLHINTPGIPROC)wglGetProcAddress("glHintPGI");
	GLM_struct->glDetailTexFuncSGISproc = (PFNGLDETAILTEXFUNCSGISPROC)wglGetProcAddress("glDetailTexFuncSGIS");
	GLM_struct->glGetDetailTexFuncSGISproc = (PFNGLGETDETAILTEXFUNCSGISPROC)wglGetProcAddress("glGetDetailTexFuncSGIS");
	GLM_struct->glFogFuncSGISproc = (PFNGLFOGFUNCSGISPROC)wglGetProcAddress("glFogFuncSGIS");
	GLM_struct->glGetFogFuncSGISproc = (PFNGLGETFOGFUNCSGISPROC)wglGetProcAddress("glGetFogFuncSGIS");
	GLM_struct->glSampleMaskSGISproc = (PFNGLSAMPLEMASKSGISPROC)wglGetProcAddress("glSampleMaskSGIS");
	GLM_struct->glSamplePatternSGISproc = (PFNGLSAMPLEPATTERNSGISPROC)wglGetProcAddress("glSamplePatternSGIS");
	GLM_struct->glPixelTexGenParameteriSGISproc = (PFNGLPIXELTEXGENPARAMETERISGISPROC)wglGetProcAddress("glPixelTexGenParameteriSGIS");
	GLM_struct->glPixelTexGenParameterivSGISproc = (PFNGLPIXELTEXGENPARAMETERIVSGISPROC)wglGetProcAddress("glPixelTexGenParameterivSGIS");
	GLM_struct->glPixelTexGenParameterfSGISproc = (PFNGLPIXELTEXGENPARAMETERFSGISPROC)wglGetProcAddress("glPixelTexGenParameterfSGIS");
	GLM_struct->glPixelTexGenParameterfvSGISproc = (PFNGLPIXELTEXGENPARAMETERFVSGISPROC)wglGetProcAddress("glPixelTexGenParameterfvSGIS");
	GLM_struct->glGetPixelTexGenParameterivSGISproc = (PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)wglGetProcAddress("glGetPixelTexGenParameterivSGIS");
	GLM_struct->glGetPixelTexGenParameterfvSGISproc = (PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)wglGetProcAddress("glGetPixelTexGenParameterfvSGIS");
	GLM_struct->glPointParameterfSGISproc = (PFNGLPOINTPARAMETERFSGISPROC)wglGetProcAddress("glPointParameterfSGIS");
	GLM_struct->glPointParameterfvSGISproc = (PFNGLPOINTPARAMETERFVSGISPROC)wglGetProcAddress("glPointParameterfvSGIS");
	GLM_struct->glSharpenTexFuncSGISproc = (PFNGLSHARPENTEXFUNCSGISPROC)wglGetProcAddress("glSharpenTexFuncSGIS");
	GLM_struct->glGetSharpenTexFuncSGISproc = (PFNGLGETSHARPENTEXFUNCSGISPROC)wglGetProcAddress("glGetSharpenTexFuncSGIS");
	GLM_struct->glTexImage4DSGISproc = (PFNGLTEXIMAGE4DSGISPROC)wglGetProcAddress("glTexImage4DSGIS");
	GLM_struct->glTexSubImage4DSGISproc = (PFNGLTEXSUBIMAGE4DSGISPROC)wglGetProcAddress("glTexSubImage4DSGIS");
	GLM_struct->glTextureColorMaskSGISproc = (PFNGLTEXTURECOLORMASKSGISPROC)wglGetProcAddress("glTextureColorMaskSGIS");
	GLM_struct->glGetTexFilterFuncSGISproc = (PFNGLGETTEXFILTERFUNCSGISPROC)wglGetProcAddress("glGetTexFilterFuncSGIS");
	GLM_struct->glTexFilterFuncSGISproc = (PFNGLTEXFILTERFUNCSGISPROC)wglGetProcAddress("glTexFilterFuncSGIS");
	GLM_struct->glAsyncMarkerSGIXproc = (PFNGLASYNCMARKERSGIXPROC)wglGetProcAddress("glAsyncMarkerSGIX");
	GLM_struct->glFinishAsyncSGIXproc = (PFNGLFINISHASYNCSGIXPROC)wglGetProcAddress("glFinishAsyncSGIX");
	GLM_struct->glPollAsyncSGIXproc = (PFNGLPOLLASYNCSGIXPROC)wglGetProcAddress("glPollAsyncSGIX");
	GLM_struct->glGenAsyncMarkersSGIXproc = (PFNGLGENASYNCMARKERSSGIXPROC)wglGetProcAddress("glGenAsyncMarkersSGIX");
	GLM_struct->glDeleteAsyncMarkersSGIXproc = (PFNGLDELETEASYNCMARKERSSGIXPROC)wglGetProcAddress("glDeleteAsyncMarkersSGIX");
	GLM_struct->glIsAsyncMarkerSGIXproc = (PFNGLISASYNCMARKERSGIXPROC)wglGetProcAddress("glIsAsyncMarkerSGIX");
	GLM_struct->glFlushRasterSGIXproc = (PFNGLFLUSHRASTERSGIXPROC)wglGetProcAddress("glFlushRasterSGIX");
	GLM_struct->glFragmentColorMaterialSGIXproc = (PFNGLFRAGMENTCOLORMATERIALSGIXPROC)wglGetProcAddress("glFragmentColorMaterialSGIX");
	GLM_struct->glFragmentLightfSGIXproc = (PFNGLFRAGMENTLIGHTFSGIXPROC)wglGetProcAddress("glFragmentLightfSGIX");
	GLM_struct->glFragmentLightfvSGIXproc = (PFNGLFRAGMENTLIGHTFVSGIXPROC)wglGetProcAddress("glFragmentLightfvSGIX");
	GLM_struct->glFragmentLightiSGIXproc = (PFNGLFRAGMENTLIGHTISGIXPROC)wglGetProcAddress("glFragmentLightiSGIX");
	GLM_struct->glFragmentLightivSGIXproc = (PFNGLFRAGMENTLIGHTIVSGIXPROC)wglGetProcAddress("glFragmentLightivSGIX");
	GLM_struct->glFragmentLightModelfSGIXproc = (PFNGLFRAGMENTLIGHTMODELFSGIXPROC)wglGetProcAddress("glFragmentLightModelfSGIX");
	GLM_struct->glFragmentLightModelfvSGIXproc = (PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)wglGetProcAddress("glFragmentLightModelfvSGIX");
	GLM_struct->glFragmentLightModeliSGIXproc = (PFNGLFRAGMENTLIGHTMODELISGIXPROC)wglGetProcAddress("glFragmentLightModeliSGIX");
	GLM_struct->glFragmentLightModelivSGIXproc = (PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)wglGetProcAddress("glFragmentLightModelivSGIX");
	GLM_struct->glFragmentMaterialfSGIXproc = (PFNGLFRAGMENTMATERIALFSGIXPROC)wglGetProcAddress("glFragmentMaterialfSGIX");
	GLM_struct->glFragmentMaterialfvSGIXproc = (PFNGLFRAGMENTMATERIALFVSGIXPROC)wglGetProcAddress("glFragmentMaterialfvSGIX");
	GLM_struct->glFragmentMaterialiSGIXproc = (PFNGLFRAGMENTMATERIALISGIXPROC)wglGetProcAddress("glFragmentMaterialiSGIX");
	GLM_struct->glFragmentMaterialivSGIXproc = (PFNGLFRAGMENTMATERIALIVSGIXPROC)wglGetProcAddress("glFragmentMaterialivSGIX");
	GLM_struct->glGetFragmentLightfvSGIXproc = (PFNGLGETFRAGMENTLIGHTFVSGIXPROC)wglGetProcAddress("glGetFragmentLightfvSGIX");
	GLM_struct->glGetFragmentLightivSGIXproc = (PFNGLGETFRAGMENTLIGHTIVSGIXPROC)wglGetProcAddress("glGetFragmentLightivSGIX");
	GLM_struct->glGetFragmentMaterialfvSGIXproc = (PFNGLGETFRAGMENTMATERIALFVSGIXPROC)wglGetProcAddress("glGetFragmentMaterialfvSGIX");
	GLM_struct->glGetFragmentMaterialivSGIXproc = (PFNGLGETFRAGMENTMATERIALIVSGIXPROC)wglGetProcAddress("glGetFragmentMaterialivSGIX");
	GLM_struct->glLightEnviSGIXproc = (PFNGLLIGHTENVISGIXPROC)wglGetProcAddress("glLightEnviSGIX");
	GLM_struct->glFrameZoomSGIXproc = (PFNGLFRAMEZOOMSGIXPROC)wglGetProcAddress("glFrameZoomSGIX");
	GLM_struct->glIglooInterfaceSGIXproc = (PFNGLIGLOOINTERFACESGIXPROC)wglGetProcAddress("glIglooInterfaceSGIX");
	GLM_struct->glGetInstrumentsSGIXproc = (PFNGLGETINSTRUMENTSSGIXPROC)wglGetProcAddress("glGetInstrumentsSGIX");
	GLM_struct->glInstrumentsBufferSGIXproc = (PFNGLINSTRUMENTSBUFFERSGIXPROC)wglGetProcAddress("glInstrumentsBufferSGIX");
	GLM_struct->glPollInstrumentsSGIXproc = (PFNGLPOLLINSTRUMENTSSGIXPROC)wglGetProcAddress("glPollInstrumentsSGIX");
	GLM_struct->glReadInstrumentsSGIXproc = (PFNGLREADINSTRUMENTSSGIXPROC)wglGetProcAddress("glReadInstrumentsSGIX");
	GLM_struct->glStartInstrumentsSGIXproc = (PFNGLSTARTINSTRUMENTSSGIXPROC)wglGetProcAddress("glStartInstrumentsSGIX");
	GLM_struct->glStopInstrumentsSGIXproc = (PFNGLSTOPINSTRUMENTSSGIXPROC)wglGetProcAddress("glStopInstrumentsSGIX");
	GLM_struct->glGetListParameterfvSGIXproc = (PFNGLGETLISTPARAMETERFVSGIXPROC)wglGetProcAddress("glGetListParameterfvSGIX");
	GLM_struct->glGetListParameterivSGIXproc = (PFNGLGETLISTPARAMETERIVSGIXPROC)wglGetProcAddress("glGetListParameterivSGIX");
	GLM_struct->glListParameterfSGIXproc = (PFNGLLISTPARAMETERFSGIXPROC)wglGetProcAddress("glListParameterfSGIX");
	GLM_struct->glListParameterfvSGIXproc = (PFNGLLISTPARAMETERFVSGIXPROC)wglGetProcAddress("glListParameterfvSGIX");
	GLM_struct->glListParameteriSGIXproc = (PFNGLLISTPARAMETERISGIXPROC)wglGetProcAddress("glListParameteriSGIX");
	GLM_struct->glListParameterivSGIXproc = (PFNGLLISTPARAMETERIVSGIXPROC)wglGetProcAddress("glListParameterivSGIX");
	GLM_struct->glPixelTexGenSGIXproc = (PFNGLPIXELTEXGENSGIXPROC)wglGetProcAddress("glPixelTexGenSGIX");
	GLM_struct->glDeformationMap3dSGIXproc = (PFNGLDEFORMATIONMAP3DSGIXPROC)wglGetProcAddress("glDeformationMap3dSGIX");
	GLM_struct->glDeformationMap3fSGIXproc = (PFNGLDEFORMATIONMAP3FSGIXPROC)wglGetProcAddress("glDeformationMap3fSGIX");
	GLM_struct->glDeformSGIXproc = (PFNGLDEFORMSGIXPROC)wglGetProcAddress("glDeformSGIX");
	GLM_struct->glLoadIdentityDeformationMapSGIXproc = (PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)wglGetProcAddress("glLoadIdentityDeformationMapSGIX");
	GLM_struct->glReferencePlaneSGIXproc = (PFNGLREFERENCEPLANESGIXPROC)wglGetProcAddress("glReferencePlaneSGIX");
	GLM_struct->glSpriteParameterfSGIXproc = (PFNGLSPRITEPARAMETERFSGIXPROC)wglGetProcAddress("glSpriteParameterfSGIX");
	GLM_struct->glSpriteParameterfvSGIXproc = (PFNGLSPRITEPARAMETERFVSGIXPROC)wglGetProcAddress("glSpriteParameterfvSGIX");
	GLM_struct->glSpriteParameteriSGIXproc = (PFNGLSPRITEPARAMETERISGIXPROC)wglGetProcAddress("glSpriteParameteriSGIX");
	GLM_struct->glSpriteParameterivSGIXproc = (PFNGLSPRITEPARAMETERIVSGIXPROC)wglGetProcAddress("glSpriteParameterivSGIX");
	GLM_struct->glTagSampleBufferSGIXproc = (PFNGLTAGSAMPLEBUFFERSGIXPROC)wglGetProcAddress("glTagSampleBufferSGIX");
	GLM_struct->glColorTableSGIproc = (PFNGLCOLORTABLESGIPROC)wglGetProcAddress("glColorTableSGI");
	GLM_struct->glColorTableParameterfvSGIproc = (PFNGLCOLORTABLEPARAMETERFVSGIPROC)wglGetProcAddress("glColorTableParameterfvSGI");
	GLM_struct->glColorTableParameterivSGIproc = (PFNGLCOLORTABLEPARAMETERIVSGIPROC)wglGetProcAddress("glColorTableParameterivSGI");
	GLM_struct->glCopyColorTableSGIproc = (PFNGLCOPYCOLORTABLESGIPROC)wglGetProcAddress("glCopyColorTableSGI");
	GLM_struct->glGetColorTableSGIproc = (PFNGLGETCOLORTABLESGIPROC)wglGetProcAddress("glGetColorTableSGI");
	GLM_struct->glGetColorTableParameterfvSGIproc = (PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)wglGetProcAddress("glGetColorTableParameterfvSGI");
	GLM_struct->glGetColorTableParameterivSGIproc = (PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)wglGetProcAddress("glGetColorTableParameterivSGI");
	GLM_struct->glFinishTextureSUNXproc = (PFNGLFINISHTEXTURESUNXPROC)wglGetProcAddress("glFinishTextureSUNX");
	GLM_struct->glGlobalAlphaFactorbSUNproc = (PFNGLGLOBALALPHAFACTORBSUNPROC)wglGetProcAddress("glGlobalAlphaFactorbSUN");
	GLM_struct->glGlobalAlphaFactorsSUNproc = (PFNGLGLOBALALPHAFACTORSSUNPROC)wglGetProcAddress("glGlobalAlphaFactorsSUN");
	GLM_struct->glGlobalAlphaFactoriSUNproc = (PFNGLGLOBALALPHAFACTORISUNPROC)wglGetProcAddress("glGlobalAlphaFactoriSUN");
	GLM_struct->glGlobalAlphaFactorfSUNproc = (PFNGLGLOBALALPHAFACTORFSUNPROC)wglGetProcAddress("glGlobalAlphaFactorfSUN");
	GLM_struct->glGlobalAlphaFactordSUNproc = (PFNGLGLOBALALPHAFACTORDSUNPROC)wglGetProcAddress("glGlobalAlphaFactordSUN");
	GLM_struct->glGlobalAlphaFactorubSUNproc = (PFNGLGLOBALALPHAFACTORUBSUNPROC)wglGetProcAddress("glGlobalAlphaFactorubSUN");
	GLM_struct->glGlobalAlphaFactorusSUNproc = (PFNGLGLOBALALPHAFACTORUSSUNPROC)wglGetProcAddress("glGlobalAlphaFactorusSUN");
	GLM_struct->glGlobalAlphaFactoruiSUNproc = (PFNGLGLOBALALPHAFACTORUISUNPROC)wglGetProcAddress("glGlobalAlphaFactoruiSUN");
	GLM_struct->glDrawMeshArraysSUNproc = (PFNGLDRAWMESHARRAYSSUNPROC)wglGetProcAddress("glDrawMeshArraysSUN");
	GLM_struct->glReplacementCodeuiSUNproc = (PFNGLREPLACEMENTCODEUISUNPROC)wglGetProcAddress("glReplacementCodeuiSUN");
	GLM_struct->glReplacementCodeusSUNproc = (PFNGLREPLACEMENTCODEUSSUNPROC)wglGetProcAddress("glReplacementCodeusSUN");
	GLM_struct->glReplacementCodeubSUNproc = (PFNGLREPLACEMENTCODEUBSUNPROC)wglGetProcAddress("glReplacementCodeubSUN");
	GLM_struct->glReplacementCodeuivSUNproc = (PFNGLREPLACEMENTCODEUIVSUNPROC)wglGetProcAddress("glReplacementCodeuivSUN");
	GLM_struct->glReplacementCodeusvSUNproc = (PFNGLREPLACEMENTCODEUSVSUNPROC)wglGetProcAddress("glReplacementCodeusvSUN");
	GLM_struct->glReplacementCodeubvSUNproc = (PFNGLREPLACEMENTCODEUBVSUNPROC)wglGetProcAddress("glReplacementCodeubvSUN");
	GLM_struct->glReplacementCodePointerSUNproc = (PFNGLREPLACEMENTCODEPOINTERSUNPROC)wglGetProcAddress("glReplacementCodePointerSUN");
	GLM_struct->glColor4ubVertex2fSUNproc = (PFNGLCOLOR4UBVERTEX2FSUNPROC)wglGetProcAddress("glColor4ubVertex2fSUN");
	GLM_struct->glColor4ubVertex2fvSUNproc = (PFNGLCOLOR4UBVERTEX2FVSUNPROC)wglGetProcAddress("glColor4ubVertex2fvSUN");
	GLM_struct->glColor4ubVertex3fSUNproc = (PFNGLCOLOR4UBVERTEX3FSUNPROC)wglGetProcAddress("glColor4ubVertex3fSUN");
	GLM_struct->glColor4ubVertex3fvSUNproc = (PFNGLCOLOR4UBVERTEX3FVSUNPROC)wglGetProcAddress("glColor4ubVertex3fvSUN");
	GLM_struct->glColor3fVertex3fSUNproc = (PFNGLCOLOR3FVERTEX3FSUNPROC)wglGetProcAddress("glColor3fVertex3fSUN");
	GLM_struct->glColor3fVertex3fvSUNproc = (PFNGLCOLOR3FVERTEX3FVSUNPROC)wglGetProcAddress("glColor3fVertex3fvSUN");
	GLM_struct->glNormal3fVertex3fSUNproc = (PFNGLNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glNormal3fVertex3fSUN");
	GLM_struct->glNormal3fVertex3fvSUNproc = (PFNGLNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glNormal3fVertex3fvSUN");
	GLM_struct->glColor4fNormal3fVertex3fSUNproc = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glColor4fNormal3fVertex3fSUN");
	GLM_struct->glColor4fNormal3fVertex3fvSUNproc = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glColor4fNormal3fVertex3fvSUN");
	GLM_struct->glTexCoord2fVertex3fSUNproc = (PFNGLTEXCOORD2FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fVertex3fSUN");
	GLM_struct->glTexCoord2fVertex3fvSUNproc = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fVertex3fvSUN");
	GLM_struct->glTexCoord4fVertex4fSUNproc = (PFNGLTEXCOORD4FVERTEX4FSUNPROC)wglGetProcAddress("glTexCoord4fVertex4fSUN");
	GLM_struct->glTexCoord4fVertex4fvSUNproc = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC)wglGetProcAddress("glTexCoord4fVertex4fvSUN");
	GLM_struct->glTexCoord2fColor4ubVertex3fSUNproc = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fColor4ubVertex3fSUN");
	GLM_struct->glTexCoord2fColor4ubVertex3fvSUNproc = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fColor4ubVertex3fvSUN");
	GLM_struct->glTexCoord2fColor3fVertex3fSUNproc = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fColor3fVertex3fSUN");
	GLM_struct->glTexCoord2fColor3fVertex3fvSUNproc = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fColor3fVertex3fvSUN");
	GLM_struct->glTexCoord2fNormal3fVertex3fSUNproc = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fNormal3fVertex3fSUN");
	GLM_struct->glTexCoord2fNormal3fVertex3fvSUNproc = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fNormal3fVertex3fvSUN");
	GLM_struct->glTexCoord2fColor4fNormal3fVertex3fSUNproc = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fSUN");
	GLM_struct->glTexCoord2fColor4fNormal3fVertex3fvSUNproc = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fvSUN");
	GLM_struct->glTexCoord4fColor4fNormal3fVertex4fSUNproc = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)wglGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fSUN");
	GLM_struct->glTexCoord4fColor4fNormal3fVertex4fvSUNproc = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)wglGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fvSUN");
	GLM_struct->glReplacementCodeuiVertex3fSUNproc = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiVertex3fSUN");
	GLM_struct->glReplacementCodeuiVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiVertex3fvSUN");
	GLM_struct->glReplacementCodeuiColor4ubVertex3fSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4ubVertex3fSUN");
	GLM_struct->glReplacementCodeuiColor4ubVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4ubVertex3fvSUN");
	GLM_struct->glReplacementCodeuiColor3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiColor3fVertex3fSUN");
	GLM_struct->glReplacementCodeuiColor3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiColor3fVertex3fvSUN");
	GLM_struct->glReplacementCodeuiNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiNormal3fVertex3fSUN");
	GLM_struct->glReplacementCodeuiNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiNormal3fVertex3fvSUN");
	GLM_struct->glReplacementCodeuiColor4fNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fSUN");
	GLM_struct->glReplacementCodeuiColor4fNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fvSUN");
	GLM_struct->glReplacementCodeuiTexCoord2fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fSUN");
	GLM_struct->glReplacementCodeuiTexCoord2fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fvSUN");
	GLM_struct->glReplacementCodeuiTexCoord2fNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN");
	GLM_struct->glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN");
	GLM_struct->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN");
	GLM_struct->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUNproc = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)wglGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN");
}