#if defined _gui_camera_rotation_inc
	#endinput
#endif
#define _gui_camera_rotation_inc


static Text:gui_CameraRotationInfo[8];
static bool: gui_CameraRotationPlayerShow[MAX_PLAYERS];


public OnGameModeInit()
{
	gui_CameraRotationInfo[0] = TextDrawCreate(2.3335, 142.1, "LD_SPAC:white");
	TextDrawTextSize(gui_CameraRotationInfo[0], 83.0000, 12.0000);
	TextDrawAlignment(gui_CameraRotationInfo[0], 1);
	TextDrawColor(gui_CameraRotationInfo[0], 370480895);
	TextDrawBackgroundColor(gui_CameraRotationInfo[0], 255);
	TextDrawFont(gui_CameraRotationInfo[0], 4);
	TextDrawSetProportional(gui_CameraRotationInfo[0], 0);
	TextDrawSetShadow(gui_CameraRotationInfo[0], 0);

	gui_CameraRotationInfo[1] = TextDrawCreate(42.0002, 133.9998, "camera_rotation_in_panel");
	TextDrawLetterSize(gui_CameraRotationInfo[1], 0.1103, 0.7040);
	TextDrawAlignment(gui_CameraRotationInfo[1], 2);
	TextDrawColor(gui_CameraRotationInfo[1], -1);
	TextDrawSetOutline(gui_CameraRotationInfo[1], 1);
	TextDrawBackgroundColor(gui_CameraRotationInfo[1], 255);
	TextDrawFont(gui_CameraRotationInfo[1], 2);
	TextDrawSetProportional(gui_CameraRotationInfo[1], 1);
	TextDrawSetShadow(gui_CameraRotationInfo[1], 0);

	gui_CameraRotationInfo[2] = TextDrawCreate(9.0002, 143.9555, "UP");
	TextDrawLetterSize(gui_CameraRotationInfo[2], 0.1103, 0.7040);
	TextDrawAlignment(gui_CameraRotationInfo[2], 2);
	TextDrawColor(gui_CameraRotationInfo[2], COLOR_GREY);
	TextDrawBackgroundColor(gui_CameraRotationInfo[2], 255);
	TextDrawFont(gui_CameraRotationInfo[2], 2);
	TextDrawSetProportional(gui_CameraRotationInfo[2], 1);
	TextDrawSetShadow(gui_CameraRotationInfo[2], 0);

	gui_CameraRotationInfo[3] = TextDrawCreate(21.2002, 143.9555, "DOWN");
	TextDrawLetterSize(gui_CameraRotationInfo[3], 0.1103, 0.7040);
	TextDrawAlignment(gui_CameraRotationInfo[3], 2);
	TextDrawColor(gui_CameraRotationInfo[3], COLOR_GREY);
	TextDrawBackgroundColor(gui_CameraRotationInfo[3], 255);
	TextDrawFont(gui_CameraRotationInfo[3], 2);
	TextDrawSetProportional(gui_CameraRotationInfo[3], 1);
	TextDrawSetShadow(gui_CameraRotationInfo[3], 0);

	gui_CameraRotationInfo[4] = TextDrawCreate(35.8002, 143.9555, "LEFT");
	TextDrawLetterSize(gui_CameraRotationInfo[4], 0.1103, 0.7040);
	TextDrawAlignment(gui_CameraRotationInfo[4], 2);
	TextDrawColor(gui_CameraRotationInfo[4], COLOR_GREY);
	TextDrawBackgroundColor(gui_CameraRotationInfo[4], 255);
	TextDrawFont(gui_CameraRotationInfo[4], 2);
	TextDrawSetProportional(gui_CameraRotationInfo[4], 1);
	TextDrawSetShadow(gui_CameraRotationInfo[4], 0);

	gui_CameraRotationInfo[5] = TextDrawCreate(49.9999, 143.9555, "RIGHT");
	TextDrawLetterSize(gui_CameraRotationInfo[5], 0.1103, 0.7040);
	TextDrawAlignment(gui_CameraRotationInfo[5], 2);
	TextDrawColor(gui_CameraRotationInfo[5], COLOR_GREY);
	TextDrawBackgroundColor(gui_CameraRotationInfo[5], 255);
	TextDrawFont(gui_CameraRotationInfo[5], 2);
	TextDrawSetProportional(gui_CameraRotationInfo[5], 1);
	TextDrawSetShadow(gui_CameraRotationInfo[5], 0);

	gui_CameraRotationInfo[6] = TextDrawCreate(64.9996, 143.9555, "Shift");
	TextDrawLetterSize(gui_CameraRotationInfo[6], 0.1103, 0.7040);
	TextDrawAlignment(gui_CameraRotationInfo[6], 2);
	TextDrawColor(gui_CameraRotationInfo[6], COLOR_GREY);
	TextDrawBackgroundColor(gui_CameraRotationInfo[6], 255);
	TextDrawFont(gui_CameraRotationInfo[6], 2);
	TextDrawSetProportional(gui_CameraRotationInfo[6], 1);
	TextDrawSetShadow(gui_CameraRotationInfo[6], 0);

	gui_CameraRotationInfo[7] = TextDrawCreate(78.3994, 143.9555, "Alt");
	TextDrawLetterSize(gui_CameraRotationInfo[7], 0.1103, 0.7040);
	TextDrawAlignment(gui_CameraRotationInfo[7], 2);
	TextDrawColor(gui_CameraRotationInfo[7], COLOR_GREY);
	TextDrawBackgroundColor(gui_CameraRotationInfo[7], 255);
	TextDrawFont(gui_CameraRotationInfo[7], 2);
	TextDrawSetProportional(gui_CameraRotationInfo[7], 1);
	TextDrawSetShadow(gui_CameraRotationInfo[7], 0);
#if defined guicamerain_OnGameModeInit
	return guicamerain_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit guicamerain_OnGameModeInit
#if defined    guicamerain_OnGameModeInit
	forward guicamerain_OnGameModeInit();
#endif

public OnPlayerDisconnect(playerid, reason)
{
	gui_camera_rot_HideInfo(playerid);
#if defined guicamerain_OnPlayerDisconnect
	return guicamerain_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect guicamerain_OnPlayerDisconnect
#if defined    guicamerain_OnPlayerDisconnect
	forward guicamerain_OnPlayerDisconnect(playerid, reason);
#endif


public OnVirtualKeyPressed(playerid, key_vk)
{
	if (gui_camera_rot_IsShow(playerid)
		&& !attachcameramove_IsBannedMove(playerid))
	{
		if (key_vk == VK_UP
			|| key_vk == VK_DOWN
			|| key_vk == VK_LEFT
			|| key_vk == VK_RIGHT
			|| key_vk == VK_LSHIFT
			|| key_vk == VK_LMENU)
		{
			gui_camera_rot_SetClorPressBtn(playerid, COLOR_WHITE, key_vk);
		}
	}
#if defined guicamerain_OnVirtualKeyPressed
	return guicamerain_OnVirtualKeyPressed(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyPressed
	#undef OnVirtualKeyPressed
#else
	#define _ALS_OnVirtualKeyPressed
#endif
#define OnVirtualKeyPressed guicamerain_OnVirtualKeyPressed
#if defined    guicamerain_OnVirtualKeyPressed
	forward guicamerain_OnVirtualKeyPressed(playerid, key_vk);
#endif

public OnVirtualKeyReleased(playerid, key_vk)
{
	if (gui_camera_rot_IsShow(playerid))
	{
		if (key_vk == VK_UP
			|| key_vk == VK_DOWN
			|| key_vk == VK_LEFT
			|| key_vk == VK_RIGHT
			|| key_vk == VK_LSHIFT
			|| key_vk == VK_LMENU)
		{
			gui_camera_rot_SetClorPressBtn(playerid, COLOR_GREY, key_vk);
		}
	}
#if defined guicamerain_OnVirtualKeyRld
	return guicamerain_OnVirtualKeyRld(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased guicamerain_OnVirtualKeyRld
#if defined    guicamerain_OnVirtualKeyRld
	forward guicamerain_OnVirtualKeyRld(playerid, key_vk);
#endif


stock gui_camera_rot_ShowInfo(playerid)
{
	if (gui_camera_rot_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_CameraRotationInfo); i++)
	{
		TextDrawShowForPlayer(playerid, gui_CameraRotationInfo[i]);
	}
	gui_CameraRotationPlayerShow[playerid] = true;
	return 1;
}

stock gui_camera_rot_HideInfo(playerid)
{
	if (!gui_camera_rot_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_CameraRotationInfo); i++)
	{
		TextDrawHideForPlayer(playerid, gui_CameraRotationInfo[i]);
	}
	gui_CameraRotationPlayerShow[playerid] = false;
	return 1;
}

static gui_camera_rot_SetClorPressBtn(playerid, color, key_vk)
{
	if (!gui_camera_rot_IsShow(playerid))
	{
		return 0;
	}
	const
		TD_BUTTON_UP			= 2,
		TD_BUTTON_DOWN			= 3,
		TD_BUTTON_LEFT			= 4,
		TD_BUTTON_RIGHT			= 5,
		TD_BUTTON_LSHIFT		= 6,
		TD_BUTTON_LMENU			= 7;

	new index;

	switch (key_vk)
	{
		case VK_UP:			index = TD_BUTTON_UP;
		case VK_DOWN:		index = TD_BUTTON_DOWN;
		case VK_LEFT:		index = TD_BUTTON_LEFT;
		case VK_RIGHT:		index = TD_BUTTON_RIGHT;
		case VK_LSHIFT:		index = TD_BUTTON_LSHIFT;
		case VK_LMENU:		index = TD_BUTTON_LMENU;
	}
	TextDrawColor(
		gui_CameraRotationInfo[index],
		color
	);
	TextDrawShowForPlayer(
		playerid,
		gui_CameraRotationInfo[index]
	);
	return 1;
}

stock gui_camera_rot_IsShow(playerid)
{
	return gui_CameraRotationPlayerShow[playerid];
}
