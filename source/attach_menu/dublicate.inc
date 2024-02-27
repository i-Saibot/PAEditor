#if defined _attach_dublicate_inc
	#endinput
#endif
#define _attach_dublicate_inc


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_DUBLICATE)
	{
		if (attachmain_GetCurrentSlotId(playerid) == ITER_NONE)
		{
			language_MessageError(playerid, MSG_NO_CREATED_PROCESS_FOUND);
			return 0;
		}
		if (attachmain_GetFreeSlotId(playerid) == ITER_NONE)
		{
			language_MessageError(playerid, MSG_DUBLICT_NOT_FOUND_FREE_SLOT);
			return 0;
		}
		Dialog_Show(playerid, "dAttachDublicateMenu");
		return 1;
	}
#if defined attachdub_OnGuiAttachMenu
	return attachdub_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachdub_OnGuiAttachMenu
#if defined attachdub_OnGuiAttachMenu
	forward attachdub_OnGuiAttachMenu(playerid, typeid);
#endif

DialogCreate:dAttachDublicateMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_CONFIRM_DUPLICATE_PROCESS,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachDublicateMenu,
		DIALOG_STYLE_MSGBOX,
		name_dialog_header,
		str_dialog,
		"»",
		"X"
	);
	return 1;
}


DialogResponse:dAttachDublicateMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	Dialog_Show(playerid, "dAttachMenuDublicateNote");
	return 1;
}

DialogCreate:dAttachMenuDublicateNote(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_COMMENT,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuDublicateNote,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		str_dialog,
		"»",
		""
	);
	return 1;
}

DialogResponse:dAttachMenuDublicateNote(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new lenght_note = strlen(inputtext);

	if (lenght_note > CORE_MAX_LENGHT_NAME_NOTE)
	{
		language_MessageError(
			playerid,
			MSG_MAX_COMMENT_LENGTH_IS_CHARS
		);
		Dialog_Show(playerid, "dAttachMenuDublicateNote");
		return 0;
	}
	new
		slotid = attachmain_GetCurrentSlotId(playerid),
		new_slotid = attachmain_GetFreeSlotId(playerid);

	attachmain_SetObjectSlotNote(playerid, new_slotid, !lenght_note ? CORE_EMPTY_NOTE : inputtext);

	new
		boneid,
		modelid,
		Float:offset_x,
		Float:offset_y,
		Float:offset_z,
		Float:rot_x,
		Float:rot_y,
		Float:rot_z,
		Float:scale_x,
		Float:scale_y,
		Float:scale_z,
		materialcolor1,
		materialcolor2;

	attachmain_GetMainAttachData(
		playerid,
		slotid,
		modelid,
		boneid,
		offset_x,
		offset_y,
		offset_z,
		rot_x,
		rot_y,
		rot_z,
		scale_x,
		scale_y,
		scale_z,
		materialcolor1,
		materialcolor2
	);
	attachmain_SetMainAttachData(
		playerid,
		new_slotid,
		modelid,
		boneid,
		offset_x,
		offset_y,
		offset_z,
		rot_x,
		rot_y,
		rot_z,
		scale_x,
		scale_y,
		scale_z,
		materialcolor1,
		materialcolor2
	);
	attachmain_JsonSaveAttach(playerid, new_slotid);
	attachmain_SetCurrentSlotId(playerid, new_slotid);
	attachmain_AddIterSlotId(playerid, new_slotid);
	attachmain_SetMainAttachObject(playerid, new_slotid);

	SendClientMessage(playerid, COLOR_WHITE, "");

	language_MessageInfo(playerid, MSG_OBJECT_DUPLICATED_SUCCESS);
	return 1;
}