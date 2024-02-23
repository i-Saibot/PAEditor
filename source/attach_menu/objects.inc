#if defined _attach_objects_inc
	#endinput
#endif
#define _attach_objects_inc


static gAttachObjectsPage[MAX_PLAYERS];
static gAttachObjectsSelectModel[MAX_PLAYERS];

static gAttachObjectsArrayModel[MAX_PLAYERS][ATTACH_OBJ_MAX_ITEM_IN_PAGE];
static gAttachObjectArrayIndex[MAX_PLAYERS][ATTACH_OBJ_MAX_ITEM_IN_PAGE];
static gAttachObjectArrayLength[MAX_PLAYERS];
static gAttachObjectCooldownClick[MAX_PLAYERS];


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_OBJECT)
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);

		if (slotid == ITER_NONE)
		{
			language_MessageError(playerid, MSG_PROCESS_START_PRESS_NEW);
			return 0;
		}
		Dialog_Show(playerid, "dAttachObjectsMenu");
		return 1;
	}
#if defined attachobj_OnGuiAttachMenu
	return attachobj_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachobj_OnGuiAttachMenu
#if defined attachobj_OnGuiAttachMenu
	forward attachobj_OnGuiAttachMenu(playerid, typeid);
#endif

public OnGuiAttachObjectsClicked(playerid, typeid, index)
{
	if (typeid == GUI_ATTACH_OBJECT_PREVIOUS)
	{
		new total_objects = gAttachObjectArrayLength[playerid];
		new total_pages = (total_objects + ATTACH_OBJ_MAX_ITEM_IN_PAGE - 1) / ATTACH_OBJ_MAX_ITEM_IN_PAGE;
		new current_page = gAttachObjectsPage[playerid];

		gAttachObjectsPage[playerid] = (current_page == 0) ? (total_pages ? total_pages - 1 : 0) : (current_page - 1);

		attach_obj_ShowObjectList(playerid);
		return 1;
	}
	else if (typeid == GUI_ATTACH_OBJECT_NEXT)
	{
		new total_objects = gAttachObjectArrayLength[playerid];
		new total_pages = (total_objects + ATTACH_OBJ_MAX_ITEM_IN_PAGE - 1) / ATTACH_OBJ_MAX_ITEM_IN_PAGE;
		new current_page = gAttachObjectsPage[playerid];

		gAttachObjectsPage[playerid] = (current_page == total_pages - 1) ? 0 : (current_page + 1);

		attach_obj_ShowObjectList(playerid);
		return 1;
	}
	else if (typeid == GUI_ATTACH_OBJECT_ITEM)
	{
		if (gAttachObjectCooldownClick[playerid] > gettime())
		{
			language_MessageInfo(playerid, MSG_PRTCT_FRM_ACCIDENTAL_CLICK);
			return 0;
		}
		new modelid = gAttachObjectsArrayModel[playerid][index];

		if (modelid == CORE_INVALID_OBJECT_MODEL)
		{
			return 0;
		}
		new array_index = gAttachObjectArrayIndex[playerid][index];

		gAttachObjectsSelectModel[playerid] = modelid;
		gAttachObjectArrayIndex[playerid][0] = array_index;

		Dialog_Show(playerid, "dAttachObjectsActionMenu");
		return 1;
	}
	else if (typeid == GUI_ATTACH_OBJECT_CLOSE)
	{
		Dialog_Show(playerid, "dAttachObjectsMenu");
		return 1;
	}
#if defined attachobj_OnGuihObjectsClicked
	return attachobj_OnGuihObjectsClicked(playerid, typeid, index);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachObjectsClicked
	#undef OnGuiAttachObjectsClicked
#else
	#define _ALS_OnGuiAttachObjectsClicked
#endif
#define OnGuiAttachObjectsClicked attachobj_OnGuihObjectsClicked
#if defined attachobj_OnGuihObjectsClicked
	forward attachobj_OnGuihObjectsClicked(playerid, typeid, index);
#endif


DialogCreate:dAttachObjectsMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_SET_MODEL_ADD_SELECT_OBJECT,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachObjectsMenu,
		DIALOG_STYLE_LIST,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"X"
	);
	return 1;
}

