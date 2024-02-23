#if defined _project_help_inc
	#endinput
#endif
#define _project_help_inc


DialogCreate:dProjectMainHelp(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DC_MAIN_MENU_HELP,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dProjectMainHelp,
		DIALOG_STYLE_MSGBOX,
		!""cMain"PAEditor",
		str_dialog,
		!"«",
		!""
	);
	return 1;
}

DialogResponse:dProjectMainHelp(playerid, response, listitem, inputtext[])
{
	Dialog_Show(playerid, "dProjectMainMenu");
	return 1;
}