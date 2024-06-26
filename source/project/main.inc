#if defined _project_main_inc
	#endinput
#endif
#define _project_main_inc

static
	bool:gProjectPlayerHasActiveProcess[MAX_PLAYERS],
	gProjectJsonName[MAX_PLAYERS][CORE_MAX_LENGHT_FOLDER_PROJECT],
	gProjectFileName[MAX_PLAYERS][CORE_MAX_LENGHT_FOLDER_PROJECT];

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

public OnVirtualKeyReleased(playerid, key_vk)
{
	if (!attachedit_IsPlayerEditing(playerid)
		&& gui_atatch_menu_IsShow(playerid)
		&& !Dialog_IsOpen(playerid))
	{
		if (key_vk == VK_MB5)
		{
			if (!gui_atatch_menu_IsActivePanel(playerid))
			{
				gui_atatch_menu_ShowCursor(playerid);
				gui_camera_rot_ShowInfo(playerid);
			}
			else
			{
				if (attachcameramove_IsUseMove(playerid))
				{
					SetCameraBehindPlayer(playerid);
				}
				CancelSelectTextDraw(playerid);
				
				gui_atatch_menu_HideCursor(playerid);
				gui_camera_rot_HideInfo(playerid);
			}
		}
	}
#if defined projectmain_OnVKeyReleased
	return projectmain_OnVKeyReleased(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased projectmain_OnVKeyReleased
#if defined projectmain_OnVKeyReleased
	forward projectmain_OnVKeyReleased(playerid, key_vk);
#endif

DialogCreate:dProjectMainMenu(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dProjectMainMenu,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		"DG_CREATE_LOAD_CLS_HELP_PROJECT",
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
				language_MessageError(playerid, "MSG_NO_ACTIVE_PROJECT_FOUND");
				Dialog_Show(playerid, "dProjectMainMenu");
				return 0;
			}
			gui_atatch_menu_HideMenu(playerid);
			gui_camera_rot_HideInfo(playerid);
			attachmain_ClearArray(playerid);
			project_SetStatusActiveProject(playerid, false);
			attachanim_SetAnimIndex(playerid, ATTACH_ANIM_INVALID_ANIM_ID);
			
			language_MessageInfo(playerid, "MSG_CURRENT_PRJCT_CLSD_SUCCESS");
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


stock project_JsonSaveSkin(playerid)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];
	project_GetJsonName(playerid, name_project);

	new
		JsonNode:node,
		JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_SetInt(node, "skinid", GetPlayerSkin(playerid));
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(node);
	return 1;
}

stock project_JsonSaveAnimation(playerid, index_anim)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

	project_GetJsonName(playerid, name_project);

	new
		JsonNode:node,
		JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_SetInt(node, "animation", index_anim);
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(node);
	return 1;
}

stock project_JsonSaveAttach(playerid, slotid)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

	project_GetJsonName(playerid, name_project);

	new
		JsonNode:node,
		JsonNode:item,
		JsonNode:obj,
		JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new note[CORE_MAX_LENGHT_NAME_NOTE + 1];

		new
			objectid,
			boneid,
			Float:offset_x,
			Float:offset_y,
			Float:offset_z,
			Float:rot_x,
			Float:rot_y,
			Float:rot_z,
			Float:scale_x,
			Float:scale_y,
			Float:scale_z,
			material_color_1,
			material_color_2;

		attachmain_GetObjectSlotNote(playerid, slotid, note);

		attachmain_GetMainAttachData(
			playerid,
			slotid,
			objectid,
			boneid,
			offset_x,
			offset_y,
			offset_z,
			rot_x,
			rot_y,
			rot_z,
			scale_x,
			scale_y,
			scale_z,
			material_color_1,
			material_color_2
		);
		new
			length,
			json_slotid;

		JSON_GetObject(node, "attach", obj);
		JSON_ArrayLength(obj, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(obj, i, item);

			JSON_GetInt(item, "slotid", json_slotid);

			if (json_slotid == slotid)
			{
				JSON_ArrayRemoveIndex(node, "attach", i);
				break;
			}
		}
		JSON_ArrayAppend(node, "attach", JSON_Object(
			"slotid", JSON_Int(slotid),
			"boneid", JSON_Int(boneid),
			"objectid", JSON_Int(objectid),
			"fOffsetX", JSON_Float(offset_x),
			"fOffsetY", JSON_Float(offset_y),
			"fOffsetZ", JSON_Float(offset_z),
			"fRotX", JSON_Float(rot_x),
			"fRotY", JSON_Float(rot_y),
			"fRotZ", JSON_Float(rot_z),
			"fScaleX", JSON_Float(scale_x),
			"fScaleY", JSON_Float(scale_y),
			"fScaleZ", JSON_Float(scale_z),
			"materialcolor1", JSON_Int(material_color_1),
			"materialcolor2", JSON_Int(material_color_2),
			"note", JSON_String(note))
		);
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(obj);
	JSON_Cleanup(item);
	JSON_Cleanup(node);
	return 1;
}


stock project_JsonDeleteAttach(playerid, slotid)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

	project_GetJsonName(playerid, name_project);
	
	new
		JsonNode:node,
		JsonNode:item,
		JsonNode:attachArray,
		JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new json_slotid;

		JSON_GetObject(node, "attach", attachArray);
		JSON_ArrayLength(attachArray, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(attachArray, i, item);

			JSON_GetInt(item, "slotid", json_slotid);

			if (json_slotid == slotid)
			{
				JSON_ArrayRemoveIndex(node, "attach", i);
				break;
			}
		}
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(attachArray);
	JSON_Cleanup(item);
	JSON_Cleanup(node);
	return 1;
}