#pragma once

namespace win_event {
	void Start(double time);
	void Update(double time);
	void SyncUpdate(double time);
	void Resize(double time, int width, int height);
	void Render(double time);

	void TerminateWindow();
	double GetTime();
}