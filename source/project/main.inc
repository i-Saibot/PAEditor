#if defined _project_main_inc
	#endinput
#endif
#define _project_main_inc

static bool: gProjectPlayerHasActiveProcess[MAX_PLAYERS];
static gProjectJsonName[MAX_PLAYERS][CORE_MAX_LENGHT_FOLDER_PROJECT];
static gProjectFileName[MAX_PLAYERS][CORE_MAX_LENGHT_FOLDER_PROJECT];

public OnPlayerDisconnect(playerid, reason)
{
	project_SetStatusActiveProject(playerid, false);
#if defined projectmain_OnPlayerDisconnect
	return projectmain_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect projectmain_OnPlayerDisconnect
#if defined    projectmain_OnPlayerDisconnect
	forward projectmain_OnPlayerDisconnect(playerid, reason);
#endif


public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (!attachedit_IsPlayerEditing(playerid))
	{
		if (newkeys & KEY_YES)
		{
			Dialog_Show(playerid, "dProjectMainMenu");
		}
		else if (newkeys & KEY_NO)
		{
			if (gui_atatch_menu_IsShow(playerid))
			{
				gui_atatch_menu_ShowCursor(playerid);
				gui_camera_rot_ShowInfo(playerid);
			}
		}
	}
#if defined projectmain_OnKeyStateChange
	return projectmain_OnKeyStateChange(playerid, newkeys, oldkeys);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange projectmain_OnKeyStateChange
#if defined projectmain_OnKeyStateChange
	forward projectmain_OnKeyStateChange(playerid, newkeys, oldkeys);
#endif

DialogCreate:dProjectMainMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_CREATE_LOAD_CLS_HELP_PROJECT,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dProjectMainMenu,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		str_dialog,
		"»",
		"X"
	);
	return 1;
}

DialogResponse:dProjectMainMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	switch (listitem)
	{
		case 0: Dialog_Show(playerid, "dAttachMainCreateProject");
		case 1: Dialog_Show(playerid, "dAttachMainLoadProject");
		case 2:
		{
			if (!project_IsHasActiveProject(playerid))
			{
				language_MessageError(playerid, MSG_NO_ACTIVE_PROJECT_FOUND);
				Dialog_Show(playerid, "dProjectMainMenu");
				return 0;
			}
			gui_atatch_menu_HideMenu(playerid);
			gui_camera_rot_HideInfo(playerid);
			attachmain_ClearArray(playerid);
			project_SetStatusActiveProject(playerid, false);

			language_MessageInfo(playerid, MSG_CURRENT_PRJCT_CLSD_SUCCESS);
			Dialog_Show(playerid, "dProjectMainMenu");
		}
		case 4:
		{
			Dialog_Show(playerid, "dProjectMainHelp");
		}
		default:
		{
			Dialog_Show(playerid, "dProjectMainMenu");
		}
	}
	return 1;
}


stock project_IsHasActiveProject(playerid)
{
	return gProjectPlayerHasActiveProcess[playerid];
}

stock project_SetStatusActiveProject(playerid, bool:value)
{
	gProjectPlayerHasActiveProcess[playerid] = value;
	return 1;
}

stock project_GetJsonName(playerid, name[], const size = sizeof(name))
{
	name[0] = EOS;
	strcat(name, gProjectJsonName[playerid], size);
	return 1;
}

stock project_SetJsonName(playerid, const name[])
{
	new string[CORE_MAX_LENGHT_FOLDER_PROJECT];

	strcat(string, json_file_name_import);
	strcat(string, name);
	strcat(string, ".json");

	gProjectJsonName[playerid][0] = EOS;
	strcat(gProjectJsonName[playerid], string);
	return 1;
}

stock project_GetFileName(playerid, name[], const size = sizeof(name))
{
	name[0] = EOS;
	strcat(name, gProjectFileName[playerid], size);
	return 1;
}

stock project_SetFileName(playerid, const name[])
{
	new string[CORE_MAX_LENGHT_FOLDER_PROJECT];

	strcat(string, json_file_name_export);
	strcat(string, name);
	strcat(string, ".txt");

	gProjectFileName[playerid][0] = EOS;
	strcat(gProjectFileName[playerid], string);
	return 1;
}