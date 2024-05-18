#if defined _attach_skin_inc
	#endinput
#endif
#define _attach_skin_inc

const
	ATTACH_SKIN_MIN_ID_SKIN								= 0,
	ATTACH_SKIN_MAX_ID_SKIN								= 311,
	ATTACH_SKIN_TIME_GAME_TEXT							= 1_600,

	Float:ATTACH_SKIN_CRD_PREV_BTN_MIN_X				= 0.8536,
	Float:ATTACH_SKIN_CRD_PREV_BTN_MAX_X				= 0.8932,
	Float:ATTACH_SKIN_CRD_PREV_BTN_MIN_Y				= 0.9270,
	Float:ATTACH_SKIN_CRD_PREV_BTN_MAX_Y				= 0.9944,

	Float:ATTACH_SKIN_CRD_NEXT_BTN_MIN_X				= 0.9416,
	Float:ATTACH_SKIN_CRD_NEXT_BTN_MAX_X				= 0.9817,
	Float:ATTACH_SKIN_CRD_NEXT_BTN_MIN_Y				= 0.9268,
	Float:ATTACH_SKIN_CRD_NEXT_BTN_MAX_Y				= 0.9916;


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
		if (attachmain_IsNoBannedClick(playerid))
		{
			new
				Float:x,
				Float:y;

			GetMousePos(x, y);

			if ((ATTACH_SKIN_CRD_PREV_BTN_MIN_X <= x <= ATTACH_SKIN_CRD_PREV_BTN_MAX_X)
				&& (ATTACH_SKIN_CRD_PREV_BTN_MIN_Y <= y <= ATTACH_SKIN_CRD_PREV_BTN_MAX_Y))
			{
				if (attach_unqedit_IsStartEdit(playerid) || attachedit_IsPlayerEditing(playerid))
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
				if (attach_unqedit_IsStartEdit(playerid) || attachedit_IsPlayerEditing(playerid))
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

CMD:skin(playerid, params[])
{
	if (!gui_atatch_menu_IsShow(playerid))
	{
		return 0;
	}
	new skinid;

	if (sscanf(params, "d", skinid))
	{
		return 0;
	}
	if (!(ATTACH_SKIN_MIN_ID_SKIN <= skinid <= ATTACH_SKIN_MAX_ID_SKIN))
	{
		language_MessageError(playerid, "MSG_SPECIFY_SKIN_ID_IN_RANGE");
		return 0;
	}
	SetPlayerSkin(playerid, skinid);
	project_JsonSaveSkin(playerid);

	new string[38 + (- 2 + 3) * 2] = "~y~Skin %d";

	format(string, sizeof(string),
		string,
		GetPlayerSkin(playerid)
	);
	GameTextForPlayer(playerid, string, ATTACH_SKIN_TIME_GAME_TEXT, 4);
	return 1;
}

DialogCreate:dAttachSkinMenu(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dAttachSkinMenu,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		"DG_ENTER_SKIN_ID_TO_SET",
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
	new skinid;

	if (sscanf(inputtext, "d", skinid))
	{
		Dialog_Show(playerid, "dAttachSkinMenu");
		return 0;
	}
	if (!(ATTACH_SKIN_MIN_ID_SKIN <= skinid <= ATTACH_SKIN_MAX_ID_SKIN))
	{
		Dialog_Show(playerid, "dAttachSkinMenu");
		language_MessageError(playerid, "MSG_SPECIFY_SKIN_ID_IN_RANGE");
		return 0;
	}
	SetPlayerSkin(playerid, skinid);
	
	language_MessageInfo(playerid, "MSG_SKIN_SET_SUCCESS");
	
	gui_atatch_menu_ShowCursor(playerid);
	gui_camera_rot_ShowInfo(playerid);
	project_JsonSaveSkin(playerid);

	new anim_index = attachanim_GetAnimIndex(playerid);

	if (anim_index != ATTACH_ANIM_INVALID_ANIM_ID)
	{
		attachanim_ApplyAnimationIndex(playerid, anim_index);
	}
	return 1;
}

static attachskin_SetPrevSkin(playerid, bool:is_export = false)
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

	new anim_index = attachanim_GetAnimIndex(playerid);

	if (anim_index != ATTACH_ANIM_INVALID_ANIM_ID)
	{
		attachanim_ApplyAnimationIndex(playerid, anim_index);
	}
	return 1;
}

static attachskin_SetNextSkin(playerid, bool:is_export = false)
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

	new anim_index = attachanim_GetAnimIndex(playerid);

	if (anim_index != ATTACH_ANIM_INVALID_ANIM_ID)
	{
		attachanim_ApplyAnimationIndex(playerid, anim_index);
	}
	return 1;
}