#pragma once

#include <mutex>
#include <atomic>

namespace native
{
	constexpr int MOUSE_NO_MOVE = 0;
	constexpr int MOUSE_MOVE_UP = 1;
	constexpr int MOUSE_MOVE_DOWN = 2;
	constexpr int MOUSE_MOVE_LEFT = 3;
	constexpr int MOUSE_MOVE_RIGHT = 4;

	static bool g_previousKeyState[256] = { false };
	static float g_prevX = -1.0f;
	static float g_prevY = -1.0f;
	static std::mutex g_colorMutex;
	static std::atomic<bool> g_pendingColor = false;
	static int g_pendingR, g_pendingG, g_pendingB;

	void setPalette(int r, int g, int b);
	void closePalette();
	void processPendingColor();
};