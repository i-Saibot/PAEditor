#if defined _attach_colors_inc
	#endinput
#endif
#define _attach_colors_inc

const ATTACH_COLOR_MAX_ROW_IN_PAGE					= 25;
const ATTACH_COLOR_MAX_LNGT_HEX_CODE				= 6;

static gAttachColorsSelectColorId[MAX_PLAYERS];
static gAttachColorsPage[MAX_PLAYERS];

static gAttachColorHexCode[MAX_PLAYERS][ATTACH_COLOR_MAX_ROW_IN_PAGE];
static gAttachColorsArrayIndex[MAX_PLAYERS][ATTACH_COLOR_MAX_ROW_IN_PAGE];


public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_COLOR_1 || typeid == GUI_ATTACH_MENU_COLOR_2)
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);

		if (slotid == ITER_NONE)
		{
			language_MessageError(playerid, MSG_PROCESS_START_PRESS_NEW);
			return 0;
		}
		new modelid = attachmain_GetObjectSlotId(playerid, slotid);

		if (modelid == CORE_INVALID_OBJECT_MODEL)
		{
			language_MessageError(playerid, MSG_START_SELECT_OBJ_PRESS_OBJ);
			return 0;
		}
		gAttachColorsSelectColorId[playerid] = (typeid == GUI_ATTACH_MENU_COLOR_1 ? 0 : 1);

		Dialog_Show(playerid, "dAttachColorMenu");
		return 1;
	}
#if defined attachcolor_OnGuiAttachMenu
	return attachcolor_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachcolor_OnGuiAttachMenu
#if defined attachcolor_OnGuiAttachMenu
	forward attachcolor_OnGuiAttachMenu(playerid, typeid);
#endif

DialogCreate:dAttachColorMenu(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_HEX_SLCT_REMOVE_COLOR,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachColorMenu,
		DIALOG_STYLE_LIST,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"X"
	);
	return 1;
}

DialogResponse:dAttachColorMenu(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		gui_atatch_menu_ShowCursor(playerid);
		return 0;
	}
	switch (listitem)
	{
		case 0:
		{
			Dialog_Show(playerid, "dAttachColorInput");
		}
		case 1:
		{
			gAttachColorsPage[playerid] = 0;
			Dialog_Show(playerid, "dAttachColorList");
		}
		case 3:
		{
			new slotid = attachmain_GetCurrentSlotId(playerid);
			new colorid = gAttachColorsSelectColorId[playerid];

			if (colorid == 0)
			{
				attachmain_SetMaterialColor1(playerid, slotid, 0);
			}
			else
			{
				attachmain_SetMaterialColor2(playerid, slotid, 0);
			}
			attachmain_JsonSaveAttach(playerid, slotid);
			attachedit_SetAttachObject(playerid);

			language_MessageInfo(playerid, MSG_COLOR_HEX_REMOVED_SUCCESS);
		}
		default:
		{
			Dialog_Show(playerid, "dAttachColorMenu");
		}
	}
	return 1;
}

DialogCreate:dAttachColorInput(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_HEX_COLOR,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachColorInput,
		DIALOG_STYLE_INPUT,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"X"
	);
	return 1;
}

DialogResponse:dAttachColorInput(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachColorMenu");
		return 0;
	}
	if (!IsValidHexCode(inputtext))
	{
		language_MessageError(playerid, MSG_INVALID_COLOR_HEX_CODE);
		Dialog_Show(playerid, "dAttachColorInput");
		return 0;
	}
	new hex_code;

	HexToARGB(inputtext, hex_code);

	new slotid = attachmain_GetCurrentSlotId(playerid);
	new colorid = gAttachColorsSelectColorId[playerid];

	if (colorid == 0)
	{
		attachmain_SetMaterialColor1(playerid, slotid, hex_code);
	}
	else
	{
		attachmain_SetMaterialColor2(playerid, slotid, hex_code);
	}
	attachedit_SetAttachObject(playerid);
	attachmain_JsonSaveAttach(playerid, slotid);

	language_MessageInfo(playerid, MSG_COLOR_HEX_APPLIED_SUCCESS);
	return 1;
}


