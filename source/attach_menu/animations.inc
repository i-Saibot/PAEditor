#if defined _attach_animations_inc
	#endinput
#endif
#define _attach_animations_inc

const
	ATTACH_ANIM_MAX_ROW_IN_PAGE 					= 20,
	ATTACH_ANIM_MAX_LENGHT_NAME						= 64,
	ATTACH_ANIM_INVALID_ANIM_ID						= -1;


static
	gAttachAnimationsPage[MAX_PLAYERS],
	gAttachAnimationsLibraryIndex[MAX_PLAYERS][ATTACH_ANIM_MAX_ROW_IN_PAGE],
	gAttachAnimationsArrayIndex[MAX_PLAYERS][ATTACH_ANIM_MAX_ROW_IN_PAGE],
	gAttachAnimationsUseIndex[MAX_PLAYERS] = {ATTACH_ANIM_INVALID_ANIM_ID, ...};


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_ANIMATIONS)
	{
		if (gui_ath_uniqedit_IsShowTD(playerid))
		{
			return 0;
		}
		gAttachAnimationsPage[playerid] = 0;
		Dialog_Show(playerid, "dAttachAnimationsList");
		return 1;
	}
	else if (typeid == GUI_ATTACH_MENU_ANIMATION_CLEAR)
	{
		ClearAnimations(playerid);
		attachanim_SetAnimIndex(playerid, ATTACH_ANIM_INVALID_ANIM_ID);
		project_JsonSaveAnimation(playerid, ATTACH_ANIM_INVALID_ANIM_ID);
		return 1;
	}
#if defined attachanim_OnGuiAttachMenu
	return attachanim_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachanim_OnGuiAttachMenu
#if defined attachanim_OnGuiAttachMenu
	forward attachanim_OnGuiAttachMenu(playerid, typeid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	attachanim_SetAnimIndex(playerid, ATTACH_ANIM_INVALID_ANIM_ID);
#if defined attachanim_OnPlayerDisconnect
	return attachanim_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect attachanim_OnPlayerDisconnect
#if defined    attachanim_OnPlayerDisconnect
	forward attachanim_OnPlayerDisconnect(playerid, reason);
#endif

DialogCreate:dAttachAnimationsList(playerid)
{
	new
		length,
		library_index,
		name[ATTACH_ANIM_MAX_LENGHT_NAME + 1],
		string[42 + 30 * 2 + (25 + (- 2 + sizeof(name))) * ATTACH_ANIM_MAX_ROW_IN_PAGE];
	new
		JsonNode:node,
		JsonNode:item,
		JsonCallResult:result = JSON_ParseFile(json_file_name_animations, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_GetArray(node, "animations", node);
		JSON_ArrayLength(node, length);

		new
			page = gAttachAnimationsPage[playerid],
			i = page * ATTACH_ANIM_MAX_ROW_IN_PAGE,
			j,
			index;

		for (; i < length; i++)
		{
			if (j++ == ATTACH_ANIM_MAX_ROW_IN_PAGE)
			{
				break;
			}
			JSON_ArrayObject(node, i, item);

			JSON_GetString(item, "name", name, sizeof(name));
			JSON_GetInt(item, "library_index", library_index);

			format(string, sizeof(string),
				"%s"cMain"» "cGrey"%s\n",
				string,
				name
			);
			gAttachAnimationsLibraryIndex[playerid][index] = library_index;
			gAttachAnimationsArrayIndex[playerid][index] = i;
			index++;
		}
		if (length > (page * ATTACH_ANIM_MAX_ROW_IN_PAGE) + ATTACH_ANIM_MAX_ROW_IN_PAGE)
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
		Dialog:dAttachAnimationsList,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		"DG_ADD_ANIMATION",
		"»",
		"X",
		string
	);
	return 1;
}

DialogResponse:dAttachAnimationsList(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		gui_atatch_menu_ShowCursor(playerid);
		gui_camera_rot_ShowInfo(playerid);
		return 0;
	}
	if (!strcmp(inputtext, "»»»", false))
	{
		gAttachAnimationsPage[playerid]++;
		Dialog_Show(playerid, "dAttachAnimationsList");
		return 0;
	}
	else if (!strcmp(inputtext, "«««", false))
	{
		gAttachAnimationsPage[playerid]--;
		Dialog_Show(playerid, "dAttachAnimationsList");
		return 0;
	}
	if (listitem == 0)
	{
		Dialog_Show(playerid, "dAttachAddAnimation");
		return 0;
	}
	if (listitem == 1)
	{
		Dialog_Show(playerid, "dAttachAnimationsList");
		return 0;
	}
	new
		index_library = gAttachAnimationsLibraryIndex[playerid][listitem - 2],
		index_array = gAttachAnimationsArrayIndex[playerid][listitem - 2];

	gAttachAnimationsLibraryIndex[playerid][0] = index_library;
	gAttachAnimationsArrayIndex[playerid][0] = index_array;

	Dialog_Open(
		playerid,
		Dialog:dAttachAnimationAction,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		"DG_APPLY_ANIM_REMOVE_FROM_LIST",
		"»",
		"«"
	);
	return 1;
}


