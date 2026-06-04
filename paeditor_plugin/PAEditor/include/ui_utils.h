#pragma once
#include <windows.h>

namespace ui_utils
{
	enum class DragMode
	{
		NONE,
		SPECTRUM,
		BRIGHTNESS
	};

	static DragMode g_currentMode = DragMode::NONE;
	static HFONT g_hFontUI = NULL;
	static HWND g_paletteWnd = NULL;
	static HWND g_gameWnd = NULL;
	static HWINEVENTHOOK g_hMinHook = NULL;
	static HWINEVENTHOOK g_hFgHook = NULL;
	static bool g_bIsRunning = false;
	static COLORREF g_baseColor = RGB(255, 0, 0);
	static float g_brightness = 1.0f;
	static float g_ratSpec = 0.0f;
	static bool g_bCopied = false;
	static DWORD g_dwCopiedAt = 0;
	static RECT rSpec = { 15,  45, 285, 115 };
	static RECT rBright = { 300, 45, 320, 115 };
	static RECT rClose = { 345, 10, 365,  30 };
	static bool g_bVisible = false;

	void showPalette();
	void hidePalette();
	void destroyPalette();
	void initPaletteClass();
}