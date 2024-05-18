#if defined _attach_bone_inc
	#endinput
#endif
#define _attach_bone_inc

const
	Float:ATTACH_BONE_COORD_BTN_MIN_X				= 0.4822,
	Float:ATTACH_BONE_COORD_BTN_MAX_X				= 0.5223,

	Float:ATTACH_BONE_COORD_BTN_MIN_Y				= 0.9268,
	Float:ATTACH_BONE_COORD_BTN_MAX_Y				= 0.9916;


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_BONE)
	{
		if (gui_ath_uniqedit_IsShowTD(playerid))
		{
			return 0;
		}
		if (!attachmain_IsCreateProcess(playerid))
		{
			language_MessageError(playerid, "MSG_PROCESS_START_PRESS_NEW");
			return 0;
		}
		Dialog_Show(playerid, "dAttachMenuChangeBone");
		return 1;
	}
#if defined attachbone_OnGuiAttachMenu
	return attachbone_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachbone_OnGuiAttachMenu
#if defined attachbone_OnGuiAttachMenu
	forward attachbone_OnGuiAttachMenu(playerid, typeid);
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

			if ((ATTACH_BONE_COORD_BTN_MIN_X <= x <= ATTACH_BONE_COORD_BTN_MAX_X)
				&& (ATTACH_BONE_COORD_BTN_MIN_Y <= y <= ATTACH_BONE_COORD_BTN_MAX_Y))
			{
				if (!attachmain_IsCreateProcess(playerid))
				{
					language_MessageError(playerid, "MSG_PROCESS_START_PRESS_NEW");
					return 0;
				}
				Dialog_Show(playerid, "dAttachBoneSaveChangeNote");
				return 1;
			}
		}
	}
#if defined attachbone_OnVirtualKeyReleased
	return attachbone_OnVirtualKeyReleased(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased attachbone_OnVirtualKeyReleased
#if defined    attachbone_OnVirtualKeyReleased
	forward attachbone_OnVirtualKeyReleased(playerid, key_vk);
#endif

DialogCreate:dAttachMenuChangeBone(playerid)
{
	new
		string[24 + (19 + 10 + (- 2 + CORE_MAX_LENGHT_NAME_BONE)) * CORE_MAX_COUNT_BONE],
		index,
		slotid = attachmain_GetCurrentSlotId(playerid),
		current_bone = attachmain_GetBoneSlotId(playerid, slotid),
		Lang:lanid = Lang_GetPlayerLang(playerid);

	for (new i; i < CORE_MAX_COUNT_BONE; i++)
	{
		index = attachmain_GetBoneId(i);

		format(string, sizeof(string),
			"%s"cMain"» %s%s\n",
			string,
			current_bone == index ? ""cRed"" : ""cWhite"",
			gLangArrayBone[_:lanid][i]
		);
	}
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuChangeBone,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		string,
		"»",
		"X"
	);
	return 1;
}

DialogResponse:dAttachMenuChangeBone(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new
		boneid = attachmain_GetBoneId(listitem),
		slotid = attachmain_GetCurrentSlotId(playerid),
		modelid = attachmain_GetObjectSlotId(playerid, slotid);

	attachmain_SetBoneSlotId(playerid, slotid, boneid);
	project_JsonSaveAttach(playerid, slotid);

	SendClientMessage(playerid, COLOR_WHITE, "");

	if (modelid != CORE_INVALID_OBJECT_MODEL)
	{
		attachmain_ApplyMainAttach(playerid, slotid);
	}
	language_MessageInfo(playerid, "MSG_CHANGE_BONE");
	return 1;
}

DialogCreate:dAttachBoneSaveChangeNote(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dAttachBoneSaveChangeNote,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		"DG_ENTER_COMMENT",
		"»",
		"X"
	);
	return 1;
}

DialogResponse:dAttachBoneSaveChangeNote(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new lenght_note = strlen(inputtext);

	if (lenght_note > CORE_MAX_LENGHT_NAME_NOTE)
	{
		language_MessageError(playerid, "MSG_MAX_COMMENT_LENGTH_IS_CHARS");
		Dialog_Show(playerid, "dAttachBoneSaveChangeNote");
		return 0;
	}
	new slotid = attachmain_GetCurrentSlotId(playerid);
	
	attachmain_SetObjectSlotNote(
		playerid,
		slotid, !lenght_note ? CORE_EMPTY_NOTE : inputtext
	);
	project_JsonSaveAttach(playerid, slotid);
	return 1;
}