DialogResponse:dAttachObjectsMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		gui_atatch_menu_ShowCursor(playerid);
		return 0;
	}
	if (listitem == 0)
	{
		Dialog_Show(playerid, "dAttachObjectsInput");
	}
	else if (listitem == 2)
	{
		Dialog_Show(playerid, "dAttachObjectsAddToList");
	}
	else if (listitem == 3)
	{
		gAttachObjectsPage[playerid] = 0;
		gAttachObjectCooldownClick[playerid] = gettime() + 1;

		attach_obj_ShowObjectList(playerid);
	}
	else
	{
		Dialog_Show(playerid, "dAttachObjectsMenu");
	}
	return 1;
}

DialogCreate:dAttachObjectsInput(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_ATTACHMENT_OBJ_MODEL,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachObjectsInput,
		DIALOG_STYLE_INPUT,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"«"
	);
	return 1;
}

DialogResponse:dAttachObjectsInput(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachObjectsMenu");
		return 0;
	}
	new modelid;

	if (sscanf(inputtext, "d", modelid))
	{
		Dialog_Show(playerid, "dAttachObjectsInput");
		return 0;
	}
	if (!(CORE_MIN_VALID_OBJECT_MODEL <= modelid <= CORE_MAX_VALID_OBJECT_MODEL))
	{
		language_MessageError(playerid, MSG_INVALID_OBJECT_MODEL);
		Dialog_Show(playerid, "dAttachObjectsInput");
		return 0;
	}
	gAttachObjectsSelectModel[playerid] = modelid;

	Dialog_Show(playerid, "dAttachMenuObjectNote");
	return 1;
}

DialogCreate:dAttachMenuObjectNote(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_COMMENT,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuObjectNote,
		DIALOG_STYLE_INPUT,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"«"
	);
	return 1;
}

DialogResponse:dAttachMenuObjectNote(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachObjectsMenu");
		return 0;
	}
	new lenght_note = strlen(inputtext);

	if (lenght_note > CORE_MAX_LENGHT_NAME_NOTE)
	{
		language_MessageInit(
			playerid,
			COLOR_RED,
			MSG_MAX_COMMENT_LENGTH_IS_CHARS,
			CORE_MAX_LENGHT_NAME_NOTE
		);
		Dialog_Show(playerid, "dAttachMenuObjectNote");
		return 0;
	}
	new slotid = attachmain_GetCurrentSlotId(playerid);
	new modelid = gAttachObjectsSelectModel[playerid];

	attachmain_SetObjectSlotId(playerid, slotid, modelid);
	attachmain_SetObjectSlotNote(playerid, slotid, !lenght_note ? CORE_EMPTY_NOTE : inputtext);

	attachmain_JsonSaveAttach(playerid, slotid);
	attachedit_SetAttachObject(playerid);
	gui_ath_obj_DestroyTextdraws(playerid);

	SendClientMessage(playerid, COLOR_WHITE, !"");

	language_MessageInfo(playerid, MSG_PRESS_TO_EDIT_START_EDITING);
	return 1;
}

static attach_obj_ShowObjectList(playerid)
{
	new JsonNode:node;
	new JsonNode:item;
	new JsonCallResult:result = JSON_ParseFile(json_file_name_objects, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		
		gui_ath_obj_CreateTextdraws(playerid);
		gui_ath_obj_ShowTextdraws(playerid);

		JSON_GetArray(node, "objects", node);
		JSON_ArrayLength(node, length);

		new modelid;
		new page = gAttachObjectsPage[playerid];
		new i = page * ATTACH_OBJ_MAX_ITEM_IN_PAGE;
		new j;
		new index;

		gAttachObjectArrayLength[playerid] = length;

		for (; i < length; i++)
		{
			if (j++ == ATTACH_OBJ_MAX_ITEM_IN_PAGE)
			{
				break;
			}
			JSON_ArrayObject(node, i, item);

			JSON_GetInt(item, "modelid", modelid);

			gui_ath_obj_SetModelObjecInCell(playerid, index, modelid);
			gui_ath_obj_SetModelTextInCell(playerid, index, modelid);

			gAttachObjectsArrayModel[playerid][index] = modelid;
			gAttachObjectArrayIndex[playerid][index] = i;
			index++;
		}
		if (j < ATTACH_OBJ_MAX_ITEM_IN_PAGE)
		{
			for (; j < ATTACH_OBJ_MAX_ITEM_IN_PAGE; j++)
			{
				gui_ath_obj_SetModelObjecInCell(playerid, j, -1);
				gui_ath_obj_SetModelTextInCell(playerid, j, -1);

				gAttachObjectsArrayModel[playerid][j] = -1;
			}
		}
	}
	JSON_Cleanup(item);
	JSON_Cleanup(node);
	return 1;
}

