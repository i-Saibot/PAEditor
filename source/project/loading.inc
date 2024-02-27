#if defined _attach_load_project_inc
	#endinput
#endif
#define _attach_load_project_inc


const ATTACH_LOAD_MAX_ROW_IN_PAGE					= 25;

static gAttachLoadPage[MAX_PLAYERS];
static gAttachLoadArrayIndex[MAX_PLAYERS][ATTACH_LOAD_MAX_ROW_IN_PAGE];


DialogCreate:dAttachMainLoadProject(playerid)
{
	if (project_IsHasActiveProject(playerid))
	{
		language_MessageError(playerid, MSG_CLOSE_CURRENT_PROJECT_FIRST);
		Dialog_Show(playerid, "dProjectMainMenu");
		return 0;
	}
	new name[CORE_MAX_LENGHT_NAME_PROJECT + 1];
	new string[47 + 30 * 2 + (48 + (- 2 + sizeof(name))) * ATTACH_LOAD_MAX_ROW_IN_PAGE];

	new JsonNode:node;
	new JsonNode:item;
	new JsonCallResult:result = JSON_ParseFile(json_file_name_list, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;

		JSON_GetArray(node, "list", node);
		JSON_ArrayLength(node, length);

		if (length == 0)
		{
			language_MessageError(playerid, MSG_PROJECTS_LIST_EMPTY);
			Dialog_Show(playerid, "dProjectMainMenu");
			return 0;
		}
		new page = gAttachLoadPage[playerid];
		new i = page * ATTACH_LOAD_MAX_ROW_IN_PAGE;
		new j;
		new index;

		for (; i < length; i++)
		{
			if (j++ == ATTACH_LOAD_MAX_ROW_IN_PAGE)
			{
				break;
			}
			JSON_ArrayObject(node, i, item);

			JSON_GetString(item, "name", name, sizeof(name));

			format(string, sizeof(string),
				"%s"cMain"» "cWhite"%s\n",
				string,
				name
			);
			gAttachLoadArrayIndex[playerid][index] = i;
			index++;
		}
		if (length > (page * ATTACH_LOAD_MAX_ROW_IN_PAGE) + ATTACH_LOAD_MAX_ROW_IN_PAGE)
		{
			strcat(string, ""cMain"»»»\n");

			if (page > 0)
			{
				strcat(string, ""cMain"«««");
			}
		}
		else if (page > 0)
		{
			strcat(string, ""cMain"«««");
		}
	}
	JSON_Cleanup(item);
	JSON_Cleanup(node);

	Dialog_Open(
		playerid,
		Dialog:dAttachMainLoadProject,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		string,
		"»",
		"«"
	);
	return 1;
}

DialogResponse:dAttachMainLoadProject(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dProjectMainMenu");
		return 0;
	}
	if (!strcmp(inputtext, "»»»", false))
	{
		gAttachLoadPage[playerid]++;
		Dialog_Show(playerid, "dAttachMainLoadProject");
		return 0;
	}
	else if (!strcmp(inputtext, "«««", false))
	{
		gAttachLoadPage[playerid]--;
		Dialog_Show(playerid, "dAttachMainLoadProject");
		return 0;
	}
	new index_array = gAttachLoadArrayIndex[playerid][listitem];

	gAttachLoadArrayIndex[playerid][0] = index_array;

	Dialog_Show(playerid, "dAttachMainLoadProjectAct");
	return 1;
}


DialogCreate:dAttachMainLoadProjectAct(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_LOAD_PRJCT_REMOVE_FROM_LIST,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachMainLoadProjectAct,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		str_dialog,
		"»",
		"«"
	);
	return 1;
}

