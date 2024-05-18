#if defined _attach_manage_inc
	#endinput
#endif
#define _attach_manage_inc


const
	Float:ATTACH_MANAGE_COORD_BTN_MIN_X				= 0.2192,
	Float:ATTACH_MANAGE_COORD_BTN_MAX_X				= 0.2593,

	Float:ATTACH_MANAGE_COORD_BTN_MIN_Y				= 0.926,
	Float:ATTACH_MANAGE_COORD_BTN_MAX_Y				= 0.997,

	ATTACH_MANAGE_UPDATE_TIMER						= 100;


static gAttachManageListItem[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS];


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_MANAGE)
	{
		if (gui_ath_uniqedit_IsShowTD(playerid))
		{
			return 0;
		}
		if (attachmain_IsUseMultiObject(playerid))
		{
			Dialog_Show(playerid, "dAttachMenuManageMultiObj");
		}
		else
		{
			Dialog_Show(playerid, "dAttachMenuManage");
		}
		return 1;
	}
#if defined attachmng_OnGuiAttachMenu
	return attachmng_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachmng_OnGuiAttachMenu
#if defined attachmng_OnGuiAttachMenu
	forward attachmng_OnGuiAttachMenu(playerid, typeid);
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

			if ((ATTACH_MANAGE_COORD_BTN_MIN_X <= x <= ATTACH_MANAGE_COORD_BTN_MAX_X)
				&& (ATTACH_MANAGE_COORD_BTN_MIN_Y <= y <= ATTACH_MANAGE_COORD_BTN_MAX_Y))
			{
				Dialog_Show(playerid, "dAttachMenuManageMultiObj");
				return 1;
			}
		}
	}
#if defined attachmng_OnVirtualKeyReleased
	return attachmng_OnVirtualKeyReleased(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased attachmng_OnVirtualKeyReleased
#if defined    attachmng_OnVirtualKeyReleased
	forward attachmng_OnVirtualKeyReleased(playerid, key_vk);
#endif

DialogCreate:dAttachMenuManage(playerid)
{
	new
		note[CORE_MAX_LENGHT_NAME_NOTE + 1],
		str_obj[12],
		string
		[
			67
			+ (35 + (- 2 + CORE_MAX_LENGHT_NAME_BONE)
			+ (- 2 + 8) * 3
			+ (- 2 + sizeof(note))
			+ (- 2 + 11)
			+ (- 2 + sizeof(str_obj))
			+ (- 2 + CORE_MAX_LENGHT_NAME_NOTE + 1)) * MAX_PLAYER_ATTACHED_OBJECTS
		];

	new
		count,
		modelid,
		slotid,
		boneid,
		Lang:lanid = Lang_GetPlayerLang(playerid);

	foreach (AttachObjectSlots[playerid], i)
	{
		str_obj = "-";
		modelid = attachmain_GetObjectSlotId(playerid, i);

		if (modelid != CORE_INVALID_OBJECT_MODEL)
		{
			format(str_obj, sizeof(str_obj), "%d", modelid);
		}
		slotid = attachmain_GetCurrentSlotId(playerid);
		boneid = attachmain_GetBoneSlotId(playerid, i) - 1;

		attachmain_GetObjectSlotNote(playerid, i, note);

		format(string, sizeof(string),
			"%s"cMain"%d\t%s%s\t%s%s\t%s%s\n",
			string,
			count + 1,
			slotid == i ? ""cRed"" : ""cWhite"",
			gLangArrayBone[_:lanid][boneid],
			slotid == i ? ""cRed"" : ""cWhite"",
			str_obj,
			slotid == i ? ""cRed"" : ""cWhite"",
			note
		);
		gAttachManageListItem[playerid][count++] = i;
	}
	if (count == 0)
	{
		language_MessageError(playerid, "MSG_LIST_ATTACHED_OBJECTS_EMPTY");
		return 0;
	}
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuManage,
		DIALOG_STYLE_TABLIST_HEADERS,
		name_dialog_header,
		"DG_MANAGE_LIST",
		"»",
		"X",
		string
	);
	return 1;
}

DialogResponse:dAttachMenuManage(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new slotid = gAttachManageListItem[playerid][listitem];

	attachmain_SetCurrentSlotId(playerid, slotid);
	return 1;
}

DialogCreate:dAttachMenuManageMultiObj(playerid)
{
	new
		note[CORE_MAX_LENGHT_NAME_NOTE + 1],
		str_obj[12],
		string
		[
			67
			+ 15
			+ (35 + (- 2 + CORE_MAX_LENGHT_NAME_BONE)
			+ (- 2 + 8) * 3
			+ (- 2 + sizeof(note))
			+ (- 2 + 11)
			+ (- 2 + sizeof(str_obj))
			+ (- 2 + CORE_MAX_LENGHT_NAME_NOTE + 1)) * MAX_PLAYER_ATTACHED_OBJECTS
		];
	new
		count,
		modelid,
		slotid,
		boneid,
		Lang:lanid = Lang_GetPlayerLang(playerid);

	foreach (AttachObjectSlots[playerid], i)
	{
		str_obj = "-";
		modelid = attachmain_GetObjectSlotId(playerid, i);

		if (modelid != CORE_INVALID_OBJECT_MODEL)
		{
			format(str_obj, sizeof(str_obj), "%d", modelid);
		}
		slotid = attachmain_GetMultiObjSlot(playerid, i);
		boneid = attachmain_GetBoneSlotId(playerid, i) - 1;

		attachmain_GetObjectSlotNote(playerid, i, note);

		format(string, sizeof(string),
			"%s"cMain"%d\t%s%s\t%s%s\t%s%s\n",
			string,
			count + 1,
			slotid == i ? ""cRed"" : ""cWhite"",
			gLangArrayBone[_:lanid][boneid],
			slotid == i ? ""cRed"" : ""cWhite"",
			str_obj,
			slotid == i ? ""cRed"" : ""cWhite"",
			note
		);
		gAttachManageListItem[playerid][count++] = i;
	}
	if (count == 0)
	{
		language_MessageError(playerid, "MSG_LIST_ATTACHED_OBJECTS_EMPTY");
		return 0;
	}
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuManageMultiObj,
		DIALOG_STYLE_TABLIST_HEADERS,
		name_dialog_header,
		"DG_MULTIOBJECT_LIST_MANAGE",
		"»",
		"X",
		string
	);
	return 1;
}

DialogResponse:dAttachMenuManageMultiObj(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	if (listitem == 0)
	{
		attachmain_ClearMultiObjSlots(playerid);
		Dialog_Show(playerid, "dAttachMenuManageMultiObj");
		return 0;
	}
	else if (listitem == 1)
	{
		Dialog_Show(playerid, "dAttachMenuManageMultiObj");
		return 0;
	}
	new
		slotid = gAttachManageListItem[playerid][listitem - 2],
		modelid = attachmain_GetObjectSlotId(playerid, slotid);

	if (modelid == CORE_INVALID_OBJECT_MODEL)
	{
		Dialog_Show(playerid, "dAttachMenuManageMultiObj");
		language_MessageError(playerid, "MSG_MULTIOBJ_INVALID_MODELID");
		return 0;
	}
	if (attachmain_IsUseMultiObjSlotId(playerid, slotid))
	{
		attachmain_RemoveMultiObjSlot(playerid, slotid);
		Dialog_Show(playerid, "dAttachMenuManageMultiObj");
		return 0;
	}
	attachmain_AddMultiObjSlot(playerid, slotid);
	Dialog_Show(playerid, "dAttachMenuManageMultiObj");
	return 1;
}
