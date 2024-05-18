#if defined _attach_new_inc
	#endinput
#endif
#define _attach_new_inc

#define RGB_ARGBToRGBA(%0)							((((%0) << 8) & 0xFFFFFF00) | (((%0) >>> 24) & 0xFF))

const
	Float:ATTACH_NEW_COORD_BTN_MIN_X				= 0.3072,
	Float:ATTACH_NEW_COORD_BTN_MAX_X				= 0.3468,

	Float:ATTACH_NEW_COORD_BTN_MIN_Y				= 0.9268,
	Float:ATTACH_NEW_COORD_BTN_MAX_Y				= 0.9944;

static enum e_new_attach_add_struct
{
	anew_ObjectId,
	anew_BoneId,
	Float:anew_fOffsetX,
	Float:anew_fOffsetY,
	Float:anew_fOffsetZ,
	Float:anew_fRotX,
	Float:anew_fRotY,
	Float:anew_fRotZ,
	Float:anew_fScaleX,
	Float:anew_fScaleY,
	Float:anew_fScaleZ,
	anew_materialcolor1,
	anew_materialcolor2
}
static
	anew_Structure[MAX_PLAYERS][e_new_attach_add_struct],
	anew_DefaultValue[e_new_attach_add_struct] =
	{
		CORE_INVALID_OBJECT_MODEL,
		0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		1.0,
		1.0,
		1.0,
		0xFFFFFFFF,
		0xFFFFFFFF
	},
	gAnewSelectType[MAX_PLAYERS];

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_NEW)
	{
		if (gui_ath_uniqedit_IsShowTD(playerid))
		{
			return 0;
		}
		if (attachmain_GetFreeSlotId(playerid) == ITER_NONE)
		{
			language_MessageError(playerid, "MSG_NO_AVAILABLE_ATTACH_SLOTS");
			return 0;
		}
		Dialog_Show(playerid, "dAttachMenuNew");
		return 1;
	}
#if defined attachnew_OnGuiAttachMenu
	return attachnew_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachnew_OnGuiAttachMenu
#if defined attachnew_OnGuiAttachMenu
	forward attachnew_OnGuiAttachMenu(playerid, typeid);
#endif