DialogResponse:dAttachMainLoadProjectAct(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachMainLoadProject");
		return 0;
	}
	new index = gAttachLoadArrayIndex[playerid][0];

	if (listitem == 0)
	{
		new JsonNode:node;
		new JsonNode:item;
		new JsonNode:obj;
		new JsonCallResult:result = JSON_ParseFile(json_file_name_list, node);

		new name[CORE_MAX_LENGHT_NAME_PROJECT + 1];

		if (result == JSON_CALL_NO_ERR)
		{
			JSON_GetObject(node, "list", obj);
			JSON_ArrayObject(obj, index, item);
			JSON_GetString(item, "name", name, sizeof(name));
		}
		JSON_Cleanup(item);
		JSON_Cleanup(obj);
		JSON_Cleanup(node);

		new str_name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

		strcat(str_name_project, json_file_name_import);
		strcat(str_name_project, name);
		strcat(str_name_project, ".json");

		result = JSON_ParseFile(str_name_project, node);

		if (result == JSON_CALL_NO_SUCH_FILE_ERR)
		{
			language_MessageError(playerid, MSG_PRJCT_FILE_NO_FOUND_WH_NAME);

			Dialog_Show(playerid, "dAttachMainLoadProjectAct");
		}
		else
		{
			new length;
			new slotid;
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
			new note[CORE_MAX_LENGHT_NAME_NOTE + 1];

			new skinid;
			new anim_index;

			JSON_GetInt(node, "skinid", skinid);
			JSON_GetInt(node, "animation", anim_index);

			SetPlayerSkin(playerid, skinid);
			attachanim_ApplyAnimationIndex(playerid, anim_index);

			JSON_GetObject(node, "attach", obj);
			JSON_ArrayLength(obj, length);

			for (new i; i < length; i++)
			{
				JSON_ArrayObject(obj, i, item);

				JSON_GetInt(item, "slotid", slotid);
				JSON_GetInt(item, "boneid", boneid);
				JSON_GetInt(item, "objectid", modelid);
				
				JSON_GetFloat(item, "fOffsetX", fOffsetX);
				JSON_GetFloat(item, "fOffsetY", fOffsetY);
				JSON_GetFloat(item, "fOffsetZ", fOffsetZ);

				JSON_GetFloat(item, "fRotX", fRotX);
				JSON_GetFloat(item, "fRotY", fRotY);
				JSON_GetFloat(item, "fRotZ", fRotZ);

				JSON_GetFloat(item, "fScaleX", fScaleX);
				JSON_GetFloat(item, "fScaleY", fScaleY);
				JSON_GetFloat(item, "fScaleZ", fScaleZ);

				JSON_GetInt(item, "materialcolor1", materialcolor1);
				JSON_GetInt(item, "materialcolor2", materialcolor2);

				JSON_GetString(item, "note", note, sizeof(note));

				attachmain_SetMainAttachData(
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
				attachmain_SetObjectSlotNote(playerid, slotid, note);

				attachmain_AddIterSlotId(playerid, slotid);
				attachmain_SetCurrentSlotId(playerid, slotid);
				attachmain_SetMainAttachObject(playerid, slotid);
			}
			language_MessageInfo(playerid, MSG_PROJECT_LOADED_SUCCESS);
		}
		JSON_Cleanup(item);
		JSON_Cleanup(obj);
		JSON_Cleanup(node);

		project_SetJsonName(playerid, name);
		project_SetFileName(playerid, name);

		gui_atatch_menu_ShowMenu(playerid);
		gui_camera_rot_ShowInfo(playerid);
		gui_atatch_menu_ShowCursor(playerid);

		project_SetStatusActiveProject(playerid, true);
	}
	else
	{
		new JsonNode:node;
		new JsonCallResult: result = JSON_ParseFile(json_file_name_list, node);

		if (result == JSON_CALL_NO_ERR)
		{
			language_MessageInfo(playerid, MSG_PRJCT_RMOVD_FRM_LT_SUCCESS);
			
			JSON_ArrayRemoveIndex(node, "list", index);
			JSON_SaveFile(json_file_name_list, node, 4);
		}
		JSON_Cleanup(node);

		gAttachLoadPage[playerid] = 0;
		Dialog_Show(playerid, "dAttachMainLoadProject");
	}
	return 0;
}

