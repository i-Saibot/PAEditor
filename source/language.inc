#if defined _language_inc
	#endinput
#endif
#define _language_inc


const LANGUAGE_MAX_CODE_MESSAGE							= 45;
const LANGUAGE_MAX_CODE_DIALOG							= 21;
const LANGUAGE_MAX_LENGHT_STRING_DL						= 415;

////////////////////////////////////////
static enum
{
	LANGUAGE_EN,
	LANGUAGE_UA,
	LANGUAGE_RU,
	LANGUAGE_BY
}

const LANGUAGE_MAX_COUNT								= 4;
////////////////////////////////////////

enum
{
	MSG_START_ROBOT_PRESS_MAIN_END,
	MSG_ANIM_APPLIED_TO_CHARACTER,
	MSG_ANIM_REMOVED_SUCCESS,
	MSG_ANIM_EXISTS_WITH_INDEX,
	MSG_PROCESS_START_PRESS_NEW,
	MSG_START_SELECT_OBJ_PRESS_OBJ,
	MSG_COLOR_HEX_REMOVED_SUCCESS,
	MSG_INVALID_COLOR_HEX_CODE,
	MSG_COLOR_HEX_APPLIED_SUCCESS,
	MSG_COLOR_REMOVED_SUCCESS,
	MSG_COLOR_EXISTS_WITH_HEX_CODE,
	MSG_NEW_COLOR_ADDED_TO_LIST,
	MSG_NO_CREATED_PROCESS_FOUND,
	MSG_MAX_COMMENT_LENGTH_IS_CHARS,
	MSG_OBJECT_DUPLICATED_SUCCESS,
	MSG_FREE_LOOK_HOLD_SPRINT_KEY,
	MSG_SAVE_PRESS_ICON_CNL_USE_ESC,
	MSG_NOT_SAVED_EDITING_CANCELLED,
	MSG_CHANGES_SAVED_AFTER_EDIT,
	MSG_LIST_ATTACHED_OBJECTS_EMPTY,
	MSG_NO_AVAILABLE_ATTACH_SLOTS,
	MSG_TO_SET_OBJECT_PRESS_OBJECTS,
	MSG_TO_MNG_ATTAC_PRESS_MANAGE,
	MSG_PRTCT_FRM_ACCIDENTAL_CLICK,
	MSG_INVALID_OBJECT_MODEL,
	MSG_PRESS_TO_EDIT_START_EDITING,
	MSG_OBJECT_REMOVED_SUCCESS,
	MSG_OBJECT_MODEL_EXISTS_WITH_ID,
	MSG_OBJECT_MODEL_ADDED_SUCCESS,
	MSG_SPECIFY_SKIN_ID_IN_RANGE,
	MSG_SKIN_SET_SUCCESS,
	MSG_CLOSE_CURRENT_PROJECT_FIRST,
	MSG_MAX_PROJECT_LENGTH_IS_CHARS,
	MSG_ONLY_LATIN_LETTERS_DIGITS,
	MSG_PROJECT_WITH_NAME_EXISTS,
	MSG_PRJCT_NAME_SUCCESS_CREATED,
	MSG_FREE_LK_MODE_ACTIV_PRS_ESC,
	MSG_CURSOR_ACTIVATION_PRESS_N,
	MSG_PROCESS_SRT_SLCT_OPTION_NEW,
	MSG_PROJECTS_LIST_EMPTY,
	MSG_PRJCT_FILE_NO_FOUND_WH_NAME,
	MSG_PROJECT_LOADED_SUCCESS,
	MSG_PRJCT_RMOVD_FRM_LT_SUCCESS,
	MSG_NO_ACTIVE_PROJECT_FOUND,
	MSG_CURRENT_PRJCT_CLSD_SUCCESS
}

