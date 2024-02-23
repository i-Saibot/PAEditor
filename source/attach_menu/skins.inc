#if defined _attach_skin_inc
	#endinput
#endif
#define _attach_skin_inc


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_SKIN)
	{
		Dialog_Show(playerid, "dAttachSkinMenu");
		return 1;
	}
#if defined attachskin_OnGuiAttachMenu
	return attachskin_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachskin_OnGuiAttachMenu
#if defined attachskin_OnGuiAttachMenu
	forward attachskin_OnGuiAttachMenu(playerid, typeid);
#endif


DialogCreate:dAttachSkinMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_SKIN_ID_TO_SET,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachSkinMenu,
		DIALOG_STYLE_INPUT,
		!""cMain"PAEditor",
		str_dialog,
		"»",
		!"X"
	);
	return 1;
}


DialogResponse:dAttachSkinMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		gui_atatch_menu_ShowCursor(playerid);
		return 0;
	}
	new skinid = strval(inputtext);

	if (skinid < 1 || skinid > 311)
	{
		Dialog_Show(playerid, "dAttachSkinMenu");

		language_MessageError(playerid, MSG_SPECIFY_SKIN_ID_IN_RANGE);
		return 0;
	}
	SetPlayerSkin(playerid, skinid);
	
	language_MessageInfo(playerid, MSG_SKIN_SET_SUCCESS);
	
	gui_atatch_menu_ShowCursor(playerid);
	attachmain_JsonSaveSkin(playerid);
	return 1;
}