public OnVirtualKeyReleased(playerid, key_vk)
{
	if (key_vk == VK_RBUTTON)
	{
		if (attachmain_IsNoBannedClick(playerid))
		{
			new
				Float:x,
				Float:y;

			GetMousePos(x, y);

			if ((ATTACH_NEW_COORD_BTN_MIN_X <= x <= ATTACH_NEW_COORD_BTN_MAX_X)
				&& (ATTACH_NEW_COORD_BTN_MIN_Y <= y <= ATTACH_NEW_COORD_BTN_MAX_Y))
			{
				anew_Structure[playerid] = anew_DefaultValue;

				Dialog_Show(playerid, "dAttachMenuNewSelectInput");
				return 1;
			}
		}
	}
#if defined attachnew_OnVirtualKeyReleased
	return attachnew_OnVirtualKeyReleased(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased attachnew_OnVirtualKeyReleased
#if defined    attachnew_OnVirtualKeyReleased
	forward attachnew_OnVirtualKeyReleased(playerid, key_vk);
#endif

DialogCreate:dAttachMenuNew(playerid)
{
	new
		string[24 + (19 + (- 2 + CORE_MAX_LENGHT_NAME_BONE)) * CORE_MAX_COUNT_BONE],
		Lang:lanid = Lang_GetPlayerLang(playerid);

	for (new i; i < CORE_MAX_COUNT_BONE; i++)
	{
		format(string, sizeof(string),
			"%s"cMain"» "cWhite"%s\n",
			string,
			gLangArrayBone[_:lanid][i]
		);
	}
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuNew,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		string,
		"»",
		"X"
	);
	return 1;
}

DialogResponse:dAttachMenuNew(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new
		boneid = attachmain_GetBoneId(listitem),
		slotid = attachmain_GetFreeSlotId(playerid);

	attachmain_SetSlotId(playerid, slotid, slotid);
	attachmain_SetCurrentSlotId(playerid, slotid);
	attachmain_SetBoneSlotId(playerid, slotid, boneid);

	project_JsonSaveAttach(playerid, slotid);

	SendClientMessage(playerid, COLOR_WHITE, "");

	language_MessageError(playerid, "MSG_TO_SET_OBJECT_PRESS_OBJECTS");
	language_MessageInfo(playerid, "MSG_TO_MNG_ATTAC_PRESS_MANAGE");
	return 1;
}

DialogCreate:dAttachMenuNewSelectInput(playerid)
{
	new
		boneid = anew_Structure[playerid][anew_BoneId] - 1,
		Lang:lanid = Lang_GetPlayerLang(playerid);

	Dialog_Open(
		playerid,
		Dialog:dAttachMenuNewSelectInput,
		DIALOG_STYLE_TABLIST,
		name_dialog_header,
		"DG_ANEW_INPUT_MENU",
		"»",
		"X",
		anew_Structure[playerid][anew_ObjectId],
		boneid == -1 ? "-" : gLangArrayBone[_:lanid][boneid],
		anew_Structure[playerid][anew_fOffsetX],
		anew_Structure[playerid][anew_fOffsetY],
		anew_Structure[playerid][anew_fOffsetZ],
		anew_Structure[playerid][anew_fRotX],
		anew_Structure[playerid][anew_fRotY],
		anew_Structure[playerid][anew_fRotZ],
		anew_Structure[playerid][anew_fScaleX],
		anew_Structure[playerid][anew_fScaleY],
		anew_Structure[playerid][anew_fScaleZ],
		RGB_ARGBToRGBA(anew_Structure[playerid][anew_materialcolor1]) >>> 8,
		RGB_ARGBToRGBA(anew_Structure[playerid][anew_materialcolor2]) >>> 8
	);
	return 1;
}

DialogResponse:dAttachMenuNewSelectInput(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	switch (listitem)
	{
		case 1:
		{
			new
				string[24 + (19 + (- 2 + CORE_MAX_LENGHT_NAME_BONE)) * CORE_MAX_COUNT_BONE],
				Lang:lanid = Lang_GetPlayerLang(playerid);

			for (new i; i < CORE_MAX_COUNT_BONE; i++)
			{
				format(string, sizeof(string),
					"%s"cMain"» "cWhite"%s\n",
					string,
					gLangArrayBone[_:lanid][i]
				);
			}
			Dialog_Open(
				playerid,
				Dialog:dAttachMenuAnewBone,
				DIALOG_STYLE_LIST,
				name_dialog_header,
				string,
				"»",
				"X"
			);
			return 0;
		}
		case 13, 15:
		{
			Dialog_Show(playerid, "dAttachMenuNewSelectInput");
			return 0;
		}
		case 14:
		{
			Dialog_Show(playerid, "dAttachMenuNewInputDots");
			return 0;
		}
		case 16:
		{
			if (anew_Structure[playerid][anew_ObjectId] == CORE_INVALID_OBJECT_MODEL)
			{
				language_MessageError(playerid, "MSG_INVALID_OBJECT");
				Dialog_Show(playerid, "dAttachMenuNewSelectInput");
				return 0;
			}
			if (anew_Structure[playerid][anew_BoneId] - 1 == -1)
			{
				Dialog_Show(playerid, "dAttachMenuNewSelectInput");
				language_MessageError(playerid, "MSG_INVALID_BONE");
				return 0;
			}
			new slotid = attachmain_GetFreeSlotId(playerid);

			attachmain_SetSlotId(playerid, slotid, slotid);
			attachmain_SetCurrentSlotId(playerid, slotid);

			attachmain_SetMainAttachData(
				playerid,
				slotid,
				anew_Structure[playerid][anew_ObjectId],
				anew_Structure[playerid][anew_BoneId],
				anew_Structure[playerid][anew_fOffsetX],
				anew_Structure[playerid][anew_fOffsetY],
				anew_Structure[playerid][anew_fOffsetZ],
				anew_Structure[playerid][anew_fRotX],
				anew_Structure[playerid][anew_fRotY],
				anew_Structure[playerid][anew_fRotZ],
				anew_Structure[playerid][anew_fScaleX],
				anew_Structure[playerid][anew_fScaleY],
				anew_Structure[playerid][anew_fScaleZ],
				anew_Structure[playerid][anew_materialcolor1],
				anew_Structure[playerid][anew_materialcolor2]
			);
			attachmain_ApplyMainAttach(playerid, slotid);
			project_JsonSaveAttach(playerid, slotid);
			return 0;
		}
	}
	gAnewSelectType[playerid] = listitem;
	Dialog_Show(playerid, "dAttachMenuNewInputData");
	return 1;
}

DialogCreate:dAttachMenuNewInputData(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuNewInputData,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		"DG_ANEW_INPUT_DATA",
		"»",
		"«"
	);
	return 1;
}

