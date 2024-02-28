#if defined _attach_bone_inc
	#endinput
#endif
#define _attach_bone_inc

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_BONE)
	{
		if (!attachmain_IsCreateProcess(playerid))
		{
			language_MessageError(playerid, MSG_PROCESS_START_PRESS_NEW);
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


DialogCreate:dAttachMenuChangeBone(playerid)
{
	new
		name_bone[CORE_MAX_LENGHT_NAME_BONE + 1],
		string[24 + (19 + 10 + (- 2 + sizeof(name_bone))) * CORE_MAX_COUNT_BONE],
		language = language_GetLanguage(playerid),
		index,
		slotid = attachmain_GetCurrentSlotId(playerid),
		current_bone = attachmain_GetBoneSlotId(playerid, slotid);

	for (new i; i < CORE_MAX_COUNT_BONE; i++)
	{
		index = attachmain_GetBoneId(i);
		attachmain_GetBoneName(language, i, name_bone);

		format(string, sizeof(string),
			"%s"cMain"» %s%s\n",
			string,
			current_bone == index ? ""cRed"" : ""cWhite"",
			name_bone
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
	new boneid = attachmain_GetBoneId(listitem);
	new slotid = attachmain_GetCurrentSlotId(playerid);
	new modelid = attachmain_GetObjectSlotId(playerid, slotid);

	attachmain_SetBoneSlotId(playerid, slotid, boneid);
	project_JsonSaveAttach(playerid, slotid);

	SendClientMessage(playerid, COLOR_WHITE, "");

	if (modelid != CORE_INVALID_OBJECT_MODEL)
	{
		attachmain_SetMainAttachObject(playerid, slotid);
	}
	language_MessageInfo(playerid, MSG_CHANGE_BONE);
	return 1;
}