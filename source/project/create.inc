#if defined _attach_create_project_inc
	#endinput
#endif
#define _attach_create_project_inc


DialogCreate:dAttachMainCreateProject(playerid)
{
	if (project_IsHasActiveProject(playerid))
	{
		language_MessageError(playerid, MSG_CLOSE_CURRENT_PROJECT_FIRST);

		Dialog_Show(playerid, "dProjectMainMenu");
		return 0;
	}
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_PROJECT_NAME,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachMainCreateProject,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		str_dialog,
		"»",
		"«"
	);
	return 1;
}


DialogResponse:dAttachMainCreateProject(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dProjectMainMenu");
		return 0;
	}
	new lenght = strlen(inputtext);

	if (lenght == 0)
	{
		Dialog_Show(playerid, "dAttachMainCreateProject");
		return 0;
	}
	if (lenght > CORE_MAX_LENGHT_NAME_PROJECT)
	{
		language_MessageError(
			playerid,
			MSG_MAX_PROJECT_LENGTH_IS_CHARS
		);
		Dialog_Show(playerid, "dAttachMainCreateProject");
		return 0;
	}
	for (new i; i < lenght; i++)
	{
		switch (inputtext[i])
		{
			case 'A'..'Z', 'a'..'z', '0'..'9', '_':
			{
				continue;
			}
			default:
			{
				language_MessageError(playerid, MSG_ONLY_LATIN_LETTERS_DIGITS);
				Dialog_Show(playerid, "dAttachMainCreateProject");
				return 0;
			}
		}
	}
	new str_name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

	strcat(str_name_project, json_file_name_import);
	strcat(str_name_project, inputtext);
	strcat(str_name_project, ".json");

	new JsonNode:node;
	new JsonCallResult:result = JSON_ParseFile(str_name_project, node);

	if (result != JSON_CALL_NO_SUCH_FILE_ERR)
	{
		language_MessageError(playerid, MSG_PROJECT_WITH_NAME_EXISTS);

		Dialog_Show(playerid, "dAttachMainCreateProject");
		JSON_Cleanup(node);
		return 0;
	}
	new JsonNode:node_create = JSON_Object();

	JSON_SetInt(node_create, "skinid", GetPlayerSkin(playerid));
	JSON_SetInt(node_create, "animation", -1);
	JSON_SetObject(node_create, "attach", JSON_Array());

	JSON_SaveFile(str_name_project, node_create, 4);

	JSON_Cleanup(node_create);
	JSON_Cleanup(node);

	project_SetJsonName(playerid, inputtext);
	project_SetFileName(playerid, inputtext);

	SendClientMessage(playerid, COLOR_WHITE, "");

	language_MessageInfo(playerid, MSG_PRJCT_NAME_SUCCESS_CREATED);

	SendClientMessage(playerid, COLOR_WHITE, "");
	
	gui_atatch_menu_ShowMenu(playerid);
	gui_camera_rot_ShowInfo(playerid);
	gui_atatch_menu_ShowCursor(playerid);

	language_MessageInfo(playerid, MSG_FREE_LK_MODE_ACTIV_PRS_ESC);
	language_MessageInfo(playerid, MSG_CURSOR_ACTIVATION_PRESS_N);
	language_MessageInfo(playerid, MSG_PROCESS_SRT_SLCT_OPTION_NEW);

	result = JSON_ParseFile(json_file_name_list, node);

	if (result != JSON_CALL_NO_SUCH_FILE_ERR)
	{
		JSON_ArrayAppend(node, "list", JSON_Object(
			"name", JSON_String(inputtext))
		);
		JSON_SaveFile(json_file_name_list, node, 4);
	}
	JSON_Cleanup(node);

	project_SetStatusActiveProject(playerid, true);
	return 1;
}