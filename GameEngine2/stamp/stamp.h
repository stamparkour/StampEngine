#pragma once

#include <stamp/define.h>

STAMP_NAMESPACE_BEGIN

struct StampEngineSettings {
	bool showConsole = false;
};

void InitStampEngine(const StampEngineSettings&);
void CloseStampEngine();

bool IsRenderThread();
//bool RenderThreadId();

STAMP_NAMESPACE_END