#if defined _attach_move_camera_inc
	#endinput
#endif
#define _attach_move_camera_inc

const Float: ATTACH_MCAMERA_DEFAULT_ZOOM				= 2.9;
const Float: ATTACH_MCAMERA_DEFAULT_HIGHT				= 0.3;

static bool: gAttachCameraMoveBanned[MAX_PLAYERS];
static Float: gAttachCameraAngle[MAX_PLAYERS];
static Float: gAttachCameraZoom[MAX_PLAYERS] = {ATTACH_MCAMERA_DEFAULT_ZOOM, ...};
static Float: gAttachCameraVertical[MAX_PLAYERS] = {ATTACH_MCAMERA_DEFAULT_HIGHT, ...};


public OnPlayerDisconnect(playerid, reason)
{
	gAttachCameraAngle[playerid] = 0.0;
	gAttachCameraZoom[playerid] = ATTACH_MCAMERA_DEFAULT_ZOOM;
	gAttachCameraVertical[playerid] = ATTACH_MCAMERA_DEFAULT_HIGHT;
#if defined attachcmove_OnPlayerDisconnect
	return attachcmove_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect attachcmove_OnPlayerDisconnect
#if defined    attachcmove_OnPlayerDisconnect
	forward attachcmove_OnPlayerDisconnect(playerid, reason);
#endif


public OnVirtualKeyPressed(playerid, key_vk)
{
	if (gui_atatch_menu_IsShow(playerid)
		&& gui_atatch_menu_IsActivePanel(playerid)
		&& !Dialog_IsOpen(playerid)
		&& !attachcameramove_IsBannedMove(playerid))
	{
		const
			Float: CAMERA_STEP 		= 0.06,
			Float: MIN_HIGHT		= -0.6,
			Float: MAX_HIGHT		= 1.5,
			Float: MIN_ZOOM			= 0.7,
			Float: MAX_ZOOM			= 5.5;

		new
			Float: x,
			Float: y,
			Float: z,
			Float: angle,
			bool: is_move_camera;

		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, angle);

		if ((key_vk == VK_UP && gAttachCameraVertical[playerid] < MAX_HIGHT) ||
			(key_vk == VK_DOWN && gAttachCameraVertical[playerid] > MIN_HIGHT) ||
			(key_vk == VK_LEFT) ||
			(key_vk == VK_RIGHT) ||
			(key_vk == VK_LSHIFT && gAttachCameraZoom[playerid] > MIN_ZOOM) ||
			(key_vk == VK_LMENU && gAttachCameraZoom[playerid] < MAX_ZOOM))
		{
			is_move_camera = true;

			if (key_vk == VK_UP) gAttachCameraVertical[playerid] += CAMERA_STEP;
			else if (key_vk == VK_DOWN) gAttachCameraVertical[playerid] -= CAMERA_STEP;
			else if (key_vk == VK_LEFT) gAttachCameraAngle[playerid] -= CAMERA_STEP;
			else if (key_vk == VK_RIGHT) gAttachCameraAngle[playerid] += CAMERA_STEP;
			else if (key_vk == VK_LSHIFT) gAttachCameraZoom[playerid] -= CAMERA_STEP;
			else if (key_vk == VK_LMENU) gAttachCameraZoom[playerid] += CAMERA_STEP;
		}
		if (is_move_camera)
		{
			angle += gAttachCameraAngle[playerid];

			SetPlayerCameraPos(
				playerid,
				x + gAttachCameraZoom[playerid] * floatcos(angle),
				y + gAttachCameraZoom[playerid] * floatsin(angle),
				z + gAttachCameraVertical[playerid]
			);
			SetPlayerCameraLookAt(playerid, x, y, z + gAttachCameraVertical[playerid]);
		}
	}
#if defined attachcmove_OnVirtualKeyPressed
	return attachcmove_OnVirtualKeyPressed(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyPressed
	#undef OnVirtualKeyPressed
#else
	#define _ALS_OnVirtualKeyPressed
#endif
#define OnVirtualKeyPressed attachcmove_OnVirtualKeyPressed
#if defined    attachcmove_OnVirtualKeyPressed
	forward attachcmove_OnVirtualKeyPressed(playerid, key_vk);
#endif

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_CAMERA_MOVE)
	{
		gAttachCameraMoveBanned[playerid] = !gAttachCameraMoveBanned[playerid];

		GameTextForPlayer(
			playerid,
			gAttachCameraMoveBanned[playerid] ? "~r~Camera Move OFF" : "~g~Camera Move ON",
			850,
			4
		);
		return 1;
	}
#if defined attachcmove_OnGuiAttachMenu
	return attachcmove_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachcmove_OnGuiAttachMenu
#if defined attachcmove_OnGuiAttachMenu
	forward attachcmove_OnGuiAttachMenu(playerid, typeid);
#endif


stock attachcameramove_IsBannedMove(playerid)
{
	return gAttachCameraMoveBanned[playerid];
}