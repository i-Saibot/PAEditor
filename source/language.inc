#if defined _language_inc
	#endinput
#endif
#define _language_inc


const LANGUAGE_MAX_LENGHT_STRING_DL						= 1450;

////////////////////////////////////////
static enum
{
	LANGUAGE_EN,
	LANGUAGE_RU,
	LANGUAGE_UA,
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
	MSG_CURRENT_PRJCT_CLSD_SUCCESS,
	MSG_SMTRY_NOT_FOUND_FREE_SLOT,
	MSG_DUBLICT_NOT_FOUND_FREE_SLOT,
	MSG_CHANGE_BONE,
	MSG_MULTIOBJ_INVALID_MODELID,
	MSG_NO_AVAILABLE_MULTIPLE_OBJ
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
	DG_MAIN_MENU_HELP,
	DG_ADD_COLOR_HEX_IN_LIST,
	DG_CONFIRM_MULT_DELETE_PROCESS,
	DG_MULTIOBJECT_LIST_MANAGE
}

static gPlayerLanguage[MAX_PLAYERS];

public OnGameModeInit()
{
	for (new i; i < sizeof(language_ArrayString); i++)
	{
		for (new j; j < sizeof(language_ArrayString[]); j++)
		{
			attachmain_SetBoneName(i, j, language_ArrayString[i][j]);
		}
	}
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
		name_dialog_header,
		"English\n\
		Русский язык\n\
		Українська мова\n\
		Беларуская мова",
		"»",
		""
	);
	return 1;
}

DialogResponse:dLanguageChoose(playerid, response, listitem, inputtext[])
{
	gPlayerLanguage[playerid] = listitem;

	language_MessageInfo(playerid, MSG_START_ROBOT_PRESS_MAIN_END);

	SendClientMessage(playerid, COLOR_WHITE, "");
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

stock language_GetDialogString(playerid, code, string[], const size = sizeof(string))
{
	new language = language_GetLanguage(playerid);

	string[0] = EOS;
	strcat(string, language_dialog[language][code], size);
	return 1;
}

stock language_GetLanguage(playerid)
{
	return gPlayerLanguage[playerid];
}
