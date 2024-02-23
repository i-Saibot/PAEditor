#if defined _attach_delete_inc
	#endinput
#endif
#define _attach_delete_inc


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_DELETE)
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);

		if (slotid == ITER_NONE)
		{
			language_MessageError(playerid, MSG_NO_CREATED_PROCESS_FOUND);
			return 0;
		}
		Dialog_Show(playerid, "dAttachDeleteMenu");
		return 1;
	}
#if defined attachdlt_OnGuiAttachMenu
	return attachdlt_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachdlt_OnGuiAttachMenu
#if defined attachdlt_OnGuiAttachMenu
	forward attachdlt_OnGuiAttachMenu(playerid, typeid);
#endif

DialogCreate:dAttachDeleteMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_CONFIRM_DELETE_PROCESS,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachDeleteMenu,
		DIALOG_STYLE_MSGBOX,
		!""cMain"PAEditor",
		str_dialog,
		"»",
		!"X"
	);
	return 1;
}

DialogResponse:dAttachDeleteMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new slotid = attachmain_GetCurrentSlotId(playerid);

	attachmain_ClearSlotId(playerid, slotid);
	attachmain_IterRemoveSlotId(playerid, slotid);
	attachmain_JsonDeleteAttach(playerid, slotid);
	
	new first_slotid = attachmain_GetFirstSlotId(playerid);

	attachmain_SetCurrentSlotId(playerid, first_slotid);
	return 1;
}