DialogResponse:dAttachAnimationAction(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachAnimationsList");
		return 0;
	}
	if (listitem == 0)
	{
		new anim_index = gAttachAnimationsLibraryIndex[playerid][0];
		
		attachanim_ApplyAnimationIndex(playerid, anim_index);
		project_JsonSaveAnimation(playerid, anim_index);
		language_MessageInfo(playerid, "MSG_ANIM_APPLIED_TO_CHARACTER");
	}
	else
	{
		new
			JsonNode:node,
			JsonCallResult:result = JSON_ParseFile(json_file_name_animations, node),
			index = gAttachAnimationsArrayIndex[playerid][0];

		if (result == JSON_CALL_NO_ERR)
		{
			language_MessageInfo(playerid, "MSG_ANIM_REMOVED_SUCCESS");

			JSON_ArrayRemoveIndex(node, "animations", index);
			JSON_SaveFile(json_file_name_animations, node, 4);
		}
		JSON_Cleanup(node);
		gAttachAnimationsPage[playerid] = 0;
		Dialog_Show(playerid, "dAttachAnimationsList");
	}
	return 1;
}


DialogCreate:dAttachAddAnimation(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dAttachAddAnimation,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		"DG_ADD_ANIM_ENTER_TITLE_INDEX",
		"»",
		"«"
	);
	return 1;
}

DialogResponse:dAttachAddAnimation(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachAnimationsMenu");
		return 0;
	}
	new
		name[ATTACH_ANIM_MAX_LENGHT_NAME + 1],
		library_index;

	if (sscanf(inputtext, "P<,.>s[*]d", ATTACH_ANIM_MAX_LENGHT_NAME, name, library_index))
	{
		Dialog_Show(playerid, "dAttachAddAnimation");
		return 0;
	}
	new
		JsonNode:item,
		JsonNode:node,
		JsonCallResult:result = JSON_ParseFile(json_file_name_animations, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new existing_library_index;
		
		JSON_GetArray(node, "animations", node);
		JSON_ArrayLength(node, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(node, i, item);
			JSON_GetInt(item, "library_index", existing_library_index);

			if (existing_library_index == library_index)
			{
				language_MessageError(playerid, "MSG_ANIM_EXISTS_WITH_INDEX");

				Dialog_Show(playerid, "dAttachAddAnimation");
				JSON_Cleanup(node);
				JSON_Cleanup(item);
				return 0;
			}
		}
	}
	JSON_Cleanup(item);
	JSON_Cleanup(node);
	
	result = JSON_ParseFile(json_file_name_animations, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_ArrayAppend(node, "animations", JSON_Object(
			"name", JSON_String(name),
			"library_index", JSON_Int(library_index))
		);
		JSON_SaveFile(json_file_name_animations, node, 4);
	}
	JSON_Cleanup(node);
	
	gAttachAnimationsPage[playerid] = 0;
	Dialog_Show(playerid, "dAttachAnimationsList");
	return 1;
}

stock attachanim_ApplyAnimationIndex(playerid, index)
{
	if (index == ATTACH_ANIM_INVALID_ANIM_ID)
	{
		return 0;
	}
	new
		lib[24],
		name[24],
		anim_index = index;

	GetAnimationName(anim_index, lib, sizeof(lib), name, sizeof(name));

	ApplyAnimation(
		.playerid = playerid,
		.animlib = lib,
		.animname = name,
		.fDelta = 4.0,
		.loop = 1,
		.lockx = 0,
		.locky = 0,
		.freeze = 0,
		.time = 0,
		.forcesync = 0
	);
	attachanim_SetAnimIndex(playerid, index);
	return 1;
}

stock attachanim_SetAnimIndex(playerid, index)
{
	gAttachAnimationsUseIndex[playerid] = index;
	return 1;
}

stock attachanim_GetAnimIndex(playerid)
{
	return gAttachAnimationsUseIndex[playerid];
}