enum
{
	DG_ADD_ANIMATION,
	DG_APPLY_ANIM_REMOVE_FROM_LIST,
	DG_ADD_ANIM_ENTER_TITLE_INDEX,
	DG_ENTER_HEX_SLCT_REMOVE_COLOR,
	DG_ENTER_HEX_COLOR,
	DG_APPLY_RMV_COLOR_FROM_LIST,
	DG_CONFIRM_DELETE_PROCESS,
	DG_CONFIRM_DUPLICATE_PROCESS,
	DG_ENTER_COMMENT,
	DG_DATA_EXPORT_SUCCESS,
	DG_NUM_NAME_OBJECT_COMMENT,
	DG_SET_MODEL_ADD_SELECT_OBJECT,
	DG_ENTER_ATTACHMENT_OBJ_MODEL,
	DG_SET_OBJECT_REMOVE_FROM_LIST,
	DG_ENTER_OBJECT_MODEL_TO_ADD,
	DG_ENTER_SKIN_ID_TO_SET,
	DG_ENTER_PROJECT_NAME,
	DG_LOAD_PRJCT_REMOVE_FROM_LIST,
	DG_CREATE_LOAD_CLS_HELP_PROJECT,
	DG_ADD_COLOR_HEX_CODE,
	DC_MAIN_MENU_HELP
}


static gConnectPlayerLanguage[MAX_PLAYERS];
static language_message[LANGUAGE_MAX_COUNT][LANGUAGE_MAX_CODE_MESSAGE][MAX_CHATBUBBLE_LENGTH + 1];
static language_dialog[LANGUAGE_MAX_COUNT][LANGUAGE_MAX_CODE_DIALOG][LANGUAGE_MAX_LENGHT_STRING_DL + 1];

public OnGameModeInit()
{
	new JsonNode:node;
	new JsonNode:obj;
	new JsonNode:array;
	new JsonCallResult:result = JSON_ParseFile(json_file_name_language_msg, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new message[MAX_CHATBUBBLE_LENGTH + 1];

//////////////////////////////////////UA////////////////////////////////////////

		JSON_GetArray(node, "UA", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "message", message, sizeof(message));

			strcat(language_message[LANGUAGE_UA][i], message);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);

//////////////////////////////////////RU////////////////////////////////////////

		JSON_GetArray(node, "RU", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "message", message, sizeof(message));

			strcat(language_message[LANGUAGE_RU][i], message);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);

//////////////////////////////////////EN////////////////////////////////////////

		JSON_GetArray(node, "EN", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "message", message, sizeof(message));

			strcat(language_message[LANGUAGE_EN][i], message);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);

//////////////////////////////////////BY////////////////////////////////////////

		JSON_GetArray(node, "BY", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "message", message, sizeof(message));

			strcat(language_message[LANGUAGE_BY][i], message);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);
	}
	JSON_Cleanup(node);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

	result = JSON_ParseFile(json_file_name_language_dialog, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new string[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

//////////////////////////////////////UA////////////////////////////////////////

		JSON_GetArray(node, "UA", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "string", string, sizeof(string));

			strcat(language_dialog[LANGUAGE_UA][i], string);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);

//////////////////////////////////////RU////////////////////////////////////////

		JSON_GetArray(node, "RU", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "string", string, sizeof(string));

			strcat(language_dialog[LANGUAGE_RU][i], string);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);

//////////////////////////////////////EN////////////////////////////////////////

		JSON_GetArray(node, "EN", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "string", string, sizeof(string));

			strcat(language_dialog[LANGUAGE_EN][i], string);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);

//////////////////////////////////////BY////////////////////////////////////////

		JSON_GetArray(node, "BY", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);
			JSON_GetString(obj, "string", string, sizeof(string));

			strcat(language_dialog[LANGUAGE_BY][i], string);
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);
	}
	JSON_Cleanup(node);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

	result = JSON_ParseFile(json_file_name_language_array, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new length_arr;

//////////////////////////////////////UA////////////////////////////////////////

		JSON_GetArray(node, "UA", array);
		JSON_ArrayLength(array, length);

		new JsonNode:item;
		new JsonNode:element;

		new string[100];

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);

			JSON_GetArray(obj, "array", item);

			JSON_ArrayLength(item, length_arr);

			for (new j; j < length_arr; j++)
			{
				JSON_ArrayObject(item, j, element);
				JSON_GetNodeString(element, string, sizeof(string));

				attachmain_SetBoneName(LANGUAGE_UA, j, string);
			}
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);
		JSON_Cleanup(item);
		JSON_Cleanup(element);

	//////////////////////////////////////RU////////////////////////////////////

		JSON_GetArray(node, "RU", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);

			JSON_GetArray(obj, "array", item);

			JSON_ArrayLength(item, length_arr);

			for (new j; j < length_arr; j++)
			{
				JSON_ArrayObject(item, j, element);
				JSON_GetNodeString(element, string, sizeof(string));

				attachmain_SetBoneName(LANGUAGE_RU, j, string);
			}
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);
		JSON_Cleanup(item);
		JSON_Cleanup(element);

