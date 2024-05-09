#pragma once

namespace win::event {

	enum struct WindowStyle {
		Normal,
		Borderless,
	};

	void Start(double time);
	void Update(double time);
	void SyncUpdate(double time);
	void Resize(double time, int width, int height);
	void Render(double time);

	void TerminateWindow();
	double GetTime();
	bool isWindowActive();
	void SetWindowState(WindowStyle style, unsigned int width, unsigned int height);
	bool vSync();
	void vSync(bool enable);
}