#define SAMP_SDK_WANT_AMX_EVENTS
#include "samp-sdk/samp_sdk.hpp"

#include "win_system.h"
#include "native.h"
#include "ui_utils.h"

#include <Windows.h>
#include <cmath>


void native::setPalette(int r, int g, int b)
{
	std::lock_guard<std::mutex> lock(g_colorMutex);
	g_pendingR = r;
	g_pendingG = g;
	g_pendingB = b;
	g_pendingColor = true;
}

void native::processPendingColor()
{
	if (!g_pendingColor)
	{
		return;
	}
	int r, g, b;
	{
		std::lock_guard<std::mutex> lock(g_colorMutex);
		r = g_pendingR;
		g = g_pendingG;
		b = g_pendingB;
		g_pendingColor = false;
	}
	char hexColor[8];
	snprintf(hexColor, sizeof(hexColor), "%02X%02X%02X", r, g, b);
	Pawn_Public(OnPaletteChange, std::string(hexColor));
}

void native::closePalette()
{
	Pawn_Public(OnPaletteClose);
}

Plugin_Native(ShowPalette, AMX* amx, cell* params)
{
	ui_utils::showPalette();
	return 1;
}

Plugin_Native(HidePalette, AMX* amx, cell* params)
{
	ui_utils::hidePalette();
	return 1;
}

Plugin_Native(GetKeyPressed, AMX* amx, cell* params)
{
	if (!win_system::getGtaSanAndreasActive())
	{
		return 0;
	}
	int32_t vKey;
	Register_Parameters(vKey);

	return (GetAsyncKeyState(vKey) & 0x8001) != 0;
}

Plugin_Native(GetKeyReleased, AMX* amx, cell* params)
{
	if (!win_system::getGtaSanAndreasActive())
	{
		return 0;
	}
	int32_t vKey;
	Register_Parameters(vKey);

	bool isReleased = !((GetAsyncKeyState(vKey) & 0x8001) != 0);
	bool wasPressed = native::g_previousKeyState[vKey];

	native::g_previousKeyState[vKey] = !isReleased;

	return (wasPressed && isReleased);
}

Plugin_Native(GetMousePos, AMX* amx, cell* params)
{
	if (!win_system::getGtaSanAndreasActive())
	{
		return 0;
	}
	POINT cursor;
	RECT screen;

	GetCursorPos(&cursor);

	if (!win_system::foregroundWindow)
	{
		return 0;
	}
	GetWindowRect(win_system::foregroundWindow, &screen);

	float width = static_cast<float>(screen.right - screen.left);
	float height = static_cast<float>(screen.bottom - screen.top);

	if (width <= 0 || height <= 0)
	{
		return 0;
	}
	float x = static_cast<float>(cursor.x - screen.left) / width;
	float y = static_cast<float>(cursor.y - screen.top) / height;

	Samp_SDK::Native_Params p(amx, params);

	p.Set_REF(0, x);
	p.Set_REF(1, y);
	return 1;
}

Plugin_Native(GetMouseDirection, AMX* amx, cell* params)
{
	if (!win_system::getGtaSanAndreasActive())
	{
		return native::MOUSE_NO_MOVE;
	}
	POINT cursor;
	RECT screen;

	if (!GetCursorPos(&cursor) || !win_system::foregroundWindow)
	{
		return native::MOUSE_NO_MOVE;
	}
	GetWindowRect(win_system::foregroundWindow, &screen);

	float width = static_cast<float>(screen.right - screen.left);
	float height = static_cast<float>(screen.bottom - screen.top);

	if (width <= 0 || height <= 0)
	{
		return native::MOUSE_NO_MOVE;
	}
	float currentX = static_cast<float>(cursor.x - screen.left) / width;
	float currentY = static_cast<float>(cursor.y - screen.top) / height;

	if (native::g_prevX < 0)
	{
		native::g_prevX = currentX;
		native::g_prevY = currentY;
		return native::MOUSE_NO_MOVE;
	}
	float deltaX = currentX - native::g_prevX;
	float deltaY = currentY - native::g_prevY;

	native::g_prevX = currentX;
	native::g_prevY = currentY;

	float absX = abs(deltaX);
	float absY = abs(deltaY);

	if (absX < 0.001f && absY < 0.001f)
	{
		return native::MOUSE_NO_MOVE;
	}
	if (absX > absY)
	{
		return (deltaX > 0) ? native::MOUSE_MOVE_RIGHT : native::MOUSE_MOVE_LEFT;
	}
	else
	{
		return (deltaY > 0) ? native::MOUSE_MOVE_DOWN : native::MOUSE_MOVE_UP;
	}
	return native::MOUSE_NO_MOVE;
}