#if defined _attach_manage_inc
	#endinput
#endif
#define _attach_manage_inc

static gAttachManageListItem[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS];

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_MANAGE)
	{
		Dialog_Show(playerid, "dAttachMenuManage");
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

DialogCreate:dAttachMenuManage(playerid)
{
	new name_bone[CORE_MAX_LENGHT_NAME_BONE + 1];
	new note[CORE_MAX_LENGHT_NAME_NOTE + 1];
	new str_obj[12];
	new string
	[
		67
		+ (35 + (- 2 + sizeof(name_bone))
		+ (- 2 + 8) * 3
		+ (- 2 + sizeof(note))
		+ (- 2 + 11)
		+ (- 2 + sizeof(str_obj))
		+ (- 2 + CORE_MAX_LENGHT_NAME_NOTE)) * MAX_PLAYER_ATTACHED_OBJECTS
	];
	new count;
	new modelid;
	new slotid;
	new boneid;
	new language = language_GetLanguage(playerid);

	language_GetDialogString(
		playerid,
		DG_NUM_NAME_OBJECT_COMMENT,
		string
	);
	foreach (AttachObjectSlots[playerid], i)
	{
		modelid = attachmain_GetObjectSlotId(playerid, i);

		if (modelid == CORE_INVALID_OBJECT_MODEL)
		{
			str_obj = "-";
		}
		else
		{
			format(str_obj, sizeof(str_obj),
				"%d",
				modelid
			);
		}
		slotid = attachmain_GetCurrentSlotId(playerid);
		boneid = attachmain_GetBoneSlotId(playerid, i) - 1;

		attachmain_GetBoneName(language, boneid, name_bone);
		attachmain_GetObjectSlotNote(playerid, i, note);

		format(string, sizeof(string),
			"%s"cMain"%d\t%s%s\t%s%s\t%s%s\n",
			string,
			count + 1,
			slotid == i ? ""cRed"" : ""cWhite"",
			name_bone,
			slotid == i ? ""cRed"" : ""cWhite"",
			str_obj,
			slotid == i ? ""cRed"" : ""cWhite"",
			note
		);
		gAttachManageListItem[playerid][count++] = i;
	}
	if (count == 0)
	{
		language_MessageInfo(playerid, MSG_LIST_ATTACHED_OBJECTS_EMPTY);
		return 0;
	}
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuManage,
		DIALOG_STYLE_TABLIST_HEADERS,
		!""cMain"PAEditor",
		string,
		"»",
		!"X"
	);
	return 1;
}

DialogResponse:dAttachMenuManage(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new boneid = gAttachManageListItem[playerid][listitem];

	attachmain_SetCurrentSlotId(playerid, boneid);
	return 1;
}