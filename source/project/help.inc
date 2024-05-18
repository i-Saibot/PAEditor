#if defined _project_help_inc
	#endinput
#endif
#define _project_help_inc


DialogCreate:dProjectMainHelp(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dProjectMainHelp,
		DIALOG_STYLE_MSGBOX,
		name_dialog_header,
		"DG_MAIN_MENU_HELP",
		"«",
		""
	);
	return 1;
}

DialogResponse:dProjectMainHelp(playerid, response, listitem, inputtext[])
{
	Dialog_Show(playerid, "dProjectMainMenu");
	return 1;
}