//////////////////////////////////////////EN////////////////////////////////////

		JSON_GetArray(node, "EN", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);

			JSON_GetArray(obj, "array", item);

			JSON_ArrayLength(item, length_arr);

			for (new j; j < length_arr; j++)
			{
				JSON_ArrayObject(item, j, element);
				JSON_GetNodeString(element, string, sizeof(string));

				attachmain_SetBoneName(LANGUAGE_EN, j, string);
			}
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);
		JSON_Cleanup(item);
		JSON_Cleanup(element);

//////////////////////////////////////////BY////////////////////////////////////

		JSON_GetArray(node, "BY", array);
		JSON_ArrayLength(array, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(array, i, obj);

			JSON_GetArray(obj, "array", item);

			JSON_ArrayLength(item, length_arr);

			for (new j; j < length_arr; j++)
			{
				JSON_ArrayObject(item, j, element);
				JSON_GetNodeString(element, string, sizeof(string));

				attachmain_SetBoneName(LANGUAGE_BY, j, string);
			}
		}
		JSON_Cleanup(obj);
		JSON_Cleanup(array);
		JSON_Cleanup(item);
		JSON_Cleanup(element);
	}
	JSON_Cleanup(node);
#if defined core_OnGameModeInit
	return core_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit core_OnGameModeInit
#if defined    core_OnGameModeInit
	forward core_OnGameModeInit();
#endif

DialogCreate:dLanguageChoose(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dLanguageChoose,
		DIALOG_STYLE_LIST,
		!""cMain"PAEditor",
		!"English\n\
		Українська мова\n\
		Русский язык\n\
		Беларуская мова",
		!"»",
		!""
	);
	return 1;
}

DialogResponse:dLanguageChoose(playerid, response, listitem, inputtext[])
{
	gConnectPlayerLanguage[playerid] = listitem;

	language_MessageInfo(playerid, MSG_START_ROBOT_PRESS_MAIN_END);

	SendClientMessage(playerid, COLOR_WHITE, !"");
	return 1;
}


/*
	functions
*/

stock language_MessageInfo(playerid, code)
{
	new string[MAX_CHATBUBBLE_LENGTH + 1];
	new language = language_GetLanguage(playerid);

	strcat(string, "[!] "cWhite"");
	strcat(string, language_message[language][code]);

	SendClientMessage(playerid, COLOR_SERVER_MAIN, string);
	return 1;
}

stock language_MessageError(playerid, code)
{
	new string[MAX_CHATBUBBLE_LENGTH + 1];
	new language = language_GetLanguage(playerid);

	strcat(string, "[x] "cWhite"");
	strcat(string, language_message[language][code]);

	SendClientMessage(playerid, COLOR_RED, string);
	return 1;
}

stock language_MessageInit(playerid, color, code, value)
{
	new string[MAX_CHATBUBBLE_LENGTH + 1];
	new language = language_GetLanguage(playerid);

	format(string, sizeof(string),
		"[x] "cWhite"%s",
		language_message[language][code],
		value
	);
	SendClientMessage(playerid, color, string);
	return 1;
}


stock language_GetDialogString(playerid, code, string[], const size = sizeof(string))
{
	new language = language_GetLanguage(playerid);

	string[0] = EOS;
	strcat(string, language_dialog[language][code], size);
	return 1;
}


stock language_GetLanguage(playerid)
{
	return gConnectPlayerLanguage[playerid];
}
