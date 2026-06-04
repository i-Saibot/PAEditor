#pragma once


namespace win_system
{
	inline HWND foregroundWindow = nullptr;

	inline bool getGtaSanAndreasActive()
	{
		wchar_t windowTitle[50];
		foregroundWindow = GetForegroundWindow();

		GetWindowTextW(foregroundWindow, windowTitle, sizeof(windowTitle) / sizeof(windowTitle[0]));
		return (wcsstr(windowTitle, L"GTA:SA:MP") != nullptr);
	}
}