DialogCreate:dAttachColorList(playerid)
{
	new length;
	new str_hex[ATTACH_COLOR_MAX_LNGT_HEX_CODE + 1];
	new string[47 + 30 * 2 + (48 + (- 2 + sizeof(str_hex))) * ATTACH_COLOR_MAX_ROW_IN_PAGE];
	
	language_GetDialogString(
		playerid,
		DG_ADD_COLOR_HEX_CODE,
		string
	);
	new JsonNode:node;
	new JsonNode:item;
	new JsonCallResult:result = JSON_ParseFile(json_file_name_colors, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_GetArray(node, "colors", node);
		JSON_ArrayLength(node, length);

		new page = gAttachColorsPage[playerid];
		new i = page * ATTACH_COLOR_MAX_ROW_IN_PAGE;
		new j;
		new index;
		new hex_code;

		for (; i < length; i++)
		{
			if (j++ == ATTACH_COLOR_MAX_ROW_IN_PAGE)
			{
				break;
			}
			JSON_ArrayObject(node, i, item);

			JSON_GetString(item, "hex", str_hex, sizeof(str_hex));

			format(string, sizeof(string),
				"%s"cMain"» "cGrey"{%s}#######################\n",
				string,
				str_hex
			);
			HexToARGB(str_hex, hex_code);

			gAttachColorHexCode[playerid][index] = hex_code;
			gAttachColorsArrayIndex[playerid][index] = i;
			index++;
		}
		if (length > (page * ATTACH_COLOR_MAX_ROW_IN_PAGE) + ATTACH_COLOR_MAX_ROW_IN_PAGE)
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
		Dialog:dAttachColorList,
		DIALOG_STYLE_LIST,
		!""cMain"PAEditor",
		string,
		!"»",
		!"X"
	);
	return 1;
}


DialogResponse:dAttachColorList(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachColorMenu");
		return 0;
	}
	if (!strcmp(inputtext, "»»»", false))
	{
		gAttachColorsPage[playerid]++;
		Dialog_Show(playerid, "dAttachColorList");
		return 0;
	}
	else if (!strcmp(inputtext, "«««", false))
	{
		gAttachColorsPage[playerid]--;
		Dialog_Show(playerid, "dAttachColorList");
		return 0;
	}
	if (listitem == 0)
	{
		Dialog_Show(playerid, "dAttachColorsAddToList");
		return 0;
	}
	else if (listitem == 1)
	{
		Dialog_Show(playerid, "dAttachColorList");
		return 0;
	}
	new hex_code = gAttachColorHexCode[playerid][listitem - 2];
	new index_array = gAttachColorsArrayIndex[playerid][listitem - 2];

	gAttachColorHexCode[playerid][0] = hex_code;
	gAttachColorsArrayIndex[playerid][0] = index_array;

	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_APPLY_RMV_COLOR_FROM_LIST,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachColorsAction,
		DIALOG_STYLE_LIST,
		!""cMain"PAEditor",
		str_dialog,
		!"»",
		!"«"
	);
	return 1;
}


DialogResponse:dAttachColorsAction(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachColorList");
		return 0;
	}
	if (listitem == 0)
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);
		new colorid = gAttachColorsSelectColorId[playerid];
		new hex_code = gAttachColorHexCode[playerid][0];

		if (colorid == 0)
		{
			attachmain_SetMaterialColor1(playerid, slotid, hex_code);
		}
		else
		{
			attachmain_SetMaterialColor2(playerid, slotid, hex_code);
		}
		attachedit_SetAttachObject(playerid);
		attachmain_JsonSaveAttach(playerid, slotid);

		language_MessageInfo(playerid, MSG_COLOR_HEX_APPLIED_SUCCESS);
	}
	else
	{
		new JsonNode:node;
		new JsonCallResult:result = JSON_ParseFile(json_file_name_colors, node);
		new index = gAttachColorsArrayIndex[playerid][0];

		if (result == JSON_CALL_NO_ERR)
		{
			language_MessageInfo(playerid, MSG_COLOR_REMOVED_SUCCESS);

			JSON_ArrayRemoveIndex(node, "colors", index);
			JSON_SaveFile(json_file_name_colors, node, 4);
		}
		JSON_Cleanup(node);

		gAttachColorsPage[playerid] = 0;
		Dialog_Show(playerid, "dAttachColorList");
	}
	return 1;
}

