#if defined _attach_delete_inc
	#endinput
#endif
#define _attach_delete_inc


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_DELETE)
	{
		if (attachmain_IsUseMultiObject(playerid) && !attacheditbtn_IsStartEdit(playerid))
		{
			Dialog_Show(playerid, "dAttachMultiDeleteMenu");
			return 0;
		}
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
		name_dialog_header,
		str_dialog,
		"»",
		"X"
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
	new per_slotid = Iter_Previous(AttachObjectSlots[playerid], slotid);
	new last_slotid = Iter_Last(AttachObjectSlots[playerid]);
	new new_slotid;

	attachmain_ClearSlotId(playerid, slotid);
	attachmain_IterRemoveSlotId(playerid, slotid);
	project_JsonDeleteAttach(playerid, slotid);

	if (per_slotid > last_slotid)
	{
		new_slotid = Iter_First(AttachObjectSlots[playerid]);
	}
	else
	{
		new_slotid = per_slotid;
	}
	if (Iter_Count(AttachObjectSlots[playerid]) == 0)
	{
		attachmain_SetCurrentSlotId(playerid, ITER_NONE);
	}
	else
	{
		attachmain_SetCurrentSlotId(playerid, new_slotid);
	}
	return 1;
}

DialogCreate:dAttachMultiDeleteMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_CONFIRM_MULT_DELETE_PROCESS,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachMultiDeleteMenu,
		DIALOG_STYLE_MSGBOX,
		name_dialog_header,
		str_dialog,
		"»",
		"X"
	);
	return 1;
}

DialogResponse:dAttachMultiDeleteMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new slotid = attachmain_GetCurrentSlotId(playerid);
	new bool: find_new_slot;

	foreach (AttachMultiObjectSlots[playerid], i)
	{
		if (slotid == i)
		{
			find_new_slot = true;
		}
		attachmain_ClearSlotId(playerid, i);
		attachmain_IterRemoveSlotId(playerid, i);
		project_JsonDeleteAttach(playerid, i);

		attachmain_SetMultiObjSlot(playerid, i, ITER_NONE);
		Iter_SafeRemove(AttachMultiObjectSlots[playerid], i, i);
	}
	if (find_new_slot == true)
	{
		new first_slotid = attachmain_GetFirstSlotId(playerid);
		attachmain_SetCurrentSlotId(playerid, first_slotid);
	}
	return 1;
}