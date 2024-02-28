#if defined _attach_symmetry_inc
	#endinput
#endif
#define _attach_symmetry_inc

static enum e_edit_btn_temp_struct
{
	asymmetry_SlotId,
	asymmetry_ObjectId,
	asymmetry_BoneId,
	Float:asymmetry_fOffsetX,
	Float:asymmetry_fOffsetY,
	Float:asymmetry_fOffsetZ,
	Float:asymmetry_fRotX,
	Float:asymmetry_fRotY,
	Float:asymmetry_fRotZ,
	Float:asymmetry_fScaleX,
	Float:asymmetry_fScaleY,
	Float:asymmetry_fScaleZ,
	asymmetry_materialcolor1,
	asymmetry_materialcolor2
}
static asymmetry_TempStructure[MAX_PLAYERS][e_edit_btn_temp_struct];
static gAttachSymmetryTempSlotId[MAX_PLAYERS];

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_SYMMETRY)
	{
		if (!attachmain_IsCreateProcess(playerid))
		{
			language_MessageError(playerid, MSG_PROCESS_START_PRESS_NEW);
			return 0;
		}
		if (!attachmain_IsValidObject(playerid))
		{
			language_MessageError(playerid, MSG_START_SELECT_OBJ_PRESS_OBJ);
			return 0;
		}
		if (attachmain_GetFreeSlotId(playerid) == ITER_NONE)
		{
			language_MessageError(playerid, MSG_SMTRY_NOT_FOUND_FREE_SLOT);
			return 0;
		}
		if (gui_atatch_symm_IsShow(playerid))
		{
			return 0;
		}
		new
			boneid,
			modelid,
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
			material_color_2,
			slotid = attachmain_GetCurrentSlotId(playerid);

		attachmain_GetMainAttachData(
			playerid,
			slotid,
			modelid,
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
		new free_slotid = attachmain_GetFreeSlotId(playerid);

		gAttachSymmetryTempSlotId[playerid] = free_slotid;

		asymmetry_SetTempAttach(
			playerid,
			modelid,
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
		gui_atatch_symm_ShowMenu(playerid);
		return 1;
	}
#if defined attachsmm_OnGuiAttachMenu
	return attachsmm_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachsmm_OnGuiAttachMenu
#if defined attachsmm_OnGuiAttachMenu
	forward attachsmm_OnGuiAttachMenu(playerid, typeid);
#endif

DialogCreate:dAttachSymmetrySaveNote(playerid)
{
	new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

	language_GetDialogString(
		playerid,
		DG_ENTER_COMMENT,
		str_dialog
	);
	Dialog_Open(
		playerid,
		Dialog:dAttachSymmetrySaveNote,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		str_dialog,
		"»",
		""
	);
	return 1;
}

DialogResponse:dAttachSymmetrySaveNote(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		SelectTextDraw(playerid, COLOR_TD_CLICK);
		return 0;
	}
	new lenght_note = strlen(inputtext);

	if (lenght_note > CORE_MAX_LENGHT_NAME_NOTE)
	{
		language_MessageError(
			playerid,
			MSG_MAX_COMMENT_LENGTH_IS_CHARS
		);
		Dialog_Show(playerid, "dAttachSymmetrySaveNote");
		return 0;
	}
	new slotid = gAttachSymmetryTempSlotId[playerid];
	
	attachmain_SetObjectSlotNote(
		playerid,
		slotid, !lenght_note ? CORE_EMPTY_NOTE : inputtext
	);
	asymmetry_PressSave(playerid);
	return 1;
}

static asymmetry_GetTempAttach(
	playerid,
	&objectid,
	&boneid,
	&Float:offset_x,
	&Float:offset_y,
	&Float:offset_z,
	&Float:rot_x,
	&Float:rot_y,
	&Float:rot_z,
	&Float:scale_x,
	&Float:scale_y,
	&Float:scale_z,
	&material_color_1,
	&material_color_2)
{
	objectid		=	asymmetry_TempStructure[playerid][asymmetry_ObjectId];
	boneid			=	asymmetry_TempStructure[playerid][asymmetry_BoneId];
	offset_x		=	asymmetry_TempStructure[playerid][asymmetry_fOffsetX];
	offset_y		=	asymmetry_TempStructure[playerid][asymmetry_fOffsetY];
	offset_z		=	asymmetry_TempStructure[playerid][asymmetry_fOffsetZ];
	rot_x			=	asymmetry_TempStructure[playerid][asymmetry_fRotX];
	rot_y			=	asymmetry_TempStructure[playerid][asymmetry_fRotY];
	rot_z			=	asymmetry_TempStructure[playerid][asymmetry_fRotZ];
	scale_x			=	asymmetry_TempStructure[playerid][asymmetry_fScaleX];
	scale_y			=	asymmetry_TempStructure[playerid][asymmetry_fScaleY];
	scale_z			=	asymmetry_TempStructure[playerid][asymmetry_fScaleZ];
	material_color_1	=	asymmetry_TempStructure[playerid][asymmetry_materialcolor1];
	material_color_2	=	asymmetry_TempStructure[playerid][asymmetry_materialcolor2];
	return 1;
}

static asymmetry_SetTempAttach(
	playerid,
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
	material_color_2)
{
	asymmetry_TempStructure[playerid][asymmetry_ObjectId]		= objectid;
	asymmetry_TempStructure[playerid][asymmetry_BoneId]			= boneid;
	asymmetry_TempStructure[playerid][asymmetry_fOffsetX]		= offset_x;
	asymmetry_TempStructure[playerid][asymmetry_fOffsetY]		= offset_y;
	asymmetry_TempStructure[playerid][asymmetry_fOffsetZ]		= offset_z;
	asymmetry_TempStructure[playerid][asymmetry_fRotX]			= rot_x;
	asymmetry_TempStructure[playerid][asymmetry_fRotY]			= rot_y;
	asymmetry_TempStructure[playerid][asymmetry_fRotZ]			= rot_z;
	asymmetry_TempStructure[playerid][asymmetry_fScaleX]		= scale_x;
	asymmetry_TempStructure[playerid][asymmetry_fScaleY]		= scale_y;
	asymmetry_TempStructure[playerid][asymmetry_fScaleZ]		= scale_z;
	asymmetry_TempStructure[playerid][asymmetry_materialcolor1]	= material_color_1;
	asymmetry_TempStructure[playerid][asymmetry_materialcolor2]	= material_color_2;

	new slotid = gAttachSymmetryTempSlotId[playerid];

	SetPlayerAttachedObject(
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
	return 1;
}

stock asymmetry_SetSymmetryType(playerid, typeid)
{
	new
		boneid,
		modelid,
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

	new slotid = attachmain_GetCurrentSlotId(playerid);

	attachmain_GetMainAttachData(
		playerid,
		slotid,
		modelid,
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
		Float:fSymmetricalOffsetX,
		Float:fSymmetricalOffsetY,
		Float:fSymmetricalOffsetZ,
		Float:fSymmetricalRotX,
		Float:fSymmetricalRotY,
		Float:fSymmetricalRotZ;

	fSymmetricalOffsetX = offset_x;
	fSymmetricalOffsetY = offset_y;
	fSymmetricalOffsetZ = offset_z;
	fSymmetricalRotX = rot_x;
	fSymmetricalRotY = rot_y;
	fSymmetricalRotZ = rot_z;

	switch (typeid)
	{
		case GUI_ATTACH_SYMMETRY_TYPE_X:
		{
			fSymmetricalOffsetX = -fSymmetricalOffsetX;
			fSymmetricalRotX = -fSymmetricalRotX;
		}
		case GUI_ATTACH_SYMMETRY_TYPE_Y:
		{
			fSymmetricalOffsetY = -fSymmetricalOffsetY;
			fSymmetricalRotY = -fSymmetricalRotY;
		}
		case GUI_ATTACH_SYMMETRY_TYPE_Z:
		{
			fSymmetricalOffsetZ = -fSymmetricalOffsetZ;
			fSymmetricalRotZ = -fSymmetricalRotZ;
		}
		case GUI_ATTACH_SYMMETRY_TYPE_R:
		{
			fSymmetricalRotX = -fSymmetricalRotX;
			fSymmetricalRotY = -fSymmetricalRotY;
			fSymmetricalRotZ = -fSymmetricalRotZ;
		}
		case GUI_ATTACH_SYMMETRY_TYPE_XY:
		{
			fSymmetricalOffsetX = -fSymmetricalOffsetX;
			fSymmetricalOffsetY = -fSymmetricalOffsetY;
			fSymmetricalRotX = -fSymmetricalRotX;
			fSymmetricalRotY = -fSymmetricalRotY;
		}
		case GUI_ATTACH_SYMMETRY_TYPE_YZ:
		{
			fSymmetricalOffsetY = -fSymmetricalOffsetY;
			fSymmetricalOffsetZ = -fSymmetricalOffsetZ;
			fSymmetricalRotY = -fSymmetricalRotY;
			fSymmetricalRotZ = -fSymmetricalRotZ;
		}
		case GUI_ATTACH_SYMMETRY_TYPE_ZX:
		{
			fSymmetricalOffsetZ = -fSymmetricalOffsetZ;
			fSymmetricalOffsetX = -fSymmetricalOffsetX;
			fSymmetricalRotZ = -fSymmetricalRotZ;
			fSymmetricalRotX = -fSymmetricalRotX;
		}
	}
	new opposite_boneids = attachmain_GetOppositeBoneIds(boneid);

	asymmetry_SetTempAttach(
		playerid,
		modelid,
		opposite_boneids,
		fSymmetricalOffsetX,
		fSymmetricalOffsetY,
		fSymmetricalOffsetZ,
		fSymmetricalRotX,
		fSymmetricalRotY,
		fSymmetricalRotZ,
		scale_x,
		scale_y,
		scale_z,
		material_color_1,
		material_color_2
	);
	return 1;
}

stock asymmetry_PressSave(playerid)
{
	new
		boneid,
		modelid,
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

	asymmetry_GetTempAttach(
		playerid,
		modelid,
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
	new slotid = gAttachSymmetryTempSlotId[playerid];

	attachmain_SetMainAttachData(
		playerid,
		slotid,
		modelid,
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
	project_JsonSaveAttach(playerid, slotid);
	attachmain_SetCurrentSlotId(playerid, slotid);
	attachmain_AddIterSlotId(playerid, slotid);
	attachmain_SetMainAttachObject(playerid, slotid);

	gui_atatch_symm_HideMenu(playerid);
	return 1;
}

stock asymmetry_PressCancel(playerid)
{
	new slotid = gAttachSymmetryTempSlotId[playerid];

	RemovePlayerAttachedObject(playerid, slotid);
	gui_atatch_symm_HideMenu(playerid);
	return 1;
}