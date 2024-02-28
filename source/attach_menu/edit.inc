#if defined _attach_edit_inc
	#endinput
#endif
#define _attach_edit_inc

static bool: gAttachEditPlayerEditing[MAX_PLAYERS];


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_EDIT)
	{
		if (!attachmain_IsUseMultiObject(playerid))
		{
			if (!attachmain_IsCreateProcess(playerid))
			{
				language_MessageError(playerid, MSG_PROCESS_START_PRESS_NEW);
				return 0;
			}
			if (!attachmain_IsValidObject(playerid))
			{
				language_MessageError(playerid, MSG_START_SELECT_OBJ_PRESS_OBJ);
				return 0;
			}
			CancelSelectTextDraw(playerid);

			new slotid = attachmain_GetCurrentSlotId(playerid);

			attachmain_SetMainAttachObject(playerid, slotid);
			EditAttachedObject(playerid, slotid);

			SendClientMessage(playerid, COLOR_WHITE, "");

			language_MessageInfo(playerid, MSG_FREE_LOOK_HOLD_SPRINT_KEY);
			language_MessageInfo(playerid, MSG_SAVE_PRESS_ICON_CNL_USE_ESC);

			gAttachEditPlayerEditing[playerid] = true;
			return 1;
		}
	}
#if defined attachedit_OnGuiAttachMenu
	return attachedit_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachedit_OnGuiAttachMenu
#if defined attachedit_OnGuiAttachMenu
	forward attachedit_OnGuiAttachMenu(playerid, typeid);
#endif


public OnPlayerEditAttachedObject(
	playerid,
	response,
	index,
	modelid,
	boneid,
	Float:fOffsetX,
	Float:fOffsetY,
	Float:fOffsetZ,
	Float:fRotX,
	Float:fRotY,
	Float:fRotZ,
	Float:fScaleX,
	Float:fScaleY,
	Float:fScaleZ)
{
	SendClientMessage(playerid, COLOR_WHITE, "");

	new slotid = attachmain_GetCurrentSlotId(playerid);

	if (!response)
	{
		language_MessageInfo(playerid, MSG_NOT_SAVED_EDITING_CANCELLED);
		attachmain_SetMainAttachObject(playerid, slotid);
	}
	else
	{
		attachmain_SetAttachCoord(
			playerid,
			slotid,
			fOffsetX,
			fOffsetY,
			fOffsetZ,
			fRotX,
			fRotY,
			fRotZ,
			fScaleX,
			fScaleY,
			fScaleZ
		);
		language_MessageInfo(playerid, MSG_CHANGES_SAVED_AFTER_EDIT);
		project_JsonSaveAttach(playerid, slotid);
	}
	gui_atatch_menu_ShowCursor(playerid);
	gui_camera_rot_ShowInfo(playerid);
	gAttachEditPlayerEditing[playerid] = false;
#if defined attachedit_OnEditAttachedObject
	return attachedit_OnEditAttachedObject(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerEditAttachedObject
	#undef OnPlayerEditAttachedObject
#else
	#define _ALS_OnPlayerEditAttachedObject
#endif
#define OnPlayerEditAttachedObject attachedit_OnEditAttachedObject
#if defined attachedit_OnEditAttachedObject
	forward attachedit_OnEditAttachedObject(playerid, typeid);
#endif

stock attachedit_IsPlayerEditing(playerid)
{
	return gAttachEditPlayerEditing[playerid];
}