DialogCreate:dAttachColorsAddToList(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dAttachColorsAddToList,
		DIALOG_STYLE_INPUT,
		!""cMain"PAEditor",
		""cWhite"Чтобы добавить цвет, введите цвет в формате HEX, например, FF0000.\n\
		Чтобы узнать цвет, вы можете воспользоваться сайтом: "cMain"htmlcolorcodes.com\n\n\
		"cRed"Примечание: "cWhite"Некоторые цвета могут отображаться некорректно на объектах.",
		!"»",
		!"«"
	);
	return 1;
}

DialogResponse:dAttachColorsAddToList(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachColorMenu");
		return 0;
	}
	if (!IsValidHexCode(inputtext))
	{
		language_MessageError(playerid, MSG_INVALID_COLOR_HEX_CODE);
		Dialog_Show(playerid, "dAttachColorsAddToList");
		return 0;
	}
	new JsonNode:item;
	new JsonNode:node;
	new JsonCallResult:result = JSON_ParseFile(json_file_name_colors, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new str_hex_in_json[ATTACH_COLOR_MAX_LNGT_HEX_CODE + 1];
		
		JSON_GetArray(node, "colors", node);
		JSON_ArrayLength(node, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(node, i, item);
			JSON_GetString(item, "hex", str_hex_in_json, sizeof(str_hex_in_json));

			if (!strcmp(inputtext, str_hex_in_json, false))
			{
				language_MessageError(playerid, MSG_COLOR_EXISTS_WITH_HEX_CODE);

				Dialog_Show(playerid, "dAttachColorsAddToList");
				JSON_Cleanup(node);
				JSON_Cleanup(item);
				return 0;
			}
		}
	}
	JSON_Cleanup(node);
	JSON_Cleanup(item);

	result = JSON_ParseFile(json_file_name_colors, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_ArrayAppend(node, "colors", JSON_Object(
			"hex", JSON_String(inputtext))
		);
		JSON_SaveFile(json_file_name_colors, node, 4);
	}
	JSON_Cleanup(node);

	language_MessageInfo(playerid, MSG_NEW_COLOR_ADDED_TO_LIST);

	gAttachColorsPage[playerid] = 0;
	Dialog_Show(playerid, "dAttachColorList");
	return 1;
}


static IsValidHexCode(const hex_code[])
{
	new lenght = strlen(hex_code);

	if (lenght != ATTACH_COLOR_MAX_LNGT_HEX_CODE)
	{
		return 0;
	}
	for (new i; i < lenght; i++)
	{
		switch (hex_code[i])
		{
			case 'A'..'F', 'a'..'f', '0'..'9':
			{
				continue;
			}
			default:
			{
				return 0;
			}
		}
	}
	return 1;
}

static HexToARGB(const hex_color[], &argb_color)
{
	argb_color = 0xFF000000
		| (HexCharToValue(hex_color[0]) << 20)
		| (HexCharToValue(hex_color[1]) << 16)
		| (HexCharToValue(hex_color[2]) << 12)
		| (HexCharToValue(hex_color[3]) << 8)
		| (HexCharToValue(hex_color[4]) << 4)
		| HexCharToValue(hex_color[5]
	);
	return 1;
}

static HexCharToValue(hex_char)
{
	return hex_char >= 'A' ? (hex_char & 0xDF) - 'A' + 10 : hex_char - '0';
}