DialogCreate:dAttachObjectsActionMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_SET_OBJECT_REMOVE_FROM_LIST,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachObjectsActionMenu,
		DIALOG_STYLE_LIST,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"X"
	);
	return 1;
}


DialogResponse:dAttachObjectsActionMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		attach_obj_ShowObjectList(playerid);
		return 0;
	}
	if (listitem == 0)
	{
		Dialog_Show(playerid, "dAttachMenuObjectNote");
	}
	else
	{
		new JsonNode:node;
		new JsonCallResult:result = JSON_ParseFile(json_file_name_objects, node);
		new index = gAttachObjectArrayIndex[playerid][0];

		if (result == JSON_CALL_NO_ERR)
		{
			language_MessageInfo(playerid, MSG_OBJECT_REMOVED_SUCCESS);

			JSON_ArrayRemoveIndex(node, "objects", index);
			JSON_SaveFile(json_file_name_objects, node, 4);
		}
		JSON_Cleanup(node);

		gAttachObjectsPage[playerid] = 0;
		gAttachObjectCooldownClick[playerid] = gettime() + 1;
		attach_obj_ShowObjectList(playerid);
	}
	return 1;
}

DialogCreate:dAttachObjectsAddToList(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_OBJECT_MODEL_TO_ADD,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachObjectsAddToList,
		DIALOG_STYLE_INPUT,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"«"
	);
	return 1;
}

DialogResponse:dAttachObjectsAddToList(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachObjectsMenu");
		return 0;
	}
	new modelid;

	if (sscanf(inputtext, "d", modelid))
	{
		Dialog_Show(playerid, "dAttachObjectsAddToList");
		return 0;
	}
	if (!(CORE_MIN_VALID_OBJECT_MODEL <= modelid <= CORE_MAX_VALID_OBJECT_MODEL))
	{
		language_MessageError(playerid, MSG_INVALID_OBJECT_MODEL);

		Dialog_Show(playerid, "dAttachObjectsAddToList");
		return 0;
	}
	new JsonNode:item;
	new JsonNode:node;
	new JsonCallResult:result = JSON_ParseFile(json_file_name_objects, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new modelid_json;
		
		JSON_GetArray(node, "objects", node);
		JSON_ArrayLength(node, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(node, i, item);
			JSON_GetInt(item, "modelid", modelid_json);

			if (modelid_json == modelid)
			{
				language_MessageInfo(playerid, MSG_OBJECT_MODEL_EXISTS_WITH_ID);

				Dialog_Show(playerid, "dAttachObjectsAddToList");
				JSON_Cleanup(node);
				JSON_Cleanup(item);
				return 0;
			}
		}
	}
	JSON_Cleanup(node);
	JSON_Cleanup(item);

	result = JSON_ParseFile(json_file_name_objects, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_ArrayAppend(node, "objects", JSON_Object(
			"modelid", JSON_Int(modelid))
		);
		JSON_SaveFile(json_file_name_objects, node, 4);
	}
	JSON_Cleanup(node);

	language_MessageInfo(playerid, MSG_OBJECT_MODEL_ADDED_SUCCESS);
	Dialog_Show(playerid, "dAttachObjectsMenu");
	return 1;
}