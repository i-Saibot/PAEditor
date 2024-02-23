#if defined _attach_dublicate_inc
	#endinput
#endif
#define _attach_dublicate_inc


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_DUBLICATE)
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);

		if (slotid == ITER_NONE)
		{
			language_MessageError(playerid, MSG_NO_CREATED_PROCESS_FOUND);
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
		!""cMain"PAEditor",
		str_dialog,
		"»",
		!"X"
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
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!""
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
		language_MessageInit(
			playerid,
			COLOR_RED,
			MSG_MAX_COMMENT_LENGTH_IS_CHARS,
			CORE_MAX_LENGHT_NAME_NOTE
		);
		Dialog_Show(playerid, "dAttachMenuObjectNote");
		return 0;
	}
	new slotid = attachmain_GetCurrentSlotId(playerid);
	new new_slotid = attachmain_GetFreeSlotId(playerid);

	attachmain_SetObjectSlotNote(playerid, new_slotid, !lenght_note ? CORE_EMPTY_NOTE : inputtext);

	new boneid;
	new modelid;
	new Float:fOffsetX;
	new Float:fOffsetY;
	new Float:fOffsetZ;
	new Float:fRotX;
	new Float:fRotY;
	new Float:fRotZ;
	new Float:fScaleX;
	new Float:fScaleY;
	new Float:fScaleZ;
	new materialcolor1;
	new materialcolor2;

	attachmain_GetAttachInfo(
		playerid,
		slotid,
		modelid,
		boneid,
		fOffsetX,
		fOffsetY,
		fOffsetZ,
		fRotX,
		fRotY,
		fRotZ,
		fScaleX,
		fScaleY,
		fScaleZ,
		materialcolor1,
		materialcolor2
	);
	attachmain_SetAttachInfo(
		playerid,
		new_slotid,
		modelid,
		boneid,
		fOffsetX,
		fOffsetY,
		fOffsetZ,
		fRotX,
		fRotY,
		fRotZ,
		fScaleX,
		fScaleY,
		fScaleZ,
		materialcolor1,
		materialcolor2
	);
	attachmain_JsonSaveAttach(playerid, new_slotid);
	attachmain_SetCurrentSlotId(playerid, new_slotid);
	attachmain_AddIterSlotId(playerid, new_slotid);
	attachedit_SetAttachObject(playerid);

	SendClientMessage(playerid, COLOR_WHITE, !"");

	language_MessageInfo(playerid, MSG_OBJECT_DUPLICATED_SUCCESS);
	return 1;
}