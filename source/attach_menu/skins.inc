#if defined _attach_skin_inc
	#endinput
#endif
#define _attach_skin_inc

const ATTACH_SKIN_MIN_ID_SKIN							= 0;
const ATTACH_SKIN_MAX_ID_SKIN							= 311;
const ATTACH_SKIN_TIME_GAME_TEXT						= 1_600;

const Float: ATTACH_SKIN_CRD_PREV_BTN_MIN_X				= 0.8536;
const Float: ATTACH_SKIN_CRD_PREV_BTN_MAX_X				= 0.8932;
const Float: ATTACH_SKIN_CRD_PREV_BTN_MIN_Y				= 0.9270;
const Float: ATTACH_SKIN_CRD_PREV_BTN_MAX_Y				= 0.9944;

const Float: ATTACH_SKIN_CRD_NEXT_BTN_MIN_X				= 0.9416;
const Float: ATTACH_SKIN_CRD_NEXT_BTN_MAX_X				= 0.9817;
const Float: ATTACH_SKIN_CRD_NEXT_BTN_MIN_Y				= 0.9268;
const Float: ATTACH_SKIN_CRD_NEXT_BTN_MAX_Y				= 0.9916;


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_SKIN)
	{
		Dialog_Show(playerid, "dAttachSkinMenu");
		return 1;
	}
	else if (typeid == GUI_ATTACH_MENU_PREV_SKIN || typeid == GUI_ATTACH_MENU_NEXT_SKIN)
	{
		if (typeid == GUI_ATTACH_MENU_PREV_SKIN)
		{
			attachskin_SetPrevSkin(playerid);
		}
		else
		{
			attachskin_SetNextSkin(playerid);
		}
		return 1;
	}
#if defined attachskin_OnGuiAttachMenu
	return attachskin_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachskin_OnGuiAttachMenu
#if defined attachskin_OnGuiAttachMenu
	forward attachskin_OnGuiAttachMenu(playerid, typeid);
#endif

public OnVirtualKeyReleased(playerid, key_vk)
{
	if (key_vk == VK_RBUTTON)
	{
		if (gui_atatch_menu_IsShow(playerid)
			&& !attachedit_IsPlayerEditing(playerid)
			&& !Dialog_IsOpen(playerid)
			&& !gui_atatch_menu_IsBannedPanel(playerid))
		{
			new Float:x;
			new Float:y;

			GetMousePos(x, y);

			if ((ATTACH_SKIN_CRD_PREV_BTN_MIN_X <= x <= ATTACH_SKIN_CRD_PREV_BTN_MAX_X)
				&& (ATTACH_SKIN_CRD_PREV_BTN_MIN_Y <= y <= ATTACH_SKIN_CRD_PREV_BTN_MAX_Y))
			{
				if (attacheditbtn_IsStartEdit(playerid) || attachedit_IsPlayerEditing(playerid))
				{
					return 0;
				}
				attachexport_Export(playerid, .is_show_dialog_info = false);
				attachskin_SetPrevSkin(playerid, .is_export = true);
				return 1;
			}
			else if ((ATTACH_SKIN_CRD_NEXT_BTN_MIN_X <= x <= ATTACH_SKIN_CRD_NEXT_BTN_MAX_X)
				&& (ATTACH_SKIN_CRD_NEXT_BTN_MIN_Y <= y <= ATTACH_SKIN_CRD_NEXT_BTN_MAX_Y))
			{
				if (attacheditbtn_IsStartEdit(playerid) || attachedit_IsPlayerEditing(playerid))
				{
					return 0;
				}
				attachexport_Export(playerid, .is_show_dialog_info = false);
				attachskin_SetNextSkin(playerid, .is_export = true);
				return 1;
			}
		}
	}
#if defined attachskin_OnVirtualKeyReleased
	return attachskin_OnVirtualKeyReleased(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased attachskin_OnVirtualKeyReleased
#if defined    attachskin_OnVirtualKeyReleased
	forward attachskin_OnVirtualKeyReleased(playerid, key_vk);
#endif


DialogCreate:dAttachSkinMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_SKIN_ID_TO_SET,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachSkinMenu,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		str_dialog,
		"»",
		"X"
	);
	return 1;
}

DialogResponse:dAttachSkinMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		gui_atatch_menu_ShowCursor(playerid);
		gui_camera_rot_ShowInfo(playerid);
		return 0;
	}
	new skinid = strval(inputtext);

	if (!(ATTACH_SKIN_MIN_ID_SKIN <= skinid <= ATTACH_SKIN_MAX_ID_SKIN))
	{
		Dialog_Show(playerid, "dAttachSkinMenu");

		language_MessageError(playerid, MSG_SPECIFY_SKIN_ID_IN_RANGE);
		return 0;
	}
	SetPlayerSkin(playerid, skinid);
	
	language_MessageInfo(playerid, MSG_SKIN_SET_SUCCESS);
	
	gui_atatch_menu_ShowCursor(playerid);
	gui_camera_rot_ShowInfo(playerid);
	project_JsonSaveSkin(playerid);
	return 1;
}

static attachskin_SetPrevSkin(playerid, bool: is_export = false)
{
	new skinid = GetPlayerSkin(playerid);

	if (--skinid < ATTACH_SKIN_MIN_ID_SKIN)
	{
		skinid = ATTACH_SKIN_MAX_ID_SKIN;
	}
	SetPlayerSkin(playerid, skinid);
	project_JsonSaveSkin(playerid);

	new string[38 + (- 2 + 3) * 2] = "~y~Skin %d";

	if (is_export)
	{
		string = "~y~Skin %d~n~~g~+ Export Prev Skin %d";
	}
	format(string, sizeof(string),
		string,
		GetPlayerSkin(playerid),
		GetPlayerSkin(playerid) + 1
	);
	GameTextForPlayer(playerid, string, ATTACH_SKIN_TIME_GAME_TEXT, 4);
	return 1;
}

static attachskin_SetNextSkin(playerid, bool: is_export = false)
{
	new skinid = GetPlayerSkin(playerid);

	if (++skinid >= ATTACH_SKIN_MAX_ID_SKIN)
	{
		skinid = ATTACH_SKIN_MIN_ID_SKIN;
	}
	SetPlayerSkin(playerid, skinid);
	project_JsonSaveSkin(playerid);

	new string[38 + (- 2 + 3) * 2] = "~y~Skin %d";

	if (is_export)
	{
		string = "~y~Skin %d~n~~g~+ Export Prev Skin %d";
	}
	format(string, sizeof(string),
		string,
		GetPlayerSkin(playerid),
		GetPlayerSkin(playerid) - 1
	);
	GameTextForPlayer(playerid, string, ATTACH_SKIN_TIME_GAME_TEXT, 4);
	return 1;
}