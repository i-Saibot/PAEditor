#include <Windows.h>
#include "SDK\amx\amx.h"
#include "SDK\plugincommon.h"

typedef void (*logprintf_t)(char* format, ...);

logprintf_t logprintf;
extern void* pAMXFunctions;

cell* Buff;
POINT Cursor;
RECT Screen;

const int MAX_KEYS_STATE = 256;

bool previousKeyState[MAX_KEYS_STATE] = { false };


bool IsGtaSanAndreasActive()
{
	HWND foregroundWindow = GetForegroundWindow();
	wchar_t windowTitle[256];
	GetWindowTextW(foregroundWindow, windowTitle, sizeof(windowTitle) / sizeof(windowTitle[0]));
	return (wcsstr(windowTitle, L"GTA:SA:MP") != nullptr);
}

cell AMX_NATIVE_CALL GetKeyPressed(AMX* amx, cell* params)
{
	if (!IsGtaSanAndreasActive()) {
		return 0;
	}

	return (GetAsyncKeyState(params[1]) & 0x8001) != 0;
}

cell AMX_NATIVE_CALL GetKeyReleased(AMX* amx, cell* params)
{
	if (!IsGtaSanAndreasActive()) {
		return 0;
	}

	int key = params[1];
	bool isReleased = !((GetAsyncKeyState(key) & 0x8001) != 0);
	bool wasPressed = previousKeyState[key];

	previousKeyState[key] = !isReleased;

	return (wasPressed && isReleased);
}

cell AMX_NATIVE_CALL GetMousePos(AMX* amx, cell* params)
{
	GetCursorPos(&Cursor);
	GetWindowRect(GetDesktopWindow(), &Screen);

	float normalizedX = static_cast<float>(Cursor.x - Screen.left) / static_cast<float>(Screen.right - Screen.left);
	float normalizedY = static_cast<float>(Cursor.y - Screen.top) / static_cast<float>(Screen.bottom - Screen.top);

	amx_GetAddr(amx, params[1], &Buff);
	*Buff = amx_ftoc(normalizedX);

	amx_GetAddr(amx, params[2], &Buff);
	*Buff = amx_ftoc(normalizedY);

	return true;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	static char message[] = "- PAE Plugin loaded.";
	logprintf(message);
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	static char message[] = "- PAE Plugin unloaded.";
	logprintf(message);
}

AMX_NATIVE_INFO PluginNatives[] =
{
	{"GetKeyPressed", GetKeyPressed},
	{"GetKeyReleased", GetKeyReleased},
	{"GetMousePos", GetMousePos}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
	return amx_Register(amx, PluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
	return AMX_ERR_NONE;
}