DialogResponse:dAttachMenuNewInputData(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachMenuNewSelectInput");
		return 0;
	}
	new typeid = gAnewSelectType[playerid];

	switch (typeid)
	{
		case 0:
		{
			new value;

			if (sscanf(inputtext, "d", value))
			{
				Dialog_Show(playerid, "dAttachMenuNewInputData");
				return 0;
			}
			switch (typeid)
			{
				case 0:
				{
					if (!(CORE_MIN_VALID_OBJECT_MODEL <= value <= CORE_MAX_VALID_OBJECT_MODEL))
					{
						language_MessageError(playerid, "MSG_INVALID_OBJECT_MODEL");
						Dialog_Show(playerid, "dAttachMenuNewInputData");
						return 0;
					}
					anew_Structure[playerid][anew_ObjectId] = value;
				}
			}
		}
		case 2..10:
		{
			new Float:value;

			if (sscanf(inputtext, "f", value))
			{
				Dialog_Show(playerid, "dAttachMenuNewInputData");
				return 0;
			}
			switch (typeid)
			{
				case 2: anew_Structure[playerid][anew_fOffsetX] = value;
				case 3: anew_Structure[playerid][anew_fOffsetY] = value;
				case 4: anew_Structure[playerid][anew_fOffsetZ] = value;
				case 5: anew_Structure[playerid][anew_fRotX] = value;
				case 6: anew_Structure[playerid][anew_fRotY] = value;
				case 7: anew_Structure[playerid][anew_fRotZ] = value;
				case 8: anew_Structure[playerid][anew_fScaleX] = value;
				case 9: anew_Structure[playerid][anew_fScaleY] = value;
				case 10: anew_Structure[playerid][anew_fScaleZ] = value;
			}
		}
		case 11..12:
		{
			if (!IsValidHexCode(inputtext))
			{
				language_MessageError(playerid, "MSG_INVALID_COLOR_HEX_CODE");
				Dialog_Show(playerid, "dAttachMenuNewInputData");
				return 0;
			}
			new hex_code;

			HexToARGB(inputtext, hex_code);

			switch (typeid)
			{
				case 11: anew_Structure[playerid][anew_materialcolor1] = hex_code;
				case 12: anew_Structure[playerid][anew_materialcolor2] = hex_code;
			}
		}
	}
	Dialog_Show(playerid, "dAttachMenuNewSelectInput");
	return 1;
}

DialogResponse:dAttachMenuAnewBone(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachMenuNewSelectInput");
		return 0;
	}
	anew_Structure[playerid][anew_BoneId] = attachmain_GetBoneId(listitem);

	Dialog_Show(playerid, "dAttachMenuNewSelectInput");
	return 1;
}

DialogCreate:dAttachMenuNewInputDots(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuNewInputDots,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		"DG_ANEW_INPUT_DATA_DOTS",
		"»",
		"«"
	);
	return 1;
}

DialogResponse:dAttachMenuNewInputDots(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		Dialog_Show(playerid, "dAttachMenuNewSelectInput");
		return 0;
	}
	new
		modelid,
		boneid,
		Float:offset_x,
		Float:offset_y,
		Float:offset_z,
		Float:rot_x,
		Float:rot_y,
		Float:rot_z,
		Float:scale_x,
		Float:scale_y,
		Float:scale_z;

	if (sscanf(inputtext, "p<,>ddfffffffff", modelid, boneid, offset_x, offset_y, offset_z, rot_x, rot_y, rot_z, scale_x, scale_y, scale_z))
	{
		Dialog_Show(playerid, "dAttachMenuNewInputDots");
		return 0;
	}
	if (!(CORE_MIN_VALID_OBJECT_MODEL <= modelid <= CORE_MAX_VALID_OBJECT_MODEL))
	{
		language_MessageError(playerid, "MSG_INVALID_OBJECT_MODEL");
		Dialog_Show(playerid, "dAttachMenuNewInputDots");
		return 0;
	}
	if (!(0 <= boneid <= CORE_MAX_COUNT_BONE))
	{
		language_MessageError(playerid, "MSG_INVALID_BONE");
		Dialog_Show(playerid, "dAttachMenuNewInputDots");
		return 0;
	}
	anew_Structure[playerid][anew_ObjectId] = modelid;
	anew_Structure[playerid][anew_BoneId]  = boneid;
	anew_Structure[playerid][anew_fOffsetX] = offset_x;
	anew_Structure[playerid][anew_fOffsetY] = offset_y;
	anew_Structure[playerid][anew_fOffsetZ] = offset_z;
	anew_Structure[playerid][anew_fRotX] = rot_x;
	anew_Structure[playerid][anew_fRotY] = rot_y;
	anew_Structure[playerid][anew_fRotZ] = rot_z;
	anew_Structure[playerid][anew_fScaleX] = scale_x;
	anew_Structure[playerid][anew_fScaleY] = scale_y;
	anew_Structure[playerid][anew_fScaleZ] = scale_z;

	Dialog_Show(playerid, "dAttachMenuNewSelectInput");
	return 1;
}

