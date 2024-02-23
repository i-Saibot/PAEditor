#if defined _attach_new_inc
	#endinput
#endif
#define _attach_new_inc


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_NEW)
	{
		if (attachmain_GetFreeSlotId(playerid) == ITER_NONE)
		{
			language_MessageInfo(playerid, MSG_NO_AVAILABLE_ATTACH_SLOTS);
			return 0;
		}
		Dialog_Show(playerid, "dAttachMenuNew");
		return 1;
	}
#if defined attachnew_OnGuiAttachMenu
	return attachnew_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachnew_OnGuiAttachMenu
#if defined attachnew_OnGuiAttachMenu
	forward attachnew_OnGuiAttachMenu(playerid, typeid);
#endif


DialogCreate:dAttachMenuNew(playerid)
{
	new name_bone[CORE_MAX_LENGHT_NAME_BONE + 1];
	new string[24 + (19 + (- 2 + sizeof(name_bone))) * CORE_MAX_COUNT_BONE];
	new language = language_GetLanguage(playerid);

	for (new i; i < CORE_MAX_COUNT_BONE; i++)
	{
		attachmain_GetBoneName(language, i, name_bone);

		format(string, sizeof(string),
			"%s"cMain"» "cWhite"%s\n",
			string,
			name_bone
		);
	}
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuNew,
		DIALOG_STYLE_LIST,
		!""cMain"PAEditor",
		string,
		"»",
		!"X"
	);
	return 1;
}

DialogResponse:dAttachMenuNew(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new boneid = attachmain_GetBoneId(listitem);
	new slotid = attachmain_GetFreeSlotId(playerid);

	attachmain_SetSlotId(playerid, slotid, slotid);
	attachmain_SetCurrentSlotId(playerid, slotid);
	attachmain_SetBoneSlotId(playerid, slotid, boneid);

	attachmain_JsonSaveAttach(playerid, slotid);

	SendClientMessage(playerid, COLOR_WHITE, !"");

	language_MessageInfo(playerid, MSG_TO_SET_OBJECT_PRESS_OBJECTS);
	language_MessageInfo(playerid, MSG_TO_MNG_ATTAC_PRESS_MANAGE);
	return 1;
}